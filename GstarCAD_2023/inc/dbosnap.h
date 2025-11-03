/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _DBOSNAP_H
#define _DBOSNAP_H

#include "gsoft.h"

#pragma warning (disable: 4786)

#pragma pack (push, 8)

class GCCORE_PORT GcDbCustomOsnapInfo : public GcRxObject {
public:
  GCRX_DECLARE_MEMBERS(GcDbCustomOsnapInfo);

  virtual Gcad::ErrorStatus   getOsnapInfo(
    GcDbEntity*           pickedObject,
    Gsoft::GsMarker       gsSelectionMark,
    const GcGePoint3d&    pickPoint,
    const GcGePoint3d&    lastPoint,
    const GcGeMatrix3d&   viewXform,
    GcArray<GcGePoint3d>& snapPoints,
    GcDbIntArray &     geomIdsForPts,
    GcArray<GcGeCurve3d*>& snapCurves,
    GcDbIntArray &     geomIdsForLines) = 0;
};

class GCCORE_PORT GcGiGlyph : public GcGiDrawable
{
public:
  GCRX_DECLARE_MEMBERS(GcGiGlyph);

  virtual Gcad::ErrorStatus setLocation(const GcGePoint3d& dcsPoint) = 0;
  Gsoft::Boolean  isPersistent() const override { return Gsoft::kFalse; }
  GcDbObjectId    id() const override { return 0; }

protected:
  Gsoft::UInt32   subSetAttributes(GcGiDrawableTraits*) override
  {
    return 0;
  }
  Gsoft::Boolean  subWorldDraw(GcGiWorldDraw*) override { return Gsoft::kFalse; };
  void subViewportDraw(GcGiViewportDraw* vportDrawContext) override = 0;
};

class GCCORE_PORT GcDbCustomOsnapMode {
public:
  virtual const GCHAR * localModeString() const = 0;
  virtual const GCHAR * globalModeString() const = 0;
  virtual const GcRxClass* entityOsnapClass() const = 0;
  virtual GcGiGlyph* glyph() const = 0;
  virtual const GCHAR* tooltipString() const = 0;
  virtual ~GcDbCustomOsnapMode() {}
};

class GCCORE_PORT GcDbCustomOsnapManager {
public:
  virtual ~GcDbCustomOsnapManager() { }

  virtual Gcad::ErrorStatus addCustomOsnapMode(GcDbCustomOsnapMode* pMode) = 0;
  virtual Gcad::ErrorStatus removeCustomOsnapMode(GcDbCustomOsnapMode* pMode) = 0;
  virtual Gcad::ErrorStatus activateOsnapMode(const GCHAR * modeStr) = 0;
  virtual Gcad::ErrorStatus deactivateOsnapMode(const GCHAR * modeStr) = 0;
  virtual Gsoft::Boolean modeIsActive(const GCHAR * modeStr) = 0;
  virtual int osnapGlyphSize() const = 0;
};

GCCORE_PORT GcDbCustomOsnapManager* gcdbCustomOsnapManager();

extern "C" __declspec (dllexport)
bool gcedIsOsnapOverride();

#pragma pack (pop)

#endif  