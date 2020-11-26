#pragma once
#include "Component.h"

class GameObject;

class Body : public Component
{
public:
	Body();
	~Body();

	virtual void update(void) override;
	virtual void Serialize(std::ifstream& InputStream);

	// seperate from update()
	void Integrate(float Gravity, float DeltaTime, glm::vec3& pos);

public:
	glm::vec2 mPos;
	glm::vec2 mPrevPos;
	glm::vec2 velocity;
	glm::vec2 acc;
	glm::vec2 totalF;
	float mMass, mInvMass;


};

