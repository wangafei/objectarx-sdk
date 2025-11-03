/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _DBALIGNMENT_H
#define _DBALIGNMENT_H

#include "gcdb.h"
#include "dbmain.h"

#pragma pack (push, 8)

class GSOFT_NO_VTABLE GCCORE_PORT GcDbAlignment : public GcRxObject{
public:
  GCRX_DECLARE_MEMBERS(GcDbAlignment);

  virtual Gcad::ErrorStatus getAlignment(
        GcDbEntity*           pEnt,
        const GcArray< GcDbObjectIdArray,
            GcArrayObjectCopyReallocator< GcDbObjectIdArray > >&
                nestedPickedEntities,
        const GcGePoint3d&    pickPoint,
        const GcGeVector3d&   normal,
        GcGePoint3d&          closestPoint,
        GcGeVector3d&         direction) = 0;
};

#pragma pack (pop)

#endif  