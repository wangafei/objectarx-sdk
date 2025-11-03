/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef FILEREADDESCRIPTOR_H
#include "FileReadDescriptor.h"
#endif
#ifndef DATASTREAMINTERFACE_H
#include "DataStreamInterface.h"
#endif
#ifndef TRANSFORMS_H
#include "Transforms.h"
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
#ifndef FINDFILEINTERFACE_H
namespace Gtil { class FindFileInterface; }
#endif

#ifndef FILEREADDESCRIPTORREP_H
#define FILEREADDESCRIPTORREP_H

namespace Gtil
{
  class GTIL_EXPORT FileReadDescriptorRep
  {
  public:
    virtual void construct(const FileSpecifier& fs, FindFileInterface* pFF) = 0;
    virtual void construct(const FileSpecifier& fs, const ImageFormatCodec* useThisCodec, FindFileInterface* pFF) = 0;
    virtual void construct(DataStreamInterface* pdsStream, const ImageFormatCodec* useThisCodec) = 0;
    virtual void construct(FileReadDescriptorRep* pCloneRep) = 0;

    virtual void open() const = 0;
    virtual void close() const = 0;

    virtual void getFileSpecifier(FileSpecifier& fs) const = 0;

    virtual void getDataSize(Size& size) const = 0;
    virtual void getDataSize(int& nRows, int& nColumns, int& nDepths) const = 0;

    virtual Gtil::Orientation dataOrientation() const = 0;
    virtual void getOrientedSize(Size& size) const = 0;

    virtual const DataModel& dataModel() const = 0;

    virtual const ImageFormatCodec * formatCodec() const = 0;

    virtual int numFrames() const = 0;

    virtual int selectedFrame() const = 0;

    virtual bool setFrame(int frame) = 0;

    virtual FileReadDescriptor::MethodType loadMethod() const = 0;

    virtual FormatCodecPropertySetIterator* newPropertySetIterator() const = 0;

    virtual FormatCodecPropertyInterface* getProperty(FormatCodecPropertyInterface::PropertyIdentifier id) const = 0;
    virtual FormatCodecPropertyInterface* getProperty(StringBuffer sbPropertyName) const = 0;

    virtual RowProviderInterface* read() = 0;

    virtual RowProviderInterface* scaledRead(const double& dScale, Resample::FilterTypes filterMethod) = 0;

    virtual int numClosureSetFiles() const = 0;

    virtual FileSpecifier getClosureSetFilename(int nIndex) const = 0;

    virtual ~FileReadDescriptorRep();
  };
}
#endif
