/*
** GLWindow.cpp
** File description:
** GLWindow class implementation
*/

#include "GLWindow.hpp"

GLWindow::GLWindow(unsigned int width, unsigned int height, const std::string &title, bool full) : _width(width), _height(height)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    if (full == true) {
	_window = glfwCreateWindow(width, height, title.c_str(), glfwGetPrimaryMonitor(), nullptr);
    } else {
	_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    }
    glfwMakeContextCurrent(_window);
    glEnable(GL_DEPTH_TEST);
    glGenVertexArrays(1, &_vao);
    glBindVertexArray(_vao);
}

GLWindow::~GLWindow()
{
    glDeleteVertexArrays(1, &_vao);
    glfwTerminate();
}

bool GLWindow::isOpen() const
{
    return (!glfwWindowShouldClose(_window));
}

void GLWindow::close() const
{
    glfwSetWindowShouldClose(_window, GL_TRUE);
}

void GLWindow::pollEvents() const
{
    glfwPollEvents();
}

bool GLWindow::isKeyPressed(int keycode)
{
    return (glfwGetKey(_window, keycode) == GLFW_PRESS);
}

void GLWindow::display()
{
    glfwSwapBuffers(_window);
}

void GLWindow::clear(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    glClearColor(r / 255.0f, g / 255.0F, b / 255.0f, a / 255.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

const int GLWindow::getWidth() const
{
    return _width;
}

const int GLWindow::getHeight() const
{
    return _height;
}
