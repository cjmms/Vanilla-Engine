#pragma once
#include "Component.h"



class Controller : public Component
{
public:
	Controller();
	~Controller();

	virtual void Serialize(std::ifstream& stream) override;
	
	virtual void update(void) override;

};

