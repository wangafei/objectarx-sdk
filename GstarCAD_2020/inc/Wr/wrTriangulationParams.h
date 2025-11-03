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

#ifndef _TRIANGULATIONPARAMS_H_
#define _TRIANGULATIONPARAMS_H_

#include "../OdHeap.h"

/** Description:
    This container class holds ACIS triangulation (rendering) parameters. 
    {group:Other_Classes}
*/
class wrTriangulationParams
{
public:
  OdUInt32 maxNumGridLines;     // Maximum number of grid lines.
  double   maxFacetEdgeLength;  // Maximum facet edge length
  double   normalTolerance;     // Normal tolerance for parallel faces
  double   surfaceTolerance;    // Distance tolerance for coincident faces.
  double   gridAspectRatio;     // Grid aspect ratio
  OdUInt16 BetweenKnots;        // Distance between knots
  OdUInt32 PointsPerEdge;       // Points / Edge
  bool     bUseFacetRES;        // Use Facetres System variable.
  bool     bFastMode;           // Fast mode is much more faster, but generates more errors.


  // default triangulation parameters
  /** Remarks:
    Default triangulation parameters:
    
    @table
    Parameter             Default
    maxNumGridLines       10000  
    maxFacetEdgeLength    0  
    normalTolerance       15  
    surfaceTolerance      0  
    gridAspectRatio       0  
    PointsPerEdge         0  
    BetweenKnots          2  
    bUseFacetRES          false  
  */
  wrTriangulationParams()
  : maxNumGridLines(10000)
  , maxFacetEdgeLength(0)
  , normalTolerance(15)
  , surfaceTolerance(0)
  , gridAspectRatio(0)
  , BetweenKnots(2)
  , PointsPerEdge(0)
  , bUseFacetRES(false)
  , bFastMode(false)
  {
  }

  /**
    Note:
    bUseFacetRES is NOT part of the comparison.
  */
  bool operator ==(const wrTriangulationParams other) const 
  {
    return other.maxNumGridLines == maxNumGridLines
    && other.maxFacetEdgeLength == maxFacetEdgeLength
    && other.normalTolerance == normalTolerance
    && other.surfaceTolerance == surfaceTolerance
    && other.gridAspectRatio == gridAspectRatio
    && other.PointsPerEdge == PointsPerEdge
    && other.BetweenKnots == BetweenKnots;
    // bUseFacetRES, bFastMode skipped
  }
};

#endif // _TRIANGULATIONPARAMS_H_
