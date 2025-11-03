#pragma once
#include "AcDbAssocPersSubentIdPE.h"
#include "AcConstraintGroupNode.h"
#include "AcGeomConstraint.h"
#include "genurb3d.h"
#include "../OdConstrainedGeometry.h"


#define AcConstrainedGeometry GcConstrainedGeometry
#define GcConstrainedGeometry OdConstrainedGeometry

#define AcConstrainedImplicitPoint	GcConstrainedImplicitPoint
#define GcConstrainedImplicitPoint	OdConstrainedImplicitPoint

#define AcConstrainedCurve		GcConstrainedCurve
#define GcConstrainedCurve		OdConstrainedCurve

#define AcConstrainedLine		GcConstrainedLine
#define GcConstrainedLine		OdConstrainedLine
#define AcConstrainedConstructionLine GcConstrainedConstructionLine
#define GcConstrainedConstructionLine OdConstrainedConstructionLine

#define AcConstrained2PointsConstructionLine  GcConstrained2PointsConstructionLine
#define GcConstrained2PointsConstructionLine  OdConstrained2PointsConstructionLine

#define AcConstrainedDatumLine  GcConstrainedDatumLine
#define GcConstrainedDatumLine  OdConstrainedDatumLine

#define AcConstrainedBoundedLine  GcConstrainedBoundedLine
#define GcConstrainedBoundedLine  OdConstrainedBoundedLine

#define AcConstrainedCircle		GcConstrainedCircle
#define GcConstrainedCircle		OdConstrainedCircle

#define AcConstrainedArc  GcConstrainedArc
#define GcConstrainedArc  OdConstrainedArc

#define AcConstrainedEllipse	GcConstrainedEllipse
#define GcConstrainedEllipse	OdConstrainedEllipse

#define AcConstrainedBoundedEllipse  GcConstrainedBoundedEllipse
#define GcConstrainedBoundedEllipse  OdConstrainedBoundedEllipse

#define AcConstrainedSpline		GcConstrainedSpline
#define GcConstrainedSpline		OdConstrainedSpline

#define AcConstrainedRigidSet	GcConstrainedRigidSet
#define GcConstrainedRigidSet	OdConstrainedRigidSet

#define AcConstrainedGeometryDraggingInfo  GcConstrainedGeometryDraggingInfo
#define GcConstrainedGeometryDraggingInfo  OdConstrainedGeometryDraggingInfo

#define AcConstrainedPoint		GcConstrainedPoint
#define GcConstrainedPoint		OdConstrainedPoint

struct OdConstrainedGeometryDraggingInfo : OdDbAssocTransInfo
{

	OdDbFullSubentPathArray maGeomFullSubentPaths;


	OdArray<OdConstrainedGeometry *> maDraggingGeometries;


  TOOLKIT_EXPORT static const OdString& getKey()
  {
    throw OdError(eNotImplemented);
  }
};