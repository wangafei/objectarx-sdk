#pragma once
#include "TD_PackPush.h"

#include "DbHostAppServices.h"

TOOLKIT_EXPORT OdResult oddbSendInitialDwgFileOpenComplete(OdDbDatabase* pDb);
TOOLKIT_EXPORT void oddbTriggerGcadOctTreeReclassification();
TOOLKIT_EXPORT OdResult oddbSetBreak3dQueueForRegen(bool);

extern TOOLKIT_EXPORT OdDbGlobals* getDefaultGlobals();

class TOOLKIT_EXPORT OdDbPasswordedFile
{
protected:
  virtual OdResult tryPassword(const wchar_t* wzPassword) = 0;
  virtual const OdChar* getFullPath() = 0;
public:
  OdResult open(const wchar_t* wszPassword, OdDbHostAppServices::PasswordOptions options);
};