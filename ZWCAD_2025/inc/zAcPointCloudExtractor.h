#pragma once

#include "zAcDbPointCloudEx.h"
#include "zAcPointCloudExtractProfileCurve.h"

class ZCDB_PORT ExtractOption
{
public:
    enum ExtractionType
    {
        kOutLine,
        kAllLine,
    };

public:
    ExtractionType  m_extractionType;

    unsigned int    m_processPoints;

    double          m_fillGap;

    unsigned int    m_snapAngle;

    double          m_minSegLength;

    bool            m_useLineSegmentOnly;

    ExtractOption();
};

class ZCDB_PORT IPointCloudExtracProgressCallback
{
public:
    IPointCloudExtracProgressCallback(void){}
    virtual ~IPointCloudExtracProgressCallback(void){}

    virtual void updateProgress(int progress) = 0;

    virtual void updateCaption(const ZcString& caption) = 0;

    virtual bool cancelled() const = 0;

    virtual void cancel() = 0;

    virtual void updateRemainTime(double remainTime) = 0;

    virtual void end() = 0;
};

class ZCDB_PORT ZcPointCloudExtractor
{
public:
    static Zcad::ErrorStatus extract(ZcDbPointCloudEx *pointCloud,
        const ZcGeVector3d& planeZDirection,
        const ZcGeVector3d& planeXDirection,
        ZcGePoint3d pointPlane,
        const ExtractOption& extractOption,
        ZcPointCloudExtractResult& outlineResult,
        IPointCloudExtracProgressCallback* progress = 0);

    static ZcDbObjectIdArray appendLineProfile(const ZcPointCloudExtractResult& profile,
        ZcDbObjectId spaceId,
        ZcString layer,
        ZcCmColor color);

    static ZcDbObjectIdArray appendPolylineProfile(const ZcPointCloudExtractResult& profile,
        ZcDbObjectId spaceId,
        ZcString layer,
        ZcCmColor color,
        double polylineWidth);

};
