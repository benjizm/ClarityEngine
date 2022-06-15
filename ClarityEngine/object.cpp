#include "object.h"

cengine::object::object(cengine::mesh& imesh, cengine::shader& ishader, cengine::vao& ivao) {
	mesh = new cengine::mesh(imesh);
	shader = new cengine::shader(ishader);
	vao = new cengine::vao(ivao);
	vbo = new cengine::vbo(mesh);

	rotation = cengine::fmat4x4::identity();
	position = cengine::fvec3d(0, 0, 0);
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

	cengine::fmat4x4 model = cengine::fmat4x4::identity();
	cengine::fmat4x4 trans = cengine::fmat4x4::createTranslation(position);
	model = cengine::fmat4x4::dot(model, trans);
	model = cengine::fmat4x4::dot(model, rotation);
	cengine::fmat4x4 view = cam.getViewMatrix();
	cengine::fmat4x4 proj = cam.getProjectionMatrix();
	shader->setMat4x4("model", model);
	shader->setMat4x4("view", view);
	shader->setMat4x4("projection", proj);

	glDrawArrays(GL_TRIANGLES, 0, mesh->tris.size() * 3);
}

void cengine::object::deleteObject() {
	vao->deleteVao();
	vbo->deleteVbo();
	shader->deleteShader();
}