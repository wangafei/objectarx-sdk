/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _Gc_String_h_
#define _Gc_String_h_

#include "gcbasedefs.h"
#include "gsoft.h"
#include "GcHeapOpers.h"
#include "GdGChar.h"
#include "rxresource.h"
#include <cstdarg>

class GcDbHandle;
class GcRxResourceInstance;

class GcString : public GcHeapOperators
{
public:
  enum Encoding {
    Utf8
  };

  GCBASE_PORT GcString();
  GCBASE_PORT GcString(wchar_t wch);
  GCBASE_PORT GcString(const char *psz, Encoding encoding);
  GCBASE_PORT GcString(const char *psz, Encoding encoding, unsigned int nByteCount);
  GCBASE_PORT GcString(const wchar_t *pwsz);
  GCBASE_PORT GcString(const wchar_t *pwsz, unsigned int count);
  GCBASE_PORT GcString(const GcString & gcs);
  GCBASE_PORT GcString(GcString && gcs);

  enum eFormat {
    kSigned = 0x0002,
    kUnSigned = 0x0003,
    kHex = 0x0004
  };

  GCBASE_PORT GcString(eFormat nCtorFlags, unsigned nArg);
  GCBASE_PORT GcString(GCHAR ch, unsigned nRepeatTimes);
  GCBASE_PORT GcString(const GcDbHandle &h);
  GCBASE_PORT GcString(const GcRxResourceInstance& hDll, unsigned int nId);
  GCBASE_PORT ~GcString();

  GCBASE_PORT const char * utf8Ptr() const;
  const wchar_t * kwszPtr() const;
  const wchar_t *  constPtr() const;
  const wchar_t * kTCharPtr() const;
  const GCHAR * kGCharPtr() const;
  operator const wchar_t * () const;
  bool isEmpty() const;

  GCBASE_PORT unsigned length() const;
  unsigned tcharLength() const
  {
    return this->length();
  }

  GCBASE_PORT unsigned capacity() const;
  GCBASE_PORT bool reserve(unsigned nCapacity);
  GCBASE_PORT bool isAscii() const;
  GCBASE_PORT bool is7Bit() const;

  enum {
    kParseZero = 0,
    kParseMinus1 = 0x01,
    kParseAssert = 0x02,
    kParseExcept = 0x04,
    kParseNoEmpty = 0x08,
    kParseDefault = (kParseAssert | kParseZero)
  };

  GCBASE_PORT int asDeci(int nFlags = kParseDefault) const;
  GCBASE_PORT int asHex(int nFlags = kParseDefault) const;
  GCBASE_PORT unsigned int asUDeci(int nFlags = kParseDefault) const;
  GCBASE_PORT unsigned int asUHex(int nFlags = kParseDefault) const;
  GCBASE_PORT int64_t asDeci64(int nFlags = kParseDefault) const;
  GCBASE_PORT int64_t asHex64(int nFlags = kParseDefault) const;
  GCBASE_PORT Gsoft::UInt64 asUDeci64(int nFlags = kParseDefault) const;
  GCBASE_PORT Gsoft::UInt64 asUHex64(int nFlags = kParseDefault) const;
  GCBASE_PORT GcDbHandle asGcDbHandle(int nFlags = kParseDefault) const;

  int find(GCHAR ch) const;
  GCBASE_PORT int find(GCHAR ch, int nStartPos) const;
  GCBASE_PORT int find(const GCHAR *psz) const;
  GCBASE_PORT int find(const GCHAR *psz, int nStartPos) const;
  GCBASE_PORT int find(const GcString & gcs) const;

  GCBASE_PORT int findOneOf(const GCHAR *psz) const;
  GCBASE_PORT int findOneOf(const GCHAR *psz, int nStartPos) const;
  GCBASE_PORT int findNoneOf(const GCHAR *psz, int nStartPos = 0) const;

  int findRev(GCHAR ch) const;
  GCBASE_PORT int findRev(const GCHAR *psz) const;
  GCBASE_PORT int findOneOfRev(const GCHAR *psz) const;
  GCBASE_PORT int findRev(const GcString & gcs) const;

  int findLast(GCHAR ch, int nEndPos = -1) const;
  GCBASE_PORT int findLast(const GCHAR *psz, int nEndPos = -1) const;

  GCBASE_PORT int findLastOneOf(const GCHAR *psz, int nEndPos = -1) const;
  GCBASE_PORT int findLastNoneOf(const GCHAR *psz, int nEndPos = -1) const;

  GcString mid(int nStart) const;
  GcString mid(int nStart, int nNumChars) const;

  GcString substr(int numChars) const;
  GCBASE_PORT GcString substr(int nStart, int nNumChars) const;
  GCBASE_PORT GcString substrRev(int numChars) const;

  GcString left(int nNumChars) const;
  GcString right(int nNumChars) const;

  GcString & assign(wchar_t wch);
  GCBASE_PORT  GcString & assign(const char *psz, Encoding encoding);
  GCBASE_PORT GcString & assign(const wchar_t *pwsz);
  GCBASE_PORT GcString & assign(const GcString & gcs);
  GCBASE_PORT GcString & assign(const GcDbHandle & h);

  GcString & operator = (wchar_t wch);
  GcString & operator = (const wchar_t *pwsz);
  GcString & operator = (const GcString & gcs);
  GCBASE_PORT GcString & operator = (GcString && gcs);
  GcString & operator = (const GcDbHandle & h);

  GCBASE_PORT GcString & setEmpty();
  GCBASE_PORT bool loadString(const GcRxResourceInstance& hDll, unsigned nId);
  GCBASE_PORT GcString & format(const GCHAR    *pszFmt, ...);
  GCBASE_PORT GcString & formatV(const GCHAR   *pszFmt, va_list args);
  GCBASE_PORT GcString & appendFormat(const GCHAR   *pszFmt, ...);

  GcString & operator += (wchar_t wch);
  GcString & operator += (const wchar_t * pwsz);
  GcString & operator += (const GcString & gcs);

  GcString & append(wchar_t wch);
  GCBASE_PORT GcString & append(const char *psz, Encoding encoding);
  GCBASE_PORT GcString & append(const wchar_t *pwsz);
  GCBASE_PORT GcString & append(const GcString & gcs);

  GcString operator + (wchar_t wch) const;
  GcString operator + (const wchar_t * pwsz) const;
  GcString operator + (const GcString & gcs) const;

  GcString concat(wchar_t wch) const;
  GCBASE_PORT GcString concat(const char * psz, Encoding encoding) const;
  GCBASE_PORT GcString concat(const wchar_t * pwsz) const;
  GCBASE_PORT GcString concat(const GcString & gcs) const;

  GcString precat(GCHAR ch) const;
  GCBASE_PORT GcString precat(const char * psz, Encoding encoding) const;
  GCBASE_PORT GcString precat(const wchar_t * psz) const;

  int  compare(wchar_t wch) const;
  GCBASE_PORT int  compare(const char *psz, Encoding encoding) const;
  GCBASE_PORT int  compare(const wchar_t *pwsz) const;
  int  compare(const GcString & gcs) const;

  GCBASE_PORT int  collate(const wchar_t *pwsz) const;
  int  collate(const GcString & gcs) const;

  int  compareNoCase(wchar_t wch) const;
  GCBASE_PORT int  compareNoCase(const char *psz, Encoding encoding) const;
  GCBASE_PORT int  compareNoCase(const wchar_t *pwsz) const;
  int  compareNoCase(const GcString & gcs) const;

  static bool equalsNoCase(const GcString& left, const GcString& right);
  GCBASE_PORT int collateNoCase(const wchar_t *psz) const;
  int collateNoCase(const GcString& gcs) const;

  bool operator == (wchar_t wch) const;
  bool operator == (const wchar_t *pwsz) const;
  bool operator == (const GcString & gcs) const;

  bool operator != (wchar_t wch) const;
  bool operator != (const wchar_t *pwsz) const;
  bool operator != (const GcString & gcs) const;

  bool operator >  (wchar_t wch) const;
  bool operator >  (const wchar_t *pwsz) const;
  bool operator >  (const GcString & gcs) const;

  bool operator >= (wchar_t wch) const;
  bool operator >= (const wchar_t *pwsz) const;
  bool operator >= (const GcString & gcs) const;

  bool operator <  (wchar_t wch) const;
  bool operator <  (const wchar_t *pwsz) const;
  bool operator <  (const GcString & gcs) const;

  bool operator <= (wchar_t wch) const;
  bool operator <= (const wchar_t *pwsz) const;
  bool operator <= (const GcString & gcs) const;

  GCBASE_PORT int  match(const char *psz, Encoding encoding) const;
  GCBASE_PORT int  match(const wchar_t *pwsz) const;
  GCBASE_PORT int  match(const GcString & gcs) const;

  GCBASE_PORT int  matchNoCase(const char *psz, Encoding encoding) const;
  GCBASE_PORT int  matchNoCase(const wchar_t *pwsz) const;
  GCBASE_PORT int  matchNoCase(const GcString & gcs) const;

  GCBASE_PORT GcString & makeUpper();
  GCBASE_PORT GcString & makeLower();
  GCBASE_PORT GcString& makeReverse();

  GCBASE_PORT GcString & trimLeft(wchar_t wch);
  GCBASE_PORT GcString & trimRight(wchar_t wch);
  GCBASE_PORT GcString & trim(wchar_t wch);

  GcString & trimLeft();
  GCBASE_PORT GcString & trimLeft(const wchar_t *pwszChars);
  GcString & trimRight();
  GCBASE_PORT GcString & trimRight(const wchar_t *pwszChars);
  GcString & trim();
  GCBASE_PORT GcString & trim(const wchar_t *pwszChars);

  GCBASE_PORT int remove(wchar_t wch);
  int remove()
  {
    return this->remove(0);
  }

  GCBASE_PORT GcString spanExcluding(const wchar_t *pwszChars) const;

#if  defined(_AFX) || defined (__OSX_WINAPI_UNIX_STRING_H__) || defined(__ATLSTR_H__)

  GcString(const CStringW &csw);

  GcString & operator = (const CStringW &csw);
  GcString & operator += (const CStringW &csw);

  int  compare(const CStringW & csw) const;
  int  compareNoCase(const CStringW & csw) const;

  bool operator == (const CStringW &) const;
  bool operator != (const CStringW &) const;
  bool operator <  (const CStringW &) const;
  bool operator <= (const CStringW &) const;
  bool operator >  (const CStringW &) const;
  bool operator >= (const CStringW &) const;

  int  match(const CStringW & csw) const;
  int  matchNoCase(const CStringW & csw) const;

#endif

  GCBASE_PORT  int replace(const wchar_t* pwszOld, const wchar_t* pwszNew);
  GCBASE_PORT int replace(wchar_t wchOld, wchar_t wchNew);

  GCBASE_PORT int deleteAtIndex(int iIndex, int nCount = 1);
  GCBASE_PORT GcString tokenize(const wchar_t* pszTokens, int& iStart);
  GCBASE_PORT GcString& setAt(int nIndex, GCHAR ch);
  wchar_t getAt(int nIndex) const;

  GCBASE_PORT GcString& insert(int nIndex, wchar_t ch);
  GCBASE_PORT GcString& insert(int nIndex, const wchar_t* pwsz);

  GCBASE_PORT GCHAR* getBuffer(int nMinBufferLength = 0);
  GCBASE_PORT bool   releaseBuffer(int nNewLength = -1);

private:
  friend class GcStringImp;
  wchar_t *m_wsz;
};

#ifdef GC_GCARRAY_H
typedef
GcArray< GcString, GcArrayObjectCopyReallocator< GcString > > GcStringArray;
#endif

bool operator == (wchar_t wch, const GcString & gcs);

bool operator == (const wchar_t *pwsz, const GcString & gcs);

bool operator != (wchar_t wch, const GcString & gcs);

bool operator != (const wchar_t *pwsz, const GcString & gcs);

bool operator >  (wchar_t wch, const GcString & gcs);

bool operator >  (const wchar_t *pwsz, const GcString & gcs);

bool operator >= (wchar_t wch, const GcString & gcs);

bool operator >= (const wchar_t *pwsz, const GcString & gcs);

bool operator <  (wchar_t wch, const GcString & gcs);

bool operator <  (const wchar_t *pwsz, const GcString & gcs);

bool operator <= (wchar_t wch, const GcString & gcs);

bool operator <= (const wchar_t *pwsz, const GcString & gcs);

GcString operator + (wchar_t wch, const GcString & gcs);

GcString operator + (const wchar_t *pwsz, const GcString & gcs);

inline GcString::operator const wchar_t *() const
{
  return this->kwszPtr();
}

inline const wchar_t * GcString::constPtr() const
{
  return this->kwszPtr();
}

inline const wchar_t * GcString::kTCharPtr() const
{
  return this->kwszPtr();
}

inline const GCHAR * GcString::kGCharPtr() const
{
  return this->kwszPtr();
}

inline bool GcString::isEmpty() const
{
  return this->m_wsz[0] == L'\0';
}

inline wchar_t GcString::getAt(int nIndex) const
{
  return this->m_wsz[nIndex];
}

inline int GcString::find(GCHAR ch) const
{
  const GCHAR str[2] = { ch, '\0' };
  return this->findOneOf(str);
}

inline int GcString::findRev(GCHAR ch) const
{
  return this->findLast(ch);
}

inline int GcString::findLast(GCHAR ch, int nStartPos) const
{
  const GCHAR str[2] = { ch, '\0' };
  return this->findLastOneOf(str, nStartPos);
}

inline GcString GcString::mid(int nStart, int nNumChars) const
{
  return this->substr(nStart, nNumChars);
}

inline GcString GcString::mid(int nStart) const
{
  return this->mid(nStart, -1);
}

inline GcString GcString::substr(int nNumChars) const
{
  return this->substr(0, nNumChars);
}

inline GcString GcString::left(int nNumChars) const
{
  return this->substr(nNumChars);
}

inline GcString GcString::right(int nNumChars) const
{
  return this->substrRev(nNumChars);
}

inline GcString & GcString::trimLeft(wchar_t wch)
{
  const wchar_t wszChars[] = { wch, L'\0' };
  return this->trimLeft(wszChars);
}

inline GcString & GcString::trimLeft()
{
  return this->trimLeft(nullptr);
}

inline GcString & GcString::trimRight(wchar_t wch)
{
  const wchar_t wszChars[] = { wch, L'\0' };
  return this->trimRight(wszChars);
}

inline GcString & GcString::trimRight()
{
  return this->trimRight(nullptr);
}

inline GcString & GcString::trim(wchar_t wch)
{
  const wchar_t wszChars[] = { wch, L'\0' };
  return this->trim(wszChars);
}

inline GcString & GcString::trim()
{
  return this->trim(nullptr);
}

inline GcString & GcString::trim(const wchar_t *pwszChars)
{
  return this->trimRight(pwszChars).trimLeft(pwszChars);
}

inline GcString & GcString::assign(wchar_t wch)
{
  const wchar_t wstr[2] = { wch, L'\0' };
  return this->assign(wstr);
}

inline GcString & GcString::operator = (wchar_t wch)
{
  return this->assign(wch);
}

inline GcString & GcString::operator = (const wchar_t *pwsz)
{
  return this->assign(pwsz);
}

inline GcString & GcString::operator = (const GcString & gcs)
{
  return this->assign(gcs);
}

inline GcString & GcString::operator = (const GcDbHandle & h)
{
  return this->assign(h);
}

inline GcString & GcString::operator += (wchar_t wch)
{
  return this->append(wch);
}

inline GcString & GcString::operator += (const wchar_t *pwsz)
{
  return this->append(pwsz);
}

inline GcString & GcString::operator += (const GcString & gcs)
{
  return this->append(gcs);
}

inline GcString & GcString::append(wchar_t wch)
{
  const wchar_t wstr[2] = { wch, L'\0' };
  return this->append(wstr);
}

inline GcString GcString::operator + (wchar_t wch) const
{
  return this->concat(wch);
}

inline GcString GcString::operator + (const wchar_t * pwsz) const
{
  return this->concat(pwsz);
}

inline GcString GcString::operator + (const GcString & gcs) const
{
  return this->concat(gcs);
}

inline GcString GcString::concat(wchar_t wch) const
{
  const wchar_t wstr[2] = { wch, L'\0' };
  return this->concat(wstr);
}

inline GcString GcString::precat(wchar_t ch) const
{
  const wchar_t str[2] = { ch, '\0' };
  return this->precat(str);
}

inline const wchar_t * GcString::kwszPtr() const
{
  return this->m_wsz;
}

inline int GcString::compare(wchar_t wch) const
{
  const wchar_t wstr[2] = { wch, L'\0' };
  return this->compare(wstr);
}

inline int GcString::compare(const GcString & gcs) const
{
  return this->compare(gcs.kwszPtr());
}

inline int GcString::compareNoCase(wchar_t wch) const
{
  const wchar_t wstr[2] = { wch, L'\0' };
  return this->compareNoCase(wstr);
}

inline int GcString::compareNoCase(const GcString & gcs) const
{
  return this->compareNoCase(gcs.kwszPtr());
}

inline int GcString::collate(const GcString & gcs) const
{
  return this->collate(gcs.kwszPtr());
}

inline int GcString::collateNoCase(const GcString & gcs) const
{
  return this->collateNoCase(gcs.kwszPtr());
}

inline bool GcString::operator == (wchar_t wch) const
{
  return this->compare(wch) == 0;
}

inline bool GcString::operator == (const wchar_t *pwsz) const
{
  return this->compare(pwsz) == 0;
}

inline bool GcString::operator == (const GcString & gcs) const
{
  return this->compare(gcs) == 0;
}

inline bool GcString::operator != (wchar_t wch) const
{
  return this->compare(wch) != 0;
}

inline bool GcString::operator != (const wchar_t *pwsz) const
{
  return this->compare(pwsz) != 0;
}

inline bool GcString::operator != (const GcString & gcs) const
{
  return this->compare(gcs) != 0;
}

inline bool GcString::operator > (wchar_t wch) const
{
  return this->compare(wch) > 0;
}

inline bool GcString::operator > (const wchar_t *pwsz) const
{
  return this->compare(pwsz) > 0;
}

inline bool GcString::operator > (const GcString & gcs) const
{
  return this->compare(gcs) > 0;
}

inline bool GcString::operator >= (wchar_t wch) const
{
  return this->compare(wch) >= 0;
}

inline bool GcString::operator >= (const wchar_t *pwsz) const
{
  return this->compare(pwsz) >= 0;
}

inline bool GcString::operator >= (const GcString & gcs) const
{
  return this->compare(gcs) >= 0;
}

inline bool GcString::operator < (wchar_t wch) const
{
  return this->compare(wch) < 0;
}

inline bool GcString::operator < (const wchar_t *pwsz) const
{
  return this->compare(pwsz) < 0;
}

inline bool GcString::operator < (const GcString & gcs) const
{
  return this->compare(gcs) < 0;
}

inline bool GcString::operator <= (wchar_t wch) const
{
  return this->compare(wch) <= 0;
}

inline bool GcString::operator <= (const wchar_t *pwsz) const
{
  return this->compare(pwsz) <= 0;
}

inline bool GcString::operator <= (const GcString & gcs) const
{
  return this->compare(gcs) <= 0;
}


inline bool operator == (wchar_t wch, const GcString & gcs)
{
  return gcs.compare(wch) == 0;
}

inline bool operator == (const wchar_t *pwsz, const GcString & gcs)
{
  return gcs.compare(pwsz) == 0;
}

inline bool operator != (wchar_t wch, const GcString & gcs)
{
  return gcs.compare(wch) != 0;
}

inline bool operator != (const wchar_t *pwsz, const GcString & gcs)
{
  return gcs.compare(pwsz) != 0;
}

inline bool operator > (wchar_t wch, const GcString & gcs)
{
  return gcs.compare(wch) < 0;
}

inline bool operator > (const wchar_t *pwsz, const GcString & gcs)
{
  return gcs.compare(pwsz) < 0;
}

inline bool operator >= (wchar_t wch, const GcString & gcs)
{
  return gcs.compare(wch) <= 0;
}

inline bool operator >= (const wchar_t *pwsz, const GcString & gcs)
{
  return gcs.compare(pwsz) <= 0;
}

inline bool operator < (wchar_t wch, const GcString & gcs)
{
  return gcs.compare(wch) > 0;
}

inline bool operator < (const wchar_t *pwsz, const GcString & gcs)
{
  return gcs.compare(pwsz) > 0;
}

inline bool operator <= (wchar_t wch, const GcString & gcs)
{
  return gcs.compare(wch) >= 0;
}

inline bool operator <= (const wchar_t *pwsz, const GcString & gcs)
{
  return gcs.compare(pwsz) >= 0;
}

inline GcString operator + (GCHAR ch, const GcString & gcs)
{
  return gcs.precat(ch);
}

inline GcString operator + (const wchar_t *pwsz, const GcString & gcs)
{
  return gcs.precat(pwsz);
}

inline bool GcString::equalsNoCase(const GcString& left, const GcString& right)
{
  return left.compareNoCase(right) == 0;
}

class GcUniqueString
{
public:
  GCBASE_PORT static const GcUniqueString *Intern(const wchar_t *);
};

#if defined(_AFX) || defined(__OSX_WINAPI_UNIX_STRING_H__) || defined(__ATLSTR_H__)


inline GcString::GcString(const CStringW &csw) : GcString()
{
  const wchar_t *pwsz = (const wchar_t *)csw;
  *this = pwsz;
}

inline GcString & GcString::operator=(const CStringW &csw)
{
  const wchar_t *pwsz = (const wchar_t *)csw;
  return this->assign(pwsz);
}

inline GcString & GcString::operator+=(const CStringW &csw)
{
  const wchar_t *pwsz = (const wchar_t *)csw;
  return this->append(pwsz);
}

inline int GcString::compare(const CStringW & csw) const
{
  const wchar_t *pwsz = (const wchar_t *)csw;
  return this->compare(pwsz);
}

inline int GcString::compareNoCase(const CStringW & csw) const
{
  const wchar_t *pwsz = (const wchar_t *)csw;
  return this->compareNoCase(pwsz);
}

inline int GcString::match(const CStringW & csw) const
{
  const wchar_t *pwsz = (const wchar_t *)csw;
  return this->match(pwsz);
}

inline int GcString::matchNoCase(const CStringW & csw) const
{
  const wchar_t *pwsz = (const wchar_t *)csw;
  return this->matchNoCase(pwsz);
}

inline bool GcString::operator == (const CStringW & csw) const
{
  return this->compare(csw) == 0;
}

inline bool GcString::operator != (const CStringW & csw) const
{
  return this->compare(csw) != 0;
}

inline bool GcString::operator > (const CStringW & csw) const
{
  return this->compare(csw) > 0;
}

inline bool GcString::operator >= (const CStringW & csw) const
{
  return this->compare(csw) >= 0;
}

inline bool GcString::operator < (const CStringW & csw) const
{
  return this->compare(csw) < 0;
}

inline bool GcString::operator <= (const CStringW & csw) const
{
  return this->compare(csw) <= 0;
}

#if defined(_AFX) && !defined(__cplusplus_cli)
inline bool operator == (const CStringW & csw, const GcString & gcs)
{
  return gcs.compare(csw) == 0;
}

inline bool operator != (const CStringW & csw, const GcString & gcs)
{
  return gcs.compare(csw) != 0;
}

inline bool operator >  (const CStringW & csw, const GcString & gcs)
{
  return gcs.compare(csw) < 0;
}

inline bool operator >= (const CStringW & csw, const GcString & gcs)
{
  return gcs.compare(csw) <= 0;
}

inline bool operator <  (const CStringW & csw, const GcString & gcs)
{
  return gcs.compare(csw) > 0;
}

inline bool operator <= (const CStringW & csw, const GcString & gcs)
{
  return gcs.compare(csw) >= 0;
}

#ifndef DISABLE_CSTRING_PLUS_GCSTRING
inline GcString operator + (const CStringW & csw, const GcString & gcs)
{
  const wchar_t *pwsz = (const wchar_t *)csw;
  return gcs.precat(pwsz);
}
#endif

#endif

#endif 

#endif