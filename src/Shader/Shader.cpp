/*
** Shader.cpp
** File description:
** Shader class implementation
*/

#include "Shader.hpp"

Shader::Shader()
{
}

Shader::Shader(const std::string &path, int type)
{   
    ShaderLoader::load(path, _source);
    _shader = glCreateShader(type);
    _c_str = _source.c_str();
    glShaderSource(_shader, 1, &_c_str, nullptr);
    glCompileShader(_shader);
    glGetShaderiv(_shader, GL_COMPILE_STATUS, &_status);
    if (_status != GL_TRUE) {
	std::cout << "Shader at location : " << path << " failed to compile." << std::endl;
	char buffer[512];
	glGetShaderInfoLog(_shader, 512, nullptr, buffer);
	std::cout << buffer << std::endl;
    }
    _here = true;
}

Shader::~Shader()
{
    glDeleteShader(_shader);
}

void Shader::load(const std::string &path, int type)
{
    if (_here == true) {
	glDeleteShader(_shader);
    }
    ShaderLoader::load(path, _source);
    _shader = glCreateShader(type);
    _c_str = _source.c_str();
    glShaderSource(_shader, 1, &_c_str, nullptr);
    glCompileShader(_shader);
    glGetShaderiv(_shader, GL_COMPILE_STATUS, &_status);
    if (_status != GL_TRUE) {
	std::cout << "Shader at location : " << path << " failed to compile." << std::endl;
	char buffer[512];
	glGetShaderInfoLog(_shader, 512, nullptr, buffer);
	std::cout << buffer << std::endl;
    }
}

GLuint Shader::get() const
{
    return _shader;
}
