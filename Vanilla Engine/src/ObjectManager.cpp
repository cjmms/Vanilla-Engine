#include "ObjectManager.h"


ObjectManager::ObjectManager()
{}



ObjectManager::~ObjectManager()
{
}



void ObjectManager::add(GameObject *object)
{
	if (object != nullptr) GameObjects.push_back(object);
}

void ObjectManager::remove(GameObject* object)
{
	if (object != nullptr) // remove by value
	{
		delete object;
		GameObjects.erase(std::remove(GameObjects.begin(), GameObjects.end(), object), GameObjects.end());
	}
}


ObjectManager& ObjectManager::getInstance(void)
{
	static ObjectManager objMgr;
	return objMgr;
}


void ObjectManager::update( void )
{
	for (GameObject* obj : GameObjects) obj->update();

	// check if the obj is dead
	for (GameObject* obj : GameObjects) if (obj->attribute->dead()) remove(obj);
}


void ObjectManager::render(Shader& shader) const
{
	for (GameObject* obj : GameObjects) obj->sprite->draw(shader);
}


void ObjectManager::close( void )
{
	for (GameObject* object : GameObjects) delete object;
	GameObjects.clear();
}

