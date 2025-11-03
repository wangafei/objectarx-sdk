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



#ifndef _OD_LY_H
#define _OD_LY_H

#include "RxObject.h"
#include "OdArray.h"
#include "DbObjectId.h"
#include "IdArrays.h"

class OdLyBoolExpr;
class OdLyLayerFilter;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdLyLayerFilter object pointers.
*/
typedef OdSmartPtr<OdLyLayerFilter> OdLyLayerFilterPtr;
/** Description:
  This template class is a specialization of the OdArray class for OdLyLayerFilter object pointers.
*/
typedef OdArray<OdLyLayerFilterPtr> OdLyLayerFilterArray;

class OdDbLayerTableRecord;
class OdDbDxfFiler;
class OdLySystemInternals;

/** Description:
    This class implements LayerFilter objects. 

    Remarks:
    This class allows the client to specify, retrieve, and nest and unnest LayerFilters,
    and to determine if a layer is visible with for LayerFilter object.
    
    All Layer Filters implement this interface.
    Library:
    TD_Db
    {group:OdLy_Classes} 
*/
class TOOLKIT_EXPORT OdLyLayerFilter : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdLyLayerFilter);
  OdLyLayerFilter();
  virtual ~OdLyLayerFilter();
  
  /** Description:
    Returns the *name* of this LayerFilter object.
  */
  virtual const OdChar * name() const;
  
  /** Description:
    Sets the *name* of this LayerFilter object.
    Arguments:
    name (I) Name.
    
    Remarks:
    Returns true if and only if successful.

    Some LayerFilter objects do not allow renamimg; e.g., "All", "Xref".

  */
  virtual OdResult setName(
    const OdChar * name);
    
  /** Description:
    Returns true if and only if this LayerFilter object can be renamed.

    Remarks:
    Some LayerFilter objects do not allow renamimg; e.g., "All", "Xref".
  */
  virtual bool allowRename() const;

  /** Description:
    Returns the *parent* LayerFilter of this LayerFilter object.

    Remarks:
    All LayerFilter objects, except the top level, "ALL", have parents.
  */
  virtual OdLyLayerFilter* parent() const;
  
  /** Description:
    Returns the nested LayerFilters of this LayerFilter object.
  */
  virtual const OdArray<OdLyLayerFilter*>& getNestedFilters() const;

  /** Description:
    Adds the specified LayerFilter as a nested LayerFilter to this LayerFilter object.
    Arguments:
    pLayerFilter (I) Pointer to the LayerFilter to nest.
  */
  virtual OdResult addNested(
    OdLyLayerFilter* pLayerFilter);
    
  /** Description:
    Removes the specified LayerFilter as a nested LayerFilter of this LayerFilter object.
    Arguments:
    pLayerFilter (I) Pointer to the LayerFilter to remove.
  */
  virtual OdResult removeNested(
    OdLyLayerFilter* pLayerFilter);
  
  /** Description:
    Notification function called after a LayerFilter is loaded.
    
    Remarks:
    This is an opportunity for a LayerFilter to automatically generate its nested filters.
  */
  virtual OdResult generateNested();
  
  
  /** Description:
    Returns true if and only if this LayerFilter was dynamically generated.
    
    Remarks:
    True indicates that this LayerFilter should not be persisted.
  */
  virtual bool dynamicallyGenerated() const;
  
  /** Description:
    Returns true if and only if this LayerFilter allows nested LayerFilters.
  */
  virtual bool allowNested() const;
  
  /** Description:
    Returns true if and only if this LayerFilter can be deleted.
  */
  virtual bool allowDelete() const;
  
  /** Description:
    Returns true if and only if this LayerFilter is a proxy LayerFilter.
  */
  virtual bool isProxy() const;
  
  /** Description:
    Returns true if and only if this LayerFilter filters for the Object ID of a LayerTableRecord.
    
    Remarks:
    These filters are known as LayerGroups.
  */
  virtual bool isIdFilter() const;
  
  /** Description:
    Returns true if and only if the specified *layer* is visible with this LayerFilter object.
    Arguments:
    layer (I) Layer.
  */
  virtual bool filter(
    OdDbLayerTableRecord* layer) const;
  
  enum DialogResult {kOk = 0, kCancel=1, kUseDefault = 2};
  virtual  DialogResult showEditor();
  
  /** Description:
    Returns the *filter* expression for this LayerFilter object.
  */
  virtual const OdChar * filterExpression() const;
  
  /** Description:
    Sets the *filter* expression for this LayerFilter object.
    Arguments:
    filterExpression (I) Filter expression.
  */
  virtual OdResult setFilterExpression(
     const OdChar * filterExpression );
  
  virtual const OdLyBoolExpr* filterExpressionTree() const;
  
  /** Description:
    Returns true if and only if this LayerFilter object and the specified LayerFilter
    object allow the same layers.
    Arguments:
    pOther (I) Pointer to the other LayerFilter.
  */
  virtual bool compareTo(
    const OdLyLayerFilter* pOther) const;
  
  /** Description:
    Reads the DXF format data of this object from the specified *filter*.
    Arguments:
    pFiler (I) Pointer to the filer from which data are to be read.
  */
  virtual OdResult readFrom(
    OdDbDxfFiler* pFiler);
    
  /** Description:
    Writes the DXF format data of this object to the specified *filter*.
    Arguments:
    pFiler (I) Pointer to the filer to which data are to be written.
  */
  virtual OdResult writeTo(
    OdDbDxfFiler* pFiler) const;
  
private:
  void* m_pImpl;
  friend class OdLySystemInternals;
  
protected:
  OdLyLayerFilter( OdLySystemInternals* );
};


/** Description:
    This class implements LayerGroup objects. 

    Remarks:
    This class allows the client to specify, retrieve, and group and ungroup layers,
    and to determine if a layer is grouped within a LayerGroup object.

    Library:
    TD_Db
    {group:OdLy_Classes} 
*/
class TOOLKIT_EXPORT OdLyLayerGroup : public OdLyLayerFilter
{
public:
  ODRX_DECLARE_MEMBERS(OdLyLayerGroup);
  OdLyLayerGroup();
  
  /** Description:
    Adds the specified layer to this LayerGroup object.
    Arguments:
    layerId (I) Object ID of the OdDbLayerTableRecord.
  */
  virtual OdResult addLayerId(
    const OdDbObjectId& layerId);
    
  /** Description:
    Removes the specified layer to this LayerGroup object.
    Arguments:
    layerId (I) Object ID of the OdDbLayerTableRecord.
  */
  virtual OdResult removeLayerId (
    const OdDbObjectId& layerId);
  
  /** Description:
    Returns the LayerTableRecord Object IDs in this LayerGroup object.
  */
  virtual const OdDbObjectIdArray& layerIds() const;
  
protected:
  OdLyLayerGroup( OdLySystemInternals* );
};


/** Description:
    This class simplifies accessing LayerFilter objects in the LayerTable extension dictionary.
    Library:
    TD_Db
    {group:OdLy_Classes} 
*/
class OdLyLayerFilterManager : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdLyLayerFilterManager);
  /** Description:
    Returns the root and current filters from the *database* containing this LayerFilterManager object.
    Arguments:
    pRoot (O) Receives a SmartPointer to the root *filter*.
    pCurrent (O) Receives a SmartPointer to the filter current when setFilters() was last called.  
  */
  virtual OdResult getFilters(
    OdLyLayerFilterPtr& pRoot, 
    OdLyLayerFilterPtr& pCurrent ) = 0;

  virtual OdResult getFilters(
    OdLyLayerFilter*& pRoot, 
    OdLyLayerFilter*& pCurrent ) = 0;
  
  /** Description:
    Writes the filter tree and current filters to the *database* containing this LayerFilterManager object.
    Arguments:
    pRoot (I) Pointer to the root *filter*.
    pCurrent (I) Pointer to the current filter to be persisted.  
  */
  virtual OdResult setFilters(
    const OdLyLayerFilterPtr pRoot, 
    const OdLyLayerFilterPtr pCurrent ) = 0;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdLyLayerFilterManager object pointers.
*/
typedef OdSmartPtr<OdLyLayerFilterManager> OdLyLayerFilterManagerPtr;

/** Description:
  Returns a LayerFilterManager object for the specified *database*.
  Arguments:
  pDb (I) Pointer to the *database*.
*/
TOOLKIT_EXPORT OdLyLayerFilterManagerPtr odlyGetLayerFilterManager(
  OdDbDatabase* pDb );

#endif  // _OD_LY_H
