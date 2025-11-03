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


#ifndef _ODUTILADS_H_
#define _ODUTILADS_H_

#include "DbDatabase.h"

/** Description:
    Return true if and only if the specified *string* matches the wild-card pattern of this WildcardExpr object.
    Arguments:
    string (I) String to test.
    wcPattern (I) Wildcard pattern.
    
    Remarks:
    The following wildcard characters are supported:
    
    @table
    Name              Character      Description
    Back quote        `              Escapes the next character (takes it literally).
    Comma             ,              Separates patterns.
    Asterisk          *              Matches any character sequence, including a null sequence, anywhere in the pattern.
    Question Mark     ?              Matches a single character.
    Period            .              Matches a single non-alphanumeric character.
    At sign           @              Matches a single alphabetic character.
    Pound sign        #              Matches a single numeric character.
    Tilda             ~              If the first character in a pattern, matches anything but the pattern.
    Brackets          [...]          Matches a single enclosed character.
    Tilda brackets    [~...]         Matches a single non-enclosed character.
    Hyphen            -              In brackets, matches a single character in the specified range.
*/
TOOLKIT_EXPORT bool odutWcMatch(const OdString& string, const OdString& wcPattern);

TOOLKIT_EXPORT bool odutWcMatchNoCase(const OdString& string, const OdString& wcPattern);

TOOLKIT_EXPORT double oddbGetUnitsConversion(OdDb::UnitsValue from, OdDb::UnitsValue to);

#endif // _ODUTILADS_H_

