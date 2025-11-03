/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#pragma pack (push, 8)

struct GcUt {
  enum QFormatBitFlags {
    kSuppressZeroFeet = 0x100,
    kSuppressZeroInches = 0x200,
    kSuppressLeadingZero = 0x400,
    kSuppressTrailingZero = 0x800,
    kIgnoreUnitMode = 0x1000,
    kUseAltUnits = 0x2000
  };
};

#pragma pack (pop)