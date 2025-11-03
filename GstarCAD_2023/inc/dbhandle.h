/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBHANDLE_H
#define GD_DBHANDLE_H 1

#include "gsoft.h"
#include <stddef.h>
#include "GcDbCore2dDefs.h"

#pragma pack (push, 8)

class GCBASE_PORT GcDbHandle
{
public:
  GcDbHandle();
  GcDbHandle(int lo, int hi);
  GcDbHandle(const GCHAR*);
  GcDbHandle(Gsoft::UInt64);

  GcDbHandle& operator=(const GcDbHandle&);
  GcDbHandle& operator=(const GCHAR*);

  bool getIntoAsciiBuffer(GCHAR* pBuf, size_t nBufLen) const;
  enum { kStrSiz = 17 };

  template<size_t nBufLen> inline bool getIntoAsciiBuffer(wchar_t(&buf)[nBufLen]) const
  {
    return this->getIntoAsciiBuffer(buf, nBufLen);
  }

  bool operator == (const GcDbHandle&) const;
  bool operator != (const GcDbHandle&) const;

  bool           isNull() const;
  void           setNull();
  Gsoft::UInt32  low() const;
  Gsoft::UInt32  high() const;
  void           setLow(Gsoft::UInt32 low);
  void           setHigh(Gsoft::UInt32 high);
  bool           isOne(void) const;

  GcDbHandle& operator++();
  GcDbHandle operator++(int);
  void increment(void);
  void decrement(void);
  GcDbHandle operator + (const GcDbHandle&) const;
  GcDbHandle slowOperatorPlus(const GcDbHandle&) const;
  GcDbHandle& operator += (const GcDbHandle&);
  GcDbHandle operator - (const GcDbHandle&) const;
  GcDbHandle& operator -= (const GcDbHandle&);
  bool operator > (const GcDbHandle&) const;
  bool operator >= (const GcDbHandle&) const;
  bool operator < (const GcDbHandle&) const;
  bool operator <= (const GcDbHandle&) const;
  int compare(const GcDbHandle&) const;
  void copyToOldType(Gsoft::UInt8 hand[8]) const;
  void copyFromOldType(const Gsoft::UInt8 hand[8]);
  void getValueBytes(Gsoft::UInt8*, Gsoft::UInt8*) const;
  void setValueBytes(Gsoft::UInt8, const Gsoft::UInt8*);

  GcDbHandle& operator=(Gsoft::UInt64);
  operator Gsoft::UInt64() const;
  GcDbHandle operator + (Gsoft::ULongPtr) const;
  void print() const;
  enum { kMaxValueBytes = 8 };
  int byte(Gsoft::UInt32 i) const;
  bool restZeros(int i) const;

private:
  Gsoft::UInt64 get64BitVal() const
  {
    return mHandle.mWord64;
  }
  void set64BitVal(Gsoft::UInt64 val)
  {
    mHandle.mWord64 = val;
  }

#pragma warning(push)
#pragma warning(disable:4201)
  union
  {
    struct
    {
      Gsoft::UInt32 mLow;
      Gsoft::UInt32 mHigh;
    };

    Gsoft::UInt64 mWord64 = 0;
  } mHandle;
#pragma warning(pop)

  friend class GcDbHandleTable;
  friend class HandleDataBase;
};

inline GcDbHandle::GcDbHandle()
{
}

inline GcDbHandle::GcDbHandle(int lo, int hi)
{
  mHandle.mLow = lo;
  mHandle.mHigh = hi;
}

inline
GcDbHandle::GcDbHandle(Gsoft::UInt64 val)
{
  this->set64BitVal(val);
}

inline GcDbHandle&
GcDbHandle::operator=(const GcDbHandle& handle)
{
  this->set64BitVal(handle.get64BitVal());

  return *this;
}

inline GcDbHandle&
GcDbHandle::operator=(Gsoft::UInt64 val)
{
  this->set64BitVal(val);
  return *this;
}

inline GcDbHandle
GcDbHandle::operator+(const GcDbHandle& handle) const
{
  GcDbHandle tHandle(*this);
  tHandle.set64BitVal(tHandle.get64BitVal() + handle.get64BitVal());
  return tHandle;
}

inline GcDbHandle
GcDbHandle::operator+(Gsoft::ULongPtr val) const
{
  GcDbHandle tHandle(*this);
  tHandle.set64BitVal(tHandle.get64BitVal() + val);
  return tHandle;
}

inline bool
GcDbHandle::operator > (const GcDbHandle& handle) const
{
  return this->get64BitVal() > handle.get64BitVal();
}

inline int
GcDbHandle::compare(const GcDbHandle& handle) const
{
  if (this->get64BitVal() > handle.get64BitVal())
    return -1;
  else if (this->get64BitVal() == handle.get64BitVal())
    return 0;
  else
    return 1;
}

inline bool
GcDbHandle::operator==(const GcDbHandle &handle) const
{
  return this->get64BitVal() == handle.get64BitVal();
}

inline bool
GcDbHandle::operator!=(const GcDbHandle &handle) const
{
  return this->get64BitVal() != handle.get64BitVal();
}

inline bool
GcDbHandle::isNull(void) const
{
  return this->get64BitVal() == 0;
}

inline void GcDbHandle::setNull(void)
{
  mHandle.mHigh = mHandle.mLow = 0;
}

inline bool
GcDbHandle::isOne(void) const
{
  return this->get64BitVal() == 1;
}

inline GcDbHandle&
GcDbHandle::operator++(void)
{
  this->set64BitVal(get64BitVal() + 1);

  return *this;
}

inline void
GcDbHandle::increment(void)
{
  this->set64BitVal(get64BitVal() + 1);
}

inline void
GcDbHandle::decrement(void)
{
  this->set64BitVal(get64BitVal() - 1);
}

inline GcDbHandle
GcDbHandle::operator++(int)
{
  GcDbHandle tempHandle = *this;
  ++(*this);
  return tempHandle;
}

inline GcDbHandle::operator Gsoft::UInt64() const
{
  return get64BitVal();
}

inline bool
GcDbHandle::operator < (const GcDbHandle& handle) const
{
  return this->get64BitVal() < handle.get64BitVal();
}

inline int GcDbHandle::byte(Gsoft::UInt32 i) const
{
  if (i >= kMaxValueBytes)
    return 0;
  return *((unsigned char *)&(mHandle.mLow) + i);
}

inline bool GcDbHandle::restZeros(int i) const
{
  if (i < 0 || i >= kMaxValueBytes)
    return false;
  if (i < 4) {
    const Gsoft::UInt32 mask = ~0U << (i << 3);
    return !(mHandle.mHigh | (mHandle.mLow & mask));
  }
  else {
    const Gsoft::UInt32 mask = ~0U << ((i - 4) << 3);
    return !(mHandle.mHigh & mask);
  }
}

inline Gsoft::UInt32  GcDbHandle::low() const
{
  return mHandle.mLow;
}
inline Gsoft::UInt32  GcDbHandle::high() const
{
  return mHandle.mHigh;
}

inline void GcDbHandle::setLow(Gsoft::UInt32 low)
{
  mHandle.mLow = low;
  return;
}
inline void GcDbHandle::setHigh(Gsoft::UInt32 high)
{
  mHandle.mHigh = high;
  return;
}

#pragma pack (pop)

#endif