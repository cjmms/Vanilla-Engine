#pragma once
#include "Component.h"


class UpDown : public Component
{
private:
	float timer;
	bool movingUp;
	float timerLimit;

public:
	UpDown();
	~UpDown();

	virtual void update(void) override;
	virtual void Serialize(std::ifstream& stream) override;
	virtual void HandleEvent(Event* event) override;

};

