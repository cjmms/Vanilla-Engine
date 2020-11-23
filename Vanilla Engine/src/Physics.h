#pragma once

#include "ext.hpp"
#include <cmath>
class Physics
{
};


int StaticRectToStaticRect(glm::vec2 pRect0, float Width0, float Height0, glm::vec2 pRect1, float Width1, float Height1);


int checkLineCollideHori(float line1Left, float line1Right, float line1W, float line2Left, float line2Right, float line2W);


float pointDistance(float a, float b);

