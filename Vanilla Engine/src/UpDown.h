#pragma once
#include "Component.h"
#include "FPSController.h"
//#include "GameObject.h"


class UpDown : public Component
{
private:
	float timer;
	bool movingUp;

public:
	UpDown();
	~UpDown();

	void update();


};

