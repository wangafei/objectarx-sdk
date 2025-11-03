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

#ifndef _OdTtfDescriptor_h_Included_
#define _OdTtfDescriptor_h_Included_

#include "../Gi/Gi.h"
#include "../OdString.h"

/** Description:
    This class implements TrueType Descriptor objects which provide an interface to
    the characteristics of a TrueType font.
    
    {group:Other_Classes}
*/
class FIRSTDLL_EXPORT OdTtfDescriptor
{
  // Members

	OdUInt32        m_nFlags;
  OdString        m_sFontFile;
	OdString        m_Typeface;

public:
  // Constructor

  OdTtfDescriptor() : m_nFlags(0) 
  {
  }

  /** Arguments:
    typeface (I) Typeface.
    bold (I) True if and only if a *bold* font.
    italic (I) True if and only if an *italic* font.
    charset (I) Character set.
    pitchAndFamily (I) Pitch and Family.
    
    Remarks:
    The two low-order bits of pitchAndFamily specify the pitch of the font.
    Bits 4 through 7 of pitchAndFamily specify the font family.

  */
  OdTtfDescriptor(const OdString& typeface, bool bold, bool italic, int charset, int pitchAndFamily)
    : m_Typeface(typeface)
  {
    setTtfFlags(bold, italic, charset, pitchAndFamily);
  }

  // Accessors /transformers

  /** Description
    Returns the *filename* of this TtfDescriptor object.
  */
  const OdString &fileName() const     { return m_sFontFile; }

  /** Description
    Returns the *typeface* of this TtfDescriptor object.
  */
  const OdString &typeface() const     { return m_Typeface;  }

  OdUInt32 getTtfFlags() const  { return m_nFlags;    }

  /** Description
    Clears the *filename* of this TtfDescriptor object.
  */
  void clearFileName()
  { 
    m_sFontFile.empty();  
  }
  /** Description
    Clears the *typeface* of this TtfDescriptor object.
  */
  void clearTypeface()
  { 
    m_Typeface.empty();  
  }
  /** Description
    Adds the specified *typeface* to this TtfDescriptor object.
  */
  void addTypeface(OdChar typeface)
  { 
    m_Typeface += typeface;
  }

  /** Description:
    Returns the flags of this TtfDescriptor object. 
    Arguments:
    typeface (O) Receives the full name of the font.
    bold (O) Receives true if and only if this is a *bold* font.
    italic (O) Receives true if and only if this is an *italic* font.
    charset (O) Receives the character set.
    pitchAndFamily (O) Receives the Pitch and Family.
    
    Remarks:
    The two low-order bits of pitchAndFamily specify the pitch of the font.
    Bits 4 through 7 of pitchAndFamily specify the font family.
  */
	void getTtfFlags(bool& bold, bool& italic, int& charset, int& pitchAndFamily) const
  {
	  bold = isBold();
	  italic = isItalic();
	  charset = charSet();
	  pitchAndFamily = this->pitchAndFamily();
  }

  /** Description
    Sets the *filename* of this TtfDescriptor object.
    Arguments:
    filename (I) Filename.
  */
  void setFileName(const OdString& filename)  { m_sFontFile = filename; }
  /** Description
    Sets the *typeface* of this TtfDescriptor object.
    Arguments:
    typeface (I) Typeface.
  */
  void setTypeFace(const OdString& typeface)  { m_Typeface = typeface;  }
  /** Description
    Sets the *flags* of this TtfDescriptor object.
    Arguments:
    flags (I) Flags.

  */
  void setTtfFlags(OdUInt32 flags)           { m_nFlags = flags;      }
  /** Arguments:
    bold (I) True if and only if a *bold* font.
    italic (I) True if and only if an *italic* font.
    charset (I) Character set.
    pitchAndFamily (I) Pitch and Family.
    
    Remarks:
    The two low-order bits of pitchAndFamily specify the pitch of the font.
    Bits 4 through 7 of pitchAndFamily specify the font family.
  */
  void setTtfFlags(bool bold, bool italic, int charset, int pitchAndFamily)
  {
    setBold(bold);
    setItalic(italic);
    setCharSet(charset);
    setPitchAndFamily(pitchAndFamily);
  }

  /** Description:
    Sets the *bold* flag of this TtfDescriptor object.
    Arguments:
    bold (I) True if and only if a *bold* font.
  */ 
  void setBold(bool bold)          { SETBIT(m_nFlags, 0x02000000, bold);  }
  /** Description:
    Sets the *italic* flag of this TtfDescriptor object.
    Arguments:
    italic (I) True if and only if an *italic* font.
  */ 
  void setItalic(bool italic)        { SETBIT(m_nFlags, 0x01000000, italic);  }
  /** Description:
    Sets the character set of this TtfDescriptor object.
    Arguments:
    charset (I) Character set.
  */ 
  void setCharSet(int charset)        { m_nFlags = ((m_nFlags & 0xFFFF00FF) | ((charset << 8) & 0x0000FF00)); }
  /** Description:
    Sets the pitch and family of this TtfDescriptor object.
    Arguments:
    pitchAndFamily (I) Pitch and Family.
    
    Remarks:
    The two low-order bits of pitchAndFamily specify the pitch of the font.
    Bits 4 through 7 of pitchAndFamily specify the font family.
  */
  void setPitchAndFamily(int pitchAndFamily) { m_nFlags = ((m_nFlags & 0xFFFFFF00) | (pitchAndFamily & 0x000000FF));  }

  /** Description:
    Returns true if and only if this TtfDescriptor is a *bold* font.
  */
  bool isBold() const             { return GETBIT(m_nFlags, 0x02000000);  }
  /** Description:
    Returns true if and only if this TtfDescriptor is an *italic* font.
  */
  bool isItalic() const           { return GETBIT(m_nFlags, 0x01000000);  }
  /** Description:
    Returns the character set for this TtfDescriptor object.
  */
  OdUInt16 charSet() const        { return OdUInt16((m_nFlags & 0x0000ff00) >> 8); }
  /** Description:
    Returns the pitch and family of this TtfDescriptor object.
    
    Remarks:
    The two low-order bits of pitchAndFamily specify the pitch of the font.
    Bits 4 through 7 of pitchAndFamily specify the font family.
  */
  int pitchAndFamily() const      { return (m_nFlags & 0x000000ff); }

  /** Description:
    Returns the pitch of this TtfDescriptor object.
  */
  int getPitch() const            { return (pitchAndFamily() & 0x00000003); }
  /** Description:
    Returns the family of this TtfDescriptor object.
  */
  int getFamily() const           { return (pitchAndFamily() & 0x000000f0); }
};

#endif // _OdTtfDescriptor_h_Included_
