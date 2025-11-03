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

#ifndef __FMMDL_ITERATORS_H__
#define __FMMDL_ITERATORS_H__

#include "../FacetModeler/Modeler/FMMdlBody.h"
#include "../FacetModeler/Modeler/FMMdlVertex.h"
#include "../FacetModeler/Modeler/FMMdlEdge.h"
#include "../FacetModeler/Modeler/FMMdlFace.h"

/**
  <group TA_Geometry>
*/
namespace FacetModeler
{

/** \details
   Body vertex iterator.
*/
class FMGEOMETRY_API VertexIterator
{
    public:
        /** \details
           Constructor.
        */
        VertexIterator( const Body* pBody );

        /** \details
           Returns whether iteration is finished.
        */
        bool done();

        /** \details
           Sets iterator to next item.
        */
        void next();

        /** \details
           Returns current item.
        */
        Vertex* get();

    private:
        Body* m_pOwner;
        Vertex* m_pCurrent;
        Vertex* m_pNext;
        Vertex* m_pFirst;
};

/** \details
   Body edge iterator.
*/
class FMGEOMETRY_API EdgeBodyIterator
{
    public:
        /** \details
        */
        EdgeBodyIterator( const Body* pBody );

        /** \details
           Returns whether iteration is finished.
        */
        bool done();

        /** \details
           Sets iterator to next item.
        */
        void next( bool* bNextLoop = 0 );

        /** \details
           Returns current item.
        */
        Edge* get();

    private:
        Body* m_pOwner;
        Face* m_pCurrentFace;
        Face* m_pFirstFace;
        OdUInt32 m_iCurrentLoop;
        Edge* m_pFirst;
        Edge* m_pCurrent;
        Edge* m_pNext;
};

/** \details
   Face edge iterator.
*/
class FMGEOMETRY_API EdgeFaceIterator
{
    public:
        /** \details
           Constructor.
        */
        EdgeFaceIterator( const Face* pFace );

        /** \details
           Returns whether iteration is finished.
        */
        bool done();

        /** \details
           Sets iterator to next item.
        */
        void next( bool* bNextLoop = 0 );

        /** \details
           Returns current item.
        */
        Edge* get();

    private:
        Face* m_pFace;
        OdUInt32 m_iCurrentLoop;
        Edge* m_pFirst;
        Edge* m_pCurrent;
        Edge* m_pNext;
};

/** \details
   Body face iterator.
*/
class FMGEOMETRY_API FaceIterator
{
    public:
        /** \details
           Constructor.
        */
        FaceIterator( const Body* pBody );

        /** \details
           Returns whether iteration is finished.
        */
        bool done();

        /** \details
           Sets iterator to next item.
        */
        void next();

        /** \details
           Returns current item.
        */
        Face* get();

    private:
        Body* m_pOwner;
        Face* m_pFirst;
        Face* m_pCurrent;
        Face* m_pNext;
};

}

#endif //__FMMDL_ITERATORS_H__
