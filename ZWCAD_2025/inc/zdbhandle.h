

#ifndef ZD_DBHANDLE_H
#define ZD_DBHANDLE_H 1

#include "zadesk.h"
#include <stddef.h>
#include"zAcDbCore2dDefs.h"

#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbHandle
{
public:

    ZcDbHandle();                
    ZcDbHandle(int lo, int hi);  
    ZcDbHandle(const ZTCHAR*);
    ZcDbHandle(ZSoft::UInt64);

    ZcDbHandle& operator=(const ZcDbHandle&);

    ZcDbHandle& operator=(const ZTCHAR*);
    bool getIntoAsciiBuffer(ZTCHAR* pBuf, size_t nBufLen) const;
	enum {kStrSiz = 17};

	template<size_t nBufLen> inline bool getIntoAsciiBuffer(wchar_t (& buf)[nBufLen]) const
	{
		return this->getIntoAsciiBuffer(buf, nBufLen);
	}

    bool operator == (const ZcDbHandle&) const;
    bool operator != (const ZcDbHandle&) const;

    bool           isNull() const;
    void           setNull();

    ZSoft::UInt32  low() const;
    ZSoft::UInt32  high() const;
    void           setLow(ZSoft::UInt32 low);
    void           setHigh(ZSoft::UInt32 high);

    bool           isOne(void) const;

    ZcDbHandle& operator++();
    ZcDbHandle operator++(int);
    void increment(void);
    void decrement(void);
    ZcDbHandle operator + (const ZcDbHandle&) const;
    ZcDbHandle slowOperatorPlus(const ZcDbHandle&) const;
    ZcDbHandle& operator += (const ZcDbHandle&);
    ZcDbHandle operator - (const ZcDbHandle&) const;
    ZcDbHandle& operator -= (const ZcDbHandle&);
    bool operator > (const ZcDbHandle&) const;
    bool operator >= (const ZcDbHandle&) const;
    bool operator < (const ZcDbHandle&) const;
    bool operator <= (const ZcDbHandle&) const;
    int compare(const ZcDbHandle&) const;
    void copyToOldType(ZSoft::UInt8 hand[8]) const;
    void copyFromOldType(const ZSoft::UInt8 hand[8]);
    void getValueBytes(ZSoft::UInt8*, ZSoft::UInt8*) const;
    void setValueBytes(ZSoft::UInt8, const ZSoft::UInt8*);	
	ZcDbHandle& operator=(ZSoft::UInt64);
	operator ZSoft::UInt64() const;
    ZcDbHandle operator + (ZSoft::ULongPtr) const;
    void print() const;
    enum { kMaxValueBytes = 8 };
    int byte(ZSoft::UInt32 i) const;
    bool restZeros(int i) const;
private:
    ZSoft::UInt64  get64BitVal() const
          { return mHandle.mWord64; }
    void set64BitVal(ZSoft::UInt64 val)
          { mHandle.mWord64 = val; }

#pragma warning(push)
#pragma warning(disable:4201)
	union
	{
		struct
		{
			ZSoft::UInt32 mLow;
			ZSoft::UInt32 mHigh;
		};

		ZSoft::UInt64 mWord64 = 0;
	} mHandle;
#pragma warning(pop)

    friend class ZcDbHandleTable;
    friend class HandleDataBase;
};

inline ZcDbHandle::ZcDbHandle()
{
}

inline ZcDbHandle::ZcDbHandle(int lo, int hi)
{
	mHandle.mLow = lo;
	mHandle.mHigh = hi;
}

inline
ZcDbHandle::ZcDbHandle(ZSoft::UInt64 val)
{
    this->set64BitVal(val);
}

inline ZcDbHandle&
ZcDbHandle::operator=(const ZcDbHandle& handle)
{
    this->set64BitVal(handle.get64BitVal());

    return *this;
}

inline ZcDbHandle&
ZcDbHandle::operator=(ZSoft::UInt64 val)
{
	this->set64BitVal(val);
	return *this; 
}

inline ZcDbHandle
ZcDbHandle::operator+(const ZcDbHandle& handle) const
{
    ZcDbHandle tHandle(*this);
    tHandle.set64BitVal(tHandle.get64BitVal() + handle.get64BitVal());
    return tHandle;
}

inline ZcDbHandle
ZcDbHandle::operator+(ZSoft::ULongPtr val) const
{
    ZcDbHandle tHandle(*this);
    tHandle.set64BitVal(tHandle.get64BitVal() + val);
    return tHandle;
}

inline bool
ZcDbHandle::operator > (const ZcDbHandle& handle) const
{
    return this->get64BitVal() > handle.get64BitVal();
}

inline int
ZcDbHandle::compare(const ZcDbHandle& handle) const
{
    if (this->get64BitVal() > handle.get64BitVal())
        return -1;
    else if (this->get64BitVal() == handle.get64BitVal())
        return 0;
    else
        return 1;
}

inline bool
ZcDbHandle::operator==(const ZcDbHandle &handle) const
{
    return this->get64BitVal() == handle.get64BitVal();
}

inline bool
ZcDbHandle::operator!=(const ZcDbHandle &handle) const
{
    return this->get64BitVal() != handle.get64BitVal();
}

inline bool
ZcDbHandle::isNull(void) const
{
    return this->get64BitVal() == 0;
}

inline void ZcDbHandle::setNull(void)
{
   mHandle.mHigh = mHandle.mLow = 0;
}

inline bool
ZcDbHandle::isOne(void) const
{
    return this->get64BitVal() == 1;
}

inline ZcDbHandle&
ZcDbHandle::operator++(void)          
{
	this->set64BitVal(get64BitVal() + 1);
    return *this;
}

inline void
ZcDbHandle::increment(void)          
{
	this->set64BitVal(get64BitVal() + 1);
}

inline void
ZcDbHandle::decrement(void)          
{
	this->set64BitVal(get64BitVal() - 1);
}

inline ZcDbHandle
ZcDbHandle::operator++(int)           
{
    ZcDbHandle tempHandle = *this;
    ++(*this);
    return tempHandle;
}

inline ZcDbHandle::operator ZSoft::UInt64() const
{
	return get64BitVal();
}

inline bool
ZcDbHandle::operator < (const ZcDbHandle& handle) const
{
    return this->get64BitVal() < handle.get64BitVal();
}

inline int ZcDbHandle::byte(ZSoft::UInt32 i) const
{
	if (i >= kMaxValueBytes)
		return 0;
    return *((unsigned char *)&(mHandle.mLow) + i);
}

inline bool ZcDbHandle::restZeros(int i) const
{
	if (i < 0 || i >= kMaxValueBytes)
		return false;
    if (i < 4) {
        const ZSoft::UInt32 mask = ~0U << (i << 3);
        return !(mHandle.mHigh | (mHandle.mLow & mask));
    } else {
       const ZSoft::UInt32 mask = ~0U << ((i - 4) << 3);
        return !(mHandle.mHigh & mask);
    }
}

inline ZSoft::UInt32  ZcDbHandle::low() const
{
    return mHandle.mLow;
}
inline ZSoft::UInt32  ZcDbHandle::high() const
{
    return mHandle.mHigh;
}
 
inline void ZcDbHandle::setLow(ZSoft::UInt32 low)
{
    mHandle.mLow = low;
    return;
}
inline void ZcDbHandle::setHigh(ZSoft::UInt32 high)
{
   mHandle.mHigh = high;
    return;
}

#pragma pack (pop)

#endif
