#include <Exact_predicates_inexact_constructions_kernel.h>
#include<ch_graham_andrew.h>
#include<vector>
#include<algorithm>
#include<Origin.h>
using namespace SCGAL;
template <class InputIterator, class OutputIterator, class Traits>
OutputIterator
ch_graham_anderson(InputIterator  first, InputIterator  beyond,
	OutputIterator result, const Traits&  ch_traits)
{
	typedef typename Traits::Point_2						Point_2;
	typedef typename Traits::Less_xy_2						Less_xy_2;
	typedef typename Traits::Less_rotate_ccw_2				Less_rotate_ccw_2;

	if (first == beyond) return result;
	std::vector<Point_2> V(first, beyond);
	typename std::vector<Point_2>::iterator it =
		std::min_element(V.begin(), V.end(), Less_xy_2());

	const Point_2 p = *it; // smallest one;
	std::sort(V.begin(), V.end(), [&p](const Point_2& p1, const Point_2& p2) {return Less_rotate_ccw_2()(p, p1, p2); });


}

typedef Exact_predicates_inexact_constructions_kernel    Kernel;
typedef Kernel::Point_2                                  Point_2;
#include<iostream>
int main() {

	std::vector<Point_2> data{ Point_2(5887, 415)
		, Point_2(3001, 7410), Point_2(1424, 5645),
		Point_2(152, 4513), Point_2(3309, 92)
		, Point_2(2056, 5013), Point_2(2867, 5103),
		Point_2(2130, 2112) };
	/*int size = data.size();
	for (auto p : data) {
		std::cout << p.x() << " " << p.y() << std::endl;
	}*/
	auto in_start = data.begin();
	auto in_end = data.end();
	std::ostream_iterator< Point_2 >  out(std::cout, "\n");

	ch_graham_anderson(in_start, in_end, out, Kernel());


}