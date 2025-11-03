
#pragma once
#include "zAcDbAssocArrayItem.h"

class ZCDB_PORT ZcDbArrayGripAppData : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbArrayGripAppData);

    ZcDbArrayGripAppData(const ZcGePoint3d& position = ZcGePoint3d(),
                         unsigned int modes = 0);

    virtual ~ZcDbArrayGripAppData();

    const ZcGePoint3d& position() const { return mPosition; }

    unsigned int modes() const { return mnModes; }

    void addGripMode(unsigned int mode) { mnModes |= mode; }

    void* getAppData(ZcRxClass** ppClass = NULL) const
    {
        if(NULL != ppClass)
            *ppClass = mpAppDataClass;
        return mpAppData;
    }

    void setAppData(void* pData, ZcRxClass* pClass)
    {
        mpAppData = pData; mpAppDataClass = pClass;
    }

    bool& arrowGrip() { return mbArrowGrip; }

    ZcGeVector3d& xDir() { return mDirections[0]; }

    ZcGeVector3d& yDir() { return mDirections[1]; }

    ZcDbItemLocator& locator() { return mLocator; }

    const ZcDbDimDataPtrArray& dimData() const { return mDimData; }

    void appendDimData(ZcDbDimData* pData);

    void deleteDimData();

    void setBasePoint(ZcGePoint3d &basePoint);

    const ZcGePoint3d* basePoint() const {return mpBasePoint;}

private:
    ZcGePoint3d mPosition;
    unsigned int mnModes;
    void* mpAppData;
    ZcRxClass* mpAppDataClass;
    ZcDbItemLocator mLocator;
    bool mbArrowGrip;
    ZcGeVector3d mDirections[2];
    ZcDbDimDataPtrArray mDimData;
    ZcGePoint3d *mpBasePoint;
};

