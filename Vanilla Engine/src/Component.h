#pragma once
#include "InputManager.h"
//#include "GameObject.h"
#include <fstream>
#include "ext.hpp"



class GameObject;

enum ComponentType
{
	TRANSFORM,
	SPRITE,
	CONTROLLER,
	UP_DOWN,
	BODY
};


class Component
{
public:
	Component(ComponentType cType);
	virtual ~Component();
	
	virtual void update() = 0;

	virtual void Serialize(std::ifstream& InputStream) = 0;

	inline ComponentType getType() { return type; };
	GameObject* owner;
	

private:
	ComponentType type;

};

