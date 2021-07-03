#include<predicate.h>
#include<kernel.h>
typedef float  Cartesian;
typedef CGAL::Kernel<Cartesian> MyKernel;
typedef MyKernel::Point_2 Point_2;

//using namespace CGAL;
int main(int argc, char *argv[])
{
	Point_2 p(1.0, 2.0);
	Point_2 q(3.5, 8.9);
	CGAL::less_xy_2<MyKernel>(p, q);
	return 0;
}
