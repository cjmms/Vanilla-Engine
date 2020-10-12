#pragma once

#include <GL/glew.h>
#include <iostream>

#include "../Dependencies/stb_image.h"
#include <vector>


class ResourceManager
{
private:
	std::vector<unsigned int> TextureIDList;


public: 
	static void createTexture(unsigned int &id, const char* filePath);
	
	void init(void);
	void close(void);

	ResourceManager();
	~ResourceManager();

};

