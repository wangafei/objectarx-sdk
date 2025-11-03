/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2002-2015, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) Copyright (C) 2002-2015 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////

#ifndef __FMMDL_ENTITY_H__
#define __FMMDL_ENTITY_H__

#include "../FacetModeler/Modeler/FMMdlBase.h"

/**
  <group TA_Geometry>
*/
namespace FacetModeler
{

typedef unsigned Flag;

Flag inline FLAG(unsigned int i) { return (1 << i); }

inline int isSubset(Flag a, Flag b) { return ((a & b) == a); }

enum OnOff { kOff, kOn };


/** \details
   Base class for modeler primitives.
*/
class FMGEOMETRY_API Entity
{
public:
  /** \details
     Constructor.
  */
  Entity();

  /** \details
  */
  Entity(const Entity& ent);

  /** \details
  */
  Entity& operator =(const Entity&);

  /** \details
     Destructor.
  */
  virtual ~Entity();

  /** \details
     Returns flags.
  */
  Flag flags() const;

  /** \details
     Sets flags.
  */
  void setFlags( Flag iFlags );

  /** \details
     Returns whether specified flag is on.
  */
  bool isFlagOn( Flag iFlag ) const;
  bool isFlagOff( Flag iFlag ) const;

  /** \details
     Sets whether specified flag is on.
  */
  void setFlagOn( Flag iFlag );
  void setFlagOff( Flag iFlag );

  void flipFlag( Flag iFlag );

  /** \details
     Returns tag.
  */
  FacetModeler::AecTagType tag() const;

  /** \details
     Sets tag.
  */
  void setTag( FacetModeler::AecTagType nTag );
 
  /** \details
     Returns brep.

     \note
     For internal use only - not intended for direct use by client code.
  */
  void* brep() const;

  /** \details
     Sets cargo.

     \note
     For internal use only - not intended for direct use by client code.
  */
  void setBrep(void* pBrep);

private:
  Flag  m_flags;
  AecTagType  m_nTag;
  void* m_pBrep;
};


inline Entity::Entity() {
  m_flags = 0;
  m_nTag = 0;
  m_pBrep = NULL;
}

inline Entity::Entity(const Entity& ent) {
  m_flags = ent.m_flags;
  m_nTag = ent.m_nTag;
  *this = ent;
}

inline Entity& Entity::operator =(const Entity& ent) {
  setTag( ent.tag() );
  m_flags = ent.m_flags;
  return *this;
}

inline Entity::~Entity() {
}

inline Flag Entity::flags() const {
  return m_flags;
}

inline void Entity::setFlags( Flag iFlags ) {
  m_flags = iFlags;
}

inline bool Entity::isFlagOn( Flag iFlag ) const {
  return (m_flags & iFlag) != 0;
}

inline bool Entity::isFlagOff( Flag iFlag ) const {
  return (m_flags & iFlag) == 0;
}

inline void Entity::setFlagOn( Flag iFlag ) {
  m_flags |= iFlag;
}

inline void Entity::setFlagOff( Flag iFlag ) {
  m_flags &= ~iFlag;
}

inline void Entity::flipFlag (Flag iFlag) { 
  m_flags ^= iFlag; 
}

inline AecTagType Entity::tag() const {
  return m_nTag;
}

inline void Entity::setTag( AecTagType nTag ) {
  m_nTag = nTag;
}

inline void* Entity::brep() const {
  return m_pBrep;
}

inline void Entity::setBrep(void* pBrep) {
  m_pBrep = pBrep;
}

}

#endif //__FMMDL_ENTITY_H__
