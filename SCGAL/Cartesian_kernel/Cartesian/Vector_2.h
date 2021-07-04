#ifndef CARTESIAN_VECTOR_2_H
#define CARTESIAN_VECTOR_2_H

#include <Origin.h>
#include <array>

namespace SCGAL {

	template < class R_ >
	class VectorC2
	{
		typedef VectorC2<R_>                      Self;
		typedef typename R_::FT                   FT;
		typedef typename R_::Point_2              Point_2;
		typedef typename R_::Vector_2             Vector_2;

		typedef std::array<FT, 2>               Rep;

		Rep base;

	public:
		typedef R_                                R;
		VectorC2() {}
		VectorC2(const FT &x, const FT &y)  {
			base[0] = x;
			base[1] = y;
		};

		const FT & x() const
		{
			return base[0];
		}

		const FT & y() const
		{
			return base[1];
		}


	};
};
#endif // CARTESIAN_VECTOR_2_H
