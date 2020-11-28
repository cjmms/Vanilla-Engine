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

// Contact -----------------------------------

Contact::Contact(Shape* shape1, Shape* shape2)
{
	bodies[0] = shape1->ownerBody;
	bodies[1] = shape2->ownerBody;
}


Contact::~Contact()
{
	delete bodies;
}


void Contact::set(Shape* shape1, Shape* shape2)
{
	bodies[0] = shape1->ownerBody;
	bodies[1] = shape2->ownerBody;
}


// CollisionManager --------------------------

CollisionManager::CollisionManager()
{
}



CollisionManager::~CollisionManager()
{}


void CollisionManager::AddContact(Shape* shape1, Shape* shape2)
{
	contacts.push_back(new Contact(shape1, shape2));
}


bool CollisionManager::CheckCollisionAABBAABB(Shape* shape1, glm::vec2 pos1, Shape* shape2, glm::vec2 pos2)
{
}


bool CollisionManager::CheckCollisionCircleCircle(Shape* shape1, glm::vec2 pos1, Shape* shape2, glm::vec2 pos2)
{
}


bool CollisionManager::CheckCollisionAABBCircle(Shape* shapeAABB, glm::vec2 posAABB, Shape* shapeCircle, glm::vec2 posCircle)
{
	ShapeAABB* aabb = static_cast<ShapeAABB*>(shapeAABB);
	ShapeCircle* circle = static_cast<ShapeCircle*>(shapeCircle);

	glm::vec2 point;

	float left = posAABB.x + aabb->left;
	float right = posAABB.x + aabb->right;
	float top = posAABB.y + aabb->top;
	float bottom = posAABB.y + aabb->bottom;

	if (posCircle.x < left)	point.x = left;
	else					point.x = posCircle.x > right ? right : posAABB.x;

	if (posCircle.y < top)  point.y = top;
	else					point.y = posCircle.y > bottom ? bottom : posAABB.y;


	if (circle->pointCollision(point) == false) return false;

	// Add new contact
	AddContact(shapeAABB, shapeCircle);

	return true;
}


bool CollisionManager::CheckCollisionCircleAABB(Shape* shapeCircle, glm::vec2 posCircle, Shape* shapeAABB, glm::vec2 posAABB)
{
	return CheckCollisionAABBCircle(shapeAABB, posAABB, shapeCircle, posCircle);
}