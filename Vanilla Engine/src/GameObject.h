#pragma once
#include "Transform.h"
#include "Sprite.h"
#include "Controller.h"
#include "UpDown.h"

class GameObject
{

public:
	GameObject();
	~GameObject();
	void update();


public:
	Transform *transform;
	Sprite *sprite;
	Controller *controller;
	UpDown* upDown;

};

