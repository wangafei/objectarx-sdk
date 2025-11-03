

#ifndef _zrxiter_h
#define _zrxiter_h 1

#include "zrxobject.h"
#include "zrxboiler.h"
#include "zacbasedefs.h" 
#pragma pack (push, 8)

class ZcRxIterator: public ZcRxObject
{
public:
	ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxIterator, ZCBASE_PORT);

    virtual bool done() const = 0;  
    virtual bool next() = 0;  
    virtual ZcRxObject*    object() const = 0;
};

#pragma pack (pop)
#endif
