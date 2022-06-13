#include <math.h>
#include "camera.h"
#include "mat.h"

cengine::camera::camera() {
	pos = fvec3d(0, 0, 0);
	pitch = 0.0f;
	yaw = -1.57079f;
	fov = 90;
	near = 0.1f;
	far = 1000.0f;
	aspectRatio = 800.0f / 600.0f;
	front = cengine::fvec3d(0, 0, -1);
	up = cengine::fvec3d(0, 1, 0);
	right = cengine::fvec3d(1, 0, 0);
}

cengine::camera::camera(fvec3d position) {
	pos = position;
	pitch = 0.0f;
	yaw = -1.57079f;
	fov = 90;
	near = 0.1f;
	far = 1000.0f;
	aspectRatio = 800.0f / 600.0f;
	front = cengine::fvec3d(0, 0, -1);
	up = cengine::fvec3d(0, 1, 0);
	right = cengine::fvec3d(1, 0, 0);
}

float cengine::camera::degToRad(float deg) {
	return deg / 57.2958f;
}

float cengine::camera::radToDeg(float rad) {
	return rad * 57.2958f;
}

cengine::fmat4x4 cengine::camera::getViewMatrix() {
	cengine::fvec3d target = cengine::fvec3d::add(pos, front);
	return cengine::fmat4x4::lookAt(pos, target, up);
}

cengine::fmat4x4 cengine::camera::getProjectionMatrix() {
	float yMax = near * std::tanf(0.5f * getFov());
	float yMin = -yMax;
	float xMin = yMin * aspectRatio;
	float xMax = yMax * aspectRatio;

	cengine::fmat4x4 retval;
	retval.m[0][0] = (2.0f * near) / (xMax - xMin);
	retval.m[1][1] = (2.0f * near) / (yMax - yMin);
	retval.m[0][2] = (xMax + xMin) / (xMax - xMin);
	retval.m[1][2] = (yMax + yMin) / (yMax - yMin);
	retval.m[2][2] = (far + near) / (far - near);
	retval.m[3][2] = -1.0f;
	retval.m[2][3] = (2.0f * far * near) / (far - near);
	return retval;
}

void cengine::camera::updateVectors() {
	front.x = std::cosf(pitch) * std::cosf(yaw);
	front.y = std::sinf(pitch);
	front.z = std::cosf(pitch) * std::sinf(yaw);

	front = cengine::fvec3d::normalize(front);
	right = cengine::fvec3d::normalize(cengine::fvec3d::cross(front, fvec3d(0, 1, 0)));
	up = cengine::fvec3d::normalize(cengine::fvec3d::cross(right, front));
}

float cengine::camera::getFov() {
	return radToDeg(fov);
}

float cengine::camera::getPitch() {
	return radToDeg(pitch);
}

float cengine::camera::getYaw() {
	return radToDeg(yaw);
}

void cengine::camera::setFov(float val) {
	fov = degToRad(val);
}

void cengine::camera::setPitch(float val) {
	if (val < -89.0f)
		val = -89.0f;
	if (val > 89.0f)
		val = 89.0f;
	pitch = degToRad(val);
	updateVectors();
}

void cengine::camera::setYaw(float val) {
	yaw = degToRad(val);
	updateVectors();
}