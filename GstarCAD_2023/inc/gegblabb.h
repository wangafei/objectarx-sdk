/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEGBLABB_H
#define GC_GEGBLABB_H

#include "gegbl.h"

const int eGood = GcGe::eGood;
const int eBad = GcGe::eBad;

typedef GcGe::EntityId EntityId;

const GcGe::EntityId kEntity2d = GcGe::kEntity2d;
const GcGe::EntityId kEntity3d = GcGe::kEntity3d;
const GcGe::EntityId kPointEnt2d = GcGe::kPointEnt2d;
const GcGe::EntityId kPointEnt3d = GcGe::kPointEnt3d;
const GcGe::EntityId kPosition2d = GcGe::kPosition2d;
const GcGe::EntityId kPosition3d = GcGe::kPosition3d;
const GcGe::EntityId kPointOnCurve2d = GcGe::kPointOnCurve2d;
const GcGe::EntityId kPointOnCurve3d = GcGe::kPointOnCurve3d;
const GcGe::EntityId kBoundedPlane = GcGe::kBoundedPlane;
const GcGe::EntityId kCircArc2d = GcGe::kCircArc2d;
const GcGe::EntityId kCircArc3d = GcGe::kCircArc3d;
const GcGe::EntityId kConic2d = GcGe::kConic2d;
const GcGe::EntityId kConic3d = GcGe::kConic3d;
const GcGe::EntityId kCurve2d = GcGe::kCurve2d;
const GcGe::EntityId kCurve3d = GcGe::kCurve3d;
const GcGe::EntityId kEllipArc2d = GcGe::kEllipArc2d;
const GcGe::EntityId kEllipArc3d = GcGe::kEllipArc3d;
const GcGe::EntityId kHelix = GcGe::kHelix;
const GcGe::EntityId kLine2d = GcGe::kLine2d;
const GcGe::EntityId kLine3d = GcGe::kLine3d;
const GcGe::EntityId kLinearEnt2d = GcGe::kLinearEnt2d;
const GcGe::EntityId kLinearEnt3d = GcGe::kLinearEnt3d;
const GcGe::EntityId kLineSeg2d = GcGe::kLineSeg2d;
const GcGe::EntityId kLineSeg3d = GcGe::kLineSeg3d;
const GcGe::EntityId kPlanarEnt = GcGe::kPlanarEnt;
const GcGe::EntityId kExternalCurve3d = GcGe::kExternalCurve3d;
const GcGe::EntityId kExternalCurve2d = GcGe::kExternalCurve2d;
const GcGe::EntityId kPlane = GcGe::kPlane;
const GcGe::EntityId kRay2d = GcGe::kRay2d;
const GcGe::EntityId kRay3d = GcGe::kRay3d;
const GcGe::EntityId kSurface = GcGe::kSurface;
const GcGe::EntityId kSphere = GcGe::kSphere;
const GcGe::EntityId kCone = GcGe::kCone;
const GcGe::EntityId kTorus = GcGe::kTorus;
const GcGe::EntityId kCylinder = GcGe::kCylinder;
const GcGe::EntityId kSplineEnt2d = GcGe::kSplineEnt2d;
const GcGe::EntityId kSurfaceCurve2dTo3d = GcGe::kSurfaceCurve2dTo3d;
const GcGe::EntityId kSurfaceCurve3dTo2d = GcGe::kSurfaceCurve3dTo2d;

const GcGe::EntityId kPolyline2d = GcGe::kPolyline2d;
const GcGe::EntityId kAugPolyline2d = GcGe::kAugPolyline2d;
const GcGe::EntityId kNurbCurve2d = GcGe::kNurbCurve2d;
const GcGe::EntityId kDSpline2d = GcGe::kDSpline2d;
const GcGe::EntityId kCubicSplineCurve2d = GcGe::kCubicSplineCurve2d;
const GcGe::EntityId kSplineEnt3d = GcGe::kSplineEnt3d;
const GcGe::EntityId kPolyline3d = GcGe::kPolyline3d;
const GcGe::EntityId kAugPolyline3d = GcGe::kAugPolyline3d;
const GcGe::EntityId kNurbCurve3d = GcGe::kNurbCurve3d;
const GcGe::EntityId kDSpline3d = GcGe::kDSpline3d;
const GcGe::EntityId kCubicSplineCurve3d = GcGe::kCubicSplineCurve3d;
const GcGe::EntityId kTrimmedCrv2d = GcGe::kTrimmedCrv2d;
const GcGe::EntityId kCompositeCrv2d = GcGe::kCompositeCrv2d;
const GcGe::EntityId kCompositeCrv3d = GcGe::kCompositeCrv3d;
const GcGe::EntityId kEnvelope2d = GcGe::kEnvelope2d;

const GcGe::EntityId kExternalSurface = GcGe::kExternalSurface;
const GcGe::EntityId kNurbSurface = GcGe::kNurbSurface;
const GcGe::EntityId kOffsetSurface = GcGe::kOffsetSurface;
const GcGe::EntityId kTrimmedSurface = GcGe::kTrimmedSurface;
const GcGe::EntityId kCurveBoundedSurface = GcGe::kCurveBoundedSurface;
const GcGe::EntityId kPointOnSurface = GcGe::kPointOnSurface;
const GcGe::EntityId kExternalBoundedSurface = GcGe::kExternalBoundedSurface;
const GcGe::EntityId kCurveCurveInt2d = GcGe::kCurveCurveInt2d;
const GcGe::EntityId kCurveCurveInt3d = GcGe::kCurveCurveInt3d;
const GcGe::EntityId kBoundBlock2d = GcGe::kBoundBlock2d;
const GcGe::EntityId kBoundBlock3d = GcGe::kBoundBlock3d;
const GcGe::EntityId kOffsetCurve2d = GcGe::kOffsetCurve2d;
const GcGe::EntityId kOffsetCurve3d = GcGe::kOffsetCurve3d;
const GcGe::EntityId kPolynomCurve3d = GcGe::kPolynomCurve3d;
const GcGe::EntityId kBezierCurve3d = GcGe::kBezierCurve3d;
const GcGe::EntityId kObject = GcGe::kObject;
const GcGe::EntityId kFitData3d = GcGe::kFitData3d;
const GcGe::EntityId kHatch = GcGe::kHatch;
const GcGe::EntityId kTrimmedCurve2d = GcGe::kTrimmedCurve2d;
const GcGe::EntityId kTrimmedCurve3d = GcGe::kTrimmedCurve3d;
const GcGe::EntityId kCurveSampleData = GcGe::kCurveSampleData;

const GcGe::EntityId kEllipCone = GcGe::kEllipCone;
const GcGe::EntityId kEllipCylinder = GcGe::kEllipCylinder;
const GcGe::EntityId kIntervalBoundBlock = GcGe::kIntervalBoundBlock;
const GcGe::EntityId kClipBoundary2d = GcGe::kClipBoundary2d;
const GcGe::EntityId kExternalObject = GcGe::kExternalObject;
const GcGe::EntityId kCurveSurfaceInt = GcGe::kCurveSurfaceInt;
const GcGe::EntityId kSurfaceSurfaceInt = GcGe::kSurfaceSurfaceInt;

typedef GcGe::ExternalEntityKind ExternalEntityKind;

const GcGe::ExternalEntityKind kAcisEntity = GcGe::kAcisEntity;
const GcGe::ExternalEntityKind kExternalEntityUndefined
= GcGe::kExternalEntityUndefined;

typedef GcGe::NurbSurfaceProperties NurbSurfaceProperties;

const GcGe::NurbSurfaceProperties kOpen = GcGe::kOpen;
const GcGe::NurbSurfaceProperties kClosed = GcGe::kClosed;
const GcGe::NurbSurfaceProperties kPeriodic = GcGe::kPeriodic;
const GcGe::NurbSurfaceProperties kRational = GcGe::kRational;
const GcGe::NurbSurfaceProperties kNoPoles = GcGe::kNoPoles;
const GcGe::NurbSurfaceProperties kPoleAtMin = GcGe::kPoleAtMin;
const GcGe::NurbSurfaceProperties kPoleAtMax = GcGe::kPoleAtMax;
const GcGe::NurbSurfaceProperties kPoleAtBoth = GcGe::kPoleAtBoth;

typedef GcGe::PointContainment PointContainment;

const GcGe::PointContainment kInside = GcGe::kInside;
const GcGe::PointContainment kOutside = GcGe::kOutside;
const GcGe::PointContainment kOnBoundary = GcGe::kOnBoundary;

typedef GcGe::GcGeXConfig GcGeXConfig;

const GcGe::GcGeXConfig kNotDefined = GcGe::kNotDefined;
const GcGe::GcGeXConfig kUnknown = GcGe::kUnknown;
const GcGe::GcGeXConfig kLeftRight = GcGe::kLeftRight;
const GcGe::GcGeXConfig kRightLeft = GcGe::kRightLeft;
const GcGe::GcGeXConfig kLeftLeft = GcGe::kLeftLeft;
const GcGe::GcGeXConfig kRightRight = GcGe::kRightRight;
const GcGe::GcGeXConfig kPointLeft = GcGe::kPointLeft;
const GcGe::GcGeXConfig kPointRight = GcGe::kPointRight;
const GcGe::GcGeXConfig kLeftOverlap = GcGe::kLeftOverlap;
const GcGe::GcGeXConfig kOverlapLeft = GcGe::kOverlapLeft;
const GcGe::GcGeXConfig kRightOverlap = GcGe::kRightOverlap;
const GcGe::GcGeXConfig kOverlapRight = GcGe::kOverlapRight;
const GcGe::GcGeXConfig kOverlapStart = GcGe::kOverlapStart;
const GcGe::GcGeXConfig kOverlapEnd = GcGe::kOverlapEnd;
const GcGe::GcGeXConfig kOverlapOverlap = GcGe::kOverlapOverlap;

typedef GcGe::ErrorCondition  GcGeError;

const GcGe::ErrorCondition	kOk = GcGe::kOk;
const GcGe::ErrorCondition	k0This = GcGe::k0This;
const GcGe::ErrorCondition	k0Arg1 = GcGe::k0Arg1;
const GcGe::ErrorCondition	k0Arg2 = GcGe::k0Arg2;
const GcGe::ErrorCondition	kPerpendicularArg1Arg2 = GcGe::kPerpendicularArg1Arg2;
const GcGe::ErrorCondition	kEqualArg1Arg2 = GcGe::kEqualArg1Arg2;
const GcGe::ErrorCondition	kEqualArg1Arg3 = GcGe::kEqualArg1Arg3;
const GcGe::ErrorCondition	kEqualArg2Arg3 = GcGe::kEqualArg2Arg3;
const GcGe::ErrorCondition	kLinearlyDependentArg1Arg2Arg3 = GcGe::kLinearlyDependentArg1Arg2Arg3;
const GcGe::ErrorCondition	kArg1TooBig = GcGe::kArg1TooBig;
const GcGe::ErrorCondition	kArg1OnThis = GcGe::kArg1OnThis;
const GcGe::ErrorCondition	kArg1InsideThis = GcGe::kArg1InsideThis;

typedef GcGe::GcGeIntersectError GcGeIntersectError;

const GcGe::GcGeIntersectError kXXOk = GcGe::kXXOk;
const GcGe::GcGeIntersectError kXXIndexOutOfRange = GcGe::kXXIndexOutOfRange;
const GcGe::GcGeIntersectError kXXWrongDimensionAtIndex = GcGe::kXXWrongDimensionAtIndex;
const GcGe::GcGeIntersectError kXXUnknown = GcGe::kXXUnknown;

typedef GcGe::KnotParameterization KnotParameterization;

const GcGe::KnotParameterization kChord = GcGe::kChord;
const GcGe::KnotParameterization kSqrtChord = GcGe::kSqrtChord;
const GcGe::KnotParameterization kUniform = GcGe::kUniform;
const GcGe::KnotParameterization kCustomParameterization = GcGe::kCustomParameterization;
const GcGe::KnotParameterization kNotDefinedKnotParam = GcGe::kNotDefinedKnotParam;

#endif