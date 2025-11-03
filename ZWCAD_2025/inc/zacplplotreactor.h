

#ifndef ZCPLPLOTREACTOR_H
#define ZCPLPLOTREACTOR_H

#include "zAdAChar.h"
#include "zacpl.h"
#include "zacplobject.h"

class ZcPlPlotInfo;
class ZcPlPlotPageInfo;
class ZcPlPlotProgress;

class ZCPL_PORT ZcPlPlotReactor : public ZcRxObject 
{
public:

    enum PlotType {
        kPlot,
        kPreview,
        kBackgroundPackaging,
        kBackgroundPlot
    };

    virtual void beginPlot(ZcPlPlotProgress* pPlotProgress, PlotType type);

    virtual void beginDocument(ZcPlPlotInfo& plotInfo,
                                         const ZTCHAR * pDocname,
                               ZSoft::Int32 nCopies = 1, bool bPlotToFile = false,
                               const ZTCHAR * pFilename = NULL);

    virtual void beginPage(ZcPlPlotPageInfo& pageInfo, ZcPlPlotInfo& plotInfo,
                           bool bLastPage);

    virtual void endPage(ZcPlPlotProgress::SheetCancelStatus status);

    virtual void endDocument(ZcPlPlotProgress::PlotCancelStatus status);

    virtual void endPlot(ZcPlPlotProgress::PlotCancelStatus status);

    virtual void plotCancelled();

    virtual void pageCancelled();

    virtual ~ZcPlPlotReactor();
    
protected:
    ZcPlPlotReactor();
};

#endif 
