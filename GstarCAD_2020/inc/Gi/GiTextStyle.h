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

#ifndef __ODGITEXTSTYLE_H__
#define __ODGITEXTSTYLE_H__

#include "../TD_PackPush.h"

#include "../OdCodePage.h"
#include "../OdFont.h"
#include "../Gi/TtfDescriptor.h"
#include "../DbBaseDatabase.h"

class OdGiWorldDraw;
class OdGiTextStyleImpl;
class OdString;
class OdGePoint2d;


/** Description:
    This class provides an interface to the display attributes of text.

    Remarks:
    This class is used as an argument to OdGiGeometry::text().

    Library:
    TD_Gi

    {group:OdGi_Classes}
*/
class FIRSTDLL_EXPORT OdGiTextStyle
{
  // Members
  //
protected:
  // : public OdTtfDescriptor                         // MKU 14.02.2003

  OdTtfDescriptor       m_ttfDescriptor;

  mutable OdFontPtr     m_pFont;
  mutable OdFontPtr     m_pBigFont;

  mutable OdString      m_sFontPath;
  mutable OdString      m_sBigFontPath;

  OdString              m_sBigfontFile;
  double                m_dTextSize;
  double                m_dXScale;
  double                m_dObliquingAngle;
  double                m_dTrackingPercent;
  mutable OdUInt16      m_flags;
  mutable OdCodePageId  m_Codepage;

  OdString              m_StyleName;

  double                m_dIntercharSpacing;

public:
  enum
  {
    kShape       = 0x01,
    kUpsideDown  = 0x02,
    kVertical    = 0x04,
    kUnderlined  = 0x08,
    kOverlined   = 0x10,
    kShxFont     = 0x20,
    kPreLoaded   = 0x40,
    kBackward    = 0x80,
    kShapeLoaded = 0x100,
    kStriked     = 0x200,
    kUseIntercharSpacing   = 0x400,
    kFixedIntercharSpacing = 0x800
  };

  /** Description:
    Controls if the text *font* file for this TextStyle marked as loaded.

    Arguments:
    shapeLoaded (I) Controls shape loaded.
  */
  /** { Secret } */
  void setShapeLoaded(
    bool shapeLoaded) const;

  /** Description:
    Returns true if and only if the text *font* file for this TextStyle marked as loaded.
  */
  /** { Secret } */
  bool isShapeLoaded() const { return GETBIT(m_flags, kShapeLoaded); }

  OdGiTextStyle();
  OdGiTextStyle(const OdFont *pFont);
  ~OdGiTextStyle();

  /** Description:
    Sets the parameters of this TextStyle object according to its parameters.

    Arguments:
    fontName (I) Font filename.
    bigFontName (I) BigFont filename.
    textSize (I) Fixed text size.
    xScale (I) X-scale (width) factor of text.
    obliquingAngle (I) Obliquing angle of text.
    trackingPercent (I) Tracking percent of text.
    isBackward (I) Controls backwards drawing of text.
    isUpsideDown (I) Controls upside down drawing of text.
    isVertical (I) Controls vertical drawing of text.
    isOverlined (I) Controls overlined drawing of text.
    isUnderlined (I) Controls overlined drawing of text.

    Remarks:
    obliquingAngle has a domain of ?.48335 radians (?5?. Negative angles will have Oda2PI added to them.

    Note:
    All angles are expressed in radians.
  */
  void set(
    const OdChar * fontName,
    const OdChar *  bigFontName,
    const double textSize,
    const double xScale,
    const double obliquingAngle,
    const double trackingPercent,
    const bool isBackward,
    const bool isUpsideDown,
    const bool isVertical,
    const bool isOverlined,
    const bool isUnderlined);

  /** Description:
    Loads the *font* file(s) associated with this TextStyle.

    Arguments:
    pDb (I) Pointer to the *database* whose OdDbHostAppServices object will be used.

    Remarks:
    This function is run after a call to setFileName() or setBigFontFileName(), and
    must be called after loading a True Type *font* (TTF).
  */
  virtual int loadStyleRec(
    OdDbBaseDatabase* pDb = NULL) const;

  /** Description:
    Returns the fully qualified *font* file path associated with this TextStyle.

    Arguments:
    pDb (I) Pointer to the *database* whose OdDbHostAppServices object will be used.

  */
  OdString getFontFilePath(
    OdDbBaseDatabase* pDb) const;

	virtual const OdChar* fileName() const;

  /** Description:
    Returns the fully qualified BigFont file path associated with this TextStyle.

    Arguments:
    pDb (I) Pointer to the *database* whose OdDbHostAppServices object will be used.

  */
  const OdChar * getBigFontFilePath(
    OdDbBaseDatabase* pDb) const;

  /** Description:
    Sets the fully qualified *font* file path associated with this TextStyle.

    Arguments:
    fontFilePath (I) Font file path.

    Remarks:
    loadStyleRec() should be called after calling this function:
  */
  void setFontFilePath(
    const OdChar * fontFilePath){m_sFontPath = fontFilePath;}

  /** Description:
    Sets the fully qualified BigFont file path associated with this TextStyle.

    Arguments:
    bigFontFilePath (I) BigFont file path.

    Remarks:
    loadStyleRec() should be called after calling this function:
  */
  void setBigFontFilePath(
    const OdChar * bigFontFilePath){m_sBigFontPath = bigFontFilePath;}

  /** Description:
    Sets the fixed text size for this TextStyle.

    Arguments:
    textSize (I) Fixed text size.
  */
  void setTextSize(
    double textSize);

  /** Description:
    Sets the X-scale (width) factor for this TextStyle.

    Arguments:
    xScale (I) X-scale factor.
  */
  void setXScale(
    double xScale);

  /** Description:
    Sets the obliquing angle for this TextStyle.

    Arguments:
    obliquingAngle (I) Obliquing angle.

    Remarks:
    obliquingAngle has a domain of ?.48335 radians (?5?. Negative angles will have Oda2PI added to them.

    Note:
    All angles are expressed in radians.
  */
  void setObliquingAngle(double obliquingAngle);

  /** Description:
    Sets the tracking percent for this TextStyle.

    Arguments:
    trackingPercent (I) TrackingPercent [0.75, 4.0].

    Remarks:
    Tracking percent is a multiplier for the spacing between characters as defined in the *font* file.

  */
  void setTrackingPercent(
    double trackingPercent);

  /** Description:
    Controls the backwards drawing of text with this TextStyle.

    Arguments:
    isBackwards (I) Controls backwards drawing.
  */
  void setBackward(
    bool isBackward);

  /** Description:
    Controls the upside down drawing of text with this TextStyle.

    Arguments:
    isUpsideDown (I) Controls upside down drawing.
  */
  void setUpsideDown(
    bool isUpsideDown);

  /** Description:
    Controls the vertical drawing of text with this TextStyle.

    Arguments:
    isVertical (I) Controls vertical drawing.
  */
  void setVertical(
    bool isVertical);

  /** Description:
    Controls the underlined drawing of text with this TextStyle.

    Arguments:
    underlined (I) Controls underlined drawing.
  */
  void setUnderlined(
    bool isUnderlined);

  /** Description:
    Controls the overlined drawing of text with this TextStyle.

    Arguments:
    overlined (I) Controls overlined drawing.
  */
  void setOverlined(
    bool isOverlined);

  /** Description:
    Controls the strike drawing of text with this TextStyle.

    Arguments:
    overlined (I) Controls strike drawing.
  */
  void setStriked(
    bool isStriked);

  /** { Secret } */
  void setPreLoaded(bool value) const;

  /** { Secret } */
  void setShxFont(bool value) const;

  /** Description:
    Sets the name of the *font* file associated with this TextStyle.

    Arguments:
    fontFileName (I) Filename.
  */
  void setFileName(
    const OdChar * fontFileName);
    
  /** Description:
    Sets the name of the BitFont file associated with this TextStyle.

    Arguments:
    bigFontFileName (I) Filename.
  */
  void setBigFontFileName(
    const OdChar * bigFontFileName);

  /** Description:
    Returns true if and only if text is drawn backwards with this TextStyle.
  */
  bool isBackward() const   { return GETBIT(m_flags, kBackward);  }

  /** Description:
    Returns true if and only if text is drawn upside down with this TextStyle.
  */
  bool isUpsideDown() const { return GETBIT(m_flags, kUpsideDown);}

  /** Description:
    Returns true if and only if text is drawn vertical with this TextStyle.
  */
  bool isVertical() const   { return GETBIT(m_flags, kVertical);  }

  /** Description:
    Returns true if and only if text is drawn underlined with this TextStyle.
  */
  bool isUnderlined() const { return GETBIT(m_flags, kUnderlined);}

  /** Description:
    Returns true if and only if text is drawn overlined with this TextStyle.
  */
  bool isOverlined() const  { return GETBIT(m_flags, kOverlined); }

  /** Description:
    Returns true if and only if text is drawn strike with this TextStyle.
  */
  bool isStriked() const  { return GETBIT(m_flags, kStriked); }

  /** { Secret } */
  bool isPreLoaded() const  { return GETBIT(m_flags, kPreLoaded); }

  /** { Secret } */
  bool isShxFont() const    { return GETBIT(m_flags, kShxFont);   }

  /** { Secret } */
  bool isTtfFont() const    { return !isShxFont();  }

  /** Description:
    Controls if the *font* file for this TextStyle is treated as a shape file.
    Arguments:
    isShape (I) Controls setting.
  */
  /** { Secret } */
   void setIsShape(
    bool isShape) { SETBIT(m_flags, kShape, isShape); }

  /** Description:
    Returns true if and only if the *font* file for this TextStyle is a shape file.
  */
  /** { Secret } */
  bool isShape() const { return GETBIT(m_flags, kShape); }


  /** Description:
    Sets this TextStyle to use the specified OdFont or Windows *font* characteristics.

    Arguments:
    pFont(I) Pointer to the *font*.
    typeface (I) Typeface name of the *font*.
    bold (I) Bold if and only if true.
    italic (I) Italic if and only if true.
    charset (I) Windows character *set* identifier.
    pitchAndFamily (I) Windows pitch and character family identifier.

    Remarks:
    If typeface is null, the Windows *font* information is removed from this text style.
  */
  virtual OdResult setFont(
    const OdChar * typeface, 
    bool bold, bool italic, 
    int charset, 
    int pitchAndFamily);
  virtual OdResult setFont(
    OdFont* font){m_pFont = font;return Oda::eOk;}

  /** Description:
    Sets this TextStyle to use the specified OdFont as the BigFont.

    Arguments:
    pBigFont (I) Pointer to the BigFont.
  */
  void setBigFont(
    OdFont* pBigFont){m_pBigFont = pBigFont;}


  /** Description:
    Returns the Windows *font* characteristics for this TextStyle.

    Arguments:
    typeface (O) Typeface name of the *font*.
    bold (O) True if and only if *bold*.
    italic (O) True if and only if *italic*.
    charset (O) Windows character *set* identifier.
    pitchAndFamily (O) Windows pitch and character family identifier.
  */
  OdResult font(
    OdString& typeface,
    bool& bold,
    bool& italic,
    int& charset,
    int& pitchAndFamily) const;

  /** Description:
    Returns the OdFont associated with this TextStyle.
  */
  OdFont* getFont() const     { return m_pFont;     }

  /** Description:
    Returns the OdFont associated with the BigFont for this TextStyle.
  */
  OdFont* getBigFont() const  { return m_pBigFont;  }

  /** Description:
    Returns a reference to or a copy of the TTF descriptor for this TextStyle.
  */
  OdTtfDescriptor& ttfdescriptor()
  {
    return m_ttfDescriptor;
  }
  const OdTtfDescriptor& ttfdescriptor() const
  {
    return m_ttfDescriptor;
  }

  /** Description:
    Returns the BigFont filename for this TextStyle.
  */
  const OdChar * bigFontFileName() const
  {
    return (const OdChar *)m_sBigfontFile;
  }
  /** Description:
      Returns the fixed text size for this TextStyle.
  */
  double textSize() const
  {
    return m_dTextSize;
  }

  /** Description:
    Returns the X-scale (width) factor for this TextStyle.
  */
  double xScale() const
  {
    return m_dXScale;
  }

  /** Description:
    Returns the obliquing angle for this TextStyle.

    Remarks:
    obliquingAngle has a domain of ?.48335 radians (?5?. Negative angles will have Oda2PI added to them.

    Note:
    All angles are expressed in radians.
  */
  double obliquingAngle() const
  {
    return m_dObliquingAngle;
  }
  /** Description:
    Returns the tracking percent for this TextStyle.

    Remarks:
    Tracking percent is a multiplier for the spacing between characters as defined in the *font* file.

    trackingPercent() has a range of  [0.75..4].
  */
  double trackingPercent() const
  {
    return m_dTrackingPercent;
  }

//  void odExtentsBox(const OdChar* pStr, int nStrLen, OdUInt32 flags, OdDbDatabase* pDb, OdGePoint3d& min, OdGePoint3d& max, OdGePoint3d* pEndPos = 0);     // MKU 02.06.2003

  /** Description:
    Returns the CodePage associated with this TextStyle.
  */
  OdCodePageId getCodePage() const
  {
    return m_Codepage;
  }

  /** Description:
    Sets the CodePage associated with this TextStyle.
    Arguments:
    codePage (I) CodePage.
  */
  void setCodePage(OdCodePageId codePage)
  {
    m_Codepage = codePage;
  }

  const OdChar * styleName() const
  {
    return (const OdChar *)m_StyleName;
  }

  void setStyleName(const OdChar * name)
  {
    m_StyleName = name;
  }

  /** \details
    Controls if interchar spacing used.
    \param isShape [in]  Controls setting.
  */
  /*!DOM*/
   void setIsUseIntercharSpacing(
    bool isUseIntercharSpacing) { SETBIT(m_flags, kUseIntercharSpacing, isUseIntercharSpacing); }

  /** \details
    Returns true if interchar spacing used.
  */
  /*!DOM*/
  bool isUseIntercharSpacing() const { return GETBIT(m_flags, kUseIntercharSpacing); }

    /** \details
    Controls if fixed interchar spacing used.
    \param isShape [in]  Controls setting.
    */
  /*!DOM*/
   void setIsFixedIntercharSpacing(
    bool isUseIntercharSpacing) { SETBIT(m_flags, kFixedIntercharSpacing, isUseIntercharSpacing); }

  /** \details
    Returns true if fixed interchar spacing used.
  */
  /*!DOM*/
  bool isFixedIntercharSpacing() const { return GETBIT(m_flags, kFixedIntercharSpacing); }
  
  virtual OdGePoint2d extents(
    const OdChar* pStr, 
    const OdBool penups,
    const int len,
    const OdBool raw,
    OdGiWorldDraw *ctxt = NULL) const;
  virtual OdResult extentsBox(
    const OdChar* pStr,
    const OdBool penups,
    const int len,
    const OdBool raw,
    OdGePoint2d& extMin,
    OdGePoint2d& extMax,
    OdGiWorldDraw* ctxt = NULL) const;

 /** \details
    Returns the interchar spacing for this TextStyle.

    \remarks
    Interchar spacing is a factor of text size, that determine distance from start of character to 
    start of next character for fixed interchar spacing mode or a additional distance from end of 
    character to start of next character for common interchar spacing mode.
  */
  double getIntercharSpacing() const;

  /** \details
    Allow to set interchar spacing for this TextStyle.
  */

  void setIntercharSpacing( double dSpacing );
  
  
  virtual bool queryMText2(int type, void *pInput, void *pOutput)
  {
    return false;
  }
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdGiTextStyle object pointers.
*/
typedef OdSmartPtr<OdGiTextStyle> OdGiTextStylePtr;

#include "../TD_PackPop.h"

#endif  // __ODGITEXTSTYLE_H__

