#pragma once
#include <string>
#include <glad/glad.h>
#include <fstream>
#include <iostream>
#include <sstream>



class Shader
{
public :
	char* name;
	unsigned int ID;

	void use();

	//uniform
	void SetBool(const std::string& name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;

	void createVertexShader();
	void createFragmentShader();
	void createShaderProgram();

	static Shader* CreateShader(const char* vertexPath, const char* fragmentPath);
private:
	char* content;
};

