#pragma once
#include "Component.h"
#include "FPSController.h"




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

