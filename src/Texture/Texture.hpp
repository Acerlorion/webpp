/*
** Texture.hpp
** File description:
** Texture class definition
*/

#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_

#include <GLES3/gl3.h>
#include "GLFW/glfw3.h"

#include "SOIL/SOIL.h"

#include <string>

class Texture
{
private:
    int _width = 0;
    int _height = 0;
    unsigned char *_texture = nullptr;
    GLuint _texture_id;
    bool _here = false;
public:
    Texture();
    Texture(const std::string &);
    ~Texture();

    const GLuint get() const;
    void load(const std::string &);
};

#endif /* TEXTURE_HPP_ */
