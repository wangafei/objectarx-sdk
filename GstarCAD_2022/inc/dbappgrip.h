#pragma once

#include "DbDatabase.h"
#include "DbAudit.h"

#include "RxProtocolReactor.h"


#pragma pack(push, 8)

class OdDbBlockTableRecord;
class OdDbBlockReference;

class FIRSTDLL_EXPORT OdDbAppEntityGrips : public OdRxProtocolReactor
{
public:

    ODRX_DECLARE_MEMBERS(OdDbAppEntityGrips);

    virtual OdResult getGripPoints (
                                        OdDbGripDataPtrArray& grips,
                                        const double          curViewUnitSize, 
                                        const int             gripSize, 
                                        const OdGeVector3d&   curViewDir, 
                                        const int             bitflags,
                                        OdDbEntity*           pEntity) = 0;
 
   
    virtual OdResult moveGripPointsAt (
                         const OdDbVoidPtrArray&        gripAppData, 
                         const OdGeVector3d&            offset,
                         const int                      bitflags,
                         OdDbEntity*                    pEntity) = 0;

    virtual void gripStatus(const OdDb::GripStat status,
                            OdDbEntity*          pEntity) = 0;
};

class FIRSTDLL_EXPORT OdDbBlockInsertionPoints :  public OdRxProtocolReactor
{
    public:

        ODRX_DECLARE_MEMBERS(OdDbBlockInsertionPoints);

        virtual OdResult getInsertionPoints (
                        const OdDbBlockTableRecord* pBlock,
                        const OdDbBlockReference*   pBlkRef,
                        OdGePoint3dArray&           insPts,
                        OdGeVector3dArray&          alignmentDirections) = 0;
};
#pragma pack(pop)
