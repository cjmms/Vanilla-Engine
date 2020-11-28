#include "VanillaEngine.h"


void VanillaEngine::init(void)
{
    initUI();

    if (glewInit() != GLEW_OK) std::cout << "GLEW init error" << std::endl;

    InputManager::getInstance().init();
    ResourceManager::getInstance().init();
    ObjectManager::getInstance().close();
    PhysicsManager::getInstance().init();


    ResourceManager::getInstance().LoadLevel("res/Data/Level.txt");
}


void VanillaEngine::initUI(void)
{
    // Initialize the library
    if (!glfwInit()) std::cout << "GLFW init error" << std::endl;

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(1200, 1000, "Vanilla", NULL, NULL);
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
    PhysicsManager::getInstance().close();
    ObjectManager::getInstance().close();
    ResourceManager::getInstance().close();
    InputManager::getInstance().close();
    closeUI();
}


void VanillaEngine::update(void)
{
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

        //if (InputManager::getInstance().keyIsPressed(GLFW_KEY_W))

        shader.setMat4("Projection", pers);
        shader.setMat4("View", lookat);

        PhysicsManager::getInstance().update();

        ObjectManager::getInstance().update();
        ObjectManager::getInstance().render(shader);


        glfwSwapBuffers(window);
    }
}
 
