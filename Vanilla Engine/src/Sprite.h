#pragma once
#include "Component.h"
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

	void draw( const glm::vec3& pos, const Shader& shader);

	unsigned int TexID;
	


};

