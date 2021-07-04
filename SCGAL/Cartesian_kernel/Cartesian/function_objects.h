#include<kernel/function_objects.h>
namespace SCGAL {
	namespace CartesianKernelFunctors {
		using namespace CommonKernelFunctors;

		
		template <typename K>
		class Orientation_2
		{
			typedef typename K::Point_2       Point_2;
			typedef typename K::Vector_2      Vector_2;
		public:
			typedef bool   result_type;

			result_type
				operator()(const Point_2& p, const Point_2& q, const Point_2& r) const
			{
				return orientationC2(p.x(), p.y(), q.x(), q.y(), r.x(), r.y());
			}

			result_type
				operator()(const Vector_2& u, const Vector_2& v) const
			{
				return orientationC2(u.x(), u.y(), v.x(), v.y());
			}

			
		};

		template <typename K>
		class Compare_xy_2
		{
			typedef typename K::Point_2            Point_2;
		public:
			typedef bool  result_type;

			result_type
				operator()(const Point_2& p, const Point_2& q) const
			{
				return compare_lexicographically_xyC2(p.x(), p.y(), q.x(), q.y());
			}
		};

		template <typename K>
		class Less_xy_2
		{
			typedef typename K::Point_2        Point_2;
			typedef typename K::Compare_xy_2   Compare_xy_2;
			Compare_xy_2 c;
		public:
			typedef bool       result_type;

			Less_xy_2() {}
			Less_xy_2(const Compare_xy_2& c_) : c(c_) {}

			result_type
				operator()(const Point_2& p, const Point_2& q) const
			{
				return c(p, q) == SMALLER;
			}
		};
	}
}