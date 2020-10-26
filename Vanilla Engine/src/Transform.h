#pragma once
#include "Component.h"
#include "Vector2D.h"


class Transform : public Component
{

public:
	Transform();
	~Transform();
	
	void update();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void Serialize(std::ifstream& stream);

	Vector2D position;

};

