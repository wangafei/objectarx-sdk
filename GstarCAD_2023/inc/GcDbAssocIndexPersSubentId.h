/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "dbsubeid.h"
#include "GcDbAssocPersSubentId.h"
#pragma pack (push, 8)

class GcDbAssocIndexPersSubentId : public GcDbAssocPersSubentId
{
#ifdef __GNUC__
protected:
  typedef GcDbAssocPersSubentId __super;
  static_assert((std::is_same<__super, GcDbAssocPersSubentId>::value), "Incorrect __super class");
#endif

public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbAssocIndexPersSubentId, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcDbAssocIndexPersSubentId(GcDb::SubentType subentType = GcDb::kNullSubentType, unsigned int index = 0);

  DBCONSTRAINTS_PORT bool operator ==(const GcDbAssocIndexPersSubentId& other) const
  {
    return mSubentType == other.mSubentType && mIndex == other.mIndex;
  }
  DBCONSTRAINTS_PORT bool operator <(const GcDbAssocIndexPersSubentId& other) const
  {
    return mSubentType != other.mSubentType ? mSubentType < other.mSubentType : mIndex < other.mIndex;
  }

  DBCONSTRAINTS_PORT GcDb::SubentType subentType(const GcDbEntity*, GcDbDatabase*) const override { return mSubentType; }

  DBCONSTRAINTS_PORT bool isNull() const override { return mSubentType == GcDb::kNullSubentType; }

  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus dwgOutFieldsData(GcDbDwgFiler* pFiler) const;
  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus dxfOutFieldsData(GcDbDxfFiler* pFiler) const;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;

  DBCONSTRAINTS_PORT unsigned int index() const { return mIndex; }

  DBCONSTRAINTS_PORT void setSubentType(GcDb::SubentType subentType) { mSubentType = subentType; }
  DBCONSTRAINTS_PORT void setIndex(unsigned int newIndex) { mIndex = newIndex; }

private:
  int encodeActualClassInSubentType() const;

  static const int kRoundTripOffset = 1000000;
  virtual int roundTripOffset() const { return kRoundTripOffset; }
  friend void roundTripReadViaGcDbAssocSimplePersSubentId(GcDbAssocPersSubentId*&);

protected:
  GcDb::SubentType mSubentType;
  unsigned int     mIndex;
};

class GcDbAssocExternalIndexPersSubentId : public GcDbAssocIndexPersSubentId
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbAssocExternalIndexPersSubentId, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcDbAssocExternalIndexPersSubentId(GcDb::SubentType subentType = GcDb::kNullSubentType, unsigned int index = 0)
    : GcDbAssocIndexPersSubentId(subentType, index) {}

private:
  static const int kRoundTripOffset = 2000000;
  int roundTripOffset() const override { return kRoundTripOffset; }

  friend void roundTripReadViaGcDbAssocSimplePersSubentId(GcDbAssocPersSubentId*&);
};

class  GcDbAssocObjectAndIndexPersSubentId : public GcDbAssocIndexPersSubentId
{
#ifdef __GNUC__
  typedef GcDbAssocIndexPersSubentId __super;
  static_assert((std::is_same<__super, GcDbAssocIndexPersSubentId>::value), "Incorrect __super class");
#endif

public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbAssocObjectAndIndexPersSubentId, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcDbAssocObjectAndIndexPersSubentId() {}
  DBCONSTRAINTS_PORT GcDbAssocObjectAndIndexPersSubentId(const GcDbObjectId& objId, GcDb::SubentType subentType, unsigned int index);

  DBCONSTRAINTS_PORT bool operator ==(const GcDbAssocObjectAndIndexPersSubentId& other) const;
  DBCONSTRAINTS_PORT bool operator  <(const GcDbAssocObjectAndIndexPersSubentId& other) const;

  DBCONSTRAINTS_PORT GcDbObjectId objectId() const { return mObjectId; }
  DBCONSTRAINTS_PORT void setObjectId(const GcDbObjectId& objId) { mObjectId = objId; }

  DBCONSTRAINTS_PORT Gcad::ErrorStatus dwgOutFieldsData(GcDbDwgFiler*) const override;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus dxfOutFieldsData(GcDbDxfFiler*) const override;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler*) const override;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus dwgInFields(GcDbDwgFiler*) override;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler*) const override;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus dxfInFields(GcDbDxfFiler*) override;

private:
  GcDbObjectId mObjectId;
};

#pragma pack (pop)