/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "dbeval.h"
#include "GcString.h"

#pragma pack (push, 8)

class GcDbDynBlockReference;
class GcDbDynBlockReferenceProperty;
class GcDbImpDynBlockReference;
class GcDbImpDynBlockReferenceProperty;
class GcDbImpDynBlockTableRecord;

class DYNBLOCKS_PORT GcDbDynBlockReferenceProperty : public GcHeapOperators
{
public:
  enum UnitsType {
    kNoUnits = 0,
    kAngular,
    kDistance,
    kArea
  };

  GcDbDynBlockReferenceProperty();
  virtual ~GcDbDynBlockReferenceProperty();
  GcDbDynBlockReferenceProperty(const GcDbDynBlockReferenceProperty& other);
  GcDbDynBlockReferenceProperty& operator=(const GcDbDynBlockReferenceProperty& other);

  GcDbObjectId          blockId() const;
  GcString              propertyName()   const;
  GcDb::DwgDataType     propertyType()  const;
  bool                  readOnly()       const;
  bool                  show()           const;
  bool                  visibleInCurrentVisibilityState()       const;
  GcString              description()    const;
  UnitsType             unitsType() const;
  Gcad::ErrorStatus     getAllowedValues(GcDbEvalVariantArray& values);
  GcDbEvalVariant       value() const;
  Gcad::ErrorStatus     setValue(const GcDbEvalVariant& value);
  bool operator==(const GcDbDynBlockReferenceProperty& other);

private:
  GcDbImpDynBlockReferenceProperty* mpImp;
  friend class GcDbImpDynBlockReferenceProperty;
  friend class GcDbImpDynBlockReference;
};

typedef GcArray<GcDbDynBlockReferenceProperty,
  GcArrayObjectCopyReallocator<GcDbDynBlockReferenceProperty> >
  GcDbDynBlockReferencePropertyArray;

class DYNBLOCKS_PORT GcDbDynBlockReference : public GcHeapOperators
{
public:
  GcDbDynBlockReference(GcDbObjectId blockRefId);
  GcDbDynBlockReference(GcDbBlockReference* pRef);
  virtual ~GcDbDynBlockReference();

  static bool       isDynamicBlock(GcDbObjectId blockTableRecordId);
  bool              isDynamicBlock() const;
  GcDbObjectId      blockId() const;
  void              getBlockProperties(
    GcDbDynBlockReferencePropertyArray& properties) const;
  Gcad::ErrorStatus resetBlock();
  Gcad::ErrorStatus convertToStaticBlock();
  Gcad::ErrorStatus convertToStaticBlock(const GcString& newBlockName);
  GcDbObjectId      dynamicBlockTableRecord() const;
  GcDbObjectId      anonymousBlockTableRecord() const;

private:
  GcDbDynBlockReference();
  GcDbImpDynBlockReference* mpImp;
};

class DYNBLOCKS_PORT GcDbDynBlockTableRecord : public GcHeapOperators
{
public:
  GcDbDynBlockTableRecord(GcDbObjectId blockTableRecordId);
  virtual ~GcDbDynBlockTableRecord();

  bool isDynamicBlock() const;
  GcDbObjectId blockTableRecordId() const;
  Gcad::ErrorStatus getAnonymousBlockIds
  (GcDbObjectIdArray& anonymousIds) const;
  Gcad::ErrorStatus updateAnonymousBlocks() const;

private:
  GcDbDynBlockTableRecord();
  GcDbImpDynBlockTableRecord* mpImp;
};
#pragma pack (pop)