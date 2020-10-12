#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <unordered_map>


class InputManager
{
private:
	std::unordered_map<int, bool> keyboardEventMap;
	
public:
	
	~InputManager();	// do nothing
	InputManager();
	
	void init();		// real instructor

	void close();		// real destructor

	void getInputs(GLFWwindow* window);

	bool keyIsPressed(int key);

	//static InputManager& getInstance();


};

