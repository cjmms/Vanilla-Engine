#include "VanillaEngine.h"


void VanillaEngine::init(void)
{
    initUI();

    if (glewInit() != GLEW_OK) std::cout << "GLEW init error" << std::endl;

    InputMgr.init();

    ResourceManager::getInstance().init();

    entity.spawn();

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
    InputMgr.close();
    closeUI();
}


void VanillaEngine::update(void)
{
    // game loop
    while (!glfwWindowShouldClose(window))
    {
        UpdateFrameTime();
        InputMgr.getInputs(window);

        if (InputMgr.keyIsPressed(GLFW_KEY_W)) entity.moveUp();
        if (InputMgr.keyIsPressed(GLFW_KEY_A)) entity.moveLeft();
        if (InputMgr.keyIsPressed(GLFW_KEY_S)) entity.moveDown();
        if (InputMgr.keyIsPressed(GLFW_KEY_D)) entity.moveRight();
 
        entity.draw();

        glfwSwapBuffers(window);
        limiteFPS(60);
    }
}
    
// object moves base on FPS, this is for testing FPS only
void VanillaEngine::limiteFPS(int fps)
{
    float currentTime = glfwGetTime();
    float waitTime = 1.0f / fps - (currentTime - lastFrame);

    while (glfwGetTime() - currentTime < waitTime);
}




void VanillaEngine::UpdateFrameTime()
{
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    std::cout << "Frame time: " << deltaTime * 1000.0f << "  FPS: " << 1.0f / deltaTime << std::endl;
}