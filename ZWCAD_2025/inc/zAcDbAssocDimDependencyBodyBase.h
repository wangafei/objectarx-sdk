
#pragma once
#include "zAcDbAssocGlobal.h"
#include "zAcString.h"
#include "zAcArray.h"
#include "zAcConstrainedGeometry.h"
#include "zAcDbAssocDependencyBody.h"
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbAssocDimDependencyBodyBase : public ZcDbAssocDependencyBody
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocDimDependencyBodyBase);

    explicit ZcDbAssocDimDependencyBodyBase(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    ~ZcDbAssocDimDependencyBodyBase();

    virtual ZcString getEntityTextOverride() const = 0;

    virtual Zcad::ErrorStatus setEntityTextOverride(const ZcString& newText) = 0;

    virtual double getEntityMeasurementOverride() const = 0;

    virtual bool isEntityAttachmentChangedOverride() const = 0;

    Zcad::ErrorStatus updateDependentOnObjectOverride() override;

    class ZcExplicitConstraint* constraint() const;

    ZcDbObjectId variable() const;

    Zcad::ErrorStatus getConstrainedGeoms(ZcArray<ZcConstrainedGeometry*>& geoms) const;

    Zcad::ErrorStatus getConstrainedGeoms(ZcArray<ZcDbFullSubentPath>& geoms) const;

    Zcad::ErrorStatus getConstrainedGeoms(ZcArray<ZcDbSubentGeometry>& geoms,
                                          ZcGeVector3d&                distanceDirection) const;

    Zcad::ErrorStatus getVariableNameAndExpression(ZcString& name, ZcString& expression, ZcString& value) const;

    Zcad::ErrorStatus getEntityNameAndExpression(ZcString& name, ZcString& expression) const;

    Zcad::ErrorStatus setVariableNameAndExpression(const ZcString& name, const ZcString& expression);

    Zcad::ErrorStatus setEntityNameAndExpression(const ZcString& name, const ZcString& expression, const ZcString& value);

    Zcad::ErrorStatus setNameAndExpression(const ZcString& name, const ZcString& expression);

    Zcad::ErrorStatus validateEntityText(const ZcString& entityTextToValidate,
                                         ZcString&       errorMessage) const;

    Zcad::ErrorStatus updateEntityText();

    ZcString composeEntityText(int requiredNameFormat = -1) const;

    Zcad::ErrorStatus setVariableValueToMeasuredValue() const;

    Zcad::ErrorStatus deactivateConstraint() const;

    Zcad::ErrorStatus reactivateConstraint() const;

    bool isConstraintActive() const;

    Zcad::ErrorStatus getMeasuredValue(double& measurement) const;

    Zcad::ErrorStatus setIsReferenceOnly(bool yesNo);

    static Zcad::ErrorStatus
    getNameAndExpressionFromEntityText(const ZcString& entityText,
                                       bool            useMeasurementIfNoText,
                                       double          measurement,
                                       bool            isAngular,
                                       ZcString&       name,
                                       ZcString&       expression);

    int getCurrentlyUsedEntityNameFormat() const;

    void dragStatus(const ZcDb::DragStat status);

    static Zcad::ErrorStatus getFromEntity(const ZcDbObjectId& entityId, ZcDbObjectId& dimDepBodyId);

    Zcad::ErrorStatus entityAttachmentPointMoved(const ZcArray<ZcDbSubentGeometry>& newAttachedGeometries,
                                                 double measurement = 0.0);

    Zcad::ErrorStatus isRelevantChangeOverride(bool& isRelevChange) const override;

    void evaluateOverride() override;

    void modifiedOverride(const ZcDbObject* pDbObj) override;

    void erasedOverride(const ZcDbObject* pDbObj, ZSoft::Boolean isErasing) override;

    Zcad::ErrorStatus subErase(ZSoft::Boolean erasing) override;

    static ZcString formatToCurrentPrecision(const ZcString& expression, bool isAngular);

    static bool setEraseDimensionIfDependencyIsErased(bool yesNo);

    static bool getEraseDimensionIfDependencyIsErased();

    class ZCDBCORE2D_PORT NotificationIgnorer
    {
    public:

        NotificationIgnorer();

        ~NotificationIgnorer();

        static bool isIgnoringNotifications();
    private:
        const bool mPrevIsIgnoringNotifications;
        static bool smIsIgnoringNotifications;
    };
};

#pragma pack (pop)

