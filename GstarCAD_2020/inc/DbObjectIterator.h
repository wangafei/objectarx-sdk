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




#ifndef _ODDBOBJECTITERATOR_INCLUDED_
#define _ODDBOBJECTITERATOR_INCLUDED_

#include "RxObject.h"
#include "DbObjectId.h"

class OdDbEntity;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbEntity object pointers.
*/
typedef OdSmartPtr<OdDbEntity> OdDbEntityPtr;

/** Description:
    This class defines bidirectional Iterator objects that traverse entities contained in complex entities.
    
    
    OdDbBlock Table Records in an OdDbDatabase instance.

    Library:
    TD_Db
    
    Remarks:
    Complex entities include the following:
    
    @table
    Entity               Iterated entities
    OdDbBlockReference   All
    OdDb2dPolyline       Vertex
    OdDb3dPolyline       Vertex
    OdDbPolyFaceMesh     Vertex
    OdDbPolygonMesh      Vertex

    This class cannot directly instantiated, but must be instantiated with the
    iterator creation methods of the class to be iterated through.

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbObjectIterator : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbObjectIterator);

  OdDbObjectIterator() {}
  virtual ~OdDbObjectIterator() {}

  /** Description:
    Sets this Iterator object to reference the *entity* that it would normally return first.
     
    Remarks:
    Allows multiple traversals of the iterator list.

    Arguments:
    atBeginning (I) True to start at the beginning, false to start at the end. 
    skipErased (I) If and only if true, *erased* records are skipped.
  */  
  virtual void start(
    bool atEnd = false, 
    bool skipErased = true) = 0;

  /** Description:
    Returns true if and only if the traversal by this Iterator object is complete.
  */  
  virtual bool done() const = 0;

  /** Description:
    Returns the Object ID of the *entity* currently referenced by this Iterator object.
  */
  virtual OdDbObjectId objectId() const = 0;  // For DBRO
  virtual OdDbEntity* entity() = 0;           // For Non-DBRO

  /** Description:
    Opens and returns the *entity* currently referenced by this Iterator object.

    Arguments:
    openMode (I) Mode in which to open the *entity*.
    openErasedEntity (I) If and only if true, *erased* records will be opened or retrieved.

    Remarks:
    Returns a SmartPointer to the opened *entity* if successful, otherwise a null SmartPointer.
  */
  virtual OdDbEntityPtr entity(
    OdDb::OpenMode openMode /*=OdDb::kForRead*/, 
    bool openErasedEntity = false) = 0;       // For both

  /** Description:
    Steps this Iterator object.

    Arguments:
    forward (I) True to step *forward*, false to step backward.
    skipErased (I) If and only if true, *erased* records are skipped.
  */
  virtual void step(
    bool backwards = false, 
    bool skipErased = true) = 0;

  /** Description:
    Positions this Iterator object at the specified record.
    Arguments:
    objectId (I) Object ID of the *entity*.
    pEntity(I) Pointer to the *entity*.
  */  
  virtual bool seek(
    OdDbObjectId objectId) = 0;
  virtual bool seek(
    const OdDbEntity* pEntity) = 0;

  // Gcad(Add)
  void setPosition(OdDbEntity* pEnt);
  void setPosition(OdDbObjectId objId);
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbObjectIterator object pointers.
*/
typedef OdSmartPtr<OdDbObjectIterator> OdDbObjectIteratorPtr;

#endif //_ODDBOBJECTITERATOR_INCLUDED_

