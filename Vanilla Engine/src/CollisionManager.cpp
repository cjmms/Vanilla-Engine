#include "CollisionManager.h"
#include <cmath>


bool CheckCollisionAABBAABB(Shape* shape1, glm::vec2 pos1, Shape* shape2, glm::vec2 pos2);
bool CheckCollisionCircleCircle(Shape* shape1, glm::vec2 pos1, Shape* shape2, glm::vec2 pos2);
bool CheckCollisionAABBCircle(Shape* shapeAABB, glm::vec2 posAABB, Shape* shapeCircle, glm::vec2 posCircle);
bool CheckCollisionCircleAABB(Shape* shapeCircle, glm::vec2 posCircle, Shape* shapeAABB, glm::vec2 posAABB);


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

// Contact ----------------------------------------------------------

Contact::Contact(Shape* shape1, Shape* shape2)
{
	bodies[0] = shape1->ownerBody;
	bodies[1] = shape2->ownerBody;
}


Contact::~Contact()
{
	//bodies[0];
	//delete bodies;
}


void Contact::set(Shape* shape1, Shape* shape2)
{
	bodies[0] = shape1->ownerBody;
	bodies[1] = shape2->ownerBody;
}


// CollisionManager -----------------------------------------------------

CollisionManager& CollisionManager::getInstance(void)
{
	static CollisionManager manager;
	return manager;
}


CollisionManager::~CollisionManager(){}

// init collision functions
// terrible implementation, but it works
void CollisionManager::init(void)
{
	CollisionFunctions[Shape::AABB][Shape::AABB] = CheckCollisionAABBAABB;
	CollisionFunctions[Shape::AABB][Shape::CIRCLE] = CheckCollisionAABBCircle;
	CollisionFunctions[Shape::CIRCLE][Shape::AABB] = CheckCollisionAABBCircle;
	CollisionFunctions[Shape::CIRCLE][Shape::CIRCLE] = CheckCollisionCircleCircle;
}


void CollisionManager::close(void)
{
	Reset();
}


void CollisionManager::Reset()
{
	for (auto contact : contacts) delete contact;
	contacts.clear();
}


bool CollisionManager::CheckCollision(Shape* shape1, glm::vec2 pos1, Shape* shape2, glm::vec2 pos2)
{
	//std::cout<< "check collision" <<std::endl;
	return CollisionFunctions[shape1->type][shape2->type](shape1, pos1, shape2, pos2);
}


void CollisionManager::AddContact(Shape* shape1, Shape* shape2)
{
	contacts.push_back(new Contact(shape1, shape2));
}




// These collision detection functions are hidden from everything except Collision Manager
// These function can only get accessed by calling CheckCollision()
bool CheckCollisionAABBAABB(Shape* shape1, glm::vec2 pos1, Shape* shape2, glm::vec2 pos2)
{
	//std::cout << "check collision AABBAABB" << std::endl;
	ShapeAABB* aabb1 = static_cast<ShapeAABB*>(shape1);
	ShapeAABB* aabb2 = static_cast<ShapeAABB*>(shape2);

	float left1 = pos1.x + aabb1->left;
	float right1 = pos1.x + aabb1->right;
	float top1 = pos1.y + aabb1->top;
	float bottom1 = pos1.y + aabb1->bottom;

	float left2 = pos2.x + aabb2->left;
	float right2 = pos2.x + aabb2->right;
	float top2 = pos2.y + aabb2->top;
	float bottom2 = pos2.y + aabb2->bottom;

	if (left1 > right2 || left2 > right1 || top1 > bottom2 || top2 > bottom1) return false;

	// Add new contact
	//CollisionManager::getInstance().AddContact(shape1, shape1);

	return true;
}


bool CheckCollisionCircleCircle(Shape* shape1, glm::vec2 pos1, Shape* shape2, glm::vec2 pos2)
{
	//std::cout << "check collision C2C" << std::endl;
	//std::cout << "pos1: " << pos1.x << ", " << pos1.y << std::endl;
	//std::cout << "pos2: " << pos2.x << ", " << pos2.y << std::endl;

	float sqDis = pow((pos1.x - pos2.x), 2) + pow((pos1.y - pos2.y), 2);
	float r1 = static_cast<ShapeCircle*>(shape1)->radius;
	float r2 = static_cast<ShapeCircle*>(shape2)->radius;

	//std::cout << "obj1.r: " << r1 << std::endl;
	//std::cout << "obj2.r: " << r2 << std::endl;

	if (sqDis > pow((r1 + r2), 2)) return false;

	// Add new contact
	//CollisionManager::getInstance().AddContact(shape1, shape1);

	return true;
}


bool CheckCollisionAABBCircle(Shape* shapeAABB, glm::vec2 posAABB, Shape* shapeCircle, glm::vec2 posCircle)
{
	//std::cout << "check collision aabb2c" << std::endl;
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
	//CollisionManager::getInstance().AddContact(shapeAABB, shapeCircle);

	return true;
}


bool CheckCollisionCircleAABB(Shape* shapeCircle, glm::vec2 posCircle, Shape* shapeAABB, glm::vec2 posAABB)
{
	//std::cout << "check collision C2AABB" << std::endl;
	return CheckCollisionAABBCircle(shapeAABB, posAABB, shapeCircle, posCircle);
}