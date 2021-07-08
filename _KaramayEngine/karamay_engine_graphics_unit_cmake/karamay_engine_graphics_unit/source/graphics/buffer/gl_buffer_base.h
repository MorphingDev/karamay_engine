#ifndef H_GL_BUFFER_BASE
#define H_GL_BUFFER_BASE

#include "graphics/glo/gl_object.h"

enum class internal_format : GLenum
{
    R8 = GL_R8,
    R16 = GL_R16,
    R16F = GL_R16F,
    R32F = GL_R32F,
    R8I = GL_R8I,
    R16I = GL_R16I,
    R32I = GL_R32I,
    R8UI = GL_R8UI,
    R16UI = GL_R16UI,
    R32UI = GL_R32UI,
    RG8 = GL_RG8,
    RG16 = GL_RG16,
    RG16F = GL_RG16F,
    RG32F = GL_RG32F,
    RG8I = GL_RG8I,
    RG16I = GL_RG16I,
    RG32I = GL_RG32I,
    RG8UI = GL_RG8UI,
    RG16UI = GL_RG16UI,
    RG32UI = GL_RG32UI,
    RGB32F = GL_RGB32F,
    RGB32I = GL_RGB32I,
    RGB32UI = GL_RGB32UI,
    RGBA8 = GL_RGBA8,
    RGBA16 = GL_RGBA16,
    RGBA16F = GL_RGBA16F,
    RGBA32F = GL_RGBA32F,
    RGBA8I = GL_RGBA8I,
    RGBA16I = GL_RGBA16I,
    RGBA32I = GL_RGBA32I,
    RGBA8UI = GL_RGBA8UI,
    RGBA16UI = GL_RGBA16UI,
    RGBA32UI = GL_RGBA32UI
};

enum class format : GLenum
{
    RED = GL_RED,
    RG = GL_RG,
    RGB = GL_RGB,
    BGR = GL_BGR,
    RGBA = GL_RGBA,
    BGRA = GL_BGRA,
    RED_INTEGER = GL_RED_INTEGER,
    RG_INTEGER = GL_RG_INTEGER,
    RGB_INTEGER = GL_RGB_INTEGER,
    BGR_INTEGER = GL_BGR_INTEGER,
    RGBA_INTEGER = GL_RGBA_INTEGER,
    BGRA_INTEGER = GL_BGRA_INTEGER,
    STENCIL_INDEX = GL_STENCIL_INDEX,
    DEPTH_COMPONENT = GL_DEPTH_COMPONENT,
    DEPTH_STENCIL = GL_DEPTH_STENCIL
};

enum class data_type : GLenum
{
    HALF_FLOAT = GL_HALF_FLOAT,
    FLOAT = GL_FLOAT,

    BYTE = GL_BYTE,
    UNSIGNED_BYTE = GL_UNSIGNED_BYTE,
    SHORT = GL_SHORT,
    UNSIGNED_SHORT = GL_UNSIGNED_SHORT,
    INT = GL_INT,
    UNSIGNED_INT = GL_UNSIGNED_INT,

    UNSIGNED_BYTE_3_3_2 = GL_UNSIGNED_BYTE_3_3_2,
    UNSIGNED_BYTE_2_3_3_REV = GL_UNSIGNED_BYTE_2_3_3_REV,
    UNSIGNED_SHORT_5_6_5 = GL_UNSIGNED_SHORT_5_6_5,
    UNSIGNED_SHORT_5_6_5_REV = GL_UNSIGNED_SHORT_5_6_5_REV,
    UNSIGNED_SHORT_4_4_4_4 = GL_UNSIGNED_SHORT_4_4_4_4,
    UNSIGNED_SHORT_4_4_4_4_REV = GL_UNSIGNED_SHORT_4_4_4_4_REV,
    UNSIGNED_SHORT_5_5_5_1 = GL_UNSIGNED_SHORT_5_5_5_1,
    UNSIGNED_SHORT_1_5_5_5_REV = GL_UNSIGNED_SHORT_1_5_5_5_REV,
    UNSIGNED_INT_8_8_8_8 = GL_UNSIGNED_INT_8_8_8_8,
    UNSIGNED_INT_8_8_8_8_REV = GL_UNSIGNED_INT_8_8_8_8_REV,
    UNSIGNED_INT_10_10_10_2 = GL_UNSIGNED_INT_10_10_10_2,
    UNSIGNED_INT_2_10_10_10_REV = GL_UNSIGNED_INT_2_10_10_10_REV
};

enum class access : GLenum
{
    READ_WRITE = GL_READ_WRITE,
    READ_ONLY = GL_READ_ONLY,
    WRITE_ONLY = GL_WRITE_ONLY
};

enum class gl_buffer_storage_flag : GLenum
{
    MAP_READ_BIT = GL_MAP_READ_BIT,
    MAP_WRITE_BIT = GL_MAP_WRITE_BIT,
    DYNAMIC_STORAGE_BIT = GL_DYNAMIC_STORAGE_BIT,
    CLIENT_STORAGE_BIT = GL_CLIENT_STORAGE_BIT,
    MAP_PERSISTENT_BIT = GL_MAP_PERSISTENT_BIT,
    MAP_COHERENT_BIT = GL_MAP_COHERENT_BIT
};

struct gl_buffer_storage_options
{
    std::uint8_t is_map_read;
    std::uint8_t is_map_write;
    std::uint8_t is_dynamic_storage;
    std::uint8_t is_client_storage;
    std::uint8_t is_map_persistent;
    std::uint8_t is_map_coherent;
};

enum class gl_buffer_map_access_flag : GLenum
{
    MAP_READ_BIT = GL_MAP_READ_BIT,
    MAP_WRITE_BIT = GL_MAP_WRITE_BIT,
    MAP_PERSISTENT = GL_MAP_PERSISTENT_BIT,
    MAP_COHERENT_BIT = GL_MAP_COHERENT_BIT,

    MAP_INVALIDATE_RANGE_BIT = GL_MAP_INVALIDATE_RANGE_BIT,
    MAP_INVALIDATE_BUFFER_BIT = GL_MAP_INVALIDATE_BUFFER_BIT,
    MAP_FLUSH_EXPLICIT_BIT = GL_MAP_FLUSH_EXPLICIT_BIT,
    MAP_UNSYNCHRONIZED_BIT = GL_MAP_UNSYNCHRONIZED_BIT
};

enum class gl_buffer_type
{

};

enum class gl_buffer_memory_barrier_flag
{
    VERTEX_ATTRIB_ARRAY_BARRIER_BIT = GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT,
    ELEMENT_ARRAY_BARRIER_BIT = GL_ELEMENT_ARRAY_BARRIER_BIT,
    TRANSFORM_FEEDBACK_BARRIER_BIT = GL_TRANSFORM_FEEDBACK_BARRIER_BIT,

    UNIFORM_BARRIER_BIT = GL_UNIFORM_BARRIER_BIT,
    SHADER_STORAGE_BARRIER_BIT = GL_SHADER_STORAGE_BARRIER_BIT,
    ATOMIC_COUNTER_BARRIER_BIT = GL_ATOMIC_COUNTER_BARRIER_BIT,

    FRAMEBUFFER_BARRIER_BIT = GL_FRAMEBUFFER_BARRIER_BIT,

    TEXTURE_FETCH_BARRIER_BIT = GL_TEXTURE_FETCH_BARRIER_BIT,

    SHADER_IMAGE_ACCESS_BARRIER_BIT = GL_SHADER_IMAGE_ACCESS_BARRIER_BIT,

    COMMAND_BARRIER_BIT = GL_COMMAND_BARRIER_BIT,

    PIXEL_BUFFER_BARRIER_BIT = GL_PIXEL_BUFFER_BARRIER_BIT,

    TEXTURE_UPDATE_BARRIER_BIT = GL_TEXTURE_UPDATE_BARRIER_BIT,
    BUFFER_UPDATE_BARRIER_BIT = GL_BUFFER_UPDATE_BARRIER_BIT
};

enum class gl_buffer_memory_barrier_region_flag
{
    UNIFORM_BARRIER_BIT = GL_UNIFORM_BARRIER_BIT,
    SHADER_STORAGE_BARRIER_BIT = GL_SHADER_STORAGE_BARRIER_BIT,
    ATOMIC_COUNTER_BARRIER_BIT = GL_ATOMIC_COUNTER_BARRIER_BIT,

    FRAMEBUFFER_BARRIER_BIT = GL_FRAMEBUFFER_BARRIER_BIT,

    SHADER_IMAGE_ACCESS_BARRIER_BIT = GL_SHADER_IMAGE_ACCESS_BARRIER_BIT,

    TEXTURE_FETCH_BARRIER_BIT = GL_TEXTURE_FETCH_BARRIER_BIT
};


class gl_buffer_base : public gl_object
{
public:

    const static std::int64_t THEORETICAL_MAX_CAPACITY;
    const static std::int64_t HARDWARE_MAX_CAPACITY;
    const static std::int64_t GPU_MAX_CAPACITY;
    const static std::int64_t BUFFER_AVAILABLE_MAX_CAPACITY;

public:

    explicit gl_buffer_base(std::int64_t capacity, gl_buffer_storage_options storage_options) :
        _capacity(capacity),
        _size(0),
        _storage_flags(0),
        _storage_options(storage_options)
    {
        glCreateBuffers(1, &_handle);
        if(_handle != 0)
        {
            if(storage_options.is_map_read) _storage_flags |= GL_MAP_READ_BIT;
            if(storage_options.is_map_write) _storage_flags |= GL_MAP_WRITE_BIT;
            if(storage_options.is_map_persistent) _storage_flags |= GL_MAP_PERSISTENT_BIT;
            if(storage_options.is_map_coherent) _storage_flags |= GL_MAP_COHERENT_BIT;
            if(storage_options.is_client_storage) _storage_flags |= GL_CLIENT_STORAGE_BIT;
            if(storage_options.is_dynamic_storage) _storage_flags |= GL_DYNAMIC_STORAGE_BIT;

            glNamedBufferStorage(_handle, capacity, nullptr, _storage_flags);
            _capacity = capacity;
        }
    }

    ~gl_buffer_base() override
    {
        glDeleteBuffers(1, &_handle);
    }

public:

    [[nodiscard]] std::int64_t get_capacity() const { return _capacity; }

    [[nodiscard]] std::int64_t get_size() const { return _size; }

    [[nodiscard]] std::uint32_t get_storage_flags() const { return _storage_flags; }

public:

    void reserve(std::int64_t capacity);

    void shrink_to_fit();

public:

    /*
     * [App -> GL]
     * */
    void push_back(const std::uint8_t* data, std::int64_t data_size)
    {
        if(!_storage_options.is_dynamic_storage|| !data || data_size < 0 || _size < 0) return;
        if(_size + data_size > _capacity)  _reallocate(_size + data_size);

        glNamedBufferSubData(_handle, _size, data_size, reinterpret_cast<const void*>(data));

        _size += data_size;
    }

    /*
     * [App -> GL]
     * */
    template<typename GLM_T>
    inline void push_back(const GLM_T& data)
    {
        push_back(reinterpret_cast<const std::uint8_t*>(glm::value_ptr(data)), sizeof (GLM_T));
    }

    /*
     * [App -> GL]
     * */
    template<typename GLM_T>
    inline void push_back(const std::vector<GLM_T>& data_collection)
    {
        push_back(reinterpret_cast<const std::uint8_t*>(data_collection.data()), data_collection.size() * sizeof(GLM_T));
    }

public:

    /*
     * Pure [Client -> Server]
     * offset > 0 && data_size > 0 &&
     * offset + data_size <= _capacity &&
     * data's length == data_size
     * */
    void overwrite(std::int64_t offset, const std::uint8_t* data, std::int64_t data_size);

    /*
     * Pure [Client -> Server]
     * offset > 0 && data_size > 0 &&
     * offset + data_size <= _capacity &&
     * data's length == data_size
     * */
    template<typename GLM_T>
    inline void overwrite(std::int64_t offset, const GLM_T& data)
    {
        overwrite(offset, reinterpret_cast<const std::uint8_t*>(glm::value_ptr(data)), static_cast<std::int64_t>(sizeof(GLM_T)));
    }

    /*
     * Pure [Client -> Server]
     * offset > 0 && data_size > 0 &&
     * offset + data_size <= _capacity &&
     * data's length == data_size
     * */
    template<typename GLM_T>
    inline void overwrite(std::int64_t offset, const std::vector<GLM_T>& data_collection)
    {
        overwrite(offset, reinterpret_cast<const std::uint8_t*>(data_collection.data()), static_cast<std::int64_t>(data_collection.size() * sizeof(GLM_T)));
    }

public:

    /*
     * Mostly [Server -> Server]
     * You must sacrifice some flexibility to get rapid filling.
     * capacity % sizeof (data_mask) == 0
     * */
    void overwrite_by_unit(std::uint8_t unit = 0);

    template<typename GLM_T>
    inline void overwrite_by_unit(const GLM_T& unit)
    {

    }

public:

    /*
     * grab another same buffer storage as new one
     * */
    void invalidate(std::int64_t offset, std::int64_t size);

    void invalidate()
    {
        glInvalidateBufferData(_handle);
    }

public:
    /*
     * Pure [Server -> Server]
     * */
    void output_data_to_buffer(std::int64_t self_offset, int64_t output_size, gl_buffer_base& target, std::int64_t target_offset);

    /*
     * Pure [Server -> Server]
     * */
    void output_data_to_buffer(gl_buffer_base& target_buffer);

public:

    /*
     * map a block of immutable memory
     * then execute a handler you specified (can not do any modification)
     * @ task void(mapped_memory_block, mapped_memory_block_size)
     * */
    void execute_immutable_memory_handler(std::int64_t offset, std::int64_t size, const std::function<void(const std::uint8_t*, std::int64_t)>& handler);

    /*
     * map a block of mutable memory
     * then execute a handler you specified
     * @ task void(mapped_memory_block, mapped_memory_block_size)
     * */
    void execute_mutable_memory_handler(std::int64_t offset, std::int64_t size, const std::function<void(std::uint8_t*, std::int64_t)>& handler);

public:

    [[nodiscard]] std::int64_t get_buffer_size() const
    {
        std::int64_t _buffer_size = 0;
        glGetNamedBufferParameteri64v(_handle, GL_BUFFER_SIZE, &_buffer_size);
        return _buffer_size;
    }

    [[nodiscard]] std::uint8_t is_mapped() const
    {
        std::int32_t _is_mapped = 0;
        glGetNamedBufferParameteriv(_handle, GL_BUFFER_MAPPED, &_is_mapped);
        return _is_mapped == GL_TRUE;
    }

    [[nodiscard]] std::int32_t get_access() const
    {
        std::int32_t _buffer_access = 0;
        glGetNamedBufferParameteriv(_handle, GL_BUFFER_ACCESS, &_buffer_access);
        return _buffer_access;
    }

    [[nodiscard]] std::int32_t get_usage() const
    {
        std::int32_t _buffer_usage = 0;
        glGetNamedBufferParameteriv(_handle, GL_BUFFER_USAGE, &_buffer_usage);
        return _buffer_usage;
    }

protected:

    [[nodiscard]] inline bool _check_capacity(std::int64_t capacity) const
    {
        return capacity != _capacity && capacity < BUFFER_AVAILABLE_MAX_CAPACITY;
    }

public:

    template<typename T>
    void print()
    {
        execute_immutable_memory_handler(0, _size, [](const std::uint8_t* data, std::int64_t size){
            const auto _data = reinterpret_cast<const T*>(data);
            if(_data)
            {
                for(std::int32_t _index = 0; _index < size/ sizeof(T); ++_index)
                {
                    std::cout<<": "<<_data[_index] <<std::endl;

                }
            }
        });
    }

private:

    void _reallocate(std::int64_t new_capacity);

private:

    std::int64_t _capacity, _size;

    std::uint32_t _storage_flags;

    gl_buffer_storage_options _storage_options;



    //    void asynchronous(){}
//
//    void synchronous(){}
//
//    void synchronized(){}


};

#endif
