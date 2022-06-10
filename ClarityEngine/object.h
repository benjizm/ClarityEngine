#ifndef OBJECT_H
#define OBJECT_H

#include "mesh.h"
#include "shader.h"
#include "vao.h"
#include "vbo.h"
#include "camera.h"

namespace cengine {
	struct object {
		mesh* mesh;
		shader* shader;
		vao* vao;
		vbo* vbo;

		void draw(const camera& camera);
	};
}

#endif