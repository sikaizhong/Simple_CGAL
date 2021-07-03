
#ifndef EXACT_PREDICATES_INEXACT_CONSTRUCTIONS_KERNEL_H
#define EXACT_PREDICATES_INEXACT_CONSTRUCTIONS_KERNEL_H

#include <Simple_cartesian.h>
#include <Filtered_kernel.h>
//#include <CGAL/Triangulation_structural_filtering_traits.h>

namespace SCGAL {

// The following is equivalent to Filtered_kernel< Simple_cartesian<double> >,
// but it's shorter in terms of template name length (for error messages, mangling...).

class Epick
  : public Filtered_kernel_adaptor<
               Type_equality_wrapper< Simple_cartesian<double>::Base<Epick>::Type, Epick >,
               true>
{};

typedef Epick Exact_predicates_inexact_constructions_kernel;

/*template <>
struct Triangulation_structural_filtering_traits<Epick> {
  typedef Tag_true Use_structural_filtering_tag;
};*/

} //namespace CGAL

#endif // CGAL_EXACT_PREDICATES_INEXACT_CONSTRUCTIONS_KERNEL_H
