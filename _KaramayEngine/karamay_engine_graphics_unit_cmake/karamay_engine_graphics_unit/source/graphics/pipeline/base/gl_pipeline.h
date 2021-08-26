#include "graphics/program/gl_program.h"

class gl_pipeline_parameters
{
	std::vector<std::shared_ptr<glsl_uniform_block_t>> uniform_blocks;
	std::vector<std::shared_ptr<glsl_shader_storage_block_t>> shader_storage_blocks;
	std::vector<std::shared_ptr<glsl_image_t>> images;
	std::vector<std::shared_ptr<glsl_sampler_t>> samplers;
	std::vector<std::shared_ptr<glsl_atomic_uint>> atomic_counters;
};

class gl_pipeline
{

public:

	gl_pipeline()
	{
		_program = std::make_shared<gl_program>();
	}

public:

	virtual bool ouput_pipeline_glsl_template(const std::string& renderer_dir) const = 0;

protected:
	
	std::string _name;

	std::shared_ptr<gl_program> _program;

};