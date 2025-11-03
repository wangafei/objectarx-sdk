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




#ifndef ODDB_DBSUBENT_H
#define ODDB_DBSUBENT_H /* {Secret} */

#include "DbBaseSubentId.h"
#include "DbObjectId.h"
#include "IdArrays.h"

/** Description:
    This class uniquely defines subentities within in an OdDbDatabase instance.  

    Remarks:
    Each OdDbFullSubentPath object consists of a OdDbSubentId object and
    an ordered array of Object IDs. The SubentId consists the index and subentType
    of the object. The array of Object IDs defines the path to the 
    subentity from the outermost entity (in PaperSpace or ModelSpace) 
    to the entity containing the subentity.
    
    Library: TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbFullSubentPath : public OdDbBaseFullSubentPath
{
public:
  OdDbFullSubentPath() 
  {
  }
  OdDbFullSubentPath(OdDb::SubentType type, OdGsMarker index)
    : OdDbBaseFullSubentPath(type, index)
  {
  }
  OdDbFullSubentPath(OdDbObjectId entId, OdDbSubentId subId)
    : OdDbBaseFullSubentPath(entId, subId)
  {
  }
  OdDbFullSubentPath(OdDbObjectId entId, OdDb::SubentType type, OdGsMarker index)
    : OdDbBaseFullSubentPath(entId, type, index)
  {
  }
  OdDbFullSubentPath(OdDbObjectIdArray objectIds, OdDbSubentId subId)
    : OdDbBaseFullSubentPath(*reinterpret_cast<OdDbStubPtrArray*>(&objectIds), subId)
  {
  }
  OdDbFullSubentPath(OdDbStubPtrArray objectIds, OdDbSubentId subId)
    : OdDbBaseFullSubentPath(objectIds, subId)
  {
  }
  OdDbFullSubentPath(const OdDbFullSubentPath& s)
  {
    OdDbBaseFullSubentPath::operator=(s);
  }
  OdDbFullSubentPath(const OdDbBaseFullSubentPath& s)
  {
    OdDbBaseFullSubentPath::operator=(s);
  }
  ~OdDbFullSubentPath()
  {
  }
  void objectIds(OdDbObjectIdArray& objectIdsArg) const
  {
    objectIdsArg = *reinterpret_cast<const OdDbObjectIdArray*>(&m_ObjectIds);
  }

  OdDbFullSubentPath& operator =(const OdDbFullSubentPath& fullSubentPath)
  {
    OdDbBaseFullSubentPath::operator=(fullSubentPath);
    return *this;
  }
  OdDbFullSubentPath& operator =(const OdDbBaseFullSubentPath& fullSubentPath)
  {
    OdDbBaseFullSubentPath::operator=(fullSubentPath);
    return *this;
  }

  bool operator==(const OdDbFullSubentPath& fullSubentPath) const
  {
    return OdDbBaseFullSubentPath::operator==(fullSubentPath);
  }

  bool operator!=(const OdDbFullSubentPath& fullSubentPath) const
  {
    return OdDbBaseFullSubentPath::operator!=(fullSubentPath);
  }
  /** Description:
    Returns a reference to the embedded OdDbObjectIdArray object in this FullSubentPath object.
  */
  const OdDbObjectIdArray& objectIds() const
  {
    return *reinterpret_cast<const OdDbObjectIdArray*>(&m_ObjectIds);
  }
  OdDbObjectIdArray& objectIds()
  {
    return *reinterpret_cast<OdDbObjectIdArray*>(&m_ObjectIds);
  }
  
  /** Description:
    Returns a reference to, or a copy of, the embedded OdDbSubentId object in this FullSubentPath object.
  */
  const OdDbSubentId& subentId() const
  {
    return m_SubentId;
  }

  OdDbSubentId& subentId()
  {
    return m_SubentId;
  }
  TOOLKIT_EXPORT_STATIC static const OdDbFullSubentPath kNull;
};

/** Description:
    This template class is a specialization of the OdArray class for OdDbFullSubentPath object pointers.
*/
#define kNullSubent OdDbFullSubentPath::kNull
typedef OdArray<OdDbFullSubentPath> OdDbFullSubentPathArray;

#endif


