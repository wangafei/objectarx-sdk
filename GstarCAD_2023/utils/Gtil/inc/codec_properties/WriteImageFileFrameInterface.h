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
#ifndef FORMATCODECPROPERTYINTERFACE_H
#include "FormatCodecPropertyInterface.h"
#endif

#ifndef ROWITERATORINTERFACE_H
namespace Gtil { class RowIteratorInterface; }
#endif
#ifndef FORMATCODECPROPERTYSETITERATOR_H
namespace Gtil { class GTIL_EXPORT FormatCodecPropertySetIterator; }
#endif

#ifndef WRITEIMAGEFILEFRAMEINTERFACE_H
#define WRITEIMAGEFILEFRAMEINTERFACE_H

namespace Gtil
{
  class GTIL_EXPORT WriteImageFileFrameInterface
  {
  public:
    virtual ~WriteImageFileFrameInterface();

    virtual void setDimensions(int nRows, int nColumns) = 0;
    virtual void setDataModel(DataModelAttributes::DataModelType dataModelType) = 0;
    virtual void setBitsPerPixel(int bitsPerPixel) = 0;
    virtual void setBitsUsedPerPixel(int bitsUsedPerPixel) = 0;
    virtual void setNumPaletteEntries(int nPaletteEntries) = 0;
    virtual void setPaletteEntries(UInt8* palette) = 0;

    virtual FormatCodecPropertySetIterator* newPropertySetIterator() = 0;
    virtual FormatCodecPropertyInterface* getProperty(FormatCodecPropertyInterface::PropertyIdentifier id) = 0;
    virtual FormatCodecPropertyInterface* getProperty(const StringBuffer& sbPropertyName) = 0;
    virtual bool setProperty(const FormatCodecPropertyInterface* pThisProp) = 0;
    virtual void resetProperties() = 0;
    virtual bool requiredPropertiesSet() const = 0;
  };
}

#endif
