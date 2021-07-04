#ifndef CARTESIAN_POINT_2_H
#define CARTESIAN_POINT_2_H
// Since we want kernels extensiable, we need a base class for them
// and defer the instantiation;
#include<Origin.h>
namespace SCGAL {
	template <class R_>// R_:: representation?
	class PointC2 {
		typedef PointC2<R_>                       Self;
		typedef typename R_::FT                   FT;

		typedef typename R_::Vector_2             Vector_2_;
		typedef typename R_::Point_2              Point_2;

		Vector_2_ base; // data;

	public:


		PointC2() {};

		PointC2(const Origin &)
			: base(NULL_VECTOR) {}

		PointC2(const FT &x, const FT &y)
			: base(x, y) {}


		friend void swap(Self& a, Self& b) {
			swap(a.base, b.base);
		}

		const FT& x() const
		{
			return base.x();
		}

		const FT& y() const
		{
			return base.y();
		}



	};
}


#endif 