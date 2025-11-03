/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBGRIP_H
#define GD_DBGRIP_H

#include "gcdb.h"
#include "gcarray.h"
#include "dbDimData.h"

class GcGiViewport;
class GcDbEntity;
class GcDbGripData;
class GcGiWorldDraw;
class GcGiViewportDraw;
class GcDbCustomOsnapMode;

#include "dbgripoperations.h"

typedef GcArray<GcDbGripData*, GcArrayMemCopyReallocator<GcDbGripData*> > GcDbGripDataPtrArray;
typedef GcArray<GcDbGripData, GcArrayObjectCopyReallocator<GcDbGripData> > GcDbGripDataArray;

typedef GcDbGripOperations::ReturnValue(*GripOperationPtr)(GcDbGripData* pThis,
  const GcDbObjectId& entId, int contextFlags);

typedef void(*ContextMenuItemIndexPtr)(unsigned int itemIndex);

typedef GcDbGripOperations::ReturnValue(*GripRtClkHandler)(GcDbGripDataArray& hotGrips,
  const GcDbObjectIdArray& ents, GCHAR *& menuName, HMENU& menu,
  ContextMenuItemIndexPtr& cb);

typedef GcDbGripOperations::ReturnValue(*GripRightClickHandler)(GcDbGripDataArray& hotGrips,
  const GcDbObjectIdArray& ents, GcRxObject*& handler);

typedef bool(*GripWorldDrawPtr)(GcDbGripData* pThis, GcGiWorldDraw* pWd,
  const GcDbObjectId& entId, GcDbGripOperations::DrawType type,
  GcGePoint3d* imageGripPoint, double dGripSize);

typedef void(*GripViewportDrawPtr)(GcDbGripData* pThis, GcGiViewportDraw* pWd,
  const GcDbObjectId& entId, GcDbGripOperations::DrawType type,
  GcGePoint3d* imageGripPoint, int gripSize);

typedef void(*GripOpStatusPtr)(GcDbGripData* pThis, const GcDbObjectId& entId,
  GcDbGripOperations::GripStatus stat);

typedef const GCHAR * (*GripToolTipPtr)(GcDbGripData* pThis);

typedef const GCHAR * (*GripCLIPromptPtr)(GcDbGripData* pThis);

typedef const GCHAR * (*GripCLIDisplayStringPtr)(GcDbGripData* pThis);

typedef void(*GripDimensionPtr)(GcDbGripData* pThis, const GcDbObjectId& entId,
  double dimScale, GcDbDimDataPtrArray& dimData);

typedef GcDbGripOperations::ReturnValue(*GripInputPointPtr)(
  GcDbGripData* pThis, const GcDbObjectId& entId, bool& changedPoint,
  GcGePoint3d& newPoint, const GcGiViewport& viewContext,
  const GcDbObjectId& viewportId, bool pointComputed, int history,
  const GcGePoint3d& lastPoint, const GcGePoint3d& rawPoint,
  const GcGePoint3d& grippedPoint, const GcGePoint3d& cartesianSnappedPoint,
  const GcGePoint3d& osnappedPoint, GcDb::OsnapMask osnapMask,
  const GcArray<GcDbCustomOsnapMode*>& customOsnapModes,
  GcDb::OsnapMask osnapOverrides,
  const GcArray<GcDbCustomOsnapMode*>& customOsnapOverrides,
  const GcArray<GcDbObjectId>& pickedEntities,
  const GcArray< GcDbObjectIdArray,
  GcArrayObjectCopyReallocator< GcDbObjectIdArray > >& nestedPickedEntities,
  const GcArray<Gsoft::GsMarker>& gsSelectionMark,
  const GcArray<GcDbObjectId>& keyPointEntities,
  const GcArray< GcDbObjectIdArray,
  GcArrayObjectCopyReallocator< GcDbObjectIdArray > >& nestedKeyPointEntities,
  const GcArray<Gsoft::GsMarker>& keyPointGsSelectionMark,
  const GcArray<GcGeCurve3d*>& alignmentPaths, const GcGePoint3d& computedPoint);

class GcDbGripData {
public:
  GcDbGripData();
  GcDbGripData(const GcGePoint3d&, void*, GripOperationPtr hotGrip = NULL,
    GripOperationPtr hoverGrip = NULL, GripRtClkHandler RtClk = NULL,
    GripWorldDrawPtr wd = NULL, GripViewportDrawPtr vd = NULL,
    GripOpStatusPtr stat = NULL, GripToolTipPtr tt = NULL,
    GripDimensionPtr hoverDim = NULL, GripDimensionPtr hotGripDim = NULL,
    unsigned int bitFlags = 0,
    GcGePoint3d* altBasePt = NULL, GripInputPointPtr inputPointFunc = NULL);
  GcDbGripData(const GcGePoint3d&, void*, GcRxClass*,
    GripOperationPtr hotGrip = NULL,
    GripOperationPtr hoverGrip = NULL, GripRtClkHandler RtClk = NULL,
    GripWorldDrawPtr wd = NULL, GripViewportDrawPtr vd = NULL,
    GripOpStatusPtr stat = NULL, GripToolTipPtr tt = NULL,
    GripDimensionPtr hoverDim = NULL, GripDimensionPtr hotGripDim = NULL,
    unsigned int bitFlags = 0,
    GcGePoint3d* altBasePt = NULL, GripInputPointPtr inputPointFunc = NULL);
  ~GcDbGripData() {}
  GcDbGripData(const GcDbGripData&);
  GcDbGripData& operator = (const GcDbGripData&);

  void setAllData(const GcGePoint3d&, void*,
    GripOperationPtr hotGrip = NULL, GripOperationPtr hoverGrip = NULL,
    GripRtClkHandler RtClk = NULL, GripWorldDrawPtr wd = NULL,
    GripViewportDrawPtr vd = NULL, GripOpStatusPtr stat = NULL,
    GripToolTipPtr tt = NULL, GripDimensionPtr hoverDim = NULL,
    GripDimensionPtr hotGripDim = NULL,
    unsigned int bitFlags = 0, GcGePoint3d* altBasePt = NULL,
    GripInputPointPtr inputPointFunc = NULL,
    GcRxClass* appDataGcRxClass = NULL);

  const GcGePoint3d&        gripPoint() const;
  void                      setGripPoint(const GcGePoint3d& pt);
  void*                     appData() const;
  void                      setAppData(void* appData);
  GcRxClass*                appDataGcRxClass() const;
  void                      setAppDataGcRxClass(GcRxClass* pClass);
  GripOperationPtr          hotGripFunc() const;
  void                      setHotGripFunc(GripOperationPtr pFunc);
  GripOperationPtr          hoverFunc() const;
  void                      setHoverFunc(GripOperationPtr pFunc);
  GripRtClkHandler          rtClk() const;
  void                      setRtClk(GripRtClkHandler pFunc);
  GripRightClickHandler     righClick() const;
  void                      setRightClick(GripRightClickHandler pFunc);
  GripWorldDrawPtr          worldDraw() const;
  void                      setWorldDraw(GripWorldDrawPtr pFunc);
  GripViewportDrawPtr       viewportDraw() const;
  void                      setViewportDraw(GripViewportDrawPtr pFunc);
  GripOpStatusPtr           gripOpStatFunc() const;
  void                      setGripOpStatFunc(GripOpStatusPtr pFunc);
  GripToolTipPtr            toolTipFunc() const;
  void                      setToolTipFunc(GripToolTipPtr pFunc);
  GripDimensionPtr          hoverDimensionFunc() const;
  void                      setHoverDimensionFunc(GripDimensionPtr pFunc);
  GripDimensionPtr          hotGripDimensionFunc() const;
  void                      setHotGripDimensionFunc(GripDimensionPtr pFunc);
  GcGePoint3d*              alternateBasePoint() const;
  void                      setAlternateBasePoint(GcGePoint3d* altBasePt);
  GripCLIPromptPtr          getCLIPromptFunc()const;
  void                      setCLIPromptFunc(GripCLIPromptPtr pFunc);
  GripCLIDisplayStringPtr   getCLIDisplayStringFunc()const;
  void                      setCLIDisplayStringFunc(GripCLIDisplayStringPtr pFunc);
  unsigned int              bitFlags() const;
  void                      setBitFlags(unsigned int flags);
  bool                      skipWhenShared() const;
  void                      setSkipWhenShared(bool skip);
  bool                      isRubberBandLineDisabled() const;
  void                      disableRubberBandLine(bool disable);
  bool                      areModeKeywordsDisabled() const;
  void                      disableModeKeywords(bool disable);
  bool                      drawAtDragImageGripPoint() const;
  void                      setDrawAtDragImageGripPoint(bool atDragPoint);
  bool                      triggerGrip() const;
  void                      setTriggerGrip(bool trigger);
  GripInputPointPtr         inputPointFunc() const;
  void                      setInputPointFunc(GripInputPointPtr pFunc);
  bool                      forcedPickOn() const;
  void                      setForcedPickOn(bool on);
  bool                      mapGripHotToRtClk() const;
  void                      setMapGripHotToRtClk(bool on);
  bool                      gizmosEnabled() const;
  void                      setGizmosEnabled(bool on);
  bool                      gripIsPerViewport() const;
  void                      setGripIsPerViewport(bool on);
  bool                      gripIsDisabled() const;
  void                      disableGrip(bool disable);
  bool                      gripRightClickIsNewStyle() const;

private:
  GcGePoint3d         m_gripPt;
  GcGePoint3d*        m_pAltBasePt;
  void*               m_pAppData;
  GripOperationPtr    m_pHotGripFunc;
  GripOperationPtr    m_pHoverFunc;
  union {
    GripRtClkHandler oldHandler;
    GripRightClickHandler newHandler;
  } m_pRtClk;
  GripWorldDrawPtr    m_pWorldDraw;
  GripViewportDrawPtr m_pViewportDraw;
  GripOpStatusPtr     m_pGripOpStatFunc;
  GripToolTipPtr      m_pToolTipFunc;
  GripDimensionPtr    m_pHoverDimensionFunc;
  GripDimensionPtr    m_pHotGripDimensionFunc;
  unsigned int        m_bitFlags;
  GripInputPointPtr   m_pInputPointFunc;
  GcRxClass*          m_pAppDataClass;
  GripCLIPromptPtr          m_pCLIPromptFunc;
  GripCLIDisplayStringPtr   m_pCLIDisplayStringFunc;
};

inline GcDbGripData::GcDbGripData()
  : m_pAppData(NULL)
  , m_pAppDataClass(NULL)
  , m_pHotGripFunc(NULL)
  , m_pHoverFunc(NULL)
  , m_pWorldDraw(NULL)
  , m_pViewportDraw(NULL)
  , m_pGripOpStatFunc(NULL)
  , m_pToolTipFunc(NULL)
  , m_pHoverDimensionFunc(NULL)
  , m_pHotGripDimensionFunc(NULL)
  , m_bitFlags(0)
  , m_pAltBasePt(NULL)
  , m_pInputPointFunc(NULL)
  , m_pCLIPromptFunc(NULL)
  , m_pCLIDisplayStringFunc(NULL)
{
  setRtClk(NULL);
}

inline GcDbGripData::GcDbGripData(const GcGePoint3d& pt, void* AppData,
  GripOperationPtr hotGrip, GripOperationPtr hoverGrip,
  GripRtClkHandler RtClk, GripWorldDrawPtr wd,
  GripViewportDrawPtr vd, GripOpStatusPtr stat,
  GripToolTipPtr tt, GripDimensionPtr hoverDim,
  GripDimensionPtr hotGripDim,
  unsigned int bitFlags, GcGePoint3d* altBasePt,
  GripInputPointPtr inputPointFunc) :
  m_gripPt(pt), m_pAppData(AppData), m_pAppDataClass(NULL), m_pHotGripFunc(hotGrip),
  m_pHoverFunc(hoverGrip), m_pWorldDraw(wd),
  m_pViewportDraw(vd), m_pGripOpStatFunc(stat),
  m_pToolTipFunc(tt), m_pHoverDimensionFunc(hoverDim),
  m_pHotGripDimensionFunc(hotGripDim),
  m_bitFlags(bitFlags), m_pAltBasePt(altBasePt),
  m_pInputPointFunc(inputPointFunc), m_pCLIPromptFunc(NULL), m_pCLIDisplayStringFunc(NULL)
{
  setRtClk(RtClk);
}

inline GcDbGripData::GcDbGripData(const GcGePoint3d& pt, void* AppData,
  GcRxClass* pAppDataClass,
  GripOperationPtr hotGrip, GripOperationPtr hoverGrip,
  GripRtClkHandler RtClk, GripWorldDrawPtr wd,
  GripViewportDrawPtr vd, GripOpStatusPtr stat,
  GripToolTipPtr tt, GripDimensionPtr hoverDim,
  GripDimensionPtr hotGripDim,
  unsigned int bitFlags, GcGePoint3d* altBasePt,
  GripInputPointPtr inputPointFunc) :
  m_gripPt(pt), m_pAppData(AppData), m_pAppDataClass(pAppDataClass),
  m_pHotGripFunc(hotGrip), m_pHoverFunc(hoverGrip),
  m_pWorldDraw(wd), m_pViewportDraw(vd), m_pGripOpStatFunc(stat),
  m_pToolTipFunc(tt), m_pHoverDimensionFunc(hoverDim),
  m_pHotGripDimensionFunc(hotGripDim),
  m_bitFlags(bitFlags), m_pAltBasePt(altBasePt),
  m_pInputPointFunc(inputPointFunc), m_pCLIPromptFunc(NULL), m_pCLIDisplayStringFunc(NULL)
{
  setRtClk(RtClk);
}

inline GcDbGripData::GcDbGripData(const GcDbGripData& src)
{
  m_gripPt = src.gripPoint();
  m_pAppData = src.appData();
  m_pAppDataClass = src.appDataGcRxClass();
  m_pHotGripFunc = src.hotGripFunc();
  m_pHoverFunc = src.hoverFunc();
  m_pRtClk.oldHandler = src.rtClk();
  m_pWorldDraw = src.worldDraw();
  m_pViewportDraw = src.viewportDraw();
  m_pGripOpStatFunc = src.gripOpStatFunc();
  m_pToolTipFunc = src.toolTipFunc();
  m_pHoverDimensionFunc = src.hoverDimensionFunc();
  m_pHotGripDimensionFunc = src.hotGripDimensionFunc();
  m_bitFlags = src.bitFlags();
  m_pAltBasePt = src.alternateBasePoint();
  m_pInputPointFunc = src.inputPointFunc();
  m_pCLIPromptFunc = src.getCLIPromptFunc();
  m_pCLIDisplayStringFunc = src.getCLIDisplayStringFunc();
}

inline GcDbGripData& GcDbGripData::operator = (const GcDbGripData& rtSide)
{
  m_gripPt = rtSide.gripPoint();
  m_pAppData = rtSide.appData();
  m_pAppDataClass = rtSide.appDataGcRxClass();
  m_pHotGripFunc = rtSide.hotGripFunc();
  m_pHoverFunc = rtSide.hoverFunc();
  m_pRtClk.oldHandler = rtSide.rtClk();
  m_pWorldDraw = rtSide.worldDraw();
  m_pViewportDraw = rtSide.viewportDraw();
  m_pGripOpStatFunc = rtSide.gripOpStatFunc();
  m_pToolTipFunc = rtSide.toolTipFunc();
  m_pHoverDimensionFunc = rtSide.hoverDimensionFunc();
  m_pHotGripDimensionFunc = rtSide.hotGripDimensionFunc();
  m_bitFlags = rtSide.bitFlags();
  m_pAltBasePt = rtSide.alternateBasePoint();
  m_pInputPointFunc = rtSide.inputPointFunc();
  m_pCLIPromptFunc = rtSide.getCLIPromptFunc();
  m_pCLIDisplayStringFunc = rtSide.getCLIDisplayStringFunc();

  return *this;
}

inline void GcDbGripData::setAllData(const GcGePoint3d& pt, void* AppData,
  GripOperationPtr hotGrip, GripOperationPtr hoverGrip,
  GripRtClkHandler RtClk, GripWorldDrawPtr wd,
  GripViewportDrawPtr vd, GripOpStatusPtr stat,
  GripToolTipPtr tt, GripDimensionPtr hoverDim,
  GripDimensionPtr hotGripDim,
  unsigned int bitFlags, GcGePoint3d* altBasePt,
  GripInputPointPtr inputPointFunc,
  GcRxClass* pAppDataClass)
{
  m_gripPt = pt;
  m_pAppData = AppData;
  m_pAppDataClass = pAppDataClass;
  m_pHotGripFunc = hotGrip;
  m_pHoverFunc = hoverGrip;
  setRtClk(RtClk);
  m_pWorldDraw = wd;
  m_pViewportDraw = vd;
  m_pGripOpStatFunc = stat;
  m_pToolTipFunc = tt;
  m_pHoverDimensionFunc = hoverDim;
  m_pHotGripDimensionFunc = hotGripDim;
  m_bitFlags = bitFlags;
  m_pAltBasePt = altBasePt;
  m_pInputPointFunc = inputPointFunc;
}

inline const GcGePoint3d&
GcDbGripData::gripPoint() const
{
  return m_gripPt;
}

inline void
GcDbGripData::setGripPoint(const GcGePoint3d& pt)
{
  m_gripPt = pt;
}

inline void*
GcDbGripData::appData() const
{
  return m_pAppData;
}

inline void
GcDbGripData::setAppData(void* appData)
{
  m_pAppData = appData;
}

inline GcRxClass*
GcDbGripData::appDataGcRxClass() const
{
  return m_pAppDataClass;
}

inline void
GcDbGripData::setAppDataGcRxClass(GcRxClass* appDataClass)
{
  m_pAppDataClass = appDataClass;
}

inline GripOperationPtr
GcDbGripData::hotGripFunc() const
{
  return m_pHotGripFunc;
}

inline void
GcDbGripData::setHotGripFunc(GripOperationPtr pFunc)
{
  m_pHotGripFunc = pFunc;
}

inline GripOperationPtr
GcDbGripData::hoverFunc() const
{
  return m_pHoverFunc;
}

inline void
GcDbGripData::setHoverFunc(GripOperationPtr pFunc)
{
  m_pHoverFunc = pFunc;
}

inline GripRtClkHandler
GcDbGripData::rtClk() const
{
  return m_pRtClk.oldHandler;
}

inline void
GcDbGripData::setRtClk(GripRtClkHandler pFunc)
{
  m_bitFlags &= ~GcDbGripOperations::kGripRightClickIsNewStyle;
  m_pRtClk.oldHandler = pFunc;
}

inline GripRightClickHandler
GcDbGripData::righClick() const
{
  return m_pRtClk.newHandler;
}

inline void
GcDbGripData::setRightClick(GripRightClickHandler pFunc)
{
  m_bitFlags |= GcDbGripOperations::kGripRightClickIsNewStyle;
  m_pRtClk.newHandler = pFunc;
}

inline GripWorldDrawPtr
GcDbGripData::worldDraw() const
{
  return m_pWorldDraw;
}

inline void
GcDbGripData::setWorldDraw(GripWorldDrawPtr pFunc)
{
  m_pWorldDraw = pFunc;
}

inline GripViewportDrawPtr
GcDbGripData::viewportDraw() const
{
  return m_pViewportDraw;
}

inline void
GcDbGripData::setViewportDraw(GripViewportDrawPtr pFunc)
{
  m_pViewportDraw = pFunc;
}

inline GripOpStatusPtr
GcDbGripData::gripOpStatFunc() const
{
  return m_pGripOpStatFunc;
}

inline void
GcDbGripData::setGripOpStatFunc(GripOpStatusPtr pFunc)
{
  m_pGripOpStatFunc = pFunc;
}

inline GripToolTipPtr
GcDbGripData::toolTipFunc() const
{
  return m_pToolTipFunc;
}

inline void
GcDbGripData::setToolTipFunc(GripToolTipPtr pFunc)
{
  m_pToolTipFunc = pFunc;
}

inline GripDimensionPtr
GcDbGripData::hoverDimensionFunc() const
{
  return m_pHoverDimensionFunc;
}

inline void
GcDbGripData::setHoverDimensionFunc(GripDimensionPtr pFunc)
{
  m_pHoverDimensionFunc = pFunc;
}

inline GripDimensionPtr
GcDbGripData::hotGripDimensionFunc() const
{
  return m_pHotGripDimensionFunc;
}

inline void
GcDbGripData::setHotGripDimensionFunc(GripDimensionPtr pFunc)
{
  m_pHotGripDimensionFunc = pFunc;
}

inline GcGePoint3d*
GcDbGripData::alternateBasePoint() const
{
  return m_pAltBasePt;
}

inline void
GcDbGripData::setAlternateBasePoint(GcGePoint3d* altBasePt)
{
  m_pAltBasePt = altBasePt;
}

inline unsigned int
GcDbGripData::bitFlags() const
{
  return m_bitFlags;
}

inline void
GcDbGripData::setBitFlags(unsigned int flags)
{
  m_bitFlags = flags;
}

inline bool
GcDbGripData::skipWhenShared() const
{
  return !!(m_bitFlags & GcDbGripOperations::kSkipWhenShared);
}

inline void
GcDbGripData::setSkipWhenShared(bool skip)
{
  if (skip)
    m_bitFlags |= GcDbGripOperations::kSkipWhenShared;
  else
    m_bitFlags &= ~GcDbGripOperations::kSkipWhenShared;
}

inline bool
GcDbGripData::isRubberBandLineDisabled() const
{
  return !!(m_bitFlags & GcDbGripOperations::kDisableRubberBandLine);
}

inline void
GcDbGripData::disableRubberBandLine(bool disable)
{
  if (disable)
    m_bitFlags |= GcDbGripOperations::kDisableRubberBandLine;
  else
    m_bitFlags &= ~GcDbGripOperations::kDisableRubberBandLine;
}

inline bool
GcDbGripData::areModeKeywordsDisabled() const
{
  return !!(m_bitFlags & GcDbGripOperations::kDisableModeKeywords);
}

inline void
GcDbGripData::disableModeKeywords(bool disable)
{
  if (disable)
    m_bitFlags |= GcDbGripOperations::kDisableModeKeywords;
  else
    m_bitFlags &= ~GcDbGripOperations::kDisableModeKeywords;
}

inline bool
GcDbGripData::drawAtDragImageGripPoint() const
{
  return !!(m_bitFlags & GcDbGripOperations::kDrawAtDragImageGripPoint);
}

inline void
GcDbGripData::setDrawAtDragImageGripPoint(bool atDragPoint)
{
  if (atDragPoint)
    m_bitFlags |= GcDbGripOperations::kDrawAtDragImageGripPoint;
  else
    m_bitFlags &= ~GcDbGripOperations::kDrawAtDragImageGripPoint;
}

inline bool
GcDbGripData::triggerGrip() const
{
  return !!(m_bitFlags & GcDbGripOperations::kTriggerGrip);
}

inline void
GcDbGripData::setTriggerGrip(bool trigger)
{
  if (trigger)
    m_bitFlags |= GcDbGripOperations::kTriggerGrip
    | GcDbGripOperations::kSkipWhenShared;
  else
    m_bitFlags &= ~(GcDbGripOperations::kTriggerGrip
      | GcDbGripOperations::kSkipWhenShared);
}

inline GripInputPointPtr
GcDbGripData::inputPointFunc() const
{
  return m_pInputPointFunc;
}

inline void
GcDbGripData::setInputPointFunc(GripInputPointPtr pFunc)
{
  m_pInputPointFunc = pFunc;
}

inline bool
GcDbGripData::forcedPickOn() const
{
  return !!(m_bitFlags & GcDbGripOperations::kTurnOnForcedPick);
}

inline void
GcDbGripData::setForcedPickOn(bool on)
{
  if (on)
    m_bitFlags |= GcDbGripOperations::kTurnOnForcedPick;
  else
    m_bitFlags &= ~GcDbGripOperations::kTurnOnForcedPick;
}

inline bool
GcDbGripData::mapGripHotToRtClk() const
{
  return !!(m_bitFlags & GcDbGripOperations::kMapGripHotToRtClk);
}

inline void
GcDbGripData::setMapGripHotToRtClk(bool on)
{
  if (on)
    m_bitFlags |= GcDbGripOperations::kMapGripHotToRtClk;
  else
    m_bitFlags &= ~GcDbGripOperations::kMapGripHotToRtClk;
}

inline bool
GcDbGripData::gizmosEnabled() const
{
  return !!(m_bitFlags & GcDbGripOperations::kGizmosEnabled);
}

inline void
GcDbGripData::setGizmosEnabled(bool on)
{
  if (on)
    m_bitFlags |= GcDbGripOperations::kGizmosEnabled;
  else
    m_bitFlags &= ~GcDbGripOperations::kGizmosEnabled;
}

inline bool
GcDbGripData::gripIsPerViewport() const
{
  return !!(m_bitFlags & GcDbGripOperations::kGripIsPerViewport);
}

inline void
GcDbGripData::setGripIsPerViewport(bool on)
{
  if (on)
    m_bitFlags |= GcDbGripOperations::kGripIsPerViewport;
  else
    m_bitFlags &= ~GcDbGripOperations::kGripIsPerViewport;
}

inline bool
GcDbGripData::gripIsDisabled() const
{
  return !!(m_bitFlags & GcDbGripOperations::kGripIsDisabled);
}

inline void
GcDbGripData::disableGrip(bool disable)
{
  if (disable)
    m_bitFlags |= GcDbGripOperations::kGripIsDisabled;
  else
    m_bitFlags &= ~GcDbGripOperations::kGripIsDisabled;
}

inline bool
GcDbGripData::gripRightClickIsNewStyle() const
{
  return !!(m_bitFlags & GcDbGripOperations::kGripRightClickIsNewStyle);
}

inline GripCLIPromptPtr
GcDbGripData::getCLIPromptFunc() const
{
  return m_pCLIPromptFunc;
}

inline void
GcDbGripData::setCLIPromptFunc(GripCLIPromptPtr pFunc)
{
  m_pCLIPromptFunc = pFunc;
}

inline GripCLIDisplayStringPtr
GcDbGripData::getCLIDisplayStringFunc() const
{
  return m_pCLIDisplayStringFunc;
}

inline void
GcDbGripData::setCLIDisplayStringFunc(GripCLIDisplayStringPtr pFunc)
{
  m_pCLIDisplayStringFunc = pFunc;
}

#endif 