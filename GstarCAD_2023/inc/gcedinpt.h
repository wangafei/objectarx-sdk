/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GCEDINPT_H
#define _GCEDINPT_H

#include "rxobject.h"
#include "dbmain.h"
#pragma pack (push, 8)

#pragma warning (disable: 4786)

class GcEdInputPointFilter;
class GcEdInputPointMonitor;
class GcApDocument;
class GcEdInputContextReactor;
class GcDbCustomOsnapMode;
class GcEdSubSelectFilter;

class GcEdInputPoint;
class GcEdInputPointFilterResult;
class GcEdInputPointMonitorResult;

class GcGeCurve3d;
class GcGeMatrix3d;
class GcGePoint3d;
class GcGeVector3d;

class GcEdInputPointManager
{
public:
  virtual ~GcEdInputPointManager() { }

  virtual Gcad::ErrorStatus     registerPointFilter(GcEdInputPointFilter* pFilter) = 0;
  virtual Gcad::ErrorStatus     revokePointFilter() = 0;
  virtual GcEdInputPointFilter* currentPointFilter() const = 0;

  virtual Gcad::ErrorStatus addPointMonitor(GcEdInputPointMonitor* pMonitor) = 0;
  virtual Gcad::ErrorStatus removePointMonitor(GcEdInputPointMonitor* pMonitor) = 0;

  virtual Gcad::ErrorStatus addInputContextReactor(GcEdInputContextReactor* pReactor) = 0;
  virtual Gcad::ErrorStatus removeInputContextReactor(GcEdInputContextReactor* pReact) = 0;

  virtual Gcad::ErrorStatus disableSystemCursorGraphics() = 0;
  virtual Gcad::ErrorStatus enableSystemCursorGraphics() = 0;

  virtual int systemCursorDisableCount() const = 0;

  virtual Gcad::ErrorStatus turnOnForcedPick() = 0;
  virtual Gcad::ErrorStatus turnOffForcedPick() = 0;
  virtual int forcedPickCount() const = 0;

  virtual int mouseHasMoved() const = 0;

  virtual Gcad::ErrorStatus turnOnSubentityWindowSelection() = 0;
  virtual Gcad::ErrorStatus turnOffSubentityWindowSelection() = 0;

  virtual void enableMultiSubentPathSelection(bool bEnable) = 0;

  virtual Gcad::ErrorStatus addSubSelectFilter(
    GcEdSubSelectFilter* pSSSubFilter) = 0;
  virtual Gcad::ErrorStatus removeSubSelectFilter(
    GcEdSubSelectFilter* pSSSubFilter) = 0;
};

class GcEdImpInputPointFilterResult;
class GcEdImpInputPointManager;

#ifndef _GSOFT_MAC_
#ifndef GCAD_PORT
#ifdef GCAD_API
#include "gsoft.h"
#define GCAD_PORT GSOFT_EXPORT
#else
#define GCAD_PORT
#endif
#endif
#else
#undef GCAD_PORT
#define GCAD_PORT
#endif 

class GcEdInputPoint
{
private:
  GcEdImpInputPointManager* m_pImpMgr;
  GcEdInputPoint(GcEdImpInputPointManager* pImpMgr);
  GcEdInputPoint & operator=(const GcEdInputPoint&);
public:
  GCCORE_PORT GcApDocument*                            document() const;
  GCCORE_PORT bool                                     pointComputed() const;
  GCCORE_PORT int                                      history() const;
  GCCORE_PORT const GcGePoint3d&                       lastPoint() const;
  GCCORE_PORT const GcGePoint3d&                       rawPoint() const;
  GCCORE_PORT const GcGePoint3d&                       grippedPoint() const;
  GCCORE_PORT const GcGePoint3d&                       cartesianSnappedPoint() const;
  GCCORE_PORT const GcGePoint3d&                       osnappedPoint() const;
  GCCORE_PORT const GcDb::OsnapMask                    osnapMask() const;
  GCCORE_PORT const GcArray<GcDbCustomOsnapMode*>&     customOsnapModes() const;
  GCCORE_PORT const GcDb::OsnapMask                    osnapOverrides() const;
  GCCORE_PORT const GcArray<GcDbCustomOsnapMode*>&     customOsnapOverrides() const;
  GCCORE_PORT const GcArray<GcDbObjectId>&             pickedEntities() const;
  GCCORE_PORT const GcArray< GcDbObjectIdArray, GcArrayObjectCopyReallocator< GcDbObjectIdArray > >&
    nestedPickedEntities() const;
  GCCORE_PORT const GcArray<Gsoft::GsMarker>&          gsSelectionMark() const;
  GCCORE_PORT const GcArray<GcDbObjectId>&             keyPointEntities() const;
  GCCORE_PORT const GcArray< GcDbObjectIdArray, GcArrayObjectCopyReallocator< GcDbObjectIdArray > >&
    nestedKeyPointEntities() const;
  GCCORE_PORT const GcArray<Gsoft::GsMarker>&          keyPointGsSelectionMark() const;
  GCCORE_PORT const GcArray<GcGeCurve3d*>&             alignmentPaths() const;
  GCCORE_PORT const GcGePoint3d&                       computedPoint() const;
  GCCORE_PORT const GCHAR*                             tooltipString() const;
  GCCORE_PORT GcGiViewportDraw*                        drawContext() const;

  friend class GcEdImpInputPointManager;
};

class  GcEdInputPointFilterResult
{
private:
  GcEdImpInputPointFilterResult* m_pImp;
  GcEdInputPointFilterResult();
  GcEdInputPointFilterResult& operator=(const GcEdInputPointFilterResult&);
public:
  GCCORE_PORT ~GcEdInputPointFilterResult();
  GCCORE_PORT void                             setNewPoint(const GcGePoint3d& newValue);
  GCCORE_PORT void                             setDisplayOsnapGlyph(bool newValue);
  GCCORE_PORT void                             setNewTooltipString(const GCHAR* newValue);
  GCCORE_PORT void                             setRetry(bool newValue);
  GCCORE_PORT const GcGePoint3d&               newPoint() const;
  GCCORE_PORT bool                             displayOsnapGlyph() const;
  GCCORE_PORT const GCHAR*                     newTooltipString() const;
  GCCORE_PORT bool                       retry() const;

  friend class GcEdImpInputPointManager;
};

class GcEdImpInputPointMonitorResult;
class GcEdInputPointMonitorResult
{
private:
  GcEdImpInputPointMonitorResult* m_pImp;
  GcEdInputPointMonitorResult();
  GcEdInputPointMonitorResult& operator=(const GcEdInputPointMonitorResult&);
public:
  GCCORE_PORT ~GcEdInputPointMonitorResult();
  GCCORE_PORT void setAdditionalTooltipString(const GCHAR*);
  GCCORE_PORT bool appendToTooltipStr() const;
  GCCORE_PORT const GCHAR* additionalTooltipString() const;

  friend class GcEdImpInputPointManager;
};
class GCCORE_PORT GcEdInputPointFilter : public GcRxObject
{

public:
  GCRX_DECLARE_MEMBERS(GcEdInputPointFilter);

  GSOFT_DEPRECATED virtual Gcad::ErrorStatus processInputPoint(
    bool&,
    GcGePoint3d&,
    bool&,
    bool&,
    GCHAR*&,
    bool&,
    GcGiViewportDraw*,
    GcApDocument*,
    bool,
    int,
    const GcGePoint3d&,
    const GcGePoint3d&,
    const GcGePoint3d&,
    const GcGePoint3d&,
    const GcGePoint3d&,
    GcDb::OsnapMask,
    const GcArray<GcDbCustomOsnapMode*>&,
    GcDb::OsnapMask,
    const GcArray<GcDbCustomOsnapMode*>&,
    const GcArray<GcDbObjectId>&,
    const GcArray< GcDbObjectIdArray, GcArrayObjectCopyReallocator< GcDbObjectIdArray > >&,
    const GcArray<Gsoft::GsMarker>&,
    const GcArray<GcDbObjectId>&,
    const GcArray< GcDbObjectIdArray, GcArrayObjectCopyReallocator< GcDbObjectIdArray > >&,
    const GcArray<Gsoft::GsMarker>&,
    const GcArray<GcGeCurve3d*>&,
    const GcGePoint3d&,
    const GCHAR*)
  {
    return Gcad::eOk;
  }

  virtual Gcad::ErrorStatus processInputPoint(const GcEdInputPoint& input, GcEdInputPointFilterResult& output);

  virtual GcEdInputPointFilter* revokeInputFilter
  (GcEdInputPointFilter*) {
    return this;
  }
};

class GCCORE_PORT GcEdInputPointMonitor : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcEdInputPointMonitor);
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus monitorInputPoint(
    bool&,
    GCHAR*&,
    GcGiViewportDraw*,
    GcApDocument*,
    bool,
    int,
    const GcGePoint3d&,
    const GcGePoint3d&,
    const GcGePoint3d&,
    const GcGePoint3d&,
    const GcGePoint3d&,
    GcDb::OsnapMask,
    const GcArray<GcDbCustomOsnapMode*>&,
    GcDb::OsnapMask,
    const GcArray<GcDbCustomOsnapMode*>&,
    const GcArray<GcDbObjectId>&,
    const GcArray< GcDbObjectIdArray, GcArrayObjectCopyReallocator< GcDbObjectIdArray > >&,
    const GcArray<Gsoft::GsMarker>&,
    const GcArray<GcDbObjectId>&,
    const GcArray< GcDbObjectIdArray, GcArrayObjectCopyReallocator< GcDbObjectIdArray > >&,
    const GcArray<Gsoft::GsMarker>&,
    const GcArray<GcGeCurve3d*>&,
    const GcGePoint3d&,
    const GCHAR*)
  {
    return Gcad::eOk;
  }

  virtual Gcad::ErrorStatus monitorInputPoint(const GcEdInputPoint& input, GcEdInputPointMonitorResult& output);

  virtual bool
    excludeFromOsnapCalculation(const GcArray<GcDbObjectId>&,
      Gsoft::GsMarker)
  {
    return false;
  }
};

class GcEdInputContextReactor
{
public:
  virtual ~GcEdInputContextReactor() { }

  virtual void beginGetPoint(const GcGePoint3d*,
    const GCHAR*,
    int,
    const GCHAR*) { }
  virtual void endGetPoint(Gcad::PromptStatus,
    const GcGePoint3d&,
    const GCHAR*&) { }

  virtual void beginGetAngle(const GcGePoint3d*,
    const GCHAR*,
    int,
    const GCHAR*) { }
  virtual void endGetAngle(Gcad::PromptStatus,
    double&,
    const GCHAR*&) { }

  virtual void beginGetDistance(const GcGePoint3d*,
    const GCHAR*,
    int,
    const GCHAR*) { }
  virtual void endGetDistance(Gcad::PromptStatus,
    double&,
    const GCHAR*&) { }

  virtual void beginGetOrientation(const GcGePoint3d*,
    const GCHAR*,
    int,
    const GCHAR*) { }
  virtual void endGetOrientation(Gcad::PromptStatus,
    double&,
    const GCHAR*&) { }

  virtual void beginGetCorner(const GcGePoint3d*,
    const GCHAR*,
    int,
    const GCHAR*) { }
  virtual void endGetCorner(Gcad::PromptStatus,
    GcGePoint3d&,
    const GCHAR*&) { }

  virtual void beginGetScaleFactor(const GcGePoint3d*,
    const GCHAR*,
    int,
    const GCHAR*) { }
  virtual void endGetScaleFactor(Gcad::PromptStatus,
    double&,
    const GCHAR*&) { }

  virtual void beginGetString(const GCHAR*,
    int) { }
  virtual void endGetString(Gcad::PromptStatus,
    GCHAR*) { }

  virtual void beginGetKeyword(const GCHAR*,
    int,
    const GCHAR*) { }
  virtual void endGetKeyword(Gcad::PromptStatus,
    const GCHAR*&) { }

  virtual void beginGetInteger(const int*,
    const GCHAR*,
    int,
    const GCHAR*) { }
  virtual void endGetInteger(Gcad::PromptStatus,
    int&,
    const GCHAR*&) { }

  virtual void beginGetColor(const int*,
    const GCHAR*,
    int,
    const GCHAR*) { }
  virtual void endGetColor(Gcad::PromptStatus,
    int&,
    const GCHAR*&) { }
  virtual void beginGetReal(const double*,
    const GCHAR*,
    int,
    const GCHAR*) { }

  virtual void endGetReal(Gcad::PromptStatus,
    double&,
    const GCHAR*&) { }

  virtual void beginEntsel(const GCHAR*,
    int,
    const GCHAR*) { }
  virtual void endEntsel(Gcad::PromptStatus,
    GcDbObjectId&,
    GcGePoint3d&,
    const GCHAR*) { }

  virtual void beginNentsel(const GCHAR*,
    Gsoft::Boolean,
    int,
    const GCHAR*) { }
  virtual void endNentsel(Gcad::PromptStatus,
    GcDbObjectId,
    const GcGePoint3d&,
    const GcGeMatrix3d&,
    const resbuf*,
    const GCHAR*) { }

  virtual void beginSSGet(const GCHAR*,
    int,
    const GCHAR*,
    const GCHAR*,
    const GcArray<GcGePoint3d>&,
    const resbuf*) { }
  virtual void endSSGet(Gcad::PromptStatus,
    const GcArray<GcDbObjectId>&) { }

  virtual void beginDragSequence(const GCHAR*) { }
  virtual void endDragSequence(Gcad::PromptStatus,
    GcGePoint3d&,
    GcGeVector3d&) { }

  virtual void beginQuiescentState() { }
  virtual void endQuiescentState() { }
};

#pragma pack (pop)
#endif  