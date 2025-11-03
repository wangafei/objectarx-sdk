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




#ifndef OD_DBLAYOUT_H
#define OD_DBLAYOUT_H

#include "TD_PackPush.h"

#include "DbPlotSettings.h"

class IGcReadStream;
class OdString;

/** Description:
    This class represents Layout objects in an OdDbDatabase instance.
    
    Library:
    TD_Db
   
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbLayout : public OdDbPlotSettings
{
public:
  ODDB_DECLARE_MEMBERS(OdDbLayout);

  /** Description:
      Constructor (no arguments).
  */
  OdDbLayout();
  virtual ~OdDbLayout();
  ///////// BEGIN ODA SPECIFIC /////////////

  /** Description:
    Returns the minimum limits for this Layout object (DXF 10).
  */
  const OdGePoint2d& getLIMMIN() const;

  /** Description:
    Sets the minimum limits for this Layout object (DXF 10).
    
    Arguments:
    limMin (I) Minimum limits.
  */
  void setLIMMIN(
    const OdGePoint2d& limMin);

  /** Description:
    Returns the maximum limits for this Layout object (DXF 11).
  */
  const OdGePoint2d& getLIMMAX() const;

  /** Description:
    Sets the maximum limits for this Layout object (DXF 11).

    Arguments:
    limMax (I) Maximum limits.
  */
  void setLIMMAX(
    const OdGePoint2d& limMax);

  /** Description:
    Returns the minimum extents for this Layout object (DXF 14).
  */
  const OdGePoint3d& getEXTMIN() const;

  /** Description:
    Sets the minimum extents for this Layout object (DXF 14).
    
    Arguments:
    extMin (I) Minimum extents.
  */
  void setEXTMIN(
    const OdGePoint3d& extMin);

  /** Description:
    Returns the maximum extents for this Layout object (DXF 15).
  */
  const OdGePoint3d& getEXTMAX() const;

  /** Description:
    Sets the maximum extents for this Layout object (DXF 15).
    
    Arguments:
    extMax (I) Maximum extents.
  */
  void setEXTMAX(
    const OdGePoint3d& extMax);

  /** Gcad(Add): 增加兼容函数接口
    封装模式, 非虚函数, 参数一致
  */
  void getLimits (
    OdGePoint2d& limMin, 
    OdGePoint2d& limMax) const;

  void getExtents (
    OdGePoint3d& extMin, 
    OdGePoint3d& extMax) const;

  /** Description:
    Returns the insertion base for this Layout object (DXF 12).
  */
  const OdGePoint3d& getINSBASE() const;

  /** Description:
    Sets the insertion base for this Layout object (DXF 12).

    Arguments:
    insBase (I) Insertion base.
  */
  void setINSBASE(
    const OdGePoint3d& insBase);

  /** Description:
    Returns the LIMCHECK variable for this Layout object (DXF 70, bit 0x02).
  */
  bool getLIMCHECK() const;

  /** Description:
    Sets the LIMCHECK variable for this Layout object (DXF 70, bit 0x02).
    
    Arguments:
    limCheck (I) LIMCHECK variable.  
  */
  void setLIMCHECK(
    bool limCheck);

  /** Description:
    Returns the PSLTSCALE variable for this Layout object (DXF 70, bit 0x01).
  */
  bool getPSLTSCALE() const;

  /** Description:
    Sets the PSLTSCALE variable for this Layout object (DXF 70, bit 0x01).
      
    Arguments:
    psLtScale (I) PSLTSCALE variable.
  */
  void setPSLTSCALE(
    bool psLtScale);

  ///////// END ODA SPECIFIC /////////////

  IGcReadStream* getStyleSheetReadStream();

  /** Description:
    Returns the Object ID of the PaperSpace OdDbBlockTableRecord associated with this Layout object (DXF 330).
  */
  OdDbObjectId getBlockTableRecordId() const;

  /** Description:
    Associates this Layout object with the specified PaperSpace OdDbBlockTableRecord (DXF 330).
    
    Arguments:
    blockTableRecordId (I) Block table record Object Id.

    Gcad(Modify): returns:void->OdResult parameter:OdDbObjectId
  */
  virtual OdResult setBlockTableRecordId(
    OdDbObjectId blockTableRecordId);

  /** Description:
    Adds this Layout object to the layout dictionary in the specified *database*, and associates 
    this Layout object with the specified PaperSpace OdDbBlockTableRecord. 

    Arguments:
    pDb (I) Pointer to the *database*
    blockTableRecordId (I) Block table record Object Id.

    Gcad(Modify): returns:void->OdResult
  */
  virtual OdResult addToLayoutDict(
    OdDbDatabase* pDb, 
    OdDbObjectId blockTableRecordId);
  
  /** Description:
    Returns the *name* of this Layout object (DXF 1).
  */
  OdString getLayoutName() const;

  /** Gcad(Add): 增加兼容函数接口
    封装模式, 非虚函数, 参数一致
  */
  OdResult getLayoutName(
    const OdChar*& name) const;
  OdResult getLayoutName(
    OdChar*& name) const;

  /** Description:
    Sets the *name* of this Layout object (DXF 1).
      
    Arguments:
    layoutName (I) Layout name.  

    Gcad(Internal): 修改函数接口为内部函数
  */
  void setLayoutName(
    ODSYSDEF,
    const OdString& layoutName);

  /** Gcad(Add): 增加兼容虚函数接口
  */
private:
  void setLayoutNameInternal(
    const OdString& layoutName);
public:
  virtual OdResult setLayoutName(
    const OdChar* layoutName);
  
  /** Description:
    Returns the tab order for this Layout object (DXF 71).
    
    Remarks:
    The tab order determines the order in which layout tabs are to be displayed.
  */
  int getTabOrder() const;

  /** Description:
    Sets the tab order for this Layout Ooject (DXF 71).
    
    Arguments:
    tabOrder (I) Tab order.

    Remarks:
    The tab order determines the order in which layout tabs are to be displayed.
    
    Tab order should be sequential for all Layout objects in the *database*.
  */
  virtual void setTabOrder(
    int tabOrder);
  
  /** Description:
    Returns true if and only if this layout tab is selected.
  */
  bool getTabSelected() const;

  /** Description:
    Controls the selected status for this Layout object.
    
    Arguments:
    tabSelected (I) Controls selected status. 
    
    Remarks:
    Selected Layout objects are included in selection sets for operations effecting multiple layouts.
  */
  virtual void setTabSelected(
    OdBool tabSelected);

  
  /** Description:
    Returns an array of OdDbObjectIds of all the OdDbViewports that exist in the Paper Space layout.
    The first ID in the list will be the overall Paper Space viewport.
    If the list returned is empty, then this layout is Model Space or has never been switched to (activated).
  */
  OdDbObjectIdArray getViewportArray() const;


  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  // Gcad(Modify): returns:void->OdResult
  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual void appendToOwner (
    OdDbIdPair& idPair, 
    OdDbObject* pOwnerObject, 
    OdDbIdMapping& ownerIdMap);

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  // Gcad(Modify): returns:void->OdResult
  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  /** Description:
    Returns the Object ID of the viewport that was last active
    in this Layout object (DXF 331).
  */
  OdDbObjectId activeViewportId() const;

  OdDbObjectId previousViewportId() const;

  /** Description:
    Makes the specified viewport the active viewport of this Layout object (DXF 331).

    Arguments:  
    viewportId (I) Object ID of the active viewport.      
  */
  OdResult setActiveViewportId(
    OdDbObjectId viewportId);

  /** Description:
      Returns the Object ID of the overall viewport of this Layout object.
  */
  OdDbObjectId overallVportId() const;

  OdUInt32 subSetAttributes(
    OdGiDrawableTraits* pTraits);

  OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

  void subViewportDraw(
    OdGiViewportDraw* vPd);

  OdResult subGetGeomExtents(OdDbExtents& extents) const;

  OdResult subClose();

  bool annoAllVisible() const;

  OdResult setAnnoAllVisible(bool newVal);

  OdResult initialize(OdDbObjectId* paperVportId = NULL);
  
/** Gcad(Comment): 不实现
#ifdef _WINDOWS_
  OdResult getThumbnail (BITMAPINFO*& thumbnail) const;
  OdResult setThumbnail(const BITMAPINFO * thumbnail);
#endif
*/
};

// !!! SYMBOL RENAMED !!! USE activeViewportId()

#define lastActiveVportId() activeViewportId()

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbLayout object pointers.
*/
typedef OdSmartPtr<OdDbLayout> OdDbLayoutPtr;

#include "TD_PackPop.h"

#endif

