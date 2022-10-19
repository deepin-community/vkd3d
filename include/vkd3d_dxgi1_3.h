/*** Autogenerated by WIDL 3.17 from include/vkd3d_dxgi1_3.idl - Do not edit ***/

#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif


#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __vkd3d_dxgi1_3_h_tmp__
#define __vkd3d_dxgi1_3_h_tmp__

/* Forward declarations */

#ifndef __IDXGISwapChain2_FWD_DEFINED__
#define __IDXGISwapChain2_FWD_DEFINED__
typedef interface IDXGISwapChain2 IDXGISwapChain2;
#ifdef __cplusplus
interface IDXGISwapChain2;
#endif /* __cplusplus */
#endif

#ifndef __IDXGIFactory3_FWD_DEFINED__
#define __IDXGIFactory3_FWD_DEFINED__
typedef interface IDXGIFactory3 IDXGIFactory3;
#ifdef __cplusplus
interface IDXGIFactory3;
#endif /* __cplusplus */
#endif

/* Headers for imported files */

#include <vkd3d_dxgi1_2.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct DXGI_MATRIX_3X2_F DXGI_MATRIX_3X2_F;
/*****************************************************************************
 * IDXGISwapChain2 interface
 */
#ifndef __IDXGISwapChain2_INTERFACE_DEFINED__
#define __IDXGISwapChain2_INTERFACE_DEFINED__

DEFINE_GUID(IID_IDXGISwapChain2, 0xa8be2ac4, 0x199f, 0x4946, 0xb3,0x31, 0x79,0x59,0x9f,0xb9,0x8d,0xe7);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("a8be2ac4-199f-4946-b331-79599fb98de7")
IDXGISwapChain2 : public IDXGISwapChain1
{
    virtual HRESULT STDMETHODCALLTYPE SetSourceSize(
        UINT width,
        UINT height) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetSourceSize(
        UINT *width,
        UINT *height) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetMaximumFrameLatency(
        UINT latency) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetMaximumFrameLatency(
        UINT *latency) = 0;

    virtual HANDLE STDMETHODCALLTYPE GetFrameLatencyWaitableObject(
        ) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetMatrixTransform(
        const DXGI_MATRIX_3X2_F *matrix) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetMatrixTransform(
        DXGI_MATRIX_3X2_F *matrix) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IDXGISwapChain2, 0xa8be2ac4, 0x199f, 0x4946, 0xb3,0x31, 0x79,0x59,0x9f,0xb9,0x8d,0xe7)
#endif
#else
typedef struct IDXGISwapChain2Vtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IDXGISwapChain2 *This,
        REFIID riid,
        void **object);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IDXGISwapChain2 *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IDXGISwapChain2 *This);

    /*** IDXGIObject methods ***/
    HRESULT (STDMETHODCALLTYPE *SetPrivateData)(
        IDXGISwapChain2 *This,
        REFGUID name,
        UINT data_size,
        const void *data);

    HRESULT (STDMETHODCALLTYPE *GetPrivateDataInterface)(
        IDXGISwapChain2 *This,
        REFGUID name,
        const IUnknown *unknown);

    HRESULT (STDMETHODCALLTYPE *GetPrivateData)(
        IDXGISwapChain2 *This,
        REFGUID name,
        UINT *data_size,
        void *data);

    HRESULT (STDMETHODCALLTYPE *GetParent)(
        IDXGISwapChain2 *This,
        REFIID riid,
        void **parent);

    /*** IDXGIDeviceSubObject methods ***/
    HRESULT (STDMETHODCALLTYPE *GetDevice)(
        IDXGISwapChain2 *This,
        REFIID riid,
        void **device);

    /*** IDXGISwapChain methods ***/
    HRESULT (STDMETHODCALLTYPE *Present)(
        IDXGISwapChain2 *This,
        UINT sync_interval,
        UINT flags);

    HRESULT (STDMETHODCALLTYPE *GetBuffer)(
        IDXGISwapChain2 *This,
        UINT buffer_idx,
        REFIID riid,
        void **surface);

    HRESULT (STDMETHODCALLTYPE *SetFullscreenState)(
        IDXGISwapChain2 *This,
        BOOL fullscreen,
        IDXGIOutput *target);

    HRESULT (STDMETHODCALLTYPE *GetFullscreenState)(
        IDXGISwapChain2 *This,
        BOOL *fullscreen,
        IDXGIOutput **target);

    HRESULT (STDMETHODCALLTYPE *GetDesc)(
        IDXGISwapChain2 *This,
        DXGI_SWAP_CHAIN_DESC *desc);

    HRESULT (STDMETHODCALLTYPE *ResizeBuffers)(
        IDXGISwapChain2 *This,
        UINT buffer_count,
        UINT width,
        UINT height,
        DXGI_FORMAT format,
        UINT flags);

    HRESULT (STDMETHODCALLTYPE *ResizeTarget)(
        IDXGISwapChain2 *This,
        const DXGI_MODE_DESC *desc);

    HRESULT (STDMETHODCALLTYPE *GetContainingOutput)(
        IDXGISwapChain2 *This,
        IDXGIOutput **output);

    HRESULT (STDMETHODCALLTYPE *GetFrameStatistics)(
        IDXGISwapChain2 *This,
        DXGI_FRAME_STATISTICS *stats);

    HRESULT (STDMETHODCALLTYPE *GetLastPresentCount)(
        IDXGISwapChain2 *This,
        UINT *last_present_count);

    /*** IDXGISwapChain1 methods ***/
    HRESULT (STDMETHODCALLTYPE *GetDesc1)(
        IDXGISwapChain2 *This,
        DXGI_SWAP_CHAIN_DESC1 *desc);

    HRESULT (STDMETHODCALLTYPE *GetFullscreenDesc)(
        IDXGISwapChain2 *This,
        DXGI_SWAP_CHAIN_FULLSCREEN_DESC *desc);

    HRESULT (STDMETHODCALLTYPE *GetHwnd)(
        IDXGISwapChain2 *This,
        HWND *hwnd);

    HRESULT (STDMETHODCALLTYPE *GetCoreWindow)(
        IDXGISwapChain2 *This,
        REFIID riid,
        void **object);

    HRESULT (STDMETHODCALLTYPE *Present1)(
        IDXGISwapChain2 *This,
        UINT sync_interval,
        UINT flags,
        const DXGI_PRESENT_PARAMETERS *parameters);

    BOOL (STDMETHODCALLTYPE *IsTemporaryMonoSupported)(
        IDXGISwapChain2 *This);

    HRESULT (STDMETHODCALLTYPE *GetRestrictToOutput)(
        IDXGISwapChain2 *This,
        IDXGIOutput **output);

    HRESULT (STDMETHODCALLTYPE *SetBackgroundColor)(
        IDXGISwapChain2 *This,
        const DXGI_RGBA *color);

    HRESULT (STDMETHODCALLTYPE *GetBackgroundColor)(
        IDXGISwapChain2 *This,
        DXGI_RGBA *color);

    HRESULT (STDMETHODCALLTYPE *SetRotation)(
        IDXGISwapChain2 *This,
        DXGI_MODE_ROTATION rotation);

    HRESULT (STDMETHODCALLTYPE *GetRotation)(
        IDXGISwapChain2 *This,
        DXGI_MODE_ROTATION *rotation);

    /*** IDXGISwapChain2 methods ***/
    HRESULT (STDMETHODCALLTYPE *SetSourceSize)(
        IDXGISwapChain2 *This,
        UINT width,
        UINT height);

    HRESULT (STDMETHODCALLTYPE *GetSourceSize)(
        IDXGISwapChain2 *This,
        UINT *width,
        UINT *height);

    HRESULT (STDMETHODCALLTYPE *SetMaximumFrameLatency)(
        IDXGISwapChain2 *This,
        UINT latency);

    HRESULT (STDMETHODCALLTYPE *GetMaximumFrameLatency)(
        IDXGISwapChain2 *This,
        UINT *latency);

    HANDLE (STDMETHODCALLTYPE *GetFrameLatencyWaitableObject)(
        IDXGISwapChain2 *This);

    HRESULT (STDMETHODCALLTYPE *SetMatrixTransform)(
        IDXGISwapChain2 *This,
        const DXGI_MATRIX_3X2_F *matrix);

    HRESULT (STDMETHODCALLTYPE *GetMatrixTransform)(
        IDXGISwapChain2 *This,
        DXGI_MATRIX_3X2_F *matrix);

    END_INTERFACE
} IDXGISwapChain2Vtbl;

interface IDXGISwapChain2 {
    CONST_VTBL IDXGISwapChain2Vtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IDXGISwapChain2_QueryInterface(This,riid,object) (This)->lpVtbl->QueryInterface(This,riid,object)
#define IDXGISwapChain2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDXGISwapChain2_Release(This) (This)->lpVtbl->Release(This)
/*** IDXGIObject methods ***/
#define IDXGISwapChain2_SetPrivateData(This,name,data_size,data) (This)->lpVtbl->SetPrivateData(This,name,data_size,data)
#define IDXGISwapChain2_GetPrivateDataInterface(This,name,unknown) (This)->lpVtbl->GetPrivateDataInterface(This,name,unknown)
#define IDXGISwapChain2_GetPrivateData(This,name,data_size,data) (This)->lpVtbl->GetPrivateData(This,name,data_size,data)
#define IDXGISwapChain2_GetParent(This,riid,parent) (This)->lpVtbl->GetParent(This,riid,parent)
/*** IDXGIDeviceSubObject methods ***/
#define IDXGISwapChain2_GetDevice(This,riid,device) (This)->lpVtbl->GetDevice(This,riid,device)
/*** IDXGISwapChain methods ***/
#define IDXGISwapChain2_Present(This,sync_interval,flags) (This)->lpVtbl->Present(This,sync_interval,flags)
#define IDXGISwapChain2_GetBuffer(This,buffer_idx,riid,surface) (This)->lpVtbl->GetBuffer(This,buffer_idx,riid,surface)
#define IDXGISwapChain2_SetFullscreenState(This,fullscreen,target) (This)->lpVtbl->SetFullscreenState(This,fullscreen,target)
#define IDXGISwapChain2_GetFullscreenState(This,fullscreen,target) (This)->lpVtbl->GetFullscreenState(This,fullscreen,target)
#define IDXGISwapChain2_GetDesc(This,desc) (This)->lpVtbl->GetDesc(This,desc)
#define IDXGISwapChain2_ResizeBuffers(This,buffer_count,width,height,format,flags) (This)->lpVtbl->ResizeBuffers(This,buffer_count,width,height,format,flags)
#define IDXGISwapChain2_ResizeTarget(This,desc) (This)->lpVtbl->ResizeTarget(This,desc)
#define IDXGISwapChain2_GetContainingOutput(This,output) (This)->lpVtbl->GetContainingOutput(This,output)
#define IDXGISwapChain2_GetFrameStatistics(This,stats) (This)->lpVtbl->GetFrameStatistics(This,stats)
#define IDXGISwapChain2_GetLastPresentCount(This,last_present_count) (This)->lpVtbl->GetLastPresentCount(This,last_present_count)
/*** IDXGISwapChain1 methods ***/
#define IDXGISwapChain2_GetDesc1(This,desc) (This)->lpVtbl->GetDesc1(This,desc)
#define IDXGISwapChain2_GetFullscreenDesc(This,desc) (This)->lpVtbl->GetFullscreenDesc(This,desc)
#define IDXGISwapChain2_GetHwnd(This,hwnd) (This)->lpVtbl->GetHwnd(This,hwnd)
#define IDXGISwapChain2_GetCoreWindow(This,riid,object) (This)->lpVtbl->GetCoreWindow(This,riid,object)
#define IDXGISwapChain2_Present1(This,sync_interval,flags,parameters) (This)->lpVtbl->Present1(This,sync_interval,flags,parameters)
#define IDXGISwapChain2_IsTemporaryMonoSupported(This) (This)->lpVtbl->IsTemporaryMonoSupported(This)
#define IDXGISwapChain2_GetRestrictToOutput(This,output) (This)->lpVtbl->GetRestrictToOutput(This,output)
#define IDXGISwapChain2_SetBackgroundColor(This,color) (This)->lpVtbl->SetBackgroundColor(This,color)
#define IDXGISwapChain2_GetBackgroundColor(This,color) (This)->lpVtbl->GetBackgroundColor(This,color)
#define IDXGISwapChain2_SetRotation(This,rotation) (This)->lpVtbl->SetRotation(This,rotation)
#define IDXGISwapChain2_GetRotation(This,rotation) (This)->lpVtbl->GetRotation(This,rotation)
/*** IDXGISwapChain2 methods ***/
#define IDXGISwapChain2_SetSourceSize(This,width,height) (This)->lpVtbl->SetSourceSize(This,width,height)
#define IDXGISwapChain2_GetSourceSize(This,width,height) (This)->lpVtbl->GetSourceSize(This,width,height)
#define IDXGISwapChain2_SetMaximumFrameLatency(This,latency) (This)->lpVtbl->SetMaximumFrameLatency(This,latency)
#define IDXGISwapChain2_GetMaximumFrameLatency(This,latency) (This)->lpVtbl->GetMaximumFrameLatency(This,latency)
#define IDXGISwapChain2_GetFrameLatencyWaitableObject(This) (This)->lpVtbl->GetFrameLatencyWaitableObject(This)
#define IDXGISwapChain2_SetMatrixTransform(This,matrix) (This)->lpVtbl->SetMatrixTransform(This,matrix)
#define IDXGISwapChain2_GetMatrixTransform(This,matrix) (This)->lpVtbl->GetMatrixTransform(This,matrix)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT IDXGISwapChain2_QueryInterface(IDXGISwapChain2* This,REFIID riid,void **object) {
    return This->lpVtbl->QueryInterface(This,riid,object);
}
static FORCEINLINE ULONG IDXGISwapChain2_AddRef(IDXGISwapChain2* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG IDXGISwapChain2_Release(IDXGISwapChain2* This) {
    return This->lpVtbl->Release(This);
}
/*** IDXGIObject methods ***/
static FORCEINLINE HRESULT IDXGISwapChain2_SetPrivateData(IDXGISwapChain2* This,REFGUID name,UINT data_size,const void *data) {
    return This->lpVtbl->SetPrivateData(This,name,data_size,data);
}
static FORCEINLINE HRESULT IDXGISwapChain2_GetPrivateDataInterface(IDXGISwapChain2* This,REFGUID name,const IUnknown *unknown) {
    return This->lpVtbl->GetPrivateDataInterface(This,name,unknown);
}
static FORCEINLINE HRESULT IDXGISwapChain2_GetPrivateData(IDXGISwapChain2* This,REFGUID name,UINT *data_size,void *data) {
    return This->lpVtbl->GetPrivateData(This,name,data_size,data);
}
static FORCEINLINE HRESULT IDXGISwapChain2_GetParent(IDXGISwapChain2* This,REFIID riid,void **parent) {
    return This->lpVtbl->GetParent(This,riid,parent);
}
/*** IDXGIDeviceSubObject methods ***/
static FORCEINLINE HRESULT IDXGISwapChain2_GetDevice(IDXGISwapChain2* This,REFIID riid,void **device) {
    return This->lpVtbl->GetDevice(This,riid,device);
}
/*** IDXGISwapChain methods ***/
static FORCEINLINE HRESULT IDXGISwapChain2_Present(IDXGISwapChain2* This,UINT sync_interval,UINT flags) {
    return This->lpVtbl->Present(This,sync_interval,flags);
}
static FORCEINLINE HRESULT IDXGISwapChain2_GetBuffer(IDXGISwapChain2* This,UINT buffer_idx,REFIID riid,void **surface) {
    return This->lpVtbl->GetBuffer(This,buffer_idx,riid,surface);
}
static FORCEINLINE HRESULT IDXGISwapChain2_SetFullscreenState(IDXGISwapChain2* This,BOOL fullscreen,IDXGIOutput *target) {
    return This->lpVtbl->SetFullscreenState(This,fullscreen,target);
}
static FORCEINLINE HRESULT IDXGISwapChain2_GetFullscreenState(IDXGISwapChain2* This,BOOL *fullscreen,IDXGIOutput **target) {
    return This->lpVtbl->GetFullscreenState(This,fullscreen,target);
}
static FORCEINLINE HRESULT IDXGISwapChain2_GetDesc(IDXGISwapChain2* This,DXGI_SWAP_CHAIN_DESC *desc) {
    return This->lpVtbl->GetDesc(This,desc);
}
static FORCEINLINE HRESULT IDXGISwapChain2_ResizeBuffers(IDXGISwapChain2* This,UINT buffer_count,UINT width,UINT height,DXGI_FORMAT format,UINT flags) {
    return This->lpVtbl->ResizeBuffers(This,buffer_count,width,height,format,flags);
}
static FORCEINLINE HRESULT IDXGISwapChain2_ResizeTarget(IDXGISwapChain2* This,const DXGI_MODE_DESC *desc) {
    return This->lpVtbl->ResizeTarget(This,desc);
}
static FORCEINLINE HRESULT IDXGISwapChain2_GetContainingOutput(IDXGISwapChain2* This,IDXGIOutput **output) {
    return This->lpVtbl->GetContainingOutput(This,output);
}
static FORCEINLINE HRESULT IDXGISwapChain2_GetFrameStatistics(IDXGISwapChain2* This,DXGI_FRAME_STATISTICS *stats) {
    return This->lpVtbl->GetFrameStatistics(This,stats);
}
static FORCEINLINE HRESULT IDXGISwapChain2_GetLastPresentCount(IDXGISwapChain2* This,UINT *last_present_count) {
    return This->lpVtbl->GetLastPresentCount(This,last_present_count);
}
/*** IDXGISwapChain1 methods ***/
static FORCEINLINE HRESULT IDXGISwapChain2_GetDesc1(IDXGISwapChain2* This,DXGI_SWAP_CHAIN_DESC1 *desc) {
    return This->lpVtbl->GetDesc1(This,desc);
}
static FORCEINLINE HRESULT IDXGISwapChain2_GetFullscreenDesc(IDXGISwapChain2* This,DXGI_SWAP_CHAIN_FULLSCREEN_DESC *desc) {
    return This->lpVtbl->GetFullscreenDesc(This,desc);
}
static FORCEINLINE HRESULT IDXGISwapChain2_GetHwnd(IDXGISwapChain2* This,HWND *hwnd) {
    return This->lpVtbl->GetHwnd(This,hwnd);
}
static FORCEINLINE HRESULT IDXGISwapChain2_GetCoreWindow(IDXGISwapChain2* This,REFIID riid,void **object) {
    return This->lpVtbl->GetCoreWindow(This,riid,object);
}
static FORCEINLINE HRESULT IDXGISwapChain2_Present1(IDXGISwapChain2* This,UINT sync_interval,UINT flags,const DXGI_PRESENT_PARAMETERS *parameters) {
    return This->lpVtbl->Present1(This,sync_interval,flags,parameters);
}
static FORCEINLINE BOOL IDXGISwapChain2_IsTemporaryMonoSupported(IDXGISwapChain2* This) {
    return This->lpVtbl->IsTemporaryMonoSupported(This);
}
static FORCEINLINE HRESULT IDXGISwapChain2_GetRestrictToOutput(IDXGISwapChain2* This,IDXGIOutput **output) {
    return This->lpVtbl->GetRestrictToOutput(This,output);
}
static FORCEINLINE HRESULT IDXGISwapChain2_SetBackgroundColor(IDXGISwapChain2* This,const DXGI_RGBA *color) {
    return This->lpVtbl->SetBackgroundColor(This,color);
}
static FORCEINLINE HRESULT IDXGISwapChain2_GetBackgroundColor(IDXGISwapChain2* This,DXGI_RGBA *color) {
    return This->lpVtbl->GetBackgroundColor(This,color);
}
static FORCEINLINE HRESULT IDXGISwapChain2_SetRotation(IDXGISwapChain2* This,DXGI_MODE_ROTATION rotation) {
    return This->lpVtbl->SetRotation(This,rotation);
}
static FORCEINLINE HRESULT IDXGISwapChain2_GetRotation(IDXGISwapChain2* This,DXGI_MODE_ROTATION *rotation) {
    return This->lpVtbl->GetRotation(This,rotation);
}
/*** IDXGISwapChain2 methods ***/
static FORCEINLINE HRESULT IDXGISwapChain2_SetSourceSize(IDXGISwapChain2* This,UINT width,UINT height) {
    return This->lpVtbl->SetSourceSize(This,width,height);
}
static FORCEINLINE HRESULT IDXGISwapChain2_GetSourceSize(IDXGISwapChain2* This,UINT *width,UINT *height) {
    return This->lpVtbl->GetSourceSize(This,width,height);
}
static FORCEINLINE HRESULT IDXGISwapChain2_SetMaximumFrameLatency(IDXGISwapChain2* This,UINT latency) {
    return This->lpVtbl->SetMaximumFrameLatency(This,latency);
}
static FORCEINLINE HRESULT IDXGISwapChain2_GetMaximumFrameLatency(IDXGISwapChain2* This,UINT *latency) {
    return This->lpVtbl->GetMaximumFrameLatency(This,latency);
}
static FORCEINLINE HANDLE IDXGISwapChain2_GetFrameLatencyWaitableObject(IDXGISwapChain2* This) {
    return This->lpVtbl->GetFrameLatencyWaitableObject(This);
}
static FORCEINLINE HRESULT IDXGISwapChain2_SetMatrixTransform(IDXGISwapChain2* This,const DXGI_MATRIX_3X2_F *matrix) {
    return This->lpVtbl->SetMatrixTransform(This,matrix);
}
static FORCEINLINE HRESULT IDXGISwapChain2_GetMatrixTransform(IDXGISwapChain2* This,DXGI_MATRIX_3X2_F *matrix) {
    return This->lpVtbl->GetMatrixTransform(This,matrix);
}
#endif
#endif

#endif


#endif  /* __IDXGISwapChain2_INTERFACE_DEFINED__ */

/*****************************************************************************
 * IDXGIFactory3 interface
 */
#ifndef __IDXGIFactory3_INTERFACE_DEFINED__
#define __IDXGIFactory3_INTERFACE_DEFINED__

DEFINE_GUID(IID_IDXGIFactory3, 0x25483823, 0xcd46, 0x4c7d, 0x86,0xca, 0x47,0xaa,0x95,0xb8,0x37,0xbd);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("25483823-cd46-4c7d-86ca-47aa95b837bd")
IDXGIFactory3 : public IDXGIFactory2
{
    virtual UINT STDMETHODCALLTYPE GetCreationFlags(
        ) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IDXGIFactory3, 0x25483823, 0xcd46, 0x4c7d, 0x86,0xca, 0x47,0xaa,0x95,0xb8,0x37,0xbd)
#endif
#else
typedef struct IDXGIFactory3Vtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IDXGIFactory3 *This,
        REFIID riid,
        void **object);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IDXGIFactory3 *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IDXGIFactory3 *This);

    /*** IDXGIObject methods ***/
    HRESULT (STDMETHODCALLTYPE *SetPrivateData)(
        IDXGIFactory3 *This,
        REFGUID name,
        UINT data_size,
        const void *data);

    HRESULT (STDMETHODCALLTYPE *GetPrivateDataInterface)(
        IDXGIFactory3 *This,
        REFGUID name,
        const IUnknown *unknown);

    HRESULT (STDMETHODCALLTYPE *GetPrivateData)(
        IDXGIFactory3 *This,
        REFGUID name,
        UINT *data_size,
        void *data);

    HRESULT (STDMETHODCALLTYPE *GetParent)(
        IDXGIFactory3 *This,
        REFIID riid,
        void **parent);

    /*** IDXGIFactory methods ***/
    HRESULT (STDMETHODCALLTYPE *EnumAdapters)(
        IDXGIFactory3 *This,
        UINT adapter_idx,
        IDXGIAdapter **adapter);

    HRESULT (STDMETHODCALLTYPE *MakeWindowAssociation)(
        IDXGIFactory3 *This,
        HWND hwnd,
        UINT flags);

    HRESULT (STDMETHODCALLTYPE *GetWindowAssociation)(
        IDXGIFactory3 *This,
        HWND *hwnd);

    HRESULT (STDMETHODCALLTYPE *CreateSwapChain)(
        IDXGIFactory3 *This,
        IUnknown *device,
        DXGI_SWAP_CHAIN_DESC *desc,
        IDXGISwapChain **swapchain);

    HRESULT (STDMETHODCALLTYPE *CreateSoftwareAdapter)(
        IDXGIFactory3 *This,
        HMODULE hmodule,
        IDXGIAdapter **adapter);

    /*** IDXGIFactory1 methods ***/
    HRESULT (STDMETHODCALLTYPE *EnumAdapters1)(
        IDXGIFactory3 *This,
        UINT adapter_idx,
        IDXGIAdapter1 **adpter);

    BOOL (STDMETHODCALLTYPE *IsCurrent)(
        IDXGIFactory3 *This);

    /*** IDXGIFactory2 methods ***/
    BOOL (STDMETHODCALLTYPE *IsWindowedStereoEnabled)(
        IDXGIFactory3 *This);

    HRESULT (STDMETHODCALLTYPE *CreateSwapChainForHwnd)(
        IDXGIFactory3 *This,
        IUnknown *device,
        HWND window,
        const DXGI_SWAP_CHAIN_DESC1 *desc,
        const DXGI_SWAP_CHAIN_FULLSCREEN_DESC *fullscreen_desc,
        IDXGIOutput *output,
        IDXGISwapChain1 **swapchain);

    HRESULT (STDMETHODCALLTYPE *CreateSwapChainForCoreWindow)(
        IDXGIFactory3 *This,
        IUnknown *device,
        IUnknown *window,
        const DXGI_SWAP_CHAIN_DESC1 *desc,
        IDXGIOutput *output,
        IDXGISwapChain1 **swapchain);

    HRESULT (STDMETHODCALLTYPE *GetSharedResourceAdapterLuid)(
        IDXGIFactory3 *This,
        HANDLE resource,
        LUID *luid);

    HRESULT (STDMETHODCALLTYPE *RegisterStereoStatusWindow)(
        IDXGIFactory3 *This,
        HWND window,
        UINT msg,
        DWORD *cookie);

    HRESULT (STDMETHODCALLTYPE *RegisterStereoStatusEvent)(
        IDXGIFactory3 *This,
        HANDLE event,
        DWORD *cookie);

    void (STDMETHODCALLTYPE *UnregisterStereoStatus)(
        IDXGIFactory3 *This,
        DWORD cookie);

    HRESULT (STDMETHODCALLTYPE *RegisterOcclusionStatusWindow)(
        IDXGIFactory3 *This,
        HWND window,
        UINT msg,
        DWORD *cookie);

    HRESULT (STDMETHODCALLTYPE *RegisterOcclusionStatusEvent)(
        IDXGIFactory3 *This,
        HANDLE event,
        DWORD *cookie);

    void (STDMETHODCALLTYPE *UnregisterOcclusionStatus)(
        IDXGIFactory3 *This,
        DWORD cookie);

    HRESULT (STDMETHODCALLTYPE *CreateSwapChainForComposition)(
        IDXGIFactory3 *This,
        IUnknown *device,
        const DXGI_SWAP_CHAIN_DESC1 *desc,
        IDXGIOutput *output,
        IDXGISwapChain1 **swapchain);

    /*** IDXGIFactory3 methods ***/
    UINT (STDMETHODCALLTYPE *GetCreationFlags)(
        IDXGIFactory3 *This);

    END_INTERFACE
} IDXGIFactory3Vtbl;

interface IDXGIFactory3 {
    CONST_VTBL IDXGIFactory3Vtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IDXGIFactory3_QueryInterface(This,riid,object) (This)->lpVtbl->QueryInterface(This,riid,object)
#define IDXGIFactory3_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDXGIFactory3_Release(This) (This)->lpVtbl->Release(This)
/*** IDXGIObject methods ***/
#define IDXGIFactory3_SetPrivateData(This,name,data_size,data) (This)->lpVtbl->SetPrivateData(This,name,data_size,data)
#define IDXGIFactory3_GetPrivateDataInterface(This,name,unknown) (This)->lpVtbl->GetPrivateDataInterface(This,name,unknown)
#define IDXGIFactory3_GetPrivateData(This,name,data_size,data) (This)->lpVtbl->GetPrivateData(This,name,data_size,data)
#define IDXGIFactory3_GetParent(This,riid,parent) (This)->lpVtbl->GetParent(This,riid,parent)
/*** IDXGIFactory methods ***/
#define IDXGIFactory3_EnumAdapters(This,adapter_idx,adapter) (This)->lpVtbl->EnumAdapters(This,adapter_idx,adapter)
#define IDXGIFactory3_MakeWindowAssociation(This,hwnd,flags) (This)->lpVtbl->MakeWindowAssociation(This,hwnd,flags)
#define IDXGIFactory3_GetWindowAssociation(This,hwnd) (This)->lpVtbl->GetWindowAssociation(This,hwnd)
#define IDXGIFactory3_CreateSwapChain(This,device,desc,swapchain) (This)->lpVtbl->CreateSwapChain(This,device,desc,swapchain)
#define IDXGIFactory3_CreateSoftwareAdapter(This,hmodule,adapter) (This)->lpVtbl->CreateSoftwareAdapter(This,hmodule,adapter)
/*** IDXGIFactory1 methods ***/
#define IDXGIFactory3_EnumAdapters1(This,adapter_idx,adpter) (This)->lpVtbl->EnumAdapters1(This,adapter_idx,adpter)
#define IDXGIFactory3_IsCurrent(This) (This)->lpVtbl->IsCurrent(This)
/*** IDXGIFactory2 methods ***/
#define IDXGIFactory3_IsWindowedStereoEnabled(This) (This)->lpVtbl->IsWindowedStereoEnabled(This)
#define IDXGIFactory3_CreateSwapChainForHwnd(This,device,window,desc,fullscreen_desc,output,swapchain) (This)->lpVtbl->CreateSwapChainForHwnd(This,device,window,desc,fullscreen_desc,output,swapchain)
#define IDXGIFactory3_CreateSwapChainForCoreWindow(This,device,window,desc,output,swapchain) (This)->lpVtbl->CreateSwapChainForCoreWindow(This,device,window,desc,output,swapchain)
#define IDXGIFactory3_GetSharedResourceAdapterLuid(This,resource,luid) (This)->lpVtbl->GetSharedResourceAdapterLuid(This,resource,luid)
#define IDXGIFactory3_RegisterStereoStatusWindow(This,window,msg,cookie) (This)->lpVtbl->RegisterStereoStatusWindow(This,window,msg,cookie)
#define IDXGIFactory3_RegisterStereoStatusEvent(This,event,cookie) (This)->lpVtbl->RegisterStereoStatusEvent(This,event,cookie)
#define IDXGIFactory3_UnregisterStereoStatus(This,cookie) (This)->lpVtbl->UnregisterStereoStatus(This,cookie)
#define IDXGIFactory3_RegisterOcclusionStatusWindow(This,window,msg,cookie) (This)->lpVtbl->RegisterOcclusionStatusWindow(This,window,msg,cookie)
#define IDXGIFactory3_RegisterOcclusionStatusEvent(This,event,cookie) (This)->lpVtbl->RegisterOcclusionStatusEvent(This,event,cookie)
#define IDXGIFactory3_UnregisterOcclusionStatus(This,cookie) (This)->lpVtbl->UnregisterOcclusionStatus(This,cookie)
#define IDXGIFactory3_CreateSwapChainForComposition(This,device,desc,output,swapchain) (This)->lpVtbl->CreateSwapChainForComposition(This,device,desc,output,swapchain)
/*** IDXGIFactory3 methods ***/
#define IDXGIFactory3_GetCreationFlags(This) (This)->lpVtbl->GetCreationFlags(This)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT IDXGIFactory3_QueryInterface(IDXGIFactory3* This,REFIID riid,void **object) {
    return This->lpVtbl->QueryInterface(This,riid,object);
}
static FORCEINLINE ULONG IDXGIFactory3_AddRef(IDXGIFactory3* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG IDXGIFactory3_Release(IDXGIFactory3* This) {
    return This->lpVtbl->Release(This);
}
/*** IDXGIObject methods ***/
static FORCEINLINE HRESULT IDXGIFactory3_SetPrivateData(IDXGIFactory3* This,REFGUID name,UINT data_size,const void *data) {
    return This->lpVtbl->SetPrivateData(This,name,data_size,data);
}
static FORCEINLINE HRESULT IDXGIFactory3_GetPrivateDataInterface(IDXGIFactory3* This,REFGUID name,const IUnknown *unknown) {
    return This->lpVtbl->GetPrivateDataInterface(This,name,unknown);
}
static FORCEINLINE HRESULT IDXGIFactory3_GetPrivateData(IDXGIFactory3* This,REFGUID name,UINT *data_size,void *data) {
    return This->lpVtbl->GetPrivateData(This,name,data_size,data);
}
static FORCEINLINE HRESULT IDXGIFactory3_GetParent(IDXGIFactory3* This,REFIID riid,void **parent) {
    return This->lpVtbl->GetParent(This,riid,parent);
}
/*** IDXGIFactory methods ***/
static FORCEINLINE HRESULT IDXGIFactory3_EnumAdapters(IDXGIFactory3* This,UINT adapter_idx,IDXGIAdapter **adapter) {
    return This->lpVtbl->EnumAdapters(This,adapter_idx,adapter);
}
static FORCEINLINE HRESULT IDXGIFactory3_MakeWindowAssociation(IDXGIFactory3* This,HWND hwnd,UINT flags) {
    return This->lpVtbl->MakeWindowAssociation(This,hwnd,flags);
}
static FORCEINLINE HRESULT IDXGIFactory3_GetWindowAssociation(IDXGIFactory3* This,HWND *hwnd) {
    return This->lpVtbl->GetWindowAssociation(This,hwnd);
}
static FORCEINLINE HRESULT IDXGIFactory3_CreateSwapChain(IDXGIFactory3* This,IUnknown *device,DXGI_SWAP_CHAIN_DESC *desc,IDXGISwapChain **swapchain) {
    return This->lpVtbl->CreateSwapChain(This,device,desc,swapchain);
}
static FORCEINLINE HRESULT IDXGIFactory3_CreateSoftwareAdapter(IDXGIFactory3* This,HMODULE hmodule,IDXGIAdapter **adapter) {
    return This->lpVtbl->CreateSoftwareAdapter(This,hmodule,adapter);
}
/*** IDXGIFactory1 methods ***/
static FORCEINLINE HRESULT IDXGIFactory3_EnumAdapters1(IDXGIFactory3* This,UINT adapter_idx,IDXGIAdapter1 **adpter) {
    return This->lpVtbl->EnumAdapters1(This,adapter_idx,adpter);
}
static FORCEINLINE BOOL IDXGIFactory3_IsCurrent(IDXGIFactory3* This) {
    return This->lpVtbl->IsCurrent(This);
}
/*** IDXGIFactory2 methods ***/
static FORCEINLINE BOOL IDXGIFactory3_IsWindowedStereoEnabled(IDXGIFactory3* This) {
    return This->lpVtbl->IsWindowedStereoEnabled(This);
}
static FORCEINLINE HRESULT IDXGIFactory3_CreateSwapChainForHwnd(IDXGIFactory3* This,IUnknown *device,HWND window,const DXGI_SWAP_CHAIN_DESC1 *desc,const DXGI_SWAP_CHAIN_FULLSCREEN_DESC *fullscreen_desc,IDXGIOutput *output,IDXGISwapChain1 **swapchain) {
    return This->lpVtbl->CreateSwapChainForHwnd(This,device,window,desc,fullscreen_desc,output,swapchain);
}
static FORCEINLINE HRESULT IDXGIFactory3_CreateSwapChainForCoreWindow(IDXGIFactory3* This,IUnknown *device,IUnknown *window,const DXGI_SWAP_CHAIN_DESC1 *desc,IDXGIOutput *output,IDXGISwapChain1 **swapchain) {
    return This->lpVtbl->CreateSwapChainForCoreWindow(This,device,window,desc,output,swapchain);
}
static FORCEINLINE HRESULT IDXGIFactory3_GetSharedResourceAdapterLuid(IDXGIFactory3* This,HANDLE resource,LUID *luid) {
    return This->lpVtbl->GetSharedResourceAdapterLuid(This,resource,luid);
}
static FORCEINLINE HRESULT IDXGIFactory3_RegisterStereoStatusWindow(IDXGIFactory3* This,HWND window,UINT msg,DWORD *cookie) {
    return This->lpVtbl->RegisterStereoStatusWindow(This,window,msg,cookie);
}
static FORCEINLINE HRESULT IDXGIFactory3_RegisterStereoStatusEvent(IDXGIFactory3* This,HANDLE event,DWORD *cookie) {
    return This->lpVtbl->RegisterStereoStatusEvent(This,event,cookie);
}
static FORCEINLINE void IDXGIFactory3_UnregisterStereoStatus(IDXGIFactory3* This,DWORD cookie) {
    This->lpVtbl->UnregisterStereoStatus(This,cookie);
}
static FORCEINLINE HRESULT IDXGIFactory3_RegisterOcclusionStatusWindow(IDXGIFactory3* This,HWND window,UINT msg,DWORD *cookie) {
    return This->lpVtbl->RegisterOcclusionStatusWindow(This,window,msg,cookie);
}
static FORCEINLINE HRESULT IDXGIFactory3_RegisterOcclusionStatusEvent(IDXGIFactory3* This,HANDLE event,DWORD *cookie) {
    return This->lpVtbl->RegisterOcclusionStatusEvent(This,event,cookie);
}
static FORCEINLINE void IDXGIFactory3_UnregisterOcclusionStatus(IDXGIFactory3* This,DWORD cookie) {
    This->lpVtbl->UnregisterOcclusionStatus(This,cookie);
}
static FORCEINLINE HRESULT IDXGIFactory3_CreateSwapChainForComposition(IDXGIFactory3* This,IUnknown *device,const DXGI_SWAP_CHAIN_DESC1 *desc,IDXGIOutput *output,IDXGISwapChain1 **swapchain) {
    return This->lpVtbl->CreateSwapChainForComposition(This,device,desc,output,swapchain);
}
/*** IDXGIFactory3 methods ***/
static FORCEINLINE UINT IDXGIFactory3_GetCreationFlags(IDXGIFactory3* This) {
    return This->lpVtbl->GetCreationFlags(This);
}
#endif
#endif

#endif


#endif  /* __IDXGIFactory3_INTERFACE_DEFINED__ */

/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __vkd3d_dxgi1_3_h_tmp__ */
