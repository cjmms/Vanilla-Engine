#pragma once

#include "Component.h"



class Attribute : public Component
{
public:
	Attribute();
	~Attribute();

	virtual void update(void) override;

	virtual void Serialize(std::ifstream& InputStream) override;


	virtual void HandleEvent(Event* event) override;

	bool dead(void);

	unsigned int health;
};

