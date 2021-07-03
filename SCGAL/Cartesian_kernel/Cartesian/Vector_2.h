#ifndef CARTESIAN_VECTOR_2_H
#define CARTESIAN_VECTOR_2_H

#include <Origin.h>

namespace CGAL {

template < class R_ >
class VectorC2
{
	typedef VectorC2<R_>                      Self;
	typedef typename R_::FT                   FT;
	typedef typename R_::Point_2              Point_2;
	typedef typename R_::Vector_2             Vector_2;
	typedef typename R_::Segment_2            Segment_2;
	typedef typename R_::Ray_2                Ray_2;
	typedef typename R_::Line_2               Line_2;
	typedef typename R_::Direction_2          Direction_2;

}

#endif // CARTESIAN_VECTOR_2_H
