#pragma once
#include "Component.h"
#include "../Shader.h"



class Sprite : public Component
{
public:
	Sprite();
	~Sprite( void );
	
	virtual void update( void ) override;
	virtual void Serialize(std::ifstream& InputStream) override;

	void draw(const Shader& shader);

	unsigned int TexID;
	


};

