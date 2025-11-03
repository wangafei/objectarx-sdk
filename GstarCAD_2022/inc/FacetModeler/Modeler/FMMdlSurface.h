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

#ifndef __FMMDL_SURFACE_H__
#define __FMMDL_SURFACE_H__

#include "../FacetModeler/Modeler/FMMdlEntity.h"
#include "../Ge/GeLine3d.h"

/**
  <group TA_Geometry>
*/
namespace FacetModeler
{

  /** \details
     Facet body surface.
  */
  class FMGEOMETRY_API Surface : public Entity
  {
  public:
    /** \details
       Constructor.
    */
    Surface();

    enum Type {
      kUndefined    = 0,
      kCylinder     = 1,
      kCone         = 2,
      kSphere       = 3,
      kTorus        = 4
    };

    virtual Type type() const;
    virtual void normal( const FacetModeler::Vertex& atV, const Face& atF, OdGeVector3d& normal ) const;
    virtual void transform( const OdGeMatrix3d& x );
    virtual int compare( const Surface* pOther, double eps ) const;
    virtual Surface* copy( Body& to ) const;
    bool isEqivalent( const Surface* pTo, const OdGeTol& tol ) const;

    /** \details
       Returns next surface in body.
    */
    Surface* next() const;

    ~Surface();
  protected:
    int surface_compare( const Surface* pOther, double eps ) const;
    virtual Surface* clone( Body& to ) const;
    virtual bool _isEqivalent( const Surface& to, const OdGeTol& tol ) const;
  private:
    Surface(const Surface&);
    Surface& operator=(const Surface&);

  public:
    Surface* m_pNext;

    friend class Body;
    friend class BodyImpl;
  };

  class FMGEOMETRY_API Revolution : public Surface {
  public:
    Revolution( const OdGeLine3d& axis, const OdGeVector3d& startDir );

    void transform( const OdGeMatrix3d& x );
    const OdGeLine3d& axis() const;
    const OdGeVector3d& startDir() const;
    int compare( const Surface* pOther, double eps ) const;
  protected:
    OdGeLine3d m_axis;
    OdGeVector3d m_startDir;
  };

  class FMGEOMETRY_API Sphere : public Revolution {
  public:
    //mku 02/7/17 In fact there is no a default constructor //Sphere();
    Sphere( const OdGePoint3d& center, double radius, OdUInt32 approximation ); 

    Type type() const;
    const OdGePoint3d& center() const;
    double radius() const;
    OdUInt32 approximation() const;
    void normal( const FacetModeler::Vertex& atV, const Face& atF, OdGeVector3d& normal ) const;
    void transform( const OdGeMatrix3d& x );
    int compare( const Surface* pOther, double eps ) const;
    Surface* copy( Body& to ) const;
  protected:
    OdGePoint3d m_center;
    double m_radius;
    OdUInt32 m_approximation1;
    OdUInt32 m_approximation2;
  };

  class FMGEOMETRY_API Cylinder : public Revolution {
  public:
    Cylinder( const OdGeLine3d& lAxis, const OdGeVector3d& vStartDirection,
              double dRadius, OdUInt32 iAppriximation );

    Type type() const;
    double radius() const;
    OdUInt32 approximation() const;
    void normal( const FacetModeler::Vertex& atV, const Face& atF, OdGeVector3d& normal ) const;
    void transform( const OdGeMatrix3d& x );
    int compare( const Surface* pOther, double eps ) const;
    Surface* copy( Body& to ) const;
  protected:
    double m_radius;
    OdUInt32 m_approximation;
    OdUInt32 m_approximation2;
  };

  class FMGEOMETRY_API Cone : public Revolution {
  public:
    Cone( const OdGeLine3d& axis, const OdGeVector3d& startDir,
          double radius1, double radius2, OdUInt32 approx );

    Type type() const;
    double radius() const;
    double topRadius() const;
    double tanAngle() const;
    OdUInt32 approximation() const;
    void normal( const FacetModeler::Vertex& atV, const Face& atF, OdGeVector3d& normal ) const;
    void transform( const OdGeMatrix3d& x );
    int compare( const Surface* pOther, double e ) const;
    Surface* copy( Body& to ) const;
  protected:
    double m_radius;
    double m_tanAngle;
    OdUInt32 m_approximation;
    OdUInt32 m_approximation2;
  };

  class FMGEOMETRY_API Torus : public Revolution {
  public:
    Torus( const OdGeLine3d& axis, const OdGeVector3d& startDir,
           double majorRadius, double minorRadius, 
           OdUInt32 majorApprox, OdUInt32 minorApprox );

    Type type() const;
    double majorRadius() const;
    double minorRadius() const;
    OdUInt32 majorApproximation() const;
    OdUInt32 minorApproximation() const;
    void normal( const FacetModeler::Vertex& atV, const Face& atF, OdGeVector3d& normal ) const;
    void transform( const OdGeMatrix3d& x );
    int compare( const Surface* pOther, double e ) const;
    Surface* copy( Body& to ) const;
  protected:
    double m_majorRadius;
    double m_minorRadius;
    OdUInt32 m_majorApprox;
    OdUInt32 m_minorApprox;
  };

}

#endif //__FMMDL_SURFACE_H__
