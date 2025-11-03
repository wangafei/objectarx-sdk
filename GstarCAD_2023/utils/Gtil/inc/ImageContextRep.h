/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef DATAMODELATTRIBUTES_H
#include "DataModelAttributes.h"
#endif

#ifndef OFFSET_H
namespace Gtil { class Offset; }
#endif
#ifndef SIZE_H
namespace Gtil { class Size; }
#endif
#ifndef IMAGEPIXEL_H
namespace Gtil { struct ImagePixel; }
#endif
#ifndef PIXELSELECTORINTERFACE_H
namespace Gtil { class PixelSelectorInterface; }
#endif
#ifndef IMAGE_H
namespace Gtil { class Image; }
#endif

#ifndef IMAGECONTEXTREP_H
#define IMAGECONTEXTREP_H

namespace Gtil
{
  class GTIL_EXPORT CellRequestor
  {
  public:
    virtual ~CellRequestor();

    virtual bool getCellAt(const Offset& at, void* pValues) = 0;

    virtual Size cellSize() const = 0;

    virtual int cellBytes() const = 0;
  };

  class GTIL_EXPORT ImageContextRep
  {
  public:
    virtual ~ImageContextRep();

    virtual DataModelAttributes::PixelType getPixelType() const = 0;

    virtual void setOutOfBoundsBehavior(int likeThis) = 0;
    virtual void setOutOfBoundsColor(ImagePixel color) = 0;

    virtual int     get1(Int32 x, Int32 y) = 0;
    virtual UInt8   get8(Int32 x, Int32 y) = 0;
    virtual UInt16  get16(Int32 x, Int32 y) = 0;
    virtual UInt32  get32(Int32 x, Int32 y) = 0;
    virtual UInt64  get64(Int32 x, Int32 y) = 0;
    virtual Data128 get128(Int32 x, Int32 y) = 0;

    virtual void put1(Int32 x, Int32 y, int value) = 0;
    virtual void put8(Int32 x, Int32 y, UInt8 value) = 0;
    virtual void put16(Int32 x, Int32 y, UInt16 value) = 0;
    virtual void put32(Int32 x, Int32 y, UInt32 value) = 0;
    virtual void put64(Int32 x, Int32 y, UInt64 value) = 0;
    virtual void put128(Int32 x, Int32 y, Data128 value) = 0;

    virtual void flush() = 0;

    virtual ImagePixel getPixel(Int32 x, Int32 y) = 0;
    virtual void putPixel(Int32 x, Int32 y, ImagePixel value) = 0;

    virtual void getRow(Int32 y, Int32 x, int nCount, void* pBuffer) = 0;
    virtual void putRow(Int32 y, Int32 x, int nCount, void* pBuffer) = 0;
    virtual void setRow(Int32 y, Int32 x, int nCount, ImagePixel value) = 0;

    virtual bool getTile(int row, int col, UInt8 *& pTileData) = 0;
    virtual void releaseTile() = 0;
    virtual bool putTile() = 0;

    virtual bool tileHasData(int Row, int Col) = 0;

    virtual CellRequestor* constructCellRequestor(int cellSize) = 0;
  };
}

#endif
