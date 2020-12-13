#include "Transform.h"
#include <fstream>
#include "Component.h"
#include "../GameObject.h"
#include "Attribute.h"

Transform::Transform() : Component(TRANSFORM), position(glm::vec3(0.0f)), scale(glm::vec3(1.0f))
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

void Transform::move(glm::vec2 dis)
{
    position.x += dis.x;
    position.y += dis.y;
}

void Transform::Serialize(std::ifstream& InputStream)
{
    std::cout << "Serializing Transform" << std::endl;

    // serialize scale from object file
    SerializeScale(InputStream);

    print();
}



void Transform::SerializePosition(std::ifstream& InputStream)
{
    InputStream >> position.x;
    InputStream >> position.y;
    InputStream >> position.z;
    
}



void Transform::SerializeScale(std::ifstream& InputStream)
{
    InputStream >> scale.x;
    InputStream >> scale.y;
    InputStream >> scale.z;
}


void Transform::print() const
{
    std::cout << "Position: x: " << position.x << "  y: " << position.y << "  z: " << position.z << std::endl;
    std::cout << "Scale: x: " << scale.x << "  y: " << scale.y << "  z: " << scale.z << std::endl;
}