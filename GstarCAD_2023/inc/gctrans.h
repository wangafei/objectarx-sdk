/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef   _GCTRANS_H
#define   _GCTRANS_H

#include "rxnames.h"
#include "dbptrar.h"
#include "dbtrans.h"
#include "gcdocman.h"
#pragma pack (push, 8)


class GCDB_PORT GcTransactionManager : public GcDbTransactionManager
{
public:
  GCRX_DECLARE_MEMBERS(GcTransactionManager);

  virtual Gcad::ErrorStatus   enableGraphicsFlush(bool doEnable) = 0;
  virtual void                flushGraphics() = 0;
};

inline GcTransactionManager* gcTransactionManagerPtr()
{
  GcApDocument* pDoc = gcDocManager->curDocument();
  return pDoc ? pDoc->transactionManager() : NULL;
}

#define gctrTransactionManager  gcTransactionManagerPtr()

#pragma pack (pop)
#endif