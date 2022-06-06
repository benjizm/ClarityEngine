#ifndef MESH_H
#define MESH_H

#include <vector>
#include "vec.h"

namespace cengine {
	struct triangle {
		fvec3d p[3];
	};

	struct mesh {
		std::vector<triangle> tris;
	};
}

#endif