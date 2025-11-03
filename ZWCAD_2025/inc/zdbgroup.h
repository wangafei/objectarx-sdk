

#ifndef ZCDB_DBGROUP_H
#define ZCDB_DBGROUP_H

#include "zdbmain.h"
#include "zdbapserv.h"

#pragma pack(push, 8)

class ZcDbGroupIterator;

class ZCDBCORE2D_PORT ZcDbGroup: public  ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbGroup);
    ZcDbGroup();
    ZcDbGroup(const ZTCHAR * grpDesc, bool selectable = true);
    virtual ~ZcDbGroup();

    ZcDbGroupIterator*  newIterator();

    const ZTCHAR *       description() const;
    Zcad::ErrorStatus   setDescription(const ZTCHAR * grpDesc);

    bool                isSelectable() const;
    Zcad::ErrorStatus   setSelectable(bool selectable);

	Zcad::ErrorStatus   getName(ZTCHAR *& pName) const;   
	Zcad::ErrorStatus   getName(const ZTCHAR *& name) const;   
	Zcad::ErrorStatus   getName(ZcString & sName) const;   

	const wchar_t *       name() const;		 

    Zcad::ErrorStatus   setName(const ZTCHAR * newName);

    bool                isNotAccessible() const;

    bool                isAnonymous() const;
    Zcad::ErrorStatus   setAnonymous();

    Zcad::ErrorStatus   append(ZcDbObjectId id);
    Zcad::ErrorStatus   append(const ZcDbObjectIdArray & ids);
    Zcad::ErrorStatus   prepend(ZcDbObjectId id);
    Zcad::ErrorStatus   prepend(const ZcDbObjectIdArray & ids);  
    Zcad::ErrorStatus   insertAt(ZSoft::UInt32 idx, ZcDbObjectId id);
    Zcad::ErrorStatus   insertAt(ZSoft::UInt32 idx, const ZcDbObjectIdArray & ids);
    Zcad::ErrorStatus   remove(ZcDbObjectId id);
    Zcad::ErrorStatus   removeAt(ZSoft::UInt32 idx);
    Zcad::ErrorStatus   remove(const ZcDbObjectIdArray & ids);
    Zcad::ErrorStatus   removeAt(ZSoft::UInt32 idx, const ZcDbObjectIdArray & ids);
    Zcad::ErrorStatus   replace(ZcDbObjectId oldId, ZcDbObjectId newId);
    Zcad::ErrorStatus   transfer(ZSoft::UInt32 fromIndex, 
                                 ZSoft::UInt32 toIndex, 
                                 ZSoft::UInt32 numItems);

    Zcad::ErrorStatus   clear();
    ZSoft::UInt32       numEntities() const;
    bool                has(const ZcDbEntity* pEntity) const;
    ZSoft::UInt32       allEntityIds(ZcDbObjectIdArray& ids) const;
    Zcad::ErrorStatus   getIndex(ZcDbObjectId id, ZSoft::UInt32& idx) const;
    Zcad::ErrorStatus   reverse();

    Zcad::ErrorStatus   setColor(const ZcCmColor& color);
    Zcad::ErrorStatus   setColorIndex(ZSoft::UInt16 color);
    Zcad::ErrorStatus   setLayer(const ZTCHAR * newVal);
    Zcad::ErrorStatus   setLayer(ZcDbObjectId newVal);
    Zcad::ErrorStatus   setLinetype(const ZTCHAR * newVal);
    Zcad::ErrorStatus   setLinetype(ZcDbObjectId newVal);
    Zcad::ErrorStatus   setLinetypeScale(double newval);
    Zcad::ErrorStatus   setVisibility(ZcDb::Visibility newVal);
    Zcad::ErrorStatus   setHighlight(bool newVal);

    Zcad::ErrorStatus   setMaterial(const ZTCHAR * newVal);
    Zcad::ErrorStatus   setMaterial(ZcDbObjectId newVal);
    virtual Zcad::ErrorStatus applyPartialUndo(ZcDbDwgFiler* undoFiler,
                                               ZcRxClass*    classObj) override;

    virtual Zcad::ErrorStatus subClose() override;
    virtual Zcad::ErrorStatus subErase(ZSoft::Boolean erasing ) override;

    virtual void              erased(const ZcDbObject* dbObj,
                                     ZSoft::Boolean erasing ) override;
    virtual void              goodbye(const ZcDbObject* dbObj) override;

    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler) override;
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const override;

    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler) override;
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const override;
protected:
    virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
} ;

class ZCDBCORE2D_PORT ZSOFT_NO_VTABLE ZcDbGroupIterator: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbGroupIterator);
    virtual ~ZcDbGroupIterator() {}

    virtual Zcad::ErrorStatus getObject(ZcDbObject*& pObject,
        ZcDb::OpenMode) = 0;
    virtual ZcDbObjectId      objectId () const = 0;

    virtual bool              done     () const = 0;
    virtual bool              next     () = 0;

protected:
    ZcDbGroupIterator() {}
};

#pragma pack(pop)

#endif
