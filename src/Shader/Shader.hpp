/*
** Shader.hpp
** File description:
** Shader class definition
*/

#ifndef SHADER_HPP_
#define SHADER_HPP_

#include <GLES3/gl3.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "ShaderLoader.hpp"

class Shader
{
private:
    const char *_c_str = nullptr;
    std::string _source;
    GLuint _shader;
    bool _here = false;
    GLint _status;
public:
    Shader();
    Shader(const std::string &, int);
    ~Shader();

    void load(const std::string &, int);
    GLuint get() const;
};

#endif /* SHADER_HPP_ */
