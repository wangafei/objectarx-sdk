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

#ifndef __FMMDL_FACE_H__
#define __FMMDL_FACE_H__

#include "../FacetModeler/Modeler/FMMdlEntity.h"
#include "../FacetModeler/FMProfile3D.h"
#include "FMMdlBody.h"

/**
  <group TA_Geometry>
*/
namespace FacetModeler
{

const OdUInt32 VFF = FLAG(0);
const OdUInt32 OFF = FLAG(1);
const OdUInt32 SKIP_HATCH = FLAG(18);

struct Vertex2Surface;
class Surface;

/** \details
   Facet body face.
*/
class FMGEOMETRY_API Face : public Entity
{
    public:
        /** \details
           Returns next face.
        */
        Face* next() const;

        /** \details
           Returns previous face.
        */
        Face* prev() const;

        /** \details
           Returns face plane.
        */
        const OdGePlane& plane() const;

        /** \details
           Returns face normal.
        */
        OdGeVector3d normal() const;

        /** \details
           Returns whether face is convex.
        */
        bool isConvex() const;

        /** \details
           Returns whether face has holes.
        */
        bool hasHoles() const;

        /** \details
           Returns loop count.
        */
        OdUInt32 loopCount() const;

        /** \details
           Returns loop count.
        */
        void setLoopCount( OdUInt32 n );

        /** \details
           Returns loop edge count.
        */
        OdUInt32 loopEdgeCount( OdUInt32 iLoopIndex = 0 ) const;

        int      edgeCount     () const;
        Edge* edge( OdUInt32 edgeIndexInFace = 0 ) const;

        Edge*    edgeLoop      () const        { return mpEdgeLoop; }
        void     setEdgeLoop   (Edge*       e) { mpEdgeLoop = e;    }

        /** \details
           Appends edge to the loop specified by the index.
        */
        Edge* addEdge( OdUInt32 nLoop, FacetModeler::Vertex* pVertex, bool bInverseOrder = false );

        /** \details
           Returns index of loop, containing the edge owned by this face
        */
        OdUInt32 findLoop( const Edge* pEdge ) const;

        /** \details
           Returns face area.
        */
        double area() const;

        /** \details
           Removes plane information.
        */
        void deletePlane() const;

        /** \details
           Clears vertex tags.
        */
        void clearVertexTags();

        /** \details
           Clears edge tags.
        */
        void clearEdgeTags();

        /** \details
           Inverts face normal.
        */
        void negate();

        /** \details
           Returns 3D profile with transform.
        */
        void profile( Profile3D& rResult, const OdGePlane* pPlane = 0, bool bIncludeHoles = true) const;

        /** \details
           Face's orthogonal projection onto plane.
        */
        void profile( const OdGePlane& plane, Profile2D& result, bool bIncludeHoles = true, OdArray<const Edge*>* pSourceEdges = NULL ) const;

        /** \details
           Returns outer 2D profile with transform.
        */
        void profileOuter( Profile3D& rResult, const OdGePlane* pPlane = 0 ) const;

        /** \details
           Returns face orientation.
        */
        FaceOrientation orientation() const;

        /** \details
           Sets face orientation.
        */
        void setOrientation( FaceOrientation eOrientation );

        /** \details
           Returns the point of intersection of this face and the line.
           If the line is in the plane of this face, the method returns false and *pbCoplanar=true.
        */
        bool intersectLine( const OdGeLinearEnt3d& gLine, OdGePoint3d* pptResult = 0, bool* pbCoplanar = 0 ) const;

        /** \details
           Retuns Surface of this Face
        */
        Surface* surface( ) const { return m_pSurface; }

        /** \details
           Accessor for the color of current face
        */
        Color color() const { return m_iColor; }

        /** \details
           Accessor for the color of current face
        */
        void     setColor      (Color, bool edgesAlso = false, bool partnerEdgesAlso = false);

        //!DOM
        void debugValidate( bool bValidateEdgePartners = false ) const;

        //!DOM
        void nullLoopEdgesRefs();

        //!DOM
        struct EdgeLoop
        {
          EdgeLoop()
          {
            m_pFace = 0;
            m_pFirstEdge = 0;
            m_pNextLoop = 0;
          }
          Face* m_pFace;
          Edge* m_pFirstEdge;
          EdgeLoop* m_pNextLoop;

          void zero()
          {
            m_pNextLoop = NULL;
            m_pFirstEdge = NULL;
            m_pFace = NULL;
          }
        };

        //!DOM
        EdgeLoop* loop( OdUInt32 nLoop ) const;

        // all code below is secret and opened for testing purposes. DO NOT USE DIRECT ACCESS TO THESE VARIABLES!
    //protected:

        Face();
        ~Face();

    

        Face(const Face&);
        Face& operator=(const Face&);

        Face(const Circle3d&, int type, int approx, Body*);

        Face(const Point3d      plg       [],
          PolygonVertexData* vertexData[],
          int                numVertices, 
          const Vector3d&    plgNormal,
          int                type,  
          bool               checkPlanarity, 
          Body*);

        Face(Point3d            p[], 
          int                numEdges,
          int                type, 
          bool               checkPlanarity,
          Body*,
          Edge**             createdEdges = NULL); 

        Face(Vertex*            vertices[],
          Curve*             curves[],
          Edge*              partners[], 
          int                numEdges, 
          int                type, 
          bool               checkPlanarity, 
          Body*, 
          Edge**             createdEdges = NULL);

    //private:
        Face* clone( Body& to ) const;
        void clear();
        void evaluatePlane() const;

        // "This" face represents a positive face. The given holeFaces vector 
        // contains faces completely inside this face, coplanar with this faces, 
        // but with opposite orientation.
        //
        // The method joins the hole faces with this face by adding bridge edges.
        // The hole faces are then set to faces containg no edges. The result of 
        // this joining may be more than one well-formed face. All the faces are
        // returned in the faces vector. Notice that if the result is more than
        // one face, new faces are created and "this" face will become empty, i.e.
        // containing no edges
        // 
        void insertHoles(const std::vector<Face*>& holeFaces, // Hole faces, coplanar and completely inside "this" face
          Body*                     pBody,     // Body that receives the new vertices and new faces
          std::vector<Face*>&       faces);    // The resulting contiguous faces (may be more than one)

        EdgeLoop* insertLoop( OdUInt32 nIndex, Edge* pFirstEdge = 0 );

        Edge*          mpEdgeLoop;     // One edge in the loop of edges of the face

        // Previous face.
        Face* m_pPrev;

        // Next face.
        Face* m_pNext;

        // First loop.
        EdgeLoop m_Loops;

        // Cached face plane.
        mutable OdGePlane* m_Plane;

        // Surface
        Surface* m_pSurface;

        // Color
        Color m_iColor;

        friend class Body;
        friend class BodyInternalConsistencyRestorer;
        friend class BodyImpl;
        friend class Edge;
};

inline void Face::profileOuter( Profile3D& result, const OdGePlane* pPlane ) const {
  profile( result, pPlane, false );
}

/** \details
           Returns first edge from loop with specified index.
          
           \remarks
           Each face has at least one loop.
           */
Edge* firstEdgeInLoop( const Face* fFace, OdUInt32 nLoop = 0 );

#if 0
// debug finctions for memory leaks checking
class FaceTracker
{
  int m_id;
  std::map<Face*, int> m_faces;

public:
  FaceTracker()
  {
    m_id = 0;
  }

  ~FaceTracker();

  void FaceCreated(Face* pFace)
  {
    if(m_id == 5677163)
    {
      int breakHere = 0;
    }
    m_faces.insert(std::make_pair(pFace, m_id));
    m_id++;
  }

  void FaceDeleted(Face* pFace)
  {
    m_faces.erase(pFace);
  }

  void CheckFloatingEdges();
};

FaceTracker* GetFaceTracker();
#endif

}

#endif //__FMMDL_FACE_H__
