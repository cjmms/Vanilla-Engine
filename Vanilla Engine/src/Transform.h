#pragma once
#include "Component.h"
#include "Vector2D.h"
#include <string>
#include <iostream>

#include "Shader.h"


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

