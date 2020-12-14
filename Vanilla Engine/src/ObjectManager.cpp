#include "ObjectManager.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include <ft2build.h>
#include "FPSController.h"
#include "TextRenderer.h"

ObjectManager::ObjectManager()
{
	totalTime = 0;
}



ObjectManager::~ObjectManager()
{
}

int ObjectManager::FindTerminalHealth()
{
	for (auto obj : GameObjects)
		if (obj->sprite->address == "res/Texture/bonfire.png") return obj->attribute->health;	
	
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

	totalTime += FPSController::getInstance().getFrameTime();

	TextRenderer renderer;
	renderer.init(1200, 800, "src/text.shader");
	renderer.loadFont("res/Font/Lora-Regular.ttf");
	std::string t("Passed Time: ");

	t = t +  std::to_string(totalTime / 1000.0f);
	renderer.RenderText(t, 400.0f, 700.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
	
	int frequency = totalTime / 5000;
	if (frequency == 0) frequency = 1;
	for (int i = 0; i < frequency; i++) createEnemy();

}



void ObjectManager::createEnemy()
{
	timer -= FPSController::getInstance().getFrameTime();

	if (timer < 0.0f)
	{
		timer = 1000;
		GameObject* obj = ResourceManager::getInstance().LoadGameObject("res/Data/Enemy.txt");

		float x = (rand() % 300 + 100) / 100.0f;
		float sign = rand() % 2;
		x = sign > 0 ? x : -x;

		obj->transform->position.x = x;

		float y = (rand() % 300 + 100) / 100.0f;
		sign = rand() % 2;
		std::cout << "sign: " << sign << std::endl;
		y = sign > 0 ? y : -y;

		obj->transform->position.y = y;
	}

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

