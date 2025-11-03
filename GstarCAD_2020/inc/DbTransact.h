///////////////////////////////////////////////////////////////////////////////
// Copyright ?2006, Open Design Alliance Inc. ("Open Design") 
// 
// This software is owned by Open Design, and may only be incorporated into 
// application programs owned by members of Open Design subject to a signed 
// Membership Agreement and Supplemental Software License Agreement with 
// Open Design. The structure and organization of this Software are the valuable 
// trade secrets of Open Design and its suppliers. The Software is also protected 
// by copyright law and international treaty provisions. Application 
// programs incorporating this software must include the following statement 
// with their copyright notices:
//
//      DWGdirect ?2006 by Open Design Alliance Inc. All rights reserved. 
//
// By use of this software, you acknowledge and accept the terms of this 
// agreement.
///////////////////////////////////////////////////////////////////////////////


#ifndef _ODDBTRANSACT_INCLUDED_
#define _ODDBTRANSACT_INCLUDED_

#include "RxObject.h"
#include "TD_PackPush.h"

/*/Gcad(Add)
/*/
class OdDbObject;
class OdTransaction;
class OdTransactionReactor;

class TOOLKIT_EXPORT OdDbTransactionManager : public OdRxObject
{ 
public:
    ODRX_DECLARE_MEMBERS(OdDbTransactionManager);

    virtual OdTransaction*      startTransaction() = 0;
    virtual OdResult			endTransaction  () = 0;
    virtual OdResult			abortTransaction() = 0;

    virtual int                 numActiveTransactions() = 0;
    virtual OdTransaction*      topTransaction() = 0;
    virtual OdResult			addNewlyCreatedDBRObject(OdDbObject* obj,
                                     bool add = true) = 0;

    virtual OdResult			getAllObjects(OdDbVoidPtrArray& objs) = 0;

    virtual void                addReactor(OdTransactionReactor* reactor) = 0;
    virtual void                removeReactor(OdTransactionReactor* reactor) =0;

    virtual OdResult			getObject(OdDbObject*& obj, OdDbObjectId id,
                                          OdDb::OpenMode mode, 
                                          bool openErasedObj = false) = 0; 

    virtual OdResult			markObjectPageable(OdDbObject* pObject) = 0;
    virtual OdResult			queueForGraphicsFlush() = 0;

};

typedef OdSmartPtr<OdDbTransactionManager> OdDbTransactionManagerPtr;


class TOOLKIT_EXPORT OdTransaction : public OdRxObject
{ 
public:
    ODRX_DECLARE_MEMBERS(OdTransaction);

    virtual OdResult  getObject(OdDbObject*& obj, 
                                OdDbObjectId objectId, OdDb::OpenMode mode,
                                bool openErasedObject = false) = 0;

    virtual OdResult  markObjectPageable(OdDbObject* pObject) = 0;

    virtual OdResult  getAllObjects(OdDbVoidPtrArray& objs) = 0;
};

typedef OdSmartPtr<OdTransaction> OdTransactionPtr;
//*/


/** Description:
    This class is the base class for custom classes that receive notification
    of OdTransactionMangager events.

    Note:
    The default implementations of all methods in this class do nothing.
    
    Library:
    Db
    
    {group:Other_Classes}
*/
class TOOLKIT_EXPORT OdTransactionReactor : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdTransactionReactor);

  /** Description
    Notification function called to indicate a new transaction is about to start.
    
    Remarks:
    Arguments:
    numTransactions (I) Current number of transactions.
    pTransactionManager (I) Pointer to the transaction manager sending the notification.
    
    Remarks:
    numTransactions does not include the transaction about to start.
    
    See Also:
    o  transactionAborted
    o  transactionAboutToAbort
    o  transactionAboutToEnd
    o  transactionEnded
    o  transactionStarted
  */
  virtual void transactionAboutToStart(
    int& numTransactions, 
    OdDbTransactionManager* pTransactionManager);
  
  /** Description
    Notification function called to indicate a new transaction has started.
    
    Remarks:
    Arguments:
    numTransactions (I) Current number of transactions.
    pTransactionManager (I) Pointer to the transaction manager sending the notification.
    
    Remarks:
    numTransactions includes the transaction just started.

    See Also:
    o  transactionAborted
    o  transactionAboutToAbort
    o  transactionAboutToEnd
    o  transactionAboutToStart
    o  transactionEnded
  */
  virtual void transactionStarted(
    int& numTransactions, 
    OdDbTransactionManager* pTransactionManager);

  /** Description
    Notification function called to indicate a transaction is about to end.
    
    Remarks:
    Arguments:
    numTransactions (I) Current number of transactions.
    pTransactionManager (I) Pointer to the transaction manager sending the notification.
    
    Remarks:
    numTransactions includes the transaction about to end.

    See Also:
    o  transactionAborted
    o  transactionAboutToAbort
    o  transactionAboutToStart
    o  transactionEnded
    o  transactionStarted
  */
  virtual void transactionAboutToEnd(
    int& numTransactions, 
    OdDbTransactionManager* pTransactionManager);

  /** Description
    Notification function called to indicate a transaction has ended.
    
    Remarks:
    Arguments:
    numTransactions (I) Current number of transactions.
    pTransactionManager (I) Pointer to the transaction manager sending the notification.
    
    Remarks:
    numTransactions does not include the transaction just ended.
    See Also:
    o  transactionAborted
    o  transactionAboutToAbort
    o  transactionAboutToEnd
    o  transactionAboutToStart
    o  transactionStarted
  */
  virtual void transactionEnded(
    int& numTransactions, 
    OdDbTransactionManager* pTransactionManager);

  /** Description
    Notification function called to indicate a transaction is about to be terminated.
    
    Remarks:
    Arguments:
    numTransactions (I) Current number of transactions.
    pTransactionManager (I) Pointer to the transaction manager sending the notification.
    
    Remarks:
    numTransactions includes the transaction about to be terminated.
    See Also:
    o  transactionAborted
    o  transactionAboutToEnd
    o  transactionAboutToStart
    o  transactionEnded
    o  transactionStarted
  */
  virtual void transactionAboutToAbort(
    int& numTransactions, 
    OdDbTransactionManager* pTransactionManager);

  /** Description
    Notification function called to indicate a transaction has been terminated.
    
    Remarks:
    Arguments:
    numTransactions (I) Current number of transactions.
    pTransactionManager (I) Pointer to the transaction manager sending the notification.
    
    Remarks:
    numTransactions does not include the transaction just terminated.
    See Also:
    o  transactionAboutToAbort
    o  transactionAboutToEnd
    o  transactionAboutToStart
    o  transactionEnded
    o  transactionStarted
  */
  virtual void transactionAborted(
    int& numTransactions, 
    OdDbTransactionManager* pTransactionManager);

  /** Description
    Notification function called to indicate the outermost transaction has ended.
    
    Remarks:
    numTransactions should equal 1.
    Arguments:
    numTransactions (I) Current number of transactions.
    pTransactionManager (I) Pointer to the transaction manager sending the notification.
  */
  virtual void endCalledOnOutermostTransaction(
    int& numTransactions, 
    OdDbTransactionManager* pTransactionManager);

  /** Description
    Notification function called to indicate a transaction-resident object was involved in swapIdWidth() operation.
    
    Arguments:
    pTransResObj (I) Transaction-resident object
    pOtherObj (I) Other object.
    
    Remarks:
    When both objects are transaction-resident, this function will be called once for each object. 
  */
  virtual void objectIdSwapped(
    const OdDbObject* pTransResObj, 
    const OdDbObject* pOtherObj, 
    OdDbTransactionManager* pTransactionManager);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdTransactionReactor object pointers.
*/
typedef OdSmartPtr<OdTransactionReactor> OdTransactionReactorPtr;


/*/Gcad(Add)
/*/
//arx:actrans.h
class TOOLKIT_EXPORT OdTransactionManager: public OdDbTransactionManager 
{ 
public:
    ODRX_DECLARE_MEMBERS(OdTransactionManager);

    virtual OdResult  enableGraphicsFlush(bool doEnable) = 0;
    virtual void      flushGraphics() = 0; 
};

class TOOLKIT_EXPORT OdDbGraphicsTransaction : public OdRxObject
{
public:
	ODRX_DECLARE_MEMBERS(OdDbGraphicsTransaction);

	virtual void updateGraphics(const void *p){}
	virtual void flushGraphics(const void *p , int n){}
};

typedef OdSmartPtr<OdTransactionManager> OdTransactionManagerPtr;


#define OD_TRANSACTION_MANAGER_OBJ OD_T("OdTransactionManager")
OdTransactionManagerPtr odCreateTransactionManager();

TOOLKIT_EXPORT OdDbTransactionManager* oddbTransactionManagerPtr();
#define oddbTransactionManager  oddbTransactionManagerPtr()

TOOLKIT_EXPORT OdTransactionManager* odTransactionManagerPtr();
#define odtrTransactionManager  odTransactionManagerPtr()

TOOLKIT_EXPORT OdDbGraphicsTransaction *oddbGraphicsTransactionPtr();
//*/

class TOOLKIT_EXPORT OdTransactionInner
{
public:
  virtual OdResult queueForGraphicsFlush() = 0;
  virtual OdResult enableGraphicsFlush(bool doEnable) = 0;
  virtual void flushGraphics() = 0;
};

#include "TD_PackPop.h"

#endif // _ODDBTRANSACT_INCLUDED_

