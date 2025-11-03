
#pragma once



class __declspec(novtable) IZcReadStream
{
  public:

    enum {
            eOk = 0,
            eNotSupported = 1,
            eNotOpen = 2,
            eInvalidArg = 3,
            eEndOfFile = 4,
            eDiskFull = 5,
            eDisconnected = 6,
            eJustAnError = 7
    };

    enum {
            eFromStart = 0,
            eFromCurrent = 1,
            eFromEnd = 2
    };

    virtual int  seek(ZSoft::Int64 nDistance, int nMode) { 
        ZSOFT_UNREFED_PARAM(nDistance);
        ZSOFT_UNREFED_PARAM(nMode);
        return eNotSupported; 
    }

    virtual ZSoft::Int64 tell() { return -1; }

    virtual int read(void* pDestBuf, size_t nNumBytes,
                                     size_t *pNumRead) = 0;

    virtual int  close() { return eNotSupported; }

    virtual ZSoft::Int64 control(ZSoft::Int64 nArg) {
        ZSOFT_UNREFED_PARAM(nArg);
        return 0; 
    }

  protected:

    virtual ~IZcReadStream() {}     
};

class __declspec(novtable) IZcWriteStream : public IZcReadStream
{
  public:

    virtual int write(const void* pSrcBuf, size_t nNumBytes,
                      size_t *pNumWritten) = 0;

    virtual int flushBuffers() { return eNotSupported; }

    virtual int setEndOfFile() { return eNotSupported; }
  protected:

    virtual ~IZcWriteStream() {} 
};

