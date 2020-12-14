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

void Controller::deploy()
{
    Attribute* attribute = static_cast<Attribute*>(owner->GetComponent(ATTRIBUTE));

    if (InputManager::getInstance().keyIsPressed(GLFW_KEY_K)) {
        owner->RemoveComponent(CONTROLLER);
        if (attribute != nullptr) attribute->deploied = true;
    }
}

void Controller::move()
{
    Transform* transform = static_cast<Transform*>(owner->GetComponent(TRANSFORM));
    if (transform == nullptr) return;

    if (InputManager::getInstance().keyIsPressed(GLFW_KEY_W)) transform->moveUp();
    if (InputManager::getInstance().keyIsPressed(GLFW_KEY_A)) transform->moveLeft();
    if (InputManager::getInstance().keyIsPressed(GLFW_KEY_S)) transform->moveDown();
    if (InputManager::getInstance().keyIsPressed(GLFW_KEY_D)) transform->moveRight();


    std::cout << "position: " << transform->position.x << ", " << transform->position.y << std::endl;
}


void Controller::update(void)
{
    move();
    deploy();
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