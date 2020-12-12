#pragma once

#include <string>
#include "Shader.h"

#include <iostream>
#include <map>


#include <ft2build.h>
#include FT_FREETYPE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "ext.hpp"

class TextRenderer
{
private:
    struct Character {
        unsigned int TextureID; // ID handle of the glyph texture
        glm::ivec2   Size;      // Size of glyph
        glm::ivec2   Bearing;   // Offset from baseline to left/top of glyph
        unsigned int Advance;   // Horizontal offset to advance to next glyph
    };

    std::map<GLchar, Character> Characters;
    unsigned int VAO, VBO;
    unsigned int SCR_WIDTH;
    unsigned int SCR_HEIGHT;

    Shader* shader;


public:
	void RenderText(std::string text, float x, float y, float scale, glm::vec3 color);
    void init(unsigned int width, unsigned int height, std::string shaderAdd);
    void loadFont(std::string fontAddress);
    void close(void);
};

