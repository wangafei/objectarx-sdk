#pragma once
#include "GcPl.h"
#include "GcPlPlotProgress.h"
#include "GcPlPlotInfo.h"
#include "GcPlPlotPageInfo.h"
#include "gcplobject.h"


class GcPlPlotReactor:public GcRxObject
{
//public:
//	GCRX_DECLARE_MEMBERS(GcPlPlotReactor);

public:

	// Plot Type
	enum PlotType {
		kPlot,
		kPreview,
		kBackgroundPackaging,
		kBackgroundPlot
	};

	// Notification for begin of plot
	GCPL_PORT virtual void beginPlot(GcPlPlotProgress* pPlotProgress, GcPlPlotReactor::PlotType type);

	// Notification for beginning of an document
	GCPL_PORT virtual void beginDocument(GcPlPlotInfo& plotInfo,
		const GCHAR * pDocname,
		long nCopies = 1, bool bPlotToFile = false,
		const GCHAR * pFilename = NULL);

	// Notification for begin page
	GCPL_PORT virtual void beginPage(GcPlPlotPageInfo& pageInfo, GcPlPlotInfo& plotInfo,
		bool bLastPage);

	// Notification for end page
	GCPL_PORT virtual void endPage(GcPlPlotProgress::SheetCancelStatus status);

	// Notification for end of an document
	GCPL_PORT virtual void endDocument(GcPlPlotProgress::PlotCancelStatus status);

	// Notification that plot has ended
	GCPL_PORT virtual void endPlot(GcPlPlotProgress::PlotCancelStatus status);

	// Notification that plot was cancelled
	GCPL_PORT virtual void plotCancelled();

	// Notification that page was cancelled
	GCPL_PORT virtual void pageCancelled();

	// Destructor
	GCPL_PORT virtual ~GcPlPlotReactor();

protected:
    GCPL_PORT GcPlPlotReactor(void);

};

