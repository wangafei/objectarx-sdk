/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#ifndef GD_DBPL_H
#define GD_DBPL_H 1

#include "dbmain.h"
#include "dbcurve.h"

#include "gelnsg2d.h"
#include "gelnsg3d.h"
#include "gearc2d.h"
#include "gearc3d.h"
#include "gept2dar.h"
#include "dbboiler.h"

#pragma pack(push, 8)

class GcDb2dPolyline;

class GCDB_PORT GcDbPolyline : public GcDbCurve
{
public:
  GcDbPolyline();
  GcDbPolyline(unsigned int num_verts);
  ~GcDbPolyline();
  GCDB_DECLARE_MEMBERS(GcDbPolyline);

  virtual Gcad::ErrorStatus convertFrom(GcDbEntity*& pPline, Gsoft::Boolean transferId = Gsoft::kTrue);
  Gcad::ErrorStatus convertTo(GcDb2dPolyline*&  pPline, Gsoft::Boolean transferId = Gsoft::kTrue) const;
  Gcad::ErrorStatus getPointAt(unsigned int, GcGePoint3d& pt) const;

  enum SegType {
    kLine,
    kArc,
    kCoincident,
    kPoint,
    kEmpty
  };

  SegType           segType(unsigned int index) const;
  Gcad::ErrorStatus getLineSegAt(unsigned int index, GcGeLineSeg2d& ln) const;
  Gcad::ErrorStatus getLineSegAt(unsigned int index, GcGeLineSeg3d& ln) const;
  Gcad::ErrorStatus getArcSegAt(unsigned int index, GcGeCircArc2d& arc) const;
  Gcad::ErrorStatus getArcSegAt(unsigned int index, GcGeCircArc3d& arc) const;
  virtual Gsoft::Boolean onSegAt(unsigned int index, const GcGePoint2d& pt2d, double& param) const;

  virtual void      setClosed(Gsoft::Boolean);
  void              setPlinegen(Gsoft::Boolean);
  virtual void      setElevation(double);
  virtual Gcad::ErrorStatus setThickness(double);
  virtual Gcad::ErrorStatus setConstantWidth(double);
  virtual Gcad::ErrorStatus setNormal(const GcGeVector3d&);

  Gsoft::Boolean    isOnlyLines()                        const;
  Gsoft::Boolean    hasPlinegen()                        const;
  double            elevation()                        const;
  double            thickness()                        const;
  Gcad::ErrorStatus getConstantWidth(double&)                 const;
  GcGeVector3d      normal()                        const;

  virtual Gcad::ErrorStatus addVertexAt(unsigned int index,
    const GcGePoint2d& pt,
    double bulge = 0.,
    double startWidth = -1.,
    double endWidth = -1.,
    Gsoft::Int32 vertexIdentifier = 0);
  virtual Gcad::ErrorStatus removeVertexAt(unsigned int index);

  unsigned int      numVerts()                        const;
  Gcad::ErrorStatus getPointAt(unsigned int index, GcGePoint2d& pt)         const;
  Gcad::ErrorStatus getBulgeAt(unsigned int index, double&      bulge)      const;
  Gcad::ErrorStatus getVertexIdentifierAt(unsigned int index, Gsoft::Int32& vertexIdentifier) const;
  Gcad::ErrorStatus getWidthsAt(unsigned int index,
    double&      startWidth,
    double&      endWidth)   const;

  virtual Gcad::ErrorStatus setPointAt(unsigned int index, const GcGePoint2d& pt);
  virtual Gcad::ErrorStatus setBulgeAt(unsigned int index, double       bulge);
  virtual Gcad::ErrorStatus setVertexIdentifierAt(unsigned int index, Gsoft::Int32 suggestedValue);
  virtual Gcad::ErrorStatus setWidthsAt(unsigned int index,
    double       startWidth,
    double       endWidth);

  Gcad::ErrorStatus minimizeMemory();
  Gcad::ErrorStatus maximizeMemory();
  virtual void      reset(Gsoft::Boolean reuse,
    unsigned int    numVerts);
  Gsoft::Boolean     hasBulges()        const;
  Gsoft::Boolean     hasVertexIdentifiers()    const;
  Gsoft::Boolean     hasWidth()        const;
  Gcad::ErrorStatus  makeClosedIfStartAndEndVertexCoincide(double distTol);

  DBCURVE_METHODS

  void              getEcs(GcGeMatrix3d& retVal) const override;
  Gcad::ErrorStatus applyPartialUndo(GcDbDwgFiler* filer, GcRxClass*    classobj) override;
  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* filer) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* filer) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* filer) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* filer) const override;

  void              saveAs(GcGiWorldDraw* mode, GcDb::SaveType st) override;

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

inline Gsoft::Boolean GcDbPolyline::isPlanar() const
{
  return Gsoft::kTrue;
}

inline Gcad::ErrorStatus GcDbPolyline::getStartParam(double& startParam) const
{
  startParam = 0.;
  return Gcad::eOk;
}

inline Gcad::ErrorStatus GcDbPolyline::getSpline(GcDbSpline*& spline) const
{
  GSOFT_UNREFED_PARAM(spline);
  return Gcad::eNotApplicable;
}

#pragma pack(pop)

#endif 