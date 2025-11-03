/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2012, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) Copyright (C) 2003-2012 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////

#ifndef _DBOBJECTCONTEXT_H__INCLUDED_
#define _DBOBJECTCONTEXT_H__INCLUDED_

#include "RxObject.h"
#include "SmartPtr.h"

////////////////////////////////////////////////////////////////////////
// class OdDbObjectContext
////////////////////////////////////////////////////////////////////////

/** Description:
    This class represents a context that can determine what properties
	and behaviors are available for custom objects. 

    Remarks:
    An annotation scale is an example of an object that 
	has a context that determines its available options and behavior.
    
    Library:
    TD_Db
   
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbObjectContext : public OdRxObject
{
public:

  ODRX_DECLARE_MEMBERS(OdDbObjectContext);
  OdDbObjectContext() {}
  virtual ~OdDbObjectContext ();

   /** Description:
    Returns the name of the context.
  
	Remarks:
	When referencing a context, do not use the context name since it can change.
	Use the context ID instead.
   */  
  virtual OdResult getName (OdString& name) const = 0;

   /** Description:
    Sets a new name of a context.
  
    Arguments:
	name (I) New name of the context.
 
	Remarks:
	Returns eOk if successful, or an appropriate error code if not.
   */  
  virtual OdResult setName ( const OdString& name ) = 0;

   /** Description:
    Returns the ID of the context.
 
	Remarks:
	Use the context ID when referencing a context since it is unique. Do not use 
	the context name since it can change.	
   */  
  virtual OdIntPtr uniqueIdentifier () const = 0;

  /** Description:
    Returns the name of the context collection to which the context belongs.
   */  
  virtual OdString collectionName () const = 0;
};

typedef OdSmartPtr<OdDbObjectContext> OdDbObjectContextPtr;

#endif //_DBOBJECTCONTEXT_H__INCLUDED_
