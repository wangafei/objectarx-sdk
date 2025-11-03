/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif

#ifndef DATASTREAMINTERFACE_H
#define DATASTREAMINTERFACE_H

namespace Gtil
{
  class GTIL_EXPORT DataStreamInterface
  {
  public:
    enum StreamMode
    {
      kClosed,
      kForRead,
      kForWrite
    };

  public:
    virtual ~DataStreamInterface();

    virtual void read(int nBytes, unsigned char* pBytes, int& nRead) = 0;
    virtual bool write(int nBytes, const unsigned char* cpBytes) = 0;

    virtual bool open(StreamMode mode) = 0;
    virtual bool reset() = 0;
    virtual void close() = 0;
  };

  class GTIL_EXPORT SeekableDataStreamInterface : public Gtil::DataStreamInterface
  {
  public:
    enum SeekBase
    {
      kFromStart,
      kFromEnd,
      kFromCurrent
    };
  public:
    virtual ~SeekableDataStreamInterface();

    virtual Int32 seek(Int32 nOffset, SeekBase from) = 0;
  };
}

#endif
