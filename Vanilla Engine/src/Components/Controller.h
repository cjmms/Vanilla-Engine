#pragma once
#include "Component.h"
#include "../EventManager.h"

class PlayerHitEvent: public Event
{
public:
	PlayerHitEvent();
	~PlayerHitEvent();
};

class Controller : public Component
{
public:
	Controller();
	~Controller();

	virtual void Serialize(std::ifstream& stream) override;
	
	virtual void update(void) override;

	virtual void HandleEvent(Event* event) override;

};

