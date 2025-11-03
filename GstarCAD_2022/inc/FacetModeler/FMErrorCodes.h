#ifndef __FMERRORCODES_H__
#define __FMERRORCODES_H__

#include "../FacetModeler/FMGeometry.h"
#include <tchar.h>

namespace FacetModeler
{
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
    eInternalError                                         = 1000
  }; 

  FMGEOMETRY_API void disableExceptionForError(unsigned int err);
  FMGEOMETRY_API void enableExceptionForError(unsigned int err);
  FMGEOMETRY_API bool isExceptionDisabledForError(unsigned int err);


#ifdef _DEBUG

#define checkError(testExpr, err) checkErrorFunc(testExpr, err, _T(__FILE__), __LINE__)

  FMGEOMETRY_API void checkErrorFunc(bool testExpr, ErrorCode, const wchar_t* file, int line);

#else

  inline void checkError(bool testExpr, ErrorCode err)
  {
    if (!testExpr && !isExceptionDisabledForError(static_cast<unsigned int>(err)))
      throw err;
  }

#endif


  // Returns the error string corresponding to the ErrorCode or a string "nnn" 
  // where "nnn" is the error number if there is no error string for the given 
  // ErrorCode
  //
  FMGEOMETRY_API const wchar_t* errorString(ErrorCode);

}

#endif  //__FMERRORCODES_H__
