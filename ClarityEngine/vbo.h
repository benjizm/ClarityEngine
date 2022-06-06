#ifndef VBO_H
#define VBO_H

#include <glad\glad.h>
#include "mesh.h"

namespace cengine {
	class vbo {
	public:
		GLuint id;

		vbo(GLfloat* vertices, GLsizeiptr size);
		vbo(mesh* mesh);

		void bind();
		void unbind();
		void deleteVbo();
	};
}

#endif