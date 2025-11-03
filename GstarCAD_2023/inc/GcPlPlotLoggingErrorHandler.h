/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCPLPLOTLOGGINGERRORHANDLER_H
#define GCPLPLOTLOGGINGERRORHANDLER_H

class GcPlPlotLogger;
class GcPlSystenInternals;

class GcPlPlotLoggingErrorHandler : public GcPlPlotErrorHandler
{
public:
  GCPL_PORT GcPlPlotLoggingErrorHandler();
  GCPL_PORT GcPlPlotLoggingErrorHandler(GcPlPlotLogger *);
  GCPL_PORT ~GcPlPlotLoggingErrorHandler();

  GCPL_DECLARE_MEMBERS(GcPlPlotLoggingErrorHandler);

public:

  GCPL_PORT void infoMessage(const GCHAR *pMessage) override;
  GCPL_PORT int messageBox(
    const GCHAR *pText,
    const GCHAR *pCaption,
    unsigned int uType,
    int defaultReturn) override;
  GCPL_PORT void info(
    GCPL_ULONG_PTR category,
    const unsigned int specific,
    const GCHAR *pLocation,
    const GCHAR *pContextData,
    const GCHAR *pRevision) override;
  GCPL_PORT ErrorResult warning(
    GCPL_ULONG_PTR category,
    const unsigned int specific,
    const GCHAR *pLocation,
    const GCHAR *pContextData,
    const GCHAR *pRevision) override;
  GCPL_PORT void severeError(
    GCPL_ULONG_PTR category,
    const unsigned int specific,
    const GCHAR *pLocation,
    const GCHAR *pContextData,
    const GCHAR *pRevision) override;
  GCPL_PORT ErrorResult error(
    GCPL_ULONG_PTR category,
    const unsigned int specific,
    const GCHAR *pLocation,
    const GCHAR *pContextData,
    const GCHAR *pRevision) override;
  GCPL_PORT ErrorResult ariError(
    GCPL_ULONG_PTR category,
    const unsigned int specific,
    const GCHAR *pLocation,
    const GCHAR *pContextData,
    const GCHAR *pRevision) override;
  GCPL_PORT void terminalError(
    GCPL_ULONG_PTR category,
    const unsigned int specific,
    const GCHAR *pLocation,
    const GCHAR *pContextData,
    const GCHAR *pRevision) override;
  GCPL_PORT void logMessage(const GCHAR *pTitle, const GCHAR *pMsg) override;

};

#endif 