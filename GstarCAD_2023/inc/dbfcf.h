/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef DBFCF_H
#define DBFCF_H

#include "dbmain.h"
#include "GcDbCore2dDefs.h"     

#pragma pack(push, 8)

class GCDB_PORT GcDbFcf : public  GcDbEntity
{
public:
  GCDB_DECLARE_MEMBERS(GcDbFcf);
  GcDbFcf();
  GcDbFcf(const GCHAR *, const GcGePoint3d&,
    const GcGeVector3d&, const GcGeVector3d&);
  ~GcDbFcf();

  enum whichLine { kAll = -1 };
  virtual void              setText(const GCHAR *);
  virtual Gcad::ErrorStatus text(GcString & sText, int lineNo = kAll) const;
  virtual GCHAR *           text(int lineNo = kAll) const final;
  virtual void              setLocation(const GcGePoint3d&);
  virtual GcGePoint3d       location() const;
  virtual void              setOrientation(const GcGeVector3d& norm, const GcGeVector3d& dir);
  virtual GcGeVector3d normal()    const;
  virtual GcGeVector3d direction() const;

  virtual void getBoundingPoints(GcGePoint3dArray&) const;
  virtual void getBoundingPline(GcGePoint3dArray&)  const;

  virtual void              setDimensionStyle(GcDbHardPointerId);
  virtual GcDbHardPointerId dimensionStyle() const;

  Gcad::ErrorStatus   getDimstyleData(GcDbDimStyleTableRecord*& pRecord) const;
  Gcad::ErrorStatus   setDimstyleData(GcDbDimStyleTableRecord* pNewData);
  Gcad::ErrorStatus   setDimstyleData(GcDbObjectId newDataId);
  virtual void        setDimVars();

  GcCmColor      dimclrd() const;
  GcCmColor      dimclrt() const;
  double         dimgap() const;
  double         dimscale() const;
  GcDbObjectId   dimtxsty() const;
  double         dimtxt() const;

  Gcad::ErrorStatus setDimclrd(GcCmColor&     val);
  Gcad::ErrorStatus setDimclrt(GcCmColor&     val);
  Gcad::ErrorStatus setDimgap(double         val);
  Gcad::ErrorStatus setDimscale(double         val);
  Gcad::ErrorStatus setDimtxsty(GcDbObjectId   val);
  Gcad::ErrorStatus setDimtxt(double         val);

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

#pragma pack(pop)

inline GCHAR * GcDbFcf::text(int lineNo) const
{
  GcString sText;
  if (this->text(sText, lineNo) == Gcad::eOutOfRange)
    return nullptr;
  GCHAR *pRet = nullptr;
  ::gcutNewString(sText.kwszPtr(), pRet);
  return pRet;
}
#endif
