#pragma once
#include "./Components/Transform.h"
#include "./Components/Sprite.h"
#include "./Components/Controller.h"
#include "./Components/UpDown.h"
#include "./Components/Body.h"
#include "./Components/Attribute.h"
#include "./Components/Attack.h"
#include <vector>


class GameObject
{

public:
	GameObject();
	~GameObject();
	void update(void);

	Component* AddComponent(ComponentType type);
	Component* GetComponent(ComponentType type);
	void RemoveComponent(ComponentType type);
	void HandleEvent(Event* event);

	virtual void Serialize(std::ifstream& InputStream) {};

private:
	std::vector<Component*> componentList;

public:
	Transform *transform;
	Sprite *sprite;
	Controller *controller;
	UpDown* upDown;
	Body* body;
	Attribute* attribute;
	Attack* attack;
};

