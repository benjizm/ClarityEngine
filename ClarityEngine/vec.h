#ifndef VEC_H
#define VEC_H

#include <cmath>
#include <cstdint>

namespace cengine {
	template <class T>
	struct vec3d_gen {
		T x, y, z;

		vec3d_gen(T x, T y, T z) : x(x), y(y), z(z) { }

		T magnitude() {
			return T(std::sqrt(x * x + y * y + z * z));
		}

		vec3d_gen normalize() {
			T recip = 1 / magnitude();
			return vec3d_gen(recip * x, recip * y, recip * z);
		}
	};

	typedef vec3d_gen<int32_t> ivec3d;
	typedef vec3d_gen<uint32_t> uvec3d;
	typedef vec3d_gen<float> fvec3d;
	typedef vec3d_gen<double> dvec3d;
}

#endif