
#ifndef KERNEL_TYPE_EQUALITY_WRAPPER_H
#define KERNEL_TYPE_EQUALITY_WRAPPER_H

#include <user_classes.h>

namespace CGAL {

// This is a kernel wrapper which provides the type equality between
// Kernel::Point_2 and CGAL::Point_2<Kernel>, by deriving from
// K_base::Point_2 (and similar for the other types).

template < typename K_base, typename Kernel_ >
struct Type_equality_wrapper
  : public K_base
{
    typedef K_base                                  Kernel_base;

#define CGAL_Kernel_obj(X)   typedef CGAL::X<Kernel_> X;

#include <Kernel/interface_macros.h>

    // Undocumented stuff.
    //typedef CGAL::Conic_2<Kernel_>                   Conic_2;
    //typedef CGAL::Aff_transformation_2<Kernel_>      Aff_transformation_2;
    //typedef CGAL::Aff_transformation_3<Kernel_>      Aff_transformation_3;
};

} //namespace CGAL

#endif // CGAL_KERNEL_TYPE_EQUALITY_WRAPPER_H
