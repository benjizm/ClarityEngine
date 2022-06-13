#include <glad\glad.h>
#include "window.h"

cengine::window::window(float w, float h, const char* wname) {
	width = w;
	height = h;
	name = wname;
	win = nullptr;
}

void cengine::window::glInitialize() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	win = glfwCreateWindow(width, height, name, NULL, NULL);
	glfwMakeContextCurrent(win);

	gladLoadGL();
	glViewport(0, 0, width, height);

	GLFWframebuffersizefun fun = &framebuffer_size_callback;
	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);

	last = clock.now();

	initialize();
}

void cengine::window::glRenderFrame(float dtime) {
	onRenderFrame(dtime);

	glfwSwapBuffers(win);
	glfwPollEvents();
}

void cengine::window::close() {
	onClose();
	glfwDestroyWindow(win);
	glfwTerminate();
}

void cengine::window::run() {
	glInitialize();

	while (!glfwWindowShouldClose(win)) {
		std::chrono::system_clock::time_point current = clock.now();
		std::chrono::duration<float> elapsedTime = current - last;
		last = current;

		glRenderFrame(elapsedTime.count());
	}

	close();
}

void cengine::window::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
};
