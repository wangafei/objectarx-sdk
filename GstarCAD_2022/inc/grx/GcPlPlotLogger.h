#ifndef GCPLPLOTLOGGER_H
#define GCPLPLOTLOGGER_H

class GcPlPlotLogger
{
public:

    GcPlPlotLogger(){};
    virtual ~GcPlPlotLogger(){};

    // informs the logging service that a job has started
    virtual OdResult startJob(void) = 0;

    // informs the logging service that a sheet within a job has started
    virtual OdResult startSheet(void) = 0;

    // log a terminal error
    virtual OdResult logTerminalError(const GCHAR *pErrorString) = 0;

    // log an Abort, Retry, Ignore error
    virtual OdResult logARIError(const GCHAR *pErrorString) = 0;

    // log a severe error
    virtual OdResult logSevereError(const GCHAR *pErrorString) = 0;

    // log an error
    virtual OdResult logError(const GCHAR *pErrorString) = 0;

    // log a warning
    virtual OdResult logWarning(const GCHAR *pWarningString) = 0;


    // log a message
    virtual OdResult logMessage(const GCHAR *pMessageString) = 0;

    // log an informational message
    virtual OdResult logInformation(const GCHAR *pMessageString) = 0;

    // informs the logging service that a sheet within a job has ended
    virtual OdResult endSheet(void) = 0;

    // returns whether an error was logged during the sheet
    virtual bool errorHasHappenedInSheet(void) const = 0;

    // returns whether a warning was logged during the sheet
    virtual bool warningHasHappenedInSheet(void) const = 0;

    // informs the logging service that a job has ended
    virtual OdResult endJob(void) = 0;

    // returns whether an error was logged during the job
    virtual bool errorHasHappenedInJob(void) const = 0;

    // returns whether a warning was logged during the job
    virtual bool warningHasHappenedInJob(void) const = 0;
};

#endif // GCPLPLOTLOGGER_H
