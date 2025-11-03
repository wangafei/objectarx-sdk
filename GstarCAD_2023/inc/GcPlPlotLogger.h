/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCPLPLOTLOGGER_H
#define GCPLPLOTLOGGER_H

class GSOFT_NO_VTABLE GcPlPlotLogger
{
public:

  GcPlPlotLogger() {};
  virtual ~GcPlPlotLogger() {};

  virtual Gcad::ErrorStatus startJob(void) = 0;
  virtual Gcad::ErrorStatus startSheet(void) = 0;
  virtual Gcad::ErrorStatus logTerminalError(const GCHAR *pErrorString) = 0;
  virtual Gcad::ErrorStatus logARIError(const GCHAR *pErrorString) = 0;
  virtual Gcad::ErrorStatus logSevereError(const GCHAR *pErrorString) = 0;
  virtual Gcad::ErrorStatus logError(const GCHAR *pErrorString) = 0;
  virtual Gcad::ErrorStatus logWarning(const GCHAR *pWarningString) = 0;
  virtual Gcad::ErrorStatus logMessage(const GCHAR *pMessageString) = 0;
  virtual Gcad::ErrorStatus logInformation(const GCHAR *pMessageString) = 0;
  virtual Gcad::ErrorStatus endSheet(void) = 0;
  virtual bool errorHasHappenedInSheet(void) const = 0;
  virtual bool warningHasHappenedInSheet(void) const = 0;
  virtual Gcad::ErrorStatus endJob(void) = 0;
  virtual bool errorHasHappenedInJob(void) const = 0;
  virtual bool warningHasHappenedInJob(void) const = 0;
};

#endif 