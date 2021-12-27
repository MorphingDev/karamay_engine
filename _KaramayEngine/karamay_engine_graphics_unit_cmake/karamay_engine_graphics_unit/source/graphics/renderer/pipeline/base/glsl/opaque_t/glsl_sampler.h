#ifndef GLSL_SAMPLER_H
#define GLSL_SAMPLER_H

#include "../base/glsl_class.h"
#include "../../resource/texture/gl_texture.h"
#include "../../resource/sampler/gl_sampler.h"

class glsl_sampler_t 
{
protected:
    glsl_sampler_t(const std::string& type_token, const std::string var_token) :
        _texture(nullptr),
        _sampler(nullptr),
        _bindless_handle(0)
    {}

    glsl_sampler_t(const glsl_sampler_t&) = delete;
    glsl_sampler_t& operator=(const glsl_sampler_t&) = delete;

    ~glsl_sampler_t() = default;

protected:

    void _set_sampler_internal(gl_texture_t* texture)
    {
        if (!texture) return;

        if (_bindless_handle != 0)
        {
            glMakeTextureHandleNonResidentARB(_bindless_handle);
        }

        _texture = texture;
        _bindless_handle = glGetTextureHandleARB(_texture->get_handle());
        glMakeTextureHandleResidentARB(_bindless_handle);
    }

    void _set_sampler_internal(gl_texture_t* texture, gl_sampler* sampler)
    {
        if (!texture || !sampler) return;

        if (_bindless_handle != 0)
        {
            glMakeTextureHandleNonResidentARB(_bindless_handle);
        }

        _texture = texture;
        _sampler = sampler;
        _bindless_handle = glGetTextureSamplerHandleARB(_texture->get_handle(), _sampler->get_handle());
        glMakeTextureHandleResidentARB(_bindless_handle);
    }

    gl_texture_t* _get_texture() const { return _texture; }

public:

    gl_sampler* get_sampler() const { return _sampler; }

    uint64 get_handle() const { return _bindless_handle; }

private:
    
    gl_texture_t* _texture;

    gl_sampler* _sampler;
    
    uint64 _bindless_handle;

};

class glsl_sampler : public glsl_sampler_t
{
public:
    glsl_sampler(const std::string& type_name, const std::string& var_name) : 
        glsl_sampler_t(type_name, var_name) 
    {}

protected:

    void _set_sampler(gl_texture_t* texture)
    {
        if (!_check_format(texture))
        {
            std::cerr << "internal format must be float about." << std::endl;
            return;
        }
        _set_sampler_internal(texture);
    }

    void _set_sampler(gl_texture_t* texture, gl_sampler* sampler)
    {
        if (!_check_format(texture))
        {
            std::cerr << "internal format must be float about." << std::endl;
            return;
        }
        _set_sampler_internal(texture, sampler);
    }

private:

    bool _check_format(gl_texture_t* texture)
    {
        switch (texture->get_internal_format())
        {
        case gl_texture_internal_format::F_R11_G11_B10: return true;
        case gl_texture_internal_format::R_F32: return true;
        case gl_texture_internal_format::RG_F32: return true;
        case gl_texture_internal_format::RGB_F32: return true;
        case gl_texture_internal_format::RGBA_F32: return true;
        case gl_texture_internal_format::NOR_R_I16: return true;
        case gl_texture_internal_format::NOR_R_I8: return true;
        case gl_texture_internal_format::NOR_RG_I16: return true;
        case gl_texture_internal_format::NOR_RG_I8: return true;
        case gl_texture_internal_format::NOR_RGB_I16: return true;
        case gl_texture_internal_format::NOR_RGB_I8: return true;
        case gl_texture_internal_format::NOR_RGBA_I16: return true;
        case gl_texture_internal_format::NOR_RGBA_I8: return true;
        case gl_texture_internal_format::NOR_R_UI16: return true;
        //case gl_texture_internal_format::NOR_UI_R3_G3_B2: return true;
        case gl_texture_internal_format::NOR_RGB_UI16_5_6_5: return true;
        case gl_texture_internal_format::NOR_R_UI8: return true;
        case gl_texture_internal_format::NOR_RG_UI16: return true;
        case gl_texture_internal_format::NOR_RG_UI8: return true;
        case gl_texture_internal_format::NOR_RGBA_UI32_10_10_10_2: return true;
        case gl_texture_internal_format::NOR_RGB_UI16: return true;
        case gl_texture_internal_format::NOR_RGBA_UI16_5_5_5_1: return true;
        case gl_texture_internal_format::NOR_RGB_UI8: return true;
        case gl_texture_internal_format::NOR_RGBA_UI16: return true;
        //case gl_texture_internal_format::NOR_UI_RGBA2: return true;
        //case gl_texture_internal_format::NOR_UI_RGBA4: return true;
        case gl_texture_internal_format::NOR_RGBA_UI8: return true;
        case gl_texture_internal_format::NOR_UI_SRGB8: return true;
        case gl_texture_internal_format::NOR_UI_SRGB8_ALPHA8: return true;
        default: return false;
        }
    }

};

class glsl_sampler1D : public glsl_sampler
{
public:
    glsl_sampler1D(const std::string& name)
        : glsl_sampler("sampler1D", name)
    {}

    glsl_sampler1D(const glsl_sampler1D&) = delete;
    glsl_sampler1D& operator=(const glsl_sampler1D&) = delete;

    ~glsl_sampler1D() = default;

public:

    void associate(gl_texture_1d* texture) { _set_sampler(texture); }

    void associate(gl_texture_1d* texture, gl_sampler* sampler) { _set_sampler(texture, sampler); }

    gl_texture_1d* get_texture_1d() const { return dynamic_cast<gl_texture_1d*>(_get_texture()); }

};
class glsl_sampler1DArray : public glsl_sampler
{
public:
    glsl_sampler1DArray(const std::string& name) 
        : glsl_sampler("sampler1DArray", name) 
    {}

    glsl_sampler1DArray(const glsl_sampler1DArray&) = delete;
    glsl_sampler1DArray& operator=(const glsl_sampler1DArray&) = delete;

    ~glsl_sampler1DArray() = default;

public:

    void associate(gl_texture_1d_array* texture) { _set_sampler(texture); }

    void associate(gl_texture_1d_array* texture, gl_sampler* sampler) { _set_sampler(texture, sampler); }

    gl_texture_1d_array* get_texture_1d_array() const { return dynamic_cast<gl_texture_1d_array*>(_get_texture()); }

};
class glsl_sampler2D : public glsl_sampler
{
public:
    glsl_sampler2D(const std::string& name)
        : glsl_sampler("sampler2D", name)
    {}

    glsl_sampler2D(const glsl_sampler2D&) = delete;
    glsl_sampler2D& operator=(const glsl_sampler2D&) = delete;

    ~glsl_sampler2D() {}

public:

    void associate(gl_texture_2d* texture) { _set_sampler(texture); }

    void associate(gl_texture_2d* texture, gl_sampler* sampler) { _set_sampler(texture, sampler); }

    gl_texture_2d* get_texture_2d() const { return dynamic_cast<gl_texture_2d*>(_get_texture()); }

};
class glsl_sampler2DArray : public glsl_sampler
{
public:
    glsl_sampler2DArray(const std::string& name)
        : glsl_sampler("sampler2DArray", name)
    {}

    glsl_sampler2DArray(const glsl_sampler2DArray&) = delete;
    glsl_sampler2DArray& operator=(const glsl_sampler2DArray&) = delete;

    ~glsl_sampler2DArray() = default;

public:

    void associate(gl_texture_2d_array* texture) { _set_sampler(texture); }

    void associate(gl_texture_2d_array* texture, gl_sampler* sampler) { _set_sampler(texture, sampler); }

    gl_texture_2d_array* get_texture_2d_array() const { return dynamic_cast<gl_texture_2d_array*>(_get_texture()); }

};
class glsl_sampler2DMS : public glsl_sampler
{
public:
    glsl_sampler2DMS(const std::string& name)
        : glsl_sampler("sampler2DMS", name)
    {}

    glsl_sampler2DMS(const glsl_sampler2DMS&) = delete;
    glsl_sampler2DMS& operator=(const glsl_sampler2DMS&) = delete;

    ~glsl_sampler2DMS() = default;

public:

    void associate(gl_texture_2d_multisample* texture) { _set_sampler(texture); }

    void associate(gl_texture_2d_multisample* texture, gl_sampler* sampler) { _set_sampler(texture, sampler); }

    gl_texture_2d_multisample* get_texture_2d_multisample() const { return dynamic_cast<gl_texture_2d_multisample*>(_get_texture()); }

};
class glsl_sampler2DMSArray : public glsl_sampler
{
public:
    glsl_sampler2DMSArray(const std::string& name)
        : glsl_sampler("sampler2DMSArray", name)
    {}

    glsl_sampler2DMSArray(const glsl_sampler2DMSArray&) = delete;
    glsl_sampler2DMSArray& operator=(const glsl_sampler2DMSArray&) = delete;

    ~glsl_sampler2DMSArray() = default;

public:

    void associate(gl_texture_2d_multisample_array* texture) { _set_sampler(texture); }

    void associate(gl_texture_2d_multisample_array* texture, gl_sampler* sampler) { _set_sampler(texture, sampler); }

    gl_texture_2d_multisample_array* get_texture_2d_multisample_array() const { return dynamic_cast<gl_texture_2d_multisample_array*>(_get_texture()); }

};
class glsl_samplerCube : public glsl_sampler
{
public:
    glsl_samplerCube(const std::string& name)
        : glsl_sampler("samplerCube", name)
    {}

    glsl_samplerCube(const glsl_samplerCube&) = delete;
    glsl_samplerCube& operator=(const glsl_samplerCube&) = delete;

    ~glsl_samplerCube() = default;

public:

    void associate(gl_texture_cube* texture) { _set_sampler(texture); }

    void associate(gl_texture_cube* texture, gl_sampler* sampler) { _set_sampler(texture, sampler); }

    gl_texture_cube* get_texture_cube() const { return dynamic_cast<gl_texture_cube*>(_get_texture()); }

};
class glsl_samplerCubeArray : public glsl_sampler
{
public:
    glsl_samplerCubeArray(const std::string& name)
        : glsl_sampler("samplerCubeArray", name)
    {}

    glsl_samplerCubeArray(const glsl_samplerCubeArray&) = delete;
    glsl_samplerCubeArray& operator=(const glsl_samplerCubeArray&) = delete;

    ~glsl_samplerCubeArray() = default;

public:

    void associate(gl_texture_cube_array* texture) { _set_sampler(texture); }

    void associate(gl_texture_cube_array* texture, gl_sampler* sampler) { _set_sampler(texture, sampler); }

    gl_texture_cube_array* get_texture_cube_array() const { return dynamic_cast<gl_texture_cube_array*>(_get_texture()); }

};
class glsl_sampler2DRect : public glsl_sampler
{
public:
    glsl_sampler2DRect(const std::string& name)
        : glsl_sampler("sampler2DRect", name)
    {}

    glsl_sampler2DRect(const glsl_sampler2DRect&) = delete;
    glsl_sampler2DRect& operator=(const glsl_sampler2DRect&) = delete;

    ~glsl_sampler2DRect() = default;

public:

    void associate(gl_texture_rectangle* texture) { _set_sampler(texture); }

    void associate(gl_texture_rectangle* texture, gl_sampler* sampler) { _set_sampler(texture, sampler); }

    gl_texture_rectangle* get_texture_rectangle() const { return dynamic_cast<gl_texture_rectangle*>(_get_texture()); }

};
class glsl_sampler3D : public glsl_sampler
{
public:
    glsl_sampler3D(const std::string& name)
        : glsl_sampler("sampler3D", name)
    {}

    glsl_sampler3D(const glsl_sampler3D&) = delete;
    glsl_sampler3D& operator=(const glsl_sampler3D&) = delete;

    ~glsl_sampler3D() = default;

public:

    void associate(gl_texture_3d* texture) { _set_sampler(texture); }

    void associate(gl_texture_3d* texture, gl_sampler* sampler) { _set_sampler(texture, sampler); }

    gl_texture_3d* get_texture_3d() const { return dynamic_cast<gl_texture_3d*>(_get_texture()); }

};
class glsl_samplerBuffer : public glsl_sampler
{
public:
    glsl_samplerBuffer(const std::string& name)
        : glsl_sampler("samplerBuffer", name)
    {}

    glsl_samplerBuffer(const glsl_samplerBuffer&) = delete;
    glsl_samplerBuffer& operator=(const glsl_samplerBuffer&) = delete;

    ~glsl_samplerBuffer() = default;

public:

    void associate(gl_texture_buffer* texture) { _set_sampler(texture); }

    void associate(gl_texture_buffer* texture, gl_sampler* sampler) { _set_sampler(texture, sampler); }

    gl_texture_buffer* get_texture_buffer() const { return dynamic_cast<gl_texture_buffer*>(_get_texture()); }

};

class glsl_samplerShadow : public glsl_sampler
{};

class glsl_sampler1DShadow : public glsl_samplerShadow
{

};
class glsl_sampler1DArrayShadow : public glsl_samplerShadow
{

};
class glsl_sampler2DShadow : public glsl_samplerShadow
{};
class glsl_sampler2DArrayShadow : public glsl_samplerShadow
{};
class glsl_samplerCubeShadow : public glsl_samplerShadow
{};
class glsl_samplerCubeArrayShadow : public glsl_samplerShadow
{};
class glsl_sampler2DRectShadow : public glsl_samplerShadow
{};

class glsl_isampler : public glsl_sampler_t
{};

class glsl_isampler1D : public glsl_isampler {};
class glsl_isampler1DArray : public glsl_isampler {};
class glsl_isampler2D : public glsl_isampler {};
class glsl_isampler2DArray : public glsl_isampler {};
class glsl_isampler2DRect : public glsl_isampler {};
class glsl_isampler2DMS : public glsl_isampler {};
class glsl_isampler2DMSArray : public glsl_isampler {};
class glsl_isamplerCube : public glsl_isampler {};
class glsl_isamplerCubeArray : public glsl_isampler {};
class glsl_isampler3D : public glsl_isampler {};
class glsl_isamplerBuffer : public glsl_isampler {};

class glsl_usampler :public glsl_sampler_t
{};

class glsl_usampler1D : public glsl_usampler {};
class glsl_usampler1DArray : public glsl_usampler {};
class glsl_usampler2D : public glsl_usampler {};
class glsl_usampler2DArray : public glsl_usampler {};
class glsl_usampler2DRect : public glsl_usampler {};
class glsl_usampler2DMS : public glsl_usampler {};
class glsl_usampler2DMSArray : public glsl_usampler {};
class glsl_usamplerCube : public glsl_usampler {};
class glsl_usamplerCubeArray : public glsl_usampler {};
class glsl_usampler3D : public glsl_usampler {};
class glsl_usamplerBuffer : public glsl_usampler {};

#endif
