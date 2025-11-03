/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_ERRCODES_H
#define GMODELER_INC_ERRCODES_H

#if defined(WIN32) || defined(WIN64)
#include <tchar.h>
#endif

GMODELER_NAMESPACE_BEGIN

enum ErrorCode
{
  eOk = 0,
  eFail,
  eViewPointLiesInsideScene,
  eBadBodyGeometry,
  eBadSurfaceType,
  eBadCurveType,
  eBadInput,
  eNullVector,
  eNullNormalVector,
  eBadPlane,
  eBadLine,
  eBadAxis,
  eBadTransform,
  ePointLiesInPlane,
  eInputBodiesMustNotBeNegated,
  eRadiusMustBePositive,
  eRadiusMustBeNonNegative,
  eRadiusMustNotBeZero,
  eApproximationMustBeAtLeastFour,
  eScaleFactorMustBePositive,
  eAngleMustNotBeZero,
  eBodyPointerIsNull,
  eFacePointerIsNull,
  eEdgePointerIsNull,
  eVertexPointerIsNull,
  ePolygonPointerIsNull,
  eProfilePolygonPointerIsNull,
  ePathPolygonPointerIsNull,
  eBodyIsNegative,
  eIntervalIsNull,
  eFileNameIsNull,
  eBadFile,
  eIncorrectFile,
  eFilePointerIsNull,
  eFileOpenError,
  eFileReadError,
  eFileWriteError,
  eSaveError,
  eRestoreError,
  eBadDataRestored,
  eFileIsNewerThanCurrentVersionOfModeler,
  eBoxSizesMustNotBeZero,
  eMajorRadiusMustBeGreaterThanMinorRadius,
  eInnerRadiusMustBeSmallerThanOuterRadius,
  eInnerRadiusCanBeZeroOnlyIfOuterRadiusIsZero,
  eViewPointCoincidesWithTargetPoint,
  eEpsilonMustBePositive,
  eCallbackObjectPointerIsNull,
  ePickingNotPossible,
  eAtLeast4NonCoplanarPointsRequired,
  ePointsDoNotDefineConvexPolyhedron,
  eApexMustNotLieInPolygon,
  eExtrusionVectorMustNotBeParallelToPolygon,
  eAxisOfRevolutionMustLieInPolygonPlane,
  eAxisOfRevolutionIntersectsPolygon,
  eBadNormal,
  eBadPolygon,
  ePolygonIsSelfIntersectingOrTouching,
  eBadRelativePolygonPosition,
  eCannotCreateFillet,
  eBadArcCenter,
  eRadiusTooSmall,
  eFilletRadiusMustBePositive,
  eCannotFilletVerticesBelongingToArcs,
  eFirstAndLastVertexInEndpointRevolutionMustNotBeFilleted,
  eArcBetweenLastAndFirstVertexNotAllowedForEndpointRevolution,
  eEntitiesSectionNotFoundInDxfFile,
  ePolylineEntityNotFoundInDxfFile,
  ePolylineMustBeClosed,
  e3dPolylineOrMeshNotAllowed,
  eBadDxfFile,
  ePointsAreColinearOrCoincident,
  eSourceArgumentsAreColinearOrCoincident,
  eDestinationArgumentsAreColinearOrCoincident,
  ePointsAreCoplanar,
  eChamferingDistanceMustBePositive,
  eOnlyManifoldEdgesCanBeFilletedAndChamfered,
  eOnlyStraightAndCircularEdgesCanBeFilletedAndChamfered,
  ePlanarEdgesCannotBeFilletedAndChamfered,
  eAtLeastOneEdgeExpected,
  eFilletRadiusTooLarge,
  eChamferDistanceTooLarge,
  eCannotFilletEdge,
  eCannotMitreEdgesOfDifferentConvexity,
  eTooComplexMixedConvexityCap,
  eNotYetImplemented,
  eCircleIsNotValid,
  eBaseNormalPerpendicularToAxisVector,
  eEndCentersMustHaveEqualDistance,
  eFaceMustNotBelongToABody,
  eFaceHasNoEdges,
  eOneSidedFaceExpected,
  eProfileFacesMustHaveTheSameNumberOfEdges,
  eAtLeastTwoProfilesExpected,
  eBodyProfileMustContainExactlyOneFace,
  eProfileFaceHasNoEdges,
  eBadMorphingMap,
  eEdgesOfFirstProfileCannotBeMarkedApproximating,
  eBaseSizesMustBePositive,
  eTopCircleMustLieAboveBaseRectangle,
  eFilletByRadiusOrArcByBulgeTypeExpected,
  eArcByRadiusTypeExpected,
  eArc3dTypeExpected,
  eCannotCreateTouchingCircle,
  eNonPlanarPolygon,
  eNonPlanarProfileFace,
  eFaceMustHaveAtLeastThreeEdges,
  ePolygonPointsCoincide,
  eBadPath,
  eBadProfileAndPathOrientation,
  eFirstPathPointMustLieInStartProfilePlane,
  eLastPathPointMustLieInEndProfilePlane,
  eWidthTooSmall,
  eHeightTooSmall,
  eEndProfileNotAllowedWhenPathIsClosed,
  eScaleFactorNotAllowedWhenPathIsClosed,
  eTwistAngleNotAllowedWhenPathIsClosed,
  eMorphingMustBeIdentityWhenPathIsClosed,
  eExtrusionBodyLooksSelfIntersecting,
  eMorphingMapRequiresEndProfile,
  eNegativeIndexInMorphingMap,
  eFixedPointMustLieInPolygonPlane,
  eTriStripsMayBeGeneratedOnlyWhenCachingTriangles,
  eStartProfileNormalHasOppositeDirectionThanFirstPathSegment,
  eEndProfileNormalHasOppositeDirectionThanLastPathSegment,
  eStartProfileIsParallelWithFirstPathSegment,
  eEndProfileIsParallelWithLastPathSegment,
  eProfilePolygonMustContainAtLeastOnePoint,
  eArcByRadiusNotAllowedForPathPolygons_UseArc3d,
  eArcByBulgeNotAllowedForPathPolygons_UseArc3d,
  eNumberOfLinearSegmentsMustBeAtLeastOne,
  eZeroBulgeNotAllowed,
  eFixedPointMustLieInStartProfilePlane,
  eBodyCannotBeClosed,
  ePolygonNormalNotPerpendicularToPolygonPlane,
  eSizeMustBePositive,
  ePointerIsNull,
  eToleranceMustBePositive,
  eValueMustBePositive,
  ePartnerEdgesOfNonManifoldEdgeCannotBeOrdered,
  eNonManifoldEdgesMustHaveEvenNumberOfPartners,
  eFaceMustHaveManifoldEdgesOnly,
  eStitchingFacesDidNotProduceAValidBody,
  eFaceCanNotBeMoved,
  eManifoldEdgeExpected,
  eEdgeSharedByTwoDifferentFacesExpected,
  eCoplanarFacesExpected,
  eInvalidVector,
  eAngleMustBePositive,
  eMinNumberOfFacesInSurfaceMustBeAtLeastTwo,
  eUnspecifiedCurveTypeExpected,
  eInvalidTerrainBody,
  eHeightMustBePositive,
  eCannotCreateLoopOfEdges,
  eTerrainSurfaceContainsHole,
  eBadIndexInMorphingMap,
  eStartProfileIsWrong,
  eEndProfileIsWrong,
  eExtrusionPathIsWrong,
  eStartProfileMustHaveOnlySingleLoop,
  eEndProfileMustHaveOnlySingleLoop,
  eInternalError = 1000
};

DllImpExp void disableExceptionForError(unsigned int err);
DllImpExp void enableExceptionForError(unsigned int err);
DllImpExp bool isExceptionDisabledForError(unsigned int err);

#ifdef _DEBUG

#define checkError(testExpr, err) checkErrorFunc(testExpr, err, _T(__FILE__), __LINE__)

DllImpExp void checkErrorFunc(bool testExpr, ErrorCode, const wchar_t* file, int line);

#else

inline void checkError(bool testExpr, ErrorCode err)
{
  if (!testExpr && !isExceptionDisabledForError(static_cast<unsigned int>(err)))
    throw err;
}

#endif

DllImpExp const wchar_t* errorString(ErrorCode);

GMODELER_NAMESPACE_END
#endif
