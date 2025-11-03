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




#ifndef _LIBRARYINFO_H_
#define _LIBRARYINFO_H_

#include "DbRootExport.h"
#include "OdString.h"

#include "TD_PackPush.h"


/** Description:
    This class encapsulates a set of character strings containing 
    describing the Teigha library.

    Remarks:

    Library: TD_Db
    {group:OdDb_Classes}
*/
class DBROOT_EXPORT OdDbLibraryInfo
{
public:
  /** Description:
    Returns the Library Name (Teigha).
  */
  virtual const OdString& getLibName() const = 0;
  /** Description:
    Returns the Library Version (#.##.##).
  */
  virtual const OdString& getLibVersion() const = 0;
  
  /** Description:
    Returns the Company Name (Open Design Alliance Inc. ("Open Design")).
  */
  virtual const OdString& getCompanyName() const = 0;
  /** Description:
    Returns the Copyright Message (Copyright ?yyyy, Open Design Alliance Inc. ("Open Design")).
  */
  virtual const OdString& getCopyright() const = 0;

  /** Description:
    Returns the Library Build Comments.
  */
  virtual const OdString& getBuildComments() const = 0;
};

#include "TD_PackPop.h"

#endif // _LIBRARYINFO_H_
