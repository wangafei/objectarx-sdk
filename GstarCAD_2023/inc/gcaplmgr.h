/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef   _GCAPLMGR_H
#define   _GCAPLMGR_H

#include "GcDbLMgr.h"
#pragma pack (push, 8)

class GcDbObjectId;
class GcGePoint2d;
class GcGePoint3d;

template <class T> class GcArrayMemCopyReallocator;
template <class T, class R  > class GcArray;
typedef GcArray<GcGePoint2d> GcGePoint2dArray;

class GcApLayoutManager : public GcDbLayoutManager {
public:
  virtual int                pageSetup(GcDbObjectId layoutBTRId = GcDbObjectId::kNull,
                                       void* pParent = nullptr,
                                       Gsoft::Boolean isPageSetupDlg = true) = 0;
  virtual void               updateCurrentPaper(Gsoft::Boolean zoomToPaper = false) = 0;
  virtual void               updateLayoutTabs() = 0;

  virtual Gcad::ErrorStatus  getActiveTab(GcString &sName) = 0;
  virtual const GCHAR *      findActiveTab() final;

  virtual Gsoft::Boolean     showTabs() = 0;
  virtual void               setShowTabs(Gsoft::Boolean showTabs) = 0;

  virtual Gsoft::Boolean     showPageSetup() = 0;
  virtual void               setShowPageSetup(Gsoft::Boolean showPageSetupDlg) = 0;

  virtual Gsoft::Boolean     createViewports() = 0;
  virtual void               setCreateViewports(Gsoft::Boolean createViewports) = 0;

  virtual Gsoft::Boolean     showPaperBackground() = 0;
  virtual void               setShowPaperBackground(Gsoft::Boolean showPaperBackground) = 0;

  virtual Gsoft::Boolean     showPaperMargins() = 0;
  virtual void               setShowPaperMargins(Gsoft::Boolean showPaperMargins) = 0;

  virtual Gsoft::Boolean     showPrintBorder() = 0;
  virtual void               setShowPrintBorder(Gsoft::Boolean showPrintBorder) = 0;

  virtual Gcad::ErrorStatus  generateNextNewLayoutName(GcString &sName,
                                                       GcDbDatabase* useDb = nullptr) = 0;
  virtual GCHAR *            getNextNewLayoutName(GcDbDatabase* useDb = nullptr) final;

  virtual void               setDefaultPlotConfig(GcDbObjectId layoutBTRId) = 0;
  virtual Gcad::ErrorStatus  getClipBoundaryElaboration(GcDbObjectId clipId,
                               GcGePoint2dArray *&clipBoundary) = 0;
  virtual Gcad::ErrorStatus  pointInViewports(const GcGePoint3d &pickPt,
                     GcDbObjectIdArray &viewports) = 0;
  virtual void               setCaptureOnLayoutSwitch(bool bCaptureOnLayout) = 0;
  virtual Gcad::ErrorStatus  createLayoutFromTemplate(const GCHAR *newLayoutName, GcDbObjectId& newLayoutId,
                             const GCHAR *templatePath, const GCHAR *layoutName, GcDbDatabase* pDb = NULL) = 0;
};
#pragma pack (pop)
inline const GCHAR * GcApLayoutManager::findActiveTab()
{
  static GcString sCachedName;
  this->getActiveTab(sCachedName);
  return sCachedName.constPtr();
}

inline GCHAR * GcApLayoutManager::getNextNewLayoutName(GcDbDatabase* useDb)
{
  GcString sName;
  return ::gcutGcStringToGChar(sName, this->generateNextNewLayoutName(sName, useDb));
}

#endif 