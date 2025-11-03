/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef IMAGEFORMATCODEC_H
#include "ImageFormatCodec.h"
#endif
#ifndef DATASTREAMINTERFACE_H
#include "DataStreamInterface.h"
#endif

#ifndef FORMATCODECAPIVERSIONINTERFACE_H
namespace Gtil { class GTIL_EXPORT FormatCodecApiVersionInterface; }
#endif

#ifndef TIFFFORMATCODEC_H
#define TIFFFORMATCODEC_H

extern "C"
{
  GTIL_EXPORT const Gtil::FormatCodecApiVersionInterface* tiffApiVersion();
}

class GTIL_EXPORT TiffFormatCodec : public Gtil::ImageFormatCodec, public Gtil::ImageFormatCodecStreamingInterface
{
public:
  enum TiffId
  {
    kMember,
    kByteOrder,
    kPhotometricInterpretation,
    kArtist,
    kCopyright,
    kDateTime,
    kFillOrder,
    kGrayResponse,
    kHostComputer,
    kImageDescription,
    kScannerMake,
    kScannerModel,
    kSoftware,
    kCompressionType,
    kPrivateTag,
    kSampleRange,
    kPageInformation
  };
public:
  TiffFormatCodec(int enabledPatentedEncoding = 3);

  virtual ~TiffFormatCodec();

  virtual void getLibVersionInfo(unsigned int& nLibMajor,
                                 unsigned int& nLibMinor,
                                 unsigned int& nRelease,
                                 unsigned int& nBranch,
                                 unsigned int& nBuild) const;

  virtual void getApiVersionInfo(unsigned int& nMajor, unsigned int& nMinor) const;

  virtual Gtil::ImageFormatCodec::CodecCapability codecCapability() const;

  virtual bool isValidFileName(const Gtil::FileSpecifier& fs) const;

  virtual ImageFormatCodec::FormatType getFormatDecodabilityType() const;

  virtual bool getTiffPropertyName(TiffId id, Gtil::StringBuffer& sbName) const;

  virtual bool isFormatFeature(FormatFeature feature) const;

  virtual FormatOrganization getFormatOrganization() const;
  virtual FormatFrameType getFormatFrameType() const;

  virtual bool isSupportedProperty(
    Gtil::FormatCodecPropertyInterface::PropertyIdentifier propId,
    Gtil::StringBuffer* pCustomPropertyName = (Gtil::StringBuffer*) NULL) const;

  virtual int getNumExtensions() const;
  virtual void getExtensionText(int nExtensionIndex, Gtil::StringBuffer& sbExtension) const;
  virtual void getFormatName(Gtil::StringBuffer& sbFormatName) const;
  virtual void getDescriptionText(Gtil::StringBuffer& sbDescription) const;
  virtual void getCopyrightText(Gtil::StringBuffer& sbCopyright) const;

  void getPrivateTagName(unsigned short tagID, Gtil::StringBuffer& sbName) const;

  virtual ImageFormatCodec::FormatDecodability isDecodableFile(const Gtil::FileSpecifier& fileSpecifier,
                                                               Gtil::FindFileInterface* ff = (Gtil::FindFileInterface*) NULL) const;

  virtual bool isEncodableImage(const Gtil::DataModelAttributes& allAboutImageData, Gtil::Size size) const;

  virtual Gtil::ReadImageFileInterface* openImage(const Gtil::FileSpecifier* fsThisImage) const;
  virtual Gtil::ReadImageFileInterface * openImage(const Gtil::FileSpecifier* fsThisImage, Gtil::FindFileInterface& ff) const;

  virtual Gtil::WriteImageFileInterface* writeImage() const;
  virtual Gtil::ReadImageFileInterface* cloneOpenImage(const Gtil::ReadImageFileInterface* pOpenImage, Gtil::FindFileInterface& ff) const;

  virtual bool isExtensionMatch(const char* pExt) const;

  virtual Gtil::ReadImageFileInterface* openImage(Gtil::DataStreamInterface* pdsStream) const;
  virtual Gtil::WriteImageFileInterface* writeImage(Gtil::DataStreamInterface* pdsStream) const;

  virtual int patentedEncodingEnabled() const;

  void setPathToCsvFiles(const Gtil::StringBuffer& sbPath);
  void getPathToCsvFiles(Gtil::StringBuffer& sbPath) const;

private:
  bool mbPatentedReadEnabled;
  bool mbPatentedWriteEnabled;

  static Gtil::StringBuffer   msbCsvPath;
};

#endif
