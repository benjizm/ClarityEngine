#ifndef CAMERA_H
#define CAMERA_H

#include <cstdint>
#include "vec.h"
#include "mat.h"

namespace cengine {
	class camera {
		float pitch, yaw, fov;

		float degToRad(float deg);
		float radToDeg(float rad);
		void updateVectors();

	public:
		float near, far, aspectRatio;
		fvec3d pos, front, up, right;

		camera(fvec3d pos);

		fmat4x4 getViewMatrix();
		fmat4x4 getProjectionMatrix();
		float getPitch();
		float getYaw();
		float getFov();
		void setPitch(float val);
		void setYaw(float val);
		void setFov(float val);
	};
}

#endif