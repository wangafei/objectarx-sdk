#ifndef  __ACCONSTRAINEDGEOMETRY_H__
#define __ACCONSTRAINEDGEOMETRY_H__

#include "AcDbAssocPersSubentIdPE.h"
#include "AcConstraintGroupNode.h"
#include "AcGeomConstraint.h"
#include "genurb3d.h"
#include "acdb.h"

#include "../../inc/zAcConstrainedGeometry.h"

#ifndef AcConstrainedRigidSet
#define AcConstrainedRigidSet		ZcConstrainedRigidSet
#endif //#ifndef AcConstrainedRigidSet

#ifndef ACDB_PORT
#define ACDB_PORT		ZCDB_PORT
#endif //#ifndef ACDB_PORT

#ifndef AcConstrainedGeometry
#define AcConstrainedGeometry		ZcConstrainedGeometry
#endif //#ifndef AcConstrainedGeometry

#ifndef AcConstraintGroupNode
#define AcConstraintGroupNode		ZcConstraintGroupNode
#endif //#ifndef AcConstraintGroupNode

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS
 
#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef   Acad
#define   Acad		  Zcad
#endif //#ifndef   Acad

#ifndef AcArray
#define AcArray		ZcArray
#endif //#ifndef AcArray

#ifndef AcGeomConstraint
#define AcGeomConstraint		ZcGeomConstraint
#endif //#ifndef AcGeomConstraint

#ifndef AcDbFullSubentPathArray
#define AcDbFullSubentPathArray		ZcDbFullSubentPathArray
#endif //#ifndef AcDbFullSubentPathArray

#ifndef AcGeNurbCurve3d
#define AcGeNurbCurve3d		ZcGeNurbCurve3d
#endif //#ifndef AcGeNurbCurve3d

#ifndef AcConstrainedBoundedEllipse
#define AcConstrainedBoundedEllipse		ZcConstrainedBoundedEllipse
#endif //#ifndef AcConstrainedBoundedEllipse

#ifndef AcConstrainedPoint
#define AcConstrainedPoint		ZcConstrainedPoint
#endif //#ifndef AcConstrainedPoint

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef  AcGraphNode
#define  AcGraphNode		 ZcGraphNode
#endif //#ifndef  AcGraphNode

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcConstrainedImplicitPoint
#define AcConstrainedImplicitPoint		ZcConstrainedImplicitPoint
#endif //#ifndef AcConstrainedImplicitPoint

#ifndef AcConstrainedCurve
#define AcConstrainedCurve		ZcConstrainedCurve
#endif //#ifndef AcConstrainedCurve

#ifndef AcConstrainedLine
#define AcConstrainedLine		ZcConstrainedLine
#endif //#ifndef AcConstrainedLine

#ifndef AcGeVector3d
#define AcGeVector3d		ZcGeVector3d
#endif //#ifndef AcGeVector3d

#ifndef AcConstrainedConstructionLine
#define AcConstrainedConstructionLine		ZcConstrainedConstructionLine
#endif //#ifndef AcConstrainedConstructionLine

#ifndef AcConstrained2PointsConstructionLine
#define AcConstrained2PointsConstructionLine		ZcConstrained2PointsConstructionLine
#endif //#ifndef AcConstrained2PointsConstructionLine

#ifndef AcConstrainedDatumLine
#define AcConstrainedDatumLine		ZcConstrainedDatumLine
#endif //#ifndef AcConstrainedDatumLine

#ifndef AcConstrainedBoundedLine
#define AcConstrainedBoundedLine		ZcConstrainedBoundedLine
#endif //#ifndef AcConstrainedBoundedLine

#ifndef AcConstrainedCircle
#define AcConstrainedCircle		ZcConstrainedCircle
#endif //#ifndef AcConstrainedCircle

#ifndef AcConstrainedArc
#define AcConstrainedArc		ZcConstrainedArc
#endif //#ifndef AcConstrainedArc

#ifndef AcConstrainedEllipse
#define AcConstrainedEllipse		ZcConstrainedEllipse
#endif //#ifndef AcConstrainedEllipse

#ifndef AcConstrainedSpline
#define AcConstrainedSpline		ZcConstrainedSpline
#endif //#ifndef AcConstrainedSpline

#ifndef AcGeMatrix3d
#define AcGeMatrix3d		ZcGeMatrix3d
#endif //#ifndef AcGeMatrix3d

#ifndef AcDbAssocTransInfo
#define AcDbAssocTransInfo		ZcDbAssocTransInfo
#endif //#ifndef AcDbAssocTransInfo

#ifndef AcConstrainedGeometryDraggingInfo
#define AcConstrainedGeometryDraggingInfo		ZcConstrainedGeometryDraggingInfo
#endif //#ifndef AcConstrainedGeometryDraggingInfo

#ifndef AcString
#define AcString		ZcString
#endif //#ifndef AcString


#endif