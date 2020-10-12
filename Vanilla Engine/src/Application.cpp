#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Entity.h"


int main()
{
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit()) return -1;

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(1200, 1000, "Vanilla", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    

    // Make the window's context current
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) std::cout << "init error" << std::endl; 


    Entity entity(0.4);
    entity.spawn();


    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        // Render here
        entity.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}