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


ObjectManager& ObjectManager::getInstance()
{
	static ObjectManager objMgr;
	return objMgr;
}

void ObjectManager::update( void )
{
	for (GameObject* obj : GameObjects) obj->update();
}


void ObjectManager::render(Shader& shader) const
{
	for (GameObject* obj : GameObjects) obj->sprite->draw(obj->transform->position, shader);
}


void ObjectManager::close( void )
{
	for (GameObject* object : GameObjects) delete object;
	GameObjects.clear();
}
