#include "Attack.h"
#include "../FPSController.h"
#include "../GameObject.h"
#include "../ObjectManager.h"



Attack::Attack()
	:Component(ATTACK), target(nullptr)
{}


Attack::~Attack(){}


void Attack::update()
{
	if (!hasTarget()) searchTarget();
	if (hasTarget()) attack();
}



void Attack::print() const
{}



void Attack::Serialize(std::ifstream& InputStream)
{
	std::cout << "Serializing Attack" << std::endl;

	InputStream >> coolDown;

	std::cout << "Timer limit: " << timer << std::endl;
}


// find target as long as it's enemy
bool Attack::searchTarget()
{
	target = ObjectManager::getInstance().findEnemy(true);
	return target == nullptr;
}


void Attack::attack()
{
	timer -= FPSController::getInstance().getFrameTime();

	if (timer < 0.0f)
	{
		timer = coolDown;
		// attack
	}
}


bool Attack::hasTarget()
{
	if (target == nullptr) return false;
	return ObjectManager::getInstance().find(target);
}


