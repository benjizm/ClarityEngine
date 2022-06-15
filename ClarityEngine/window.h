#ifndef WINDOW_H
#define WINDOW_H

#include <chrono>
#include <GLFW\glfw3.h>

namespace cengine {
	class window {
		GLFWwindow* win;

		void glInitialize();
		void glRenderFrame(float dtime);
		void close();

		static void framebufferSizeCallback(GLFWwindow* window, int32_t width, int32_t height);

	public:
		int32_t maxfps = 60;
		float width, height;
		const char* name;

		window(float w, float h, const char* wname);

		void run();

		virtual void initialize() = 0;
		virtual void onRenderFrame(float dtime) = 0;
		virtual void onClose() = 0;
	};
}

#endif