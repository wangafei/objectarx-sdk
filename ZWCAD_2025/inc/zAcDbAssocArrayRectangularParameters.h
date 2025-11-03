#pragma once

#include "zAcDbAssocArrayCommonParameters.h"

class ZcDbImpAssocArrayRectangularParameters;

class ZCDBCORE2D_PORT ZcDbAssocArrayRectangularParameters : public ZcDbAssocArrayCommonParameters
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocArrayRectangularParameters);

    enum GripModes
    {

        kStretchGrip             = 1 << 0,

        kRowCountGrip            = 1 << 1,

        kRowSpacingGrip          = 1 << 2,

        kUniformRowSpacingGrip   = 1 << 3,

        kColumnCountGrip         = 1 << 4,

        kColumnSpacingGrip       = 1 << 5,

        kUniformColSpacingGrip   = 1 << 6,

        kRowColumnCountGrip      = 1 << 7,

        kRowColumnSpacingGrip    = 1 << 8,

        kColumnDirectionGrip     = 1 << 9,

        kRowDirectionGrip        = 1 << 10,

        kLevelCountGrip          = 1 << 11,

        kLevelSpacingGrip        = 1 << 12,

        kUniformLevelSpacingGrip = 1 << 13,

        kRowAxisAngleGrip        = 1 << 14,
    };

    ZcDbAssocArrayRectangularParameters(double columnSpacing = 1, double rowSpacing = 1,
        double levelSpacing = 1, int columnCount = 1, int rowCount = 1,
        int levelCount = 1, double rowElevation = 1, double axesAngle = 90);

    ~ZcDbAssocArrayRectangularParameters(void);

    int columnCount(ZcString& expression, ZcString& evaluatorId) const;
    inline int columnCount() const
    {
        ZcString expression, evaluatorId;
        return columnCount(expression, evaluatorId);
    }
    inline int columnCount(ZcString& expression) const
    {
        ZcString evaluatorId;
        return columnCount(expression, evaluatorId);
    }

    double columnSpacing(ZcString& expression, ZcString& evaluatorId) const;
    inline double columnSpacing() const
    {
        ZcString expression, evaluatorId;
        return columnSpacing(expression, evaluatorId);
    }
    inline double columnSpacing(ZcString& expression) const
    {
        ZcString evaluatorId;
        return columnSpacing(expression, evaluatorId);
    }

    double axesAngle(ZcString& expression, ZcString& evaluatorId) const;
    inline double axesAngle() const
    {
        ZcString expression, evaluatorId;
        return axesAngle(expression, evaluatorId);
    }
    inline double axesAngle(ZcString& expression) const
    {
        ZcString evaluatorId;
        return axesAngle(expression, evaluatorId);
    }

    ZcGeVector3d axisDirection(ZcGeVector3d* pYAxis = NULL) const;

    Zcad::ErrorStatus setColumnCount(int nColumns, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString(), ZcString& errorMessage = dummyString());

    Zcad::ErrorStatus setColumnSpacing(double offset, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString(), ZcString& errorMessage = dummyString());

    Zcad::ErrorStatus setAxesAngle(double axesAngle, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString(), ZcString& errorMessage = dummyString());

    Zcad::ErrorStatus setAxisDirection(const ZcGeVector3d& xAxis);

    Zcad::ErrorStatus getItems(ZcArray<ZcDbAssocArrayItem*>& items) const override;

    Zcad::ErrorStatus getItemPosition(const ZcDbItemLocator& locator,
        ZcGePoint3d& position, ZcGeMatrix3d& xform) const override;

protected:
    friend class ZcDbImpAssocArrayRectangularParameters;
    explicit ZcDbAssocArrayRectangularParameters(ZcDbImpAssocArrayRectangularParameters* pSelf);
};
