#include "Entity.h"


Entity::Entity(void)
	:position(Vector2D(0.0f)), health(10.0f)
{}

Entity::Entity(const Vector2D& position)
	:position(position), health(10.0f)
{}

void Entity::spawn(void) 
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

    ResourceManager::getInstance().createTexture(TexID, "res/Texture/wood.jpg");
}


void Entity::setPosition(const Vector2D& position)
{
	this->position = position;
}

void Entity::setHealth(float health)
{
	this->health = health;
}

void Entity::draw(void) const
{
    Shader shader("src/demo.shader");

    shader.setInt("diffuse", 0);
    glActiveTexture(GL_TEXTURE0);

    shader.setVec2("position", position);
    shader.Bind();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}


void Entity::moveUp()
{
    position.y += 0.01f;
}


void Entity::moveDown(void)
{
    position.y -= 0.01f;
}


void Entity::moveLeft(void)
{
    position.x -= 0.01f;
}


void Entity::moveRight(void)
{
    position.x += 0.01f;
}