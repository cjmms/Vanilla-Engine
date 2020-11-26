#pragma once
#include "Transform.h"
#include "Sprite.h"
#include "Controller.h"
#include "UpDown.h"
#include "Body.h"
#include <vector>


class GameObject
{

public:
	GameObject();
	~GameObject();
	void update();

	Component* AddComponent(ComponentType type);
	Component* GetComponent(ComponentType type);

	virtual void Serialize(std::ifstream& InputStream) {};

private:
	std::vector<Component*> componentList;

public:
	Transform *transform;
	Sprite *sprite;
	Controller *controller;
	UpDown* upDown;
	Body* body;

};

