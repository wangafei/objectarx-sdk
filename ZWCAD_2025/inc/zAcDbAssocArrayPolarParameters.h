
#pragma once

#include "zAcDbAssocArrayCommonParameters.h"

class ZcDbImpAssocArrayPolarParameters;

class ZCDBCORE2D_PORT ZcDbAssocArrayPolarParameters : public ZcDbAssocArrayCommonParameters
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocArrayPolarParameters);

    ZcDbAssocArrayPolarParameters(double angle = 15, double rowSpacing = 1,
        double levelSpacing = 1, int itemCount = 1, int rowCount = 1,
        int levelCount = 1, double rowElevation = 1);

    ~ZcDbAssocArrayPolarParameters(void);

    enum GripModes
    {

        kCenterPointGrip         = 1 << 0,

        kStretchRadiusGrip       = 1 << 1,

        kRowCountGrip            = 1 << 2,

        kRowSpacingGrip          = 1 << 3,

        kUniformRowSpacingGrip   = 1 << 4,

        kLevelCountGrip          = 1 << 5,

        kLevelSpacingGrip        = 1 << 6,

        kUniformLevelSpacingGrip = 1 << 7,

        kItemCountGrip           = 1 << 8,

        kAngleBetweenItemsGrip   = 1 << 9,

        kFillAngleGrip           = 1 << 10,

    };

    enum Direction
    {
        kClockwise,
        kCounterClockwise,
    };

    int itemCount(ZcString& expression, ZcString& evaluatorId) const;
    inline int itemCount() const
    {
        ZcString expression, evaluatorId;
        return itemCount(expression, evaluatorId);
    }
    inline int itemCount(ZcString& expression) const
    {
        ZcString evaluatorId;
        return itemCount(expression, evaluatorId);
    }

    double angleBetweenItems(ZcString& expression , ZcString& evaluatorId) const;
    inline double angleBetweenItems() const
    {
        ZcString expression, evaluatorId;
        return angleBetweenItems(expression, evaluatorId);
    }
    inline double angleBetweenItems(ZcString& expression) const
    {
        ZcString evaluatorId;
        return angleBetweenItems(expression, evaluatorId);
    }

    double fillAngle(ZcString& expression, ZcString& evaluatorId) const;
    inline double fillAngle() const
    {
        ZcString expression, evaluatorId;
        return fillAngle(expression, evaluatorId);
    }
    inline double fillAngle(ZcString& expression) const
    {
        ZcString evaluatorId;
        return fillAngle(expression, evaluatorId);
    }

    double startAngle(ZcString& expression, ZcString& evaluatorId) const;

    Direction direction() const;

    bool rotateItems() const;

    double radius(ZcString& expression, ZcString& evaluatorId) const;
    inline double radius() const
    {
        ZcString expression, evaluatorId;
        return radius(expression, evaluatorId);
    }
    inline double radius(ZcString& expression) const
    {
        ZcString evaluatorId;
        return radius(expression, evaluatorId);
    }

    Zcad::ErrorStatus setItemCount(int nItems, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString(), ZcString& errorMessage = dummyString());

    Zcad::ErrorStatus setAngleBetweenItems(double angle, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString(), ZcString& errorMessage = dummyString());

    Zcad::ErrorStatus setFillAngle(double fillAngle, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString(), ZcString& errorMessage = dummyString());

    Zcad::ErrorStatus setStartAngle(double angle, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString(), ZcString& errorMessage = dummyString());

    Zcad::ErrorStatus setDirection(Direction direction);

    Zcad::ErrorStatus setRotateItems(bool bRotateItems);

    Zcad::ErrorStatus setRadius(double radius, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString(), ZcString& errorMessage = dummyString());

    Zcad::ErrorStatus getItems(ZcArray<ZcDbAssocArrayItem*>& items) const override;

    Zcad::ErrorStatus getItemPosition(const ZcDbItemLocator& locator,
        ZcGePoint3d& position, ZcGeMatrix3d& xform) const override;

protected:
    friend class ZcDbImpAssocArrayPolarParameters;
    explicit ZcDbAssocArrayPolarParameters(ZcDbImpAssocArrayPolarParameters* pSelf);
};
