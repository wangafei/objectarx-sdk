/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef WRITEIMAGEFRAMEINTERFACE_H
#include "WriteImageFileFrameInterface.h"
#endif

#ifndef IMAGEFORMATCODEC_H
namespace Gtil { class ImageFormatCodec; }
#endif
#ifndef FILESPECIFIER_H
namespace Gtil { class FileSpecifier; }
#endif

#ifndef WRITEIMAGEFILEINTERFACE_H
#define WRITEIMAGEFILEINTERFACE_H

namespace Gtil
{
  class GTIL_EXPORT WriteImageFileInterface
  {
  public:
    virtual ~WriteImageFileInterface();

    virtual WriteImageFileFrameInterface* newWriteImageFileFrameInterface() = 0;

    virtual const ImageFormatCodec* formatCodec() const = 0;

    virtual bool setFileName(const FileSpecifier& fsNewFile) = 0;
    virtual const FileSpecifier& fileName() const = 0;

    virtual int numFilesInClosureSet() = 0;

    virtual FileSpecifier getClosureSetMember(int nMemberIndex) = 0;

    virtual int writeImageFileFrame(WriteImageFileFrameInterface* pFrameAtts,
                                    RowIteratorInterface* pRowIterator) = 0;
  };
}

#endif

#ifndef FILESPECIFIER_H
#include <FileSpecifier.h>
#endif
