/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef STRINGBUFFER_H
#include "StringBuffer.h"
#endif
#ifndef DATAMODELATTRIBUTES_H
#include "DataModelAttributes.h"
#endif
#ifndef FORMATCODECPROPERTYINTERFACE_H
#include "FormatCodecPropertyInterface.h"
#endif
#ifndef FORMATCODECPROPERTYSETITERATOR_H
namespace Gtil { class GTIL_EXPORT FormatCodecPropertySetIterator; }
#endif
#ifndef ROWITERATORINTERFACE_H
namespace Gtil { class RowIteratorInterface; }
#endif

#ifndef READIMAGEFILEFRAMEINTERFACE_H
#define READIMAGEFILEFRAMEINTERFACE_H

namespace Gtil
{
  class GTIL_EXPORT ReadImageFileFrameInterface
  {
  public:
    enum AccessMethod
    {
      kRow,
      kDirectTile,
      kSubRegion,
      kSubSampled
    };
  public:
    virtual ~ReadImageFileFrameInterface();

    virtual bool isSupportedAccessMethod(AccessMethod method) const = 0;

    virtual int index() const = 0;

    virtual void dimensions(int& nRows, int& nColumns) const = 0;
    virtual void dimensions(int& nRows, int& nColumns, int& nDepths) const
    {
      dimensions(nRows, nColumns);
      nDepths = 1;
    }

    virtual DataModelAttributes::DataModelType dataModel() const = 0;

    virtual DataModelAttributes::BitsPerPixel bitsPerPixel() const = 0;

    virtual int bitsUsedPerPixel() const = 0;

    virtual DataModelAttributes::DataType dataType() const = 0;

    virtual DataModelAttributes::BitFields bitFields() const = 0;

    virtual Gtil::Orientation dataOrientation() = 0;

    virtual int numPaletteEntries() = 0;

    virtual void getPaletteEntries(int nPaletteEntries, UInt8* palette) = 0;

    virtual RowIteratorInterface* getRowIterator() = 0;

    virtual bool canProvideTileSize(int nSizes, int* paSquareTileSizes) const = 0;

    virtual FormatCodecPropertySetIterator* newPropertySetIterator() = 0;

    virtual FormatCodecPropertyInterface* getProperty(FormatCodecPropertyInterface::PropertyIdentifier id) = 0;
    virtual FormatCodecPropertyInterface* getProperty(const StringBuffer& sbPropertyName) = 0;
  };
}

#endif
