#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Shader.h"


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


    float vertices[] = {
        // positions         
         0.5f, -0.5f, 0.0f,    // bottom right
        -0.5f, -0.5f, 0.0f,   // bottom left
         0.0f,  0.5f, 0.0f   // top
    };

    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // VAO
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    Shader shader("src/demo.shader");
    shader.Bind();


    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        // Render here
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}