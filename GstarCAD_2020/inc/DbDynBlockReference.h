/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2011, Open Design Alliance (the "Alliance"). 
// All rights reserved. 
// 
// This software and its documentation and related materials are owned by 
// the Alliance. The software may only be incorporated into application 
// programs owned by members of the Alliance, subject to a signed 
// Membership Agreement and Supplemental Software License Agreement with the
// Alliance. The structure and organization of this software are the valuable  
// trade secrets of the Alliance and its suppliers. The software is also 
// protected by copyright law and international treaty provisions. Application  
// programs incorporating this software must include the following statement 
// with their copyright notices:
//   
//   This application incorporates Teigha(R) software pursuant to a license 
//   agreement with Open Design Alliance.
//   Teigha(R) for .dwg files Copyright (C) 2003-2011 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
//
//
// *DWG is the native and proprietary file format for AutoCAD(R) and a trademark  
// of Autodesk, Inc.  Open Design Alliance is not associated with Autodesk.
///////////////////////////////////////////////////////////////////////////////

#ifndef _DbDynBlock_h_Included_
#define _DbDynBlock_h_Included_


#include "DbEvalGraph.h"
#include "TD_PackPush.h"

// Forward class declarations

class OdDbBlockReference;
class OdDbDynBlockReference;
class OdDbDynBlockReferenceProperty;
class OdDbDynBlockReferencePropertyImpl;
class OdDbDynBlockReferenceImpl;
struct OdDbBlkParamPropertyDescriptor;
class OdDbBlockParameter;
class OdDbDynBlockTableRecordImpl;
class OdDbBlockRepresentationContext;
typedef OdSmartPtr<OdDbBlockParameter> OdDbBlockParameterPtr;

/** Description:
    This class is a utility class referencing properties of dynamic blocks.
    
    Remarks:
    
    Library: TD_DynBlocks
    {group:OdDb_Classes}
*/
class DYNBLOCKS_EXPORT OdDbDynBlockReferenceProperty : public OdRxObject
{
public:

  enum UnitsType {
    kNoUnits  = 0,  // No units defined.
    kAngular  = 1,  // Angle.
    kDistance = 2,  // Distance.
    kArea     = 3   // 2D area.
  };

  OdDbDynBlockReferenceProperty ();
  virtual ~OdDbDynBlockReferenceProperty ();

  OdDbDynBlockReferenceProperty (
    const OdDbDynBlockReferenceProperty& other);

  OdDbDynBlockReferenceProperty& operator=(
    const OdDbDynBlockReferenceProperty& other);

  /** Description:
    Returns the Object ID of the dynamic block reference that owns this property.
  */
  OdDbObjectId blockId() const;

  /** Description:
    Returns the name of this property.
    Remarks:
    All property names in a given block reference are guaranteed unique.
  */
  OdString propertyName ()  const;

  /** Description:
    Returns the type of the property *value*.
  */
  OdDb::DwgDataType propertyType() const;

  /** Description:
    Returns true if and only if this property is Read-Only.
  */
  bool readOnly () const;

  
  /** Description:
    Returns true if and only if this property is displayed on the Property Palette.
  */
  bool show () const;

  /** Description:
    Returns the *description* of this property.
  */
  OdString description () const;

  /** Description:
    Returns the *connection* of this property.
  */
  OdString connection() const;

  /** Description:
    Returns the units of this property.
    
    Remarks:
    This function may be used to format property values.
    
    unitsType() returns one of the following:
    
    @table
    Name        Value   Description
    kNoUnits    0       No units defined.
    kAngular    1       Angle.
    kDistance   2       Distance.
    kArea       3       2D area.
  */
  UnitsType             unitsType () const;


  /** Description:
    Returns an array of allowed values for this property.
    Arguments:
    allowedValues (O) Receives an an array of allowd values.
  */
  // Gcad(Modify): OdDbEvalVariant
  OdResult getAllowedValues(OdDbEvalVariantArray& allowedValues);

  /** Description:
    Returns the current *value* of the property on the dynamic block reference.
  */
  // Gcad(Modify): OdDbEvalVariant
  OdDbEvalVariant value (ODSYSDEF) const;

  /** Description:
    Sets the current *value* of the property on the dynamic block reference.
    Arguments:
    value (I) Value.
    Remarks:
    Returns true if and only if successful.
  */
  // Gcad(Modify): OdDbEvalVariant
  OdResult setValue (ODSYSDEF, const OdDbEvalVariant& value);

  GcDbEvalVariant value() const;
  OdResult setValue(const GcDbEvalVariant& value);

  bool getDescriptor(OdDbEvalNodeId& parameterId, OdDbBlkParamPropertyDescriptor& pDescriptor);

private:
  friend class OdDbDynBlockReferencePropertyImpl;
  OdDbDynBlockReferencePropertyImpl* m_pImpl;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbDynBlockReferenceProperty object pointers.
*/
typedef OdSmartPtr<OdDbDynBlockReferenceProperty> OdDbDynBlockReferencePropertyPtr;
/** Description:
    This template class is a specialization of the OdArray class for OdDbDynBlockReferencePropertyPtr objects.
*/
typedef OdArray<OdDbDynBlockReferenceProperty, OdObjectsAllocator<OdDbDynBlockReferenceProperty> > OdDbDynBlockReferencePropertyArray;

/** Description:
    This class is a utility class providing access to information on dynamic block references. 
    Library: TD_DynBlocks
    {group:OdDb_Classes}
*/
class DYNBLOCKS_EXPORT OdDbDynBlockReference
{
public:
  ODRX_HEAP_OPERATORS();
public:
  
  /**
    Arguments:
    blockRefId (I) Object ID of the dynamic block reference.
  */
  OdDbDynBlockReference(OdDbObjectId blockRefId);

  /**
    Arguments:
    pRef (I) Pointer to the dynamic block reference.
  */
  OdDbDynBlockReference(OdDbBlockReference* pRef);

  virtual ~OdDbDynBlockReference ();

  /** Description:
    Returns true if and only if the specified Block Table Record 
    contains dynamic block information.
    
    Arguments:
    blockTableRecordId (I) Block Table Record Object ID.
    
    Remarks:
    If blockTableRecordId is not specified, the Block Reference specified
    in the constructor will be used
  */
  static bool isDynamicBlock (OdDbObjectId blockTableRecordId);

  bool              isDynamicBlock () const;

  /** Description:
    Returns the Object ID of the block reference.
  */
  OdDbObjectId blockId() const;


  /** Description:
    Returns an array of the dynamic block *properties* of the block reference.
    Arguments:
    properties (O) Receives an array of *properties*.
    Remarks:
    An empty array will be returned if the block reference has no dynamic block *properties*.
  */
  void getBlockProperties(OdDbDynBlockReferencePropertyArray& properties) const;

  /** Description:
    Resets all properties in the block reference to those of the block definition.
  */
  // Gcad(Modify): void->OdResult
  OdResult resetBlock();

  /** Description:
    Converts the dynamic block reference to a static block.
    
    Arguments:
    newBlockName (I) New block name.
    Remarks:
    If newBlockName is not specified, an anonymous block is created.
  */
  // Gcad(Modify): bool->OdResult
  OdResult convertToStaticBlock();
  OdResult convertToStaticBlock (const OdString& newBlockName);

  /** Description:
    Returns the Object ID of the dynamic block BlockTableRecord.
    
    Remarks:
    Returns NULL if the block reference is not a dynamic block. 
  */
  OdDbObjectId dynamicBlockTableRecord () const;

  /** Description:
    Returns the ObjectID of the anonymous block BlockTableRecord used to draw the dynamic block.
  */
  OdDbObjectId anonymousBlockTableRecord () const; 

private:
  OdDbDynBlockReference();
  OdDbBlockRepresentationContext* getRepresentationContext() const;
  OdDbDynBlockReferenceImpl* m_pImpl;
  friend class OdDbDynBlockTableRecord;
};

class DYNBLOCKS_EXPORT OdDbDynBlockTableRecord
{
  ODRX_HEAP_OPERATORS();
public:
  OdDbDynBlockTableRecord(OdDbObjectId blockId);
  ~OdDbDynBlockTableRecord();
  bool isDynamicBlock() const;
  OdDbObjectId blockTableRecordId() const;
  
  /** \details
    Gets an ObjectId array of all anonymous representation blocks created from the dynamic block definition.
    
    \param anonymousIds [out]  An output OdDbObjectIdArray.
  */
  OdResult getAnonymousBlockIds(OdDbObjectIdArray& anonymousIds) const;
  OdResult updateAnonymousBlocks() const;
private:
  OdDbDynBlockTableRecord();
  OdDbDynBlockTableRecordImpl* m_pImpl;
};

#include "TD_PackPop.h"

#endif
