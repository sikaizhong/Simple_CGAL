#ifndef CARTESIAN_BASE_
#define CARTESIAN_BASE_
// Since we want kernels extensiable, we need a base class for them
// and defer the instantiation;
#include <Cartesian/Point_2.h>

namespace SCGAL {
	// K_: kernel;
	// FT_: floating number;
	template <typename K_, typename FT_>
	struct Cartesian_base {
		typedef K_						Kernel;
		typedef FT_                                         FT;
		typedef Cartesian_base<K_, FT_>                      Self;
		// distinguish cartesian from homogeneous
	};
}


#endif 