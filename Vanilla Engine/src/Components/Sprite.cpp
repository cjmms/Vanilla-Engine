#include "Sprite.h"
#include "../ResourceManager.h"
#include "../GameObject.h"


Sprite::Sprite() :Component(SPRITE), TexID(-1) {}


Sprite::~Sprite()
{}


void Sprite::update(void)
{}



void Sprite::draw(const Shader& shader)
{
    Transform* transform = static_cast<Transform*>(owner->GetComponent(TRANSFORM));
    shader.setInt("diffuse", 0);
    glActiveTexture(GL_TEXTURE0);
   
    shader.Bind();
    glm::mat4 Model = glm::translate(glm::mat4(1.0f), transform->position);
    shader.setMat4("Model", Model);

    //std::cout << "pos: x: " << pos.x << "  pos: y " << pos.y  << " pos: z " << pos.z<< std::endl;

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void Sprite::Serialize(std::ifstream& InputStream)
{
    std::cout << "Serializing Sprite" << std::endl;
    float vertices[] = {
        // positions         
        -0.25f,  0.25f, 0.0, 1.0,
        -0.25f, -0.25f, 0.0, 0.0,
         0.25f,  0.25f, 1.0, 1.0,
         0.25f, -0.25f, 1.0, 0.0
    };

    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // VAO
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    std::string address;
    InputStream >> address;
    address = "res/Texture/" + address;
    ResourceManager::getInstance().createTexture(TexID, address.c_str());

    std::cout << "Address: " << address << std::endl;
}