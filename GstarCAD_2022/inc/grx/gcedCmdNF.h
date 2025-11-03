#pragma once

#include "gcedinpt.h"
#include "gcdocman.h"

#ifdef __cplusplus
    extern "C" {
#endif
#pragma pack (push, 8)

GCED_DLL_DECL bool gcedFiberWorld();
GCAP_DLL_DECL int gcedCommandS(int rtype, ...);
class GcApDocument;

GCAP_DLL_DECL int gcedCmdS(const resbuf*       rb,
               bool          forFutureUse  = false,
               GcApDocument* pForFutureUse = NULL);

typedef int (*GcEdCoroutineCallback)(void* pData);

GCED_DLL_DECL int gcedCommandC(GcEdCoroutineCallback pCallback,
                           void* pReturnFcnParms,
                           int rtype, ...);
GCED_DLL_DECL int gcedCmdC(GcEdCoroutineCallback pCallback,
                       void* pReturnFcnParms,
                       const struct resbuf *rb);
    
GCED_DLL_DECL bool gcedPendingCmdCTokens();

GCED_DLL_DECL bool gcedResumingInvocation();

GCED_DLL_DECL void gcedCallBackOnCancel();

GCED_DLL_DECL bool gcedCmdCWasCancelled();

#pragma pack (pop)
#ifdef __cplusplus
    }
#endif  /* __cplusplus */

GCED_DLL_DECL bool gcedPendingFiberlessDocSwitch(GcApDocument** pNextActiveDocument = NULL);
