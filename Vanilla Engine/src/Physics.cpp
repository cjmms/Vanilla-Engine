#include "Physics.h"




int StaticRectToStaticRect(glm::vec2 pRect0, float Width0, float Height0, glm::vec2 pRect1, float Width1, float Height1)
{
    // check if horizontally overlap
    int hori = checkLineCollideHori(pRect0.x - Width0 / 2.0f, pRect0.x + Width0 / 2.0f, Width0,
        pRect1.x - Width1 / 2.0f, pRect1.x + Width1 / 2.0f, Width1);
    if (hori != 1) return 0;

    int vert = checkLineCollideHori(pRect0.y - Height0 / 2.0f, pRect0.y + Height0 / 2.0f, Height0,
        pRect1.y - Height1 / 2.0f, pRect1.y + Height1 / 2.0f, Height1);
    return vert;
}


int checkLineCollideHori(float line1Left, float line1Right, float line1W, float line2Left, float line2Right, float line2W)
{
    if (pointDistance(line1Left, line2Right) > line1W + line2W) return 0;
    if (pointDistance(line1Right, line2Left) > line1W + line2W) return 0;
    return 1;
}


float pointDistance(float a, float b)
{
    return std::abs(a - b);
}