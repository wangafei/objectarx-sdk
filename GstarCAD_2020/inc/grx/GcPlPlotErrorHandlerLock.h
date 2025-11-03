#pragma once
#include "../grx/gchar.h"
#include "GcPlObject.h"
#include "GcPlPlotErrorHandler.h"

class GcPlPlotErrorHandler;

class GcPlPlotErrorHandlerLock : public GcPlObject
{
  GCPL_DECLARE_MEMBERS(GcPlPlotErrorHandlerLock);
public:
  enum LockStatus {
    kLocked,
    kUnLocked
  };

  GCPL_PORT GcPlPlotErrorHandlerLock();
  GCPL_PORT GcPlPlotErrorHandlerLock(GcPlPlotErrorHandler* pAppErrHandler, const GCHAR * pAppName);

  GCPL_PORT LockStatus status() const;
  GCPL_PORT bool lock(GcPlPlotErrorHandler* pAppErrHandler, const GCHAR * pAppName);
  GCPL_PORT bool unLock(GcPlPlotErrorHandler* pAppErrHandler);
  GCPL_PORT void getErrorHandler(GcPlPlotErrorHandler*& pAppErrHandler) const;
  GCPL_PORT const GCHAR * appName() const;
};
