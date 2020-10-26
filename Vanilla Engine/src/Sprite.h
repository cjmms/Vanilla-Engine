#pragma once
#include "Component.h"
#include <string>
#include <GL/glew.h>
#include "ResourceManager.h"
#include "Shader.h"


class Sprite : public Component
{
public:
	Sprite(std::string address);
	Sprite();
	~Sprite( void );
	
	void update( void );
	void Serialize(std::ifstream& InputStream);

	void draw( const Vector2D& pos );

	unsigned int TexID;
	


};

