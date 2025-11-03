/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBSPFILT_H
#define GD_DBSPFILT_H

#include "dbfilter.h"
#include "gepnt2d.h"
#include "gevec2d.h"
#include "gept2dar.h"

#pragma pack (push, 8)

#define GCDB_INFINITE_XCLIP_DEPTH (1.0e+300)

class GcDbExtents;

class GCDB_PORT GcDbSpatialFilter : public  GcDbFilter
{
public:
  GCDB_DECLARE_MEMBERS(GcDbSpatialFilter);

  GcDbSpatialFilter();
  ~GcDbSpatialFilter();

  GcRxClass* indexClass() const override;
  virtual void queryBounds(GcDbExtents& ext, const GcDbBlockReference * pRefBlkRef) const;

  GcDbSpatialFilter(const GcGePoint2dArray& pts,
    const GcGeVector3d&     normal,
    double                  elevation,
    double                  frontClip,
    double                  backClip,
    Gsoft::Boolean          enabled);

  void queryBounds(GcDbExtents& ext) const;
  Gcad::ErrorStatus  getVolume(GcGePoint3d&  fromPt,
    GcGePoint3d&  toPt,
    GcGeVector3d& upDir,
    GcGeVector2d& viewField) const;

  Gcad::ErrorStatus setDefinition(const GcGePoint2dArray& pts,
    const GcGeVector3d&     normal,
    double                  elevation,
    double                  frontClip,
    double                  backClip,
    Gsoft::Boolean          enabled);
  Gcad::ErrorStatus getDefinition(GcGePoint2dArray& pts,
    GcGeVector3d&     normal,
    double&           elevation,
    double&           frontClip,
    double&           backClip,
    Gsoft::Boolean&   enabled) const;

  GcGeMatrix3d& getClipSpaceToWCSMatrix(GcGeMatrix3d& mat) const;
  GcGeMatrix3d& getOriginalInverseBlockXform(GcGeMatrix3d& mat) const;

  Gcad::ErrorStatus setPerspectiveCamera(const GcGePoint3d& fromPt);
  Gsoft::Boolean    clipVolumeIntersectsExtents(const GcDbExtents& ext) const;
  Gsoft::Boolean    hasPerspectiveCamera() const;

  bool isInverted() const;
  Gcad::ErrorStatus setInverted(bool bInverted);
};

#pragma pack (pop)

#endif 