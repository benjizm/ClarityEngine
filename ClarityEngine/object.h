#ifndef OBJECT_H
#define OBJECT_H

#include "mesh.h"
#include "shader.h"
#include "vao.h"
#include "vbo.h"
#include "camera.h"

namespace cengine {
	class object {
	public:
		mesh* mesh;
		shader* shader;
		vao* vao;
		vbo* vbo;

		object(cengine::mesh& imesh, cengine::shader& ishader, cengine::vao& ivao);

		void initialize();
		void draw(camera& camera);
		void deleteObject();
	};
}

#endif