/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef OFFSET_H
#include "Offset.h"
#endif
#ifndef SIZE_H
#include "Size.h"
#endif
#ifndef IMAGEFILTER_H
#include "ImageFilter.h"
#endif
#ifndef DATABUFFER_H
#include "DataBuffer.h"
#endif
#ifndef IMAGE_H
#include "Image.h"
#endif
#ifndef POINT2D_H
#include "Point2d.h"
#endif
#ifndef VECTOR2D_H
#include "Vector2d.h"
#endif
#ifndef MATRIX2D_H
#include "Matrix2d.h"
#endif
#ifndef BOUNDINGBOX_H
#include "BoundingBox.h"
#endif

#ifndef TRANSFORMS_H
#define TRANSFORMS_H

#ifndef PIXELCOPIER_H
namespace Gtil { class PixelCopier; }
#endif
namespace Gtil
{
  GTIL_EXPORT RowProviderInterface* newScaleFilter(RowProviderInterface* pInput, const Size& output);
  GTIL_EXPORT RowProviderInterface* newScaleFilter(const Image* pImage, const Size& szOutput);
  GTIL_EXPORT RowProviderInterface* newScaleFilter(const Image* pImage,
                                                   const Size& size,
                                                   const Offset& offset,
                                                   const Size& szOutput);

  struct Resample
  {
    enum FilterTypes
    {
      kNearest,
      kTriangle,
      kCubic,
      kBell,
      kBSpline,
      kLanczos3,
      kMitchell,
      kBellBinary
    };
  };
  GTIL_EXPORT RowProviderInterface* newResampleFilter(const Image* pImage,
                                                      const Size& size,
                                                      const Offset& offset,
                                                      Resample::FilterTypes filterMethod,
                                                      bool bAdaptive,
                                                      bool bProcessAlpha,
                                                      const Size& szOutput);
  GTIL_EXPORT RowProviderInterface* newResampleFilter(RowProviderInterface* pInput,
                                                      const Size& output,
                                                      Resample::FilterTypes filterMethod,
                                                      bool bAdaptive = false,
                                                      bool bProcessAlpha = false,
                                                      bool bReturnRaw = false,
                                                      ImagePixel const* pVoidPixel = NULL);

  struct Shear
  {
    enum Quality
    {
      kInterpolate,
      kRound
    };
  };

  GTIL_EXPORT RowProviderInterface* newXShearFilter(RowProviderInterface* pInput,
                                                    const double& dXShear,
                                                    ImagePixel clearColor,
                                                    Shear::Quality quality,
                                                    bool bProcessAlpha = false,
                                                    bool bReturnRaw = false);
  GTIL_EXPORT RowProviderInterface* newYShearFilter(RowProviderInterface* pInput,
                                                    const double& dYShear,
                                                    ImagePixel clearColor,
                                                    Shear::Quality quality,
                                                    bool bProcessAlpha = false,
                                                    bool bReturnRaw = false);
  GTIL_EXPORT RowProviderInterface* newRotateFilter(RowProviderInterface* pInput,
                                                    const double& dAngle,
                                                    ImagePixel clearColor,
                                                    Shear::Quality method,
                                                    bool bProcessAlpha = false,
                                                    bool bReturnRaw = false);

  class GTIL_EXPORT ImageView
  {
  public:
    enum RotationMethod
    {
      kInterpolated,
      kNearestNeighbor
    };

  public:
    ImageView(const Image& image, const Size& output);
    ImageView(const Size& input, ImagePixel clearColor, const Size& output);
    ~ImageView();

    RowProviderInterface* getViewedImageData(Resample::FilterTypes filter = Resample::kNearest,
                                             bool bAdaptive = false,
                                             RotationMethod rotate = kInterpolated);
    RowProviderInterface* getViewedImageData(RowProviderInterface* pInput,
                                             Resample::FilterTypes filter = Resample::kNearest,
                                             bool bAdaptive = false,
                                             RotationMethod rotate = kInterpolated);

    const Size& output() const;

    Point2d origin() const;

    double rotation() const;

    Vector2d xAxis() const;
    Vector2d yAxis() const;

    ImagePixel fillColor() const;

    bool transparency() const;

    bool returnRawData() const;

    void setRotation(const double& dRgds);
    void setRotation(int n90DegreeIncrements);
    void rotateBy(const double& dRgds);
    void rotateBy(int n90DegreeIncrements);

    void setFillColor(ImagePixel color);
    void setTransparency(bool bTurnOn);
    void setReturnRawData(bool bReturnRaw);
    void setSize(const double& dXLength, const double& dYLength);

    void scaleBy(const double& dScale);
    void moveTo(const Point2d& origin);
    void moveBy(const double& dPanX, const double& dPanY);

    void setByVectors(const Point2d& origin, const Vector2d& xAxis, const Vector2d& yAxis);

    void setRegionOfInterest(const Size& size, const Offset& offset);

    bool imageInView(Size& size, Offset& offset);

    Point2d transform(Point2d imageOffset) const;

    Matrix2d getTransformation() const;

    bool getInputandOrientation(Offset& origin, Size& size, Gtil::Orientation& orientation) const;

    RowProviderInterface* getViewedImageData(ImagePixel voidPixel,
                                             Resample::FilterTypes filter = Resample::kNearest,
                                             bool bAdaptive = false,
                                             RotationMethod rotate = kInterpolated);
    RowProviderInterface* getViewedImageData(RowProviderInterface* pInput,
                                             ImagePixel voidPixel,
                                             Resample::FilterTypes filter = Resample::kNearest,
                                             bool bAdaptive = false,
                                             RotationMethod rotate = kInterpolated);

  private:
    RowProviderInterface* getViewedImageDataImp(const ImagePixel*, Resample::FilterTypes, bool, RotationMethod);
    RowProviderInterface* getViewedImageDataImp(RowProviderInterface*,
                                                const ImagePixel*,
                                                Resample::FilterTypes,
                                                bool, RotationMethod);

    BoundingBox mbbRegion;
    const Image* mpImage;
    ImagePixel mFillColor;
    Point2d mOrigin;
    Vector2d mvXAxis;
    Vector2d mvYAxis;

    Size mImageSize;
    Size mOutput;
    bool mbFillColorSet;
    bool mbTransparencyOn;
    bool mbReturnRawData;
  };

  GTIL_EXPORT RowProviderInterface* applyAffine(const Image* pSrcImage,
                                                const Size& szOutput,
                                                const Point2d& srcOrigin,
                                                const Vector2d& srcUAxis,
                                                const Vector2d& srcVAxis,
                                                bool bReturnRawData);

  GTIL_EXPORT bool bufferedImageBottomUpPaste(Image* pImage,
                                              RowProviderInterface* pPipe,
                                              const Offset& at,
                                              bool bTransparently = false);
}

#endif
