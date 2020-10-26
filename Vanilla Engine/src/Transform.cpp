#include "Transform.h"


Transform::Transform() : Component(TRANSFORM)
{
	position.x = 0;
	position.y = 0;
}



Transform::~Transform()
{}



void Transform::update()
{}


void Transform::moveUp(void)
{
    position.y += 0.01f;
}


void Transform::moveDown(void)
{
    position.y -= 0.01f;
}


void Transform::moveLeft(void)
{
    position.x -= 0.01f;
}


void Transform::moveRight(void)
{
    position.x += 0.01f;
}