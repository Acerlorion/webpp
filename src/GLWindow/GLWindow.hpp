/*
** GLWindow.hpp
** File description:
** GLWindow class definition
*/

#ifndef GLWINDOW_HPP_
#define GLWINDOW_HPP_

#include <GLES3/gl3.h>
#include <GLFW/glfw3.h>

#include <string>

class GLWindow
{
private:
    GLFWwindow *_window = nullptr;
    GLuint _vao = 0;
    int _width = 0;
    int _height = 0;
public:
    GLWindow(unsigned int, unsigned int, const std::string &, bool = false);
    ~GLWindow();

    GLWindow(const GLWindow &) = delete;
    GLWindow(GLWindow &&) = delete;

    GLWindow &operator=(const GLWindow &) = delete;
    GLWindow &operator=(GLWindow &&) = delete;

    bool isOpen() const;
    void close() const;
    void pollEvents() const;
    bool isKeyPressed(int);
    void display();
    void clear(unsigned char, unsigned char, unsigned char, unsigned char);

    const int getWidth() const;
    const int getHeight() const;
};

#endif /* GLWINDOW_HPP_ */
