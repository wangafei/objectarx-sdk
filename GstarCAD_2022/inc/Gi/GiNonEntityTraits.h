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


#ifndef __ODGI_NONENTITYTRAITS_H__
#define __ODGI_NONENTITYTRAITS_H__

#include "../TD_PackPush.h"

#include "../Gi/Gi.h"
#include "../OdCodePage.h"
#include "../Gi/GiDrawable.h"

class OdGiLinetypeDash;
class OdFont;
class OdTtfDescriptor;
class OdGiTextStyle;

/** Description:
    This class defines the interface to the *layer* traits for the vectorization process.
    
    Library: TD_Gi
    {group:OdGi_Classes} 
*/
class FIRSTDLL_EXPORT OdGiLayerTraits : public OdGiDrawableTraits
{
public:
  ODRX_DECLARE_MEMBERS(OdGiLayerTraits);

  // returned via subSetAttributes()

  enum
  {
    kByBlock    = (OdGiDrawable::kLastFlag << 1),
    kFrozen     = (OdGiDrawable::kLastFlag << 2),
    kOff        = (OdGiDrawable::kLastFlag << 3),
    kPlottable  = (OdGiDrawable::kLastFlag << 4),
    kDefpoints  = (OdGiDrawable::kLastFlag << 5),
    kLocked     = (OdGiDrawable::kLastFlag << 6)
  };
  
  /** Description:
    Returns the *color* for this object.
  */
  virtual OdCmEntityColor color() const = 0;

  /** Description:
    Returns the *lineweight* for this object.
  */
  virtual OdDb::LineWeight lineweight() const = 0;

  /** Description:
    Returns the Object ID of the *linetype* for this object. 
  */
  virtual OdDbStub* linetype() const = 0;
  
  /** Description:
    Returns the Plot Style Name Type for this object. 
    Remarks:
    plotStyleNameType() returns one of the following:
    
    @table
    Name                                 Value                         
    OdDb::kPlotStyleNameByLayer          0
    OdDb::kPlotStyleNameByBlock          1
    OdDb::kPlotStyleNameIsDictDefault    2
    OdDb::kPlotStyleNameById             3
  */
  virtual OdDb::PlotStyleNameType plotStyleNameType() const = 0;
  /** Description:
    Returns the Object ID of the Plot Style Name. 
  */
  virtual OdDbStub* plotStyleNameId() const = 0;
  /** Description:
    Returns the Object ID of the *material*.
  */
  virtual OdDbStub* materialId() const = 0;
  /** Description:
    Returns the transparency for this object.
  */
  virtual OdCmTransparency transparency() const = 0;

  /** Description:
    Sets the *color* for this object.
    Arguments:
    color (I) Entity *color*.
  */
  virtual void setColor(const OdCmEntityColor& color) = 0;
  /** Description:
    Sets the *lineweight* for this object.
    Arguments:
    lineweight (I) Lineweight.
  */
  virtual void setLineweight(OdDb::LineWeight lineweight) = 0;
  /** Description:
    Sets the *linetype* for this object.
    Arguments:
    pLinetypeId (I) Pointer to the Object ID of the *linetype*.
  */
  virtual void setLinetype(OdDbStub* pLinetypeId) = 0;
  
  /** Description:
    Sets the Plot Style Name for this object.

    Arguments:
    plotStyleNameType (I) Plot Style Name Type.
    pPlotStyleNameId (I) Pointer to the Object ID of the Plot Style Name.
    
    Remarks:
    pPlotStyleNameId is used only when plotStyleNameType == kPlotStyleNameById.
    
    plotStyleNameType must be one of the following:
    
    @table
    Name                                 Value                         
    OdDb::kPlotStyleNameByLayer          0
    OdDb::kPlotStyleNameByBlock          1
    OdDb::kPlotStyleNameIsDictDefault    2
    OdDb::kPlotStyleNameById             3
  */
  virtual void setPlotStyleName(OdDb::PlotStyleNameType plotStyleNameType, OdDbStub* pPlotStyleNameId= 0) = 0;

  /** Description:
    Sets the *material* ID for this object.
    Arguments:
    pMaterialId (I) Pointer to the Object ID of the *material*.
  */
  virtual void setMaterial(OdDbStub* pMaterialId) = 0;

  /** Description:
    Sets the *transparency* for this object.
    Atguments:
    transparency (I) OdCmTransparency object.
  */
  virtual void setTransparency(const OdCmTransparency &transparency) = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGiLayerTraits object pointers.
*/
typedef OdSmartPtr<OdGiLayerTraits> OdGiLayerTraitsPtr;


/** Description:
    This class defines the interface to *linetype* traits for the vectorization process.
    Library Gi
    {group:OdGi_Classes} 
*/
class FIRSTDLL_EXPORT OdGiLinetypeTraits : public OdGiDrawableTraits
{
public:
  ODRX_DECLARE_MEMBERS(OdGiLinetypeTraits);

  // returned via subSetAttributes()
  
  enum
  {
    kByBlock    = (OdGiDrawable::kLastFlag << 1),
    kByLayer    = (OdGiDrawable::kLastFlag << 2),
    kContinuous = (OdGiDrawable::kLastFlag << 3),
    // Teigha(R) for .dgn files specific
    kScalability= (OdGiDrawable::kLastFlag << 4),
    kDgLinetype = (OdGiDrawable::kLastFlag << 5),
    //
    kGiLinetypeFlagMax = kDgLinetype
  };

  /** Description:
    Returns the length of the linetype pattern for this LinetypeTraits object.
    
    Remarks:
    patternLength is the total length in drawing units of all the *dashes* in this Linetype pattern.
  */
  virtual double patternLength() const = 0;
  
  /** Description:
    Returns an array of *dashes* for this LinetypeTraits object.
    Arguments:
    dashes (O) Receives the array of *dashes*.
  */
  virtual void dashes(OdArray<OdGiLinetypeDash>& dashes) = 0;

  /** Description:
    Returns the *scale* for this LinetypeTraits object.
  */
  virtual double scale() const = 0;
  
  /** Description:
    Sets the *dashes* for this LinetypeTraits object.
    Arguments:
    dashes (I) Array of *dashes*.
  */
  virtual void setDashes(const OdArray<OdGiLinetypeDash>& dashes) = 0;
  /** Description:
    Sets the *scale* for this LinetypeTraits object.
  */
  virtual void setScale(double scale) = 0;
  /** Description:
    Sets the length of the linetype pattern for this LinetypeTraits object.
    
    Arguments:
    patternLength (I) Pattern length.
    
    Remarks:
    patternLength is the total length in drawing units of all the *dashes* in this Linetype pattern.
  */
  virtual void setPatternLength(double patternLength) = 0;
};
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGiLinetypeTraits object pointers.
*/
typedef OdSmartPtr<OdGiLinetypeTraits> OdGiLinetypeTraitsPtr;

/** Description:
    This class defines the interface to text style traits for the vectorization process.
    Library: TD_Gi
    {group:OdGi_Classes} 
*/
class FIRSTDLL_EXPORT OdGiTextStyleTraits : public  OdGiDrawableTraits
{
public:
  ODRX_DECLARE_MEMBERS(OdGiTextStyleTraits);

  /** Description:
    Returns the text style of this TextStyleTraits object.
    Arguments:
    giTextStyle (O) Receives the text style.
  */
  virtual void textStyle(OdGiTextStyle& giTextStyle) const = 0;

  /** Description:
    Sets the text style of this TextStyleTraits object.
    Arguments:
    giTextStyle (I) Text style.
  */
  virtual void setTextStyle(const OdGiTextStyle& giTextStyle) = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGiTextStyleTraits object pointers.
*/
typedef OdSmartPtr<OdGiTextStyleTraits> OdGiTextStyleTraitsPtr;

#include "../TD_PackPop.h"

#endif
