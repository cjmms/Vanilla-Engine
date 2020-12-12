#include "ObjectManager.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include <ft2build.h>

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
		GameObjects.erase(std::remove(GameObjects.begin(), GameObjects.end(), object), GameObjects.end());	
		delete object;
	}
}


ObjectManager& ObjectManager::getInstance(void)
{
	static ObjectManager objMgr;
	return objMgr;
}


void ObjectManager::update( void )
{
	int test = 0;
	
	std::vector<GameObject*>::size_type size = GameObjects.size();
	for (std::vector<GameObject*>::size_type i = 0; i < size; ++i)
		GameObjects[i]->update();
	

	if (InputManager::getInstance().keyIsPressed(GLFW_KEY_J)) createObj();
}



void ObjectManager::createObj()
{
	
	GameObject* player = ResourceManager::getInstance().LoadGameObject("res/Data/player.txt");
	
}



void ObjectManager::deleteObj()
{
	std::vector< GameObject* >::iterator it = GameObjects.begin();

	while (it != GameObjects.end()) {
		Attribute* attribute = static_cast<Attribute*>((*it)->GetComponent(ATTRIBUTE));
		if (attribute != nullptr && attribute->dead()) {
			delete (*it);
			//std::cout << "deleting!!!!!" << std::endl;
			it = GameObjects.erase(it);
		}
		else ++it;
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

