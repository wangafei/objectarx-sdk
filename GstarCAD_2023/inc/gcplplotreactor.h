/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCPLPLOTREACTOR_H
#define GCPLPLOTREACTOR_H

#include "GdGChar.h"
#include "GcPl.h"
#include "GcPlObject.h"

class GcPlPlotInfo;
class GcPlPlotPageInfo;
class GcPlPlotProgress;

class GCPL_PORT GcPlPlotReactor : public GcRxObject
{
public:
  enum PlotType {
    kPlot,
    kPreview,
    kBackgroundPackaging,
    kBackgroundPlot
  };

  virtual void beginPlot(GcPlPlotProgress* pPlotProgress, PlotType type);
  virtual void endPlot(GcPlPlotProgress::PlotCancelStatus status);

  virtual void beginDocument(GcPlPlotInfo& plotInfo,
    const GCHAR * pDocname,
    Gsoft::Int32 nCopies = 1,
    bool bPlotToFile = false,
    const GCHAR * pFilename = NULL);
  virtual void endDocument(GcPlPlotProgress::PlotCancelStatus status);

  virtual void beginPage(GcPlPlotPageInfo& pageInfo, GcPlPlotInfo& plotInfo,
    bool bLastPage);
  virtual void endPage(GcPlPlotProgress::SheetCancelStatus status);

  virtual void plotCancelled();
  virtual void pageCancelled();

  ~GcPlPlotReactor();

protected:
  GcPlPlotReactor();
};

#endif 