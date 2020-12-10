#include "Attribute.h"
#include "../GameObject.h"
#include "../CollisionManager.h"
#include "../PhysicsManager.h"
#include "../ObjectManager.h"

Attribute::Attribute()
	:Component(ATTRIBUTE), health(1), hostile(false), deploied(false)
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
	std::string h;
	InputStream >> h;
	if (h == "health") InputStream >> health;

	InputStream >> h;
	if (h == "hostile") InputStream >> hostile;

	InputStream >> h;
	if (h == "deploy") InputStream >> deploied;


	std::cout << "Serializing Attributes" << std::endl;
	print();
}


void Attribute::getAttacked(Event * event)
{
	if (event->type == EventType::COLLISION) {
		CollideEvent* collide = dynamic_cast<CollideEvent*>(event);
		
		if (collide->isHostile)
			--health;
	}
}



void Attribute::HandleEvent(Event* event)
{
	// check if get attched
	if (deploied) getAttacked(event);
	
}


void Attribute::print() const
{
	std::cout << "Health: " << health << std::endl;
	std::cout << "Hostile: " << hostile << std::endl;
}