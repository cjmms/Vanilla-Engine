#pragma once
#include "../InputManager.h"
#include "ext.hpp"		// GLM library




class GameObject;
class Event;

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

	// component should be able to handle event
	// but not every component should do so
	virtual void HandleEvent(Event* event) {};

	inline ComponentType getType() { return type; };
	GameObject* owner;
	

private:
	ComponentType type;

};

