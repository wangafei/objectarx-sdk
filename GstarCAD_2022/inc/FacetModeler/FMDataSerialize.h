/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2002-2017, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) Copyright (C) 2002-2017 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////
#ifndef _FM_DATA_SERIALIZE_
#define _FM_DATA_SERIALIZE_

#include <../OdaCommon.h>
#include "../OdPlatformSettings.h"
#include "../FacetModeler/Modeler/FMMdlBody.h"
#include "../FacetModeler/Modeler/FMMdlVertex.h"
#include <map>

namespace FacetModeler
{

  static FacetModeler::BodyImpl* GetBodyImpl(const FacetModeler::Body& val)
  {
    FacetModeler::BodyImpl* pBodyImpl = *((FacetModeler::BodyImpl**)(&val));
    return pBodyImpl;
  }

  struct VertexImage
  {
    VertexImage() : pVtx(NULL), pPrev(NULL), pNext(NULL), pKey(NULL)
    {}
    FacetModeler::Vertex* pVtx;
    void* pKey;
    void* pPrev;
    void* pNext;
  };

  struct EdgeImage
  {
    EdgeImage() : pEdge(NULL), pFaceKey(NULL), pLoopKey(NULL),
      pVertexKey(NULL), pPrevKey(NULL), pNextKey(NULL), pPairKey(NULL), pPartnerKey(NULL)
    {}

    FacetModeler::Edge* pEdge;
    void* pFaceKey;
    void* pLoopKey;
    void* pVertexKey;
    void* pPrevKey;
    void* pNextKey;
    void* pPairKey;
    void* pPartnerKey;
  };

  struct LoopImage
  {
    LoopImage() : pLoopKey(NULL)
    {}

    void* pLoopKey;
    std::vector<void*> edgeKeys;
  };

  typedef std::vector<LoopImage> LoopImages;

  struct FaceImage
  {
    FaceImage() : pFace(NULL), pPrevKey(NULL), pNextKey(NULL)
    {}

    FacetModeler::Face* pFace;
    void* pFaceKey;
    void* pPrevKey;
    void* pNextKey;

    LoopImages loopImages;
  };

  typedef std::vector<VertexImage> VertexImages;
  typedef std::map<void*, EdgeImage> EdgeImages;
  typedef std::vector<FaceImage> FaceImages;

  class FMGEOMETRY_API BinaryStream
  {
    FILE* m_hFile;

  public:
    enum OdaObjectMarker
    {
      ePoint2dMarker = 1,
      eContour2dMarker = 2,
      eProfile2dMarker = 3,
      eBodyMarker = 4,
      eFaceMarker = 5,
      ePoint3dMarker = 6
    };

  public:
    BinaryStream();
    ~BinaryStream();

    bool Create(const OdString& szFile);
    bool Open(const OdString& szFile);

    void Write(const void* pData, size_t length);
    void Read(void* pData, size_t length);

    template<typename T>
    void Write(const T val)
    {
      Write(&val, sizeof(val));
    }

    void Write(const OdGePoint2d& val);
    void Write(const FacetModeler::Contour2D& val);
    void Write(const FacetModeler::Profile2D& val);

    void Write(const OdGePoint3d& val);
    void Write(const FacetModeler::Face& val);
    void Write(const FacetModeler::Body& val);

    void WriteVertexList(FacetModeler::Vertex* pVertexList, OdUInt32 uVtxCount);
    void WriteVertex(FacetModeler::Vertex* pVertex);
    void WriteEdgesList(const FacetModeler::Body& val);
    void WriteEdge(FacetModeler::Edge* pEdge);

    template<typename T>
    void Read(T& val)
    {
      Read(&val, sizeof(val));
    }

    void Read(OdGePoint2d& val);
    void Read(FacetModeler::Contour2D& val);
    void Read(FacetModeler::Profile2D& val);

    void Read(OdGePoint3d& val);
    void ReadFaceToBody(FacetModeler::Body& val);
    void Read(FacetModeler::Body& val);

    void ReadVertexImages(VertexImages& vertexImages, FacetModeler::Body* pBody);
    void SetVertexListForBody(VertexImages& vertexImages, FacetModeler::Body& val);

    void ReadEdgeImages(EdgeImages& edgeImages);
    void ReadFaceImages(FaceImages& faceImages);
  };

} // ::
#endif //_FM_DATA_SERIALIZE_
