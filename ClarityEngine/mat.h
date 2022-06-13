#ifndef MAT_H
#define MAT_H

#include <cstdint>
#include "vec.h"

namespace cengine {
	template<class T>
	struct mat4x4_gen {
		// column, row
		T m[4][4] = { 0 };

		static mat4x4_gen<T> identity() {
			mat4x4_gen<T> retval;
			retval.m[0][0] = 1;
			retval.m[1][1] = 1;
			retval.m[2][2] = 1;
			retval.m[3][3] = 1;
			return retval;
		}

		static mat4x4_gen<T> dot(mat4x4_gen<T>& mat1, mat4x4_gen<T>& mat2) {
			mat4x4_gen<T> retval;
			retval.m[0][0] = mat1.m[0][0] * mat2.m[0][0] + mat1.m[1][0] * mat2.m[0][1] + mat1.m[2][0] * mat2.m[0][2] + mat1.m[3][0] * mat2.m[0][3];
			retval.m[1][0] = mat1.m[0][0] * mat2.m[1][0] + mat1.m[1][0] * mat2.m[1][1] + mat1.m[2][0] * mat2.m[1][2] + mat1.m[3][0] * mat2.m[1][3];
			retval.m[2][0] = mat1.m[0][0] * mat2.m[2][0] + mat1.m[1][0] * mat2.m[2][1] + mat1.m[2][0] * mat2.m[2][2] + mat1.m[3][0] * mat2.m[2][3];
			retval.m[3][0] = mat1.m[0][0] * mat2.m[3][0] + mat1.m[1][0] * mat2.m[3][1] + mat1.m[2][0] * mat2.m[3][2] + mat1.m[3][0] * mat2.m[3][3];

			retval.m[0][1] = mat1.m[0][1] * mat2.m[0][0] + mat1.m[1][1] * mat2.m[0][1] + mat1.m[2][1] * mat2.m[0][2] + mat1.m[3][1] * mat2.m[0][3];
			retval.m[1][1] = mat1.m[0][1] * mat2.m[1][0] + mat1.m[1][1] * mat2.m[1][1] + mat1.m[2][1] * mat2.m[1][2] + mat1.m[3][1] * mat2.m[1][3];
			retval.m[2][1] = mat1.m[0][1] * mat2.m[2][0] + mat1.m[1][1] * mat2.m[2][1] + mat1.m[2][1] * mat2.m[2][2] + mat1.m[3][1] * mat2.m[2][3];
			retval.m[3][1] = mat1.m[0][1] * mat2.m[3][0] + mat1.m[1][1] * mat2.m[3][1] + mat1.m[2][1] * mat2.m[3][2] + mat1.m[3][1] * mat2.m[3][3];

			retval.m[0][2] = mat1.m[0][2] * mat2.m[0][0] + mat1.m[1][2] * mat2.m[0][1] + mat1.m[2][2] * mat2.m[0][2] + mat1.m[3][2] * mat2.m[0][3];
			retval.m[1][2] = mat1.m[0][2] * mat2.m[1][0] + mat1.m[1][2] * mat2.m[1][1] + mat1.m[2][2] * mat2.m[1][2] + mat1.m[3][2] * mat2.m[1][3];
			retval.m[2][2] = mat1.m[0][2] * mat2.m[2][0] + mat1.m[1][2] * mat2.m[2][1] + mat1.m[2][2] * mat2.m[2][2] + mat1.m[3][2] * mat2.m[2][3];
			retval.m[3][2] = mat1.m[0][2] * mat2.m[3][0] + mat1.m[1][2] * mat2.m[3][1] + mat1.m[2][2] * mat2.m[3][2] + mat1.m[3][2] * mat2.m[3][3];

			retval.m[0][3] = mat1.m[0][3] * mat2.m[0][0] + mat1.m[1][3] * mat2.m[0][1] + mat1.m[2][3] * mat2.m[0][2] + mat1.m[3][3] * mat2.m[0][3];
			retval.m[1][3] = mat1.m[0][3] * mat2.m[1][0] + mat1.m[1][3] * mat2.m[1][1] + mat1.m[2][3] * mat2.m[1][2] + mat1.m[3][3] * mat2.m[1][3];
			retval.m[2][3] = mat1.m[0][3] * mat2.m[2][0] + mat1.m[1][3] * mat2.m[2][1] + mat1.m[2][3] * mat2.m[2][2] + mat1.m[3][3] * mat2.m[2][3];
			retval.m[3][3] = mat1.m[0][3] * mat2.m[3][0] + mat1.m[1][3] * mat2.m[3][1] + mat1.m[2][3] * mat2.m[3][2] + mat1.m[3][3] * mat2.m[3][3];

			return retval;
		}

		static mat4x4_gen<T> createTranslation(vec3d_gen<T>& vec) {
			mat4x4_gen<T> retval = identity();
			retval.m[0][3] = vec.x;
			retval.m[1][3] = vec.y;
			retval.m[2][3] = vec.z;
			retval.m[3][3] = 1;
			return retval;
		}

		static mat4x4_gen<T> lookAt(vec3d_gen<T>& eye, vec3d_gen<T>& target, vec3d_gen<T>& up) {
			vec3d_gen<T> z = vec3d_gen<T>::normalize(vec3d_gen<T>::sub(eye, target));
			vec3d_gen<T> x = vec3d_gen<T>::normalize(vec3d_gen<T>::cross(up, z));
			vec3d_gen<T> y = vec3d_gen<T>::normalize(vec3d_gen<T>::cross(z, x));

			mat4x4_gen<T> rot;
			rot.m[0][0] = x.x;
			rot.m[1][0] = y.x;
			rot.m[2][0] = z.x;
			rot.m[3][0] = 0;

			rot.m[0][1] = x.y;
			rot.m[1][1] = y.y;
			rot.m[2][1] = z.y;
			rot.m[3][1] = 0;

			rot.m[0][2] = x.z;
			rot.m[1][2] = y.z;
			rot.m[2][2] = z.z;
			rot.m[3][2] = 0;

			rot.m[0][3] = 0;
			rot.m[1][3] = 0;
			rot.m[2][3] = 0;
			rot.m[3][3] = 1;

			vec3d_gen<T> mul = vec3d_gen<T>::mul(eye, -1);
			mat4x4_gen<T> trans = createTranslation(mul);
			return dot(trans, rot);
		}

		static vec3d_gen<T> multiplyVector(vec3d_gen<T>& vec, mat4x4_gen<T>& mat) {
			vec3d_gen<T> retval;
			retval.x = vec.x * mat.m[0][0] + vec.y * mat.m[1][0] + vec.z * mat.m[2][0] + mat.m[3][0];
			retval.y = vec.x * mat.m[0][1] + vec.y * mat.m[1][1] + vec.z * mat.m[2][1] + mat.m[3][1];
			retval.z = vec.x * mat.m[0][2] + vec.y * mat.m[1][2] + vec.z * mat.m[2][2] + mat.m[3][2];
			float w = vec.x * mat.m[0][3] + vec.y * mat.m[1][3] + vec.z * mat.m[2][3] + mat.m[3][3];

			if (w != 0.0f) {
				retval.x /= w;
				retval.y /= w;
				retval.z /= w;
			}

			return retval;
		}
	};

	typedef mat4x4_gen<int32_t> imat4x4;
	typedef mat4x4_gen<uint32_t> umat4x4;
	typedef mat4x4_gen<float> fmat4x4;
	typedef mat4x4_gen<double> dmat4x4;
}

#endif