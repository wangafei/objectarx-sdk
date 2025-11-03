#pragma once

class __declspec(novtable) IGcReadStream
{
  public:
    enum {
            eOk = 0,// No errors occurred

            eNotSupported = 1,// This function is not supported for this stream object

            eNotOpen = 2,// The stream is not open

            eInvalidArg = 3,// One of the arguments is an invalid value

            eEndOfFile = 4,// The stream is at the end of the file

            eDiskFull = 5,// The disk to which the stream is writing is full

            eDisconnected = 6,// The stream is disconnected

            eJustAnError = 7// Unknown error
    };

    // seek mode arguments
    enum {
            eFromStart = 0,// Seek from start of stream

            eFromCurrent = 1,// Seek from current stream position

            eFromEnd = 2// Seek from end of stream
    };

    virtual int  seek(__int64 nDistance, int nMode) { return eNotSupported; }

    virtual __int64 tell() { return -1; }

    virtual int read(void* pDestBuf, size_t nNumBytes,
                                     size_t *pNumRead) = 0;

    virtual int  close() { return eNotSupported; }

    virtual __int64 control(__int64 nArg) { return 0; }

  protected:
    virtual ~IGcReadStream() {}     // no explicit deletes
};

class __declspec(novtable) IGcWriteStream : public IGcReadStream
{
  public:
    virtual int write(const void* pSrcBuf, size_t nNumBytes,
                      size_t *pNumWritten) = 0;

    virtual int flushBuffers() { return eNotSupported; }

    virtual int setEndOfFile() { return eNotSupported; }
	
  protected:
    virtual ~IGcWriteStream() {} // no explicit deletes
};

