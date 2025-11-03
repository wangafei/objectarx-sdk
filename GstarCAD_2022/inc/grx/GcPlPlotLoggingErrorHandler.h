#ifndef _GCPLPLOTLOGGINGERRORHANDLER_H
#define _GCPLPLOTLOGGINGERRORHANDLER_H

#include "GcPlPlotErrorHandler.h"

class GcPlPlotLogger;
//class GcPlSystenInternals;

class GcPlPlotLoggingErrorHandler : public GcPlPlotErrorHandler
{
public:
    GCPL_PORT GcPlPlotLoggingErrorHandler();
    GCPL_PORT GcPlPlotLoggingErrorHandler(GcPlPlotLogger *plotLogger);
    GCPL_PORT virtual ~GcPlPlotLoggingErrorHandler();

    GCPL_DECLARE_MEMBERS(GcPlPlotLoggingErrorHandler);

public:

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

};

#endif // _GCPLPLOTLOGGINGERRORHANDLER_H
