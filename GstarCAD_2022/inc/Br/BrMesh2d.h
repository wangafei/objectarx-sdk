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
#ifndef BRMESH2D_H_INCLUDED
#define BRMESH2D_H_INCLUDED

#include "../Br/BrMesh.h"
#include "../Br/BrMesh2dFilter.h"

class OdBrMesh2dData;

/** \details
  This class defines the interface class for 2D meshes. 

  \remarks 
  This class is implemented only for Spatial modeler.

  \sa
  TD_Br

  <group OdBr_Classes>
*/
class ODBR_TOOLKIT_EXPORT OdBrMesh2d : public OdBrMesh
{
public:
  ODRX_DECLARE_MEMBERS(OdBrMesh2d);

  /** \details
    Default constructor.
  */
  OdBrMesh2d();
  OdBrMesh2d(const OdBrMesh2d& src);

  /** \details
    Destructor.
  */
  ~OdBrMesh2d();

  // Assignment operator
  OdBrMesh2d& operator =(const OdBrMesh2d& src);

  OdBrErrorStatus set(OdBrMesh2dData* mesh2d);
  OdBrErrorStatus get(OdBrMesh2dData*& mesh2d) const;

  OdBrErrorStatus generate(const OdBrMesh2dFilter& meshFilter);
};

#endif
