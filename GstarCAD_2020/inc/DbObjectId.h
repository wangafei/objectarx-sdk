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




// (C) Copyright 2001 by Open Design Alliance. All rights reserved.

#ifndef _ODDBOBJECTID_INCLUDED_
#define _ODDBOBJECTID_INCLUDED_ /* {Secret } */

#include "OdDb.h"
#include "DbHandle.h"
#include "OdError.h"
#include "TD_PackPush.h"

class OdDbDatabase;
class OdDbObject;
template <class T> class OdSmartPtr;
class OdRxObjectPtr;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbObject object pointers.
*/
typedef OdSmartPtr<OdDbObject> OdDbObjectPtr;

class OdDbStub;
class OdDbStubExt;

/** Description: 
  
    {group:TD_Namespaces}
*/
namespace OdDb
{
  enum ReferenceType
  {
    kSoftPointerRef     = 0,  // Soft Pointer Reference
    kHardPointerRef     = 1,  // Hard Pointer Reference
    kSoftOwnershipRef   = 2,  // Soft Ownership Reference
    kHardOwnershipRef   = 3   // Hard Ownership Reference
  };
}

/** 
    Description:
    This class implements memory-resident ObjectId objects for OdDbDatabase objects.  

    Remarks:
    Database objects reference
    other *database* objects using ObjectId objects, and a *database* object pointer
    can always be obtained from a valid ObjectId objects. The effect of this mechanism is
    that *database* objects do not have to reside in memory unless they are explicitly
    being examined or modified by the user.  
    
    The user must explicitly open an object
    before reading or writing to it, and should release it when the operation
    is completed.  This functionality allows Teigha to support partial loading of 
    a *database*, where ObjectId objects exist for all objects in the *database*, but 
    the actual *database* objects need not be loaded until they are accessed.  
    It also allows *database* objects that are not in use to be swapped out of memory, 
    and loaded back in when they are accessed.  ObjectId objects are not written out to a 
    DWG/DXF file.  If a reference must be preserved to a *database* object that has been 
    serialized, the object's *database* handle (OdDbHandle) should be used.

    See Also:
    o  OdDbHandle
    o  OdDbObject

    Library: TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbObjectId
{
public:
  /**
    Remarks:
    This function guarantees that isNull() will 
    return true if it is the first operation applied to this instance.
  */
  OdDbObjectId () : m_Id (0) { }

  /** 
    Description:
    For Teigha internal use only. 
  */

  /* {Secret} */
  OdDbObjectId (
    const OdDbStub* objectId) : m_Id ((OdDbStub*)objectId) { }

  /** 
    Description:
    The null ObjectId object.
  */
  TOOLKIT_EXPORT_STATIC static const OdDbObjectId kNull;

  /** 
    Description:
    Returns true and only if this ObjectId object is null.
  */
  inline bool isNull () const {return m_Id == 0;}

  /** 
    Description:
    Sets this Object ID to null.
  */
  void setNull () { m_Id = 0; }

  /** 
    Description:
    Returns true and only if this ObjectId object references a valid object.
  */
  bool isValid () const;

  // VS2015 requires to create copy constructor explicity
#if defined(_MSC_VER) && (_MSC_VER > 1800)
  OdDbObjectId(const OdDbObjectId& objectId) = default;  
#endif

  OdDbObjectId& operator = (
    const OdDbObjectId& objectId) { m_Id = objectId.m_Id; return *this; }

  /* { Secret } */
  OdDbObjectId& operator = (
    const OdDbStub* objectId) { m_Id = (OdDbStub*)objectId; return *this; }

  bool operator < (
    const OdDbObjectId& objectId) const;

  bool operator > (
    const OdDbObjectId& objectId) const;

  inline bool operator >= (
	  const OdDbObjectId& objectId) const{return (operator > (objectId)) || (operator == (objectId));}

  inline bool operator <= (
	  const OdDbObjectId& objectId) const{return (operator < (objectId)) || (operator == (objectId));}

  bool operator == (
    const OdDbObjectId& objectId) const;

  inline bool operator != (
	  const OdDbObjectId& objectId) const {return !(operator == (objectId));}

  inline bool  operator <  (const OdDbStub* pID) const{return operator < (OdDbObjectId(pID));}
  inline bool  operator >  (const OdDbStub* pID) const{return operator > (OdDbObjectId(pID));}
  inline bool  operator >= (const OdDbStub* pID) const{return operator >= (OdDbObjectId(pID));}
  inline bool  operator <= (const OdDbStub* pID) const{return operator <= (OdDbObjectId(pID));}
  inline bool  operator == (const OdDbStub* pID) const{return operator == (OdDbObjectId(pID));}
  inline bool  operator != (const OdDbStub* pID) const{return operator != (OdDbObjectId(pID));}

  inline bool operator ! () const{return isNull();}

  /** 
    Description:
    For Teigha internal use only.
  */
  
  /* {Secret} */
  inline OdDbStub* getStub() const { return (OdDbStub*)m_Id; }

  /** 
    Description:
    For Teigha internal use only.
  */
  
  /* {Secret} */
  inline operator OdDbStub* () const { return (OdDbStub*)m_Id; }

  /** 
    Description:
    For Teigha internal use only. 
  */
  
  /* {Secret} */
  inline OdDbStubExt* operator -> () const { return (OdDbStubExt*)m_Id; }

  /** 
    Description:
    Returns the *database* with which this ObjectId object is associated.
    
    Remarks:
    Returns NULL if this ObjectId object is not associated with any *database*.
  */
  OdDbDatabase* database () const;

  /** Description:
    Returns the original *database* with which this ObjectId object is associated.
    
    Remarks:
    If the object associated with this ObjectId object has been redirected to
    a host *database* from an Xref *database*, this function returns
    a pointer to the Xref *database*. 
    
    Otherwise, it returns a pointer to the *database* with which this ObjectId object is associated.
  */
  OdDbDatabase* originalDatabase () const;

  /** Description:
    If this ObjectId object has been redirected from another *database* (possibly an Xref), this function
    returns the actual ObjectId object for that *database*.
  */
  void convertToRedirectedId ();

  /** Description:
    Returns true if and only if the object associated with this ObjectId object is erased.
  */
  bool isErased () const;

  /** 
    Description:
    Returns true if and only if this object associated with this ObjectId object is erased, or any of its ownership hierarchy
    have been erased.
  */
  bool isEffectivelyErased () const;

  /** 
    Description:
    For Teigha internal use only. 
  */
  
  /* {Secret} */
  bool objectLeftOnDisk () const;

  /** Description:
    Returns the *database* handle of the object referenced by this ObjectId object.
    
    Remarks:
    Returns NULL if no *database* object is referenced by this ObjectId object.

    If this ObjectId object has been redirected from another *database* (possibly an Xref), this function
    returns the handle for this *database*.
  */
  const OdDbHandle& getHandle () const;

  /** Description:
    Returns the *database* handle of the object referenced by this ObjectId object.
    
    Remarks:
    Returns NULL if no *database* object is referenced by this ObjectgId object.

    If this ObjectId object has been redirected from another *database* (possibly an Xref), this function
    returns the handle for the original *database*.
  */
  const OdDbHandle& getNonForwardedHandle () const;

  /** Description:
    Opens the *database* object associated with this ObjectId object, in the specified mode.

    Arguments:
    pObj (O) Smart pointer to opened object
    openMode (I) Mode in which to open the object.
    openErasedOne (I) If and only if true, *erased* objects will be opened.

    Remarks:
    Returns eOk if successful, otherwise an Error Code.
    
    openMode must be one of the following:
    
    @table
    Name                Value     Description
    OdDb::kForRead      0         Object is open for reading.
    OdDb::kForWrite     1         Object is open for reading and/or writing.
    OdDb::kForNotify    2         Object is open for notify.
    
  */
  OdResult openObject (
    OdDbObjectPtr& pObj,
    OdDb::OpenMode openMode = OdDb::kForRead, 
    bool openErasedOne = false,
    bool bCheckMode = false) const;
  /** Description:
    Opens the *database* object associated with this ObjectId object, in the specified mode.

    Arguments:
    openMode (I) Mode in which to open the object.
    openErasedOne (I) If and only if true, *erased* objects will be opened.

    Remarks:
    Returns a SmartPointer to the opened object if successful, otherwise a null SmartPointer.
    
    openMode must be one of the following:
    
    @table
    Name                Value     Description
    OdDb::kForRead      0         Object is open for reading.
    OdDb::kForWrite     1         Object is open for reading and/or writing.
    OdDb::kForNotify    2         Object is open for notify.
    
  */
  OdDbObjectPtr openObject (
    OdDb::OpenMode openMode = OdDb::kForRead, 
    bool openErasedOne = false) const;
  /** Description:
    Opens the *database* object associated with this ObjectId object, in the specified mode, or throws and exception if unsucessful.

    Arguments:
    openMode (I) Mode in which to open the object.
    openErasedOne (I) If and only if true, *erased* objects will be opened.

    Remarks:
    Returns a SmartPointer to the opened object.
    
    openMode must be one of the following:
    
    @table
    Name                Value     Description
    OdDb::kForRead      0         Object is open for reading.
    OdDb::kForWrite     1         Object is open for reading and/or writing.
    OdDb::kForNotify    2         Object is open for notify.

    Throws:
    
    @table
    Exception           Cause
    eNullObjectId       This ObjectId object is null.
    ePermanentlyErased  Not opened and openErasedOne == 1
    eWasErased          Not opened and openErasedOne == 0
    
  */  
  OdDbObjectPtr safeOpenObject (
    OdDb::OpenMode openMode = OdDb::kForRead, 
    bool openErasedOne = false) const;

  /** Description:
    Binds the specified object.
    
    Arguments:
    pObj (I) Pointer to the object to bind.
  */
  void bindObject (
    OdDbObject* pObj);

  OdRxObjectPtr &getRxObject() const;

  // Gcad(Add) {{
  
  /** Description:
    An alias of getHandle
  */
  OdDbHandle handle() const;

  /** Description:
    An alias of getNonForwardedHandle
  */
  OdDbHandle nonForwardedHandle() const;

  /** Description:
    Returns true if the object associated with this objectId is resident in memory.
  */
  bool isResident() const;

  /** Description:
    Sets from old id.
  */
  OdDbObjectId& setFromOldId(OdLongPtr oldId);
  
  /** Description:
    Returns old id.
  */
  OdLongPtr asOldId() const;

#if defined(_WIN64) || defined(_AC64)
  private:
    OdDbObjectId&  setFromOldId(long);

  public:
    inline OdDbObjectId&  setFromOldId(OdUIntPtr nUnsignedId)
    {
      const OdLongPtr nSignedId = static_cast<OdLongPtr>(nUnsignedId);
      return this->setFromOldId(nSignedId);
    }
#endif
  /** Description:
    Returns the class of the object that is associated with the object id, 
    or OdRxObject::desc() if there is no associated object, or if the object id is NULL.
  */
  
  // Gcad(Add) }}

  //{{ºØ≥…ÃÌº”
  OdRxClass*    objectClass() const;

  //}}
  
  void setFlags(OdUInt32 flags, OdUInt32 mask);
  OdUInt32 getFlags(OdUInt32 mask) const;

protected:
  friend class OdDbStub;
  OdDbStub* m_Id;
};

/** Description:
    This class is a specialization of OdDbObjectId indicating a hard owner relationship.

    Remarks:
    An OdDbHardOwnershipId reference to another object is used when the owner requires the owned
    object, and the owned object cannot exist on its own.
    
    An OdDbHardOwnershipId reference to an object dictates that the owned object is written to 
    .dwg and .dxf files whenever the owner object is written.
    
    Library: TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbHardOwnershipId : public OdDbObjectId
{
public:

  OdDbHardOwnershipId () {}

  OdDbHardOwnershipId (
    const OdDbObjectId& objectId) : OdDbObjectId (objectId) {}

  /* {Secret} */
  OdDbHardOwnershipId (
    const OdDbStub* objectId) : OdDbObjectId (objectId) {}

  OdDbHardOwnershipId& operator = (
    const OdDbHardOwnershipId& objectId) { OdDbObjectId::operator= (objectId); return *this; }

  OdDbHardOwnershipId& operator = (
    const OdDbObjectId& objectId) { OdDbObjectId::operator= (objectId); return *this; }

  /** { Secret } */
  OdDbHardOwnershipId& operator = (
    const OdDbStub* objectId) { m_Id = (OdDbStub*)objectId; return *this; }

  bool operator != (
    const OdDbObjectId& objectId) const { return OdDbObjectId::operator!= (objectId); }

  /** { Secret } */
  bool operator != (
    const OdDbStub* objectId) const { return OdDbObjectId::operator!= (objectId); }

  bool operator == (
    const OdDbObjectId& objectId) const { return OdDbObjectId::operator== (objectId); }

  /** { Secret } */
  bool operator == (
    const OdDbStub* objectId) const { return OdDbObjectId::operator== (objectId); }

  operator OdDbStub* () const { return OdDbObjectId::operator OdDbStub *(); }
};

/** Description:
    This class is a specialization of OdDbObjectId indicating a soft owner relationship.

    Remarks:
    An OdDbSoftOwnershipId reference to another object is used when the owner does not requires the owned
    object, and the owned object cannot exist on its own.

    An OdDbSoftOwnershipId reference to an object dictates that the owned object is written to 
    .dwg and .dxf files whenever the owner object is written.
    
    Library: TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbSoftOwnershipId : public OdDbObjectId
{
public:

  OdDbSoftOwnershipId () {}

  OdDbSoftOwnershipId (
    const OdDbObjectId& objectId) : OdDbObjectId (objectId) {}

  /** { Secret } */
  OdDbSoftOwnershipId (
    const OdDbStub* objectId) : OdDbObjectId (objectId) {}

  OdDbSoftOwnershipId& operator = (
    const OdDbSoftOwnershipId& objectId) { OdDbObjectId::operator= (objectId); return *this; }

  OdDbSoftOwnershipId& operator = (
    const OdDbObjectId& objectId) { OdDbObjectId::operator= (objectId); return *this; }

  /** { Secret } */
  OdDbSoftOwnershipId& operator = (
    const OdDbStub* objectId) { m_Id = (OdDbStub*)objectId; return *this; }

  bool operator != (
    const OdDbObjectId& objectId) const { return OdDbObjectId::operator!= (objectId); }

  /** { Secret } */
  bool operator != (
    const OdDbStub* objectId) const { return OdDbObjectId::operator!= (objectId); }

  bool operator == (
    const OdDbObjectId& objectId) const { return OdDbObjectId::operator== (objectId); }

  /** { Secret } */
  bool operator == (
    const OdDbStub* objectId) const { return OdDbObjectId::operator== (objectId); }

  operator OdDbStub* () const { return OdDbObjectId::operator OdDbStub *(); }
};

/** Description:
    This class is a specialization of OdDbObjectId indicating a hard pointer relationship.

    Remarks:
    An OdDbHardPointerId reference to another object is used when one object depends on the existance of another, but
    both are owned by other objects.

    Library: TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbHardPointerId : public OdDbObjectId
{
public:

  OdDbHardPointerId () {}

  OdDbHardPointerId (
    const OdDbObjectId& objectId) : OdDbObjectId (objectId) {}

  /** { Secret } */
  OdDbHardPointerId (
    const OdDbStub* objectId) : OdDbObjectId (objectId) {}

  OdDbHardPointerId& operator = (
    const OdDbHardPointerId& objectId) { OdDbObjectId::operator= (objectId); return *this; }

  OdDbHardPointerId& operator = (
    const OdDbObjectId& objectId) { OdDbObjectId::operator= (objectId); return *this; }

  /** { Secret } */
  OdDbHardPointerId& operator = (
    const OdDbStub* objectId) { m_Id = (OdDbStub*)objectId; return *this; }

  bool operator != (
    const OdDbObjectId& objectId) const { return OdDbObjectId::operator!= (objectId); }

  /** { Secret } */
  bool operator != (
    const OdDbStub* objectId) const { return OdDbObjectId::operator!= (objectId); }

  bool operator == (
    const OdDbObjectId& objectId) const { return OdDbObjectId::operator== (objectId); }

  /** { Secret } */
  bool operator == (
    const OdDbStub* objectId) const { return OdDbObjectId::operator== (objectId); }

  operator OdDbStub* () const { return OdDbObjectId::operator OdDbStub *(); }
};

/** Description:
    This class is a specialization of OdDbObjectId indicating a soft pointer relationship.

    Remarks:
    An OdDbSoftPointerId reference another object is used when neither object depends on the existance of the other.

    Library: TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbSoftPointerId : public OdDbObjectId
{
public:
  OdDbSoftPointerId () {}

  OdDbSoftPointerId (
    const OdDbObjectId& objectId) : OdDbObjectId (objectId) {}

  /** { Secret } */
  OdDbSoftPointerId (
    const OdDbStub* objectId) : OdDbObjectId (objectId) {}

  OdDbSoftPointerId& operator = (
    const OdDbSoftPointerId& objectId) { OdDbObjectId::operator= (objectId); return *this; }

  OdDbSoftPointerId& operator = (
    const OdDbObjectId& objectId) { OdDbObjectId::operator= (objectId); return *this; }

  /** { Secret } */
  OdDbSoftPointerId& operator = (
    const OdDbStub* objectId) { m_Id = (OdDbStub*)objectId; return *this; }

  bool operator != (
    const OdDbObjectId& objectId) const { return OdDbObjectId::operator!= (objectId); }

  /** { Secret } */
  bool operator != (
    const OdDbStub* objectId) const { return OdDbObjectId::operator!= (objectId); }

  bool operator == (
    const OdDbObjectId& objectId) const { return OdDbObjectId::operator== (objectId); }
  /** { Secret } */
  bool operator == (
    const OdDbStub* objectId) const { return OdDbObjectId::operator== (objectId); }

  operator OdDbStub* () const { return OdDbObjectId::operator OdDbStub *(); }
};

#include "DbIdOpen.h"
#include "TD_PackPop.h"

#endif //_ODDBOBJECTID_INCLUDED_


