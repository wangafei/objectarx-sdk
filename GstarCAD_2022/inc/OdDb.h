#pragma once
#include "OdaCommon.h"

// String Constants
#define ACDB_SERVICES                  OD_T("AcDbServices")
#define ACDB_MODEL_SPACE               OD_T("*Model_Space")
#define ACDB_PAPER_SPACE               OD_T("*Paper_Space")
#define ACDB_NULL_HANDLE               OD_T("\0\0\0\0\0\0\0")
#define ACDB_BROKEN_HANDLE             OD_T("FFFFFFFF")
#define ACDB_OPEN_BRACE_STR            OD_T("{")
#define ACDB_OPEN_BRACE_CHAR           OD_T('{')
#define ACDB_CLOSE_BRACE_STR           OD_T("}")
#define ACDB_CLOSE_BRACE_CHAR          OD_T('}')
#define ACDB_GROUP_DICTIONARY          OD_T("ACAD_GROUP")
#define ACDB_MLINESTYLE_DICTIONARY     OD_T("ACAD_MLINESTYLE")
#define ACDB_LAYOUT_DICTIONARY         OD_T("ACAD_LAYOUT")
#define ACDB_PLOTSETTINGS_DICTIONARY   OD_T("ACAD_PLOTSETTINGS")
#define ACDB_PLOTSTYLENAME_DICTIONARY  OD_T("ACAD_PLOTSTYLENAME")
#define ACDB_MATERIAL_DICTIONARY       OD_T("ACAD_MATERIAL")
#define ACDB_COLOR_DICTIONARY          OD_T("ACAD_COLOR")
#define ACDB_EMBEDDED_OBJECT_STR       OD_T("Embedded Object")
#define ACDB_LAYERSTATES_DICTIONARY    OD_T("ACAD_LAYERSTATES")

#define ACDB_VISUALSTYLE_DICTIONARY    OD_T("ACAD_VISUALSTYLE")
#define ACDB_TABLESTYLE_DICTIONARY     OD_T("ACAD_TABLESTYLE")
#define ACDB_FIELD_DICTIONARY          OD_T("ACAD_FIELD")
#define ACDB_FIELDLIST                 OD_T("ACAD_FIELDLIST")
#define ACDB_ENHANCED_BLOCK            OD_T("ACAD_ENHANCEDBLOCK")
#define ACDB_ENHANCED_BLOCK_EVALKEY    OD_T("ACAD_ENHANCEDBLOCKEVALKEY")
#define ACDB_ENHANCED_BLOCK_REF        OD_T("ACAD_ENHANCEDBLOCK_REFERENCE")
#define ACDB_SECTION_MANAGER           OD_T("ACAD_SECTION_MANAGER")
#define ACDB_DATALINK                  OD_T("ACAD_DATALINK")
#define ACDB_ANNOTATIONSCALES_COLLECTION OD_T("ACDB_ANNOTATIONSCALES")
#define ACDB_MLEADERSTYLE_DICTIONARY   OD_T("ACAD_MLEADERSTYLE")
#define ACDB_ASSOCNETWORK_DICTIONARY   OD_T("ACAD_ASSOCNETWORK")
#pragma pack(push, 8)



namespace OdDb
{
  enum OpenMode
  {
    kNotOpen           =-1,
    kForRead           = 0,
    kForWrite          = 1,
    kForNotify         = 2
  };

  enum CoordAxis
  {
    kX                 = 0,
    kY                 = 1,
    kZ                 = 2
  };

  enum CoordSystem
  {
    kWorldCS           = 0,
    kUserCS            = 1,
    kCurDisplayCS      = 2,
    kPaperDisplayCS    = 3,
    kEntityCS          = 4
  };

  enum Intersect
  {
    kOnBothOperands    = 0,
    kExtendThis        = 1,
    kExtendArg         = 2,
    kExtendBoth        = 3
  };

  enum Visibility
  {
    kInvisible         = 1,
    kVisible           = 0
  };

  typedef int DxfCode;
  enum
  {
    kDxfInvalid        = -9999,
    kDxfXDictionary     = -6,
    kDxfPReactors       = -5,
    kDxfOperator        = -4,
    kDxfXDataStart      = -3,
    kDxfHeaderId        = -2,
    kDxfFirstEntId      = -2,
    kDxfEnd             = -1,
    kDxfStart           = 0,
    kDxfText            = 1,
    kDxfXRefPath        = 1,
    kDxfShapeName       = 2,
    kDxfBlockName       = 2,
    kDxfAttributeTag    = 2,
    kDxfSymbolTableName = 2,
    kDxfMstyleName      = 2,
    kDxfSymTableRecName = 2,
    kDxfAttributePrompt = 3,
    kDxfDimStyleName    = 3,
    kDxfLinetypeProse   = 3,
    kDxfTextFontFile    = 3,
    kDxfDescription     = 3,
    kDxfDimPostStr      = 3,
    kDxfTextBigFontFile = 4,
    kDxfDimAPostStr     = 4,
    kDxfCLShapeName     = 4,
    kDxfSymTableRecComments = 4,
    kDxfHandle          = 5,
    kDxfDimBlk          = 5,
    kDxfDimBlk1         = 6,
    kDxfLinetypeName    = 6,
    kDxfDimBlk2         = 7,
    kDxfTextStyleName   = 7,
    kDxfLayerName       = 8,
    kDxfCLShapeText     = 9,

    kDxfXCoord         = 10,

    kDxfYCoord         = 20,

    kDxfZCoord         = 30,

    kDxfElevation      = 38,
    kDxfThickness      = 39,

    kDxfReal           = 40,
    kDxfViewportHeight = 40,
    kDxfTxtSize        = 40,
    kDxfTxtStyleXScale = 41,
    kDxfViewWidth      = 41,
    kDxfViewportAspect = 41,
    kDxfTxtStylePSize  = 42,
    kDxfViewLensLength = 42,
    kDxfViewFrontClip  = 43,
    kDxfViewBackClip   = 44,
    kDxfShapeXOffset   = 44,
    kDxfShapeYOffset   = 45,
    kDxfViewHeight     = 45,
    kDxfShapeScale     = 46,
    kDxfPixelScale     = 47,

    kDxfLinetypeScale  = 48,

    kDxfDashLength     = 49,
    kDxfMlineOffset    = 49,
    kDxfLinetypeElement = 49,

    kDxfAngle          = 50,
    kDxfViewportSnapAngle = 50,
    kDxfViewportTwist  = 51,

    kDxfVisibility     = 60,
    kDxfViewportGridDisplay = 60,
    kDxfLayerLinetype  = 61,
    kDxfViewportGridMajor   = 61,
    kDxfColor          = 62,
    // Removed codes intended
    // only for internal
    // use:  63-65
    kDxfHasSubentities = 66,
    kDxfViewportVisibility = 67,
    kDxfViewportActive = 68,
    kDxfViewportNumber = 69,

    kDxfInt16          = 70,
    kDxfViewMode       = 71,
    kDxfCircleSides    = 72,
    kDxfViewportZoom   = 73,
    kDxfViewportIcon   = 74,
    kDxfViewportSnap   = 75,
    kDxfViewportGrid   = 76,
    kDxfViewportSnapStyle= 77,
    kDxfViewportSnapPair= 78,

    kDxfRegAppFlags    = 71,

    kDxfTxtStyleFlags  = 71,
    kDxfLinetypeAlign  = 72,
    kDxfLinetypePDC    = 73,

    kDxfInt32          = 90,
    kDxfVertexIdentifier = 91,
    // Subclass Section Marker
    //
    // to be followed by subclass name.
    //
    kDxfSubclass            = 100,
    kDxfEmbeddedObjectStart = 101,
    kDxfControlString       = 102,

    // DimVarTableRecords have been using 5 for a
    // string value.  With R13, they get a handle
    // value as well.  Since 5 is already in use,
    // we use 105 for this special case.
    //
    kDxfDimVarHandle = 105,

    kDxfUCSOrg         = 110,
    kDxfUCSOriX        = 111,
    kDxfUCSOriY        = 112,

    kDxfXReal          = 140,
    kDxfViewBrightness = 141,
    kDxfViewContrast   = 142,

    kDxfInt64          = 160,
    kDxfXInt16         = 170,

    kDxfNormalX        = 210,
    kDxfNormalY        = 220,
    kDxfNormalZ        = 230,

    kDxfXXInt16        = 270,

    kDxfInt8           = 280,
    kDxfRenderMode     = 281,
    kDxfDefaultLightingType = 282,
    kDxfShadowFlags         = 284,

    kDxfBool           = 290,
    kDxfDefaultLightingOn   = 292,

    //  More string values 300-309
    kDxfXTextString    = 300,

    //  Arbitrary Binary Chunks 310-319
    kDxfBinaryChunk   = 310,

    //  Arbitrary Object Handles 320-329
    kDxfArbHandle  = 320,

    kDxfSoftPointerId   = 330,  // 330-339
    kDxfViewBackgroundId = 332, // softPointer to background of viewport and viewporttable record
    kDxfShadePlotId      = 333, // softPointer to shade plot visual style or render preset
    kDxfLiveSectionId      = 334, // softPointer to LiveSection of view, viewport and viewporttable record
    kDxfLiveSectionName    = 309, // LiveSection Name
    kDxfHardPointerId   = 340,  // 340-349
    kDxfObjVisualStyleId = 345,
    kDxfVpVisualStyleId = 346,
    kDxfMaterialId       = 347, // hardpointer reference to AcDbMaterial
    kDxfVisualStyleId    = 348, // hardpointer reference to visual style
    kDxfDragVisualStyleId = 349, // hardpointer reference to visual style
    kDxfSoftOwnershipId = 350,  // 350-359
    kDxfHardOwnershipId = 360,  // 360-369
    kDxfSunId            = 361, // hardownership reference to sun object

    // New base entity properties
    // Lineweight is either an integer
    // or "BYLAYER" or "BYBLOCK"
    kDxfLineWeight        = 370,
    kDxfPlotStyleNameType = 380,
    kDxfPlotStyleNameId   = 390,
    kDxfXXXInt16          = 400,

    kDxfLayoutName     = 410,

    // Extended color information for base entities

    kDxfColorRGB       = 420,
    kDxfColorName      = 430,

    // New base entity property Alpha is an integer
    kDxfAlpha          = 440,

    kDxfGradientObjType  = 450,
    kDxfGradientPatType  = 451,
    kDxfGradientTintType = 452,
    kDxfGradientColCount = 453,
    kDxfGradientAngle    = 460,
    kDxfGradientShift    = 461,
    kDxfGradientTintVal  = 462,
    kDxfGradientColVal   = 463,
    kDxfGradientName     = 470,

    kDxfFaceStyleId = 480,
    kDxfEdgeStyleId = 481,

    kDxfComment        = 999,

    kDxfXdAsciiString  = 1000,
    kDxfRegAppName     = 1001,
    kDxfXdControlString = 1002,
    kDxfXdLayerName    = 1003,
    kDxfXdBinaryChunk  = 1004,
    kDxfXdHandle       = 1005,

    kDxfXdXCoord       = 1010,
    kDxfXdYCoord       = 1020,
    kDxfXdZCoord       = 1030,

    kDxfXdWorldXCoord  = 1011,
    kDxfXdWorldYCoord  = 1021,
    kDxfXdWorldZCoord  = 1031,

    kDxfXdWorldXDisp   = 1012,
    kDxfXdWorldYDisp   = 1022,
    kDxfXdWorldZDisp   = 1032,

    kDxfXdWorldXDir    = 1013,
    kDxfXdWorldYDir    = 1023,
    kDxfXdWorldZDir    = 1033,

    kDxfXdReal         = 1040,
    kDxfXdDist         = 1041,
    kDxfXdScale        = 1042,

    kDxfXdInteger16    = 1070,
    kDxfXdInteger32    = 1071
  };

  // Primitives.
  enum DwgDataType
  {
    kDwgNull            = 0,
    kDwgReal            = 1,
    kDwgInt32           = 2,
    kDwgInt16           = 3,
    kDwgInt8            = 4,
    kDwgText            = 5,
    kDwgBChunk          = 6,
    kDwgHandle          = 7,
    kDwgHardOwnershipId = 8,
    kDwgSoftOwnershipId = 9,
    kDwgHardPointerId   = 10,
    kDwgSoftPointerId   = 11,
    kDwg3Real           = 12,
    kDwgInt64           = 13,
    kDwg2Real			 = 14,
    kDwgNotRecognized   = 19 
  };

  enum OsnapMask
  {
    kOsMaskEnd          = 1,
    kOsMaskMid          = 2,
    kOsMaskCen          = 4,
    kOsMaskNode         = 8,
    kOsMaskQuad         = 0x10,
    kOsMaskInt          = 0x20,
    kOsMaskIns          = 0x40,
    kOsMaskPerp         = 0x80,
    kOsMaskTan          = 0x100,
    kOsMaskNear         = 0x200,
    kOsMaskQuick        = 0x400,
    kOsMaskApint        = 0x800,
    kOsMaskImmediate    = 0x10000,
    kOsMaskAllowTan     = 0x20000,
    kOsMaskDisablePerp  = 0x40000,
    kOsMaskRelCartesian = 0x80000,
    kOsMaskRelPolar     = 0x100000,
    kOsMaskNoneOverride = 0x200000,
    kOsMaskDistance     = 0x400000,
    kOsMaskDivide       = 0x800000,
    kOsMaskGeoCent      = 0x1000000
  };

  enum OsnapMode
  {
    kOsModeEnd          = 1,
    kOsModeMid          = 2,
    kOsModeCen          = 3,
    kOsModeNode         = 4,
    kOsModeQuad         = 5, 
    kOsModeIntersec     = 6,
    kOsModeIns          = 7,
    kOsModePerp         = 8,
    kOsModeTan          = 9,
    kOsModeNear         = 10,
    kOsModeCentroid     = 11,
    kOsModeApint        = 12,
    kOsModeExt          = 13,
    kOsModePar          = 14,
    kOsModeStart        = 15,
    kOsModeDistance     = 16,
    kOsModeDivide       = 17,    
  };

  enum ShowImagesMode
  {
    kNeverShow     = 0,
    kAlwaysShow      = 1,
    kBoundingBoxShow = 2
  };

  enum SaveImagesMode
  {
    kNeverSave     = 0,
    kAlwaysSave      = 1
  };

  enum TextHorzMode
  {
    kTextLeft    = 0,   // TH_LEFT,
    kTextCenter  = 1,   // TH_CENT,
    kTextRight   = 2,   // TH_RIGHT,
    kTextAlign   = 3,   // THV_ALIGN,
    kTextMid     = 4,   // THV_MID,
    kTextFit     = 5
  }; // THV_FIT

  enum TextVertMode
  {
    kTextBase    = 0,   // TV_BASE,
    kTextBottom  = 1,   // TV_BOT,
    kTextVertMid = 2,   // TV_MID,
    kTextTop     = 3    // TV_TOP
  };

  enum LineSpacingStyle
  {
    kAtLeast = 1,
    kExactly = 2
  };

  enum Planarity
  {
    kNonPlanar = 0,
    kPlanar    = 1,
    kLinear    = 2
  };

  enum PointIndex
  {
    kMPoint1    = 0,
    kMPoint2    = 1,
    kMPoint3    = 2,
    kMPoint4    = 3
  };

  enum EdgeIndex
  {
    kMEdge1    = 0,
    kMEdge2    = 1,
    kMEdge3    = 2,
    kMEdge4    = 3
  };

  enum Poly2dType
  {
    k2dSimplePoly      = 0,
    k2dFitCurvePoly    = 1,
    k2dQuadSplinePoly  = 2,
    k2dCubicSplinePoly = 3
  };

  enum Poly3dType
  {
    k3dSimplePoly      = 0,
    k3dQuadSplinePoly  = 1,
    k3dCubicSplinePoly = 2
  };

  enum PolyMeshType
  {
    kSimpleMesh        = 0,
    kQuadSurfaceMesh   = 5,
    kCubicSurfaceMesh  = 6,
    kBezierSurfaceMesh = 8
  };

  enum Vertex2dType
  {
    k2dVertex          = 0,
    k2dSplineCtlVertex = 1,
    k2dSplineFitVertex = 2,
    k2dCurveFitVertex =  3
  };

  enum Vertex3dType
  {
    k3dSimpleVertex    = 0,
    k3dControlVertex   = 1,
    k3dFitVertex       = 2
  };

  enum SpaceValueType
  {
    kUndefined,
    kStubPtr,
    kEndOfFile,
    kBackwardBranch,
    kForwardBranch,
    kDetour
  };

  enum BoolOperType
  {
    kBoolUnite      = 0, 
    kBoolIntersect  = 1, 
    kBoolSubtract   = 2 
  };

  typedef OdUInt32 SubentType;
  enum 
  {
    kNullSubentType   = 0,
    kFaceSubentType   = 1,
    kEdgeSubentType   = 2,
    kVertexSubentType = 3,
    kMlineSubentCache = 4,
    kClassSubentType  = 5,  
  };

  typedef OdUInt32  GeomId;
  enum 
  {
    kNoGeom = 0
  };

  enum GeomType
  {
    kInvalidGeom = 0,
    kPointGeom,
    kLineGeom,
    kCircleGeom,
    kPlaneGeom
  };

  enum FilerType
  {
    kFileFiler     = 0,
    kCopyFiler     = 1,
    kUndoFiler     = 2,
    kBagFiler      = 3,
    kIdXlateFiler      = 4,
    kPageFiler         = 5,
    kDeepCloneFiler    = 6,
    kIdFiler           = 7,
    kPurgeFiler        = 8,
    kWblockCloneFiler  = 9
  };

  enum FilerSeekType
  {
#ifdef SEEK_SET
    kSeekFromStart   = SEEK_SET,
    kSeekFromCurrent = SEEK_CUR,
    kSeekFromEnd     = SEEK_END
#else
    kSeekFromStart   = 0,
    kSeekFromCurrent = 1,
    kSeekFromEnd     = 2
#endif
  };

  enum SaveType          
  {
    kNoSave = 0,
    kR12Save,  // Only used for R12 DXF
    kR13Save,  // No longer used
    kR14Save,
    k2000Save,
    k2004Save,
    k2007Save,
    k2010Save, 
    k2013Save, 
    k2018Save, 
  };

  enum SaveFileType
  {
    kDwg   = 0,
    kDxf   = 1,
    kDxb   = 2,
    kUnknown = -1,
  };

  enum GroupOperType
  {
    kNoOp           = 0,
    kAdd            = 1,
    kRemove         = 2,
    kRename         = 3,
    kOrdered        = 4,
    kGrpDesc        = 5,
    kSelect         = 6,
    kCreate         = 7,
    kPrepend        = 8,
    kInsert         = 9,
    kGrpFlags       = 10
  };

  enum DeepCloneType
  {
    kDcCopy           = 0,
    kDcExplode        = 1,
    kDcBlock          = 2,
    kDcXrefBind       = 3,
    kDcSymTableMerge  = 4,
    kDcInsert         = 6,
    kDcWblock         = 7,
    kDcObjects        = 8,
    kDcXrefInsert     = 9,
    kDcInsertCopy     = 10,
    kDcWblkObjects    = 11
  };

  enum DuplicateRecordCloning
  { 
    kDrcNotApplicable  = 0,
    kDrcIgnore         = 1,
    kDrcReplace        = 2,
    kDrcXrefMangleName = 3,
    kDrcMangleName     = 4,
    kDrcUnmangleName   = 5,
    kDrcMax            = kDrcUnmangleName
  };

  enum XrefStatus
  {
    kXrfNotAnXref     = 0,
    kXrfResolved      = 1,
    kXrfUnloaded      = 2,
    kXrfUnreferenced  = 3,
    kXrfFileNotFound  = 4,
    kXrfUnresolved    = 5
  };

  enum XrefNotificationStatus
  { 
    kXrfNotifyNone = 0,
    kXrfNotifyResolvedMatch = 1,
    kXrfNotifyResolvedElsewhere = 2,
    kXrfNotifyResolvedWithUpdate = 3,
    kXrfNotifyResolvedUpdateAvailable = 4
  };

  enum MeasurementValue
  {
    kEnglish = 0,
    kMetric  = 1,
  };

  enum UnitsValue
  {
    kUnitsUndefined     = 0,
    kUnitsInches        = 1,
    kUnitsFeet          = 2,
    kUnitsMiles         = 3,
    kUnitsMillimeters   = 4,
    kUnitsCentimeters   = 5,
    kUnitsMeters        = 6,
    kUnitsKilometers    = 7,
    kUnitsMicroinches   = 8,
    kUnitsMils          = 9,
    kUnitsYards         = 10,
    kUnitsAngstroms     = 11,
    kUnitsNanometers    = 12,
    kUnitsMicrons       = 13,
    kUnitsDecimeters    = 14,
    kUnitsDekameters    = 15,
    kUnitsHectometers   = 16,
    kUnitsGigameters    = 17,
    kUnitsAstronomical  = 18,
    kUnitsLightYears    = 19,
    kUnitsParsecs       = 20,
    kUnitsMax           = kUnitsParsecs,
  };

  enum TimeZone
  {
    kInternationalDateLine      = -12000,   //(GMT-12:00) International Date Line West
    kMidwayIsland               = -11000,   //(GMT-11:00) Midway Island, Samoa
    kHawaii                     = -10000,   //(GMT-10:00) Hawaii
    kAlaska                     = -9000,    //(GMT-09:00) Alaska
    kPacific                    = -8000,    //(GMT-08:00) Pacific Time (US & Canada); Tijuana
    kMountain                   = -7000,    //(GMT-07:00) Mountain Time (US & Canada)
    kArizona                    = -7001,    //(GMT-07:00) Arizona
    kMazatlan                   = -7002,    //(GMT-07:00) Chihuahua, La Paz, Mazatlan
    kCentral                    = -6000,    //(GMT-06:00) Central Time (US & Canada)
    kCentralAmerica             = -6001,    //(GMT-06:00) Central America
    kMexicoCity                 = -6002,    //(GMT-06:00) Guadalajara, Mexico City, Monterrey
    kSaskatchewan               = -6003,    //(GMT-06:00) Saskatchewan
    kEastern                    = -5000,    //(GMT-05:00) Eastern Time (US & Canada)
    kIndiana                    = -5001,    //(GMT-05:00) Indiana (East)
    kBogota                     = -5002,    //(GMT-05:00) Bogota, Lima, Quito
    kAtlanticCanada             = -4000,    //(GMT-04:00) Atlantic Time (Canada)
    kCaracas                    = -4001,    //(GMT-04:00) Caracas, La Paz
    kSantiago                   = -4002,    //(GMT-04:00) Santiago
    kNewfoundland               = -3300,    //(GMT-03:30) Newfoundland
    kBrasilia                   = -3000,    //(GMT-03:00) Brasilia
    kBuenosAires                = -3001,    //(GMT-03:00) Buenos Aires, Georgetown
    kGreenland                  = -3002,    //(GMT-03:00) Greenland
    kMidAtlantic                = -2000,    //(GMT-02:00) Mid-Atlantic
    kAzores                     = -1000,    //(GMT-01:00) Azores
    kCapeVerde                  = -1001,    //(GMT-01:00) Cape Verde Is.
    kUTC                        =     0,    //(UTC) Universal Coordinated Time
    kGMT                        =     1,    //(GMT) Greenwich Mean Time: Dublin, Edinburgh, Lisbon, London
    kMonrovia                   =     2,    //(GMT) Casablanca, Monrovia
    kBerlin                     =  1000,    //(GMT+01:00) Amsterdam, Berlin, Bern, Rome, Stockholm, Vienna
    kParis                      =  1001,    //(GMT+01:00) Brussels, Copenhagen, Madrid, Paris
    kPrague                     =  1002,    //(GMT+01:00) Belgrade, Bratislava, Budapest, Ljubljana, Prague
    kSarajevo                   =  1003,    //(GMT+01:00) Sarajevo, Skopje, Warsaw, Zagreb
    kWestCentralAfrica          =  1004,    //(GMT+01:00) West Central Africa
    kAthens                     =  2000,    //(GMT+02:00) Athens, Beirut, Istanbul, Minsk
    kEasternEurope              =  2001,    //(GMT+02:00) Bucharest
    kCairo                      =  2002,    //(GMT+02:00) Cairo
    kHarare                     =  2003,    //(GMT+02:00) Harare, Pretoria
    kHelsinki                   =  2004,    //(GMT+02:00) Helsinki, Kyiv, Riga, Sofia, Tallinn, Vilnius
    kJerusalem                  =  2005,    //(GMT+02:00) Jerusalem
    kMoscow                     =  3000,    //(GMT+03:00) Moscow, St. Petersburg, Volgograd
    kRiyadh                     =  3001,    //(GMT+03:00) Kuwait, Riyadh
    kBaghdad                    =  3002,    //(GMT+03:00) Baghdad
    kEastAfrica                 =  3003,    //(GMT+03:00) Nairobi
    kTehran                     =  3300,    //(GMT+03:30) Tehran
    kAbuDhabi                   =  4000,    //(GMT+04:00) Abu Dhabi, Muscat
    kCaucasus                   =  4001,    //(GMT+04:00) Baku, Tbilisi, Yerevan
    kKabul                      =  4300,    //(GMT+04:30) Kabul
    kEkaterinburg               =  5000,    //(GMT+05:00) Ekaterinburg
    kIslamabad                  =  5001,    //(GMT+05:00) Islamabad, Karachi, Tashkent
    kKolkata                    =  5300,    //(GMT+05:30) Chennai, Kolkata, Mumbai, New Delhi
    kKathmandu                  =  5450,    //(GMT+05:45) Kathmandu
    kAlmaty                     =  6000,    //(GMT+06:00) Almaty, Novosibirsk
    kDhaka                      =  6001,    //(GMT+06:00) Astana, Dhaka
    kSriLanka                   =  6002,    //(GMT+06:00) Sri Jayawardenepura
    kRangoon                    =  6300,    //(GMT+06:30) Rangoon
    kBangkok                    =  7000,    //(GMT+07:00) Bangkok, Hanoi, Jakarta
    kKrasnoyarsk                =  7001,    //(GMT+07:00) Krasnoyarsk
    kBeijing                    =  8000,    //(GMT+08:00) Beijing, Chongqing, Hong Kong, Urumqi
    kSingapore                  =  8001,    //(GMT+08:00) Kuala Lumpur, Singapore
    kTaipei                     =  8002,    //(GMT+08:00) Taipei
    kIrkutsk                    =  8003,    //(GMT+08:00) Irkutsk, Ulaan Bataar
    kPerth                      =  8004,    //(GMT+08:00) Perth
    kTokyo                      =  9000,    //(GMT+09:00) Osaka, Sapporo, Tokyo
    kSeoul                      =  9001,    //(GMT+09:00) Seoul
    kYakutsk                    =  9002,    //(GMT+09:00) Yakutsk
    kAdelaide                   =  9300,    //(GMT+09:30) Adelaide
    kDarwin                     =  9301,    //(GMT+09:30) Darwin
    kSydney                     = 10000,    //(GMT+10:00) Canberra, Melbourne, Sydney
    kGuam                       = 10001,    //(GMT+10:00) Guam, Port Moresby
    kBrisbane                   = 10002,    //(GMT+10:00) Brisbane
    kHobart                     = 10003,    //(GMT+10:00) Hobart
    kVladivostock               = 10004,    //(GMT+10:00) Vladivostok
    kMagadan                    = 11000,    //(GMT+11:00) Magadan, Solomon Is., New Caledonia
    kWellington                 = 12000,    //(GMT+12:00) Auckland, Wellington
    kFiji                       = 12001,    //(GMT+12:00) Fiji, Kamchatka, Marshall Is.
    kTonga                      = 13000,    //(GMT+13:00) Nuku'alofa
  };

  enum EndCaps
  {
    kEndCapNone       =  0,
    kEndCapRound      =  1,
    kEndCapAngle      =  2,
    kEndCapSquare     =  3
  };

  enum JoinStyle
  {
    kJnStylNone       =  0,
    kJnStylRound      =  1,
    kJnStylAngle      =  2,
    kJnStylFlat       =  3
  };

  enum DimArrowFlags
  {
    kFirstArrow  = 0x00,
    kSecondArrow = 0x01
  };

  enum DimblkFlags
  {
    kDimblk = 0,
    kDimblk1,
    kDimblk2,
    kDimLdrBlk
  };

  enum OrthographicView
  {
    kNonOrthoView = 0,
    kTopView      = 1,
    kBottomView   = 2,
    kFrontView    = 3,
    kBackView     = 4,
    kLeftView     = 5,
    kRightView    = 6
  };

  enum VpFreezeOps
  {
    kFreeze = 0,
    kThaw,
    kReset
  };

  enum reservedStringEnumType
  {
    kByLayer           = 0,
    kByBlock           = 1,
    kNone              = 2,
    kContinuous        = 3,
    kStandard          = 4, 
    kNormal            = 5,
    kDefPoints         = 6,
    kDefault           = 7,
    kMissing           = 8,
    kByColor           = 9,
    kModel             = 10,
    kGlobal            = 11, 
    kVS2DWireframe     = 12,
    kVS3DWireframe     = 13,
    kVS3DHidden        = 14,
    kVSRealistic       = 15,
    kVSConceptual      = 16,
    kTitle             = 17, 
    kHeader            = 18, 
    kData              = 19,
    kVSShadesOfGray    = 20,
    kVSSketchy         = 21,
    kVSXRay            = 22,
    kVSShadedWithEdges = 23,
    kVSShaded          = 24,
    kReservedStringCount
  };


  enum SortEntsFlags
  {
    kSortEntsSelection  = 0x01,
    kSortEntsOsnap      = 0x02,
    kSortEntsRedraw     = 0x04,
    kSortEntsSlide      = 0x08, // (obsolete)
    kSortEntsRegen      = 0x10, 
    kSortEntsPlot       = 0x20,
    kSortEntsPsout      = 0x40
  };

  enum DragStat
  {
    kDragStart = 0,
    kDragEnd   = 1,
    kDragAbort = 2
  };

  enum GripStat
  {
    kGripsDone          = 0,
    kGripsToBeDeleted   = 1,
    kDimDataToBeDeleted = 2
  };

  //IcDbTable
  enum CellType
  {
    kUnknownCell           = 0,
    kTextCell              = 1,
    kBlockCell             = 2,
    kMultipleContentCell   = 3
  };

  enum CellContentType
  {
    kCellContentTypeUnknown = 0,
    kCellContentTypeValue   = 0x1,
    kCellContentTypeField   = 0x2,
    kCellContentTypeBlock   = 0x4,
  };

  enum CellEdgeMask
  {
    kTopMask        = 1,
    kRightMask      = 2,
    kBottomMask     = 4,
    kLeftMask       = 8
  };

  enum CellMargin
  {
    kCellMarginTop         = 0x1,
    kCellMarginLeft        = 0x2,
    kCellMarginBottom      = 0x4,
    kCellMarginRight       = 0x8,
    kCellMarginHorzSpacing = 0x10,
    kCellMarginVertSpacing = 0x20
  };

  enum CellContentLayout
  {
    kCellContentLayoutFlow              = 0x1,
    kCellContentLayoutStackedHorizontal = 0x2,
    kCellContentLayoutStackedVertical   = 0x4,
  };

  enum CellState
  {
    kCellStateNone             = 0,
    kCellStateContentLocked    = 0x1,
    kCellStateContentReadOnly  = 0x2,
    kCellStateLinked           = 0x4,
    kCellStateContentModifiedAfterUpdate = 0x8,
    kCellStateFormatLocked     = 0x10,
    kCellStateFormatReadOnly   = 0x20,
    kCellStateFormatModifiedAfterUpdate = 0x40,
    kAllCellStates             = (kCellStateContentLocked | kCellStateContentReadOnly |
    kCellStateLinked | kCellStateContentModifiedAfterUpdate | 
    kCellStateFormatLocked | kCellStateFormatReadOnly |
    kCellStateFormatModifiedAfterUpdate),
  };

  enum CellClass
  {
    kCellClassNone     = 0,
    kCellClassLabel    = 0x1,
    kCellClassData     = 0x2,
  };

  enum CellProperty
  {
    kCellPropInvalid               = 0,
    // Content properties
    kCellPropDataType              = 0x1,
    kCellPropDataFormat            = 0x2,
    kCellPropRotation              = 0x4,
    kCellPropScale                 = 0x8,
    kCellPropAlignment             = 0x10,
    kCellPropContentColor          = 0x20,
    kCellPropTextStyle             = 0x40,
    kCellPropTextHeight            = 0x80,
    kCellPropAutoScale             = 0x100,
    // Cell properties
    kCellPropBackgroundColor       = 0x200,
    kCellPropMarginLeft            = 0x400,
    kCellPropMarginTop             = 0x800,
    kCellPropMarginRight           = 0x1000,
    kCellPropMarginBottom          = 0x2000,
    kCellPropMarginHorzSpacing     = 0x20000,  // TODO: Re-order
    kCellPropMarginVertSpacing     = 0x40000,  // TODO: Re-order
    kCellPropContentLayout         = 0x4000,
    // Row/col properties
    kCellPropMergeAll              = 0x8000,
    // Table properties
    kCellPropFlowDirBtoT           = 0x10000,
    // Combos
    kCellPropDataTypeAndFormat     = (kCellPropDataType | kCellPropDataFormat),
    kCellPropContent               = (kCellPropDataType | kCellPropDataFormat | kCellPropRotation |
    kCellPropScale | kCellPropContentColor |  kCellPropTextStyle | 
    kCellPropTextHeight | kCellPropAutoScale),
    kCellPropBitProperties         = (kCellPropAutoScale | kCellPropMergeAll | kCellPropFlowDirBtoT),
    kCellPropAll                   = (kCellPropDataType | kCellPropDataFormat | kCellPropRotation |
    kCellPropScale | kCellPropAlignment | kCellPropContentColor | kCellPropBackgroundColor | 
    kCellPropTextStyle | kCellPropTextHeight | kCellPropMarginLeft | kCellPropMarginTop |
    kCellPropMarginRight | kCellPropMarginBottom | kCellPropMarginHorzSpacing | 
    kCellPropMarginVertSpacing | kCellPropAutoScale | kCellPropMergeAll | 
    kCellPropFlowDirBtoT | kCellPropContentLayout),
  };

  enum GridProperty
  {
    kGridPropInvalid           = 0,
    kGridPropLineStyle         = 0x1,
    kGridPropLineWeight        = 0x2,
    kGridPropLinetype          = 0x4,
    kGridPropColor             = 0x8,
    kGridPropVisibility        = 0x10,
    kGridPropDoubleLineSpacing = 0x20,
    kGridPropAll               = (kGridPropLineStyle | kGridPropLineWeight | kGridPropLinetype |
    kGridPropColor | kGridPropVisibility | kGridPropDoubleLineSpacing),
  };

  enum GridLineType
  {
    kInvalidGridLine       = 0,
    kHorzTop               = 1,
    kHorzInside            = 2,
    kHorzBottom            = 4,
    kVertLeft              = 8,
    kVertInside            = 0x10,
    kVertRight             = 0x20,
    kHorzGridLineTypes     = kHorzTop | kHorzBottom | kHorzInside,
    kVertGridLineTypes     = kVertLeft | kVertRight | kVertInside,
    kOuterGridLineTypes    = kHorzTop | kHorzBottom | kVertLeft | kVertRight,
    kInnerGridLineTypes    = kHorzInside | kVertInside,
    kAllGridLineTypes      = kOuterGridLineTypes | kInnerGridLineTypes };

    enum GridLineStyle
    {
      kGridLineStyleSingle = 1,
      kGridLineStyleDouble = 2,
    };

    enum CellOption
    {
      kCellOptionNone    = 0,
      kInheritCellFormat = 0x1,
    };

    enum SelectType
    {
      kWindow         = 1,
      kCrossing       = 2
    };

    enum FlowDirection
    {
      kTtoB           = 0,
      kBtoT           = 1
    };

    enum RotationAngle
    {
      kDegreesUnknown = -1,
      kDegrees000     = 0,
      kDegrees090     = 1,
      kDegrees180     = 2,
      kDegrees270     = 3
    };

    enum CellAlignment
    {
      kTopLeft        = 1,
      kTopCenter      = 2,
      kTopRight       = 3,
      kMiddleLeft     = 4,
      kMiddleCenter   = 5,
      kMiddleRight    = 6,
      kBottomLeft     = 7,
      kBottomCenter   = 8,
      kBottomRight    = 9
    };

    enum RowType
    {
      kUnknownRow     = 0,
      kDataRow        = 1,
      kTitleRow       = 2,
      kHeaderRow      = 4,
      kAllRowTypes = kDataRow | kTitleRow | kHeaderRow
    };

    enum TableStyleFlags
    {
      kHorzInsideLineFirst  = 0x1,
      kHorzInsideLineSecond = 0x2,
      kHorzInsideLineThird  = 0x4,
      kTableStyleModified   = 0x8,
      kTableStyleDataTypeModified = 0x10,
    };

    enum TableBreakOption
    {
      kTableBreakNone                    = 0,
      kTableBreakEnableBreaking          = 0x1,
      kTableBreakRepeatTopLabels         = 0x2,
      kTableBreakRepeatBottomLabels      = 0x4,
      kTableBreakAllowManualPositions    = 0x8,
      kTableBreakAllowManualHeights      = 0x10,
    };

    enum TableBreakFlowDirection
    {
      kTableBreakFlowRight         = 0x1,
      kTableBreakFlowDownOrUp      = 0x2,
      kTableBreakFlowLeft          = 0x4,
    };

    enum TableFillOption
    {
      kTableFillNone                     = 0,
      kTableFillRow                      = 0x1,
      kTableFillReverse                  = 0x2,
      kTableFillGenerateSeries           = 0x4,
      kTableFillCopyContent              = 0x8,
      kTableFillCopyFormat               = 0x10,
      kTableFillOverwriteReadOnlyContent = 0x20,
      kTableFillOverwriteReadOnlyFormat  = 0x40,
    };

    enum TableCopyOption   
    { 
      kTableCopyOptionNone                                 = 0,
      kTableCopyOptionExpandOrContractTable                = 0x1,
      kTableCopyOptionSkipContent                          = 0x2,
      kTableCopyOptionSkipValue                            = 0x4,
      kTableCopyOptionSkipField                            = 0x8,
      kTableCopyOptionSkipFormula                          = 0x10,
      kTableCopyOptionSkipBlock                            = 0x20,
      kTableCopyOptionSkipDataLink                         = 0x40,
      kTableCopyOptionSkipLabelCell                        = 0x80,
      kTableCopyOptionSkipDataCell                         = 0x100,
      kTableCopyOptionSkipFormat                           = 0x200,
      kTableCopyOptionSkipCellStyle                        = 0x400,
      kTableCopyOptionConvertFormatToOverrides             = 0x800,
      kTableCopyOptionSkipCellState                        = 0x1000,
      kTableCopyOptionSkipContentFormat                    = 0x2000,
      kTableCopyOptionSkipDissimilarContentFormat          = 0x4000,
      kTableCopyOptionSkipGeometry                         = 0x8000,
      kTableCopyOptionSkipMerges                           = 0x10000,
      kTableCopyOptionFillTarget                           = 0x20000,
      kTableCopyOptionOverwriteReadOnlyContent             = 0x40000,
      kTableCopyOptionOverwriteReadOnlyFormat              = 0x80000,
      kTableCopyOptionOverwriteContentModifiedAfterUpdate  = 0x100000,
      kTableCopyOptionOverwriteFormatModifiedAfterUpdate   = 0x200000,
      kTableCopyOptionOnlyContentModifiedAfterUpdate       = 0x400000,
      kTableCopyOptionOnlyFormatModifiedAfterUpdate        = 0x800000,
      kTableCopyOptionRowHeight                            = 0x1000000,
      kTableCopyOptionColumnWidth                          = 0x2000000,
      kTableCopyOptionFullCellState                        = 0x4000000,
      kTableCopyOptionForRountrip                          = 0x8000000,  
      kTableCopyOptionConvertFieldToValue                  = 0x10000000, 
      kTableCopyOptionSkipFieldTranslation                 = 0x20000000,
		kTableCopyNone                                 = 0,
		kTableCopyExpandOrContractTable                = 0x1,
		kTableCopySkipContent                          = 0x2,
		kTableCopySkipValue                            = 0x4,
		kTableCopySkipField                            = 0x8,
		kTableCopySkipFormula                          = 0x10,
		kTableCopySkipBlock                            = 0x20,
		kTableCopySkipDataLink                         = 0x40,
		kTableCopySkipLabelCell                        = 0x80,
		kTableCopySkipDataCell                         = 0x100,
		kTableCopySkipFormat                           = 0x200,
		kTableCopySkipCellStyle                        = 0x400,
		kTableCopyConvertFormatToOverrides             = 0x800,
		kTableCopySkipCellState                        = 0x1000,
		kTableCopySkipContentFormat                    = 0x2000,
		kTableCopySkipDissimilarContentFormat          = 0x4000,
		kTableCopySkipGeometry                         = 0x8000,
		kTableCopySkipMerges                           = 0x10000,
		kTableCopyFillTarget                           = 0x20000,
		kTableCopyOverwriteReadOnlyContent             = 0x40000,
		kTableCopyOverwriteReadOnlyFormat              = 0x80000,
		kTableCopyOverwriteContentModifiedAfterUpdate  = 0x100000,
		kTableCopyOverwriteFormatModifiedAfterUpdate   = 0x200000,
		kTableCopyOnlyContentModifiedAfterUpdate       = 0x400000,
		kTableCopyOnlyFormatModifiedAfterUpdate        = 0x800000,
		kTableCopyRowHeight                            = 0x1000000,
		kTableCopyColumnWidth                          = 0x2000000,
		kTableCopyFullCellState                        = 0x4000000,
		kTableCopyForRountrip                          = 0x8000000,    // For internal use only
		kTableCopyConvertFieldToValue                  = 0x10000000,   // For internal use only
		kTableCopySkipFieldTranslation                 = 0x20000000,   // For internal use only
    };

    enum TableIteratorOption
    {
      kTableIteratorNone               = 0,
      kTableIteratorIterateSelection   = 0x1,
      kTableIteratorIterateRows        = 0x2,
      kTableIteratorIterateColumns     = 0x4,
      kTableIteratorIterateDataLinks   = 0x80,
      kTableIteratorReverseOrder       = 0x8,
      kTableIteratorSkipReadOnlyContent= 0x10,
      kTableIteratorSkipReadOnlyFormat = 0x20,
      kTableIteratorSkipMerged         = 0x40,
    };

    enum MergeCellStyleOption
    {
      kMergeCellStyleNone                         = 0,
      kMergeCellStyleCopyDuplicates               = 0x1,
      kMergeCellStyleOverwriteDuplicates          = 0x2,
      kMergeCellStyleConvertDuplicatesToOverrides = 0x4,
      kMergeCellStyleIgnoreNewStyles              = 0x8,
    };

    enum TableHitItem
    { 
      kTableHitNone            = 0,
      kTableHitCell            = 0x1,
      kTableHitRowIndicator    = 0x2,
      kTableHitColumnIndicator = 0x4,
      kTableHitGridLine        = 0x8,
    };

    enum RowTypes
    {
      kAllRows = kDataRow | kTitleRow | kHeaderRow
    };

    enum GridLineTypes
    {
      kAllGridLines = kAllGridLineTypes
    };

    enum DrawOrderFlags
    {
      kDrawOrderInPlaceEditOn  = 0x01,
      kDrawOrderInheritanceOn  = 0x02
    };

    enum UpdateThumbnailFlags
    {
      kUpdateModelViews   = 0x01,
      kUpdateSheetViews   = 0x02,
      kUpdateSheets       = 0x04,
      kUpdateWhenAccessed = 0x08,
      kUpdateWhenSaving   = 0x10
    };

    enum EnhancedBlockEvalType
    {
      kInitialization    = 1,
      kForUpdate         = 2,
      kForRefresh        = 3
    };

    enum SliceModelType
    {
      kKeepBothSides    = 0x01,
      kUseCurrentColor  = 0x02
    };

    enum CollisionType
    {
      kCollisionTypeNone  = 0,
      kCollisionTypeSolid = 1
    };

    enum LoftParamType
    {
      kLoftNoParam = 0x00,
      kLoftNoTwist = 0x01,
      kLoftAlignDirection = 0x02,
      kLoftSimplify = 0x04,
      kLoftClose = 0x08,
      kLoftDefault = kLoftNoTwist | kLoftAlignDirection | kLoftSimplify
    };

    enum LoftNormalsType
    {
      kLoftRuled = 0,
      kLoftSmooth = 1,
      kLoftFirstNormal = 2,
      kLoftLastNormal = 3,
      kLoftEndsNormal = 4,
      kLoftAllNormal = 5,
      kLoftUseDraftAngles = 6
    };

    enum ShadowFlags
    {
      kShadowsCastAndReceive  = 0x00,
      kShadowsDoesNotReceive  = 0x01,
      kShadowsDoesNotCast     = 0x02,
      kShadowsIgnore          = kShadowsDoesNotCast | kShadowsDoesNotReceive
    };

    enum LightingUnits
    {
      kLightingUnitsGeneric = 0,
      kLightingUnitsAmerican = 1,
      kLightingUnitsInternational = 2
    };

    enum DataLinkOption
    {
      kDataLinkOptionNone = 0,
      kDataLinkOptionAnonymous = 0x1,
      kDataLinkOptionPersistCache = 0x2,
      kDataLinkOptionDisableInLongTransaction = 0x4,
      kDataLinkHasCustomData = 0x8,
      kDataLinkOptionDisableInLT = kDataLinkOptionDisableInLongTransaction,
      kDataLinkHasCutomData = kDataLinkHasCustomData,
     };

    enum PathOption
    {
      kPathOptionNone = 1,
      kPathOptionRelative,
      kPathOptionAbsolute,
      kPathOptionPathAndFile,
      kNoPath = kPathOptionNone,
      kRelativePath = kPathOptionRelative,
      kAbsolutePath = kPathOptionAbsolute,
      kPathAndFile = kPathOptionPathAndFile
    };

    enum UpdateDirection
    {
      kUpdateDirectionSourceToData = 0x1,
      kUpdateDirectionDataToSource = 0x2
    };

    enum UpdateOption
    {
      kUpdateOptionNone = 0,
      kUpdateOptionSkipFormat = 0x20000,
      kUpdateOptionUpdateRowHeight = 0x40000,
      kUpdateOptionUpdateColumnWidth = 0x80000,
      kUpdateOptionAllowSourceUpdate = 0x100000,
      kUpdateOptionForceFullSourceUpdate = 0x200000,
      kUpdateOptionOverwriteContentModifiedAfterUpdate = 0x400000,
      kUpdateOptionOverwriteFormatModifiedAfterUpdate = 0x800000,
      kUpdateOptionForPreview = 0x1000000,
      kUpdateOptionIncludeXrefs = 0x2000000,
      kUpdateOptionSkipFormatAfterFirstUpdate = 0x4000000
    };

    enum DataLinkGetSourceContext
    {
      kDataLinkGetSourceContextUnknown,
      kDataLinkGetSourceContextEtransmit,
      kDataLinkGetSourceContextXrefManager,
      kDataLinkGetSourceContextFileWatcher,
      kDataLinkGetSourceContextOther,
      kDataLinkGetSourceContextOrignalPath = (0x1 << 8),
    };

    enum IndexCreation
    {
      kNoIndex = 0,
      kIndexByLayer = 1,
      kIndexSpatially = 2
    };

    enum LayerEvaluation {
      kNoNewLayerEvaluation = 0,
      kEvalNewXrefLayers = 1,
      kEvalAllNewLayers = 2
    };

    enum NewLayerNotification
    {
      kNoNewLayerNotification = 0,
      kNotifyOnPlot = 1,
      kNotifyOnOpen = 2,
      kNotifyOnXrefAttachAndReload = 4,
      kNotifyOnLayerStateRestore = 8,
      kNotifyOnSave = 16,
      kNotifyOnInsert = 32
    };
}

#pragma pack(pop)