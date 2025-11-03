/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocGlobal.h"
#include "GcString.h"
#include "gcarray.h"
#include "GcConstrainedGeometry.h"
#include "GcDbAssocDependencyBody.h"
#pragma pack (push, 8)

class GcDbAssocDimDependencyBodyBase : public GcDbAssocDependencyBody
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbAssocDimDependencyBodyBase, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcDbAssocDimDependencyBodyBase(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);
  DBCONSTRAINTS_PORT ~GcDbAssocDimDependencyBodyBase();

  DBCONSTRAINTS_PORT virtual GcString getEntityTextOverride() const = 0;
  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus setEntityTextOverride(const GcString& newText) = 0;

  DBCONSTRAINTS_PORT virtual double getEntityMeasurementOverride() const = 0;
  DBCONSTRAINTS_PORT virtual bool isEntityAttachmentChangedOverride() const = 0;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus updateDependentOnObjectOverride() override;
  DBCONSTRAINTS_PORT class GcExplicitConstraint* constraint() const;
  DBCONSTRAINTS_PORT GcDbObjectId variable() const;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus getConstrainedGeoms(GcArray<GcConstrainedGeometry*>& geoms) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus getConstrainedGeoms(GcArray<GcDbFullSubentPath>& geoms) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus getConstrainedGeoms(GcArray<GcDbSubentGeometry>& geoms,
    GcGeVector3d&                distanceDirection) const;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus getVariableNameAndExpression(GcString& name, GcString& expression, GcString& value) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus getEntityNameAndExpression(GcString& name, GcString& expression) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setVariableNameAndExpression(const GcString& name, const GcString& expression);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setEntityNameAndExpression(const GcString& name, const GcString& expression, const GcString& value);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setNameAndExpression(const GcString& name, const GcString& expression);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus validateEntityText(const GcString& entityTextToValidate,
    GcString&       errorMessage) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus updateEntityText();
  DBCONSTRAINTS_PORT GcString          composeEntityText(int requiredNameFormat = -1) const;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus setVariableValueToMeasuredValue() const;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus deactivateConstraint() const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus reactivateConstraint() const;

  DBCONSTRAINTS_PORT bool isConstraintActive() const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus getMeasuredValue(double& measurement) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setIsReferenceOnly(bool yesNo);
  DBCONSTRAINTS_PORT static Gcad::ErrorStatus
    getNameAndExpressionFromEntityText(const GcString& entityText,
      bool            useMeasurementIfNoText,
      double          measurement,
      bool            isAngular,
      GcString&       name,
      GcString&       expression);

  DBCONSTRAINTS_PORT int getCurrentlyUsedEntityNameFormat() const;
  DBCONSTRAINTS_PORT void dragStatus(const GcDb::DragStat status);
  DBCONSTRAINTS_PORT static Gcad::ErrorStatus getFromEntity(const GcDbObjectId& entityId, GcDbObjectId& dimDepBodyId);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus entityAttachmentPointMoved(const GcArray<GcDbSubentGeometry>& newAttachedGeometries,
    double measurement = 0.0);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus isRelevantChangeOverride(bool& isRelevChange) const override;

  DBCONSTRAINTS_PORT void evaluateOverride() override;
  DBCONSTRAINTS_PORT void modifiedOverride(const GcDbObject* pDbObj) override;
  DBCONSTRAINTS_PORT void erasedOverride(const GcDbObject* pDbObj, Gsoft::Boolean isErasing) override;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus subErase(Gsoft::Boolean erasing) override;

  DBCONSTRAINTS_PORT static GcString formatToCurrentPrecision(const GcString& expression, bool isAngular);

  DBCONSTRAINTS_PORT static bool setEraseDimensionIfDependencyIsErased(bool yesNo);
  DBCONSTRAINTS_PORT static bool getEraseDimensionIfDependencyIsErased();

  class NotificationIgnorer
  {
  public:
    DBCONSTRAINTS_PORT NotificationIgnorer();
    DBCONSTRAINTS_PORT ~NotificationIgnorer();

    DBCONSTRAINTS_PORT static bool isIgnoringNotifications();

  private:
    const bool mPrevIsIgnoringNotifications;
    static bool smIsIgnoringNotifications;
  };
};

#pragma pack (pop)