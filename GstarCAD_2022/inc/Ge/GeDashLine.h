
#ifndef GEDASHLINE_INCLUDED
#define GEDASHLINE_INCLUDED /* {Secret} */

#include "../OdArray.h"
#include "../Ge/GePoint2d.h"
#include "../Ge/GeVector2d.h"
#include "../Ge/GePoint3d.h"
#include "../Ge/GeVector3d.h"
#include "../Ge/GePoint2dArray.h"
#include "../Ge/GePoint3dArray.h"

#include "../TD_PackPush.h"

class GE_TOOLKIT_EXPORT OdGeDashLine2d
{
public:
  OdGeDashLine2d();
  OdGeDashLine2d(OdUInt32 count, const OdGePoint2d& start, const OdGeVector2d& dir, const OdGeVector2d& step);
  ~OdGeDashLine2d();

public:

  OdUInt32 numLines() const{return m_count;}

  bool getLineSegAt(int index, OdGePoint2d& startPt, OdGePoint2d& endPt) const;
  bool getLineSegs(OdGePoint2dArray& startPts, OdGePoint2dArray& endPts) const;

  OdGePoint2d startPoint() const;
  OdGePoint2d endPoint() const;
  
public:

  OdGePoint2d  m_start;
  OdGeVector2d m_dir;
  OdGeVector2d m_step;
  OdUInt32     m_count;
};

typedef OdArray<OdGeDashLine2d> OdGeDashLine2dArray;

class GE_TOOLKIT_EXPORT OdGeMultiDashLine2d
{
public:
  OdGeMultiDashLine2d();
  ~OdGeMultiDashLine2d();

public:
  struct LineInfo2d
  {
    LineInfo2d(OdUInt32 c = 0, const OdGePoint2d& pt = OdGePoint2d::kOrigin)
      : count(c)
      , start(pt)
    {}
    OdGePoint2d start;
    OdUInt32    count;
  };
  typedef OdArray<LineInfo2d, OdMemoryAllocator<LineInfo2d>> OdGeLineInfo2dArray;

  OdGeLineInfo2dArray m_lineInfo;

  OdGeVector2d m_dir;
  OdGeVector2d m_step;

public:
  OdUInt32 numLines() const;

  bool getLineSeg(int index, OdGePoint2d& startPt, OdGePoint2d& endPt) const;
  bool getLineSeg(int index, int subIndex, OdGePoint2d& startPt, OdGePoint2d& endPt) const;

  bool getLineSegs(OdGePoint2dArray& startPts, OdGePoint2dArray& endPts) const;
};


typedef OdArray<OdGeMultiDashLine2d> OdGeMultiDashLine2dArray;

class GE_TOOLKIT_EXPORT OdGeDashLine3d
{
public:
  OdGeDashLine3d();
  OdGeDashLine3d(OdUInt32 count, const OdGePoint3d& start, const OdGeVector3d& dir, const OdGeVector3d& step);
  ~OdGeDashLine3d();

public:
  OdUInt32 numLines() const{return m_count;}

  bool getLineSegAt(int index, OdGePoint3d& startPt, OdGePoint3d& endPt) const;
  bool getLineSegs(OdGePoint3dArray& startPts, OdGePoint3dArray& endPts) const;

  OdGePoint3d startPoint() const;
  OdGePoint3d endPoint() const;

public:

  OdGePoint3d  m_start;
  OdGeVector3d m_dir;
  OdGeVector3d m_step;
  OdUInt32     m_count;
};

typedef OdArray<OdGeDashLine3d> OdGeDashLine3dArray;


class GE_TOOLKIT_EXPORT OdGeMultiDashLine3d
{
public:
  OdGeMultiDashLine3d();
  ~OdGeMultiDashLine3d();

public:
  struct LineInfo3d
  {
    LineInfo3d(OdUInt32 c = 0, const OdGePoint3d& pt = OdGePoint3d::kOrigin)
      : count(c)
      , start(pt)
    {}
    OdGePoint3d start;
    OdUInt32    count;
  };
  typedef OdArray<LineInfo3d, OdMemoryAllocator<LineInfo3d>> OdGeLineInfo3dArray;

  OdGeLineInfo3dArray m_lineInfo;

  OdGeVector3d m_dir;
  OdGeVector3d m_step;

public:
  OdUInt32 numLines() const;

  bool getLineSeg(int index, OdGePoint3d& startPt, OdGePoint3d& endPt) const;
  bool getLineSeg(int index, int subIndex, OdGePoint3d& startPt, OdGePoint3d& endPt) const;

  bool getLineSegs(OdGePoint3dArray& startPts, OdGePoint3dArray& endPts) const;
};


typedef OdArray<OdGeMultiDashLine3d> OdGeMultiDashLine3dArray;

#include "../TD_PackPop.h"

#endif // GEDASHLINE_INCLUDED

