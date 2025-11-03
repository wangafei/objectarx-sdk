#pragma once


#include "GcPlPlotReactor.h"

class GcPlPlotProgress;

class GcPlPlotReactorMgr
{
public:
	GcPlPlotReactorMgr(void);
	~GcPlPlotReactorMgr(void);

public:
	// Adds the given reactor to the reactor chain
	GCPL_PORT void addReactor(GcPlPlotReactor* pReactor);

	// Removes the given reactor from the reactor chain
	GCPL_PORT void removeReactor(GcPlPlotReactor* pReactor);
public:

	// Notification for begin of plot
	virtual void fireBeginPlot(GcPlPlotProgress* pPlotProgress, GcPlPlotReactor::PlotType type);

	// Notification for beginning of an document
	virtual void fireBeginDocument(GcPlPlotInfo& plotInfo,
		const GCHAR * pDocname,
		long nCopies = 1, bool bPlotToFile = false,
		const GCHAR * pFilename = NULL);

	// Notification for begin page
	virtual void fireBeginPage(GcPlPlotPageInfo& pageInfo, GcPlPlotInfo& plotInfo,
		bool bLastPage);

	// Notification for end page
	virtual void fireEndPage(GcPlPlotProgress::SheetCancelStatus status);

	// Notification for end of an document
	virtual void fireEndDocument(GcPlPlotProgress::PlotCancelStatus status);

	// Notification that plot has ended
	virtual void fireEndPlot(GcPlPlotProgress::PlotCancelStatus status);

	// Notification that plot was cancelled
	virtual void firePlotCancelled();

	// Notification that page was cancelled
	virtual void firePageCancelled();
protected:
	void *m_pImpl;
};

GCPL_PORT GcPlPlotReactorMgr* __stdcall gcplPlotReactorMgrPtr();
#define gcplPlotReactorMgr gcplPlotReactorMgrPtr()
