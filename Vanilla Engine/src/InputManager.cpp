#include "InputManager.h"

InputManager::InputManager()
{}

InputManager::~InputManager()
{}

void InputManager::getInputs(GLFWwindow* window)
{
    glfwPollEvents();

    // iterate all events, update map
    for (auto it : keyboardEventMap)
        keyboardEventMap[it.first] = glfwGetKey(window, it.first) == GLFW_PRESS;
    
}

bool InputManager::keyIsPressed(int key)
{
    // key does not exist return false
    if (keyboardEventMap.find(key) == keyboardEventMap.end()) return false;

    return keyboardEventMap[key];
}



InputManager& InputManager::getInstance(void)
{
    static InputManager InputMgr;
    return InputMgr;
}


void InputManager::init(void)		// real instructor
{
    keyboardEventMap[GLFW_KEY_W] = false;
    keyboardEventMap[GLFW_KEY_S] = false;
    keyboardEventMap[GLFW_KEY_A] = false;
    keyboardEventMap[GLFW_KEY_D] = false;

    // fix obj location, remove controller
    keyboardEventMap[GLFW_KEY_K] = false;
    keyboardEventMap[GLFW_KEY_J] = false;

}

void InputManager::close(void)
{}


