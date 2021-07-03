#include <Exact_predicates_inexact_constructions_kernel.h>
#include<ch_graham_andrew.h>
#include<vector>
#include<algorithm>

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

#include<iostream>
int main() {
	return 0;
}