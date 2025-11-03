/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBLAYOUT_H
#define GD_DBLAYOUT_H

#include "dbmain.h"
#include "dbdict.h"
#include "GdGChar.h"
#include "dbplotsettings.h"

namespace Gtil
{
  class Image;
}

typedef struct tagBITMAPINFO BITMAPINFO;

#pragma pack(push, 8)

class GCDB_PORT GcDbLayout : public GcDbPlotSettings
{
public:
  GCDB_DECLARE_MEMBERS(GcDbLayout);
  GcDbLayout();
  ~GcDbLayout();

  GcDbObjectId getBlockTableRecordId() const;
  virtual Gcad::ErrorStatus setBlockTableRecordId(GcDbObjectId BlockTableRecordId);
  virtual Gcad::ErrorStatus addToLayoutDict(GcDbDatabase *towhichDb, GcDbObjectId BlockTableRecordId);
  Gcad::ErrorStatus getLayoutName(const GCHAR*& layoutName) const;
  Gcad::ErrorStatus getName(GcString & sName) const;
  Gcad::ErrorStatus getLayoutName(GCHAR*& layoutName) const;
  virtual Gcad::ErrorStatus setLayoutName(const GCHAR* layoutName);

  int getTabOrder() const;
  virtual void setTabOrder(int newOrder);
  bool getTabSelected() const;
  virtual void setTabSelected(Gsoft::Boolean tabSelected);
  GcDbObjectIdArray getViewportArray() const;

  Gcad::ErrorStatus getThumbnail(BITMAPINFO*& thumbnail) const;
  Gcad::ErrorStatus setThumbnail(const BITMAPINFO * thumbnail);
  Gcad::ErrorStatus getPreviewImage(Gtil::Image*& pPreviewImage) const;
  Gcad::ErrorStatus setPreviewImage(const Gtil::Image * pPreviewImage);

  void getLimits(GcGePoint2d& limMin, GcGePoint2d& limMax) const;
  void getLimits(GcDbExtents2d& extent) const;
  void getExtents(GcGePoint3d& extMin, GcGePoint3d& extMax) const;
  void getExtents(GcDbExtents& extent) const;
  Gcad::ErrorStatus initialize(GcDbObjectId* paperVportId = NULL);
  bool annoAllVisible() const;
  Gcad::ErrorStatus setAnnoAllVisible(bool newVal);

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

inline Gcad::ErrorStatus GcDbLayout::getLayoutName(GCHAR*& layoutName) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbLayout::getName, layoutName);
}

#pragma pack(pop)

#endif