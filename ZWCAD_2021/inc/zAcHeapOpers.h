

#pragma once
#include "zadesk.h"

#include "zacheapmanager.h"

class ZCBASE_PORT ZcHeapOperators {
    private:
        static void * ZSOFT_STDCALL allocRawMem(size_t size);
        static void * ZSOFT_STDCALL allocRawMem(size_t size, const char *pFName,
                                             int nLine);
        static void   ZSOFT_STDCALL freeRawMem(void *p);
        static void   ZSOFT_STDCALL freeRawMem(void *p, const char *pFName,
                                            int nLine);
    public:

#undef new
#undef delete
		static void* operator new(size_t size) {
			void *p = allocRawMem(size);
			__assume(p != NULL);
			return p;
		}

		static void* operator new[](size_t size) {
			void *p = allocRawMem(size);
			__assume(p != NULL);
			return p;
		}

			static void* operator new(size_t size, const char *pFName,
				int nLine)
		{
			void * p = allocRawMem(size, pFName, nLine);
			__assume(p != NULL);
			return p;
		}

		static void* operator new[](size_t size,
			const char *pFName, int nLine)
		{
			void *p = allocRawMem(size, pFName, nLine);
			__assume(p != NULL);
			return p;
		}

			static void operator delete(void *p) {
			if (p != NULL)
				freeRawMem(p);
		}

		static void operator delete[](void *p) {
			if (p != NULL)
				freeRawMem(p);
		}

			static void operator delete(void *p, const char *pFName,
				int nLine)
		{
			if (p != NULL)
				freeRawMem(p, pFName, nLine);
		}

		static void operator delete[](void *p,
			const char *pFName, int nLine)
		{
			if (p != NULL)
				freeRawMem(p, pFName, nLine);
		}
};  

