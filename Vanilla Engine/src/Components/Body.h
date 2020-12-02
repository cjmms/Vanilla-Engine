#pragma once
#include "Component.h"

/*
* Body component is the contains phsyics info of an object
* In theory, it's possible that one entity having several Body Components
* However, current serialization system doesn't support
* 
*/


class GameObject;
class Shape;

class Body : public Component
{
public:
	Body();
	~Body();

	virtual void update(void) override;

	// serialize mass and inMass
	virtual void Serialize(std::ifstream& InputStream) override;

	// seperate from update()
	void Integrate(float Gravity, float DeltaTime, glm::vec3& pos);

	virtual void HandleEvent(Event* event) override;

	bool dead(void);

public:
	glm::vec2 mPos;
	glm::vec2 mPrevPos;
	glm::vec2 velocity;
	glm::vec2 acc;
	glm::vec2 totalF;
	float mMass, mInvMass;

	Shape* shape;

	unsigned int health;
		


};

