/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef   _GCPLPLOTENGINE_H
#define   _GCPLPLOTENGINE_H

#include "GdGChar.h"
#include "GcPl.h"
#include "GcPlObject.h"

class GcViewport;
class PlotEnvironment;
class GcPlPlotProgress;
class GcPlPlotInfo;
class GcDbPlotSettings;
class GcPlPlotConfig;

enum PreviewStatus {
  kNormal = 0,
  kPlot,
  kCancel,
  kNext,
  kPrevious
};

struct GCPL_PREVIEWENDPLOT {
  PreviewStatus nStatus;
};

class GcPlPlotPageInfo : public GcPlObject
{
  GCPL_DECLARE_MEMBERS(GcPlPlotPageInfo);

public:
  GCPL_PORT GcPlPlotPageInfo();
  GCPL_PORT ~GcPlPlotPageInfo();

  GCPL_PORT Gsoft::Int32 entityCount() const;
  GCPL_PORT Gsoft::Int32 rasterCount() const;
  GCPL_PORT Gsoft::Int32 oleObjectCount() const;
  GCPL_PORT Gsoft::Int32 gradientCount() const;
  GCPL_PORT Gsoft::Int32 shadedViewportType() const;
};

class GSOFT_NO_VTABLE GcPlPlotEngine {
public:
  virtual Gcad::ErrorStatus beginPlot(GcPlPlotProgress* pPlotProgress, void* pParams = NULL);
  virtual Gcad::ErrorStatus endPlot(void* pParams = NULL);

  virtual Gcad::ErrorStatus beginDocument(GcPlPlotInfo& plotInfo,
    const GCHAR * pDocname,
    void *pParams = NULL,
    Gsoft::Int32 nCopies = 1,
    bool bPlotToFile = false,
    const GCHAR * pFileName = NULL);
  virtual Gcad::ErrorStatus endDocument(void* pParams = NULL);

  virtual Gcad::ErrorStatus beginPage(GcPlPlotPageInfo& pageInfo,
    GcPlPlotInfo& plotInfo,
    bool bLastPage,
    void* pParams = NULL);
  virtual Gcad::ErrorStatus endPage(void* pParams = NULL);

  virtual Gcad::ErrorStatus beginGenerateGraphics(void* pParams = NULL);
  virtual Gcad::ErrorStatus beginGenerateGraphics(GcViewport*& pViewport, void* pParams = NULL);
  virtual Gcad::ErrorStatus endGenerateGraphics(void* pParams = NULL);

  virtual void destroy();
  virtual bool isBackgroundPackaging() const;
};

#endif 