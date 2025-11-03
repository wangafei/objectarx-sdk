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


#ifndef _SSET_H_
#define _SSET_H_

#include "OdPlatform.h"
#include "DbExport.h"

#include "Ge/GePoint3d.h"
#include "DbBaseSubentId.h"

/** Description:
    This class is the abstract base class for all selection methods.

    {group:OdDb_Classes}
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdDbSelectionMethod : public OdRxObject
{
protected:
  OdDbSelectionMethod();
public:
  ~OdDbSelectionMethod();
  ODRX_DECLARE_MEMBERS(OdDbSelectionMethod);

  enum Type
  {
	  kVisual     = 1,
	  kNonVisual  = 2,
	  kCustom     = 3
  };
  virtual Type methodType() const = 0;
};

typedef OdSmartPtr<OdDbSelectionMethod> OdDbSelectionMethodPtr;

class OdGiViewport;

/** Description:

    {group:OdDb_Classes}
*/
class FIRSTDLL_EXPORT OdDbVisualSelection : public OdDbSelectionMethod
{
protected:
  OdDbVisualSelection();
public:
  ~OdDbVisualSelection();
  ODRX_DECLARE_MEMBERS(OdDbVisualSelection);

  virtual OdDbSelectionMethod::Type methodType() const; // kVisual

  enum Mode
  {
    kPoint        = 0,
    kBox          = 1,
    kWindow       = 2,
    kCrossing     = 3,
    kFence        = 4,
    kWPoly        = 5,
    kCPoly        = 6
  };
  
  enum SubentMode
  {
    kDisableSubents = 0,
    kEnableSubents = 1
  };

  virtual OdGiViewport& viewport() const = 0;
  virtual OdGePoint3dArray points() const = 0; // WCS
  virtual Mode mode() const = 0;
  virtual SubentMode subentMode() const = 0;
};

typedef OdDbVisualSelection::Mode OdDbSelectionMode;
typedef OdDbVisualSelection::SubentMode OdDbSelectionSubentMode;

typedef OdSmartPtr<OdDbVisualSelection> OdDbVisualSelectionPtr;


/** Description:
  This class implements iterators for OdSelectionSet objects.

  Remarks:

  Instances are returned by OdSelectionSet::newIterator().

  {group:OdDb_Classes}
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdSelectionSetIterator : public OdRxObject
{
protected:
  OdSelectionSetIterator();
public:
  ~OdSelectionSetIterator();
  ODRX_DECLARE_MEMBERS(OdSelectionSetIterator);
  

  /** Description:
    Returns true if and only if the traversal by this Iterator *object* is complete.
  */  
  virtual bool done() const = 0;

  /** Description:
    Sets this Iterator *object* to reference the entry following the current entry.

    Remarks:
    Returns true if and only if not at the end of the list.
  */
  virtual bool next() = 0;

  /** Description:
    Returns the number of subentities selected inside the current entity.
    (analogous to acedSSSubentLength)

    Remarks:
    Returns true if and only if not at the end of the list.
  */
  virtual OdUInt32 subentCount() = 0;

  /** Description:
    Returns the given subentity path inside the current entity.
    (analogous to acedSSSubentName)
    Arguments:
    i (I) index of the subentity.
    path (O) Path to the subentity.

    Remarks:
    Returns true if and only if "i" is valid index in the subentities array.
  */
  virtual bool getSubentity(OdUInt32 i, OdDbBaseFullSubentPath& path) = 0;

  /** Description:
      Returns the GiDrawable ID at the current position specified by
      this Iterator object.
  */
  virtual OdDbStub* id() const = 0;

  virtual OdDbSelectionMethodPtr method() const = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdSelectionSetIterator object pointers.
*/
typedef OdSmartPtr<OdSelectionSetIterator>  OdSelectionSetIteratorPtr;

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdSelectionSet object pointers.
*/
typedef OdSmartPtr<class OdSelectionSet>  OdSelectionSetPtr;

/** Description:
    This class represents Selection Sets in an Teigha application.

    Remarks:
    Only entities from an OdDbDatabase object's ModelSpace or PaperSpace may be
    added to a Selection Set.

    {group:OdDb_Classes}
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdSelectionSet : public OdRxObject
{
protected:
  OdSelectionSet();
public:
  ~OdSelectionSet();
  ODRX_DECLARE_MEMBERS(OdSelectionSet);

  virtual const OdRxObject* baseDatabase() const = 0;

  /** Description:
    Returns an Iterator object that provides access to the entities in this Selection Set.
  */
  virtual OdSelectionSetIteratorPtr newIterator() const = 0;

  // operations on the selection set 

  /** Description:
    Returns the number of entities in this group.
  */
  virtual OdUInt32 numEntities() const = 0;

  /** Description:
    Appends the specified entity to this SelectionSet object.  

    Arguments:
    entityId (I) Object ID of the OdDbEntity. 
    method(I) Selection method to associate with object
  */
  virtual void append(OdDbStub* entityId, OdDbSelectionMethod* pMethod = 0) = 0;

  /** Description:
    Appends the specified subentity to this SelectionSet object.  

    Arguments:
    subent (I) Subentity path to append. 
  */
  virtual void append(const OdDbBaseFullSubentPath& subent, OdDbSelectionMethod* pMethod = 0) = 0;

  /** Description:
    Appends the specified entity to this SelectionSet object.  

    Arguments:
    pSSet (I) Other selection set to copy entities from. 
  */
  virtual void append(const OdSelectionSet* pSSet) = 0;

  /** Description:
    Removes the specified entity from this SelectionSet object.  

    Arguments:
    entityId (I) Object ID of the OdDbEntity. 
  */
  virtual void remove(OdDbStub* entityId) = 0;

  /** Description:
    Removes the specified subentity from this SelectionSet object.  

    Arguments:
    subent (I) Subentity path  to remove. 
  */
  virtual void remove(const OdDbBaseFullSubentPath& subent) = 0;

  /** Description:
    Removes the specified entity from this SelectionSet object.  

    Arguments:
    pSSet (I) Object ID of the OdDbEntity. 
  */
  virtual void remove(const OdSelectionSet* pSSet) = 0;

  /** Description:
    Returns true if and only if the specified entity is a member
    of this SelectionSet object.
    Arguments:
    entityId (I) Object ID of the OdDbEntity. 
  */
  virtual bool isMember(OdDbStub* entityId) const = 0;

  /** Description:
    Returns true if and only if the specified subentity is a member
    of this SelectionSet object.
    Arguments:
    entityId (I) Subentity path. 
  */
  virtual bool isMember(const OdDbBaseFullSubentPath& subent) const = 0;

  virtual OdDbSelectionMethodPtr method(OdDbStub* entityId) const = 0;

  /** Description:
    Removes all members of this SelectionSet object.
  */
  virtual void clear() = 0;
};

#endif //_SSET_H_
