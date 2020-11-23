#pragma once
#include "Component.h"
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

	glm::vec3 position;

};

