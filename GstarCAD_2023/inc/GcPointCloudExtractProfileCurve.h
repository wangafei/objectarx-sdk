/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once 

class DBPOINTCLOUDOBJ_PORT ProfileCurve2d
{
public:
  enum ProfileurveType
  {
    kLineSeg = 0,
    kArc,
  };
private:
  GcGeLineSeg2d m_seg;
  GcGeCircArc2d m_arc;
  ProfileurveType m_type;

public:
  ProfileCurve2d()
  {
    m_type = kLineSeg;
  }
  ProfileCurve2d(const GcGeLineSeg2d& seg)
  {
    m_seg = seg;
    m_type = kLineSeg;
  }
  ProfileCurve2d(const GcGeCircArc2d& arc)
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
  GcGeLineSeg2d lineSeg() const
  {
    return m_seg;
  }
  void setLineSeg(const GcGeLineSeg2d& lineSeg)
  {
    m_seg = lineSeg;
    m_type = kLineSeg;
  }
  GcGeCircArc2d arc() const
  {
    return m_arc;
  }
  void setArc(const GcGeCircArc2d& arc)
  {
    m_arc = arc;
    m_type = kArc;
  }
};

class DBPOINTCLOUDOBJ_PORT GcPointCloudExtractResult
{
public:
  GcArray<ProfileCurve2d> Curves;
  GcGeMatrix3d            transform;
  GcGePlane               ProjectedPlane;
};