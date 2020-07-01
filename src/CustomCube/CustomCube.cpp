/*
** CustomCube.cpp
** File description:
** CustomCube class implementation
*/

#include "CustomCube.hpp"

CustomCube::CustomCube(const GLWindow &window)
{
    glGenBuffers(1, &_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(GLfloat), _vertices.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &_ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _elements.size() * sizeof(GLuint), _elements.data(), GL_STATIC_DRAW);

    _vertexShader.load("shaders/vertexShader.glsl", GL_VERTEX_SHADER);
    _fragmentShader.load("shaders/fragmentShader.glsl", GL_FRAGMENT_SHADER);

    _shaderProgram = glCreateProgram();
    glAttachShader(_shaderProgram, _vertexShader.get());
    glAttachShader(_shaderProgram, _fragmentShader.get());
    glLinkProgram(_shaderProgram);
    glUseProgram(_shaderProgram);

    _posAttrib = glGetAttribLocation(_shaderProgram, "position");
    glEnableVertexAttribArray(_posAttrib);
    glVertexAttribPointer(_posAttrib, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);

    _texAttrib = glGetAttribLocation(_shaderProgram, "texcoord");
    glEnableVertexAttribArray(_texAttrib);
    glVertexAttribPointer(_texAttrib, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void *)(3 * sizeof(GLfloat)));

    _colorAttrib = glGetAttribLocation(_shaderProgram, "color");
    glEnableVertexAttribArray(_colorAttrib);
    glVertexAttribPointer(_colorAttrib, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void *)(5 * sizeof(GLfloat))); 

    _texture.load("assets/shocked_pikachu.png");

    _uniTrans = glGetUniformLocation(_shaderProgram, "trans");
    _trans = glm::mat4(1.0f);

    _view = glm::lookAt(glm::vec3(1.2f, 1.2f, 1.2f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    _uniView = glGetUniformLocation(_shaderProgram, "view");
    glUniformMatrix4fv(_uniView, 1, GL_FALSE, glm::value_ptr(_view));

    _window_ratio = (window.getWidth() * 1.0f) / (window.getHeight() * 1.0f);
    _proj = glm::perspective(glm::radians(70.0f), _window_ratio, 1.0f, 10.0f);
    _uniProj = glGetUniformLocation(_shaderProgram, "proj");
    glUniformMatrix4fv(_uniProj, 1, GL_FALSE, glm::value_ptr(_proj));

    _start = std::chrono::steady_clock::now();
    _animation = std::chrono::steady_clock::now();
}

CustomCube::~CustomCube()
{
    glDeleteProgram(_shaderProgram);
    glDeleteBuffers(1, &_vbo);
    glDeleteBuffers(1, &_ebo);
}

void CustomCube::draw()
{
    _animation = std::chrono::steady_clock::now();
    _time = std::chrono::duration_cast<std::chrono::duration<float>>(_animation - _start).count();
    _trans = glm::rotate(_trans, _time * glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    glUniformMatrix4fv(_uniTrans, 1, GL_FALSE, glm::value_ptr(_trans));
    _start = std::chrono::steady_clock::now();

    glDrawElements(GL_TRIANGLES, _elements.size(), GL_UNSIGNED_INT, 0);
}
