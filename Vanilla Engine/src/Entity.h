#pragma once

#include "ResourceManager.h"
//#include "VanillaEngine.h"
#include "Shader.h" 

// Base class for all game objects
//extern ResourceManager ResourceMgr;

class Entity
{

public:

	Entity(void);
	Entity(const Vector2D& position);
	
	void setPosition(const Vector2D& position);
	void setHealth(float health);

	void spawn(void);

	void draw(void) const;

	void moveUp(void);
	void moveDown(void);
	void moveLeft(void);
	void moveRight(void);
	


private:
	float health;	// Do all entities have health?
	Vector2D position;
	unsigned int TexID;
	
};

