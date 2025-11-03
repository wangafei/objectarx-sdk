/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef DATAMODELATTRIBUTES_H
#define DATAMODELATTRIBUTES_H

namespace Gtil
{
  class GTIL_EXPORT DataModelAttributes
  {
  public:
    enum BitsPerPixel
    {
      k1,
      k8,
      k16,
      k32,
      k64,
      k128
    };

    enum DataModelType
    {
      kDataModel,
      kRgbModel,
      kPalettedRgbModel,
      kGrayModel,
      kBitonalModel,
      kRgbModel5b,
      kRgbModel10,
      kRgbModel16i,
      kRgbModel16f,
      kRgbModel32f,
      kGrayModel16i,
      kGrayModel16f,
      kGrayModel32f,
      kGrayModel32i
    };

    enum PixelType
    {
      kData1,
      kData8,
      kData16,
      kData32,
      kData64,
      kData128,
      kBitonal,
      kGray,
      kPalettedRgb,
      kRgba,
      kBgra,
      kGray16i,
      kGray16f,
      kGray32f,
      kRgba5b,
      kBgra5b,
      kRgba10i,
      kBgra10i,
      kRgba16i,
      kBgra16i,
      kRgba16f,
      kBgra16f,
      kRgba32f,
      kBgra32f,
      kGray32i,
      kRgba32i,
      kBgra32i
    };

    enum DataType
    {
      kUnknown,
      kUnsignedShort,
      kSignedShort,
      kUnsignedInteger,
      kSignedInteger,
      kFloat16,
      kFloat,
      kBitFields
    };

    enum BitFields
    {
      kFull,
      k5551,
      k565
    };

    enum ChannelOrder
    {
      kSingleChannel,
      kRedGreenBlueAlpha,
      kBlueGreenRedAlpha
    };
  public:
    virtual BitsPerPixel bitsPerPixel() const = 0;

    virtual int bitsUsedPerPixel() const = 0;

    virtual DataModelType dataModelType() const = 0;

    virtual PixelType pixelType() const = 0;

    virtual DataType dataType() const = 0;

    virtual BitFields bitFields() const = 0;

    virtual DataModelAttributes::ChannelOrder channelOrder() const = 0;

  protected:
    virtual ~DataModelAttributes();
  };

  namespace RgbModelAttributes
  {
    enum Channels
    {
      k3Channels,
      k4Channels
    };
    enum Masks
    {
      kLowMask      = 0x001F,
      kMidMask5551  = 0x03E0,
      kMidMask565   = 0x07E0,
      kHighMask5551 = 0x7C00,
      kHighMask565  = 0xF800,
      kAlphaMask    = 0x8000
    };
  }
}
#endif
