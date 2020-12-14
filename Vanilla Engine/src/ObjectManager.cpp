#include "ObjectManager.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include <ft2build.h>
#include "FPSController.h"

ObjectManager::ObjectManager()
{}



ObjectManager::~ObjectManager()
{
}

int ObjectManager::FindTerminalHealth()
{
	//int health = 0;
	for (auto obj : GameObjects)
	{
		//Attribute* attribute = static_cast<Attribute*>(obj->GetComponent(ATTRIBUTE));
		//if (attribute == nullptr) continue;
		//if (attribute->health > health) {
		//	if (attribute->health <= 10)
		//	health = attribute->health;
			//std::cout << "set health to: " << health << std::endl;
		//}
		//std::cout << obj->sprite->address << std::endl;
		if (obj->sprite->address == "res/Texture/bonfire.png") return obj->attribute->health;
	}
	
	return 0;
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
	std::vector<GameObject*>::size_type size = GameObjects.size();
	for (std::vector<GameObject*>::size_type i = 0; i < size; ++i)
		GameObjects[i]->update();
	
	if (InputManager::getInstance().keyIsPressed(GLFW_KEY_J)) createObj();
	createEnemy();
}



void ObjectManager::createEnemy()
{
	timer -= FPSController::getInstance().getFrameTime();

	if (timer < 0.0f)
	{
		timer = 2000;
		GameObject* obj = ResourceManager::getInstance().LoadGameObject("res/Data/Enemy.txt");

		float x = rand() % 1 + 2;
		float sign = rand() % 2;
		x = sign > 0 ? x : -x;

		obj->transform->position.x = x;

		float y = rand() % 1 + 2;
		sign = rand() % 2;
		std::cout << "sign: " << sign << std::endl;
		y = sign > 0 ? y : -y;

		obj->transform->position.y = y;
	}



	//GameObject* obj = ResourceManager::getInstance().LoadGameObject("res/Data/Enemy.txt");
	//obj->transform->position.x = 2;
	//obj->transform->position.y = 2;
}


void ObjectManager::createObj()
{
	std::vector<GameObject*>::size_type size = GameObjects.size();

	// do not create new object if player is controlling one object already
	for (std::vector<GameObject*>::size_type i = 0; i < size; ++i) 
		if (nullptr != GameObjects[i]->GetComponent(CONTROLLER)) return;
		
	ResourceManager::getInstance().LoadGameObject("res/Data/player.txt");
}



void ObjectManager::deleteObj()
{
	std::vector< GameObject* >::iterator it = GameObjects.begin();

	while (it != GameObjects.end()) {
		Attribute* attribute = static_cast<Attribute*>((*it)->GetComponent(ATTRIBUTE));
		if (attribute != nullptr && attribute->dead()) {
			delete (*it);
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

