#pragma once
#include "Component.h"
#include "FPSController.h"
//#include "GameObject.h"
#include <string>
#include <iostream>
#include "Shader.h"


class UpDown : public Component
{
private:
	float timer;
	bool movingUp;
	float timerLimit;

public:
	UpDown();
	~UpDown();

	void update();
	void Serialize(std::ifstream& stream);

};

