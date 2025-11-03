#pragma once

class ZCDBCORE2D_PORT ZcDbItemLocator
{
public:

    enum IndexType
    {

        kItemIndex,

        kRowIndex,

        kLevelIndex,
    };

    ZcDbItemLocator();

    ZcDbItemLocator(int itemIndex, int rowIndex, int levelIndex);

    ZcDbItemLocator(const ZcDbItemLocator& other);

    int operator [] (IndexType i) const { return mIndices[i]; }

    ZcDbItemLocator& operator = (const ZcDbItemLocator& other);

    ZcDbItemLocator  operator -  (const ZcDbItemLocator& other) const;

    ZcDbItemLocator  operator +  (const ZcDbItemLocator& other) const;

    bool operator == (const ZcDbItemLocator& other) const;

    bool operator != (const ZcDbItemLocator& other) const;

    bool operator <  (const ZcDbItemLocator& other) const;

    bool operator >  (const ZcDbItemLocator& other) const { return compareWith(other) > 0; }

    int compareWith(const ZcDbItemLocator& other) const;

private:
    int mIndices[3];
};

class ZcDbImpAssocArrayItem;

class ZCDBCORE2D_PORT ZcDbAssocArrayItem : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocArrayItem);

    ZcDbAssocArrayItem();

    ZcDbAssocArrayItem(ZcDbItemLocator& locator, const ZcGeMatrix3d& transform);

    ~ZcDbAssocArrayItem();

    Zcad::ErrorStatus getTransform(ZcGeMatrix3d& transform, bool bCompounded = true) const;

    bool hasRelativeTransform() const;

    Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& transform);

    Zcad::ErrorStatus setDefaultTransform(const ZcGeMatrix3d& transform);

    Zcad::ErrorStatus setErased(bool bErased);

    bool isErased() const;

    const ZcDbItemLocator& locator() const;

    const ZcDbObjectId& entityProvider() const;

    void setEntityProvider(ZcDbObjectId provider);

    Zcad::ErrorStatus copyFrom(const ZcRxObject* other) override;

    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);

    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;

    virtual Zcad::ErrorStatus dxfInFields (ZcDbDxfFiler* pFiler);

    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;

private:
    ZcDbAssocArrayItem(const ZcDbAssocArrayItem& other);
    friend class ZcDbImpAssocArrayItem;
    ZcDbImpAssocArrayItem* mpSelf;
};
