/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCDB_DBDWFHOST_H
#define GCDB_DBDWFHOST_H

#include "dbmain.h"
#include "GcString.h"

#pragma pack (push, 8)

class GcImpUnderlayLayer;
class IGcReadStream;
class GCBASE_PORT GcUnderlayLayer
{
public:
  GcUnderlayLayer();
  ~GcUnderlayLayer();
  GcUnderlayLayer(GcUnderlayLayer const &);

  GcUnderlayLayer const & operator= (GcUnderlayLayer const &);

  friend bool operator == (GcUnderlayLayer const & l, GcUnderlayLayer const & r);

  typedef enum {
    kOff = 0,
    kOn = 1
  } State;

  GcString name() const;
  State state() const;
  Gcad::ErrorStatus setName(const GcString& name);
  Gcad::ErrorStatus setState(State state);

private:
  GcImpUnderlayLayer* m_pImpUnderlayLayer;
};

struct GcDbUnderlayDrawContext
{
  Gsoft::UInt8 contrast;
  Gsoft::UInt8 fade;
  bool monochrome;
  bool adjustColorForBackground;
  GcUnderlayLayer** pLayers;
};

const int kItemVersionNumber = 1;

class GSOFT_NO_VTABLE GCBASE_PORT GcDbUnderlayItem
{
public:
  virtual ~GcDbUnderlayItem() = 0;
  virtual GcString getName() const = 0;
  virtual Gcad::ErrorStatus getThumbnail(BITMAPINFO*& thumbnail) const = 0;
  virtual Gcad::ErrorStatus getExtents(GcGePoint2d& min, GcGePoint2d& max) const = 0;
  virtual GcDb::UnitsValue getUnits() const = 0;
  virtual bool usingPartialContent() const = 0;
  virtual Gcad::ErrorStatus draw(GcGiWorldDraw* pWorldDraw,
    GcGiViewportDraw* pViewportDraw,
    const GcDbUnderlayDrawContext& context) const = 0;
  virtual GcGeMatrix3d modelTransform() const = 0;
  virtual Gcad::ErrorStatus getOsnapPoints(const GcGeMatrix3d& modelToWorld,
    GcDb::OsnapMode osnapMode,
    Gsoft::GsMarker   gsSelectionMark,
    const GcGePoint3d&  pickPoint,
    const GcGePoint3d&  lastPoint,
    const GcGeMatrix3d& viewXform,
    GcGePoint3dArray&      snapPoints,
    GcDbIntArray &   geomIds)
    const = 0;
  virtual GcDbEntity* getSubEntityAtGsMarker(const GcGeMatrix3d& modelToWorld, Gsoft::GsMarker gsSelectionMark) const = 0;
  virtual Gcad::ErrorStatus intersectWith(const GcGeMatrix3d& modelToWorld,
    const GcDbEntity* pEnt,
    GcDb::Intersect intType,
    const GcGePlane* projPlane,
    GcGePoint3dArray& points,
    Gsoft::GsMarker thisGsMarker,
    Gsoft::GsMarker otherGsMarker) const = 0;

  virtual Gsoft::UInt32 underlayLayerCount() const { return 0; }
  virtual Gcad::ErrorStatus getUnderlayLayer(int, GcUnderlayLayer&) const {
    return Gcad::eNotImplemented;
  }
  int version() const;
};

class GSOFT_NO_VTABLE GCDB_PORT GcDbDgnUnderlayItem : public GcDbUnderlayItem
{
public:
  virtual bool useMasterUnits() const = 0;
  virtual void setUseMasterUnits(bool bUseMasterUnits) = 0;
  virtual bool showRasterRef() const = 0;
  virtual void setShowRasterRef(bool bShow) = 0;
};

class GSOFT_NO_VTABLE GCDB_PORT GcDbUnderlayFile
{
public:
  virtual ~GcDbUnderlayFile() = 0;
  virtual int getItemCount() const = 0;
  virtual Gcad::ErrorStatus getItem(int i, GcDbUnderlayItem*& pItem) const = 0;
  virtual Gcad::ErrorStatus getItem(const GCHAR* name, GcDbUnderlayItem*& pItem) const = 0;
};

class GSOFT_NO_VTABLE GCDB_PORT GcDbUnderlayHost
{
public:
  virtual Gcad::ErrorStatus getFile(
    const GCHAR* fullPath,
    const wchar_t* password,
    GcDbUnderlayFile*& pFile) const = 0;
  virtual Gcad::ErrorStatus getFile(
    IGcReadStream* pFileStream,
    const wchar_t* password,
    GcDbUnderlayFile*& pFile) const = 0;

  static void getAdjustedColor(
    GcGeVector3d& rgbResult,
    const GcGeVector3d& rgbInputColor,
    const GcGeVector3d& rgbCurrentBackgroundColor,
    const GcGeVector3d& hslFadedContrastColor,
    const GcDbUnderlayDrawContext& drawContext);
protected:
  virtual ~GcDbUnderlayHost() = 0;
};
GCDB_PORT GcDbUnderlayHost* gcdbGetCurrentDwfHost();
GCDB_PORT GcDbUnderlayHost* gcdbSetCurrentDwfHost(GcDbUnderlayHost* pHost);
GCDB_PORT GcDbUnderlayHost* gcdbGetCurrentDgnHost();
GCDB_PORT GcDbUnderlayHost* gcdbSetCurrentDgnHost(GcDbUnderlayHost* pHost);
GCDB_PORT GcDbUnderlayHost* gcdbGetCurrentDgnDocHost();
GCDB_PORT GcDbUnderlayHost* gcdbSetCurrentDgnDocHost(GcDbUnderlayHost* pHost);
GCDB_PORT void              gcdbConvertRgbToHsl(const GcGeVector3d& rgb, GcGeVector3d& hsl);
GCDB_PORT void              gcdbConvertHslToRgb(const GcGeVector3d& hsl, GcGeVector3d& rgb);
GCDB_PORT bool              gcdbIsDgnToDwgInProgress();
GCDB_PORT GcDbUnderlayHost* gcdbGetCurrentPdfHost();
GCDB_PORT GcDbUnderlayHost* gcdbSetCurrentPdfHost(GcDbUnderlayHost* pHost);

#pragma pack (pop)

#endif