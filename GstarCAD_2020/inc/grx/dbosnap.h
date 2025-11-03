#ifndef GCDB_OSNAP_H
#define GCDB_OSNAP_H

#include "gcadstd.h"

#pragma pack (push, 8)

class GCDB_DLL_DECL GcDbCustomOsnapInfo : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbCustomOsnapInfo);

  virtual Gcad::ErrorStatus getOsnapInfo(
    GcDbEntity*            pickedObject,
    Hccad::GsMarker        gsSelectionMark,
    const GcGePoint3d&     pickPoint,
    const GcGePoint3d&     lastPoint,
    const GcGeMatrix3d&    viewXform,
    GcArray<GcGePoint3d>&  snapPoints,
    GcDbIntArray&          geomIdsForPts,
    GcArray<GcGeCurve3d*>& snapCurves,
    GcDbIntArray&          geomIdsForLines) = 0;
};

class GCDB_DLL_DECL GcGiGlyph : public GcGiDrawable
{
public:
  GCRX_DECLARE_MEMBERS(GcGiGlyph);

  virtual Gcad::ErrorStatus setLocation(const GcGePoint3d& dcsPoint) = 0;

  virtual Hccad::UInt32 subSetAttributes(GcGiDrawableTraits* pTraits) { return 0; }

  virtual Hccad::Boolean subWorldDraw(GcGiWorldDraw* pWordDraw) { return false; }

  virtual void subViewportDraw(GcGiViewportDraw* pViewportDraw) = 0;

  virtual OdBool isPersistent() const       { return kFalse;}
  virtual GcDbObjectId id() const           { return 0;     }
  virtual GcDbStub * getStub() const		    { return NULL;	}
  virtual void setGsNode(OdGsNode* pGsNode) { return ;      }
  virtual OdGsNode* gsNode() const          { return NULL;  }
};



class GCDB_DLL_DECL GcDbCustomOsnapMode
{
public:
  virtual ~GcDbCustomOsnapMode() {}

  virtual const GCHAR* localModeString() const = 0;
  virtual const GCHAR* globalModeString() const = 0;

  virtual const OdRxClass* entityOsnapClass() const = 0;

  virtual GcGiGlyph* glyph() const = 0;

  virtual const GCHAR* tooltipString() const = 0;
};

class GCDB_DLL_DECL GcDbCustomOsnapManager
{
public:

  virtual Gcad::ErrorStatus addCustomOsnapMode(GcDbCustomOsnapMode* pMode) = 0;

  virtual Gcad::ErrorStatus removeCustomOsnapMode(GcDbCustomOsnapMode* pMode) = 0;

  virtual Gcad::ErrorStatus activateOsnapMode(const GCHAR* sMode) = 0;

  virtual Gcad::ErrorStatus deactivateOsnapMode(const GCHAR* sMode) = 0;

  virtual OdBool modeIsActive(const GCHAR* sMode) = 0;

  virtual int osnapGlyphSize() const = 0;

};

GCDB_DLL_DECL GcDbCustomOsnapManager* gcdbCustomOsnapManager();

extern "C" GCED_DLL_DECL bool gcedIsOsnapOverride();

#pragma pack (pop)

#endif  // ODDB_OSNAP_H

