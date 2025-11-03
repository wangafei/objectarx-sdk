
#ifndef ODDBDOUBLECLICKEDIT_H
#define ODDBDOUBLECLICKEDIT_H

#include "gcadstd.h"
#include "gcdb.h"
#include "dbmain.h"

#pragma pack (push, 8)

class GCDB_DLL_DECL GcDbDoubleClickEdit : public GcRxObject
{
public:
    ODRX_DECLARE_MEMBERS(GcDbDoubleClickEdit);

    virtual void startEdit(GcDbEntity *pEnt, GcGePoint3d pt) = 0; 
    virtual void finishEdit(void) = 0;
};


#pragma pack (pop)

#endif // ODDBDOUBLECLICKEDIT_H

