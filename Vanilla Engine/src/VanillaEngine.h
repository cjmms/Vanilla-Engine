#pragma once

#include "InputManager.h"
#include "ResourceManager.h"
#include "Entity.h"

//static InputManager InputMgr;
//ResourceManager ResourceMgr;


class VanillaEngine
{

public:	

	GLFWwindow* window;
	InputManager InputMgr;
	//ResourceManager ResourceMgr;

	Entity entity;
	
	
	void init(void);
	void close(void);

	void initUI(void);
	void closeUI(void);

	void update(void);
};

