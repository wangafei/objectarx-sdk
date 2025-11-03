/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

class __declspec(novtable) IGcReadStream
{
public:
  enum
  {
    eOk           = 0,
    eNotSupported = 1,
    eNotOpen      = 2,
    eInvalidArg   = 3,
    eEndOfFile    = 4,
    eDiskFull     = 5,
    eDisconnected = 6,
    eJustAnError  = 7
  };

  enum
  {
    eFromStart   = 0,
    eFromCurrent = 1,
    eFromEnd     = 2
  };

  virtual int  seek(Gsoft::Int64 nDistance, int nMode)
  {
    GSOFT_UNREFED_PARAM(nDistance);
    GSOFT_UNREFED_PARAM(nMode);
    return eNotSupported;
  }

  virtual Gsoft::Int64 tell() { return -1; }

  virtual int read(void* pDestBuf, size_t nNumBytes, size_t *pNumRead) = 0;
  virtual int close() { return eNotSupported; }

  virtual Gsoft::Int64 control(Gsoft::Int64 nArg)
  {
    GSOFT_UNREFED_PARAM(nArg);
    return 0;
  }

protected:
  virtual ~IGcReadStream() {}
};

class __declspec(novtable) IGcWriteStream : public IGcReadStream
{
public:
  virtual int write(const void* pSrcBuf, size_t nNumBytes, size_t *pNumWritten) = 0;
  virtual int flushBuffers() { return eNotSupported; }
  virtual int setEndOfFile() { return eNotSupported; }
protected:
  ~IGcWriteStream() {}
};
