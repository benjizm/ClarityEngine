#ifndef CAMERA_H
#define CAMERA_H

#include <cstdint>
#include "vec.h"
#include "mat.h"

namespace cengine {
	class camera {
	public:
		fvec3d pos;
		float ratio;
		float near;
		float far;
		float fov;

		fmat4x4 getProjectionMatrix();
	};
}

#endif