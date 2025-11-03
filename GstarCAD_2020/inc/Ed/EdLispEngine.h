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

#ifndef _EDLISPENGINE_H_INCLUDED_
#define _EDLISPENGINE_H_INCLUDED_

#include "../RxObject.h"
#include "../RxModule.h"

class OdEdCommandContext;

/**
    {group:OdEd_Classes}
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdEdLispEngineReactor : public OdRxObject
{
protected:
  OdEdLispEngineReactor();
public:
  ODRX_DECLARE_MEMBERS(OdEdLispEngineReactor);
  
  ~OdEdLispEngineReactor();

  virtual void lispWillStart(OdEdCommandContext* pCmdCtx, const OdString& firstLine);

  virtual void lispEnded(OdEdCommandContext* pCmdCtx);

  virtual void lispCancelled(OdEdCommandContext* pCmdCtx);
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdEdLispEngineReactor object pointers. 
*/
typedef OdSmartPtr<OdEdLispEngineReactor> OdEdLispEngineReactorPtr;


/**
    {group:OdEd_Classes}
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdEdLispEngine : public OdRxObject
{
protected:
  OdEdLispEngine();
public:
  ODRX_DECLARE_MEMBERS(OdEdLispEngine);

  ~OdEdLispEngine();

   /** Description:
    Adds the specified *reactor* to this object's *reactor* list.

    Arguments:
    pReactor (I) Pointer to the *reactor* object.
  */
  virtual void addReactor(OdEdLispEngineReactor* pReactor) = 0;

  /** Description:
    Removes the specified transient *reactor* from this object's *reactor* list.

    Arguments:
    pReactor (I) Pointer to the *reactor* object.
  */
  virtual void removeReactor(OdEdLispEngineReactor* pReactor) = 0;

  virtual void execute(OdEdCommandContext* pCmdCtx, const OdString& firstLine) = 0;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdEdLispEngineReactor object pointers. 
*/
typedef OdSmartPtr<OdEdLispEngine> OdEdLispEnginePtr;


/**
    {group:OdEd_Classes}
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdEdLispModule : public OdRxModule
{
protected:
   OdEdLispModule();
public:
  ODRX_DECLARE_MEMBERS(OdEdLispModule);

  ~OdEdLispModule();

  virtual OdEdLispEnginePtr createLispEngine() = 0;
};

typedef OdSmartPtr<OdEdLispModule> OdEdLispModulePtr;


#endif //_EDLISPENGINE_H_INCLUDED_
