#include "CollisionManager.h"


Shape::Shape(ShapeType type)
	:type(type), ownerBody(nullptr) 
{}




// ShapeCircle----------------------------------------

ShapeCircle::ShapeCircle(float radius)
	:Shape(CIRCLE), radius(radius)
{}


ShapeCircle::~ShapeCircle()
{}

// compare square distance with square radius
bool ShapeCircle::pointCollision(glm::vec2 point) const
{
	float pointCircleSqrDis = (point.x - ownerBody->mPos.x) * (point.x - ownerBody->mPos.x)
							+ (point.y - ownerBody->mPos.y) * (point.y - ownerBody->mPos.y);

	return pointCircleSqrDis <= (radius * radius);
}






// ShapeAABB--------------------------------------------


ShapeAABB::ShapeAABB(float left, float right, float top, float bottom)
	:Shape(AABB), left(left), right(right), top(top), bottom(bottom)
{}


ShapeAABB::~ShapeAABB()
{}


bool ShapeAABB::pointCollision(glm::vec2 point) const
{
	if (point.x < left)		return false;
	if (point.x > right)	return false;
	if (point.y > top)		return false;
	if (point.y < bottom)	return false;

	return true;
}

