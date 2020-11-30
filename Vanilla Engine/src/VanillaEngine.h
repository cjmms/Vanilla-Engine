#pragma once

#include "ResourceManager.h"
#include "FPSController.h"
#include "GameObject.h"
#include "ObjectManager.h"
#include "PhysicsManager.h"
#include "EventManager.h"


class VanillaEngine
{

public:	

	GLFWwindow* window;
	
	void init(void);
	void close(void);

	void initUI(void);
	void closeUI(void);

	void update(void);

};

