/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
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
#ifndef FILEREADDESCRIPTORREP_H
namespace Gtil { class FileReadDescriptorRep; }
#endif
#ifndef FILESPECIFIER_H
namespace Gtil { class FileSpecifier; }
#endif
#ifndef IMAGEFORMATCODEC_H
namespace Gtil { class ImageFormatCodec; }
#endif
#ifndef ROWPROVIDERINTERFACE_H
namespace Gtil { class RowProviderInterface; }
#endif
#ifndef FORMATCODECPROPERTYSETITERATOR_H
namespace Gtil { class GTIL_EXPORT FormatCodecPropertySetIterator; }
#endif
#ifndef DATAMODEL_H
namespace Gtil { class DataModel; }
#endif
#ifndef INTERNAL_H
namespace Gtil { class Internal; }
#endif
#ifndef FINDFILEINTERFACE_H
namespace Gtil { class FindFileInterface; }
#endif

#ifndef IMAGEFORMATCODEC_H
#include "ImageFormatCodec.h"
#endif

#ifndef FILEREADDESCRIPTOR_H
#define FILEREADDESCRIPTOR_H

namespace Gtil
{
  class GTIL_EXPORT FileReadDescriptor
  {
  public:
    enum MethodType
    {
      kFullRead,
      kDirectRead,
      kMultipleResolution,
      kPartialLoad,
      kThumbnail,
      kStream
    };

  public:
    static ImageFormatCodec::FormatDecodability findImageFileCodec(const FileSpecifier& fs,
                                                                   const ImageFormatCodec*& pIsThisCodec);
    static ImageFormatCodec::FormatDecodability isDecodableFile(const FileSpecifier& fs,
                                                                const ImageFormatCodec* useThisCodec);

    FileReadDescriptor(const FileSpecifier& fs);
    FileReadDescriptor(const FileSpecifier& fs, FindFileInterface* pFindFile);
    FileReadDescriptor(const FileSpecifier& fs, const ImageFormatCodec* useThisCodec);
    FileReadDescriptor(const FileSpecifier& fs, const ImageFormatCodec* useThisCodec, FindFileInterface* pFindFile);
    FileReadDescriptor(DataStreamInterface* pdsStream, const ImageFormatCodec* useThisCodec);
    FileReadDescriptor(const FileReadDescriptor& copyThis);
    ~FileReadDescriptor();

    void open() const;
    void close() const;

    void getFileSpecifier(FileSpecifier& fs) const;

    const ImageFormatCodec* formatCodec() const;

    int numFrames() const;
    int selectedFrame() const;
    bool setFrame(int frame);

    FileReadDescriptor::MethodType loadMethod() const;

    void getDataSize(Size& size) const;
    void getDataSize(int& nRows, int& nColumns, int& nDepths) const;

    Gtil::Orientation dataOrientation() const;

    void getOrientedSize(Size& size) const;

    const DataModel& dataModel() const;

    FormatCodecPropertySetIterator* newPropertySetIterator() const;

    FormatCodecPropertyInterface* getProperty(FormatCodecPropertyInterface::PropertyIdentifier id) const;
    FormatCodecPropertyInterface* getProperty(StringBuffer sbPropertyName) const;

    RowProviderInterface* read();

    RowProviderInterface* scaledRead(const double& dScale, Resample::FilterTypes filterMethod);

    int numClosureSetFiles() const;

    FileSpecifier getClosureSetFilename(int nIndex) const;

  private:
    FileReadDescriptorRep* mpImplementation;
    friend class Internal;
  };
}

#endif
