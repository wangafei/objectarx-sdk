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




#ifndef OD_DBSPINDX_H
#define OD_DBSPINDX_H

#include "TD_PackPush.h"

#include "DbIndex.h"
#include "DbBlockIterator.h"

/** Description:
    This class implements Spatial Index objects in an OdDbDatabase instance.

    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbSpatialIndex : public OdDbIndex
{
public:
  ODDB_DECLARE_MEMBERS(OdDbSpatialIndex);

  OdDbSpatialIndex();
  virtual ~OdDbSpatialIndex();

  virtual OdDbFilteredBlockIterator* newIterator(
    const OdDbFilter* pFilter) const;
  
  OdResult rebuildFull(
    OdDbIndexUpdateData* pIdxData);
  
  OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

protected:

  OdResult rebuildModified(
    OdDbBlockChangeIterator* iterator);
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbSpatialIndex object pointers.
*/
typedef OdSmartPtr<OdDbSpatialIndex> OdDbSpatialIndexPtr;

class OdDbSpatialIndexIteratorImpl;
class OdDbSpatialFilter;


class OdDbSpatialIndexIterator;

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbSpatialIndexIterator object pointers.
*/
typedef OdSmartPtr<OdDbSpatialIndexIterator> OdDbSpatialIndexIteratorPtr;

/** Description:
    This class implements Iterator objects that traverse queries defined by OdDbSpatialFilter objects.
    Library:
    TD_Db
    
    Remarks:
    This class is used by OcDbSpatialIndex.
     
    {group:OdDb_Classes}
*/
class OdDbSpatialIndexIterator : public OdDbFilteredBlockIterator
{
protected:
  OdDbSpatialIndexIterator();
public:
  ODRX_DECLARE_MEMBERS(OdDbSpatialIndexIterator);

  OdDbSpatialIndexIterator(const OdDbSpatialIndex*  pIndex,
    const OdDbSpatialFilter* pFilter);

  virtual ~OdDbSpatialIndexIterator();

  virtual OdResult start();
  virtual OdDbObjectId next();
  virtual OdDbObjectId id() const;
  virtual OdResult seek(OdDbObjectId id);

  virtual double estimatedHitFraction() const;
  virtual OdResult accepts(OdDbObjectId id,
    OdBool& stat) const;

  static OdDbSpatialIndexIteratorPtr newIterator(
    const OdDbSpatialIndex* pIndex, 
    const OdDbSpatialFilter* pFilter);
};


#include "TD_PackPop.h"

#endif // OD_DBSPINDX_H
