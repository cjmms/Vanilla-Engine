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
    //textRenderer.loadFont("res/Font/Lora-Regular.ttf");
    //textRenderer.loadFont("res/Font/Cyberpunk.ttf");

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

enum GameState
{
    LOGO,
    INTRO,
    GAME
};


void VanillaEngine::update(void)
{
    GameState state = LOGO;
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


        if (state == GameState::LOGO)
        {
            if (InputManager::getInstance().keyIsPressed(GLFW_KEY_N)) state = GameState::INTRO;

            TextRenderer renderer;
            renderer.init(width, height, "src/text.shader");
            renderer.loadFont("res/Font/Cyberpunk.ttf");
            renderer.RenderText("CyberPunk", 360.0f, 470.0f, 1.5f, glm::vec3(0.5, 0.8f, 0.2f));

            textRenderer.loadFont("res/Font/Lora-Regular.ttf");
            textRenderer.RenderText("1077", 700.0f, 400.0f, 1.0f, glm::vec3(0.3, 0.7f, 0.9f));

            textRenderer.RenderText("Press N to Continue", 500.0f, 200.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));

        }
        else if (state == GameState::INTRO)
        {
            if (InputManager::getInstance().keyIsPressed(GLFW_KEY_K)) state = GameState::GAME;
            textRenderer.RenderText("This is a turret defend game.", 400.0f, 700.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
            textRenderer.RenderText("The game ends when \"Fire\" extinguished.", 200.0f, 500.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
            textRenderer.RenderText("1. Press J to creat cannon.", 200.0f, 400.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
            textRenderer.RenderText("2. Press WASD to move the cannon.", 200.0f, 370.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
            textRenderer.RenderText("3. press K to deploy.", 200.0f, 340.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
            textRenderer.RenderText("Press K to Continue", 500.0f, 100.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
        }
        else
        {   // Mune
            glDisable(GL_BLEND);

            std::string healthUI(ObjectManager::getInstance().FindTerminalHealth(), 'x');

            textRenderer.RenderText(healthUI, 100.0f, 700.0f, 1.0f, glm::vec3(0.7, 0.7f, 0.0f));
            ObjectManager::getInstance().update();
            PhysicsManager::getInstance().update();

            EventManager::getInstance().update(FPSController::getInstance().getFrameTime());
            ObjectManager::getInstance().deleteObj();

            ObjectManager::getInstance().render(shader);

            if (InputManager::getInstance().keyIsPressed(GLFW_KEY_N)) {
                state = GameState::GAME;
                ObjectManager::getInstance().close();
                ResourceManager::getInstance().LoadLevel("res/Data/Level.txt");
            }
        }

        glfwSwapBuffers(window);
    }
}
 
