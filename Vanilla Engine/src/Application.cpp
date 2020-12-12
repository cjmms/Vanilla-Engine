#define STB_IMAGE_IMPLEMENTATION
#include "VanillaEngine.h"


int main()
{
    VanillaEngine Engine;
    Engine.init();

    // Loop until the user closes the window
    Engine.update();

    Engine.close();
    return 0;
}

