

#ifndef KERNEL_FUNCTION_OBJECTS_H
#define KERNEL_FUNCTION_OBJECTS_H
#include<predicates/sign_of_determinant.h>
#include<enum.h>
namespace SCGAL {
	

	namespace CommonKernelFunctors {

		template < class FT >
		inline bool
			orientationC2(const FT &ux, const FT &uy, const FT &vx, const FT &vy)
		{
			return sign_of_determinant(ux, uy, vx, vy);
		}

		template < class FT >
			inline
			bool
			compare_lexicographically_xyC2(const FT &px, const FT &py,
				const FT &qx, const FT &qy)
		{
				if (px <= qx) return true;
				else if (px == qx && py < qy) return true;
				return false;
		}


		template <typename K>
		class Orientation_2
		{
			typedef typename K::Point_2       Point_2;
			typedef typename K::Vector_2      Vector_2;
			//typedef typename K::Circle_2      Circle_2;
		public:
			typedef typename K::Orientation    result_type;

			result_type
				operator()(const Point_2& p, const Point_2& q, const Point_2& r) const
			{
				return orientationC2(p.x(), p.y(), q.x(), q.y(), r.x(), r.y());
			}
		};



		////kernel_ftC2
		template < class FT >
		bool
			collinear_are_ordered_along_lineC2(const FT &px, const FT &py,
				const FT &qx, const FT &qy,
				const FT &rx, const FT &ry)
		{
			if (px < qx) return !(rx < qx);
			if (qx < px) return !(qx < rx);
			if (py < qy) return !(ry < qy);
			if (qy < py) return !(qy < ry);
			return true; // p==q
		}

		template <typename K>
		class Collinear_are_ordered_along_line_2
		{
			typedef typename K::Point_2         Point_2;
		public:
			typedef bool         result_type;

			result_type
				operator()(const Point_2& p, const Point_2& q, const Point_2& r) const
			{
				//CGAL_kernel_exactness_precondition(collinear(p, q, r));
				return collinear_are_ordered_along_lineC2
				(p.x(), p.y(), q.x(), q.y(), r.x(), r.y());
			}
		};



		template <typename K>
		class Less_rotate_ccw_2
		{
			typedef typename K::Point_2        Point_2;
			/*typedef typename K::Orientation_2  Orientation_2;
			typedef typename K::Collinear_are_ordered_along_line_2
				Collinear_are_ordered_along_line_2;*/
			typedef typename K::Orientation_2  Orientation_2;
			Orientation_2 o;
			Collinear_are_ordered_along_line_2<K> co;
		public:
			typedef bool        result_type;

			Less_rotate_ccw_2() {}

			result_type
				operator()(const Point_2& r, const Point_2& p, const Point_2& q) const
			{
				Orientation ori = o(r, p, q);
				if (ori == LEFT_TURN)
					return true;
				else if (ori == RIGHT_TURN)
					return false;
				else
				{
					if (p == r) return false;
					if (q == r) return true;
					if (p == q) return false;
					return co(r, q, p);
				}
			}
		};
	};
};
#endif