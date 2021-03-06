#ifndef CARTESIAN_BASE_
#define CARTESIAN_BASE_
// Since we want kernels extensiable, we need a base class for them
// and defer the instantiation;
#include <Cartesian/Point_2.h>
#include <Cartesian/Vector_2.h>
#include<Cartesian/function_objects.h>
namespace SCGAL {
	// K_: kernel;
	// FT_: floating number;
	template <typename K_, typename FT_>
	struct Cartesian_base {
		typedef K_						Kernel;
		typedef FT_                                         FT;
		typedef Cartesian_base<K_, FT_>                      Self;
		// distinguish cartesian from homogeneous

		typedef PointC2<Kernel>                             Point_2;
		typedef VectorC2<Kernel>                            Vector_2;
		//typedef CircleC2<Kernel>                            Circle_2;


		

	};
}


#endif 