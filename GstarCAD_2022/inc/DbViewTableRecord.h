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




#ifndef _ODDBVIEWTABLERECORD_INCLUDED
#define _ODDBVIEWTABLERECORD_INCLUDED

#include "TD_PackPush.h"

#include "DbAbstractViewTableRecord.h"
#include "DbViewTable.h"
#include "DbAnnotationScale.h"

/** Description:
    This class represents View records in the OdDbViewTable in an OdDbDatabase instance.

    Library:
    TD_Db
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbViewTableRecord : public OdDbAbstractViewTableRecord
{
public:
  ODDB_DECLARE_MEMBERS(OdDbViewTableRecord);

  OdDbViewTableRecord();
  virtual ~OdDbViewTableRecord();
  typedef OdDbViewTable TableType;
  
  OdResult setParametersFromViewport(OdDbObjectId objId);

  /** Description:
    Returns true if and only if this View is a Paper Space view (DXF 70, bit 0x01).
  */
  bool isPaperspaceView() const;
  
  /** Description:
    Controls if this View is a Paper Space view (DXF 70, bit 0x01).
    
    Arguments:
    pspaceView (I) True for Paper Space, false for Model space.
  */
  void setIsPaperspaceView(
    bool pspaceView);
  
  /** Description:
    Returns true if and only if there is a UCS associated with this View.
  */
  bool isUcsAssociatedToView() const;
  /** Description:
    Disassociates any UCS associated with this View.
  */
  OdResult disassociateUcsFromView();

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  // new in 2005
  
  /** Description:
    Returns the name of the category of this View.
  */
  OdString getCategoryName() const;
  OdResult getCategoryName(OdChar *& categoryName) const;
  /** Description:
    Sets the name of the category of this View.
    Arguments:
    categoryName (I) Category name.
  */
  OdResult setCategoryName(
    const OdChar * categoryName);

  /** Description:
    Returns the name of the *layer* state of this View.
  */
  OdString getLayerState() const;
  OdResult getLayerState(OdChar*& layerStateName) const;
  /** Description:
    Sets the name of the *layer* state of this View.
    Arguments:
    layerStateName (I) Layer State name.
  */
  OdResult setLayerState(
    const OdChar * layerStateName);

  /** Description:
    Returns the Object ID of the OdDbLayout of this View.
  */
  OdDbObjectId getLayout() const;
  OdResult getLayout (OdDbObjectId& layoutId) const;
  /** Description:
    Sets the Object ID of the Layout of this View.
    Arguments:
    layoutId (I) Layout ID.
  */
  OdResult setLayout(
    OdDbObjectId layoutId);

  /** Description:
    Returns true if and only if this View is associated with a Paper Space Viewport.
  */
  bool isViewAssociatedToViewport() const;
  
  /** Description:
    Controls if this View is associated with a Viewport.
    Arguments:
    viewAssociated (I) Controls association.
  */
  OdResult setViewAssociatedToViewport (
    bool viewAssociated);

  /** Description:
    Returns the thumbnail information for this view.
    
    Arguments:
    pThumbnail (O) Receives a pointer to the thumbnail.
    
    Remarks:
    Thumbnail information consists of a packed BITMAPINFO structure 
    immediately followed in memory by the thumbnail data.
  */
  void getThumbnail (
    OdBinaryData* pThumbnail) const;
  /** Description:
    Sets the thumbnail information for this view.
    
    Arguments:
    pThumbnail (I) Pointer to the thumbnail.

    Remarks:
    Thumbnail information consists of a packed BITMAPINFO structure 
    immediately followed in memory by the thumbnail data.
  */
  void setThumbnail(
    const OdBinaryData* pThumbnail);

  //  void setParametersFromViewport(OdDbObjectId objId);
  
  // new R21 methods
  
  bool isCameraPlottable () const;
  OdResult setIsCameraPlottable(bool plottable);//Gcad(Modify)

  OdDbObjectId camera() const;
  void setCamera(const OdDbObjectId &cameraId);

  virtual OdResult subClose();

  // Live Section

  OdDbObjectId liveSection() const;
  OdResult setLiveSection(const OdDbObjectId& liveSectionId);   

  OdResult setAnnotationScale(const OdDbAnnotationScale* pScaleObj);
  OdDbAnnotationScalePtr annotationScale(ODSYSDEF) const;
#ifdef ODARXDEF
  OdDbAnnotationScale* annotationScale() const;
#endif
  OdInt16 getViewMode() const;
#ifdef _WINDOWS_
  OdResult getThumbnail (BITMAPINFO*& thumbnail) const;
  OdResult setThumbnail(const BITMAPINFO * thumbnail);
#endif

  OdDbObjectId sunId() const;
  OdResult setSun(OdDbObjectId &retId, OdDbObject *pSun);
  OdResult setSun(OdDbObjectId &retId, OdDbObject *pSun, bool eraseOldSun);

};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbViewTableRecord object pointers.
*/
typedef OdSmartPtr<OdDbViewTableRecord> OdDbViewTableRecordPtr;

#include "TD_PackPop.h"

#endif // _ODDBVIEWTABLERECORD_INCLUDED

