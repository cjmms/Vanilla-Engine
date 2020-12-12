#pragma once

#include "ResourceManager.h"
#include "FPSController.h"
#include "GameObject.h"
#include "ObjectManager.h"
#include "PhysicsManager.h"
#include "EventManager.h"
#include "TextRenderer.h"


class VanillaEngine
{

public:	

	GLFWwindow* window;
	TextRenderer textRenderer;
	unsigned int width = 1200;
	unsigned int height = 1000;

	
	void init(void);
	void close(void);

	void initUI(void);
	void closeUI(void);

	void update(void);

};

