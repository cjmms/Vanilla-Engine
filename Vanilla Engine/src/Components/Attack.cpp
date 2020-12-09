#include "Attack.h"


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
}



bool Attack::searchTarget()
{
	return false;
}


void Attack::attack()
{

}


bool Attack::hasTarget()
{
	return false;
}


