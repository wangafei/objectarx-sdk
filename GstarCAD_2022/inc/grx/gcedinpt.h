#pragma once

#include "gcadstd.h"
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

class GcEdInputPointManager
{
public:
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

  virtual int mouseHasMoved() const
  {
    throw OdError(eNotImplemented);
    return 0;
  }

  virtual Gcad::ErrorStatus turnOnSubentityWindowSelection() = 0;
  virtual Gcad::ErrorStatus turnOffSubentityWindowSelection() = 0;

  virtual Gcad::ErrorStatus addSubSelectFilter(GcEdSubSelectFilter* pSSSubFilter) = 0;
  virtual Gcad::ErrorStatus removeSubSelectFilter(GcEdSubSelectFilter* pSSSubFilter) = 0;

  virtual void resetOsnap() = 0;
};

#ifdef GCED_EXPORTS
#define GCEDCLASSDECL _declspec(dllexport)
#else
#define GCEDCLASSDECL
#endif

class GcEdImpInputPointFilterResult;
class GcEdImpInputPointManager;

class GCEDCLASSDECL GcEdInputPoint
{
private:
  GcEdImpInputPointManager* m_pImpMgr;

  GcEdInputPoint(GcEdImpInputPointManager* pImpMgr);
  GcEdInputPoint& operator=(const GcEdInputPoint&);

public:
  GcApDocument*                            document() const;
  bool                                     pointComputed() const;
  int                                      history() const;
  const GcGePoint3d&                       lastPoint() const;
  const GcGePoint3d&                       rawPoint() const;
  const GcGePoint3d&                       grippedPoint() const;
  const GcGePoint3d&                       cartesianSnappedPoint() const;
  const GcGePoint3d&                       osnappedPoint() const;
  const GcDb::OsnapMask                    osnapMask() const;
  const GcArray<GcDbCustomOsnapMode*>&     customOsnapModes() const;
  const GcDb::OsnapMask                    osnapOverrides() const;
  const GcArray<GcDbCustomOsnapMode*>&     customOsnapOverrides() const;
  const GcArray<GcDbObjectId>&             pickedEntities() const;
  const GcArray< GcDbObjectIdArray,        GcArrayObjectCopyReallocator< GcDbObjectIdArray > >& 
    nestedPickedEntities() const;
  const GcArray<Hccad::GsMarker>&          gsSelectionMark() const;
  const GcArray<GcDbObjectId>&             keyPointEntities() const;
  const GcArray< GcDbObjectIdArray,        GcArrayObjectCopyReallocator< GcDbObjectIdArray > >& 
    nestedKeyPointEntities() const;
  const GcArray<Hccad::GsMarker>&          keyPointGsSelectionMark() const;
  const GcArray<GcGeCurve3d*>&             alignmentPaths() const;
  const GcGePoint3d&                       computedPoint() const;
  const GCHAR*                             tooltipString() const;
  GcGiViewportDraw*                        drawContext() const;

  friend class GcEdImpInputPointManager;
};

class GCEDCLASSDECL GcEdInputPointFilterResult
{
private:
  GcEdImpInputPointFilterResult* m_pImp;

  GcEdInputPointFilterResult();
  GcEdInputPointFilterResult& operator=(const GcEdInputPointFilterResult&);

public:
  ~GcEdInputPointFilterResult();

  void                             setNewPoint(const GcGePoint3d& newValue);
  void                             setDisplayOsnapGlyph(bool newValue);
  void                             setNewTooltipString(const GCHAR* newValue);
  void                             setRetry(bool newValue);

  const GcGePoint3d&               newPoint() const;
  bool                             displayOsnapGlyph() const;
  const GCHAR*                     newTooltipString() const;
  bool                             retry() const;

  friend class GcEdImpInputPointManager;
};

class GcEdImpInputPointMonitorResult;
class GCEDCLASSDECL GcEdInputPointMonitorResult
{
private:
  GcEdImpInputPointMonitorResult* m_pImp; 

  GcEdInputPointMonitorResult();
  GcEdInputPointMonitorResult& operator=(const GcEdInputPointMonitorResult&);

public:
  ~GcEdInputPointMonitorResult();

  void         setAdditionalTooltipString(const GCHAR*);

  bool         appendToTooltipStr() const;
  const GCHAR* additionalTooltipString() const;

  friend class GcEdImpInputPointManager;
};

class GCEDCLASSDECL GcEdInputPointFilter : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(GcEdInputPointFilter);

  virtual Gcad::ErrorStatus processInputPoint(
    bool&                            changedPoint,
    OdGePoint3d&                     newPoint,
    bool&                            displayOsnapGlyph,
    bool&                            changedTooltipStr,
    GCHAR*&                          newTooltipString,
    bool&                            retry,
    OdGiViewportDraw*                drawContext,
    GcApDocument*                    document,
    bool                             pointComputed,
    int                              history,
    const OdGePoint3d&               lastPoint,
    const OdGePoint3d&               rawPoint,
    const OdGePoint3d&               grippedPoint,
    const OdGePoint3d&               cartesianSnappedPoint,
    const OdGePoint3d&               osnappedPoint,
    GcDb::OsnapMask                  osnapMask,
    const OdArray<GcDbCustomOsnapMode*>& customOsnapModes,
    GcDb::OsnapMask                  osnapOverrides,
    const OdArray<GcDbCustomOsnapMode*>& customOsnapOverrides,
    const OdArray<OdDbObjectId>&     pickedEntities,
    const OdArray<GcDbObjectIdArray, OdObjectsAllocator<GcDbObjectIdArray > >& nestedPickedEntities,
    const OdArray<Hccad::GsMarker>&  gsSelectionMark,
    const OdArray<OdDbObjectId>&     keyPointEntities,
    const OdArray<GcDbObjectIdArray, OdObjectsAllocator<GcDbObjectIdArray > >& nestedKeyPointEntities,
    const OdArray<Hccad::GsMarker>&  keyPointGsSelectionMark,
    const OdArray<OdGeCurve3d*>&     alignmentPaths,
    const OdGePoint3d&               computedPoint,
    const GCHAR*                     tooltipString) { return Oda::eOk; }

  virtual Gcad::ErrorStatus processInputPoint(const GcEdInputPoint& input, GcEdInputPointFilterResult& output);

  virtual GcEdInputPointFilter* revokeInputFilter	(GcEdInputPointFilter* revokedFilter) { return this; }
};

class GCEDCLASSDECL GcEdInputPointMonitor : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(GcEdInputPointMonitor);

  virtual Gcad::ErrorStatus monitorInputPoint(
    bool&                                appendToTooltipStr,
    GCHAR*&                              additionalTooltipString,
    OdGiViewportDraw*                    drawContext,
    GcApDocument*                        document,
    bool                                 pointComputed,
    int                                  history,
    const OdGePoint3d&                   lastPoint,
    const OdGePoint3d&                   rawPoint,
    const OdGePoint3d&                   grippedPoint,
    const OdGePoint3d&                   cartesianSnappedPoint,
    const OdGePoint3d&                   osnappedPoint,
    GcDb::OsnapMask                      osnapMask,
    const OdArray<GcDbCustomOsnapMode*>& customOsnapModes,
    GcDb::OsnapMask                      osnapOverrides,
    const OdArray<GcDbCustomOsnapMode*>& customOsnapOverrides,
    const OdArray<OdDbObjectId>&         apertureEntities,
    const OdArray<GcDbObjectIdArray, OdObjectsAllocator<GcDbObjectIdArray > >& nestedApertureEntities,
    const OdArray<Hccad::GsMarker>&      gsSelectionMark,
    const OdArray<OdDbObjectId>&         keyPointEntities,
    const OdArray<GcDbObjectIdArray, OdObjectsAllocator<GcDbObjectIdArray > >& nestedKeyPointEntities,
    const OdArray<Hccad::GsMarker>&      keyPointGsSelectionMark,
    const OdArray<OdGeCurve3d*>&         alignmentPaths,
    const OdGePoint3d&                   computedPoint,
    const GCHAR*                         tooltipString) { return Oda::eOk; }

  virtual Gcad::ErrorStatus monitorInputPoint(const GcEdInputPoint& input, GcEdInputPointMonitorResult& output);

  virtual bool excludeFromOsnapCalculation (const OdArray<OdDbObjectId>& nestedEntity,Hccad::GsMarker gsSelectionMark) { return false; }
};

class GcEdInputContextReactor
{
public:
  virtual void beginGetPoint(const OdGePoint3d* pointIn,const GCHAR* promptString,int   initGetFlags,const GCHAR* pKeywords) { }
  virtual void endGetPoint(Gcad::PromptStatus returnStatus,const OdGePoint3d& pointOut,const GCHAR*& pKeyword) { }

  virtual void beginGetAngle(const OdGePoint3d* pointIn,const GCHAR* promptString,int   initGetFlags,const GCHAR* pKeywords) { }
  virtual void endGetAngle(Gcad::PromptStatus returnStatus,double& angle,const GCHAR*& pKeyword) { }

  virtual void beginGetDistance(const OdGePoint3d* pointIn,const GCHAR* promptString,int   initGetFlags,const GCHAR* pKeywords) { }
  virtual void endGetDistance(Gcad::PromptStatus returnStatus,double& distance,const GCHAR*& pKeyword) { }

  virtual void beginGetOrientation(const OdGePoint3d* pointIn,const GCHAR* promptString,int   initGetFlags,const GCHAR* pKeywords) { }
  virtual void endGetOrientation(Gcad::PromptStatus returnStatus,double& angle,const GCHAR*& pKeyword) { }

  virtual void beginGetCorner(const OdGePoint3d* firstCorner,const GCHAR* promptString,int   initGetFlags,const GCHAR* pKeywords) { }
  virtual void endGetCorner(Gcad::PromptStatus returnStatus,OdGePoint3d& secondCorner,const GCHAR*& pKeyword) { }

  virtual void beginGetScaleFactor(const OdGePoint3d* pointIn,const GCHAR* promptString,int   initGetFlags,const GCHAR* pKeywords) { }
  virtual void endGetScaleFactor(Gcad::PromptStatus returnStatus,double& distance,const GCHAR*& pKeyword) { }

  virtual void beginGetString(const GCHAR* promptString,int   initGetFlags) { }
  virtual void endGetString (Gcad::PromptStatus returnStatus,GCHAR* pString) { }

  virtual void beginGetKeyword(const GCHAR* promptString,int   initGetFlags,const GCHAR* pKeywords) { }
  virtual void endGetKeyword (Gcad::PromptStatus returnStatus,const GCHAR*& pKeyword) { }

  virtual void beginGetInteger(const int* dfault,	const GCHAR* promptString,int   initGetFlags,const GCHAR* pKeywords) { }
  virtual void endGetInteger(Gcad::PromptStatus returnStatus,int& retValue,const GCHAR*& pKeyword) { }

  virtual void beginGetColor(const int* dfault,const GCHAR* promptString,int   initGetFlags,const GCHAR* pKeywords) { }
  virtual void endGetColor(Gcad::PromptStatus returnStatus,int& retValue,const GCHAR*& pKeyword) { }

  virtual void beginGetReal(const double* dfault,const GCHAR* promptString,int   initGetFlags,const GCHAR* pKeywords) { }
  virtual void endGetReal(Gcad::PromptStatus returnStatus,double& returnValue,const GCHAR*& pKeyword) { }

  virtual void beginEntsel(const GCHAR* promptString,int   initGetFlags,const GCHAR* pKeywords) { }
  virtual void endEntsel(Gcad::PromptStatus returnStatus,OdDbObjectId& entPicked,OdGePoint3d& pickPoint,const GCHAR* pKeyword) { }

  virtual void beginNentsel(const GCHAR*    promptString,Hccad::Boolean pickFlag,int initGetFlags,const GCHAR*    pKeywords) { }
  virtual void endNentsel(Gcad::PromptStatus returnStatus,OdDbObjectId entPicked,const OdGePoint3d&  pickPoint,const OdGeMatrix3d& xform,const resbuf* referenceStack,const GCHAR*   pKeyword) { }

  virtual void beginSSGet(const GCHAR*  pPrompt,int initGetFlags,const GCHAR*  pKeywords,const GCHAR*  pSSControls,const OdArray<OdGePoint3d>& points,const resbuf* entMask) { }
  virtual void endSSGet(Gcad::PromptStatus returnStatus,const OdArray<OdDbObjectId>& ss) { }

  virtual void beginDragSequence(const GCHAR*  promptString) { }
  virtual void endDragSequence(Gcad::PromptStatus returnStatus,OdGePoint3d&  pickPoint,OdGeVector3d& vec) { }

  virtual void beginQuiescentState() { }
  virtual void endQuiescentState() { }
};

#pragma pack (pop)