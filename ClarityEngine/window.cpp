#include <thread>
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

	double lastTime = glfwGetTime();
	double secs = lastTime;
	int fps = 0;

	while (!glfwWindowShouldClose(win)) {
		double currentTime = glfwGetTime();
		double diff = currentTime - lastTime;

		glRenderFrame(diff);
		double sleep = 1000.0f / 60.0f - diff;
		std::this_thread::sleep_for(std::chrono::milliseconds((int)(sleep * 1000.0f)));
		fps++;

		if (currentTime - secs >= 1.0) {
			fps = 0;
			secs += 1.0;
		}

		//int count = 1000.0f / 60.0f - ms.count();
		//std::this_thread::sleep_for(std::chrono::milliseconds(count));
	}

	close();
}

void cengine::window::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
};
