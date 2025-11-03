/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBLEAD_H
#define GD_DBLEAD_H 1

#include "dbmain.h"
#include "dbcurve.h"
#include "gescl3d.h"
#include "gepnt2d.h"
#include "geplane.h"

#pragma pack(push, 8)

class GCDB_PORT GcDbLeader : public  GcDbCurve
{
public:
  GcDbLeader();
  ~GcDbLeader();
  GCDB_DECLARE_MEMBERS(GcDbLeader);
  DBCURVE_METHODS

    virtual  void              setPlane(const GcGePlane&);
  virtual  GcGeVector3d      normal() const;
  virtual  int               numVertices() const;
  virtual  Gsoft::Boolean    appendVertex(const GcGePoint3d&);
  virtual  void              removeLastVertex();
  virtual  GcGePoint3d firstVertex() const;
  virtual  GcGePoint3d lastVertex() const;
  virtual  GcGePoint3d vertexAt(int) const;
  virtual  Gsoft::Boolean setVertexAt(int, const GcGePoint3d&);

  virtual Gsoft::Boolean    hasArrowHead() const;
  virtual void              enableArrowHead();
  virtual void              disableArrowHead();
  void                      setHasArrowHead(Gsoft::Boolean bEnable);
  virtual Gsoft::Boolean    hasHookLine() const;
  virtual void              setToSplineLeader();
  virtual void              setToStraightLeader();
  virtual Gsoft::Boolean    isSplined() const;
  void                      setSplined(Gsoft::Boolean bSplined);
  virtual GcDbHardPointerId dimensionStyle() const;
  virtual void              setDimensionStyle(const GcDbHardPointerId&);

  Gcad::ErrorStatus   getDimstyleData(GcDbDimStyleTableRecord*& pRecord) const;
  Gcad::ErrorStatus   setDimstyleData(GcDbDimStyleTableRecord* pNewData);
  Gcad::ErrorStatus   setDimstyleData(GcDbObjectId newDataId);

  virtual Gcad::ErrorStatus attachAnnotation(const GcDbObjectId& annoId);
  virtual Gcad::ErrorStatus detachAnnotation();
  virtual GcDbObjectId      annotationObjId() const;
  Gcad::ErrorStatus         setAnnotationObjId(const GcDbObjectId& annoId);
  virtual Gcad::ErrorStatus evaluateLeader();
  virtual GcGeVector3d      annotationOffset() const;
  virtual Gcad::ErrorStatus setAnnotationOffset(const GcGeVector3d& offset);

  enum AnnoType {
    kMText = 0,
    kFcf,
    kBlockRef,
    kNoAnno
  };
  AnnoType annoType()   const;
  double   annoHeight() const;
  double   annoWidth()  const;

  virtual double           dimasz() const;
  virtual GcCmColor        dimclrd() const;
  virtual double           dimgap() const;
  virtual GcDb::LineWeight dimlwd() const;
  virtual GcDbObjectId     dimldrblk() const;
  virtual bool             dimsah() const;
  virtual double           dimscale() const;
  virtual int              dimtad() const;
  virtual GcDbObjectId     dimtxsty() const;
  virtual double           dimtxt() const;

  virtual Gcad::ErrorStatus setDimasz(double         val);
  virtual Gcad::ErrorStatus setDimclrd(GcCmColor&     val);
  virtual Gcad::ErrorStatus setDimgap(double         val);
  virtual Gcad::ErrorStatus setDimldrblk(GcDbObjectId   val);
  virtual Gcad::ErrorStatus setDimldrblk(const GCHAR *  val);
  virtual Gcad::ErrorStatus setDimlwd(GcDb::LineWeight v);
  virtual Gcad::ErrorStatus setDimsah(bool           val);
  virtual Gcad::ErrorStatus setDimscale(double         val);
  virtual Gcad::ErrorStatus setDimtad(int            val);
  virtual Gcad::ErrorStatus setDimtxsty(GcDbObjectId   val);
  virtual Gcad::ErrorStatus setDimtxt(double         val);

  void              modified(const GcDbObject*) override;
  void              erased(const GcDbObject*, Gsoft::Boolean = Gsoft::kTrue) override;
  void              goodbye(const GcDbObject*) override;
  void              copied(const GcDbObject*, const GcDbObject*) override;

  virtual void              setDimVars();
  Gcad::ErrorStatus         setColorIndex(Gsoft::UInt16, Gsoft::Boolean doSubents = Gsoft::kTrue) override;

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

inline Gsoft::Boolean GcDbLeader::isClosed() const
{
  return Gsoft::kFalse;
}

inline Gsoft::Boolean GcDbLeader::isPeriodic() const
{
  return Gsoft::kFalse;
}

inline Gsoft::Boolean GcDbLeader::isPlanar() const
{
  return Gsoft::kTrue;
}

inline Gcad::ErrorStatus GcDbLeader::getStartParam(double& param) const
{
  param = 0.0;
  return Gcad::eOk;
}

inline Gcad::ErrorStatus GcDbLeader::getOrthoProjectedCurve(const GcGePlane&, GcDbCurve*&) const
{
  return Gcad::eNotApplicable;
}

inline Gcad::ErrorStatus GcDbLeader::getProjectedCurve(const GcGePlane&, const GcGeVector3d&, GcDbCurve*&) const
{
  return Gcad::eNotApplicable;
}

inline Gcad::ErrorStatus GcDbLeader::getOffsetCurves(double, GcDbVoidPtrArray&) const
{
  return Gcad::eNotApplicable;
}

inline Gcad::ErrorStatus GcDbLeader::getSecondDeriv(double, GcGeVector3d&) const
{
  return Gcad::eNotApplicable;
}

inline Gcad::ErrorStatus GcDbLeader::getSecondDeriv(const GcGePoint3d&, GcGeVector3d&) const
{
  return Gcad::eNotApplicable;
}

inline Gcad::ErrorStatus GcDbLeader::getSplitCurves(const GcGeDoubleArray&, GcDbVoidPtrArray&) const
{
  return Gcad::eNotApplicable;
}

inline Gcad::ErrorStatus GcDbLeader::getSplitCurves(const GcGePoint3dArray&, GcDbVoidPtrArray&) const
{
  return Gcad::eNotApplicable;
}

inline Gcad::ErrorStatus GcDbLeader::extend(double)
{
  return Gcad::eNotApplicable;
}

inline Gcad::ErrorStatus GcDbLeader::extend(Gsoft::Boolean, const GcGePoint3d&)
{
  return Gcad::eNotApplicable;
}

inline Gcad::ErrorStatus GcDbLeader::getArea(double&) const
{
  return Gcad::eNotApplicable;
}

#pragma pack(pop)

#endif