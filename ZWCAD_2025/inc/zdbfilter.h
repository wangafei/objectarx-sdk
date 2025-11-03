

#ifndef ZD_DBFILTER_H
#define ZD_DBFILTER_H

#include "zdbmain.h"

#pragma pack (push, 8)

class ZcDbFilteredBlockIterator;

class ZCDBCORE2D_PORT ZcDbFilter: public  ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbFilter);
	     ZcDbFilter();
    virtual ~ZcDbFilter();

    virtual ZcRxClass* indexClass() const;
};

#pragma pack (pop)

#endif 
