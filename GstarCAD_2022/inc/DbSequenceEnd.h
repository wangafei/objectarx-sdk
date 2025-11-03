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




#ifndef _OD_DB_SEQUENCE_END_
#define _OD_DB_SEQUENCE_END_

#include "TD_PackPush.h"

#include "DbEntity.h"

/** Description:
    This class represents SequenceEnd (Seqend) entities in an OdDbDatabase instance.  
    
    Remarks:
    OdDbSequenceEnd entities are automatically created and handled by Teigha for
    complex objects such as OdDb2dPolyline and OdDbBlockReference.
     
    Client applications may add extended data or extension dictionaries to these 
    entities, but should not create or delete them.

    These entities have no associated geometries.
 
    Note:
    Do not derive from this class.

    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbSequenceEnd: public OdDbEntity
{
public:
  ODDB_DECLARE_MEMBERS(OdDbSequenceEnd);

  OdDbSequenceEnd();
  ~OdDbSequenceEnd();
  
  // for lisp && bag filer - outputs (-2,owner)
  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;
  // for vertices post-processing, when called from lisp
  OdResult dxfIn(
    OdDbDxfFiler* pFiler);
  /**
    Note:
    Always returns eInvalidExtents.
  */
  virtual OdResult subGetGeomExtents(OdDbExtents& extents) const;
  /**
  Note:
  Always returns eInvalidExtents.
  */
  virtual OdResult subErase(OdBool erasing);

  virtual OdResult subGetTransformedCopy(const OdGeMatrix3d& mat, OdDbEntityPtr& pCopy) const;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbSequenceEnd object pointers.
*/
typedef OdSmartPtr<OdDbSequenceEnd> OdDbSequenceEndPtr;

#include "TD_PackPop.h"

#endif
