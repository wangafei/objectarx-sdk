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




#ifndef _ODDBGROUP_INCLUDED_
#define _ODDBGROUP_INCLUDED_

#include "TD_PackPush.h"

#include "DbObject.h"

class OdDbGroupIterator;
class OdCmColor;
class OdDbGroupImpl;
class OdDbGroup;

/** Description:
    This class defines Iterator objects that traverse entries in OdDbGroup 
    objects in an OdDbDatabase instance.
    
    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbGroupIterator : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbGroupIterator);
  
  virtual ~OdDbGroupIterator() { }

  /** Description:
    Returns the entity currently referenced by this Iterator object.
  
    Arguments:
    openMode (I) Mode in which to open the current entity.

    Remarks:
    Returns a null SmartPointer if not successful.
  */
  OdDbObjectPtr getObject( // Gcad(Modify)
    OdDb::OpenMode openMode);

  virtual OdResult getObject( // Gcad(Add)
    OdDbObject*& pObject,
    OdDb::OpenMode openMode) = 0;

  /** Description:
    Returns the Object ID of the entity currently referenced by this Iterator object.
  */
  virtual OdDbObjectId objectId() const = 0;

  /** Description:
    Returns true if and only if the traversal by this Iterator object is complete.
  */  
  virtual bool done() const = 0;

  /** Description:
    Sets this Iterator object to reference the entity following the current entity.
    
    Remarks:
    Returns true if and only if not at the end of the list.
  */  
  virtual bool next() = 0;

  /*
     virtual OdResult subGetClassID(CLSID* pClsid) const;
  */
protected:
  OdDbGroupIterator() {}
};
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbGroupIterator object pointers.
*/
typedef OdSmartPtr<OdDbGroupIterator> OdDbGroupIteratorPtr;

/** Description:
    This class represents Group objects in an OdDbDatabase instance.

    Remarks:
    Only top level entities in ModelSpace or PaperSpace can be placed in a Group.

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbGroup: public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbGroup);

  OdDbGroup();
  OdDbGroup(const OdChar* grpDesc,bool selectable = true);
  virtual ~OdDbGroup();

  /** Description:
    Creates an Iterator object that provides access to the entities in this Group object.
  */
  OdDbGroupIteratorPtr newIterator(ODSYSDEF); // Gcad(Modify)
#ifdef ODARXDEF
  OdDbGroupIterator* newIterator(); // Gcad(Add) 
#endif
  /** Description:
    Returns the *description* of this Group object (DXF 300).
  */
  const OdChar * description() const; // Gcad(Modify) 

  /** Description:
    Sets the *description* of this Group object (DXF 300).
    Arguments:
    description (I) Description.
  */
  OdResult setDescription( // Gcad(Modify) 
    const OdChar * description);

  /** Description:
    Returns true if and only if this Group object is *selectable* (DXF 71).
  */
  bool isSelectable() const;

  /** Description:
    Sets this Group object as *selectable* (DXF 71).

    Arguments:
    selectable (I) Selectable flag.
  */
  OdResult setSelectable( // Gcad(Modify) 
    bool selectable);

  /** Description:
    Returns the *name* of this Group object.
  */
  const OdChar * name() const; // Gcad(Modify) 

  OdResult getName(OdChar*& grpName) const; // Gcad(Add) 
  
  /** Description:
    Sets the *name* for this Group object.
    Arguments:
    name (I) Name.
  */
  OdResult setName(const OdChar * name); // Gcad(Modify) 

  /** Description:
    Returns true if and only if this Group object is inaccessible.
      
    Remarks:
    Currently, only groups in Xrefs are flagged as inaccessable.  
  */
  bool isNotAccessible() const;

  /** Description:
    Returns true if and only if this Group object is anonymous (DXF 70).
  */
  bool isAnonymous() const;

  /** Description:
    Sets this Group object as anonymous (DXF 70).
    
    Remarks:
    The *name* of this Group object will be set to an automatically generated anonymous group *name*.
  */
  OdResult setAnonymous(); // Gcad(Modify) 

  /** Description:
    Appends the specified entity or entities to this Group object.  

    Arguments:
    objectId (I) Object ID of the entity to be appended.
  */
  OdResult append( // Gcad(Modify) 
    OdDbObjectId objectId);

  /**
    Arguments:
    objectIds (I) Object IDs of the entities to be appended.
  */
  OdResult append( // Gcad(Modify) 
    OdDbObjectIdArray objectIds);

  /** Description:
    Prepends the specified entity or entities to this Group object.  

    Arguments:
    objectId (I) Object ID of the entity to be prepended.
  */
  OdResult prepend( // Gcad(Modify) 
    OdDbObjectId objectId);

  /**
    Arguments:
    objectIds (I) Object IDs of the entities to be prepended.
  */
  OdResult prepend( // Gcad(Modify) 
    OdDbObjectIdArray objectIds);

  /** Description:
    Inserts the specified entity or entities to this Group object at the specified *index*.  

    Arguments:
    objectId (I) Object ID of the entity to be inserted.
    insertionIndex (I) Insertion *index*.
  */
  OdResult insertAt( // Gcad(Modify) 
    OdUInt32 insertionIndex, 
    OdDbObjectId objectId);

  /**
    Arguments:
    objectIds (I) Object IDs of the entities to be inserted.
  */
  OdResult insertAt( // Gcad(Modify) 
    OdUInt32 insertionIndex, 
    OdDbObjectIdArray objectIds);

  /** Description:
    Removes the specified entity or entities from this Group object.
    
    Arguments:
    objectId (I) Object ID of the entity to be removed.
  */
  OdResult remove( // Gcad(Modify) 
    OdDbObjectId objectId);

  /** Description:
    Removes the entity at the specified *index*, 
    or the specified entities at or above the specified *index*,
    from this Group object.

    Arguments:
    entityIndex (I) Entity *index*.
    
  */
  OdResult removeAt( // Gcad(Modify) 
    OdUInt32 entityIndex);

  /**
    Arguments:
    objectIds (I) Object IDs of the entities to be removed.
  */
  OdResult remove( // Gcad(Modify) 
    OdDbObjectIdArray objectIds);

  /** 
    Arguments:
    objectIds (I) Object IDs of the entities to be inserted.

    Remarks:
    If any of the entities in objectIds are not in this Group object,
    or are at an *index* > index, none of the entities will be removed.
        
  */
  OdResult removeAt( // Gcad(Modify) 
    OdUInt32 index, 
    OdDbObjectIdArray objectIds);

  /** Description:
    Replaces the specified entity in this Group object with 
    the specified entity currently not in this Group object.

    Arguments:
    oldId (I) Object ID of the entity to be 
    newId (I) Object ID of the entity to replace oldId.
  */
  OdResult replace( // Gcad(Modify) 
    OdDbObjectId oldId, 
    OdDbObjectId newId);

  /** Description:
    Rearranges the entities within this Group object.

    Arguments:
    fromIndex (I) Index of the first entity to be moved.
    toIndex (I) Destination *index* of the first entity moved.
    numItems (I) Number of objects to move.
      
    Remarks:
    This function transfers numItems starting at the fromIndex to the toIndex. 
  */
  OdResult transfer( // Gcad(Modify) 
    OdUInt32 fromIndex, 
    OdUInt32 toIndex, 
    OdUInt32 numItems);

  /** Description:
    Clears the contents of this Group object.
    
    Remarks:
    After clearing, this Group object contains no entities.
  */
  OdResult clear(); // Gcad(Modify) 

  /** Description:
    Returns the number of entities in this Group object.
  */
  OdUInt32 numEntities() const;

  /** Description:
    Returns true if and only if this Group object contains the specified entity.
    
    Arguments:
    pEntity (I) Pointer to the entity being tested.
  */
  bool has(
    const OdDbEntity* pEntity) const;

  /** Description:
    Returns the number of entities in this Group object, and their Object IDs.

    Arguments:
    objectIds (O) Receives the Object IDs.
  */
  OdUInt32 allEntityIds(
    OdDbObjectIdArray& objectIds) const;

  /** Description:
    Returns the *index* of the specified entity within this Group object.

    Arguments:
    objectId (I) Object ID of the entity.
    index (O) Index of objectId within this Group.

    Throws:
    @table
    Exception            Cause
    eInvalidInput        objectId is not in this Group object.
  */
  OdResult getIndex( // Gcad(Modify) 
    OdDbObjectId objectId, 
    OdUInt32& index) const;

  /** Description:
    Reverses the order of the entities in this Group object.
  */
  OdResult reverse(); // Gcad(Modify) 

  /** Description:
      Sets the *color* of all entities in this Group object to the specified *color*.
  void setColor(const OdCmColor &color);
  */

  /** Description:
    Sets the *color* *index* of all entities in this Group object to the specified value.
    
    Arguments:
    colorIndex (I) Color *index*.
  */
  OdResult setColorIndex( // Gcad(Modify) 
    OdUInt16 colorIndex);

  /** Description:
    Sets the *color* of all entities in this Group object to the specified value.

    Arguments:
    color (I) Color.
  */
  OdResult setColor(
    const OdCmColor& color);

  /** Description:
    Sets the *layer* of all entities in this Group object to the specified value.
    
    Arguments:
    layer (I) Layer *name*.
  */
  OdResult setLayer( // Gcad(Modify) 
    const OdChar * layer);

  /**
    Arguments:
    layerId (I) Object ID of the LayerTableRecord.  
  */
  OdResult setLayer( // Gcad(Modify) 
    OdDbObjectId layerId);

  /** Description:
    Sets the *linetype* of all entities in this Group object to the specified value.
    
    Arguments:
    linetype (I) Linetype *name*.
  */
  OdResult setLinetype( // Gcad(Modify) 
    const OdChar * linetype);

  /**
    Arguments:
    linetypeId (I) Object ID of *linetype*.
  */
  OdResult setLinetype( // Gcad(Modify) 
    OdDbObjectId linetypeID);

  /** Description:
    Sets the *linetype* scale of all entities in this Group object to the specified value.
    
    Arguments:
    linetypeScale (I) Linetype scale.
  */
  OdResult setLinetypeScale( // Gcad(Modify) 
    double linetypeScale);

  /** Description:
    Sets the *visibility* of all entities in this Group object to the specified value.
    
    Arguments:
    visibility (I) Visibility.
  */
  OdResult setVisibility( // Gcad(Modify) 
    OdDb::Visibility visibility);

  /** Description:
    Sets the PlotStyleName of all entities in this Group object to the specified value.

    Arguments:
    plotStyleName (I) PlotStyleName.
  */
  OdResult setPlotStyleName( // Gcad(Modify) 
    const OdChar * plotStyleName);

  /** Description:
    Sets the lineweight of all entities in this Group object to the specified value.
    
    Arguments:
    lineWeight (I) Lineweight.
  */
  OdResult setLineweight( // Gcad(Modify) 
    OdDb::LineWeight lineWeight);

  OdResult setHighlight(
    bool newVal);
  OdResult setMaterial(
    const OdChar* materialName);
  OdResult setMaterial(
    OdDbObjectId materialID);

  virtual OdResult applyPartialUndo(
    OdDbDwgFiler* undoFiler,
    OdRxClass*    classObj);

  virtual OdResult subErase(
    OdBool erasing = true);

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual void copied (
    const OdDbObject* pObject, 
    const OdDbObject* pNewObject);

  virtual void appendToOwner(
    OdDbIdPair& idPair, 
    OdDbObject* pOwnerObject, 
    OdDbIdMapping& ownerIdMap);

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  virtual OdResult subClose();

  virtual void erased(
    const OdDbObject* dbObj,
    OdBool erasing = true);

  virtual void goodbye(
    const OdDbObject* dbObj);

  /*
      void setHighlight(bool newVal);
      virtual void applyPartialUndo(OdDbDwgFiler* undoFiler, OdRxClass* classObj);
      virtual OdResult subErase(OdBool erasing = true);
      virtual void goodbye(const OdDbObject* dbObj);
  */
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbGroup object pointers.
*/
typedef OdSmartPtr<OdDbGroup> OdDbGroupPtr;

#include "TD_PackPop.h"

#endif //_ODDBGROUP_INCLUDED_

