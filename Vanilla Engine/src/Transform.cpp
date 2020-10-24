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