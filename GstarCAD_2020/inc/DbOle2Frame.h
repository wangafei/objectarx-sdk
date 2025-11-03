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




#ifndef _OD_DB_OLE2FRAME_
#define _OD_DB_OLE2FRAME_

#include "TD_PackPush.h"

#include "DbOleFrame.h"
#include "Ge/GePoint3d.h"

class OdOleItemHandler;

class TOOLKIT_EXPORT OdRectangle3d
{
public:
  OdGePoint3d upLeft;
  OdGePoint3d upRight;
  OdGePoint3d lowLeft;
  OdGePoint3d lowRight;
};

/** Description:
    This class represents OLE2 entities in an OdDbDatabase instance.

    Library:
    TD_Db
    
    {group:OdDb_Classes}
*/
#define szRegOLE2FRAM_APP    OD_T("ACAD")

class COleClientItem;
class TOOLKIT_EXPORT OdDbOle2Frame : public OdDbOleFrame
{
public:
  ODDB_DECLARE_MEMBERS(OdDbOle2Frame);

  OdDbOle2Frame();
  
  virtual ~OdDbOle2Frame();
	
  OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  //Gcad(Modify):returns:void->OdResult
  OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  //Gcad(Modify):returns:void->OdResult
  OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  OdCmTransparency transparency() const;

  virtual OdResult setTransparency(const OdCmTransparency& trans,
    OdBool doSubents = true);

  OdDb::Visibility visibility() const;

  virtual OdResult setVisibility(OdDb::Visibility newVal,
    OdBool doSubents = true);

  virtual void saveAs(OdGiWorldDraw* mode, OdDb::SaveType st);

  COleClientItem* getOleClientItem(void) const;
  OdResult setOleClientItem(const COleClientItem* pItem);
  
  ODRX_SEALED_VIRTUAL OdBool subWorldDraw(
    OdGiWorldDraw* pWd) ODRX_OVERRIDE;

  ODRX_SEALED_VIRTUAL void subViewportDraw(
    OdGiViewportDraw* pVd) ODRX_OVERRIDE;

  ODRX_SEALED_VIRTUAL OdResult subTransformBy(
    const OdGeMatrix3d& xfm) ODRX_OVERRIDE;
  virtual void* getOleObject(void) const;
  virtual void setOleObject(const void *pItem);
  
  /** Description:
    Returns the upper-left corner of the OLE object (DXF 10).
    
    Arguments:
    point3d (O) Receives the upper-left corner.
  */
  void getLocation(OdGePoint3d& 
    point3d) const;

  void setLocation(const OdGePoint3d& point3d);

  /** Description:
    Returns the corner points of the OLE object (DXF 10 & 11).
    
    Arguments:
    rect3d (O) Receives the corner points.
  */
  void position(
    OdRectangle3d& rect3d) const;
  
  /** Description:
      Sets the corner points of the OLE object (DXF 10 & 11).
    
    Arguments:
    rect3d (I) Corner points.
  */
  void setPosition(
    const OdRectangle3d& rect3d);

  /** Description:*/
  virtual void position(RECT& rect) const;
  virtual void setPosition(const RECT& rect);
 
  const OdString& getUserType() const;
  
  virtual void getUserType(OdChar * pszName, int nNameSize) const;
  enum Type
  {
      kUnknown  = 0,
      kLink     = 1,
      kEmbedded = 2,
      kStatic   = 3
  };
  /** Description:
    Returns the type of this OLE object (DXF 71).  
    
    Remarks:
    getType() returns one of the following:
    
    @table
    Name         Value
    kUnknown     0
    kLink        1
    kEmbedded    2
    kStatic      3
  */
  Type getType() const;

  /** Description:
    Returns the filename and item to which this OLE object is linked.
    
    Example:
    D:\My Documents\My Workbook.xls!Sheet2!R1C1:R10C10

    See also:
    getLinkPath()
  */
  OdString getLinkName() const;
  
   virtual OdBool getLinkName(OdChar * pszName, int nNameSize) const;
  /** Description:
    Returns the filename to which this OLE object is linked.

    Example:
    D:\My Documents\My Workbook.xls
             
    See also:
    getLinkName()
  */
  OdString getLinkPath() const;
  
  virtual OdBool getLinkPath(OdChar * pszPath, int nPathSize) const;
  typedef enum PlotQuality
  {
      kMonochrome   = 0,  // e.g., spreadsheet
	  kOQMonochrome	= 0,
      kLowGraphics  = 1,  // e.g., color text & pie charts
	  kOQLowGraphics= 1,
      kHighGraphics = 2,   // e.g., photograph 
	  kOQHighGraphics=2,
	  kOQAutomatic=3
  }OleQuality;

  /** Description:
    Returns the *output* *quality* for this OLE object (DXF 73).
    
    Remarks:
    Controls the *color* depth and resolution when plotted.
    
    outputQuality() returns one of the following:

    @table
    Name               Value    Example
    kMonochrome        0        Spreadsheet
    kLowGraphics       1        Color text & pie charts
    kHighGraphics      2        Photograph 
  */
  PlotQuality outputQuality() const;

  OdBool autoOutputQuality() const;
  /** Description:
    Sets the *output* *quality* for this OLE object (DXF 73).
    
    Arguments:
    quality (I) Output *quality*.
      
    Remarks:
    Controls the *color* depth and resolution when plotted.

    quality must be one of the following:
    
    @table
    Name               Value    Example
    kMonochrome        0        Spreadsheet
    kLowGraphics       1        Color text & pie charts
    kHighGraphics      2        Photograph 
  */
  void setOutputQuality(
    PlotQuality  quality);
	void setAutoOutputQuality(OdUInt8);

  /** Description:
    Returns the compound document data size for this OLE object.
  */
  OdUInt32 getCompoundDocumentDataSize() const;

  /** Description:
    Writes the compound document data to the specified stream.
    
    Arguments:
    streamBuf (O) StreamBuf object to which the data are to be written.
  */
  void getCompoundDocument(
    OdStreamBuf& streamBuf) const;

  /** Description:
    Reads the compound document data from the specified stream.
    
    Arguments:
    nSize (I) Size of compound data.
    streamBuf (I) StreamBuf object from which the data are to be read.
  */
  void setCompoundDocument(
    OdUInt32 nSize, 
    OdStreamBuf& streamBuf);

  OdResult subGetClassID(CLSID* pClsid) const;
  
  /** Description:
    Returns the Item Handler for this OLE object.
  */
  const OdOleItemHandler* itemHandler() const;

  
  /** Description:
    Creates an Item Handler for this OLE object.
    
    Remarks:
    Returns the Item Handler.
  */
  OdOleItemHandler* getItemHandler();

  //Gcad(Modify):returns:void->OdResult
  OdResult subClose();

  /** Description:
    Returns unknown field.

    Remarks:
    Was not accessible in DD1.12 (OdDbOle2FrameImpl::m_UnknownFromDWG)

    Note:
    Currently Teigha does not *handle* this field.
    This method will be removed or renamed in future releases.
  */
  OdInt32 unhandled_unknown0() const;

  /** Description:
    Returns unknown field.

    Remarks:
    Still unknown. OdDbOle2Frame::getUnknown1() in DD1.12

    Note:
    Currently Teigha does not *handle* this field.
    This method will be removed or renamed in future releases.
  */
  OdUInt8 unhandled_unknown1() const;

  /** Description:
    Returns unknown field.

    Remarks:
    Still unknown. OdDbOle2Frame::getUnknown2() in DD1.12

    Note:
    Currently Teigha does not *handle* this field.
    This method will be removed or renamed in future releases.
  */
  OdUInt8 unhandled_unknown2() const;

  /** Description:
    Sets unknown fields.

    Note:
    Currently Teigha does not *handle* these fields.
    This method will be removed or renamed in future releases.
  */
  void unhandled_setUnknown(OdInt32 unk0 = 0, OdUInt8 unk1 = 0x80, OdUInt8 unk2 = 0x55);

  /** Description:

    Remarks:
    OdDbOle2Frame::getPixelWidth() in DD1.12

    Note:
    Currently Teigha does not *handle* this field.
    This method will be removed or renamed in future releases.
  */
  OdUInt16 unhandled_himetricWidth() const;

  /** Description:

    Remarks:
    OdDbOle2Frame::getPixelHeight() in DD1.12

    Note:
    Currently Teigha does not *handle* this field.
    This method will be removed or renamed in future releases.
  */
  OdUInt16 unhandled_himetricHeight() const;

  /** Description:
    Sets unhandled fields.

    Note:
    Currently Teigha does not *handle* these fields.
    This method will be removed or renamed in future releases.
  */
  void unhandled_setHimetricSize(OdUInt16 w, OdUInt16 h);

  // New properties

  /** Description:
    Resets current OLE XData.

    Arguments:
    bInitSize (I) Init actual OLE object size using current WCS size.
  */
  void reset(bool bInitSize = false);

  /** Description:
    Sets plot quality to automatically selectable by application.

    Arguments:
    bFlag (I) New value.
  */
  void setAutoOutputQuality(bool bFlag);

  /** Description:
    Returns rotation angle for this OLE object.
  */
  double rotation() const;

  /** Description:
    Sets rotation angle for this OLE object.

    Arguments:
    fAngle (I) New value.
  */
  OdResult setRotation(const double fAngle);

  /** Description:
    Returns actual width of this OLE object in WCS.
  */
  double wcsWidth() const;

  /** Description:
    Sets actual width of this OLE object in WCS.

    Arguments:
    fWidth (I) New OLE object WCS width.
  */
  OdResult setWcsWidth(const double fWidth);

  /** Description:
    Returns actual height of this OLE object in WCS.
  */
  double wcsHeight() const;

  /** Description:
    Sets actual height of this OLE object in WCS.

    Arguments:
    fHeight (I) New OLE object WCS height.
  */
  OdResult setWcsHeight(const double fHeight);

  /** Description:
    Returns percentage of the current OLE object width scale to original object width scale.
  */
  double scaleWidth() const;

  /** Description:
    Sets new OLE object width scale relative to original object width.

    Arguments:
    fScale (I) New width scale in percents.
  */
  OdResult setScaleWidth(const double fScale);

  /** Description:
    Returns percentage of the current OLE object height scale to original object height scale.
  */
  double scaleHeight() const;

  /** Description:
    Sets new OLE object height scale relative to original object height.

    Arguments:
    fScale (I) New height scale in percents.
  */
  OdResult setScaleHeight(const double fScale);

  /** Description:
    Returns lock aspect property.
  */
  OdBool lockAspect() const;

  /** Description:
    Sets lock aspect property.

    Arguments:
    bFlag (I) New value.
  */
  OdResult setLockAspect(const OdBool bLockAspect);

  virtual OdResult subGetTransformedCopy(const OdGeMatrix3d& mat, OdDbEntity*& pCopy) const;

  virtual OdResult subGetSubentPathsAtGsMarker(OdDb::SubentType type, OdGsMarker gsMark, 
    const OdGePoint3d& pickPoint,const OdGeMatrix3d& xfm, 
    int& numPaths, OdDbFullSubentPath*& subentPaths, 
    int numInserts = 0,
    OdDbObjectId* pEntAndInsertStack = 0) const;

  virtual OdResult subGetGsMarkersAtSubentPath(const OdDbFullSubentPath& subPath, 
    OdGsMarkerArray& gsMarkers) const;

  virtual OdDbEntity* subSubentPtr(const OdDbFullSubentPath& path) const;

  virtual OdResult subExplode(OdDbVoidPtrArray& entitySet) const;

  virtual OdBool subCloneMeForDragging();

  void updateLinkPath();
protected:
	OdResult ScaleItem(double dscale);
	double GetSourceWcsHeight()const;
	double GetSourceWcsWidth()const;
	bool GetOleXData(OdResBufPtr resbuf)const;
	bool SetOleXData(OdResBufPtr resbuf);
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbOld2Frame object pointers.
*/
typedef OdSmartPtr<OdDbOle2Frame> OdDbOle2FramePtr;

#include "TD_PackPop.h"

#endif
