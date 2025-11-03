

#ifndef ZCPLPLOTERRORHANDLER_H
#define ZCPLPLOTERRORHANDLER_H

#include "zacplobject.h"

class ZcPlSystemInternals;
class ZcString;

class ZcPlPlotErrorHandler : public ZcPlObject
{
protected:

#if !defined(_WIN64) && !defined (_ZC64)
    using ZCPL_ULONG_PTR = unsigned long;
#else
    using ZCPL_ULONG_PTR = unsigned __int64;
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

    ZCPL_PORT ZcPlPlotErrorHandler();
    ZCPL_PORT ~ZcPlPlotErrorHandler();

    ZCPL_DECLARE_MEMBERS(ZcPlPlotErrorHandler);

public:
    
    ZCPL_PORT virtual void infoMessage(const ZTCHAR *pMessage);

    ZCPL_PORT virtual int messageBox(const ZTCHAR *pText,
                                     const ZTCHAR *pCaption,
                                     unsigned int uType, 
                                     int defaultReturn);

    ZCPL_PORT virtual void info(ZCPL_ULONG_PTR category,
                                const unsigned int specific,
                                const ZTCHAR *pLocation,
                                const ZTCHAR *pContextData,
                                const ZTCHAR *pRevision);

    ZCPL_PORT virtual ErrorResult warning(ZCPL_ULONG_PTR category,
                                          const unsigned int specific,
                                          const ZTCHAR *pLocation,
                                          const ZTCHAR *pContextData,
                                          const ZTCHAR *pRevision);

    ZCPL_PORT virtual void severeError(ZCPL_ULONG_PTR category,
                                       const unsigned int specific, 
                                       const ZTCHAR *pLocation,
                                       const ZTCHAR *pContextData,
                                       const ZTCHAR *pRevision);

    ZCPL_PORT virtual ErrorResult error(ZCPL_ULONG_PTR category,
                                        const unsigned int specific, 
                                        const ZTCHAR *pLocation,
                                        const ZTCHAR *pContextData,
                                        const ZTCHAR *pRevision);

    ZCPL_PORT virtual ErrorResult ariError(ZCPL_ULONG_PTR category,
                                           const unsigned int specific,
                                           const ZTCHAR *pLocation,
                                           const ZTCHAR *pContextData,
                                           const ZTCHAR *pRevision);

    ZCPL_PORT virtual void terminalError(ZCPL_ULONG_PTR category,
                                         const unsigned int specific,
                                         const ZTCHAR *pLocation,
                                         const ZTCHAR *pContextData,
                                         const ZTCHAR *pRevision);

    ZCPL_PORT virtual void logMessage(const ZTCHAR *pTitle, const ZTCHAR *pMsg);

    ZCPL_PORT virtual bool takeResponsibility(Handler kind) ;

    ZCPL_PORT virtual bool setLogHandle(const ZTCHAR *pFilePathName) ;

    ZCPL_PORT virtual void setQuietMode(bool bQuiet);

    ZCPL_PORT virtual void setLogMode(bool bLog);

    ZCPL_PORT virtual bool quietMode() const;

    ZCPL_PORT virtual bool logMode() const;

    ZCPL_PORT void getProductString(ZcString& pProductString) const;
    ZCPL_PORT void getProgramString(ZcString& pProgramString) const;
    ZCPL_PORT void getCompanyString(ZcString& pCompanyString) const;

    ZCPL_PORT virtual const ZTCHAR* warningTitle() const;
    ZCPL_PORT virtual const ZTCHAR* severeTitle() const;
    ZCPL_PORT virtual const ZTCHAR* errorTitle() const;
    ZCPL_PORT virtual const ZTCHAR* ariTitle() const;
    ZCPL_PORT virtual const ZTCHAR* terminalTitle() const;
    ZCPL_PORT virtual const ZTCHAR* infoTitle() const;

protected:

    ZCPL_PORT void appInfoMessage(const ZTCHAR *pMessage);

    ZCPL_PORT int appMessageBox(const ZTCHAR *pText,
                                const ZTCHAR *pCaption,
                                unsigned int uType, 
                                int defaultReturn);

    ZCPL_PORT void appInfo(ZCPL_ULONG_PTR category,
                           const unsigned int specific,
                           const ZTCHAR *pLocation,
                           const ZTCHAR *pContextData,
                           const ZTCHAR *pRevision);

    ZCPL_PORT ErrorResult appWarning(ZCPL_ULONG_PTR category,
                                     const unsigned int specific,
                                     const ZTCHAR *pLocation,
                                     const ZTCHAR *pContextData,
                                     const ZTCHAR *pRevision);

    ZCPL_PORT void appSevereError(ZCPL_ULONG_PTR category,
                                  const unsigned int specific,
                                  const ZTCHAR *pLocation,
                                  const ZTCHAR *pContextData,
                                  const ZTCHAR *pRevision);

    ZCPL_PORT ErrorResult appError(ZCPL_ULONG_PTR category,
                                   const unsigned int specific,
                                   const ZTCHAR *pLocation,
                                   const ZTCHAR *pContextData,
                                   const ZTCHAR *pRevision);

    ZCPL_PORT ErrorResult appARIError(ZCPL_ULONG_PTR category,
                                      const unsigned int specific,
                                      const ZTCHAR *pLocation,
                                      const ZTCHAR *pContextData,
                                      const ZTCHAR *pRevision);

    ZCPL_PORT void appTerminalError(ZCPL_ULONG_PTR category,
                                    const unsigned int specific,
                                    const ZTCHAR *pLocation,
                                    const ZTCHAR *pContextData,
                                    const ZTCHAR *pRevision);

    ZCPL_PORT void appLogMessage(const ZTCHAR *pTitle, const ZTCHAR *pMsg);

    ZCPL_PORT bool appSetLogHandle(const ZTCHAR *pFilePathName);
};

#endif 
