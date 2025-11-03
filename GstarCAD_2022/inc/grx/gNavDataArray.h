#ifndef _GNavDataArray_h
#define _GNavDataArray_h

#if _MSC_VER >= 1000
#pragma once
#endif

#pragma warning(push)
#pragma warning(disable : 4275)

class GNAV_PORT CNavDataArray : public CNavArray<CNavData> {
public:
                CNavDataArray ();
virtual         ~CNavDataArray ();
};

#pragma warning(pop)
#endif
