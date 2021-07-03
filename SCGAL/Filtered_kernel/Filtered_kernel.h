
#ifndef FILTERED_KERNEL_H
#define FILTERED_KERNEL_H



namespace SCGAL {

	// CK = eventually rebound construction kernel (gets Point_2 from).
// Exact_kernel = exact kernel called when needed by the filter.
// Approximate_kernel = filtering "interval" kernel
	template < typename CK >
	struct Filtered_kernel_base
		: public CK
	{
		// Use Exact_kernel_selector as a base class?
		typedef typename Exact_kernel_selector<CK>::Exact_nt        Exact_nt;
		typedef typename Exact_kernel_selector<CK>::Exact_kernel    Exact_kernel;
		typedef typename Exact_kernel_selector<CK>::Exact_kernel_rt Exact_kernel_rt;
		typedef typename Exact_kernel_selector<CK>::C2E             C2E;
		typedef typename Exact_kernel_selector<CK>::C2E_rt          C2E_rt;

		typedef Simple_cartesian<Interval_nt_advanced>        Approximate_kernel;
		typedef Cartesian_converter<CK, Approximate_kernel>   C2F;

		enum { Has_filtered_predicates = true };
		typedef Boolean_tag<Has_filtered_predicates> Has_filtered_predicates_tag;

		template < typename Kernel2 >
		struct Base {
			typedef typename CK::template Base<Kernel2> CK2;
			typedef Filtered_kernel_base<CK2>  Type;
		};

		template < typename T >
		struct Ambient_dimension {
			typedef typename T::Ambient_dimension type; // maybe not the right way...
		};

		template < typename T >
		struct Feature_dimension {
			typedef typename T::Feature_dimension type; // maybe not the right way...
		};

		// We change the predicates.
#define CGAL_Kernel_pred(P, Pf) \
    typedef Filtered_predicate<typename Exact_kernel::P, typename Approximate_kernel::P, C2E, C2F> P; \
    P Pf() const { return P(); }

#define CGAL_Kernel_pred_RT(P, Pf) \
    typedef Filtered_predicate<typename Exact_kernel_rt::P, typename Approximate_kernel::P, C2E_rt, C2F> P; \
    P Pf() const { return P(); }

	// We don't touch the constructions.
#define CGAL_Kernel_cons(Y,Z)

//#include <Kernel/interface_macros.h>

	};

	template < typename CK >
	struct Static_filters_base
		: public internal::Static_filters< Filtered_kernel_base<CK> >
	{
		template < typename Kernel2 >
		struct Base {
			typedef typename CK::template Base<Kernel2>::Type  CK2;
			typedef Static_filters_base<CK2>                   Type;
		};
	};

#ifdef CGAL_NO_STATIC_FILTERS
	template < typename CK, bool UseStaticFilters = false >
#else
	template < typename CK, bool UseStaticFilters = true >
#endif
	struct Filtered_kernel_adaptor
		: public Filtered_kernel_base<CK>
	{
		enum { Has_static_filters = false };
	};

	template < typename CK >
	struct Filtered_kernel_adaptor<CK, true>
		: public Static_filters_base<CK>
	{
		enum { Has_static_filters = true };
	};

} 

#endif 
