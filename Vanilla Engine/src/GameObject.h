#pragma once
#include "Transform.h"
#include "Sprite.h"
#include "Controller.h"

class GameObject
{

public:
	GameObject();
	~GameObject();
	void update();


	Transform *transform;
	Sprite *sprite;
	Controller* controller;

};

