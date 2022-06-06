#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include "shader.h"
#include "vao.h"
#include "ebo.h"

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

	GLFWwindow* window = glfwCreateWindow(800, 600, "ClarityEngine", NULL, NULL);
	glfwMakeContextCurrent(window);

	gladLoadGL();
	glViewport(0, 0, 800, 600);

	cengine::shader shader("default.vert", "default.frag");

	cengine::vao vao;
	vao.bind();

	cengine::vbo vbo(verts, sizeof(verts));
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
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

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