/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _PAL_FONT_PITCH_AND_FAMILY_H
#define _PAL_FONT_PITCH_AND_FAMILY_H

#ifdef PAL
#undef PAL
#endif

namespace Gssoft
{
  namespace Gscad
  {
    namespace PAL
    {
      namespace FontUtils
      {
        enum class FontPitch
        {
          kDefault,
          kFixed,
          kVariable
        };
        enum class FontFamily
        {
          kDoNotCare = 0,
          kRoman = 16,
          kSwiss = 32,
          kModern = 48,
          kScript = 64,
          kDecorative = 80
        };
      }
    }
  }
};

#endif