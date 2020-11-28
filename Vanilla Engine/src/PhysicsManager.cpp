#include "PhysicsManager.h"


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
	for (auto pGameObj : ObjectManager::getInstance().GameObjects)
	{
		Body* body = static_cast<Body*>(pGameObj->GetComponent(BODY));
		// assume all obj with body component has position
		//if (body != nullptr) body->Integrate(200, frameTime, pGameObj->transform->position);
	}

}

void PhysicsManager::init(void)
{
	
}



void PhysicsManager::close(void)
{}


PhysicsManager& PhysicsManager::getInstance(void)
{
	static PhysicsManager pMgr;
	return pMgr;
}