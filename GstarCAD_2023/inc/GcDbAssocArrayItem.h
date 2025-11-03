/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

class DBCONSTRAINTS_PORT GcDbItemLocator
{
public:
  enum IndexType
  {
    kItemIndex,
    kRowIndex,
    kLevelIndex,
  };

  GcDbItemLocator();
  GcDbItemLocator(int itemIndex, int rowIndex, int levelIndex);
  GcDbItemLocator(const GcDbItemLocator& other);

  int operator [] (IndexType i) const { return mIndices[i]; }
  GcDbItemLocator& operator = (const GcDbItemLocator& other);
  GcDbItemLocator  operator -  (const GcDbItemLocator& other) const;
  GcDbItemLocator  operator +  (const GcDbItemLocator& other) const;

  bool operator == (const GcDbItemLocator& other) const;
  bool operator != (const GcDbItemLocator& other) const;
  bool operator <  (const GcDbItemLocator& other) const;
  bool operator >  (const GcDbItemLocator& other) const { return compareWith(other) > 0; }

  int compareWith(const GcDbItemLocator& other) const;

private:
  int mIndices[3];
};

class GcDbImpAssocArrayItem;
class DBCONSTRAINTS_PORT GcDbAssocArrayItem : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocArrayItem);

  GcDbAssocArrayItem();
  GcDbAssocArrayItem(GcDbItemLocator& locator, const GcGeMatrix3d& transform);
  ~GcDbAssocArrayItem();

  Gcad::ErrorStatus getTransform(GcGeMatrix3d& transform, bool bCompounded = true) const;
  bool hasRelativeTransform() const;
  Gcad::ErrorStatus transformBy(const GcGeMatrix3d& transform);
  Gcad::ErrorStatus setDefaultTransform(const GcGeMatrix3d& transform);
  Gcad::ErrorStatus setErased(bool bErased);
  bool isErased() const;
  const GcDbItemLocator& locator() const;
  const GcDbObjectId& entityProvider() const;
  void setEntityProvider(GcDbObjectId provider);
  Gcad::ErrorStatus copyFrom(const GcRxObject* other) override;

  virtual Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler);
  virtual Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const;
  virtual Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler);
  virtual Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const;

private:
  GcDbAssocArrayItem(const GcDbAssocArrayItem& other);
  friend class GcDbImpAssocArrayItem;
  GcDbImpAssocArrayItem* mpSelf;
};