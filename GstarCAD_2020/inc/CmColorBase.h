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
#ifndef ODA_CMBASE_COLOR
#define ODA_CMBASE_COLOR

#include "OdString.h"
#include "Gi/Gi.h"

#include "TD_PackPush.h"

class OdDbDwgFiler;

/** Description:
    This class implements EntityColor objects, which represent the colors of OdDbEntity objects.

    Remarks:
    EntityColor objects may specify any of the following *color* methods:

    @table
    Name         Value    Description
    kByLayer     0xC0     *Color* of the *layer* on which it resides.
    kByBlock     0xC1     *Color* of the block reference in which it is contained.
    kByColor     0xC2     *Color* specified by RGB value.
    kByACI       0xC3     *Color* specified by an index (ACI) into a *color* table.
    kByPen       0xC4     *Color* specified by an index into a pen *color* table.
    kForeground  0xC5     Editor foreground *color*.
    kByDgnIndex  0xC7     *Color* specified by an index into a *color* table for dgn.
    kNone        0xC8     No *color*.

    An entity has no *color* from the time it is first instantiated until it is assigned one
    or added to a *database*.
    
    Colors are stored in the m_RGBM member of the EntityColor object, defined as follows:

              typedef OdUInt32 RGBM;
              RGBM   m_RGBM
    
    Colors are stored in m_RGBM in the two following methods:
    
    @table
    Byte      Description
    0         Blue component.
    1         Green component.
    2         Red component.
    high      *Color* Method.
    
    @table
    Byte      Description
    0-1       ACI Signed.
    2         Not used.
    high      *Color* Method.
    
    {group:OdCm_Classes}
*/
class FIRSTDLL_EXPORT OdCmEntityColor
{
public:
  ODRX_HEAP_OPERATORS();
  enum Color
  {
    kRed,
    kGreen,
    kBlue
  };
  
  enum ColorMethod
  {
    kByLayer    = 0xC0,   // *Color* of the *layer* on which it resides.
    kByBlock    = 0xC1,   // *Color* of the block reference in which it is contained.
    kByColor    = 0xC2,   // *Color* specified by RGB value.
    kByACI      = 0xC3,   // *Color* specified by an index (ACI) into a *color* table.
    kByPen      = 0xC4,   // *Color* specified by an index into a pen *color* table.
    kForeground = 0xC5,   // Editor foreground *color*.
    kLayerOff   = 0xC6,   // Gcad(Add)
    kLayerFrozen= 0xC7,   // Gcad(Add)
    kNone       = 0xC8,    // No *color*.
    kByDgnIndex = 0xC9,   // *Color* specified by an index into a *color* table for dgn.
  };
  
  enum ACIcolorMethod
  {
    kACIbyBlock     = 0,    // ByBlock.
    kACIforeground  = 7,    // Editor foreground *color*.
    kACIbyLayer     = 256,  // ByLayer.

    kACIclear       = 0,    // Clear.

    kACIRed         = 1,    // Red.
    kACIYellow      = 2,    // Yellow.
    kACIGreen       = 3,    // Green.
    kACICyan        = 4,    // Cyan.
    kACIBlue        = 5,    // Blue.
    kACIMagenta     = 6,    // Magenta.
    kACIWhite       = 7,    // White.

    kACIstandard    = 7,    
    kACImaximum     = 255,
    kACInone        = 257,  // None
    kACIminimum     = -255,
    kACIfrozenLayer = -32700, // Gcad(Add)
  };
  
  typedef OdUInt32 RGBM;
  
  /** Arguments:
    colorMethod (I) *Color* *method*.
    red (I) Red component.
    green (I) Green component.
    blue (I) Blue component.
    
    Remarks:
    Default ColorMethod is kByColor. 
  */
  OdCmEntityColor() : m_RGBM(0) { setColorMethod(kByColor); }
  OdCmEntityColor(
    const OdCmEntityColor & color) : m_RGBM(color.m_RGBM) { }
  OdCmEntityColor(
    const ColorMethod colorMethod) : m_RGBM(0) { setColorMethod(colorMethod); }
  OdCmEntityColor(
    const OdUInt8 red,
    const OdUInt8 green,
    const OdUInt8 blue)
  {
    setColorMethod(kByColor);
    setRGB(red, green, blue);
  }

  OdCmEntityColor& operator =(
    const OdCmEntityColor& color)
  {
    m_RGBM = color.m_RGBM;
    return *this;
  }

  bool operator ==(
    const OdCmEntityColor& color) const
  {
    return m_RGBM == color.m_RGBM;
  }
  
  bool operator !=(
    const OdCmEntityColor& color) const
  {
    return m_RGBM != color.m_RGBM;
  }

  /** Description
    Sets the *color* *method* for this EntityColor object.

    Arguments:
    colorMethod (I) *Color* *method*.

    Remarks:
    colorMethod must be one of the following: 
    
    @table
    Name         Value    Description
    kByLayer     0xC0     *Color* of the *layer* on which it resides.
    kByBlock     0xC1     *Color* of the block reference in which it is contained.
    kByColor     0xC2     *Color* specified by RGB value.
    kByACI       0xC3     *Color* specified by an index (ACI) into a *color* table.
    kByPen       0xC4     *Color* specified by an index into a pen *color* table.
    kForeground  0xC5     *Color* of editor foreground.
    kLayerFrozen 0xC7
    kNone        0xC8     No *color*.
    kByDgnIndex  0xC9     *Color* specified by an index into a *color* table for dgn.


    An entity has no *color* from the time it is first instantiated until it is assigned one
    or added to a *database*.
  */
  OdResult setColorMethod(
    const ColorMethod colorMethod) { return OdCmEntityColor::setColorMethod(&m_RGBM, colorMethod); }

  /** Description
    Returns the *color* *method* for this EntityColor object.

    Remarks:
    colorMethodof the following: one of the following:
     
    @table
    Name         Value    Description
    kByLayer     0xC0     *Color* of the *layer* on which it resides.
    kByBlock     0xC1     *Color* of the block reference in which it is contained.
    kByColor     0xC2     *Color* specified by RGB value.
    kByACI       0xC3     *Color* specified by an index (ACI) into a *color* table.
    kByPen       0xC4     *Color* specified by an index into a pen *color* table.
    kForeground  0xC5     *Color* of editor foreground.
    kLayerFrozen 0xC7
    kNone        0xC8     No *color*.
    kByDgnIndex  0xC9     *Color* specified by an index into a *color* table for dgn.

    An entity has no *color* from the time it is first instantiated until it is assigned one
    or added to a *database*.
  */
  ColorMethod colorMethod() const
  {
    return colorMethod(&m_RGBM);
  } 
  
  /** Description:
    Sets the *color* value and *color* *method* for this EntityColor object.

    Arguments:
    color (I) *Color* value and *color* *method*.
    
    Remarks:
    *Color* value and *color* *method* are packed as follows:
    
    @table
    Byte      Description
    0         Blue component.
    1         Green component.
    2         Red component.
    high      *Color* Method.
    
    See Also:
    OdCmEntityColor::ColorMethod
  */
  OdResult setColor(
    OdUInt32 color);

  /** Description:
    Returns the *color* value and *color* *method* for this EntityColor object.

    Remarks:
    *Color* value and *color* *method* are packed as follows:
    
    @table
    Byte      Description
    0         Blue component.
    1         Green component.
    2         Red component.
    high      *Color* Method.
    
    See Also:
    ColorMethod
  */
  OdUInt32 color() const { return m_RGBM; } 
  
  /** Description:
    Sets the *color* index (ACI) for this EntityColor object.

    Arguments:
    colorIndex (I) *Color* index.
    
    Remarks:
    colorIndex must be one of the following:
    
    @table
    Name              Value   Description
    kACIbyBlock       0       ByBlock.
    kACIforeground    7       Foreground *color*.
    kACIbyLayer       256     ByLayer. 
    kACIRed           1       Red. 
    kACIYellow        2       Yellow. 
    kACIGreen         3       Green. 
    kACICyan          4       Cyan. 
    kACIBlue          5       Blue. 
    kACIMagenta       6       Magenta. 
    ..                8-255   Defined by display device.
    kACInone          257     No *color*.

    An entity has no *color* from the time it is first instantiated until it is assigned one
    or added to a *database*.
  */
  OdResult setColorIndex(
    const OdInt16 colorIndex) { return setColorIndex(&m_RGBM, colorIndex); }

  /** Description:
    Returns the *color* index (ACI) for this EntityColor object.

    Remarks:
    colorIndexof the following: one of the following:
    
    @table
    Name              Value   Description
    kACIbyBlock       0       ByBlock.
    kACIforeground    7       Foreground *color*.
    kACIbyLayer       256     ByLayer. 
    kACIRed           1       Red. 
    kACIYellow        2       Yellow. 
    kACIGreen         3       Green. 
    kACICyan          4       Cyan. 
    kACIBlue          5       Blue. 
    kACIMagenta       6       Magenta. 
    ..                8-255   Defined by display device.
    kACInone          257     No *color*.

    An entity has no *color* from the time it is first instantiated until it is assigned one
    or added to a *database*.
  */
  OdInt16 colorIndex() const { return OdCmEntityColor::colorIndex(&m_RGBM); }
  
  // Gcad(Add) {{

  /** Description:
	Sets the color method to kByLayer and the color value to LayerIndex.

	Arguments:
    layerIndex (I) *Color* value.
  */
  OdResult setLayerIndex(const OdInt16 layerIndex) { return setLayerIndex(&m_RGBM, layerIndex); }

  /** Description:
	Returns the layer index. 
  */
  OdInt16 layerIndex() const { return layerIndex(&m_RGBM); }

  /** Description:
	Sets the color method to kByPen and the color value to penIndex.

	Arguments:
    penIndex (I) *Color* value.
  */
  OdResult setPenIndex(OdUInt16 penIndex) { return setPenIndex(&m_RGBM, penIndex); }

  /** Description:
	Returns the pen index. 
  */
  OdUInt16 penIndex() const { return penIndex(&m_RGBM); }

  // Gcad(Add) }} 
  /** Description:
    Sets the *red*, *green*, and *blue* components for this EntityColor object.
    
    Arguments: 
    red (I) Red component.
    green (I) Green component.
    blue (I) Blue component.
  */
  OdResult setRGB(
    const OdUInt8 red, 
    const OdUInt8 green,
    const OdUInt8 blue)
  {
    return setRGB(&m_RGBM, red, green, blue);
  }    

  /** Description:
    Sets the *red* component for this EntityColor object.
    
    Arguments: 
    red (I) Red component.
  */
  OdResult setRed(
    const OdUInt8 red) { return setRed(&m_RGBM, red); }

  /** Description:
    Sets the *green* component for this EntityColor object.
    
    Arguments: 
    green (I) Green component.
  */
  OdResult setGreen(
    const OdUInt8 green) { return setGreen(&m_RGBM, green); }

  /** Description:
    Sets the *blue* component for this EntityColor object.
    
    Arguments: 
    blue (I) Blue component.
  */
  OdResult setBlue(
    const OdUInt8 blue) { return setBlue(&m_RGBM, blue); }

  /** Description:
    Returns the *red* component for this EntityColor object.
  */
  OdUInt8 red() const { return red(&m_RGBM); }
  
  /** Description:
    Returns the *green* component for this EntityColor object.
  */
  OdUInt8 green() const { return green(&m_RGBM); }

  /** Description:
    Returns the *blue* component for this EntityColor object.
  */
  OdUInt8 blue() const { return blue(&m_RGBM); }
  
  // Method check
  
  /** Description:
    Returns true if and only if the *color* *method* for this EntityColor object is kByColor.
  */
  bool isByColor() const { return isByColor(&m_RGBM); }

  /** Description:
    Returns true if and only if the *color* *method* for this EntityColor object is kByLayer or the
    *color* *method* is kByACI and the ACI is kACIbyLayer.
  */
  bool isByLayer() const { return isByLayer(&m_RGBM); }

  
  /** Description:
    Returns true if and only if the *color* *method* for this EntityColor object is kByBlock or the
    *color* *method* is kByACI and the ACI is kACIbyBlock.
  */
  bool isByBlock() const { return isByBlock(&m_RGBM); }
   

  /** Description:
    Returns true if and only if the *color* *method* for this EntityColor object is kByACI.
    
    Note: isByACI() returns true for ACI values of 0 (ByBlock), 7 (ByForeground), 256 (ByLayer), and 257 (None).
  */
  bool isByACI() const { return isByACI(&m_RGBM); }

  /** Description:
	 Returns true if the color method is kByPen; otherwise, it returns false.
  */
  bool isByPen() const { return isByPen(&m_RGBM); } // Gcad(Add)

  /** Description:
	 Returns true if the color method is kLayerOff; otherwise, it returns false.
  */
  bool isLayerOff() const { return isLayerOff (&m_RGBM); } // Gcad(Add)

  /** Description:
	 Returns true if the color method is kLayerFrozen; otherwise, it returns false.
  */
  bool isLayerFrozen() const { return isLayerFrozen(&m_RGBM); }; // Gcad(Add)

  /** Description:
	 Returns true if the color method is kLayerFrozen or isLayerOff; otherwise, it returns false.
  */
  bool isLayerFrozenOrOff() const { return (isLayerFrozen() || isLayerOff()); } // Gcad(Add)

  /** Description:
    Returns true if and only if the *color* *method* for this EntityColor object is kForeground or the
    *color* *method* is kByACI and the ACI is kACIForeground.
  */
  bool isForeground() const { return isForeground(&m_RGBM); }

  /** Description:
    Returns true if and only if the *color* *method* for this EntityColor object is kByDgnIndex.
  */
  bool isByDgnIndex() const { return isByDgnIndex(&m_RGBM); }

  /** Description:
    Returns true if and only if the *color* *method* for this EntityColor object is kNone or the
    *color* *method* is kByACI and the ACI is kACInone.
  */
  bool isNone() const  { return isNone(&m_RGBM); }
  
  /** Description:
    Returns the TrueColor value of this EntityColor object.
  */
  OdUInt32 trueColor() const;
  
  /** Description:
    Converts the *color* *method* from ACIcolorMethod to ColorMethod. 

    Remarks:
    Returns the ColorMethod value.
    
    Note:
    Assumes the current *color* *method* is ACIcolorMethod.
  */
  OdUInt8 trueColorMethod() const;

  /** Description:
    Sets the *color* of the calling Entity with this EntityColor object.
  */
  OdResult setTrueColor();
  
  /** Description:
    Converts the *color* *method* from ACIcolorMethod to ColorMethod. 

    Note:
    Assumes the current *color* *method* is ACIcolorMethod.
  */
  OdResult setTrueColorMethod();
  
  /**
    Arguments:
    pRGBM (I) Pointer to the m_RGBM member of the EntityColor object.
  */
  static OdResult setColorMethod(
    RGBM* pRGBM, 
    const ColorMethod colorMethod);

  /**
    Arguments:
    pRGBM (I) Pointer to the m_RGBM member of the EntityColor object.
  */
  static ColorMethod colorMethod(
    const RGBM* pRGBM)
  {
    return OdCmEntityColor::ColorMethod((*pRGBM >> 24) & 0xFF);
  }
  
  /**
    Arguments:
    pRGBM (I) Pointer to the m_RGBM member of the EntityColor object.
  */
  static OdResult setColor(
    RGBM* pRGBM, 
    OdUInt32 color);
    
  /**
    Arguments:
    pRGBM (I) Pointer to the m_RGBM member of the EntityColor object.
  */
  static OdUInt32 color(
    const RGBM* pRGBM); 
  
  /**
    Arguments:
    pRGBM (I) Pointer to the m_RGBM member of the EntityColor object.
  */
  static OdResult setColorIndex(
    RGBM* pRGBM, 
    const OdInt16 colorIndex);
    
  /**
    Arguments:
    pRGBM (I) Pointer to the m_RGBM member of the EntityColor object.
  */
  static OdInt16 colorIndex(
    const RGBM* pRGBM);
  static OdResult setLayerIndex( // Gcad(Add)
	RGBM* pRGBM,
	const OdInt16 layerIndex);
  static OdInt16 layerIndex( // Gcad(Add)
	const RGBM* pRGBM);
  
    
  static OdResult setPenIndex( // Gcad(Add)
	RGBM* pRGBM,
	const OdUInt16 penIndex);
  /**
    Arguments:
    pRGBM (I) Pointer to the m_RGBM member of the EntityColor object.
  */
  static OdUInt16 penIndex( // Gcad(Add)
	const RGBM* pRGBM);
  static OdResult setRGB(
    RGBM* pRGBM, 
    const OdUInt8 red, 
    const OdUInt8 green,
    const OdUInt8 blue)
  {
    setColorMethod(pRGBM, kByColor);
    setRed(pRGBM, red);
    setGreen(pRGBM, green);
    setBlue(pRGBM, blue);

	  return Oda::eOk;
  }
    
  /**
    Arguments:
    pRGBM (I) Pointer to the m_RGBM member of the EntityColor object.
  */
  static OdResult setRed(
    RGBM* pRGBM, 
    const OdUInt8 red)
  {
    ODA_ASSERT(colorMethod(pRGBM) == kByColor); 
    *pRGBM &= 0xFF00FFFF;
    *pRGBM |= RGBM(((OdUInt32)red << 16) & 0x00FF0000);
	  return Oda::eOk;
  }
      
  /**
    Arguments:
    pRGBM (I) Pointer to the m_RGBM member of the EntityColor object.
  */
  static OdResult setGreen(
    RGBM* pRGBM, 
    const OdUInt8 green)
  {
    ODA_ASSERT(colorMethod(pRGBM) == kByColor); 
    *pRGBM &= 0xFFFF00FF;
    *pRGBM |= RGBM(((OdUInt32)green << 8) & 0x0000FF00);
	  return Oda::eOk;
  }
    
    
  /**
    Arguments:
    pRGBM (I) Pointer to the m_RGBM member of the EntityColor object.
  */
  static OdResult setBlue(
    RGBM* pRGBM, 
    const OdUInt8 blue)
  {
    ODA_ASSERT(colorMethod(pRGBM) == kByColor); 
    *pRGBM &= 0xFFFFFF00;
    *pRGBM |= RGBM((blue) & 0x000000FF);
	  return Oda::eOk;
  }    
    
  /**
    Arguments:
    pRGBM (I) Pointer to the m_RGBM member of the EntityColor object.
  */
  static OdUInt8 red(
    const RGBM* pRGBM)
  {
    ODA_ASSERT(colorMethod(pRGBM) == kByColor); 
    return OdUInt8((*pRGBM >> 16) & 0xFF);
  }
    
  /**
    Arguments:
    pRGBM (I) Pointer to the m_RGBM member of the EntityColor object.
  */
  static OdUInt8 green(
    const RGBM* pRGBM)
  {
    ODA_ASSERT(colorMethod(pRGBM) == kByColor); 
    return OdUInt8((*pRGBM >> 8) & 0xFF);
  }
    
  /**
    Arguments:
    pRGBM (I) Pointer to the m_RGBM member of the EntityColor object.
  */
  static OdUInt8 blue(
    const RGBM* pRGBM)
  {
    ODA_ASSERT(colorMethod(pRGBM) == kByColor); 
    return OdUInt8(*pRGBM & 0xFF);
  }
    
    
  /**
    Arguments:
    pRGBM (I) Pointer to the m_RGBM member of the EntityColor object.
  */
  static bool isByColor(
    const RGBM* pRGBM) { return colorMethod(pRGBM) == kByColor; }  
    
  /**
    Arguments:
    pRGBM (I) Pointer to the m_RGBM member of the EntityColor object.
  */
  static bool isByLayer(
    const RGBM* pRGBM)
  {
    return (colorMethod(pRGBM) == kByLayer || (colorMethod(pRGBM) == kByACI && indirect(pRGBM) == kACIbyLayer)); 
  }    
    
  /**
    Arguments:
    pRGBM (I) Pointer to the m_RGBM member of the EntityColor object.
  */
  static bool isByBlock(
    const RGBM* pRGBM)
  {
    return (colorMethod(pRGBM) == kByBlock || (colorMethod(pRGBM) == kByACI && indirect(pRGBM) == kACIbyBlock)); 
  }    
    
  /**
    Arguments:
    pRGBM (I) Pointer to the m_RGBM member of the EntityColor object.
  */
  static bool isByACI(
    const RGBM* pRGBM)
  {
    return colorMethod(pRGBM) == kByACI;
  }
  static bool isByPen( // Gcad(Add)
    const RGBM* pRGBM)
  {
    return colorMethod(pRGBM) == kByPen;
  }

  static bool isLayerOff( // Gcad(Add)
    const RGBM* pRGBM)
  {
	return (colorMethod(pRGBM) == kLayerOff) ||
	  (colorMethod(pRGBM) == kByACI &&
	   indirect(pRGBM)<0 &&
	   indirect(pRGBM) != kACIfrozenLayer);
  }
  
  /**
    Arguments:
    pRGBM (I) Pointer to the m_RGBM member of the EntityColor object.
  */
  static bool isForeground(
    const RGBM* pRGBM)
  {
    return (colorMethod(pRGBM) == kForeground || (colorMethod(pRGBM) == kByACI && indirect(pRGBM) == kACIforeground)); 
  }
  static bool isLayerFrozen( // Gcad(Add)
    const RGBM* pRGBM)
  {
	  return (colorMethod(pRGBM) == kLayerFrozen || (colorMethod(pRGBM) == kByACI && indirect(pRGBM) == kACIfrozenLayer)); 
  }
  /**
    Arguments:
    pRGBM (I) Pointer to the m_RGBM member of the EntityColor object.
  */
  static bool isByDgnIndex(
    const RGBM* pRGBM)
  {
    return colorMethod(pRGBM) == kByDgnIndex;
  }
    
  /**
    Arguments:
    pRGBM (I) Pointer to the m_RGBM member of the EntityColor object.
  */
  static bool isNone(
    const RGBM* pRGBM)
  {
    return (colorMethod(pRGBM) == kNone || (colorMethod(pRGBM) == kByACI && indirect(pRGBM) == kACInone)); 
  }
    
    
  /**
    Arguments:
    pRGBM (I) Pointer to the m_RGBM member of the EntityColor object.
  */
  static OdUInt32 trueColor(
    const RGBM* pRGBM);
    
  /**
    Arguments:
    aciColorMethod (I) ACIcolorMethod value.
  */
  static OdUInt8 trueColorMethod(
    const OdInt16 aciColorMethod);
    
  /**
    Arguments:
    pRGBM (I) Pointer to the m_RGBM member of the EntityColor object.
  */
  static OdResult setTrueColor(
    RGBM* pRGBM);
    
  /**
    Arguments:
    pRGBM (I) Pointer to the m_RGBM member of the EntityColor object.
  */
  static OdResult setTrueColorMethod(
    RGBM* pRGBM);
  
  /** Description:
    Returns the *color* value and *color* *method* corresponding to the specified *color* index (ACI).

    Remarks:
    *Color* value and *color* *method* are packed as follows:
    
    @table
    Byte      Description
    0         Blue component.
    1         Green component.
    2         Red component.
    high      *Color* Method.

    See Also:
    OdCmEntityColor::ColorMethod
  */
  static OdUInt32 lookUpRGB(
    const OdUInt8 colorIndex);
  
  /** Description:
    Returns the *color* index (ACI) corresponding to the specified *red*, *green*, and *blue* components.

    Arguments:
    red (I) Red component.
    green (I) Green component.
    blue (I( Blue component.
  */
  static OdUInt8 lookUpACI(
    const OdUInt8 red, 
    const OdUInt8 green,
    const OdUInt8 blue);
  
protected:
  /* {Secret} */
  static OdInt16 indirect(
    const RGBM* pRGBM) 
  {
    ODA_ASSERT(colorMethod(pRGBM) != kByColor); 
    return OdInt16((*pRGBM) & 0x0000FFFF);
  }

  /* {Secret} */
  static OdResult setIndirect(
    RGBM* pRGBM, 
    OdInt16 indirect)
  {
    ODA_ASSERT(colorMethod(pRGBM) != kByColor); 
    *pRGBM = ((*pRGBM & 0xFF000000) | (OdUInt32(indirect) & 0x0000FFFF));
    return Oda::eOk;
  }
      
  /* {Secret} */
  OdInt16 indirect() const { return indirect(&m_RGBM); }

  /* {Secret} */
  OdResult setIndirect(OdInt16 indirect) { return setIndirect(&m_RGBM, indirect); }

  RGBM m_RGBM;
  
public:
  /** Description:
      Maps index colors to their RGB representations.
  */
  FIRSTDLL_EXPORT_STATIC static  OdUInt8 mLUT[256][3]; 
};


/** Description:
    This class is a virtual interface for classes that represent colors in Teigha as RGB, ACI, or named colors.
    
    Remarks:
    
    See Also:
    OdCmEntityColor
    
    {group:OdCm_Classes}
*/
class FIRSTDLL_EXPORT OdCmColorBase
{
public:
  ODRX_HEAP_OPERATORS();
  virtual ~OdCmColorBase() {}

  /** Description
    Returns the *color* *method* for this object.

    Remarks:
    colorMethodof the following: one of the following:
     
    @table
    Name         Value    Description
    kByLayer     0xC0     *Color* of the *layer* on which it resides.
    kByBlock     0xC1     *Color* of the block reference in which it is contained.
    kByColor     0xC2     *Color* specified by RGB value.
    kByACI       0xC3     *Color* specified by an index (ACI) into a *color* table.
    kByPen       0xC4     *Color* specified by an index into a pen *color* table.
    kForeground  0xC5     *Color* of editor foreground.
    kByDgnIndex  0xC7     *Color* specified by an index into a *color* table for dgn.
    kNone        0xC8     No *color*.

    An entity has no *color* from the time it is first instantiated until it is assigned one
    or added to a *database*.
    
    Note:
    Use of this *method* by third-party applications is neither supported nor recommended.
  */
  virtual OdCmEntityColor::ColorMethod colorMethod() const = 0;
  
  /** Description
    Sets the *color* *method* for this object.

    Arguments:
    colorMethod (I) *Color* *method*.

    Remarks:
    colorMethod must be one of the following: 
    
    @table
    Name                          Value    Description
    OdCmEntityColor::kByLayer     0xC0     *Color* of the *layer* on which it resides.
    OdCmEntityColor::kByBlock     0xC1     *Color* of the block reference in which it is contained.
    OdCmEntityColor::kByColor     0xC2     *Color* specified by RGB value.
    OdCmEntityColor::kByACI       0xC3     *Color* specified by an index (ACI) into a *color* table.
    OdCmEntityColor::kByPen       0xC4     *Color* specified by an index into a pen *color* table.
    OdCmEntityColor::kForeground  0xC5     *Color* of editor foreground.
    OdCmEntityColor::kByDgnIndex  0xC7     *Color* specified by an index into a *color* table for dgn.
    OdCmEntityColor::kNone        0xC8     No *color*.

    An entity has no *color* from the time it is first instantiated until it is assigned one
    or added to a *database*.

    Note:
    Use of this *method* by third-party applications is neither supported nor recommended.
  */
  virtual OdResult  setColorMethod(
    OdCmEntityColor::ColorMethod colorMethod) = 0;

  /** Description:
    Returns true if and only if the *color* *method* for this object is kByColor.
  */
  virtual bool isByColor() const = 0;
    
  /** Description:
    Returns true if and only if the *color* *method* for this object is kByLayer or the
    *color* *method* is kByACI and the ACI is kACIbyLayer.
  */
  virtual bool isByLayer() const = 0;
  
  /** Description:
    Returns true if and only if the *color* *method* for this object is kByBlock or the
    *color* *method* is kByACI and the ACI is kACIbyBlock.
  */
  virtual bool isByBlock() const = 0;

  /** Description:
    Returns true if and only if the *color* *method* for this object is kByACI.

    Note: isByACI() returns true for ACI values of 0 (ByBlock), 7 (ByForeground), 256 (ByLayer), and 257 (None).
  */
  virtual bool isByACI() const = 0;

  /** Description:
    Returns true if and only if the *color* *method* for this object is kForeground or the
    *color* *method* is kByACI and the ACI is kACIForeground.
  */
  virtual bool isForeground()   const = 0;

  /** Description:
    Returns true if and only if the *color* *method* for this object is kByDgnIndex.
  */
  virtual bool isByDgnIndex()   const = 0;

  /** Description:
    Returns the *color* value and *color* *method* for this object.

    Remarks:
    *Color* value and *color* *method* are packed as follows:
    
    @table
    Byte      Description
    0         Blue component.
    1         Green component.
    2         Red component.
    high      *Color* Method.
    
    See Also:
    OdCmEntityColor::ColorMethod
    
  */
  virtual OdUInt32  color() const = 0;
  
  /** Description:
    Sets the *color* value and *color* *method* for this object.

    Arguments:
    color (I) *Color* value and *color* *method*.
    
    Remarks:
    *Color* value and *color* *method* are packed as follows:
    
    @table
    Byte      Description
    0         Blue component.
    1         Green component.
    2         Red component.
    high      *Color* Method.
    
    See Also:
    OdCmEntityColor::ColorMethod
  */
  virtual OdResult setColor(
    OdUInt32 color) = 0;

  /** Description:
    Sets the *red*, *green*, and *blue* components for this object.

    Arguments: 
    red (I) Red component.
    green (I) Green component.
    blue (I( Blue component.
  */
  virtual OdResult setRGB(
    OdUInt8 red, 
    OdUInt8 green, 
    OdUInt8 blue) = 0;
                           
  /** Description:
    Sets the *red* component for this object.
    
    Arguments: 
    red (I) Red component.
  */
  virtual OdResult setRed(
    OdUInt8 red) = 0;
    
  /** Description:
    Sets the *green* component for this object.
    
    Arguments: 
    green (I) Green component.
  */
  virtual OdResult setGreen(
    OdUInt8 green) = 0;
    
  /** Description:
    Sets the *blue* component for this object.
    
    Arguments: 
    blue (I) Blue component.
  */
  virtual OdResult setBlue(
    OdUInt8 blue) = 0;
    
  /** Description:
    Returns the *red* component for this object.
  */
  virtual OdUInt8 red() const = 0;
   /** Description:
    Returns the *green* component for this object.
  */
  virtual OdUInt8 green() const = 0;

  /** Description:
    Returns the *blue* component for this object.
  */
  virtual OdUInt8 blue() const = 0;

  /** Description:
    Returns the *color* index (ACI) for this object.

    Remarks:
    colorIndexof the following: one of the following:
    
    @table
    Name              Value   Description
    kACIbyBlock       0       ByBlock.
    kACIforeground    7       Foreground *color*.
    kACIbyLayer       256     ByLayer. 
    kACIRed           1       Red. 
    kACIYellow        2       Yellow. 
    kACIGreen         3       Green. 
    kACICyan          4       Cyan. 
    kACIBlue          5       Blue. 
    kACIMagenta       6       Magenta. 
    ..                8-255   Defined by display device.
    kACInone          257     No *color*.

    An entity has no *color* from the time it is first instantiated until it is assigned one
    or added to a *database*.
  */
  virtual OdUInt16  colorIndex() const = 0;

  /** Description:
    Sets the *color* index (ACI) for this object.

    Arguments:
    colorIndex (I) *Color* index.
    
    Remarks:
    colorIndex must be one of the following:
    
    @table
    Name                               Value   Description
    OdCmEntityColor::kACIbyBlock       0       ByBlock.
    OdCmEntityColor::kACIforeground    7       Foreground *color*.
    OdCmEntityColor::kACIbyLayer       256     ByLayer. 
    OdCmEntityColor::kACIRed           1       Red. 
    OdCmEntityColor::kACIYellow        2       Yellow. 
    OdCmEntityColor::kACIGreen         3       Green. 
    OdCmEntityColor::kACICyan          4       Cyan. 
    OdCmEntityColor::kACIBlue          5       Blue. 
    OdCmEntityColor::kACIMagenta       6       Magenta. 
    ..                                 8-255   Defined by display device.
    OdCmEntityColor::kACInone          257     No *color*.

    An entity has no *color* from the time it is first instantiated until it is assigned one
    or added to a *database*.
  */
  virtual OdResult setColorIndex(
    OdUInt16 colorIndex) = 0;

  /** Description:
    Sets the *color* name and book name for this object.
    Remarks:
    Returns true if and only if successful.

    Note:
    Either bookName and colorName may be empty strings, but not both.
    
    Arguments:
    colorName (I) Color name.
    bookName (I) Book name.
  */
  virtual OdResult setNames(
    const OdChar* colorName,
    const OdChar* bookName = NULL) = 0;
    
  /** Description:
    Returns the *color* name for this object.
  */
  virtual const OdChar* colorName() const = 0;

  /** Description:
    Returns the book name for this object.
  */
  virtual const OdChar* bookName() const = 0;
  
  /** Description:
    Returns the display *color* name for this object.
    
    Remarks:
    For named colors, this is the same as colorName(). For unnamed colors, it is an 'appropriate' name.
  */
  virtual const OdChar* colorNameForDisplay() = 0;

  /**
    Returns true if the kHasColorName bit is set; otherwise, it returns false.
  */
  virtual bool hasColorName(void) const = 0;

  /** Description:
    Returns true if the kHasBookName bit is set; otherwise, it returns false.
  */
  virtual bool hasBookName(void) const = 0;

  /** Description:
    Returns true if the color method is kByPen; otherwise, it returns false.

    Remarks:
	This method is intended for internal use only.
  */
  virtual bool isByPen(void) const = 0;

  /** Description:
    Returns the pen index.

	Remarks:
	This method is intended for internal use only.
  */
  virtual OdUInt16 penIndex(void) const = 0;

  /** Description:
    Sets the pen index.

    Remarks:
    This method is intended for internal use only.
  */
  virtual OdResult setPenIndex(OdUInt16 penIndex) = 0;
};

/** Description:
    This class implements Transparency objects, which provide *transparency* information about OdGiDrawable objects.
    {group:OdCm_Classes}
*/
class OdCmTransparency 
{
public:
  ODRX_HEAP_OPERATORS();
  
  enum transparencyMethod 
  {
    kByLayer    = 0, // Use the setting for the *layer*.
    kByBlock    = 1, // Use the setting for the block.
    kByAlpha    = 2, // Use the *alpha* value in this object.     
    kErrorValue = 3  //  
  };
  enum
  {
    kTransparencyByLayer = (unsigned long)kByLayer,
    kTransparencyByBlock = (unsigned long)kByBlock,
    kTransparencySolid = ((unsigned long)(kByAlpha | (0xff << 24))),
    kTransparencyClear = (unsigned long)kByAlpha
  };
  /**
    Remarks:
    The default *method* is kByLayer.
  */
  OdCmTransparency() { setMethod(kByLayer); }
  OdCmTransparency(OdUInt8 alpha) { setAlpha(alpha); }
  OdCmTransparency(double alphaPercent) { setAlphaPercent(alphaPercent); }
  OdCmTransparency(
    const OdCmTransparency& transparency) { m_AM = transparency.m_AM; }
  ~OdCmTransparency() {}
  
  OdCmTransparency& operator=(
    const OdCmTransparency& transparency) { m_AM = transparency.m_AM; return *this; }

  bool operator==(
    const OdCmTransparency& transparency) const { return (m_AM == transparency.m_AM); }
  bool operator!=(
    const OdCmTransparency& transparency) const { return (m_AM != transparency.m_AM); }
  
  /** Description:
    Sets the *alpha*, and sets the *transparency* *method* to kByAlpha, for this Transparency object.
    
    Remarks:
    *alpha* == 0 means totally transparent. *alpha* == 255 means totally opaque.
    Arguments:
    alpha (I) Alpha.
  */
  void setAlpha(
    OdUInt8 alpha)
  {
    m_AM = ((OdUInt32)kByAlpha << 24) | alpha;
  }

  /** Description:
    Sets the *alpha* percent, and sets the *transparency* *method* to kByAlpha, for this Transparency object.
    
    Remarks:
    *alphaPercent* == 0.0 means totally transparent. *alphaPercent* == 1.0 means totally opaque.
    Arguments:
    alphaPercent (I) Alpha percent.
  */
  void setAlphaPercent(
    double alphaPercent)
  {
    if (alphaPercent < 0.0)
      setAlpha(0);
    else if (alphaPercent > 1.0)
      setAlpha(0xFF);
    else
      setAlpha((OdUInt8)(alphaPercent * 255));
  }

  /** Description:
    Returns the *transparency* *method* for this Transparency object.
    
    Remarks:
    transparencyMethod() returns one of the following:
    
    @table
    Name        Value   Description
    kByLayer    0       Use the setting for the *layer*.
    kByBlock    1       Use the setting for the block.
    kByAlpha    2       Use the *alpha* value in this object.
  */
  transparencyMethod method() const
  {
    return transparencyMethod(OdUInt8(m_AM >> 24));
  }

  /** Description:
    Sets the *transparency* *method* for this Transparency object.
    
    Remarks:
    method (I) Transparency *method*.
    
    method must be one of the following:
    
    @table
    Name        Value   Description
    kByLayer    0       Use the setting for the *layer*.
    kByBlock    1       Use the setting for the block.
    kByAlpha    2       Use the *alpha* value in this object.
  */
  void setMethod(
    transparencyMethod method)
  {
    m_AM = (OdUInt32)method << 24;
  }

  /** Description:
    Returns alpha value in [0 - 255] range.
  */
  OdUInt8 alpha() const
  {
    ODA_ASSERT(method() == kByAlpha);
    return OdUInt8(m_AM);
  }

  /** Description:
    Returns alpha value in [0.0 - 1.0] range.
  */
  double alphaPercent() const
  {
    return (double)alpha() / 255;
  }

  /** Description:
    Returns true if and only if the *transparency* *method* for this Transparency object is kByAlpha.
  */
  bool isByAlpha() const { return (method() == kByAlpha); }

  /** Description:
    Returns true if and only if the *transparency* *method* for this Transparency object is kByBlock.
  */
  bool isByBlock() const { return (method() == kByBlock); }
  
  /** Description:
    Returns true if and only if the *transparency* *method* for this Transparency object is kByLayer.
  */
  bool isByLayer() const { return (method() == kByLayer); }
  
  /** Description:
    Returns true if and only if the *transparency* *method* for this Transparency object is kByALpha and
    *alpha* == 0.
  */
  bool isClear() const   { return (method() == kByAlpha) && (alpha() == 0);}
  
  /** Description:
    Returns true if and only if the *transparency* *method* for this Transparency object is kByALpha and
    *alpha* == 255.
  */
  bool isSolid() const   { return (method() == kByAlpha) && (alpha() == 255);}
  
  /** Description:
    Returns the transparency converted to an integer.
    
    Remarks:
    This is useful when storing transparency values in a .dwg file.
  */
  OdUInt32  serializeOut() const { return m_AM; }
  /** Description:
    Converts the specified integer to a *transparency* value, and sets the value of this Transparency object from it.

    Arguments:
    transparency (I) Transparency.
    
    Remarks:
    This is useful when reading transparency values from a .dwg file.
  */
  void  serializeIn(
    OdUInt32 transparency) { m_AM = transparency; }

  /** 
    Description:
    Reads the .dwg file format data of this object from the specified file.
       
    Arguments:   
    pFiler (I) Pointer to the filer from which the data are to be read.
    
  */
  void dwgIn(
    OdDbDwgFiler* pFiler);

  /** 
    Description:
    Writes the .dwg file format data of this object to the specified filer. 
    
    Arguments:
    pFiler (I) Pointer to the filer to which the data are to be written.
  */
  void dwgOut(
    OdDbDwgFiler* pFiler) const;

private: 
  OdUInt32 m_AM;
};

// Gcad(Add)
namespace OdCm
{
    enum DialogTabs
    {   
        //these flags can be OR-ed 
        kACITab = 1,
        kTrueColorTab = 2,
        kColorBookTab = 4,
    };

    enum ACIColors
    {   
        kACIByBlock     = 0,
        kACIRed         = 1,
        kACIYellow      = 2,
        kACIGreen       = 3,
        kACICyan        = 4,
        kACIBlue        = 5,
        kACIMagenta     = 6,
        kACIForeground  = 7,
        kACIByLayer     = 256,
    };
}
#include "TD_PackPop.h"

#endif //ODA_CMBASE_COLOR