

#ifndef ZC_ZCARRAY_H
#define ZC_ZCARRAY_H

#include "PAL/api/zc11_Annex_K.h"
#include <memory>     
#include <stdlib.h>
#include <algorithm>
#include <type_traits>
#include "zadesk.h"

#ifdef ASSERT
#define ZC_ARRAY_ASSERT ASSERT
#elif defined assert
#define ZC_ARRAY_ASSERT assert
#elif defined _ASSERTE
#define ZC_ARRAY_ASSERT _ASSERTE
#else
#define ZC_ARRAY_ASSERT(T)
#endif

#pragma pack (push, 8)

#pragma push_macro("new")
#pragma push_macro("delete")
#undef new
#undef delete

#define ZCARRAY_GROWTH_THRESHOLD 0x10000
#define AllocatorSelector ZcArrayItemCopierSelector  

template <class T> void ZcArrayValidateParams(bool bSameBuffer,
                                              T* pDest, int nBufLen,
                                              const T * pSource, int nCount);

template <class T> class ZcArrayMemCopyReallocator
{
public:
    static void copyItems(T* pDest, int nBufLen, const T * pSource, int nCount)
    {
        ZcArrayValidateParams<T>(false, pDest, nBufLen, pSource, nCount);
        if (nCount > 0)
           memcpy_s(pDest, nBufLen * sizeof(T), pSource, nCount * sizeof(T));
    }
    static void moveItems(T* pDest, int nBufLen, T * pSource, int nCount,
                          bool bSameBuffer)
    {
        ZcArrayValidateParams<T>(bSameBuffer, pDest, nBufLen, pSource, nCount);
        if (nCount > 0) {

            if (bSameBuffer)
                memmove_s(pDest, nBufLen * sizeof(T), pSource, nCount * sizeof(T));
            else
                memcpy_s(pDest, nBufLen * sizeof(T), pSource, nCount * sizeof(T));
        }
    }
};

template <class T> class ZcArrayObjectCopyReallocator
{
public:
    static void copyItems(T* pDest, int nBufLen, const T * pSource, int nCount)
    {
        ZcArrayValidateParams<T>(false, pDest, nBufLen, pSource, nCount);
        while (nCount--) {
            *pDest = *pSource;
            pDest++;
            pSource++;
        }
    }

    static void moveItems(T* pDest, int nBufLen, T * pSource, int nCount,
                          bool bSameBuffer)
    {
        ZcArrayValidateParams<T>(bSameBuffer, pDest, nBufLen, pSource, nCount);
        while (nCount--) {
            *pDest = std::move(*pSource);
            pDest++;
            pSource++;
        }
    }
};

template<typename T, bool>
struct ZcArrayItemCopierSelector;

template<typename T>
struct ZcArrayItemCopierSelector<T, false>
{
    typedef ZcArrayObjectCopyReallocator<T> allocator;
};

template<typename T>
struct ZcArrayItemCopierSelector<T, true>
{
    typedef ZcArrayMemCopyReallocator<T> allocator;
};

template <typename T, typename R = typename ZcArrayItemCopierSelector<T, std::is_trivial<T>::value>::allocator  > class ZcArray
{
public:
    ZcArray(int initPhysicalLength = 0, int initGrowLength = 8);
    ZcArray(const ZcArray<T,R>&);
	ZcArray(ZcArray<T,R>&&);
    ~ZcArray();

    typedef T Type;
	typedef R Allocator;

    constexpr static int maxLength() { return 0x7fffffff / sizeof(T); }

    enum { eUsesMemCopy = std::is_same<R, ZcArrayMemCopyReallocator<T>>::value };

    ZcArray<T,R>&         operator =  (const ZcArray<T,R>&);
	ZcArray<T,R>&         operator =  (ZcArray<T,R>&&);
    bool                operator == (const ZcArray<T,R>&) const;

    T&                  operator [] (int);
    const T &           operator [] (int) const;
    const T &             at          (int index) const;
          T &             at          (int index);
    ZcArray<T,R>&         setAt       (int index, const T& value);
    ZcArray<T,R>&         setAll      (const T& value);
    T&                  first       ();
    const T &           first       () const;
    T&                  last        ();
    const T &           last        () const;

    int                 append      (const T& value);
    ZcArray<T,R>&         append      (const ZcArray<T,R>& array);

    int                   append      (T&& value);
    int                   appendMove  (T& value);
    ZcArray<T,R>&         appendMove  (ZcArray<T,R>& array);

    ZcArray<T, R>&         appendRep(const T& value, int nCount);

    template<typename... TV> ZcArray<T, R> & appendList(const TV & ... args)
    {
        const auto nNumArgs = sizeof...(TV);

        const int nOldLen = this->mLogicalLen;
        this->setLogicalLength(mLogicalLen + nNumArgs);

        return this->assignHelper(nOldLen, args...);
    }


    ZcArray<T,R>&         insertAt    (int index, T&& value);
    ZcArray<T,R>&         insertAt    (int index, const T& value);
    ZcArray<T,R>&         insertAtMove(int index, T& value);

    ZcArray<T,R>&         removeAt    (int index);
    bool                  remove      (const T& value, int start = 0);
    ZcArray<T,R>&         removeFirst ();
    ZcArray<T,R>&         removeLast  ();
    ZcArray<T,R>&         removeAll   ();
    ZcArray<T,R>&         removeSubArray (int startIndex, int endIndex);

    bool                contains    (const T& value, int start = 0) const;
    bool                find        (const T& value, int& foundAt,
                                     int start = 0) const;
	int                 find        (const T& value) const;
	int                 findFrom    (const T& value, int start) const;

    int                 length      () const; 
    bool                isEmpty     () const;
    int                 logicalLength() const;
    ZcArray<T,R>&       setLogicalLength(int);
    ZcArray<T, R>&      setLogicalLength(int, const T& value);
    int                 physicalLength() const;
    ZcArray<T,R>&         setPhysicalLength(int);

    int                 growLength  () const;
    ZcArray<T,R>&         setGrowLength(int);

    ZcArray<T,R>&         reverse     ();
    ZcArray<T,R>&         swap        (int i1, int i2);

    const T*            asArrayPtr  () const;
    T*                  asArrayPtr  ();

	T* begin()				{ return mpArray; }
	T* end()				{ return mpArray + mLogicalLen; }

	const T* begin() const	{ return mpArray; }
	const T* end() const	{ return mpArray + mLogicalLen; }

private:

    ZcArray<T, R> & assignHelper(int)
    {
        return *this;
    }
    ZcArray<T, R> & assignHelper(int nIndex, const T & value)
    {
        this->setAt(nIndex, value);
        return *this;
    }
    template<typename... TV> ZcArray<T, R> & assignHelper(int nIndex, const T & value,
        const TV & ... args)
    {
        this->assignHelper(nIndex, value);
        return this->assignHelper(nIndex + 1, args...);
    }
protected:
    T*                  mpArray;
    int                 mPhysicalLen;
    int                 mLogicalLen;
    int                 mGrowLen;   

    void                insertSpace(int nIndex);
    void                copyOtherIntoThis(const ZcArray<T,R>& otherArray);
    void                moveOtherIntoThis(ZcArray<T,R>& otherArray);
    bool                isValid     (int) const;
};

#pragma pack (pop)

#ifdef GE_LOCATED_NEW

#error ZcArray.h doesn't expect GE_LOCATED_NEW!

#endif

#pragma pack (push, 8)

template <class T, class R> inline bool
ZcArray<T,R>::contains(const T& value, int start) const
{ return this->findFrom(value, start) != -1; }

template <class T, class R> inline int
ZcArray<T,R>::length() const
{ return mLogicalLen; }

template <class T, class R> inline bool
ZcArray<T,R>::isEmpty() const
{ return mLogicalLen == 0; }

template <class T, class R> inline int
ZcArray<T,R>::logicalLength() const
{ return mLogicalLen; }

template <class T, class R> inline int
ZcArray<T,R>::physicalLength() const
{ return mPhysicalLen; }

template <class T, class R> inline int
ZcArray<T,R>::growLength() const
{ return mGrowLen; }

template <class T, class R> inline const T*
ZcArray<T,R>::asArrayPtr() const
{ return mpArray; }

template <class T, class R> inline T*
ZcArray<T,R>::asArrayPtr()
{ return mpArray; }

template <class T, class R> inline bool
ZcArray<T,R>::isValid(int i) const
{ return i >= 0 && i < mLogicalLen; }

template <class T, class R> inline T&
ZcArray<T,R>::operator [] (int i)
{ ZC_ARRAY_ASSERT(this->isValid(i)); return mpArray[i]; }

template <class T, class R> inline const T&
ZcArray<T,R>::operator [] (int i) const
{ ZC_ARRAY_ASSERT(this->isValid(i)); return mpArray[i]; }

template <class T, class R> inline T&
ZcArray<T,R>::at(int i)
{ ZC_ARRAY_ASSERT(this->isValid(i)); return mpArray[i]; }

template <class T, class R> inline const T&
ZcArray<T,R>::at(int i) const
{ ZC_ARRAY_ASSERT(this->isValid(i)); return mpArray[i]; }

template <class T, class R> inline ZcArray<T,R>&
ZcArray<T,R>::setAt(int i, const T& value)
{ ZC_ARRAY_ASSERT(this->isValid(i)); mpArray[i] = value; return *this; }

template <class T, class R> inline T&
ZcArray<T,R>::first()
{ ZC_ARRAY_ASSERT(!this->isEmpty()); return mpArray[0]; }

template <class T, class R> inline const T&
ZcArray<T,R>::first() const
{ ZC_ARRAY_ASSERT(!this->isEmpty()); return mpArray[0]; }

template <class T, class R> inline T&
ZcArray<T,R>::last()
{ ZC_ARRAY_ASSERT(!this->isEmpty()); return mpArray[mLogicalLen-1]; }

template <class T, class R> inline const T&
ZcArray<T,R>::last() const
{ ZC_ARRAY_ASSERT(!this->isEmpty()); return mpArray[mLogicalLen-1]; }

template <class T, class R> inline int
ZcArray<T,R>::append(const T& value)
{ insertAt(mLogicalLen, value); return mLogicalLen-1; }

template <class T, class R> inline ZcArray<T, R> &
ZcArray<T, R>::appendRep(const T& value, int nCount)
{
    ZC_ARRAY_ASSERT(nCount > 0);
    if (nCount > 0)
        this->setLogicalLength(mLogicalLen + nCount, value);
    return *this;
}

template <class T, class R> inline int ZcArray<T,R>::append(T && value)
{
    return this->appendMove(value);
}
template <class T, class R> inline int
ZcArray<T,R>::appendMove(T& value)
{
    this->insertAtMove(mLogicalLen, value);
    return this->mLogicalLen - 1;
}

template <class T, class R> inline ZcArray<T,R>&
ZcArray<T,R>::removeFirst()
{ ZC_ARRAY_ASSERT(!isEmpty()); return removeAt(0); }

template <class T, class R> inline ZcArray<T,R>&
ZcArray<T,R>::removeLast()
{
    ZC_ARRAY_ASSERT(!isEmpty());
    if (!isEmpty())
        mLogicalLen--;
    return *this;
}

template <class T, class R> inline ZcArray<T,R>&
ZcArray<T,R>::removeAll()
{
    this->setLogicalLength(0);
    return *this; 
}

template <class T, class R> inline ZcArray<T,R>&
ZcArray<T,R>::setGrowLength(int glen)
{
    ZC_ARRAY_ASSERT(glen > 0);
    ZC_ARRAY_ASSERT(glen <= maxLength());
    mGrowLen = glen;
    return *this;
}

template < class T, class R > inline
ZcArray< T, R > ::ZcArray(int physicalLength, int growLength)
: mpArray(nullptr),
  mPhysicalLen(0),
  mLogicalLen(0),
  mGrowLen(growLength)
{
    static_assert(std::is_trivial<T>::value || !std::is_pod<T>::value, "is_pod but not is_trivial?");
    ZC_ARRAY_ASSERT(mGrowLen > 0);
    ZC_ARRAY_ASSERT(mGrowLen <= maxLength());
    ZC_ARRAY_ASSERT(physicalLength >= 0);
    ZC_ARRAY_ASSERT(physicalLength <= maxLength());
    if (physicalLength > 0)
	{
        this->setPhysicalLength(physicalLength);
    }
}

template <class T, class R> inline
ZcArray<T,R>::ZcArray(const ZcArray<T,R>& src)
: mpArray(nullptr),
  mPhysicalLen(0),
  mLogicalLen(0),
  mGrowLen(src.mGrowLen)
{
    this->copyOtherIntoThis(src);
}

template <class T, class R> inline
ZcArray<T,R>::ZcArray(ZcArray<T,R>&& src)
: mpArray(nullptr),
  mPhysicalLen(0),
  mLogicalLen(0),
 mGrowLen(src.mGrowLen)
{
    this->moveOtherIntoThis(src);
}

template <class T, class R> inline
ZcArray<T,R>::~ZcArray()
{
    if (mPhysicalLen > 0)
        this->setPhysicalLength(0);
}

template <class T, class R> inline ZcArray<T,R>&
ZcArray<T,R>::operator = (const ZcArray<T,R>& src)
{
    if (this != &src)
        this->copyOtherIntoThis(src);
                    return *this;
}

template <class T, class R> inline ZcArray<T,R>&
ZcArray<T,R>::operator = (ZcArray<T,R>&& src)
{
    if (this != &src) {
        this->setPhysicalLength(0);
        this->moveOtherIntoThis(src);
    }
    return *this;
}

template <class T, class R> bool
ZcArray<T,R>::operator == (const ZcArray<T,R>& cpr) const
{
    if (mLogicalLen == cpr.mLogicalLen) {
        for (int i = 0; i < mLogicalLen; i++)
            if (mpArray[i] != cpr.mpArray[i])
                return false;
        return true;
    }
    return false;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::setAll(const T& value)
{
    for (int i = 0; i < mLogicalLen; i++) {
        mpArray[i] = value;
    }
    return *this;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::append(const ZcArray<T,R>& otherArray)
{
    const int nOrigLogLen = this->mLogicalLen;

    const int nOrigOtherLogLen = otherArray.mLogicalLen;
    this->setLogicalLength(nOrigLogLen + nOrigOtherLogLen);

    R::copyItems(mpArray + nOrigLogLen, mLogicalLen - nOrigLogLen,
                 otherArray.mpArray, nOrigOtherLogLen);

        return *this;
}

template <class T, class R> inline void
ZcArray<T,R>::copyOtherIntoThis(const ZcArray<T,R>& otherArray)
{
    ZC_ARRAY_ASSERT(this != &otherArray);

    this->setLogicalLength(otherArray.mLogicalLen);

    R::copyItems(mpArray, mPhysicalLen, otherArray.mpArray, mLogicalLen);
}

template <class T, class R> inline void
ZcArray<T,R>::moveOtherIntoThis(ZcArray<T,R>& otherArray)
{
    ZC_ARRAY_ASSERT(this != &otherArray);
    ZC_ARRAY_ASSERT(this->mpArray == nullptr);
    this->mpArray = otherArray.mpArray;
    this->mLogicalLen = otherArray.mLogicalLen;
    this->mPhysicalLen = otherArray.mPhysicalLen;
    otherArray.mpArray = nullptr;
    otherArray.mLogicalLen = 0;
    otherArray.mPhysicalLen = 0;
    otherArray.mGrowLen = 8;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::appendMove(ZcArray<T,R>& otherArray)
{
    ZC_ARRAY_ASSERT(this != &otherArray);
    if (this != &otherArray) {
        if (this->mLogicalLen == 0) {

            this->setPhysicalLength(0);
            this->moveOtherIntoThis(otherArray);
        }
        else {
            const int nOrigLogLen = this->mLogicalLen;

            this->setLogicalLength(nOrigLogLen + otherArray.mLogicalLen);

            R::moveItems(mpArray + nOrigLogLen, mLogicalLen - nOrigLogLen,
                 otherArray.mpArray, otherArray.mLogicalLen, false);
        }
    }
    return *this;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::insertAt(int index, const T& value)
{
    ZC_ARRAY_ASSERT(index >= 0);
    ZC_ARRAY_ASSERT(index <= mLogicalLen);
    ZC_ARRAY_ASSERT(mLogicalLen <= mPhysicalLen);
    if (index < 0 || index > mLogicalLen)
        return *this;
    if (index == mLogicalLen && mLogicalLen < mPhysicalLen) {
        mpArray[index] = value;
        mLogicalLen++;
    }
    else {

        T tmp(value);
        this->insertSpace(index);
        mpArray[index] = std::move(tmp);
    }
        return *this;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::insertAt(int index, T && value)
{ 
	return this->insertAtMove(index, value);
}
template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::insertAtMove(int index, T& value)
{
    ZC_ARRAY_ASSERT(index >= 0);
    ZC_ARRAY_ASSERT(index <= mLogicalLen);
    ZC_ARRAY_ASSERT(mLogicalLen <= mPhysicalLen);
    if (index < 0 || index > mLogicalLen)
        return *this;

    if (index == mLogicalLen && mLogicalLen < mPhysicalLen) {
        mpArray[index] = std::move(value);
        mLogicalLen++;
    }
    else {

        T tmp(std::move(value));
        this->insertSpace(index);
        mpArray[index] = std::move(tmp);
    }
    return *this;
}

template <class T, class R> void ZcArray<T,R>::insertSpace(int nIndex)
{
    this->setLogicalLength(mLogicalLen + 1);

    if (nIndex < mLogicalLen - 1) {
        ZC_ARRAY_ASSERT(mLogicalLen >= 0);

        T* p = mpArray + mLogicalLen - 1;
        T* const pSpace = mpArray + nIndex;
        ZC_ARRAY_ASSERT(p >= pSpace);
        do {

            *p = std::move(*(p-1));
        } while (--p != pSpace);
    }
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::removeAt(int index)
{
    ZC_ARRAY_ASSERT(isValid(index));
	ZC_ARRAY_ASSERT(mLogicalLen <= mPhysicalLen);
	ZC_ARRAY_ASSERT(!isEmpty());
	if (isEmpty() || !isValid(index))
		return *this;
    if (index < mLogicalLen - 1) {
        R::moveItems(mpArray + index, mPhysicalLen - index,
                     mpArray + index + 1, mLogicalLen - 1 - index,
                     true);
    }
    mLogicalLen--;
    return *this;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::removeSubArray(int startIndex, int endIndex)
{
    ZC_ARRAY_ASSERT(isValid(startIndex));
    ZC_ARRAY_ASSERT(startIndex <= endIndex);

    if ( endIndex >= mLogicalLen - 1) {
        mLogicalLen = startIndex;
        return *this;
    }

	const int kNumToRemove = endIndex + 1 - startIndex;
	const int kNumToShift = mLogicalLen - 1 - endIndex;
	ZC_ARRAY_ASSERT(kNumToShift >= 1);
    R::moveItems(mpArray + startIndex, mPhysicalLen - startIndex,
                 mpArray + endIndex + 1, kNumToShift,
                 true);
	mLogicalLen -= kNumToRemove;
    return *this;
}

template <class T, class R> bool
ZcArray<T,R>::find(const T& value, int& index, int start) const
{
    const int nFoundAt = this->findFrom(value, start);
    if (nFoundAt == -1)
        return false;
    index = nFoundAt;
    return true;
}

template <class T, class R> int
ZcArray<T,R>::find(const T& value) const
{
	return this->findFrom(value, 0);   
}

template <class T, class R> int
ZcArray<T,R>::findFrom(const T& value, int start) const
{
	ZC_ARRAY_ASSERT(start >= 0);
	if (start < 0)
		return -1;
	for (int i = start; i < this->mLogicalLen; i++) {
		if (mpArray[i] == value)
			return i;
	}
	return -1;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::setLogicalLength(int n)
{
    ZC_ARRAY_ASSERT(n >= 0);
	if (n < 0)
		n = 0;
    ZC_ARRAY_ASSERT(n < maxLength());
    if (n > mPhysicalLen) {

        const int growth = (mPhysicalLen * sizeof(T)) < ZCARRAY_GROWTH_THRESHOLD ?
            mPhysicalLen : ZCARRAY_GROWTH_THRESHOLD / sizeof(T);

        int minSize = mPhysicalLen + std::max<int>(growth, mGrowLen);
        if ( n > minSize)
            minSize = n;
        setPhysicalLength(minSize);
    }
    mLogicalLen = n;
	ZC_ARRAY_ASSERT(mLogicalLen <= mPhysicalLen);
    return *this;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T, R>::setLogicalLength(int n, const T& value)
{
    const int nOldLen = this->mLogicalLen;
    this->setLogicalLength(n);
    for (int i = nOldLen; i < this->mLogicalLen; i++)
        this->mpArray[i] = value;
    return *this;
}

template <class T, class R> ZcArray<T, R>&
ZcArray<T,R>::setPhysicalLength(int n)
{
    ZC_ARRAY_ASSERT(mPhysicalLen >= mLogicalLen);
    ZC_ARRAY_ASSERT((mPhysicalLen == 0) == (mpArray == nullptr));
    ZC_ARRAY_ASSERT(n >= 0);
    ZC_ARRAY_ASSERT(n < maxLength());
    if (n == mPhysicalLen || n < 0)
        return *this;

    T* pOldArray = mpArray;
    const int nOldLen = mPhysicalLen;

    mPhysicalLen = n;
    mpArray = nullptr;

    if (mPhysicalLen < mLogicalLen)
        mLogicalLen = mPhysicalLen;

    if (mPhysicalLen != 0) {

        mpArray = static_cast<T *>(::operator new(sizeof(T) * mPhysicalLen));
        ZC_ARRAY_ASSERT(mpArray != nullptr);
        if (mpArray == nullptr) {

            mPhysicalLen = 0;
            mLogicalLen = 0;
        }
        else {

            T *pNewBuf = mpArray;
            for (int i = 0; i < mPhysicalLen; i++, pNewBuf++)
                ::new(pNewBuf) T;

            R::moveItems(mpArray, mPhysicalLen, pOldArray, mLogicalLen,
                         false);
        }
    }

    for (int i = 0; i < nOldLen; i++)
        (pOldArray + i)->~T();

    ::operator delete(static_cast<void *>(pOldArray));

    return *this;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::reverse()
{
    for (int i = 0; i < mLogicalLen/2; i++) {

        T tmp = std::move(mpArray[i]);
        mpArray[i] = std::move(mpArray[mLogicalLen - 1 - i]);
        mpArray[mLogicalLen - 1 - i] = std::move(tmp);
    }
    return *this;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::swap(int i1, int i2)
{
    ZC_ARRAY_ASSERT(isValid(i1));
    ZC_ARRAY_ASSERT(isValid(i2));

    if (i1 == i2) return *this;

    T tmp = std::move(mpArray[i1]);
    mpArray[i1] = std::move(mpArray[i2]);
    mpArray[i2] = std::move(tmp);
    return *this;
}

template <class T, class R> bool
ZcArray<T,R>::remove(const T& value, int start)
{
    const int i = this->findFrom(value, start);
    if (i == -1)
        return false;
    this->removeAt(i);
    return true;
}

template <class T> void ZcArrayValidateParams(bool bSameBuffer,
                                              T* pDest, int nBufLen,
                                              const T * pSource, int nCount)
{
    ZSOFT_UNREFED_PARAM(pDest);
    ZSOFT_UNREFED_PARAM(nBufLen);
    ZSOFT_UNREFED_PARAM(pSource);
    ZSOFT_UNREFED_PARAM(nCount);
    ZC_ARRAY_ASSERT(nCount >= 0);
    ZC_ARRAY_ASSERT(nCount <= nBufLen);
    ZC_ARRAY_ASSERT(nCount <= ZcArray<T>::maxLength());
    if (bSameBuffer) {
        ZC_ARRAY_ASSERT(pSource > pDest);
    }
    else {
        ZC_ARRAY_ASSERT(pSource >= pDest + nBufLen || (pDest >= pSource + nCount));
    }
}

class ZcArrayUtil
{
public:

    template<typename T> static
    ZcArray<T *> & deletePtrs(ZcArray<T *> &arr, bool bFreeBuffer = false,
        bool bUseArrayDelete = false)
    {
        for (T * p : arr)
            if (bUseArrayDelete)
                delete[] p;
            else
                delete p;
        return bFreeBuffer ? arr.setPhysicalLength(0) : arr.setLogicalLength(0);
    }

    template<typename T> static
        ZcArray<void *> & deleteVoidPtrs(ZcArray<void *> &arr, bool bFreeBuffer = false)
    {
        for (void * p : arr) {
            T * pT = static_cast<T *>(p);
            delete pT;
        }
        return bFreeBuffer ? arr.setPhysicalLength(0) : arr.setLogicalLength(0);
    }
};

template<> ZcArray<void *> & ZcArrayUtil::deletePtrs<void>(ZcArray<void *> &arr,
    bool bFreeBuffer, bool bUseArrayDelete) = delete;



#include "zacarrayhelper.h"

#ifdef _Zc_String_h_
typedef
ZcArray< ZcString, ZcArrayObjectCopyReallocator< ZcString > > ZcStringArray;
#endif

#pragma pop_macro("new")
#pragma pop_macro("delete")
#pragma pack (pop)
#endif
