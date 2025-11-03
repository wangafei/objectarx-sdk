/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif

#ifndef IMAGEFORMATCODEC_H
namespace Gtil { class ImageFormatCodec; }
#endif
#ifndef FORMATCODECAPIVERSIONINTERFACE_H
namespace Gtil { class GTIL_EXPORT FormatCodecApiVersionInterface; }
#endif
#ifndef PROPERTYSTRINGPROVIDERINTERFACE_H
namespace Gtil { class PropertyStringProviderInterface; }
#endif

#ifndef GTILFORMATS_H
#define GTILFORMATS_H

struct GTIL_EXPORT GtilFormatCodecLibrary
{
  enum AvailableFormats
  {
    kJfif,
    kPng,
    kTiff,
    kBmp,
    kCals,
    kSpot,
    kIg4,
    kPict,
    kRlc,
    kTarga,
    kPcx,
    kFlic,
    kGif,
    kQBTIFF,
    kAAIGrid,
    kBAIGrid,
    kDDS,
    kDem,
    kDoq,
    kDted,
    kECW,
    kOpenEXR,
    kFAST,
    kHDR,
    kJp2,
    kNITF,
    kPsd,
    kSid,
  };

  static int numberOfCodecs();
  static int numberOfCodecsDelayedInit();

  static Gtil::ImageFormatCodec* createImageFormatCodec(AvailableFormats format);

  static const Gtil::FormatCodecApiVersionInterface* getFormatCodecApiVersion(int nCodec);

  static Gtil::ImageFormatCodec* loadFormatCodec(int nCodec);
  static void unloadFormatCodec(int nCodec);

  static Gtil::ImageFormatCodec* getFormatCodec(AvailableFormats cdc);

  static const Gtil::FormatCodecApiVersionInterface* findFormatCodecApiVersion(AvailableFormats cdc);

  static int getFormatPosition(AvailableFormats cdc);

  static void setResourceFileName(const Gtil::char_t* pResourceFile);

  static void setPatentedEncodingSupportEnabled(bool bTurnOnRead, bool bTurnOnWrite);

  static void registerPropertyStringProvider(Gtil::PropertyStringProviderInterface const* pcProvider);
};

#endif