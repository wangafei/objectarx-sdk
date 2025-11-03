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




#ifndef __ODDBIDMAPPING_INCLUDED__
#define __ODDBIDMAPPING_INCLUDED__

#include "OdDb.h"
#include "OdaDefs.h"
#include "DbObjectId.h"
#include "DbObject.h"
#include "RxObject.h"
#include "RxObjectImpl.h"
#include "DbGraph.h"

class OdDbDatabase;
class OdDbIdMapping;

#include "TD_PackPush.h"

/** Description:
This template class is a specialization of the OdSmartPtr class for OdDbIdMapping object pointers.
*/
typedef OdSmartPtr<OdDbIdMapping> OdDbIdMappingPtr;

/** Description:
    This class is the element class for OdDbMapping, 
    which is used in deepclone operations to map
    Object IDs from the original objects to their clones.
  
    Library:
    TD_Db
    
    Remarks:
    Key is the Object ID of the original object.  
    Value is the Object ID of the cloned object.  
    
    {group:OdDb_Classes}
*/
class OdDbIdPair
{
public:
  /**
    Arguments:
    source (I) OdDbIdPair to be copied.
    key (I) Object ID to use as *key*.
    value (I) Object ID to use as Value.
    cloned (I) Key object has been *cloned*.
    ownerXlated (I) Owner of *key* object has been translated.    
  */
  OdDbIdPair()
    : m_bCloned(false), m_bOwnerXlated(false),m_bPrimary(false) { }
    
  OdDbIdPair(
    const OdDbIdPair& source)
    : m_Key(source.key())
    , m_Value(source.value())
    , m_bCloned(source.isCloned())
    , m_bOwnerXlated(source.isOwnerXlated())
	,m_bPrimary(source.isPrimary()){ }

  OdDbIdPair(
    const OdDbObjectId& key)
    : m_Key(key)
    , m_bCloned(false)
    , m_bOwnerXlated(false)
	, m_bPrimary(false){ }
    
  OdDbIdPair(
    OdDbObjectId key, 
    OdDbObjectId value, 
    bool cloned, 
	bool isPrimary = false,
    bool ownerXlated = true)
    : m_Key(key)
    , m_Value(value)
    , m_bCloned(cloned)
	, m_bPrimary(isPrimary)
    , m_bOwnerXlated(ownerXlated) { }

  
  /** Description:
    Returns the *key* for this IdPair object.
  */
  OdDbObjectId key() const { return m_Key; } 

  /** Description:
    Returns the *value* for this IdPair object.
  */
  OdDbObjectId value() const { return m_Value; }

  /** Description:
    Returns true if and only if the *key* object for this IdPair object has been cloned.
  */
  inline bool isCloned() const { return m_bCloned; }
  
  //Gcad(Add)
  inline bool isPrimary() const {return m_bPrimary;}
  /** Description:
    Returns true if and only if the owner of the *key* object for this IdPair object has been translated.
  */
  inline bool isOwnerXlated() const { return m_bOwnerXlated; }
  
  /** Description:
    Sets the parameters for this IdPair object according to the arguments.

    Arguments:
    key (I) Object ID to use as *key*.
    value (I) Object ID to use as Value.
    cloned (I) Key object has been *cloned*.
    ownerXlated (I) Owner of *key* object has been translated.    
  */
  OdDbIdPair& set(
    OdDbObjectId key, 
    OdDbObjectId value,
    bool cloned = false, 
	bool isPrimary = false,
    bool ownerXlated = true)
  {
    setKey(key);
    setValue(value);
    setIsCloned(cloned);
	setIsPrimary(isPrimary);
    setIsOwnerXlated(ownerXlated);
    return *this;
  }

    
  /** Description:
    Sets the *key* for this IdPair object.

    Arguments:
    key (I) Object ID to use as *key*.
  */
  void setKey(
    OdDbObjectId key) { m_Key = key; }
    
  /** Description:
    Sets the *value* for this IdPair object.

    Arguments:
    value (I) Object ID to use as Value.
  */
  void setValue(
    OdDbObjectId value) { m_Value = value; }
    
  /** Description:
    Controls the *cloned* setting for this IdPair object.

    Arguments:
    cloned (I) Key object has been *cloned*.

	//Gcad(Modify)
  */
  void setIsCloned(
    bool cloned) { m_bCloned = cloned; }

  //Gcad(Add)
  void setIsPrimary(
    bool isPrimary) { m_bPrimary = isPrimary; }

  /** Description:
    Controls the owner translated setting for this IdPair object.

    Arguments:
    ownerXlated (I) Owner of *key* object has been translated.    

	//Gcad(Modify)
  */
  void setIsOwnerXlated(
    bool ownerXlated) { m_bOwnerXlated = ownerXlated; }
  
private:
  OdDbObjectId m_Key;
  OdDbObjectId m_Value;
  bool m_bCloned;
  bool m_bOwnerXlated;
  bool m_bPrimary;//Gcad(Add)
};

class OdDbIdMappingIter;

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbIdMappingIter object pointers.
*/
typedef OdSmartPtr<OdDbIdMappingIter> OdDbIdMappingIterPtr;

/** Description: 
  
    {group:TD_Namespaces}
*/

/** Description:
    This class is used in deepclone operations to map, using OdDbIdPair objects,
    Object IDs from the original objects to their clones.
    
    Library:
    TD_Db
    
    Remarks:
    There is no mechanism to clear all the mappings in an OdDbIdMapping instance; a new
    instance must be created for each deepclone operation.

    {group:OdDb_Classes}
*/
//Gcad(Modify):
class OdDbIdMappingImpl;

class OdIdMapping : public OdRxObject
{
protected:
  OdIdMapping() {}
  ~OdIdMapping() {}
};

class TOOLKIT_EXPORT OdDbIdMapping : public OdRxObjectImpl<OdIdMapping>
{
public:
  ODRX_DECLARE_MEMBERS(OdDbIdMapping);

  OdDbIdMapping();

  OdDbIdMapping(OdDbDatabase* pOrigDb, OdDbDatabase* pDestDb,
    OdDb::DeepCloneType DCType, OdDb::DuplicateRecordCloning DRCloning);

  virtual ~OdDbIdMapping();
  
  /** Description:
    Adds the specified IdPair object to this IdMapping object.
    
    Arguments:
    idPair (I) IdPair to add.
  */
  virtual OdResult assign(const OdDbIdPair& idPair);

  /** Description:
    Returns the *value* of the IdPair in this IdMapping object
    that matches the *key* in the specified IdPair object.
    
    Arguments:
    idPair (I/O) Supplies the *key* and receives the *value*.
    
    Remarks:
    Returns true if and only if the *key* is found. 
  */
  virtual bool compute(OdDbIdPair& idPair) const;

  // Gcad(Add)
  virtual bool change(const OdDbIdPair&);
  
  /** Description:
    Deletes the IdPair with the specified *key* from this IdMapping object.
    
    Arguments:
    key (I) Object ID *key* to delete.
  */
  virtual bool del(OdDbObjectId key);

  /** Description:
    Creates an Iterator object that provides access to the IdPair objects in this IdMapping object.
  */ 
  virtual OdDbIdMappingIterPtr newIterator();

  /** Description:
    Returns the destination *database* for the deepclone operation using this IdMapping object. 
  */
  virtual OdResult  destDb(OdDbDatabase*& db) const;  

  OdDbDatabase* destDb() const { OdDbDatabase* pDb = NULL; destDb(pDb); return pDb; }

  /** Description:
    Sets the destination *database* for the deepclone operation using this IdMapping object.
    
    Arguments:
    pDb (I) Pointer to the destination *database*. 
  */
  virtual OdResult setDestDb(OdDbDatabase* pDb);

  /** Description:
    Returns the source *database* for the deepclone operation using this IdMapping object. 
  */
  virtual OdResult origDb(OdDbDatabase*& db) const;
  
  OdDbDatabase* origDb() const { OdDbDatabase* pDb = NULL; origDb(pDb); return pDb; }

  /** Description:
    Notification function called whenever the Xref Block ID is about to be inserted
    into the destination *database*.
    
    Returns the ObjectID of the Xref Block.
  */
  virtual OdDbObjectId insertingXrefBlockId() const;
  
  /** Description:
    Returns the type of deepclone operation using this IdMapping object.
    
    Remarks:
    deepCloneContext() returns one of the of the following:
    
    @table
    Name                Value   Description
    kDcCopy             0       Copy Array Mirror
    kDcExplode          1       Explode
    kDcBlock            2       Block definition
    kDcXrefBind         3       Xref Bind
    kDcSymTableMerge    4       Xref Attach DxfIn IgesIn
    kDcInsert           6       Insert of a .dwg file
    kDcWblock           7       Wblock
    kDcObjects          8       OdDbDatabase::deepCloneObjects()
    kDcXrefInsert       9       Xref Insert Xref BInd
    kDcInsertCopy       10      Insert() 
    kDcWblkObjects      11      Wblock objects
    
  */
  virtual OdDb::DeepCloneType deepCloneContext() const;
  
  /** Description:
    Returns the type of duplicate record cloning for IdMapping object.
    
    Remarks:
    duplicateRecordCloning() returns one of the of the following:
    
    @table
    Name                  Value   Description
    kDrcNotApplicable     0       Not applicable to the object.
    kDrcIgnore            1       If a duplicate record exists, use the existing record in the *database*, and ignore the clone.
    kDrcReplace           2       If a duplicate record exists, replace it with the cloned record.
    kDrcXrefMangleName    3       Incoming record names are mangled with <Xref>$0$<name>
    kDrcMangleName        4       Incoming record names are mangled with $0$<name>
    kDrcUnmangleName      5       Unmangle the names mangled by kDrcMangleName, then default to kDrcIgnore. Typically used by RefEdit when checking records into the original *database*.  

  */
  virtual OdDb::DuplicateRecordCloning duplicateRecordCloning() const;

  virtual OdResult copyFrom(const OdRxObject* other);

protected:
  friend class OdDbIdMappingImpl;
  OdDbIdMapping(OdDbIdMappingImpl* pImpl);
  OdDbIdMappingImpl* m_pImpl;
};

/** Description:
    This class defines Iterator objects that 
    traverse OdDbIdPair records in OdDbIdMapping instances.

    Library:
    TD_Db
  
    Remarks:
    Instances are returned by OdDbIdMapping::newIterator().

    {group:OdDb_Classes}
*/
class OdIdMappingIterImpl;

class OdIdMappingIter : public OdRxObject
{
protected:
  OdIdMappingIter() {}
  ~OdIdMappingIter() {}
};

class TOOLKIT_EXPORT OdDbIdMappingIter :public OdRxObjectImpl<OdIdMappingIter>
{
public:
  ODRX_DECLARE_MEMBERS(OdDbIdMappingIter);

  OdDbIdMappingIter();

  // Gcad(Add)
  OdDbIdMappingIter(const OdDbIdMapping&);

  virtual ~OdDbIdMappingIter();

  // Gcad(Add)
  virtual OdResult iterateOn(
    const OdDbIdMapping&);

  /** Description:
    Sets this Iterator object to reference the OdIdPair that it would normally return first.
     
    Remarks:
    Allows multiple traversals of the Iterator list.
  */  
  virtual void start();
  
  /** Description:
    Returns the IdPair pointed to by this Iterator Object.
    
    Arguments:
    idPair (O) IdPair.
  */ 
  virtual bool getMap(
    OdDbIdPair& idPair);

  /** Description:
    Increments this Iterator object.
  */
  virtual bool next();
  
  /** Description:
    Returns true if and only if the traversal by this Iterator *object* is complete.
  */  
  virtual bool done();

protected:
  friend class OdDbIdMappingIterImpl;
  OdDbIdMappingIter(OdDbIdMappingIterImpl* pImpl);
  OdDbIdMappingIterImpl* m_pImpl;
};


class TOOLKIT_EXPORT OdDbObjectIdGraphNode : public OdDbGraphNode
{
public:
  OdDbObjectIdGraphNode(const OdDbObjectId& id) : OdDbGraphNode((OdDbStub*)id), mId(id) {}
  ~OdDbObjectIdGraphNode() {}

  OdDbObjectId id () const { return mId; }

private:
  OdDbObjectId mId;
};

// 注意：本类功能未完全实现
class TOOLKIT_EXPORT OdDbObjectIdGraph : public OdDbGraph
{
public:
  OdDbObjectIdGraph() {}
  ~OdDbObjectIdGraph() {}

  OdResult addNode (OdDbObjectIdGraphNode* pNode)
  { /*TODO: Add to Mapping*/ return OdDbGraph::addNode(pNode); }

  OdResult delNode (OdDbObjectIdGraphNode* pNode)
  { /*TODO: del from Mapping*/ return OdDbGraph::delNode(pNode); }

  OdDbObjectIdGraphNode* findNode (const OdDbObjectId& destId) const
  {
    for(int i=0; i<numNodes(); ++i)
	{
      OdDbObjectIdGraphNode* pNode = idNode(i);
	  if(pNode->id() == destId)
        return pNode;
	}
	return NULL;
  }

  OdDbObjectIdGraphNode* idNode (int idx) const
  { return (OdDbObjectIdGraphNode*)node(idx); }

private:
  // Gcad(TODO)
  //OdDbIdMapping mIdNodeMap;
};

#include "TD_PackPop.h"

#endif // __ODDBIDMAPPING_INCLUDED__


