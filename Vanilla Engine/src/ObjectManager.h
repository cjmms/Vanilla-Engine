#pragma once

#include <vector>;
#include "GameObject.h"


class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
	void add(GameObject *object);

	std::vector<GameObject *> GameObjects;
	



};

