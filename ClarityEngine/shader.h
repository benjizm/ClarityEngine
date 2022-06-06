#ifndef SHADER_H
#define SHADER_H

#include <glad\glad.h>
#include <GLFW\glfw3.h>

namespace cengine {
	class shader {
	public:
		GLuint id;

		shader(const char* vertexPath, const char* fragmentPath);

		void use();
		void deleteShader();
	};
}

#endif