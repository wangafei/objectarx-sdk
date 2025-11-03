/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _rxsrvice_h
#define _rxsrvice_h 1

#include "rxobject.h"
#pragma pack (push, 8)

extern "C"
{
  typedef GcRx::AppRetCode(*DepFuncPtr)(GcRx::AppMsgCode, void*);
}

class GcRxServicePrototype;
class GcRxService;

class GCBASE_PORT GcRxService : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcRxService);
  GcRxService();
  ~GcRxService();

  GcRxObject* getSysInfo() const;
  void        setSysInfo(GcRxObject* sysInfoObj);

  void        addDependency();
  void        removeDependency();

  Gsoft::Boolean unloadable() const;

  DepFuncPtr dependencyFunctionPtr();
  void       setDependencyFunctionPtr(DepFuncPtr);

private:
  GcRxServicePrototype* mpImpService;
};

#pragma pack (pop)
#endif
