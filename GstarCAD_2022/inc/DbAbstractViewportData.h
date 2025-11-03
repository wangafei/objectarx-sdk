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




#ifndef OD_DBABSTRACTVIEWPORTDATA_H
#define OD_DBABSTRACTVIEWPORTDATA_H


#include "AbstractViewPE.h"

class OdGsView;
class OdGiToneOperatorParameters;
/** Description:
    This class is the base class for Protocol Extension classes for OdDbViewport and OdDbViewportTableRecord objects.
    
    Library: TD_Db
    
    See Also:
    OdDbAbstractViewTableRecord

    Note:
    Only the following objects are supported:
    
    o  OdDbViewport
    o  OdDbViewportTableRecord
    o  Derivatives of one of the above.

    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbAbstractViewportData : public OdAbstractViewPE
{
public:
  ODRX_DECLARE_MEMBERS(OdDbAbstractViewportData);

  /** Description:
    Sets the parameters for the specified Viewport object according to the arguments.
    Arguments:
    pSourceView (I) Pointer to the source View object.
    pDestinationView (I) Pointer to the destination View object
  */
  virtual void setProps(OdRxObject* pViewport, const OdRxObject* pSourceView) const;

  /** \details
    Returns compatible visual style or background object for the specified viewport.
    \param pViewport [in] Input pointer to the viewport object.
    \param pCopyObject [in] Input object ID.
    \returns Returns compatible objectID or null if no compatible objects are found.
  */
  virtual OdDbStub* compatibleCopyObject(const OdRxObject* pViewport, OdDbStub* pCopyObject) const;
  /** Description:
    Returns true if and only if the UCS that is associated with the specified Viewport object will become active
    with activation of the Viewport object.

    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual bool isUcsSavedWithViewport(const OdRxObject* pViewport) const = 0;

  /** Description:
    Controls the activation of the UCS that is associated with the specified Viewport object 
    with the activation of the Viewport object.
    
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    ucsPerViewport (I) Controls activation of the UCS.
  */
  virtual void setUcsPerViewport( OdRxObject* pViewport, bool ucsPerViewport) const = 0;

  /** Description:
    Returns true if and only if UCS follow mode is on for the specified Viewport object.
    
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual bool isUcsFollowModeOn(const OdRxObject* pViewport) const = 0;

  /** Description:
    Controls UCS follow mode for the specified Viewport object.
    
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    ucsFollowMode (I) Controls UCS follow mode.
  */
  virtual void setUcsFollowModeOn(OdRxObject* pViewport, bool ucsFollowMode) const = 0;

  /** Description:
    Returns the *circle* *zoom* percent for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    Remarks:
    Returns a value in the range [1..20000]
  */
  virtual OdUInt16 circleSides(const OdRxObject* pViewport) const = 0;
  /** Description:
    Sets *circle* *zoom* percent for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    circleSides (I) Circle *zoom* percent. [1,20000]
  */
  virtual void setCircleSides(OdRxObject* pViewport, OdUInt16 circleSides) const = 0;

  /** Description:
    Returns true if and only if the grid is on for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual bool isGridOn(const OdRxObject* pViewport) const = 0;
  /** Description:
    Controls the grid for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    gridOn (I) Controls the grid.
  */
  virtual void setGridOn(OdRxObject* pViewport, bool gridOn) const = 0;

  /** Description:
    Returns the grid increment for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual OdGeVector2d gridIncrement(const OdRxObject* pViewport) const = 0;
  /** Description:
    Sets the grid increment for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    gridIncrement (I) Grid increment.
  */
  virtual void setGridIncrement(OdRxObject* pViewport, const OdGeVector2d& gridIncrement) const = 0;

  /** Description:
    Returns true if and only if the UCS icon is visible for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual bool isUcsIconVisible(const OdRxObject* pViewport) const = 0;
  /** Description:
    Controls the UCS icon visibility for the specified Viewport object.
    
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    iconVisible (I) Controls the visibility.
  */
  virtual void setUcsIconVisible(OdRxObject* pViewport, bool iconVisible) const = 0;

  /** Description:
    Returns true if and only if the UCS icon is at the UCS orgin for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual bool isUcsIconAtOrigin(const OdRxObject* pViewport) const = 0;
  /** Description:
    Controls the UCS icon display at the UCS orgin for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    atOrigin (I) Controls the UCS icon.
    
    Remarks:
    If atOrigin is true, the UCS icon is at the UCS origin for this Viewport object. If false, it is at the 
    corner for this Viewport object.
    
  */
  virtual void setUcsIconAtOrigin(OdRxObject* pViewport, bool atOrigin) const = 0;

  /** Description:
    Returns true if and only if the snap mode is on for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual bool isSnapOn(const OdRxObject* pViewport) const = 0;
  /** Description:
    Controls the snap mode for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    snapOn (I) Controls snap mode.
  */
  virtual void setSnapOn(OdRxObject* pViewport, bool snapOn) const = 0;

  /** Description:
    Returns true if and only if isometric snap style is on for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual bool isSnapIsometric(const OdRxObject* pViewport) const = 0;
  /** Description:
    Controls the isometric snap style for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    snapIsometric (I) Controls isometric snap style.
  */
  virtual void setSnapIsometric(OdRxObject* pViewport, bool snapIsometric) const = 0;

  /** Description:
    Returns the UCS snap angle for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual double snapAngle(const OdRxObject* pViewport) const = 0;
  /** Description:
    Returns the UCS snap angle for the specified Viewport object (DXF 50).
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    snapAngle (I) Snap angle.
    Note:
    All angles are expressed in radians.
  */
  virtual void setSnapAngle(OdRxObject* pViewport, double snapAngle) const = 0;

  /** Description:
    Returns the UCS snap base point of the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual OdGePoint2d snapBase(const OdRxObject* pViewport) const = 0;
  /** Description:
    Sets the UCS snap base point of the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    snapBase (I) Snap base.
  */
  virtual void setSnapBase(OdRxObject* pViewport, const OdGePoint2d& snapBase) const = 0; 

  /** Description:
    Returns the snap increment of the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual OdGeVector2d snapIncrement(const OdRxObject* pViewport) const = 0;
  /** Description:
    Returns the snap increment of the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    snapIncrement (I) Snap increment.
  */
  virtual void setSnapIncrement(OdRxObject* pViewport, const OdGeVector2d& snapIncrement) const = 0;

  /** Description:
    Returns the snap IsoPair of this Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.

    Remarks:
    snapIsoPair() returns one of the following:
    
    @table
    Value    Description
    0        Left isoplane
    1        Top isoplane
    2        Right isoplane
  */
  virtual OdUInt16 snapIsoPair(const OdRxObject* pViewport) const = 0;
  /** Description:
    Sets the snap IsoPair of this Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    snapIsoPair (I) Snap IsoPair
    Remarks:
    snapIsoPair must be one of the following:
    
    @table
    Value    Description
    0        Left isoplane
    1        Top isoplane
    2        Right isoplane
  */
  virtual void setSnapIsoPair(OdRxObject* pViewport, OdUInt16 snapIsoPair) const = 0;

  virtual OdGsView* gsView(OdRxObject* pViewport) const = 0;
  virtual void setGsView(OdRxObject* pViewport, OdGsView*) = 0;

  //GCAD-add
  virtual OdUInt16 gridMajor(const OdRxObject* pViewport) const = 0;
  virtual bool isGridAdaptive(const OdRxObject* pViewport) const = 0;
  virtual bool isGridFollow(const OdRxObject* pViewport) const = 0;
  virtual bool isGridSubdivisionRestricted(const OdRxObject* pViewport) const = 0;
  virtual bool isGridBoundToLimits(const OdRxObject* pViewport) const = 0;
  /** \details
    Returns the brightness value of the specified viewport object.
    \param pViewport [in] Input pointer to the viewport object.
  */
  virtual double brightness(const OdRxObject* pViewport) const = 0;
  /** \details
    Sets the brightness value to the specified viewport object.
    \param pViewport [in] Input pointer to the viewport object.
    \param brightness [in] Input brightness value.
  */
  virtual void setBrightness(OdRxObject* pViewport, double brightness) const = 0;

  /** \details
    Returns the contrast value of the specified viewport object.
    \param pViewport [in] Input pointer to the viewport object.
  */
  virtual double contrast(const OdRxObject* pViewport) const = 0;
  /** \details
    Sets the contrast value to the specified viewport object.
    \param pViewport [in] Input pointer to the viewport object.
    \param contrast [in] Input brightness value.
  */
  virtual void setContrast(OdRxObject* pViewport, double contrast) const = 0;

  /** \details
    Returns the ambient light color of the specified viewport object.
    \param pViewport [in] Input pointer to the viewport object.
  */
  virtual OdCmColor ambientLightColor(const OdRxObject* pViewport) const = 0;
  /** \details
    Sets the ambient light color to the specified viewport object.
    \param pViewport [in] Input pointer to the viewport object.
    \param color [in] Input ambient light color.
  */
  virtual void setAmbientLightColor(OdRxObject* pViewport, const OdCmColor& color) const = 0;

  /** \details
    Returns the sun ID of the specified viewport object.
    \param pViewport [in] Input pointer to the viewport object.
  */
  virtual OdDbStub *sunId(const OdRxObject* pViewport) const = 0;
  /** \details
    Sets the sun object to the specified viewport object.
    \param pViewport [in] Input pointer to the viewport object.
    \param pSun [in] Input pointer to the sun object.
  */
  virtual OdDbStub *setSun(OdRxObject* pViewport, OdRxObject* pSun) const = 0;

  /** \details
    Returns the tone operator parameters of the specified viewport object.
    \param pViewport [in] Input pointer to the viewport object.
    \param params [out] Output tone operator parameters.
  */
  virtual OdResult toneOperatorParameters(const OdRxObject* pViewport, OdGiToneOperatorParameters &params) const = 0;
  /** \details
    Sets the tone operator parameters to the specified viewport object.
    \param pViewport [in] Input pointer to the viewport object.
    \param params [in] Input tone operator parameters.
  */
  virtual OdResult setToneOperatorParameters(OdRxObject* pViewport, const OdGiToneOperatorParameters &params) const = 0;

  /** \details
    Returns the type of the viewcube display of the specified viewport object.
    \param pViewport [in] Input pointer to the viewport object.
  */
  virtual int navvcubedisplay(const OdRxObject* pViewport) const;
  /** \details
    Sets the type of the viewcube display to the specifiedvViewport object.
    \param pViewport [in] Input pointer to the viewport object.
    \param nVal [in] Input type of the viewcube display.
  */
  virtual OdResult setNavvcubedisplay(OdRxObject* pViewport, int nVal) const;

  // UCS/P
  virtual void pushUCS(const OdRxObject* pViewport) = 0;
  virtual bool popUCS(const OdRxObject* pViewport) = 0;
  virtual bool topUCS(const OdRxObject* pViewport, OdGeMatrix3d& mat) = 0;
};
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbAbstractViewportData object pointers.
*/
typedef OdSmartPtr<OdDbAbstractViewportData> OdDbAbstractViewportDataPtr;


#endif //#ifndef OD_DBABSTRACTVIEWPORTDATA_H

