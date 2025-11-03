/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef   _LTRANSMAN_H
#define   _LTRANSMAN_H

#include "rxnames.h"
#include "dbidar.h"
#pragma pack (push, 8)

class GcDbLongTransaction;
class GcDbDatabase;
class GcDbIdMapping;
class GcApDocument;

#define GC_LONG_TRANSACTION_MANAGER_OBJ GCRX_T("GcApLongTransactionManager")

class GCDB_PORT GcApLongTransactionReactor : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcApLongTransactionReactor);
  virtual void beginCheckOut(GcDbLongTransaction&, GcDbObjectIdArray& originList);
  virtual void endCheckOut(GcDbLongTransaction&);
  virtual void beginCheckIn(GcDbLongTransaction&);
  virtual void endCheckIn(GcDbLongTransaction&);
  virtual void abortLongTransaction(GcDbLongTransaction&);

protected:
  Gcad::ErrorStatus veto();
private:
  Gsoft::UInt8 mVeto;

  friend class GcApImpLongTransactionManager;
};

class GcApLongTransactionManager : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcApLongTransactionManager);

  virtual Gcad::ErrorStatus   checkOut(GcDbObjectId& transId,
                                       GcDbObjectIdArray& objList,
                                       GcDbObjectId toBlock,
                                       GcDbIdMapping& errorMap,
                                       GcDbObjectId lockBlkRef = GcDbObjectId::kNull) = 0;
  virtual Gcad::ErrorStatus   checkIn(GcDbObjectId transId,
                                      GcDbIdMapping& errorMap,
                                      bool keepObjs = false) = 0;

  virtual Gcad::ErrorStatus   abortLongTransaction(GcDbObjectId transId,
                                                   bool keepObjs = false) = 0;

  virtual GcDbObjectId        currentLongTransactionFor(const GcApDocument* pDoc) const = 0;

  virtual void                addReactor(GcApLongTransactionReactor*) = 0;
  virtual void                removeReactor(GcApLongTransactionReactor*) = 0;

  virtual Gcad::ErrorStatus   addClassFilter(GcRxClass*) = 0;
  virtual bool                isFiltered(GcRxClass*) const = 0;
};

extern GCDB_PORT GcApLongTransactionManager* gcapLongTransactionManagerPtr();
#define gcapLongTransactionManager  gcapLongTransactionManagerPtr()

#pragma pack (pop)
#endif
