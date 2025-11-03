/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifdef GD_GCDBABB_H
#error "gcdbabb.h included more than once!  Is it included by a .h file?"
#endif

#define GD_GCDBABB_H 1

#include "gcdbabbES.h"

const GcDb::OpenMode kForRead = GcDb::kForRead;
const GcDb::OpenMode kForWrite = GcDb::kForWrite;
const GcDb::OpenMode kForNotify = GcDb::kForNotify;

const GcDb::ShowImagesMode kNeverShow      = GcDb::kNeverShow;
const GcDb::ShowImagesMode kAlwaysShow     = GcDb::kAlwaysShow;
const GcDb::ShowImagesMode kBoundingBoxShow     = GcDb::kBoundingBoxShow;

const GcDb::SaveImagesMode kNeverSave      = GcDb::kNeverSave;
const GcDb::SaveImagesMode kAlwaysSave     = GcDb::kAlwaysSave;

const GcDb::CoordAxis kX = GcDb::kX;
const GcDb::CoordAxis kY = GcDb::kY;
const GcDb::CoordAxis kZ = GcDb::kZ;

const GcDb::CoordSystem kWorldCS = GcDb::kWorldCS;
const GcDb::CoordSystem kUserCS = GcDb::kUserCS;
const GcDb::CoordSystem kCurDisplayCS = GcDb::kCurDisplayCS;
const GcDb::CoordSystem kPaperDisplayCS = GcDb::kPaperDisplayCS;
const GcDb::CoordSystem kEntityCS = GcDb::kEntityCS;

const GcDb::Intersect kOnBothOperands = GcDb::kOnBothOperands;
const GcDb::Intersect kExtendThis = GcDb::kExtendThis;
const GcDb::Intersect kExtendArg = GcDb::kExtendArg;
const GcDb::Intersect kExtendBoth = GcDb::kExtendBoth;

const GcDb::Visibility kInvisible = GcDb::kInvisible;
const GcDb::Visibility kVisible = GcDb::kVisible;

const GcDb::DxfCode kDxfInvalid = GcDb::kDxfInvalid;
const GcDb::DxfCode kDxfXDictionary = GcDb::kDxfXDictionary;
const GcDb::DxfCode kDxfPReactors = GcDb::kDxfPReactors;
const GcDb::DxfCode kDxfOperator = GcDb::kDxfOperator;
const GcDb::DxfCode kDxfXDataStart = GcDb::kDxfXDataStart;
const GcDb::DxfCode kDxfHeaderId = GcDb::kDxfHeaderId;
const GcDb::DxfCode kDxfEnd = GcDb::kDxfEnd;
const GcDb::DxfCode kDxfStart = GcDb::kDxfStart;
const GcDb::DxfCode kDxfText = GcDb::kDxfText;
const GcDb::DxfCode kDxfShapeName = GcDb::kDxfShapeName;
const GcDb::DxfCode kDxfSymbolTableName = GcDb::kDxfSymbolTableName;
const GcDb::DxfCode kDxfBlockName = GcDb::kDxfBlockName;
const GcDb::DxfCode kDxfAttributeTag = GcDb::kDxfAttributeTag;
const GcDb::DxfCode kDxfAttributePrompt = GcDb::kDxfAttributePrompt;
const GcDb::DxfCode kDxfDimStyleName = GcDb::kDxfDimStyleName;
const GcDb::DxfCode kDxfXRefPath = GcDb::kDxfXRefPath;
const GcDb::DxfCode kDxfHandle = GcDb::kDxfHandle;
const GcDb::DxfCode kDxfLinetypeName = GcDb::kDxfLinetypeName;
const GcDb::DxfCode kDxfTextStyleName = GcDb::kDxfTextStyleName;
const GcDb::DxfCode kDxfCLShapeText = GcDb::kDxfCLShapeText;
const GcDb::DxfCode kDxfCLShapeName = GcDb::kDxfCLShapeName;
const GcDb::DxfCode kDxfLayerName = GcDb::kDxfLayerName;
const GcDb::DxfCode kDxfLayoutName = GcDb::kDxfLayoutName;
const GcDb::DxfCode kDxfXCoord = GcDb::kDxfXCoord;
const GcDb::DxfCode kDxfYCoord = GcDb::kDxfYCoord;
const GcDb::DxfCode kDxfZCoord = GcDb::kDxfZCoord;
const GcDb::DxfCode kDxfElevation = GcDb::kDxfElevation;
const GcDb::DxfCode kDxfThickness = GcDb::kDxfThickness;
const GcDb::DxfCode kDxfReal = GcDb::kDxfReal;
const GcDb::DxfCode kDxfXReal = GcDb::kDxfXReal;
const GcDb::DxfCode kDxfInt8 = GcDb::kDxfInt8;
const GcDb::DxfCode kDxfBool = GcDb::kDxfBool;
const GcDb::DxfCode kDxfLinetypeScale = GcDb::kDxfLinetypeScale;
const GcDb::DxfCode kDxfLinetypeElement = GcDb::kDxfLinetypeElement;
const GcDb::DxfCode kDxfAngle = GcDb::kDxfAngle;
const GcDb::DxfCode kDxfVisibility = GcDb::kDxfVisibility;
const GcDb::DxfCode kDxfLayerLinetype = GcDb::kDxfLayerLinetype;
const GcDb::DxfCode kDxfColor = GcDb::kDxfColor;
const GcDb::DxfCode kDxfHasSubentities = GcDb::kDxfHasSubentities;
const GcDb::DxfCode kDxfViewportVisibility = GcDb::kDxfViewportVisibility;
const GcDb::DxfCode kDxfViewportActive = GcDb::kDxfViewportActive;
const GcDb::DxfCode kDxfViewportNumber = GcDb::kDxfViewportNumber;
const GcDb::DxfCode kDxfInt16 = GcDb::kDxfInt16;
const GcDb::DxfCode kDxfXInt16 = GcDb::kDxfXInt16;
const GcDb::DxfCode kDxfXXInt16 = GcDb::kDxfXXInt16;
const GcDb::DxfCode kDxfInt32 = GcDb::kDxfInt32;
const GcDb::DxfCode kDxfInt64 = GcDb::kDxfInt64;
const GcDb::DxfCode kDxfControlString = GcDb::kDxfControlString;
const GcDb::DxfCode kDxfSymTableRecComments = GcDb::kDxfSymTableRecComments;
const GcDb::DxfCode kDxfDimVarHandle = GcDb::kDxfDimVarHandle;
const GcDb::DxfCode kDxfUCSOrg = GcDb::kDxfUCSOrg;
const GcDb::DxfCode kDxfUCSOriX = GcDb::kDxfUCSOriX;
const GcDb::DxfCode kDxfUCSOriY = GcDb::kDxfUCSOriY;
const GcDb::DxfCode kDxfSubclass = GcDb::kDxfSubclass;
const GcDb::DxfCode kDxfEmbeddedObjectStart = GcDb::kDxfEmbeddedObjectStart;
const GcDb::DxfCode kDxfNormalX = GcDb::kDxfNormalX;
const GcDb::DxfCode kDxfNormalY = GcDb::kDxfNormalY;
const GcDb::DxfCode kDxfNormalZ = GcDb::kDxfNormalZ;
const GcDb::DxfCode kDxfXTextString = GcDb::kDxfXTextString;
const GcDb::DxfCode kDxfBinaryChunk = GcDb::kDxfBinaryChunk;
const GcDb::DxfCode kDxfArbHandle   = GcDb::kDxfArbHandle;
const GcDb::DxfCode kDxfSoftPointerId = GcDb::kDxfSoftPointerId;
const GcDb::DxfCode kDxfHardPointerId = GcDb::kDxfHardPointerId;
const GcDb::DxfCode kDxfSoftOwnershipId = GcDb::kDxfSoftOwnershipId;
const GcDb::DxfCode kDxfHardOwnershipId = GcDb::kDxfHardOwnershipId;
const GcDb::DxfCode kDxfLineWeight = GcDb::kDxfLineWeight;
const GcDb::DxfCode kDxfPlotStyleNameType = GcDb::kDxfPlotStyleNameType;
const GcDb::DxfCode kDxfPlotStyleNameId = GcDb::kDxfPlotStyleNameId;
const GcDb::DxfCode kDxfXXXInt16 = GcDb::kDxfXXXInt16;
const GcDb::DxfCode kDxfComment = GcDb::kDxfComment;
const GcDb::DxfCode kDxfXdAsciiString = GcDb::kDxfXdAsciiString;
const GcDb::DxfCode kDxfRegAppName = GcDb::kDxfRegAppName;
const GcDb::DxfCode kDxfXdControlString = GcDb::kDxfXdControlString;
const GcDb::DxfCode kDxfXdLayerName = GcDb::kDxfXdLayerName;
const GcDb::DxfCode kDxfXdBinaryChunk = GcDb::kDxfXdBinaryChunk;
const GcDb::DxfCode kDxfXdHandle = GcDb::kDxfXdHandle;
const GcDb::DxfCode kDxfXdXCoord = GcDb::kDxfXdXCoord;
const GcDb::DxfCode kDxfXdYCoord = GcDb::kDxfXdYCoord;
const GcDb::DxfCode kDxfXdZCoord = GcDb::kDxfXdZCoord;
const GcDb::DxfCode kDxfXdWorldXCoord = GcDb::kDxfXdWorldXCoord;
const GcDb::DxfCode kDxfXdWorldYCoord = GcDb::kDxfXdWorldYCoord;
const GcDb::DxfCode kDxfXdWorldZCoord = GcDb::kDxfXdWorldZCoord;
const GcDb::DxfCode kDxfXdWorldXDisp = GcDb::kDxfXdWorldXDisp;
const GcDb::DxfCode kDxfXdWorldYDisp = GcDb::kDxfXdWorldYDisp;
const GcDb::DxfCode kDxfXdWorldZDisp = GcDb::kDxfXdWorldZDisp;
const GcDb::DxfCode kDxfXdWorldXDir = GcDb::kDxfXdWorldXDir;
const GcDb::DxfCode kDxfXdWorldYDir = GcDb::kDxfXdWorldYDir;
const GcDb::DxfCode kDxfXdWorldZDir = GcDb::kDxfXdWorldZDir;
const GcDb::DxfCode kDxfXdReal = GcDb::kDxfXdReal;
const GcDb::DxfCode kDxfXdDist = GcDb::kDxfXdDist;
const GcDb::DxfCode kDxfXdScale = GcDb::kDxfXdScale;
const GcDb::DxfCode kDxfXdInteger16 = GcDb::kDxfXdInteger16;
const GcDb::DxfCode kDxfXdInteger32 = GcDb::kDxfXdInteger32;
const GcDb::DxfCode kDxfColorRGB =  GcDb::kDxfColorRGB; 
const GcDb::DxfCode kDxfColorName =  GcDb::kDxfColorName;
const GcDb::DxfCode kDxfAlpha =  GcDb::kDxfAlpha;    
const GcDb::DxfCode kDxfMaterialId =  GcDb::kDxfMaterialId;
const GcDb::DxfCode kDxfViewportGridDisplay = GcDb::kDxfViewportGridDisplay;
const GcDb::DxfCode kDxfObjVisualStyleId = GcDb::kDxfObjVisualStyleId;
const GcDb::DxfCode kDxfVpVisualStyleId = GcDb::kDxfVpVisualStyleId;
const GcDb::DxfCode kDxfDragVisualStyleId = GcDb::kDxfDragVisualStyleId;
const GcDb::DxfCode kDxfShadowFlags = GcDb::kDxfShadowFlags;
const GcDb::DxfCode kDxfFaceStyleId = GcDb::kDxfFaceStyleId;
const GcDb::DxfCode kDxfEdgeStyleId = GcDb::kDxfEdgeStyleId;
const GcDb::DxfCode kDxfVisualStyleId = GcDb::kDxfVisualStyleId;

const GcDb::DxfCode kDxfGradientObjType  = GcDb::kDxfGradientObjType;
const GcDb::DxfCode kDxfGradientPatType  = GcDb::kDxfGradientPatType;
const GcDb::DxfCode kDxfGradientTintType = GcDb::kDxfGradientTintType;
const GcDb::DxfCode kDxfGradientColCount = GcDb::kDxfGradientColCount;
const GcDb::DxfCode kDxfGradientAngle    = GcDb::kDxfGradientAngle;
const GcDb::DxfCode kDxfGradientShift    = GcDb::kDxfGradientShift;
const GcDb::DxfCode kDxfGradientTintVal  = GcDb::kDxfGradientTintVal;
const GcDb::DxfCode kDxfGradientColVal   = GcDb::kDxfGradientColVal;
const GcDb::DxfCode kDxfGradientName     = GcDb::kDxfGradientName;

const GcDb::DwgDataType kDwgNull = GcDb::kDwgNull;
const GcDb::DwgDataType kDwgReal = GcDb::kDwgReal;
const GcDb::DwgDataType kDwgInt64 = GcDb::kDwgInt64;
const GcDb::DwgDataType kDwgInt32 = GcDb::kDwgInt32;
const GcDb::DwgDataType kDwgInt16 = GcDb::kDwgInt16;
const GcDb::DwgDataType kDwgInt8 = GcDb::kDwgInt8;
const GcDb::DwgDataType kDwgText = GcDb::kDwgText;
const GcDb::DwgDataType kDwgBChunk = GcDb::kDwgBChunk;
const GcDb::DwgDataType kDwgHandle = GcDb::kDwgHandle;
const GcDb::DwgDataType kDwgHardOwnershipId = GcDb::kDwgHardOwnershipId;
const GcDb::DwgDataType kDwgSoftOwnershipId = GcDb::kDwgSoftOwnershipId;
const GcDb::DwgDataType kDwgHardPointerId   = GcDb::kDwgHardPointerId;
const GcDb::DwgDataType kDwgSoftPointerId   = GcDb::kDwgSoftPointerId;
const GcDb::DwgDataType kDwg3Real = GcDb::kDwg3Real;
const GcDb::DwgDataType kDwgNotRecognized = GcDb::kDwgNotRecognized;

const GcDb::OsnapMask kOsMaskEnd = GcDb::kOsMaskEnd;
const GcDb::OsnapMask kOsMaskMid = GcDb::kOsMaskMid;
const GcDb::OsnapMask kOsMaskCen = GcDb::kOsMaskCen;
const GcDb::OsnapMask kOsMaskNode = GcDb::kOsMaskNode;
const GcDb::OsnapMask kOsMaskQuad = GcDb::kOsMaskQuad;
const GcDb::OsnapMask kOsMaskInt = GcDb::kOsMaskInt;
const GcDb::OsnapMask kOsMaskIns = GcDb::kOsMaskIns;
const GcDb::OsnapMask kOsMaskPerp = GcDb::kOsMaskPerp;
const GcDb::OsnapMask kOsMaskTan = GcDb::kOsMaskTan;
const GcDb::OsnapMask kOsMaskNear = GcDb::kOsMaskNear;
const GcDb::OsnapMask kOsMaskQuick = GcDb::kOsMaskQuick;
const GcDb::OsnapMask kOsMaskCentroid = GcDb::kOsMaskCentroid;
const GcDb::OsnapMask kOsMaskImmediate = GcDb::kOsMaskImmediate;
const GcDb::OsnapMask kOsMaskAllowTan = GcDb::kOsMaskAllowTan;
const GcDb::OsnapMask kOsMaskDisablePerp = GcDb::kOsMaskDisablePerp;
const GcDb::OsnapMask kOsMaskRelCartesian = GcDb::kOsMaskRelCartesian;
const GcDb::OsnapMask kOsMaskRelPolar = GcDb::kOsMaskRelPolar;
const GcDb::OsnapMask kOsMaskNoneOverride = GcDb::kOsMaskNoneOverride;

const GcDb::OsnapMode kOsModeEnd = GcDb::kOsModeEnd;
const GcDb::OsnapMode kOsModeMid = GcDb::kOsModeMid;
const GcDb::OsnapMode kOsModeCen = GcDb::kOsModeCen;
const GcDb::OsnapMode kOsModeCentroid = GcDb::kOsModeCentroid;
const GcDb::OsnapMode kOsModeNode = GcDb::kOsModeNode;
const GcDb::OsnapMode kOsModeQuad = GcDb::kOsModeQuad;
const GcDb::OsnapMode kOsModeIns = GcDb::kOsModeIns;
const GcDb::OsnapMode kOsModePerp = GcDb::kOsModePerp;
const GcDb::OsnapMode kOsModeTan = GcDb::kOsModeTan;
const GcDb::OsnapMode kOsModeNear = GcDb::kOsModeNear;

const GcDb::TextHorzMode kTextLeft = GcDb::kTextLeft;
const GcDb::TextHorzMode kTextCenter = GcDb::kTextCenter;
const GcDb::TextHorzMode kTextRight = GcDb::kTextRight;
const GcDb::TextHorzMode kTextAlign = GcDb::kTextAlign;
const GcDb::TextHorzMode kTextMid = GcDb::kTextMid;
const GcDb::TextHorzMode kTextFit = GcDb::kTextFit;

const GcDb::TextVertMode kTextBase = GcDb::kTextBase;
const GcDb::TextVertMode kTextBottom = GcDb::kTextBottom;
const GcDb::TextVertMode kTextVertMid = GcDb::kTextVertMid;
const GcDb::TextVertMode kTextTop = GcDb::kTextTop;

const GcDb::LineSpacingStyle kAtLeast = GcDb::kAtLeast;
const GcDb::LineSpacingStyle kExactly = GcDb::kExactly;

const GcDb::Planarity kNonPlanar = GcDb::kNonPlanar;
const GcDb::Planarity kPlanar = GcDb::kPlanar;
const GcDb::Planarity kLinear = GcDb::kLinear;

const GcDb::PointIndex kMPoint1 = GcDb::kMPoint1;
const GcDb::PointIndex kMPoint2 = GcDb::kMPoint2;
const GcDb::PointIndex kMPoint3 = GcDb::kMPoint3;
const GcDb::PointIndex kMPoint4 = GcDb::kMPoint4;

const GcDb::EdgeIndex kMEdge1 = GcDb::kMEdge1;
const GcDb::EdgeIndex kMEdge2 = GcDb::kMEdge2;
const GcDb::EdgeIndex kMEdge3 = GcDb::kMEdge3;
const GcDb::EdgeIndex kMEdge4 = GcDb::kMEdge4;

const GcDb::Poly2dType k2dSimplePoly = GcDb::k2dSimplePoly;
const GcDb::Poly2dType k2dFitCurvePoly = GcDb::k2dFitCurvePoly;
const GcDb::Poly2dType k2dQuadSplinePoly = GcDb::k2dQuadSplinePoly;
const GcDb::Poly2dType k2dCubicSplinePoly = GcDb::k2dCubicSplinePoly;

const GcDb::Poly3dType k3dSimplePoly = GcDb::k3dSimplePoly;
const GcDb::Poly3dType k3dQuadSplinePoly = GcDb::k3dQuadSplinePoly;
const GcDb::Poly3dType k3dCubicSplinePoly = GcDb::k3dCubicSplinePoly;

const GcDb::PolyMeshType kSimpleMesh = GcDb::kSimpleMesh;
const GcDb::PolyMeshType kQuadSurfaceMesh = GcDb::kQuadSurfaceMesh;
const GcDb::PolyMeshType kCubicSurfaceMesh = GcDb::kCubicSurfaceMesh;
const GcDb::PolyMeshType kBezierSurfaceMesh = GcDb::kBezierSurfaceMesh;

const GcDb::Vertex2dType k2dVertex = GcDb::k2dVertex;
const GcDb::Vertex2dType k2dSplineCtlVertex = GcDb::k2dSplineCtlVertex;
const GcDb::Vertex2dType k2dSplineFitVertex = GcDb::k2dSplineFitVertex;
const GcDb::Vertex2dType k2dCurveFitVertex = GcDb::k2dCurveFitVertex;

const GcDb::Vertex3dType k3dSimpleVertex = GcDb::k3dSimpleVertex;
const GcDb::Vertex3dType k3dControlVertex = GcDb::k3dControlVertex;
const GcDb::Vertex3dType k3dFitVertex = GcDb::k3dFitVertex;

const GcDb::SpaceValueType kUndefined = GcDb::kUndefined;
const GcDb::SpaceValueType kStubPtr = GcDb::kStubPtr;
const GcDb::SpaceValueType kEndOfFile = GcDb::kEndOfFile;
const GcDb::SpaceValueType kBackwardBranch = GcDb::kBackwardBranch;
const GcDb::SpaceValueType kForwardBranch = GcDb::kForwardBranch;
const GcDb::SpaceValueType kDetour = GcDb::kDetour;

const GcDb::BoolOperType kBoolUnite = GcDb::kBoolUnite;
const GcDb::BoolOperType kBoolIntersect = GcDb::kBoolIntersect;
const GcDb::BoolOperType kBoolSubtract = GcDb::kBoolSubtract;

const GcDb::SubentType kNullSubentType   = GcDb::kNullSubentType;
const GcDb::SubentType kVertexSubentType = GcDb::kVertexSubentType;
const GcDb::SubentType kEdgeSubentType   = GcDb::kEdgeSubentType;
const GcDb::SubentType kFaceSubentType   = GcDb::kFaceSubentType;
const GcDb::SubentType kMlineSubentCache = GcDb::kMlineSubentCache;
const GcDb::SubentType kClassSubentType  = GcDb::kClassSubentType;
const GcDb::SubentType kAxisSubentType   = GcDb::kAxisSubentType;
const GcDb::SubentType kSilhouetteSubentType = GcDb::kSilhouetteSubentType;

const GcDb::GeomId kNoGeom = GcDb::kNoGeom;

const GcDb::GeomType kInvalidGeom = GcDb::kInvalidGeom;
const GcDb::GeomType kPointGeom = GcDb::kPointGeom;
const GcDb::GeomType kLineGeom = GcDb::kLineGeom;
const GcDb::GeomType kCircleGeom = GcDb::kCircleGeom;
const GcDb::GeomType kPlaneGeom = GcDb::kPlaneGeom;

const GcDb::UnitsValue kUnitsUndefined      = GcDb::kUnitsUndefined;
const GcDb::UnitsValue kUnitsInches         = GcDb::kUnitsInches;
const GcDb::UnitsValue kUnitsFeet           = GcDb::kUnitsFeet;
const GcDb::UnitsValue kUnitsMillimeters    = GcDb::kUnitsMillimeters;
const GcDb::UnitsValue kUnitsMeters         = GcDb::kUnitsMeters;
const GcDb::UnitsValue kUnitsMicroinches    = GcDb::kUnitsMicroinches;
const GcDb::UnitsValue kUnitsMils           = GcDb::kUnitsMils;
const GcDb::UnitsValue kUnitsYards          = GcDb::kUnitsYards;
const GcDb::UnitsValue kUnitsMiles          = GcDb::kUnitsMiles;
const GcDb::UnitsValue kUnitsAngstroms      = GcDb::kUnitsAngstroms;
const GcDb::UnitsValue kUnitsNanometers     = GcDb::kUnitsNanometers;
const GcDb::UnitsValue kUnitsMicrons        = GcDb::kUnitsMicrons;
const GcDb::UnitsValue kUnitsDecimeters     = GcDb::kUnitsDecimeters;
const GcDb::UnitsValue kUnitsCentimeters    = GcDb::kUnitsCentimeters;
const GcDb::UnitsValue kUnitsDekameters     = GcDb::kUnitsDekameters;
const GcDb::UnitsValue kUnitsHectometers    = GcDb::kUnitsHectometers;
const GcDb::UnitsValue kUnitsKilometers     = GcDb::kUnitsKilometers;
const GcDb::UnitsValue kUnitsGigameters     = GcDb::kUnitsGigameters;
const GcDb::UnitsValue kUnitsAstronomical   = GcDb::kUnitsAstronomical;
const GcDb::UnitsValue kUnitsLightYears     = GcDb::kUnitsLightYears;
const GcDb::UnitsValue kUnitsParsecs        = GcDb::kUnitsParsecs;
const GcDb::UnitsValue kUnitsUSSurveyFeet   = GcDb::kUnitsUSSurveyFeet;
const GcDb::UnitsValue kUnitsUSSurveyInch   = GcDb::kUnitsUSSurveyInch;
const GcDb::UnitsValue kUnitsUSSurveyYard   = GcDb::kUnitsUSSurveyYard;
const GcDb::UnitsValue kUnitsUSSurveyMile   = GcDb::kUnitsUSSurveyMile;
const GcDb::UnitsValue kUnitsMax            = GcDb::kUnitsMax;

const GcDb::OrthographicView kTopView      = GcDb::kTopView;
const GcDb::OrthographicView kBottomView   = GcDb::kBottomView;
const GcDb::OrthographicView kFrontView    = GcDb::kFrontView;
const GcDb::OrthographicView kBackView     = GcDb::kBackView;
const GcDb::OrthographicView kLeftView     = GcDb::kLeftView;
const GcDb::OrthographicView kRightView    = GcDb::kRightView;
const GcDb::OrthographicView kNonOrthoView = GcDb::kNonOrthoView;

const GcDb::CellType kUnknownCell          =  GcDb::kUnknownCell;	
const GcDb::CellType kTextCell             =  GcDb::kTextCell;	
const GcDb::CellType kBlockCell            =  GcDb::kBlockCell;	
 
const GcDb::CellEdgeMask kTopMask          =  GcDb::kTopMask;	
const GcDb::CellEdgeMask kRightMask        =  GcDb::kRightMask;	
const GcDb::CellEdgeMask kBottomMask       =  GcDb::kBottomMask;	
const GcDb::CellEdgeMask kLeftMask         =  GcDb::kLeftMask;	
 
const GcDb::FlowDirection kTtoB            =  GcDb::kTtoB;	
const GcDb::FlowDirection kBtoT            =  GcDb::kBtoT;
 
const GcDb::RotationAngle kDegrees000      =  GcDb::kDegrees000;	
const GcDb::RotationAngle kDegrees090      =  GcDb::kDegrees090;	
const GcDb::RotationAngle kDegrees180      =  GcDb::kDegrees180;	
const GcDb::RotationAngle kDegrees270      =  GcDb::kDegrees270;	
const GcDb::RotationAngle kDegreesUnknown  =  GcDb::kDegreesUnknown;	

const GcDb::CellAlignment kTopLeft		     =  GcDb::kTopLeft;
const GcDb::CellAlignment kTopCenter	     =  GcDb::kTopCenter;	
const GcDb::CellAlignment kTopRight		     =  GcDb::kTopRight;	
const GcDb::CellAlignment kMiddleLeft	     =  GcDb::kMiddleLeft;	
const GcDb::CellAlignment kMiddleCenter	   =  GcDb::kMiddleCenter;	
const GcDb::CellAlignment kMiddleRight	   =  GcDb::kMiddleRight;	
const GcDb::CellAlignment kBottomLeft	     =  GcDb::kBottomLeft;	
const GcDb::CellAlignment kBottomCenter	   =  GcDb::kBottomCenter;	
const GcDb::CellAlignment kBottomRight	   =  GcDb::kBottomRight;	

const GcDb::GridLineType kInvalidGridLine  =  GcDb::kInvalidGridLine;	  
const GcDb::GridLineType kHorzTop		   =  GcDb::kHorzTop;	
const GcDb::GridLineType kHorzInside	   =  GcDb::kHorzInside;	
const GcDb::GridLineType kHorzBottom	   =  GcDb::kHorzBottom;	
const GcDb::GridLineType kVertLeft		   =  GcDb::kVertLeft;	
const GcDb::GridLineType kVertInside	   =  GcDb::kVertInside;	
const GcDb::GridLineType kVertRight		   =  GcDb::kVertRight;	

const GcDb::GridLineTypes kAllGridLines	 =  GcDb::kAllGridLines;	

const GcDb::RowType kUnknownRow			     =  GcDb::kUnknownRow;	
const GcDb::RowType kDataRow			       =  GcDb::kDataRow;	
const GcDb::RowType kTitleRow			       =  GcDb::kTitleRow;	
const GcDb::RowType kHeaderRow			     =  GcDb::kHeaderRow;	

const GcDb::RowTypes kAllRows               =  GcDb::kAllRows;	

const GcDb::TableStyleFlags kHorzInsideLineFirst  =  GcDb::kHorzInsideLineFirst;
const GcDb::TableStyleFlags kHorzInsideLineSecond =  GcDb::kHorzInsideLineSecond;
const GcDb::TableStyleFlags kHorzInsideLineThird  =  GcDb::kHorzInsideLineThird;
const GcDb::TableStyleFlags kTableStyleModified   =  GcDb::kTableStyleModified;

const GcDb::SliceModelType kKeepBothSides         =  GcDb::kKeepBothSides;	
const GcDb::SliceModelType kUseCurrentColor       =  GcDb::kUseCurrentColor;	