

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


#define ZCDBCORE2D_DECLARE_MEMBERS(CLASSNAME) \
private: \
	friend class ZcDbSystemInternals; \
protected: \
	CLASSNAME(ZcDbSystemInternals*); \
public: \
	ZCRX_DECLARE_MEMBERS_EXPIMP(CLASSNAME, ZCDBCORE2D_PORT)

#endif
