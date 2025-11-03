#pragma once

#include "zacedinpt.h"
#include "zacdocman.h"

#ifdef __cplusplus
    extern "C" {
#endif
#pragma pack (push, 8)

ZCAD_PORT bool zcedFiberWorld();

int             zcedCommandS(int rtype, ...);

class ZcApDocument;

int             zcedCmdS(const resbuf*       rb,
               bool          forFutureUse  = false,
               ZcApDocument* pForFutureUse = NULL);

typedef int (*ZcEdCoroutineCallback)(void* pData);

ZCAD_PORT int zcedCommandC(ZcEdCoroutineCallback pCallback,
                           void* pReturnFcnParms,
                           int rtype, ...);
ZCAD_PORT int zcedCmdC(ZcEdCoroutineCallback pCallback,
                       void* pReturnFcnParms,
                       const struct resbuf *rb);

ZCAD_PORT bool zcedPendingCmdCTokens();

ZCAD_PORT bool zcedResumingInvocation();

ZCAD_PORT void zcedCallBackOnCancel();

ZCAD_PORT bool zcedCmdCWasCancelled();

#pragma pack (pop)
#ifdef __cplusplus
    }
#endif 

ZCAD_PORT bool zcedPendingFiberlessDocSwitch(ZcApDocument** pNextActiveDocument = NULL);
