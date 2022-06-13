#ifndef SHADER_H
#define SHADER_H

#include <map>
#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include "mat.h"
#include "vec.h"

namespace cengine {
	class shader {
		struct cmp_pchar {
			bool operator()(const char * const a, const char * const b) const {
				return std::strcmp(a, b) < 0;
			}
		};

		std::map<const char*, uint32_t, cmp_pchar> locations;

	public:
		uint32_t id;

		shader(const char* vertexPath, const char* fragmentPath);

		void use();
		void deleteShader();
		void setMat4x4(const char* name, fmat4x4& mat);
		void setVec3(const char* name, fvec3d& vec);
	};
}

#endif