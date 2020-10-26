#include "ObjectManager.h"


ObjectManager::ObjectManager()
{}



ObjectManager::~ObjectManager()
{
	for (auto& object : GameObjects) delete(object);
}



void ObjectManager::add(GameObject *object)
{
	if (object != nullptr) GameObjects.push_back(object);
}


ObjectManager& ObjectManager::getInstance()
{
	static ObjectManager ResourceMgr;
	return ResourceMgr;
}
