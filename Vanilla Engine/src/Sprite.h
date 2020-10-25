#pragma once
#include "Component.h"
#include <string>
#include <GL/glew.h>
#include "ResourceManager.h"
#include "Shader.h"
//#include "GameObject.h"

class Sprite : public Component
{
public:
	Sprite(std::string address);
	~Sprite( void );
	
	void update( void );

	void draw( const Vector2D& pos );

	unsigned int TexID;
	


};

