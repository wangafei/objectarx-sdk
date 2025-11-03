

#ifndef ZC_DBBOILER_H
#define ZC_DBBOILER_H

#include "zrxboiler.h"

#define ZCDB_DECLARE_MEMBERS(CLASSNAME) \
private: \
    friend class ZcDbSystemInternals; \
protected: \
    CLASSNAME(ZcDbSystemInternals*); \
public: \
    ZCRX_DECLARE_MEMBERS(CLASSNAME)


#define ZCDB_DECLARE_MEMBERS_EXPIMP(CLASSNAME, EXPIMP) \
private: \
	friend class ZcDbSystemInternals; \
protected: \
	CLASSNAME(ZcDbSystemInternals*); \
public: \
	ZCRX_DECLARE_MEMBERS_EXPIMP(CLASSNAME, EXPIMP)

#define ZCDBCORE2D_DECLARE_MEMBERS(CLASSNAME) ZCDB_DECLARE_MEMBERS_EXPIMP(CLASSNAME, ZCDBCORE2D_PORT)

#if defined(_ZSOFT_IOS_) || defined(_ZSOFT_WEB_) || defined(_ZSOFT_ANDROID_)
#define GEOMENT_DECLARE_MEMBERS(CLASSNAME) \
ZCDBCORE2D_DECLARE_MEMBERS(CLASSNAME);
#else
#define GEOMENT_DECLARE_MEMBERS(CLASSNAME) \
ZCDB_DECLARE_MEMBERS(CLASSNAME);
#endif

#endif
