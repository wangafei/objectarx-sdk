#pragma once
#include "gcadstd.h"

struct GcUt
{
  enum QFormatBitFlags
  {
    kSuppressZeroFeet     = 0x100,
    kSuppressZeroInches   = 0x200,
    kSuppressLeadingZero  = 0x400,
    kSuppressTrailingZero = 0x800,
    kIgnoreUnitMode       = 0x1000,
    kUseAltUnits          = 0x2000
  };
};
