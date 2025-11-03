/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef FORMATCODECPROPERTYSETITERATOR_H
#include <FormatCodecPropertySetIterator.h>
#endif
#ifndef IMAGEFORMATCODEC_H
#include <ImageFormatCodec.h>
#endif
#ifndef FILESPECIFIER_H
#include <FileSpecifier.h>
#endif
#ifndef FINDFILEINTERFACE_H
namespace Gtil { class FindFileInterface; }
#endif

#ifndef CORRELATIONPROPERTYSETITERATOR_H
#define CORRELATIONPROPERTYSETITERATOR_H

class GTIL_EXPORT CorrelationPropertySetIterator : public Gtil::FormatCodecPropertySetIterator
{
public:
  enum Mode
  {
    kForRead,
    kForWrite
  };

  CorrelationPropertySetIterator(Mode mode,
                                 const Gtil::ImageFormatCodec& requestingCodec,
                                 const Gtil::FileSpecifier& fsImage,
                                 Gtil::FindFileInterface* pFFI = (Gtil::FindFileInterface*) NULL);
};

#endif
