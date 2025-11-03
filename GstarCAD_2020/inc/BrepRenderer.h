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



#ifndef _BREPRENDERER_H_
#define _BREPRENDERER_H_

#include "Wr/wrExport.h"
#include "Wr/wrTriangulationParams.h"

class OdGiCommonDraw ;
class OdGiViewportDraw;
class OdBrBrep;
class OdGeMatrix3d;

/** Description:
    This class is the base class for classes that provide platform-dependent ACIS rendering
    for Teigha.
    Library: TD_BrepRenderer

    {group:Other_Classes}
*/
class RENDER_EXPORT OdBrepRenderer
{
protected:
  OdBrepRenderer() {}

public:  
  
  virtual ~OdBrepRenderer() {}

  enum
  {
    kNothing      = 0,
    kIsolines     = 1,
    kEdges        = 2,
    kShells       = 4,
    kOrderedEdges = 8, //  Geometry is returned as closed loops.
    kSurfIsolines = 16
  };

  /** Description:
    Sets the BREP data for this Renderer object.
    Arguments:
    brep (I) BREP data.
  */
  virtual void setBrep(const OdBrBrep& brep) = 0;

  /** Description:
    Enables caching for this Renderer object.
  */
  virtual void enableCaching() = 0;
  /** Description:
    Disables caching for this Renderer object.
    Arguments:
    clearCache (I) Clears rendering cache if and only if true.
  */
  virtual void disableCaching(bool clearCache = true) = 0;
  /** Description:
    Returns true if and only if caching is enabled for this Renderer object.
  */
  virtual bool isCachingEnabled() const = 0;

  /** Description:
    Sets the Triangular Parameters for this Renderer object.
    Arguments:
    pTriangulationParams (I) Pointer to the Triangular Parameters.
  */
  virtual void setTriangulationParams(const wrTriangulationParams *pTriangulationParams) = 0;
  /** Description:
    Returns the Triangular Parameters for this Renderer object.
  */
  virtual const wrTriangulationParams * getTriangulationParams() const = 0;

  struct NumIsolines
  {
    OdUInt32 numU, numV;
  };

  /** Description:
    Creates a geometric representation of the BREP data of this Renderer object.
    
    Remarks:
    Returns true if and only if the geometric representation can be generated. 

    Arguments:
    pWd (I) Pointer to the OdGiCommonDraw  interface.
    geomType (I) Geometry type.
    
    Remarks:
    geomType must be a combination of one or more of the following:
    
    @table
    Name            Value
    kNothing        0   
    kIsolines       1
    kEdges          2
    kShells         4
    kOrderedEdges   8
    kSurfIsolines   16
  */
  virtual bool draw(OdGiCommonDraw * pWd, OdUInt32 geomType, const NumIsolines *pNumIsolines = 0) = 0;

  /** Description:
    Creates a silhouette representation of the BREP data of this Renderer object.
    Remarks:
    Returns true if and only if the silhouette representation can be generated. 

    Arguments:
    pVd (I) Pointer to the OdGiViewportDraw interface.
  */
  virtual bool drawSilhouettes(OdGiViewportDraw* pVd) = 0;

  /**
    Description:
    Applies the 3D transformation matrix to the BREP data of Renderer object.

    Arguments:
    xfm (I) 3D transformation matrix.
  */
  virtual void transformBy(const OdGeMatrix3d &xfm) = 0;
};

#endif //_BREPRENDERER_H_
