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

#ifndef FORMATCODECEXCEPTION_H
#define FORMATCODECEXCEPTION_H
namespace Gtil
{
  class GTIL_EXPORT FormatCodecException : public GTILException
  {
  public:
    enum ExceptionType
    {
      kUnSpecified,
      kRequiredPropertiesNotSet,
      kInvalidRowIterator,
      kRowIteratorMismatch,
      kParametersNotComplete,
      kUnableToAppendFrame,
      kUnsupportedColorModel,
      kUnsupportedBitsPerPixel,
      kCorruptFile,
      kUnsupportedDimensions,
      kUnsupportedFeature
    };
  public:
    FormatCodecException(const StringBuffer& sbMessage, ExceptionType type = FormatCodecException::kUnSpecified);
    FormatCodecException(const FormatCodecException& x);

    virtual ~FormatCodecException();

    virtual ExceptionType getExceptionType();

  private:
    ExceptionType eType;
  };
}
#endif
