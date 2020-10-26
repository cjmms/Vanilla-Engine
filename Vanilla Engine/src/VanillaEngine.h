#pragma once


#include "ResourceManager.h"
#include "Entity.h"
#include "GameObject.h"


class VanillaEngine
{
private:
	float lastFrame, deltaTime;

public:	

	GLFWwindow* window;

	

	//Entity entity;
	GameObject obj;
	
	void init(void);
	void close(void);

	void initUI(void);
	void closeUI(void);

	void update(void);

	void UpdateFrameTime();

	void limiteFPS(int fps);


};

