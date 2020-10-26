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

void Transform::Serialize(std::ifstream& InputStream)
{
    InputStream >> position.x;
    InputStream >> position.y;

    std::cout << "x: " << position.x << std::endl;
    std::cout << "y: " << position.y << std::endl;

}