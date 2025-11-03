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

#ifndef FILEHANDLEINTERFACE_H
#define FILEHANDLEINTERFACE_H

namespace Gtil
{
  class GTIL_EXPORT FileHandleInterface
  {
  public:
    enum Basis
    {
      kBegin,
      kCurrent,
      kEnd
    };

  public:
    virtual ~FileHandleInterface();
    virtual const FileSpecifier& name() = 0;
    virtual Int64 size() = 0;
    virtual Int64 seek(Int64 nOffset, enum Basis from) = 0;
    virtual Int64 position() = 0;
    virtual Int64 read(Byte* pBuffer, Int64 bytesToRead) = 0;
    virtual Int64 write(const Byte* pData, Int64 bytesToWrite) = 0;
  };
}

#endif
