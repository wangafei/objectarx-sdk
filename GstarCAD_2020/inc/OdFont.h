/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2012, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) Copyright (C) 2003-2012 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////




// OdFont.h: interface for the OdFont class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ODFONT_H__0B76813A_DCFA_450E_8591_B6C6F1ED76EC__INCLUDED_)
#define AFX_ODFONT_H__0B76813A_DCFA_450E_8591_B6C6F1ED76EC__INCLUDED_

#include "RxObject.h"
#include "OdArray.h"
//#include "OdCodePage.h"

// For memset below
#include <memory.h>

class OdGiCommonDraw;
class OdGiConveyorGeometry;
class OdGePoint2d;
class OdGePoint3d;
class OdStreamBuf;

#include "TD_PackPush.h"

typedef enum {
  kFontTypeUnknown    = 0,  // Unknown.
  kFontTypeShx        = 1,  // SHX font.
  kFontTypeTrueType   = 2,  // TrueType font.
  kFontTypeShape      = 3,  // Shape file.
  kFontTypeBig        = 4,  // BigFont file.
  kFontTypeRsc        = 5   // MicroStation Recource file.
} OdFontType;

/** Description:
    This structure implements *character* properties in an OdGi context. 
    Library: TD_Root
    {group:Structs}
*/
struct FIRSTDLL_EXPORT OdCharacterProperties
{
  OdCharacterProperties()
  { ::memset(this, 0, sizeof(*this)); }

  bool  bUnderlined;
  bool  bOverlined;
  bool  bStriked;
  bool  bLastChar;
  bool  bInBigFont;
  bool  bAsian;
  bool  bValid;
  bool  bSpecialSymbol;
};

/** Description:
    This structure implements text properties in an OdGi context.
    Library: TD_Root
    {group:Structs}
*/
struct FIRSTDLL_EXPORT OdTextProperties
{
  double   m_trackingPercent;
  OdUInt16 m_flags;
  OdUInt16 m_textQuality;
  enum
  {
    kNormalText   = 0x01,
    kVerticalText = 0x02,
    kUnderlined   = 0x04,
    kOverlined    = 0x08,
    kLastChar     = 0x10,
    kInBigFont    = 0x20,
    kInclPenups   = 0x40,
    kZeroNormals  = 0x80,
    kBezierCurves = 0x100,
    kStriked      = 0x200,
	kFillTtf      = 0X400
  };
public:
  OdTextProperties() : m_flags(kFillTtf), m_trackingPercent(0.0), m_textQuality(50) {}
  /** Description:
    Returns true if and only if the Normal Text flag is set for this TextProperties object.
  */
  bool isNormalText() const { return GETBIT(m_flags, kNormalText); }
  /** Description:
    Controls the Normal Text flag for this TextProperties object.
    Arguments:
    value (I) Controls the flag.
  */
  void setNormalText(bool value) { SETBIT(m_flags, kNormalText, value); }
  /** Description:
    Returns true if and only if the Vertical Text flag is set for this TextProperties object.
  */
  bool isVerticalText() const { return GETBIT(m_flags, kVerticalText); }
  /** Description:
    Controls the Vertical Text flag for this TextProperties object.
    Arguments:
    value (I) Controls the flag.
  */
  void setVerticalText(bool value) { SETBIT(m_flags, kVerticalText, value); }
  /** Description:
    Returns true if and only if the Underlined flag is set for this TextProperties object.
  */
  bool isUnderlined() const { return GETBIT(m_flags, kUnderlined); }
  /** Description:
    Controls the Underlined flag for this TextProperties object.
    Arguments:
    value (I) Controls the flag.
  */
  void setUnderlined(bool value) { SETBIT(m_flags, kUnderlined, value); }
  /** Description:
    Returns true if and only if the Overlined flag is set for this TextProperties object.
  */
  bool isOverlined() const { return GETBIT(m_flags, kOverlined); }
  /** Description:
    Controls the Overlined flag for this TextProperties object.
    Arguments:
    value (I) Controls the flag.
  */
  void setOverlined(bool value) { SETBIT(m_flags, kOverlined, value); }
  /** Description:
    Returns true if and only if the Striked flag is set for this TextProperties object.
  */
  bool isStriked() const { return GETBIT(m_flags, kStriked); }
  /** Description:
    Controls the Striked flag for this TextProperties object.
    Arguments:
    value (I) Controls the flag.
  */
  void setStriked(bool value) { SETBIT(m_flags, kStriked, value); }
  /** Description:
  Returns true if and only if the LastChar flag is set for this TextProperties object.
  */

  /** Description:
    Returns true if and only if the LastChar flag is set for this TextProperties object.
  */
  bool isLastChar() const { return GETBIT(m_flags, kLastChar); }
  /** Description:
    Controls the LastChar flag for this TextProperties object.
    Arguments:
    value (I) Controls the flag.
  */
  void setLastChar(bool value) { SETBIT(m_flags, kLastChar, value); }
  /** Description:
    Returns true if and only if the InBigFont flag is set for this TextProperties object.
  */
  bool isInBigFont() const { return GETBIT(m_flags, kInBigFont); }
  /** Description:
    Controls the InBigFont flag for this TextProperties object.
    Arguments:
    value (I) Controls the flag.
  */
  void setInBigFont(bool value) { SETBIT(m_flags, kInBigFont, value); }
  /** Description:
    Returns true if and only if the IncludePenups flag is set for this TextProperties object.
  */
  bool isIncludePenups() const { return GETBIT(m_flags, kInclPenups); }
  /** Description:
    Controls the IncludePenups flag for this TextProperties object.
    Arguments:
    value (I) Controls the flag.
  */
  void setIncludePenups(bool value) { SETBIT(m_flags, kInclPenups, value); }
  
  /** Description:
  Returns true if and only if the FillTtf flag is set for this TextProperties object.
  */
  bool isFillTtf() const { return GETBIT(m_flags, kFillTtf); }
  
  /** Description:
  Controls the FillTtf flag for this TextProperties object.
  Arguments:
  value (I) Controls the flag.
  */
  void setFillTtf(bool value) { SETBIT(m_flags, kFillTtf, value); }
  
  /** Description:
    Returns true if and only if the ZeroNormals flag is set for this TextProperties object.
  */
  bool isZeroNormals() const { return GETBIT(m_flags, kZeroNormals); }
  /** Description:
    Controls the kZeroNormals flag for this TextProperties object.
    Arguments:
    value (I) Controls the flag.
  */
  void setZeroNormals(bool value) { SETBIT(m_flags, kZeroNormals, value); }
  /** Description:
    Returns smooth TTF text contour output flag.
  */
  bool ttfPolyDraw() const { return GETBIT(m_flags, kBezierCurves); }
  /** Description:
    Sets smooth TTF text contour output flag.
    Arguments:
    bFlag (in) New flag value.
  */
  void setTtfPolyDraw(bool bFlag) { SETBIT(m_flags, kBezierCurves, bFlag); }
  /** Description:
    Returns the tracking percent for this TextProperties object.
  */
  double trackingPercent() const {return m_trackingPercent; }
  /** Description:
    Sets the tracking percent for this TextProperties object.
    Arguments:
    trackingPercent (I) Tracking percent.
  */
  void setTrackingPercent(double trackingPercent) { m_trackingPercent = trackingPercent; }

  /** Description:
    Returns the text quality percent for this vectorization process.
    Remarks:
    Returns a value in the range [0,100]. 50 is the default.
  */
  OdUInt32 textQuality() const { return m_textQuality; }

  /** Description:
    Returns the text quality percent for this vectorization process.
    Remarks:
    Sets a value in the range [0,100]. 50 is the default.
  */
  void setTextQuality(OdUInt32 val) { m_textQuality = (OdUInt16)val; }
};

typedef OdUInt32 OdFontSubType;
#define kBigFont10    0x0001
#define kUniFont10    0x0002
#define kFont10       0x0004
#define kFont11       0x0008
#define kFont10A      0x0010
#define kTrueType     0x0020
#define kFontGdt      0x0040
#define kFontSimplex6 0x0080
#define kShapes11     0x0100
#define kFontRsc      0x0200   // MicroStation Resource file.

class OdGePoint2d;
class OdGiConveyorGeometry;
class OdTtfDescriptor;

/** Description:
    This class is the base interface class for classes that implements font objects.
    {group:Other_Classes}
*/
class FIRSTDLL_EXPORT OdFont : public OdRxObject
{
  OdUInt32 m_Flags;
  bool     m_UseDefaultChar;

public:
  ODRX_DECLARE_MEMBERS(OdFont);

  OdFont() : m_Flags(0), m_UseDefaultChar(true) {}

  bool useDefaultChar() const    { return m_UseDefaultChar; }
  void setUseDefaultChar(bool b) { m_UseDefaultChar = b; }

  /** Description:
    Returns the font *flags* for this Font object.
    Remarks:
    getFlags() returns a combination of zero or more of the following: 
    
    @table
    Name              Value
    kBigFont10        0x0001
    kUniFont10        0x0002
    kFont10           0x0004
    kFont11           0x0008
    kFont10A          0x0010
    kTrueType         0x0020
    kFontGdt          0x0040
    kFontSimplex6     0x0080
    kShapes11         0x0100
    kFontRsc          0x0200
  */  
  OdUInt32 getFlags() const { return m_Flags; }
  /** Description:
    Returns the font *flags* for this Font object.
    
    Remarks:
    flags() returns a combination of zero or more of the following: 
    
    @table
    Name              Value
    kBigFont10        0x0001
    kUniFont10        0x0002
    kFont10           0x0004
    kFont11           0x0008
    kFont10A          0x0010
    kTrueType         0x0020
    kFontGdt          0x0040
    kFontSimplex6     0x0080
    kShapes11         0x0100
    kFontRsc          0x0200
  */  
  OdUInt32 flags() { return m_Flags; }

  /** Description:
    Sets the font *flags* for this Font object.
    Arguments:
    fontFlags (I) Font *flags*.

    Remarks:
    fontFlags must be a combination of zero or more of the following:
    
    @table
    Name              Value
    kBigFont10        0x0001
    kUniFont10        0x0002
    kFont10           0x0004
    kFont11           0x0008
    kFont10A          0x0010
    kTrueType         0x0020
    kFontGdt          0x0040
    kFontSimplex6     0x0080
    kShapes11         0x0100
    kFontRsc          0x0200
  */  
  void setFlags(OdUInt32 fontFlags) { m_Flags = fontFlags; }

  /** Description:
    Adds the specified font *flags* to this Font object.
    Arguments:
    fontFlags (I) Font *flags*.

    Remarks:
    fontFlags must be a combination of zero or more of the following:
     
    @table
    Name              Value
    kBigFont10        0x0001
    kUniFont10        0x0002
    kFont10           0x0004
    kFont11           0x0008
    kFont10A          0x0010
    kTrueType         0x0020
    kFontGdt          0x0040
    kFontSimplex6     0x0080
    kShapes11         0x0100
    kFontRsc          0x0200
  */  
  void addFlag(OdUInt32 fontFlags) { m_Flags |= fontFlags; }

  /** Description:
    Initializes this Font object to read font data from the specified StreamBuf object.

    Arguments:
    pStreamBuf (I) Pointer to the StreamBuf object from which the data are to be read.
    
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.    
  */    
  virtual OdResult initialize(OdStreamBuf* pStreamBuf) = 0;
  /** Description:
    Draws the specified *character* with this Font object.
    Arguments:
    character (I) Character to draw.
    advance (I) Offset to next *character*.
    pWd (I/O) Draw object that can be used by this function to set the 
              necessary attributes and create the necessary geometry.
    textProperties (I) Text properties.
    pGeometry (I) Pointer to the modeler geometry.

  */
  virtual OdResult     drawCharacter(OdChar character, OdGePoint2d& advance,/*OdGePoint2d& scale,*/ OdGiCommonDraw* pWd,
                                     OdTextProperties& textProperties) = 0;
  virtual OdResult     drawCharacter(OdChar character, OdGePoint2d& advance,/*OdGePoint2d& scale,*/
                                     OdGiConveyorGeometry* pGeometry,
                                     OdTextProperties& textProperties) = 0;
  /** Description:
    Returns the height of this Font object above the baseline.
  */
  virtual double       getAbove() const = 0;
  /** Description:
    Returns the depth of this font object below the baseline.
  */
  virtual double       getBelow() const = 0;
  /** Description:
    Returns an array of the *characters* defined in this Font object.
    Arguments:
    characters (O) Receives the array of *characters*.
  */
  virtual OdUInt32     getAvailableChars(OdArray<OdChar>& characters) = 0;
  /** Description:
    Returns true if and only if the specified *character* is defined in this Font object.
    Arguments:
    character (I) Character.
  */
  virtual bool        hasCharacter(OdChar character) = 0;
  
  /** Description:
    Returns the height of this Font object.
  */
  virtual double      getHeight() const                                                   // MKU 20.02.2003
  {
    return getAbove() + getBelow();
  }
  /** Description:
    Returns the internal leading of this Font object.
    Note:
    The default implementation of this function always returns 0.
  */
  virtual double getInternalLeading() const
  {
    return 0;
  }


  //  removed here from GiContextForDbDatabase.cpp              // MKU 04.03.2003

  /** Description:
    Returns the height of this Font object above the baseline.
    Note:
    The default implementation of this function returns getAbove(), unless it is 0.0, in which case this function returns 1.0. 
  */
  double fontAbove() const  
  {
    double above = getAbove();
    if(OdZero(above))
    {
      above = 1.0;
    }
    return above;
  }
  /** Description:
    Returns the underline position for this Font object at the specified text size.
    Arguments:
    textSize (I) Text size.
    Note:
    The default implementation of this function returns -2.0 * textSize.
  */
  virtual double getUnderlinePos(double textSize) const
  {
    return -0.2 * textSize;
    
  }
  /** Description:
    Returns the overline position for this Font object at the specified text size.
    Arguments:
    textSize (I) Text size.
    Note:
    The default implementation of this function returns 1.2 * textSize.
  */
  virtual double getOverlinePos(double textSize) const
  {
    return 1.2 * textSize;
  }

  virtual bool isShpFont()
  {
    return false;
  }
  
  /** Description:
    Returns true if and only if this Font object is an SHX font.
    Note:
    The default implementation of this function always returns true.
  */
  virtual bool isShxFont()
  {
    return true;
  }
  /** Description:
    Returns the average width of characters in this Font object.
    Note:
    The default implementation of this function always returns 0.0.
  */
  virtual double getAverageWidth()
  {
    return 0.0;
  }

  /** Description:
    Returns arrays of *points* over and under the baseline for the specified *character* in this OdFont object.
    Arguments:
    character (I) Character.
    advance (I) Offset to next *character*.
    pointsOver (I) Array of *points* over the baseline..
    pointsUnder (I) Array of *points* under the baseline.
    
    textFlags (I) Text *flags*.

    Remarks:
    textFlags must be a combination of one or more of the following:
 
    @table
    Name                                Value
    OdTextProperties::kNormalText       0x01
    OdTextProperties::kVerticalText     0x02
    OdTextProperties::kUnderlined       0x04
    OdTextProperties::kOverlined        0x08
    OdTextProperties::kLastChar         0x10
    OdTextProperties::kInBigFont        0x20
    OdTextProperties::kInclPenups       0x40
    
    Note:
    The default implementation of this function does nothing but return.
    
  */
  virtual void getScore( OdUInt16 character, 
                         OdGePoint2d& advance, 
                         OdGePoint3d* pointsOver,
                         OdGePoint3d* pointsUnder,
                         const OdTextProperties& textFlags);

  /** Description:
    Returns the font data for the specified *character*.
    Arguments:
    dwTable (I) Metric table to query.
    dwOffset (I) Offset into table.
    pBuffer (I) Pointer to to the buffer to receive the data.
    cbData (I) ???.
    Remarks:
    Returns the number of bytes returned in buffer.
    
    Note:
    The default implementation of this function does nothing but return -1.
  */
  virtual OdUInt32 getFontData(
    OdUInt32 dwTable,     // metric table to query
    OdUInt32 dwOffset,    // offset into table being queried
    void * pBuffer,  // pointer to buffer for returned data
    OdUInt32 cbData       ) const;

  /** Description:
    Returns true if and only if the font supports vertical mode.
    
    Note:
    The default implementation of this function returns false.
  */
  virtual bool supportsVerticalMode()
  {
    return false;
  }

  /** Description:
    Returns font file name.

    Note:
    The default implementation of this function returns empty string.
  */
  virtual OdString getFileName() const
  {
    return OdString();
  }
  virtual void getDescriptor(OdTtfDescriptor& descr)
  {
  }

  virtual void setFileName(const OdString& fileName)
  {

  }
};

inline void OdFont::getScore( OdUInt16 /*character*/, 
                         OdGePoint2d& /*advance*/, 
                         OdGePoint3d* /*pointsOver*/,
                         OdGePoint3d* /*pointsUnder*/,
                         const OdTextProperties& /*flags*/ )
  {}

inline OdUInt32 OdFont::getFontData(
    OdUInt32 /*dwTable*/,     // metric table to query
    OdUInt32 /*dwOffset*/,    // offset into table being queried
    void * /*lpvBuffer*/,  // pointer to buffer for returned data
    OdUInt32 /*cbData*/       ) const
  {
    return OdUInt32(-1);
  }


/** Description:
    This template class is a specialization of the OdSmartPtr class for OdFont object pointers.
*/
typedef OdSmartPtr<OdFont> OdFontPtr;

/** Description:
  This class is the base interface class for text iterators, to be used both by Teigha and DGNdirect clients.
  
  {group:Other_Classes}
*/
class FIRSTDLL_EXPORT OdBaseTextIterator : public OdRxObject
{
public:
  virtual OdChar nextChar() = 0;
  /** Description:
  Returns the properties of the character at the current position of this TextIterator object.
  */
  virtual const OdCharacterProperties& currProperties() const = 0;

  /** Description:
  Returns the character at the current position of this TextIterator object.
  */
  virtual const OdChar* currPos() const = 0;
};

/** Description:
This template class is a specialization of the OdSmartPtr class for OdBaseTextIterator object pointers.
*/
typedef OdSmartPtr<OdBaseTextIterator> OdBaseTextIteratorPtr;

#include "TD_PackPop.h"

#endif // !defined(AFX_ODFONT_H__0B76813A_DCFA_450E_8591_B6C6F1ED76EC__INCLUDED_)

