#include "Attribute.h"
#include "../GameObject.h"
#include "../CollisionManager.h"
#include "../ObjectManager.h"

Attribute::Attribute()
	:Component(ATTRIBUTE), health(1)
{}



Attribute::~Attribute()
{}


bool Attribute::dead(void)
{
	return health <= 0;
}

void Attribute::update(void)
{}

// serialize mass and inMass
void Attribute::Serialize(std::ifstream& InputStream)
{
	//std::cout << "Serializing Attributes!!!!!!!!!!!!!!!!" << std::endl;
	std::string h;
	InputStream >> h;
	if (h == "health") InputStream >> health;

	std::cout << "Serializing Attributes" << std::endl;
	std::cout << "Health: " << health << std::endl;
}



void Attribute::HandleEvent(Event* event)
{
	// get attcked, if health reachs 0, remove obj
	if (event->type == EventType::COLLISION)
	{
		//std::cout << "handle collision" << std::endl;
		--health;
	}
}