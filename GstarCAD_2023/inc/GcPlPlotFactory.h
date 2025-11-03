/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef   _GCPLPLOTFACTORY_H
#define   _GCPLPLOTFACTORY_H

#include "GcPl.h"
#include "gsoft.h"    
#include "gcadstrc.h" 


class GcPlPlotEngine;

class GcPlPlotFactory
{
public:

  enum PreviewEngineFlags {
    kShowPlot = 0x0001,
    kShowNextSheet = 0x0002,
    kShowPreviousSheet = 0x0004
  };

  static GCPL_PORT Gcad::ErrorStatus createPublishEngine(GcPlPlotEngine *& pEngine);
  static GCPL_PORT Gcad::ErrorStatus createPreviewEngine(GcPlPlotEngine *& pPreview,
    long nPreviewFlags = kShowPlot);
};

enum ProcessPlotState
{
  kNotPlotting = 0,
  kForegroundPlotting,
  kBackgroundPlotting
};

GCPL_PORT ProcessPlotState GSOFT_STDCALL gcplProcessPlotState();

#endif 