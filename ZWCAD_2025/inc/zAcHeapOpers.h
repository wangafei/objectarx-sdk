

#pragma once
#include "zadesk.h"

#include "zacheapmanager.h"

class ZcHeapOperators {
public:

#undef new
#undef delete
		static void* operator new(size_t size) {
            void *p = ::zcHeapAlloc(nullptr, size);
            if (p)
                return p;
            ZSOFT_UNREACHABLE;
		}

		static void* operator new[](size_t size) {
            void *p = ::zcHeapAlloc(nullptr, size);
            if (p)
                return p;
            ZSOFT_UNREACHABLE;
		}

			static void* operator new(size_t size, const char *pFName,
				int nLine)
		{
            void *p = ::zcHeapAlloc(nullptr, size);
            if (p)
                return p;
            ZSOFT_UNREACHABLE;
		}

		static void* operator new[](size_t size,
			const char *pFName, int nLine)
		{
            void *p = ::zcHeapAlloc(nullptr, size);
            if (p)
                return p;
            ZSOFT_UNREACHABLE;
		}

			static void operator delete(void *p) {
			if (p != NULL)
                ::zcHeapFree(nullptr, p);
		}

		static void operator delete[](void *p) {
			if (p != NULL)
                ::zcHeapFree(nullptr, p);
		}

			static void operator delete(void *p, const char *pFName,
				int nLine)
		{
			if (p != NULL)
                ::zcHeapFree(nullptr, p);
		}

		static void operator delete[](void *p,
			const char *pFName, int nLine)
		{
			if (p != NULL)
                ::zcHeapFree(nullptr, p);
		}
};  

