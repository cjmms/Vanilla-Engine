#pragma once
#include "ext.hpp"
#include "Components/Body.h"
class Body;

class CollisionManager
{
};



// Each body has one Shape
// Abstract Class
class Shape 
{

public:
	enum ShapeType
	{
		CIRCLE,
		AABB,
		NUM
	};

	Shape(ShapeType type);
	virtual ~Shape() {}
	virtual bool pointCollision(glm::vec2 point) = 0;

public:
	Body* ownerBody;
	ShapeType type;
};




// ---------------------------------------
// CIRCLE
class ShapeCircle : public Shape
{
public:
	ShapeCircle();
	~ShapeCircle();

	virtual bool pointCollision(glm::vec2 point) override;

public:
	float radius;


};




// ---------------------------------------
// AABB
class ShapeAABB : public Shape
{
public:
	ShapeAABB();
	~ShapeAABB();

	virtual bool pointCollision(glm::vec2 point) override;

public:
	float left, right, top, bottom;


};

