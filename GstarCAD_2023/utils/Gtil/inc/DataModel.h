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
#ifndef IMAGEPIXEL_H
#include "ImagePixel.h"
#endif
#ifndef DATAMODEL_H
#define DATAMODEL_H

namespace Gtil
{
  class GTIL_EXPORT DataModel : public DataModelAttributes
  {
  public:
    enum TileSize
    {
      k64x64,
      k128x128,
      k256x256,
      k512x512,
      k1024x1024,
      kUnspecified,
      kDefault
    };

    static int bytesPerRow(Int32 nPixels, DataModelAttributes::BitsPerPixel bpp);
    static int bitsPerPixel(DataModelAttributes::BitsPerPixel bpp);
    static void tileSize(TileSize size, int& nRows, int& nColumns);

  public:
    DataModel(DataModelAttributes::DataType format, DataModelAttributes::BitsPerPixel bpp, int dataBits);
    virtual ~DataModel();

    virtual DataModel* clone() const;

    virtual DataModel::TileSize defaultTileSize() const;

    virtual bool isCompatibleTileSize(DataModel::TileSize size) const;
    virtual bool isCompatibleDataSize(DataModelAttributes::BitsPerPixel dataSize) const;

    virtual DataModelAttributes::BitsPerPixel bitsPerPixel() const;

    virtual int bitsUsedPerPixel() const;

    virtual DataModelAttributes::DataModelType dataModelType() const;
    virtual DataModelAttributes::PixelType     pixelType() const;
    virtual DataModelAttributes::DataType      dataType() const;
    virtual DataModelAttributes::BitFields     bitFields() const;
    virtual DataModelAttributes::ChannelOrder  channelOrder() const;

    virtual bool operator==(const DataModel& dm) const;
    virtual bool operator!=(const DataModel& dm) const;

  protected:
    DataModel(DataModelAttributes::DataModelType dmt,
              DataModelAttributes::DataType format,
              DataModelAttributes::BitsPerPixel bpp);
    DataModel(DataModelAttributes::DataModelType dmt,
              DataModelAttributes::DataType format,
              DataModelAttributes::BitsPerPixel bpp,
              int dataBits);

    DataModel& operator=(const DataModel& rhs);

    DataModel();

    DataModelAttributes::DataModelType mDMType;
    DataModelAttributes::BitsPerPixel  mPackedBits;
    DataModelAttributes::DataType      mDataType;

    int mnBitsPerPixel;
    int mnDataBits;

    TileSize mDefaultTileSize;
  };
}
#endif
