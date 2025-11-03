/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif

#ifndef DATABUFFER_H
#define DATABUFFER_H

namespace Gtil
{
  class GTIL_EXPORT DataBuffer
  {
  public:
    typedef Byte* DataPtr;

  public:
    DataBuffer();
    DataBuffer(int nBytes);
    DataBuffer(const DataBuffer& other);
    virtual ~DataBuffer();

    virtual int numBytes() const;

    virtual  unsigned char* dataPtr();
    virtual  const unsigned char* dataPtr() const;

    virtual void setSize(int nBytes);

    virtual DataBuffer& operator= (const DataBuffer& rhs);

  protected:
    int mnBufferBytes;
    DataPtr mpBuffer;
  };
}
#endif

#ifndef DATABUFFER_INL
#include <DataBuffer.inl>
#endif
