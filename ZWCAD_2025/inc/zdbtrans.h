
#ifndef   _ZCDBTRANS_H__
#define   _ZCDBTRANS_H__

#include "zdbmain.h"
#include "zdbapserv.h"
#include "zAcDbCore2dDefs.h"

#pragma pack (push, 8)

class ZcTransaction;
class ZcTransactionReactor;

class ZCDBCORE2D_PORT ZcDbTransactionManager: public ZcRxObject
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcDbTransactionManager);

    virtual ZcTransaction*      startTransaction() = 0;
    virtual Zcad::ErrorStatus   endTransaction  () = 0;
    virtual Zcad::ErrorStatus   abortTransaction() = 0;

    virtual int                 numActiveTransactions() = 0;
    virtual int                 numOpenedObjects() = 0;
    virtual ZcTransaction*      topTransaction() = 0;
    virtual Zcad::ErrorStatus   addNewlyCreatedDBRObject(ZcDbObject* obj,
                                     bool add = true) = 0;

    virtual Zcad::ErrorStatus   getAllObjects(ZcDbVoidPtrArray& objs) = 0;
	virtual Zcad::ErrorStatus   getAllObjects(ZcArray<ZcDbObject *>& objs) = 0;

    virtual void                addReactor(ZcTransactionReactor* reactor) = 0;
    virtual void                removeReactor(ZcTransactionReactor* reactor) =0;

    virtual Zcad::ErrorStatus   getObject(ZcDbObject*& obj, ZcDbObjectId id,
                                          ZcDb::OpenMode mode = ZcDb::kForRead, 
                                          bool openErasedObj = false) = 0; 

    template<class ObjType> Zcad::ErrorStatus getObject(ObjType *& pDerived,
                                ZcDbObjectId id, ZcDb::OpenMode mode = ZcDb::kForRead,
                                bool openErasedObject = false)
    {
        ZcDbObject *pObj = nullptr;
        Zcad::ErrorStatus es = this->getObject(pObj, id, mode, openErasedObject);
        if (es != Zcad::eOk || pObj == nullptr)
            pDerived = nullptr;
        else {
            pDerived = ObjType::cast(pObj);

            if (pDerived == nullptr)
                es = Zcad::eNotThatKindOfClass;
        }
        return es;
    }

    virtual Zcad::ErrorStatus   markObjectPageable(ZcDbObject* pObject) = 0;
    virtual Zcad::ErrorStatus   queueForGraphicsFlush() = 0;

};

class ZCDBCORE2D_PORT ZcTransaction: public ZcRxObject
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcTransaction);
    virtual 
    Zcad::ErrorStatus getObject(ZcDbObject*& obj, 
                                ZcDbObjectId   objectId, ZcDb::OpenMode mode = ZcDb::kForRead,
                                bool openErasedObject = false) = 0;

    template<class ObjType> Zcad::ErrorStatus getObject(ObjType *& pDerived,
                                ZcDbObjectId   objectId, ZcDb::OpenMode mode = ZcDb::kForRead,
                                bool openErasedObject = false)
    {
        ZcDbObject *pObj = nullptr;
        Zcad::ErrorStatus es = this->getObject(pObj, objectId, mode, openErasedObject);
        if (es != Zcad::eOk || pObj == nullptr)
            pDerived = nullptr;
        else {
            pDerived = ObjType::cast(pObj);

            if (pDerived == nullptr)
                es = Zcad::eNotThatKindOfClass;
        }
        return es;
    }

    virtual 
    Zcad::ErrorStatus markObjectPageable(ZcDbObject* pObject) = 0;

    virtual int                 numOpenedObjects() = 0;
    virtual Zcad::ErrorStatus   getAllObjects(ZcDbVoidPtrArray& objs) = 0;
    virtual Zcad::ErrorStatus   getAllObjects(ZcArray<ZcDbObject *>& objs) = 0;
};

class ZCDBCORE2D_PORT ZcTransactionReactor: public ZcRxObject

{
public:
    ZCRX_DECLARE_MEMBERS(ZcTransactionReactor);
    virtual ~ZcTransactionReactor() {};

    virtual void transactionAboutToStart (int& numTransactions,
        ZcDbTransactionManager* transactionManagerPtr) {}
    virtual void transactionStarted      (int& numTransactions,
        ZcDbTransactionManager* transactionManagerPtr) {}
    virtual void transactionAboutToEnd   (int& numTransactions,
        ZcDbTransactionManager* transactionManagerPtr) {}
    virtual void transactionEnded        (int& numTransactions,
        ZcDbTransactionManager* transactionManagerPtr) {}
    virtual void transactionAboutToAbort (int& numTransactions,
        ZcDbTransactionManager* transactionManagerPtr) {}
    virtual void transactionAborted      (int& numTransactions,
        ZcDbTransactionManager* transactionManagerPtr) {}
    virtual void endCalledOnOutermostTransaction (int& numTransactions,
        ZcDbTransactionManager* transactionManagerPtr) {}
    virtual void objectIdSwapped (const ZcDbObject* pTransResObj,
        const ZcDbObject* pOtherObj,
        ZcDbTransactionManager* transactionManagerPtr) {}
};

inline ZcDbTransactionManager* zcdbTransactionManagerPtr()
{
    return zcdbHostApplicationServices()->workingTransactionManager();
}

#define zcdbTransactionManager  zcdbTransactionManagerPtr()

#pragma pack (pop)

#endif   //_ZCDBTRANS_H__
