#include "Attack.h"
#include "../FPSController.h"
#include "../GameObject.h"
#include "../ResourceManager.h"
#include "../ObjectManager.h"



Attack::Attack()
	:Component(ATTACK), target(nullptr)
{}


Attack::~Attack(){}


void Attack::update()
{
	Attribute* attribute = static_cast<Attribute*>(owner->GetComponent(ATTRIBUTE));
	if (!hasTarget()) searchTarget();

	if (attribute == nullptr) return;
	if (hasTarget() && attribute->deploied) attack();
}



void Attack::print() const
{}



void Attack::Serialize(std::ifstream& InputStream)
{
	std::cout << "Serializing Attack" << std::endl;

	InputStream >> coolDown ;
	coolDown *= 1000;

	std::cout << "coolDown limit: " << coolDown << std::endl;
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
		GameObject* bullet = ResourceManager::getInstance().LoadGameObject("res/Data/Bullet.txt");
		bullet->transform->position = owner->transform->position / bullet->transform->scale;	// set bullet initial position
		bullet->transform->print();
	
		bullet->body->setVelocity(glm::vec2(target->transform->position) - glm::vec2(bullet->transform->position));
		//std::cout << "Attack ends" << std::endl;
	}
}


bool Attack::hasTarget()
{
	if (target == nullptr) return false;
	return ObjectManager::getInstance().find(target);
}


