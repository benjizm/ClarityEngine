#ifndef VBO_H
#define VBO_H

#include <glad\glad.h>

namespace cengine {
	class vbo {
	public:
		GLuint id;

		vbo(GLfloat* vertices, GLsizeiptr size);

		void bind();
		void unbind();
		void deleteVbo();
	};
}

#endif