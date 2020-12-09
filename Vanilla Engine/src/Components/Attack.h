#pragma once

#include "Component.h"



/*
*  This component find target and attacked automatically
*  not event based
*/
class Attack : public Component
{
public:
	Attack();
	~Attack();

	virtual void update() override;

	virtual void print() const override;

	virtual void Serialize(std::ifstream& InputStream) override;

	

	GameObject* target;

private:
	bool searchTarget();
	void attack();
	bool hasTarget();

	float timer;
	float coolDown;
};

