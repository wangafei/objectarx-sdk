/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBCOLOR_H
#define GD_DBCOLOR_H 1

#include "gsoft.h"
#include "gcadstrc.h"
#include "rxobject.h"
#include "GcDbCore2dDefs.h"     

#pragma pack (push, 8)

class GcCmEntityColor;

class GCBASE_PORT GcCmEntityColor
{
public:
  enum Color {
    kRed,
    kGreen,
    kBlue
  };

  enum ColorMethod {
    kByLayer = 0xC0,
    kByBlock,
    kByColor,
    kByACI,
    kByPen,
    kForeground,
    kLayerOff,
    kLayerFrozen,
    kNone
  };

  enum ACIcolorMethod {
    kACIbyBlock = 0,
    kACIforeground = 7,
    kACIbyLayer = 256,
    kACIclear = 0,
    kACIstandard = 7,
    kACImaximum = 255,
    kACInone = 257,
    kACIminimum = -255,
    kACIfrozenLayer = -32700
  };

public:
  union RGBM {
    Gsoft::UInt32    whole;
    Gsoft::Int16     indirect;
    struct {
      Gsoft::UInt8 blue,
        green,
        red,
        colorMethod;
    } mdata;
    Gsoft::Int32    mnIndirect32;
    Gsoft::Int32    indirect24() const;
  };

public:
  GcCmEntityColor();
  GcCmEntityColor(const GcCmEntityColor & color);
  GcCmEntityColor(ColorMethod eColorMethod);
  GcCmEntityColor(Gsoft::UInt8 red, Gsoft::UInt8 green, Gsoft::UInt8 blue);

  GcCmEntityColor&    operator =  (const GcCmEntityColor& color);
  bool                operator == (const GcCmEntityColor& color) const;
  bool                operator != (const GcCmEntityColor& color) const;


  Gcad::ErrorStatus   setColorMethod(ColorMethod eColorMethod);
  ColorMethod         colorMethod() const;

  Gcad::ErrorStatus   setColor(Gsoft::UInt32 color);
  Gsoft::UInt32       color() const;

  Gcad::ErrorStatus   setColorIndex(Gsoft::Int16 colorIndex);
  Gsoft::Int16        colorIndex() const;

  Gcad::ErrorStatus   setLayerIndex(Gsoft::Int32 layerIndex);
  Gsoft::Int32        layerIndex() const;

  Gcad::ErrorStatus   setPenIndex(Gsoft::UInt16 penIndex);
  Gsoft::UInt16       penIndex() const;

  Gcad::ErrorStatus   setRGB(Gsoft::UInt8 red, Gsoft::UInt8 green, Gsoft::UInt8 blue);
  Gcad::ErrorStatus   setRed(Gsoft::UInt8 red);
  Gcad::ErrorStatus   setGreen(Gsoft::UInt8 green);
  Gcad::ErrorStatus   setBlue(Gsoft::UInt8 blue);
  Gsoft::UInt8        red() const;
  Gsoft::UInt8        green() const;
  Gsoft::UInt8        blue() const;

  bool                isByColor() const;
  bool                isByLayer() const;
  bool                isByBlock() const;
  bool                isByACI()   const;
  bool                isByPen()  const;
  bool                isForeground() const;
  bool                isLayerOff() const;
  bool                isLayerFrozen() const;
  bool                isNone()   const;
  bool                isLayerFrozenOrOff() const;

  Gsoft::UInt32       trueColor() const;
  Gsoft::UInt8        trueColorMethod() const;
  Gcad::ErrorStatus   setTrueColor();
  Gcad::ErrorStatus   setTrueColorMethod();

  static  Gcad::ErrorStatus   setColorMethod(RGBM* rgbm, ColorMethod eColorMethod);
  static  ColorMethod         colorMethod(const RGBM* rgbm);

  static  Gcad::ErrorStatus   setColor(RGBM* rgbm, Gsoft::UInt32 color);
  static  Gsoft::UInt32       color(const RGBM* rgbm);

  static  Gcad::ErrorStatus setColorIndex(RGBM* rgbm, Gsoft::Int16 colorIndex);
  static  Gsoft::Int16        colorIndex(const RGBM* rgbm);

  static  Gcad::ErrorStatus setLayerIndex(RGBM* rgbm, Gsoft::Int32 layerIndex);
  static  Gsoft::Int32        layerIndex(const RGBM* rgbm);

  static  Gcad::ErrorStatus setPenIndex(RGBM* rgbm, Gsoft::UInt16 penIndex);
  static  Gsoft::UInt16       penIndex(const RGBM* rgbm);

  static  Gcad::ErrorStatus    setRGB(RGBM* rgbm,
    Gsoft::UInt8 red,
    Gsoft::UInt8 green,
    Gsoft::UInt8 blue);
  static Gcad::ErrorStatus    setRed(RGBM* rgbm, Gsoft::UInt8 red);
  static Gcad::ErrorStatus    setGreen(RGBM* rgbm, Gsoft::UInt8 green);
  static Gcad::ErrorStatus    setBlue(RGBM* rgbm, Gsoft::UInt8 blue);
  static Gsoft::UInt8         red(const RGBM* rgbm);
  static Gsoft::UInt8         green(const RGBM* rgbm);
  static Gsoft::UInt8         blue(const RGBM* rgbm);

  static  bool                isByColor(const RGBM* rgbm);
  static  bool                isByLayer(const RGBM* rgbm);
  static  bool                isByBlock(const RGBM* rgbm);
  static  bool                isByACI(const RGBM* rgbm);
  static  bool                isByPen(const RGBM* rgbm);
  static  bool                isForeground(const RGBM* rgbm);
  static  bool                isLayerOff(const RGBM* rgbm);
  static  bool                isLayerFrozen(const RGBM* rgbm);
  static  bool                isNone(const RGBM* rgbm);

  static Gsoft::UInt32        trueColor(const RGBM* rgbm);
  static Gsoft::UInt8         trueColorMethod(Gsoft::Int16);
  static Gcad::ErrorStatus    setTrueColor(RGBM* rgbm);
  static Gcad::ErrorStatus    setTrueColorMethod(RGBM* rgbm);

  static Gsoft::UInt32        lookUpRGB(Gsoft::UInt8 colorIndex);
  static Gsoft::UInt8         lookUpACI(Gsoft::UInt8 red, Gsoft::UInt8 green, Gsoft::UInt8 blue);

protected:
  RGBM mRGBM;

public:
  static const Gsoft::UInt8 mLUT[256][3];
};

inline
GcCmEntityColor::GcCmEntityColor()
{
  mRGBM.whole = 0;
  mRGBM.mdata.colorMethod = kByColor;
}

inline
GcCmEntityColor::GcCmEntityColor(const GcCmEntityColor & color)
{
  mRGBM.whole = color.mRGBM.whole;
}

inline
GcCmEntityColor::GcCmEntityColor(ColorMethod eColorMethod)
{
  mRGBM.whole = 0;
  mRGBM.mdata.colorMethod = static_cast<Gsoft::UInt8>(eColorMethod);
}

inline
GcCmEntityColor::GcCmEntityColor(Gsoft::UInt8 red,
  Gsoft::UInt8 green,
  Gsoft::UInt8 blue)
{
  mRGBM.mdata.red = red;
  mRGBM.mdata.green = green;
  mRGBM.mdata.blue = blue;
  mRGBM.mdata.colorMethod = kByColor;
}

inline GcCmEntityColor&
GcCmEntityColor::operator= (const GcCmEntityColor & color)
{
  mRGBM.whole = color.mRGBM.whole;
  return *this;
}

inline bool
GcCmEntityColor::operator==(const GcCmEntityColor& color) const
{
  return mRGBM.whole == color.mRGBM.whole;
}

inline bool
GcCmEntityColor::operator!=(const GcCmEntityColor& color) const
{
  return mRGBM.whole != color.mRGBM.whole;
}

inline GcCmEntityColor::ColorMethod
GcCmEntityColor::colorMethod() const
{
  return (ColorMethod)mRGBM.mdata.colorMethod;
}

inline Gsoft::UInt32
GcCmEntityColor::color() const
{
  return mRGBM.whole;
}

inline Gsoft::Int16 GcCmEntityColor::colorIndex() const
{
  return colorIndex(&mRGBM);
}

inline Gcad::ErrorStatus GcCmEntityColor::setColorMethod(ColorMethod eColorMethod)
{
  return setColorMethod(&mRGBM, eColorMethod);
}

inline Gcad::ErrorStatus GcCmEntityColor::setColor(Gsoft::UInt32 color)
{
  return setColor(&mRGBM, color);
}

inline Gcad::ErrorStatus GcCmEntityColor::setColorIndex(Gsoft::Int16 colorIndex)
{
  return setColorIndex(&mRGBM, colorIndex);
}

inline Gsoft::Int32 GcCmEntityColor::RGBM::indirect24() const
{
  Gsoft::Int32 nRet = this->mnIndirect32;
  if ((nRet & 0x800000) != 0)
    nRet |= 0xff000000;
  else
    nRet &= ~0xff000000;
  return nRet;
}

inline Gcad::ErrorStatus GcCmEntityColor::setLayerIndex(Gsoft::Int32 layerIndex)
{
  return setLayerIndex(&mRGBM, layerIndex);
}

inline Gsoft::Int32 GcCmEntityColor::layerIndex(const RGBM* rgbm)
{
  if (rgbm == nullptr)
    return -1;
  if (rgbm->mdata.colorMethod != kByLayer && rgbm->mdata.colorMethod != kLayerOff)
    return -1;

  return rgbm->indirect24();
}

inline Gsoft::Int32 GcCmEntityColor::layerIndex() const
{
  return layerIndex(&mRGBM);
}

inline Gcad::ErrorStatus GcCmEntityColor::setPenIndex(Gsoft::UInt16 penIndex)
{
  return setPenIndex(&mRGBM, penIndex);
}

inline Gsoft::UInt16 GcCmEntityColor::penIndex(const RGBM* rgbm)
{
  if (rgbm == nullptr)
    return 0xffff;
  if (rgbm->mdata.colorMethod != kByPen)
    return 0xffff;
  return (Gsoft::UInt16)rgbm->indirect;
}

inline Gsoft::UInt16 GcCmEntityColor::penIndex() const
{
  return penIndex(&mRGBM);
}

inline Gsoft::UInt8
GcCmEntityColor::red() const
{
  return mRGBM.mdata.red;
}

inline Gsoft::UInt8
GcCmEntityColor::green() const
{
  return mRGBM.mdata.green;
}

inline Gsoft::UInt8
GcCmEntityColor::blue() const
{
  return mRGBM.mdata.blue;
}

inline bool
GcCmEntityColor::isByColor() const
{
  return mRGBM.mdata.colorMethod == kByColor;
}

inline bool
GcCmEntityColor::isByLayer() const
{
  return (mRGBM.mdata.colorMethod == kByLayer ||
    (mRGBM.mdata.colorMethod == kByACI &&
      mRGBM.indirect == kACIbyLayer)) ? true : false;
}

inline bool
GcCmEntityColor::isByBlock() const
{
  return (mRGBM.mdata.colorMethod == kByBlock ||
    (mRGBM.mdata.colorMethod == kByACI &&
      mRGBM.indirect == kACIbyBlock)) ? true : false;
}

inline bool
GcCmEntityColor::isByACI()   const
{
  return mRGBM.mdata.colorMethod == kByACI;
}

inline bool
GcCmEntityColor::isByPen()   const
{
  return mRGBM.mdata.colorMethod == kByPen;
}

inline bool
GcCmEntityColor::isForeground()   const
{
  return (mRGBM.mdata.colorMethod == kForeground ||
    (mRGBM.mdata.colorMethod == kByACI &&
      mRGBM.indirect == kACIforeground)) ? true : false;
}

inline bool
GcCmEntityColor::isLayerOff() const
{
  return (mRGBM.mdata.colorMethod == kLayerOff ||
    (mRGBM.mdata.colorMethod == kByACI &&
      mRGBM.indirect < 0 &&
      mRGBM.indirect != kACIfrozenLayer)) ? true : false;
}

inline bool
GcCmEntityColor::isLayerFrozen() const
{
  return (mRGBM.mdata.colorMethod == kLayerFrozen ||
    (mRGBM.mdata.colorMethod == kByACI &&
      mRGBM.indirect == kACIfrozenLayer)) ? true : false;
}

inline bool
GcCmEntityColor::isLayerFrozenOrOff() const
{
  return isLayerFrozen() || isLayerOff();
}

inline bool
GcCmEntityColor::isNone()   const
{
  return (mRGBM.mdata.colorMethod == kNone ||
    (mRGBM.mdata.colorMethod == kByACI &&
      mRGBM.indirect == kACInone)) ? true : false;
}

inline Gcad::ErrorStatus GcCmEntityColor::setRGB(Gsoft::UInt8 red,
  Gsoft::UInt8 green, Gsoft::UInt8 blue)
{
  return setRGB(&mRGBM, red, green, blue);
}

inline Gcad::ErrorStatus GcCmEntityColor::setRed(Gsoft::UInt8 red)
{
  return setRed(&mRGBM, red);
}

inline Gcad::ErrorStatus GcCmEntityColor::setGreen(Gsoft::UInt8 green)
{
  return setGreen(&mRGBM, green);
}

inline Gcad::ErrorStatus GcCmEntityColor::setBlue(Gsoft::UInt8 blue)
{
  return setBlue(&mRGBM, blue);
}

inline Gsoft::UInt32 GcCmEntityColor::trueColor() const
{
  return trueColor(&mRGBM);
}

class GSOFT_NO_VTABLE GCBASE_PORT GcCmColorBase
{
public:
  virtual ~GcCmColorBase() {}

  virtual GcCmEntityColor::ColorMethod  colorMethod() const = 0;;
  virtual Gcad::ErrorStatus   setColorMethod(GcCmEntityColor::ColorMethod eColorMethod) = 0;

  virtual bool                isByColor() const = 0;
  virtual bool                isByLayer() const = 0;
  virtual bool                isByBlock() const = 0;
  virtual bool                isByACI()   const = 0;
  virtual bool                isByPen() const = 0;
  virtual bool                isForeground()   const = 0;

  virtual Gsoft::UInt32       color() const = 0;
  virtual Gcad::ErrorStatus   setColor(Gsoft::UInt32 color) = 0;

  virtual Gcad::ErrorStatus   setRGB(Gsoft::UInt8 red, Gsoft::UInt8 green, Gsoft::UInt8 blue) = 0;
  virtual Gcad::ErrorStatus   setRed(Gsoft::UInt8 red) = 0;
  virtual Gcad::ErrorStatus   setGreen(Gsoft::UInt8 green) = 0;
  virtual Gcad::ErrorStatus   setBlue(Gsoft::UInt8 blue) = 0;
  virtual Gsoft::UInt8        red() const = 0;
  virtual Gsoft::UInt8        green() const = 0;
  virtual Gsoft::UInt8        blue() const = 0;

  virtual Gsoft::UInt16       colorIndex() const = 0;
  virtual Gcad::ErrorStatus   setColorIndex(Gsoft::UInt16 colorIndex) = 0;
  virtual Gsoft::UInt16       penIndex() const = 0;
  virtual Gcad::ErrorStatus   setPenIndex(Gsoft::UInt16 penIndex) = 0;

  virtual Gcad::ErrorStatus   setNames(const GCHAR *colorName, const GCHAR *bookName = NULL) = 0;
  virtual const GCHAR *       colorName(void) const = 0;
  virtual const GCHAR *       bookName(void) const = 0;
  virtual const GCHAR *       colorNameForDisplay(void) = 0;
  virtual bool                hasColorName(void) const = 0;
  virtual bool                hasBookName(void) const = 0;
};

class GCBASE_PORT GcCmTransparency
{
public:
  enum transparencyMethod {
    kByLayer = 0,
    kByBlock,
    kByAlpha,
    kErrorValue
  };

  enum {
    kTransparencyByLayer = (unsigned long)kByLayer,
    kTransparencyByBlock = (unsigned long)kByBlock,
    kTransparencySolid = ((unsigned long)(kByAlpha | (0xff << 24))),
    kTransparencyClear = (unsigned long)kByAlpha
  };

  GcCmTransparency() { mAM.whole = kTransparencyByLayer; }
  GcCmTransparency(Gsoft::UInt8 alpha);
  GcCmTransparency(double alphaPercent);
  GcCmTransparency(const GcCmTransparency& other) { mAM.whole = other.mAM.whole; }
  ~GcCmTransparency() {}

  GcCmTransparency& operator=(const GcCmTransparency& other);
  bool operator==(const GcCmTransparency& other) const;
  bool operator!=(const GcCmTransparency& other) const;

  void setAlpha(Gsoft::UInt8 alpha);
  void setAlphaPercent(double alphaPercent);

  void setMethod(transparencyMethod method);

  Gsoft::UInt8 alpha(void) const;
  double alphaPercent(void) const;

  bool isByAlpha(void) const { return (mAM.mdata.method == kByAlpha); }
  bool isByBlock(void) const { return (mAM.mdata.method == kByBlock); }
  bool isByLayer(void) const { return (mAM.mdata.method == kByLayer); }
  bool isInvalid(void) const { return (mAM.mdata.method == kErrorValue); }
  bool isClear(void) const;
  bool isSolid(void) const;

  Gsoft::UInt32   serializeOut(void) const { return mAM.whole; }
  void            serializeIn(Gsoft::UInt32);

private:

  union AM {
    struct {
      Gsoft::UInt8    alpha;
      Gsoft::UInt8    reserved1;
      Gsoft::UInt8    reserved2;
      Gsoft::UInt8    method;
    } mdata;
    Gsoft::UInt32       whole;
  };

  AM mAM;
};

namespace GcCm
{
  enum DialogTabs
  {
    kACITab = 1,
    kTrueColorTab = 2,
    kColorBookTab = 4,
  };

  enum ACIColors
  {
    kACIByBlock = 0,
    kACIRed = 1,
    kACIYellow = 2,
    kACIGreen = 3,
    kACICyan = 4,
    kACIBlue = 5,
    kACIMagenta = 6,
    kACIForeground = 7,
    kACIByLayer = 256,
  };
}

#pragma pack (pop)

#define GSFT_GCCMENTITYCOLOR_DEFINED
#include "gcarrayhelper.h"

#endif 