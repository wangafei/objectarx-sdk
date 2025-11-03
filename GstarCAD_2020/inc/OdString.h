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





#ifndef __ODSTRING_H__
#define __ODSTRING_H__

#include <stdarg.h>
#include <stdio.h>

class OdDbHandle;

#ifdef sgi
#include <string>
using namespace std;  // va_XXXX items are in std namespace for newest SGI compiler
#endif

// Gcad(Add): 增加字符串分配删除处理函数
#include "OdAnsiString.h"

#define odaIsValidString(lpch)    (true)



#include "TD_PackPush.h"

/** Description:
    This structure contains string *data* used by OdString.

    Remarks:
    An OdChar array (buffer) is allocated along with this structure, and
    is freed when this structure is freed.
    
    Library: TD_Root
    {group:Structs}
*/
struct OdStringData
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

  /** Description:
    Underlying OdChar array (buffer) of this StringData object.
  */
  OdChar* unicodeBuffer;
  
  /** Description:
    Underlying char array (buffer) of this StringData object.
  */
  char* ansiString;
};

/** Description:
    This class implements Teigha character String objects.

    Remarks:
    OdString objects use zero-based indices to access string elements.

    {group:Other_Classes}
*/
class FIRSTDLL_EXPORT OdString
{
#if  defined(_AFX) || defined(__ATLSTR_H__)
public:
  OdString(const CStringW &csw);

  OdString & operator = (const CStringW &csw);

  OdString & operator += (const CStringW &csw);

  int  compare(const CStringW & csw) const;

  int  iCompare(const CStringW & csw) const;
  
  int  compareNoCase(const CStringW & csw) const;

  bool operator == (const CStringW &) const;

  bool operator != (const CStringW &) const;

  bool operator <  (const CStringW &) const;

  bool operator <= (const CStringW &) const;

  bool operator >  (const CStringW &) const;
  
  bool operator >= (const CStringW &) const;

  int  match(const CStringW & csw) const;

  int  matchNoCase(const CStringW & csw) const;
#else
public:
  inline operator const char*() const
  {
    return kszPtr();
  }
#endif

public:
  FIRSTDLL_EXPORT_STATIC const static OdString kEmpty;

  enum
  {
    kAppRes = 0x0001,
    kSigned = 0x0002,
    kUnSigned = 0x0003,
    kHex = 0x0004
  };

  OdString();

  // Initialize with a single character.
  // ch : input character
  OdString(char ch);

  // Initialize with a single Unicode character
  // wch : input character
  OdString(wchar_t wch);
  /** Arguments:
    source (I) Source.
  */
  OdString(const OdString& source);

  /** Arguments:
    ch (I) Character to repeat.
    length (I) Number of characters.
  */
  OdString(OdChar ch, int length);

  OdString(const OdChar* source);
  OdString(const OdChar* source, int length);
#if !defined(NATIVE_ODCHAR) && defined(_MSC_VER) && _MSC_VER >= 1300 && !defined(_WIN32_WCE)
  OdString(const __wchar_t* source);
  OdString(const __wchar_t* source, int length);
#endif


  OdString(const char* lpch, OdCodePageId codepage = CP_UNDEFINED);
  OdString(const char* lpch, int nLength, OdCodePageId codepage = CP_UNDEFINED);
  OdString(const OdAnsiString&);

  // Formats an OdDbHandle value in hex, as in: "a2f".
  // h : input reference to an oddb handle value
  OdString(const OdDbHandle &h);

#if defined(_WINBASE_)
  // Loads a resource string from the specified dll handle.
  // hDll : input windows handle to a loaded resource dll
  // nId : input int id of the resource string to load
  OdString(HINSTANCE hDll, unsigned nId);
#endif

  // Get a pointer to the current string (code page based).  This
  // pointer is only valid until the OdString object is next modified!
  const    char * kszPtr() const;
  
  // Get a pointer to the current string (in Unicode).  This pointer
  // is only valid until this OdString object is next modified!
  const wchar_t * kwszPtr() const
  {
    return (const wchar_t *)*this;
  }

  // Get a pointer to the current string as a TCHAR pointer.  In
  // Unicode builds, this will be Unicode, and in multibyte builds
  // it will be code page dependent.  Pointer is only valid until
  // this OdString is next modified.
  const OdChar *  constPtr() const
  {
    return c_str();
  }

  // Get a pointer to the current string in OdChars.
  const OdChar * kACharPtr() const
  {
    return c_str();
  }

  /** Description:
    Returns the number of characters in this String object.
  */
  int getLength() const;

  int getLengthA() const;

  /** Description:
    Returns true and only if this String object is *empty*.
  */
  bool isEmpty() const;

  /** Description:
    Sets this String object to the *empty* string.
  */
  void empty();

  // Return logical length of (i.e. number of chars in) the string.
  // WARNING!!!  Double-byte chars count as a single character.
  // This method does *not* return the *byte* length of the string.
  // If the string contains doublebyte chars, then this method will
  // return a smaller length than the byte length.
  // To get the byte length, please call tcharLength() or lengthA().
  //
  unsigned length() const
  {
    return getLength();
  }

  // Return length of the current string, in TCHAR units.
  // In ansi build, call lengthA(), returning number of bytes.
  // In Unicode build, call lengthW(), returning number of widechars.
  unsigned tcharLength() const
  {
    return length();
  }

  // Returns true if all chars are in the ascii range: 0x20..0x7f
  bool isAscii() const;

  //
  // Parsing methods.
  //
  enum {
    // Enum value allowing caller to specify how to handle errors
    // (invalid chars or overflow) during string parsing.
    kParseZero = 0,       // return zero on errors
    kParseMinus1 = 0x01,  // return -1 or ffff
    kParseAssert = 0x02,  // pop an assert in debug build
    kParseExcept = 0x04,  // throw an int exception
    kParseNoEmpty = 0x08, // treat empty string as error
    kParseDefault = (kParseAssert | kParseZero)
  };

  // Parse the current string as decimal, return a signed int
  // nFlags : input bits specifying how to do the parsing
  int asDeci(int nFlags = kParseDefault) const;

  // Parse the current string as hexadecimal, return a signed int
  // nFlags : input bits specifying how to do the parsing
  int asHex (int nFlags = kParseDefault) const;

  // Parse the current string as decimal, return an unsigned int
  // nFlags : input bits specifying how to do the parsing
  unsigned int asUDeci(int nFlags = kParseDefault) const;

  // Parse the current string as hexadecimal, return an unsigned int
  // nFlags : input bits specifying how to do the parsing
  unsigned int asUHex (int nFlags = kParseDefault) const;

  // Parse the current string as decimal, return a signed int64
  // nFlags : input bits specifying how to do the parsing
  __int64 asDeci64(int nFlags = kParseDefault) const;

  // Parse the current string as hexadecimal, return a signed int64
  // nFlags : input bits specifying how to do the parsing
  __int64 asHex64 (int nFlags = kParseDefault) const;

  // Parse the current string as decimal, return an unsigned int64
  // nFlags : input bits specifying how to do the parsing
  OdUInt64 asUDeci64(int nFlags = kParseDefault) const;

  // Parse the current string as hexadecimal, return an unsigned int64
  // nFlags : input bits specifying how to do the parsing
  OdUInt64 asUHex64 (int nFlags = kParseDefault) const;

  // Parse the current string as hexadecimal.  Return the handle.
  // nFlags : input bits specifying how to do the parsing
  OdDbHandle asOdDbHandle(int nFlags = kParseDefault) const;

  /** Description:
    Returns the single character of this String object *at* the specified position.
    Arguments:
    charIndex (I) Character *index*. 
  */
  OdChar getAt(int charIndex) const;

  /** Description:
    Indexing Operator
    
    Remarks:
    Returns the single character of this String object *at* the specified position.
    Arguments:
    charIndex (I) Character *index*. 
  */
  OdChar operator[](int charIndex) const;

  /** Description:
    Sets the single character of this String object *at* the specified position.
    Arguments:
    charIndex (I) Character *index*.
    ch (I) Character.
    Note:
    No range checking is performed.
  */
  void setAt(int charIndex, OdChar ch);

  /** Description:
    Returns the underlying OdChar array (buffer) of this String object.
  */
  const OdChar* c_str() const;

  const OdChar* kTCharPtr() const
  {
    return c_str();
  }
  /** Description:
    Returns the underlying character array (buffer) of this String object.
  */
  operator const OdChar*() const;

#if !defined(NATIVE_ODCHAR) && defined(_MSC_VER) && _MSC_VER >= 1300 && !defined(_WIN32_WCE)
  operator const __wchar_t*() const;
#endif
  
  // Copy the string and append a char to it
  // ch : input char to append to the string copy
  OdString concat(char ch) const
  {
    return operator+(ch);
  }

  // Copy the string and append a Unicode char to it
  // ch : input char to append to the string copy
  OdString concat(wchar_t wch) const
  {
    return operator+(wch);
  }

  // Copy the string and append a string of chars to it
  // psz : input pointer to the string to append
  OdString concat(const char * psz) const
  {
    return operator+(psz);
  }

  // Copy the string and append a string of Unicode chars to it
  // pwsz : input pointer to the string to append
  OdString concat(const wchar_t * pwsz) const
  {
    return operator+(pwsz);
  }

  // Copy the string and append an OdString to it
  // pwsz : input reference to the OdString to append
  OdString concat(const OdString & ods) const
  {
    return operator+(ods);
  }

  // These copy the current string and then insert the char or
  // string in front of it.  They're used by the global "+" operators.

  // Copy the string and insert a char in front of it
  // ch : input char to insert
  OdString precat(OdChar ch) const
  {
    return OdString(ch) + *this;
  }

  // Copy the string and insert a string of chars in front of it
  // psz : input pointer to the string of chars to insert
  OdString precat(const char * psz) const
  {
    return OdString(psz) + *this;
  }

  // Copy the string and insert a string of chars in front of it
  // psz : input pointer to the string of chars to insert
  OdString precat(const wchar_t * psz) const
  {
    return OdString(psz) + *this;
  }

  OdString& operator=(const OdString& source);

  OdString& operator=(OdChar ch);
  
  OdString& operator=(const OdChar* source);

#if !defined(NATIVE_ODCHAR) && defined(_MSC_VER) && _MSC_VER >= 1300 && !defined(_WIN32_WCE)
  OdString& operator=(const __wchar_t* source);
#endif

  OdString& operator=(const OdAnsiString& source);

  OdString& operator=(const char* source);

  /** Description:
    Concatenation-Equals Operator.
    Remarks:
    Sets this object to the concatenation of this String object with the 
    value on the *right*, and returns a reference to this String object.
  */
  OdString& operator+=(const OdString& string);

  OdString& operator+=(OdChar ch);

  OdString& operator+=(const OdChar* string);

#if !defined(NATIVE_ODCHAR) && defined(_MSC_VER) && _MSC_VER >= 1300 && !defined(_WIN32_WCE)
  OdString& operator+=(const __wchar_t* string);
#endif

  OdString& operator+=(const char* string);

  // Copy the string and append a char to it
  // ch : input char to append to the string copy
  OdString operator + (char ch) const
  {
    return operator+(OdString(ch));
  }

  // Copy the string and append a Unicode char to it
  // ch : input char to append to the string copy
  OdString operator + (wchar_t wch) const;

  // Copy the string and append a string of chars to it
  // psz : input pointer to the string to append
  OdString operator + (const char * psz) const
  {
    return operator+(OdString(psz));
  }

  // Copy the string and append a string of Unicode chars to it
  // pwsz : input pointer to the string to append
  OdString operator + (const wchar_t * pwsz) const;

  // Copy the string and append an OdString to it
  // pwsz : input reference to the OdString to append
  OdString operator + (const OdString & ods) const;
  /** Description:
    Concatenation Operator.
    Remarks:
    Returns the concatenation of this object on the *left* with the object on the *right*.
  */
  friend FIRSTDLL_EXPORT OdString operator+(OdChar ch, const OdString& string);

  friend FIRSTDLL_EXPORT OdString operator+(const OdChar* string1, const OdString& string2);

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
  int compare(char ch) const;

  int compare(wchar_t wch) const;

  int compare(const OdChar* otherString) const;

  int compare(const OdString& otherString) const;

#if !defined(NATIVE_ODCHAR) && defined(_MSC_VER) && _MSC_VER >= 1300 && !defined(_WIN32_WCE)
  int compare(const __wchar_t* otherString) const;
#endif

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
  int iCompare(char ch) const;

  int iCompare(wchar_t wch) const;

  int iCompare(const char* otherString) const;

  int iCompare(const OdChar* otherString) const;

  int iCompare(const OdString& otherString) const;

#if !defined(NATIVE_ODCHAR) && defined(_MSC_VER) && _MSC_VER >= 1300 && !defined(_WIN32_WCE)
  int iCompare(const __wchar_t* otherString) const;
#endif   

  // Compare the string case-independently to a Unicode char
  // wch : input char to compare to
  int  compareNoCase(wchar_t wch) const
  {
    return iCompare(wch);
  }

  // Compare the string case-independently to a string of chars
  // psz : input pointer to the string of chars to compare to
  int  compareNoCase(const char *psz) const
  {
    return iCompare(psz);
  }

  // Compare the string case-independently to a string of Unicode chars
  // pwsz : input pointer to the string of chars to compare to
  int  compareNoCase(const wchar_t *pwsz) const
  {
    return iCompare(pwsz);
  }

  // Compare the string case-independently to another OdString
  // ods : input reference to the other OdString
  int  compareNoCase(const OdString & ods) const
  {
    return iCompare(ods);
  }

  /** Description:
    Returns the substring specified by a start index and a *length* from this String object.
    Arguments:
    startIndex (I) Starting index.
    length (I) Length of substring. 
    
    Remarks:
    If length is not specified, the remainder of this String object is returned.
  */
  OdString mid(int startIndex, int length) const;

  OdString mid(int startIndex) const;

  // Get a substring from the start of string.
  // nNumChars : input number of chars (not bytes) to retrieve.
  //             if nNumChars is -1, then return the rest of the string
  OdString substr(int numChars) const
  {
    return left(numChars);
  }

  // Get a substring from the string.  (same as mid() method)
  // nStart : input index (in bytes) from the start of the string
  // nNumChars : input number of chars (not bytes) to retrieve.
  //             if nNumChars is -1, then return the rest of the string
  OdString substr(int nStart, int nNumChars) const
  {
    return mid(nStart, nNumChars);
  }

  // Get a substring from the end of string.
  // nNumChars : input number of chars (not bytes) to retrieve.
  OdString substrRev(int numChars) const
  {
    return right(numChars);
  }

  /** Description: 
    Returns the leftmost substring of the specified *length* from this String object.
    Arguments:
    length (I) Length of substring. 
  */
  OdString left(int length) const;

  /** Description: 
    Returns the rightmost substring of the specified *length* from this String object.
    Arguments:
    length (I) Length of substring. 
  */
  OdString right(int length) const;

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
  OdString spanIncluding(const OdChar* charSet) const;
  
  OdString spanIncluding(const OdString& charSet) const;

#if !defined(NATIVE_ODCHAR) && defined(_MSC_VER) && _MSC_VER >= 1300 && !defined(_WIN32_WCE)
  OdString spanIncluding(const __wchar_t* charSet) const;
#endif

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
  OdString spanExcluding(const OdChar* charSet) const;

  OdString spanExcluding(const OdString& charSet) const;

#if !defined(NATIVE_ODCHAR) && defined(_MSC_VER) && _MSC_VER >= 1300 && !defined(_WIN32_WCE)
  OdString spanExcluding(const __wchar_t* charSet) const;
#endif
  
  /** Description:
    Converts this String object to upper case.

    Remarks:
    Returns a reference to this String object.  
  */
  OdString& makeUpper();

  /** Description:
    Converts this String object to lower case.

    Remarks:
    Returns a reference to this String object.  
  */
  OdString& makeLower();

  /** Description:
    Reverses this String object.

    Remarks:
    Returns a reference to this String object.  
  */
  OdString& makeReverse();


  /** Description:
    Removes all whitespace from the *right* side of this String object.
   
    Remarks:
    Returns a reference to this String object.
    
    A space (' ') is used if no whitespace characters are specfied.  
  */
  OdString& trimRight();

  /** Description:
    Removes all whitespace from the *left* side of this String object.
   
    Remarks:
    Returns a reference to this String object.  

    A space (' ') is used if no other whitespace characters are specfied.  
  */
  OdString& trimLeft();

  /**
    Arguments:
    whiteChar (I) Whitespace character.
  */
  OdString& trimRight(OdChar whiteChar);

  /**
    Arguments:
    whiteChars (I) Whitespace characters.
  */
  OdString& trimRight(const OdChar* whiteChars);

  OdString& trimRight(const OdString& whiteChars);

#if !defined(NATIVE_ODCHAR) && defined(_MSC_VER) && _MSC_VER >= 1300 && !defined(_WIN32_WCE)
  OdString& trimRight(const __wchar_t* whiteChars);
#endif

  /**
    Arguments:
    whiteChar (I) Whitespace character.
  */
  OdString& trimLeft(OdChar whiteChar);

  /**
    Arguments:
    whiteChars (I) Whitespace characters.
  */
  OdString& trimLeft(const OdChar* whiteChars);
  
  OdString& trimLeft(const OdString& whiteChars);

#if !defined(NATIVE_ODCHAR) && defined(_MSC_VER) && _MSC_VER >= 1300 && !defined(_WIN32_WCE)
  OdString& trimLeft(const __wchar_t* whiteChars);
#endif
  /** Description:
    Replaces all occurrences of the specified character or string in this String object.

    Arguments:
    oldChar (I) Old character.
    newChar (I) New character.
    
    Remarks:
    Returns the number of characters or strings replaced.
   */
  int replace(OdChar oldChar, OdChar newChar);

  /**
    Arguments:
    oldString (I) Old string.
    newString (I) New string.
  */
  int replace(const OdChar* oldString, const OdChar* newString);
  
  int replace(const OdString& oldString, const OdString& newString);

#if !defined(NATIVE_ODCHAR) && defined(_MSC_VER) && _MSC_VER >= 1300 && !defined(_WIN32_WCE)
  int replace(const __wchar_t* oldString, const __wchar_t* newString);
#endif
  /** Description:
    Removes all occurrences of the specified character from this String object.

    Arguments:
    removeChar (I) Character to remove.

    Remarks:
    Returns the number of characters removed.
  */
  int remove(OdChar chRemove);

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
  int insert(int insertIndex, OdChar insertChar);

  /** Description:
    Arguments:
    insertString (I) String to insert.
  */

  int insert(int insertIndex, const OdChar* insertString);

  int insert(int insertIndex, const OdString& insertString);

#if !defined(NATIVE_ODCHAR) && defined(_MSC_VER) && _MSC_VER >= 1300 && !defined(_WIN32_WCE)
  int insert(int insertIndex, const __wchar_t* insertString);
#endif
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
  int find(OdChar searchChar) const;

  /**
    Arguments:
    startIndex (I) Start index.
  */
  int find(OdChar searchChar, int startIndex) const;

  /** Description:
    Returns the last occurrence of the specified character in this String object.

    Arguments:
    searchChar (I) Search character.
     
    Remarks:
    Returns -1 if not found.
  */
  int reverseFind(OdChar searchChar) const;

  /** Description:
    Returns the first occurrence in this String object of any member of the specified character set. 

    Arguments:
    charSet (I) Character set.
     
    Remarks:
    Returns -1 if not found.
  */
  int findOneOf(const OdChar* charSet) const;

  int findOneOf(const OdString& charSet) const;

#if !defined(NATIVE_ODCHAR) && defined(_MSC_VER) && _MSC_VER >= 1300
  int findOneOf(const __wchar_t* charSet) const;
#endif

  /**
    Arguments:
    searchString (I) Search string.
  */
  int find(const OdChar* searchString) const;

  int find(const OdChar* searchString, int startIndex) const;

  int find(const OdString& searchString) const;

  int find(const OdString& searchString, int startIndex) const;

#if !defined(NATIVE_ODCHAR) && defined(_MSC_VER) && _MSC_VER >= 1300
  int find(const __wchar_t* searchString) const;

  int find(const __wchar_t* searchString, int startIndex) const;
#endif

  // Find last occurrence of a char in the string
  // ch : input char to search for
  int findRev(OdChar ch) const
  {
    return reverseFind(ch);
  }

  // Find last occurrence of any of a group of chars in the string
  // psz : input pointer to string of chars to search for
  int findRev(const OdChar *psz) const;

  // Find last occurrence of a group of chars in the string
  // psz : input ptr to the string of chars to search for
  int findOneOfRev(const OdChar *psz) const;

  // Find last occurrence of a string in the string
  // ods : input reference to the string to search for
  int findRev(const OdString & ods) const
  {
    return findRev((const OdChar*)ods);
  }

  /** Description: 
    Assigns a value to this String object using a printf-style *format* string and 
    arguments.
    Arguments:
    formatString (I) Format string.
    Remarks:
    Returns a reference to this String Object.
  */
  OdString& format(const OdChar* formatString, ...);

  /** Description:
    Assigns a value to this String object using a vsprintf-style *format* string and 
    argument list.
    Arguments:
    formatString (I) Format string.
    argList (I) Argument list.   
    Remarks:
    Returns a reference to this String Object.
  */
  OdString& formatV(const OdChar* formatString, va_list argList); 

#if !defined(NATIVE_ODCHAR) && defined(_MSC_VER) && _MSC_VER >= 1300 && !defined(_WIN32_WCE)
  OdString& formatV(const __wchar_t* formatString, va_list argList);
#endif
                                                                
  /** Description:
    Returns a modifiable C style OdChar array (buffer) of the specified minimum length for this String object.
    Arguments:
    minBufferLength (I) Minimum buffer *length*.
    
    Note:
    releaseBuffer() should be called before using any other OdString methods.
    
    The pointer returned by this function is not valid after releaseBuffer() is called.
  */
  OdChar* getBuffer(int minBufLength);

  /** Description:
    Releases a buffer obtained by getBuffer() or getBufferSetLength(), and sets its *length*.
    Arguments:
    newLength (I) New buffer *length*.
    Remarks:
    If newLength == -1, the buffer is treated as 0 terminated.  
  */
  void releaseBuffer(int newLength = -1);

  /** Description:
    Returns a modifiable C style OdChar array (buffer) of of the specified length for this String object.
    Arguments:
    length (I) buffer *length*.
    
    Note:
    releaseBuffer() should be called before using any other OdString methods.
    
    The pointer returned by this function is not valid after releaseBuffer() is called.
  */
  OdChar* getBufferSetLength(int length);

  /** Description: 
    Releases any unused memory allocated by this String object.
  */
  void freeExtra();

  /** Description:
    Enables reference counting for this String object.
  */
  OdChar* lockBuffer();

  /** Description:
    Disables reference counting for this String object.
  */
  void unlockBuffer();
  //修改Ansi字符串的代码页
  void setAnsiStrCodePage(OdCodePageId codepage);

/*   disable wide char functionalities
   Constructor.  This OdString will receive a copy of the wide character string referenced
   by lpsz.
  OdString(const OdCharW* lpsz);

  Constructor. This OdString will receive a copy of the first nLength wide characters of
  the string referenced by lpch.
  OdString(const OdCharW* lpch, int nLength);

   Assignment operator.  This OdString is assigned the value of lpsz.
  const OdString& operator=(const OdCharW* lpsz);

*/

#ifdef NOT_IMPLEMENTED

  /* { Secret } */
  /** Description:
    Case sensitive string comparison.  
    
    Arguments:
    otherString (I) Other string.
    
    Remarks:
    collate() returns one of the following:
    
    @table
    Returns   Condition
    < 0       This String object < otherString. 
    0         This String object == otherString.
    > 0       This String object > otherString.
  */
  int collate(const OdChar* otherString) const;

  /* { Secret } */
  /** Description:
    Case insensitive string comparison.  
    
    Arguments:
    otherString (I) Other string.
    
    Remarks:
    icollate() returns one of the following:
    
    @table
    Returns   Condition
    < 0       This String object < otherString. 
    0         This String object == otherString.
    > 0       This String object > otherString.
  */
  int iCollate(const OdChar* otherString) const;
  /**
    Arguments:
    formatID (I) Format ID. 
  */
  OdString& ODA_CDECL format(unsigned int formatID, ...);
#endif

  //
  // Assignment operators and methods
  //

  // assign a char to the string
  // ch : input char to assign
  OdString & assign(char ch)
  {
    return operator=(ch);
  }

  // assign a Unicode char to the string
  // wch : input char to assign
  OdString & assign(wchar_t wch)
  {
    return operator=(wch);
  }

  // assign a string of chars to the string
  // psz : input pointer to the string of chars to assign
  OdString & assign(const char *psz)
  {
    return operator=(psz);
  }

  // assign a string of Unicode chars to the string
  // pwsz : input pointer to the string of chars to assign
  OdString & assign(const wchar_t *pwsz)
  {
    return operator=(pwsz);
  }

  // assign an OdString object to the string
  // ods : input reference to the OdString
  OdString & assign(const OdString & ods)
  {
    return operator=(ods);
  }

  // assign an OdDbHandle object to the string (format it as hex)
  // h : input reference to the OdDbHandle object
  OdString & assign(const OdDbHandle & h)
  {
    return operator=(h);
  }

  // append an ansi char to the end of the string
  // ch : input char to append
  OdString & append(char ch)
  {
    return operator+=(ch);
  }

  // append a Unicode char to the end of the string
  // wch : input char to append
  OdString & append(wchar_t wch)
  {
    return operator+=(wch);
  }

  // append a char string to the end of the string
  // psz : input pointer to the char string
  OdString & append(const char *psz)
  {
    return operator+=(psz);
  }

  // append a Unicode string to the end of the string
  // pwsz : input pointer to the Unicode string
  OdString & append(const wchar_t *pwsz)
  {
    return operator+=(pwsz);
  }

  // append an OdString object to the end of the string
  // ods : input reference to the OdString
  OdString & append(const OdString & ods)
  {
    return operator+=(ods);
  }

  // Set the string to be empty.
  OdString & setEmpty()
  {
    empty();
    return *this;
  }

  // Set the string from a resource string
  // nId : input id of the string resource in the current mfc resource dll
  bool loadString(unsigned nId);

#if defined(_WINBASE_)
  // Set the string from a resource string
  // hDll : input windows handle to a loaded resource dll
  // nId : input id of the string resource in the specified resource dll
  bool loadString(HINSTANCE hDll, unsigned nId);
#endif

  // The match() methods return how many chars (not bytes) match
  // between two strings.  Not fully implemented yet (non-ascii
  // chars not supported yet).

  // Return the number of chars that match a string of chars
  // psz : input pointer to the string of chars
  int  match(const char *psz) const
  {
    return match(OdString(psz));
  }

  // Return the number of chars matching a string of Unicode chars
  // pwsz : input pointer to the string of chars
  int  match(const wchar_t *pwsz) const
  {
    return match(OdString(pwsz));
  }

  // Return the number of chars matching another OdString
  // ods : input reference to the other OdString
  int  match(const OdString & ods) const;

  // Return number of chars case-independently matching a string of chars
  // psz : input pointer to the string of chars
  int  matchNoCase(const char *psz) const
  {
    return matchNoCase(OdString(psz));
  }

  // Return number of chars case-indep'ly matching a string of Unicode chars
  // pwsz : input pointer to the string of chars
  int  matchNoCase(const wchar_t *pwsz) const
  {
    return matchNoCase(OdString(pwsz));
  }

  // Return number of chars case-indep'ly matching another OdString
  // ods : input reference to the other OdString
  int  matchNoCase(const OdString & ods) const;

public:
  bool operator == (char ch) const;

  bool operator == (wchar_t wch) const;

  bool operator == (const char *psz) const;

  bool operator == (const wchar_t *pwsz) const;

  bool operator == (const OdString & ods) const;

  bool operator != (char ch) const;

  bool operator != (wchar_t wch) const;

  bool operator != (const char *psz) const;

  bool operator != (const wchar_t *pwsz) const;

  bool operator != (const OdString & ods) const;

  bool operator >  (char ch) const;

  bool operator >  (wchar_t wch) const;

  bool operator >  (const char *psz) const;

  bool operator >  (const wchar_t *pwsz) const;

  bool operator >  (const OdString & ods) const;

  bool operator >= (char ch) const;

  bool operator >= (wchar_t wch) const;

  bool operator >= (const char *psz) const;

  bool operator >= (const wchar_t *pwsz) const;

  bool operator >= (const OdString & ods) const;

  bool operator <  (char ch) const;

  bool operator <  (wchar_t wch) const;

  bool operator <  (const char *psz) const;

  bool operator <  (const wchar_t *pwsz) const;

  bool operator <  (const OdString & ods) const;

  bool operator <= (char wch) const;

  bool operator <= (wchar_t wch) const;

  bool operator <= (const char *psz) const;

  bool operator <= (const wchar_t *pwsz) const;

  bool operator <= (const OdString & ods) const;

public:
  ~OdString();

  /** Description:
    Returns the number of characters allocated for the underlying OdChar array (buffer) in this String object.
  */
  int getAllocLength() const;

protected:
  FIRSTDLL_EXPORT_STATIC static OdStringData kEmptyData;

  /** Description:
    Pointer to the underlying OdChar array (buffer). 
  */
  OdStringData* m_pData;  
  
  /** Description:
    Returns the StringData for this String object.
  */
  OdStringData* getData() const;

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
  void allocCopy(OdString& destString, int copyLength, int copyIndex, int extraLength) const;

  /** Description:
    Allocates the specified number of characters for the character buffer of this String object.
    Arguments:
    length (I) buffer *length*.
    allocAlways - if true, allocates new OdStringData even for 0 length unicode buffer (for ansi string constructors)
  */
  void allocBuffer(int length, bool allocAlways = false);

  /* Description:
    Copies the specified string to this String object.
    
    Arguments:
    sourceLength (I) Number of characters to copy.
    source (I) Source string.

    Remarks:
    If getAllocLength() < sourceLength, this function calls allocBuffer(sourceLength).
  */  
  void assignCopy(int sourceLength, const OdChar* source);

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
  void concatCopy(int sourceLength1, const OdChar* source1, int sourceLength2, const OdChar* source2);

  /* Description:
    Concatenates the string to this String object.
    
    Arguments:
    sourceLength (I) Number of characters to copy.
    source (I) Source string.

    Remarks:
    If getAllocLength() < getLength() + sourceLength, this function calls allocBuffer(getLength()+ sourceLength2).
  */  
  void concatInPlace(int sourceLength, const OdChar* source);
 
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

  static void release(OdStringData* pStringData);

  /** Description:
    Returns the length of the specified string.
    Arguments:
    string (I) 0 terminated string or NULL.
    Remarks:
    Returns 0 if string == NULL.
  */
#ifndef _SUPPORT_MFC_CSTRING_HOOK_
  static int safeStrlen(const OdChar* string)
  { return (string == NULL) ? (int)0 : (int)odStrLen((const wchar_t*)string); }
#else
  static int safeStrlen(const OdChar* string);
#endif

  /** Description:
    Frees the specified StringData object.
    Arguments:
    pStringData (I) Pointer to the StringData object.
  */
  static void freeData(OdStringData* pStringData);

  bool isUnicodeNotInSync() const;

  void syncUnicode() const;
  void syncUnicodeSafe() const;

  OdAnsiString* getAnsiString() const;

  void freeAnsiString()const;

  friend class OdAnsiString;
  friend class OdGetStringData;
};

typedef OdChar OdCharW;
typedef OdString OdWString;


#ifndef _SUPPORT_MFC_CSTRING_HOOK_

inline OdString::OdString()
  { init(); }

inline OdStringData* OdString::getData() const
  { ODA_ASSERT(m_pData!= NULL); return m_pData; }

inline int OdString::getAllocLength() const
  { return getData()->nAllocLength; }

inline bool OdString::isUnicodeNotInSync() const
  { return !getData()->unicodeBuffer && getData()->ansiString; }

inline void OdString::syncUnicodeSafe() const
  {
    if (isUnicodeNotInSync())
      syncUnicode();
  }

inline OdAnsiString* OdString::getAnsiString() const
  {
    if (getData()->ansiString)
      return reinterpret_cast<OdAnsiString*>(&getData()->ansiString);
    else 
      return 0;
  }

inline int OdString::getLength() const
  { 
    syncUnicodeSafe();
    return getData()->nDataLength; 
  }

inline bool OdString::isEmpty() const
  {
    return (getData()->nDataLength == 0 && getData()->ansiString == 0)
      || (getData()->nDataLength == 0 && getData()->ansiString != 0 && getAnsiString()->isEmpty());
  }

inline OdChar OdString::getAt(int charIndex) const
  {
    syncUnicodeSafe(); 
    ODA_ASSERT(charIndex >= 0);
    ODA_ASSERT(charIndex < getData()->nDataLength);
    return getData()->unicodeBuffer[charIndex];
  }

inline OdChar OdString::operator[](int charIndex) const
  { return getAt(charIndex); }

inline const OdChar* OdString::c_str() const
  { 
    syncUnicodeSafe();
    return getData()->unicodeBuffer; 
  }

inline OdString::operator const OdChar*() const
  { return c_str(); }

inline int OdString::compare(char ch) const
{
  const char str[2] = { ch, '\0' };
  return compare(str);
}

inline int OdString::compare(wchar_t wch) const
{
  const wchar_t wstr[2] = { wch, L'\0' };
  return compare(wstr);
}

inline int OdString::compare(const OdChar* otherString) const
  { 
    syncUnicodeSafe();
    return odStrCmp((const wchar_t*)getData()->unicodeBuffer, (const wchar_t*)otherString);
  }

inline int OdString::iCompare(char ch) const
{
  const char str[2] = { ch, '\0' };
  return iCompare(str);
}

inline int OdString::iCompare(wchar_t wch) const
{
  const wchar_t wstr[2] = { wch, L'\0' };
  return iCompare(wstr);
}

inline int OdString::iCompare(const OdChar* otherString) const
  { 
    syncUnicodeSafe();
    return odStrICmp((const OdChar*)getData()->unicodeBuffer, (const OdChar*)otherString); 
  }

inline int OdString::compare(const OdString& otherString) const
  { return compare(otherString.c_str()); }

inline int OdString::iCompare(const OdString& otherString) const
  { return iCompare(otherString.c_str()); }

inline OdString OdString::spanIncluding(const OdString& charSet) const
  { return spanIncluding(charSet.c_str()); }

inline OdString OdString::spanExcluding(const OdString& charSet) const
  { return spanExcluding(charSet.c_str()); }

inline OdString& OdString::trimRight(const OdString& whiteChars)
  { return trimRight(whiteChars.c_str()); }

inline OdString& OdString::trimLeft(const OdString& whiteChars)
  { return trimLeft(whiteChars.c_str()); }

inline int OdString::replace(const OdString& oldString, const OdString& newString)
  { return replace(oldString.c_str(), newString.c_str()); }

inline int OdString::insert(int insertIndex, const OdString& insertString)
  { return insert(insertIndex, insertString.c_str()); }

inline int OdString::find(OdChar ch) const
  { return find(ch, 0); }

inline int OdString::find(const OdChar* lpszSub) const
  { return find(lpszSub, 0); }

inline int OdString::find(const OdString& searchString) const
  { return find(searchString.c_str()); }

inline int OdString::find(const OdString& searchString, int startIndex) const
  { return find(searchString.c_str(), startIndex); }

inline int OdString::findOneOf(const OdString& charSet) const
  { return findOneOf(charSet.c_str()); }

#if !defined(NATIVE_ODCHAR) && defined(_MSC_VER) && _MSC_VER >= 1300
inline OdString::operator const __wchar_t*() const
  { return reinterpret_cast<const __wchar_t*>(c_str()); }

inline OdString& OdString::operator=(const __wchar_t* source)
  { return operator=((const OdChar*)source); }

inline OdString& OdString::operator+=(const __wchar_t* string)
  { return operator+=((const OdChar*)string); }

inline int OdString::compare(const __wchar_t* otherString) const
  { return compare((const OdChar*)otherString); }

inline int OdString::iCompare(const __wchar_t* otherString) const
  { return iCompare((const OdChar*)otherString); }

inline OdString OdString::spanIncluding(const __wchar_t* charSet) const
  { return spanIncluding((const OdChar*)charSet); }

inline OdString OdString::spanExcluding(const __wchar_t* charSet) const
  { return spanExcluding((const OdChar*)charSet); }

inline OdString& OdString::trimRight(const __wchar_t* whiteChars)
  { return trimRight((const OdChar*)whiteChars); }

inline OdString& OdString::trimLeft(const __wchar_t* whiteChars)
  { return trimLeft((const OdChar*)whiteChars); }

inline int OdString::replace(const __wchar_t* oldString, const __wchar_t* newString)
  { return replace((const OdChar*)oldString, (const OdChar*)newString); }

inline int OdString::insert(int insertIndex, const __wchar_t* insertString)
  { return insert(insertIndex,(const OdChar*)insertString); }

inline int OdString::findOneOf(const __wchar_t* charSet) const
  { return findOneOf((const OdChar*)charSet); }

inline int OdString::find(const __wchar_t* searchString) const
  { return find((const OdChar*)searchString); }

inline int OdString::find(const __wchar_t* searchString, int startIndex) const
  { return find((const OdChar*)searchString,startIndex); }

inline OdString& OdString::formatV(const __wchar_t* formatString, va_list argList) 
  { return formatV((const OdChar*)formatString, argList); }
#endif


#if !defined(NATIVE_ODCHAR) && defined(_MSC_VER) && _MSC_VER >= 1300
inline OdString operator+(const __wchar_t* string1, const OdString& string2)
  { return operator+((const OdChar*)string1, string2); }
#endif

inline bool OdString::operator == (char ch) const
{
  return compare(ch) == 0;
}

inline bool OdString::operator == (wchar_t wch) const
{
  return compare(wch) == 0;
}

inline bool OdString::operator == (const char *psz) const
{
  return compare(psz) == 0;
}

inline bool OdString::operator == (const wchar_t *pwsz) const
{
  return compare(pwsz) == 0;
}

inline bool OdString::operator == (const OdString & ods) const
{
  return compare(ods) == 0;
}

inline bool OdString::operator != (char ch) const
{
  return compare(ch) != 0;
}

inline bool OdString::operator != (wchar_t wch) const
{
  return compare(wch) != 0;
}

inline bool OdString::operator != (const char *psz) const
{
  return compare(psz) != 0;
}

inline bool OdString::operator != (const wchar_t *pwsz) const
{
  return compare(pwsz) != 0;
}

inline bool OdString::operator != (const OdString & ods) const
{
  return compare(ods) != 0;
}

inline bool OdString::operator > (char ch) const
{
  return compare(ch) > 0;
}

inline bool OdString::operator > (wchar_t wch) const
{
  return compare(wch) > 0;
}

inline bool OdString::operator > (const char *psz) const
{
  return compare(psz) > 0;
}

inline bool OdString::operator > (const wchar_t *pwsz) const
{
  return compare(pwsz) > 0;
}

inline bool OdString::operator > (const OdString & ods) const
{
  return compare(ods) > 0;
}

inline bool OdString::operator >= (char ch) const
{
  return compare(ch) >= 0;
}

inline bool OdString::operator >= (wchar_t wch) const
{
  return compare(wch) >= 0;
}

inline bool OdString::operator >= (const char *psz) const
{
  return compare(psz) >= 0;
}

inline bool OdString::operator >= (const wchar_t *pwsz) const
{
  return compare(pwsz) >= 0;
}

inline bool OdString::operator >= (const OdString & ods) const
{
  return compare(ods) >= 0;
}

inline bool OdString::operator < (char ch) const
{
  return compare(ch) < 0;
}

inline bool OdString::operator < (wchar_t wch) const
{
  return compare(wch) < 0;
}

inline bool OdString::operator < (const char *psz) const
{
  return compare(psz) < 0;
}

inline bool OdString::operator < (const wchar_t *pwsz) const
{
  return compare(pwsz) < 0;
}

inline bool OdString::operator < (const OdString & ods) const
{
  return compare(ods) < 0;
}

inline bool OdString::operator <= (char ch) const
{
  return compare(ch) <= 0;
}

inline bool OdString::operator <= (wchar_t wch) const
{
  return compare(wch) <= 0;
}

inline bool OdString::operator <= (const char *psz) const
{
  return compare(psz) <= 0;
}

inline bool OdString::operator <= (const wchar_t *pwsz) const
{
  return compare(pwsz) <= 0;
}

inline bool OdString::operator <= (const OdString & ods) const
{
  return compare(ods) <= 0;
}

////
inline bool operator == (char ch, const OdString & s)
{
  return s.compare(ch) == 0;
}

inline bool operator == (wchar_t wch, const OdString & s)
{
  return s.compare(wch) == 0;
}

inline bool operator==(const char* s1, const OdString& s2)
{
  return odStrCmpA(s2.kszPtr(), s1) == 0;
}

inline bool operator==(const OdChar* s1, const OdString& s2)
  { return s2.compare(s1) == 0; }

#if !defined(NATIVE_ODCHAR) && defined(_MSC_VER) && _MSC_VER >= 1300 && !defined(_WIN32_WCE)
inline bool operator==(const OdString& s1, const __wchar_t* s2)
{ return s1.compare((const OdChar*)s2) == 0; }

inline bool operator==(const __wchar_t* s1, const OdString& s2)
{ return s2.compare((const OdChar*)s1) == 0; }
#endif


inline bool operator != (char ch, const OdString & s)
{
  return s.compare(ch) != 0;
}

inline bool operator != (wchar_t wch, const OdString & s)
{
  return s.compare(wch) != 0;
}

inline bool operator!=(const OdChar* s1, const OdString& s2)
  { return s2.compare(s1) != 0; }

#if !defined(NATIVE_ODCHAR) && defined(_MSC_VER) && _MSC_VER >= 1300 && !defined(_WIN32_WCE)
inline bool operator!=(const OdString& s1, const __wchar_t* s2)
{ return s1.compare((const OdChar*)s2) != 0; }

inline bool operator!=(const __wchar_t* s1, const OdString& s2)
{ return s2.compare((const OdChar*)s1) != 0; }
#endif

inline bool operator!=(const char* s1, const OdString& s2)
{ return s2.compare(s1) != 0; }

inline bool operator<(const OdChar* s1, const OdString& s2)
  { return s2.compare(s1) > 0; }

#if !defined(NATIVE_ODCHAR) && defined(_MSC_VER) && _MSC_VER >= 1300 && !defined(_WIN32_WCE)
inline bool operator<(const OdString& s1, const __wchar_t* s2)
{ return s1.compare((const OdChar*)s2) < 0; }

inline bool operator<(const __wchar_t* s1, const OdString& s2)
{ return s2.compare((const OdChar*)s1) > 0; }
#endif

inline bool operator < (char ch, const OdString & s)
{
  return s.compare(ch) > 0;
}

inline bool operator < (wchar_t wch, const OdString & s)
{
  return s.compare(wch) > 0;
}

inline bool operator<(const char* s1, const OdString& s2)
{ return s2.compare(s1) > 0; }


inline bool operator>(const OdChar* s1, const OdString& s2)
  { return s2.compare(s1) < 0; }

#if !defined(NATIVE_ODCHAR) && defined(_MSC_VER) && _MSC_VER >= 1300 && !defined(_WIN32_WCE)
inline bool operator>(const OdString& s1, const __wchar_t* s2)
{ return s1.compare((const OdChar*)s2) > 0; }
inline bool operator>(const __wchar_t* s1, const OdString& s2)
{ return s2.compare((const OdChar*)s1) < 0; }
#endif

inline bool operator > (char ch, const OdString & s)
{
  return s.compare(ch) < 0;
}

inline bool operator > (wchar_t wch, const OdString & s)
{
  return s.compare(wch) < 0;
}

inline bool operator>(const char* s1, const OdString& s2)
{ return s2.compare(s1) < 0; }

inline bool operator<=(const OdChar* s1, const OdString& s2)
  { return s2.compare(s1) >= 0; }

#if !defined(NATIVE_ODCHAR) && defined(_MSC_VER) && _MSC_VER >= 1300 && !defined(_WIN32_WCE)
inline bool operator<=(const OdString& s1, const __wchar_t* s2)
{ return s1.compare((const OdChar*)s2) <= 0; }
inline bool operator<=(const __wchar_t* s1, const OdString& s2)
{ return s2.compare((const OdChar*)s1) >= 0; }
#endif

inline bool operator <= (char ch, const OdString & s)
{
  return s.compare(ch) >= 0;
}

inline bool operator <= (wchar_t wch, const OdString & s)
{
  return s.compare(wch) >= 0;
}

inline bool operator<=(const char* s1, const OdString& s2)
{ return s2.compare(s1) >= 0; }

inline bool operator>=(const OdChar* s1, const OdString& s2)
  { return s2.compare(s1) <= 0; }

#if !defined(NATIVE_ODCHAR) && defined(_MSC_VER) && _MSC_VER >= 1300 && !defined(_WIN32_WCE)
inline bool operator>=(const OdString& s1, const __wchar_t* s2)
{ return s1.compare((const OdChar*)s2) >= 0; }

inline bool operator>=(const __wchar_t* s1, const OdString& s2)
{ return s2.compare((const OdChar*)s1) <= 0; }
#endif

inline bool operator>=(const char* s1, const OdString& s2)
{ return s2.compare(s1) <= 0; }

#if defined(ODA_UNIXOS)
/**
    {group:Other_Classes}
*/
class OdW2US
{
  OdUInt16* _buf;
public:
  OdW2US(const wchar_t* pStr)
  {
    size_t len = wcslen(pStr);
    _buf = new OdUInt16[len+1];
    for (size_t i = 0; i < len; i++)
    {
      _buf[i] = (OdUInt16)pStr[i];
    }
    _buf[len] = 0;
  }
  ~OdW2US() 
  {
    delete _buf;
  }
  operator const OdUInt16*() const { return _buf; }
};

/** Description:
    {group:Other_Classes}
*/
class OdUS2W
{
  wchar_t* _buf;
public:
  OdUS2W(const OdUInt16* pStr)
  {
    size_t len = 0;
    if (const OdUInt16* p = pStr)
    {
      while (*p++)
        len++;
    }
    _buf = new wchar_t[len+1];
    for (size_t i = 0; i < len; i++)
    {
      _buf[i] = (wchar_t)pStr[i];
    }
    _buf[len] = 0;
  }
  ~OdUS2W() 
  {
    delete _buf;
  }
  operator const wchar_t*() const { return _buf; }
};

#else

#define OdUS2W(a) (const wchar_t*)(a)
#define OdW2US(a) (const OdUInt16*)(a)

#endif

#endif //_SUPPORT_MFC_CSTRING_HOOK_

#if defined(_AFX) || defined(__ATLSTR_H__)
inline OdString::OdString(const CStringW &csw) 
{
  init();

  *this = (const wchar_t *)csw;
}

inline OdString & OdString::operator=(const CStringW &csw)
{
  return this->assign((const wchar_t *)csw);
}

inline OdString & OdString::operator+=(const CStringW &csw)
{
  return this->append((const wchar_t *)csw);
}

inline int OdString::compare(const CStringW & csw) const
{
  return this->compare((const wchar_t *)csw);
}

inline int OdString::iCompare(const CStringW & csw) const
{
  return this->iCompare((const wchar_t *)csw);
}

inline int OdString::compareNoCase(const CStringW & csw) const
{
  return this->compareNoCase((const wchar_t *)csw);
}

inline int OdString::match(const CStringW & csw) const
{
  return this->match((const wchar_t *)csw);
}

inline int OdString::matchNoCase(const CStringW & csw) const
{
  return this->matchNoCase((const wchar_t *)csw);
}

inline bool OdString::operator == (const CStringW & csw) const
{
  return this->compare(csw) == 0;
}

inline bool OdString::operator != (const CStringW & csw) const
{
  return this->compare(csw) != 0;
}

inline bool OdString::operator > (const CStringW & csw) const
{
  return this->compare(csw) > 0;
}

inline bool OdString::operator >= (const CStringW & csw) const
{
  return this->compare(csw) >= 0;
}

inline bool OdString::operator < (const CStringW & csw) const
{
  return this->compare(csw) < 0;
}

inline bool OdString::operator <= (const CStringW & csw) const
{
  return this->compare(csw) <= 0;
}

#ifdef _AFX

inline bool operator == (const CStringW & csw, const OdString & ods)
{
  return ods.compare(csw) == 0;
}

inline bool operator != (const CStringW & csw, const OdString & ods)
{
  return ods.compare(csw) != 0;
}

inline bool operator >  (const CStringW & csw, const OdString & ods)
{
  return ods.compare(csw) < 0;
}

inline bool operator >= (const CStringW & csw, const OdString & ods)
{
  return ods.compare(csw) <= 0;
}

inline bool operator <  (const CStringW & csw, const OdString & ods)
{
  return ods.compare(csw) > 0;
}

inline bool operator <= (const CStringW & csw, const OdString & ods)
{
  return ods.compare(csw) >= 0;
}

inline CStringW operator + (const CStringW & csw, const char* c)
{
  return csw + CStringW(c);
}

#ifndef DISABLE_CSTRING_PLUS_ACSTRING
inline OdString operator + (const CStringW & csw, const OdString & ods)
{
  return ods.precat((const wchar_t *)csw);
}
#endif

#endif

#endif // _AFX
#include "TD_PackPop.h"

#endif // __ODSTRING_H__


