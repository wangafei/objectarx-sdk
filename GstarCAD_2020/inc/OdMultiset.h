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




#ifndef OD_MULTISET_H
#define OD_MULTISET_H

#define  STL_USING_SET
#include "OdaSTL.h"

#include "OdPlatform.h"

/** Description:
    This template class extends the functionality of the standard STL class std::multiset.

    Remarks:
    The default constructor creates an empty set.

    The template arguments are the same as that of the STL class std::multiset.
    Library: TD_Db
    {group:Other_Classes}
*/
template<class Key, 
                                 class Pred = OD_TYPENAME std::less<Key>, 
                                 class A = OD_TYPENAME2 std::allocator<Key> >
class OdMultiset : public std::multiset<Key, Pred, A>
{
public:
  typedef typename std::multiset<Key, Pred, A>::iterator iterator;
  typedef typename std::multiset<Key, Pred, A>::const_iterator const_iterator;

  // 01.06.2002 G. Udov trying to eliminate using static variables
  
  OdMultiset(const Pred& comp = Pred(), const A& al = A()) 
    : std::multiset<Key, Pred, A>(comp, al) {}

  OdMultiset(const typename std::multiset<Key, Pred, A>::value_type *first, 
             const typename std::multiset<Key, Pred, A>::value_type *last, 
             const Pred& comp = Pred(), 
             const A& al = A())
    : std::multiset<Key, Pred, A>(first, last, comp, al) {}
  
  /** Description:
    Returns an *iterator* addressing the first element in the multiset that has a *key* equal to the specified *key*.
    Arguments:
    key (I) Search *key*.
  */
  iterator find_ex(const Key& key)
  {
    iterator i = find (key),
             iend = this->end();
    while (i != iend && !this->key_comp() (key, *i))
    {
      if (*i == key)
        return i;
      ++i;
    }
    return iend;
  }

  // This method and the previous one do the same. But the former is used for constant objects.
  
  const_iterator find_ex(const Key& key) const
  {
    const_iterator i = find (key),
                   iend = this->end();
    while (i != iend && !this->key_comp() (key, *i))
    {
      if (*i == key)
        return i;
      ++i;
    }
    return iend;
  }

  /** Description:
    Returns an *iterator* addressing the last element in a multiset that has a *key* equivalent to the specified *key*.
    Arguments:
    key (I) Search *key*.
  */
  iterator find_last(const Key& key)
  {
    iterator i = find (key), j,
             iend = this->end();
    while (i != iend && !this->key_comp() (key, *i))
    {
      j = i;
      ++i;
    }
    return j;
  }
};

#endif // OD_MULTISET_H
