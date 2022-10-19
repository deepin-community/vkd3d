/*
 * Copyright 2017 Józef Kucia for CodeWeavers
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

#ifndef __VKD3D_SHADER_H
#define __VKD3D_SHADER_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#define VKD3D_FORCE_32_BIT_ENUM(name) name##_FORCE_32BIT = 0x7fffffff

enum vkd3d_result
{
    VKD3D_OK = 0,
    VKD3D_ERROR = -1, /* unspecified failure */
    VKD3D_ERROR_OUT_OF_MEMORY = -2,
    VKD3D_ERROR_INVALID_ARGUMENT = -3,
    VKD3D_ERROR_NOT_IMPLEMENTED = -4,

    VKD3D_FORCE_32_BIT_ENUM(VKD3D_RESULT),
};

enum vkd3d_shader_compiler_option
{
    VKD3D_SHADER_STRIP_DEBUG = 0x00000001,

    VKD3D_FORCE_32_BIT_ENUM(VKD3D_SHADER_COMPILER_OPTION),
};

enum vkd3d_shader_visibility
{
    VKD3D_SHADER_VISIBILITY_ALL = 0,
    VKD3D_SHADER_VISIBILITY_VERTEX = 1,
    VKD3D_SHADER_VISIBILITY_HULL = 2,
    VKD3D_SHADER_VISIBILITY_DOMAIN = 3,
    VKD3D_SHADER_VISIBILITY_GEOMETRY = 4,
    VKD3D_SHADER_VISIBILITY_PIXEL = 5,

    VKD3D_FORCE_32_BIT_ENUM(VKD3D_SHADER_VISIBILITY),
};

struct vkd3d_shader_code
{
    const void *code;
    size_t size;
};

enum vkd3d_shader_descriptor_type
{
    VKD3D_SHADER_DESCRIPTOR_TYPE_UNKNOWN,
    VKD3D_SHADER_DESCRIPTOR_TYPE_CBV,     /* cb# */
    VKD3D_SHADER_DESCRIPTOR_TYPE_SRV,     /* t#  */
    VKD3D_SHADER_DESCRIPTOR_TYPE_UAV,     /* u#  */
    VKD3D_SHADER_DESCRIPTOR_TYPE_SAMPLER, /* s#  */

    VKD3D_FORCE_32_BIT_ENUM(VKD3D_SHADER_DESCRIPTOR_TYPE),
};

struct vkd3d_shader_descriptor_binding
{
    uint32_t set;
    uint32_t binding;
};

struct vkd3d_shader_resource_binding
{
    enum vkd3d_shader_descriptor_type type;
    unsigned int register_index;
    enum vkd3d_shader_visibility shader_visibility;
    bool is_buffer;

    struct vkd3d_shader_descriptor_binding binding;
};

struct vkd3d_shader_uav_counter_binding
{
    unsigned int register_index; /* u# */

    struct vkd3d_shader_descriptor_binding binding;
};

struct vkd3d_shader_push_constant_buffer
{
    unsigned int register_index;
    enum vkd3d_shader_visibility shader_visibility;

    unsigned int offset; /* in bytes */
    unsigned int size;   /* in bytes */
};

struct vkd3d_shader_interface
{
    const struct vkd3d_shader_resource_binding *bindings;
    unsigned int binding_count;

    const struct vkd3d_shader_push_constant_buffer *push_constant_buffers;
    unsigned int push_constant_buffer_count;

    /* A sampler used by OpImageFetches generated for SM4 ld instructions.
     *
     * In Vulkan OpImageFetch must be used with a sampled image.
     */
    struct vkd3d_shader_descriptor_binding dummy_sampler;

    const struct vkd3d_shader_uav_counter_binding *uav_counters;
    unsigned int uav_counter_count;
};

struct vkd3d_shader_compile_arguments
{
    unsigned int *output_swizzles;
    unsigned int output_swizzle_count;
};

int vkd3d_shader_compile_dxbc(const struct vkd3d_shader_code *dxbc,
        struct vkd3d_shader_code *spirv, uint32_t compiler_options,
        const struct vkd3d_shader_interface *shader_interface,
        const struct vkd3d_shader_compile_arguments *compile_args);
void vkd3d_shader_free_shader_code(struct vkd3d_shader_code *code);

enum vkd3d_filter
{
    VKD3D_FILTER_MIN_MAG_MIP_POINT = 0x0,
    VKD3D_FILTER_MIN_MAG_POINT_MIP_LINEAR = 0x1,
    VKD3D_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT = 0x4,
    VKD3D_FILTER_MIN_POINT_MAG_MIP_LINEAR = 0x5,
    VKD3D_FILTER_MIN_LINEAR_MAG_MIP_POINT = 0x10,
    VKD3D_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x11,
    VKD3D_FILTER_MIN_MAG_LINEAR_MIP_POINT = 0x14,
    VKD3D_FILTER_MIN_MAG_MIP_LINEAR = 0x15,
    VKD3D_FILTER_ANISOTROPIC = 0x55,
    VKD3D_FILTER_COMPARISON_MIN_MAG_MIP_POINT = 0x80,
    VKD3D_FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR = 0x81,
    VKD3D_FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT = 0x84,
    VKD3D_FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR = 0x85,
    VKD3D_FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT = 0x90,
    VKD3D_FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x91,
    VKD3D_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT = 0x94,
    VKD3D_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR = 0x95,
    VKD3D_FILTER_COMPARISON_ANISOTROPIC = 0xd5,
    VKD3D_FILTER_MINIMUM_MIN_MAG_MIP_POINT = 0x100,
    VKD3D_FILTER_MINIMUM_MIN_MAG_POINT_MIP_LINEAR = 0x101,
    VKD3D_FILTER_MINIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT = 0x104,
    VKD3D_FILTER_MINIMUM_MIN_POINT_MAG_MIP_LINEAR = 0x105,
    VKD3D_FILTER_MINIMUM_MIN_LINEAR_MAG_MIP_POINT = 0x110,
    VKD3D_FILTER_MINIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x111,
    VKD3D_FILTER_MINIMUM_MIN_MAG_LINEAR_MIP_POINT = 0x114,
    VKD3D_FILTER_MINIMUM_MIN_MAG_MIP_LINEAR = 0x115,
    VKD3D_FILTER_MINIMUM_ANISOTROPIC = 0x155,
    VKD3D_FILTER_MAXIMUM_MIN_MAG_MIP_POINT = 0x180,
    VKD3D_FILTER_MAXIMUM_MIN_MAG_POINT_MIP_LINEAR = 0x181,
    VKD3D_FILTER_MAXIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT = 0x184,
    VKD3D_FILTER_MAXIMUM_MIN_POINT_MAG_MIP_LINEAR = 0x185,
    VKD3D_FILTER_MAXIMUM_MIN_LINEAR_MAG_MIP_POINT = 0x190,
    VKD3D_FILTER_MAXIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x191,
    VKD3D_FILTER_MAXIMUM_MIN_MAG_LINEAR_MIP_POINT = 0x194,
    VKD3D_FILTER_MAXIMUM_MIN_MAG_MIP_LINEAR = 0x195,
    VKD3D_FILTER_MAXIMUM_ANISOTROPIC = 0x1d5,

    VKD3D_FORCE_32_BIT_ENUM(VKD3D_FILTER),
};

enum vkd3d_texture_address_mode
{
    VKD3D_TEXTURE_ADDRESS_MODE_WRAP = 1,
    VKD3D_TEXTURE_ADDRESS_MODE_MIRROR = 2,
    VKD3D_TEXTURE_ADDRESS_MODE_CLAMP = 3,
    VKD3D_TEXTURE_ADDRESS_MODE_BORDER = 4,
    VKD3D_TEXTURE_ADDRESS_MODE_MIRROR_ONCE = 5,

    VKD3D_FORCE_32_BIT_ENUM(VKD3D_TEXTURE_ADDRESS_MODE),
};

enum vkd3d_comparison_func
{
    VKD3D_COMPARISON_FUNC_NEVER = 1,
    VKD3D_COMPARISON_FUNC_LESS = 2,
    VKD3D_COMPARISON_FUNC_EQUAL = 3,
    VKD3D_COMPARISON_FUNC_LESS_EQUAL = 4,
    VKD3D_COMPARISON_FUNC_GREATER = 5,
    VKD3D_COMPARISON_FUNC_NOT_EQUAL = 6,
    VKD3D_COMPARISON_FUNC_GREATER_EQUAL = 7,
    VKD3D_COMPARISON_FUNC_ALWAYS = 8,

    VKD3D_FORCE_32_BIT_ENUM(VKD3D_COMPARISON_FUNC),
};

enum vkd3d_static_border_color
{
    VKD3D_STATIC_BORDER_COLOR_TRANSPARENT_BLACK = 0,
    VKD3D_STATIC_BORDER_COLOR_OPAQUE_BLACK = 1,
    VKD3D_STATIC_BORDER_COLOR_OPAQUE_WHITE = 2,

    VKD3D_FORCE_32_BIT_ENUM(VKD3D_STATIC_BORDER_COLOR),
};

struct vkd3d_static_sampler_desc
{
    enum vkd3d_filter filter;
    enum vkd3d_texture_address_mode address_u;
    enum vkd3d_texture_address_mode address_v;
    enum vkd3d_texture_address_mode address_w;
    float mip_lod_bias;
    unsigned int max_anisotropy;
    enum vkd3d_comparison_func comparison_func;
    enum vkd3d_static_border_color border_color;
    float min_lod;
    float max_lod;
    unsigned int shader_register;
    unsigned int register_space;
    enum vkd3d_shader_visibility shader_visibility;
};

enum vkd3d_descriptor_range_type
{
    VKD3D_DESCRIPTOR_RANGE_TYPE_SRV = 0,
    VKD3D_DESCRIPTOR_RANGE_TYPE_UAV = 1,
    VKD3D_DESCRIPTOR_RANGE_TYPE_CBV = 2,
    VKD3D_DESCRIPTOR_RANGE_TYPE_SAMPLER = 3,

    VKD3D_FORCE_32_BIT_ENUM(VKD3D_DESCRIPTOR_RANGE_TYPE),
};

struct vkd3d_descriptor_range
{
    enum vkd3d_descriptor_range_type range_type;
    unsigned int descriptor_count;
    unsigned int base_shader_register;
    unsigned int register_space;
    unsigned int descriptor_table_offset;
};

struct vkd3d_root_descriptor_table
{
    unsigned int descriptor_range_count;
    const struct vkd3d_descriptor_range *descriptor_ranges;
};

struct vkd3d_root_constants
{
    unsigned int shader_register;
    unsigned int register_space;
    unsigned int value_count;
};

struct vkd3d_root_descriptor
{
    unsigned int shader_register;
    unsigned int register_space;
};

enum vkd3d_root_parameter_type
{
    VKD3D_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE = 0,
    VKD3D_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS = 1,
    VKD3D_ROOT_PARAMETER_TYPE_CBV = 2,
    VKD3D_ROOT_PARAMETER_TYPE_SRV = 3,
    VKD3D_ROOT_PARAMETER_TYPE_UAV = 4,

    VKD3D_FORCE_32_BIT_ENUM(VKD3D_ROOT_PARAMETER_TYPE),
};

struct vkd3d_root_parameter
{
    enum vkd3d_root_parameter_type parameter_type;
    union
    {
        struct vkd3d_root_descriptor_table descriptor_table;
        struct vkd3d_root_constants constants;
        struct vkd3d_root_descriptor descriptor;
    } u;
    enum vkd3d_shader_visibility shader_visibility;
};

enum vkd3d_root_signature_flags
{
    VKD3D_ROOT_SIGNATURE_FLAG_NONE = 0x0,
    VKD3D_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT = 0x1,
    VKD3D_ROOT_SIGNATURE_FLAG_DENY_VERTEX_SHADER_ROOT_ACCESS = 0x2,
    VKD3D_ROOT_SIGNATURE_FLAG_DENY_HULL_SHADER_ROOT_ACCESS = 0x4,
    VKD3D_ROOT_SIGNATURE_FLAG_DENY_DOMAIN_SHADER_ROOT_ACCESS = 0x8,
    VKD3D_ROOT_SIGNATURE_FLAG_DENY_GEOMETRY_SHADER_ROOT_ACCESS = 0x10,
    VKD3D_ROOT_SIGNATURE_FLAG_DENY_PIXEL_SHADER_ROOT_ACCESS = 0x20,
    VKD3D_ROOT_SIGNATURE_FLAG_ALLOW_STREAM_OUTPUT = 0x40,

    VKD3D_FORCE_32_BIT_ENUM(VKD3D_ROOT_SIGNATURE_FLAGS),
};

struct vkd3d_root_signature_desc
{
    unsigned int parameter_count;
    const struct vkd3d_root_parameter *parameters;
    unsigned int static_sampler_count;
    const struct vkd3d_static_sampler_desc *static_samplers;
    enum vkd3d_root_signature_flags flags;
};

int vkd3d_shader_parse_root_signature(const struct vkd3d_shader_code *dxbc,
        struct vkd3d_root_signature_desc *root_signature);
void vkd3d_shader_free_root_signature(struct vkd3d_root_signature_desc *root_signature);

enum vkd3d_root_signature_version
{
    VKD3D_ROOT_SIGNATURE_VERSION_1_0 = 0x1,

    VKD3D_FORCE_32_BIT_ENUM(VKD3D_ROOT_SIGNATURE_VERSION),
};

int vkd3d_shader_serialize_root_signature(const struct vkd3d_root_signature_desc *root_signature,
        enum vkd3d_root_signature_version version, struct vkd3d_shader_code *dxbc);

#define VKD3D_SHADER_MAX_UNORDERED_ACCESS_VIEWS 8

struct vkd3d_shader_scan_info
{
    unsigned int uav_read_mask : VKD3D_SHADER_MAX_UNORDERED_ACCESS_VIEWS;
    unsigned int uav_counter_mask : VKD3D_SHADER_MAX_UNORDERED_ACCESS_VIEWS;
};

int vkd3d_shader_scan_dxbc(const struct vkd3d_shader_code *dxbc,
        struct vkd3d_shader_scan_info *scan_info);

enum vkd3d_component_type
{
    VKD3D_TYPE_VOID    = 0,
    VKD3D_TYPE_UINT    = 1,
    VKD3D_TYPE_INT     = 2,
    VKD3D_TYPE_FLOAT   = 3,
    VKD3D_TYPE_BOOL,
    VKD3D_TYPE_COUNT,

    VKD3D_FORCE_32_BIT_ENUM(VKD3D_COMPONENT_TYPE),
};

enum vkd3d_sysval_semantic
{
    VKD3D_SV_POSITION                  = 1,
    VKD3D_SV_CLIP_DISTANCE             = 2,
    VKD3D_SV_CULL_DISTANCE             = 3,
    VKD3D_SV_RENDER_TARGET_ARRAY_INDEX = 4,
    VKD3D_SV_VIEWPORT_ARRAY_INDEX      = 5,
    VKD3D_SV_VERTEX_ID                 = 6,
    VKD3D_SV_PRIMITIVE_ID              = 7,
    VKD3D_SV_INSTANCE_ID               = 8,
    VKD3D_SV_IS_FRONT_FACE             = 9,
    VKD3D_SV_SAMPLE_INDEX              = 10,
    VKD3D_SV_TESS_FACTOR_QUADEDGE      = 11,
    VKD3D_SV_TESS_FACTOR_QUADINT       = 12,
    VKD3D_SV_TESS_FACTOR_TRIEDGE       = 13,
    VKD3D_SV_TESS_FACTOR_TRIINT        = 14,
    VKD3D_SV_TESS_FACTOR_LINEDET       = 15,
    VKD3D_SV_TESS_FACTOR_LINEDEN       = 16,

    VKD3D_FORCE_32_BIT_ENUM(VKD3D_SYSVAL_SEMANTIC),
};

struct vkd3d_shader_signature_element
{
    const char *semantic_name;
    unsigned int semantic_index;
    unsigned int stream_index;
    enum vkd3d_sysval_semantic sysval_semantic;
    enum vkd3d_component_type component_type;
    unsigned int register_index;
    unsigned int mask;
};

struct vkd3d_shader_signature
{
    struct vkd3d_shader_signature_element *elements;
    unsigned int element_count;
};

int vkd3d_shader_parse_input_signature(const struct vkd3d_shader_code *dxbc,
        struct vkd3d_shader_signature *signature);
struct vkd3d_shader_signature_element *vkd3d_shader_find_signature_element(
        const struct vkd3d_shader_signature *signature, const char *semantic_name,
        unsigned int semantic_index, unsigned int stream_index);
void vkd3d_shader_free_shader_signature(struct vkd3d_shader_signature *signature);

/* swizzle bits fields: wwzzyyxx */
#define VKD3D_SWIZZLE_X (0u)
#define VKD3D_SWIZZLE_Y (1u)
#define VKD3D_SWIZZLE_Z (2u)
#define VKD3D_SWIZZLE_W (3u)
#define VKD3D_SWIZZLE_MASK (0x3u)
#define VKD3D_SWIZZLE_SHIFT(idx) (2u * (idx))
#define VKD3D_SWIZZLE(x, y, z, w) (((x & VKD3D_SWIZZLE_MASK) << VKD3D_SWIZZLE_SHIFT(0)) \
        | ((y & VKD3D_SWIZZLE_MASK) << VKD3D_SWIZZLE_SHIFT(1)) \
        | ((z & VKD3D_SWIZZLE_MASK) << VKD3D_SWIZZLE_SHIFT(2)) \
        | ((w & VKD3D_SWIZZLE_MASK) << VKD3D_SWIZZLE_SHIFT(3)))
#define VKD3D_NO_SWIZZLE \
        VKD3D_SWIZZLE(VKD3D_SWIZZLE_X, VKD3D_SWIZZLE_Y, VKD3D_SWIZZLE_Z, VKD3D_SWIZZLE_W)

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* __VKD3D_SHADER_H */
