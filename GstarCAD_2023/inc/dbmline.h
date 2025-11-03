/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBMLINE_H
#define GD_DBMLINE_H

#include "dbmain.h"

#pragma pack(push, 8)

struct Mline
{
  typedef Gsoft::Int8 MlineJustification;
  enum {
    kTop = 0,
    kZero = 1,
    kBottom = 2
  };
  enum {
    kOpen = 0,
    kClosed = 1,
    kMerged = 2
  };
};

class GcGePlane;

class GCDB_PORT GcDbMline : public  GcDbEntity
{
public:
  GCDB_DECLARE_MEMBERS(GcDbMline);
  GcDbMline();
  ~GcDbMline();

  Gcad::ErrorStatus setStyle(const GcDbObjectId &newStyleId);
  GcDbObjectId      style() const;

  Gcad::ErrorStatus setJustification(Mline::MlineJustification newJust);
  Mline::MlineJustification justification() const;

  Gcad::ErrorStatus setScale(double newScale);
  double            scale() const;

  GcGeVector3d      normal() const;
  Gcad::ErrorStatus setNormal(const GcGeVector3d & newNormal);

  Gcad::ErrorStatus appendSeg(const GcGePoint3d& newVertex);
  Gcad::ErrorStatus removeLastSeg(GcGePoint3d& lastVertex);

  Gcad::ErrorStatus moveVertexAt(int index, const GcGePoint3d& newPosition);

  Gcad::ErrorStatus setClosedMline(bool closed);
  bool              closedMline() const;

  void              setSupressStartCaps(bool supressIt);
  bool              supressStartCaps() const;
  void              setSupressEndCaps(bool supressIt);
  bool              supressEndCaps() const;
  int               numVertices() const;
  int               element(const GcGePoint3d & pt) const;
  GcGePoint3d       vertexAt(int index) const;
  GcGeVector3d      axisAt(int index) const;
  GcGeVector3d      miterAt(int index) const;
  Gcad::ErrorStatus getParametersAt(int index, GcGeVoidPointerArray& params) const;
  Gcad::ErrorStatus setParametersAt(int index, GcGeVoidPointerArray& params);
  Gcad::ErrorStatus getClosestPointTo(
    const GcGePoint3d& givenPoint,
    GcGePoint3d& pointOnCurve,
    bool extend,
    bool excludeCaps = false) const;
  Gcad::ErrorStatus getClosestPointTo(
    const GcGePoint3d& givenPoint,
    const GcGeVector3d& normal,
    GcGePoint3d& pointOnCurve,
    bool extend,
    bool excludeCaps = false) const;
  void              getPlane(GcGePlane&) const;

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

#pragma pack(pop)

#endif