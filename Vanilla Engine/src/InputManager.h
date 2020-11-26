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
	
	void init(void);		// real instructor

	void close(void);		// real destructor

	void getInputs(GLFWwindow* window);

	bool keyIsPressed(int key);

	static InputManager& getInstance(void);

	InputManager(InputManager const&) = delete;
	void operator=(InputManager const&) = delete;
};

