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




#ifndef _ODDBTRANSACTIONREACTOR_INCLUDED_
#define _ODDBTRANSACTIONREACTOR_INCLUDED_

#include "TD_PackPush.h"

class OdDbDatabase;

#include "RxObject.h"


/** Description:
    This class is the base class for custom classes that receive notification
    of OdDbTransaction events.

    Note:
    The default implementations of all methods in this class do nothing but return.

    Library:
    TD_Db
        
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbTransactionReactor : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbTransactionReactor);
  
  OdDbTransactionReactor() {}
  /** Description
    Notification function called to indicate a new transaction is about to start.
    
    Arguments:
    pDb (I) Pointer to the database sending the notification.
    
    See Also:
    o  transactionAborted
    o  transactionAboutToAbort
    o  transactionAboutToEnd
    o  transactionEnded
    o  transactionStarted
  */
  virtual void transactionAboutToStart(
    OdDbDatabase* pDb);
  
  /** Description
    Notification function called to indicate a new transaction has started.
    
    Arguments:
    pDb (I) Pointer to the database sending the notification.
    
    See Also:
    o  transactionAborted
    o  transactionAboutToAbort
    o  transactionAboutToEnd
    o  transactionAboutToStart
    o  transactionEnded
  */
  virtual void transactionStarted(
    OdDbDatabase* pDb);

  /** Description
    Notification function called to indicate a transaction is about to end.
    
    Arguments:
    pDb (I) Pointer to the database sending the notification.
    
    See Also:
    o  transactionAborted
    o  transactionAboutToAbort
    o  transactionAboutToStart
    o  transactionEnded
    o  transactionStarted
  */
  virtual void transactionAboutToEnd(
    OdDbDatabase* pDb);

  /** Description
    Notification function called to indicate a transaction has ended.
    
    Arguments:
    pDb (I) Pointer to the database sending the notification.
    
    See Also:
    o  transactionAborted
    o  transactionAboutToAbort
    o  transactionAboutToEnd
    o  transactionAboutToStart
    o  transactionStarted
  */
  virtual void transactionEnded(
    OdDbDatabase* pDb);

  /** Description
    Notification function called to indicate a transaction is about to be terminated.
    
    Arguments:
    pDb (I) Pointer to the database sending the notification.
    
    See Also:
    o  transactionAborted
    o  transactionAboutToEnd
    o  transactionAboutToStart
    o  transactionEnded
    o  transactionStarted
  */
  virtual void transactionAboutToAbort(
    OdDbDatabase* pDb);

  /** Description
    Notification function called to indicate a transaction has been terminated.
    
    Arguments:
    pDb (I) Pointer to the database sending the notification.
    
    See Also:
    o  transactionAboutToAbort
    o  transactionAboutToEnd
    o  transactionAboutToStart
    o  transactionEnded
    o  transactionStarted
  */
  virtual void transactionAborted(
    OdDbDatabase* pDb);

  /** Description
    Notification function called to indicate the outermost transaction has ended.
    
    Arguments:
    pDb (I) Pointer to the database sending the notification.
  */
  virtual void endCalledOnOutermostTransaction(
    OdDbDatabase* pDb);

  /** Description
    Notification function called when the transaction resident object is involved in a swapIdWith() operation.
    
    Arguments:
    pTransObj (I) Pointer to the first transaction resident object.
    pOtherTransObj (I) Pointer to the second transaction resident object.
    pDb (I) Pointer to the database sending the notification.

    Remarks:
    According to database transactions implementation the both objects are transaction-resident or not.
    So this function will be called only once in OdDbObject::swapIdWith() method.
  */
  virtual void objectIdSwapped(
    const OdDbObject* pTransObj,
    const OdDbObject* pOtherTransObj,
    OdDbDatabase* pDb);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbTransactionReactor object pointers.
*/
typedef OdSmartPtr<OdDbTransactionReactor> OdDbTransactionReactorPtr;

#include "TD_PackPop.h"

#endif // _ODDBTRANSACTIONREACTOR_INCLUDED_
