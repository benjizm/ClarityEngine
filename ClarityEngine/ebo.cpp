#include "ebo.h"

cengine::ebo::ebo(GLuint* indices, GLsizeiptr size) {
	glGenBuffers(1, &id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

void cengine::ebo::bind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void cengine::ebo::unbind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void cengine::ebo::deleteEbo() {
	glDeleteBuffers(1, &id);
}