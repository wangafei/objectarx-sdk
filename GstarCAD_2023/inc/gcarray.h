/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GCARRAY_H
#define GC_GCARRAY_H
#include "PAL/api/c11_Annex_K.h"
#include <memory>
#include <stdlib.h>
#include <algorithm>
#include <type_traits>
#include "gsoft.h"

#ifdef ASSERT
#define GC_ARRAY_ASSERT ASSERT
#elif defined assert
#define GC_ARRAY_ASSERT assert
#elif defined _ASSERTE
#define GC_ARRAY_ASSERT _ASSERTE
#else
#define GC_ARRAY_ASSERT(T)
#endif

#pragma pack (push, 8)
#pragma push_macro("new")
#pragma push_macro("delete")
#undef new
#undef delete

#define GCARRAY_GROWTH_THRESHOLD 0x10000

template <class T> void GcArrayValidateParams(bool bSameBuffer,
  T* pDest, size_t nBufLen,
  const T * pSource, size_t nCount)
{
  GSOFT_UNREFED_PARAM(pDest);
  GSOFT_UNREFED_PARAM(nBufLen);
  GSOFT_UNREFED_PARAM(pSource);
  GSOFT_UNREFED_PARAM(nCount);
  GC_ARRAY_ASSERT(nCount >= 0);
  GC_ARRAY_ASSERT(nCount <= nBufLen);
  GC_ARRAY_ASSERT(nCount < 0x40000000);
  if (bSameBuffer) {
    GC_ARRAY_ASSERT(pSource > pDest);
  }
  else {
    GC_ARRAY_ASSERT(pSource >= pDest + nBufLen || (pDest >= pSource + nCount));
  }
}

template <class T> class GcArrayMemCopyReallocator
{
public:
  static void copyItems(T* pDest, size_t nBufLen, const T * pSource, size_t nCount)
  {
    GcArrayValidateParams<T>(false, pDest, nBufLen, pSource, nCount);
    if (nCount > 0)
      memcpy_s(pDest, nBufLen * sizeof(T), pSource, nCount * sizeof(T));
  }
  static void moveItems(T* pDest, size_t nBufLen, T * pSource, size_t nCount,
    bool bSameBuffer)
  {
    GcArrayValidateParams<T>(bSameBuffer, pDest, nBufLen, pSource, nCount);
    if (nCount > 0) {
      if (bSameBuffer)
        memmove_s(pDest, nBufLen * sizeof(T), pSource, nCount * sizeof(T));
      else
        memcpy_s(pDest, nBufLen * sizeof(T), pSource, nCount * sizeof(T));
    }
  }
};

template <class T> class GcArrayObjectCopyReallocator
{
public:
  static void copyItems(T* pDest, size_t nBufLen, const T * pSource, size_t nCount)
  {
    GcArrayValidateParams<T>(false, pDest, nBufLen, pSource, nCount);
    while (nCount--) {
      *pDest = *pSource;
      pDest++;
      pSource++;
    }
  }

  static void moveItems(T* pDest, size_t nBufLen, T * pSource, size_t nCount,
    bool bSameBuffer)
  {
    GcArrayValidateParams<T>(bSameBuffer, pDest, nBufLen, pSource, nCount);
    while (nCount--) {
      *pDest = std::move(*pSource);
      pDest++;
      pSource++;
    }
  }
};

template<typename T, bool>
struct GcArrayItemCopierSelector;

template<typename T>
struct GcArrayItemCopierSelector<T, false>
{
  typedef GcArrayObjectCopyReallocator<T> allocator;
};

template<typename T>
struct GcArrayItemCopierSelector<T, true>
{
  typedef GcArrayMemCopyReallocator<T> allocator;
};

template <typename T, typename R = typename GcArrayItemCopierSelector<T, std::is_trivial<T>::value>::allocator  > class GcArray
{
public:
  GcArray(int initPhysicalLength = 0, int initGrowLength = 8);
  GcArray(const GcArray<T, R>&);
  GcArray(GcArray<T, R>&&);
  ~GcArray();

  typedef T Type;
  typedef R Allocator;

  enum { eUsesMemCopy = std::is_same<R, GcArrayMemCopyReallocator<T> >::value };

  GcArray<T, R>&      operator =  (const GcArray<T, R>&);
  GcArray<T, R>&      operator =  (GcArray<T, R>&&);
  bool                operator == (const GcArray<T, R>&) const;

  T&                  operator [] (int);
  const T &           operator [] (int) const;

  const T &           at(int index) const;
  T &                 at(int index);
  GcArray<T, R>&      setAt(int index, const T& value);
  GcArray<T, R>&      setAll(const T& value);
  T&                  first();
  const T &           first() const;
  T&                  last();
  const T &           last() const;

  int                 append(const T& value);
  GcArray<T, R>&      append(const GcArray<T, R>& array);
  GcArray<T, R>&      insertAt(int index, const T& value);

  int                 append(T&& value);
  int                 appendMove(T& value);
  GcArray<T, R>&      appendMove(GcArray<T, R>& array);
  GcArray<T, R>&      insertAt(int index, T&& value);
  GcArray<T, R>&      insertAtMove(int index, T& value);

  GcArray<T, R>&      removeAt(int index);
  bool                remove(const T& value, int start = 0);
  GcArray<T, R>&      removeFirst();
  GcArray<T, R>&      removeLast();
  GcArray<T, R>&      removeAll();
  GcArray<T, R>&      removeSubArray(int startIndex, int endIndex);

  bool                contains(const T& value, int start = 0) const;
  bool                find(const T& value, int& foundAt,
    int start = 0) const;
  int                 find(const T& value) const;
  int                 findFrom(const T& value, int start) const;

  int                 length() const;
  bool                isEmpty() const;
  int                 logicalLength() const;
  GcArray<T, R>&      setLogicalLength(int);
  int                 physicalLength() const;
  GcArray<T, R>&      setPhysicalLength(int);

  int                 growLength() const;
  GcArray<T, R>&      setGrowLength(int);

  GcArray<T, R>&      reverse();
  GcArray<T, R>&      swap(int i1, int i2);

  const T*            asArrayPtr() const;
  T*                  asArrayPtr();

  T *       begin() { return mpArray; }
  T *       end() { return mpArray + mLogicalLen; }

  const T * begin() const { return mpArray; }
  const T * end() const { return mpArray + mLogicalLen; }

protected:
  T*                  mpArray;
  int                 mPhysicalLen;
  int                 mLogicalLen;
  int                 mGrowLen;

  void                insertSpace(int nIndex);
  void                copyOtherIntoThis(const GcArray<T, R>& otherArray);
  void                moveOtherIntoThis(GcArray<T, R>& otherArray);
  bool                isValid(int) const;
};

#pragma pack (pop)

#ifdef GE_LOCATED_NEW
#error gcarray.h doesn't expect GE_LOCATED_NEW!
#endif

#pragma pack (push, 8)

template <class T, class R> inline bool
GcArray<T, R>::contains(const T& value, int start) const
{
  return this->findFrom(value, start) != -1;
}

template <class T, class R> inline int
GcArray<T, R>::length() const
{
  return mLogicalLen;
}

template <class T, class R> inline bool
GcArray<T, R>::isEmpty() const
{
  return mLogicalLen == 0;
}

template <class T, class R> inline int
GcArray<T, R>::logicalLength() const
{
  return mLogicalLen;
}

template <class T, class R> inline int
GcArray<T, R>::physicalLength() const
{
  return mPhysicalLen;
}

template <class T, class R> inline int
GcArray<T, R>::growLength() const
{
  return mGrowLen;
}

template <class T, class R> inline const T*
GcArray<T, R>::asArrayPtr() const
{
  return mpArray;
}

template <class T, class R> inline T*
GcArray<T, R>::asArrayPtr()
{
  return mpArray;
}

template <class T, class R> inline bool
GcArray<T, R>::isValid(int i) const
{
  return i >= 0 && i < mLogicalLen;
}

template <class T, class R> inline T&
GcArray<T, R>::operator [] (int i)
{
  GC_ARRAY_ASSERT(this->isValid(i)); return mpArray[i];
}

template <class T, class R> inline const T&
GcArray<T, R>::operator [] (int i) const
{
  GC_ARRAY_ASSERT(this->isValid(i)); return mpArray[i];
}

template <class T, class R> inline T&
GcArray<T, R>::at(int i)
{
  GC_ARRAY_ASSERT(this->isValid(i)); return mpArray[i];
}

template <class T, class R> inline const T&
GcArray<T, R>::at(int i) const
{
  GC_ARRAY_ASSERT(this->isValid(i)); return mpArray[i];
}

template <class T, class R> inline GcArray<T, R>&
GcArray<T, R>::setAt(int i, const T& value)
{
  GC_ARRAY_ASSERT(this->isValid(i)); mpArray[i] = value; return *this;
}

template <class T, class R> inline T&
GcArray<T, R>::first()
{
  GC_ARRAY_ASSERT(!this->isEmpty()); return mpArray[0];
}

template <class T, class R> inline const T&
GcArray<T, R>::first() const
{
  GC_ARRAY_ASSERT(!this->isEmpty()); return mpArray[0];
}

template <class T, class R> inline T&
GcArray<T, R>::last()
{
  GC_ARRAY_ASSERT(!this->isEmpty()); return mpArray[mLogicalLen - 1];
}

template <class T, class R> inline const T&
GcArray<T, R>::last() const
{
  GC_ARRAY_ASSERT(!this->isEmpty()); return mpArray[mLogicalLen - 1];
}

template <class T, class R> inline int
GcArray<T, R>::append(const T& value)
{
  insertAt(mLogicalLen, value); return mLogicalLen - 1;
}

template <class T, class R> inline int GcArray<T, R>::append(T && value)
{
  return this->appendMove(value);
}

template <class T, class R> inline int
GcArray<T, R>::appendMove(T& value)
{
  this->insertAtMove(mLogicalLen, value);
  return this->mLogicalLen - 1;
}

template <class T, class R> inline GcArray<T, R>&
GcArray<T, R>::removeFirst()
{
  GC_ARRAY_ASSERT(!isEmpty()); return removeAt(0);
}

template <class T, class R> inline GcArray<T, R>&
GcArray<T, R>::removeLast()
{
  GC_ARRAY_ASSERT(!isEmpty());
  if (!isEmpty())
    mLogicalLen--;
  return *this;
}

template <class T, class R> inline GcArray<T, R>&
GcArray<T, R>::removeAll()
{
  this->setLogicalLength(0);
  return *this;
}

template <class T, class R> inline GcArray<T, R>&
GcArray<T, R>::setGrowLength(int glen)
{
  GC_ARRAY_ASSERT(glen > 0); mGrowLen = glen; return *this;
}

template < class T, class R > inline
GcArray< T, R > ::GcArray(int physicalLength, int growLength)
  : mpArray(nullptr),
  mPhysicalLen(0),
  mLogicalLen(0),
  mGrowLen(growLength)
{
  static_assert(std::is_trivial<T>::value || !std::is_pod<T>::value, "is_pod but not is_trivial?");
  GC_ARRAY_ASSERT(mGrowLen > 0);
  GC_ARRAY_ASSERT(physicalLength >= 0);
  if (physicalLength > 0)
    this->setPhysicalLength(physicalLength);
}

template <class T, class R> inline
GcArray<T, R>::GcArray(const GcArray<T, R>& src)
  : mpArray(nullptr),
  mPhysicalLen(0),
  mLogicalLen(0),
  mGrowLen(src.mGrowLen)
{
  this->copyOtherIntoThis(src);
}

template <class T, class R> inline
GcArray<T, R>::GcArray(GcArray<T, R>&& src)
  : mpArray(nullptr),
  mPhysicalLen(0),
  mLogicalLen(0),
  mGrowLen(src.mGrowLen)
{
  this->moveOtherIntoThis(src);
}

template <class T, class R> inline
GcArray<T, R>::~GcArray()
{
  this->setPhysicalLength(0);
}

template <class T, class R> inline GcArray<T, R>&
GcArray<T, R>::operator = (const GcArray<T, R>& src)
{
  if (this != &src)
    this->copyOtherIntoThis(src);
  return *this;
}

template <class T, class R> inline GcArray<T, R>&
GcArray<T, R>::operator = (GcArray<T, R>&& src)
{
  if (this != &src) {
    this->setPhysicalLength(0);
    this->moveOtherIntoThis(src);
  }
  return *this;
}

template <class T, class R> bool
GcArray<T, R>::operator == (const GcArray<T, R>& cpr) const
{
  if (mLogicalLen == cpr.mLogicalLen) {
    for (int i = 0; i < mLogicalLen; i++)
      if (mpArray[i] != cpr.mpArray[i])
        return false;
    return true;
  }
  return false;
}

template <class T, class R> GcArray<T, R>&
GcArray<T, R>::setAll(const T& value)
{
  for (int i = 0; i < mLogicalLen; i++) {
    mpArray[i] = value;
  }
  return *this;
}

template <class T, class R> GcArray<T, R>&
GcArray<T, R>::append(const GcArray<T, R>& otherArray)
{
  const int nOrigLogLen = this->mLogicalLen;
  const int nOrigOtherLogLen = otherArray.mLogicalLen;
  this->setLogicalLength(nOrigLogLen + nOrigOtherLogLen);

  R::copyItems(mpArray + nOrigLogLen, mLogicalLen - nOrigLogLen,
    otherArray.mpArray, nOrigOtherLogLen);

  return *this;
}

template <class T, class R> inline void
GcArray<T, R>::copyOtherIntoThis(const GcArray<T, R>& otherArray)
{
  GC_ARRAY_ASSERT(this != &otherArray);
  this->setLogicalLength(otherArray.mLogicalLen);
  R::copyItems(mpArray, mPhysicalLen, otherArray.mpArray, mLogicalLen);
}

template <class T, class R> inline void
GcArray<T, R>::moveOtherIntoThis(GcArray<T, R>& otherArray)
{
  GC_ARRAY_ASSERT(this != &otherArray);
  GC_ARRAY_ASSERT(this->mpArray == nullptr);
  this->mpArray = otherArray.mpArray;
  this->mLogicalLen = otherArray.mLogicalLen;
  this->mPhysicalLen = otherArray.mPhysicalLen;
  otherArray.mpArray = nullptr;
  otherArray.mLogicalLen = 0;
  otherArray.mPhysicalLen = 0;
  otherArray.mGrowLen = 8;
}

template <class T, class R> GcArray<T, R>&
GcArray<T, R>::appendMove(GcArray<T, R>& otherArray)
{
  GC_ARRAY_ASSERT(this != &otherArray);
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

template <class T, class R> GcArray<T, R>&
GcArray<T, R>::insertAt(int index, const T& value)
{
  GC_ARRAY_ASSERT(index >= 0);
  GC_ARRAY_ASSERT(index <= mLogicalLen);
  GC_ARRAY_ASSERT(mLogicalLen <= mPhysicalLen);
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

template <class T, class R> GcArray<T, R>&
GcArray<T, R>::insertAt(int index, T && value)
{
  return this->insertAtMove(index, value);
}

template <class T, class R> GcArray<T, R>&
GcArray<T, R>::insertAtMove(int index, T& value)
{
  GC_ARRAY_ASSERT(index >= 0);
  GC_ARRAY_ASSERT(index <= mLogicalLen);
  GC_ARRAY_ASSERT(mLogicalLen <= mPhysicalLen);
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

template <class T, class R> void GcArray<T, R>::insertSpace(int nIndex)
{
  this->setLogicalLength(mLogicalLen + 1);

  if (nIndex < mLogicalLen - 1) {
    GC_ARRAY_ASSERT(mLogicalLen >= 0);
    T* p = mpArray + mLogicalLen - 1;
    T* const pSpace = mpArray + nIndex;
    GC_ARRAY_ASSERT(p >= pSpace);
    do {
      *p = std::move(*(p - 1));
    } while (--p != pSpace);
  }
}

template <class T, class R> GcArray<T, R>&
GcArray<T, R>::removeAt(int index)
{
  GC_ARRAY_ASSERT(isValid(index));
  GC_ARRAY_ASSERT(mLogicalLen <= mPhysicalLen);
  GC_ARRAY_ASSERT(!isEmpty());
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

template <class T, class R> GcArray<T, R>&
GcArray<T, R>::removeSubArray(int startIndex, int endIndex)
{
  GC_ARRAY_ASSERT(isValid(startIndex));
  GC_ARRAY_ASSERT(startIndex <= endIndex);

  if (endIndex >= mLogicalLen - 1) {
    mLogicalLen = startIndex;
    return *this;
  }

  const int kNumToRemove = endIndex + 1 - startIndex;
  const int kNumToShift = mLogicalLen - 1 - endIndex;
  GC_ARRAY_ASSERT(kNumToShift >= 1);
  R::moveItems(mpArray + startIndex, mPhysicalLen - startIndex,
    mpArray + endIndex + 1, kNumToShift,
    true);
  mLogicalLen -= kNumToRemove;
  return *this;
}

template <class T, class R> bool
GcArray<T, R>::find(const T& value, int& index, int start) const
{
  const int nFoundAt = this->findFrom(value, start);
  if (nFoundAt == -1)
    return false;
  index = nFoundAt;
  return true;
}

template <class T, class R> int
GcArray<T, R>::find(const T& value) const
{
  return this->findFrom(value, 0);
}

template <class T, class R> int
GcArray<T, R>::findFrom(const T& value, int start) const
{
  GC_ARRAY_ASSERT(start >= 0);
  if (start < 0)
    return -1;
  for (int i = start; i < this->mLogicalLen; i++) {
    if (mpArray[i] == value)
      return i;
  }
  return -1;
}

template <class T, class R> GcArray<T, R>&
GcArray<T, R>::setLogicalLength(int n)
{
  GC_ARRAY_ASSERT(n >= 0);
  if (n < 0)
    n = 0;
  GC_ARRAY_ASSERT(n < 0x40000000);
  if (n > mPhysicalLen) {

    const int growth = (mPhysicalLen * sizeof(T)) < GCARRAY_GROWTH_THRESHOLD ?
      mPhysicalLen : GCARRAY_GROWTH_THRESHOLD / sizeof(T);

    int minSize = mPhysicalLen + std::max<int>(growth, mGrowLen);
    if (n > minSize)
      minSize = n;
    setPhysicalLength(minSize);
  }
  mLogicalLen = n;
  GC_ARRAY_ASSERT(mLogicalLen <= mPhysicalLen);
  return *this;
}

template <class T, class R> GcArray<T, R>&
GcArray<T, R>::setPhysicalLength(int n)
{
  GC_ARRAY_ASSERT(mPhysicalLen >= mLogicalLen);
  GC_ARRAY_ASSERT((mPhysicalLen == 0) == (mpArray == nullptr));
  GC_ARRAY_ASSERT(n >= 0);
  GC_ARRAY_ASSERT(n < 0x40000000);
  if (n == mPhysicalLen || n < 0)
    return *this;

  T* pOldArray = mpArray;
  const size_t nOldLen = mPhysicalLen;

  mPhysicalLen = n;
  mpArray = nullptr;

  if (mPhysicalLen < mLogicalLen)
    mLogicalLen = mPhysicalLen;

  if (mPhysicalLen != 0) {
    mpArray = static_cast<T *>(::operator new(sizeof(T) * mPhysicalLen));
    GC_ARRAY_ASSERT(mpArray != nullptr);
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

  for (size_t i = 0; i < nOldLen; i++)
    (pOldArray + i)->~T();

  ::operator delete(static_cast<void *>(pOldArray));

  return *this;
}

template <class T, class R> GcArray<T, R>&
GcArray<T, R>::reverse()
{
  for (int i = 0; i < mLogicalLen / 2; i++) {
    T tmp = std::move(mpArray[i]);
    mpArray[i] = std::move(mpArray[mLogicalLen - 1 - i]);
    mpArray[mLogicalLen - 1 - i] = std::move(tmp);
  }
  return *this;
}

template <class T, class R> GcArray<T, R>&
GcArray<T, R>::swap(int i1, int i2)
{
  GC_ARRAY_ASSERT(isValid(i1));
  GC_ARRAY_ASSERT(isValid(i2));

  if (i1 == i2) return *this;

  T tmp = std::move(mpArray[i1]);
  mpArray[i1] = std::move(mpArray[i2]);
  mpArray[i2] = std::move(tmp);
  return *this;
}

template <class T, class R> bool
GcArray<T, R>::remove(const T& value, int start)
{
  const int i = this->findFrom(value, start);
  if (i == -1)
    return false;
  this->removeAt(i);
  return true;
}

#include "gcarrayhelper.h"

#ifdef _Gc_String_h_
typedef
GcArray< GcString, GcArrayObjectCopyReallocator< GcString > > GcStringArray;
#endif

#pragma pop_macro("new")
#pragma pop_macro("delete")
#pragma pack (pop)
#endif