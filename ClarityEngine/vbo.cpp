#include <cstdint>
#include "vbo.h"

cengine::vbo::vbo(GLfloat* vertices, GLsizeiptr size) {
	glGenBuffers(1, &id);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

cengine::vbo::vbo(mesh* mesh) {
	glGenBuffers(1, &id);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	const uint32_t count = mesh->tris.size() * 9;
	GLfloat* vertices = new GLfloat[count];
	uint32_t i = 0;
	for (const auto& tri : mesh->tris) {
		for (const auto& vec : tri.p) {
			vertices[i] = vec.x;
			vertices[i + 1] = vec.y;
			vertices[i + 2] = vec.z;
			i += 3;
		}
	}
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * count, vertices, GL_STATIC_DRAW);
	delete[] vertices;
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