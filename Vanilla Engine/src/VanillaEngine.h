#pragma once

#include "ResourceManager.h"
#include "FPSController.h"
#include "GameObject.h"
#include "ObjectManager.h"


class VanillaEngine
{

public:	

	GLFWwindow* window;

	GameObject* obj;
	GameObject* player;
	
	
	void init(void);
	void close(void);

	void initUI(void);
	void closeUI(void);

	void update(void);

};

