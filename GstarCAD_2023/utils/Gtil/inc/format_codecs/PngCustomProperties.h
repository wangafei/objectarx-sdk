/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef FORMATCODECPROPERTYINTERFACE_H
#include <FormatCodecPropertyInterface.h>
#endif
#ifndef FORMATCODECINTPROPERTY_H
#include <FormatCodecIntProperty.h>
#endif
#ifndef FORMATCODECDOUBLEPROPERTY_H
#include <FormatCodecDoubleProperty.h>
#endif
#ifndef FORMATCODECSTRINGPROPERTY_H
#include <FormatCodecStringProperty.h>
#endif
#ifndef FORMATCODECINCLUSIVEPROPERTYSETINTERFACE_H
#include <FormatCodecInclusivePropertySetInterface.h>
#endif
#ifndef FORMATCODECEXCLUSIVEPROPERTYSETINTERFACE_H
#include <FormatCodecExclusivePropertySetInterface.h>
#endif
#ifndef FORMATCODECPROPERTYSETITERATOR_H
#include <FormatCodecPropertySetIterator.h>
#endif
#ifndef FORMATCODECTRANSPARENCY_H
#include <FormatCodecTransparency.h>
#endif
#ifndef FORMATCODECDENSITY_H
#include <FormatCodecDensity.h>
#endif
#ifndef FORMATCODECCOLORPROPERTY_H
#include <FormatCodecColorProperty.h>
#endif
#ifndef FORMATCODECBOOLEANPROPERTY_H
#include <FormatCodecBooleanProperty.h>
#endif

#ifndef PNGFORMATCODEC_H
#include <PngFormatCodec.h>
#endif

#ifndef PNG_H
#if !defined LINUX
struct png_info_def;
typedef struct png_info_def png_info;
#else
struct png_info_struct;
typedef struct png_info_struct png_info;
#endif
typedef png_info* png_infop;

struct png_struct_def;
typedef struct png_struct_def png_struct;
typedef png_struct* png_structp;
#endif

#ifndef PNGCUSTOMPROPERTIES_H
#define PNGCUSTOMPROPERTIES_H

class GTIL_EXPORT PngCustomProperty
{
public:
  virtual ~PngCustomProperty();

  PngFormatCodec::PngIdentifier pngId() const;

  virtual bool writeBefore() const;
  virtual bool write(png_structp pPng, png_infop pInfo) const = 0;

protected:
  PngFormatCodec::PngIdentifier mPngId;

  bool mbWriteBeforePLTE;
};

class GTIL_EXPORT PngGamma : public Gtil::FormatCodecDoubleProperty, public PngCustomProperty
{
public:
  PngGamma();
  PngGamma(png_structp pPng, png_infop pInfo);
  ~PngGamma();

  virtual Gtil::FormatCodecPropertyInterface* clone() const;

  bool write(png_structp pPng, png_infop pInfo) const;
};

class GTIL_EXPORT PngScale : public Gtil::FormatCodecInclusivePropertySetInterface, public PngCustomProperty
{
public:
  PngScale();
  PngScale(png_structp pPng, png_infop pInfo);
  ~PngScale();

  virtual Gtil::FormatCodecPropertyInterface* clone() const;

  bool write(png_structp pPng, png_infop pInfo) const;
};

class GTIL_EXPORT PngPageOffset : public Gtil::FormatCodecInclusivePropertySetInterface, public PngCustomProperty
{
public:
  PngPageOffset();
  PngPageOffset(png_structp pPng, png_infop pInfo);
  ~PngPageOffset();

  virtual Gtil::FormatCodecPropertyInterface* clone() const;

  bool write(png_structp pPng, png_infop pInfo) const;
};

class GTIL_EXPORT PngText : public Gtil::FormatCodecStringProperty, public PngCustomProperty
{
public:
  enum Keyword
  {
    kComment = 0,
    kTitle,
    kAuthor,
    kDescription,
    kCopyright,
    kCreationTime,
    kSoftware,
    kDisclaimer,
    kWarning,
    kSource
  };

  static const char* getString(Keyword key);
public:
  PngText(const Gtil::StringBuffer& sbDefault, int nMaximumBytes, Keyword key = kComment);
  ~PngText();

  virtual Gtil::FormatCodecPropertyInterface* clone() const;

  void getKeyword(const char*& pKeyword) const;

  bool write(png_structp pPng, png_infop pInfo) const;

protected:
  Keyword mKeyword;

  static const char* mcpKeywords[10];
};

class GTIL_EXPORT PngSRGB : public Gtil::FormatCodecExclusivePropertySetInterface, public PngCustomProperty
{
  enum Intent
  {
    kPerceptual = 0,
    kRelative,
    kSaturation,
    kAbsolute
  };
public:
  PngSRGB();
  PngSRGB(png_structp pPng, png_infop pInfo);
  ~PngSRGB();

  virtual Gtil::FormatCodecPropertyInterface* clone() const;

  virtual void setSelectedIndex(int nSelectionIndex);

  bool write(png_structp pPng, png_infop pInfo) const;
private:
  Intent mSRgbIntent;
};

class GTIL_EXPORT PngHistogram : public Gtil::FormatCodecPropertyInterface, public PngCustomProperty
{
public:
  PngHistogram();
  PngHistogram(png_structp pPng, png_infop pInfo);
  ~PngHistogram();

  virtual Gtil::FormatCodecPropertyInterface* clone() const;

  int numEntries() const;

  void getHistogram(int nEntries, unsigned short* pEntries) const;
  void setHistogram(int nEntries, unsigned short* pEntries);

  bool write(png_structp pPng, png_infop pInfo) const;

private:
  unsigned short * masHistogram;
  int mnEntries;
};

class GTIL_EXPORT PngGraySignificantBits : public Gtil::FormatCodecIntProperty, public PngCustomProperty
{
public:
  PngGraySignificantBits();
  PngGraySignificantBits(png_structp pPng, png_infop pInfo);
  ~PngGraySignificantBits();

  bool write(png_structp pPng, png_infop pInfo) const;
};

class GTIL_EXPORT PngCompressionType : public Gtil::FormatCodecPropertyInterface
{
public:
  enum Compression
  {
    kNone   = 0,
    kLow    = 1,
    kMedium = 3,
    kNormal = 6,
    kHigh   = 9
  };
public:
  PngCompressionType(Compression type);
  ~PngCompressionType();

  virtual Gtil::FormatCodecPropertyInterface* clone() const;
  Compression type();
private:
  Compression mCompressionType;
};

class GTIL_EXPORT PngCompression : public Gtil::FormatCodecExclusivePropertySetInterface
{
public:
  PngCompression(PngCompressionType::Compression type = PngCompressionType::kNormal);
  ~PngCompression();
public:
  virtual Gtil::FormatCodecPropertyInterface* clone() const;

  PngCompressionType::Compression getCompressionType(int nIndex)const;

  bool selectCompression(PngCompressionType::Compression use);

  bool write(png_structp pPng, png_infop pInfo) const;
};

class GTIL_EXPORT PngInterlacing : public Gtil::FormatCodecBooleanProperty, public PngCustomProperty
{
public:
  PngInterlacing();
  PngInterlacing(png_structp pPng, png_infop pInfo);
  ~PngInterlacing();

  virtual Gtil::FormatCodecPropertyInterface* clone() const;

  bool write(png_structp pPng, png_infop pInfo) const;
};

#endif
