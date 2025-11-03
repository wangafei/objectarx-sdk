/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef IMAGEPIXEL_H
#include "ImagePixel.h"
#endif

#ifndef FORMATCODECPROPERTYINTERFACE_H
#include "FormatCodecPropertyInterface.h"
#endif

#ifndef FORMATCODECCOLORPROPERTY_H
#define FORMATCODECCOLORPROPERTY_H

namespace Gtil
{
  class GTIL_EXPORT FormatCodecColorProperty : public FormatCodecPropertyInterface
  {
  public:
    enum ColorType
    {
      kTransparent,
      kForeground,
      kBackground,
      kCustom
    };
  public:
    FormatCodecColorProperty(ColorType type);
    virtual ~FormatCodecColorProperty();

    virtual FormatCodecPropertyInterface* clone() const;

    virtual ImagePixel getColor() const;

    virtual ColorType getType() const;

    virtual bool setColor(ImagePixel color, ColorType type);

  protected:
    ImagePixel mColor;
    ColorType  mColorType;
  };
}

#endif
