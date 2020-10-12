#include "VanillaEngine.h"


void VanillaEngine::init(void)
{
    initUI();

    if (glewInit() != GLEW_OK) std::cout << "GLEW init error" << std::endl;

    InputMgr.init();

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

    closeUI();
}


void VanillaEngine::update(void)
{
    InputMgr.getInputs(window);

    if (InputMgr.keyIsPressed(GLFW_KEY_W)) entity.moveUp(); 
    if (InputMgr.keyIsPressed(GLFW_KEY_A)) entity.moveLeft();
    if (InputMgr.keyIsPressed(GLFW_KEY_S)) entity.moveDown();
    if (InputMgr.keyIsPressed(GLFW_KEY_D)) entity.moveRight();
 
    entity.draw();
}
    