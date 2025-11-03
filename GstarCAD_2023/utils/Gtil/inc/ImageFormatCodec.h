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
#ifndef FORMATCODECPROPERTYINTERFACE_H
#include "FormatCodecPropertyInterface.h"
#endif

#ifndef SIZE_H
namespace Gtil { class Size; }
#endif
#ifndef STRINGBUFFER_H
namespace Gtil { class StringBuffer; }
#endif
#ifndef FILESPECIFIER_H
namespace Gtil { class FileSpecifier; }
#endif
#ifndef DATAMODELATTRIBUTES_H
namespace Gtil { class DataModelAttributes; }
#endif
#ifndef FINDFILEINTERFACE_H
namespace Gtil { class FindFileInterface; }
#endif
#ifndef READIMAGEFILEINTERFACE_H
namespace Gtil { class ReadImageFileInterface; }
#endif
#ifndef WRITEIMAGEFILEINTERFACE_H
namespace Gtil { class WriteImageFileInterface; }
#endif
#ifndef DATASTREAMINTERFACE_H
namespace Gtil { class DataStreamInterface; }
#endif

#ifndef IMAGEFORMATCODEC_H
#define IMAGEFORMATCODEC_H

namespace Gtil
{
  class GTIL_EXPORT ImageFormatCodec
  {
  public:
    enum CodecCapability
    {
      kCanRead = 0x0001,
      kCanWrite = 0x002,
      kCanReadAndWrite = 0x003
    };

    enum FormatType
    {
      kStronglyTyped,
      kLooselyTyped
    };

    enum FormatOrganization
    {
      kSingleFile,
      kMultipleFiles
    };

    enum FormatDecodability
    {
      kReadable,
      kNonSupported,
      kNonReadable,
      kCorrupted
    };

    enum FormatFeature
    {
      kLosslessCompression,
      kLossyCompression,
      kDirectLoadable,
      kDelayLoadable,
      kMultipleFrames,
      kThumbnailFrames,
      kStreamable
    };

    enum FormatFrameType
    {
      kImage,
      kBand,
      kMipMap
    };

  public:
    virtual ~ImageFormatCodec();

    virtual void getLibVersionInfo(unsigned int& nLibMajor,
                                   unsigned int& nLibMinor,
                                   unsigned int& nRelease,
                                   unsigned int& nBranch,
                                   unsigned int& nBuild) const = 0;

    virtual void getApiVersionInfo(unsigned int& nMajor, unsigned int& nMinor) const = 0;

    virtual CodecCapability codecCapability() const = 0;

    virtual bool isValidFileName(const FileSpecifier& fs) const = 0;

    virtual FormatType getFormatDecodabilityType() const = 0;
    virtual FormatOrganization getFormatOrganization() const = 0;
    virtual FormatFrameType getFormatFrameType() const = 0;

    virtual bool isFormatFeature(FormatFeature feature) const = 0;
    virtual bool isSupportedProperty(FormatCodecPropertyInterface::PropertyIdentifier propId,
                                     StringBuffer* pCustomPropertyName = (StringBuffer*)NULL) const = 0;

    virtual int getNumExtensions() const = 0;

    virtual void getExtensionText(int nExtensionIndex, StringBuffer& sbExtension) const = 0;
    virtual void getFormatName(StringBuffer& sbFormatName) const = 0;
    virtual void getDescriptionText(StringBuffer& sbDescription) const = 0;
    virtual void getCopyrightText(StringBuffer& sbCopyright) const = 0;

    virtual FormatDecodability isDecodableFile(const FileSpecifier& fileSpecifier,
                                               FindFileInterface* ff = (FindFileInterface*)NULL) const = 0;

    virtual bool isEncodableImage(const DataModelAttributes& allAboutImageData, Size size) const = 0;

    virtual ReadImageFileInterface* openImage(const FileSpecifier* fsThisImage) const = 0;
    virtual ReadImageFileInterface* openImage(const FileSpecifier* fsThisImage, FindFileInterface& ff) const = 0;
    virtual WriteImageFileInterface* writeImage() const = 0;
    virtual ReadImageFileInterface* cloneOpenImage(const ReadImageFileInterface* pOpenImage, FindFileInterface& ff) const = 0;

    virtual bool isExtensionMatch(const char* pExt) const = 0;
  };

  class GTIL_EXPORT ImageFormatCodecStreamingInterface
  {
  public:
    virtual ~ImageFormatCodecStreamingInterface();

    virtual ReadImageFileInterface* openImage(DataStreamInterface* pdsStream) const = 0;
    virtual WriteImageFileInterface* writeImage(DataStreamInterface* pdsStream) const = 0;
  };
}

#endif
