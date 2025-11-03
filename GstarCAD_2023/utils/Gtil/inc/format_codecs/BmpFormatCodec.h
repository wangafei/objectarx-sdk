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

#ifndef BMPFORMATCODEC_H
#define BMPFORMATCODEC_H

extern "C"
{
  GTIL_EXPORT const Gtil::FormatCodecApiVersionInterface* bmpApiVersion();
}

class GTIL_EXPORT BmpFormatCodec : public Gtil::ImageFormatCodec, public Gtil::ImageFormatCodecStreamingInterface
{
public:
  BmpFormatCodec();
  virtual ~BmpFormatCodec();

  virtual void getLibVersionInfo(unsigned int& nLibMajor,
                                 unsigned int& nLibMinor,
                                 unsigned int& nRelease,
                                 unsigned int& nBranch,
                                 unsigned int& nBuild) const;
  virtual void getApiVersionInfo(unsigned int& nMajor, unsigned int& nMinor) const;

  virtual Gtil::ImageFormatCodec::CodecCapability codecCapability() const;

  virtual bool isValidFileName(const Gtil::FileSpecifier& fs) const;

  virtual Gtil::ImageFormatCodec::FormatType getFormatDecodabilityType() const;
  virtual FormatOrganization getFormatOrganization() const;
  virtual FormatFrameType getFormatFrameType() const;

  virtual bool isFormatFeature(FormatFeature feature) const;
  virtual bool isSupportedProperty(Gtil::FormatCodecPropertyInterface::PropertyIdentifier propId,
                                   Gtil::StringBuffer* pCustomPropertyName = (Gtil::StringBuffer*) NULL) const;

  virtual int  getNumExtensions() const;
  virtual void getExtensionText(int nExtensionIndex, Gtil::StringBuffer& sbExtension) const;
  virtual void getFormatName(Gtil::StringBuffer& sbFormatName) const;
  virtual void getDescriptionText(Gtil::StringBuffer& sbDescription) const;
  virtual void getCopyrightText(Gtil::StringBuffer& sbCopyright) const;

  virtual Gtil::ImageFormatCodec::FormatDecodability isDecodableFile(const Gtil::FileSpecifier& fileSpecifier,
                                                                     Gtil::FindFileInterface * ff = NULL) const;

  virtual bool isEncodableImage(const Gtil::DataModelAttributes& allAboutImageData, Gtil::Size size) const;

  virtual Gtil::ReadImageFileInterface*  openImage(const Gtil::FileSpecifier* fsThisImage) const;
  virtual Gtil::ReadImageFileInterface * openImage(const Gtil::FileSpecifier* fsThisImage,
                                                   Gtil::FindFileInterface& ff) const;
  virtual Gtil::ReadImageFileInterface*  openImage(Gtil::DataStreamInterface* pdsStream) const;
  virtual Gtil::WriteImageFileInterface* writeImage() const;
  virtual Gtil::WriteImageFileInterface* writeImage(Gtil::DataStreamInterface* pdsStream) const;
  virtual Gtil::ReadImageFileInterface*  cloneOpenImage(const Gtil::ReadImageFileInterface* pOpenImage,
                                                        Gtil::FindFileInterface& ff) const;

  virtual bool isExtensionMatch(const char* pExt) const;
};

#endif
