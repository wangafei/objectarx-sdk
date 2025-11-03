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




#ifndef DBFCF_H
#define DBFCF_H

#include "TD_PackPush.h"

#include "DbEntity.h"
#include "DbDimStyleTableRecord.h"

/** Description:
    This class represents feature control frames in an OdDbDatabase instance.

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbFcf : public OdDbEntity
{
public:
  ODDB_DECLARE_MEMBERS(OdDbFcf);

  OdDbFcf();
  /** 
  Gcad(Add):增加兼容接口	
  */
  OdDbFcf(const OdChar *, const OdGePoint3d&,
		const OdGeVector3d&, const OdGeVector3d&);
  /** 
  Gcad(Add):增加兼容接口	
  */
  virtual ~OdDbFcf();

  enum whichLine 
  {
    kAll = -1
  };
  
  /** Description:
    Sets the text string of this feature control frame (DXF 1).
    
    Arguments:
    fcfText (I) Text of this feature control frame.
    
    Remarks:
    The following escape sequences are used to specify the feature control frame:

    @table
    Sequence        Meaning
    \n	            newline 
    {\\Fgdt;a}	    angularity
    {\\Fgdt;b}	    perpendicularity
    {\\Fgdt;c}	    flatness
    {\\Fgdt;d}	    profile of a surface
    {\\Fgdt;e}	    circularity
    {\\Fgdt;f}	    parallelism
    {\\Fgdt;g}	    cylindricity
    {\\Fgdt;h}	    circular runout
    {\\Fgdt;i}	    symmetry
    {\\Fgdt;j}	    positional (+)
    {\\Fgdt;k}	    profile of a line
    {\\Fgdt;l}	    least material condition
    {\\Fgdt;m}	    maximum material condition
    {\\Fgdt;n}	    diameter
    {\\Fgdt;p}	    positional(P)
    {\\Fgdt;r}	    concentricity
    {\\Fgdt;s}	    regardless of feature size
    {\\Fgdt;t}	    total runout
    {\\Fgdt;u}	    straightness
    %%v	            vertical side of frame box
  */
  virtual void setText(
    const OdChar * fcfText);
  
  /** Description:
    Returns the text string of this feature control frame (DXF 1).

    Arguments:
    lineNo (I) Index of the line desired.

    Remarks:
    The following escape sequences are used to specify the feature control frame:
    
    @table
    Sequence        Meaning
    \n	            newline 
    {\\Fgdt;a}	    angularity
    {\\Fgdt;b}	    perpendicularity
    {\\Fgdt;c}	    flatness
    {\\Fgdt;d}	    profile of a surface
    {\\Fgdt;e}	    circularity
    {\\Fgdt;f}	    parallelism
    {\\Fgdt;g}	    cylindricity
    {\\Fgdt;h}	    circular runout
    {\\Fgdt;i}	    symmetry
    {\\Fgdt;j}	    positional (+)
    {\\Fgdt;k}	    profile of a line
    {\\Fgdt;l}	    least material condition
    {\\Fgdt;m}	    maximum material condition
    {\\Fgdt;n}	    diameter
    {\\Fgdt;p}	    positional (P)
    {\\Fgdt;r}	    concentricity
    {\\Fgdt;s}	    regardless of feature size
    {\\Fgdt;t}	    total runout
    {\\Fgdt;u}	    straightness
    %%v	            vertical side of frame box
      
    Note:
    lineNo is not currently implemented. All lines of text will be returned, separated by \n.

	// Gcad(Internal)
  */
  OdString text(
	ODSYSDEF,
    int lineNo = kAll) const;

  const OdString& textConst(
    int lineNo = kAll) const;

  /** Gcad(Add): 
  Warning: The caller of this function is responsible for deallocating the string 
           returned by this function (odutDelString() should be used).
  */
#ifdef ODARXDEF
  virtual OdChar* text(
    const int lineNo = kAll) const;
#endif
  /** Description:
    Sets the insertion point of this feature control frame (WCS equivalent of DXF 10).

    Arguments:
    insPoint (I) Insertion point.

    Remarks:
    The insertion point is the middle of the left edge of the feature control frame.
  */
  virtual void setLocation(
    const OdGePoint3d& insPoint);

  /** Description:
    Returns the insertion point of this feature control frame (WCS equivalent of DXF 10).
    
    Remarks:
    The insertion point is the middle of the left edge of the feature control frame.
  */
  virtual OdGePoint3d location() const;

  /** Description:
    Sets the orientation vectors of this feature control frame (DXF 210 and 11).
    Arguments:
    normal (I) WCS *normal* to plane of feature control frame.
    direction (I) WCS X-axis *direction* vector of feature control frame. 
  */
  virtual void setOrientation(
    const OdGeVector3d& normal, 
    const OdGeVector3d& direction);

  /** Description:
    Returns the WCS *normal* to the plane of this feature control frame (DXF 210).
  */
  virtual OdGeVector3d normal() const;

  /** Description:
    Returns the WCS X-axis *direction* vector of this feature control frame (DXF 11).
  */
  virtual OdGeVector3d direction() const;

  /** Description:
    Sets the dimension style (OdDbDimStyleTableRecord) to used by this feature control frame (DXF 3).
    
    Arguments:
    dimStyleId (I) Object ID of the dimension style.
  */
  virtual void setDimensionStyle(
    OdDbHardPointerId dimStyleId);

  /** Description:
    Returns the dimension style (OdDbDimStyleTableRecord) used by this feature control frame (DXF 3).
  */
  virtual OdDbHardPointerId dimensionStyle() const;

  /** Description: Returns the DIMCLRD value of this object.  
    Remarks: 
    DIMCLRD specifies the *color* of dimension lines, leader lines, frames, and arrowheads. 
    
    Remarks: 
    The value from the dimension style of this object will be returned unless 
    that value has been overridden, in which case, the override value will be returned. 
    
  */ 
  OdCmColor dimclrd() const;

  /** Description: Returns the DIMCLRT value of this object.  
    Remarks: 
    DIMCLRT specifies the *color* of dimension text. 
    
    Remarks: 
    The value from the dimension style of this object will be returned unless 
    that value has been overridden, in which case, the override value will be returned. 
  */
  OdCmColor dimclrt() const;

  /** Description: Returns the DIMGAP value of this object.  
    Remarks: 
    DIMGAP specifies the gap between dimension text and dimension lines.

    A negative value for DIMGAP draws a reference box round the dimension text.

    Text is placed inside a dimension line only if there will be two line segments
    each as long as abs(DIMGAP). 
    
    Remarks: 
    The value from the dimension style of this object will be returned unless 
    that value has been overridden, in which case, the override value will be returned. 
    
  */ 
  double dimgap() const;

  /** Description: Returns the DIMSCALE value of this object.  
    Remarks: 
    DIMSCALE is an scale factor applied to all dimension variables that
    regulate sizes, offsets, and distances.

    DIMSCALE serves as an overall "volume control" for dimensions
    and leaders.

    @table
    Value        Description
    0,0          A "reasonable" value is computed for model space viewports.
    > 0.0        If set to the inverse of the plot scale, plotted dimensions will be at the sizes specified by the other dimension variables. 
    
    Remarks: 
    The value from the dimension style of this object will be returned unless 
    that value has been overridden, in which case, the override value will be returned. 
    
  */ 
  double dimscale() const;

  /** Description: Returns the DIMTXSTY value of this object.  
    Remarks: 
    DIMTXSTY specifies the text style of the dimension text. 
    
    Remarks: 
    The value from the dimension style of this object will be returned unless 
    that value has been overridden, in which case, the override value will be returned. 
    
  */ 
  OdDbObjectId dimtxsty() const;

  /** Description: Returns the DIMTXT value of this object.  
    Remarks: 
    DIMTXT specifies the size of the dimension text. 
    
    Remarks: 
    The value from the dimension style of this object will be returned unless 
    that value has been overridden, in which case, the override value will be returned. 
    
  */ 
  double dimtxt() const;

  /** Description: Sets the DIMCLRD override for this object. 
    Arguments: val (I) New value for DIMCLRD.   
    Remarks: 
    DIMCLRD specifies the *color* of dimension lines, leader lines, frames, and arrowheads. 

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setDimclrd(
    const OdCmColor& val);

  /** Description: Sets the DIMCLRT override for this object. 
    Arguments: val (I) New value for DIMCLRT.   
    Remarks: 
    DIMCLRT specifies the *color* of dimension text. 

	Gcad(Modify):returns:void->OdResult
  */ 
  OdResult setDimclrt(
    const OdCmColor& val);

  /** Description: Sets the DIMGAP override for this object. 
    Arguments: val (I) New value for DIMGAP.   
    Remarks: 
    DIMGAP specifies the gap between dimension text and dimension lines.

    A negative value for DIMGAP draws a reference box round the dimension text.

    Text is placed inside a dimension line only if there will be two line segments
    each as long as abs(DIMGAP). 

	Gcad(Modify):returns:void->OdResult
  */ 
  OdResult setDimgap(
    double val);

  /** Description: Sets the DIMSCALE override for this object. 
    Arguments: val (I) New value for DIMSCALE.   
    Remarks: 
    DIMSCALE is an scale factor applied to all dimension variables that
    regulate sizes, offsets, and distances.

    DIMSCALE serves as an overall "volume control" for dimensions
    and leaders.

    @table
    Value        Description
    0.0          A "reasonable" value is computed for model space viewports.
    > 0.0        If set to the inverse of the plot scale, plotted dimensions will be at the sizes specified by the other dimension variables. 

	Gcad(Modify):returns:void->OdResult
  */ 
  OdResult setDimscale(
    double val);

  /** Description: Sets the DIMTXSTY override for this object. 
    Arguments: val (I) New value for DIMTXSTY.   
    Remarks: 
    DIMTXSTY specifies the text style of the dimension text. 

	Gcad(Modify):returns:void->OdResult
  */ 
  OdResult setDimtxsty(
    OdDbObjectId val);

  /** Description: Sets the DIMTXT override for this object. 
    Arguments: val (I) New value for DIMTXT.   
    Remarks: 
    DIMTXT specifies the size of the dimension text. 

	Gcad(Modify):returns:void->OdResult
  */ 
  OdResult setDimtxt(
    double val);

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  //Gcad(Modify):returns:void->OdResult
  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  //Gcad(Modify):returns:void->OdResult
  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  OdBool subWorldDraw(
    OdGiWorldDraw* pWd);
  
  void subViewportDraw(
    OdGiViewportDraw* pVd);

  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm) ODRX_OVERRIDE;

  /** Note:
     This function is an override for OdDbEntity::subSetDatabaseDefaults() to set 
     the dimension style of this entity to the current style for the specified *database*.
  */
  void subSetDatabaseDefaults(OdDbDatabase *pDb);

  /** Description:
    Returns the WCS bounding points of this feature control frame.
    
    Arguments:
    boundingPoints (O) Receives the bounding points.
    
    Remarks:
    The points are returned as follows:
    
    @table
    Point                Corner
    boundingPoints[0]    Top left
    boundingPoints[1]    Top right
    boundingPoints[2]    Bottom right
    boundingPoints[3]    Bottom left
  */
  virtual void getBoundingPoints(
    OdGePoint3dArray& boundingPoints) const ;

  //Gcad(Modify):returns:void->OdResult
  OdResult subClose();

  virtual void modified (
    const OdDbObject* pObject);

  /** Description:
    Copies the dimension style settings, including overrides, of this entity into the specified
    dimension style table record.
    
    Arguments:
    pRecord (O) Receives the effective dimension style data.
    
    Remarks:
    The *copied* data includes the dimension style data with all applicable overrides. 

	Gcad(Modify):returns:void->OdResult
  */
  OdResult getDimstyleData(
    OdDbDimStyleTableRecord *pRecord) const;

  /** Description:
    Copies the dimension style settings, including overrides, from the specified
    dimension style table record to this entity.
    
    Arguments:
    pDimstyle (I) Pointer to non- *database* -resident dimension style record.
    dimstyleID (I) Database-resident dimension style record.

    Remarks:
    The *copied* data includes the dimension style with all applicable overrides. 

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setDimstyleData(
    const OdDbDimStyleTableRecord* pDimstyle);
  OdResult setDimstyleData(
    OdDbObjectId dimstyleID);

  /** Description:
    Appends the consecutive distinct corner points of this feature control frame to the specified array.
    
    Arguments:
    ptArray (I/O) Receives corner points.
  */
  virtual void getBoundingPline(
    OdGePoint3dArray& 
    ptArray) const;
  /*
      virtual void getGripPoints(OdGePoint3dArray&, OdDbIntArray&, OdDbIntArray&) const;
      virtual void moveGripPointsAt(const OdDbIntArray&, const OdGeVector3d&);
  */

  //Gcad(Add) 
    //virtual OdResult getGripPoints   (OdGePoint3dArray&,OdDbIntArray&,OdDbIntArray&) const;
    //virtual OdResult moveGripPointsAt(const OdDbIntArray&,const OdGeVector3d&);
	virtual void     setDimVars();
 //   virtual void     list() const;
/*//arx2008
	virtual bool castShadows() const;
    virtual void setCastShadows(bool newVal);
    virtual bool receiveShadows() const;
    virtual void setReceiveShadows(bool newVal);
  */
  /////////////////////////////add//////////////////////
  
  /*/Gcad(Modify)
  virtual OdDbObjectPtr decomposeForSave(
    OdDb::DwgVersion ver, 
    OdDbObjectId& replaceId, 
    bool& exchangeXData);
 /*/
  virtual OdResult decomposeForSave(
	OdDb::DwgVersion ver,
	OdDbObject*& replaceObj,
	OdDbObjectId& replaceId,
	OdBool& exchangeXData);
  //*/

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType,
    OdGePoint3dArray& points, OdGsMarker thisGsMarker = 0,
    OdGsMarker otherGsMarker = 0) const;

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType,
    const OdGePlane& projPlane, OdGePoint3dArray& points,
    OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0) const;

};
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbFcf object pointers.
*/
typedef OdSmartPtr<OdDbFcf> OdDbFcfPtr;

#include "TD_PackPop.h"

#endif

