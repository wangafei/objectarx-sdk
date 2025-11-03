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




#ifndef _OD_CHARMAPPER_H_
#define _OD_CHARMAPPER_H_

#include "TD_PackPush.h"

#include "OdCodePage.h"
#include "OdError.h"
#include "OdArray.h"

class OdStreamBuf;
class OdString;


/** Description:
    This class implements character mapping.
    Library: TD_Root
    {group:Other_Classes}
*/
typedef OdArray<char , OdMemoryAllocator<char> > charArray;
typedef OdArray<OdChar,OdMemoryAllocator<OdChar> > OdCharArray;

class FIRSTDLL_EXPORT OdCharMapper
{
  static OdString m_MapFile;
private:
	OdCharMapper();
public:
//	static OdResult initialize(OdStreamBuf* pIo);

  /** Description:
    Initializes this CharMapper object from the specified mapping file.
    Arguments:
    filename (I) File name.
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  static OdResult initialize(const OdString& filename);

  /** Description:
    Maps the specified Unicode character to the specified code page.
    Arguments:
    sourceChar (I) Unicode source character.
    codepageId (I) Object ID of the code page.
    codepageChar (O) Receives the code page character.
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  static OdResult unicodeToCodepage(OdChar sourceChar,
    OdCodePageId codepageId,
    OdChar& codepageChar,
    OdCodePageId* pNewCodePage = NULL,
    bool bTryToUseSystemCP = true);

  /** Description:
  Maps the specified Unicode character to the specified code page using IMLangFontLink2 interface.
  Arguments:
  sourceChar (I) Unicode source character.
  codepageId (I) Object ID of the code page.
  codepageChar (O) Receives the code page character.
  Remarks:
  Returns eOk if successful, or an appropriate error code if not.
  */
  static OdResult unicodeToCodepage2(OdChar sourceChar,
    OdCodePageId codepageId,
    OdChar& codepageChar);

  /** Description:
    Maps the specified code page character to Unicode.
    Arguments:
    sourceChar (I) Code page source character.
    codepageId (I) Object ID of the code page.
    unicodeChar (O) Receives the Unicode character.
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  static OdResult codepageToUnicode(OdChar sourceChar,
    OdCodePageId codepageId,
    OdChar& unicodeChar);

  /** Description:
    Returns true if and only if the specified byte is one of the leading bytes of the specified code page.
    Arguments:
    testByte (I) Byte to test.
    codepageId (I) Object ID of the code page.
  */
  static bool isLeadByte(OdUInt8 testByte, OdCodePageId codepageId);

  /** Description:
    Returns the code page with the specified *description*.
    Arguments:
    description (I) Description.  
    codepageId (O) Receives the object ID of the code page.  
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  static OdResult codepageDescToId(const OdString& description, OdCodePageId& codepageId);

  /** Description:
    Returns the *description* for the specified code page.
    Arguments:
    description (O) Receives the *description*.  
    codepageId (I) Object ID of the code page.
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  static OdResult codepageIdToDesc(OdCodePageId codepageId, OdString& description);

  /** Description:
    Returns the number of valid code pages for this CharMapper object.
  */
  static OdUInt32 numValidCodepages();

  /** Description:
    Returns the code page corresponding to the specified ANSI code page.
    Arguments:
    ansiCodePage (I) ANSI code page.
  */
  static OdCodePageId ansiCpToAcadCp(OdUInt32 ansiCodePage);

  /** Description:
    Returns the ANSI code page corresponding to the specified code page.
    Arguments:
    acadCodePageId (I) code page.
  */
  static OdUInt32 acadCpToAnsiCp(OdCodePageId acadCodePageId);

  /** Description:
    Returns the code page corresponding to the specified ANSI character set.
    Arguments:
    ansiCharacterSet (I) Character Set.
  */
   static OdCodePageId getCodepageByCharset(OdUInt16 ansiCharacterSet);

   static OdUInt8 getCharsetByCodepage(OdUInt32 codepage);

   /** Description:
   Returns true if and only if the specified code page supports conversion.
   Arguments:
   codepageId (I) Object ID of the code page.
   */
   static bool isConversionSupported(OdCodePageId codepageId);

   static void wideCharToMultiByte(OdCodePageId codePage, const OdChar* srcBuf, int srcSize, charArray& dstBuf, OdCodePageId* pNewCodePage = NULL);
   // Returns number of characters (! not dstBuf length)
   static void multiByteToWideChar(OdCodePageId codePage, const char* srcBuf, int srcSize, OdCharArray& dstBuf);

   static void utf8ToUnicode(const char* srcBuf, int srcSize, OdCharArray& dstBuf);
   static void unicodeToUtf8(const OdChar* srcBuf, int srcSize, charArray& dstBuf);

	static void wideCharToMultiByte(OdCodePageId codePage, const OdChar* srcBuf, int srcSize, void* pdstBuf, OdCodePageId* pNewCodePage = NULL);
	static void multiByteToWideChar(OdCodePageId codePage, const char* srcBuf, int srcSize, void* pdstBuf);
	static void utf8ToUnicode(const char* srcBuf, int srcSize, void* pdstBuf);
	static void unicodeToUtf8(const OdChar* srcBuf, int srcSize, void* pdstBuf);

   /** Description:
     Adds the *bigFont* to map.
     Arguments:
     bigFont (I) big font file name.  
     cpIndex (I) code page index.
     
     Remarks:
     cpIndex must be one of the following:
     
     @table
     Value    Description
     1        CP_ANSI_932
     2        CP_ANSI_950
     3        CP_ANSI_949
     5        CP_ANSI_936

     Returns eOk if successful, or an appropriate error code if not.
   */
   static OdResult addBigFontWithIndex(const OdString& bigFont, OdInt32 cpIndex);

   /** Description:
     Adds the *bigFont* to map.
     Arguments:
     bigFont (I) big font file name.  
     codePageId (I) CodePage ID.

     Remarks:
     codePageId must be one of the following:
     
     @untitled table
     CP_ANSI_932
     CP_ANSI_950
     CP_ANSI_949
     CP_ANSI_936

     Returns eOk if successful, or an appropriate error code if not.
   */
   static OdResult addBigFontWithCodepage(const OdString& bigFont, OdCodePageId codePageId);

   /** Description:
     Returns the OdCodePageId.
     Remarks:
     getCpByBigFont returns one of the following:
     
     @untitled table
     CP_ANSI_932
     CP_ANSI_950
     CP_ANSI_949
     CP_ANSI_936
     Arguments:
     bigFont (I) big font file name.  
   */

   static OdCodePageId getCpByBigFont(const OdString& bigFont);
   /** Description:
     Returns the code page index.
     Remarks:
     getCpIndexByBigFont returns one of the following:
     
     @table
     Value     Description
     1         CP_ANSI_932
     2         CP_ANSI_950
     3         CP_ANSI_949
     5         CP_ANSI_936
     Arguments:
     bigFont (I) big font file name.  
   */
   static OdInt32 getCpIndexByBigFont(const OdString& bigFont);

   /** Description:
     Returns the check sum for an ANSI string.
     Arguments:
     str (I) String for calculating check sum.  
   */
   static double getCheckSumAnsi(OdAnsiString str);

   /** Description:
     Returns the check sum for a unicode string.
     Arguments:
     str (I) String for calculating check sum.  
   */
   static double getCheckSumUnicode(OdString str);

   static bool getFontInfoForChar(OdCodePageId acadCodePageId, OdChar ch,
     OdCodePageId defaultCodePage,
     OdString& lfFaceName, OdUInt16& lfCharSet, OdUInt16& lfPitchAndFamily);
};
/** Description:
  Returns the specified text converted from one code page to another.
  Arguments:
  source (I) Source text.
  sourceId (I) Object ID of *source* code page.
  destId (I) Object ID of destination code page.
*/

#include "TD_PackPop.h"

#endif

