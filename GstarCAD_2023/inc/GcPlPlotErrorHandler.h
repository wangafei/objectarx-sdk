/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCPLPLOTERRORHANDLER_H
#define GCPLPLOTERRORHANDLER_H

#include "GcPlObject.h"

class GcPlSystemInternals;

class GcPlPlotErrorHandler : public GcPlObject
{
protected:
#if !defined(_WIN64) && !defined (_GC64)
  using GCPL_ULONG_PTR = unsigned long;
#else
  using GCPL_ULONG_PTR = unsigned __int64;
#endif

public:
  enum ErrorResult {
    kAbort,
    kRetry,
    kIgnore
  };
  enum Handler {
    kInfo,
    kWarning,
    kError,
    kARI,
    kSevere,
    kTerminal,
    kNone
  };

  GCPL_PORT GcPlPlotErrorHandler();
  GCPL_PORT ~GcPlPlotErrorHandler();

  GCPL_DECLARE_MEMBERS(GcPlPlotErrorHandler);

public:
  GCPL_PORT virtual void infoMessage(const GCHAR *pMessage);
  GCPL_PORT virtual int messageBox(const GCHAR *pText,
    const GCHAR *pCaption,
    unsigned int uType,
    int defaultReturn);
  GCPL_PORT virtual void info(GCPL_ULONG_PTR category,
    const unsigned int specific,
    const GCHAR *pLocation,
    const GCHAR *pContextData,
    const GCHAR *pRevision);
  GCPL_PORT virtual ErrorResult warning(GCPL_ULONG_PTR category,
    const unsigned int specific,
    const GCHAR *pLocation,
    const GCHAR *pContextData,
    const GCHAR *pRevision);
  GCPL_PORT virtual void severeError(GCPL_ULONG_PTR category,
    const unsigned int specific,
    const GCHAR *pLocation,
    const GCHAR *pContextData,
    const GCHAR *pRevision);
  GCPL_PORT virtual ErrorResult error(GCPL_ULONG_PTR category,
    const unsigned int specific,
    const GCHAR *pLocation,
    const GCHAR *pContextData,
    const GCHAR *pRevision);
  GCPL_PORT virtual ErrorResult ariError(GCPL_ULONG_PTR category,
    const unsigned int specific,
    const GCHAR *pLocation,
    const GCHAR *pContextData,
    const GCHAR *pRevision);
  GCPL_PORT virtual void terminalError(GCPL_ULONG_PTR category,
    const unsigned int specific,
    const GCHAR *pLocation,
    const GCHAR *pContextData,
    const GCHAR *pRevision);

  GCPL_PORT virtual void logMessage(const GCHAR *pTitle, const GCHAR *pMsg);
  GCPL_PORT virtual bool takeResponsibility(Handler kind);
  GCPL_PORT virtual bool setLogHandle(const GCHAR *pFilePathName);
  GCPL_PORT virtual void setQuietMode(bool bQuiet);
  GCPL_PORT virtual void setLogMode(bool bLog);
  GCPL_PORT virtual bool quietMode() const;
  GCPL_PORT virtual bool logMode() const;

  GCPL_PORT void getProductString(GCHAR*& pProductString) const;
  GCPL_PORT void getProgramString(GCHAR*& pProgramString) const;
  GCPL_PORT void getCompanyString(GCHAR*& pCompanyString) const;

  GCPL_PORT virtual const GCHAR* warningTitle() const;
  GCPL_PORT virtual const GCHAR* severeTitle() const;
  GCPL_PORT virtual const GCHAR* errorTitle() const;
  GCPL_PORT virtual const GCHAR* ariTitle() const;
  GCPL_PORT virtual const GCHAR* terminalTitle() const;
  GCPL_PORT virtual const GCHAR* infoTitle() const;

protected:

  GCPL_PORT void appInfoMessage(const GCHAR *pMessage);
  GCPL_PORT int appMessageBox(const GCHAR *pText,
    const GCHAR *pCaption,
    unsigned int uType,
    int defaultReturn);
  GCPL_PORT void appInfo(GCPL_ULONG_PTR category,
    const unsigned int specific,
    const GCHAR *pLocation,
    const GCHAR *pContextData,
    const GCHAR *pRevision);
  GCPL_PORT ErrorResult appWarning(GCPL_ULONG_PTR category,
    const unsigned int specific,
    const GCHAR *pLocation,
    const GCHAR *pContextData,
    const GCHAR *pRevision);
  GCPL_PORT void appSevereError(GCPL_ULONG_PTR category,
    const unsigned int specific,
    const GCHAR *pLocation,
    const GCHAR *pContextData,
    const GCHAR *pRevision);
  GCPL_PORT ErrorResult appError(GCPL_ULONG_PTR category,
    const unsigned int specific,
    const GCHAR *pLocation,
    const GCHAR *pContextData,
    const GCHAR *pRevision);
  GCPL_PORT ErrorResult appARIError(GCPL_ULONG_PTR category,
    const unsigned int specific,
    const GCHAR *pLocation,
    const GCHAR *pContextData,
    const GCHAR *pRevision);
  GCPL_PORT void appTerminalError(GCPL_ULONG_PTR category,
    const unsigned int specific,
    const GCHAR *pLocation,
    const GCHAR *pContextData,
    const GCHAR *pRevision);

  GCPL_PORT void appLogMessage(const GCHAR *pTitle, const GCHAR *pMsg);
  GCPL_PORT bool appSetLogHandle(const GCHAR *pFilePathName);
};

#endif 