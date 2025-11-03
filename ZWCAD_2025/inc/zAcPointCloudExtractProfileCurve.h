#pragma once

class ZCDB_PORT ProfileCurve2d
{
public:
    enum ProfileurveType
    {
        kLineSeg = 0,
        kArc,
    };
private:
    ZcGeLineSeg2d m_seg;
    ZcGeCircArc2d m_arc;
    ProfileurveType m_type;

public:
    ProfileCurve2d()
    {
        m_type = kLineSeg;
    }

    ProfileCurve2d(const ZcGeLineSeg2d& seg)
    {
        m_seg = seg;
        m_type = kLineSeg;
    }

    ProfileCurve2d(const ZcGeCircArc2d& arc)
    {
        m_arc = arc;
        m_type = kArc;
    }

    bool isSegment() const
    {
        return m_type == kLineSeg;
    }

    bool isArc() const
    {
        return m_type == kArc;
    }

    ZcGeLineSeg2d lineSeg() const
    {
        return m_seg;
    }

    void setLineSeg(const ZcGeLineSeg2d& lineSeg)
    {
        m_seg = lineSeg;
        m_type = kLineSeg;
    }

    ZcGeCircArc2d arc() const
    {
        return m_arc;
    }

    void setArc(const ZcGeCircArc2d& arc)
    {
        m_arc = arc;
        m_type = kArc;
    }
};

class ZCDB_PORT ZcPointCloudExtractResult
{
public:
    ZcArray<ProfileCurve2d> Curves;

    ZcGeMatrix3d            transform;

    ZcGePlane               ProjectedPlane;
};
