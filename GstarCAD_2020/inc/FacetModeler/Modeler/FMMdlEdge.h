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

#ifndef __FMMDL_EDGE_H__
#define __FMMDL_EDGE_H__

#include "../FacetModeler/Modeler/FMMdlVertex.h"
#include "../FacetModeler/Modeler/FMMdlFace.h"
#include "../FacetModeler/Modeler/FMMdlPoint3d.h"

/**
<group TA_Geometry>
*/
namespace FacetModeler
{
  const Flag AEF    = FLAG(0); // Silhouette edge
  const Flag VEF    = FLAG(1); 
  const Flag BEF    = FLAG(1); // Bridge edge
  const Flag PICKEF = FLAG(2); // Pickable edge

  /** \details
  Facet body edge.
  */
  class FMGEOMETRY_API Edge : public Entity
  {
  public:
    /** \details
    Constructor.
    */
    Edge();

    /** \details
    Constructor.
    */
    Edge( FacetModeler::Vertex* pVertex,
      FacetModeler::Face* pFace, Edge* pPrevEdge, Edge* pPartner );

    /** \details
    Returns owner loop.
    */
    FacetModeler::Face::EdgeLoop* loop() const;

    /** \details
    Returns owner face.
    */
    FacetModeler::Face* face() const;

    /** \details
    Returns first vertex.
    */
    FacetModeler::Vertex* vertex() const;

    FacetModeler::Vertex* next_vertex() const;

    const OdGePoint3d& startPoint() const;

    const OdGePoint3d& endPoint() const;

    double length() const;

    OdGeVector3d vector() const;

    /** \details
    Returns next edge.
    */
    Edge* next() const;

    /** \details
    Returns previous edge.
    */
    Edge* prev() const;

    /** \details
    Returns manifold pair edge.

    \remarks
    Some epsilon-region between this->face() and pair()->face()
    must contain only INNER points of a valid 3d solid. The adjacent solid angle may contain inner and outer points.
    */
    Edge* pair() const;

    /** \details
    Returns next edge in a single-linked loop of superposed edges.
    */
    Edge* nextPartner() const;

    /** \details
    Returns true, if the edges are partners (superposed).
    */
    bool isPartner( const Edge* pEdge ) const;

    /** \details
    Returns true, if the edge is between exactly two faces.
    */
    bool isManifold() const;

    /** \details
    Returns planar angle between this edge and the previous one.

    \remarks
    Angle is measured in CCW direction with face normal as Z axis.
    The value is in the range [ 0 .. Oda2PI ]
    */
    double angleBetweenEdges() const;

    /** \details
    Returns inner angle between this face and neighboring face.

    \remarks
    The value is in the range [ 0 .. Oda2PI ]
    */
    double angleBetweenFaces() const;

    /** \details
    Returns unit normal vector to the edge.

    \remarks
    The vector points inside the owner face.
    */
    OdGeVector3d normal() const;

    /** \details
    Returns edge direction.
    */
    OdGeVector3d direction() const;

    /** \details
    Returns edge loop normal multiplied by area of the edge loop.
    */
    OdGeVector3d calculateLoopNormal() const;

    /** \details
    Sets next edge. Low level operation!
    */
    void setNext( Edge* pNext );

    /** \details
    Sets prev edge. Low level operation!
    */
    void setPrev( Edge* pPrev );

    /** \details
    Sets pair edge. Low level operation!
    */
    void setPair( Edge* pPair );

    /** \details
    Sets vertex. Low level operation!
    */
    void setVertex( FacetModeler::Vertex* pVertex );

    /** \details
    Sets owner face. Low level operation!
    */
    void setFace( FacetModeler::Face* pFace );

    // Sets owner loop. Low level operation!
    void setLoop( FacetModeler::Face::EdgeLoop* pLoop );

    /** \details
    Adds partner edge. Low level operation!
    */
    void addPartner( Edge* pPartner );

    /** \details
    Removes partner edge. Low level operation!
    */
    void removePartner();

    /** \details
    Updates list of partner edges. Low level operation!
    */
    void updatePartnerPairs();

    //!DOM
    void debugValidate( bool bTestPartners = true ) const;

    //!DOM
    void debugValidateLoop( bool bTestPartners = true ) const;

    /** \details
    Sets color
    */
    void setColor(Color iColor);

    /** \details
    Gets color
    */
    Color color() const;

    void zero();

    //!DOM
    void setPartner(Edge* pPartner) { m_pNextPartner = pPartner; }

    /** \details
    Returns true for exactly one of the partner edges representing a "real" "Euler" edge.
    */
    bool isEulerEdge() const;

    bool isBridge() const;
    bool isApprox() const;

    void setBridgeFlag(OnOff iOn = kOn);
    void setApproxFlag(OnOff iOn = kOn);

    /** \details
    For AModeler compatibility reason. See nextPartner() for more details.
    */
    Edge* partner() const;

    Point3d point() const;

    ~Edge();

  private:
    static void addEdge( Face::EdgeLoop& loop, Edge* pEdge, bool bInverseOrder );

    Edge(const Edge&);
    Edge& operator=(const Edge&);

    // Owner face.
    Face* m_pFace;

    // Owner loop
    Face::EdgeLoop* m_pLoop;

    // Start vertex.
    Vertex* m_pVertex;

    // Previous edge.
    Edge* m_pPrevEdge;

    // Next edge.
    Edge* m_pNextEdge;

    // Overlapping edge from neighboring face.
    Edge* m_pPairEdge;

    // Next edge in a single-linked loop of overlapping edges.
    Edge* m_pNextPartner;

    // Edge color
    Color m_iColor;

    friend class Body;
    friend class BodyImpl;
    friend class Face;
    friend class BodyInternalConsistencyRestorer;
  };


  // Inline alias method for the statement: this->next()->vertex();
  inline Vertex* Edge::next_vertex() const {
    return next()->vertex();
  }

  inline Face::EdgeLoop* Edge::loop() const {
    return m_pLoop;
  }

  inline const OdGePoint3d& Edge::startPoint() const {
    return vertex()->point();
  }

  inline const OdGePoint3d& Edge::endPoint() const {
    return next_vertex()->point();
  }

  inline double Edge::length() const {
    return startPoint().distanceTo( endPoint() );
  }

  inline OdGeVector3d Edge::vector() const {
    return endPoint() - startPoint();
  }

  inline void Edge::setLoop( Face::EdgeLoop* pLoop ) {
    m_pLoop = pLoop;
  }


  inline Point3d Edge::point() const
  {
    return vertex()->point();
  }

  inline bool Edge::isBridge() const
  {
    return isFlagOn(BEF);
  }

  inline bool Edge::isApprox() const
  {
    return isFlagOn(AEF);
  }

#if 0
  // debug finctions for memory leaks checking
  class EdgeTracker
  {
    int m_id;
    std::map<Edge*, int> m_edges;

  public:
    EdgeTracker()
    {
      m_id = 0;
    }

    ~EdgeTracker();


    void EdgeCreated(Edge* pEdge);

    void EdgeDeleted(Edge* pEdge)
    {
      m_edges.erase(pEdge);
    }

    void GetEdges(std::map<Edge*, int>& edges)
    {
      edges = m_edges;
    }
  };

  EdgeTracker* GetEdgeTracker();
#endif

}

#endif //__FMMDL_EDGE_H__
