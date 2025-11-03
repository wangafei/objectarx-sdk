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


#ifndef _DBSSET_H_
#define _DBSSET_H_

#include "Ge/GePoint3d.h"
#include "DbDatabase.h"
#include "DbObjectId.h"
#include "DbObject.h"
#include "DbObjectIterator.h"
#include "ResBuf.h"
#include "DbSubentId.h"
#include "SSet.h"

//class OdDbSelectionSet;
//class OdDbBlockTableRecord;


/** Description:
    This class is the abstract base class for all selection filters.

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT ODRX_ABSTRACT OdDbSelectionFilter : public OdRxObject
{
protected:
  OdDbSelectionFilter();
public:
  ODRX_DECLARE_MEMBERS(OdDbSelectionFilter);

  virtual bool accept(const OdDbObjectId& entityId) const = 0;
};

typedef OdSmartPtr<OdDbSelectionFilter> OdDbSelectionFilterPtr;


class OdDbParametrizedSF;
typedef OdSmartPtr<OdDbParametrizedSF> OdDbParametrizedSFPtr;

/** Description:
    This class represents selection filter defined by ResBuf chain.

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT ODRX_ABSTRACT OdDbParametrizedSF : public OdDbSelectionFilter
{
protected:
  OdDbParametrizedSF();
public:
  static OdDbParametrizedSFPtr createObject(const OdResBuf* pSpec, const OdDbDatabase* pDb);

  virtual void setSpecification(const OdResBuf* /*pSpec*/, const OdDbDatabase* /*pDb*/ = 0) {}
  virtual OdResBufPtr specification() const { return OdResBufPtr(); }
  virtual const OdDbDatabase* database() const { return 0; }
};

class ODRX_ABSTRACT TOOLKIT_EXPORT OdDbSelectionInfo : public OdRxObject
{
protected:
  OdDbSelectionInfo();
public:
  ODRX_DECLARE_MEMBERS(OdDbSelectionInfo);

  virtual int  subentCount() const = 0;
  virtual bool getSubentity(int i, OdDbFullSubentPath& path) const = 0;
  virtual int  findSubentity(const OdDbFullSubentPath& path) const = 0; // <0, no found
  virtual bool appendSubentity(const OdDbFullSubentPath& path) = 0; // NO duplicate
  virtual void removeSubentity(const OdDbFullSubentPath& path) = 0;

  virtual OdDbSelectionMethodPtr method() const = 0;
  virtual void setMethod(OdDbSelectionMethodPtr m) = 0;

  virtual OdRxObjectPtr extendInfo() const = 0;
  virtual void setExtendInfo(OdRxObjectPtr pInfo) = 0;
};
typedef OdSmartPtr<OdDbSelectionInfo> OdDbSelectionInfoPtr;


/** Description:
  This class implements iterators for OdDbSelectionSet objects.

  Remarks:

  Instances are returned by OdDbSelectionSet::newIterator().

  {group:OdDb_Classes}
*/
//class ODRX_ABSTRACT TOOLKIT_EXPORT OdDbSelectionSetIterator : public OdRxObject
class ODRX_ABSTRACT TOOLKIT_EXPORT OdDbSelectionSetIterator : public OdSelectionSetIterator
{
protected:
  OdDbSelectionSetIterator();
public:
  ODRX_DECLARE_MEMBERS(OdDbSelectionSetIterator);

  /** Description:
      Returns the Object ID of the entity at the current position specified by
      this Iterator object.
  */
  virtual OdDbObjectId objectId() const = 0;

  virtual bool getSubentity(OdUInt32 i, OdDbFullSubentPath& path) = 0;

  virtual OdDbSelectionInfoPtr info() const { return OdDbSelectionInfoPtr(); }
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbSelectionSetIterator object pointers.
*/
typedef OdSmartPtr<OdDbSelectionSetIterator>  OdDbSelectionSetIteratorPtr;

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbSelectionSet object pointers.
*/
typedef OdSmartPtr<OdDbSelectionSet>  OdDbSelectionSetPtr;

/** Description:
    This class represents Selection Sets in an Teigha application.

    Remarks:
    Only entities from an OdDbDatabase object's ModelSpace or PaperSpace may be
    added to a Selection Set.

    {group:OdDb_Classes}
*/
class ODRX_ABSTRACT TOOLKIT_EXPORT OdDbSelectionSet : public OdSelectionSet
{
protected:
  OdDbSelectionSet();
public:
  ODRX_DECLARE_MEMBERS(OdDbSelectionSet);

  /** Description:
    Creates a SelectionSet object for the specified *database*. 
    Arguments:
    pDb (I) Pointer to the *database* object for which to create the SelectionSet object.
    Remarks:
    Returns a SmartPointer to the new SelectionSet object.
  */
  static OdDbSelectionSetPtr createObject(const OdDbDatabase *pDb);
  
  virtual const OdRxObject* baseDatabase() const;
  virtual const OdDbDatabase* database() const = 0;

  /** Description:
      Returns an Iterator object that provides access to the entities in this Selection Set.
  */
  //virtual OdSelectionSetIteratorPtr newIterator() const = 0; 

  /** Description:
  */
  virtual OdDbObjectIdArray objectIdArray() const;

  // operations on the selection set 

  /** Description:
    Filter selection only.  

    Arguments:
    pDb (I) Pointer to the *database* object for which to create the SelectionSet object.
    pFilter(I) object of type OdDbSelectionFilter or pointer to a OdResBuf chain defining the filter.
  */
  static OdDbSelectionSetPtr select(const OdDbDatabase *pDb, const OdRxObject* pFilter = 0);

  /** Description:
    Filter selection only.  

    Arguments:
    vpId (I) id of OdDbViewportTableRecord  record or OdDbViewport entity in which to select.
    nPoints (I)
    wcsPts (I)
    mode (I)
    pFilter(I) object of type OdDbSelectionFilter or pointer to a OdResBuf chain defining the filter.
  */
  static OdDbSelectionSetPtr select(
    const OdDbObjectId& vpId,
    int nPoints,
    const OdGePoint3d* wcsPts,
    OdDbSelectionMode mode = OdDbVisualSelection::kCrossing,
    OdDbSelectionSubentMode sm = OdDbVisualSelection::kDisableSubents,
    OdGsSelectionReactor* pReactor = NULL,
    OdDbSelectionMethod* pMethod = NULL,
    const OdRxObject* pFilter = NULL);
  
  /** Description:
    Returns the number of entities in this group.
  */
  //virtual OdUInt32 numEntities() const = 0;

  TD_USING(OdSelectionSet::append);

  /** Description:
    Appends the specified entity to this SelectionSet object.  

    Arguments:
    entityId (I) Object ID of the OdDbEntity. 
    method(I) Selection method to associate with object
  */
  virtual void append(OdDbStub* entityId, OdDbSelectionMethod* pMethod = 0);
  virtual void append(const OdDbObjectId& entityId, OdDbSelectionMethod* pMethod = 0) = 0;

  /** Description:
    Appends the specified entity to this SelectionSet object.  

    Arguments:
    entityIds (I) Array of Object IDs of the OdDbEntity's.
    method(I) Selection method to associate with objects
  */
  virtual void append(const OdDbObjectIdArray& entityIds, OdDbSelectionMethod* pMethod = 0);

  /** Description:
  Appends the specified subentity to this SelectionSet object.  

  Arguments:
  subent (I) Subentity path to append. 
  */
  virtual void append(const OdDbBaseFullSubentPath& subent, OdDbSelectionMethod* pMethod = 0);
  virtual void append(const OdDbFullSubentPath& subent, OdDbSelectionMethod* pMethod = 0) = 0;

  /** Description:
    Appends the specified entity to this SelectionSet object.  

    Arguments:
    pSSet (I) Other selection set to copy entities from. 
  */
  virtual void append(const OdSelectionSet* pSSet);

  TD_USING(OdSelectionSet::remove);

  /** Description:
    Removes the specified entity from this SelectionSet object.  

    Arguments:
    entityId (I) Object ID of the OdDbEntity. 
  */
  virtual void remove(OdDbStub* entityId);
  virtual void remove(const OdDbObjectId& entityId) = 0;

  /** Description:
    Removes the specified entity from this SelectionSet object.  

    Arguments:
    entityIds (I) Array Object ID of the OdDbEntity. 
  */
  virtual void remove(const OdDbObjectIdArray& entityIds);

  /** Description:
  Removes the specified subentity from this SelectionSet object.  

  Arguments:
  subent (I) Subentity path  to remove. 
  */
  virtual void remove(const OdDbBaseFullSubentPath& subent);
  virtual void remove(const OdDbFullSubentPath& subent) = 0;

  /** Description:
  Removes the specified entity from this SelectionSet object.  

  Arguments:
  pSSet (I) Object ID of the OdDbEntity. 
  */
  virtual void remove(const OdSelectionSet* pSSet);

  TD_USING(OdSelectionSet::isMember);

  /** Description:
    Returns true if and only if the specified entity is a member
    of this SelectionSet object.
    Arguments:
    entityId (I) Object ID of the OdDbEntity. 
  */
  virtual bool isMember(OdDbStub* entityId) const;
  virtual bool isMember(const OdDbObjectId& entityId) const = 0;

  /** Description:
  Returns true if and only if the specified subentity is a member
  of this SelectionSet object.
  Arguments:
  entityId (I) Subentity path. 
  */
  virtual bool isMember(const OdDbBaseFullSubentPath& subent) const;
  virtual bool isMember(const OdDbFullSubentPath& subent) const = 0;

  TD_USING(OdSelectionSet::method);

  virtual OdDbSelectionMethodPtr method(OdDbStub* entityId) const;
  virtual OdDbSelectionMethodPtr method(const OdDbObjectId& entityId) const = 0;

  /** Description:
    Removes all members of this SelectionSet object.
  */
  //virtual void clear() = 0;
};

#endif //_DBSSET_H_

