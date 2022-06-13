#ifndef VAO_H
#define VAO_H

#include <glad\glad.h>
#include "vbo.h"

namespace cengine {
	class vao {
	public:
		GLuint id;

		vao();

		void linkVbo(vbo& vbo, GLuint layout);
		void bind();
		void unbind();
		void deleteVao();
	};
}

#endif