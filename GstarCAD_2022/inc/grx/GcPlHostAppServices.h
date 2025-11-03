#pragma once
#include "GcPlPlotLogger.h"

class GcPlPlotLogger;
class GcadPlotInternalServices;

class  HCCAD_NO_VTABLE GcPlHostAppServices
{
public:
  enum PlotStatus
  {
    kSheetIdxAndName = -5, kDisableCancelSheet = -4, kDwfFilePlotted = -3, kPlottingMsg = -2,
    kNoPlotYet = -1, kPlotStart = 0, kViewPlotLog = 1, kPlotSuccessful = 2,
    kPlotHadErrors = 3, kPlotHadSystemError = 4, kViewPlottedFile = 5, kViewFileWhenSuccessful = 6
  };

  virtual GcPlPlotLogger * getPlotLogger(void) = 0;
  virtual const GcadPlotInternalServices* gcadInternalServices() = 0;

  virtual void updatePlotJobStatus(enum GcPlHostAppServices::PlotStatus nStatus, const OdChar*szPlotMsg) = 0;
};

GCPL_PORT Gcad::ErrorStatus GcPlSetHostAppServices(GcPlHostAppServices *pHostServices);
GCPL_PORT GcPlHostAppServices *GcPlGetHostAppServices();





