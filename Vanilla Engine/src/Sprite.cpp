#include "Sprite.h"



Sprite::Sprite(std::string address) : Component(SPRITE)
{
    
}


Sprite::Sprite() :Component(SPRITE)  {}


Sprite::~Sprite()
{}


void Sprite::update()
{}

// TODO: move shader to a higher level
// Each object bounds with one shader object for now
void Sprite::draw( const Vector2D& pos )
{
    Shader shader("src/demo.shader");

    shader.setInt("diffuse", 0);
    glActiveTexture(GL_TEXTURE0);
   
    shader.setVec2("position", pos);
    shader.Bind();

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void Sprite::Serialize(std::ifstream& InputStream)
{
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