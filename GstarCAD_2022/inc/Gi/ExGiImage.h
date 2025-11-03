#ifndef __EXGIIMAGE_H__
#define __EXGIIMAGE_H__

#include "../RxModule.h"
#include "../RxObject.h"

#include "../TD_PackPush.h"

// 真正的图像类
class OdGePoint2d;
class OdGeVector2d;
namespace GStar { class Image; }


/* OdExGiImage
  OdExGiImage 作用连接 OdGiRasterImage 和 GStar::Image
  上层访问 OdGiRasterImage，下层访问 GStar::Image
  因此本抽象接口类尽量简单
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdExGiImage : public OdRxObject
{
public:
  // 关键函数，用于绘制输出（目前主要是显示用，打印走内部流程）
  virtual void draw
  ( 
    void* hdc,
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
    bool bImageQualityHigh
  ) = 0;

  // 转换为标准化图像，返回新对象，外部使用者需要负责销毁
  virtual GStar::Image* convertToStandardImage
  (
    const OdGePoint2d &origin,
    const OdGeVector2d &u,          //仿射变换矩阵（始终用原点）
    const OdGeVector2d &v,          //仿射变换矩阵（始终用原点）
    const OdGePoint2d* ClipPts,
    const OdUInt32 ClipPtNum,
    const OdGePoint2d* RegionPts,
    const OdUInt32 RegionPtNum,
    BITMAPINFO ** const ppBMI,
    void ** const ppBitsOut,
    OdGeVector2d &orgOffset,
    void *const stParam,
    bool isbMonochrome      //是否单色打印
  ) = 0;

  // 关联的 GStar::Image
  virtual GStar::Image* getGImage() const = 0;

  // 重新关联，起到置换作用 (特殊用法，非必要不可调用)
  virtual GStar::Image* bindGImage(GStar::Image* newImage)  = 0;

  // 重新加载 (特殊用法，非必要不可调用)
  virtual bool reload(bool allowDecrease = true) = 0;

  // 覆盖参数类型
  enum
  {
    eDrawing = 0,  // int*
    ePlotting,     // int*
    eForeColor,    // COLORREF*
    eBackColor,    // COLORREF*
    eTransparency, // int*
    eFileType      // OdChar*
  };

  // 覆盖参数设置（通常上层设置参数通过OdGiRasterImage获取，下层细节参数通过GStar::Image获取，某些情况需要覆盖替代）
  virtual void  setOverrideStatus(OdUInt32 n, void* param) = 0;
  virtual void* getOverrideStatus(OdUInt32 n) const = 0;
};

#include "../TD_PackPop.h"

#endif // __EXGIIMAGE_H__
