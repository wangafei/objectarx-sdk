
#ifndef ZD_DBCOLOR_H
#define ZD_DBCOLOR_H 1

#include "zadesk.h"
#include "zacadstrc.h"
#include "zrxobject.h"
#include "zAcDbCore2dDefs.h"

#pragma pack (push, 8)

class ZcCmEntityColor;

#ifndef ZW_ENABLE_ZcCmColor_DEPRECATED_METHODS
#define ZW_ENABLE_ZcCmColor_DEPRECATED_METHODS
#endif

#if defined(_ZSOFT_IOS_) || defined(LOCAL_SHARDER) || defined(ZW_ENABLE_ZcCmColor_DEPRECATED_METHODS)
#define ZcCmColor_DEPRECATED_METHODS
#endif

class ZCDBCORE2D_PORT ZcCmEntityColor
{
public:
    enum Color { kRed,
                 kGreen,
                 kBlue
    };

    enum ColorMethod {   kByLayer =0xC0,
                         kByBlock,
                         kByColor,
                         kByACI,
                         kByPen,
                         kForeground,
                         kLayerOff,

                         kLayerFrozen,
                         kNone
    };

    enum ACIcolorMethod {kACIbyBlock    = 0,
                         kACIforeground = 7,
                         kACIbyLayer    = 256,

                         kACIclear      = 0,
                         kACIstandard   = 7,
                         kACImaximum    = 255,
                         kACInone       = 257,
                         kACIminimum    = -255,
                         kACIfrozenLayer= -32700
    };

    ZcCmEntityColor     ();
    ZcCmEntityColor     (const ZcCmEntityColor & color);
    ZcCmEntityColor     (ZSoft::UInt8 red,
                         ZSoft::UInt8 green,
                         ZSoft::UInt8 blue);
    ~ZcCmEntityColor() {};
    ZcCmEntityColor&    operator =  (const ZcCmEntityColor& color);
    bool                operator == (const ZcCmEntityColor& color) const;
    bool                operator != (const ZcCmEntityColor& color) const;

    void setNone() { mRGBM.whole = 0; mRGBM.mdata.colorMethod = kNone; }
    void setByBlock() { mRGBM.whole = 0; mRGBM.mdata.colorMethod = kByBlock; }
    void setForeground() { mRGBM.whole = 0; mRGBM.mdata.colorMethod = kForeground; }
    void setByLayer() { mRGBM.whole = 0; mRGBM.mdata.colorMethod = kByLayer; }
    void setLayerOff();

    static ZcCmEntityColor None() { ZcCmEntityColor ec; ec.setNone(); return ec; }
    static ZcCmEntityColor ByBlock() { ZcCmEntityColor ec; ec.setByBlock(); return ec; }
    static ZcCmEntityColor ByLayer() { ZcCmEntityColor ec; ec.setByLayer(); return ec; }
    static ZcCmEntityColor Foreground() { ZcCmEntityColor ec; ec.setForeground(); return ec; }
    static ZcCmEntityColor white() { return ZcCmEntityColor(255, 255, 255); }
    static ZcCmEntityColor black() { return ZcCmEntityColor(0, 0, 0); }

    ColorMethod         colorMethod     () const;

    Zcad::ErrorStatus   setColorIndex   (ZSoft::Int16 colorIndex);
    ZSoft::Int16        colorIndex      () const;

    Zcad::ErrorStatus   setLayerIndex   (ZSoft::Int32 layerIndex);
    ZSoft::Int32        layerIndex      () const;   

    Zcad::ErrorStatus   setPenIndex     (ZSoft::UInt16 penIndex);
    ZSoft::UInt16       penIndex        () const;

    Zcad::ErrorStatus   setRGB  (ZSoft::UInt8 red, 
                                 ZSoft::UInt8 green, 
                                 ZSoft::UInt8 blue);
    ZSoft::UInt8        red     () const;
    ZSoft::UInt8        green   () const;
    ZSoft::UInt8        blue    () const;

    Zcad::ErrorStatus   setCOLORREF(ZSoft::ColorRef cref);
    ZSoft::ColorRef     getCOLORREF() const;

    Zcad::ErrorStatus   setRGB(ZSoft::RGBQuad rgbquad);
    ZSoft::RGBQuad      getRGB() const;

    Zcad::ErrorStatus   setRGBM(ZSoft::UInt32 rgbmValue);
    ZSoft::UInt32       getRGBM() const;

    bool                isByColor   () const;
    bool                isByLayer   () const;
    bool                isByBlock   () const;
    bool                isByACI     ()   const;
    bool                isByPen     ()  const;
    bool                isForeground() const;
    bool                isLayerOff  () const;

    bool                isLayerFrozen() const;
    bool                isNone      ()   const;
    bool                isLayerFrozenOrOff() const;

    bool canResolveRGB() const;

    ZcCmEntityColor makeRGB(ZSoft::ColorRef background_rgb = 0) const;

    ZcCmEntityColor forceRGB(ZSoft::ColorRef background_rgb = 0) const;

    ZcCmEntityColor makeTrueColor() const;

public:

    union RGBM {
        ZSoft::UInt32    whole;
        ZSoft::Int16     indirect;
        struct {
            ZSoft::UInt8 blue,
                         green,
                         red,
                         colorMethod;
        } mdata;
        ZSoft::Int32    mnIndirect32;
    } mRGBM;

    ZSoft::Int32 indirect24() const;
    ZSoft::UInt8 lookUpACI() const;

    static const ZSoft::UInt8 mLUT[256][3];

#ifdef ZcCmColor_DEPRECATED_METHODS
public:
    [[deprecated("Use default constructor followed by call to setNone(), setByBlock(), setByLayer(), etc")]] ZcCmEntityColor(ColorMethod eColorMethod);
    [[deprecated("Prefer explicit setNone(), setByBlock(), setByLayer(), etc calls to this generic call")]] Zcad::ErrorStatus setColorMethod(ColorMethod eColorMethod);
    [[deprecated("Use setRGBM(), setRGB(), or setCOLORREF()")]] Zcad::ErrorStatus setColor(ZSoft::UInt32 color);
    [[deprecated("Use getRGBM(), getRGB() or getCOLORREF()")]] ZSoft::UInt32 color() const;
    [[deprecated("Use setRGB()")]] Zcad::ErrorStatus setRed(ZSoft::UInt8 red);
    [[deprecated("Use setRGB()")]] Zcad::ErrorStatus setGreen(ZSoft::UInt8 green);
    [[deprecated("Use setRGB()")]] Zcad::ErrorStatus setBlue(ZSoft::UInt8 blue);

    [[deprecated("use makeTrueColor()")]] ZSoft::UInt32 trueColor() const;
    [[deprecated("use colorMethod()")]] ZSoft::UInt8 trueColorMethod() const;
    [[deprecated("use makeTrueColor()")]] Zcad::ErrorStatus setTrueColor();
    [[deprecated("use makeTrueColor()")]] Zcad::ErrorStatus setTrueColorMethod();
    [[deprecated("use ZcCmEntityColor::makeRGB()")]]
    static ZSoft::UInt32 lookUpRGB(ZSoft::UInt8 colorIndex);
    [[deprecated("use ZcCmEntityColor::colorIndex()")]]
    static ZSoft::UInt8 lookUpACI(ZSoft::UInt8 red,
                                  ZSoft::UInt8 green,
                                  ZSoft::UInt8 blue);
#endif
};

inline
ZcCmEntityColor::ZcCmEntityColor()
{
    mRGBM.whole = 0;
    mRGBM.mdata.colorMethod = kByColor;
}

inline
ZcCmEntityColor::ZcCmEntityColor (const ZcCmEntityColor & color)
{
    mRGBM.whole = color.mRGBM.whole;
}

inline
ZcCmEntityColor::ZcCmEntityColor(ZSoft::UInt8 red,
                                 ZSoft::UInt8 green,
                                 ZSoft::UInt8 blue)
{
    mRGBM.mdata.red   = red;
    mRGBM.mdata.green = green;
    mRGBM.mdata.blue  = blue;
    mRGBM.mdata.colorMethod = kByColor;
}

inline ZcCmEntityColor&
ZcCmEntityColor::operator= (const ZcCmEntityColor & color)
{
    mRGBM.whole = color.mRGBM.whole;
    return *this;
}

inline bool
ZcCmEntityColor::operator==(const ZcCmEntityColor& color) const
{
    return mRGBM.whole == color.mRGBM.whole;
}

inline bool
ZcCmEntityColor::operator!=(const ZcCmEntityColor& color) const
{
    return mRGBM.whole != color.mRGBM.whole;
}

inline ZcCmEntityColor::ColorMethod
ZcCmEntityColor::colorMethod() const
{
    return (ColorMethod) mRGBM.mdata.colorMethod;
}

inline ZSoft::Int32 ZcCmEntityColor::indirect24() const
{

    ZSoft::Int32 nRet = mRGBM.mnIndirect32;

    if ((nRet & 0x800000) != 0)
        nRet |= 0xff000000;
    else
        nRet &= ~0xff000000;
    return nRet;
}

inline ZSoft::Int32 ZcCmEntityColor::layerIndex() const
{
    if (mRGBM.mdata.colorMethod != kByLayer && mRGBM.mdata.colorMethod != kLayerOff)
        return -1;

    return indirect24();
}

inline ZSoft::UInt16 ZcCmEntityColor::penIndex() const
{
    if (mRGBM.mdata.colorMethod != kByPen)
        return 0xffff;
    return (ZSoft::UInt16)mRGBM.indirect;
}

inline bool
ZcCmEntityColor::isByColor() const
{
    return mRGBM.mdata.colorMethod == kByColor;
}

inline bool
ZcCmEntityColor::isByLayer() const
{
    return (mRGBM.mdata.colorMethod  == kByLayer ||
            (mRGBM.mdata.colorMethod == kByACI   &&
            mRGBM.indirect == kACIbyLayer)) ? true : false;
}

inline bool
ZcCmEntityColor::isByBlock() const
{
    return (mRGBM.mdata.colorMethod  == kByBlock ||
            (mRGBM.mdata.colorMethod == kByACI   &&
            mRGBM.indirect == kACIbyBlock)) ? true : false;
}

inline bool
ZcCmEntityColor::isByACI()   const
{
    return mRGBM.mdata.colorMethod == kByACI;
}

inline bool
ZcCmEntityColor::isByPen()   const
{
    return mRGBM.mdata.colorMethod == kByPen;
}

inline bool
ZcCmEntityColor::isForeground()   const
{
    return (mRGBM.mdata.colorMethod  == kForeground ||
            (mRGBM.mdata.colorMethod == kByACI      &&
            mRGBM.indirect == kACIforeground)) ? true : false;
}

inline bool
ZcCmEntityColor::isLayerOff() const
{
    return (mRGBM.mdata.colorMethod  == kLayerOff ||
            (mRGBM.mdata.colorMethod == kByACI &&
            mRGBM.indirect    <  0 &&
            mRGBM.indirect != kACIfrozenLayer)) ? true : false;
}

inline bool
ZcCmEntityColor::isLayerFrozen() const
{
    return (mRGBM.mdata.colorMethod  == kLayerFrozen ||
            (mRGBM.mdata.colorMethod == kByACI       &&
            mRGBM.indirect == kACIfrozenLayer)) ? true : false;
}

inline bool
ZcCmEntityColor::isLayerFrozenOrOff() const
{
    return isLayerFrozen() || isLayerOff();
}

inline bool
ZcCmEntityColor::isNone()   const
{
    return (mRGBM.mdata.colorMethod  == kNone ||
            (mRGBM.mdata.colorMethod == kByACI       &&
            mRGBM.indirect == kACInone)) ? true : false;
}

#ifdef ZcCmColor_DEPRECATED_METHODS
inline
ZcCmEntityColor::ZcCmEntityColor(ColorMethod eColorMethod)
{
    mRGBM.whole = 0;
    mRGBM.mdata.colorMethod = static_cast<ZSoft::UInt8>(eColorMethod);
}

inline ZSoft::UInt32
ZcCmEntityColor::color() const
{
    return mRGBM.whole;
}


#endif

class ZCDB_PORT ZSOFT_NO_VTABLE ZcCmColorBase
{
public:

    virtual ~ZcCmColorBase() {}

    virtual ZcCmEntityColor::ColorMethod  colorMethod() const = 0;

    virtual void                setNone() = 0;
    virtual void                setByBlock() = 0;
    virtual void                setForeground() = 0;
    virtual void                setLayerOff() = 0;
    virtual void                setByLayer() = 0;

    virtual bool                isByColor() const = 0;
    virtual bool                isByLayer() const = 0;
    virtual bool                isByBlock() const = 0;
    virtual bool                isByACI()   const = 0;
    virtual bool                isByPen () const = 0;
    virtual bool                isForeground()   const = 0;

    virtual Zcad::ErrorStatus   setRGB  (ZSoft::UInt8 red,
                                         ZSoft::UInt8 green,
                                         ZSoft::UInt8 blue) = 0;
    virtual ZSoft::UInt8        red  () const = 0;
    virtual ZSoft::UInt8        green() const = 0;
    virtual ZSoft::UInt8        blue () const = 0;

    virtual Zcad::ErrorStatus   setCOLORREF(ZSoft::ColorRef cref) = 0;
    virtual ZSoft::ColorRef     getCOLORREF() const = 0;

    virtual Zcad::ErrorStatus   setRGB(ZSoft::RGBQuad rgbquad) = 0;
    virtual ZSoft::RGBQuad      getRGB() const = 0;

    virtual Zcad::ErrorStatus   setRGBM(ZSoft::UInt32 rgbmValue) = 0;
    virtual ZSoft::UInt32       getRGBM() const = 0;

    virtual ZSoft::UInt16       colorIndex() const = 0;
    virtual Zcad::ErrorStatus   setColorIndex(ZSoft::UInt16 colorIndex) = 0;
    virtual ZSoft::UInt16       penIndex() const = 0;
    virtual Zcad::ErrorStatus   setPenIndex (ZSoft::UInt16 penIndex) = 0;

    virtual Zcad::ErrorStatus   setNames(const ZTCHAR *colorName,
                                         const ZTCHAR *bookName = NULL) = 0;
    virtual const ZTCHAR *       colorName(void) const = 0;
    virtual const ZTCHAR *       bookName(void) const = 0;
    virtual const ZTCHAR *       colorNameForDisplay(void) = 0;
    virtual bool                hasColorName(void) const = 0;
    virtual bool                hasBookName(void) const = 0;
#ifdef ZcCmColor_DEPRECATED_METHODS
    virtual Zcad::ErrorStatus setColorMethod(ZcCmEntityColor::ColorMethod eColorMethod) = 0;
    virtual ZSoft::UInt32     color() const                                             = 0;
    virtual Zcad::ErrorStatus setColor(ZSoft::UInt32 color)                             = 0;
    virtual Zcad::ErrorStatus setRed(ZSoft::UInt8 red)                                  = 0;
    virtual Zcad::ErrorStatus setGreen(ZSoft::UInt8 green)                              = 0;
    virtual Zcad::ErrorStatus setBlue(ZSoft::UInt8 blue)                                = 0;
#endif
};

class ZCDB_PORT ZcCmTransparency {
public:

    enum transparencyMethod {
                kByLayer = 0,
                kByBlock,
                kByAlpha,

                kErrorValue
            };

    enum {  kTransparencyByLayer    = (unsigned long)kByLayer,
            kTransparencyByBlock    = (unsigned long)kByBlock,
            kTransparencySolid      = ((unsigned long)(kByAlpha | (0xff << 24))),
            kTransparencyClear      = (unsigned long)kByAlpha
    };

    ZcCmTransparency() { mAM.whole = kTransparencyByLayer; }
    ZcCmTransparency(ZSoft::UInt8 alpha);
    ZcCmTransparency(double alphaPercent);
    ZcCmTransparency(const ZcCmTransparency& other) { mAM.whole = other.mAM.whole; }
    ~ZcCmTransparency() {}

    ZcCmTransparency& operator=(const ZcCmTransparency& other);
    bool operator==(const ZcCmTransparency& other) const;
    bool operator!=(const ZcCmTransparency& other) const;

    void setAlpha(ZSoft::UInt8 alpha);
    void setAlphaPercent(double alphaPercent);

    void setMethod(transparencyMethod method);

    ZSoft::UInt8 alpha(void) const;
    double alphaPercent(void) const;

    bool isByAlpha(void) const { return (mAM.mdata.method == kByAlpha); }
    bool isByBlock(void) const { return (mAM.mdata.method == kByBlock); }
    bool isByLayer(void) const { return (mAM.mdata.method == kByLayer); }
    bool isInvalid(void) const { return (mAM.mdata.method == kErrorValue); }
    bool isClear(void) const;
    bool isSolid(void) const;

    ZSoft::UInt32   serializeOut(void) const { return mAM.whole; }
    void            serializeIn(ZSoft::UInt32);

private:

    union AM {
        struct {
            ZSoft::UInt8    alpha;
            ZSoft::UInt8    reserved1;
            ZSoft::UInt8    reserved2;
            ZSoft::UInt8    method;
        } mdata;
        ZSoft::UInt32       whole;
    };

    AM mAM;
};

namespace ZcCm
{
    enum DialogTabs
    {

        kACITab = 1,
        kTrueColorTab = 2,
        kColorBookTab = 4,
    };

    enum ACIColors
    {
        kACIByBlock     = 0,
        kACIRed         = 1,
        kACIYellow      = 2,
        kACIGreen       = 3,
        kACICyan        = 4,
        kACIBlue        = 5,
        kACIMagenta     = 6,
        kACIForeground  = 7,
        kACIByLayer     = 256,
    };
}

#pragma pack (pop)

class ZcDbObjectId;

ZCDBCORE2D_PORT ZcCmEntityColor
zccmResolveEffectiveColorToRGB(const ZcCmEntityColor& effectiveColor, ZcDbObjectId entLayerId);

ZCDBCORE2D_PORT ZcCmEntityColor
zccmAttenuateRGB(const ZcCmEntityColor& in);

#define ZSOFT_ZCCMENTITYCOLOR_DEFINED
#include "zacarrayhelper.h"

#endif
