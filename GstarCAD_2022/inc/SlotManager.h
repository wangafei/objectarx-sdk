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


// SlotManager.h: interface for the OdSlotManager class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _SLOTMANAGER_H_INCLUDED_
#define _SLOTMANAGER_H_INCLUDED_

#include "IntArray.h"


typedef unsigned int OdSlotId;
#define kOdNullSlotId OdSlotId(-1)


/** Description:
    This class manages OdSlot objects. 
    
    {group:Other_Classes}
*/
class OdSlotManager  
{
  OdIntArray  m_freeSlots;
  unsigned int  m_numSlots;
public:
  OdSlotManager() : m_numSlots(0) {}
  /** Description:
    Adds a Slot to this Slots object.

    Remarks:
    Returns the Slot ID of a new slot.
  */
  inline OdSlotId newSlot()
  {
    int res;
    if(m_freeSlots.isEmpty())
    {
      res = m_numSlots++;
    }
    else
    {
      res = m_freeSlots.last();
      m_freeSlots.removeLast();
    }
    return res;
  }

  /** Description:
    Frees the specified Slot of this Slots object.
    Arguments:
    slotId (I) Slot ID.
  */
  inline void freeSlot(OdSlotId slotId)
  {
    if(slotId+1==m_numSlots)
    {
      --m_numSlots;
    }
    else
    {
      m_freeSlots.append(slotId);
    }
  }

  /** Description:
    Returns true if and and only the specified Slot exists in this Slots object.
    Arguments:
    slotId (I) Slot ID.
  */
  inline bool contains(OdSlotId slotId) const
  {
    return (slotId < m_numSlots && !m_freeSlots.contains(slotId, 0));
  }
};

/** Description:
    This template class implements a collection of Slots.
    
    Remarks:
    Unlike Array elements, Slots may be *empty*, filled, or freed. New Slots
    are either allocated from the list of freed Slots, or added to the
    *end* of the underlying Array.
    
    {group:Other_Classes}
*/
template <class TVal, class TAlloc = OdObjectsAllocator<TVal> >
class OdSlots : public OdArray<TVal, TAlloc>
{
  void ensureSpace(OdSlotId slotId)
  {
    if(slotId >= this->size())
    {
      this->resize(slotId+1);
    }
  }
public:
  typedef typename OdArray<TVal, TAlloc>::size_type size_type;

  OdSlots() {}

  /**
    Arguments:
    physicalLength (I) Initial physical *length*.
    growLength (I) Initial grow *length*.
  */
  OdSlots(size_type physicalLength, int growLength = 8)
    : OdArray<TVal, TAlloc>(physicalLength, growLength) {}

  /** Description:
    Returns the *value* of an *empty* Slot in this Slots object.
  */
  static const TVal* emptySlotValue() { static const TVal def = TVal(); return &def; }

  /** Remarks:
    Returns emptySlotValue() if you access an *empty* Slot in this Slots object.
  */
  const TVal& operator[](OdSlotId slotId) const
  {
    return (slotId < this->size() ? this->getPtr()[slotId] : *emptySlotValue());
  }
  TVal& operator[](OdSlotId slotId)
  {
    ensureSpace(slotId);
    return this->asArrayPtr()[slotId];
  }
  /** Description:
    Returns the *value* *at* the specified Slot in this Slots object.

    Arguments:
    slotId (I) Slot ID.
    
    Remarks:
    Returns emptySlotValue() if you access an *empty* Slot.
  */
  const TVal& getAt(OdSlotId slotId) const
  {
    return (slotId < this->size() ? this->getPtr()[slotId] : *emptySlotValue());
  }
  /** Description:
    Sets the *value* *at* the specified Slot ID in this Slots object.

    Arguments:
    slotId (I) Slot ID.
    value (I) Value.
  */
  void setAt(OdSlotId slotId, const TVal& value)
  {
    ensureSpace(slotId);
    this->asArrayPtr()[slotId] = value;
  }
};


/** Description:
    This template class implements Managed collections of Slots. 
    {group:Other_Classes}
*/
template <class TVal, class TAlloc = OdObjectsAllocator<TVal> >
class OdManagedSlots
  : public OdSlots<TVal, TAlloc>
  , public OdSlotManager
{
public:
  typedef typename OdSlots<TVal, TAlloc>::size_type size_type;

  OdManagedSlots() {}

  /**
    Arguments:
    physicalLength (I) Initial physical *length*.
    growLength (I) Initial grow *length*.
  */
  OdManagedSlots(size_type physicalLength, int growLength = 8)
    : OdSlots<TVal, TAlloc>(physicalLength, growLength) {}

#ifdef _DEBUG
  /** Remarks:
    #ifdef _DEBUG, asserts OdSlotManager::contains(slotId) 
  */
  const TVal& operator[](OdSlotId slotId) const
  {
    ODA_ASSERT(OdSlotManager::contains(slotId)); // invalid slotId
    return OdSlots<TVal, TAlloc>::operator[](slotId);
  }
  TVal& operator[](OdSlotId slotId)
  {
    ODA_ASSERT(OdSlotManager::contains(slotId)); // invalid slotId
    return OdSlots<TVal, TAlloc>::operator[](slotId);
  }

  /** Remarks:
    #ifdef _DEBUG, asserts OdSlotManager::contains(slotId) 
  */
  const TVal& getAt(OdSlotId slotId) const
  {
    ODA_ASSERT(OdSlotManager::contains(slotId)); // invalid slotId
    return OdSlots<TVal, TAlloc>::getAt(slotId);
  }
  /** Remarks:
    #ifdef _DEBUG, asserts OdSlotManager::contains(slotId) 
  */
  void setAt(OdSlotId slotId, const TVal& value)
  {
    ODA_ASSERT(OdSlotManager::contains(slotId)); // invalid slotId
    OdSlots<TVal, TAlloc>::setAt(slotId, value);
  }
#endif //_DEBUG
};

#endif // #ifndef _SLOTMANAGER_H_INCLUDED_
