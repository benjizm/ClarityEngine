#ifndef MAT_H
#define MAT_H

#include <cstdint>

namespace cengine {
	template<class T>
	struct mat4x4_gen {
		T m[4][4] = { 0 };
	};

	typedef mat4x4_gen<int32_t> imat4x4;
	typedef mat4x4_gen<uint32_t> umat4x4;
	typedef mat4x4_gen<float> fmat4x4;
	typedef mat4x4_gen<double> dmat4x4;
}

#endif