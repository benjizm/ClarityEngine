#ifndef VEC_H
#define VEC_H

#include <cmath>
#include <cstdint>

namespace cengine {
	template<class T>
	struct vec3d_gen {
		T x = 0, y = 0, z = 0;

		vec3d_gen() { }
		vec3d_gen(T x, T y, T z) : x(x), y(y), z(z) { }

		static vec3d_gen<T> add(const vec3d_gen<T>& vec1, const vec3d_gen<T>& vec2) {
			return vec3d_gen<T>(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z);
		}

		static vec3d_gen<T> sub(const vec3d_gen<T>& vec1, const vec3d_gen<T>& vec2) {
			return vec3d_gen<T>(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
		}

		static vec3d_gen<T> mul(const vec3d_gen<T>& vec, const T& scalar) {
			vec3d_gen<T> retval(vec);
			retval.x *= scalar;
			retval.y *= scalar;
			retval.z *= scalar;
			return retval;
		}

		static T magnitude(const vec3d_gen<T>& vec) {
			return T(std::sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
		}

		static vec3d_gen<T> normalize(const vec3d_gen<T>& vec) {
			T recip = 1 / magnitude(vec);
			return vec3d_gen<T>(recip * vec.x, recip * vec.y, recip * vec.z);
		}

		static vec3d_gen<T> cross(const vec3d_gen<T>& vec1, const vec3d_gen<T>& vec2) {
			vec3d_gen<T> retval;
			retval.x = vec1.y * vec2.z - vec1.z * vec2.y;
			retval.y = vec1.z * vec2.x - vec1.x * vec2.z;
			retval.z = vec1.x * vec2.y - vec1.y * vec2.x;
			return retval;
		}
	};

	typedef vec3d_gen<int32_t> ivec3d;
	typedef vec3d_gen<uint32_t> uvec3d;
	typedef vec3d_gen<float> fvec3d;
	typedef vec3d_gen<double> dvec3d;
}

#endif