#pragma once

#include <GL/glew.h>
#include <iostream>

#include "../Dependencies/stb_image.h"
#include <string>
#include <unordered_map>



struct Texture
{
	unsigned int id;
	std::string address;
};


class ResourceManager
{
private:
	//std::unordered_map<Texture, int> TexIDMap;
	ResourceManager() {}

public: 

	static ResourceManager& getInstance();

	void createTexture(unsigned int &id, const char* filePath);
	
	void init(void);
	void close(void);

	~ResourceManager();

	ResourceManager(ResourceManager const&) = delete;
	void operator=(ResourceManager const&) = delete;

	
};

