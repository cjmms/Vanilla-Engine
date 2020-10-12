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
         -0.25f,  0.25f,
        -0.25f, -0.25f,
         0.25f,  0.25f,
         0.25f, -0.25f
    };

    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // VAO
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    Shader shader("src/demo.shader");


    shader.setVec2("position", position);
    shader.Bind();
}


void Entity::setPosition(const Vector2D& position)
{
	this->position = position;
}

void Entity::setHealth(float health)
{
	this->health = health;
}

void Entity::draw(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}