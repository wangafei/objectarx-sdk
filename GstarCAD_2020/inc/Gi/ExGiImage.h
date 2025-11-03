#ifndef __EXGIIMAGE_H__
#define __EXGIIMAGE_H__

#include "../RxModule.h"
#include "../RxObject.h"

#include "../TD_PackPush.h"

class CHcImage;

class ODRX_ABSTRACT FIRSTDLL_EXPORT OdExGiImage : public OdRxObject
{
public:
  virtual void draw( void* hdc,
    const POINT* pptLeftTop,
    const POINT* pptRightTop,
    const POINT* pptLeftBottom,
    double bright,
    double contrast,
    double fade,
    COLORREF foreColor,
    COLORREF bkColor,
    int  alphaBlend,
    bool transparent,
    int  clipPointsCount,
    const POINT* clipPoints,
    bool bImageQualityHigh = true) const = 0;

  virtual const BITMAPINFO* getBitmapInfo() const = 0;
  virtual bool hasAlphaBlend() const = 0;
  virtual const OdChar* fileType() const = 0;
  virtual BYTE* GetAlphaPointer(long x = 0L,long y = 0L) const = 0;
  virtual long GetTransIndex() const = 0;
  virtual bool AlphaPaletteIsEnabled() = 0;
  virtual bool CreateFromHBITMAP(HBITMAP hbmp, HPALETTE hpall = 0, bool bTransparency = false) = 0;
  virtual HBITMAP acquireRGBBitmap(int w, int h, bool alpha,COLORREF foreColor,COLORREF bkColor) = 0;

  virtual void benginPlotting() = 0;
  virtual void endPlotting() = 0;
  virtual bool isPlotting() const = 0;
  virtual bool isMagicConvert() const = 0;

  virtual CHcImage* getHcImage() const = 0;
  virtual bool reload(bool allowDecrease = true) = 0;
};

#include "../TD_PackPop.h"

#endif // __EXGIIMAGE_H__
