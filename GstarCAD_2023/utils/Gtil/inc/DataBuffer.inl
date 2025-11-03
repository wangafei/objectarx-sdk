/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef DATABUFFER_INL
#define DATABUFFER_INL
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Gtil
{
  inline int DataBuffer::numBytes() const
  {
    return mnBufferBytes;
  }

  inline unsigned char* DataBuffer::dataPtr()
  {
    return mpBuffer;
  }

  inline const unsigned char* DataBuffer::dataPtr() const
  {
    return mpBuffer;
  }

}
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif
