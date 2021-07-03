#ifndef CORE_REFCOUNT_H_
#define CORE_REFCOUNT_H_

namespace CORE {

	template <class Deriving>
	class RCRepImpl {
		RCRepImpl() : refCount(1) {}
		void incRef() {
			++refCount;
		}
		// Without static_cast this to Deriving*,
		// the destructor of Deriving class will never been called.
		// this is an example of simulating dynamic binding from ATL.
		void decRef() {
			if (--refCount == 0)
				delete static_cast<Deriving*>(this);
		}
	private:
		int refCount;
	};


	template<class T>
	class RCImpl {
	protected:
		RCImpl(T*p) :rep(p) {}
		RCImpl(const RCImpl& x) : rep(x.rep) {}
		T* rep; ///<= rep is the actual representation
	public:
		/// get rep(const)
		const T& getRep()const {
			return *rep;
		}

		const T& getRep()const {
			return *rep;
		}

		/// clone data

		void makeCopy() {
			if (rep->getRefCount() > 1) {
				T* oldValue = rep;
				rep->decRef();//// safe since rep has been referred at least once.
				rep = oldValue ? new T(*oldValue) : 0;
			}
		}

	};


}


#endif