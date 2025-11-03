#pragma once
#include "zrxobject.h"
#include "zAcDbAssocArrayItem.h"

class ZcDbArrayGripAppData;
class ZcDbImpAssocArrayParameters;
class ZcDbGeomRef;

class ZCDBCORE2D_PORT ZcDbAssocArrayParameters : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocArrayParameters);

    ~ZcDbAssocArrayParameters(void);

    Zcad::ErrorStatus setValueParam(const ZcString&        paramName,
                                    const ZcDbEvalVariant& value,
                                    const ZcString&        expression,
                                    const ZcString&        evaluatorId,
                                    ZcString&              errorMessage,
                                    ZcValue::UnitType*     pUnitType = NULL);

    Zcad::ErrorStatus getValueParam(const ZcString&  paramName,
                                    ZcDbEvalVariant& value,
                                    ZcString&        expression,
                                    ZcString&        evaluatorId,
                                    ZcValue::UnitType& unitType) const;

    Zcad::ErrorStatus setGeomParam(const ZcString&   paramName,
                                   const ZcDbGeomRef* pGeomRef,
                                   ZcDbObjectId&     paramId);

    Zcad::ErrorStatus getGeomParam(const ZcString&   paramName,
                                   ZcDbGeomRef*&     pGeomRef,
                                   ZcDbObjectId&     paramId) const;

    void ownedValueParamNames(ZcArray<ZcString>& paramNames) const;

    void ownedGeomParamNames(ZcArray<ZcString>& paramNames) const;

    Zcad::ErrorStatus setOwner(class ZcDbAssocArrayActionBody* pOwner);

    const ZcDbAssocArrayActionBody* owner() const;

    ZcDbAssocArrayActionBody* owner();

    Zcad::ErrorStatus copyFrom(const ZcRxObject* other) override;

    virtual Zcad::ErrorStatus getItems(ZcArray<ZcDbAssocArrayItem*>& items) const = 0;

    virtual Zcad::ErrorStatus getItemPosition(const ZcDbItemLocator& locator,
        ZcGePoint3d& position, ZcGeMatrix3d& xform) const = 0;

    virtual ZcDbItemLocator getCanonicalForm(const ZcDbItemLocator& locator) const = 0;

    virtual Zcad::ErrorStatus getGripPointAt(unsigned int mode, ZcDbArrayGripAppData* &pGrip) const;

    virtual Zcad::ErrorStatus getGripPoints(ZcArray<ZcDbArrayGripAppData*>& grips) const;

    virtual Zcad::ErrorStatus moveGripPointAt(const ZcDbArrayGripAppData* pGrip,
                                              const ZcGeVector3d &offset,
                                              int& modificationBit);

    virtual Zcad::ErrorStatus getStretchPoints(ZcGePoint3dArray& stretchPoints);

protected:
    friend class ZcDbImpAssocArrayParameters;
    explicit ZcDbAssocArrayParameters(ZcDbImpAssocArrayParameters* pSelf = NULL);
    ZcDbImpAssocArrayParameters* mpSelf;
};
