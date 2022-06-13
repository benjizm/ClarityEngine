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

	uint32_t vertShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertShader, 1, &cvert, NULL);
	glCompileShader(vertShader);

	uint32_t fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragShader, 1, &cfrag, NULL);
	glCompileShader(fragShader);

	id = glCreateProgram();
	glAttachShader(id, vertShader);
	glAttachShader(id, fragShader);
	glLinkProgram(id);
	glDeleteShader(vertShader);
	glDeleteShader(fragShader);

	int32_t* uniformCount = new int32_t();
	glGetProgramiv(id, GL_ACTIVE_UNIFORMS, uniformCount);

	for (int32_t i = 0; i < *uniformCount; i++) {
		char* active = new char[255];
		int32_t* discard = new int32_t();
		glGetActiveUniform(id, i, 255, discard, discard, (uint32_t*)discard, active);
		int32_t location = glGetUniformLocation(id, active);
		locations.emplace(active, location);
	}
}

void cengine::shader::use() {
	glUseProgram(id);
}

void cengine::shader::deleteShader() {
	glDeleteProgram(id);
}

void cengine::shader::setMat4x4(const char* name, fmat4x4& mat) {
	use();
	uint32_t location = locations.find(name)->second;
	glUniformMatrix4fv(location, 1, false, mat.m[0]);
}

void cengine::shader::setVec3(const char* name, fvec3d& vec) {
	use();
	uint32_t location = locations.find(name)->second;
	glUniform3f(location, vec.x, vec.y, vec.z);
}