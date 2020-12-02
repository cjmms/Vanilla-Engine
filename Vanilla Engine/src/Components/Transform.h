#pragma once
#include "Component.h"


class Transform : public Component
{

public:
	Transform();
	~Transform();
	
	virtual void update(void) override;

	void moveUp(void);
	void moveDown(void);
	void moveLeft(void);
	void moveRight(void);

	void move(glm::vec2 dis);

	virtual void Serialize(std::ifstream& stream) override;

	virtual void print() const override;

	glm::vec3 position;

};

