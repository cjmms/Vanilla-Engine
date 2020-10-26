#include "VanillaEngine.h"


void VanillaEngine::init(void)
{
    initUI();

    if (glewInit() != GLEW_OK) std::cout << "GLEW init error" << std::endl;

    InputManager::getInstance().init();
    ResourceManager::getInstance().init();
    


    obj.sprite = new Sprite( "res/Texture/wood.jpg" );

    obj.AddComponent(CONTROLLER);
    obj.AddComponent(TRANSFORM);
    obj.AddComponent(UP_DOWN);


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
 
        obj.update();
        obj.sprite->draw(obj.transform->position);

        FPSController::getInstance().limiteFPS(60);

        glfwSwapBuffers(window);
    }
}
 
