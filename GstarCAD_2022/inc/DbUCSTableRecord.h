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




#ifndef _ODDBUCSTABLERECORD_INCLUDED
#define _ODDBUCSTABLERECORD_INCLUDED

#include "TD_PackPush.h"

#include "DbSymbolTableRecord.h"
#include "ViewportDefs.h"
#include "DbUCSTable.h"

/** Description:
    This class represents UCS records in the OdDbUCSTable in an OdDbDatabase instance.

    Library:
    TD_Db
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbUCSTableRecord: public OdDbSymbolTableRecord
{
public:
  ODDB_DECLARE_MEMBERS(OdDbUCSTableRecord);

  OdDbUCSTableRecord();
  virtual ~OdDbUCSTableRecord();
  
  typedef OdDbUCSTable TableType;

  /** Description:
    Returns the WCS *origin* of this UCS (DXF 10).
  */
  OdGePoint3d origin() const;

  /** Description:
    Sets the WCS *origin* of this UCS (DXF 10).
    
    Arguments:
    origin (I) Origin.
  */
  void setOrigin(
    const OdGePoint3d& origin);

  /** Description:
    Returns the WCS X-axis of this UCS (DXF 11).
  */
  OdGeVector3d xAxis() const;

  /** Description:
    Sets the WCS X-axis of this UCS (DXF 11).
    
    Arguments:
    xAxis (I) X-axis.
  */
  void setXAxis(
    const OdGeVector3d& xAxis);

  /** Description:
    Returns the WCS Y-axis of this UCS (DXF 12).
  */
  OdGeVector3d yAxis() const;

  /** Description:
    Sets the WCS Y-axis of this UCS (DXF 12).
    
    Arguments:
    yAxis (I) Y-axis.
  */
  void setYAxis(
    const OdGeVector3d& yAxis);

  /** Description:
    Returns the WCS *origin* (DXF 13) of this UCS for the specified orthographic *view*, 
    when UCSBASE is set to this UCS.
    
    Arguments:
    view (I) Orthographic *view*.
  */
  OdGePoint3d ucsBaseOrigin(OdDb::OrthographicView view) const;

  /** Description:
    Sets the WCS *origin* (DXF 13) of this UCS for the specified orthographic *view* (DXF 71), 
    when UCSBASE is set to this UCS.

    Arguments:
    origin (I) Origin for this *view*.
    view (I) Orthographic *view*.
  */
  OdResult setUcsBaseOrigin(
    const OdGePoint3d& origin, 
    OdDb::OrthographicView view);

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

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
};
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbUCSTableRecord object pointers.
*/
typedef OdSmartPtr<OdDbUCSTableRecord> OdDbUCSTableRecordPtr;

#include "TD_PackPop.h"

#endif // _ODDBUCSTABLERECORD_INCLUDED

