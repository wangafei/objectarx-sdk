/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef   _GCDBTRANS_H__
#define   _GCDBTRANS_H__

#include "dbmain.h"
#include "dbapserv.h"

#pragma pack (push, 8)

class GcTransaction;
class GcTransactionReactor;

class GCDB_PORT GcDbTransactionManager : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbTransactionManager);

  virtual GcTransaction*      startTransaction() = 0;
  virtual Gcad::ErrorStatus   endTransaction() = 0;
  virtual Gcad::ErrorStatus   abortTransaction() = 0;
  virtual int                 numActiveTransactions() = 0;
  virtual int                 numOpenedObjects() = 0;
  virtual GcTransaction*      topTransaction() = 0;
  virtual Gcad::ErrorStatus   addNewlyCreatedDBRObject(GcDbObject* obj, bool add = true) = 0;
  virtual Gcad::ErrorStatus   getAllObjects(GcArray<GcDbObject *> & objs) = 0;

  virtual void                addReactor(GcTransactionReactor* reactor) = 0;
  virtual void                removeReactor(GcTransactionReactor* reactor) = 0;

  virtual Gcad::ErrorStatus   getObject(GcDbObject*& obj, GcDbObjectId id,
    GcDb::OpenMode mode = GcDb::kForRead,
    bool openErasedObj = false) = 0;

  virtual Gcad::ErrorStatus   markObjectPageable(GcDbObject* pObject) = 0;
  virtual Gcad::ErrorStatus   queueForGraphicsFlush() = 0;
};

class GCDB_PORT GcTransaction : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcTransaction);
  virtual Gcad::ErrorStatus getObject(GcDbObject*& obj,
    GcDbObjectId   objectId, GcDb::OpenMode mode = GcDb::kForRead,
    bool openErasedObject = false) = 0;
  virtual Gcad::ErrorStatus markObjectPageable(GcDbObject* pObject) = 0;
  virtual int               numOpenedObjects() = 0;
  virtual Gcad::ErrorStatus getAllObjects(GcArray<GcDbObject *> & objs) = 0;
};

class GCDB_PORT GcTransactionReactor : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcTransactionReactor);

  virtual void transactionAboutToStart(int& numTransactions, GcDbTransactionManager* transactionManagerPtr);
  virtual void transactionStarted(int& numTransactions, GcDbTransactionManager* transactionManagerPtr);
  virtual void transactionAboutToEnd(int& numTransactions, GcDbTransactionManager* transactionManagerPtr);
  virtual void transactionEnded(int& numTransactions, GcDbTransactionManager* transactionManagerPtr);
  virtual void transactionAboutToAbort(int& numTransactions, GcDbTransactionManager* transactionManagerPtr);
  virtual void transactionAborted(int& numTransactions, GcDbTransactionManager* transactionManagerPtr);
  virtual void endCalledOnOutermostTransaction(int& numTransactions, GcDbTransactionManager* transactionManagerPtr);
  virtual void objectIdSwapped(const GcDbObject* pTransResObj, const GcDbObject* pOtherObj, GcDbTransactionManager* transactionManagerPtr);
};

inline GcDbTransactionManager* gcdbTransactionManagerPtr()
{
  return gcdbHostApplicationServices()->workingTransactionManager();
}

#define gcdbTransactionManager  gcdbTransactionManagerPtr()

#pragma pack (pop)

#endif  