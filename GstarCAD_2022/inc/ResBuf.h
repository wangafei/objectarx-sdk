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




#if !defined(_ODRESBUF_H___INCLUDED_)
#define _ODRESBUF_H___INCLUDED_

#include "TD_PackPush.h"

#include "RxObject.h"
#include "OdString.h"
#include "DbHandle.h"
#include "OdError.h"
#include "OdDb.h"

class OdBinaryData;
class OdGePoint2d;
class OdGePoint3d;
class OdGeVector2d;
class OdGeVector3d;
class OdDbObjectId;
class OdDbDatabase;
class OdCmColor;
class OdResBuf;
class OdDbSelectionSet;

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbSelectionSet object pointers.
*/
typedef OdSmartPtr<OdDbSelectionSet> OdDbSelectionSetPtr;

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdResBuf object pointers.
*/
typedef OdSmartPtr<OdResBuf> OdResBufPtr;

/** Description:
    This class implements OdError objects with Result codes of eInvalidResBuf.

    Library: TD_Db
    {group:Error_Classes}
*/
class TOOLKIT_EXPORT OdError_InvalidResBuf : public OdError
{
public:
  OdError_InvalidResBuf() : OdError(eInvalidResBuf){}
};

/** Description:
  This class implements ResBuf structures that handle all .dwg file basic data types.

  Remarks:
  Each ResBuf object contains three data members:

  o  ResType: An integer which specifies the type of data stored in the ResBuf object.
  o  ResVal:  A container for the data stored in the ResBuf object.
  o  RbNext:  A SmartPointer to the *next* ResBuf object in a linked list.

  Library:
  TD_Db

  {group:Other_Classes}
*/
class TOOLKIT_EXPORT OdResBuf : public OdRxObject
{
public:

  /**
    Description:
    Copies the contents of the specified ResBuf object into this ResBuf object.

    Arguments:
    pSource (I) Pointer to the source object.

    Throws:
    eInvalidGroupCode for invalid ResType values.
  */
  OdResult copyFrom( const OdRxObject* pSource );
  bool operator==( const OdResBuf& resBuf ) const;
  bool operator!=( const OdResBuf& other ) const;

  enum ValueType
  {
    kRtNone                     = 5000,
    kRtDouble                   = 5001,
    kRtPoint2d                  = 5002,
    kRtInt16                    = 5003,
    kRtAngle                    = 5004,
    kRtString                   = 5005,

    kRtEntName                  = 5006, // setObjectId()/getEntName()/getObjectId(0)
    kRtPickSet                  = 5007,

    kRtOrient                   = 5008,

    kRtPoint3d                  = 5009,
    kRtInt32                    = 5010,
    kRtColor                    = 5011,

    kRtVoid                     = 5014,
    kRtListBeg                  = 5016, // list begin
    kRtListEnd                  = 5017, // list end
    kRtDote                     = 5018, // dot
    kRtNil                      = 5019, // nil



    kRtDXF0                     = 5020,
    kRtT                        = 5021,
    kRtResBuf                   = 5023,
//  kRtModeless                 = 5027,

    kRtBool                     =  290,
    kRtInt8                     =  280,
    kRtVector2d                 = kRtPoint2d,
    kRtVector3d                 = kRtPoint3d,
    kRtBinaryChunk              =  310,
    kRtHandle                   =  320,
    kRtObjectId                 =  330,
    kRtSoftPointerId            =  330,
    kRtHardPointerId            =  340,
    kRtSoftOwnershipId          =  350,
    kRtHardOwnershipId          =  360,

    kDxfInvalid                 = OdDb::kDxfInvalid,

    kDxfXDictionary             = OdDb::kDxfXDictionary,
    kDxfPReactors               = OdDb::kDxfPReactors,
    kDxfOperator                = OdDb::kDxfOperator,
    kDxfXDataStart              = OdDb::kDxfXDataStart,
    kDxfHeaderId                = OdDb::kDxfHeaderId,
    kDxfFirstEntId              = OdDb::kDxfFirstEntId,
    kDxfEnd                     = OdDb::kDxfEnd,
    kDxfStart                   = OdDb::kDxfStart,
    kDxfText                    = OdDb::kDxfText,
    kDxfXRefPath                = OdDb::kDxfXRefPath,
    kDxfShapeName               = OdDb::kDxfShapeName,
    kDxfBlockName               = OdDb::kDxfBlockName,
    kDxfAttributeTag            = OdDb::kDxfAttributeTag,
    kDxfSymbolTableName         = OdDb::kDxfSymbolTableName,
    kDxfMstyleName              = OdDb::kDxfMstyleName,
    kDxfSymTableRecName         = OdDb::kDxfSymTableRecName,
    kDxfAttributePrompt         = OdDb::kDxfAttributePrompt,
    kDxfDimStyleName            = OdDb::kDxfDimStyleName,
    kDxfLinetypeProse           = OdDb::kDxfLinetypeProse,
    kDxfTextFontFile            = OdDb::kDxfTextFontFile,
    kDxfDescription             = OdDb::kDxfDescription,
    kDxfDimPostStr              = OdDb::kDxfDimPostStr,
    kDxfTextBigFontFile         = OdDb::kDxfTextBigFontFile,
    kDxfDimAPostStr             = OdDb::kDxfDimAPostStr,
    kDxfCLShapeName             = OdDb::kDxfCLShapeName,
    kDxfSymTableRecComments     = OdDb::kDxfSymTableRecComments,
    kDxfHandle                  = OdDb::kDxfHandle,
    kDxfDimBlk                  = OdDb::kDxfDimBlk,
    kDxfDimBlk1                 = OdDb::kDxfDimBlk1,
    kDxfLinetypeName            = OdDb::kDxfLinetypeName,
    kDxfDimBlk2                 = OdDb::kDxfDimBlk2,
    kDxfTextStyleName           = OdDb::kDxfTextStyleName,
    kDxfLayerName               = OdDb::kDxfLayerName,
    kDxfCLShapeText             = OdDb::kDxfCLShapeText,
    kDxfXCoord                 = OdDb::kDxfXCoord,
    kDxfYCoord                 = OdDb::kDxfYCoord,
    kDxfZCoord                 = OdDb::kDxfZCoord,
    kDxfElevation              = OdDb::kDxfElevation,
    kDxfThickness              = OdDb::kDxfThickness,
    kDxfReal                   = OdDb::kDxfReal,
    kDxfViewportHeight         = OdDb::kDxfViewportHeight,
    kDxfTxtSize                = OdDb::kDxfTxtSize,
    kDxfTxtStyleXScale         = OdDb::kDxfTxtStyleXScale,
    kDxfViewWidth              = OdDb::kDxfViewWidth,
    kDxfViewportAspect         = OdDb::kDxfViewportAspect,
    kDxfTxtStylePSize          = OdDb::kDxfTxtStylePSize,
    kDxfViewLensLength         = OdDb::kDxfViewLensLength,
    kDxfViewFrontClip          = OdDb::kDxfViewFrontClip,
    kDxfViewBackClip           = OdDb::kDxfViewBackClip,
    kDxfShapeXOffset           = OdDb::kDxfShapeXOffset,
    kDxfShapeYOffset           = OdDb::kDxfShapeYOffset,
    kDxfViewHeight             = OdDb::kDxfViewHeight,
    kDxfShapeScale             = OdDb::kDxfShapeScale,
    kDxfPixelScale             = OdDb::kDxfPixelScale,
    kDxfLinetypeScale          = OdDb::kDxfLinetypeScale,
    kDxfDashLength             = OdDb::kDxfDashLength,
    kDxfMlineOffset            = OdDb::kDxfMlineOffset,
    kDxfLinetypeElement        = OdDb::kDxfLinetypeElement,
    kDxfAngle                  = OdDb::kDxfAngle,
    kDxfViewportSnapAngle      = OdDb::kDxfViewportSnapAngle,
    kDxfViewportTwist          = OdDb::kDxfViewportTwist,
    kDxfVisibility             = OdDb::kDxfVisibility,
    kDxfLayerLinetype          = OdDb::kDxfLayerLinetype,
    kDxfColor                  = OdDb::kDxfColor,
    kDxfHasSubentities         = OdDb::kDxfHasSubentities,
    kDxfViewportVisibility     = OdDb::kDxfViewportVisibility,
    kDxfViewportActive         = OdDb::kDxfViewportActive,
    kDxfViewportNumber         = OdDb::kDxfViewportNumber,
    kDxfInt16                  = OdDb::kDxfInt16,
    kDxfViewMode               = OdDb::kDxfViewMode,
    kDxfCircleSides            = OdDb::kDxfCircleSides,
    kDxfViewportZoom           = OdDb::kDxfViewportZoom,
    kDxfViewportIcon           = OdDb::kDxfViewportIcon,
    kDxfViewportSnap           = OdDb::kDxfViewportSnap,
    kDxfViewportGrid           = OdDb::kDxfViewportGrid,
    kDxfViewportSnapStyle      = OdDb::kDxfViewportSnapStyle,
    kDxfViewportSnapPair       = OdDb::kDxfViewportSnapPair,
    kDxfRegAppFlags            = OdDb::kDxfRegAppFlags,
    kDxfTxtStyleFlags          = OdDb::kDxfTxtStyleFlags,
    kDxfLinetypeAlign          = OdDb::kDxfLinetypeAlign,
    kDxfLinetypePDC            = OdDb::kDxfLinetypePDC,
    kDxfInt32                  = OdDb::kDxfInt32,
    kDxfSubclass               = OdDb::kDxfSubclass,
    kDxfEmbeddedObjectStart    = OdDb::kDxfEmbeddedObjectStart,
    kDxfControlString          = OdDb::kDxfControlString,
    kDxfDimVarHandle           = OdDb::kDxfDimVarHandle,
    kDxfUCSOrg                 = OdDb::kDxfUCSOrg,
    kDxfUCSOriX                = OdDb::kDxfUCSOriX,
    kDxfUCSOriY                = OdDb::kDxfUCSOriY,
    kDxfXReal                  = OdDb::kDxfXReal,
    // 64-bit integers can only be used with version R24 and higher
    kDxfInt64                  = OdDb::kDxfInt64,
    //
    kDxfXInt16                 = OdDb::kDxfXInt16,
    kDxfNormalX                = OdDb::kDxfNormalX,
    kDxfNormalY                = OdDb::kDxfNormalY,
    kDxfNormalZ                = OdDb::kDxfNormalZ,
    kDxfXXInt16                = OdDb::kDxfXXInt16,
    kDxfInt8                   = OdDb::kDxfInt8,
    kDxfRenderMode             = OdDb::kDxfRenderMode,
    kDxfBool                   = OdDb::kDxfBool,
    kDxfXTextString            = OdDb::kDxfXTextString,
    kDxfBinaryChunk            = OdDb::kDxfBinaryChunk,
    kDxfArbHandle              = OdDb::kDxfArbHandle,
    kDxfSoftPointerId          = OdDb::kDxfSoftPointerId,
    kDxfHardPointerId          = OdDb::kDxfHardPointerId,
    kDxfSoftOwnershipId        = OdDb::kDxfSoftOwnershipId,
    kDxfHardOwnershipId        = OdDb::kDxfHardOwnershipId,  
    kDxfLineWeight             = OdDb::kDxfLineWeight,
    kDxfPlotStyleNameType      = OdDb::kDxfPlotStyleNameType,
    kDxfPlotStyleNameId        = OdDb::kDxfPlotStyleNameId,
    kDxfXXXInt16               = OdDb::kDxfXXXInt16,
    kDxfLayoutName             = OdDb::kDxfLayoutName,
    kDxfComment                = OdDb::kDxfComment,
    kDxfXdAsciiString          = OdDb::kDxfXdAsciiString,
    kDxfRegAppName             = OdDb::kDxfRegAppName,
    kDxfXdControlString        = OdDb::kDxfXdControlString,
    kDxfXdLayerName            = OdDb::kDxfXdLayerName,
    kDxfXdBinaryChunk          = OdDb::kDxfXdBinaryChunk,
    kDxfXdHandle               = OdDb::kDxfXdHandle,
    kDxfXdXCoord               = OdDb::kDxfXdXCoord,
    kDxfXdYCoord               = OdDb::kDxfXdYCoord,
    kDxfXdZCoord               = OdDb::kDxfXdZCoord,
    kDxfXdWorldXCoord          = OdDb::kDxfXdWorldXCoord,
    kDxfXdWorldYCoord          = OdDb::kDxfXdWorldYCoord,
    kDxfXdWorldZCoord          = OdDb::kDxfXdWorldZCoord,
    kDxfXdWorldXDisp           = OdDb::kDxfXdWorldXDisp,
    kDxfXdWorldYDisp           = OdDb::kDxfXdWorldYDisp,
    kDxfXdWorldZDisp           = OdDb::kDxfXdWorldZDisp,
    kDxfXdWorldXDir            = OdDb::kDxfXdWorldXDir,
    kDxfXdWorldYDir            = OdDb::kDxfXdWorldYDir,
    kDxfXdWorldZDir            = OdDb::kDxfXdWorldZDir,
    kDxfXdReal                 = OdDb::kDxfXdReal,
    kDxfXdDist                 = OdDb::kDxfXdDist,
    kDxfXdScale                = OdDb::kDxfXdScale,
    kDxfXdInteger16            = OdDb::kDxfXdInteger16,
    kDxfXdInteger32            = OdDb::kDxfXdInteger32
  };

  ODRX_DECLARE_MEMBERS(OdResBuf);

  ~OdResBuf();

  /** Description:
    Returns the ResType of this ResBuf object.
    
    See also:
    ValueType
    
    Remarks:
    OdDxfCode::_getType() may be used to determine the type of data associated with a given *restype*.
  */
  int restype() const;
  
  /** Description:
    Sets the ResType of this ResBuf object.
    
    Arguments:
    resType (I) ResType.
        
    See also:
    ValueType
  */
  void setRestype(int restype);

  /** Description:
    Returns a SmartPointer to the *next* ResBuf object in this ResBuf object's ResBuf chain.
  */
  OdResBufPtr next() const;

  /** Description:
    Returns a SmartPointer to the *last* ResBuf object in this ResBuf object's ResBuf chain.
  */
  OdResBufPtr last() const;
  
  /** Description:
    Inserts the specified ResBuf object before the *next* ResBuf object in this ResBuf object's ResBuf chain.
    
    Arguments:
    pRb (I) Pointer to the ResBuf object.
    
    Remarks:
    Returns a SmartPointer to the ResBuf object before which it was inserted.
  */
  OdResBufPtr insert(OdResBuf* pRb);
  
  /** Description:
    Sets the specified Resbuf object as the *next* Resbuf Object in the ResBuf chain of this 
    Resbuf object after this ResBuf object.
    
    Arguments:
    pRb (I) Pointer to the ResBuf object.
  */
  OdResBufPtr setNext(OdResBuf* pRb);

  /** Description:
    Returns the ResVal in this ResBuf object.

    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of data returned by this function.
  */
  OdString getString() const;

  /** Description:
    Returns the ResVal in this ResBuf object.

    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of data returned by this function.
  */
  bool getBool() const;

  /** Description:
    Returns the ResVal in this ResBuf object.

    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of data returned by this function.
  */
  OdInt8 getInt8() const;

  /** Description:
    Returns the ResVal in this ResBuf object.

    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of data returned by this function.
  */
  OdInt16 getInt16() const;

  /** Description:
    Returns the ResVal in this ResBuf object.

    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of data returned by this function.
  */
 OdInt32 getInt32() const;

 /** Description:
   Returns the ResVal in this ResBuf object.

   Throws:
   OdError_InvalidResBuf if ResType does not correspond to the type of data returned by this function.
 */
 OdInt64 getInt64() const;

  /** Description:
    Returns the ResVal in this ResBuf object.

    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of data returned by this function.
  */
  double getDouble() const;

  /** Description:
    Returns the ResVal in this ResBuf object.

    Throws:
    eInvalidGroupCode if ResType does not correspond to the type of data returned by this function.
  */
  const OdGePoint2d& getPoint2d() const;

  /** Description:
    Returns the ResVal in this ResBuf object.

    Throws:
    eInvalidGroupCode if ResType does not correspond to the type of data returned by this function.
  */
  const OdGePoint3d& getPoint3d() const;

  /** Description:
    Returns the ResVal in this ResBuf object.

    Throws:
    eInvalidGroupCode if ResType does not correspond to the type of data returned by this function.
  */
  const OdGeVector2d& getVector2d() const;

  /** Description:
    Returns the ResVal in this ResBuf object.

    Throws:
    eInvalidGroupCode if ResType does not correspond to the type of data returned by this function.
  */
  const OdGeVector3d& getVector3d() const;

  /** Description:
    Returns the ResVal in this ResBuf object.

    Throws:
    eInvalidGroupCode if ResType does not correspond to the type of data returned by this function.
  */
  const OdBinaryData& getBinaryChunk() const;

  /** Description:
    Returns the ResVal in this ResBuf object.

    Throws:
    eInvalidGroupCode if ResType does not correspond to the type of data returned by this function.
  */
  const OdCmColor& getColor() const;

  /** Description:
    Returns the ResVal in this ResBuf object.

    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of data returned by this function.
  */
  OdDbHandle getHandle() const;

  /** Description:
    Returns the ResVal in this ResBuf object.
    
    Arguments:
    pDb (I) Pointer to the *database*.
  */
  OdDbObjectId getObjectId(const OdDbDatabase* pDb) const;

  /** Description:
    Returns the ResVal in this ResBuf object.
  */
  OdResBufPtr getResBuf() const;

  /** Description:
    Returns the ResVal in this ResBuf object.
  */
  OdDbSelectionSetPtr getPickSet() const;

  /** Description:
    Returns the ResVal in this ResBuf object.
  */
  const OdDbObjectId& getEntName() const;

  /** Description:
    Sets the ResVal in this ResBuf object.
      
    Arguments:
    resVal (I) ResVal.

    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of ResVal.
  */
  void setString(const OdString& resVal);

  /** Description:
    Sets the ResVal in this ResBuf object.
      
    Arguments:
    resVal (I) ResVal.

    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of ResVal.
  */
  void setBool(bool resVal);

  /** Description:
    Sets the ResVal in this ResBuf object.
      
    Arguments:
    resVal (I) ResVal.

    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of ResVal.
  */
  void setInt8(OdInt8 resVal);

  /** Description:
    Sets the ResVal in this ResBuf object.
      
    Arguments:
    resVal (I) ResVal.

    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of ResVal.
  */
  void setInt16(OdInt16 resVal);

  /** Description:
    Sets the ResVal in this ResBuf object.
      
    Arguments:
    resVal (I) ResVal.

    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of ResVal.
  */
  void setInt32(OdInt32 resVal);

  /** Description:
    Sets the ResVal in this ResBuf object.

    Arguments:
    resVal (I) ResVal.

    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of ResVal.
  */
  void setInt64(OdInt64 resVal);

  /** Description:
    Sets the ResVal in this ResBuf object.
      
    Arguments:
    resVal (I) ResVal.

    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of ResVal.
  */
  void setDouble(double resVal);

  /** Description:
    Sets the ResVal in this ResBuf object.
      
    Arguments:
    resVal (I) ResVal.

    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of ResVal.
  */
  void setPoint2d(const OdGePoint2d& resVal);

  /** Description:
    Sets the ResVal in this ResBuf object.
      
    Arguments:
    resVal (I) ResVal.

    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of ResVal.
  */
  void setPoint3d(const OdGePoint3d& resVal);

  /** Description:
    Sets the ResVal in this ResBuf object.
      
    Arguments:
    resVal (I) ResVal.

    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of ResVal.
  */
  void setVector2d(const OdGeVector2d& val);

  /** Description:
    Sets the ResVal in this ResBuf object.
      
    Arguments:
    resVal (I) ResVal.

    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of ResVal.
  */
  void setVector3d(const OdGeVector3d& val);

  /** Description:
    Sets the ResVal in this ResBuf object.
      
    Arguments:
    resVal (I) ResVal.

    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of ResVal.
  */
  void setBinaryChunk(const OdBinaryData& resVal);

  /** Description:
    Sets the ResVal in this ResBuf object.
      
    Arguments:
    resVal (I) ResVal.

    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of ResVal.
  */
  void setHandle(const OdDbHandle& resVal);

  /** Description:
    Sets the ResVal in this ResBuf object.
      
    Arguments:
    resVal (I) ResVal.

    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of ResVal.
  */
  void setObjectId(const OdDbObjectId& resVal);

  /** Description:
    Sets the ResVal in this ResBuf object.
      
    Arguments:
    resVal (I) ResVal.

    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of ResVal.
  */
  void setColor(const OdCmColor& resVal);

  /** Description:
    Sets the ResVal in this ResBuf object.
      
    Arguments:
    pResBuf (I) ResBuf object.

    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of ResVal.
  */
  void setResBuf(const OdResBuf* pResBuf);

  /** Description:
    Sets the ResVal in this ResBuf object.
      
    Arguments:
    pSSet (I) selection set.

    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of ResVal.
  */
  void setPickSet(const OdDbSelectionSet* pSSet);

  /** Description:
    Creates a ResBuf object of the specified ResType.
    
    Arguments:
    resType (I) ResType.
    resVal (I) ResVal.    
 
    Throws:
    OdError_InvalidResBuf if ResType does not correspond to the type of ResVal.
  */
  static OdResBufPtr newRb(int resType = OdResBuf::kRtNone);

  static OdResBufPtr newRb(int resType, bool resVal)
  {
    OdResBufPtr pRes = newRb(resType);
    pRes->setBool(resVal);
    return pRes;
  }

  static OdResBufPtr newRb(int resType, OdInt8 resVal)
  {
    OdResBufPtr pRes = newRb(resType);
    pRes->setInt8(resVal);
    return pRes;
  }

  static OdResBufPtr newRb(int resType, OdUInt8 resVal)
  {
    OdResBufPtr pRes = newRb(resType);
    pRes->setInt8(resVal);
    return pRes;
  }

  static OdResBufPtr newRb(int resType, OdInt16 resVal)
  {
    OdResBufPtr pRes = newRb(resType);
    pRes->setInt16(resVal);
    return pRes;
  }

  static OdResBufPtr newRb(int resType, OdUInt16 resVal)
  {
    OdResBufPtr pRes = newRb(resType);
    pRes->setInt16(resVal);
    return pRes;
  }

  static OdResBufPtr newRb(int resType, OdInt32 resVal)
  {
    OdResBufPtr pRes = newRb(resType);
    pRes->setInt32(resVal);
    return pRes;
  }

  static OdResBufPtr newRb(int resType, OdUInt32 resVal)
  {
    OdResBufPtr pRes = newRb(resType);
    pRes->setInt32(resVal);
    return pRes;
  }

  static OdResBufPtr newRb(int resType, OdInt64 resVal)
  {
    OdResBufPtr pRes = newRb(resType);
    pRes->setInt64(resVal);
    return pRes;
  }

  static OdResBufPtr newRb(int resType, OdUInt64 resVal)
  {
    OdResBufPtr pRes = newRb(resType);
    pRes->setInt64(resVal);
    return pRes;
  }

  static OdResBufPtr newRb(int resType, double resVal)
  {
    OdResBufPtr pRes = newRb(resType);
    pRes->setDouble(resVal);
    return pRes;
  }

  static OdResBufPtr newRb(int resType, const OdGePoint2d& resVal)
  {
    OdResBufPtr pRes = newRb(resType);
    pRes->setPoint2d(resVal);
    return pRes;
  }

  static OdResBufPtr newRb(int resType, const OdGePoint3d& resVal)
  {
    OdResBufPtr pRes = newRb(resType);
    pRes->setPoint3d(resVal);
    return pRes;
  }

  static OdResBufPtr newRb(int resType, const OdGeVector2d& resVal)
  {
    OdResBufPtr pRes = newRb(resType);
    pRes->setVector2d(resVal);
    return pRes;
  }

  static OdResBufPtr newRb(int resType, const OdGeVector3d& resVal)
  {
    OdResBufPtr pRes = newRb(resType);
    pRes->setVector3d(resVal);
    return pRes;
  }

  static OdResBufPtr newRb(int resType, const OdString& resVal)
  {
    OdResBufPtr pRes = newRb(resType);
    pRes->setString(resVal);
    return pRes;
  }

  static OdResBufPtr newRb(int resType, const OdChar* resVal)
  {
    OdResBufPtr pRes = newRb(resType);
    pRes->setString(resVal);
    return pRes;
  }
#if !defined(NATIVE_ODCHAR) && defined(_MSC_VER) && _MSC_VER >= 1300 && !defined(_WIN32_WCE)
  static OdResBufPtr newRb(int resType, const __wchar_t* resVal)
  {
    OdResBufPtr pRes = newRb(resType);
    pRes->setString(resVal);
    return pRes;
  }
#endif

  static OdResBufPtr newRb(int resType, const OdCmColor& resVal)
  {
    OdResBufPtr pRes = newRb(resType);
    pRes->setColor(resVal);
    return pRes;
  }

  static OdResBufPtr newRb(int resType, const OdDbObjectId& id)
  {
    OdResBufPtr pRes = newRb(resType);
    pRes->setObjectId(id);
    return pRes;
  }

  static OdResBufPtr newRb(int resType, const OdDbSelectionSet* pSSet)
  {
    OdResBufPtr pRes = newRb(resType);
    pRes->setPickSet(pSSet);
    return pRes;
  }

  static OdResBufPtr newRb(int resType, const OdResBuf* pNestedRb)
  {
    OdResBufPtr pRes = newRb(resType);
    pRes->setResBuf(pNestedRb);
    return pRes;
  }

  union Data
  {
    bool    Bool;
    OdInt16 Int16;
    OdInt32 Int32;
    OdInt64 Int64; // New in R24 (AC24 support) - via binary DXF
    double  Double;
    void*   Pointer;
    OdUInt8 Bytes[sizeof(OdInt64)];
  };
protected:
  OdResBuf();

  int m_nCode;  // ResType
  Data m_data;   // ResVal
  OdResBufPtr m_pNext;  // RbNext
};

inline bool
OdResBuf::operator!=( const OdResBuf& other ) const
{
  return !operator==( other );
}

TOOLKIT_EXPORT OdResBufPtr odutDupAcRb     (const resbuf* pSrc,  OdDbDatabase* pDb = NULL);
TOOLKIT_EXPORT resbuf* odutDupOdRb     (const OdResBufPtr pSrc,  OdDbDatabase* pDb = NULL);

TOOLKIT_EXPORT OdResult    odutCopyAcRb    (const resbuf* pFrom, OdResBufPtr   pTo, OdDbDatabase* pDb = NULL);
TOOLKIT_EXPORT OdResult    odutCopyOdRb    (const OdResBufPtr pFrom, resbuf*   pTo, OdDbDatabase* pDb = NULL);

TOOLKIT_EXPORT OdResBufPtr odutDupAcRbChain(const resbuf* pSrc,  OdDbDatabase* pDb = NULL);
TOOLKIT_EXPORT resbuf* odutDupOdRbChain(const OdResBufPtr pSrc,  OdDbDatabase* pDb = NULL);
#include "TD_PackPop.h"

#endif //_ODRESBUF_H___INCLUDED_

