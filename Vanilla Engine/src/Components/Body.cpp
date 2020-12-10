#include "Body.h"
#include "../GameObject.h"
#include "../CollisionManager.h"
#include "../ObjectManager.h"

Body::Body()
	: mPos(glm::vec2(0.0f)), mPrevPos(glm::vec2(0.0f)), velocity(glm::vec2(0.0f)),
	  acc(glm::vec2(0.0f)), totalF(glm::vec2(0.0f)), mMass(1.0f), mInvMass(1.0f), 
	  Component(BODY), shape(nullptr)
{}


Body::~Body()
{
	if (shape != nullptr) delete shape;
}

void Body::update(void)
{}

void Body::print() const
{

}

void Body::setVelocity(glm::vec2 v)
{
	velocity = speed * glm::normalize(v);
}

/*
* Expected Input:
* Body (handled already)
* Shape (Circle, AABB, etc)
* detailed info about shape
* 
* This serializer does not support serializing multiple Shapes
* Changing if statement to switch statement may solve the issue, still depending on input format.
*/
void Body::Serialize(std::ifstream& InputStream)
{
	/*
	*  This chunk of code serializes mass of obj, which is probably unnecessay for my game
	* 
	InputStream >> mMass;

	if (0.0f != mMass) mInvMass = 1.0f / mMass;
	else mInvMass = 0.0f;
	*/

	std::cout << "Serializing Body" << std::endl;

	std::string shapeName;
	InputStream >> shapeName;

	std::cout << "Shape Type: " << shapeName << std::endl;

	if ("Circle" == shapeName)
	{
		float radius = 0.0f;		// default radius
		InputStream >> radius;		// read radius, no Error Checking

		std::cout << "Radius: " << radius << std::endl;
		if (radius <= 0) std::cout << "WARNING: radius is smaller or equal to 0!" << std::endl;

		shape = new ShapeCircle(radius);
		shape->ownerBody = this;
	}

	if ("AABB" == shapeName)
	{
		float left, right, top, bottom;
		InputStream >> left >> right >> top >> bottom;

		std::cout << "Left: " << left << 
		  		   "  Right: " << right << 
				   "  Top: " << top << 
				   "  Bottom: " << bottom << std::endl;

		shape = new ShapeAABB(left, right, top, bottom);
		shape->ownerBody = this;
	}

	std::string v;
	InputStream >> v;
	if (v == "Velocity")
	{
		//float speed;
		InputStream >> speed;
		std::cout << "Speed: " << speed << std::endl;
	}
}


void Body::Integrate(float Gravity, float DeltaTime, glm::vec3& pos)
{
	Transform* transform = static_cast<Transform*>(owner->GetComponent(TRANSFORM));
	mPos = transform->position;

	// direction of enemy
	 //glm::vec2(0.0) is target position, terminal coordinates
	if (owner->attribute->hostile)
		velocity = speed * glm::normalize(glm::vec2(0.0) - mPos);
	//else
		//velocity = speed * glm::normalize(velocity);

	//if (owner->attribute->hostile) transform->move(velocity);
	//else transform->move(velocity * speed);

	transform->move(velocity);

/*
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
	*/

	
}







void Body::HandleEvent(Event* event)
{

}


