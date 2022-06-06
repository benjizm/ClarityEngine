#include "vao.h"

cengine::vao::vao() {
	glGenVertexArrays(1, &id);
}

void cengine::vao::linkVbo(vbo vbo, GLuint layout) {
	vbo.bind();
	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(layout);
	vbo.unbind();
}

void cengine::vao::bind() {
	glBindVertexArray(id);
}

void cengine::vao::unbind() {
	glBindVertexArray(0);
}

void cengine::vao::deleteVao() {
	glDeleteVertexArrays(1, &id);
}