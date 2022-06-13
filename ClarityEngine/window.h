#ifndef WINDOW_H
#define WINDOW_H

#include <chrono>
#include <GLFW\glfw3.h>

namespace cengine {
	class window {
		GLFWwindow* win;
		std::chrono::system_clock clock;
		std::chrono::system_clock::time_point last;

		void glInitialize();
		void glRenderFrame(float dtime);
		void close();

		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	public:
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