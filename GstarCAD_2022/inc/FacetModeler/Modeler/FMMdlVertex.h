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

#ifndef __FMMDL_VERTEX_H__
#define __FMMDL_VERTEX_H__

#include "../FacetModeler/Modeler/FMMdlEntity.h"

/**
  <group TA_Geometry>
*/
namespace FacetModeler
{

  class VertexSurfData;
  class Surface;

/** \details
   Facet body face.
*/
class FMGEOMETRY_API Vertex : public Entity
{
    public:
        /** \details
           Constructor.
           */
        Vertex();
        Vertex( const OdGePoint3d& ptPoint, Body* pBody );

        /** \details
           Returns vertex position.
        */
        const OdGePoint3d& point() const;

        /** \details
           Sets vertex position.
        */
        void setPoint( const OdGePoint3d& ptPoint );

        bool at( const Surface* pSurface ) const;

        void normal( const Face& atF, OdGeVector3d& normal ) const;

        void addSurfaceData( Surface* pSurface );

        void removeSurfaceData( Surface* pSurface );

        /** \details
           Returns previous vertex in body.
        */
        Vertex* prev() const;

        /** \details
           Returns next vertex in body.
        */
        Vertex* next() const;

        ~Vertex();

    private:
        Vertex(const Vertex&);
        Vertex& operator=(const Vertex&);
        Vertex* clone( Body& to ) const;

    public: // TEST TEST
        OdGePoint3d m_pt;

        Vertex* m_pPrev;
        Vertex* m_pNext;
        VertexSurfData* m_pSurfData;

    friend class Body;
    friend class BodyImpl;
};
    
}

#endif //__FMMDL_VERTEX_H__
