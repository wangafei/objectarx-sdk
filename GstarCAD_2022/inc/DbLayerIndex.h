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




#ifndef OD_DBLYINDX_H
#define OD_DBLYINDX_H

#include "TD_PackPush.h"

#include "DbIndex.h"
#include "DbBlockIterator.h"
#include "DbIdBuffer.h"

class OdDbLayerTable;

/** Description:
    This class implements Layer Index objects in an OdDbDatabase instance.

    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbLayerIndex: public OdDbIndex
{
public:
  ODDB_DECLARE_MEMBERS(OdDbLayerIndex);

  OdDbLayerIndex();
  virtual ~OdDbLayerIndex();

  /** Gcad(Modify): 修改为兼容函数接口
  */
  virtual OdDbFilteredBlockIterator* newIterator(
    const OdDbFilter* pFilter) const;
 
  // Gcad(Modify): returns:void->OdResult
  virtual OdResult rebuildFull(
    OdDbIndexUpdateData* pIdxData);

  OdResult compute(OdDbLayerTable* pLT,
    OdDbBlockTableRecord* pBTR);

  
  // Gcad(TODO): compute 暂不实现
  //OdResult compute(OdDbLayerTable* pLT, OdDbBlockTableRecord* pBTR);
  
  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);
  
  // Gcad(Modify): returns:void->OdResult
  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  // Gcad(Modify): returns:void->OdResult
  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

protected:
  // Gcad(Modify): returns:void->OdResult
  virtual OdResult rebuildModified(
    OdDbBlockChangeIterator* iterator);
};


/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbLayerIndex object pointers.
*/
typedef OdSmartPtr<OdDbLayerIndex> OdDbLayerIndexPtr;

class OdDbLayerIndexIterator : public OdRxObjectImpl<OdDbFilteredBlockIterator>
{
  OdDbLayerIndexIterator& operator = (const OdDbLayerIndexIterator&);
  OdDbBlockIteratorPtr m_pSource;

public:
  OdDbLayerIndexIterator(const OdDbLayerIndex* pIndex, const OdDbLayerFilter* pFilter);
  static OdDbFilteredBlockIteratorPtr createObject(const OdDbLayerIndex* pIndex, const OdDbLayerFilter* pFilter);
  void setSourceIterator(const OdDbBlockIterator* pSourceIter);

  // GreatStar(Modify): returns:void->OdResult
  OdResult start();
  OdDbObjectId next();
  OdDbObjectId id() const;

  // GreatStar(Modify): returns:bool->OdResult
  OdResult seek(OdDbObjectId id);

  double estimatedHitFraction() const;
  OdResult accepts(OdDbObjectId, OdBool& idPassesFilter) const;

private:
  OdDbLayerIndexPtr                           m_pLayerIndex;
  // mutable  needed below for AIX
  mutable OdArray<OdDbIdBufferIteratorPtr>            m_buffers;
  mutable OdArray<OdDbIdBufferIteratorPtr>::iterator  m_bufferIter;
};

#include "TD_PackPop.h"

#endif // OD_DBLYINDX_H

