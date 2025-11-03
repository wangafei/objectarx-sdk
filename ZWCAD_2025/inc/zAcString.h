

#ifndef _Zc_String_h_
#define _Zc_String_h_

#include "zacbasedefs.h"
#include "zadesk.h"
#include "zAcHeapOpers.h"
#include "zAdAChar.h"
#ifndef _ZSOFT_WINDOWS_
#include <stdarg.h>
#endif

#include "zrxresource.h"
#include <cstdarg>
#include <string>

#ifdef __cpp_lib_string_view
#include <string_view>
#endif

#pragma pack (push, 1)

class ZcDbHandle;
class ZcRxResourceInstance;

class ZCBASE_PORT ZcString : public ZcHeapOperators
{
  public:
    enum Encoding { Utf8 };
	ZcString();
	ZcString(char ch);
	ZcString(wchar_t wch);
	ZcString(const char *psz);
	ZcString(const char *psz, Encoding encoding);
	ZcString(const char *psz, Encoding encoding, unsigned int nByteCount);
	ZcString(const wchar_t *pwsz);
	ZcString(const wchar_t *pwsz, unsigned int count);
	ZcString(const ZcString & acs);
	ZcString(ZcString && acs);
    enum eFormat {
        kAppRes = 0x0001,   
        kSigned = 0x0002,   
        kUnSigned = 0x0003, 
        kHex      = 0x0004  
    };
	ZcString(eFormat nCtorFlags, unsigned nArg);
	ZcString(ZTCHAR ch, unsigned nRepeatTimes);
	ZcString(const ZcDbHandle &h);
	ZcString(const ZcRxResourceInstance& hDll, unsigned int nId);

#if defined(_WINBASE_) || defined(_ZSOFT_MAC_) || defined(_ZSOFT_LINUX_)
	ZcString(HINSTANCE hDll, unsigned nId);
#endif
    ~ZcString();
	const char * ansiPtr() const;
	const char * utf8Ptr() const;
	const char * kszPtr() const;
	const wchar_t * kwszPtr() const;
#ifdef UNICODE
    const wchar_t *  constPtr() const;
    const wchar_t * kTCharPtr() const;
#else
    const  char   *  constPtr() const;
    const  char   * kTCharPtr() const;
#endif
    const ZTCHAR * kACharPtr() const;
    operator const char * () const;
    operator const wchar_t * () const;
    bool isEmpty() const;
    unsigned length() const;
	unsigned tcharLength() const
	{
		return this->length();
	}
    unsigned capacity() const;
    bool reserve(unsigned nCapacity);
    bool isAscii() const;
	bool is7Bit() const;
    enum {
        kParseZero = 0,       
        kParseMinus1 = 0x01,  
        kParseAssert = 0x02,  
        kParseExcept = 0x04,  
        kParseNoEmpty = 0x08, 
        kParseDefault = (kParseAssert | kParseZero)
    };
    int asDeci(int nFlags = kParseDefault) const;
    int asHex (int nFlags = kParseDefault) const;
    unsigned int asUDeci(int nFlags = kParseDefault) const;
    unsigned int asUHex (int nFlags = kParseDefault) const;
    int64_t asDeci64(int nFlags = kParseDefault) const;
    int64_t asHex64 (int nFlags = kParseDefault) const;
    ZSoft::UInt64 asUDeci64(int nFlags = kParseDefault) const;
    ZSoft::UInt64 asUHex64 (int nFlags = kParseDefault) const;
    ZcDbHandle asZcDbHandle(int nFlags = kParseDefault) const;

    int find(ZTCHAR ch) const;
    int find(ZTCHAR ch, int nStartPos) const;
	int find(const ZTCHAR *psz, int nStartPos = 0) const;
    int find(const ZcString & acs) const;
	int findOneOf(const ZTCHAR *psz, int nStartPos = 0) const;
	int findNoneOf(const ZTCHAR *psz, int nStartPos = 0) const;
    int findRev(ZTCHAR ch) const;
	int findRev(const ZTCHAR *psz) const;
	int findRev(const ZcString & acs) const;
	int findOneOfRev(const ZTCHAR *psz) const;
	int findLast(ZTCHAR ch, int nEndPos = -1) const;
	int findLast(const ZTCHAR *psz, int nEndPos = -1) const;
	int findLastOneOf(const ZTCHAR *psz, int nEndPos = -1) const;
	int findLastNoneOf(const ZTCHAR *psz, int nEndPos = -1) const;
    
    ZcString mid(int nStart) const;
    ZcString mid(int nStart, int nNumChars) const;
    ZcString substr(int numChars) const;
    ZcString substr(int nStart, int nNumChars) const;
    ZcString substrRev(int numChars) const;

    ZcString left(int nNumChars) const;
    ZcString right(int nNumChars) const;
    ZcString & assign(char ch);
    ZcString & assign(wchar_t wch);
    ZcString & assign(const char *psz);
    ZcString & assign(const char *psz, Encoding encoding);
    ZcString & assign(const wchar_t *pwsz);
    ZcString & assign(const ZcString & acs);
    ZcString & assign(const ZcDbHandle & h);
    ZcString & operator = (char ch);
    ZcString & operator = (wchar_t wch);
    ZcString & operator = (const char *psz);
    ZcString & operator = (const wchar_t *pwsz);
    ZcString & operator = (const ZcString & acs);
    ZcString & operator = (ZcString && acs);
    ZcString & operator = (const ZcDbHandle & h);
    ZcString & setEmpty();
    bool loadString(unsigned nId);
    bool loadString(const ZcRxResourceInstance& hDll, unsigned nId);

#if defined(_WINBASE_) || defined(_ZSOFT_MAC_) || defined(_ZSOFT_LINUX_)
    bool loadString(HINSTANCE hDll, unsigned nId);
#endif
    ZcString & format (const ZTCHAR    *pszFmt,  ...);
    ZcString & formatV(const ZTCHAR   *pszFmt,  va_list args);
    ZcString & appendFormat(const ZTCHAR   *pszFmt, ...);
    ZcString & operator += (char ch);
    ZcString & operator += (wchar_t wch);
    ZcString & operator += (const char * psz);
    ZcString & operator += (const wchar_t * pwsz);
    ZcString & operator += (const ZcString & acs);
    ZcString & append(char ch);
    ZcString & append(wchar_t wch);
    ZcString & append(const char *psz);
    ZcString & append(const char *psz, Encoding encoding);
    ZcString & append(const wchar_t *pwsz);
    ZcString & append(const ZcString & acs);
    ZcString operator + (char ch) const;
    ZcString operator + (wchar_t wch) const;

    ZcString operator + (const char * psz) const;
    ZcString operator + (const wchar_t * pwsz) const;
    ZcString operator + (const ZcString & acs) const;
    ZcString concat(char ch) const;
    ZcString concat(wchar_t wch) const;
    ZcString concat(const char * psz) const;
    ZcString concat(const char * psz, Encoding encoding) const;
    ZcString concat(const wchar_t * pwsz) const;
    ZcString concat(const ZcString & acs) const;
    ZcString precat(ZTCHAR ch) const;
    ZcString precat(const char * psz) const;
    ZcString precat(const char * psz, Encoding encoding) const;
    ZcString precat(const wchar_t * psz) const;
    int  compare(wchar_t wch) const;
    int  compare(const char *psz) const;
    int  compare(const char *psz, Encoding encoding) const;
    int  compare(const wchar_t *pwsz) const;
    int  compare(const ZcString & acs) const;
    int  collate (const wchar_t *pwsz) const;
    int  collate(const ZcString & acs) const;
    int  compareNoCase(wchar_t wch) const;
    int  compareNoCase(const char *psz) const;
    int  compareNoCase(const char *psz, Encoding encoding) const;
    int  compareNoCase(const wchar_t *pwsz) const;
    int  compareNoCase(const ZcString & acs) const;
    static bool equalsNoCase(const ZcString& left, const ZcString& right);
    int collateNoCase(const wchar_t *psz) const;
    int collateNoCase(const ZcString& acs) const;
    bool operator == (wchar_t wch) const;
    bool operator == (const char *psz) const;
    bool operator == (const wchar_t *pwsz) const;
    bool operator == (const ZcString & acs) const;
    bool operator != (wchar_t wch) const;
    bool operator != (const char *psz) const;
    bool operator != (const wchar_t *pwsz) const;
    bool operator != (const ZcString & acs) const;
    bool operator >  (wchar_t wch) const;
    bool operator >  (const char *psz) const;
    bool operator >  (const wchar_t *pwsz) const;
    bool operator >  (const ZcString & acs) const;
    bool operator >= (wchar_t wch) const;
    bool operator >= (const char *psz) const;
    bool operator >= (const wchar_t *pwsz) const;
    bool operator >= (const ZcString & acs) const;
    bool operator <  (wchar_t wch) const;
    bool operator <  (const char *psz) const;
    bool operator <  (const wchar_t *pwsz) const;
    bool operator <  (const ZcString & acs) const;
    bool operator <= (const char ch) const;
    bool operator <= (wchar_t wch) const;
    bool operator <= (const char *psz) const;
    bool operator <= (const wchar_t *pwsz) const;
    bool operator <= (const ZcString & acs) const;
    int  match(const char *psz) const;
	int  match(const char *psz, Encoding encoding) const;
	int  match(const wchar_t *pwsz) const;
	int  match(const ZcString & acs) const;
    int  matchNoCase(const char *psz) const;
	int  matchNoCase(const char *psz, Encoding encoding) const;
	int  matchNoCase(const wchar_t *pwsz) const;
	int  matchNoCase(const ZcString & acs) const;

	ZcString & makeUpper();

	ZcString & makeLower();
	ZcString& makeReverse();
	ZcString & trimLeft(wchar_t wch);
	ZcString & trimRight(wchar_t wch);
	ZcString & trim(wchar_t wch);
	ZcString & trimLeft();
	ZcString & trimLeft(const wchar_t *pwszChars);
	ZcString & trimRight();
	ZcString & trimRight(const wchar_t *pwszChars);
	ZcString & trim();
	ZcString & trim(const wchar_t *pwszChars);
	int remove(wchar_t wch);
	int remove() { return this->remove(0); }
	ZcString spanExcluding(const wchar_t *pwszChars) const;
#if defined(_AFX) || defined(_ZSOFT_MAC_) || defined(_ZSOFT_LINUX_) || defined(__ATLSTR_H__)
    ZcString(const CStringW &csw);
    ZcString & operator = (const CStringW &csw);
    ZcString & operator += (const CStringW &csw);
    int  compare(const CStringW & csw) const;
    int  compareNoCase(const CStringW & csw) const;
    bool operator == (const CStringW & ) const;
    bool operator != (const CStringW & ) const;
    bool operator <  (const CStringW & ) const;
    bool operator <= (const CStringW & ) const;
    bool operator >  (const CStringW & ) const;
    bool operator >= (const CStringW & ) const;
    int  match(const CStringW & csw) const;
    int  matchNoCase(const CStringW & csw) const;
#endif

#ifdef __cpp_lib_string_view
	explicit ZcString(std::wstring_view str);
	ZcString& operator = (std::wstring_view csw);
#endif
	explicit ZcString(const std::wstring& str);
	ZcString& operator = (const std::wstring& csw);

	int replace(const wchar_t* pwszOld, const wchar_t* pwszNew);
	int replace(wchar_t wchOld, wchar_t wchNew);
	int deleteAtIndex(int iIndex, int nCount = 1);
	ZcString & truncate(int nIndex);
	ZcString tokenize(const wchar_t* pszTokens, int& iStart) const;
	ZcString& setAt(int nIndex, ZTCHAR ch);
	wchar_t getAt(int nIndex) const;
	ZcString& insert(int nIndex, wchar_t ch);
	ZcString& insert(int nIndex, const wchar_t* pwsz);
	ZTCHAR* getBuffer(int nMinBufferLength = 0);
	bool   releaseBuffer(int nNewLength = -1);

  private:

#if !defined(_WIN64) && !defined (_ZC64)
    enum {
#ifndef _ZSOFT_WINDOWS_
		kObjSize = 14,
#else
		kObjSize = 8,
#endif
        kMbArrSize = 7,
        kUCArrSize = 3,
        kPadArrSize = 3
    };
#else
    enum {
#ifndef _ZSOFT_WINDOWS_
		kObjSize = 30,
#else
		kObjSize = 16,
#endif
        kMbArrSize = 15,
        kUCArrSize = 7,
        kPadArrSize = 7
    };
#endif
    void clearAll();
    struct PtrAndData;
    unsigned char mnFlags;
    union {
        struct {
            unsigned char mnPad2[kPadArrSize];
            union {
                wchar_t *mpwszData;
                char *mpszData;
                PtrAndData *mpPtrAndData;
            };
        }mptr;
        struct {
            unsigned char mnPad1;
            wchar_t mwszStr[kUCArrSize];
        }mchr;
        char mszStr[kMbArrSize];
    };
	char* mpuszData = nullptr; 
    friend class ZcStringImp;
};

#include "zacarray.h"

#ifdef ZC_ZCARRAY_H
typedef
	ZcArray< ZcString, ZcArrayObjectCopyReallocator< ZcString > > ZcStringArray;
#endif

#pragma pack (pop)
bool operator == (wchar_t wch, const ZcString & acs);

bool operator == (const char *psz, const ZcString & acs);

bool operator == (const wchar_t *pwsz, const ZcString & acs);

bool operator != (wchar_t wch, const ZcString & acs);

bool operator != (const char *psz, const ZcString & acs);

bool operator != (const wchar_t *pwsz, const ZcString & acs);

bool operator >  (wchar_t wch, const ZcString & acs);

bool operator >  (const char *psz, const ZcString & acs);

bool operator >  (const wchar_t *pwsz, const ZcString & acs);

bool operator >= (wchar_t wch, const ZcString & acs);

bool operator >= (const char *psz, const ZcString & acs);

bool operator >= (const wchar_t *pwsz, const ZcString & acs);

bool operator <  (wchar_t wch, const ZcString & acs);

bool operator <  (const char *psz, const ZcString & acs);

bool operator <  (const wchar_t *pwsz, const ZcString & acs);

bool operator <= (wchar_t wch, const ZcString & acs);

bool operator <= (const char *psz, const ZcString & acs);

bool operator <= (const wchar_t *pwsz, const ZcString & acs);

ZcString operator + (wchar_t wch, const ZcString & acs);

ZcString operator + (const char *psz, const ZcString & acs);

ZcString operator + (const wchar_t *pwsz, const ZcString & acs);

#if defined (_AFX) || defined(__ATLSTR_H__)

bool operator == (const CStringW & csw, const ZcString & acs);

bool operator != (const CStringW & csw, const ZcString & acs);

bool operator >  (const CStringW & csw, const ZcString & acs);

bool operator >= (const CStringW & csw, const ZcString & acs);

bool operator <  (const CStringW & csw, const ZcString & acs);

bool operator <= (const CStringW & csw, const ZcString & acs);

#define DISABLE_CSTRING_PLUS_ZCSTRING 1
#ifndef DISABLE_CSTRING_PLUS_ZCSTRING
ZcString operator + (const CStringW & csw, const ZcString & acs);
#endif
#endif

inline const char * ZcString::kszPtr() const
{
	return this->ansiPtr();
}

inline ZcString::operator const wchar_t *() const
{
    return this->kwszPtr();
}

#ifdef UNICODE
inline const wchar_t * ZcString::constPtr() const
{
    return this->kwszPtr();
}

inline const wchar_t * ZcString::kTCharPtr() const
{
    return this->kwszPtr();
}

#elif _UNICODE
#error "Unexpected _UNICODE definition"
#else
inline const char * ZcString::constPtr() const
{
    return this->kszPtr();
}

inline const char * ZcString::kTCharPtr() const
{
    return this->kszPtr();
}

#endif

inline const ZTCHAR * ZcString::kACharPtr() const
{
#ifdef _ZSOFT_WINDOWS_
    return this->kwszPtr();
#else
	return (ZTCHAR*)this->kwszPtr();
#endif
}

inline void ZcString::clearAll()
{
    this->mnFlags = 0;
    this->mchr.mnPad1 = 0;
    this->mchr.mwszStr[0] = 0;
    this->mptr.mpszData = nullptr;
	this->mpuszData = nullptr;
}

inline int ZcString::find(ZTCHAR ch) const
{
	const ZTCHAR str[2] = {ch, '\0'};
	return this->findOneOf(str);
}

inline int ZcString::findRev(ZTCHAR ch) const
{
	const ZTCHAR str[2] = {ch, '\0'};
	return this->findOneOfRev(str);
}

inline int ZcString::findLast(ZTCHAR ch, int nEndPos) const
{
	const ZTCHAR str[2] = { ch,'\0' };
	return this->findLastOneOf(str, nEndPos);
}

inline ZcString ZcString::mid(int nStart, int nNumChars) const
{
    return this->substr(nStart, nNumChars);
}

inline ZcString ZcString::mid(int nStart) const
{
    return this->mid(nStart, -1);
}

inline ZcString ZcString::substr(int nNumChars) const
{
	return this->substr(0, nNumChars);
}

inline ZcString ZcString::left(int nNumChars) const
{
    return this->substr(nNumChars);
}

inline ZcString ZcString::right(int nNumChars) const
{
    return this->substrRev(nNumChars);
}

inline ZcString & ZcString::truncate(int nIndex)
{
	this->deleteAtIndex(nIndex, -1);
	return *this;
}

inline ZcString & ZcString::trimLeft(wchar_t wch)
{
    const wchar_t wszChars[] = { wch, L'\0' };
    return this->trimLeft(wszChars);
}

inline ZcString & ZcString::trimLeft()
{
    return this->trimLeft(nullptr);
}

inline ZcString & ZcString::trimRight(wchar_t wch)
{
    const wchar_t wszChars[] = { wch, L'\0' };
    return this->trimRight(wszChars);
}

inline ZcString & ZcString::trimRight()
{
    return this->trimRight(nullptr);
}

inline ZcString & ZcString::trim(wchar_t wch)
{
    const wchar_t wszChars[] = { wch, L'\0' };
    return this->trim(wszChars);
}

inline ZcString & ZcString::trim()
{
    return this->trim(nullptr);
}

inline ZcString & ZcString::trim(const wchar_t *pwszChars)
{
    return this->trimRight(pwszChars).trimLeft(pwszChars);
}

inline ZcString & ZcString::assign(char ch)
{
	const char str[2] = {ch, '\0'};
	return this->assign(str);
}

inline ZcString & ZcString::assign(wchar_t wch)
{
	const wchar_t wstr[2] = {wch, L'\0'};
	return this->assign(wstr);
}

inline ZcString & ZcString::operator = (char ch)
{
    return this->assign(ch);
}

inline ZcString & ZcString::operator = (wchar_t wch)
{
    return this->assign(wch);
}

inline ZcString & ZcString::operator = (const char *psz)
{
    return this->assign(psz);
}

inline ZcString & ZcString::operator = (const wchar_t *pwsz)
{
    return this->assign(pwsz);
}

inline ZcString & ZcString::operator = (const ZcString & acs)
{
    return this->assign(acs);
}

inline ZcString & ZcString::operator = (const ZcDbHandle & h)
{
    return this->assign(h);
}

inline ZcString & ZcString::operator += (char ch)
{
    return this->append(ch);
}

inline ZcString & ZcString::operator += (wchar_t wch)
{
    return this->append(wch);
}

inline ZcString & ZcString::operator += (const char *psz)
{
    return this->append(psz);
}

inline ZcString & ZcString::operator += (const wchar_t *pwsz)
{
    return this->append(pwsz);
}

inline ZcString & ZcString::operator += (const ZcString & acs)
{
    return this->append(acs);
}

inline ZcString & ZcString::append(char ch)
{
	const char str[2] = {ch, '\0'};
	return this->append(str);
}

inline ZcString & ZcString::append(wchar_t wch)
{
	const wchar_t wstr[2] = {wch, L'\0'};
	return this->append(wstr);
}

inline ZcString ZcString::operator + (char ch) const
{
    return this->concat(ch);
}

inline ZcString ZcString::operator + (wchar_t wch) const
{
    return this->concat(wch);
}

inline ZcString ZcString::operator + (const char * psz) const
{
    return this->concat(psz);
}

inline ZcString ZcString::operator + (const wchar_t * pwsz) const
{
    return this->concat(pwsz);
}

inline ZcString ZcString::operator + (const ZcString & acs) const
{
    return this->concat(acs);
}

inline ZcString ZcString::concat(char ch) const
{
	const char str[2] = {ch, '\0'};
	return this->concat(str);
}

inline ZcString ZcString::concat(wchar_t wch) const
{
	const wchar_t wstr[2] = {wch, L'\0'};
	return this->concat(wstr);
}

inline ZcString ZcString::precat(ZTCHAR ch) const
{
	const wchar_t str[2] = {ch, '\0'};
	return this->precat(str);
}

inline int ZcString::compare(wchar_t wch) const
{
	const wchar_t wstr[2] = {wch, L'\0'};
	return this->compare(wstr);
}

inline int ZcString::compareNoCase(wchar_t wch) const
{
	const wchar_t wstr[2] = {wch, L'\0'};
	return this->compareNoCase(wstr);
}

inline int ZcString::collate(const ZcString & acs) const
{
    return this->collate(acs.kwszPtr());
}

inline int ZcString::collateNoCase(const ZcString & acs) const
{
    return this->collateNoCase(acs.kwszPtr());
}

inline bool ZcString::operator == (wchar_t wch) const
{
    return this->compare(wch) == 0;
}

inline bool ZcString::operator == (const char *psz) const
{
    return this->compare(psz) == 0;
}

inline bool ZcString::operator == (const wchar_t *pwsz) const
{
    return this->compare(pwsz) == 0;
}

inline bool ZcString::operator == (const ZcString & acs) const
{
    return this->compare(acs) == 0;
}

inline bool ZcString::operator != (wchar_t wch) const
{
    return this->compare(wch) != 0;
}

inline bool ZcString::operator != (const char *psz) const
{
    return this->compare(psz) != 0;
}

inline bool ZcString::operator != (const wchar_t *pwsz) const
{
    return this->compare(pwsz) != 0;
}

inline bool ZcString::operator != (const ZcString & acs) const
{
    return this->compare(acs) != 0;
}

inline bool ZcString::operator > (wchar_t wch) const
{
    return this->compare(wch) > 0;
}

inline bool ZcString::operator > (const char *psz) const
{
    return this->compare(psz) > 0;
}

inline bool ZcString::operator > (const wchar_t *pwsz) const
{
    return this->compare(pwsz) > 0;
}

inline bool ZcString::operator > (const ZcString & acs) const
{
    return this->compare(acs) > 0;
}

inline bool ZcString::operator >= (wchar_t wch) const
{
    return this->compare(wch) >= 0;
}

inline bool ZcString::operator >= (const char *psz) const
{
    return this->compare(psz) >= 0;
}

inline bool ZcString::operator >= (const wchar_t *pwsz) const
{
    return this->compare(pwsz) >= 0;
}

inline bool ZcString::operator >= (const ZcString & acs) const
{
    return this->compare(acs) >= 0;
}

inline bool ZcString::operator < (wchar_t wch) const
{
    return this->compare(wch) < 0;
}

inline bool ZcString::operator < (const char *psz) const
{
    return this->compare(psz) < 0;
}

inline bool ZcString::operator < (const wchar_t *pwsz) const
{
    return this->compare(pwsz) < 0;
}

inline bool ZcString::operator < (const ZcString & acs) const
{
    return this->compare(acs) < 0;
}

inline bool ZcString::operator <= (char ch) const
{
	return this->compare(ch) <= 0;
}

inline bool ZcString::operator <= (wchar_t wch) const
{
    return this->compare(wch) <= 0;
}

inline bool ZcString::operator <= (const char *psz) const
{
    return this->compare(psz) <= 0;
}

inline bool ZcString::operator <= (const wchar_t *pwsz) const
{
    return this->compare(pwsz) <= 0;
}

inline bool ZcString::operator <= (const ZcString & acs) const
{
    return this->compare(acs) <= 0;
}
inline bool operator == (wchar_t wch, const ZcString & acs)
{
    return acs.compare(wch) == 0;
}

inline bool operator == (const wchar_t *pwsz, const ZcString & acs)
{
    return acs.compare(pwsz) == 0;
}

inline bool operator == (const char *psz, const ZcString & acs)
{
	return acs.compare(psz) == 0;
}

inline bool operator != (wchar_t wch, const ZcString & acs)
{
    return acs.compare(wch) != 0;
}

inline bool operator != (const wchar_t *pwsz, const ZcString & acs)
{
    return acs.compare(pwsz) != 0;
}

inline bool operator != (const char *psz, const ZcString & acs)
{
	return acs.compare(psz) != 0;
}

inline bool operator > (wchar_t wch, const ZcString & acs)
{
    return acs.compare(wch) < 0;
}

inline bool operator > (const wchar_t *pwsz, const ZcString & acs)
{
    return acs.compare(pwsz) < 0;
}

inline bool operator > (const char *psz, const ZcString & acs)
{
	return acs.compare(psz) < 0;
}

inline bool operator >= (wchar_t wch, const ZcString & acs)
{
    return acs.compare(wch) <= 0;
}

inline bool operator >= (const wchar_t *pwsz, const ZcString & acs)
{
    return acs.compare(pwsz) <= 0;
}

inline bool operator >= (const char *psz, const ZcString & acs)
{
	return acs.compare(psz) <= 0;
}

inline bool operator < (wchar_t wch, const ZcString & acs)
{
    return acs.compare(wch) > 0;
}

inline bool operator < (const wchar_t *pwsz, const ZcString & acs)
{
    return acs.compare(pwsz) > 0;
}

inline bool operator < (const char *psz, const ZcString & acs)
{
	return acs.compare(psz) > 0;
}

inline bool operator <= (wchar_t wch, const ZcString & acs)
{
    return acs.compare(wch) >= 0;
}

inline bool operator <= (const wchar_t *pwsz, const ZcString & acs)
{
    return acs.compare(pwsz) >= 0;
}

inline bool operator <= (const char *psz, const ZcString & acs)
{
	return acs.compare(psz) >= 0;
}

inline ZcString operator + (wchar_t ch, const ZcString & acs)
{
    return acs.precat(ch);
}

inline ZcString operator + (const wchar_t *pwsz, const ZcString & acs)
{
    return acs.precat(pwsz);
}

inline ZcString operator + (const char *psz, const ZcString & acs)
{
	return acs.precat(psz);
}

inline bool ZcString::equalsNoCase(const ZcString& left, const ZcString& right)
{
    return left.compareNoCase(right) == 0;
}

class ZcUniqueString
{
public:
    ZCBASE_PORT static const ZcUniqueString *Intern(const wchar_t *);
};

#if defined(_AFX) || defined(__OSX_WINAPI_UNIX_STRING_H__) || defined(__ATLSTR_H__) 

inline ZcString::ZcString(const CStringW &csw) : ZcString()
{
    const wchar_t *pwsz = (const wchar_t *)csw;
    this->clearAll();
    *this = pwsz;
}

inline ZcString & ZcString::operator=(const CStringW &csw)
{
    const wchar_t *pwsz = (const wchar_t *)csw;
    return this->assign(pwsz);
}

inline ZcString & ZcString::operator+=(const CStringW &csw)
{
    const wchar_t *pwsz = (const wchar_t *)csw;
    return this->append(pwsz);
}

inline int ZcString::compare(const CStringW & csw) const
{
    const wchar_t *pwsz = (const wchar_t *)csw;
    return this->compare(pwsz);
}

inline int ZcString::compareNoCase(const CStringW & csw) const
{
    const wchar_t *pwsz = (const wchar_t *)csw;
    return this->compareNoCase(pwsz);
}

inline int ZcString::match(const CStringW & csw) const
{
    const wchar_t *pwsz = (const wchar_t *)csw;
    return this->match(pwsz);
}

inline int ZcString::matchNoCase(const CStringW & csw) const
{
    const wchar_t *pwsz = (const wchar_t *)csw;
    return this->matchNoCase(pwsz);
}

inline bool ZcString::operator == (const CStringW & csw) const
{
    return this->compare(csw) == 0;
}

inline bool ZcString::operator != (const CStringW & csw) const
{
    return this->compare(csw) != 0;
}

inline bool ZcString::operator > (const CStringW & csw) const
{
    return this->compare(csw) > 0;
}

inline bool ZcString::operator >= (const CStringW & csw) const
{
    return this->compare(csw) >= 0;
}

inline bool ZcString::operator < (const CStringW & csw) const
{
    return this->compare(csw) < 0;
}

inline bool ZcString::operator <= (const CStringW & csw) const
{
    return this->compare(csw) <= 0;
}

#if defined(_AFX) && !defined(__cplusplus_cli)
inline bool operator == (const CStringW & csw, const ZcString & acs)
{
    return acs.compare(csw) == 0;
}

inline bool operator != (const CStringW & csw, const ZcString & acs)
{
    return acs.compare(csw) != 0;
}

inline bool operator >  (const CStringW & csw, const ZcString & acs)
{
    return acs.compare(csw) < 0;
}

inline bool operator >= (const CStringW & csw, const ZcString & acs)
{
    return acs.compare(csw) <= 0;
}

inline bool operator <  (const CStringW & csw, const ZcString & acs)
{
    return acs.compare(csw) > 0;
}

inline bool operator <= (const CStringW & csw, const ZcString & acs)
{
    return acs.compare(csw) >= 0;
}

#ifndef DISABLE_CSTRING_PLUS_ZCSTRING
inline ZcString operator + (const CStringW & csw, const ZcString & acs)
{
    const wchar_t *pwsz = (const wchar_t *)csw;
    return acs.precat(pwsz);
}
#endif
#endif
#endif

#ifdef __cpp_lib_string_view
inline ZcString::ZcString(std::wstring_view in)
	:ZcString(in.data(), static_cast<unsigned int>(in.size()))
{
}

inline ZcString& ZcString::operator=(std::wstring_view in)
{
	*this = ZcString(in);
	return *this;
}
#endif

inline ZcString::ZcString(const std::wstring& in)
	:ZcString(in.c_str())
{
}

inline ZcString& ZcString::operator=(const std::wstring& in)
{
	return this->assign(in.c_str());
}

#endif
