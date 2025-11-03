#pragma once

#include "zAcDbAssocArrayParameters.h"
#include "zAcDbAssocActionBody.h"

class ZcDbImpAssocArrayCommonParameters;
class ZcDbVertexRef;
class ZcDbFaceRef;

class ZCDBCORE2D_PORT ZcDbAssocArrayCommonParameters : public ZcDbAssocArrayParameters
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocArrayCommonParameters);

    ~ZcDbAssocArrayCommonParameters(void);

    int levelCount(ZcString& expression, ZcString& evaluatorId) const;
    inline int levelCount() const
    {
        ZcString expression, evaluatorId;
        return levelCount(expression, evaluatorId);
    }
    inline int levelCount(ZcString& expression) const
    {
        ZcString evaluatorId;
        return levelCount(expression, evaluatorId);
    }

    double levelSpacing(ZcString& expression, ZcString& evaluatorId) const;
    inline double levelSpacing() const
    {
        ZcString expression, evaluatorId;
        return levelSpacing(expression, evaluatorId);
    }
    inline double levelSpacing(ZcString& expression) const
    {
        ZcString evaluatorId;
        return levelSpacing(expression, evaluatorId);
    }

    int rowCount(ZcString& expression, ZcString& evaluatorId) const;
    inline int rowCount() const
    {
        ZcString expression, evaluatorId;
        return rowCount(expression, evaluatorId);
    }
    inline int rowCount(ZcString& expression) const
    {
        ZcString evaluatorId;
        return rowCount(expression, evaluatorId);
    }

    double rowElevation(ZcString& expression, ZcString& evaluatorId ) const;
    inline double rowElevation() const
    {
        ZcString expression, evaluatorId;
        return rowElevation(expression, evaluatorId);
    }
    inline double rowElevation(ZcString& expression) const
    {
        ZcString evaluatorId;
        return rowElevation(expression, evaluatorId);
    }

    double rowSpacing(ZcString& expression, ZcString& evaluatorId) const;
    inline double rowSpacing() const
    {
        ZcString expression, evaluatorId;
        return rowSpacing(expression, evaluatorId);
    }
    inline double rowSpacing(ZcString& expression) const
    {
        ZcString evaluatorId;
        return rowSpacing(expression, evaluatorId);
    }

    Zcad::ErrorStatus setLevelCount(int nLevels, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString(), ZcString& errorMessage = dummyString());

    Zcad::ErrorStatus setLevelSpacing(double offset, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString(), ZcString& errorMessage = dummyString());

    Zcad::ErrorStatus setRowCount(int nRows, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString(), ZcString& errorMessage = dummyString());

    Zcad::ErrorStatus setRowElevation(double elevation, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString(), ZcString& errorMessage = dummyString());

    Zcad::ErrorStatus setRowSpacing(double offset, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString(), ZcString& errorMessage = dummyString());

    Zcad::ErrorStatus getBasePlane(ZcDbVertexRef& basePoint,
        ZcGeVector3d& normal, ZcDbFaceRef* pFace = NULL) const;

    Zcad::ErrorStatus setBasePlane(const ZcDbVertexRef& basePoint,
        const ZcGeVector3d& normal, const ZcDbFaceRef* pFace = NULL);

    ZcDbItemLocator getCanonicalForm(const ZcDbItemLocator& locator) const;

protected:
    friend class ZcDbImpAssocArrayCommonParameters;
    explicit ZcDbAssocArrayCommonParameters(ZcDbImpAssocArrayCommonParameters* pSelf);
};
