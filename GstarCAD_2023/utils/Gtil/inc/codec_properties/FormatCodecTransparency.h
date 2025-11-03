/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef FORMATCODECPROPERTYINTERFACE_H
#include "FormatCodecPropertyInterface.h"
#endif
#ifndef RGBCOLOR_H
namespace Gtil { struct RgbColor; }
#endif

#ifndef FORMATCODECTRANSPARENCY_H
#define FORMATCODECTRANSPARENCY_H

namespace Gtil
{
  class GTIL_EXPORT FormatCodecTransparency : public FormatCodecPropertyInterface
  {
  public:
    enum Model
    {
      k32BitAlpha,
      kPaletteAlpha,
      kGrayAlpha,
      kKeyColorList
    };

  public:
    virtual ~FormatCodecTransparency();

    virtual FormatCodecPropertyInterface* clone() const;

    virtual Model getTransparencyModel() const;

    virtual int numKeyColors() const;

    virtual int keyColorComponentBits() const;

    virtual bool getKeyColors(UInt8* aTransparentRgbTriplets) const;
    virtual bool getKeyColors(RgbColor* aTransparentColors) const;
    virtual bool getKeyColors(Data16* aKeyColorData) const;
    virtual bool getKeyColors(Data32* aKeyColorData) const;
    virtual bool getKeyColors(Data64* aKeyColorData) const;
    virtual void setKeyColors(int nKeyColors, const UInt8* aTransparentRgbTriplets);
    virtual void setKeyColors(int nKeyColors, const Data16* aKeyColorData);
    virtual void setKeyColors(int nKeyColors, const Data32* aKeyColorData);
    virtual void setKeyColors(int nKeyColors, const Data64* aKeyColorData);

    virtual bool getPaletteAlphas(UInt8* aAlphas) const;
    virtual void setPaletteAlphas(UInt8* aAlphas);

    virtual bool getGrayAlphas(UInt8* aAlphas) const;
    virtual void setGrayAlphas(UInt8* aAlphas);

  protected:
    FormatCodecTransparency(Model transparencyType);
    FormatCodecTransparency(const FormatCodecTransparency& other);

  protected:
    Model  mModel;
    int    mnColors;
    int    mnBytes;
    int    mnComponentBits;
    UInt8* maTransparencies;
  };
}

#endif
