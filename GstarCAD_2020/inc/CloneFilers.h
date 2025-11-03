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




#ifndef OD_CLONEFILERS_INCLUDED
#define OD_CLONEFILERS_INCLUDED

#include "DbFiler.h"
#include "IdArrays.h"

class OdDbIdMapping;

class OdDbDeepCloneFiler;
class OdDbDeepCloneFilerImpl;
class OdDbIdRefQueue;
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbDeepCloneFiler object pointers.
*/
typedef OdSmartPtr<OdDbDeepCloneFiler> OdDbDeepCloneFilerPtr;

/** Description:
    This class is the base class for classes that are used for DeepClone file I/O operations utilizing .dwg 
    and .dxf file formats.
    Library: TD_Db
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbDeepCloneFiler : public OdRxObjectImpl<OdDbDwgFiler>
{
public:
  OdDbDeepCloneFiler();
  OdDbDeepCloneFiler(OdDbIdMapping* pIdMap);
  virtual ~OdDbDeepCloneFiler();

public:
  ODRX_DECLARE_MEMBERS(OdDbDeepCloneFiler);
  virtual OdResult filerStatus() const;
  OdDb::FilerType filerType() const;

  virtual void setFilerStatus(OdResult);

  virtual void resetFilerStatus();

  virtual OdDbDatabase* database() const;

  virtual OdResult readHardOwnershipId(OdDbHardOwnershipId*);
  virtual OdResult writeHardOwnershipId(const OdDbHardOwnershipId&);

  virtual OdResult readSoftOwnershipId(OdDbSoftOwnershipId*);
  virtual OdResult writeSoftOwnershipId(const OdDbSoftOwnershipId&);

  virtual OdResult readHardPointerId(OdDbHardPointerId*);
  virtual OdResult writeHardPointerId(const OdDbHardPointerId&);

  virtual OdResult readSoftPointerId(OdDbSoftPointerId*);
  virtual OdResult writeSoftPointerId(const OdDbSoftPointerId&);

  virtual OdResult readInt8(OdInt8 *);
  virtual OdResult writeInt8(OdInt8);

  // This flavor of readString may go away in a future release.
  virtual OdResult readString(OdChar **);
  virtual OdResult writeString(const OdChar *);

  virtual OdResult readString(OdString &);
  virtual OdResult writeString(const OdString &);

  virtual OdResult readBChunk(tdx_binary*);
  virtual OdResult writeBChunk(const tdx_binary&);

  virtual OdResult readOdDbHandle(OdDbHandle*);
  virtual OdResult writeOdDbHandle(const OdDbHandle&);

  virtual OdResult readInt64(OdInt64*);
  virtual OdResult writeInt64(OdInt64);

  virtual OdResult readInt32(OdInt32*);
  virtual OdResult writeInt32(OdInt32);

  virtual OdResult readInt16(OdInt16*);
  virtual OdResult writeInt16(OdInt16);

  virtual OdResult readUInt64(OdUInt64*);
  virtual OdResult writeUInt64(OdUInt64);

  virtual OdResult readUInt32(OdUInt32*);
  virtual OdResult writeUInt32(OdUInt32);

  virtual OdResult readUInt16(OdUInt16*);
  virtual OdResult writeUInt16(OdUInt16);

  virtual OdResult readUInt8(OdUInt8*);
  virtual OdResult writeUInt8(OdUInt8);

  virtual OdResult readBoolean(OdBool*);
  virtual OdResult writeBoolean(OdBool);

  virtual OdResult readBool(bool*);
  virtual OdResult writeBool(bool);

  virtual OdResult readDouble(double*);
  virtual OdResult writeDouble(double);

  virtual OdResult readPoint2d(OdGePoint2d*);
  virtual OdResult writePoint2d(const OdGePoint2d&);

  virtual OdResult readPoint3d(OdGePoint3d*);
  virtual OdResult writePoint3d(const OdGePoint3d&);

  virtual OdResult readVector2d(OdGeVector2d*);
  virtual OdResult writeVector2d(const OdGeVector2d&);

  virtual OdResult readVector3d(OdGeVector3d*);
  virtual OdResult writeVector3d(const OdGeVector3d&);

  virtual OdResult readScale3d(OdGeScale3d*);
  virtual OdResult writeScale3d(const OdGeScale3d&);

  virtual OdResult readBytes(void*, OdUIntPtr);
  virtual OdResult writeBytes(const void*, OdUIntPtr);

  virtual OdResult readAddress(void **);
  virtual OdResult writeAddress(const void *);

  virtual OdResult readInt(int*);
  virtual OdResult writeInt(int);

  virtual OdResult seek(OdInt64 offset, int seekType);
  virtual OdInt64 tell() const;

  virtual OdResult addReference(OdDbObjectId id, OdDb::ReferenceType rt);
  virtual OdResult addReferences(OdDbIdRefQueue&);

  virtual bool     usesReferences() const;

  virtual bool     getNextOwnedObject(OdDbObjectId& id);
  virtual bool     moreOwnedObjects() const;

  /** Description:
    Creates a DeepCloneFiler object with the specified ID Mapping.
    Arguments:
    pIdMapping (I) Pointer to the ID Mapping. 
  */
  static OdDbDeepCloneFilerPtr createObject(OdDbIdMapping* pIdMapping);

  // Protocol specific to clone filers

  /** Description:
    Sets this DeepCloneFiler object to reference the Object ID that it would normally reference first.

    Remarks:
    Allows multiple traversals of the ID Mapping.
  */  
  virtual void start();
  /** Description:
    Sets this DeepCloneFiler object to reference the Object ID following the current Object ID referenced.
    
    Arguments:
    objectId (O) Receives the next referenced Object ID.
  */  
  virtual bool nextReference(OdDbObjectId& objectId);

  /** Description:
    Returns the ID Mapping for this DeepCloneFiler object.
  */
  virtual OdDbIdMapping& idMapping();

  /** Description:
    Processes the objects in the ID Mapping of this DeepCloneFiler object.
  */
  virtual void defaultProcessReferences();

protected:
  OdDbDeepCloneFiler(OdDbDeepCloneFilerImpl* pImpFiler);
  OdDbDeepCloneFilerImpl*      m_pImpFiler;

  friend class OdDbInnerAccessDeepCloneFiler;
};

class OdDbWblockCloneFiler;
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbWblockCloneFiler object pointers.
*/
typedef OdSmartPtr<OdDbWblockCloneFiler> OdDbWblockCloneFilerPtr;

/** Description:
    This class is the base class for classes that are used for Wblock file I/O operations utilizing .dwg
    and .dxf file formats.
    Library Db
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbWblockCloneFiler : public OdDbDeepCloneFiler
{
protected:

public:
  ODRX_DECLARE_MEMBERS(OdDbWblockCloneFiler);

  OdDbWblockCloneFiler();
  OdDbWblockCloneFiler(OdDbIdMapping* pIdMap);
  ~OdDbWblockCloneFiler();

  OdDb::FilerType filerType() const;
  virtual OdResult addReferences(OdDbIdRefQueue&);
  virtual bool    usesReferences() const;
  virtual bool    getNextHardObject(OdDbObjectId& id);
  virtual bool    moreHardObjects() const;

  /** Description:
    Creates a WblockCloneFiler object with the specified ID Mapping.
    Arguments:
    pIdMapping (I) Pointer to the ID Mapping. 
  */
  static OdDbWblockCloneFilerPtr createObject(OdDbIdMapping* pIdMapping);
};

#endif //OD_CLONEFILERS_INCLUDED
