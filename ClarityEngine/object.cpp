#include "object.h"

cengine::object::object(cengine::mesh& imesh, cengine::shader& ishader, cengine::vao& ivao) {
	mesh = &imesh;
	shader = &ishader;
	vao = &ivao;
	vbo = new cengine::vbo(mesh);
}

void cengine::object::initialize() {
	vao->bind();
	vao->linkVbo(*vbo, 0);
	vbo->unbind();
	vao->unbind();
}

void cengine::object::draw(cengine::camera& cam) {
	shader->use();
	vao->bind();

	cengine::fvec3d position;
	cengine::fmat4x4 ident = cengine::fmat4x4::identity();
	cengine::fmat4x4 trans = cengine::fmat4x4::createTranslation(position);
	cengine::fmat4x4 i = cengine::fmat4x4::dot(ident, trans);
	cengine::fmat4x4 view = cam.getViewMatrix();
	cengine::fmat4x4 proj = cam.getProjectionMatrix();
	shader->setMat4x4("model", i);
	shader->setMat4x4("view", view);
	shader->setMat4x4("projection", proj);

	glDrawArrays(GL_TRIANGLES, 0, mesh->tris.size() * 3);
}

void cengine::object::deleteObject() {
	vao->deleteVao();
	vbo->deleteVbo();
	shader->deleteShader();
}