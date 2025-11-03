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

#ifndef _ODDBCOMMANDCONTEXT_H_INCLUDED_
#define _ODDBCOMMANDCONTEXT_H_INCLUDED_

#include "DbExport.h"
#include "DbUserIO.h"
#include "Ed/EdCommandContext.h"
#include "OdError.h"

class OdDbDatabase;
class OdDbCommandContext;

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbCommandContext object pointers.
*/
typedef OdSmartPtr<OdDbCommandContext> OdDbCommandContextPtr;

#include "TD_PackPush.h"

/** Description:
    This class defines the interface for I/O and *database* access 
    for custom commands during their execution.

    Remarks:
    Client applications that invoke custom commands, should use an instance of this
    class (or a subclass) to pass to the OdEdCommandStack::executeCommand function.
    Using this class instead of a true instance of OdEdCommandContext provides
    custom commands with *database* access.

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbCommandContext : public OdEdCommandContext
{ 
public:
  ODRX_DECLARE_MEMBERS(OdDbCommandContext);

  /** Description:
      Returns a *database*, for use in a custom command.
  */
  virtual OdDbDatabase* database();

  OdDbUserIO* dbUserIO();
};



inline OdDbUserIO*
OdDbCommandContext::dbUserIO()
{
  ODA_ASSERT(userIO() && userIO()->isKindOf(OdDbUserIO::desc()));
  return static_cast<OdDbUserIO*>(userIO());
}

inline OdDbDatabase*
OdDbCommandContext::database()
{
  //ODA_ASSERT(baseDatabase()->isKindOf(OdDbDatabase::desc()));
  //return static_cast<OdDbDatabase*>(baseDatabase());
  //
  // support for TeighaViewer 
  OdDbDatabase* pDb = OdDbDatabase::cast(baseDatabase());
  if (!pDb)
    throw OdError(eNoDatabase);
  return pDb;
}

#include "TD_PackPop.h"

#endif //#ifndef _ODDBCOMMANDCONTEXT_H_INCLUDED_
