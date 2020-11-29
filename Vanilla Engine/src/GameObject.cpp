#include "GameObject.h"


GameObject::GameObject()
	: transform(nullptr), sprite(nullptr), controller(nullptr), upDown(nullptr)
{
}

GameObject::~GameObject()
{
	for (auto component : componentList) delete component;
	componentList.clear();
}

void GameObject::update(void)
{
	for (auto component : componentList) component->update();
}


Component* GameObject::AddComponent(ComponentType type) 
{
	Component* component = GetComponent(type);
	if (component != nullptr) return component;

	switch (type)
	{
	case TRANSFORM:
		component = new Transform();
		this->transform = static_cast<Transform*>(component);
		break;
	case SPRITE:
		component = new Sprite();
		this->sprite = static_cast<Sprite*>(component);
		break;
	case CONTROLLER:
		component = new Controller();
		this->controller = static_cast<Controller*>(component);
		break;
	case UP_DOWN:
		component = new UpDown();
		this->upDown = static_cast<UpDown*>(component);
		break;
	case BODY:
		component = new Body();
		this->body = static_cast<Body*>(component);
		break;
	default:
		return nullptr;
	}


	if (component != nullptr)
	{
		componentList.push_back(component);
		component->owner = this;
	}

	return component;
}


Component* GameObject::GetComponent(ComponentType type)
{
	for (auto component : componentList)
		if (type == component->getType()) return component;

	return nullptr;
}



void GameObject::HandleEvent(Event& event)
{
	for (auto component : componentList) component->HandleEvent(event);
}