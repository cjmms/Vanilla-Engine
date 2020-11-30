#include "Controller.h"
#include "../GameObject.h"
#include "../EventManager.h"
#include "../PhysicsManager.h"



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


void Controller::HandleEvent(Event* event)
{
    if (event->type == EventType::COLLISION)
    {
        CollideEvent* collideEvent = static_cast<CollideEvent*>(event);
        std::cout << "fewfewfewfw" << std::endl;
    }
}