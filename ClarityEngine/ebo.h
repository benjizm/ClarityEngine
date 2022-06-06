#ifndef EBO_H
#define EBO_H

#include <glad\glad.h>

namespace cengine {
	class ebo {
	public:
		GLuint id;

		ebo(GLuint* indices, GLsizeiptr size);

		void bind();
		void unbind();
		void deleteEbo();
	};
}

#endif