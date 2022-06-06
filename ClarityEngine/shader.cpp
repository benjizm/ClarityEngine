#include <fstream>
#include <string>
#include "shader.h"

std::string readFile(const char* path) {
	std::ifstream stream(path, std::ios::binary);
	std::string content;
	stream.seekg(0, std::ios::end);
	content.resize(stream.tellg());
	stream.seekg(0, std::ios::beg);
	stream.read(&content[0], content.size());
	stream.close();
	return content;
}

cengine::shader::shader(const char* vertexPath, const char* fragmentPath) {
	std::string vertex = readFile(vertexPath);
	std::string fragment = readFile(fragmentPath);
	const char* cvert = vertex.c_str();
	const char* cfrag = fragment.c_str();

	GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertShader, 1, &cvert, NULL);
	glCompileShader(vertShader);

	GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragShader, 1, &cfrag, NULL);
	glCompileShader(fragShader);

	id = glCreateProgram();
	glAttachShader(id, vertShader);
	glAttachShader(id, fragShader);
	glLinkProgram(id);
	glDeleteShader(vertShader);
	glDeleteShader(fragShader);
}

void cengine::shader::use() {
	glUseProgram(id);
}

void cengine::shader::deleteShader() {
	glDeleteProgram(id);
}