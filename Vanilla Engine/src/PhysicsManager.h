#pragma once

#include "GameObject.h"
#include "ObjectManager.h"
#include "FPSController.h"
#include "EventManager.h"

class CollideEvent : public Event
{
public:
	CollideEvent();
	CollideEvent(float time);
	~CollideEvent();

	
};




// Singleton
class PhysicsManager
{
private:
	PhysicsManager();

public:
	~PhysicsManager();
	void update(void);

	void init(void);
	void close(void);

	PhysicsManager(PhysicsManager const&) = delete;
	void operator=(PhysicsManager const&) = delete;

	static PhysicsManager& getInstance(void);

};

