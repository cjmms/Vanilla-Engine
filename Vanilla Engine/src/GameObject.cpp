#include "GameObject.h"

GameObject::GameObject()
	: transform(nullptr), sprite(nullptr), controller(nullptr)
{
}

GameObject::~GameObject()
{
	delete(transform);
	delete(sprite);
}

void GameObject::update()
{
	if (transform != nullptr) transform->update();
	if (sprite != nullptr) sprite->update();
	if (controller != nullptr) controller->update();

}