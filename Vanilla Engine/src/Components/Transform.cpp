#include "Transform.h"
#include <fstream>

Transform::Transform() : Component(TRANSFORM), position(glm::vec3(0.0f))
{}


Transform::~Transform()
{}


void Transform::update(void)
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
    std::cout << "Serializing Transform" << std::endl;
    InputStream >> position.x;
    InputStream >> position.y;
    InputStream >> position.z;

    std::cout << "x: " << position.x << "  y: " << position.y << "  z: " << position.z << std::endl;

}