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




#ifndef ODDB_DBBASESUBENT_H
#define ODDB_DBBASESUBENT_H /* {Secret} */

#include "DbRootExport.h"
#include "DbStubPtrArray.h"

/** Description:
    This class implements Subentity Id objects for OdDbEntity objects in an OdDbDatabase instance.  

    Remarks:
    A given OdDbEntity object may consist of any number of graphical subentities.
    
    Subentity *type* must be one of the following:

    @table
    Name                        Value
    OdDb::kNullSubentType       0
    OdDb::kFaceSubentType       1
    OdDb::kEdgeSubentType       2
    OdDb::kVertexSubentType     3   
    OdDb::kMlineSubentCache     4  

    Each SubentityId object is created from a Subentity *type* and an *index*.
    
    Library: TD_DbRoot

    {group:OdDbRoot_Classes}
*/
class DBROOT_EXPORT OdDbSubentId
{
public:
  OdDbSubentId()
    : mType(OdDb::kNullSubentType)
    , mIndex(0) 
    , mpTypeClass(NULL)
  {}

  OdDbSubentId(OdDb::SubentType type, OdGsMarker index)
    : mType(type)
    , mIndex(index) 
    , mpTypeClass(NULL)
  {}
  OdDbSubentId(OdRxClass* pTypeClass, OdGsMarker index)
	  : mType(OdDb::kClassSubentType)
    , mIndex(index)
    , mpTypeClass(pTypeClass)
  {}

  bool operator ==(const OdDbSubentId& subentId) const
  {
    return ((mIndex == subentId.mIndex) && (mType == subentId.mType) && (mpTypeClass == subentId.mpTypeClass));
  }
      
  bool operator !=(const OdDbSubentId& subentId) const
  {
    return ((mIndex != subentId.mIndex) || (mType != subentId.mType) || (mpTypeClass != subentId.mpTypeClass));
  }
  
  /** Description:
    Returns the *type* of this SubentId object.

    Remarks:
    
    *type* returns one of the following:

    @table
    Name                        Value
    OdDb::kNullSubentType       0
    OdDb::kFaceSubentType       1
    OdDb::kEdgeSubentType       2
    OdDb::kVertexSubentType     3   
    OdDb::kMlineSubentCache     4  
  */
  OdDb::SubentType type () const 
  {
    return mType; 
  }

  /** Description:
    Sets the *type* of this SubentId object.

    Arguments:
    type (I) Type.
    
    Remarks:
    *type* must be one of the following:

    @table
    Name                        Value
    OdDb::kNullSubentType       0
    OdDb::kFaceSubentType       1
    OdDb::kEdgeSubentType       2
    OdDb::kVertexSubentType     3   
    OdDb::kMlineSubentCache     4  
  */
  void setType(OdDb::SubentType type) 
  {
    mType = type;
    if (mType != OdDb::kClassSubentType)
      mpTypeClass = NULL;
  }

  /** Description:
    Returns the *index* of this SubentId object.
  */
  OdGsMarker index() const 
  {
    return mIndex; 
  }
  
  /** Description:
    Sets the *index* of this SubentId object.
    Arguments:
    index (I) Index.
  */
  void setIndex(OdGsMarker index) 
  {
    mIndex = index; 
  }

  OdRxClass* typeClass() const
  {
    return mpTypeClass;
  }
  void setTypeClass(OdRxClass* pClass) 
  { 
    mpTypeClass = pClass;
    if (mpTypeClass != NULL)
      mType = OdDb::kClassSubentType;
  }

  static const OdDbSubentId m_kNullSubentId;
private:
  OdDb::SubentType mType;
  OdGsMarker       mIndex;
  OdRxClass*       mpTypeClass;
};

#define kNullSubentId (OdDbSubentId::m_kNullSubentId)

/** Description:
  Default Gs Marker value for highlight entire entity.
*/
const OdGsMarker kNullSubentIndex = 0;

/** Description:
    This base class uniquely defines subentities within in a database instance.

    Remarks:
    Each OdDbBaseFullSubentPath object consists of a OdDbSubentId object and
    an ordered array of Object IDs. The SubentId consists the index and subentType
    of the object. The array of Object IDs defines the path to the 
    subentity from the outermost entity to the entity containing the subentity.
    
    Library: TD_DbRoot

    {group:OdDbRoot_Classes}
*/
class DBROOT_EXPORT OdDbBaseFullSubentPath
{
public:
  OdDbBaseFullSubentPath() 
  {}
  OdDbBaseFullSubentPath(OdDb::SubentType type, OdGsMarker index)
    : m_SubentId(type, index) 
  {}
  OdDbBaseFullSubentPath(OdDbStub* entId, OdDbSubentId subId)
    : m_SubentId(subId) 
  {
    m_ObjectIds.clear();
    m_ObjectIds.append(entId) ;
  }

  OdDbBaseFullSubentPath(OdDbStub* entId, OdDb::SubentType type, OdGsMarker index)
    : m_SubentId(type, index)
  {
    m_ObjectIds.clear();
    m_ObjectIds.append(entId) ;
  }

  OdDbBaseFullSubentPath(OdDbStubPtrArray objectIds, OdDbSubentId subId)
    : m_ObjectIds(objectIds) 
    , m_SubentId(subId) 
  {
  }

  void objectIds(OdDbStubPtrArray& objectIdsArg) const
  {
    objectIdsArg = m_ObjectIds;
  }

  OdDbBaseFullSubentPath& operator =(const OdDbBaseFullSubentPath& fullSubentPath)
  {
    m_ObjectIds = fullSubentPath.objectIds();
    m_SubentId  = fullSubentPath.subentId();
    return *this;
  }

  bool operator==(const OdDbBaseFullSubentPath& fullSubentPath) const
  {
    if (this == &fullSubentPath) return true;
    return m_ObjectIds == fullSubentPath.objectIds() && m_SubentId == fullSubentPath.subentId();
  }

  bool operator!=(const OdDbBaseFullSubentPath& fullSubentPath) const
  {
    if (this == &fullSubentPath) return false;
    return !(m_ObjectIds == fullSubentPath.objectIds() && m_SubentId == fullSubentPath.subentId());
  }

  /** Description:
    Returns a reference to the embedded OdDbStubPtrArray object in this BaseFullSubentPath object.
  */
  const OdDbStubPtrArray& objectIds() const
  {
    return m_ObjectIds;
  }
  OdDbStubPtrArray& objectIds()
  {
    return m_ObjectIds;
  }
  
  /** Description:
    Returns a reference to, or a copy of, the embedded OdDbSubentId object in this BaseFullSubentPath object.
  */
  const OdDbSubentId subentId() const
  {
    return m_SubentId;
  }

  OdDbSubentId& subentId()
  {
    return m_SubentId;
  }
  
protected:              
  OdDbStubPtrArray  m_ObjectIds;
  OdDbSubentId      m_SubentId;
};

/** Description:
    This template class is a specialization of the OdArray class for OdDbBaseFullSubentPath object pointers.
*/
typedef OdArray<OdDbBaseFullSubentPath> OdDbBaseFullSubentPathArray;

DBROOT_EXPORT OdRxObject* baseDatabaseBy(OdDbStub* id);

#endif
