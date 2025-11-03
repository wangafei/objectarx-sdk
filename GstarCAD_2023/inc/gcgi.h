/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GCGI_H
#define _GCGI_H 1

#include "gsoft.h"

#define GCGI_SERVICES  GCRX_T("GcGiServices")

#include "gcgidefs.h"   

#include "rxobject.h"
#include "GdGChar.h"
#include "dbpl.h"
#include "gemat3d.h"
#include "gemat2d.h"
#include "gepnt2d.h"
#include "dbcolor.h"
#include "gcdb.h"
#include "GcGiStyleAttributes.h"
#include "assert.h"
#include "gcgiparameter.h"
#include "PAL/api/charset.h"
#include "PAL/api/FontPitchAndFamily.h"

#pragma pack (push, 8)

struct GcGiSentScanLines
{
  enum IsmRequestStatus {
    eOk,
    eInvalidInput,
    eInvalidColorDepth,
    eInvalidPixelRequest,
    eInvalidDeliveryMethod,
    eNoValidCompressors,
    eInsufficientMemory
  };

  Gsoft::Int8 *    mpPixelBuffer;
  Gsoft::UInt32    mRowBytes;
  void *           mpImageId;
  Gsoft::Int16     mIsCancelled;
  Gsoft::Int16     mHasFailed;
  Gsoft::UInt32    mBytes;
  IsmRequestStatus mRequestStatus;

};

struct GcGiRequestScanLines
{
  enum IEDitherMethod
  {
    kIEAnyPalette,
    kCustomDithering,
    kCustomDitheringMethod
  };

  enum IEColorSystem
  {
    kBitonal,
    kCMY,
    kCMYK,
    kRGB
  };

  enum ImagePaletteType
  {
    kFromDevice,
    kFromIeWholeImage
  };

  GcGiRequestScanLines()
    : mImageOrg(kGcGiBitonal)
    , mImageOrient(kGcGiXLeftToRightTopFirst)
    , mPaletteType(kFromDevice)
    , mScalingType(kDefaultScale)
    , mScaleFilterType(kDefaultScaleFilter)
    , mRotationFilterType(kDefaultRotationFilter)
  {
  }

  Gsoft::UInt32       mPixelMinX = 0;
  Gsoft::UInt32       mPixelMinY = 0;
  Gsoft::UInt32       mPixelMaxX = 0;
  Gsoft::UInt32       mPixelMaxY = 0;
  GcGePoint2d         mLowerLeft;
  GcGePoint2d         mUpperRight;
  void *              mpImageId = nullptr;
  GcGiImageOrg        mImageOrg;
  GcGiImageOrient     mImageOrient;
  Gsoft::Int16        mWindowId = 0;
  Gsoft::Int16        mColorDepth = 8;
  union {
    Gsoft::Int16 mBackgroundIndex;
    Gsoft::Int8 mBackgroundRGB[3];
  }                   mBackgroundColor;
  union {
    Gsoft::Int16 mTransparentIndex;
    Gsoft::Int8 mTransparentRGB[3];
  } mTransparentColor;
  union {
    Gsoft::Int16 mEntityIndex;
    Gsoft::Int8 mEntityRGB[3];
  }                   mEntityColor;
  Gsoft::Int32        mPaletteIncarnation = 0;
  Gsoft::Int8 *       mpPalette = nullptr;
  Gsoft::Int16        mIsDisplay = 0;
  double              mRasterRatio = 1.0;
  GcGeMatrix2d        mPixelToDc;
  ImagePaletteType    mPaletteType;
  void *              mpDataBuffer = nullptr;
  Gsoft::Int32        mRowWidth = 0;
  Gsoft::Int32        mNumRows;
  Gsoft::Int32 const *mpBoundaryPoints = nullptr;
  Gsoft::UInt32       mnContours = 0;
  Gsoft::Int32 const *mpCounts = nullptr;
  GcGiScaleType          mScalingType;
  GcGiScaleFilterType    mScaleFilterType;
  GcGiRotationFilterType mRotationFilterType;
  short                  mnTotalChunks = 0;
  short                  mnThisChunk = 0;
};

struct GcGiClipBoundary
{
  GcGeVector3d        m_vNormal;
  GcGePoint3d         m_ptPoint;
  GcGePoint2dArray    m_aptPoints;

  GcGeMatrix3d        m_xToClipSpace;
  GcGeMatrix3d        m_xInverseBlockRefXForm;

  Gsoft::Boolean      m_bClippingFront = false;
  Gsoft::Boolean      m_bClippingBack = false;
  double              m_dFrontClipZ = 0.0;
  double              m_dBackClipZ = 0.0;

  Gsoft::Boolean      m_bDrawBoundary = false;
};

class OwnerDraw3d
{
public:
  virtual ~OwnerDraw3d(void) {};
};

enum GcGiColorIntensity
{
  kGcGiMinColorIntensity = 0x0,
  kGcGiColorIntensity1 = 0x1,
  kGcGiColorIntensity2 = 0x2,
  kGcGiColorIntensity3 = 0x3,
  kGcGiColorIntensity4 = 0x4,
  kGcGiColorIntensity5 = 0x5,
  kGcGiColorIntensity6 = 0x6,
  kGcGiMaxColorIntensity = 0x7
};

class GcGiColorRGB
{
public:
  GcGiColorRGB(void)
    : red(0.0)
    , green(0.0)
    , blue(0.0)
  { }

  GcGiColorRGB(double r, double g, double b)
    : red(r)
    , green(g)
    , blue(b)
  { }

  double red;
  double green;
  double blue;
};

inline GcGiColorRGB operator* (const GcGiColorRGB& c1, const GcGiColorRGB& c2)
{
  return GcGiColorRGB(c1.red   * c2.red,
    c1.green * c2.green,
    c1.blue  * c2.blue);
}

inline GcGiColorRGB operator* (const GcGiColorRGB& c, double s)
{
  return GcGiColorRGB(s * c.red,
    s * c.green,
    s * c.blue);
}

inline GcGiColorRGB operator* (double s, const GcGiColorRGB& c)
{
  return c * s;
}

inline GcGiColorRGB operator+ (const GcGiColorRGB& c1, const GcGiColorRGB& c2)
{
  return GcGiColorRGB(c1.red + c2.red,
    c1.green + c2.green,
    c1.blue + c2.blue);
}

class GcGiColorRGBA
{
public:
  GcGiColorRGBA(void)
    : red(0.0)
    , green(0.0)
    , blue(0.0)
    , alpha(1.0)
  { }

  GcGiColorRGBA(double r, double g, double b, double a)
    : red(r)
    , green(g)
    , blue(b)
    , alpha(a)
  { }

  double red;
  double green;
  double blue;
  double alpha;
};

inline GcGiColorRGBA operator* (const GcGiColorRGBA& c1, const GcGiColorRGBA& c2)
{
  return GcGiColorRGBA(c1.red   * c2.red,
    c1.green * c2.green,
    c1.blue  * c2.blue,
    c1.alpha * c2.alpha);
}

inline GcGiColorRGBA operator*(const GcGiColorRGBA& c, double s)
{
  return GcGiColorRGBA(s * c.red,
    s * c.green,
    s * c.blue,
    s * c.alpha);
}

inline GcGiColorRGBA operator* (double s, const GcGiColorRGBA& c)
{
  return c * s;
}

inline GcGiColorRGBA operator+ (const GcGiColorRGBA& c1, const GcGiColorRGBA& c2)
{
  return GcGiColorRGBA(c1.red + c2.red,
    c1.green + c2.green,
    c1.blue + c2.blue,
    c1.alpha + c2.alpha);
}

class GcGiPixelBGRA32
{
public:
  GcGiPixelBGRA32()
  {
    m_bgra.b = 0;
    m_bgra.g = 0;
    m_bgra.r = 0;
    m_bgra.a = 255;
  }

  GcGiPixelBGRA32(Gsoft::UInt32 bgra)
    : m_whole(bgra)
  { }

  GcGiPixelBGRA32(Gsoft::UInt8 blue,
    Gsoft::UInt8 green,
    Gsoft::UInt8 red,
    Gsoft::UInt8 alpha)
  {
    m_bgra.b = blue;
    m_bgra.g = green;
    m_bgra.r = red;
    m_bgra.a = alpha;
  }

  Gsoft::UInt32     getBGRA() const;
  Gsoft::UInt32     getRGBA() const;
  Gsoft::UInt8      blue() const;
  Gsoft::UInt8      green() const;
  Gsoft::UInt8      red() const;
  Gsoft::UInt8      alpha() const;

  void setBGRA(Gsoft::UInt32 bgra);
  void setBGRA(Gsoft::UInt8 blue,
    Gsoft::UInt8 green,
    Gsoft::UInt8 red,
    Gsoft::UInt8 alpha);
  void setRGBA(Gsoft::UInt32 rgba);
  void setRGBA(Gsoft::UInt8 red,
    Gsoft::UInt8 green,
    Gsoft::UInt8 blue,
    Gsoft::UInt8 alpha);
  void setBlue(Gsoft::UInt8 blue);
  void setGreen(Gsoft::UInt8 green);
  void setRed(Gsoft::UInt8 red);
  void setAlpha(Gsoft::UInt8 alpha);

private:
  union {
    Gsoft::UInt32 m_whole;
#if defined(_GSOFT_WINDOWS_)
    struct PIXEL {
#else
    struct {
#endif
      Gsoft::UInt8  b, g, r, a;
    }m_bgra;
  };
};

inline Gsoft::UInt32 GcGiPixelBGRA32::getBGRA() const
{
  return m_whole;
}

inline Gsoft::UInt32 GcGiPixelBGRA32::getRGBA() const
{
  return (Gsoft::UInt32)(m_bgra.a) << 24
    | (Gsoft::UInt32)(m_bgra.b) << 16
    | (Gsoft::UInt32)(m_bgra.g) << 8
    | (Gsoft::UInt32)(m_bgra.r);
}

inline Gsoft::UInt8 GcGiPixelBGRA32::blue() const
{
  return m_bgra.b;
}

inline Gsoft::UInt8 GcGiPixelBGRA32::green() const
{
  return m_bgra.g;
}

inline Gsoft::UInt8 GcGiPixelBGRA32::red() const
{
  return m_bgra.r;
}

inline Gsoft::UInt8 GcGiPixelBGRA32::alpha() const
{
  return m_bgra.a;
}

inline void GcGiPixelBGRA32::setBGRA(Gsoft::UInt32 bgra)
{
  m_whole = bgra;
}

inline void GcGiPixelBGRA32::setBGRA(Gsoft::UInt8 blue,
  Gsoft::UInt8 green,
  Gsoft::UInt8 red,
  Gsoft::UInt8 alpha)
{
  m_bgra.b = blue;
  m_bgra.g = green;
  m_bgra.r = red;
  m_bgra.a = alpha;
}

inline void GcGiPixelBGRA32::setRGBA(Gsoft::UInt32 rgba)
{
  m_bgra.r = (Gsoft::UInt8)(rgba & 0x000000FF);
  m_bgra.g = (Gsoft::UInt8)((rgba & 0x0000FF00) >> 8);
  m_bgra.b = (Gsoft::UInt8)((rgba & 0x00FF0000) >> 16);
  m_bgra.a = (Gsoft::UInt8)((rgba & 0xFF000000) >> 24);
}

inline void GcGiPixelBGRA32::setRGBA(Gsoft::UInt8 red,
  Gsoft::UInt8 green,
  Gsoft::UInt8 blue,
  Gsoft::UInt8 alpha)
{
  m_bgra.r = red;
  m_bgra.g = green;
  m_bgra.b = blue;
  m_bgra.a = alpha;
}

inline void GcGiPixelBGRA32::setBlue(Gsoft::UInt8 blue)
{
  m_bgra.b = blue;
}

inline void GcGiPixelBGRA32::setGreen(Gsoft::UInt8 green)
{
  m_bgra.g = green;
}

inline void GcGiPixelBGRA32::setRed(Gsoft::UInt8 red)
{
  m_bgra.r = red;
}

inline void GcGiPixelBGRA32::setAlpha(Gsoft::UInt8 alpha)
{
  m_bgra.a = alpha;
}

class GcGiImageBGRA32
{
public:
  GcGiImageBGRA32()
    : m_nImageWidth(0)
    , m_nImageHeight(0)
    , m_pImageData(NULL)
  { }

  GcGiImageBGRA32(Gsoft::UInt32 imageWidth,
    Gsoft::UInt32 imageHeight,
    GcGiPixelBGRA32* imageData)
    : m_nImageWidth(imageWidth)
    , m_nImageHeight(imageHeight)
    , m_pImageData(imageData)
  { }

  GcGiPixelBGRA32* image() const;
  Gsoft::UInt32    width() const;
  Gsoft::UInt32    height() const;

  void setImage(Gsoft::UInt32 imageWidth,
    Gsoft::UInt32 imageHeight,
    GcGiPixelBGRA32* imageData);

private:
  GcGiPixelBGRA32* m_pImageData;
  Gsoft::UInt32 m_nImageWidth;
  Gsoft::UInt32 m_nImageHeight;
};

inline GcGiPixelBGRA32* GcGiImageBGRA32::image() const
{
  return m_pImageData;
}

inline Gsoft::UInt32 GcGiImageBGRA32::width() const
{
  return m_nImageWidth;
}

inline Gsoft::UInt32 GcGiImageBGRA32::height() const
{
  return m_nImageHeight;
}

inline void GcGiImageBGRA32::setImage(Gsoft::UInt32 imageWidth,
  Gsoft::UInt32 imageHeight,
  GcGiPixelBGRA32* imageData)
{
  m_nImageWidth = imageWidth;
  m_nImageHeight = imageHeight;
  m_pImageData = imageData;
}

class GcGiSubEntityTraits;
class GcGiDrawableTraits;
class GcGiSubEntityTraitsImp;
class GcGiWorldGeometry;
class GcGiViewport;
class GcGiViewportGeometry;
class GcGiImpEdgeData;
class GcGiImpFaceData;
class GcGiImpVertexData;
class GcGiImpTextStyle;
class GcGiImpPolyline;
class GcGiTextStyle;
class GcGiEdgeData;
class GcGiFaceData;
class GcGiVertexData;
class OwnerDraw;
class GcGiImpVariant;
class GcGiVariant;
class GcGiContextImp;
class GcGiContext;
class GcGiCommonDraw;
class GcGiGeometry;
class GcCmEntityColor;
struct TextParams;
struct FontInfo;
class GcGiMapper;
class GcGiViewportTraits;
class GcGiVisualStyleTraits;
class GcGiContextualColors;
class GcGiGdiDrawObject;
class GcGiImpHatchPatternDefinition;
class GcGiImpHatchPattern;
class GcGiFill;
class GcGiImpFill;
class GcGiImpGradientFill;
class GcUniqueString;
class GcFontHandle;

typedef void(*GcGiWorldSegmentCallback)(const GcGePoint3d *);

GCBASE_PORT bool gcgiIsValidClipBoundary(const GcGePoint2dArray& pts);

GCBASE_PORT Gcad::ErrorStatus gcgiGetRegenBlockRefStack(GcDbObjectIdArray& blkRefs);

class GCBASE_PORT GcGiVariant : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcGiVariant);

  GcGiVariant(void);
  ~GcGiVariant(void);
  GcGiVariant(const GcGiVariant & value);

  GcGiVariant & operator= (const GcGiVariant & value);
  virtual bool  operator==(const GcGiVariant & value) const;

  Gcad::ErrorStatus copyFrom(const GcRxObject* other) override;

  enum VariantType
  {
    kUndefined = 0,
    kBoolean,
    kInt,
    kDouble,
    kColor,
    kString,
    kTable,
  };

  class EnumType
  {
  public:
    explicit EnumType(int value) : m_value(value) { }

    template <typename T>
    operator T () { return static_cast<T>(m_value); }

    template <typename T>
    bool operator== (T right) const { return static_cast<int>(right) == m_value; }

    template <typename T>
    bool operator!= (T right) const { return !(*this == right); }

  protected:
    int m_value;
  };

  GcGiVariant(bool);
  GcGiVariant(Gsoft::Int32);
  GcGiVariant(double);
  GcGiVariant(const GcCmColor&);
  GcGiVariant(const GCHAR *);

  VariantType type() const;

  void                set(bool);
  void                set(Gsoft::Int32);
  void                set(double);
  void                set(const GcCmColor&);
  void                set(const GCHAR *);

  bool                asBoolean() const;
  int                 asInt() const;
  double              asDouble() const;
  GcCmColor           asColor() const;
  GcString            asString() const;

  float               asFloat() const;
  char                asChar() const;
  unsigned char       asUchar() const;
  short               asShort() const;
  unsigned short      asUshort() const;
  unsigned int        asUint() const;
  Gsoft::Int32        asLong() const;
  Gsoft::UInt32       asUlong() const;
  EnumType            asEnum() const;


  Gcad::ErrorStatus   getElem(const GCHAR * pKey, GcGiVariant & value) const;
  const GcGiVariant*  getElem(const GCHAR * pKey) const;
  void                setElem(const GCHAR * pKey, const GcGiVariant&);
  void                deleteElem(const GCHAR * pKey);

  int                 getElemCount() const;
  Gcad::ErrorStatus   getElemAt(int nIndex, GcString &, GcGiVariant &) const;
  Gcad::ErrorStatus   getElemAt(int nIndex, GCHAR*&, GcGiVariant &) const;
  GcGiVariant*        getElemAt(int nIndex, GcString &) const;
  GcGiVariant*        getElemAt(int nIndex, GCHAR*&) const;

  static bool         isEquivalent(const GcGiVariant*, const GcGiVariant*);

private:
  GcGiImpVariant * mpGcGiImpVariant;
};

inline Gcad::ErrorStatus GcGiVariant::getElemAt(int nIndex, GCHAR*&pStr, GcGiVariant &var) const
{
  GcString sElem;
  const Gcad::ErrorStatus es = this->getElemAt(nIndex, sElem, var);
  if (es != Gcad::eOk)
    pStr = nullptr;
  else
    ::gcutNewString(sElem.constPtr(), pStr);
  return es;
}
inline GcGiVariant * GcGiVariant::getElemAt(int nIndex, GCHAR*&pStr) const
{
  GcString sElem;
  GcGiVariant *pVar = this->getElemAt(nIndex, sElem);
  ::gcutNewString(sElem.constPtr(), pStr);
  return pVar;
}
template <typename T>
inline bool operator== (T left, const GcGiVariant::EnumType right)
{
  return (right == left);
}

template <typename T>
inline bool operator!= (T left, const GcGiVariant::EnumType right)
{
  return (right != left);
}

class GcGiKernelDescriptor : public GcArray<const GcUniqueString *>
{
public:
  void addRequirement(const GcUniqueString *capability)
  {
    if (capability != nullptr)
      append(capability);
  }

  bool supports(const GcUniqueString *capability) const
  {
    return capability ? contains(capability) : false;
  }

  bool supports(const GcGiKernelDescriptor& desc) const
  {
    int len = desc.length();
    for (int i = 0; i < len; i++)
    {
      if (!contains(desc[i]) && desc[i] != nullptr)
        return false;
    }
    return true;
  }
};

class GcGiGraphicsKernel
{
public:
  virtual ~GcGiGraphicsKernel() { }
  virtual const GcGiKernelDescriptor &getDescriptor(void) const { return m_descriptor; }

private:
  GcGiKernelDescriptor m_descriptor;
};

#pragma warning (push)
#pragma warning (disable : 4100)        

class GCBASE_PORT GcGiContext : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcGiContext);

  virtual Gsoft::Boolean   isPsOut() const = 0;
  virtual Gsoft::Boolean   isPlotGeneration() const = 0;
  virtual GcDbDatabase    *database() const = 0;
  virtual bool             isBoundaryClipping() const = 0;

  virtual class GcGiGraphicsKernel &graphicsKernel() { static GcGiGraphicsKernel kernel; return kernel; }

  virtual void             disableFastMoveDrag() const { }

  virtual bool isNesting() const { return false; }

  virtual GcCmEntityColor  effectiveColor()         const { return GcCmEntityColor(); }
  virtual GcDb::LineWeight byBlockLineWeight()      const { return GcDb::kLnWt000; }
  virtual GcDbObjectId     byBlockPlotStyleNameId() const { return GcDbObjectId::kNull; }
  virtual GcDbObjectId     byBlockMaterialId()      const { return GcDbObjectId::kNull; }

  virtual bool supportsTrueTypeText() { return false; }
  virtual bool supportsOwnerDraw() { return false; }
  virtual bool supportsFillTrait() const { return false; }

  virtual Gsoft::Boolean  supportsFastRenderBuffer() const { return Gsoft::kFalse; }

  virtual Gsoft::Boolean  supportsNativePointCloudRender() const { return Gsoft::kFalse; }

  virtual GcGiContextImp *getImpPtr() { return nullptr; }
  virtual const GcGiContextImp *getConstImpPtr() const { return nullptr; }

protected:
  friend class GcGiTextHook;
  friend class CShFont;
  friend class GcDbImpText;

  virtual GcGiWorldSegmentCallback wSegTaker() const { return nullptr; }
  virtual int getTrueTypeBoundingBox(GcGePoint3d const &,
    const wchar_t *,
    int, TextParams const *,
    GcGePoint3d *, float *) {
    return 0;
  }

  virtual int getTrueTypeTextExtents(GCHAR const *, Charset, double,
    int, int,
    int, short, short, double, double,
    GcGePoint2d &, GcGePoint2d &) {
    return -1;
  }

  virtual int setTrueTypeTransform(const GcGePoint3d &, const GcGeVector3d &,
    double, double, double, bool, bool) {
    return 0;
  }

  virtual int drawTrueTypeText(const GCHAR *, double, int, bool,
    const TextParams &, Charset) {
    return 0;
  }
  virtual int restoreTrueTypeTransform() { return 0; }
  virtual void bypassHiddenLineRemoval() { }
  virtual int setTextStyle(int);
  virtual GcFontHandle* loadTrueTypeFont(const GCHAR *, bool, bool, Charset, int, FontInfo &) { return nullptr; }
};

class GCBASE_PORT GcGiCommonDraw : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcGiCommonDraw);
  virtual GcGiRegenType        regenType() const = 0;
  virtual Gsoft::Boolean       regenAbort() const = 0;
  virtual GcGiSubEntityTraits &subEntityTraits() const = 0;
  virtual GcGiGeometry        *rawGeometry() const = 0;
  virtual Gsoft::Boolean       isDragging() const = 0;

  virtual double               deviation(const GcGiDeviationType,
    const GcGePoint3d &) const = 0;
  virtual Gsoft::UInt32        numberOfIsolines() const = 0;
  virtual GcGiContext         *context() = 0;
  virtual bool                 secondaryCall() const { return false; }
};

class GCBASE_PORT GcGiWorldDraw : public GcGiCommonDraw
{
public:
  GCRX_DECLARE_MEMBERS(GcGiWorldDraw);
  virtual GcGiWorldGeometry&      geometry() const = 0;
};

class GCBASE_PORT GcGiViewportDraw : public GcGiCommonDraw
{
public:
  GCRX_DECLARE_MEMBERS(GcGiViewportDraw);
  virtual GcGiViewport&        viewport() const = 0;
  virtual GcGiViewportGeometry& geometry() const = 0;
  virtual Gsoft::UInt32        sequenceNumber() const = 0;
  virtual Gsoft::Boolean       isValidId(const Gsoft::ULongPtr gcgiId) const = 0;
  virtual GcDbObjectId         viewportObjectId() const = 0;
};

class GCBASE_PORT GcGiViewport : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcGiViewport);

  virtual void getModelToEyeTransform(GcGeMatrix3d&) const = 0;
  virtual void getEyeToModelTransform(GcGeMatrix3d&) const = 0;
  virtual void getWorldToEyeTransform(GcGeMatrix3d&) const = 0;
  virtual void getEyeToWorldTransform(GcGeMatrix3d&) const = 0;

  virtual Gsoft::Boolean isPerspective() const = 0;
  virtual Gsoft::Boolean doPerspective(GcGePoint3d&) const = 0;
  virtual Gsoft::Boolean doInversePerspective(GcGePoint3d&) const = 0;

  virtual void getNumPixelsInUnitSquare(const GcGePoint3d& givenWorldpt,
    GcGePoint2d& pixelArea,
    bool includePerspective = true) const = 0;

  virtual void getCameraLocation(GcGePoint3d& location) const = 0;
  virtual void getCameraTarget(GcGePoint3d& target) const = 0;
  virtual void getCameraUpVector(GcGeVector3d& upVector) const = 0;

  virtual Gsoft::ULongPtr viewportId() const = 0;
  virtual Gsoft::Int16  acadWindowId() const = 0;
  virtual void getViewportDcCorners(GcGePoint2d& lower_left,
    GcGePoint2d& upper_right) const = 0;

  virtual Gsoft::Boolean getFrontAndBackClipValues(Gsoft::Boolean& clip_front,
    Gsoft::Boolean& clip_back,
    double& front,
    double& back) const = 0;

  virtual double linetypeScaleMultiplier() const = 0;
  virtual double linetypeGenerationCriteria() const = 0;
  virtual Gsoft::Boolean layerVisible(const GcDbObjectId &) const { return Gsoft::kTrue; }
  virtual GcGeVector3d viewDir() const { return GcGeVector3d::kZAxis; }
  virtual const GcGiContextualColors* contextualColors() const { return NULL; }
};

class GCBASE_PORT GcGiContextualColors : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcGiContextualColors);

  virtual Gsoft::UInt32 gridMajorLines() const = 0;
  virtual Gsoft::UInt32 gridMinorLines() const = 0;
  virtual Gsoft::UInt32 gridAxisLines() const = 0;
  virtual int gridMajorLineTintXYZ() const = 0;
  virtual int gridMinorLineTintXYZ() const = 0;
  virtual int gridAxisLineTintXYZ() const = 0;

  virtual Gsoft::UInt32 lightGlyphs() const = 0;
  virtual Gsoft::UInt32 lightHotspot() const = 0;
  virtual Gsoft::UInt32 lightFalloff() const = 0;
  virtual Gsoft::UInt32 lightStartLimit() const = 0;
  virtual Gsoft::UInt32 lightEndLimit() const = 0;

  virtual Gsoft::UInt32 cameraGlyphs() const = 0;
  virtual Gsoft::UInt32 cameraFrustrum() const = 0;
  virtual Gsoft::UInt32 cameraClipping() const = 0;

  virtual void setContextFlags(Gsoft::UInt32 flg, bool set = true) = 0;
  virtual bool flagsSet(Gsoft::UInt32 flg) const = 0;
};

class GcGiContextualColors2 : public GcGiContextualColors
{
public:
  GCRX_DECLARE_MEMBERS(GcGiContextualColors2);

  virtual GcCmColor webMeshColor(void) const = 0;
  virtual GcCmColor webMeshMissingColor(void) const = 0;
  virtual GcCmColor lightShapeColor(void) const = 0;
  virtual GcCmColor lightDistanceColor(void) const = 0;
};

#define GcGiSelectionMarkerGCADReserveStart         (-2147483647 - 1)   
#define GcGiSelectionMarkerGCADReserveEnd           (GcGiSelectionMarkerGCADReserveStart + 65535)

#define GcGiSelectionMarkerGCADSelectionPreviewOff  (GcGiSelectionMarkerGCADReserveStart + 1)   
#define GcGiSelectionMarkerGCADSelectionPreviewOn   (GcGiSelectionMarkerGCADReserveStart + 2)   

class GCBASE_PORT GcGiSubEntityTraits : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcGiSubEntityTraits);

  enum DrawFlags
  {
    kNoDrawFlags = 0,
    kDrawBackfaces = 1,
    kDrawHatchGroup = 2,
    kDrawFrontfacesOnly = 4,
    kDrawGradientFill = 8,
    kDrawSolidFill = 16,
    kDrawNoLineWeight = 32,
    kDrawNoOptimization = 64,
    kDrawUseGcGiEntityForDgnLineType = 128,
    kDrawFillTextBoundaryStart = 256,
    kDrawFillTextBoundaryEnd = 512,
    kDrawFillSelectionWindow = 1024,
    kDrawNoForceByLayer = 2048
  };

  enum ShadowFlags
  {
    kShadowsCastAndReceive = 0x00,
    kShadowsDoesNotCast = 0x01,
    kShadowsDoesNotReceive = 0x02,
    kShadowsIgnore = kShadowsDoesNotCast | kShadowsDoesNotReceive,
  };

  enum SelectionFlags
  {
    kNoSelectionFlags = 0x00,
    kSelectionIgnore = 0x01
  };

  virtual void              setColor(const Gsoft::UInt16 color) = 0;
  virtual void              setTrueColor(const GcCmEntityColor& color) = 0;
  virtual void              setLayer(const GcDbObjectId layerId) = 0;
  virtual void              setLineType(const GcDbObjectId linetypeId) = 0;
  virtual void              setSelectionMarker(const Gsoft::LongPtr markerId) = 0;
  virtual void              setFillType(const GcGiFillType) = 0;
  virtual void              setLineWeight(const GcDb::LineWeight lw) = 0;
  virtual void              setLineTypeScale(double dScale = 1.0) = 0;
  virtual void              setThickness(double dThickness) = 0;
  virtual void              setVisualStyle(const GcDbObjectId visualStyleId);
  virtual void              setPlotStyleName(GcDb::PlotStyleNameType,
    const GcDbObjectId & = GcDbObjectId::kNull) { }
  virtual void              setMaterial(const GcDbObjectId materialId);
  virtual void              setMapper(const GcGiMapper * mapper);
  virtual void              setSectionable(bool bSectionable);
  virtual Gcad::ErrorStatus setDrawFlags(Gsoft::UInt32 flags);
  virtual Gcad::ErrorStatus setShadowFlags(ShadowFlags flags);
  virtual void              setSelectionGeom(bool bSelectionflag);
  virtual void              setTransparency(const GcCmTransparency &transparency);
  virtual void              setFill(const GcGiFill* pFill);

  virtual Gsoft::UInt16           color(void) const = 0;
  virtual GcCmEntityColor         trueColor(void) const = 0;
  virtual GcDbObjectId            layerId(void) const = 0;
  virtual GcDbObjectId            lineTypeId(void) const = 0;
  virtual GcGiFillType            fillType(void) const = 0;
  virtual GcDb::LineWeight        lineWeight(void) const = 0;
  virtual double                  lineTypeScale(void) const = 0;
  virtual double                  thickness(void) const = 0;
  virtual GcDbObjectId            visualStyle(void) const;
  virtual GcDb::PlotStyleNameType getPlotStyleNameId(GcDbObjectId &) const
  {
    return GcDb::kPlotStyleNameByLayer;
  }
  virtual GcDbObjectId            materialId(void) const;
  virtual const GcGiMapper *      mapper(void) const;
  virtual bool                    sectionable(void) const;
  virtual Gsoft::UInt32           drawFlags(void) const;
  virtual ShadowFlags             shadowFlags(void) const;
  virtual bool                    selectionGeom(void) const;
  virtual GcCmTransparency        transparency(void) const;
  virtual const GcGiFill*         fill(void) const;

  virtual void pushMarkerOverride(bool, const Gsoft::LongPtr) { }
  virtual void popMarkerOverride(void) { }
  virtual void clearMarkerOverride(void) { }
};

inline void
GcGiSubEntityTraits::setMaterial(const GcDbObjectId)
{
}

inline GcDbObjectId
GcGiSubEntityTraits::materialId(void) const
{
  return GcDbObjectId::kNull;
}

inline
void GcGiSubEntityTraits::setMapper(const GcGiMapper *)
{
}

inline const GcGiMapper *
GcGiSubEntityTraits::mapper(void) const
{
  return NULL;
}

inline void
GcGiSubEntityTraits::setVisualStyle(GcDbObjectId)
{
}

inline GcDbObjectId
GcGiSubEntityTraits::visualStyle(void) const
{
  return GcDbObjectId::kNull;
}

inline void
GcGiSubEntityTraits::setSectionable(bool)
{
}

inline bool
GcGiSubEntityTraits::sectionable(void) const
{
  return false;
}

inline Gcad::ErrorStatus
GcGiSubEntityTraits::setDrawFlags(Gsoft::UInt32)
{
  return Gcad::eNotImplementedYet;
}

inline Gsoft::UInt32
GcGiSubEntityTraits::drawFlags(void) const
{
  return 0;
}

inline Gcad::ErrorStatus
GcGiSubEntityTraits::setShadowFlags(ShadowFlags)
{
  return Gcad::eNotImplementedYet;
}

inline GcGiSubEntityTraits::ShadowFlags
GcGiSubEntityTraits::shadowFlags(void) const
{
  return kShadowsCastAndReceive;
}

inline void
GcGiSubEntityTraits::setSelectionGeom(bool)
{
}

inline bool
GcGiSubEntityTraits::selectionGeom(void) const
{
  return false;
}

inline void
GcGiSubEntityTraits::setTransparency(const GcCmTransparency&)
{
}

inline GcCmTransparency
GcGiSubEntityTraits::transparency(void) const
{
  return GcCmTransparency();
}

inline void GcGiSubEntityTraits::setFill(const GcGiFill *)
{
}

inline const GcGiFill *GcGiSubEntityTraits::fill(void) const
{
  return nullptr;
}

class GCBASE_PORT GcGiDrawableTraits : public GcGiSubEntityTraits
{
public:

  GCRX_DECLARE_MEMBERS(GcGiDrawableTraits);

  enum HighlightProperty
  {
    kVertexRolloverHighlightSize,
  };

  virtual void            setupForEntity(GcDbEntity *pEntity);

  virtual void              addLight(const GcDbObjectId& lightId);

  virtual void              setLinePattern(const GcGiLineType linePattern);
  virtual GcGiLineType      linePattern(void) const;

  virtual Gcad::ErrorStatus setSelectionFlags(const SelectionFlags flags);
  virtual SelectionFlags    selectionFlags(void) const;

  virtual Gcad::ErrorStatus setHighlightProperty(HighlightProperty property,
    GcGiVariant&       value);
  virtual GcGiVariant       highlightProperty(HighlightProperty property) const;

  virtual GcGiContext      *context(void) const { return nullptr; }

protected:
  friend class GcDbImpLayerTableRecord;

  enum LayerFlags {
    kNone = 0x00,
    kOff = 0x01,
    kFrozen = 0x02,
    kZero = 0x04,
    kLocked = 0x08
  };

  virtual void              setLayerFlags(Gsoft::UInt8) { }
};

inline void
GcGiDrawableTraits::addLight(const GcDbObjectId&)
{
}

inline void
GcGiDrawableTraits::setLinePattern(const GcGiLineType)
{
}

inline GcGiLineType
GcGiDrawableTraits::linePattern(void) const
{
  return kLineTypeSolid;
}

inline Gcad::ErrorStatus
GcGiDrawableTraits::setSelectionFlags(const SelectionFlags)
{
  return Gcad::eOk;
}

inline GcGiSubEntityTraits::SelectionFlags
GcGiDrawableTraits::selectionFlags(void) const
{
  return kNoSelectionFlags;
}

inline Gcad::ErrorStatus
GcGiDrawableTraits::setHighlightProperty(HighlightProperty,
  GcGiVariant&)
{
  return Gcad::eOk;
}

inline GcGiVariant
GcGiDrawableTraits::highlightProperty(HighlightProperty) const
{
  return GcGiVariant();
}

class GCBASE_PORT GcGiNonEntityTraits : public GcGiDrawableTraits
{
public:
  GCRX_DECLARE_MEMBERS(GcGiNonEntityTraits);

  void                setupForEntity(GcDbEntity* pEntity) override;
  void                addLight(const GcDbObjectId& id) override;
  void                setColor(const Gsoft::UInt16 color) override;
  Gsoft::UInt16       color(void) const override;
  void                setTrueColor(const GcCmEntityColor& color) override;
  GcCmEntityColor     trueColor(void) const override;
  void                setLayer(const GcDbObjectId layerId) override;
  GcDbObjectId        layerId(void) const override;
  void                setLineType(const GcDbObjectId linetypeId) override;
  GcDbObjectId        lineTypeId(void) const override;
  void                setSelectionMarker(const Gsoft::LongPtr markerId) override;
  void                setFillType(const GcGiFillType fillType) override;
  GcGiFillType        fillType(void) const override;
  void                setLineWeight(const GcDb::LineWeight lw) override;
  GcDb::LineWeight    lineWeight(void) const override;
  void                setThickness(double thickness) override;
  double              thickness(void) const override;
  void                setLineTypeScale(double dScale) override;
  double              lineTypeScale(void) const override;
  void                setMaterial(const GcDbObjectId matId) override;
  GcDbObjectId        materialId(void) const override;
  void                setSelectionGeom(bool bSelectionflag) override;
  bool                selectionGeom(void) const override;
  void                setTransparency(const GcCmTransparency& transparency) override;
  GcCmTransparency    transparency(void) const override;
};

inline void
GcGiNonEntityTraits::setupForEntity(GcDbEntity*)
{
  assert(false);
}

inline void
GcGiNonEntityTraits::addLight(const GcDbObjectId&)
{
  assert(false);
}

inline void
GcGiNonEntityTraits::setColor(const Gsoft::UInt16)
{
  assert(false);
}

inline Gsoft::UInt16
GcGiNonEntityTraits::color(void) const
{
  assert(false);
  return 0;
}

inline void
GcGiNonEntityTraits::setTrueColor(const GcCmEntityColor&)
{
  assert(false);
}

inline GcCmEntityColor
GcGiNonEntityTraits::trueColor(void) const
{
  assert(false);
  return GcCmEntityColor();
}

inline void
GcGiNonEntityTraits::setLayer(const GcDbObjectId)
{
  assert(false);
}

inline GcDbObjectId
GcGiNonEntityTraits::layerId(void) const
{
  assert(false);
  return GcDbObjectId::kNull;
}

inline void
GcGiNonEntityTraits::setLineType(const GcDbObjectId)
{
  assert(false);
}

inline GcDbObjectId GcGiNonEntityTraits::lineTypeId(void) const
{
  assert(false);
  return  GcDbObjectId::kNull;
}

inline void
GcGiNonEntityTraits::setMaterial(const GcDbObjectId)
{
  assert(false);
}

inline GcDbObjectId GcGiNonEntityTraits::materialId(void) const
{
  assert(false);
  return  GcDbObjectId::kNull;
}

inline void
GcGiNonEntityTraits::setSelectionMarker(const Gsoft::LongPtr)
{
  assert(false);
}

inline void
GcGiNonEntityTraits::setFillType(const GcGiFillType)
{
  assert(false);
}

inline GcGiFillType
GcGiNonEntityTraits::fillType(void) const
{
  assert(false);
  return kGcGiFillAlways;
}

inline void
GcGiNonEntityTraits::setLineWeight(const GcDb::LineWeight)
{
  assert(false);
}

inline GcDb::LineWeight
GcGiNonEntityTraits::lineWeight(void) const
{
  assert(false);
  return GcDb::kLnWt000;
}

inline void
GcGiNonEntityTraits::setThickness(double)
{
  assert(false);
}

inline double
GcGiNonEntityTraits::thickness(void) const
{
  assert(false);
  return 0.0;
}

inline void
GcGiNonEntityTraits::setLineTypeScale(double)
{
  assert(false);
}

inline double
GcGiNonEntityTraits::lineTypeScale(void) const
{
  assert(false);
  return 0.0;
}

inline void
GcGiNonEntityTraits::setSelectionGeom(bool)
{
  assert(false);
}

inline bool
GcGiNonEntityTraits::selectionGeom(void) const
{
  assert(false);
  return false;
}

inline void
GcGiNonEntityTraits::setTransparency(const GcCmTransparency&)
{
  assert(false);
}

inline GcCmTransparency
GcGiNonEntityTraits::transparency(void) const
{
  assert(false);
  return GcCmTransparency();
}

#ifndef _WINDEF_
struct HDC__;
typedef     struct HDC__ *          HDC;
#endif

class GcGiGdiDrawObject : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcGiGdiDrawObject);

  virtual Gsoft::Boolean    draw(HDC hDC, int x, int y, int w, int h) = 0;
  virtual int               width() const = 0;
  virtual int               height() const = 0;

  virtual void              addRef() = 0;
  virtual void              delRef() = 0;
};

class  GcGiPolyline : public GcGiParameter
{
public:
  GCRX_DECLARE_MEMBERS_READWRITE_EXPIMP(GcGiPolyline, GcGiImpPolyline, GCBASE_PORT);

  GCBASE_PORT GcGiPolyline();
  GCBASE_PORT GcGiPolyline(Gsoft::UInt32 nbPoints, GcGePoint3d* pVertexList, GcGeVector3d* pNormal = NULL, Gsoft::LongPtr lBaseSubEntMarker = -1);
  GCBASE_PORT ~GcGiPolyline();

  enum LinetypeGeneration { kPerSegment, kEndToEnd };

  GCBASE_PORT virtual Gsoft::UInt32 points() const;
  GCBASE_PORT virtual const GcGePoint3d* vertexList() const;
  GCBASE_PORT virtual const GcGeVector3d* normal() const;
  GCBASE_PORT virtual LinetypeGeneration linetypeGen() const;
  GCBASE_PORT virtual Gsoft::LongPtr baseSubEntMarker() const;
  GCBASE_PORT virtual const Gsoft::LongPtr* subEntMarkerList() const;
  GCBASE_PORT virtual const bool* arcSegmentFlags() const;
  GCBASE_PORT virtual bool isClosed() const;
  GCBASE_PORT virtual double elevation() const;
  GCBASE_PORT virtual double thickness() const;
  GCBASE_PORT virtual double constantWidth() const;
  GCBASE_PORT virtual const double* bulge() const;
  GCBASE_PORT virtual const double* width() const;

  GCBASE_PORT virtual void setVertexList(Gsoft::UInt32 nbPoints, const GcGePoint3d* pVertexList);
  GCBASE_PORT virtual void setNormal(const GcGeVector3d* pNormal);
  GCBASE_PORT virtual void setLinetypeGen(LinetypeGeneration ltgen);
  GCBASE_PORT virtual void setBaseSubEntMarker(Gsoft::LongPtr lBaseSubEntMarker);
  GCBASE_PORT virtual void setSubEntMarkerList(const Gsoft::LongPtr* pSubEntMarkerList);
  GCBASE_PORT virtual void setArcSegmentFlags(const bool *pArcSegmentFlags);
  GCBASE_PORT virtual void setClosed(bool val);
  GCBASE_PORT virtual void setElevation(double val);
  GCBASE_PORT virtual void setThickness(double val);
  GCBASE_PORT virtual void setConstantWidth(double val);
  GCBASE_PORT virtual void setBulge(const double* pBulge);
  GCBASE_PORT virtual void setWidth(const double* pWidth);
};

typedef enum {
  kGcGiWorldPosition,
  kGcGiViewportPosition,
  kGcGiScreenPosition,
  kGcGiScreenLocalOriginPosition,
  kGcGiWorldWithScreenOffsetPosition
} GcGiPositionTransformBehavior;

typedef enum {
  kGcGiWorldScale,
  kGcGiViewportScale,
  kGcGiScreenScale,
  kGcGiViewportLocalOriginScale,
  kGcGiScreenLocalOriginScale
} GcGiScaleTransformBehavior;

typedef enum {
  kGcGiWorldOrientation,
  kGcGiScreenOrientation,
  kGcGiZAxisOrientation
} GcGiOrientationTransformBehavior;

class GCBASE_PORT GcGiGeometry : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcGiGeometry);

  enum TransparencyMode
  {
    kTransparencyOff,
    kTransparency1Bit,
    kTransparency8Bit,
  };

  virtual void getModelToWorldTransform(GcGeMatrix3d&) const = 0;
  virtual void getWorldToModelTransform(GcGeMatrix3d&) const = 0;

  virtual Gsoft::Boolean pushModelTransform(const GcGeVector3d & vNormal) = 0;
  virtual Gsoft::Boolean pushModelTransform(const GcGeMatrix3d & xMat) = 0;
  virtual Gsoft::Boolean popModelTransform() = 0;
  virtual GcGeMatrix3d pushPositionTransform(GcGiPositionTransformBehavior behavior, const GcGePoint3d& offset) = 0;
  virtual GcGeMatrix3d pushPositionTransform(GcGiPositionTransformBehavior behavior, const GcGePoint2d& offset) = 0;
  virtual GcGeMatrix3d pushScaleTransform(GcGiScaleTransformBehavior behavior, const GcGePoint3d& extents) = 0;
  virtual GcGeMatrix3d pushScaleTransform(GcGiScaleTransformBehavior behavior, const GcGePoint2d& extents) = 0;
  virtual GcGeMatrix3d pushOrientationTransform(GcGiOrientationTransformBehavior behavior) = 0;

  virtual Gsoft::Boolean  circle(const GcGePoint3d& center,
    const double radius,
    const GcGeVector3d& normal) const = 0;
  virtual Gsoft::Boolean  circle(const GcGePoint3d&, const GcGePoint3d&,
    const GcGePoint3d&) const = 0;
  virtual Gsoft::Boolean  circularArc(const GcGePoint3d& center,
    const double radius,
    const GcGeVector3d& normal,
    const GcGeVector3d& startVector,
    const double sweepAngle,
    const GcGiArcType arcType = kGcGiArcSimple) const = 0;
  virtual Gsoft::Boolean  circularArc(const GcGePoint3d& start,
    const GcGePoint3d& point,
    const GcGePoint3d& end,
    const GcGiArcType arcType = kGcGiArcSimple) const = 0;
  virtual Gsoft::Boolean  polyline(const Gsoft::UInt32 nbPoints,
    const GcGePoint3d* pVertexList,
    const GcGeVector3d* pNormal = NULL,
    Gsoft::LongPtr lBaseSubEntMarker = -1) const = 0;

  virtual Gsoft::Boolean  polyline(const GcGiPolyline& polylineObj) const = 0;
  virtual Gsoft::Boolean  polyPolyline(Gsoft::UInt32 nbPolylines,
    const GcGiPolyline* pPolylines) const = 0;

  virtual Gsoft::Boolean  polygon(const Gsoft::UInt32 nbPoints,
    const GcGePoint3d* pVertexList) const = 0;
  virtual Gsoft::Boolean  polyPolygon(const Gsoft::UInt32 numPolygonIndices,
    const Gsoft::UInt32* numPolygonPositions,
    const GcGePoint3d* polygonPositions,
    const Gsoft::UInt32* numPolygonPoints,
    const GcGePoint3d* polygonPoints,
    const GcCmEntityColor* outlineColors = NULL,
    const GcGiLineType* outlineTypes = NULL,
    const GcCmEntityColor* fillColors = NULL,
    const GcCmTransparency* fillOpacities = NULL) const = 0;

  virtual Gsoft::Boolean  mesh(const Gsoft::UInt32 rows,
    const Gsoft::UInt32 columns,
    const GcGePoint3d* pVertexList,
    const GcGiEdgeData* pEdgeData = NULL,
    const GcGiFaceData* pFaceData = NULL,
    const GcGiVertexData* pVertexData = NULL,
    const bool bAutoGenerateNormals = true
  ) const = 0;

  virtual Gsoft::Boolean  shell(const Gsoft::UInt32 nbVertex,
    const GcGePoint3d* pVertexList,
    const Gsoft::UInt32 faceListSize,
    const Gsoft::Int32* pFaceList,
    const GcGiEdgeData* pEdgeData = NULL,
    const GcGiFaceData* pFaceData = NULL,
    const GcGiVertexData* pVertexData = NULL,
    const struct resbuf* pResBuf = NULL,
    const bool bAutoGenerateNormals = true
  ) const = 0;

  virtual Gsoft::Boolean  text(const GcGePoint3d& position,
    const GcGeVector3d& normal,
    const GcGeVector3d& direction,
    const double height,
    const double width,
    const double oblique,
    const GCHAR* pMsg) const = 0;
  virtual Gsoft::Boolean  text(const GcGePoint3d& position,
    const GcGeVector3d& normal,
    const GcGeVector3d& direction,
    const GCHAR* pMsg,
    const Gsoft::Int32 length,
    const Gsoft::Boolean raw,
    const GcGiTextStyle &pTextStyle
  ) const = 0;

  virtual Gsoft::Boolean  xline(const GcGePoint3d&,
    const GcGePoint3d&) const = 0;

  virtual Gsoft::Boolean  ray(const GcGePoint3d&,
    const GcGePoint3d&) const = 0;

  virtual Gsoft::Boolean  pline(const GcDbPolyline& lwBuf,
    Gsoft::UInt32 fromIndex = 0,
    Gsoft::UInt32 numSegs = 0
  ) const = 0;

  virtual Gsoft::Boolean  draw(GcGiDrawable*) const = 0;

  virtual Gsoft::Boolean  image(const GcGiImageBGRA32& imageSource,
    const GcGePoint3d& position,
    const GcGeVector3d& u,
    const GcGeVector3d& v,
    TransparencyMode transparencyMode = kTransparency8Bit
  ) const = 0;

  virtual Gsoft::Boolean  rowOfDots(int count,
    const GcGePoint3d&     start,
    const GcGeVector3d&     step
  ) const = 0;

  virtual Gsoft::Boolean  ellipticalArc(const GcGePoint3d&         center,
    const GcGeVector3d&        normal,
    double                     majorAxisLength,
    double                     minorAxisLength,
    double                     startDegreeInRgds,
    double                     endDegreeInRgds,
    double                     tiltDegreeInRgds,
    GcGiArcType                arcType = kGcGiArcSimple
  ) const = 0;

  virtual Gsoft::Boolean          pushClipBoundary(GcGiClipBoundary * pBoundary) = 0;
  virtual void                    popClipBoundary() = 0;
  virtual Gsoft::Boolean   worldLine(const GcGePoint3d pnts[2]) {
    GcGePoint3d polyPnts[2];
    GcGeMatrix3d mat;
    getWorldToModelTransform(mat);
    polyPnts[0] = mat * pnts[0];
    polyPnts[1] = mat * pnts[1];
    return polyline(2, polyPnts);
  };
  virtual Gsoft::Boolean  polypoint(const Gsoft::UInt32 nbPoints,
    const GcGePoint3d* pVertexList,
    const GcGeVector3d* pNormal = NULL,
    const Gsoft::LongPtr *pSubEntMarkers = NULL) const {
    GcGePoint3d pline[2];
    Gsoft::Boolean retval = Gsoft::kFalse;
    for (Gsoft::UInt32 i = 0; i < nbPoints; i++) {
      pline[1] = pline[0] = pVertexList[i];
      retval = polyline(2, pline, pNormal ? &pNormal[i] : NULL, pSubEntMarkers ? pSubEntMarkers[i] : -1);
      if (retval)
        return retval;
    }
    return retval;
  };

  virtual Gsoft::Boolean ownerDraw(GcGiGdiDrawObject*,
    const GcGePoint3d&,
    const GcGeVector3d&,
    const GcGeVector3d&
  ) const {
    return Gsoft::kTrue;
  };

  virtual Gsoft::Boolean  edge(const GcArray<GcGeCurve2d*>& edges) const = 0;
};

class GCBASE_PORT GcGiWorldGeometry : public GcGiGeometry
{
public:
  GCRX_DECLARE_MEMBERS(GcGiWorldGeometry);

  virtual void setExtents(GcGePoint3d *pNewExtents) const = 0;
  virtual void startAttributesSegment() {};
};

class GCBASE_PORT GcGiViewportGeometry : public GcGiGeometry
{
public:
  GCRX_DECLARE_MEMBERS(GcGiViewportGeometry);

  virtual Gsoft::Boolean  polylineEye(const Gsoft::UInt32 nbPoints,
    const GcGePoint3d* pPoints) const = 0;
  virtual Gsoft::Boolean  polygonEye(const Gsoft::UInt32 nbPoints,
    const GcGePoint3d* pPoints) const = 0;

  virtual Gsoft::Boolean  polylineDc(const Gsoft::UInt32 nbPoints,
    const GcGePoint3d* pPoints) const = 0;
  virtual Gsoft::Boolean  polygonDc(const Gsoft::UInt32 nbPoints,
    const GcGePoint3d* pPoints) const = 0;

  enum ImageSource {
    kFromDwg,
    kFromOleObject,
    kFromRender
  };

  virtual Gsoft::Boolean  rasterImageDc(
    const GcGePoint3d& origin,
    const GcGeVector3d& u,
    const GcGeVector3d& v,
    const GcGeMatrix2d& pixelToDc,
    GcDbObjectId entityId,
    GcGiImageOrg imageOrg,
    Gsoft::UInt32 imageWidth,
    Gsoft::UInt32 imageHeight,
    Gsoft::Int16 imageColorDepth,
    Gsoft::Boolean transparency,
    ImageSource source,
    const GcGeVector3d& unrotatedU,
    const GcGiImageOrg origionalImageOrg,
    const GcGeMatrix2d& unrotatedPixelToDc,
    const Gsoft::UInt32 unrotatedImageWidth,
    const Gsoft::UInt32 unrotatedImageHeight
  ) const = 0;

  virtual Gsoft::Boolean  ownerDrawDc(
    Gsoft::Int32                       vpnumber,
    Gsoft::Int32                       left,
    Gsoft::Int32                       top,
    Gsoft::Int32                       right,
    Gsoft::Int32                       bottom,
    const OwnerDraw*           pOwnerDraw
  ) const = 0;

  virtual Gsoft::Boolean  ownerDraw3d(
    GcGePoint3d&,
    GcGePoint3d&,
    OwnerDraw3d*
  ) const {
    return Gsoft::kFalse;
  };
};

#pragma warning (pop)   

class GCBASE_PORT GcGiEdgeData : public GcGiParameter
{
public:
  GCRX_DECLARE_MEMBERS_READWRITE(GcGiEdgeData, GcGiImpEdgeData);

  ~GcGiEdgeData();
  GcGiEdgeData();

  virtual void            setColors(const short *colors);
  virtual void            setTrueColors(const GcCmEntityColor *colors);
  virtual void            setLayers(const GcDbObjectId *layers);
  virtual void            setLineTypes(const GcDbObjectId *linetypes);
  virtual void            setSelectionMarkers(const Gsoft::LongPtr* pSelectionMarkers);
  virtual void            setVisibility(const Gsoft::UInt8* pVisibility);

  virtual short*          colors() const;
  virtual GcCmEntityColor* trueColors() const;
  virtual GcDbObjectId*   layerIds() const;
  virtual GcDbObjectId*   linetypeIds() const;
  virtual Gsoft::LongPtr* selectionMarkers() const;
  virtual Gsoft::UInt8*   visibility() const;
};

class GCBASE_PORT GcGiFaceData : public GcGiParameter
{
public:
  GCRX_DECLARE_MEMBERS_READWRITE(GcGiFaceData, GcGiImpFaceData);

  ~GcGiFaceData();
  GcGiFaceData();

  virtual void            setColors(const short *colors);
  virtual void            setTrueColors(const GcCmEntityColor *colors);
  virtual void            setLayers(const GcDbObjectId *layers);
  virtual void            setSelectionMarkers(const Gsoft::LongPtr* pSelectionMarkers);
  virtual void            setNormals(const GcGeVector3d* pNormals);
  virtual void            setVisibility(const Gsoft::UInt8* vis);
  virtual void            setMaterials(const GcDbObjectId * materials);
  virtual void            setMappers(const GcGiMapper * mappers);
  virtual void            setTransparency(const GcCmTransparency *transparency);

  virtual short*          colors() const;
  virtual GcCmEntityColor* trueColors() const;
  virtual GcDbObjectId*   layerIds() const;
  virtual Gsoft::LongPtr* selectionMarkers() const;
  virtual GcGeVector3d*   normals() const;
  virtual Gsoft::UInt8*   visibility() const;
  virtual GcDbObjectId*   materials() const;
  virtual GcGiMapper*     mappers() const;
  virtual GcCmTransparency* transparency() const;
};

class GCBASE_PORT GcGiVertexData : public GcGiParameter
{
public:
  enum MapChannel
  {
    kAllChannels,
    kMapChannels
  };

  GCRX_DECLARE_MEMBERS_READWRITE(GcGiVertexData, GcGiImpVertexData);
  ~GcGiVertexData();
  GcGiVertexData();

  virtual void setNormals(const GcGeVector3d* pNormals);
  virtual GcGeVector3d* normals() const;
  virtual void setOrientationFlag(const GcGiOrientationType oflag);
  virtual GcGiOrientationType orientationFlag() const;
  virtual void setTrueColors(const GcCmEntityColor *colors);
  virtual GcCmEntityColor* trueColors() const;
  virtual void setMappingCoords(MapChannel mapChannel, const GcGePoint3d* pCoords);
  virtual GcGePoint3d* mappingCoords(MapChannel mapChannel) const;
};

class GCBASE_PORT GcGiTextStyle : public GcGiParameter
{
public:
  GCRX_DECLARE_MEMBERS_READWRITE(GcGiTextStyle, GcGiImpTextStyle);
  ~GcGiTextStyle();
  GcGiTextStyle(GcDbDatabase* pDb = NULL);

  GcGiTextStyle(
    const GCHAR*  fontName,
    const GCHAR*  bigFontName,
    const double textSize,
    const double xScale,
    const double obliqueAngle,
    const double trPercent,
    const Gsoft::Boolean isBackward,
    const Gsoft::Boolean isUpsideDown,
    const Gsoft::Boolean isVertical,
    const Gsoft::Boolean isOverlined,
    const Gsoft::Boolean isUnderlined,
    const Gsoft::Boolean isStrikethrough = false,
    const GCHAR*          styleName = NULL);

  virtual int loadStyleRec(GcDbDatabase* pDb = NULL) const;
  virtual void setTextSize(const double size);
  virtual void setXScale(const double xScale);
  virtual void setObliquingAngle(const double obliquingAngle);

  virtual void setTrackingPercent(const double trPercent);

  virtual void setBackward(const Gsoft::Boolean isBackward);
  virtual void setUpsideDown(const Gsoft::Boolean isUpsideDown);
  virtual void setVertical(const Gsoft::Boolean isVertical);

  virtual void setUnderlined(const Gsoft::Boolean isUnderlined);
  virtual void setOverlined(const Gsoft::Boolean isOverlined);
  virtual void setStrikethrough(const Gsoft::Boolean isStrikethrough);

  virtual void setFileName(const GCHAR * fontName);
  virtual void setBigFontFileName(const GCHAR * bigFontFileName);

  virtual double textSize() const;
  virtual double xScale() const;
  virtual double obliquingAngle() const;

  virtual double trackingPercent() const;

  virtual Gsoft::Boolean isBackward() const;
  virtual Gsoft::Boolean isUpsideDown() const;
  virtual Gsoft::Boolean isVertical() const;

  virtual Gsoft::Boolean isUnderlined() const;
  virtual Gsoft::Boolean isOverlined() const;
  virtual Gsoft::Boolean isStrikethrough() const;

  virtual const GCHAR * fileName() const;
  virtual const GCHAR * bigFontFileName() const;

  virtual GcGePoint2d extents(const GCHAR * pStr,
    const Gsoft::Boolean penups,
    const int len,
    const Gsoft::Boolean raw,
    GcGiWorldDraw *ctxt = NULL) const;

  virtual const GCHAR * styleName() const;
  virtual Gcad::ErrorStatus setStyleName(const GCHAR *);

  virtual Gcad::ErrorStatus setFont(const GCHAR * pTypeface,
    Gsoft::Boolean bold,
    Gsoft::Boolean italic,
    Charset charset,
    Gssoft::Gscad::PAL::FontUtils::FontPitch pitch,
    Gssoft::Gscad::PAL::FontUtils::FontFamily family);

  virtual Gcad::ErrorStatus font(GcString & sTypeface,
    bool & bold, bool & italic, Charset& charset,
    Gssoft::Gscad::PAL::FontUtils::FontPitch& pitch,
    Gssoft::Gscad::PAL::FontUtils::FontFamily& family) const;

  virtual Gcad::ErrorStatus font(GCHAR *& pTypeface,
    bool & bold, bool & italic, Charset& charset,
    Gssoft::Gscad::PAL::FontUtils::FontPitch& pitch,
    Gssoft::Gscad::PAL::FontUtils::FontFamily& family) const final;

  virtual Gcad::ErrorStatus  extentsBox(const GCHAR * pStr,
    const Gsoft::Boolean penups,
    const int len,
    const Gsoft::Boolean raw,
    GcGePoint2d &extMin,
    GcGePoint2d &extMax,
    GcGiWorldDraw *ctxt = NULL) const;

  virtual void setTrackKerning(double trackPercent) const;
  virtual bool preLoaded() const;
  virtual void setPreLoaded(bool);
};

inline Gcad::ErrorStatus GcGiTextStyle::font(GCHAR *& pTypeface,
  bool & bold, bool & italic, Charset& charset,
  Gssoft::Gscad::PAL::FontUtils::FontPitch& pitch,
  Gssoft::Gscad::PAL::FontUtils::FontFamily& family) const
{
  GcString sTypeface;
  const Gcad::ErrorStatus es = this->font(sTypeface, bold, italic, charset, pitch, family);
  ::gcutNewString(sTypeface.constPtr(), pTypeface);
  return es;
}

class  GcGiFill : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcGiFill, GCBASE_PORT);

  GCBASE_PORT GcGiFill();
  GCBASE_PORT GcGiFill(const GcGiFill&);
  GCBASE_PORT ~GcGiFill();

  GCBASE_PORT double deviation() const;
  GCBASE_PORT void   setDeviation(double dev);

private:
  GcGiImpFill *mpImp = nullptr;
};

class  GcGiHatchPatternDefinition
{
public:
  GCBASE_PORT GcGiHatchPatternDefinition();
  GCBASE_PORT GcGiHatchPatternDefinition(const GcGiHatchPatternDefinition &def);
  GCBASE_PORT GcGiHatchPatternDefinition(double angle,
    double baseX,
    double baseY,
    double offsetX,
    double offsetY,
    const GcGeDoubleArray& dashList);
  GCBASE_PORT ~GcGiHatchPatternDefinition();

  GCBASE_PORT double angle() const;
  GCBASE_PORT double baseX() const;
  GCBASE_PORT double baseY() const;
  GCBASE_PORT double offsetX() const;
  GCBASE_PORT double offsetY() const;
  GCBASE_PORT const GcGeDoubleArray& dashList() const;

  GCBASE_PORT GcGiHatchPatternDefinition & operator = (const GcGiHatchPatternDefinition &def);

private:
  friend class GcGiImpHatchPatternDefinition;
  GcGiImpHatchPatternDefinition *  mpImp = nullptr;
};

class  GcGiHatchPattern : public GcGiFill
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcGiHatchPattern, GCBASE_PORT);
  GCBASE_PORT GcGiHatchPattern(const GcArray<GcGiHatchPatternDefinition>&);
  GCBASE_PORT GcGiHatchPattern(const GcGiHatchPattern&);
  GCBASE_PORT ~GcGiHatchPattern();

  GCBASE_PORT const GcArray<GcGiHatchPatternDefinition>& patternLines() const;

private:
  GcGiImpHatchPattern *mpImp = nullptr;
};

class GcGiGradientFill : public GcGiFill
{
public:
  enum GradientType
  {
    kLinear,
    kCylinder,
    kInvCylinder,
    kSpherical,
    kHemispherical,
    kCurved,
    kInvSpherical,
    kInvHemispherical,
    kInvCurved
  };

  GCRX_DECLARE_MEMBERS_EXPIMP(GcGiGradientFill, GCCORE_PORT);

  GCCORE_PORT GcGiGradientFill(double                              gradientAngle,
    double                              gradientShift,
    bool                                bAdjustAspect,
    GcArray<GcCmColor>&                 gradientColors,
    GcGiGradientFill::GradientType type);
  GCCORE_PORT GcGiGradientFill(const GcGiGradientFill&);
  GCCORE_PORT ~GcGiGradientFill();

  GCCORE_PORT void setGradientAngle(double val);
  GCCORE_PORT double gradientAngle() const;

  GCCORE_PORT void setGradientShift(double val);
  GCCORE_PORT double gradientShift() const;

  GCCORE_PORT void setIsAdjustAspect(bool val);
  GCCORE_PORT bool isAdjustAspect() const;

  GCCORE_PORT void setGradientColors(const GcArray<GcCmColor>& val);
  GCCORE_PORT const GcArray<GcCmColor>& gradientColors() const;

  GCCORE_PORT void setGradientType(GcGiGradientFill::GradientType type);
  GCCORE_PORT const GcGiGradientFill::GradientType gradientType() const;

private:
  GcGiImpGradientFill *mpImp = nullptr;
};

#pragma pack (pop)

#endif