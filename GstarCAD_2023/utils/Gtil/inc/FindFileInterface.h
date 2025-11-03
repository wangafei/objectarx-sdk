/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif

#ifndef FILESPECIFIER_H
namespace Gtil { class FileSpecifier; }
#endif
#ifndef IMAGEFORMATCODEC_H
namespace Gtil { class ImageFormatCodec; }
#endif

#ifndef STRINGBUFFER_H
namespace Gtil { class StringBuffer; }
#endif

#ifndef FINDFILEINTERFACE_H
#define FINDFILEINTERFACE_H

namespace Gtil
{
  class GTIL_EXPORT FindFileInterface
  {
  public:
    virtual ~FindFileInterface();
    virtual bool findFile(const ImageFormatCodec& pRequestingCodec,
                          const FileSpecifier& fsAssociatedImage,
                          const FileSpecifier& fsFindMe,
                          FileSpecifier& fsWhatWasFound) = 0;
    virtual bool findFile(const ImageFormatCodec& pRequestingCodec,
                          const FileSpecifier& fsAssociatedImage,
                          const StringBuffer& sbExtension,
                          FileSpecifier& fsWhatWasFound) = 0;
  };
}

#endif
