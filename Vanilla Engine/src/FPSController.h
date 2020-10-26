#pragma once
#include "GLFW/glfw3.h"
#include <iostream>


class FPSController
{
private:
	float lastFrame, deltaTime;

public:
	FPSController();
	~FPSController();

	void UpdateFrameTime();

	void limiteFPS(int fps);

	inline float getFrameTime() { return lastFrame; }

	static FPSController& getInstance();

	FPSController(FPSController const&) = delete;
	void operator=(FPSController const&) = delete;

};

