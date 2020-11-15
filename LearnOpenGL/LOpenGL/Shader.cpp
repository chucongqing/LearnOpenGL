#include "Shader.h"

void Shader::createVertexShader() {

}

void Shader::createFragmentShader() {

}

void Shader::createShaderProgram() {

}

static Shader* CreateShader(const char* vertexPath, const char* fragmentPath) {
	Shader* shader = new Shader();

	std::string vertexCode;
	std::string framgentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	// 保证ifstream对象可以抛出异常：
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	
	try {
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);

		std::stringstream vShaderSStream, fShaderSStream;
		
		vShaderSStream << vShaderFile.rdbuf();
		fShaderSStream << fShaderSStream.rdbuf();

		vShaderFile.close();
		fShaderFile.close();

		vertexCode = vShaderSStream.str();
		framgentCode = fShaderSStream.str();
	}
	catch (std::ifstream::failure e) {
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
	
	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCOde = framgentCode.c_str();
	
	//compile shaders
	unsigned int vertex, fragment;
	int success;
	char infolog[512];

	//vertex shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);

	//error dealing
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	
	if (!success) {
		glGetShaderInfoLog(vertex, 512, NULL, infolog);
		std::cout << "ERROR_Compile VERTEX Shader " << infolog << std::endl;
	}

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCOde, NULL);
	glCompileShader(fragment);

	//error dealing
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(fragment, 512, NULL, infolog);
		std::cout << "ERROR_Compile fragment Shader " << infolog << std::endl;
	}


	//program
	unsigned ID = shader->ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);

	glGetProgramiv(ID, GL_LINK_STATUS, &success);

	if (!success) {
		glGetProgramInfoLog(ID, 512, NULL, infolog);
		std::cout << "ERROR :: Shader : : PRogram Error" << std::endl;
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);

	return shader;
}
