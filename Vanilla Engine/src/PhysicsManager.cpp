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
	* Moving objects
	*/
	for (auto pGameObj : ObjectManager::getInstance().GameObjects)
	{
		Body* body = static_cast<Body*>(pGameObj->GetComponent(BODY));
		// assume all obj with body component has position
		if (body != nullptr) body->Integrate(200, frameTime, pGameObj->transform->position);
	}

	/*
	* Collision Detection
	*/
	CollisionManager::getInstance().Reset();

	for (auto pGameObj1 : ObjectManager::getInstance().GameObjects)
	{
		Body* body1 = static_cast<Body*>(pGameObj1->GetComponent(BODY));
		if (body1 == nullptr) continue;

		for (auto pGameObj2 : ObjectManager::getInstance().GameObjects)
		{
			Body * body2 = static_cast<Body*>(pGameObj2->GetComponent(BODY));
			if (body2 == nullptr || body1 == body2) continue;
			bool collide = CollisionManager::getInstance().CheckCollision( body1->shape, body1->mPos,
															body2->shape, body2->mPos );
			//if (collide) std::cout << "Collision!!!!!" << std::endl;
			if (collide)
			{
				// test for no delay event
				CollideEvent* event1 = new CollideEvent();
				EventManager::getInstance().AddEvent(event1);
				EventManager::getInstance().Subscribe(COLLISION, body1->owner);

				// test for delayed event
				CollideEvent* event = new CollideEvent(2);
				EventManager::getInstance().AddEvent(event);
			}
		}
	}

	/*
	* Solve Collision
	*/
	for (auto contact : CollisionManager::getInstance().contacts)
	{
		CollideEvent event;

		contact->bodies[0]->HandleEvent(&event);
		contact->bodies[1]->HandleEvent(&event);
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