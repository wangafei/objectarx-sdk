#pragma once

#define ACRX_ULONG_MAX               GCRX_ULONG_MAX
#define GCRX_ULONG_MAX               ODRX_ULONG_MAX
#define ACRX_ASCII_MAX               GCRX_ASCII_MAX
#define GCRX_ASCII_MAX               ODRX_ASCII_MAX
#define ACRX_EOS                     GCRX_EOS
#define GCRX_EOS                     ODRX_EOS
#define AcRx                         GcRx
#define GcRx                         OdRx

#define acrxEntryPoint               gcrxEntryPoint

#include "adesk.h"

#define NULLFCN static_cast<OdIntPtr>(0)  // A NULL function pointer

#define ODRX_ULONG_MAX 0xFFFFFFFF

#define ODRX_ASCII_MAX 255  /* Same as UCHAR_MAX in <limits.h> */
#define ODRX_EOS 0          /* End of String Indicator */
#include "../RxDefs.h"
