#pragma once
#include "Component.h"

class GameObject;

class Body : public Component
{
public:
	Body();
	~Body();

	void Update(void);
	virtual void Serialize(std::ifstream& InputStream);
	void Integrate(float Gravity, float DeltaTime);

public:
	glm::vec2 mPos;
	glm::vec2 mPrevPos;
	glm::vec2 velocity;
	glm::vec2 acc;
	glm::vec2 totalF;
	float mMass, mInvMass;


};

