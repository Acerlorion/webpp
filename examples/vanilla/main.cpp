/*
** main.cpp
** File description:
** showing a rotating cube 
*/

#include <iostream>

#include "GLWindow.hpp"
#include "CustomCube.hpp"

int main(void)
{
    GLWindow window(1920, 1080, "OpenGL");
    CustomCube cube(window);

    if (window.isOpen()) {
        window.pollEvents();
        if (window.isKeyPressed(GLFW_KEY_ESCAPE) == true) {
            window.close();
        }
	    window.clear(128, 128, 128, 255);
	    cube.draw();
        window.display();
    } else {
	    return 0;
    }
}
