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



#ifndef _OD_DB_ARCDIMENSION_DIMENSION_
#define _OD_DB_ARCDIMENSION_DIMENSION_

#include "TD_PackPush.h"

#include "DbDimension.h"


/** Description:
    This class represents Arc Dimension entities in an OdDbDatabase instance.
    
    Remarks:
    An Arc Dimension entity dimensions the length of an arc.
    
    Library:
    TD_Db

    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbArcDimension : public OdDbDimension
{
public:
  ODDB_DECLARE_MEMBERS(OdDbArcDimension);

  OdDbArcDimension();
  /*/Gcad(Add)
  /*/
  OdDbArcDimension(
        const OdGePoint3d& centerPoint,
        const OdGePoint3d& xLine1Point,
        const OdGePoint3d& xLine2Point,
        const OdGePoint3d& arcPoint,
        const OdString&      dimText = OdString::kEmpty,
        OdDbObjectId dimStyle = OdDbObjectId::kNull);
    // Default destructor
    ~OdDbArcDimension();
  //*/
  /** Description:
    Returns the WCS point defining the location of dimension arc for this Dimension entity.
  */
  OdGePoint3d         arcPoint() const;

  /** Description:
    Sets the WCS point defining the location of dimension arc for this Dimension entity.
    Arguments:
    arcPoint (I) Arc point.

	Gcad(Modify):void->OdResult
  */
  OdResult setArcPoint(const OdGePoint3d& arcPoint);

  /** Description:
    Returns the WCS start point of the first extension line of this Dimension entity.
      
    Remarks:
    This point and the centerPoint define one side of the Arc being dimensioned.
  */
  OdGePoint3d xLine1Point() const;

  /** Description:
    Sets the WCS start point of the first extension line of this Dimension entity.
  
    Arguments:
    xLine1Point (I) Start point.
        
    Remarks:
    This point and the centerPoint define one side of the arc being dimensioned.

	Gcad(Modify):void->OdResult
  */
  OdResult   setXLine1Point(const OdGePoint3d & xLine1Pt);

  /** Description:
    Query method which returns the start point for the arc length dimension's second extension line.
  */

  /** Description:
    Returns the WCS start point of the second extension line of this Dimension entity.
      
    Remarks:
    This point and the centerPoint define one side of the Arc being dimensioned.
  */
  OdGePoint3d xLine2Point() const;

  /** Description:
    Sets the WCS start point of the second extension line of this Dimension entity.
  
    Arguments:
    xLine2Point (I) Start point.
        
    Remarks:
    This point and the centerPoint define one side of the arc being dimensioned.

	Gcad(Modify):void->OdResult
  */
  OdResult setXLine2Point(const OdGePoint3d& xLine2Pt);

  /** Description:
    Returns the WCS vertex of the arc being dimensioned by this Dimension entity.
    Remarks:
    The vertex of the arc being dimensioned is the center of the dimension arc.
  */
  OdGePoint3d centerPoint() const;

  /** Description:
    Sets the WCS vertex of the arc being dimensioned by this Dimension entity.
    Arguments:
    centerPoint (I) Center point.
    Remarks:
    The vertex of the angle being dimensioned is the center of the dimension arc.

	Gcad(Modify):void->OdResult
 */
  OdResult setCenterPoint(const OdGePoint3d& centerPoint);

  /** Description:
    Returns true if and only if this Dimension entity was specified using two points along the arc.
  */
  bool isPartial() const;
  /** Description:
    Controls the specification of this Dimension entity with two points along the arc.
    Arguments:
    partial (I) Specifies partial dimension.

	Gcad(Modify):void->OdResult
  */
  OdResult setIsPartial(const bool partial);

  /** Description:
    Returns the arc parameter of this Dimension entitiy's first definition point.
  */
  double arcStartParam() const;

  /** Description:
    Sets the arc parameter of this Dimension entity's first definition point.
    Arguments:
    arcStartParam (I) Arc start parameter.

	Gcad(Modify):void->OdResult,const double->const double&
  */
  OdResult setArcStartParam(const double& arcStartParam);


  /** Description:
    Returns the arc parameter of this Dimension entity's second definition point.
  */
  double arcEndParam() const;

  /** Description:
    Sets the arc parameter of this Dimension entity's second definition point.
    Arguments:
    arcEndParam (I) Arc end parameter.

	Gcad(Modify):void->OdResult,double->const double&
  */
  OdResult setArcEndParam(const double& arcEndParam);


  /** Description:
    Returns true if and only if this Dimension entity has a leader drawn to resolve ambiguity.
  */
  bool hasLeader() const;
  /** Description:
    Determines if this Dimension entity has a leader drawn to resolve ambiguity.
    Arguments:
    hasLeader (I) Controls leader.

	Gcad(Modify):void->OdResult,const bool->const bool&
  */
  OdResult setHasLeader(const bool& hasLeader);

  /** Description:
    Returns the start point of the extra leader of this Dimension entity.
  */
  OdGePoint3d leader1Point() const;
  /** Description:
    Sets the start point of the extra leader of this Dimension entity.
    Arguments:
    leader1Point (I) Start point of leader.

	Gcad(Modify):void->OdResult
  */
  OdResult setLeader1Point(const OdGePoint3d& leader1Point);

  /** Description:
    Returns the end point of the extra leader of this Dimension entity.
  */
  OdGePoint3d leader2Point() const;
  /** Description:
    Sets the end point of the extra leader of this Dimension entity.
    Arguments:
    leader2Point (I) End point of leader.

	Gcad(Modify):void->OdResult
  */
  OdResult   setLeader2Point(const OdGePoint3d& leader2Point);

  /** Description:
    Returns the type of arc symbol used within the dimension text of this Dimension entity.
    
    Remarks:
    arcSymbolType() returns one of the following:
    
    @table
    Value   Description
    0       Arc symbol precedes text.
    1       Arc symbol is above text.
    2       No arc symbol.

	Gcad(Modify):OdInt16->int
  */
  int arcSymbolType() const;

  /** Description:
    Set method which sets the type of symbol to use within the arc length dimension's text string.
    0 - Arc symbol precedes text, 1 - Arc symbol is above text, 2 - No arc symbol is used.
    This overrides the setting of this value in the dimension's style.
  */
  /** Description:
    Sets the type of arc symbol used within the dimension text of this Dimension entity.
    
    Remarks:
    arcSymbolType must be one of the following:
    
    @table
    Value   Description
    0       Arc symbol precedes text.
    1       Arc symbol is above text.
    2       No arc symbol.
    
    Remarks:
    Overrides the value in the dimension style.
	Gcad(Modify):void->OdResult,OdInt16->int
  */
  OdResult setArcSymbolType(const int arcSymbolType);

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  /*
  OdDbArcDimension(
  const OdGePoint3d& centerPoint,
  const OdGePoint3d& xLine1Point,
  const OdGePoint3d& xLine2Point,
  const OdGePoint3d& arcPoint,
  const OdString* dimText = NULL,
  OdDbObjectId dimStyle = OdDbObjectId::kNull );
  */
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbArcDimension object pointers.
*/
typedef OdSmartPtr<OdDbArcDimension> OdDbArcDimensionPtr;

#include "TD_PackPop.h"

#endif
