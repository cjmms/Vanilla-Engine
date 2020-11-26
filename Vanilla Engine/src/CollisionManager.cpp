#include "CollisionManager.h"



Shape::Shape(ShapeType type)
	:type(type), ownerBody(nullptr) 
{}




// ShapeCircle----------------------------------------

ShapeCircle::ShapeCircle()
	:Shape(CIRCLE), radius(0.0f)
{}


ShapeCircle::~ShapeCircle()
{}


bool ShapeCircle::pointCollision(glm::vec2 point)
{
	float pointCircleSqrDis = (point.x - ownerBody->mPos.x) * (point.x - ownerBody->mPos.x)
							+ (point.y - ownerBody->mPos.y) * (point.y - ownerBody->mPos.y);

	return pointCircleSqrDis <= (radius * radius);
}






// ShapeAABB--------------------------------------------


ShapeAABB::ShapeAABB()
	:Shape(AABB), left(0.0f), right(0.0f), top(0.0f), bottom(0.0f)
{}


ShapeAABB::~ShapeAABB()
{}


bool ShapeAABB::pointCollision(glm::vec2 point)
{
	return false;
}

