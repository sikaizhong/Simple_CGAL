#ifndef SIMPLE_CARTESIAN_
#define SIMPLE_CARTESIAN_
#include<Cartesian/Cartesian_base.h>
#include <Kernel/Type_equality_wrapper.h>

namespace SCGAL {

	template < typename FT_, typename Kernel_ >
	struct Cartesian_base_no_ref_count// haven't implemented;
		:public Cartesian_base< Kernel_, FT_ > {

		typedef FT_                                           RT;
		typedef FT_                                           FT;
		// The mechanism that allows to specify reference-counting or not.
		template < typename T >
		struct Handle { typedef T   type; };

		template < typename Kernel2 >
		struct Base { typedef Cartesian_base_no_ref_count<FT_, Kernel2>  Type; };

		typedef Kernel_ K;
//#define CGAL_Kernel_pred(Y,Z) typedef CartesianKernelFunctors::Y<K> Y; \
                              Y Z() const { return Y(); }
//#define CGAL_Kernel_cons(Y,Z) CGAL_Kernel_pred(Y,Z)

//#include <Kernel/interface_macros.h>

	};



	template <typename FT_>
	struct Simple_cartesian
		:public Type_equality_wrapper<
		Cartesian_base_no_ref_count<FT_, Simple_cartesian<FT_> >,
		Simple_cartesian<FT_>>
	{};

}

#endif