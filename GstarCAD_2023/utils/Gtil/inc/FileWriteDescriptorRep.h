/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef FORMATCODECPROPERTYINTERFACE_H
#include "FormatCodecPropertyInterface.h"
#endif
#ifndef DATASTREAMINTERFACE_H
namespace Gtil { class DataStreamInterface; }
#endif
#ifndef IMAGEFORMATCODEC_H
namespace Gtil { class ImageFormatCodec; }
#endif
#ifndef FORMATCODECPROPERTYSETITERATOR_H
namespace Gtil { class GTIL_EXPORT FormatCodecPropertySetIterator; }
#endif
#ifndef ROWPROVIDERINTERFACE_H
namespace Gtil { class RowProviderInterface; }
#endif
#ifndef FILESPECIFIER_H
namespace Gtil { class FileSpecifier; }
#endif
#ifndef FILEREADDESCRIPTOR_H
namespace Gtil { class FileReadDescriptor; }
#endif
#ifndef DATAMODEL_H
namespace Gtil { class DataModel; }
#endif
#ifndef SIZE_H
namespace Gtil { class Size; }
#endif

#ifndef FILEWRITEDESCRIPTORREP_H
#define FILEWRITEDESCRIPTORREP_H

namespace Gtil
{
  class GTIL_EXPORT FileWriteDescriptorRep
  {
  public:
    virtual ~FileWriteDescriptorRep();

    virtual void construct(const ImageFormatCodec* codec) = 0;

    virtual const ImageFormatCodec* formatCodec() const = 0;

    virtual void getFileSpecifier(FileSpecifier& fs) const = 0;
    virtual bool setFileSpecifier(const FileSpecifier& fs) = 0;

    virtual void setOutputStream(DataStreamInterface* pdsStream) = 0;

    virtual void createImageFrame(const DataModel& dataModel, Size size) = 0;

    virtual bool requiredPropertiesSet() const = 0;

    virtual FormatCodecPropertySetIterator* newPropertySetIterator() = 0;

    virtual FormatCodecPropertyInterface* getProperty(FormatCodecPropertyInterface::PropertyIdentifier id) const = 0;
    virtual FormatCodecPropertyInterface* getProperty(StringBuffer sbPropertyName) const = 0;

    virtual bool setProperty(const FormatCodecPropertyInterface* pProperty) = 0;
    virtual bool setProperties(const FileReadDescriptor* fd) = 0;

    virtual int writeImageFrame(RowProviderInterface* rowProvider) = 0;

    virtual void closeFile() = 0;
  };
}

#endif
