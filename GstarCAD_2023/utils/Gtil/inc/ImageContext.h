/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif

#ifndef GTILEXCEPTION_H
#include "ATILException.h"
#endif
#ifndef DATAMODELATTRIBUTES_H
#include "DataModelAttributes.h"
#endif

#ifndef SIZE_H
namespace Gtil { class Size; }
#endif
#ifndef OFFSET_H
namespace Gtil { class Offset; }
#endif
#ifndef IMAGEPIXEL_H
namespace Gtil { struct ImagePixel; }
#endif
#ifndef PIXELSELECTORINTERFACE_H
namespace Gtil { class PixelSelectorInterface; }
#endif
#ifndef IMAGECONTEXTREP_H
#include "ImageContextRep.h"
#endif
#ifndef INTERNAL_H
namespace Gtil { class Internal; }
#endif
#ifndef IMAGE_H
namespace Gtil { class Image; }
#endif

#ifndef IMAGECONTEXT_H
#define IMAGECONTEXT_H

namespace Gtil
{
  class GTIL_EXPORT ImageContext
  {
  public:
    enum Access
    {
      kRead,
      kWrite
    };

    enum Behavior
    {
      kDefaultColor,
      kException,
      kAutoExpand
    };

  public:
    ~ImageContext();

    DataModelAttributes::PixelType getPixelType() const;

    void setOutOfBoundsBehavior(Behavior likeThis);
    void setOutOfBoundsColor(ImagePixel color);

    ImagePixel getPixel(Int32 x, Int32 y);
    void putPixel(Int32 x, Int32 y, ImagePixel value);

    void getRow(Int32 y, Int32 x, int nCount, void* pBuffer);
    void putRow(Int32 y, Int32 x, int nCount, void* pBuffer);
    void setRow(Int32 y, Int32 x, int nCount, ImagePixel value);

    int     get1(Int32 x, Int32 y);
    UInt8   get8(Int32 x, Int32 y);
    UInt16  get16(Int32 x, Int32 y);
    UInt32  get32(Int32 x, Int32 y);
    UInt64  get64(Int32 x, Int32 y);
    Data128 get128(Int32 x, Int32 y);

    void put1(Int32 x, Int32 y, int value);
    void put8(Int32 x, Int32 y, UInt8 value);
    void put16(Int32 x, Int32 y, UInt16 value);
    void put32(Int32 x, Int32 y, UInt32 value);
    void put64(Int32 x, Int32 y, UInt64 value);
    void put128(Int32 x, Int32 y, Data128 value);

    void flush();

    bool getTile(int row, int col, UInt8*& pTileData);
    void releaseTile();
    bool putTile();

    bool tileHasData(int Row, int Col);

    CellRequestor* constructCellRequestor(int cellSize);

  private:
    friend class Image;
    friend class Internal;
    ImageContext(ImageContextRep* mpImplementation);
    ImageContextRep* mpImplementation;
  };

  class GTIL_EXPORT ImageContextException : public GTILException
  {
  public:
    enum ExceptionType
    {
      kTileAlreadyAllocated,
      kNotOpenForWrite,
      kOutOfBounds,
      kInvalidObject,
      kUnSpecified
    };

  public:
    ImageContextException(const StringBuffer& sbMessage, ExceptionType type = ImageContextException::kUnSpecified);
    ImageContextException(const ImageContextException& x);
    virtual ~ImageContextException();

    virtual ExceptionType getExceptionType();

  private:
    ExceptionType eType;
  };
}

#endif
