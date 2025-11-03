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
#ifndef SIZE_H
namespace Gtil { class Size; }
#endif
#ifndef FILESPECIFIER_H
namespace Gtil { class FileSpecifier; }
#endif
#ifndef DATAMODEL_H
namespace Gtil { class DataModel; }
#endif
#ifndef ROWPROVIDERINTERFACE_H
namespace Gtil { class RowProviderInterface; }
#endif
#ifndef IMAGEFORMATCODEC_H
namespace Gtil { class ImageFormatCodec; }
#endif
#ifndef FORMATCODECPROPERTYSETITERATOR_H
namespace Gtil { class GTIL_EXPORT FormatCodecPropertySetIterator; }
#endif
#ifndef FILEREADDESCRIPTOR_H
namespace Gtil { class FileReadDescriptor; }
#endif
#ifndef INTERNAL_H
namespace Gtil { class Internal; }
#endif
#ifndef FILEWRITEDESCRIPTORREP_H
namespace Gtil { class FileWriteDescriptorRep; }
#endif

#ifndef FILEWRITEDESCRIPTOR_H
#define FILEWRITEDESCRIPTOR_H

namespace Gtil
{
  class GTIL_EXPORT FileWriteDescriptor
  {
  public:
    static bool isCompatibleFormatCodec(const ImageFormatCodec* codec,
                                        const DataModel* dataModel,
                                        Size size);
    static void getCompatibleFormatCodecs(const DataModel* cpDataModel,
                                          const Size& size,
                                          const ImageFormatCodec**& codecs,
                                          int& numCodecs);

  public:
    friend class Internal;

    FileWriteDescriptor(const ImageFormatCodec* pCodec);
    virtual ~FileWriteDescriptor();

    const ImageFormatCodec* formatCodec() const;

    void getFileSpecifier(FileSpecifier& fs) const;
    bool setFileSpecifier(const FileSpecifier& fs);

    void setOutputStream(DataStreamInterface* pdsStream);

    void createImageFrame(const DataModel& dataModel, Size size);

    bool requiredPropertiesSet() const;

    FormatCodecPropertySetIterator* newPropertySetIterator();

    FormatCodecPropertyInterface* getProperty(FormatCodecPropertyInterface::PropertyIdentifier id) const;
    FormatCodecPropertyInterface* getProperty(StringBuffer sbPropertyName) const;

    bool setProperty(const FormatCodecPropertyInterface* pProperty);
    bool setProperties(const FileReadDescriptor* fd);

    int writeImageFrame(RowProviderInterface* pPipe);

    virtual void closeFile();

  private:
    FileWriteDescriptorRep* mpImplementation;
  };
}

#endif
