/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef IMAGEFORMATCODEC_H
namespace Gtil { class ImageFormatCodec; }
#endif
#ifndef FILESPECIFIER_H
namespace Gtil { class FileSpecifier; }
#endif
#ifndef READIMAGEFILEFRAMEINTERFACE_H
namespace Gtil { class ReadImageFileFrameInterface; }
#endif

#ifndef READIMAGEFILEINTERFACE_H
#define READIMAGEFILEINTERFACE_H

namespace Gtil
{
  class GTIL_EXPORT ReadImageFileInterface
  {
  public:
    virtual ~ReadImageFileInterface();

    virtual const ImageFormatCodec* formatCodec() const = 0;

    virtual const FileSpecifier& fileName() const = 0;

    virtual int numFilesInClosureSet() const = 0;

    virtual FileSpecifier getClosureSetMember(int nMemberIndex) const = 0;

    virtual int numFrames() const = 0;

    virtual ReadImageFileFrameInterface* getFrame(int nFrameIndex) = 0;
  };
}

#endif
