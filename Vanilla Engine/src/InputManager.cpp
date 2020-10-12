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



void InputManager::init()		// real instructor
{
    keyboardEventMap[GLFW_KEY_W] = false;
    keyboardEventMap[GLFW_KEY_S] = false;
    keyboardEventMap[GLFW_KEY_A] = false;
    keyboardEventMap[GLFW_KEY_D] = false;

}

void InputManager::close()
{}