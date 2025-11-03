#ifndef   _GCPLPLOTFACTORY_H
#define   _GCPLPLOTFACTORY_H

#include "GcPl.h"

class GcPlPlotEngine;

class GcPlPlotFactory
{
public:
    GCPL_PORT GcPlPlotFactory(void);

    GCPL_PORT ~GcPlPlotFactory(void);

    enum PreviewEngineFlags {
        kShowPlot            = 0x0001,  // Allow plot from preview state
        kShowNextSheet       = 0x0002,  // Allow "Next Sheet" from preview state
        kShowPreviousSheet   = 0x0004   // Allow "Previous Sheet" from preview state
    };

    static GCPL_PORT OdResult createPublishEngine(GcPlPlotEngine *& pEngine);
	static GCPL_PORT OdResult createPreviewEngine(GcPlPlotEngine *& pPreview, 
		long nPreviewFlags = kShowPlot);
	static GCPL_PORT OdResult createPlotEngine(GcPlPlotEngine *& pEngine);
public:
	static GcPlPlotEngine *g_PlotEngine;
};

// Possible plotting system states
enum ProcessPlotState
{
    kNotPlotting = 0,       // No plot in progress
    kForegroundPlotting,    // Plot is in progress in the current process
    kBackgroundPlotting     // Plot is in progress in a background process, 
    // this process is the foreground process.
};

// Method for determining current state of the plotting subsystem
GCPL_PORT ProcessPlotState __stdcall gcplProcessPlotState();

#endif // _GCPLPLOTFACTORY_H

