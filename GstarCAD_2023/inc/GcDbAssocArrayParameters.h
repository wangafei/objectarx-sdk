/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "rxobject.h"
#include "GcDbAssocArrayItem.h"

class GcDbArrayGripAppData;
class GcDbImpAssocArrayParameters;
class GcDbGeomRef;

class GcDbAssocArrayParameters : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbAssocArrayParameters, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT ~GcDbAssocArrayParameters(void);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus setValueParam(const GcString&        paramName,
                                                     const GcDbEvalVariant& value,
                                                     const GcString&        expression,
                                                     const GcString&        evaluatorId,
                                                     GcString&              errorMessage,
                                                     GcValue::UnitType*     pUnitType = NULL);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus getValueParam(const GcString&  paramName,
                                                     GcDbEvalVariant& value,
                                                     GcString&        expression,
                                                     GcString&        evaluatorId,
                                                     GcValue::UnitType& unitType) const;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus setGeomParam(const GcString&   paramName,
                                                    const GcDbGeomRef* pGeomRef,
                                                    GcDbObjectId&     paramId);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus getGeomParam(const GcString&   paramName,
                                                    GcDbGeomRef*&     pGeomRef,
                                                    GcDbObjectId&     paramId) const;

  DBCONSTRAINTS_PORT void ownedValueParamNames(GcArray<GcString>& paramNames) const;
  DBCONSTRAINTS_PORT void ownedGeomParamNames(GcArray<GcString>& paramNames) const;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus setOwner(class GcDbAssocArrayActionBody* pOwner);
  DBCONSTRAINTS_PORT const GcDbAssocArrayActionBody* owner() const;
  DBCONSTRAINTS_PORT GcDbAssocArrayActionBody* owner();

  DBCONSTRAINTS_PORT Gcad::ErrorStatus copyFrom(const GcRxObject* other) override;

  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus getItems(GcArray<GcDbAssocArrayItem*>& items) const = 0;
  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus getItemPosition(const GcDbItemLocator& locator,
                                                               GcGePoint3d& position, GcGeMatrix3d& xform) const = 0;

  DBCONSTRAINTS_PORT virtual GcDbItemLocator getCanonicalForm(const GcDbItemLocator& locator) const = 0;

  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus getGripPointAt(unsigned int mode, GcDbArrayGripAppData* &pGrip) const;
  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus getGripPoints(GcArray<GcDbArrayGripAppData*>& grips) const;
  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus moveGripPointAt(const GcDbArrayGripAppData* pGrip,
                                                               const GcGeVector3d &offset,
                                                               int& modificationBit);
  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus getStretchPoints(GcGePoint3dArray& stretchPoints);

protected:
  friend class GcDbImpAssocArrayParameters;
  DBCONSTRAINTS_PORT explicit GcDbAssocArrayParameters(GcDbImpAssocArrayParameters* pSelf = NULL);
  GcDbImpAssocArrayParameters* mpSelf;
};