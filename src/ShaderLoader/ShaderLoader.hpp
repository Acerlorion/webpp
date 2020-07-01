/*
** ShaderLoader.hpp
** File description:
** ShaderLoader class definition
*/

#ifndef SHADERLOADER_HPP_
#define SHADERLOADER_HPP_

#include <fstream>
#include <sstream>

class ShaderLoader
{
public:
    ShaderLoader() = delete;
    ~ShaderLoader() = delete;

    ShaderLoader(const ShaderLoader &) = delete;
    ShaderLoader(ShaderLoader &&) = delete;

    ShaderLoader &operator=(const ShaderLoader &) = delete;
    ShaderLoader &operator=(ShaderLoader &&) = delete;

    static void load(const std::string &, std::string &);
};

#endif /* SHADERLOADER_HPP_ */
