
#ifndef PREDICATES_SIGN_OF_DETERMINANT_H
#define PREDICATES_SIGN_OF_DETERMINANT_H

#include <determinant.h>
#include<enum.h>
//#include <CGAL/number_utils_classes.h>
//#include <CGAL/number_type_basic.h>

namespace SCGAL {// This one may be related how to choose predicate;

/*template <class RT>
inline
typename Sgn<RT>::result_type
sign_of_determinant( const RT& a00,  const RT& a01,
                        const RT& a10,  const RT& a11)
{
  return enum_cast<Sign>(CGAL_NTS compare( a00*a11, a10*a01));
}*/

	template <class RT>
	inline
		Sign
		sign_of_determinant(const RT& a00, const RT& a01,
			const RT& a10, const RT& a11)
	{
		return enum_cast<Sign>(compare(a00*a11, a10*a01));

		//return (a00*a11-a10*a01)>=0;
	}


} //namespace CGAL

#endif // CGAL_PREDICATES_SIGN_OF_DETERMINANT_H
