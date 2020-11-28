#pragma once
#include "ext.hpp"
#include "Components/Body.h"
#include <list>
class Body;

// This file contains three class
// 1. Shape (Abstract class)
// 2. ShapeCircle inherits from Shape
// 3. ShapeAABB inherits from Shape

// derived classes from Shape have their own collision detection methods
// Each body component should have 1 Shape



// Each body has one Shape
// Abstract Class
// Shape class has a public ENUM that contains all Shape Type
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
	virtual bool pointCollision(glm::vec2 point) const = 0;

public:
	Body* ownerBody;
	ShapeType type;
};




// ---------------------------------------
// CIRCLE
class ShapeCircle : public Shape
{
public:
	ShapeCircle(float radius);
	~ShapeCircle();

	virtual bool pointCollision(glm::vec2 point) const override;

public:
	float radius;


};




// ---------------------------------------
// AABB
class ShapeAABB : public Shape
{
public:
	ShapeAABB(float left, float right, float top, float bottom);
	~ShapeAABB();

	virtual bool pointCollision(glm::vec2 point) const override;

public:
	float left, right, top, bottom;


};


// collision contact
class Contact
{
public:
	Contact();
	~Contact();

public:
	Body* bodies[2];
};




class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	void Reset();
	bool CheckCollision(Shape* shape1, glm::vec2 pos1, Shape* shape2, glm::vec2 pos2);

public:
	std::list<Contact*> contacts;

	// 2D array of collision function ptrs
	bool (*CollisionFunctions[Shape::NUM][Shape::NUM])
		(Shape* shape1, glm::vec2 pos1, Shape* shape2, glm::vec2 pos2, std::list<Contact*>& contacts);
};

