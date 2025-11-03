/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2002-2021, Open Design Alliance (the "Alliance"). 
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
//   This application incorporates Open Design Alliance software pursuant to a license 
//   agreement with Open Design Alliance.
//   Open Design Alliance Copyright (C) 2002-2021 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////
#ifndef BRMESH2DFILTER_H_INCLUDED
#define BRMESH2DFILTER_H_INCLUDED

#include "../Br/BrEntity.h"
#include "../Br/BrMesh2dControl.h"
#include "../Br/BrExport.h"

//ODA MODELER arx使用下面注释内容
//static OdBrMesh2dControl OdBrMesh2dControlDefault;

struct pair
{
  OdBrEntity*       first;
  OdBrMesh2dControl second;
  //ODA MODELER arx使用下面注释内容
  //pair() : first((OdBrEntity*)NULL), second(OdBrMesh2dControlDefault) {}
  pair() : first((OdBrEntity*)NULL), second(OdBrMesh2dControl()) {}
  pair(const OdBrEntity*& a, const OdBrMesh2dControl& b) : first((OdBrEntity*)a), second(b) {}
};

inline pair make_pair(const OdBrEntity*& entity, const OdBrMesh2dControl& control)
{
  return pair(entity, control);
}

typedef pair value_type;
typedef void iterator;

/** \details
  This interface class represents 2D mesh filters.

  \remarks 
  This class is implemented only for Spatial modeler.

  \sa
  TD_Br

  <group OdBr_Classes>
*/
class ODBR_TOOLKIT_EXPORT OdBrMesh2dFilter
{
  const OdBrEntity* m_BrEntity;
  OdBrMesh2dControl m_meshControl;
public:

  /** \details
    Default constructor.
  */
  OdBrMesh2dFilter();

  /** \details
    Destructor.
  */
  ~OdBrMesh2dFilter();

  iterator insert(const value_type& x);

  /** \details
    Returns the topology object associated with the 2D mesh control.
  */
  const OdBrEntity* getBrEntity() const;

private:
  OdBrMesh2dFilter(const OdBrMesh2dFilter& src);
  OdBrMesh2dFilter& operator = (const OdBrMesh2dFilter& src);

  value_type mKeyValuePair;
};

inline
OdBrMesh2dFilter::OdBrMesh2dFilter(){}

inline
OdBrMesh2dFilter::~OdBrMesh2dFilter() {}

inline
iterator OdBrMesh2dFilter::insert(const value_type& x)
{
  mKeyValuePair.first = x.first; mKeyValuePair.second = x.second;
}

//ODA MODELER arx无此接口
inline
const OdBrEntity* OdBrMesh2dFilter::getBrEntity() const
{
  return m_BrEntity;
}

#endif
