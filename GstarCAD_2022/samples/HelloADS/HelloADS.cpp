#include  <adslib.h>
#include  <rxregsvc.h>
#include "tchar.h"


static int      dofun      (void);
static int      funcload   (void);


extern "C" AcRx::AppRetCode
  acrxEntryPoint(AcRx::AppMsgCode msg, void* appId)
{
  switch(msg) {
  case AcRx::kInitAppMsg:
    acrxDynamicLinker->unlockApplication(appId);
    acrxDynamicLinker->registerAppMDIAware(appId);
    break;
  case AcRx::kInvkSubrMsg:
    dofun();
    break;
  case AcRx::kLoadDwgMsg:
    funcload();
  }
  return AcRx::kRetOK;
}


static int funcload()
{
  return acedDefun(_T("helloworld"), (short)0) ? RTNORM : RTERROR;
}

static int dofun()
{
  if (acedGetFunCode() != 0)
  {
    acdbFail(_T("Received nonexistent function code."));
    return RTERROR;
  }

  ads_printf(_T("\tHello World."));

  return RTNORM;
}
