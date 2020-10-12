#pragma once

#include "InputManager.h"
#include "Entity.h"

class VanillaEngine
{

public:	

	GLFWwindow* window;
	InputManager InputMgr;

	Entity entity;
	
	
	void init(void);
	void close(void);

	void initUI(void);
	void closeUI(void);

	void update(void);
};

