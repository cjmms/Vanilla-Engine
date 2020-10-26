#include "GameObject.h"

GameObject::GameObject()
	: transform(nullptr), sprite(nullptr), controller(nullptr), upDown(nullptr)
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
	if (upDown != nullptr) upDown->update();

}