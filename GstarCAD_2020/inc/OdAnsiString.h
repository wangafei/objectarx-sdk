/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2011, Open Design Alliance (the "Alliance"). 
// All rights reserved. 
// 
// This software and its documentation and related materials are owned by 
// the Alliance. The software may only be incorporated into application 
// programs owned by members of the Alliance, subject to a signed 
// Membership Agreement and Supplemental Software License Agreement with the
// Alliance. The structure and organization of this software are the valuable  
// trade secrets of the Alliance and its suppliers. The software is also 
// protected by copyright law and international treaty provisions. Application  
// programs incorporating this software must include the following statement 
// with their copyright notices:
//   
//   This application incorporates Teigha(R) software pursuant to a license 
//   agreement with Open Design Alliance.
//   Teigha(R) for .dwg files Copyright (C) 2003-2011 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
//
//
// *DWG is the native and proprietary file format for AutoCAD(R) and a trademark  
// of Autodesk, Inc.  Open Design Alliance is not associated with Autodesk.
///////////////////////////////////////////////////////////////////////////////





#ifndef __ODANSISTRING_H__
#define __ODANSISTRING_H__

//#ifdef DD_UNICODE
#define ODA_CDECL 
#define ODA_PASCAL 

#include <stdarg.h>
#include <stdio.h>
#ifdef sgi
#include <string>
using namespace std;  // va_XXXX items are in std namespace for newest SGI compiler
#endif

//////////////////////////////////////////////////////////////////////////////////////////
// if using CString, define _SUPPORT_MFC_CSTRING_
#if defined(_SUPPORT_MFC_CSTRING_) && defined(_MSC_VER)
  #if _MSC_VER >= 1300 
    namespace ATL { 
      template< typename T, class S > class CStringT;
      template< typename T > class ChTraitsCRT;
    }
    template< typename T, class S > class StrTraitMFC_DLL;
    typedef StrTraitMFC_DLL< wchar_t, class ATL::ChTraitsCRT<wchar_t> > StrTraitMFC_DLL_W;
    typedef ATL::CStringT< wchar_t, StrTraitMFC_DLL_W > CStringW;
    typedef StrTraitMFC_DLL< char, class ATL::ChTraitsCRT<char> > StrTraitMFC_DLL_A;
    typedef ATL::CStringT< char, StrTraitMFC_DLL_A > CStringA;
  #else
    class CString;
  #endif
#endif

#ifndef _SUPPORT_MFC_CSTRING_HOOK_  // DON'T define it!!!
  #include "OdMutex.h"
#else
  #ifndef TD_SINGLE_THREAD
    struct OdRefCounter
    {
      typedef int RefCounterType;
      volatile RefCounterType _ref_count;
    };
  #else
    typedef int OdRefCounter;
  #endif
#endif

#include "OdPlatform.h"
#include "OdArrayPreDef.h"
#include "OdCodePage.h"

#define odaIsValidString(lpch)    (true)
class OdString;

#include "TD_PackPush.h"

/** Description:
This structure contains string *data* used by OdAnsiString.

Remarks:
An char array (buffer) is allocated along with this structure, and
is freed when this structure is freed.

Library: TD_Root
{group:Structs}
*/
struct OdStringDataA
{            
  /** Description:
  Number of references to this string.
  */
  OdRefCounter nRefs;      

  /** Description:
  String length in characters, omitting the 0 terminator.
  */
  int nDataLength; 

  /** Description:
  String allocation length in characters, omitting the 0 terminator. 
  */
  int nAllocLength;       
  
  OdCodePageId codepage;

  /** Description:
  Returns the underlying char array (buffer) of this StringData object.
  */
  char* data()           
  { return (char*)(this+1); }
};

#ifdef _WIN32_WCE
ODA_ASSUME((sizeof(OdStringDataA)%8)==0);
#endif

/** Description:
This structure represents *empty* strings used by OdAnsiString.

{group:Structs}
*/      
struct OdEmptyStringDataA
{
  OdStringDataA  kStrData;
  char        kChar;
};

/** Description:
This class implements Teigha single-byte character string objects.

Remarks:
OdAnsiString objects use zero-based indices to access string elements.

{group:Other_Classes}
*/
class FIRSTDLL_EXPORT OdAnsiString
{
#if defined(_SUPPORT_MFC_CSTRING_) && defined(_MSC_VER)
public:
  #if _MSC_VER >= 1300 
    OdAnsiString(const CStringW& str);
    operator CStringW () const;
    OdAnsiString(const CStringA& str);
    operator CStringA () const;
  #else
    OdAnsiString(const CString& str);
    operator CString () const;
  #endif
#endif

public:
  OdAnsiString();

  /** Arguments:
  source (I) Source.
  */
  OdAnsiString(const OdAnsiString& source);

  /** Arguments:
  ch (I) Character to repeat.
  length (I) Number of characters.
  */
  OdAnsiString(char ch, int length);

  OdAnsiString(const char* source);

  OdAnsiString(const char* source, int length);
  OdAnsiString(const char* source, OdCodePageId);
  OdAnsiString(const char* source, int length, OdCodePageId);
  OdAnsiString(const OdString& , OdCodePageId);

  void setCodepage(OdCodePageId id);
  
  OdCodePageId codepage() const;

  /** Description:
  Returns the number of characters in this String object.
  */
  int getLength() const;

  /** Description:
  Returns true and only if this String object is *empty*.
  */
  bool isEmpty() const;

  /** Description:
  Sets this String object to the *empty* string.
  */
  void empty();

  /** Description:
  Returns the single character of this String object *at* the specified position.
  Arguments:
  charIndex (I) Character *index*. 
  */
  char getAt(int charIndex) const;

  /** Description:
  Indexing Operator

  Remarks:
  Returns the single character of this String object *at* the specified position.
  Arguments:
  charIndex (I) Character *index*. 
  */
  char operator[](int charIndex) const;

  /** Description:
  Sets the single character of this String object *at* the specified position.
  Arguments:
  charIndex (I) Character *index*.
  ch (I) Character.
  Note:
  No range checking is performed.
  */
  void setAt(int charIndex, char ch);

  /** Description:
  Returns the underlying char array (buffer) of this String object.
  */
  const char* c_str() const;

  /** Description:
  Returns the underlying char array (buffer) of this String object.
  */
  operator const char*() const;

  OdAnsiString& operator=(const OdAnsiString& source);

  OdAnsiString& operator=(char ch);

  OdAnsiString& operator=(const char* source);

  OdAnsiString& operator=(const OdString& source);

  /** Description:
  Concatenation-Equals Operator.
  Remarks:
  Sets this object to the concatenation of this String object with the 
  value on the *right*, and returns a reference to this String object.
  */
  OdAnsiString& operator+=(const OdAnsiString& string);

  OdAnsiString& operator+=(char ch);

  OdAnsiString& operator+=(const char* string);

  /** Description:
  Concatenation Operator.
  Remarks:
  Returns the concatenation of this object on the *left* with the object on the *right*.
  */
  friend FIRSTDLL_EXPORT OdAnsiString operator+(const OdAnsiString& string1, const OdAnsiString& string2);
  friend FIRSTDLL_EXPORT OdAnsiString operator+(const OdAnsiString& string, char ch);
  friend FIRSTDLL_EXPORT OdAnsiString operator+(char ch, const OdAnsiString& string);

  friend FIRSTDLL_EXPORT OdAnsiString operator+(const OdAnsiString& string1, const char* string2);
  friend FIRSTDLL_EXPORT OdAnsiString operator+(const char* string1, const OdAnsiString& string2);

  /** Description:
  Case sensitive string comparison.  

  Arguments:
  otherString (I) Other string.

  Remarks:
  compare() returns one of the following:

  @table
  Returns   Condition
  < 0       This String object < otherString. 
  0         This String object == otherString.
  > 0       This String object > otherString.
  */
  int compare(const char* otherString) const;

  /** Description:
  Case insensitive string comparison.  

  Arguments:
  otherString (I) Other string.

  Remarks:
  iCompare() returns one of the following:

  @table
  Returns   Condition
  < 0       This String object < otherString. 
  0         This String object == otherString.
  > 0       This String object > otherString.
  */
  int iCompare(const char* otherString) const;

  /** Description:
  Returns the substring specified by a start index and a *length* from this String object.
  Arguments:
  startIndex (I) Starting index.
  length (I) Length of substring. 

  Remarks:
  If length is not specified, the remainder of this String object is returned.
  */
  OdAnsiString mid(int startIndex, int length) const;

  OdAnsiString mid(int startIndex) const;

  /** Description: 
  Returns the leftmost substring of the specified *length* from this String object.
  Arguments:
  length (I) Length of substring. 
  */
  OdAnsiString left(int length) const;

  /** Description: 
  Returns the rightmost substring of the specified *length* from this String object.
  Arguments:
  length (I) Length of substring. 
  */
  OdAnsiString right(int length) const;

  /** Description:
  Returns the longest leftmost substring of this String object 
  that consists solely of characters that are
  contained in the specified character set.

  Arguments:
  charSet (I) Character set.

  Remarks:
  If the first character in this String object is not in the specified character set,
  an *empty* string is returned.
  */
  OdAnsiString spanIncluding(const char* charSet) const;

  /** Description:
  Returns the longest leftmost substring of this String object 
  that consists solely of characters that are
  not contained in the specified character set.

  Arguments:
  charSet (I) Character set.

  Remarks:
  If the first character in this String object in the specified character set,
  an *empty* string is returned.
  */
  OdAnsiString spanExcluding(const char* charSet) const;

  /** Description:
  Converts this String object to upper case.

  Remarks:
  Returns a reference to this String object.  
  */
  OdAnsiString& makeUpper();

  /** Description:
  Converts this String object to lower case.

  Remarks:
  Returns a reference to this String object.  
  */
  OdAnsiString& makeLower();

  /** Description:
  Reverses this String object.

  Remarks:
  Returns a reference to this String object.  
  */
  OdAnsiString& makeReverse();


  /** Description:
  Removes all whitespace from the *right* side of this String object.

  Remarks:
  Returns a reference to this String object.

  A space (' ') is used if no whitespace characters are specfied.  
  */
  OdAnsiString& trimRight();

  /** Description:
  Removes all whitespace from the *left* side of this String object.

  Remarks:
  Returns a reference to this String object.  

  A space (' ') is used if no other whitespace characters are specfied.  
  */
  OdAnsiString& trimLeft();

  /**
  Arguments:
  whiteChar (I) Whitespace character.
  */
  OdAnsiString& trimRight(char whiteChar);

  /**
  Arguments:
  whiteChars (I) Whitespace characters.
  */
  OdAnsiString& trimRight(const char* whiteChars);

  /**
  Arguments:
  whiteChar (I) Whitespace character.
  */
  OdAnsiString& trimLeft(char whiteChar);

  /**
  Arguments:
  whiteChars (I) Whitespace characters.
  */
  OdAnsiString& trimLeft(const char* whiteChars);

  /** Description:
  Replaces all occurrences of the specified character or string in this String object.

  Arguments:
  oldChar (I) Old character.
  newChar (I) New character.

  Remarks:
  Returns the number of characters or strings replaced.
  */
  int replace(char oldChar, char newChar);

  /**
  Arguments:
  oldString (I) Old string.
  newString (I) New string.
  */
  int replace(const char* oldString, const char* newString);

  /** Description:
  Removes all occurrences of the specified character from this String object.

  Arguments:
  removeChar (I) Character to remove.

  Remarks:
  Returns the number of characters removed.
  */
  int remove(char chRemove);

  /** Description:
  Inserts the specified character or string into this String object.

  Arguments:
  insertChar (I) Character to insert.
  insertIndex (I) Insertion index.

  Remarks:
  Returns the new length of this String object.

  If insertIndex exceeds the length of this String object, 
  this String object is lengthened as necessary to accommodate the insertion.
  */
  int insert(int insertIndex, char insertChar);

  /** Description:
  Arguments:
  insertString (I) String to insert.
  */
  int insert(int insertIndex, const char* insertString);

  /** Description:
  Deletes the specified number characters from this String object.

  Arguments:
  deleteIndex (I) Deletion index.
  count (I) Number of characters to delete.
  Remarks:
  Returns the new length of this String object.
  */
  int deleteChars(int deleteIndex, int count = 1);


  /** Description:
  Returns the first occurrence of the specified character or string in this String object.

  Arguments:
  searchChar (I) Search character.

  Remarks:
  Returns -1 if not found.
  */
  int find(char searchChar) const;

  /** Description:
  Returns the last occurrence of the specified character in this String object.

  Arguments:
  searchChar (I) Search character.

  Remarks:
  Returns -1 if not found.
  */
  int reverseFind(char searchChar) const;

  /**
  Arguments:
  startIndex (I) Start index.
  */
  int find(char searchChar, int startIndex) const;

  /** Description:
  Returns the first occurrence in this String object of any member of the specified character set. 

  Arguments:
  charSet (I) Character set.

  Remarks:
  Returns -1 if not found.
  */
  int findOneOf(const char* charSet) const;

  int find(const char* searchString) const;

  /**
  Arguments:
  searchString (I) Search string.
  */
  int find(const char* searchString, int startIndex) const;

  /** Description: 
  Assigns a value to this String object using a printf-style *format* string and 
  arguments.
  Arguments:
  formatString (I) Format string.
  Remarks:
  Returns a reference to this String Object.
  */
  OdAnsiString& format(const char* formatString, ...);

  /** Description:
  Assigns a value to this String object using a vsprintf-style *format* string and 
  argument list.
  Arguments:
  formatString (I) Format string.
  argList (I) Argument list.   
  Remarks:
  Returns a reference to this String Object.
  */
  OdAnsiString& formatV(const char* formatString, va_list argList); 

  /** Description:
  Returns a modifiable C style char array (buffer) of the specified minimum length for this String object.
  Arguments:
  minBufferLength (I) Minimum buffer *length*.

  Note:
  releaseBuffer() should be called before using any other OdAnsiString methods.

  The pointer returned by this function is not valid after releaseBuffer() is called.
  */
  char* getBuffer(int minBufLength);

  /** Description:
  Releases a buffer obtained by getBuffer() or getBufferSetLength(), and sets its *length*.
  Arguments:
  newLength (I) New buffer *length*.
  Remarks:
  If newLength == -1, the buffer is treated as 0 terminated.  
  */
  void releaseBuffer(int newLength = -1);

  /** Description:
  Returns a modifiable C style char array (buffer) of of the specified length for this String object.
  Arguments:
  length (I) buffer *length*.

  Note:
  releaseBuffer() should be called before using any other OdAnsiString methods.

  The pointer returned by this function is not valid after releaseBuffer() is called.
  */
  char* getBufferSetLength(int length);

  /** Description: 
  Releases any unused memory allocated by this String object.
  */
  void freeExtra();

  /** Description:
  Enables reference counting for this String object.
  */
  char* lockBuffer();

  /** Description:
  Disables reference counting for this String object.
  */
  void unlockBuffer();

public:
  ~OdAnsiString();

  /** Description:
  Returns the number of characters allocated for the underlying char array (buffer) in this String object.
  */
  int getAllocLength() const;

protected:
  FIRSTDLL_EXPORT_STATIC static OdEmptyStringDataA kEmptyData;

  /** Description:
  Pointer to the underlying char array (buffer). 
  */
  char* m_pchData;  

  /** Description:
  Returns the StringData for this String object.
  */
  OdStringDataA* getData() const;

  /** Description:
  Initializes this String object to an *empty* string.
  */
  void init();

  /** Description:
  Copies the specified number of characters from this String object to the destination String object.
  Arguments:
  destString (O) Destination string.
  copyLength (I) Number of characters to copy.
  copyIndex (I) First byte to copy.
  extraLength (I) Extra characters to allocate.

  Remarks:
  This function calls allocBuffer(copyLength + extraLength)
  */
  void allocCopy(OdAnsiString& destString, int copyLength, int copyIndex, int extraLength) const;

  /** Description:
  Allocates the specified number of characters for the character buffer of this String object.
  Arguments:
  length (I) buffer *length*.
  */
  void allocBuffer(int length);

  /* Description:
  Copies the specified string to this String object.

  Arguments:
  sourceLength (I) Number of characters to copy.
  source (I) Source string.

  Remarks:
  If getAllocLength() < sourceLength, this function calls allocBuffer(sourceLength).
  */  
  void assignCopy(int sourceLength, const char* source);

  /* Description:
  Concatenates and copies the specified strings to this String object.

  Arguments:
  sourceLength1 (I) Number of characters in first string to copy.
  sourceLength2 (I) Number of characters in second string to copy.
  source1 (I) First source string.
  source2 (I) Second source string.

  Remarks:
  If getAllocLength() < (sourceLength1 + sourceLength2), this function calls allocBuffer(sourceLength1 + sourceLength2).
  */  
  void concatCopy(int sourceLength1, const char* source1, int sourceLength2, const char* source2);

  /* Description:
  Concatenates the string to this String object.

  Arguments:
  sourceLength (I) Number of characters to copy.
  source (I) Source string.

  Remarks:
  If getAllocLength() < getLength() + sourceLength, this function calls allocBuffer(getLength()+ sourceLength2).
  */  
  void concatInPlace(int sourceLength, const char* source);

  /** Description:
  Assures there are no multiple references to the StringData associated with this String object. 

  Remarks:
  If there is more than one reference to the StringData object, it is released, and
  replaced with a copy thereof 
  */
  void copyBeforeWrite();

  /** Description:
  Assures the character buffer of this String object is at least the specified size.
  Arguments:
  newLength (I) New length of buffer.

  Remarks:
  If getAllocLength() < newLength, this function calls allocBuffer(newLength).
  */
  void allocBeforeWrite(int newLength);

  /** Description:
  Releases the reference to the specified StringData object.

  Arguments:
  pStringData (I) Pointer to the StringData object.

  Remarks:
  If pStringData is not specified, the StringData associated with
  this String object is released.

  Decrements the reference count of the StringData object.

  When its reference count reaches zero, the StringData object is freed.
  */
  void release();

  static void ODA_PASCAL release(OdStringDataA* pStringData);

  /** Description:
  Returns the length of the specified string.
  Arguments:
  string (I) 0 terminated string or NULL.
  Remarks:
  Returns 0 if string == NULL.
  */
#ifndef _SUPPORT_MFC_CSTRING_HOOK_
  static int ODA_PASCAL safeStrlen(const char* string)
  { return (string == NULL) ? (int)0 : (int)odStrLenA(string); }
#else
  static int ODA_PASCAL safeStrlen(const char* string);
#endif

  /** Description:
  Frees the specified StringData object.
  Arguments:
  pStringData (I) Pointer to the StringData object.
  */
  static void freeData(OdStringDataA* pStringData);
  friend class OdString;
};

#ifndef _SUPPORT_MFC_CSTRING_HOOK_

inline OdAnsiString::OdAnsiString()
{ init(); }

inline OdCodePageId OdAnsiString::codepage() const
{ return getData()->codepage; }

inline int OdAnsiString::getLength() const
{ return getData()->nDataLength; }

inline bool OdAnsiString::isEmpty() const
{ return getData()->nDataLength == 0; }

inline char OdAnsiString::getAt(int charIndex) const
{
  ODA_ASSERT(charIndex >= 0);
  ODA_ASSERT(charIndex < getData()->nDataLength);
  return m_pchData[charIndex];
}

inline char OdAnsiString::operator[](int charIndex) const
{
  ODA_ASSERT(charIndex >= 0);
  ODA_ASSERT(charIndex < getData()->nDataLength);
  return m_pchData[charIndex];
}

inline const char* OdAnsiString::c_str() const
{ return m_pchData; }

inline OdAnsiString::operator const char*() const
{ return m_pchData; }

inline int OdAnsiString::compare(const char* otherString) const
{ ODA_ASSERT(odaIsValidString(otherString)); return odStrCmpA(m_pchData, otherString); }    // MBCS/Unicode aware 

inline int OdAnsiString::iCompare(const char* otherString) const
{ ODA_ASSERT(odaIsValidString(otherString)); return odStrICmpA(m_pchData, otherString); }   

inline int OdAnsiString::getAllocLength() const
{ return getData()->nAllocLength; }

inline OdStringDataA* OdAnsiString::getData() const
{ ODA_ASSERT(m_pchData != NULL); return ((OdStringDataA*)m_pchData)-1; }


inline bool operator==(const OdAnsiString& s1, const OdAnsiString& s2)
{ return s1.compare(s2) == 0; }

inline bool operator==(const OdAnsiString& s1, const char* s2)
{ return s1.compare(s2) == 0; }

inline bool operator==(const char* s1, const OdAnsiString& s2)
{ return s2.compare(s1) == 0; }

inline bool operator!=(const OdAnsiString& s1, const OdAnsiString& s2)
{ return s1.compare(s2) != 0; }

inline bool operator!=(const OdAnsiString& s1, const char* s2)
{ return s1.compare(s2) != 0; }

inline bool operator!=(const char* s1, const OdAnsiString& s2)
{ return s2.compare(s1) != 0; }

inline bool operator<(const OdAnsiString& s1, const OdAnsiString& s2)
{ return s1.compare(s2) < 0; }

inline bool operator<(const OdAnsiString& s1, const char* s2)
{ return s1.compare(s2) < 0; }

inline bool operator<(const char* s1, const OdAnsiString& s2)
{ return s2.compare(s1) > 0; }

inline bool operator>(const OdAnsiString& s1, const OdAnsiString& s2)
{ return s1.compare(s2) > 0; }

inline bool operator>(const OdAnsiString& s1, const char* s2)
{ return s1.compare(s2) > 0; }

inline bool operator>(const char* s1, const OdAnsiString& s2)
{ return s2.compare(s1) < 0; }

inline bool operator<=(const OdAnsiString& s1, const OdAnsiString& s2)
{ return s1.compare(s2) <= 0; }

inline bool operator<=(const OdAnsiString& s1, const char* s2)
{ return s1.compare(s2) <= 0; }

inline bool operator<=(const char* s1, const OdAnsiString& s2)
{ return s2.compare(s1) >= 0; }

inline bool operator>=(const OdAnsiString& s1, const OdAnsiString& s2)
{ return s1.compare(s2) >= 0; }

inline bool operator>=(const OdAnsiString& s1, const char* s2)
{ return s1.compare(s2) >= 0; }

inline bool operator>=(const char* s1, const OdAnsiString& s2)
{ return s2.compare(s1) <= 0; }

#endif //_SUPPORT_MFC_CSTRING_HOOK_

typedef OdArray<OdAnsiString> OdAnsiStringArray;

#include "TD_PackPop.h"

//#endif // DD_UNICODE

#endif // __ODANSISTRING_H__


