/*
** CustomCube.hpp
** File description:
** CustomCube class definition
*/

#ifndef CUSTOMCUBE_HPP_
#define CUSTOMCUBE_HPP_

#include <GLES3/gl3.h>
#include <GLFW/glfw3.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <vector>
#include <iostream>
#include <chrono>

#include "Shader.hpp"
#include "Texture.hpp"
#include "GLWindow.hpp"

class CustomCube
{
private:
    std::vector<GLfloat> _vertices = {
	/* X, Y, Z, TEXTUREX, TEXTUREY, R, G, B */
	-0.5, -0.5, 0.5, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	0.5, -0.5, 0.5, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	0.5,  0.5, 0.5, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f,
	-0.5,  0.5, 0.5, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
	/* X, Y, Z, TEXTUREX, TEXTUREY, R, G, B */
	-0.5, -0.5, -0.5, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f,
	-0.5, -0.5, 0.5, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f,
	-0.5,  0.5, 0.5, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f,
	-0.5,  0.5, -0.5, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f,
	/* X, Y, Z, TEXTUREX, TEXTUREY, R, G, B */
	-0.5, -0.5, -0.5, -1.0f, -1.0f, 0.0f, 0.5f, 0.5f,
	0.5, -0.5, -0.5, -1.0f, -1.0f, 0.0f, 0.5f, 0.5f,
	0.5,  0.5, -0.5, -1.0f, -1.0f, 0.0f, 0.5f, 0.5f,
	-0.5,  0.5, -0.5, -1.0f, -1.0f, 0.0f, 0.5f, 0.5f,
	/* X, Y, Z, TEXTUREX, TEXTUREY, R, G, B */
	0.5, -0.5, 0.5, -1.0f, -1.0f, 0.5f, 0.0f, 0.5f,
	0.5, -0.5, -0.5, -1.0f, -1.0f, 0.5f, 0.0f, 0.5f,
	0.5,  0.5, -0.5, -1.0f, -1.0f, 0.5f, 0.0f, 0.5f,
	0.5,  0.5, 0.5, -1.0f, -1.0f, 0.5f, 0.0f, 0.5f,
	/* X, Y, Z, TEXTUREX, TEXTUREY, R, G, B */
	-0.5, 0.5, 0.5, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f,
	0.5, 0.5, 0.5, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f,
	0.5,  0.5, -0.5, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f,
	-0.5,  0.5, -0.5, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f,
	/* X, Y, Z, TEXTUREX, TEXTUREY, R, G, B */
	-0.5, -0.5, 0.5, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
	0.5, -0.5, 0.5, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
	0.5,  -0.5, -0.5, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
	-0.5,  -0.5, -0.5, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
    };
    std::vector<GLuint> _elements = {
	0, 1, 2, 2, 3, 0,
	4, 5, 6, 6, 7, 4,
	8, 9, 10, 10, 11, 8,
	12, 13, 14, 14, 15, 12,
	16, 17, 18, 18, 19, 16,
	20, 21, 22, 22, 23, 20
    };

    Shader _fragmentShader;
    Shader _vertexShader;
    Texture _texture;
    GLuint _vbo = 0;
    GLuint _ebo = 0;
    GLuint _shaderProgram = 0;

    GLint _posAttrib = 0;
    GLint _texAttrib = 0;
    GLint _colorAttrib = 0;
    GLint _uniTrans = 0;
    GLint _uniView = 0;
    GLint _uniProj = 0;

    glm::mat4 _trans;
    glm::mat4 _view;
    glm::mat4 _proj;

    std::chrono::steady_clock::time_point _start;
    std::chrono::steady_clock::time_point _animation;
    float _time = 0;

    float _window_ratio = 0;
public:
    CustomCube(const GLWindow &);
    ~CustomCube();

    CustomCube(const CustomCube &) = delete;
    CustomCube(CustomCube &&) = delete;

    CustomCube &operator=(const CustomCube &) = delete;
    CustomCube &operator=(CustomCube &&) = delete;

    void draw();
};

#endif /* CUSTOMCUBE_HPP_ */
