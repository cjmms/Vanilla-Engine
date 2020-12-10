#include "ResourceManager.h"
#include "GameObject.h"
#include "ObjectManager.h"


void ResourceManager::createTexture(std::string filePath)
{
    // texture is created already, return
    //if (textures.find(filePath) != textures.end()) return;
    
    glGenTextures(1, &textures[filePath]);

    int width, height, nrComponents;
    unsigned char* data = stbi_load(filePath.c_str(), &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum internalFormat;
        GLenum dataFormat;
        if (nrComponents == 1)
        {
            internalFormat = dataFormat = GL_RED;
        }
        else if (nrComponents == 3)
        {
            internalFormat = GL_RGB;
            dataFormat = GL_RGB;
        }
        else if (nrComponents == 4)
        {
            internalFormat = GL_RGBA;
            dataFormat = GL_RGBA;
        }

        stbi_set_flip_vertically_on_load(true);
        glBindTexture(GL_TEXTURE_2D, textures[filePath]);
        glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, dataFormat, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << filePath << std::endl;
        stbi_image_free(data);
    }
}



void ResourceManager::bindTexture(std::string address)
{
    glBindTexture(GL_TEXTURE_2D, textures[address]);
}


ResourceManager::~ResourceManager(){}


void ResourceManager::init(void)
{
    recVAO = 0;
    initRec();
}

void ResourceManager::bindRecVAO(void)
{
    glBindVertexArray(recVAO);
}


void ResourceManager::initRec(void)
{
    float vertices[] = {
        // positions         
        -0.25f,  0.25f, 0.0, 1.0,
        -0.25f, -0.25f, 0.0, 0.0,
         0.25f,  0.25f, 1.0, 1.0,
         0.25f, -0.25f, 1.0, 0.0
    };

    GLuint VBO;
    glGenVertexArrays(1, &recVAO);
    glBindVertexArray(recVAO);

    // VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // VAO
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);
}


void ResourceManager::close(void)
{}


ResourceManager& ResourceManager::getInstance(void)
{
    static ResourceManager ResourceMgr;
    return ResourceMgr;
}



GameObject* ResourceManager::LoadGameObject(const char* fileName)
{
    GameObject* obj = nullptr;
    std::string componentName;
    std::ifstream inputStream(fileName);

    if (inputStream.is_open())
    {
        std::cout << "\n" <<"Load Game Object: " << fileName << std::endl;

        obj = new GameObject();
        while (std::getline(inputStream, componentName))
        {
            Component* component = nullptr;
            if (componentName == "Transform")   component = obj->AddComponent(TRANSFORM);
            if (componentName == "Sprite")      component = obj->AddComponent(SPRITE);
            if (componentName == "Controller")  component = obj->AddComponent(CONTROLLER);
            if (componentName == "UpDown")      component = obj->AddComponent(UP_DOWN);
            if (componentName == "Body")        component = obj->AddComponent(BODY);
            if (componentName == "Attribute")   component = obj->AddComponent(ATTRIBUTE);
            if (componentName == "Attack")      component = obj->AddComponent(ATTACK);
            
            // Serializing each component
            if (component != nullptr)           component->Serialize(inputStream);
        }
        ObjectManager::getInstance().add(obj);
        
        inputStream.close();
    }

    return obj;
}


void ResourceManager::LoadLevel(const char* fileName)
{
    std::string objName;
    std::ifstream inputStream(fileName);

    if (inputStream.is_open())
    {
        std::cout << "Load level: " << fileName << std::endl;

        while (std::getline(inputStream, objName))
        {
            std::string address = "res/Data/" + objName + ".txt";
            GameObject* obj = ResourceManager::getInstance().LoadGameObject(address.c_str());
            if (obj != nullptr) obj->transform->SerializePosition(inputStream);
        }

        inputStream.close();
    }
}

