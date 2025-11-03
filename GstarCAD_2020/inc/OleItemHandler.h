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

#ifndef _ODOLEITEMHANDLER_INCLUDED_
#define _ODOLEITEMHANDLER_INCLUDED_

#include "RxObject.h"
#include "DbSystemServices.h"
#include "OdErrorContext.h"
#include "Gi/GiViewportGeometry.h"
#include "RxModule.h"
#include "OdStreamBuf.h"
#include "DbRootExport.h"

#include "TD_PackPush.h"

class OdDbObjectId;

/** Description:
    This class is the base class for classes that provide platform-dependent I/O for OLE items for Teigha.

    {group:Other_Classes}
*/
class DBROOT_EXPORT OdOleItemInitStream : public OdStreamBuf
{
public:
  ODRX_DECLARE_MEMBERS(OdOleItemInitStream);

  /** Description:
    Returns the Object ID of the frame associated with this OdOleItemInitStream object.
  */
  virtual OdDbStub* frameId() const = 0;
};
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdOleItemInitStream object pointers.
*/
typedef OdSmartPtr<OdOleItemInitStream> OdOleItemInitStreamPtr;

class OdOleItemHandler;
class OdDbObjectId;
class OdDbObject;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdOleItemHandler object pointers.
*/
typedef OdSmartPtr<OdOleItemHandler> OdOleItemHandlerPtr;

/** Description:
    This class defines the interface for custom OLE handlers.

    {group:Other_Classes}
*/
class DBROOT_EXPORT OdOleItemHandler : public OdGiSelfGdiDrawable
{
public:
  ODRX_DECLARE_MEMBERS(OdOleItemHandler);

  /** Description:
    Reads the binary data for the OdDbOle2Frame of this OleItemHandler object from the specified stream.
    
    Arguments:
    streamBuf (I) StreamBuf object from which the data are to be read.

    Remarks:
    See MFC COleClientItem::Serialize(CArchive& ar) for details.
    Assume that ar.m_bForceFlat is TRUE.
  */
  virtual void load(OdStreamBuf& streamBuf) = 0;

  /** Description:
    Writes the binary data for the OdDbOle2Frame of this OleItemHandler object to the specified stream.
    
    Arguments:
    streamBuf (O) StreamBuf object to which the data are to be written.
    
    Remarks:
    See MFC COleClientItem::Serialize(CArchive& ar) for details.
    Assume that ar.m_bForceFlat is TRUE.
  */
  virtual void save(OdStreamBuf& streamBuf) const = 0;

  /** Description:
    Returns the data size (in bytes) of the compound document of this OleItemHandler object.
  */
  virtual OdUInt32 getCompoundDocumentDataSize() const = 0;

  /** Description:
    Writes the compound document data of this OleItemHandler object to the specified stream.
    Arguments:
    streamBuf (O) StreamBuf object to which the data are to be written.
  */
  virtual void getCompoundDocument(OdStreamBuf& streamBuf) const = 0;

  /** Description:
    Reads the compound document data of this OleItemHandler object from the specified stream.
    Arguments:
    streamBuf (I) StreamBuf object from which the data are to be read.
    numBytes (I) Number of bytes to be written.
  */
  virtual void setCompoundDocument(OdUInt32 numBytes, OdStreamBuf& streamBuf) = 0;

  enum Type
  {
    kUnknown    = 0,
    kLink       = 1,
    kEmbedded   = 2,
    kStatic     = 3
  };
  /** Description:
    Returns the *type* of the OdDbOleFrame of this OdOleItemHandler.
    
    Remarks:
    type() returns one of the following:
    
    @table
    Name          Value
    kUnknown      0
    kLink         1
    kEmbedded     2
    kStatic       3
    
  */
  virtual Type type() const = 0;

  enum DvAspect
  {
    kContent    = 1,
    kThumbnail  = 2,
    kIcon       = 4,
    kDocPrint   = 8
  };

  /** Description:
    Returns the *draw* aspect of this OleItemHandler object.
    
    Remarks:
    drawAspect() returns one of the following:
    
    @table
    Name          Value
    kContent      1 
    kThumbnail    2 
    kIcon         4 
    kDocPrint     8
  */
  virtual DvAspect drawAspect() const = 0;

  /** Description:
    Returns the link name of this OleItemHandler object.
  */
  virtual OdString linkName() const = 0;

  /** Description:
    Returns the link path of this OleItemHandler object.
  */
  virtual OdString linkPath() const = 0;

  /** Description:
    Returns the user *type* of this OleItemHandler object.
  */
  virtual OdString userType() const = 0;

  /** Description:
    Sets the *draw* aspect of this OleItemHandler object.
    Arguments:
    drawAspect (I) Draw aspect.

    Remarks:
    drawAspect must be one of the following:
    
    @table
    Name          Value
    kContent      1 
    kThumbnail    2 
    kIcon         4 
    kDocPrint     8
  */
  virtual void setDrawAspect(DvAspect drawAspect) = 0;

  virtual void* GetOleObject() = 0;
  virtual void  setOdDbObject(OdDbObject*) = 0;

  virtual int GetLinkUpdateOption() = 0;

  virtual void setLinkPath(OdString newPath) = 0;
};

#include "TD_PackPop.h"

#endif // _ODOLEITEMHANDLER_INCLUDED_
