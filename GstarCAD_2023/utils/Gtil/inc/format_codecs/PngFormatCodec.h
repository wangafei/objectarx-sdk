/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef  IMAGEFORMATCODEC_H
#include <ImageFormatCodec.h>
#endif

#ifndef FORMATCODECAPIVERSIONINTERFACE_H
namespace Gtil { class GTIL_EXPORT FormatCodecApiVersionInterface; }
#endif

#ifndef PNGFORMATCODEC_H
#define PNGFORMATCODEC_H

extern "C"
{
  GTIL_EXPORT const Gtil::FormatCodecApiVersionInterface* pngApiVersion();
}

class GTIL_EXPORT PngFormatCodec : public Gtil::ImageFormatCodec, public Gtil::ImageFormatCodecStreamingInterface
{
public:
  enum PngIdentifier
  {
    kGamma,
    kScale,
    kOffset,
    kSRGB,
    kHistogram,
    kGraySignificantBits,
    kTitle,
    kAuthor,
    kDescription,
    kCopyright,
    kCreationTime,
    kSoftware,
    kDisclaimer,
    kWarning,
    kSource,
    kComment,
    kInterlace
  };

public:
  PngFormatCodec();
  virtual ~PngFormatCodec();

  virtual void getLibVersionInfo(unsigned int& nLibMajor,
                                 unsigned int& nLibMinor,
                                 unsigned int& nRelease,
                                 unsigned int& nBranch,
                                 unsigned int& nBuild) const;

  virtual void getApiVersionInfo(unsigned int& nMajor, unsigned int& nMinor) const;

  virtual Gtil::ImageFormatCodec::CodecCapability codecCapability() const;

  virtual bool isValidFileName(const Gtil::FileSpecifier& fs) const;

  virtual Gtil::ImageFormatCodec::FormatType getFormatDecodabilityType() const;

  virtual bool isFormatFeature(FormatFeature feature) const;

  virtual FormatOrganization getFormatOrganization() const;

  virtual FormatFrameType getFormatFrameType() const;

  virtual bool isSupportedProperty(Gtil::FormatCodecPropertyInterface::PropertyIdentifier propId,
                                   Gtil::StringBuffer* pCustomPropertyName = (Gtil::StringBuffer*) NULL) const;
  virtual bool isSupportedProperty(PngFormatCodec::PngIdentifier propId) const;

  virtual bool getPngPropertyName(PngIdentifier id, Gtil::StringBuffer& sbName) const;
  virtual int  getNumExtensions() const;
  virtual void getExtensionText(int nExtensionIndex, Gtil::StringBuffer& sbExtension) const;
  virtual void getFormatName(Gtil::StringBuffer& sbFormatName) const;
  virtual void getDescriptionText(Gtil::StringBuffer& sbDescription) const;
  virtual void getCopyrightText(Gtil::StringBuffer& sbCopyright) const;

  virtual Gtil::ImageFormatCodec::FormatDecodability isDecodableFile(
    const Gtil::FileSpecifier& fileSpecifier,
    Gtil::FindFileInterface* ff = (Gtil::FindFileInterface*) NULL) const;

  virtual bool isEncodableImage(const Gtil::DataModelAttributes& allAboutImageData, Gtil::Size size) const;

  virtual Gtil::ReadImageFileInterface* openImage(const Gtil::FileSpecifier* fsThisImage) const;
  virtual Gtil::ReadImageFileInterface * openImage(const Gtil::FileSpecifier* fsThisImage, Gtil::FindFileInterface& ff) const;
  virtual Gtil::WriteImageFileInterface* writeImage() const;
  virtual Gtil::ReadImageFileInterface* cloneOpenImage(const Gtil::ReadImageFileInterface* pOpenImage, Gtil::FindFileInterface& ff) const;

  virtual bool isExtensionMatch(const char* pExt) const;

  virtual Gtil::ReadImageFileInterface* openImage(Gtil::DataStreamInterface* pdsStream) const;
  virtual Gtil::WriteImageFileInterface* writeImage(Gtil::DataStreamInterface* pdsStream) const;
};

#endif
