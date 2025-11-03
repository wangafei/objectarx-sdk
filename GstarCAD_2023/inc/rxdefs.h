/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef   _RXDEFS_H_
#define   _RXDEFS_H_

#include "gsoft.h"
#pragma pack (push, 8)

#define NULLFCN        nullptr
#define GCRX_ULONG_MAX 0xFFFFFFFF
#define GCRX_ASCII_MAX 255
#define GCRX_EOS       0

struct GcRx
{
  typedef void(*FcnPtr) ();

  enum DictIterType
  {
    kDictSorted   = 0,
    kDictCollated = 1
  };

  enum Ordering
  {
    kLessThan     = -1,
    kEqual        = 0,
    kGreaterThan  = 1,
    kNotOrderable = 2
  };

  enum AppMsgCode
  {
    kNullMsg         = 0,
    kInitAppMsg      = 1,
    kUnloadAppMsg    = 2,
    kLoadDwgMsg      = 3,
    kUnloadDwgMsg    = 4,
    kInvkSubrMsg     = 5,
    kCfgMsg          = 6,
    kEndMsg          = 7,
    kQuitMsg         = 8,
    kSaveMsg         = 9,
    kDependencyMsg   = 10,
    kNoDependencyMsg = 11,
    kOleUnloadAppMsg = 12,
    kPreQuitMsg      = 13,
    kInitDialogMsg   = 14,
    kEndDialogMsg    = 15,
    kSuspendMsg      = 16,
    kInitTabGroupMsg = 17,
    kEndTabGroupMsg  = 18
  };

  enum AppRetCode
  {
    kRetOK    = 0,
    kRetError = 3
  };
};

#ifndef kLoadADSMsg
#define kLoadADSMsg   kLoadDwgMsg
#define kUnloadADSMsg kUnloadDwgMsg
#endif

class GcRxClass;
typedef void(*AppNameChangeFuncPtr)(const GcRxClass* classObj, GCHAR *& newAppName, int saveVer);

#pragma pack (pop)

#endif
