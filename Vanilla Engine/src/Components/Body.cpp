#include "Body.h"
#include "../GameObject.h"

Body::Body()
	: mPos(glm::vec2(0.0f)), mPrevPos(glm::vec2(0.0f)), velocity(glm::vec2(0.0f)),
	  acc(glm::vec2(0.0f)), totalF(glm::vec2(0.0f)), mMass(1.0f), mInvMass(1.0f), Component(BODY)
{}


Body::~Body()
{}

void Body::update(void)
{}



void Body::Serialize(std::ifstream& InputStream)
{
	InputStream >> mMass;

	if (0.0f != mMass) mInvMass = 1.0f / mMass;
	else mInvMass = 0.0f;
}


void Body::Integrate(float Gravity, float DeltaTime, glm::vec3& pos)
{
	Transform* transform = static_cast<Transform*>(owner->GetComponent(TRANSFORM));
	mPos = transform->position;

	mPrevPos = mPos;

	// compute acc
	totalF += Gravity;
	acc = totalF * mInvMass;

	totalF = glm::vec2(0.0);

	// integrate velocity
	velocity = acc * DeltaTime + velocity;

	// integrate position
	mPos = velocity * DeltaTime + mPos;

	transform->position = glm::vec3(mPos.x, mPos.y, 0.0f);
}
