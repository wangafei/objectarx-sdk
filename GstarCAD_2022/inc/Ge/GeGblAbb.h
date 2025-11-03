#pragma once

#include "GeGbl.h"

const int eGood = OdGe::eGood;
const int eBad = OdGe::eBad;

typedef OdGe::EntityId EntityId;

const OdGe::EntityId kEntity2d = OdGe::kEntity2d;
const OdGe::EntityId kEntity3d = OdGe::kEntity3d;
const OdGe::EntityId kPointEnt2d = OdGe::kPointEnt2d;
const OdGe::EntityId kPointEnt3d = OdGe::kPointEnt3d;
const OdGe::EntityId kPosition2d = OdGe::kPosition2d;
const OdGe::EntityId kPosition3d = OdGe::kPosition3d;
const OdGe::EntityId kPointOnCurve2d = OdGe::kPointOnCurve2d;
const OdGe::EntityId kPointOnCurve3d = OdGe::kPointOnCurve3d;
const OdGe::EntityId kBoundedPlane = OdGe::kBoundedPlane;
const OdGe::EntityId kCircArc2d = OdGe::kCircArc2d;
const OdGe::EntityId kCircArc3d = OdGe::kCircArc3d;
const OdGe::EntityId kConic2d = OdGe::kConic2d;
const OdGe::EntityId kConic3d = OdGe::kConic3d;
const OdGe::EntityId kCurve2d = OdGe::kCurve2d;
const OdGe::EntityId kCurve3d = OdGe::kCurve3d;
const OdGe::EntityId kEllipArc2d = OdGe::kEllipArc2d;
const OdGe::EntityId kEllipArc3d = OdGe::kEllipArc3d;
const OdGe::EntityId kLine2d = OdGe::kLine2d;
const OdGe::EntityId kLine3d = OdGe::kLine3d;
const OdGe::EntityId kLinearEnt2d = OdGe::kLinearEnt2d;
const OdGe::EntityId kLinearEnt3d = OdGe::kLinearEnt3d;
const OdGe::EntityId kLineSeg2d = OdGe::kLineSeg2d;
const OdGe::EntityId kLineSeg3d = OdGe::kLineSeg3d;
const OdGe::EntityId kPlanarEnt = OdGe::kPlanarEnt;
const OdGe::EntityId kExternalCurve3d = OdGe::kExternalCurve3d;
const OdGe::EntityId kExternalCurve2d = OdGe::kExternalCurve2d;
const OdGe::EntityId kPlane = OdGe::kPlane;
const OdGe::EntityId kRay2d = OdGe::kRay2d;
const OdGe::EntityId kRay3d = OdGe::kRay3d;
const OdGe::EntityId kSurface = OdGe::kSurface;
const OdGe::EntityId kSphere = OdGe::kSphere;
const OdGe::EntityId kCone = OdGe::kCone;
const OdGe::EntityId kTorus = OdGe::kTorus;
const OdGe::EntityId kCylinder = OdGe::kCylinder;
const OdGe::EntityId kSplineEnt2d = OdGe::kSplineEnt2d;
const OdGe::EntityId kSurfaceCurve2dTo3d = OdGe::kSurfaceCurve2dTo3d;
const OdGe::EntityId kLWPolyine3d = OdGe::kLWPolyine3d;

const OdGe::EntityId kSurfaceCurve3dTo2d = OdGe::kSurfaceCurve3dTo2d;

const OdGe::EntityId kPolyline2d = OdGe::kPolyline2d;
const OdGe::EntityId kAugPolyline2d = OdGe::kAugPolyline2d;
const OdGe::EntityId kNurbCurve2d = OdGe::kNurbCurve2d;
const OdGe::EntityId kDSpline2d = OdGe::kDSpline2d;
const OdGe::EntityId kCubicSplineCurve2d = OdGe::kCubicSplineCurve2d;
const OdGe::EntityId kSplineEnt3d = OdGe::kSplineEnt3d;
const OdGe::EntityId kPolyline3d = OdGe::kPolyline3d;
const OdGe::EntityId kAugPolyline3d = OdGe::kAugPolyline3d;
const OdGe::EntityId kNurbCurve3d = OdGe::kNurbCurve3d;
const OdGe::EntityId kDSpline3d = OdGe::kDSpline3d;
const OdGe::EntityId kCubicSplineCurve3d = OdGe::kCubicSplineCurve3d;
const OdGe::EntityId kTrimmedCrv2d = OdGe::kTrimmedCrv2d;
const OdGe::EntityId kCompositeCrv2d = OdGe::kCompositeCrv2d;
const OdGe::EntityId kCompositeCrv3d = OdGe::kCompositeCrv3d;
const OdGe::EntityId kEnvelope2d = OdGe::kEnvelope2d;

const OdGe::EntityId kExternalSurface = OdGe::kExternalSurface;
const OdGe::EntityId kNurbSurface = OdGe::kNurbSurface;
const OdGe::EntityId kOffsetSurface = OdGe::kOffsetSurface;
const OdGe::EntityId kTrimmedSurface = OdGe::kTrimmedSurface;
const OdGe::EntityId kCurveBoundedSurface = OdGe::kCurveBoundedSurface;
const OdGe::EntityId kPointOnSurface = OdGe::kPointOnSurface;
const OdGe::EntityId kExternalBoundedSurface = OdGe::kExternalBoundedSurface;
const OdGe::EntityId kCurveCurveInt2d = OdGe::kCurveCurveInt2d;
const OdGe::EntityId kCurveCurveInt3d = OdGe::kCurveCurveInt3d;
const OdGe::EntityId kBoundBlock2d = OdGe::kBoundBlock2d;
const OdGe::EntityId kBoundBlock3d = OdGe::kBoundBlock3d;
const OdGe::EntityId kOffsetCurve2d = OdGe::kOffsetCurve2d;
const OdGe::EntityId kOffsetCurve3d = OdGe::kOffsetCurve3d;
const OdGe::EntityId kPolynomCurve3d = OdGe::kPolynomCurve3d;
const OdGe::EntityId kBezierCurve3d = OdGe::kBezierCurve3d;
const OdGe::EntityId kObject = OdGe::kObject;
const OdGe::EntityId kFitData3d = OdGe::kFitData3d;
const OdGe::EntityId kHatch = OdGe::kHatch;
const OdGe::EntityId kTrimmedCurve2d = OdGe::kTrimmedCurve2d;
const OdGe::EntityId kTrimmedCurve3d = OdGe::kTrimmedCurve3d;
const OdGe::EntityId kCurveSampleData = OdGe::kCurveSampleData;

const OdGe::EntityId kEllipCone = OdGe::kEllipCone;
const OdGe::EntityId kEllipCylinder = OdGe::kEllipCylinder;
const OdGe::EntityId kIntervalBoundBlock = OdGe::kIntervalBoundBlock;
const OdGe::EntityId kClipBoundary2d = OdGe::kClipBoundary2d;
const OdGe::EntityId kExternalObject = OdGe::kExternalObject;
const OdGe::EntityId kCurveSurfaceInt = OdGe::kCurveSurfaceInt;
const OdGe::EntityId kSurfaceSurfaceInt = OdGe::kSurfaceSurfaceInt;


typedef OdGe::ExternalEntityKind ExternalEntityKind;

const OdGe::ExternalEntityKind kAcisEntity = OdGe::kAcisEntity;
const OdGe::ExternalEntityKind kExternalEntityUndefined
= OdGe::kExternalEntityUndefined;

typedef OdGe::NurbSurfaceProperties NurbSurfaceProperties;

const OdGe::NurbSurfaceProperties kOpen = OdGe::kOpen;
const OdGe::NurbSurfaceProperties kClosed = OdGe::kClosed;
const OdGe::NurbSurfaceProperties kPeriodic = OdGe::kPeriodic;
const OdGe::NurbSurfaceProperties kRational = OdGe::kRational;
const OdGe::NurbSurfaceProperties kNoPoles= OdGe::kNoPoles;
const OdGe::NurbSurfaceProperties kPoleAtMin = OdGe::kPoleAtMin;
const OdGe::NurbSurfaceProperties kPoleAtMax = OdGe::kPoleAtMax;
const OdGe::NurbSurfaceProperties kPoleAtBoth = OdGe::kPoleAtBoth;

typedef OdGe::PointContainment PointContainment;

typedef OdGe::OdGeXConfig OdGeXConfig;

const OdGe::OdGeXConfig kNotDefined = OdGe::kNotDefined;
const OdGe::OdGeXConfig kUnknown = OdGe::kUnknown;
const OdGe::OdGeXConfig kLeftRight = OdGe::kLeftRight;
const OdGe::OdGeXConfig kRightLeft = OdGe::kRightLeft;
const OdGe::OdGeXConfig kLeftLeft = OdGe::kLeftLeft;
const OdGe::OdGeXConfig kRightRight = OdGe::kRightRight;
const OdGe::OdGeXConfig kPointLeft = OdGe::kPointLeft;
const OdGe::OdGeXConfig kPointRight = OdGe::kPointRight;
const OdGe::OdGeXConfig kLeftOverlap = OdGe::kLeftOverlap;
const OdGe::OdGeXConfig kOverlapLeft = OdGe::kOverlapLeft;
const OdGe::OdGeXConfig kRightOverlap = OdGe::kRightOverlap;
const OdGe::OdGeXConfig kOverlapRight = OdGe::kOverlapRight;
const OdGe::OdGeXConfig kOverlapStart = OdGe::kOverlapStart;
const OdGe::OdGeXConfig kOverlapEnd = OdGe::kOverlapEnd;
const OdGe::OdGeXConfig kOverlapOverlap = OdGe::kOverlapOverlap;

typedef OdGe::ErrorCondition  OdGeError;

const OdGe::ErrorCondition	kOk = OdGe::kOk;
const OdGe::ErrorCondition	k0This = OdGe::k0This;
const OdGe::ErrorCondition	k0Arg1 = OdGe::k0Arg1;
const OdGe::ErrorCondition	k0Arg2 = OdGe::k0Arg2;
const OdGe::ErrorCondition	kPerpendicularArg1Arg2 = OdGe::kPerpendicularArg1Arg2;     
const OdGe::ErrorCondition	kEqualArg1Arg2 = OdGe::kEqualArg1Arg2;
const OdGe::ErrorCondition	kEqualArg1Arg3 = OdGe::kEqualArg1Arg3;
const OdGe::ErrorCondition	kEqualArg2Arg3 = OdGe::kEqualArg2Arg3;
const OdGe::ErrorCondition	kLinearlyDependentArg1Arg2Arg3 = OdGe::kLinearlyDependentArg1Arg2Arg3;
const OdGe::ErrorCondition	kArg1TooBig = OdGe::kArg1TooBig;
const OdGe::ErrorCondition	kArg1OnThis = OdGe::kArg1OnThis;
const OdGe::ErrorCondition	kArg1InsideThis = OdGe::kArg1InsideThis;

typedef OdGe::OdGeIntersectError OdGeIntersectError;

const OdGe::OdGeIntersectError kXXOk = OdGe::kXXOk;
const OdGe::OdGeIntersectError kXXIndexOutOfRange = OdGe::kXXIndexOutOfRange;
const OdGe::OdGeIntersectError kXXWrongDimensionAtIndex = OdGe::kXXWrongDimensionAtIndex;
const OdGe::OdGeIntersectError kXXUnknown = OdGe::kXXUnknown;

