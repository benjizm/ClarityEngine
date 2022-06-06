#include "vbo.h"

cengine::vbo::vbo(GLfloat* vertices, GLsizeiptr size) {
	glGenBuffers(1, &id);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void cengine::vbo::bind() {
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

void cengine::vbo::unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void cengine::vbo::deleteVbo() {
	glDeleteBuffers(1, &id);
}