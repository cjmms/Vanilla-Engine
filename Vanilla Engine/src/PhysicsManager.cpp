#include "PhysicsManager.h"
#include "CollisionManager.h"


CollideEvent::CollideEvent()
	:Event(COLLISION)
{}

CollideEvent::CollideEvent(float time)
	: Event(COLLISION, time * 1000.0f)
{}

CollideEvent::~CollideEvent()
{}





PhysicsManager::PhysicsManager()
{}



PhysicsManager::~PhysicsManager()
{}



void PhysicsManager::update(void)
{
	// this frame time changes depends on when does update get called
	// which means it's different with other frametime
	// but it's fine since this is the only place uses frame time
	// Alternative approach is passing a uniform Frame Time
	float frameTime = FPSController::getInstance().getFrameTime();

	/*
	* Moving objects base on physics property
	* velocity, acceleration, etc.
	*/
	Integrate(frameTime);

	CollisionDetection();

	//SolveContact();
}


/*
* loop through all contacts
* send an event to two contact objects
*/
void PhysicsManager::SolveContact(void) const
{
	for (auto contact : CollisionManager::getInstance().contacts)
	{
		CollideEvent event;

		contact->bodies[0]->HandleEvent(&event);
		contact->bodies[1]->HandleEvent(&event);
	}

}



void PhysicsManager::Integrate(float frameTime) const
{
	for (auto pGameObj : ObjectManager::getInstance().GameObjects)
	{
		Body* body = static_cast<Body*>(pGameObj->GetComponent(BODY));
		// assume all obj with body component has position
		if (body != nullptr) body->Integrate(200, frameTime, pGameObj->transform->position);
	}
}


/*
* Sending events to Event Manager
* Delayed event doesn't make sense for collision event
* 2 events are created dynamically since they are linked to a sepcific object
*/
void PhysicsManager::SendCollisionEvents(GameObject* obj1, GameObject* obj2) const
{
	CollideEvent* event1 = new CollideEvent();
	EventManager::getInstance().AddEvent(event1);
	EventManager::getInstance().Subscribe(COLLISION, obj1);

	CollideEvent* event2 = new CollideEvent();
	EventManager::getInstance().AddEvent(event2);
	EventManager::getInstance().Subscribe(COLLISION, obj2);
}


/*
* Iterate all game objects and check if they are colliding with each other
* If Collision happens, send events
* 
* This method ASSUMES that each obj has a body component
*/
void PhysicsManager::CollisionDetection(void) const
{
	CollisionManager::getInstance().Reset();

	for (auto pGameObj1 = ObjectManager::getInstance().GameObjects.begin(); pGameObj1 != ObjectManager::getInstance().GameObjects.end(); ++pGameObj1)
	{
		Body* body1 = static_cast<Body*>((*pGameObj1)->GetComponent(BODY));

		for (auto pGameObj2 = pGameObj1 + 1; pGameObj2 != ObjectManager::getInstance().GameObjects.end(); ++pGameObj2)
		{
			Body* body2 = static_cast<Body*>((*pGameObj2)->GetComponent(BODY));

			if (CollisionManager::getInstance().CheckCollision(body1->shape, body1->mPos, body2->shape, body2->mPos))
				SendCollisionEvents(body1->owner, body2->owner);
		}
	}
}




void PhysicsManager::init(void)
{
	CollisionManager::getInstance().init();
}



void PhysicsManager::close(void)
{
	CollisionManager::getInstance().close();
}



PhysicsManager& PhysicsManager::getInstance(void)
{
	static PhysicsManager pMgr;
	return pMgr;
}