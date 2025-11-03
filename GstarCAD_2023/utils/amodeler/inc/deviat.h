/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_DEVIAT_H
#define GMODELER_INC_DEVIAT_H

#include "global.h"

GMODELER_NAMESPACE_BEGIN

const int kMinApprox = 4;
const int kMaxApprox = 128;

DllImpExp int deviationToApprox(double relDev);

GMODELER_NAMESPACE_END
#endif
