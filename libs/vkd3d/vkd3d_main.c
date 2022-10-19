/*
 * Copyright 2016-2017 Józef Kucia for CodeWeavers
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#define INITGUID
#include "vkd3d_private.h"

HRESULT vkd3d_create_device(const struct vkd3d_device_create_info *create_info,
        REFIID iid, void **device)
{
    struct vkd3d_instance *instance;
    struct d3d12_device *object;
    HRESULT hr;

    TRACE("create_info %p, iid %s, device %p.\n", create_info, debugstr_guid(iid), device);

    if (!create_info)
        return E_INVALIDARG;
    if (create_info->type != VKD3D_STRUCTURE_TYPE_DEVICE_CREATE_INFO)
    {
        WARN("Invalid structure type %#x.\n", create_info->type);
        return E_INVALIDARG;
    }
    if (create_info->next)
        WARN("Unhandled next %p.\n", create_info->next);
    if (!create_info->instance && !create_info->instance_create_info)
    {
        ERR("Instance or instance create info is required.\n");
        return E_INVALIDARG;
    }
    if (create_info->instance && create_info->instance_create_info)
    {
        ERR("Instance and instance create info are mutually exclusive parameters.\n");
        return E_INVALIDARG;
    }

    if (create_info->minimum_feature_level < D3D_FEATURE_LEVEL_11_0
            || !is_valid_feature_level(create_info->minimum_feature_level))
    {
        WARN("Invalid feature level %#x.\n", create_info->minimum_feature_level);
        return E_INVALIDARG;
    }

    if (!check_feature_level_support(create_info->minimum_feature_level))
    {
        FIXME("Unsupported feature level %#x.\n", create_info->minimum_feature_level);
        return E_INVALIDARG;
    }

    if ((instance = create_info->instance))
    {
        vkd3d_instance_incref(instance);
    }
    else if (FAILED(hr = vkd3d_create_instance(create_info->instance_create_info, &instance)))
    {
        WARN("Failed to create instance, hr %#x.\n", hr);
        return E_FAIL;
    }

    hr = d3d12_device_create(instance, create_info, &object);
    vkd3d_instance_decref(instance);
    if (FAILED(hr))
        return hr;

    if (!device)
    {
        ID3D12Device_Release(&object->ID3D12Device_iface);
        return S_FALSE;
    }

    return return_interface(&object->ID3D12Device_iface, &IID_ID3D12Device, iid, device);
}

/* ID3D12RootSignatureDeserializer */
struct d3d12_root_signature_deserializer
{
    ID3D12RootSignatureDeserializer ID3D12RootSignatureDeserializer_iface;
    LONG refcount;

    union
    {
        D3D12_ROOT_SIGNATURE_DESC d3d12;
        struct vkd3d_root_signature_desc vkd3d;
    } desc;
};

static struct d3d12_root_signature_deserializer *impl_from_ID3D12RootSignatureDeserializer(
        ID3D12RootSignatureDeserializer *iface)
{
    return CONTAINING_RECORD(iface, struct d3d12_root_signature_deserializer, ID3D12RootSignatureDeserializer_iface);
}

static HRESULT STDMETHODCALLTYPE d3d12_root_signature_deserializer_QueryInterface(
        ID3D12RootSignatureDeserializer *iface, REFIID riid, void **object)
{
    TRACE("iface %p, riid %s, object %p.\n", iface, debugstr_guid(riid), object);

    /* QueryInterface() implementation is broken, E_NOINTERFACE is returned for
     * IUnknown.
     */
    if (IsEqualGUID(riid, &IID_ID3D12RootSignatureDeserializer))
    {
        ID3D12RootSignatureDeserializer_AddRef(iface);
        *object = iface;
        return S_OK;
    }

    WARN("%s not implemented, returning E_NOINTERFACE.\n", debugstr_guid(riid));

    *object = NULL;
    return E_NOINTERFACE;
}

static ULONG STDMETHODCALLTYPE d3d12_root_signature_deserializer_AddRef(ID3D12RootSignatureDeserializer *iface)
{
    struct d3d12_root_signature_deserializer *deserializer = impl_from_ID3D12RootSignatureDeserializer(iface);
    ULONG refcount = InterlockedIncrement(&deserializer->refcount);

    TRACE("%p increasing refcount to %u.\n", deserializer, refcount);

    return refcount;
}

static ULONG STDMETHODCALLTYPE d3d12_root_signature_deserializer_Release(ID3D12RootSignatureDeserializer *iface)
{
    struct d3d12_root_signature_deserializer *deserializer = impl_from_ID3D12RootSignatureDeserializer(iface);
    ULONG refcount = InterlockedDecrement(&deserializer->refcount);

    TRACE("%p decreasing refcount to %u.\n", deserializer, refcount);

    if (!refcount)
    {
        vkd3d_shader_free_root_signature(&deserializer->desc.vkd3d);
        vkd3d_free(deserializer);
    }

    return refcount;
}

static const D3D12_ROOT_SIGNATURE_DESC * STDMETHODCALLTYPE d3d12_root_signature_deserializer_GetRootSignatureDesc(
        ID3D12RootSignatureDeserializer *iface)
{
    struct d3d12_root_signature_deserializer *deserializer = impl_from_ID3D12RootSignatureDeserializer(iface);

    TRACE("iface %p.\n", iface);

    return &deserializer->desc.d3d12;
}

static const struct ID3D12RootSignatureDeserializerVtbl d3d12_root_signature_deserializer_vtbl =
{
    /* IUnknown methods */
    d3d12_root_signature_deserializer_QueryInterface,
    d3d12_root_signature_deserializer_AddRef,
    d3d12_root_signature_deserializer_Release,
    /* ID3D12RootSignatureDeserializer methods */
    d3d12_root_signature_deserializer_GetRootSignatureDesc,
};

static HRESULT d3d12_root_signature_deserializer_init(struct d3d12_root_signature_deserializer *deserializer,
        const struct vkd3d_shader_code *dxbc)
{
    int ret;

    deserializer->ID3D12RootSignatureDeserializer_iface.lpVtbl = &d3d12_root_signature_deserializer_vtbl;
    deserializer->refcount = 1;

    if ((ret = vkd3d_shader_parse_root_signature(dxbc, &deserializer->desc.vkd3d)) < 0)
    {
        WARN("Failed to parse root signature, vkd3d result %d.\n", ret);
        return hresult_from_vkd3d_result(ret);
    }

    return S_OK;
}

HRESULT vkd3d_create_root_signature_deserializer(const void *data, SIZE_T data_size,
        REFIID iid, void **deserializer)
{
    struct vkd3d_shader_code dxbc = {data, data_size};
    struct d3d12_root_signature_deserializer *object;
    HRESULT hr;

    TRACE("data %p, data_size %lu, iid %s, deserializer %p.\n",
            data, data_size, debugstr_guid(iid), deserializer);

    if (!(object = vkd3d_malloc(sizeof(*object))))
        return E_OUTOFMEMORY;

    if (FAILED(hr = d3d12_root_signature_deserializer_init(object, &dxbc)))
    {
        vkd3d_free(object);
        return hr;
    }

    return return_interface(&object->ID3D12RootSignatureDeserializer_iface,
            &IID_ID3D12RootSignatureDeserializer, iid, deserializer);
}

/* ID3DBlob */
struct d3d_blob
{
    ID3D10Blob ID3DBlob_iface;
    LONG refcount;

    void *buffer;
    SIZE_T size;
};

static struct d3d_blob *impl_from_ID3DBlob(ID3DBlob *iface)
{
    return CONTAINING_RECORD(iface, struct d3d_blob, ID3DBlob_iface);
}

static HRESULT STDMETHODCALLTYPE d3d_blob_QueryInterface(ID3DBlob *iface, REFIID riid, void **object)
{
    TRACE("iface %p, riid %s, object %p.\n", iface, debugstr_guid(riid), object);

    if (IsEqualGUID(riid, &IID_ID3DBlob)
            || IsEqualGUID(riid, &IID_IUnknown))
    {
        ID3D10Blob_AddRef(iface);
        *object = iface;
        return S_OK;
    }

    WARN("%s not implemented, returning E_NOINTERFACE.\n", debugstr_guid(riid));

    *object = NULL;
    return E_NOINTERFACE;
}

static ULONG STDMETHODCALLTYPE d3d_blob_AddRef(ID3DBlob *iface)
{
    struct d3d_blob *blob = impl_from_ID3DBlob(iface);
    ULONG refcount = InterlockedIncrement(&blob->refcount);

    TRACE("%p increasing refcount to %u.\n", blob, refcount);

    return refcount;
}

static ULONG STDMETHODCALLTYPE d3d_blob_Release(ID3DBlob *iface)
{
    struct d3d_blob *blob = impl_from_ID3DBlob(iface);
    ULONG refcount = InterlockedDecrement(&blob->refcount);

    TRACE("%p decreasing refcount to %u.\n", blob, refcount);

    if (!refcount)
    {
        vkd3d_free(blob->buffer);

        vkd3d_free(blob);
    }

    return refcount;
}

static void * STDMETHODCALLTYPE d3d_blob_GetBufferPointer(ID3DBlob *iface)
{
    struct d3d_blob *blob = impl_from_ID3DBlob(iface);

    TRACE("iface %p.\n", iface);

    return blob->buffer;
}

static SIZE_T STDMETHODCALLTYPE d3d_blob_GetBufferSize(ID3DBlob *iface)
{
    struct d3d_blob *blob = impl_from_ID3DBlob(iface);

    TRACE("iface %p.\n", iface);

    return blob->size;
}

static const struct ID3D10BlobVtbl d3d_blob_vtbl =
{
    /* IUnknown methods */
    d3d_blob_QueryInterface,
    d3d_blob_AddRef,
    d3d_blob_Release,
    /* ID3DBlob methods */
    d3d_blob_GetBufferPointer,
    d3d_blob_GetBufferSize
};

static void d3d_blob_init(struct d3d_blob *blob, void *buffer, SIZE_T size)
{
    blob->ID3DBlob_iface.lpVtbl = &d3d_blob_vtbl;
    blob->refcount = 1;

    blob->buffer = buffer;
    blob->size = size;
}

static HRESULT d3d_blob_create(void *buffer, SIZE_T size, struct d3d_blob **blob)
{
    struct d3d_blob *object;

    if (!(object = vkd3d_malloc(sizeof(*object))))
        return E_OUTOFMEMORY;

    d3d_blob_init(object, buffer, size);

    TRACE("Created blob object %p.\n", object);

    *blob = object;

    return S_OK;
}

HRESULT vkd3d_serialize_root_signature(const D3D12_ROOT_SIGNATURE_DESC *root_signature_desc,
        D3D_ROOT_SIGNATURE_VERSION version, ID3DBlob **blob, ID3DBlob **error_blob)
{
    struct vkd3d_shader_code dxbc;
    struct d3d_blob *blob_object;
    HRESULT hr;
    int ret;

    TRACE("root_signature_desc %p, version %#x, blob %p, error_blob %p.\n",
            root_signature_desc, version, blob, error_blob);

    if (!blob)
    {
        WARN("Invalid blob parameter.\n");
        return E_INVALIDARG;
    }

    if (error_blob)
    {
        FIXME("Ignoring error blob %p.\n", error_blob);
        *error_blob = NULL;
    }

    if ((ret = vkd3d_shader_serialize_root_signature(
            (const struct vkd3d_root_signature_desc *)root_signature_desc,
            (enum vkd3d_root_signature_version)version, &dxbc)) < 0)
    {
        WARN("Failed to serialize root signature, vkd3d result %d.\n", ret);
        return hresult_from_vkd3d_result(ret);
    }

    if (FAILED(hr = d3d_blob_create((void *)dxbc.code, dxbc.size, &blob_object)))
    {
        WARN("Failed to create blob object, hr %#x.\n", hr);
        vkd3d_shader_free_shader_code(&dxbc);
        return hr;
    }

    *blob = &blob_object->ID3DBlob_iface;

    return S_OK;
}
