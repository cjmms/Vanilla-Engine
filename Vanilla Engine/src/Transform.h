#pragma once
#include "Component.h"
#include "Vector2D.h"

class Transform : public Component
{

public:
	Transform();
	~Transform();
	
	void update();

	Vector2D position;

};

