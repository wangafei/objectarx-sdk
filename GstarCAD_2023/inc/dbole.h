/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBOLE_H
#define GD_DBOLE_H

#include "dbmain.h"
#include "dbframe.h"
#include "gepnt3d.h"

#pragma pack (push, 8)

class CRectangle3d
{
public:
  GcGePoint3d upLeft;
  GcGePoint3d upRight;
  GcGePoint3d lowLeft;
  GcGePoint3d lowRight;
};

bool operator==(const CRectangle3d&l, const CRectangle3d&r);

class COleClientItem;

class GCDB_PORT GcDbOleFrame : public GcDbFrame
{
public:
  GCDB_DECLARE_MEMBERS(GcDbOleFrame);
  GcDbOleFrame();
  ~GcDbOleFrame();

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* filer) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* filer) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* filer) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* filer) const override;

  virtual void* getOleObject(void) const;
  virtual void setOleObject(const void *pItem);
protected:
};

class GCDB_PORT GcDbOle2Frame : public GcDbOleFrame
{
public:
  GCDB_DECLARE_MEMBERS(GcDbOle2Frame);
  GcDbOle2Frame();
  ~GcDbOle2Frame();

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* filer) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* filer) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* filer) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* filer) const override;

  void saveAs(GcGiWorldDraw* mode, GcDb::SaveType st) override;
  void* getOleObject(void) const override;
  void setOleObject(const void *pItem) override;
  void* getOleItemHost() const;

  COleClientItem* getOleClientItem(void) const;
  Gcad::ErrorStatus setOleClientItem(const COleClientItem* pItem);

  virtual void getLocation(GcGePoint3d& point3d) const;
  void setLocation(const GcGePoint3d& point3d);

  virtual void position(CRectangle3d& rect3d) const;
  virtual void setPosition(const CRectangle3d& rect3d);

  virtual void position(RECT& rect) const;
  virtual void setPosition(const RECT& rect);

  virtual void getUserType(GCHAR * pszName, int nNameSize) const;
  Gcad::ErrorStatus getUserType(GcString &) const;

  virtual int getType(void) const;

  virtual bool getLinkName(GCHAR * pszName, int nNameSize) const;
  Gcad::ErrorStatus getLinkName(GcString &) const;

  bool isLinked() const;
  virtual bool getLinkPath(GCHAR * pszPath, int nPathSize) const;
  Gcad::ErrorStatus getLinkPath(GcString &) const;

  virtual Gsoft::UInt8 outputQuality() const;
  virtual void setOutputQuality(Gsoft::UInt8);

  Gsoft::Boolean autoOutputQuality() const;
  void setAutoOutputQuality(Gsoft::UInt8);

  double rotation() const;
  Gcad::ErrorStatus setRotation(const double rotation);

  double wcsWidth() const;
  Gcad::ErrorStatus setWcsWidth(const double wcsWidth);

  double wcsHeight() const;
  Gcad::ErrorStatus setWcsHeight(const double wcsHeight);

  double scaleWidth() const;
  Gcad::ErrorStatus setScaleWidth(const double scaleWidth);

  double scaleHeight() const;
  Gcad::ErrorStatus setScaleHeight(const double scaleHeight);

  Gsoft::Boolean lockAspect() const;
  Gcad::ErrorStatus setLockAspect(const Gsoft::Boolean bLockAspect);

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

#pragma pack (pop)

#endif  