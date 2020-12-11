#include "ObjectManager.h"
#include "ResourceManager.h"
#include "InputManager.h"

ObjectManager::ObjectManager()
{}



ObjectManager::~ObjectManager()
{
}


GameObject* ObjectManager::findEnemy(bool isHostile)
{
	for (auto obj : GameObjects)
	{
		Attribute* attribute = static_cast<Attribute*>(obj->GetComponent(ATTRIBUTE));
		if (attribute->hostile == isHostile) return obj;
	}
	return nullptr;
}

bool ObjectManager::find(GameObject *object) const
{
	return std::find(GameObjects.begin(), GameObjects.end(), object) != GameObjects.end();
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
	if (InputManager::getInstance().keyIsPressed(GLFW_KEY_J)) {
		GameObject* player = ResourceManager::getInstance().LoadGameObject("res/Data/player.txt");
	
	}
}

void ObjectManager::deleteObj()
{
	// check if the obj is dead
	for (GameObject* obj : GameObjects) {
		Attribute* attribute = static_cast<Attribute*>(obj->GetComponent(ATTRIBUTE));
		if (attribute != nullptr && attribute->dead()) remove(obj);
		
	}
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

