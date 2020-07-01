/*
** ShaderLoader.cpp
** File description:
** ShaderLoader class implementation
*/

#include "ShaderLoader.hpp"

void ShaderLoader::load(const std::string &path, std::string &data)
{
    std::fstream fstream(path);
    std::stringstream sstream;

    sstream << fstream.rdbuf();
    data = sstream.str();
    fstream.close();
}
