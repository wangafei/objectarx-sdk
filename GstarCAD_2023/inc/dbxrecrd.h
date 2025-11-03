/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCDB_XRECORD_H
#define GCDB_XRECORD_H

#include "GdGChar.h"
#include "dbmain.h"

#define GCDB_XRECORD_CLASS          GCRX_T("AcDbXrecord")
#define GCDB_XRECORD_ITERATOR_CLASS GCRX_T("AcDbXrecordClass")

#pragma pack(push, 8)

class GCDB_PORT GcDbXrecord : public GcDbObject
{
public:
  GCDB_DECLARE_MEMBERS(GcDbXrecord);
  GcDbXrecord();
  ~GcDbXrecord();

  Gcad::ErrorStatus rbChain(resbuf** ppRb, GcDbDatabase* auxDb = NULL) const;
  Gcad::ErrorStatus setFromRbChain(const resbuf& pRb, GcDbDatabase* auxDb = NULL);
  Gcad::ErrorStatus appendRbChain(const resbuf& pRb);
  bool              isXlateReferences() const;
  void              setXlateReferences(bool translate);
  Gcad::ErrorStatus subClose() override;
  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* filer) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* filer) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* filer) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* filer) const override;

  GcDb::DuplicateRecordCloning mergeStyle() const override;
  virtual void  setMergeStyle(GcDb::DuplicateRecordCloning style);

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class GcDbImpXrecordIterator;

class GCDB_PORT GcDbXrecordIterator : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbXrecordIterator);

  GcDbXrecordIterator(const GcDbXrecord* pXrecord);
  ~GcDbXrecordIterator();

  void              start();
  bool              done() const;
  Gcad::ErrorStatus next();
  int               curRestype() const;
  Gcad::ErrorStatus getCurResbuf(resbuf& outItem, GcDbDatabase* db) const;
  Gcad::ErrorStatus modifyCurResbuf(const resbuf& item);
  Gcad::ErrorStatus insertRbChain(const resbuf& pRb);
  Gcad::ErrorStatus removeCurResbuf();

protected:
  GcDbXrecordIterator() {};
private:
  friend class GcDbXrecord;
  friend class GcDbImpXrecord;
  GcDbImpXrecordIterator* mpImpIter;
};

#pragma pack(pop)

#endif