#include <cstdint>
#include <vector>
#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include "shader.h"
#include "vao.h"
#include "ebo.h"
#include "mesh.h"

int32_t main() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLfloat verts[] = {
		0.5f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f
	};

	GLuint indices[] = {
		1, 2, 3,
		2, 0, 3
	};

	cengine::triangle t1 = cengine::triangle();
	t1.p[0] = new cengine::fvec3d(-0.5f, -0.5f, 0.0f);
	t1.p[1] = new cengine::fvec3d(0.5f, -0.5f, 0.0f);
	t1.p[2] = new cengine::fvec3d(-0.5f, 0.5f, 0.0f);

	cengine::triangle t2 = cengine::triangle();
	t2.p[0] = new cengine::fvec3d(0.5f, -0.5f, 0.0f);
	t2.p[1] = new cengine::fvec3d(0.5f, 0.5f, 0.0f);
	t2.p[2] = new cengine::fvec3d(-0.5f, 0.5f, 0.0f);

	cengine::mesh square;
	square.tris = std::vector<cengine::triangle>{ t1, t2 };

	GLFWwindow* window = glfwCreateWindow(800, 600, "ClarityEngine", NULL, NULL);
	glfwMakeContextCurrent(window);

	gladLoadGL();
	glViewport(0, 0, 800, 600);

	cengine::shader shader("default.vert", "default.frag");

	cengine::vao vao;
	vao.bind();

	//cengine::vbo vbo(verts, sizeof(verts));
	cengine::vbo vbo(&square);
	cengine::ebo ebo(indices, sizeof(indices));

	vao.linkVbo(vbo, 0);

	vbo.unbind();
	vao.unbind();
	ebo.unbind();

	glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	while (!glfwWindowShouldClose(window)) {
		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader.use();
		vao.bind();
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	vao.deleteVao();
	vbo.deleteVbo();
	ebo.deleteEbo();
	shader.deleteShader();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}