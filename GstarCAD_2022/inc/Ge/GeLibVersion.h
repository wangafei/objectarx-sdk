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




#ifndef OD_GE_LIB_VERSION
#define OD_GE_LIB_VERSION /* {Secret} */

#include "../Ge/GeExport.h"
#include "../TD_PackPush.h"

#define IMAGE_MAJOR_VER 2           /* {Secret} */
#define IMAGE_MINOR_VER 0           /* {Secret} */
#define IMAGE_CORRECTIVE_VER 0      /* {Secret} */
#define IMAGE_INTERNAL_VER 0        /* {Secret} */

/**
Description:
    This class provides management of GeLib versions.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeLibVersion
{
public:
  /**
    Arguments:
    major (I) Major version.
    minor (I) Minor version.
    corrective (I) Corrective version.
    schema (I) Schema version.
  */
  OdGeLibVersion ();
  OdGeLibVersion (
    const OdGeLibVersion& source);
  OdGeLibVersion (
    unsigned char major, 
    unsigned char minor,
    unsigned char corrective,
    unsigned char schema);

  /**
    Description:
    Returns the major version of GeLib.
  */
  unsigned char majorVersion () const; 

  /**
    Description:
    Returns the minor version of GeLib.
  */
  unsigned char minorVersion () const; 

  /**
    Description:
    Returns the corrective version of GeLib.
  */
  unsigned char correctiveVersion () const;
   
  /**
    Description:
    Returns the schema version of GeLib.
  */
  unsigned char schemaVersion () const;

  /**
    Description:
    Sets the *major* version of GeLib.

    Arguments:
    major (I) Major version.
  */
  OdGeLibVersion& setMajorVersion (
    unsigned char major); 

  /**
    Description:
    Sets the *minor* version of GeLib.

    Arguments:
    minor (I) Minor version.
  */
  OdGeLibVersion& setMinorVersion (
    unsigned char minor); 

  /**
    Description:
    Sets the *corrective* version of GeLib.

    Arguments:
    corrective (I) Corrective version.
  */
  OdGeLibVersion& setCorrectiveVersion (
    unsigned char corrective); 

  /**
    Description:
    Sets the *schema* version of GeLib.

    Arguments:
    schema (I) Schema version.
  */
  OdGeLibVersion& setSchemaVersion (
    unsigned char schema);

  OdBool operator == (
    const OdGeLibVersion& libVersion) const; 

  OdBool operator != (
    const OdGeLibVersion& libVersion) const; 

  OdBool operator < (
    const OdGeLibVersion& libVersion) const;

  OdBool operator <= (
    const OdGeLibVersion& libVersion) const; 

  OdBool operator > (
    const OdGeLibVersion& libVersion) const; 

  OdBool operator >= (
    const OdGeLibVersion& libVersion) const;

  GE_STATIC_EXPORT static const OdGeLibVersion kRelease0_95; // GeLib release 0.

  GE_STATIC_EXPORT static const OdGeLibVersion kReleaseSed; // GeLib 14.0 release. 

  GE_STATIC_EXPORT static const OdGeLibVersion kReleaseTah; // GeLib 15.0 release.

private:
  unsigned char mVersion[10];
};

#include "../TD_PackPop.h"

#endif // OD_GE_LIB_VERSION

