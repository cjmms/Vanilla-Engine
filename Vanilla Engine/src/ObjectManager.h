#pragma once

#include "GameObject.h"


class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
	void add(GameObject *object);
	ObjectManager& getInstance();


	std::vector<GameObject *> GameObjects;
	



};

