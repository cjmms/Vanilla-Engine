#include "Controller.h"
#include "../GameObject.h"



Controller::Controller() : Component(CONTROLLER)
{
}


Controller::~Controller()
{}


void Controller::update(void)
{
    if (InputManager::getInstance().keyIsPressed(GLFW_KEY_W)) owner->transform->moveUp();
    if (InputManager::getInstance().keyIsPressed(GLFW_KEY_A)) owner->transform->moveLeft();
    if (InputManager::getInstance().keyIsPressed(GLFW_KEY_S)) owner->transform->moveDown();
    if (InputManager::getInstance().keyIsPressed(GLFW_KEY_D)) owner->transform->moveRight();
}


void Controller::Serialize(std::ifstream& stream)
{
    std::cout << "Serializing Controller" << std::endl;
}
