/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCPLHOSTAPPSERVICES_H
#define GCPLHOSTAPPSERVICES_H

class GcPlPlotLogger;
class GcadPlotInternalServices;

class GSOFT_NO_VTABLE GcPlHostAppServices
{
public:
  enum PlotStatus {
    kSheetIdxAndName = -5,
    kDisableCancelSheet = -4,
    kDwfFilePlotted = -3,
    kPlottingMsg = -2,
    kNoPlotYet = -1,
    kPlotStart = 0,
    kViewPlotLog = 1,
    kPlotSuccessful = 2,
    kPlotHadErrors = 3,
    kPlotHadSystemError = 4,
    kViewPlottedFile = 5,
    kViewFileWhenSuccessful = 6
  };

  virtual GcPlPlotLogger * getPlotLogger(void) = 0;
  virtual const GcadPlotInternalServices* gcadInternalServices() = 0;
  virtual void updatePlotJobStatus(enum GcPlHostAppServices::PlotStatus nStatus, const GCHAR *szPlotMsg) = 0;
};

GCPL_PORT Gcad::ErrorStatus GcPlSetHostAppServices(GcPlHostAppServices *pHostServices);
GCPL_PORT GcPlHostAppServices *GcPlGetHostAppServices();

#endif 