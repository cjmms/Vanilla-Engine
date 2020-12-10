#include "Sprite.h"
#include "../ResourceManager.h"
#include "../GameObject.h"


Sprite::Sprite() :Component(SPRITE) {}


Sprite::~Sprite()
{}


void Sprite::update(void)
{}



void Sprite::draw(const Shader& shader)
{
    shader.Bind();

    Transform* transform = static_cast<Transform*>(owner->GetComponent(TRANSFORM));
    shader.setInt("diffuse", 0);
    glActiveTexture(GL_TEXTURE0);
    ResourceManager::getInstance().bindTexture(address);
   
    // Order: Scale, Rotate, Translation
    glm::mat4 Model = glm::scale(glm::mat4(1.0f), transform->scale);
    Model = glm::translate(Model, transform->position);
    
    shader.setMat4("Model", Model);

   // std::cout << "pos: x: " << transform->position.x << "  pos: y " << transform->position.y  << " pos: z " << transform->position.z<< std::endl;
    ResourceManager::getInstance().bindRecVAO();
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void Sprite::Serialize(std::ifstream& InputStream)
{
    std::cout << "Serializing Sprite" << std::endl;

    InputStream >> address;
    address = "res/Texture/" + address;
    ResourceManager::getInstance().createTexture(address);

    std::cout << "Address: " << address << std::endl;
}