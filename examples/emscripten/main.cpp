/*
** main.cpp
** File description:
** showing a rotating cube 
*/

#include <iostream>
#include <emscripten.h>

#include "GLWindow.hpp"
#include "CustomCube.hpp"

static void update(void)
{
    static GLWindow window(1920, 1080, "OpenGL");
    static CustomCube cube(window);

    if (window.isOpen()) {
        window.pollEvents();
        if (window.isKeyPressed(GLFW_KEY_ESCAPE) == true) {
            window.close();
        }
	    window.clear(128, 128, 128, 255);
	    cube.draw();
        window.display();
    } else {
	    exit(0);
    }
}

int main(void)
{
    emscripten_set_main_loop(update, 30, true);
    return 0;
}
