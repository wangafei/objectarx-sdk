
#ifndef AECMODELER_INC_DEVIAT_H
#define AECMODELER_INC_DEVIAT_H

#include "zglobal.h"

AECMODELER_NAMESPACE_BEGIN

const int kMinApprox = 4;
const int kMaxApprox = 128;

DllImpExp int ZwDeviationToApprox(double relDev);

AECMODELER_NAMESPACE_END

#endif
