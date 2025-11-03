/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_DBBOILER_H
#define GC_DBBOILER_H

#include "rxboiler.h"

#define GCDB_DECLARE_MEMBERS(CLASSNAME) \
private: \
    friend class GcDbSystemInternals; \
protected: \
    CLASSNAME(GcDbSystemInternals*); \
public: \
    GCRX_DECLARE_MEMBERS(CLASSNAME)

#define GCDB_DECLARE_MEMBERS_EXPIMP(CLASSNAME, EXPIMP) \
private: \
    friend class GcDbSystemInternals; \
protected: \
    CLASSNAME(GcDbSystemInternals*); \
public: \
    GCRX_DECLARE_MEMBERS_EXPIMP(CLASSNAME, EXPIMP)

#define GCDBCORE2D_DECLARE_MEMBERS(CLASSNAME) GCDB_DECLARE_MEMBERS_EXPIMP(CLASSNAME, GCDB_PORT)


#if defined(_GSOFT_WINRT_) || defined(_GSOFT_IOS_) || defined(_GSOFT_WEB_) || defined(_GSOFT_ANDROID_)
#define GEOMENT_DECLARE_MEMBERS(CLASSNAME) \
GCDBCORE2D_DECLARE_MEMBERS(CLASSNAME); 
#else
#define GEOMENT_DECLARE_MEMBERS(CLASSNAME) \
GCDB_DECLARE_MEMBERS(CLASSNAME);
#endif


#endif