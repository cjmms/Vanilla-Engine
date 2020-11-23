#include "Shader.h"


Shader::Shader(const std::string& path)
    :rendererID(0), shaderFilePath(path)
{
    ShaderProgramSource source = parseShader(shaderFilePath);
    rendererID = createShader(source.VertexSource,
        source.FragmentSource,
        source.GeometrySource);
}

Shader::~Shader()
{
    glDeleteProgram(rendererID);
}



ShaderProgramSource Shader::parseShader(const std::string& path)
{
    enum class ShaderMode {
        NONE = -1, VERTEX_MODE = 0, FRAGMENT_MODE = 1, GEOMETRY_MODE = 2
    };
    std::fstream stream(path);
    std::string line;

    // 3 string streams, one for vertex shader, one for fragment shader, one for geometry shader
    std::stringstream ss[3];
    ShaderMode currentMode = ShaderMode::NONE;

    // shader file has 2 lines: #shader fragment and #shader vertex 
    // if any or these lines are detected, switch mode, output to another stringstream
    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
                currentMode = ShaderMode::VERTEX_MODE;
            else if (line.find("fragment") != std::string::npos)
                currentMode = ShaderMode::FRAGMENT_MODE;
            else if (line.find("geometry") != std::string::npos &&
                !(line.find("//") != std::string::npos))
                currentMode = ShaderMode::GEOMETRY_MODE;
        }
        else
        {
            ss[(int)currentMode] << line << '\n';
        }
    }
    return { ss[0].str(), ss[1].str(), ss[2].str() };
}


unsigned int Shader::createShader(const std::string& vertexShader,
    const std::string& fragmentShader,
    const std::string& geometryShader)
{
    bool hasGeometryShader = geometryShader.length() > 0;


    unsigned int shaderProgram = glCreateProgram();
    unsigned int vertexShaderID = compileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fragmentShaderID = compileShader(GL_FRAGMENT_SHADER, fragmentShader);
    unsigned int geometryShaderID;

    glAttachShader(shaderProgram, vertexShaderID);
    glAttachShader(shaderProgram, fragmentShaderID);

    if (hasGeometryShader) {
        geometryShaderID = compileShader(GL_GEOMETRY_SHADER, geometryShader);
        glAttachShader(shaderProgram, geometryShaderID);
    }


    // TODO: catch exceptions
    glLinkProgram(shaderProgram);

    //TODO: catch exceptions
    glValidateProgram(shaderProgram);

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
    if (hasGeometryShader) glDeleteShader(geometryShaderID);

    return shaderProgram;
}

unsigned int Shader::compileShader(unsigned int type, const std::string& shaderSource)
{
    unsigned int id = glCreateShader(type);
    const char* source = shaderSource.c_str();

    glShaderSource(id, 1, &source, NULL);
    glCompileShader(id);
    shaderErrorInfo(id, type);
    return id;
}

void Shader::shaderErrorInfo(unsigned int shader, unsigned int type)
{
    GLint success;
    char infoLog[512];
    // success is a flag, it will be set to False if things went wrong
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        if (type == GL_VERTEX_SHADER)
            std::cout << "ERROR: Vertex Shader Compilation Error. " << infoLog << std::endl;
        else if (type == GL_FRAGMENT_SHADER)
            std::cout << "ERROR: Fragment Shader Compilation Error. " << infoLog << std::endl;
        else
            std::cout << "ERROR: Geometry Shader Compilation Error. " << infoLog << std::endl;
    }
}

void Shader::Bind() const
{
    glUseProgram(rendererID);
}

void Shader::unBind()
{
    glUseProgram(0);
}


int Shader::getUniformLocation(const char* name) const
{
    return glGetUniformLocation(rendererID, name);
}

unsigned int Shader::getRendererID()
{
    return rendererID;
}



void Shader::setInt(const char* name, int value) const
{
    unsigned int location = getUniformLocation(name);
    glUniform1i(location, value);
}


void Shader::setInt(const std::string& name, int value) const
{
    setInt(name.c_str(), value);
}


void Shader::setVec2(const char* name, const Vector2D& vec) const
{
    unsigned int location = getUniformLocation(name);
    glProgramUniform2f(rendererID, location, vec.x, vec.y);
}


void Shader::setVec2(const std::string& name, const Vector2D& vec) const
{
    setVec2(name.c_str(), vec);
}


void Shader::setVec3(const char* name, const glm::vec3& vec) const
{
    unsigned int location = getUniformLocation(name);
    glProgramUniform3f(rendererID, location, vec.x, vec.y, vec.z);
}


void Shader::setVec3(const std::string& name, const glm::vec3& vec) const
{
    setVec3(name.c_str(), vec);
}


void Shader::setMat4(const char* name, glm::mat4& matrix) const
{
    unsigned int location = getUniformLocation(name);
   // std::cout << "matrix[0][0]: " << matrix.table[0][0] << std::endl;
    //std::cout << "matrix[0][1]: " << matrix.table[0][1] << std::endl;
    //std::cout << "matrix[0][2]: " << matrix.table[0][2] << std::endl;
    //std::cout << "matrix[0][3]: " << matrix.table[0][3] << std::endl;
    //glUniformMatrix4fv(location, 1, GL_FALSE, Transformation::Pntr(matrix));
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}


void Shader::setMat4(const std::string& name, glm::mat4& matrix) const
{
    setMat4(name.c_str(), matrix);
}