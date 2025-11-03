/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GEOMENT_DBREGION_H
#define GEOMENT_DBREGION_H

#include "dbmain.h"
#include "dbsubeid.h"
#include "gepnt3d.h"
#include "gevec3d.h"

#pragma pack(push, 8)

class GCDB_PORT GcDbRegion : public  GcDbEntity
{
public:
  GcDbRegion();
  ~GcDbRegion();

  GEOMENT_DECLARE_MEMBERS(GcDbRegion);

  static Gcad::ErrorStatus createFromCurves(const GcDbVoidPtrArray& curveSegments, GcDbVoidPtrArray& regions);

  virtual Gcad::ErrorStatus getPerimeter(double&) const;
  virtual Gcad::ErrorStatus getArea(double& regionArea) const;
  virtual void*             ASMBodyCopy(bool bDeepCopy = false) const;
  virtual void const *      getLockedASMBody();
  virtual void              unlockASMBody();
  virtual void*             getLockedWritableASMBody();
  virtual void              commitWritableASMBody();
  virtual Gcad::ErrorStatus setASMBody(const void* modelerBody);
  virtual Gcad::ErrorStatus getAreaProp(
    const GcGePoint3d&  origin,
    const GcGeVector3d& xAxis,
    const GcGeVector3d& yAxis,
    double&             perimeter,
    double&             area,
    GcGePoint2d&        centroid,
    double              momInertia[2],
    double&             prodInertia,
    double              prinMoments[2],
    GcGeVector2d        prinAxes[2],
    double              radiiGyration[2],
    GcGePoint2d&        extentsLow,
    GcGePoint2d&        extentsHigh)const;
  virtual Gcad::ErrorStatus getPlane(GcGePlane& regionPlane) const;

  void dragStatus(const GcDb::DragStat) override;

  virtual Gsoft::Boolean    isNull() const;
  virtual Gcad::ErrorStatus getNormal(GcGeVector3d&) const;
  virtual GcDbSubentId      internalSubentId(void* ent) const;
  virtual void*             internalSubentPtr(const GcDbSubentId& id) const;
  virtual Gcad::ErrorStatus booleanOper(GcDb::BoolOperType operation, GcDbRegion* otherRegion);

  virtual Gsoft::UInt32 numChanges() const;
  virtual bool usesGraphicsCache();
  Gcad::ErrorStatus getPlane(GcGePlane& plane, GcDb::Planarity& type) const override;

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

#pragma pack(pop)

#endif