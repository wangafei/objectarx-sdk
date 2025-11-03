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

#ifndef _DBANNOTATIVEOBJECTPE_H_INCLUDED_
#define _DBANNOTATIVEOBJECTPE_H_INCLUDED_

#include "RxObject.h"

class OdDbViewport;

/** Description:
    This class must be implemented for objects that use annotation scaling.
    
    Library:
    TD_Db
   
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbAnnotativeObjectPE : public OdRxObject
{
public:

  ODRX_DECLARE_MEMBERS(OdDbAnnotativeObjectPE);

  /** Description:
    Returns whether a specified object supports annotation scaling.
  
    Arguments:
	pObject (I) Pointer to the object.
   */  
  virtual bool annotative(const OdDbObject* pObject) const = 0;

  /** Description:
    Sets whether an object supports annotation scaling.
  
    Arguments:
	pObject (I) Pointer to the object.
	bAnnotative (I) The annotative property value.

	Remarks:
	Returns eOk if successful, or an appropriate error code if not.
   */  
  virtual OdResult setAnnotative( 
    OdDbObject* pObject,
    bool bAnnotative ) = 0;

   /** Description:
    Sets the annotative property of an object according to its corresponding
	style, such as styles of text objects.
  
    Arguments:
	pObject (I) Pointer to the object.
	bUpdated (O) Returns True if the annotative property changes.

	Remarks:
	Returns eOk if successful, or an appropriate error code if not.
   */  
  virtual OdResult setFromStyle(
    OdDbObject* pObject, 
    bool&       bUpdated) = 0;

   /** Description:
    Not implemented. Returns whether the specified object is set to
	display regardless of the ANNOALLVISIBLE system variable setting.
   */   
  virtual bool forceAnnoAllVisible(OdDbObject* /*pObject*/) const { return false;} ;

   /** Description:
    Not implemented. Sets whether the specified object displays regardless
	of the ANNOALLVISIBLE system variable setting.
   */  
  virtual OdResult setForceAnnoAllVisible(OdDbObject* /*pObj*/, bool /*bForce*/) const {return Oda::eNotImplemented;}

   /** Description:
    Not implemented.
   */  
  virtual OdResult resetScaleDependentProperties(OdDbObject* /*pObject*/) {return Oda::eNotImplemented;}
};
typedef OdSmartPtr<OdDbAnnotativeObjectPE> OdDbAnnotativeObjectPEPtr;

   /** Description:
    This class is a Protocol Extension class for objects, such as annotative objects,
	that support a paper orientation property.

    Library:
    TD_Db

    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbPaperOrientationPE : public OdRxObject
{
public:

  ODRX_DECLARE_MEMBERS(OdDbPaperOrientationPE);

   /** Description:
    Returns whether the specified object is currently oriented with the paper.
  
    Arguments:
	pObject (I) Pointer to the object that supports the paper orientation property.
   */  
  virtual bool paperOrientation(OdDbObject* pObject) const = 0;

   /** Description:
    Sets the paper orientation property of a specified object.
  
    Arguments:
	pObject (I) Pointer to the object that supports the paper orientation property.
	bPaperOrientation (I) Value of the paper orientation property.

	Remarks:
	Returns eOk if successful, or an appropriate error code if not.
   */  
  virtual OdResult setPaperOrientation( 
    OdDbObject* pObject,
    const bool  bPaperOrientation ) = 0;

   /** Description:
    Not implemented.
   */  
  virtual OdResult applyPaperOrientationTransform ( 
    OdDbObject* /*pObject*/,
    const OdDbViewport* /*pVport*/ ) const
  { return Oda::eNotImplemented; }
};
typedef OdSmartPtr<OdDbPaperOrientationPE> OdDbPaperOrientationPEPtr;

#endif //_DBANNOTATIVEOBJECTPE_H_INCLUDED_
