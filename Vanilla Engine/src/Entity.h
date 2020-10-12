#pragma once


#include "Shader.h" 

// Base class for all game objects


class Entity
{

public:

	Entity(void);
	Entity(const Vector2D& position);
	
	void setPosition(const Vector2D& position);
	void setHealth(float health);

	void spawn(void) const;

	void draw(void) const;

	void moveUp(void);
	void moveDown(void);
	void moveLeft(void);
	void moveRight(void);
	


private:
	float health;	// Do all entities have health?
	Vector2D position;
	
};

