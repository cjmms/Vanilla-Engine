#include "Controller.h"
#include "../GameObject.h"

#include "../PhysicsManager.h"

PlayerHitEvent::PlayerHitEvent()
    :Event(EventType::PLAYER_HIT)
{}

PlayerHitEvent::PlayerHitEvent(float time)
    : Event(EventType::PLAYER_HIT, time * 1000.0f)
{}

PlayerHitEvent::~PlayerHitEvent()
{}


//---------------------------------------------------------------


Controller::Controller() : Component(CONTROLLER)
{}


Controller::~Controller()
{}


void Controller::update(void)
{
    if (InputManager::getInstance().keyIsPressed(GLFW_KEY_W)) owner->transform->moveUp();
    if (InputManager::getInstance().keyIsPressed(GLFW_KEY_A)) owner->transform->moveLeft();
    if (InputManager::getInstance().keyIsPressed(GLFW_KEY_S)) owner->transform->moveDown();
    if (InputManager::getInstance().keyIsPressed(GLFW_KEY_D)) owner->transform->moveRight();

    if (InputManager::getInstance().keyIsPressed(GLFW_KEY_K)) owner->RemoveComponent(CONTROLLER);
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

    }
}