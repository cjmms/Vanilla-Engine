#pragma once

#include "ResourceManager.h"
#include "FPSController.h"
#include "GameObject.h"


class VanillaEngine
{

public:	

	GLFWwindow* window;

	GameObject* obj;
	
	void init(void);
	void close(void);

	void initUI(void);
	void closeUI(void);

	void update(void);

};

