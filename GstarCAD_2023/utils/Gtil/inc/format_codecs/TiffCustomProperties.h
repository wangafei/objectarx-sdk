/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef FORMATCODECPROPERTYINTERFACE_H
#include <FormatCodecPropertyInterface.h>
#endif
#ifndef FORMATCODECPROPERTYSETITERATOR_H
#include <FormatCodecPropertySetIterator.h>
#endif
#ifndef FORMATCODECSTRINGPROPERTY_H
#include <FormatCodecStringProperty.h>
#endif
#ifndef FORMATCODECDENSITY_H
#include <FormatCodecDensity.h>
#endif
#ifndef FORMATCODECASSOCIATION_H
#include <FormatCodecAssociation.h>
#endif
#ifndef STRINGBUFFER_H
#include <StringBuffer.h>
#endif
#ifndef FORMATCODECEXCLUSIVEPROPERTYSETINTERFACE_H
#include <FormatCodecExclusivePropertySetInterface.h>
#endif
#ifndef FORMATCODECTRANSPARENCY_H
#include <FormatCodecTransparency.h>
#endif
#ifndef TIFFFORMATCODEC_H
#include <TiffFormatCodec.h>
#endif

#ifndef TIFFCUSTOMPROPERTIES_H
#define TIFFCUSTOMPROPERTIES_H

struct tiff;

class GTIL_EXPORT TiffProperty
{
public:
  virtual ~TiffProperty() {};
  virtual TiffFormatCodec::TiffId getTiffId() const { return mTiffId; }
protected:
  TiffFormatCodec::TiffId	mTiffId;
public:
  virtual bool write(struct tiff* pTIFF) const = 0;
};

class GTIL_EXPORT TiffCompressionType : public Gtil::FormatCodecPropertyInterface, public TiffProperty
{
public:
  enum Compression
  {
    kNone = 0,
    kCCITT_RLE,
    kCCITT_RLEW,
    kCCITT_FAX3,
    kCCITT_FAX4,
    kLZW,
    kPackbits,
    kJPEG,
    kDeflate
  };
public:
  TiffCompressionType(Compression type);
  ~TiffCompressionType();

  virtual Gtil::FormatCodecPropertyInterface* clone() const;

  Compression type();

  bool write(struct tiff* pTIFF) const;
private:
  Compression mCompressionType;
};

class GTIL_EXPORT TiffCompression : public Gtil::FormatCodecExclusivePropertySetInterface, public TiffProperty
{
public:
  TiffCompression(int nBitsPerPixel,
                  unsigned short usPhotometric,
                  unsigned short usSamplesPerPixel,
                  TiffCompressionType::Compression selected = TiffCompressionType::kNone,
                  bool bWriting = false,
                  bool bPatentedEncoding = false);
  ~TiffCompression();

  virtual Gtil::FormatCodecPropertyInterface* clone() const;

  TiffCompressionType::Compression getCompressionType(int nIndex) const;

  bool selectCompression(TiffCompressionType::Compression use);

  bool write(struct tiff* pTIFF) const;
};

class GTIL_EXPORT TiffPhotometricInterpretation : public Gtil::FormatCodecExclusivePropertySetInterface, public TiffProperty
{
public:
  enum Interpretation
  {
    kMinIsWhite,
    kMinIsBlack
  };
public:
  TiffPhotometricInterpretation(
    TiffPhotometricInterpretation::Interpretation interp = TiffPhotometricInterpretation::kMinIsWhite);
  ~TiffPhotometricInterpretation();

  virtual Gtil::FormatCodecPropertyInterface* clone() const;

  Interpretation photometricInterpretation() const;

  bool write(struct tiff* pTIFF) const;
};

class GTIL_EXPORT TiffFillOrder : public Gtil::FormatCodecExclusivePropertySetInterface, public TiffProperty
{
public:
  enum Order
  {
    kMSBtoLSB,
    kLSBtoMSB
  };
public:
  TiffFillOrder(TiffFillOrder::Order order = TiffFillOrder::kMSBtoLSB);
  ~TiffFillOrder();

  virtual Gtil::FormatCodecPropertyInterface* clone() const;

  Order fillOrder() const;

  bool write(struct tiff* pTIFF) const;

private:
  Order mOrder;
};

class GTIL_EXPORT TiffGrayResponseCurve : public Gtil::FormatCodecPropertyInterface, public TiffProperty
{
public:
  TiffGrayResponseCurve();
  virtual ~TiffGrayResponseCurve();

  virtual Gtil::FormatCodecPropertyInterface* clone() const;

  virtual int responseLevels() const;
  virtual void getResponseLevels(float* pValues) const;
  virtual void setResponseLevels(int nLevels, unsigned short* pValues, int nTenthDivisor);

  virtual unsigned short tenthDivisor() const;

  virtual unsigned short* unscaledData() const;

  bool write(struct tiff* pTIFF) const;
private:
  unsigned short* mpScaledLevels;
  int mnLevels;
  int mnTenthScaler;
};

class GTIL_EXPORT TiffText : public Gtil::FormatCodecStringProperty, public TiffProperty
{
public:
  TiffText(TiffFormatCodec::TiffId tiffId);
  TiffText(TiffFormatCodec::TiffId tiffId, Gtil::StringBuffer* psbText);
  ~TiffText();

  virtual Gtil::FormatCodecPropertyInterface* clone() const;

  bool setValue(const Gtil::StringBuffer& sbValue);

  bool write(struct tiff* pTIFF) const;
};

class GTIL_EXPORT TiffPrivateTag : public Gtil::FormatCodecPropertyInterface, public TiffProperty
{
public:
  enum TiffDataType
  {
    kUnknown,
    kByte,
    kAscii,
    kShort,
    kLong,
    kRational,
    kSignedByte,
    kUndefined,
    kSignedShort,
    kSignedLong,
    kSignedRational,
    kFloat,
    kDouble
  };

  typedef unsigned char TTiffByte;
  typedef unsigned char TTiffAscii;
  typedef unsigned short TTiffShort;
  typedef unsigned int TTiffLong;
  typedef float TTiffRational;
  typedef char TTiffSignedByte;
  typedef unsigned char TTiffUndefined;
  typedef short TTiffSignedShort;
  typedef int TTiffSignedLong;
  typedef float TTiffSignedRational;
  typedef float TTiffFloat;
  typedef double TTiffDouble;

public:
  TiffPrivateTag(unsigned short tagId, TiffDataType dataType);
  virtual ~TiffPrivateTag();

  virtual Gtil::FormatCodecPropertyInterface* clone() const;

  virtual bool write(struct tiff* pTiff) const;

  bool isValid() const;
  TiffDataType dataType() const;
  unsigned short tagId() const;
  unsigned int numItems() const;
  unsigned int numDataBytes() const;

  bool getValue(TTiffByte* pData, const unsigned int nItems);
  bool setValue(TTiffByte const* pData, const unsigned int nItems);

  bool getValue(TTiffShort* pData, const unsigned int nItems);
  bool setValue(TTiffShort const* pData, const unsigned int nItems);

  bool getValue(TTiffLong* pData, const unsigned int nItems);
  bool setValue(TTiffLong const* pData, const unsigned int nItems);

  bool getValue(TTiffSignedByte* pData, const unsigned int nItems);
  bool setValue(TTiffSignedByte const* pData, const unsigned int nItems);

  bool getValue(TTiffSignedShort* pData, const unsigned int nItems);
  bool setValue(TTiffSignedShort const* pData, const unsigned int nItems);

  bool getValue(TTiffSignedLong* pData, const unsigned int nItems);
  bool setValue(TTiffSignedLong const* pData, const unsigned int nItems);

  bool getValue(TTiffFloat* pData, const unsigned int nItems);
  bool setValue(TTiffFloat const* pData, const unsigned int nItems);

  bool getValue(TTiffDouble* pData, const unsigned int nItems);
  bool setValue(TTiffDouble const* pData, const unsigned int nItems);

private:
  bool storeValue(void const * pData, const unsigned int numBytes);
  bool retrieveValue(void* pData, const unsigned int numBytes);

  TiffDataType mDataType;
  unsigned int mNumItems;
  void* mpTagValue;
  unsigned short mTagId;
  bool mbValid;
};

class GTIL_EXPORT TiffSampleRange : public Gtil::FormatCodecInclusivePropertySetInterface, public TiffProperty
{
public:
  TiffSampleRange();
  virtual ~TiffSampleRange();

  virtual Gtil::FormatCodecPropertyInterface* clone() const;

  virtual void getRange(unsigned short& nMinValue, unsigned short& nMaxValue) const;
  virtual void setRange(unsigned short nMinValue, unsigned short nMaxValue);

  bool write(struct tiff* pTIFF) const;
};

class GTIL_EXPORT TiffPageInformation : public Gtil::FormatCodecInclusivePropertySetInterface, public TiffProperty
{
public:
  TiffPageInformation(Gtil::StringBuffer* pDoc,
                      Gtil::StringBuffer* pPage,
                      int nPage,
                      int nPages,
                      double* pX,
                      double* pY);

  virtual ~TiffPageInformation();

  virtual Gtil::FormatCodecPropertyInterface* clone() const;

  virtual bool getDocumentName(Gtil::StringBuffer& sbName) const;
  virtual bool getPageName(Gtil::StringBuffer& sbName) const;
  virtual bool getPageNumber(int& nNumber) const;
  virtual bool getPosition(double& dX, double& dY) const;

private:
  bool write(struct tiff* pTIFF) const;
};

#endif
