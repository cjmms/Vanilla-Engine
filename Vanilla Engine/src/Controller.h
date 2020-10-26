#pragma once
#include "Component.h"
#include "InputManager.h"




class Controller : public Component
{
public:
	Controller();
	~Controller();
	
	void update();

};

