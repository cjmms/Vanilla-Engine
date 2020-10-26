#include "FPSController.h"


// object moves base on FPS, this is for testing FPS only
void FPSController::limiteFPS(int fps)
{
    float currentTime = glfwGetTime();
    float waitTime = 1.0f / fps - (currentTime - lastFrame);

    while (glfwGetTime() - currentTime < waitTime);
}




void FPSController::UpdateFrameTime()
{
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    //std::cout << "Frame time: " << deltaTime * 1000.0f << "  FPS: " << 1.0f / deltaTime << std::endl;
}


FPSController& FPSController::getInstance()
{
    static FPSController controller;
    return controller;
}


FPSController::FPSController()
{}

FPSController::~FPSController()
{}