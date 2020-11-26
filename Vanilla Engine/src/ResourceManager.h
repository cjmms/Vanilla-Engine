#pragma once

#include <GL/glew.h>
#include <iostream>

#include "../Dependencies/stb_image.h"
#include <string>
#include <unordered_map>


class GameObject;

struct Texture
{
	unsigned int id;
	std::string address;
};


class ResourceManager
{
private:
	
	ResourceManager() {}

public: 

	static ResourceManager& getInstance(void);

	void createTexture(unsigned int &id, const char* filePath);
	
	void init(void);
	void close(void);

	~ResourceManager();

	ResourceManager(ResourceManager const&) = delete;
	void operator=(ResourceManager const&) = delete;

	GameObject* LoadGameObject(const char* fileName);
	void LoadLevel(const char * fileName);
};

