#pragma once


class GameObject;

enum ComponentType
{
	TRANSFORM,
	SPRITE,
	CONTROLLER,
	UP_DOWN
};


class Component
{
public:
	Component(ComponentType cType);
	virtual ~Component();
	
	virtual void update() = 0;

	inline ComponentType getType() { return type; };
	GameObject* owner;
	

private:
	ComponentType type;

};

