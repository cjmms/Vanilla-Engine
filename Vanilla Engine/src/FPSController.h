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

	void UpdateFrameTime(void);

	void limiteFPS(int fps);

	inline float getFrameTime(void) const { return deltaTime * 1000.0f; }

	static FPSController& getInstance(void);

	FPSController(FPSController const&) = delete;
	void operator=(FPSController const&) = delete;

};

