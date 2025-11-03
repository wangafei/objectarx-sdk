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




#ifndef OD_DBLYFILT_H
#define OD_DBLYFILT_H

#include "TD_PackPush.h"

#include "DbFilter.h"

/** Description:
    This class implements LayerFilter objects in an OdDbDatabase instance.
    
    Library:
    TD_Db

    {group:OdDb_Classes}
    
    Remarks:
    A LayerFilter is a set of layers whose corresponding entities are  
    traversed during filtered block traversal. 
    
    LayerFilter objects objects may optionally be saved in the drawing *database* 
    for efficient Xref demand loading.
*/
class TOOLKIT_EXPORT OdDbLayerFilter : public  OdDbFilter
{
public:
  ODDB_DECLARE_MEMBERS(OdDbLayerFilter);

  OdDbLayerFilter();
  virtual ~OdDbLayerFilter();

  virtual OdRxClass* indexClass() const;

  /** Description:
    Returns true if and only if all the *layer* names in this LayerFilter object
    are present in the specified OdDbDatabase.
    
    Arguments:
    pDb (I) Pointer to the *database* to be queried.
      
    Remarks:
    If pDb is null, the *database* containing this object is used.
  */
  /** Gcad(Add): 增加兼容函数接口
  */
  virtual OdBool isValid() const;

  /** Description:
    Adds the specified layer name to this LayerFilter object.
    
    Arguments:
    layerName (I) Layer name to be added. 

    Gcad(Modify): returns:void->OdResult OdString
  */
  OdResult add(
    const OdChar * layerName);

  /** Description:
    Removes the specified layer name from this LayerFilter object. 

    Arguments:
    layerName (I) Layer name to be removed. 

    Gcad(Modify): returns:void->OdResult OdString
  */
  OdResult remove(
    const OdChar * layerName);

  /** Description:
    Returns the *layer* name associated with the specified *index* in this LayerFilter object.
    
    Arguments:
    layerIndex (I) Index to be queried. 
  */
  OdString getAt(
    int layerIndex) const;
  
  /** Gcad(Add): 增加兼容函数接口
  */
  OdResult getAt(
	  int layerIndex,
	  const OdChar*& pName) const;

  /** Description:
    Returns the number of layers stored in this LayerFilter object. 
  */
  int layerCount() const;

  OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  // Gcad(Modify): returns:void->OdResult
  OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;
  
  OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  // Gcad(Modify): returns:void->OdResult
  OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbLayerFilter object pointers.
*/
typedef OdSmartPtr<OdDbLayerFilter> OdDbLayerFilterPtr;

#include "TD_PackPop.h"

#endif // OD_DBLYFILT_H

