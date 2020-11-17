#pragma once
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Vector2D.h"
#include "Vector3D.h"
#include "Matrix4.h"
#include "Transformation.h"



struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
	std::string GeometrySource;
};


class Shader
{
private:
	std::string shaderFilePath;

	// program ID of shader
	unsigned int rendererID;

public:
	Shader() :rendererID(0) {};
	Shader(const std::string& path);
	~Shader();
	void Bind() const;
	void unBind();
	int getUniformLocation(const char* name) const;
	unsigned int getRendererID();

	
	void setMat4(const char* name, Matrix4& matrix) const;
	void setMat4(const std::string& name, Matrix4& matrix) const;
	void setVec3(const char* name, const Vector3D& vec) const;
	void setVec3(const std::string& name, const Vector3D& vec) const;
	void setVec2(const char* name, const Vector2D& vec) const;
	void setVec2(const std::string& name, const Vector2D& vec) const;
	//void setFloat(const char* name, float value);
	//void setFloat(const std::string& name, float value);
	
	void setInt(const char* name, int value) const;
	void setInt(const std::string& name, int value) const;


private:
	// path: res/Shaders/basic.shader
	// path is relative a path
	// absolute path is ($SolutionDir)path
	ShaderProgramSource parseShader(const std::string& path);

	// type: GL_FRAGMENT_SHADER or GL_VERTEX_SHADER
	// return shader program ID
	unsigned int compileShader(unsigned int type, const std::string& shaderSource);
	void shaderErrorInfo(unsigned int shader, unsigned int type);

	// vertexShader: shader source as a string
	// fragmentShader: shader source as a string
	// return shader ID
	unsigned int createShader(const std::string& vertexShader,
		const std::string& fragmentShader,
		const std::string& geometryShader);
};
