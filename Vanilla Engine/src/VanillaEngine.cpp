#include "VanillaEngine.h"


void VanillaEngine::init(void)
{
    initUI();

    if (glewInit() != GLEW_OK) std::cout << "GLEW init error" << std::endl;

    InputManager::getInstance().init();
    ResourceManager::getInstance().init();

    ResourceManager::getInstance().LoadLevel("res/Data/Level.txt");
}


void VanillaEngine::initUI(void)
{
    // Initialize the library
    if (!glfwInit()) std::cout << "GLFW init error" << std::endl;

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(1200, 1000, "Vanilla", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
}



void VanillaEngine::closeUI(void)
{
    glfwTerminate();
}


void VanillaEngine::close(void)
{
    ObjectManager::getInstance().close();
    ResourceManager::getInstance().close();
    InputManager::getInstance().close();
    closeUI();
}


void VanillaEngine::update(void)
{
    // game loop
    while (!glfwWindowShouldClose(window))
    {
        FPSController::getInstance().UpdateFrameTime();
        InputManager::getInstance().getInputs(window);
 
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        Shader shader("src/demo.shader");

        //Matrix4 perspective = perspective();
            
        ObjectManager::getInstance().update();
        ObjectManager::getInstance().render(shader);


        glfwSwapBuffers(window);
    }
}
 
