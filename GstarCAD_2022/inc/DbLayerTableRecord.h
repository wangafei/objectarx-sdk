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




#ifndef _ODDBLAYERTABLETABLERECORD_INCLUDED
#define _ODDBLAYERTABLETABLERECORD_INCLUDED

#include "TD_PackPush.h"

#include "DbSymbolTableRecord.h"
#include "CmColor.h"

class OdDbLayerTable;

/** Description:
    This class represents Layer records in the OdDbLayerTable in an OdDbDatabase instance.

    Library:
    TD_Db
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbLayerTableRecord : public OdDbSymbolTableRecord
{
public:
  ODDB_DECLARE_MEMBERS(OdDbLayerTableRecord);

  OdDbLayerTableRecord();
  virtual ~OdDbLayerTableRecord();

  typedef OdDbLayerTable TableType;

  /** Description:
    Returns true if and only if this Layer is *frozen* (DXF 70, bit 0x01).
  */
  bool isFrozen() const;

  /** Description:
    Sets the *frozen* status of this Layer (DXF 70, bit 0x01).

    Arguments:
    frozen (I) True to freeze, false to thaw.

    Gcad(Modify): 返回值 void -> OdResult
  */
  OdResult setIsFrozen(
    bool frozen);

  /** Description:
    Returns true if and only if this Layer is off (DXF 62).
    
    Remarks:
    DXF 62 is negative if and only if this Layer is *off*.
  */
  bool isOff() const;

  /** Description:
    Sets the on / *off* status of this Layer (DXF 62)

    Arguments:    
    off (I) True for off, false for on.

    Remarks:
    DXF 62 is negative if and only if this Layer is *off*.
  */
  void setIsOff(
    bool off);

  /** Description:
    Returns true if and only if this Layer is *frozen* in new viewports (DXF 70, bit 0x02).
  */
  bool VPDFLT() const;

  /** Description:
    Sets the *frozen* in new viewports status of this Layer (DXF 70, bit 0x02).

    Arguments:
    frozen (I) True for *frozen*, false for thawed.
  */
  void setVPDFLT(
    bool frozen);

  /** Description:
      Returns true if and only if this Layer is locked (DXF 70, bit 0x04.  
  */
  bool isLocked() const;

  /** Description:
    Sets the *locked* status of this Layer (DXF 70, bit 0x04).

    Arguments:
    locked (I) True to lock, false to unlock.
  */
  void setIsLocked(
    bool locked);

  /** Description:
    Returns the *color* of this Layer (DXF 62).
  */
  OdCmColor color() const;

  /** Description:
    Sets the *color* of this Layer (DXF 62).

    Arguments:
    color (I) Layer *color*.
  */
  void setColor(
    const OdCmColor &color);
  
  /** Description:
    Returns the *color* index for this Layer (DXF 62).
  */
  OdInt16 colorIndex() const;

  /** Description:
    Sets the *color* index this Layer (DXF 62).

    Arguments:
    colorIndex (I) Color index.
  */
  void setColorIndex(
    OdInt16 colorIndex);

  /** Gcad(Add): 新增兼容非虚函数
    新增兼容的颜色处理函数
  */
  OdCmEntityColor entityColor(void) const;

  /** Gcad(TODO): 
  OdCmTransparency transparency(void) const;
  OdResult setTransparency(
    const OdCmTransparency& trans);
  */

  /** Description:
    Returns the Object ID of the linetype associated with this Layer (DXF 6).
    
    Remarks:
    Returns NULL if there is no linetype associated with this Layer.
  */
  OdDbObjectId linetypeObjectId() const;

  /** Description:
    Sets the Object ID for the linetype associated with this Layer (DXF 6).

    Arguments:
    linetypeId (I) Object ID of the linetype.
  */
  void setLinetypeObjectId(
    OdDbObjectId linetypeId);

  /** Description:
    Returns the Object ID of the material associated with this Layer (DXF 347).
  */
  OdDbObjectId materialId() const;

  /** Description:
    Sets the Object ID for the material associated with this Layer (DXF 347).

    Arguments:
    matId (I) Object ID of the material.
  */
  OdResult setMaterialId(
    OdDbObjectId matId);

  /** Description:
    Returns true if and only if this Layer is plottable.
  */
  bool isPlottable() const;

  enum { kDxfLayerPlotBit = OdResBuf::kDxfBool };

  /** Description:
    Sets the plottable status of this Layer (DXF 290).

    Arguments:
    plot (I) True for plottable, false for not plottable.

    Remarks:
    Some layers can't be set to plottable; e.g., the "Defpoints" Layer.

    Gcad(Modify): 返回值 void -> OdResult
  */
  OdResult setIsPlottable(bool plot);

  /** Description:
    Returns the lineweight associated with this Layer (DXF 370).
  */
  OdDb::LineWeight lineWeight() const;

  /** Description:
    Sets the lineweight associated with this Layer (DXF 370).

    Arguments:
    lineWeight (I) Lineweight.

    Gcad(Modify): 返回值 void -> OdResult
  */
  OdResult setLineWeight(
    OdDb::LineWeight lineWeight);

  /** Description:
    Retuns the name of the plot style associated with this Layer (DXF 390).

    Gcad(Internal): 冲突, 需要调整DD库
  */
  OdString plotStyleName(ODSYSDEF) const;

  /** Gcad(Add): 新增兼容非虚函数
    注意: 1. 用户需要手动删除内存
          2. 本函数不要被 DD 库内部调用, 不然内存泄漏 Gcad(char*)
  */
#ifdef ODARXDEF
  OdChar*  plotStyleName() const;
#endif
  /** Description:
    Returns the Object ID of the plot style associated with this Layer (DXF 390).
  */
  OdDbObjectId plotStyleNameId() const;

  /** Description:
    Sets the name of the plot style associated with this Layer (DXF 390).

    Arguments:
    plotstyleName (I) Plot style *name*.
    plotstyleID (I) Plot style ID.
    
    Remarks:
    plotstyleID is the Object ID of an OdDbPlaceHolder object owned by the plot style name dictionary. 
    The plot style name dictionary key for this object is the plot style name.
    
    Returns eOk if successful, or an appropriate error code if not.  
  */
  OdResult setPlotStyleName(
    const OdChar * plotstyleName);

  /**  Gcad(Modify): 返回值 void -> OdResult
  */
  OdResult setPlotStyleName(
    OdDbObjectId plotstyleId);
  
  /** in & out
  */
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

  virtual OdResult subErase(
    OdBool erasing);

  virtual OdUInt32 subSetAttributes(OdGiDrawableTraits* pTraits);

  virtual OdBool subWorldDraw(OdGiWorldDraw* pWd);

  virtual void subViewportDraw(OdGiViewportDraw* pVd);

  OdGiDrawable* drawable();

  void setGsNode(OdGsNode* pNode);
  OdGsNode* gsNode() const;

  /** Description:
    Returns true if and only if this Layer is in use.
    
    Remarks:
    Usage is determined by a call to OdDbLayerTable::generateUsageData().

    Note:
    Returns true if OdDbLayerTable::generateUsageData() has not been called
    or this Layer table record is not *database* resident.
  */
  bool isInUse() const;


  /** Description:
    Returns the *description* of this Layer.
  */
  OdString description(ODSYSDEF) const;//Gcad(Internal)
#ifdef ODARXDEF
  OdChar*  description() const;//Gcad(Add)
#endif
  /** Description:
    Returns the *description* of this Layer.

    Arguments:
    description (I) Description.
    
    Remarks:
    The *description* may be up to 255 characters length.
  */
  OdResult setDescription(const OdChar * description);//Gcad(Modify)

  /** Description:
    Returns the *transparency* setting of this entity.
  */
  OdCmTransparency transparency() const;

  /** Description:
    Sets the *transparency* setting of this entity, and returns eOk if successful.

    Arguments:
    transparency (I) OdCmTransparency object be assigned.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult setTransparency(
    const OdCmTransparency& transparency);

  OdCmColor color(const OdDbObjectId& viewportId, bool* pIsOverride = 0) const;
  OdCmColor color(const OdDbObjectId& viewportId, bool& isOverride) const;//Gcad(Add)
  OdResult setColor(const OdCmColor& color, const OdDbObjectId& viewportId);//Gcad(Modify)

  OdDbObjectId linetypeObjectId(const OdDbObjectId& viewportId, bool* pIsOverride = 0) const;
  OdDbObjectId linetypeObjectId(const OdDbObjectId& viewportId, bool& isOverride) const;//Gcad(Add)
  OdResult setLinetypeObjectId(const OdDbObjectId& id, const OdDbObjectId& viewportId);//Gcad(Modify)

  OdDb::LineWeight  lineWeight(const OdDbObjectId& viewportId, bool* pIsOverride = 0) const;
  OdDb::LineWeight  lineWeight(const OdDbObjectId& viewportId, bool& isOverride) const;//Gcad(Add)
  OdResult setLineWeight(OdDb::LineWeight weight, const OdDbObjectId& viewportId);//Gcad(Modify)

  OdString plotStyleName(const OdDbObjectId& viewportId, bool* pIsOverride = 0) const;
  OdChar* plotStyleName(const OdDbObjectId& viewportId, bool& isOverride) const;//Gcad(Add)
  OdDbObjectId plotStyleNameId(const OdDbObjectId& viewportId, bool* pIsOverride = 0) const;
  OdDbObjectId plotStyleNameId(const OdDbObjectId& viewportId, bool& isOverride) const;//Gcad(Add)
  OdResult setPlotStyleName(const OdChar* newName, const OdDbObjectId& viewportId);//Gcad(Modify)
  OdResult setPlotStyleName(const OdDbObjectId& newId, const OdDbObjectId& viewportId);//Gcad(Modify)
  OdCmTransparency transparency(const OdDbObjectId& viewportId, bool* pIsOverride = 0) const;
  OdResult setTransparency(const OdCmTransparency &transparency, const OdDbObjectId& viewportId);

  OdResult removeColorOverride(const OdDbObjectId& viewportId);//Gcad(Modify)
  OdResult removeLinetypeOverride(const OdDbObjectId& viewportId);//Gcad(Modify)
  OdResult removeLineWeightOverride(const OdDbObjectId& viewportId);//Gcad(Modify)
  OdResult removePlotStyleOverride(const OdDbObjectId& viewportId);//Gcad(Modify)
  void removeTransparencyOverride(const OdDbObjectId& viewportId);
  OdResult removeViewportOverrides(const OdDbObjectId& viewportId);//Gcad(Modify)
  OdResult removeAllOverrides();//Gcad(Modify)

  bool hasOverrides(const OdDbObjectId& viewportId) const;
  bool hasAnyOverrides() const;
  
  bool isReconciled() const;
  OdResult setIsReconciled(bool bReconcile = true);//Gcad(Modify)
  static bool isReconciled(const OdDbObjectId& id);

  bool isHidden() const;
  void setIsHidden(bool bIsHidden);
  static bool isHidden(const OdDbObjectId& id);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbLayerTableRecord object pointers.
*/
typedef OdSmartPtr<OdDbLayerTableRecord> OdDbLayerTableRecordPtr;

#include "TD_PackPop.h"

#endif // _ODDBLAYERTABLETABLERECORD_INCLUDED

