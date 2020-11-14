#pragma once
#include <string>

class Shader
{
public :
	char* name;
	
	void createVertexShader();
	void createFragmentShader();
	void createShaderProgram();

	static Shader* CreateShader(const char* shaderPath);
private:
	char* content;
};

