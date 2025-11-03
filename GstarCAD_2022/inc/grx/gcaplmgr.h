#ifndef _GCAP_LAYOUT_MANAGER_H_
#define _GCAP_LAYOUT_MANAGER_H_

#include "gcadstd.h"
#include "gcdblmgr.h"
#include "../Ge/GePoint2dArray.h"

#pragma pack (push, 8)

class GcDbObjectId;
class GcGePoint2d;
class GcGePoint3d;

class GcApLayoutManager : public GcDbLayoutManager
{
public:
  virtual int pageSetup(GcDbObjectId layoutBTRId = GcDbObjectId::kNull, void* pParent = NULL, 
                        Hccad::Boolean isPageSetupDlg = Hccad::kTrue) = 0;
  
  virtual void updateCurrentPaper(Hccad::Boolean zoomToPaper = Hccad::kFalse) = 0;

  virtual void updateLayoutTabs() = 0;

  virtual const GCHAR* findActiveTab() = 0;

  virtual Hccad::Boolean showTabs() = 0;

  virtual void setShowTabs(Hccad::Boolean showTabs) = 0;

  virtual Hccad::Boolean showPageSetup() = 0;

  virtual void setShowPageSetup(Hccad::Boolean showPageSetupDlg) = 0;

  virtual Hccad::Boolean createViewports() = 0;

  virtual void setCreateViewports(Hccad::Boolean createViewports) = 0;

  virtual Hccad::Boolean showPaperBackground() = 0;

  virtual void setShowPaperBackground(Hccad::Boolean showPaperBackground) = 0;

  virtual Hccad::Boolean showPaperMargins() = 0; 

  virtual void setShowPaperMargins(Hccad::Boolean showPaperMargins) = 0;

  virtual Hccad::Boolean showPrintBorder() = 0;

  virtual void setShowPrintBorder(Hccad::Boolean showPrintBorder) = 0;

  virtual GCHAR* getNextNewLayoutName(GcDbDatabase* useDb = NULL) = 0;

  virtual void setDefaultPlotConfig(GcDbObjectId layoutBTRId) = 0;

  virtual Gcad::ErrorStatus getClipBoundaryElaboration(GcDbObjectId clipId, GcGePoint2dArray *&clipBoundary) = 0;

  virtual Gcad::ErrorStatus pointInViewports(const GcGePoint3d &pickPt, GcDbObjectIdArray &viewports) = 0;
};

#pragma pack (pop)

#endif//_GCAP_LAYOUT_MANAGER_H_