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

	void createTexture(std::string filePath);
	
	void init(void);
	void close(void);

	~ResourceManager();

	ResourceManager(ResourceManager const&) = delete;
	void operator=(ResourceManager const&) = delete;

	// Creating and Serializing each object
	GameObject* LoadGameObject(const char* fileName);

	// Read the level file, load all the game objects
	void LoadLevel(const char * fileName);

	void bindTexture(std::string address);

	void bindRecVAO(void);

private:
	void initRec(void);

	std::unordered_map<std::string, unsigned int> textures;
	unsigned int recVAO;
};

