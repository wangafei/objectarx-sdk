/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbCore2dDefs.h"
#pragma pack (push, 8)

class GCDB_PORT GcDbCompoundObjectId : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbCompoundObjectId);

  GcDbCompoundObjectId();
  GcDbCompoundObjectId(const GcDbObjectId& id, GcDbDatabase* pHostDatabase = NULL);
  GcDbCompoundObjectId(const GcDbCompoundObjectId&);
  GcDbCompoundObjectId(const GcDbObjectId& id, const GcDbObjectIdArray& path, GcDbDatabase* pHostDatabase = NULL);
  ~GcDbCompoundObjectId();

  GcDbCompoundObjectId& operator =(const GcDbObjectId&);
  GcDbCompoundObjectId& operator =(const GcDbCompoundObjectId&);

  bool operator ==(const GcDbCompoundObjectId&) const;
  bool operator !=(const GcDbCompoundObjectId& other) const { return !(*this == other); }

  GcDbObjectId topId() const;
  GcDbObjectId leafId() const;

  Gcad::ErrorStatus getFullPath(GcDbObjectIdArray& fullPath) const;
  Gcad::ErrorStatus getPath(GcDbObjectIdArray& path) const;

  void setEmpty();

  Gcad::ErrorStatus set(const GcDbObjectId&, GcDbDatabase* pHostDatabase = NULL);
  Gcad::ErrorStatus set(const GcDbCompoundObjectId&, GcDbDatabase* pHostDatabase = NULL);
  Gcad::ErrorStatus set(const GcDbObjectId& id, const GcDbObjectIdArray& path, GcDbDatabase* pHostDatabase = NULL);

  Gcad::ErrorStatus setFullPath(const GcDbObjectIdArray& fullPath, GcDbDatabase* pHostDatabase = NULL);

  bool isEmpty() const;
  bool isValid(int validityCheckingLevel = 1) const;
  bool isExternal() const;
  bool isSimpleObjectId() const;

  enum Status
  {
    kValid = 0,
    kWasLoadedNowUnloaded = 1,
    kCouldNotResolveNonTerminal = 2,
    kCouldNotResolveTerminal = 3,
    kCouldNotResolveTooEarly = 4,
    kIncompatibleIdType = 1000,
  };

  Status status() const;
  Gcad::ErrorStatus getTransform(GcGeMatrix3d& trans) const;
  bool remap(const GcDbIdMapping& idMap);

  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler, GcDbDatabase* pHostDatabase) const;
  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler, int ownerVersion);
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler, GcDbDatabase* pHostDatabase) const;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler, GcDbDatabase* pHostDatabase, int ownerVersion);

  static const GcDbCompoundObjectId& nullId();

private:
  class GcDbImpCompoundObjectId* mpImp;
};

class GCDB_PORT GcDbParentTransformOfChildPE : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbParentTransformOfChildPE);

  virtual Gcad::ErrorStatus getParentTransformOfChild(const GcDbObject* pThisParent, const GcDbObjectId& childId, GcGeMatrix3d&) = 0;
};

#pragma pack (pop)