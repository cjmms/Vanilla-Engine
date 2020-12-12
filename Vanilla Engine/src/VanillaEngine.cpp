#include "VanillaEngine.h"



void VanillaEngine::init(void)
{
    initUI();

    if (glewInit() != GLEW_OK) std::cout << "GLEW init error" << std::endl;

    InputManager::getInstance().init();
    ResourceManager::getInstance().init();
    //ObjectManager::getInstance().init();
    EventManager::getInstance().init();
    PhysicsManager::getInstance().init();

    textRenderer.init(width, height, "src/text.shader");
    textRenderer.loadFont("res/Font/Lora-Regular.ttf");


    ResourceManager::getInstance().LoadLevel("res/Data/Level.txt");
}


void VanillaEngine::initUI(void)
{
    // Initialize the library
    if (!glfwInit()) std::cout << "GLFW init error" << std::endl;

    // Create a windowed mode window and its OpenGL context

    window = glfwCreateWindow(width, height, "Cyberpunk 1077", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
}



void VanillaEngine::closeUI(void)
{
    glfwTerminate();
}


void VanillaEngine::close(void)
{
    textRenderer.close();
    PhysicsManager::getInstance().close();
    EventManager::getInstance().close();
    ObjectManager::getInstance().close();
    ResourceManager::getInstance().close();
    InputManager::getInstance().close();

    closeUI();
}




void VanillaEngine::update(void)
{
    bool play = false;
    // game loop
    while (!glfwWindowShouldClose(window))
    {
        FPSController::getInstance().UpdateFrameTime();
        InputManager::getInstance().getInputs(window);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        Shader shader("src/demo.shader");
        shader.Bind();

        glm::mat4 pers = glm::perspective(glm::radians(45.0f), 1200 / 1000.0f, 0.1f, 100.0f);
        glm::mat4 lookat = glm::lookAt(glm::vec3(0.0, 0.0, 6.0), glm::vec3(0.0), glm::vec3(0.0, 1.0, 0.0));


        shader.setMat4("Projection", pers);
        shader.setMat4("View", lookat);



        if (play)
        {
            ObjectManager::getInstance().update();
            PhysicsManager::getInstance().update();

            EventManager::getInstance().update(FPSController::getInstance().getFrameTime());
            ObjectManager::getInstance().deleteObj();

            ObjectManager::getInstance().render(shader);

            if (InputManager::getInstance().keyIsPressed(GLFW_KEY_N)) {
                ObjectManager::getInstance().close();
                ResourceManager::getInstance().LoadLevel("res/Data/Level.txt");
            }
        }
        else
        {   // Mune
            textRenderer.RenderText("This is sample text", 25.0f, 25.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));
            textRenderer.RenderText("(C) LearnOpenGL.com", 540.0f, 570.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
            play = InputManager::getInstance().keyIsPressed(GLFW_KEY_N);
        }

        glfwSwapBuffers(window);
    }
}
 
