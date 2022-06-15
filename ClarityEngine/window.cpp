#include <thread>
#include <string>
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

	GLFWframebuffersizefun fun = &framebufferSizeCallback;
	glfwSetFramebufferSizeCallback(win, framebufferSizeCallback);

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

	double dlast = glfwGetTime();
	double lastTime = glfwGetTime();
	double secs = lastTime;
	int fps = 0;
	std::string fpsTitle;

	while (!glfwWindowShouldClose(win)) {
		double currentTime = glfwGetTime();
		double diff = currentTime - dlast;
		dlast = currentTime;
		glRenderFrame(diff);

		while (glfwGetTime() < lastTime + 1.0 / maxfps) {
			std::this_thread::sleep_for(std::chrono::microseconds(100));
		}
		lastTime += 1.0 / maxfps;

		fps++;

		if (currentTime - secs >= 1.0) {
			fpsTitle = "ClarityEngine [";
			fpsTitle += std::to_string(fps);
			fpsTitle += " FPS]";
			glfwSetWindowTitle(win, fpsTitle.c_str());
			fps = 0;
			secs += 1.0;
		}

		//int count = 1000.0f / 60.0f - ms.count();
		//std::this_thread::sleep_for(std::chrono::milliseconds(count));
	}

	close();
}

void cengine::window::framebufferSizeCallback(GLFWwindow* window, int32_t width, int32_t height) {
	glViewport(0, 0, width, height);
};
