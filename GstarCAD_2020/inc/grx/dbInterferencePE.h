#include "gcdb.h"
#include "dbmain.h"

#pragma once
#pragma pack (push, 8)

class GcDbInterferencePE : public GcRxObject
{
public:
    enum Flags 
    {
        kDefault     = 0x00,
    };

    GCRX_DECLARE_MEMBERS(GcDbInterferencePE);

    virtual Gcad::ErrorStatus createInterferenceObjects(  GcArray<GcDbEntity*>& interferenceObjects,
                                    GcDbEntity* pEnt1, 
                                    GcDbEntity* pEnt2,
                                    unsigned int flags ) const = 0;
};

#pragma pack (pop)

//#endif

