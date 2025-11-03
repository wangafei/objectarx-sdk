/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif

#ifndef IMAGECONTEXT_H
#include "ImageContext.h"
#endif

#ifndef DATAMODEL_H
#include "DataModel.h"
#endif

#ifndef GTILEXCEPTION_H
#include "ATILException.h"
#endif

#ifndef SIZE_H
namespace Gtil { class Size; }
#endif
#ifndef OFFSET_H
namespace Gtil { class Offset; }
#endif
#ifndef STRINGBUFFER_H
namespace Gtil { class StringBuffer; }
#endif
#ifndef IMAGEPIXEL_H
namespace Gtil { struct ImagePixel; }
#endif
#ifndef ROWPROVIDERINTERFACE_H
namespace Gtil { class RowProviderInterface; }
#endif
#ifndef FILEREADDESCRIPTOR_H
namespace Gtil { class FileReadDescriptor; }
#endif
#ifndef FILEWRITEDESCRIPTOR_H
namespace Gtil { class FileWriteDescriptor; }
#endif
#ifndef IMAGEREP_H
namespace Gtil { class ImageRep; }
#endif
#ifndef INTERNAL_H
namespace Gtil { class Internal; }
#endif

#ifndef IMAGE_H
#define IMAGE_H

namespace Gtil
{
  class ImageReactorInterface;

  class GTIL_EXPORT Image
  {
  public:
    friend class Internal;

    Image();
    Image(const Image & image);
    Image(const Size& size, const DataModel* colorspace, ImagePixel initialColor, DataModel::TileSize sz = DataModel::kUnspecified);
    Image(void* pData, int nBytesInBuffer, int nBytesPerRow, const Size& size, const DataModel* pDm);
    Image(RowProviderInterface* pPipe, DataModel::TileSize sz = DataModel::kUnspecified);
    Image(RowProviderInterface* pPipe, Gtil::Orientation orient, DataModel::TileSize sz = DataModel::kUnspecified);
    Image(FileReadDescriptor& readDesc, DataModel::TileSize sz = DataModel::kUnspecified);
    ~Image();

    const Image& operator= (const Image& image);
    const Image& operator= (RowProviderInterface* pPipe);

    bool operator== (const Image& image) const;
    bool operator!= (const Image& image) const;

    const Size& size() const;
    Size tileSize() const;

    const DataModel& dataModel() const;

    const FileReadDescriptor* fileReadDescriptor() const;

    int numTiles(int& nRows, int& nColumns) const;

    const ImagePixel& clearColor() const;

    void setDataModel(const DataModel& dataModel);

    void setClearColor(ImagePixel value);

    void paste(RowProviderInterface* pPipe, const Offset& at, bool bRespectTransparency = false);
    void blend(RowProviderInterface* pPipe, const Offset& at, int nAlphaValue, bool bRespectTransparency = false);

    RowProviderInterface* read(const Size& size, const Offset& offset) const;
    RowProviderInterface* read(const Size& size, const Offset& offset, Gtil::Orientation orient) const;

    ImageContext* createContext(ImageContext::Access accessNeeded, int numTilesToCache = 4);
    ImageContext* createContext(ImageContext::Access accessNeeded,
                                const Size& size,
                                const Offset& offset,
                                int numTilesToCache = 4);

    void addReactor(ImageReactorInterface* pReactor);
    void removeReactor(ImageReactorInterface* pReactor);

    bool disablePerTileLocking(bool bDisable);

    void clear();

    bool isValid() const;
    bool isModified() const;

    bool usesUserBuffer() const;
    void* getUserBuffer();

  private:
    ImageRep* mImplementation;
  };

  class GTIL_EXPORT ImageReactorInterface
  {
  public:
    virtual ~ImageReactorInterface();

    virtual void onModified(int row, int column);
  };

  class GTIL_EXPORT ImageConstructionException : public GTILException
  {
  public:
    enum ExceptionType
    {
      kIncompatibleTileSize,
      kInvalidClearColor,
      kInvalidSize,
      kNonClonal,
      kUnsafeClone,
      kInsufficentStorage,
      kInvalidRowAlignment,
      kInvalidData,
      kUnSpecified
    };

  public:
    ImageConstructionException(const StringBuffer& sbMessage, ExceptionType type = ImageConstructionException::kUnSpecified);
    ImageConstructionException(const ImageConstructionException& x);
    virtual ~ImageConstructionException();

    virtual ExceptionType getExceptionType();

  private:
    ExceptionType eType;
  };

  class GTIL_EXPORT ImageException : public GTILException
  {
  public:
    enum ExceptionType
    {
      kInvalidSubRegion,
      kIncompatibleDataModel,
      kUnableToRegisterReactor,
      kInvalidBlendTarget,
      kInvalidPixelType,
      kNullConstruction,
      kUnSpecified
    };
  public:
    ImageException(const StringBuffer& sbMessage, ExceptionType type = ImageException::kUnSpecified);
    ImageException(const ImageException& x);
    virtual ~ImageException();

    virtual ExceptionType getExceptionType();

  private:
    ExceptionType eType;
  };
}

#endif

#ifndef IMAGE_INL
#include "Image.inl"
#endif
