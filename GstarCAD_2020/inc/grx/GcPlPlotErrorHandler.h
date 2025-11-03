#ifndef _GCPLPLOTERRORHANDLER_H
#define _GCPLPLOTERRORHANDLER_H

#include "GcPl.h"
#include "GcPlObject.h"

//class GcPlSystemInternals;

class GcPlPlotErrorHandler : public GcPlObject
{
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
    // Start of functions which may delegate to the application handler.
    GCPL_PORT virtual void infoMessage(const GCHAR *pMessage);

    GCPL_PORT virtual int messageBox(const GCHAR *pText, 
                                     const GCHAR *pCaption,
                                     unsigned int uType, 
                                     int defaultReturn);

    //info error handler.
    GCPL_PORT virtual void info(ULONG_PTR category, 
                                const unsigned int specific,
                                const GCHAR *pLocation, 
                                const GCHAR *pContextData,
                                const GCHAR *pRevision);

    //warning error handler.
    GCPL_PORT virtual ErrorResult warning(ULONG_PTR category, 
                                          const unsigned int specific,
                                          const GCHAR *pLocation,
                                          const GCHAR *pContextData, 
                                          const GCHAR *pRevision);

    //Severe handler
    GCPL_PORT virtual void severeError(ULONG_PTR category, 
                                       const unsigned int specific, 
                                       const GCHAR *pLocation, 
                                       const GCHAR *pContextData, 
                                       const GCHAR *pRevision);

    //Error handler
    GCPL_PORT virtual ErrorResult error(ULONG_PTR category,
                                        const unsigned int specific, 
                                        const GCHAR *pLocation, 
                                        const GCHAR *pContextData, 
                                        const GCHAR *pRevision);

    //Abort/Retry/Ignore handler
    GCPL_PORT virtual ErrorResult ariError(ULONG_PTR category,
                                           const unsigned int specific,
                                           const GCHAR *pLocation,
                                           const GCHAR *pContextData,
                                           const GCHAR *pRevision);

    // Terminal error handler
    GCPL_PORT virtual void terminalError(ULONG_PTR category,
                                         const unsigned int specific,
                                         const GCHAR *pLocation,
                                         const GCHAR *pContextData,
                                         const GCHAR *pRevision);

    // log a message to the log file
    GCPL_PORT virtual void logMessage(const GCHAR *pTitle, const GCHAR *pMsg);

    // End of functions which may delegate to the application handler


    // true if this error handler takes responsibility for a class of errors
    GCPL_PORT virtual bool takeResponsibility(Handler kind) ;

    // set the log file name
    GCPL_PORT virtual bool setLogHandle(const GCHAR *pFilePathName) ;

    // set quiet mode
    GCPL_PORT virtual void setQuietMode(bool bQuiet);

    // set error logging mode
    GCPL_PORT virtual void setLogMode(bool bLog);

    // get the quiet mode of this error handler
    GCPL_PORT virtual bool quietMode() const;

    // get the logging mode of this error handler
    GCPL_PORT virtual bool logMode() const;

    // OEM strings : product, program, and company

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

    // The following parent functions call the corresponding function on the 
    // link handler.
    // If no link handler exists, their behavior is undefined.
    // These functions exist as a service to potential child classes.

    GCPL_PORT void appInfoMessage(const GCHAR *pMessage);

    GCPL_PORT int appMessageBox(const GCHAR *pText, 
                                const GCHAR *pCaption,
                                unsigned int uType, 
                                int defaultReturn);

    //info error handler.
    GCPL_PORT void appInfo(ULONG_PTR category, 
                           const unsigned int specific,
                           const GCHAR *pLocation, 
                           const GCHAR *pContextData,
                           const GCHAR *pRevision);

    //warning error handler.
    GCPL_PORT ErrorResult appWarning(ULONG_PTR category,
                                     const unsigned int specific,
                                     const GCHAR *pLocation,
                                     const GCHAR *pContextData,
                                     const GCHAR *pRevision);

    //Severe handler
    GCPL_PORT void appSevereError(ULONG_PTR category,
                                  const unsigned int specific,
                                  const GCHAR *pLocation,
                                  const GCHAR *pContextData,
                                  const GCHAR *pRevision);

    //Error handler
    GCPL_PORT ErrorResult appError(ULONG_PTR category,
                                   const unsigned int specific,
                                   const GCHAR *pLocation,
                                   const GCHAR *pContextData,
                                   const GCHAR *pRevision);

    //Abort/Retry/Ignore handler
    GCPL_PORT ErrorResult appARIError(ULONG_PTR category,
                                      const unsigned int specific,
                                      const GCHAR *pLocation,
                                      const GCHAR *pContextData,
                                      const GCHAR *pRevision);

    // Terminal error handler
    GCPL_PORT void appTerminalError(ULONG_PTR category,
                                    const unsigned int specific,
                                    const GCHAR *pLocation,
                                    const GCHAR *pContextData,
                                    const GCHAR *pRevision);

    // log a message to the log file
    GCPL_PORT void appLogMessage(const GCHAR *pTitle, const GCHAR *pMsg);

    GCPL_PORT bool appSetLogHandle(const GCHAR *pFilePathName);
};

#endif // _GCPLPLOTERRORHANDLER_H
