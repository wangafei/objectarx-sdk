#pragma once
#include "gcadstd.h"
#include "../RxObject.h"

#define GCRX_PE_PTR(a,b) b::cast(a-> \
                                queryX(b::desc()))

#define GCRX_X_CALL(a,b) b::cast(a->x(b::desc()))
