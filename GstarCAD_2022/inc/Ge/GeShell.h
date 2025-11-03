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

#ifndef _ODGESHELL_INCLUDED_
#define _ODGESHELL_INCLUDED_ /* {Secret} */

#include "../Int32Array.h"
#include "../CmEntityColorArray.h"
#include "../CmTransparencyArray.h"
#include "../GsMarkerArray.h"
#include "../UInt16Array.h"
#include "../UInt8Array.h"
#include "../Gi/GiMaterial.h"

/**
     
    Library: TD_Ge

    {group:OdGe_Classes}
*/
class OdGeShell
{
  int                   m_nFaceStartIndex;
public:
  OdGeShell() : m_nFaceStartIndex(-1) {}

  OdGePoint3dArray      vertices;
  OdInt32Array          faces;

  OdUInt16Array         edgeColors;
  OdCmEntityColorArray  edgeTrueColors;
  OdArray<OdDbObjectId> edgeLayers;
  OdArray<OdDbObjectId> edgeLinetypes;
  OdGsMarkerArray       edgeSelectionMarkers;
  OdUInt8Array          edgeVisibilities;

  OdUInt16Array         faceColors;
  OdCmEntityColorArray  faceTrueColors;
  OdArray<OdDbObjectId> faceLayers;
  OdGeVector3dArray     faceNormals;
  OdGsMarkerArray       faceSelectionMarkers;
  OdUInt8Array          faceVisibilities;
  OdArray<OdDbObjectId> faceMaterials;
  OdArray<OdGiMapper>   faceMappers;
  OdCmTransparencyArray faceTransparencies;

  /**
    To be determined.
  */
  void addVertex(const OdGePoint3d& vertex)
  {
    vertices.push_back(vertex);
  }

  /**
    To be determined.
  */
  void endFace()
  {
    if(m_nFaceStartIndex>=0)
    {
      faces[m_nFaceStartIndex] *= (faces.size()-m_nFaceStartIndex-1);
      m_nFaceStartIndex = -1;
    }
  }

  /**
    To be determined.
  */
  void startFace(bool bHole = false)
  {
    ODA_ASSERT(m_nFaceStartIndex==-1); // endFace() wasn't called.
    m_nFaceStartIndex = faces.size();
    faces.push_back(bHole ? -1 : 1);
  }

  /**
    To be determined.
  */
  void addFaceVertex(int nVertexIndex)
  {
    edgeVisibilities.push_back(OdUInt8(nVertexIndex > 0));
    faces.push_back(abs(nVertexIndex)-1);
  }

  /**
    To be determined.
  */
  void draw(OdGiGeometry& geometry)
  {
    ODA_ASSERT(m_nFaceStartIndex<0 || faces[m_nFaceStartIndex]>2); // endFace() wasn't called.

    OdGiEdgeData edgeData;
    if (!edgeColors.isEmpty()) 
      edgeData.setColors((const short*)edgeColors.getPtr());
    if (!edgeTrueColors.isEmpty()) 
      edgeData.setTrueColors(edgeTrueColors.getPtr());
    if (!edgeLayers.isEmpty())
      edgeData.setLayers((OdDbStub**)edgeLayers.getPtr());
    if (!edgeLinetypes.isEmpty()) 
      edgeData.setLinetypes((OdDbStub**)edgeLinetypes.getPtr());
    if (!edgeSelectionMarkers.isEmpty()) 
      edgeData.setSelectionMarkers(edgeSelectionMarkers.getPtr());
    if (!edgeVisibilities.isEmpty()) 
      edgeData.setVisibility(edgeVisibilities.getPtr());

    OdGiFaceData faceData;
    if (!faceColors.isEmpty())
      faceData.setColors((const short*)faceColors.getPtr());
    if (!faceTrueColors.isEmpty()) 
      faceData.setTrueColors(faceTrueColors.getPtr());
    if (!faceLayers.isEmpty()) 
      faceData.setLayers((OdDbStub**)faceLayers.getPtr());
    if (!faceNormals.isEmpty()) 
      faceData.setNormals(faceNormals.getPtr());
    if (!faceSelectionMarkers.isEmpty()) 
      faceData.setSelectionMarkers(faceSelectionMarkers.getPtr());
    if (!faceVisibilities.isEmpty()) 
      faceData.setVisibility(faceVisibilities.getPtr());
    if (!faceMaterials.isEmpty()) 
      faceData.setMaterials((OdDbStub**)faceMaterials.getPtr());
    if (!faceMappers.isEmpty()) 
      faceData.setMappers(faceMappers.getPtr());
    if (!faceTransparencies.isEmpty()) 
      faceData.setTransparency(faceTransparencies.getPtr());

    geometry.shell(vertices.size(), vertices.getPtr(), faces.size(), faces.getPtr(), &edgeData, &faceData);
  }
};

#endif // _ODGESHELL_INCLUDED_
