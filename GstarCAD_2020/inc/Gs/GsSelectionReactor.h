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




#ifndef __ODGSSELECTIONREACTOR_H_INCLUDED_
#define __ODGSSELECTIONREACTOR_H_INCLUDED_


class OdDbStub;
class OdGiViewport;
 
/** Description:
    This struct contains information related to an OdGiDrawable object.
    
    Remarks:
    This includes the Drawable object, its parent object, and some flags.
    Library: TD_Gs
    {group:OdGi_Classes} 
*/
struct OdGiDrawableDesc 
{
  OdGiDrawableDesc()
    : pParent(0)
    , persistId(0)
    , pTransientDrawable(0)
    , nDrawableFlags(0)
    , nDrawableDescFlags(0)
  {}

  OdGiDrawableDesc*   pParent; // Pointer to the parent of the Drawable object.

  OdDbStub*           persistId; // Persistent ID of the *database* object associated with the Drawable object.

  const OdGiDrawable* pTransientDrawable; // Pointer to the Drawable object.

  OdUInt32            nDrawableFlags; // Drawable flags for the Drawable object (come from subSetAttributes).

  enum DrawableDescFlags
  {
    kFirstFlag            = 1,

    kMarkedToSkip         = kFirstFlag << 0,
    kMarkedBySelection    = kFirstFlag << 1, // selected for crossing/fence; not selected for window
    kMarkedBySubSelection = kFirstFlag << 2, // selected for crossing/fence; not selected for window
    kMarkedByGeometry     = kFirstFlag << 3, // geometry output for entire drawable
    kMarkedBySubGeometry  = kFirstFlag << 4, // geometry output for current marker
    kMarkedToBreak        = kFirstFlag << 5, // break selection process entirely

    kLastFlag             = kMarkedToBreak
  };
  
  OdUInt32            nDrawableDescFlags; // additional desc flags

  /** Description:
      Sets the Skip flag for the Drawable object.
      
      Arguments:
      skip (I) Controls Skip flag.
      Remarks:
      If set, the Drawable object will be skipped during vectorization.
  */
  void markToSkip(bool skip) const;

  /** Description:
      Returns true if and only if this Drawable marked to be skipped during vectorization.
  */
  bool isMarkedToSkip() const;

  void markBySelection(bool val) const;

  bool isMarkedBySelection() const;

  void markBySubSelection(bool val) const;

  bool isMarkedBySubSelection() const;

  void markByGeometry(bool val) const;

  bool isMarkedByGeometry() const;

  void markBySubGeometry(bool val) const;

  bool isMarkedBySubGeometry() const;

  void markToBreak(bool val) const;

  bool isMarkedToBreak() const;
};

/** Description:
    This class is the base class for custom classes that receive notification
    of OdGs Selection events.
    
    Note:
    The default implementations of all methods in this class do nothing but return.

    Library:
    TD_Gs
  
    {group:OdGs_Classes} 
*/
class OdGsSelectionReactor
{
public:
  virtual ~OdGsSelectionReactor () {}

public:
  /** Description
    Notification function called whenever an OdGiDrawableDesc object has been *selected*.

    Arguments:
    pDrawableDesc (I) Pointer to the OdGiDrawableDesc object.

    Remarks:
    Returns true if and only if the operation is to continue.
    
    This function is called after the operation.
  */
  virtual bool selected(const OdGiDrawableDesc& pDrawableDesc) = 0;

  enum
  {
    kNotImplemented = 0x80000000,
    kContinue       = 0,
    kBreak          = 1,
    kSkipDrawable   = 2
  };
  /** Description
  */
  virtual OdUInt32 selected(const OdGiPathNode& /*pathNode*/, const OdGiViewport& /*viewInfo*/)
  {
    return OdUInt32(kNotImplemented);
  }
  /** 0x01 ==> enable subent
   *  0x02 ==> enable nested
  */
  virtual OdUInt32 selectFlags () const
  {
    return 0;
  }

  virtual bool beginDrawable(const OdGiDrawableDesc*,const OdGiViewport*) const { return true; }
  virtual void endDrawable(const OdGiDrawableDesc* ) const   { }
  virtual bool selectAbort() const {return false;}
};

inline void OdGiDrawableDesc::markToSkip(bool val) const
{
  SETBIT(const_cast<OdGiDrawableDesc*>(this)->nDrawableDescFlags, kMarkedToSkip, val);
}

inline bool OdGiDrawableDesc::isMarkedToSkip() const
{
  return GETBIT(nDrawableDescFlags, kMarkedToSkip);
}

inline void OdGiDrawableDesc::markBySelection(bool val) const
{
  SETBIT(const_cast<OdGiDrawableDesc*>(this)->nDrawableDescFlags, kMarkedBySelection, val);
}

inline bool OdGiDrawableDesc::isMarkedBySelection() const
{
  return GETBIT(nDrawableDescFlags, kMarkedBySelection);
}

inline void OdGiDrawableDesc::markBySubSelection(bool val) const
{
  SETBIT(const_cast<OdGiDrawableDesc*>(this)->nDrawableDescFlags, kMarkedBySubSelection, val);
}

inline bool OdGiDrawableDesc::isMarkedBySubSelection() const
{
  return GETBIT(nDrawableDescFlags, kMarkedBySubSelection);
}

inline void OdGiDrawableDesc::markByGeometry(bool val) const
{
  SETBIT(const_cast<OdGiDrawableDesc*>(this)->nDrawableDescFlags, kMarkedByGeometry, val);
}

inline bool OdGiDrawableDesc::isMarkedByGeometry() const
{
  return GETBIT(nDrawableDescFlags, kMarkedByGeometry);
}

inline void OdGiDrawableDesc::markBySubGeometry(bool val) const
{
  SETBIT(const_cast<OdGiDrawableDesc*>(this)->nDrawableDescFlags, kMarkedBySubGeometry, val);
}

inline bool OdGiDrawableDesc::isMarkedBySubGeometry() const
{
  return GETBIT(nDrawableDescFlags, kMarkedBySubGeometry);
}

inline void OdGiDrawableDesc::markToBreak(bool val) const
{
  SETBIT(const_cast<OdGiDrawableDesc*>(this)->nDrawableDescFlags, kMarkedToBreak, val);
}

inline bool OdGiDrawableDesc::isMarkedToBreak() const
{
  return GETBIT(nDrawableDescFlags, kMarkedToBreak);
}

#endif // __ODGSSELECTIONREACTOR_H_INCLUDED_
