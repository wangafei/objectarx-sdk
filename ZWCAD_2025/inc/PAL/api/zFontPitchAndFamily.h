#ifndef _PAL_ZFONT_PITCH_AND_FAMILY_H
#define _PAL_ZFONT_PITCH_AND_FAMILY_H
#ifdef PAL
#undef PAL
#endif

namespace ZwSoft
{
    namespace ZwCAD
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
