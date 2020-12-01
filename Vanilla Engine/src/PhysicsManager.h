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

private:
	void SolveContact(void) const;
	void Integrate(float frameTime) const;
	void CollisionDetection(void) const;

	// This method sends events(with type COLLISION) to event manager
	// It assumes each collision happens between two objects
	// Therefore, two events will be sent and subscribed to event manager
	// Broadcasting Collision event simply doesn't make sense logically
	void SendCollisionEvents(GameObject* obj1, GameObject* obj2) const;

};

