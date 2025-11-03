/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef FORMATCODECCORRELATION_H
#include "FormatCodecCorrelation.h"
#endif
#ifndef FILESPECIFIER_H
#include "FileSpecifier.h"
#endif

#ifndef FORMATCODECEXTERNALCORRELATION_H
#define FORMATCODECEXTERNALCORRELATION_H

namespace Gtil
{
  class GTIL_EXPORT FormatCodecExternalCorrelationInterface
  {
  public:
    virtual ~FormatCodecExternalCorrelationInterface() {}

    virtual FormatCodecPropertyInterface* clone() const = 0;

    virtual void getFileSpecifier(FileSpecifier& fsCorrelation) const = 0;
    virtual void getFilePath(FileSpecifier& fsCorrelationPath) const = 0;
    virtual void getFileName(StringBuffer& sbFileName) const = 0;
    virtual void getFileExtension(StringBuffer& sbFileExtension) const = 0;

    virtual void setWriteFileName(const StringBuffer& sbFileName) = 0;
    virtual void setWritePath(const FileSpecifier& fsPath) = 0;

    virtual void readCorrelation() = 0;
    virtual void writeCorrelation() = 0;

    virtual void setOrientation(Gtil::Orientation ornt) = 0;
    virtual void setImageDimensions(int rows, int columns) = 0;
    virtual void setImageBitsPerPixel(int nBits) = 0;
  };

  class GTIL_EXPORT FormatCodecExternalCorrelation
    : public FormatCodecCorrelation, public FormatCodecExternalCorrelationInterface
  {
  public:
    virtual ~FormatCodecExternalCorrelation() {}
  private:
    void operator= (const FormatCodecExternalCorrelation&);
  };
}

#endif