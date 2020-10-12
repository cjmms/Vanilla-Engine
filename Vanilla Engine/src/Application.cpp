#include "VanillaEngine.h"


int main()
{
    VanillaEngine Engine;
    Engine.init();
    

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(Engine.window))
    {
        Engine.update();

        glfwSwapBuffers(Engine.window);
        glfwPollEvents();
    }

    Engine.close();
    return 0;
}