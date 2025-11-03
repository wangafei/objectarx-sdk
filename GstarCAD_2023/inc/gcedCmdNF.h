/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gcedinpt.h"
#include "gcdocman.h"

#ifdef __cplusplus
extern "C" {
#endif
#pragma pack (push, 8)

  GCCORE_PORT bool gcedFiberWorld();

  GCCORE_PORT int             gcedCommandS(int rtype, ...);

  class GcApDocument;

  GCCORE_PORT int             gcedCmdS(const resbuf*       rb,
    bool          forFutureUse = false,
    GcApDocument* pForFutureUse = NULL);

  typedef int(*GcEdCoroutineCallback)(void* pData);

  GCCORE_PORT int gcedCommandC(GcEdCoroutineCallback pCallback,
    void* pReturnFcnParms,
    int rtype, ...);
  GCCORE_PORT int gcedCmdC(GcEdCoroutineCallback pCallback,
    void* pReturnFcnParms,
    const struct resbuf *rb);

  GCCORE_PORT bool gcedPendingCmdCTokens();
  GCCORE_PORT bool gcedResumingInvocation();
  GCCORE_PORT void gcedCallBackOnCancel();
  GCCORE_PORT bool gcedCmdCWasCancelled();

#pragma pack (pop)
#ifdef __cplusplus
}
#endif  

GCCORE_PORT bool gcedPendingFiberlessDocSwitch(GcApDocument** pNextActiveDocument = NULL);