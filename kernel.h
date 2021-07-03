#ifndef KERNEL_
#define KERNEL_
namespace CGAL {
	// predicate
	template<class FT>
	FT det2x2(FT a00, FT a01, FT a10, FT a11) {
		return a00 * a11 - a10 * a01;
	}
	template < class FT >
	void line_from_pointsC2(FT px, FT py, FT qx, FT qy,
		FT& a, FT& b, FT& c)
	{
		a = py - qy;
		b = qx - px;
		c = -px * a - py * b;
	}
	// geometry kernel
	template <class K>
	struct Point_2 {
		typedef typename K::FT FT;
		Point_2() {}
		Point_2(FT x_, FT y_) :x(x_), y(y_) {}
		FT x, y;
	};

	template <class K>
	struct Line_2 {
		typedef typename K::Point_2 Point_2;
		Line_2() {}
		Line_2(Point_2 p, Point_2 q) {
			*this = K::Construct_line_2(p, q);
		}
		typedef typename K::FT FT;
		FT a, b, c;
	};

	template <class K>
	struct Segment_2 {
		typedef typename K::Point_2 Point_2;
		Point_2 s, e;
	};

	template <class K>
	struct Less_xy_2 {
		typedef typename K::Point_2 Point_2;
		bool  operator()(Point_2 p, Point_2 q)const
		{
			return p.x < q.x || p.x == q.x&&p.y < q.y;
		}
	};

	template < class K_ >
	struct Left_turn_2 {
		typedef typename K_::Point_2 Point_2;
		bool operator()(Point_2 p, Point_2 q, Point_2 r) const
		{
			return determinant2x2(q.x - p.x, q.y - p.y,
				r.x - p.x, r.y - p.y) > 0;
		}
	};

	template < class K_ >
	struct Construct_line_2 {
		typedef typename K_::Point_2 Point_2;
		typedef typename K_::Line_2 Line_2;
		Line_2 operator()(Point_2 p, Point_2 q) const
		{
			Line_2 l;
			line_from_pointsC2(p.x, p.y, q.x, q.y, l.a, l.b, l.c);
			return l;
		}
	};

	// geometrical kernel
	template <class K_, class FT_>
	struct Kernel_base {
		// data
		typedef K_         K;
		typedef FT_        FT;
		typedef Point_2<K> Point_2;
		typedef Line_2<K> Line_2;
		typedef Segment_2< K > Segment_2;

		// operation
		typedef Less_xy_2< K > Less_xy_2;
		typedef Left_turn_2< K > Left_turn_2;
		typedef Construct_line_2< K > Construct_line_2;
		Less_xy_2 less_xy_2_object() const
		{
			return Less_xy_2();
		}
		Left_turn_2 left_turn_2_object() const
		{
			return Left_turn_2()
		};

		Construct_line_2 construct_line_2_object() const
		{
			return Construct_line_2();
		}
	};
	template <class FT_>
	struct Kernel : public Kernel_base<Kernel<FT_>, FT_> {};

	// client code;
	template <class K> inline
		bool less_xy_2(typename K::Point_2 p, typename K::Point_2 q,
			K k = K()) {
		return k.less_xy_2_object()(p, q);
	}
}
#endif