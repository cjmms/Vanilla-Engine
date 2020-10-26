#include "ResourceManager.h"
#include "GameObject.h"
#include "ObjectManager.h"


void ResourceManager::createTexture(unsigned int &id, const char* filePath)
{
    glGenTextures(1, &id);

    int width, height, nrComponents;
    unsigned char* data = stbi_load(filePath, &width, &height, &nrComponents, 0);
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

        glBindTexture(GL_TEXTURE_2D, id);
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



ResourceManager::~ResourceManager(){}


void ResourceManager::init(void)
{}


void ResourceManager::close(void)
{}


ResourceManager& ResourceManager::getInstance()
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
        std::cout << "Load Game Object: " << fileName << std::endl;

        obj = new GameObject();
        while (std::getline(inputStream, componentName))
        {
            Component* component = nullptr;

            if (componentName == "Transform")   component = obj->AddComponent(TRANSFORM);
            if (componentName == "Sprite")      component = obj->AddComponent(SPRITE);
            if (componentName == "Controller")  component = obj->AddComponent(CONTROLLER);
            if (componentName == "UpDown")      component = obj->AddComponent(UP_DOWN);
                
            if (component != nullptr) component->Serialize(inputStream);
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

            if (obj != nullptr) obj->transform->Serialize(inputStream);
        }

        inputStream.close();
    }
}

