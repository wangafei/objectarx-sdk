#ifndef _ZCGI_H
#define _ZCGI_H 1

#include "zadesk.h"

#define ZCGI_SERVICES  ZCRX_T("ZcGiServices")

#include "zacgidefs.h"


#include "zrxobject.h"
#include "zAdAChar.h"
#include "zdbpl.h"
#include "zgemat3d.h"
#include "zgemat2d.h"
#include "zgepnt2d.h"
#include "zgept2dar.h"
#include "zgecurv2d.h"
#include "zdbcolor.h"
#include "zacdb.h"
#include "zAcGiStyleAttributes.h"
#include "assert.h"
#include "zacgiparameter.h"
#include "PAL/api/Zcharset.h"
#include "PAL/api/ZFontPitchAndFamily.h"
#include "zrxboiler.h"
//#include "ZcCmColor.h"
//#include "dbObject.h"

#pragma pack (push, 8)

struct ZcGiSentScanLines 
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

    ZSoft::Int8 *    mpPixelBuffer;          
    ZSoft::UInt32    mRowBytes;              
    void *           mpImageId;              
    ZSoft::Int16     mIsCancelled;           
    ZSoft::Int16     mHasFailed;
    ZSoft::UInt32    mBytes;
    IsmRequestStatus mRequestStatus;

};

struct ZcGiRequestScanLines 
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

    ZcGiRequestScanLines()
        : mImageOrg           (kZcGiBitonal)
        , mImageOrient        (kZcGiXLeftToRightTopFirst)
        , mPaletteType        (kFromDevice)
        , mScalingType        (kDefaultScale)
        , mScaleFilterType    (kDefaultScaleFilter)
        , mRotationFilterType (kDefaultRotationFilter)
    {
    }

    ZSoft::UInt32       mPixelMinX  = 0;             
    ZSoft::UInt32       mPixelMinY = 0;
    ZSoft::UInt32       mPixelMaxX = 0;
    ZSoft::UInt32       mPixelMaxY = 0;
    ZcGePoint2d         mLowerLeft;             
    ZcGePoint2d         mUpperRight;            
    void *              mpImageId = nullptr;
    ZcGiImageOrg        mImageOrg;              
    ZcGiImageOrient     mImageOrient;           
    ZSoft::Int16        mWindowId = 0;             
    ZSoft::Int16        mColorDepth = 8;            
    union {
        ZSoft::Int16 mBackgroundIndex;
        ZSoft::Int8 mBackgroundRGB[3];
    }                   mBackgroundColor;       
    union {
        ZSoft::Int16 mTransparentIndex;
        ZSoft::Int8 mTransparentRGB[3];
    } mTransparentColor;                        
    union {
        ZSoft::Int16 mEntityIndex;
        ZSoft::Int8 mEntityRGB[3];
    }                   mEntityColor;           
    ZSoft::Int32        mPaletteIncarnation = 0; 
    ZSoft::Int8 *       mpPalette = nullptr;              
    ZSoft::Int16        mIsDisplay = 0;             
    double              mRasterRatio = 1.0;           
    ZcGeMatrix2d        mPixelToDc;             
    ImagePaletteType    mPaletteType;
    void *              mpDataBuffer = nullptr;
    ZSoft::Int32        mRowWidth = 0;
    ZSoft::Int32        mNumRows;
    ZSoft::Int32 const *mpBoundaryPoints = nullptr;        
    ZSoft::UInt32       mnContours = 0;              
    ZSoft::Int32 const *mpCounts = nullptr;                
    ZcGiScaleType          mScalingType;
    ZcGiScaleFilterType    mScaleFilterType;
    ZcGiRotationFilterType mRotationFilterType;
    short                  mnTotalChunks = 0;
    short                  mnThisChunk = 0;
	ZSoft::Int32		mOrigin[2];
	ZSoft::Int32		mLowerRightPt[2];
	ZSoft::Int32		mUpperLeftPt[2];
};

struct ZcGiClipBoundary
{
    ZcGeVector3d        m_vNormal;
    ZcGePoint3d         m_ptPoint;
    ZcGePoint2dArray    m_aptPoints;    

    ZcGeMatrix3d        m_xToClipSpace;
    ZcGeMatrix3d        m_xInverseBlockRefXForm; 

    ZSoft::Boolean      m_bClippingFront = false;
    ZSoft::Boolean      m_bClippingBack = false;
    double              m_dFrontClipZ = 0.0;
    double              m_dBackClipZ = 0.0;

    ZSoft::Boolean      m_bDrawBoundary = false;
};

class OwnerDraw3d
{
public:
    virtual ~OwnerDraw3d(void) {};
};

enum ZcGiColorIntensity 
{
    kZcGiMinColorIntensity = 0x0,
    kZcGiColorIntensity1   = 0x1,
    kZcGiColorIntensity2   = 0x2,
    kZcGiColorIntensity3   = 0x3,
    kZcGiColorIntensity4   = 0x4,
    kZcGiColorIntensity5   = 0x5,
    kZcGiColorIntensity6   = 0x6,
    kZcGiMaxColorIntensity = 0x7 
};

class ZcGiColorRGB
{
public:
    ZcGiColorRGB (void)
        : red   (0.0)
        , green (0.0)
        , blue  (0.0)
    { }

    ZcGiColorRGB (double r, double g, double b)
        : red   (r)
        , green (g)
        , blue  (b)
    { }

    double red;
    double green;
    double blue;
};

inline ZcGiColorRGB operator* (const ZcGiColorRGB& c1, const ZcGiColorRGB& c2)
{
    return ZcGiColorRGB(c1.red   * c2.red,
                        c1.green * c2.green,
                        c1.blue  * c2.blue);
}

inline ZcGiColorRGB operator* (const ZcGiColorRGB& c, double s)
{
    return ZcGiColorRGB(s * c.red,
                        s * c.green,
                        s * c.blue);
}

inline ZcGiColorRGB operator* (double s, const ZcGiColorRGB& c)
{
    return c * s;
}

inline ZcGiColorRGB operator+ (const ZcGiColorRGB& c1, const ZcGiColorRGB& c2)
{
    return ZcGiColorRGB(c1.red   + c2.red,
                        c1.green + c2.green,
                        c1.blue  + c2.blue);
}

class ZcGiColorRGBA
{
public:
    ZcGiColorRGBA (void)
        : red   (0.0)
        , green (0.0)
        , blue  (0.0)
        , alpha (1.0)
    { }

    ZcGiColorRGBA (double r, double g, double b, double a)
        : red   (r)
        , green (g)
        , blue  (b)
        , alpha (a)
    { }

    double red;
    double green;
    double blue;
    double alpha;
};

inline ZcGiColorRGBA operator* (const ZcGiColorRGBA& c1, const ZcGiColorRGBA& c2)
{
    return ZcGiColorRGBA(c1.red   * c2.red,
                         c1.green * c2.green,
                         c1.blue  * c2.blue,
                         c1.alpha * c2.alpha);
}

inline ZcGiColorRGBA operator*(const ZcGiColorRGBA& c, double s)
{
    return ZcGiColorRGBA(s * c.red,
                         s * c.green,
                         s * c.blue,
                         s * c.alpha);
}

inline ZcGiColorRGBA operator* (double s, const ZcGiColorRGBA& c)
{
    return c * s;
}

inline ZcGiColorRGBA operator+ (const ZcGiColorRGBA& c1, const ZcGiColorRGBA& c2)
{
    return ZcGiColorRGBA(c1.red   + c2.red,
                         c1.green + c2.green,
                         c1.blue  + c2.blue,
                         c1.alpha + c2.alpha);
}

class ZcGiPixelBGRA32
{
public:
	ZcGiPixelBGRA32 ()
	{
		m_bgra.b = 0;
		m_bgra.g = 0;
		m_bgra.r = 0;
		m_bgra.a = 255;
	}

	ZcGiPixelBGRA32(ZSoft::UInt32 bgra)
		: m_whole (bgra)
	{
	}

	ZcGiPixelBGRA32 (ZSoft::UInt8 blue,
		ZSoft::UInt8 green,
		ZSoft::UInt8 red,
		ZSoft::UInt8 alpha)
	{
		m_bgra.b = blue;
		m_bgra.g = green;
		m_bgra.r = red;
		m_bgra.a = alpha;
	}

	ZSoft::UInt32     getBGRA   () const;
	ZSoft::UInt32     getRGBA   () const;
	ZSoft::UInt8      blue      () const;
	ZSoft::UInt8      green     () const;
	ZSoft::UInt8      red       () const;
	ZSoft::UInt8      alpha     () const;

	void setBGRA    (ZSoft::UInt32 bgra);
	void setBGRA    (ZSoft::UInt8 blue, 
						ZSoft::UInt8 green, 
						ZSoft::UInt8 red,
						ZSoft::UInt8 alpha);
	void setRGBA    (ZSoft::UInt32 rgba);
	void setRGBA    (ZSoft::UInt8 red, 
						ZSoft::UInt8 green, 
						ZSoft::UInt8 blue,
						ZSoft::UInt8 alpha);
	void setBlue    (ZSoft::UInt8 blue);
	void setGreen   (ZSoft::UInt8 green);
	void setRed     (ZSoft::UInt8 red);
	void setAlpha   (ZSoft::UInt8 alpha);

private:
	union {
		ZSoft::UInt32 m_whole;
#if defined(_ZSOFT_WINDOWS_)
		struct PIXEL{
#else

		struct {
#endif
			ZSoft::UInt8  b, g, r, a;
		}m_bgra;
	};
};

inline ZSoft::UInt32 ZcGiPixelBGRA32::getBGRA() const
{
	return m_whole;
}

inline ZSoft::UInt32 ZcGiPixelBGRA32::getRGBA() const
{
	return (ZSoft::UInt32)(m_bgra.a)<<24 
		| (ZSoft::UInt32)(m_bgra.b)<<16
		| (ZSoft::UInt32)(m_bgra.g)<<8 
		| (ZSoft::UInt32)(m_bgra.r);
}

inline ZSoft::UInt8 ZcGiPixelBGRA32::blue() const
{
	return m_bgra.b;
}

inline ZSoft::UInt8 ZcGiPixelBGRA32::green() const
{
	return m_bgra.g;
}

inline ZSoft::UInt8 ZcGiPixelBGRA32::red() const
{
	return m_bgra.r;
}

inline ZSoft::UInt8 ZcGiPixelBGRA32::alpha() const
{
	return m_bgra.a;
}

inline void ZcGiPixelBGRA32::setBGRA(ZSoft::UInt32 bgra)
{
	m_whole = bgra;
}

inline void ZcGiPixelBGRA32::setBGRA(ZSoft::UInt8 blue, 
	ZSoft::UInt8 green, 
	ZSoft::UInt8 red,
	ZSoft::UInt8 alpha)
{
	m_bgra.b = blue;
	m_bgra.g = green;
	m_bgra.r = red;
	m_bgra.a = alpha;
}

inline void ZcGiPixelBGRA32::setRGBA(ZSoft::UInt32 rgba)
{
	m_bgra.r = (ZSoft::UInt8)(rgba & 0x000000FF);
	m_bgra.g = (ZSoft::UInt8)((rgba & 0x0000FF00) >> 8);
	m_bgra.b = (ZSoft::UInt8)((rgba & 0x00FF0000) >> 16);
	m_bgra.a = (ZSoft::UInt8)((rgba & 0xFF000000) >> 24);
}

inline void ZcGiPixelBGRA32::setRGBA(ZSoft::UInt8 red, 
	ZSoft::UInt8 green, 
	ZSoft::UInt8 blue,
	ZSoft::UInt8 alpha)
{
	m_bgra.r = red;
	m_bgra.g = green;
	m_bgra.b = blue;
	m_bgra.a = alpha;
}

inline void ZcGiPixelBGRA32::setBlue(ZSoft::UInt8 blue)
{
	m_bgra.b = blue;
}

inline void ZcGiPixelBGRA32::setGreen(ZSoft::UInt8 green)
{
	m_bgra.g = green;
}

inline void ZcGiPixelBGRA32::setRed(ZSoft::UInt8 red)
{
	m_bgra.r = red;
}

inline void ZcGiPixelBGRA32::setAlpha(ZSoft::UInt8 alpha)
{
	m_bgra.a = alpha;
}

class ZcGiImageBGRA32
{
public:
    ZcGiImageBGRA32() = default;

	ZcGiImageBGRA32(ZSoft::UInt32 imageWidth,
                    ZSoft::UInt32 imageHeight,
                    ZcGiPixelBGRA32* imageData)
		: m_nImageWidth(imageWidth)
		, m_nImageHeight(imageHeight)
		, m_pImageData(imageData)
	{
	}

	ZcGiPixelBGRA32* image() const;
	ZSoft::UInt32 width() const;
	ZSoft::UInt32 height() const;
	void setImage(ZSoft::UInt32 imageWidth, ZSoft::UInt32 imageHeight, ZcGiPixelBGRA32* imageData);

private:
	ZcGiPixelBGRA32* m_pImageData = NULL;
	ZSoft::UInt32 m_nImageWidth = 0;
	ZSoft::UInt32 m_nImageHeight = 0;
};

inline 
ZcGiPixelBGRA32* ZcGiImageBGRA32::image() const
{
	return m_pImageData;
}

inline 
ZSoft::UInt32 ZcGiImageBGRA32::width() const
{
	return m_nImageWidth;
}

inline 
ZSoft::UInt32 ZcGiImageBGRA32::height() const
{
	return m_nImageHeight;
}

inline 
void ZcGiImageBGRA32::setImage(ZSoft::UInt32 imageWidth, ZSoft::UInt32 imageHeight, ZcGiPixelBGRA32* imageData)
{
	m_nImageWidth   = imageWidth;
	m_nImageHeight  = imageHeight;
	m_pImageData    = imageData;
}

class ZcGiSubEntityTraits;
class ZcGiDrawableTraits;
class ZcGiSubEntityTraitsImp;
class ZcGiWorldGeometry;
class ZcGiViewport;
class ZcGiViewportGeometry;
class ZcGiImpEdgeData;
class ZcGiImpFaceData;
class ZcGiImpVertexData;
class ZcGiImpTextStyle;
class ZcGiImpPolyline;
class ZcGiTextStyle;
class ZcGiEdgeData;
class ZcGiFaceData;
class ZcGiVertexData;
class OwnerDraw;
class ZcGiImpVariant;
class ZcGiVariant;
class ZcGiContextImp;
class ZcGiContext;
class ZcGiCommonDraw;
class ZcGiGeometry;
class ZcCmEntityColor;
struct TextParams;
struct FontInfo;
class ZcGiMapper;
class ZcGiViewportTraits;
class ZcGiVisualStyleTraits;
class ZcGiContextualColors;
class ZcGiGdiDrawObject;
class ZcGiImpHatchPatternDefinition;
class ZcGiImpHatchPattern;
class ZcGiFill;
class ZcGiImpFill;
class ZcGiImpGradientFill;
class ZcUniqueString;
class ZcFontHandle;
class ZcDbPolyline;

typedef void (*ZcGiWorldSegmentCallback)(const ZcGePoint3d *);

bool zcgiIsValidClipBoundary(const ZcGePoint2dArray& pts);

Zcad::ErrorStatus zcgiGetRegenBlockRefStack(ZcDbObjectIdArray& blkRefs);
class ZCDBCORE2D_PORT ZcGiVariant : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiVariant);

    ZcGiVariant(void);
    virtual ~ZcGiVariant(void);

    ZcGiVariant             (const ZcGiVariant & value);
    ZcGiVariant & operator= (const ZcGiVariant & value);
    virtual bool  operator==(const ZcGiVariant & value) const;

    virtual Zcad::ErrorStatus copyFrom(const ZcRxObject* other) override;

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
        explicit EnumType (int value) : m_value(value) { }
        
        template <typename T>
        operator T () { return static_cast<T>(m_value); }

        template <typename T>
        bool operator== (T right) const { return static_cast<int>(right) == m_value; }

        template <typename T>
        bool operator!= (T right) const { return !(*this == right); }

    protected:    
        int m_value;
    };

    ZcGiVariant(bool);
    ZcGiVariant(ZSoft::Int32);
    ZcGiVariant(double);
    ZcGiVariant(const ZcCmColor&); 
    ZcGiVariant(const ZTCHAR *); 

    VariantType type() const;

    void                set(bool);
    void                set(ZSoft::Int32);
    void                set(double);
    void                set(const ZcCmColor&); 
    void                set(const ZTCHAR *); 

    bool                asBoolean() const;
    int                 asInt() const;
    double              asDouble() const;
    ZcCmColor           asColor() const;
    ZcString            asString() const;
    float               asFloat() const;
    char                asChar() const;
    unsigned char       asUchar() const;
    short               asShort() const;
    unsigned short      asUshort() const;
    unsigned int        asUint() const;
    ZSoft::Int32                asLong() const;
    ZSoft::UInt32       asUlong() const;
    EnumType            asEnum() const;
	Zcad::ErrorStatus   getElem(const ZTCHAR *, ZcGiVariant & value) const;
	const ZcGiVariant*  getElem(const ZTCHAR *) const;
	void                setElem(const ZTCHAR *, const ZcGiVariant&);
    void                deleteElem(const ZTCHAR *);

    int                 getElemCount() const;
    Zcad::ErrorStatus getElemAt(int nIndex, ZcString &, ZcGiVariant &) const;
	Zcad::ErrorStatus   getElemAt(int, ZTCHAR*&, ZcGiVariant &) const; 
    ZcGiVariant*      getElemAt(int nIndex, ZcString &) const;
	ZcGiVariant*        getElemAt(int, ZTCHAR*&) const;                

    static bool         isEquivalent(const ZcGiVariant*, const ZcGiVariant*);

private:
    ZcGiImpVariant * mpZcGiImpVariant;
};

inline Zcad::ErrorStatus ZcGiVariant::getElemAt(int nIndex, ZTCHAR*&pStr, ZcGiVariant &var) const
{
    ZcString sElem;
    const Zcad::ErrorStatus es = this->getElemAt(nIndex, sElem, var);
    if (es != Zcad::eOk)
        pStr = nullptr;
    else
        ::zcutNewString(sElem.constPtr(), pStr);
    return es;
}

inline ZcGiVariant * ZcGiVariant::getElemAt(int nIndex, ZTCHAR*&pStr) const
{
    ZcString sElem;
    ZcGiVariant *pVar = this->getElemAt(nIndex, sElem);
    ::zcutNewString(sElem.constPtr(), pStr);
    return pVar;
}

template <typename T>
inline bool operator== (T left, const ZcGiVariant::EnumType right)
{
	return (right == left);
}

template <typename T>
inline bool operator!= (T left, const ZcGiVariant::EnumType right)
{
	return (right != left);
}

class ZcGiKernelDescriptor : public ZcArray<const ZcUniqueString *>
{
public:

    void addRequirement(const ZcUniqueString *capability)
    {
        if (capability != nullptr)
            append(capability);
    }

    bool supports(const ZcUniqueString *capability) const
    {
        return capability ? contains(capability) : false;
    }

    bool supports(const ZcGiKernelDescriptor& desc) const
    {
        int len = desc.length();
        for (int i=0; i<len; i++)
        {
            if (!contains(desc[i]) && desc[i] != nullptr)
                return false;
        }
        return true;
    }
};

class ZcGiGraphicsKernel
{
public:
    virtual ~ZcGiGraphicsKernel() { }
    virtual const ZcGiKernelDescriptor &getDescriptor(void) const { return m_descriptor; }

private:
    ZcGiKernelDescriptor m_descriptor;
};

#pragma warning (push)
#pragma warning (disable : 4100)
class ZCDBCORE2D_PORT ZcGiContext : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiContext);

    virtual ZSoft::Boolean          isPsOut() const = 0;
    virtual ZSoft::Boolean          isPlotGeneration() const = 0;
    virtual ZcDbDatabase *          database() const = 0;
    virtual bool             isBoundaryClipping() const = 0;

    virtual class ZcGiGraphicsKernel &graphicsKernel() { static ZcGiGraphicsKernel kernel; return kernel; }
    virtual void          disableFastMoveDrag() const{};

    virtual bool isNesting() const { return false; }

    virtual ZcCmEntityColor   effectiveColor() const { return ZcCmEntityColor(); }
    virtual ZcDb::LineWeight  byBlockLineWeight() const { return ZcDb::kLnWt000; }
    virtual ZcDbObjectId      byBlockPlotStyleNameId() const { return ZcDbObjectId::kNull; }
    virtual ZcDbObjectId      byBlockMaterialId() const { return ZcDbObjectId::kNull; }

    virtual bool supportsTrueTypeText() { return false; }
    virtual bool supportsOwnerDraw() {return false;}
	virtual bool supportsFillTrait() const { return false; }

    virtual ZSoft::Boolean  supportsFastRenderBuffer() const { return ZSoft::kFalse; }

    virtual ZSoft::Boolean  supportsNativePointCloudRender() const { return ZSoft::kFalse; }

    virtual ZcGiContextImp * getImpPtr() { return nullptr; }
    virtual const ZcGiContextImp * getConstImpPtr() const { return nullptr; }
	virtual void setProperty(ZSoft::Int32 propertyFlag, bool bIsSet = true) {}
protected:

    friend class ZcGiTextHook;
    friend class CShFont;
    friend class ZcDbImpText;

    virtual ZcGiWorldSegmentCallback wSegTaker() const { return nullptr; }
    virtual int getTrueTypeBoundingBox(ZcGePoint3d const & location,
                                       const wchar_t * text,
                                       int length, TextParams const * tp,
                                       ZcGePoint3d * bbox, float * char_widths)
                                        { return 0; }
    
    virtual int getTrueTypeTextExtents(ZTCHAR const *, Charset, double,
                                       int,int,
                                       int,short,short,double,double,
                                       ZcGePoint2d &,ZcGePoint2d &) 	
                                       { return -1; }

    virtual int setTrueTypeTransform(const ZcGePoint3d &,const ZcGeVector3d &,
                                     double,double,double,bool,bool) 
                                     { return 0; }

    virtual int drawTrueTypeText(const ZTCHAR *,double,int,bool,
                                 const TextParams &,Charset){ return 0; }
    virtual int restoreTrueTypeTransform() { return 0; }
    virtual void bypassHiddenLineRemoval() {}
    virtual int setTextStyle(int);

    virtual ZcFontHandle* loadTrueTypeFont(const ZTCHAR *, bool, bool, Charset, int, FontInfo &) { return nullptr; }

};

class ZcGiContext2 : public ZcGiContext
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcGiContext2, ZCDBCORE2D_PORT);

    virtual bool forceUseFillTrait() const { return false; }
    virtual bool suppressHatchSmartMode() const { return false; }
    virtual bool suppressHatchBoundary() const { return false; }
};

class ZCDBCORE2D_PORT ZcGiCommonDraw : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiCommonDraw);
    virtual ZcGiRegenType           regenType() const = 0;
    virtual ZSoft::Boolean          regenAbort() const = 0;
    virtual ZcGiSubEntityTraits&    subEntityTraits() const = 0;
    virtual ZcGiGeometry *   rawGeometry() const = 0;
    virtual ZSoft::Boolean          isDragging() const = 0;

    virtual double                deviation(const ZcGiDeviationType, 
                                            const ZcGePoint3d&) const = 0;
    virtual ZSoft::UInt32           numberOfIsolines() const = 0;
    
    virtual ZcGiContext *      context() = 0;
    virtual bool               secondaryCall() const { return false; }
};

class ZCDBCORE2D_PORT ZcGiWorldDraw: public ZcGiCommonDraw
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiWorldDraw);
    virtual ZcGiWorldGeometry&      geometry() const = 0;
};

class ZCDBCORE2D_PORT ZcGiViewportDraw: public ZcGiCommonDraw 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcGiViewportDraw);
    virtual ZcGiViewport&        viewport() const = 0;
    virtual ZcGiViewportGeometry& geometry() const = 0;
    virtual ZSoft::UInt32        sequenceNumber() const = 0;
    virtual ZSoft::Boolean       isValidId(const ZSoft::ULongPtr zcgiId) const =0;
    virtual ZcDbObjectId         viewportObjectId() const = 0;
};

class ZCDBCORE2D_PORT ZcGiViewport: public ZcRxObject 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcGiViewport);

    virtual void getModelToEyeTransform(ZcGeMatrix3d&) const = 0;
    virtual void getEyeToModelTransform(ZcGeMatrix3d&) const = 0;
    virtual void getWorldToEyeTransform(ZcGeMatrix3d&) const = 0;
    virtual void getEyeToWorldTransform(ZcGeMatrix3d&) const = 0;

    virtual ZSoft::Boolean isPerspective() const = 0;
    virtual ZSoft::Boolean doPerspective(ZcGePoint3d&) const = 0;
    virtual ZSoft::Boolean doInversePerspective(ZcGePoint3d&) const = 0;

    virtual void getNumPixelsInUnitSquare(const ZcGePoint3d& givenWorldpt,
                                  ZcGePoint2d& pixelArea,
                                  bool includePerspective = true) const = 0;
    virtual void getCameraLocation(ZcGePoint3d& location) const = 0;
    virtual void getCameraTarget(ZcGePoint3d& target) const = 0;
    virtual void getCameraUpVector(ZcGeVector3d& upVector) const = 0;

    virtual ZSoft::ULongPtr viewportId() const = 0;
    virtual ZSoft::Int16  zcadWindowId() const = 0;
    virtual void getViewportDcCorners(ZcGePoint2d& lower_left,
                                      ZcGePoint2d& upper_right) const = 0;

    virtual ZSoft::Boolean getFrontAndBackClipValues(ZSoft::Boolean& clip_front,
                                         ZSoft::Boolean& clip_back,
                                         double& front,
                                         double& back) const = 0;

    virtual double linetypeScaleMultiplier() const = 0;

    virtual double linetypeGenerationCriteria() const = 0;

    virtual ZSoft::Boolean layerVisible(const ZcDbObjectId & idLayer) const { return ZSoft::kTrue; }

    virtual ZcGeVector3d viewDir() const { return ZcGeVector3d::kZAxis; }
    virtual const ZcGiContextualColors* contextualColors() const { return NULL; }
};

class ZCDBCORE2D_PORT ZcGiContextualColors : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiContextualColors);
    virtual ZSoft::UInt32 gridMajorLines() const = 0;
    virtual ZSoft::UInt32 gridMinorLines() const = 0;
    virtual ZSoft::UInt32 gridAxisLines() const = 0;
    virtual int gridMajorLineTintXYZ() const = 0;
    virtual int gridMinorLineTintXYZ() const = 0;
    virtual int gridAxisLineTintXYZ() const = 0;

    virtual ZSoft::UInt32 lightGlyphs() const = 0;
    virtual ZSoft::UInt32 lightHotspot() const = 0;
    virtual ZSoft::UInt32 lightFalloff() const = 0;
    virtual ZSoft::UInt32 lightStartLimit() const = 0;
    virtual ZSoft::UInt32 lightEndLimit() const = 0;

    virtual ZSoft::UInt32 cameraGlyphs() const = 0;
    virtual ZSoft::UInt32 cameraFrustrum() const = 0;
    virtual ZSoft::UInt32 cameraClipping() const = 0;
    virtual void setContextFlags(ZSoft::UInt32 flg, bool set = true) = 0;
    virtual bool flagsSet(ZSoft::UInt32 flg) const = 0;
};

class  ZCDBCORE2D_PORT  ZcGiContextualColors2 : public ZcGiContextualColors
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiContextualColors2);

    virtual ZcCmColor     webMeshColor        (void) const = 0;
    virtual ZcCmColor     webMeshMissingColor (void) const = 0;
    virtual ZcCmColor     lightShapeColor     (void) const = 0;
    virtual ZcCmColor     lightDistanceColor  (void) const = 0;
};

#define ZcGiSelectionMarkerZCADReserveStart         (-2147483647 - 1)
#define ZcGiSelectionMarkerZCADReserveEnd           (ZcGiSelectionMarkerZCADReserveStart + 65535)

#define ZcGiSelectionMarkerZCADSelectionPreviewOff  (ZcGiSelectionMarkerZCADReserveStart + 1)
#define ZcGiSelectionMarkerZCADSelectionPreviewOn   (ZcGiSelectionMarkerZCADReserveStart + 2)

class ZCDBCORE2D_PORT ZcGiSubEntityTraits: public ZcRxObject 
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiSubEntityTraits);

    enum DrawFlags
    {
        kNoDrawFlags        =   0,
        kDrawBackfaces      =   1,
        kDrawHatchGroup     =   2,
		kDrawFrontfacesOnly =   4,
		kDrawGradientFill   =   8,
		kDrawSolidFill      =   16,
		kDrawNoLineWeight   =   32,
		kDrawNoOptimization =   64,
		kDrawUseZcGiEntityForDgnLineType = 128,
		kDrawFillTextBoundaryStart       = 256,
		kDrawFillTextBoundaryEnd         = 512,
		kDrawFillSelectionWindow         = 1024,
        kDrawNoForceByLayer              = 2048,
        kDrawIsInWCS                     = 4096,
        kDrawNoImageFrame                = 8192
    };

    enum ShadowFlags
    {
        kShadowsCastAndReceive  = 0x00,
        kShadowsDoesNotCast     = 0x01,
        kShadowsDoesNotReceive  = 0x02,
        kShadowsIgnore          = kShadowsDoesNotCast | kShadowsDoesNotReceive,
    };

	enum SelectionFlags
	{
		kNoSelectionFlags   =   0x00,
		kSelectionIgnore    =   0x01
	};

    virtual void              setColor              (const ZSoft::UInt16 color) = 0;
    virtual void              setTrueColor          (const ZcCmEntityColor& color) = 0;
    virtual void              setLayer              (const ZcDbObjectId layerId) = 0;
    virtual void              setLineType           (const ZcDbObjectId linetypeId) = 0;
    virtual void              setSelectionMarker    (const ZSoft::LongPtr markerId) = 0;
    virtual void              setFillType           (const ZcGiFillType) = 0;
    virtual void              setLineWeight         (const ZcDb::LineWeight lw) = 0;
    virtual void              setLineWeight         (const ZcDb::LineWeight lw, const char lweight_index);
    virtual void              setLineTypeScale      (double dScale = 1.0) = 0;
    virtual void              setThickness          (double dThickness) = 0;
    virtual void              setVisualStyle        (const ZcDbObjectId visualStyleId);
    virtual void              setPlotStyleName      (ZcDb::PlotStyleNameType type, const ZcDbObjectId & id = ZcDbObjectId::kNull) {}
    virtual void              setMaterial           (const ZcDbObjectId materialId);
    virtual void              setMapper             (const ZcGiMapper * mapper);
    virtual void              setSectionable        (bool bSectionable);
    virtual Zcad::ErrorStatus setDrawFlags          (ZSoft::UInt32 flags);
    virtual Zcad::ErrorStatus setShadowFlags        (ShadowFlags flags);
    virtual void              setSelectionGeom      (bool bSelectionflag);
	virtual void              setTransparency       (const ZcCmTransparency& transparency);
	virtual void              setFill               (const ZcGiFill* pFill);

    virtual ZSoft::UInt16           color               (void) const = 0;
    virtual ZcCmEntityColor         trueColor           (void) const = 0;
    virtual ZcDbObjectId            layerId             (void) const = 0;
    virtual ZcDbObjectId            lineTypeId          (void) const = 0;
    virtual ZcGiFillType            fillType            (void) const = 0;
    virtual ZcDb::LineWeight        lineWeight          (void) const = 0;
    virtual double                  lineTypeScale       (void) const = 0;
    virtual double                  thickness           (void) const = 0;
    virtual ZcDbObjectId            visualStyle         (void) const;
    virtual ZcDb::PlotStyleNameType getPlotStyleNameId  (ZcDbObjectId& idResult) const { return ZcDb::kPlotStyleNameByLayer ; }
    virtual ZcDbObjectId            materialId          (void) const;
    virtual const ZcGiMapper *      mapper              (void) const;
    virtual bool                    sectionable         (void) const;
    virtual ZSoft::UInt32           drawFlags           (void) const;
    virtual ShadowFlags             shadowFlags         (void) const;
    virtual bool                    selectionGeom       (void) const;
	virtual ZcCmTransparency        transparency        (void) const;
	virtual const ZcGiFill*         fill                (void) const;

	virtual void pushMarkerOverride(bool flag, const ZSoft::LongPtr markerId) { }
	virtual void popMarkerOverride(void) { }
	virtual void clearMarkerOverride(void) { }
};

inline void
ZcGiSubEntityTraits::setLineWeight(const ZcDb::LineWeight lw, const char)
{
    setLineWeight(lw);
}

inline void
ZcGiSubEntityTraits::setMaterial(const ZcDbObjectId materialId)
{
}

inline ZcDbObjectId
ZcGiSubEntityTraits::materialId(void) const
{
    return ZcDbObjectId::kNull;
}

inline
void ZcGiSubEntityTraits::setMapper (const ZcGiMapper * mapper)
{
}

inline const ZcGiMapper *
ZcGiSubEntityTraits::mapper (void) const
{
    return NULL;
}

inline void
ZcGiSubEntityTraits::setVisualStyle(ZcDbObjectId visualStyleId)
{
}

inline ZcDbObjectId
ZcGiSubEntityTraits::visualStyle(void) const
{
    return ZcDbObjectId::kNull;
}

inline void
ZcGiSubEntityTraits::setSectionable(bool bSectionable)
{
}

inline bool
ZcGiSubEntityTraits::sectionable(void) const
{
    return false;
}

inline Zcad::ErrorStatus
ZcGiSubEntityTraits::setDrawFlags (ZSoft::UInt32 flags)
{
    return Zcad::eNotImplementedYet;
}

inline ZSoft::UInt32
ZcGiSubEntityTraits::drawFlags (void) const
{
    return 0;
}

inline Zcad::ErrorStatus
ZcGiSubEntityTraits::setShadowFlags (ShadowFlags flags)
{
    return Zcad::eNotImplementedYet;
}

inline ZcGiSubEntityTraits::ShadowFlags
ZcGiSubEntityTraits::shadowFlags (void) const
{
    return kShadowsCastAndReceive;
}

inline void
ZcGiSubEntityTraits::setSelectionGeom ( bool )
{
}

inline bool
ZcGiSubEntityTraits::selectionGeom ( void ) const
{
    return false;
}

inline 
void ZcGiSubEntityTraits::setTransparency (const ZcCmTransparency&)
{
}


inline 
ZcCmTransparency ZcGiSubEntityTraits::transparency (void) const
{
	return ZcCmTransparency();
}

inline 
void ZcGiSubEntityTraits::setFill(const ZcGiFill * /*pFill*/)
{
}

inline const ZcGiFill *ZcGiSubEntityTraits::fill(void) const
{
	return nullptr;
}

class ZCDBCORE2D_PORT ZcGiDrawableTraits: public ZcGiSubEntityTraits
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcGiDrawableTraits);
	enum HighlightProperty
	{
		kVertexRolloverHighlightSize,
	};
    virtual void setupForEntity(ZcDbEntity * pEntity);
    virtual void addLight(const ZcDbObjectId& lightId);

	virtual void              setLinePattern       (const ZcGiLineType linePattern);
	virtual ZcGiLineType      linePattern          (void) const;

	virtual Zcad::ErrorStatus setSelectionFlags    (const SelectionFlags flags);
	virtual SelectionFlags    selectionFlags       (void) const;

	virtual Zcad::ErrorStatus setHighlightProperty (HighlightProperty property, ZcGiVariant& value);
	virtual ZcGiVariant       highlightProperty    (HighlightProperty property) const;

	virtual ZcGiContext      *context              (void) const { return nullptr; }

protected:
    friend class ZcDbImpLayerTableRecord;

    enum LayerFlags {
        kNone       = 0x00,
        kOff        = 0x01,
        kFrozen     = 0x02,
        kZero       = 0x04,
		kLocked     = 0x08
    };

    virtual void    setLayerFlags       (ZSoft::UInt8 flags)        { }
};

inline void
ZcGiDrawableTraits::addLight(const ZcDbObjectId& lightId)
{
}

inline 
void ZcGiDrawableTraits::setLinePattern (const ZcGiLineType linePattern)
{
}

inline 
ZcGiLineType ZcGiDrawableTraits::linePattern (void) const
{
	return kLineTypeSolid;
}

inline 
Zcad::ErrorStatus ZcGiDrawableTraits::setSelectionFlags (const SelectionFlags flags)
{
	return Zcad::eOk;
}

inline 
ZcGiSubEntityTraits::SelectionFlags	ZcGiDrawableTraits::selectionFlags (void) const
{
	return kNoSelectionFlags;
}

inline 
Zcad::ErrorStatus ZcGiDrawableTraits::setHighlightProperty(HighlightProperty property, ZcGiVariant&       value)
{
	return Zcad::eOk;
}

inline 
ZcGiVariant	ZcGiDrawableTraits::highlightProperty(HighlightProperty property) const
{
	return ZcGiVariant();
}

class ZCDBCORE2D_PORT ZcGiNonEntityTraits : public ZcGiDrawableTraits
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiNonEntityTraits);
    virtual void                setupForEntity      (ZcDbEntity* pEntity) override;
    virtual void                addLight(const ZcDbObjectId& id) override;
    virtual void                setColor            (const ZSoft::UInt16 color) override;
    virtual ZSoft::UInt16       color               (void) const override;
    virtual void                setTrueColor        (const ZcCmEntityColor& color) override;
    virtual ZcCmEntityColor     trueColor           (void) const override;
    virtual void                setLayer            (const ZcDbObjectId layerId) override;
    virtual ZcDbObjectId        layerId             (void) const override;
    virtual void                setLineType         (const ZcDbObjectId linetypeId) override;
    virtual ZcDbObjectId        lineTypeId          (void) const override;
    virtual void                setSelectionMarker  (const ZSoft::LongPtr markerId) override;
    virtual void                setFillType         (const ZcGiFillType fillType) override;
    virtual ZcGiFillType        fillType            (void) const override;
    virtual void                setLineWeight       (const ZcDb::LineWeight lw) override;
    virtual ZcDb::LineWeight    lineWeight          (void) const override;
    virtual void                setThickness        (double thickness) override;
    virtual double              thickness           (void) const override;
    virtual void                setLineTypeScale    (double dScale) override;
    virtual double              lineTypeScale       (void) const override;
    virtual void                setMaterial         (const ZcDbObjectId matId) override;
    virtual ZcDbObjectId        materialId          (void) const override;
    virtual void                setSelectionGeom    (bool bSelectionflag) override;
    virtual bool                selectionGeom       ( void ) const override;

	virtual void                setTransparency     (const ZcCmTransparency& transparency) override;
	virtual ZcCmTransparency    transparency        (void) const override;

};

inline void
ZcGiNonEntityTraits::setupForEntity (ZcDbEntity* pEntity)
{
    assert(false);
}

inline void
ZcGiNonEntityTraits::addLight(const ZcDbObjectId& id)
{
    assert(false);
}

inline void
ZcGiNonEntityTraits::setColor (const ZSoft::UInt16 color)
{
    assert(false);
}

inline ZSoft::UInt16
ZcGiNonEntityTraits::color (void) const
{
    assert(false);
    return 0;
}

inline void
ZcGiNonEntityTraits::setTrueColor (const ZcCmEntityColor& color)
{
    assert(false);
}

inline ZcCmEntityColor
ZcGiNonEntityTraits::trueColor (void) const
{
    assert(false);
    return ZcCmEntityColor();
}

inline void
ZcGiNonEntityTraits::setLayer (const ZcDbObjectId layerId)
{
    assert(false);
}

inline ZcDbObjectId
ZcGiNonEntityTraits::layerId (void) const
{
    assert(false);
    return ZcDbObjectId::kNull;
}

inline void
ZcGiNonEntityTraits::setLineType (const ZcDbObjectId linetypeId)
{
    assert(false);
}

inline ZcDbObjectId ZcGiNonEntityTraits::lineTypeId (void) const
{
    assert(false);
    return  ZcDbObjectId::kNull;
}

inline void
ZcGiNonEntityTraits::setMaterial(const ZcDbObjectId matId)
{
    assert(false);
}

inline ZcDbObjectId ZcGiNonEntityTraits::materialId (void) const
{
    assert(false);
    return  ZcDbObjectId::kNull;
}

inline void
ZcGiNonEntityTraits::setSelectionMarker (const ZSoft::LongPtr markerId)
{
    assert(false);
}

inline void
ZcGiNonEntityTraits::setFillType (const ZcGiFillType fillType)
{
    assert(false);
}

inline ZcGiFillType
ZcGiNonEntityTraits::fillType (void) const
{
    assert(false);
    return kZcGiFillAlways;
}

inline void
ZcGiNonEntityTraits::setLineWeight (const ZcDb::LineWeight lw)
{
    assert(false);
}

inline ZcDb::LineWeight
ZcGiNonEntityTraits::lineWeight (void) const
{
    assert(false);
    return ZcDb::kLnWt000;
}

inline void
ZcGiNonEntityTraits::setThickness (double thickness)
{
    assert(false);
}

inline double
ZcGiNonEntityTraits::thickness (void) const
{
    assert(false);
    return 0.0;
}

inline void
ZcGiNonEntityTraits::setLineTypeScale (double dScale)
{
    assert(false);
}

inline double
ZcGiNonEntityTraits::lineTypeScale (void) const
{
    assert(false);
    return 0.0;
}

inline void
ZcGiNonEntityTraits::setSelectionGeom ( bool )
{
    assert(false);
}

inline bool
ZcGiNonEntityTraits::selectionGeom ( void ) const
{
    assert(false);
    return false;
}

inline
void ZcGiNonEntityTraits::setTransparency (const ZcCmTransparency& )  
{ 
	assert(false);
}

inline 
ZcCmTransparency ZcGiNonEntityTraits::transparency (void) const
{ 
	assert(false);
	return ZcCmTransparency(); 
}


#ifndef _WINDEF_
struct HDC__ ;
typedef     struct HDC__ *          HDC;
#endif

class ZCDBCORE2D_PORT ZcGiGdiDrawObject: public ZcRxObject
{
public:
	ZCRX_DECLARE_MEMBERS(ZcGiGdiDrawObject);

	virtual ZSoft::Boolean    draw(HDC hDC, int x, int y, int w, int h) = 0;
	virtual int               width() const = 0;
	virtual int               height() const = 0;

	virtual void              addRef() = 0;
	virtual void              delRef() = 0;
};

class ZCDBCORE2D_PORT ZcGiPolyline : public ZcGiParameter
{
public:
	ZCRX_DECLARE_MEMBERS_READWRITE(ZcGiPolyline, ZcGiImpPolyline);

	ZcGiPolyline();
	ZcGiPolyline(ZSoft::UInt32 nbPoints, ZcGePoint3d* pVertexList, ZcGeVector3d* pNormal = NULL, ZSoft::LongPtr lBaseSubEntMarker = -1);
	~ZcGiPolyline();

	enum LinetypeGeneration { kPerSegment, kEndToEnd };
	
	virtual ZSoft::UInt32         points() const;
	virtual const ZcGePoint3d*    vertexList() const;
	virtual const ZcGeVector3d*   normal() const;
	virtual LinetypeGeneration    linetypeGen() const;
	virtual ZSoft::LongPtr        baseSubEntMarker() const;
	virtual const ZSoft::LongPtr* subEntMarkerList() const;
    virtual bool hasGsMarker() const;
	virtual const bool*           arcSegmentFlags() const;
    virtual bool isClosed() const;
    virtual double elevation() const;
    virtual double thickness() const;
    virtual double constantWidth() const;
    virtual const double* bulge() const;
    virtual const double* width() const;
    virtual bool hasBulges() const;
    virtual bool hasWidth() const;
    virtual bool getPointAt(unsigned int idx, ZcGePoint3d& pt) const;
    virtual bool getBulgeAt(unsigned int idx, double& bulge) const;
    virtual bool getWidthsAt(unsigned int idx, double& startWidth, double& endWidth) const;

	virtual void setVertexList(ZSoft::UInt32 nbPoints, const ZcGePoint3d* pVertexList);
	virtual void setNormal(const ZcGeVector3d* pNormal);
	virtual void setLinetypeGen(LinetypeGeneration ltgen);
	virtual void setBaseSubEntMarker(ZSoft::LongPtr lBaseSubEntMarker);
	virtual void setSubEntMarkerList(const ZSoft::LongPtr* pSubEntMarkerList);
	virtual void setArcSegmentFlags(const bool* pArcSegmentFlags);
    virtual void setClosed(bool val);
    virtual void setElevation(double val);
    virtual void setThickness(double val);
    virtual void setConstantWidth(double val);
    virtual void setBulge(const double* pBulge);
    virtual void setWidth(const double* pWidth);
};


typedef enum { 
	kZcGiWorldPosition,
	kZcGiViewportPosition,
	kZcGiScreenPosition,
	kZcGiScreenLocalOriginPosition,
	kZcGiWorldWithScreenOffsetPosition
} ZcGiPositionTransformBehavior;

typedef enum { 
	kZcGiWorldScale,
	kZcGiViewportScale,
	kZcGiScreenScale,
	kZcGiViewportLocalOriginScale,
	kZcGiScreenLocalOriginScale
} ZcGiScaleTransformBehavior;

typedef enum { 
	kZcGiWorldOrientation,
	kZcGiScreenOrientation,
	kZcGiZAxisOrientation
} ZcGiOrientationTransformBehavior;

class ZCDBCORE2D_PORT ZcGiGeometry: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiGeometry);
	enum TransparencyMode
	{
		kTransparencyOff,
		kTransparency1Bit,
		kTransparency8Bit,
	};
    virtual void getModelToWorldTransform(ZcGeMatrix3d&) const = 0;
    virtual void getWorldToModelTransform(ZcGeMatrix3d&) const = 0;

    virtual ZSoft::Boolean pushModelTransform(const ZcGeVector3d & vNormal) = 0;
    virtual ZSoft::Boolean pushModelTransform(const ZcGeMatrix3d & xMat) = 0;
    virtual ZSoft::Boolean popModelTransform() = 0;
    virtual ZcGeMatrix3d pushPositionTransform (ZcGiPositionTransformBehavior behavior, const ZcGePoint3d& offset) = 0;
    virtual ZcGeMatrix3d pushPositionTransform (ZcGiPositionTransformBehavior behavior, const ZcGePoint2d& offset) = 0;
    virtual ZcGeMatrix3d pushScaleTransform (ZcGiScaleTransformBehavior behavior, const ZcGePoint3d& extents) = 0;
    virtual ZcGeMatrix3d pushScaleTransform (ZcGiScaleTransformBehavior behavior, const ZcGePoint2d& extents) = 0;
    virtual ZcGeMatrix3d pushOrientationTransform (ZcGiOrientationTransformBehavior behavior) = 0;

    virtual ZSoft::Boolean  circle(const ZcGePoint3d& center,
                                   const double radius,
                                   const ZcGeVector3d& normal) const = 0;

    virtual ZSoft::Boolean  circle(const ZcGePoint3d&, const ZcGePoint3d&,
                                   const ZcGePoint3d&) const = 0;

    virtual ZSoft::Boolean  circularArc(const ZcGePoint3d& center,
                                   const double radius,
                                   const ZcGeVector3d& normal,
                                   const ZcGeVector3d& startVector,
                                   const double sweepAngle,
                                   const ZcGiArcType arcType = kZcGiArcSimple) const = 0;

    virtual ZSoft::Boolean  circularArc(const ZcGePoint3d& start,
                                   const ZcGePoint3d& point,
                                   const ZcGePoint3d& end,
                                   const ZcGiArcType arcType = kZcGiArcSimple) const = 0;

    virtual ZSoft::Boolean  polyline(const ZSoft::UInt32 nbPoints,
                                   const ZcGePoint3d* pVertexList,
                                   const ZcGeVector3d* pNormal = NULL,
                                   ZSoft::LongPtr lBaseSubEntMarker = -1) const = 0;

    virtual ZSoft::Boolean  polyline(const ZcGiPolyline& polylineObj) const = 0;
    virtual ZSoft::Boolean  polyPolyline (ZSoft::UInt32 nbPolylines,
                                          const ZcGiPolyline* pPolylines) const = 0;
    virtual ZSoft::Boolean  polygon(const ZSoft::UInt32 nbPoints,
                                   const ZcGePoint3d* pVertexList) const = 0;

    virtual ZSoft::Boolean  polyPolygon(const ZSoft::UInt32 numPolygonIndices,
                                        const ZSoft::UInt32* numPolygonPositions,
                                        const ZcGePoint3d* polygonPositions,
                                        const ZSoft::UInt32* numPolygonPoints,
                                        const ZcGePoint3d* polygonPoints,
                                        const ZcCmEntityColor* outlineColors = NULL,
                                        const ZcGiLineType* outlineTypes = NULL,
                                        const ZcCmEntityColor* fillColors = NULL,
                                        const ZcCmTransparency* fillOpacities = NULL) const  = 0;
    virtual ZSoft::Boolean  mesh(const ZSoft::UInt32 rows,
                                 const ZSoft::UInt32 columns,
                                 const ZcGePoint3d* pVertexList,
                                 const ZcGiEdgeData* pEdgeData = NULL,
                                 const ZcGiFaceData* pFaceData = NULL,
                                 const ZcGiVertexData* pVertexData = NULL,
                                 const bool bAutoGenerateNormals = true
                                 ) const = 0;

    virtual ZSoft::Boolean  shell(const ZSoft::UInt32 nbVertex,
                                 const ZcGePoint3d* pVertexList,
                                 const ZSoft::UInt32 faceListSize,
                                 const ZSoft::Int32* pFaceList,
                                 const ZcGiEdgeData* pEdgeData = NULL,
                                 const ZcGiFaceData* pFaceData = NULL,
                                 const ZcGiVertexData* pVertexData = NULL,
                                 const struct resbuf* pResBuf = NULL,
                                 const bool bAutoGenerateNormals = true
                                 ) const = 0;

    virtual ZSoft::Boolean  text(const ZcGePoint3d& position,
                                 const ZcGeVector3d& normal,
                                 const ZcGeVector3d& direction,
                                 const double height,
                                 const double width,
                                 const double oblique,
                                 const ZTCHAR* pMsg) const = 0;

    virtual ZSoft::Boolean  text(const ZcGePoint3d& position,
                                 const ZcGeVector3d& normal,
                                 const ZcGeVector3d& direction,
                                 const ZTCHAR* pMsg,
                                 const ZSoft::Int32 length,
                                 const ZSoft::Boolean raw,
                                 const ZcGiTextStyle &pTextStyle
                                 ) const = 0;

    virtual ZSoft::Boolean  xline(const ZcGePoint3d&,
                                  const ZcGePoint3d&) const = 0;

    virtual ZSoft::Boolean  ray(const ZcGePoint3d&,
                                const ZcGePoint3d&) const = 0;

    virtual ZSoft::Boolean  pline(const ZcDbPolyline& lwBuf,
                                  ZSoft::UInt32 fromIndex = 0,
                                  ZSoft::UInt32 numSegs = 0
                                  ) const = 0;

    virtual ZSoft::Boolean  draw(ZcGiDrawable*) const = 0;

    virtual ZSoft::Boolean  image(const ZcGiImageBGRA32& imageSource,
                                  const ZcGePoint3d& position,
                                  const ZcGeVector3d& u,
                                  const ZcGeVector3d& v,
                                  TransparencyMode transparencyMode = kTransparency8Bit
                                  ) const = 0;

    virtual ZSoft::Boolean  rowOfDots(int count,
                                      const ZcGePoint3d&     start,
                                      const ZcGeVector3d&     step
                                     ) const = 0;

    virtual ZSoft::Boolean  ellipticalArc(const ZcGePoint3d&         center,
                                          const ZcGeVector3d&        normal,
                                          double                     majorAxisLength,
                                          double                     minorAxisLength,
                                          double                     startDegreeInRads,
                                          double                     endDegreeInRads,
                                          double                     tiltDegreeInRads,
                                          ZcGiArcType                arcType = kZcGiArcSimple
                                          ) const = 0 ;

    virtual ZSoft::Boolean          pushClipBoundary(ZcGiClipBoundary * pBoundary) = 0;
    virtual void                    popClipBoundary() = 0;
    virtual ZSoft::Boolean   worldLine(const ZcGePoint3d pnts[2]) {
                                        ZcGePoint3d polyPnts[2];
                                        ZcGeMatrix3d mat;
                                        getWorldToModelTransform(mat);
                                        polyPnts[0] = mat * pnts[0];
                                        polyPnts[1] = mat * pnts[1];
                                        return polyline(2, polyPnts);
                                    };

    virtual ZSoft::Boolean  polypoint( const ZSoft::UInt32 nbPoints,
                                       const ZcGePoint3d* pVertexList,
                                       const ZcGeVector3d* pNormal = NULL,
                                       const ZSoft::LongPtr *pSubEntMarkers = NULL ) const {
                                           ZcGePoint3d pline[2];
                                           ZSoft::Boolean retval = ZSoft::kFalse;
                                           for (ZSoft::UInt32 i = 0; i < nbPoints; i++) {
                                               pline[1] = pline[0] = pVertexList[i];
                                               retval = polyline(2, pline, pNormal ? &pNormal[i] : NULL, pSubEntMarkers ? pSubEntMarkers[i] : -1);
                                               if (retval)
                                                   return retval;
                                           }
                                           return retval;
                                    };
	virtual ZSoft::Boolean ownerDraw(ZcGiGdiDrawObject*        pObject,
                                    const ZcGePoint3d&         position,
                                    const ZcGeVector3d&        u,
                                    const ZcGeVector3d&        v) const { return ZSoft::kTrue; };

    virtual ZSoft::Boolean  edge(const ZcArray<ZcGeCurve2d*>& edges) const = 0;
};

class ZCDBCORE2D_PORT ZcGiWorldGeometry: public ZcGiGeometry 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcGiWorldGeometry);

    virtual void setExtents(ZcGePoint3d *pNewExtents) const = 0;

    virtual void startAttributesSegment() {};
};

class ZcDbRasterImage;
class ZCDBCORE2D_PORT ZcGiViewportGeometry: public ZcGiGeometry
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcGiViewportGeometry);

    virtual ZSoft::Boolean  polylineEye(const ZSoft::UInt32 nbPoints,
                                const ZcGePoint3d* pPoints) const = 0;
    virtual ZSoft::Boolean  polygonEye(const ZSoft::UInt32 nbPoints,
                                const ZcGePoint3d* pPoints) const = 0;

    virtual ZSoft::Boolean  polylineDc(const ZSoft::UInt32 nbPoints,
                                const ZcGePoint3d* pPoints) const = 0;
    virtual ZSoft::Boolean  polygonDc(const ZSoft::UInt32 nbPoints,
                                const ZcGePoint3d* pPoints) const = 0;

    enum ImageSource {
        kFromDwg,
        kFromOleObject,
        kFromRender
    };

    virtual ZSoft::Boolean  rasterImageDc(
                const ZcGePoint3d& origin,
                const ZcGeVector3d& u,
                const ZcGeVector3d& v,
                const ZcGeMatrix2d& pixelToDc,
                ZcDbObjectId entityId,
                ZcGiImageOrg imageOrg,
                ZSoft::UInt32 imageWidth,
                ZSoft::UInt32 imageHeight,
                ZSoft::Int16 imageColorDepth,
                ZSoft::Boolean transparency,
                ImageSource source,
                const ZcGeVector3d& unrotatedU,
                const ZcGiImageOrg origionalImageOrg,
                const ZcGeMatrix2d& unrotatedPixelToDc,
                const ZSoft::UInt32 unrotatedImageWidth,
                const ZSoft::UInt32 unrotatedImageHeight
                ) const = 0;

    virtual ZSoft::Boolean  ownerDrawDc(
                ZSoft::Int32                       vpnumber, 
                ZSoft::Int32                       left, 
                 ZSoft::Int32                        top, 
                 ZSoft::Int32                        right, 
                 ZSoft::Int32                        bottom, 
                const OwnerDraw*           pOwnerDraw
                ) const = 0;

    virtual ZSoft::Boolean  ownerDraw3d(
                ZcGePoint3d&               minBounds,
                ZcGePoint3d&               maxBounds,
                OwnerDraw3d*               pOwnerDraw
                ) const  { return ZSoft::kFalse; };

    virtual ZSoft::Boolean
        rasterImageDcUsingRawPointer(const ZcGePoint3d & origin,
            const ZcGeVector3d & u,
            const ZcGeVector3d & v,
            const ZcGeMatrix2d & pixelToDc,
            ZcDbRasterImage* pRasterImage,
            ZcGiImageOrg imageOrg,
            ZSoft::UInt32 imageWidth,
            ZSoft::UInt32 imageHeight,
            ZSoft::Int16 imageColorDepth,
            ZSoft::Boolean transparency,
            ImageSource source,
            const ZcGeVector3d& unrotatedU,
            const ZcGiImageOrg origionalImageOrg,
            const ZcGeMatrix2d& unrotatedPixelToDc,
            const ZSoft::UInt32 unrotatedImageWidth,
            const ZSoft::UInt32 unrotatedImageHeight) const { return ZSoft::kFalse; };

};

#pragma warning (pop)

class ZCDBCORE2D_PORT ZcGiEdgeData  : public ZcGiParameter
{ 
public:
	ZCRX_DECLARE_MEMBERS_READWRITE(ZcGiEdgeData, ZcGiImpEdgeData);

    ~ZcGiEdgeData();
    ZcGiEdgeData();

    virtual void            setColors(const short *colors);
    virtual void            setTrueColors(const ZcCmEntityColor *colors);
    virtual void            setLayers(const ZcDbObjectId *layers);
    virtual void            setLineTypes(const ZcDbObjectId *linetypes);
    virtual void            setSelectionMarkers(const ZSoft::LongPtr* pSelectionMarkers);
    virtual void            setVisibility(const ZSoft::UInt8* pVisibility);

    virtual short*          colors() const;
    virtual ZcCmEntityColor* trueColors() const;
    virtual ZcDbObjectId*   layerIds() const;
    virtual ZcDbObjectId*   linetypeIds() const;
    virtual ZSoft::LongPtr* selectionMarkers() const;
    virtual ZSoft::UInt8*   visibility() const;
private:
	ZcGiImpEdgeData *mpZcGiImpEdgeData;
};

class ZCDBCORE2D_PORT ZcGiFaceData : public ZcGiParameter
{ 
public:
	ZCRX_DECLARE_MEMBERS_READWRITE(ZcGiFaceData, ZcGiImpFaceData);

    ~ZcGiFaceData();
    ZcGiFaceData();
    virtual void            setColors(const short *colors);
    virtual void            setTrueColors(const ZcCmEntityColor *colors);
    virtual void            setLayers(const ZcDbObjectId *layers);
    virtual void            setSelectionMarkers(const ZSoft::LongPtr* pSelectionMarkers);
    virtual void            setNormals(const ZcGeVector3d* pNormals);
    virtual void            setVisibility(const ZSoft::UInt8* vis);
    virtual void            setMaterials(const ZcDbObjectId * materials);
    virtual void            setMappers(const ZcGiMapper * mappers);
	virtual void            setTransparency(const ZcCmTransparency *transparency);

    virtual short*          colors() const;
    virtual ZcCmEntityColor* trueColors() const;
    virtual ZcDbObjectId*   layerIds() const;
    virtual ZSoft::LongPtr* selectionMarkers() const;
    virtual ZcGeVector3d*   normals() const;
    virtual ZSoft::UInt8*   visibility() const;
    virtual ZcDbObjectId*   materials() const;
    virtual ZcGiMapper*     mappers() const;
	virtual ZcCmTransparency* transparency() const;
private:
	ZcGiImpFaceData *mpZcGiImpFaceData;
};

class ZCDBCORE2D_PORT ZcGiVertexData : public ZcGiParameter
{
public:
    enum MapChannel
    {
        kAllChannels,
        kMapChannels
    };

	ZCRX_DECLARE_MEMBERS_READWRITE(ZcGiVertexData, ZcGiImpVertexData);
    ~ZcGiVertexData();
    ZcGiVertexData();
    
    virtual void setNormals(const ZcGeVector3d* pNormals);
    virtual ZcGeVector3d* normals() const;
    virtual void setOrientationFlag(const ZcGiOrientationType oflag); 
    virtual ZcGiOrientationType orientationFlag() const;
    virtual void setTrueColors(const ZcCmEntityColor *colors);
    virtual ZcCmEntityColor* trueColors() const;

    virtual void setMappingCoords (MapChannel mapChannel, const ZcGePoint3d* pCoords);  
    virtual ZcGePoint3d* mappingCoords (MapChannel mapChannel) const;
private: 
	ZcGiImpVertexData *mpZcGiImpVertexData;
};

class ZCDBCORE2D_PORT ZcGiTextStyle: public ZcGiParameter
{ 
public:
	ZCRX_DECLARE_MEMBERS_READWRITE(ZcGiTextStyle, ZcGiImpTextStyle);

    ~ZcGiTextStyle();
    ZcGiTextStyle(ZcDbDatabase* pDb = NULL);

    ZcGiTextStyle(
        const ZTCHAR*  fontName,
        const ZTCHAR*  bigFontName,
        const double textSize,
        const double xScale,
        const double obliqueAngle,
        const double trPercent,

        const ZSoft::Boolean isBackward,
        const ZSoft::Boolean isUpsideDown,
        const ZSoft::Boolean isVertical,

        const ZSoft::Boolean isOverlined,
        const ZSoft::Boolean isUnderlined,
		const ZSoft::Boolean isStrikethrough = false,
        const ZTCHAR*          styleName = NULL);

    virtual int loadStyleRec(ZcDbDatabase* pDb = NULL) const;
    virtual void setTextSize(const double size);
    virtual void setXScale(const double xScale);
    virtual void setObliquingAngle(const double obliquingAngle);

    virtual void setTrackingPercent(const double trPercent);

    virtual void setBackward(const ZSoft::Boolean isBackward);
    virtual void setUpsideDown(const ZSoft::Boolean isUpsideDown);
    virtual void setVertical(const ZSoft::Boolean isVertical);

    virtual void setUnderlined(const ZSoft::Boolean isUnderlined);
    virtual void setOverlined(const ZSoft::Boolean isOverlined);
	virtual void setStrikethrough(const ZSoft::Boolean isStrikethrough);

    virtual void setFileName(const ZTCHAR * fontName);
    virtual void setBigFontFileName(const ZTCHAR * bigFontFileName);

    virtual double textSize() const;
    virtual double xScale() const;
    virtual double obliquingAngle() const;

    virtual double trackingPercent() const;

    virtual ZSoft::Boolean isBackward() const;
    virtual ZSoft::Boolean isUpsideDown() const;
    virtual ZSoft::Boolean isVertical() const;

    virtual ZSoft::Boolean isUnderlined() const;
    virtual ZSoft::Boolean isOverlined() const;
	virtual ZSoft::Boolean isStrikethrough() const;

    virtual const ZTCHAR * fileName() const;
    virtual const ZTCHAR * bigFontFileName() const;

    virtual ZcGePoint2d extents(const ZTCHAR * pStr,
                const ZSoft::Boolean penups,
                const int len,
                const ZSoft::Boolean raw,
                ZcGiWorldDraw *ctxt = NULL) const;

    virtual const ZTCHAR * styleName() const;
    virtual Zcad::ErrorStatus setStyleName(const ZTCHAR *);

     virtual Zcad::ErrorStatus setFont(const ZTCHAR * pTypeface,
                                      ZSoft::Boolean bold,
                                      ZSoft::Boolean italic,
	                                  Charset charset,
                                      ZwSoft::ZwCAD::PAL::FontUtils::FontPitch pitch,
                                      ZwSoft::ZwCAD::PAL::FontUtils::FontFamily family);

      virtual Zcad::ErrorStatus font(ZcString & sTypeface,
                                   bool & bold, bool & italic, Charset& charset,
                                   ZwSoft::ZwCAD::PAL::FontUtils::FontPitch& pitch,
                                   ZwSoft::ZwCAD::PAL::FontUtils::FontFamily& family) const;
    virtual Zcad::ErrorStatus font(ZTCHAR *& pTypeface,
                                   bool& bold, bool& italic, Charset& charset,
                                   ZwSoft::ZwCAD::PAL::FontUtils::FontPitch& pitch,
                                   ZwSoft::ZwCAD::PAL::FontUtils::FontFamily& family) const final;

    virtual Zcad::ErrorStatus  extentsBox(  const ZTCHAR * pStr,
                                            const ZSoft::Boolean penups,
                                            const int len,
                                            const ZSoft::Boolean raw,
                                            ZcGePoint2d &extMin,
                                            ZcGePoint2d &extMax,
                                            ZcGiWorldDraw *ctxt = NULL) const;

    virtual void setTrackKerning(double trackPercent) const;

    virtual bool preLoaded() const;
    virtual void setPreLoaded(bool);
private:
	friend class ZcGiImpTextStyle;
	ZcGiImpTextStyle *mpZcGiImpTextStyle;
};

inline Zcad::ErrorStatus ZcGiTextStyle::font(ZTCHAR *& pTypeface,
    bool & bold, bool & italic, Charset& charset,
    ZwSoft::ZwCAD::PAL::FontUtils::FontPitch& pitch,
    ZwSoft::ZwCAD::PAL::FontUtils::FontFamily& family) const
{
    ZcString sTypeface;
    const Zcad::ErrorStatus es = this->font(sTypeface, bold, italic, charset, pitch, family);
    ::zcutNewString(sTypeface.constPtr(), pTypeface);
    return es;
}

class ZCDBCORE2D_PORT ZcGiFill : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiFill);

    ZcGiFill();
    ZcGiFill(const ZcGiFill&);
    virtual ~ZcGiFill();

    double deviation() const;
    void   setDeviation(double dev);

private:
    ZcGiImpFill *mpImp = nullptr;
};

class ZCDBCORE2D_PORT ZcGiHatchPatternDefinition
{
public:
    ZcGiHatchPatternDefinition();
    ZcGiHatchPatternDefinition(const ZcGiHatchPatternDefinition &def);
    ZcGiHatchPatternDefinition(double angle,
                         double baseX,
                         double baseY,
                         double offsetX,
                         double offsetY,
                         const ZcGeDoubleArray& dashList);
    ~ZcGiHatchPatternDefinition();

    double angle() const;
    double baseX() const;
    double baseY() const;
    double offsetX() const;
    double offsetY() const;
    const ZcGeDoubleArray& dashList() const;

    ZcGiHatchPatternDefinition & operator = (const ZcGiHatchPatternDefinition &def);

private:
    friend class ZcGiImpHatchPatternDefinition;
    ZcGiImpHatchPatternDefinition *  mpImp = nullptr;
};

class ZCDBCORE2D_PORT ZcGiHatchPattern : public ZcGiFill
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiHatchPattern);
    ZcGiHatchPattern(const ZcArray<ZcGiHatchPatternDefinition>& );
    ZcGiHatchPattern(const ZcGiHatchPattern&);
    virtual ~ZcGiHatchPattern();

    const ZcArray<ZcGiHatchPatternDefinition>& patternLines () const;

private:
    ZcGiImpHatchPattern *mpImp = nullptr;
};

class ZCDBCORE2D_PORT ZcGiGradientFill : public ZcGiFill
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

    ZCRX_DECLARE_MEMBERS(ZcGiGradientFill);

    ZcGiGradientFill(double                              gradientAngle,
                     double                              gradientShift,
                     bool                                bAdjustAspect,
                     ZcArray<ZcCmColor>&                 gradientColors,
                     ZcGiGradientFill::GradientType type);

    ZcGiGradientFill(const ZcGiGradientFill&);
    virtual ~ZcGiGradientFill();

    void setGradientAngle(double val);
    double gradientAngle() const;

    void setGradientShift(double val);
    double gradientShift() const;

    void setIsAdjustAspect(bool val);
    bool isAdjustAspect() const;

    void setGradientColors(const ZcArray<ZcCmColor>& val);
    const ZcArray<ZcCmColor>& gradientColors() const;

    void setGradientType(ZcGiGradientFill::GradientType type);
    const ZcGiGradientFill::GradientType gradientType() const;

private:
    ZcGiImpGradientFill *mpImp = nullptr;
};

class ZcDbEntityParallelDrawPE : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcDbEntityParallelDrawPE, ZCDBCORE2D_PORT);

    virtual ZSoft::Boolean prepareForParallelDraw(ZcDbEntity* pEnt, ZcDbDwgFiler* pFiler) const = 0;
};

class ZcGiContextParallelDrawPE : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcGiContextParallelDrawPE, ZCDBCORE2D_PORT);

    virtual ZcDbDwgFiler* entityDataFiler(ZcGiContext* pCtx) const = 0;
};

#pragma pack (pop)

#endif
