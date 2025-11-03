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

#ifndef _SpatialIndex_h_Included_
#define _SpatialIndex_h_Included_


#include "../OdPlatformSettings.h"

#ifdef SPATIALINDEX_DLL_EXPORTS
  #define ODSI_API          OD_TOOLKIT_EXPORT
  #define ODSI_API_STATIC   OD_STATIC_EXPORT
#else
  #define ODSI_API          OD_TOOLKIT_IMPORT
  #define ODSI_API_STATIC   OD_STATIC_IMPORT
#endif

//////////////////////////////////////////////////////////////////////////

#include "../RxObject.h"
#include "../Ge/GeExtents3d.h"
#include "../Ge/GeExtents2d.h"

#include "../TD_PackPush.h"

/** Description:
    This class represents Spatial Index Shape objects.
    Library: SpatialIndex
    {group:OdSi_Classes}
*/
struct ODSI_API OdSiShape
{
  /**
    Description:
    Returns true if and only if this Shape object *contains* the specfied *extents*.

    Arguments:
    extents (I) Any 3D *extents* box.
    planar (I) If and only if true, a *planar* computation is made.
  */
  virtual bool contains( const OdGeExtents3d& extents, bool planar, const OdGeTol& tol = OdGeContext::gTol ) const = 0;
  /**
    Description:
    Returns true if and only if this Shape object *intersects* the specfied *extents*.

    Arguments:
    extents (I) Any 3D *extents* box.
    planar (I) If and only if true, a *planar* computation is made.
  */
  virtual bool intersects( const OdGeExtents3d& extents, bool planar, const OdGeTol& tol = OdGeContext::gTol ) const = 0;

  virtual ~OdSiShape() {};
  virtual OdSiShape* clone() const { return 0; }
  virtual void transform(const OdGeMatrix3d&) {};

  ODSI_API_STATIC static const OdSiShape& kOverallSpace;
  ODSI_API_STATIC static const OdSiShape& kNoSpace;
};
/** Description:
    This class represents Spatial Index Entity objects.
    Library: SpatialIndex

    {group:OdSi_Classes}
*/
struct OdSiEntity
{
  /**
    Description:
    Returns the *extents* of this Entity object.

    Arguments:
    extents (O) Receives the *extents*.
    Remarks:
    Returns true if and only if this Entity object has *extents*.
  */
  virtual bool extents(OdGeExtents3d& extents) const = 0;
};

/** Description:
    This class represents Spatial Index Visitor Objects
    Library: SpatialIndex
    {group:OdSi_Classes}
*/
struct OdSiVisitor
{
  /** Description:
    entity (I) Pointer to any OdSiEntity object.
    completelyInside (I) unknown.
  */
  virtual void visit( OdSiEntity* entity, bool completelyInside ) = 0;
};

class ODSI_API OdSiSpatialIndex;
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdSiSpatialIndex object pointers.
*/
typedef OdSmartPtr<OdSiSpatialIndex> OdSiSpatialIndexPtr;

/** Description:
    This class represents SpatialIndex objects.
    Library: SpatialIndex
    {group:OdSi_Classes}
*/
class ODSI_API OdSiSpatialIndex : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdSiSpatialIndex);
  /** Description:
    Creates a SpatialIndex object with the specified parameters.
    Arguments:
    planar (I) Creates a 2D SpatialIndex if true, a 3D if false.
    maxDepth (I) Maximum depth of the Spatial Index.
    maxCount (I) Maximum number of nodes in the SpatialIndex.
    eps (I) Relative tolerance (equalVector).

    Remarks:
    Returns a SmartPointer to the new SpatialIndex object.

    maxDepth specifies the maximum number of times the tree-structured SpatialIndex can branch.
  */
  static OdSiSpatialIndexPtr createObject( bool planar, unsigned int maxDepth = 16, unsigned int maxCount = 1024, double eps = 1e-10 );
  /** Description:
    Inserts the specified SiEntity object into the this SpatialIndex object.
    Arguments:
    entity (I) Pointer to the OdSiEntity to insert.
  */
  virtual void insert( OdSiEntity* entity ) = 0;
  /** Description:
    Removes the specified SiEntity object into the this SpatialIndex object.
    Arguments:
    entity (I) Pointer to the OdSiEntity to remove.
    Remarks:
    Returns true if and only if the specified *entity* was in this SpatialIndex object.
  */
  virtual bool remove( OdSiEntity* entity ) = 0;

  /** Description:
    Arguments:
    shape (I) Any OdSiShape object.
    visitor (I) Any OdSiVisitor object.
  */
  virtual void query( const OdSiShape& shape, OdSiVisitor& visitor ) const = 0;
  /** Description:
    Clears this SpatialIndex object.
  */
  virtual void clear() = 0;
  /** Description:
    Sets the maximum depth of this SpatialIndex object.
    Arguments:
    maxDepth (I) Maximum depth.
    Remarks:
    maxDepth specifies the maximum number of times the tree-structured SpatialIndex can branch.
  */
  virtual void setMaxTreeDepth( unsigned char maxDepth ) = 0;
  /** Description:
    Sets the maxiumum number of nodes in this SpatialIndex object.
    Arguments:
    maxCount (I) Maximum number of nodes.
  */
  virtual void setMaxNodeSize( unsigned char maxCount ) = 0;
  /**
    Description:
    Returns the *extents* of this SpatialIndex object.

    Arguments:
    extents (O) Receives the *extents*.
    Remarks:
    Returns true if and only if this SpatialIndex object has *extents*.
  */
  virtual bool extents(OdGeExtents3d& extents) const = 0;

  /** Description:
    Returns the maximum depth of this SpatialIndex object.
    Remarks:
    maxDepth specifies the maximum number of times the tree-structured SpatialIndex can branch.
  */
  virtual unsigned maxTreeDepth() const = 0;

  /** Description:
    Returns the maxiumum number of nodes in this SpatialIndex object.
  */
  virtual unsigned maxNodeSize() const = 0;

  /**
    Description:
    Returns the *tolerance* of this SpatialIndex object.

    Remarks:
    Returns tolerance where *equalPoint* value is scaled by *extents* of SpatialIndex.
  */
  virtual const OdGeTol& tolerance() const = 0;
  virtual void setTolerance(const OdGeTol& tol) = 0;
};

#include "../TD_PackPop.h"

#endif
