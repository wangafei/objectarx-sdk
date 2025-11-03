

#ifndef ZCDB_XRECORD_H
#define ZCDB_XRECORD_H

#include "zAdAChar.h"
#include "zdbmain.h"

#define ZCDB_XRECORD_CLASS          ZCRX_T("ZcDbXrecord") 
#define ZCDB_XRECORD_ITERATOR_CLASS ZCRX_T("ZcDbXrecordClass")

#pragma pack(push, 8)

class ZCDBCORE2D_PORT ZcDbXrecord: public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbXrecord);
    ZcDbXrecord();
    virtual ~ZcDbXrecord();

    Zcad::ErrorStatus rbChain(resbuf** ppRb, ZcDbDatabase* auxDb = NULL) const;
    Zcad::ErrorStatus setFromRbChain(const resbuf& pRb,
                                             ZcDbDatabase* auxDb = NULL);
    Zcad::ErrorStatus appendRbChain(const resbuf& pRb);
    bool              isXlateReferences() const;
    void              setXlateReferences(bool translate);

    virtual Zcad::ErrorStatus subClose() override;
    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer) override;
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const override;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer) override;
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const override;

    virtual ZcDb::DuplicateRecordCloning mergeStyle() const override;
    virtual void  setMergeStyle(ZcDb::DuplicateRecordCloning style);

protected:
	virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class ZcDbImpXrecordIterator;

class ZCDBCORE2D_PORT ZcDbXrecordIterator: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbXrecordIterator);
 
    ZcDbXrecordIterator(const ZcDbXrecord* pXrecord);
    virtual ~ZcDbXrecordIterator();

    void              start();
    bool              done() const;
    Zcad::ErrorStatus next();
    int               curRestype() const;
    Zcad::ErrorStatus getCurResbuf(resbuf& outItem, ZcDbDatabase* db) const;
    Zcad::ErrorStatus modifyCurResbuf(const resbuf& item);
    Zcad::ErrorStatus insertRbChain(const resbuf& pRb);
    Zcad::ErrorStatus removeCurResbuf();

protected:
    ZcDbXrecordIterator() {};
private:
    friend class ZcDbXrecord;
    friend class ZcDbImpXrecord;
    ZcDbImpXrecordIterator* mpImpIter;
};

#pragma pack(pop)

#endif
