#pragma once

#include "zAcDbAssocArrayCommonParameters.h"

class ZcDbImpAssocArrayPathParameters;
class ZcDbEdgeRef;

class ZCDBCORE2D_PORT ZcDbAssocArrayPathParameters : public ZcDbAssocArrayCommonParameters
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocArrayPathParameters);

    enum GripModes
    {

        kStretchGrip             = 1 << 0,

        kRowCountGrip            = 1 << 1,

        kRowSpacingGrip          = 1 << 2,

        kUniformRowSpacingGrip   = 1 << 3,

        kLevelCountGrip          = 1 << 4,

        kLevelSpacingGrip        = 1 << 5,

        kUniformLevelSpacingGrip = 1 << 6,

        kItemCountGrip           = 1 << 7,

        kItemSpacingGrip         = 1 << 8,

        kUniformItemSpacingGrip   = 1 << 9,
    };

    ZcDbAssocArrayPathParameters(double itemSpacing = 1, double rowSpacing = 1,
        double levelSpacing = 1, int itemCount = 1, int rowCount = 1,
        int levelCount = 1, double rowElevation = 1);

    ~ZcDbAssocArrayPathParameters(void);

    enum Method
    {

        kDivide,

        kMeasure,
    };

    int itemCount(ZcString& expression, ZcString& evaluatorId) const;
    inline int itemCount() const
    {
        ZcString expression, evaluatorId;
        return itemCount(expression, evaluatorId);
    }
    inline int itemCount(ZcString & expression) const
    {
        ZcString evaluatorId;
        return itemCount(expression, evaluatorId);
    }

    double itemSpacing(ZcString& expression, ZcString& evaluatorId) const;
    inline double itemSpacing() const
    {
        ZcString expression, evaluatorId;
        return itemSpacing(expression, evaluatorId);
    }
    inline double itemSpacing(ZcString& expression) const
    {
        ZcString evaluatorId;
        return itemSpacing(expression, evaluatorId);
    }

    ZcDbEdgeRef path() const;

    Method method() const;

    bool alignItems() const;

    double startOffset(ZcString& expression, ZcString& evaluatorId) const;
    inline double startOffset() const
    {
        ZcString expression, evaluatorId;
        return startOffset(expression, evaluatorId);
    }

    double endOffset(ZcString& expression, ZcString& evaluatorId) const;
    inline double endOffset() const
    {
        ZcString expression, evaluatorId;
        return endOffset(expression, evaluatorId);
    }

    Zcad::ErrorStatus setItemCount(int nItems, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString(), ZcString& errorMessage = dummyString());

    Zcad::ErrorStatus setItemSpacing(double offset, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString(), ZcString& errorMessage = dummyString());

    Zcad::ErrorStatus setPath(const ZcDbEdgeRef& edgeRef);

    Zcad::ErrorStatus setMethod(Method method);

    Zcad::ErrorStatus setAlignItems(bool bAlignItems);

    Zcad::ErrorStatus setStartOffset(double startOffset, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString(), ZcString& errorMessage = dummyString());

    Zcad::ErrorStatus setEndOffset(double endOffset, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString(), ZcString& errorMessage = dummyString());

    Zcad::ErrorStatus setPathDirection(bool bAlongParams);

    Zcad::ErrorStatus getItems(ZcArray<ZcDbAssocArrayItem*>& items) const override;

    Zcad::ErrorStatus getItemPosition(const ZcDbItemLocator& locator,
        ZcGePoint3d& position, ZcGeMatrix3d& xform) const override;
    inline Zcad::ErrorStatus getItemPosition(const ZcDbItemLocator& locator,
                                             ZcGePoint3d& position) const
    {
        ZcGeMatrix3d xform;
        return getItemPosition(locator, position,xform);
    }

protected:
    friend class ZcDbImpAssocArrayPathParameters;
	explicit ZcDbAssocArrayPathParameters(ZcDbImpAssocArrayPathParameters* pSelf);
};
