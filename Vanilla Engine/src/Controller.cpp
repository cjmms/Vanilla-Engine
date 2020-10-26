#include "Controller.h"
#include "GameObject.h"

//extern InputManager InputMgr;

Controller::Controller() : Component(CONTROLLER)
{
}


Controller::~Controller()
{}


void Controller::update()
{
    if (InputManager::getInstance().keyIsPressed(GLFW_KEY_W)) owner->transform->moveUp();
    //if (InputMgr->keyIsPressed(GLFW_KEY_A)) owner->transform->moveLeft();
    //if (InputMgr->keyIsPressed(GLFW_KEY_S)) owner->transform->moveDown();
    //if (InputMgr->keyIsPressed(GLFW_KEY_D)) owner->transform->moveRight();
}

