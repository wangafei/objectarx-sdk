/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifdef GD_GCDBABBES_H
#error "gcdbabbES.h included more than once!  Is it included by a .h file?"
#endif

#define GD_GCDBABBES_H 1

#include "gcadstrc.h"   
#include "gcdb.h"       

typedef Gcad::ErrorStatus       ErrorStatus;

typedef GcDb::OpenMode          OpenMode;
typedef GcDb::OsnapMode         OsnapMode;
typedef GcDb::CoordAxis         CoordAxis;
typedef GcDb::CoordSystem       CoordSystem;
typedef GcDb::Intersect         Intersect;
typedef GcDb::Visibility        Visibility;
typedef GcDb::SaveType          SaveType;
typedef GcDb::DxfCode           DxfCode;
typedef GcDb::DwgDataType       DwgDataType;
typedef GcDb::TextHorzMode      TextHorzMode;
typedef GcDb::TextVertMode      TextVertMode;
typedef GcDb::LineSpacingStyle  LineSpacingStyle;
typedef GcDb::Planarity         Planarity;
typedef GcDb::PointIndex        PointIndex;
typedef GcDb::EdgeIndex         EdgeIndex;
typedef GcDb::Poly2dType        Poly2dType;
typedef GcDb::Poly3dType        Poly3dType;
typedef GcDb::PolyMeshType      PolyMeshType;
typedef GcDb::Vertex2dType      Vertex2dType;
typedef GcDb::Vertex3dType      Vertex3dType;
typedef GcDb::SpaceValueType    SpaceValueType;
typedef GcDb::BoolOperType      BoolOperType;
typedef GcDb::SubentType        SubentType;
typedef GcDb::GeomId            GeomId;
typedef GcDb::GeomType          GeomType;
typedef GcDb::OrthographicView  OrthographicView;

const Gcad::ErrorStatus eOk = Gcad::eOk;
const Gcad::ErrorStatus eNotImplementedYet = Gcad::eNotImplementedYet;
const Gcad::ErrorStatus eNotApplicable = Gcad::eNotApplicable;
const Gcad::ErrorStatus eInvalidInput = Gcad::eInvalidInput;
const Gcad::ErrorStatus eAmbiguousInput = Gcad::eAmbiguousInput;
const Gcad::ErrorStatus eAmbiguousOutput = Gcad::eAmbiguousOutput;
const Gcad::ErrorStatus eOutOfMemory = Gcad::eOutOfMemory;
const Gcad::ErrorStatus eBufferTooSmall = Gcad::eBufferTooSmall;
const Gcad::ErrorStatus eInvalidOpenState = Gcad::eInvalidOpenState;
const Gcad::ErrorStatus eEntityInInactiveLayout
    = Gcad::eEntityInInactiveLayout;
const Gcad::ErrorStatus eHandleExists = Gcad::eHandleExists;
const Gcad::ErrorStatus eNullHandle = Gcad::eNullHandle;
const Gcad::ErrorStatus eBrokenHandle = Gcad::eBrokenHandle;
const Gcad::ErrorStatus eUnknownHandle = Gcad::eUnknownHandle;
const Gcad::ErrorStatus eHandleInUse = Gcad::eHandleInUse;
const Gcad::ErrorStatus eNullObjectPointer = Gcad::eNullObjectPointer;
const Gcad::ErrorStatus eNullObjectId = Gcad::eNullObjectId;
const Gcad::ErrorStatus eNullBlockName = Gcad::eNullBlockName;
const Gcad::ErrorStatus eContainerNotEmpty = Gcad::eContainerNotEmpty;
const Gcad::ErrorStatus eNullEntityPointer = Gcad::eNullEntityPointer;
const Gcad::ErrorStatus eIllegalEntityType = Gcad::eIllegalEntityType;
const Gcad::ErrorStatus eKeyNotFound = Gcad::eKeyNotFound;
const Gcad::ErrorStatus eDuplicateKey = Gcad::eDuplicateKey;
const Gcad::ErrorStatus eInvalidIndex = Gcad::eInvalidIndex;
const Gcad::ErrorStatus eDuplicateIndex = Gcad::eDuplicateIndex;
const Gcad::ErrorStatus eAlreadyInDb = Gcad::eAlreadyInDb;
const Gcad::ErrorStatus eOutOfDisk = Gcad::eOutOfDisk;
const Gcad::ErrorStatus eDeletedEntry = Gcad::eDeletedEntry;
const Gcad::ErrorStatus eNegativeValueNotAllowed 
    = Gcad::eNegativeValueNotAllowed;
const Gcad::ErrorStatus eInvalidExtents = Gcad::eInvalidExtents;
const Gcad::ErrorStatus eInvalidGdsName = Gcad::eInvalidGdsName;
const Gcad::ErrorStatus eInvalidKey = Gcad::eInvalidKey;
const Gcad::ErrorStatus eEndOfObject = Gcad::eEndOfObject;
const Gcad::ErrorStatus eEndOfFile = Gcad::eEndOfFile;
const Gcad::ErrorStatus eObjectToBeDeleted = Gcad::eObjectToBeDeleted;
const Gcad::ErrorStatus eInvalidDwgVersion = Gcad::eInvalidDwgVersion;
const Gcad::ErrorStatus eAnonymousEntry = Gcad::eAnonymousEntry;
const Gcad::ErrorStatus eIllegalReplacement = Gcad::eIllegalReplacement;
const Gcad::ErrorStatus eIsReading = Gcad::eIsReading;
const Gcad::ErrorStatus eIsWriting = Gcad::eIsWriting;
const Gcad::ErrorStatus eNotOpenForRead = Gcad::eNotOpenForRead;
const Gcad::ErrorStatus eNotOpenForWrite = Gcad::eNotOpenForWrite;
const Gcad::ErrorStatus eNotThatKindOfClass = Gcad::eNotThatKindOfClass;
const Gcad::ErrorStatus eInvalidDxfCode = Gcad::eInvalidDxfCode;
const Gcad::ErrorStatus eInvalidResBuf = Gcad::eInvalidResBuf;
const Gcad::ErrorStatus eBadDxfSequence = Gcad::eBadDxfSequence;
const Gcad::ErrorStatus eInvalidBlockName = Gcad::eInvalidBlockName;
const Gcad::ErrorStatus eMissingDxfField  = Gcad::eMissingDxfField;
const Gcad::ErrorStatus eDuplicateDxfField = Gcad::eDuplicateDxfField;
const Gcad::ErrorStatus eFilerError = Gcad::eFilerError;
const Gcad::ErrorStatus eVertexAfterFace = Gcad::eVertexAfterFace;
const Gcad::ErrorStatus eInvalidFaceVertexIndex = Gcad::eInvalidFaceVertexIndex;
const Gcad::ErrorStatus eInvalidMeshVertexIndex = Gcad::eInvalidMeshVertexIndex;
const Gcad::ErrorStatus eOtherObjectsBusy = Gcad::eOtherObjectsBusy;
const Gcad::ErrorStatus eMustFirstAddBlockToDb = Gcad::eMustFirstAddBlockToDb;
const Gcad::ErrorStatus eCannotNestBlockDefs = Gcad::eCannotNestBlockDefs;
const Gcad::ErrorStatus eDwgRecoveredOK = Gcad::eDwgRecoveredOK;
const Gcad::ErrorStatus eDwgNotRecoverable = Gcad::eDwgNotRecoverable;
const Gcad::ErrorStatus eDwgNeedsRecovery = Gcad::eDwgNeedsRecovery;
const Gcad::ErrorStatus eDeleteEntity = Gcad::eDeleteEntity;
const Gcad::ErrorStatus eInvalidFix = Gcad::eInvalidFix;
const Gcad::ErrorStatus eFSMError = Gcad::eFSMError;
const Gcad::ErrorStatus eDxfPartiallyRead = Gcad::eDxfPartiallyRead;
const Gcad::ErrorStatus eMissingSymbolTable = Gcad::eMissingSymbolTable;
const Gcad::ErrorStatus eMissingSymbolTableRec = Gcad::eMissingSymbolTableRec;
const Gcad::ErrorStatus eDwgCRCDoesNotMatch = Gcad::eDwgCRCDoesNotMatch;
const Gcad::ErrorStatus eDwgSentinelDoesNotMatch 
    = Gcad::eDwgSentinelDoesNotMatch;
const Gcad::ErrorStatus eDwgObjectImproperlyRead 
    = Gcad::eDwgObjectImproperlyRead;
const Gcad::ErrorStatus eNoInputFiler = Gcad::eNoInputFiler;
const Gcad::ErrorStatus eDwgNeedsAFullSave = Gcad::eDwgNeedsAFullSave;
const Gcad::ErrorStatus eDxfReadAborted = Gcad::eDxfReadAborted;
const Gcad::ErrorStatus eDxbPartiallyRead = Gcad::eDxbPartiallyRead;
const Gcad::ErrorStatus eDxbReadAborted = Gcad::eDxbReadAborted;
const Gcad::ErrorStatus eFileLockedByGCAD = Gcad::eFileLockedByGCAD;
const Gcad::ErrorStatus eFileAccessErr = Gcad::eFileAccessErr;
const Gcad::ErrorStatus eFileSystemErr = Gcad::eFileSystemErr;
const Gcad::ErrorStatus eFileInternalErr = Gcad::eFileInternalErr;
const Gcad::ErrorStatus eFileNotFound = Gcad::eFileNotFound;
const Gcad::ErrorStatus eDwgShareDemandLoad = Gcad::eDwgShareDemandLoad;
const Gcad::ErrorStatus eDwgShareReadAccess = Gcad::eDwgShareReadAccess;
const Gcad::ErrorStatus eDwgShareWriteAccess = Gcad::eDwgShareWriteAccess;
const Gcad::ErrorStatus eDwkLockFileFound = Gcad::eDwkLockFileFound;
const Gcad::ErrorStatus eWasErased = Gcad::eWasErased;
const Gcad::ErrorStatus eWasNotErased = Gcad::eWasNotErased;
const Gcad::ErrorStatus ePermanentlyErased = Gcad::ePermanentlyErased;
const Gcad::ErrorStatus eWasOpenForRead = Gcad::eWasOpenForRead;
const Gcad::ErrorStatus eWasOpenForWrite = Gcad::eWasOpenForWrite;
const Gcad::ErrorStatus eWasOpenForUndo = Gcad::eWasOpenForUndo;
const Gcad::ErrorStatus eWasNotifying = Gcad::eWasNotifying;
const Gcad::ErrorStatus eWasOpenForNotify = Gcad::eWasOpenForNotify;
const Gcad::ErrorStatus eOnLockedLayer = Gcad::eOnLockedLayer;
const Gcad::ErrorStatus eMustOpenThruOwner = Gcad::eMustOpenThruOwner;
const Gcad::ErrorStatus eSubentitiesStillOpen = Gcad::eSubentitiesStillOpen;
const Gcad::ErrorStatus eAtMaxReaders = Gcad::eAtMaxReaders;
const Gcad::ErrorStatus eIsWriteProtected = Gcad::eIsWriteProtected;
const Gcad::ErrorStatus eIsXRefObject = Gcad::eIsXRefObject;
const Gcad::ErrorStatus eNotAnEntity = Gcad::eNotAnEntity;
const Gcad::ErrorStatus eHadMultipleReaders = Gcad::eHadMultipleReaders;
const Gcad::ErrorStatus eWasNotOpenForWrite = Gcad::eWasNotOpenForWrite;
const Gcad::ErrorStatus eCloseWasNotifying = Gcad::eCloseWasNotifying;
const Gcad::ErrorStatus eCloseModifyAborted = Gcad::eCloseModifyAborted;
const Gcad::ErrorStatus eClosePartialFailure = Gcad::eClosePartialFailure;
const Gcad::ErrorStatus eCannotBeErasedByCaller = Gcad::eCannotBeErasedByCaller;
const Gcad::ErrorStatus eFixedAllErrors = Gcad::eFixedAllErrors;
const Gcad::ErrorStatus eLeftErrorsUnfixed = Gcad::eLeftErrorsUnfixed;
const Gcad::ErrorStatus eUnrecoverableErrors = Gcad::eUnrecoverableErrors;
const Gcad::ErrorStatus eNoDatabase = Gcad::eNoDatabase;
const Gcad::ErrorStatus eXdataSizeExceeded = Gcad::eXdataSizeExceeded;
const Gcad::ErrorStatus eRegappIdNotFound = Gcad::eRegappIdNotFound;
const Gcad::ErrorStatus eRepeatEntity = Gcad::eRepeatEntity;
const Gcad::ErrorStatus eRecordNotInTable = Gcad::eRecordNotInTable;
const Gcad::ErrorStatus eIteratorDone = Gcad::eIteratorDone;
const Gcad::ErrorStatus eNotInBlock = Gcad::eNotInBlock;
const Gcad::ErrorStatus eGeneralModelingFailure = Gcad::eGeneralModelingFailure;
const Gcad::ErrorStatus eOutOfRange = Gcad::eOutOfRange;
const Gcad::ErrorStatus eNonCoplanarGeometry = Gcad::eNonCoplanarGeometry;
const Gcad::ErrorStatus eDegenerateGeometry  = Gcad::eDegenerateGeometry;
const Gcad::ErrorStatus eOwnerNotInDatabase = Gcad::eOwnerNotInDatabase;
const Gcad::ErrorStatus eOwnerNotOpenForRead = Gcad::eOwnerNotOpenForRead;
const Gcad::ErrorStatus eOwnerNotOpenForWrite = Gcad::eOwnerNotOpenForWrite;
const Gcad::ErrorStatus eExplodeBeforeTransform = Gcad::eExplodeBeforeTransform;
const Gcad::ErrorStatus eCannotScaleNonUniformly 
    = Gcad::eCannotScaleNonUniformly;
const Gcad::ErrorStatus eNotInDatabase = Gcad::eNotInDatabase;
const Gcad::ErrorStatus eNotCurrentDatabase = Gcad::eNotCurrentDatabase;
const Gcad::ErrorStatus eIsAnEntity = Gcad::eIsAnEntity;
const Gcad::ErrorStatus eCannotChangeActiveViewport 
    = Gcad::eCannotChangeActiveViewport;
const Gcad::ErrorStatus eNotInPaperspace = Gcad::eNotInPaperspace;
const Gcad::ErrorStatus eCommandWasInProgress = Gcad::eCommandWasInProgress;
const Gcad::ErrorStatus eInvalidAxis  = Gcad::eInvalidAxis;
const Gcad::ErrorStatus ePointNotOnEntity  = Gcad::ePointNotOnEntity;
const Gcad::ErrorStatus eSingularPoint  = Gcad::eSingularPoint;
const Gcad::ErrorStatus eInvalidOffset = Gcad::eInvalidOffset;
const Gcad::ErrorStatus eStringTooLong  = Gcad::eStringTooLong;
const Gcad::ErrorStatus eNullIterator = Gcad::eNullIterator;
const Gcad::ErrorStatus eInvalidSymbolTableName = Gcad::eInvalidSymbolTableName;
const Gcad::ErrorStatus eDuplicateRecordName = Gcad::eDuplicateRecordName;
const Gcad::ErrorStatus eXRefDependent = Gcad::eXRefDependent;
const Gcad::ErrorStatus eSelfReference = Gcad::eSelfReference;
const Gcad::ErrorStatus eWrongDatabase = Gcad::eWrongDatabase;
const Gcad::ErrorStatus eWrongObjectType = Gcad::eWrongObjectType;
const Gcad::ErrorStatus eInvalidSymTableFlag = Gcad::eInvalidSymTableFlag;
const Gcad::ErrorStatus eUndefinedLineType = Gcad::eUndefinedLineType;
const Gcad::ErrorStatus eInvalidTextStyle = Gcad::eInvalidTextStyle;
const Gcad::ErrorStatus eTooFewLineTypeElements = Gcad::eTooFewLineTypeElements;
const Gcad::ErrorStatus eTooManyLineTypeElements 
    = Gcad::eTooManyLineTypeElements;
const Gcad::ErrorStatus eExcessiveItemCount = Gcad::eExcessiveItemCount;
const Gcad::ErrorStatus eIgnoredLinetypeRedef = Gcad::eIgnoredLinetypeRedef;
const Gcad::ErrorStatus eBadUCS = Gcad::eBadUCS;
const Gcad::ErrorStatus eBadPaperspaceView = Gcad::eBadPaperspaceView;
const Gcad::ErrorStatus eSomeInputDataLeftUnread=Gcad::eSomeInputDataLeftUnread;
const Gcad::ErrorStatus eNoInternalSpace=Gcad::eNoInternalSpace;
const Gcad::ErrorStatus eInvalidDimStyle = Gcad::eInvalidDimStyle;
const Gcad::ErrorStatus eInvalidLayer = Gcad::eInvalidLayer;
const Gcad::ErrorStatus eUserBreak = Gcad::eUserBreak;
const Gcad::ErrorStatus eBadLayerName = Gcad::eBadLayerName;
const Gcad::ErrorStatus eLayerGroupCodeMissing = Gcad::eLayerGroupCodeMissing;
const Gcad::ErrorStatus eBadColorIndex = Gcad::eBadColorIndex;
const Gcad::ErrorStatus eBadColor = Gcad::eBadColor;
const Gcad::ErrorStatus eBadLinetypeName = Gcad::eBadLinetypeName;
const Gcad::ErrorStatus eBadLinetypeScale = Gcad::eBadLinetypeScale;
const Gcad::ErrorStatus eBadVisibilityValue = Gcad::eBadVisibilityValue;
const Gcad::ErrorStatus eProperClassSeparatorExpected 
    = Gcad::eProperClassSeparatorExpected;
const Gcad::ErrorStatus eBadMaterialName = Gcad::eBadMaterialName;
const Gcad::ErrorStatus ePagerError = Gcad::ePagerError;
const Gcad::ErrorStatus eOutOfPagerMemory = Gcad::eOutOfPagerMemory;
const Gcad::ErrorStatus ePagerWriteError = Gcad::ePagerWriteError;
const Gcad::ErrorStatus eWasNotForwarding = Gcad::eWasNotForwarding;
const Gcad::ErrorStatus eInvalidIdMap = Gcad::eInvalidIdMap;
const Gcad::ErrorStatus eInvalidOwnerObject = Gcad::eInvalidOwnerObject;
const Gcad::ErrorStatus eOwnerNotSet = Gcad::eOwnerNotSet;
const Gcad::ErrorStatus eNoActiveTransactions = Gcad::eNoActiveTransactions; 
const Gcad::ErrorStatus eNotTopTransaction = Gcad::eNotTopTransaction; 
const Gcad::ErrorStatus eTransactionOpenWhileCommandEnded 
    = Gcad::eTransactionOpenWhileCommandEnded;
const Gcad::ErrorStatus eInProcessOfCommitting 
    = Gcad::eInProcessOfCommitting;
const Gcad::ErrorStatus eNotNewlyCreated = Gcad::eNotNewlyCreated;
const Gcad::ErrorStatus eLongTransReferenceError 
    = Gcad::eLongTransReferenceError;
const Gcad::ErrorStatus eNoWorkSet = Gcad::eNoWorkSet;
const Gcad::ErrorStatus eAlreadyInGroup = Gcad::eAlreadyInGroup;
const Gcad::ErrorStatus eNotInGroup = Gcad::eNotInGroup;
const Gcad::ErrorStatus eWrongSubentityType = Gcad::eWrongSubentityType;
const Gcad::ErrorStatus eInvalidStyle = Gcad::eInvalidStyle;
const Gcad::ErrorStatus eCannotRestoreFromAcisFile 
    = Gcad::eCannotRestoreFromAcisFile;
const Gcad::ErrorStatus eNonPlanarEntity = Gcad::eNonPlanarEntity;
const Gcad::ErrorStatus eCannotExplodeEntity = Gcad::eCannotExplodeEntity;
const Gcad::ErrorStatus ePolyWidthLost = Gcad::ePolyWidthLost;
const Gcad::ErrorStatus eNullExtents = Gcad::eNullExtents;

const Gcad::ErrorStatus eLockViolation = Gcad::eLockViolation;
const Gcad::ErrorStatus eLockConflict = Gcad::eLockConflict;
const Gcad::ErrorStatus eDatabaseObjectsOpen = Gcad::eDatabaseObjectsOpen;
const Gcad::ErrorStatus eLockChangeInProgress = Gcad::eLockChangeInProgress;

const Gcad::ErrorStatus eVetoed = Gcad::eVetoed;
const Gcad::ErrorStatus eXrefReloaded = Gcad::eXrefReloaded;
const Gcad::ErrorStatus eXrefReloadImpossibleAtThisTime = Gcad::eXrefReloadImpossibleAtThisTime;

const Gcad::ErrorStatus eNoDocument = Gcad::eNoDocument;
const Gcad::ErrorStatus eNotFromThisDocument = Gcad::eNotFromThisDocument;
const Gcad::ErrorStatus eLISPActive = Gcad::eLISPActive;
const Gcad::ErrorStatus eTargetDocNotQuiescent = Gcad::eTargetDocNotQuiescent;
const Gcad::ErrorStatus eDocumentSwitchDisabled = Gcad::eDocumentSwitchDisabled;
const Gcad::ErrorStatus eInvalidContext = Gcad::eInvalidContext;

const Gcad::ErrorStatus eProfileDoesNotExist = Gcad::eProfileDoesNotExist;
const Gcad::ErrorStatus eInvalidFileExtension= Gcad::eInvalidFileExtension;
const Gcad::ErrorStatus eInvalidProfileName  = Gcad::eInvalidProfileName;
const Gcad::ErrorStatus eFileExists          = Gcad::eFileExists;     
const Gcad::ErrorStatus eProfileIsInUse      = Gcad::eProfileIsInUse;
const Gcad::ErrorStatus eCantOpenFile        = Gcad::eCantOpenFile;
const Gcad::ErrorStatus eNoFileName          = Gcad::eNoFileName;
const Gcad::ErrorStatus eRegistryAccessError = Gcad::eRegistryAccessError;
const Gcad::ErrorStatus eRegistryCreateError = Gcad::eRegistryCreateError;

const Gcad::ErrorStatus eBadDxfFile = Gcad::eBadDxfFile;
const Gcad::ErrorStatus eUnknownDxfFileFormat = Gcad::eUnknownDxfFileFormat;
const Gcad::ErrorStatus eMissingDxfSection = Gcad::eMissingDxfSection;
const Gcad::ErrorStatus eInvalidDxfSectionName = Gcad::eInvalidDxfSectionName;
const Gcad::ErrorStatus eNotDxfHeaderGroupCode = Gcad::eNotDxfHeaderGroupCode;
const Gcad::ErrorStatus eUndefinedDxfGroupCode = Gcad::eUndefinedDxfGroupCode;
const Gcad::ErrorStatus eNotInitializedYet = Gcad::eNotInitializedYet;
const Gcad::ErrorStatus eInvalidDxf2dPoint = Gcad::eInvalidDxf2dPoint;
const Gcad::ErrorStatus eInvalidDxf3dPoint = Gcad::eInvalidDxf3dPoint;
const Gcad::ErrorStatus eBadlyNestedAppData  = Gcad::eBadlyNestedAppData;
const Gcad::ErrorStatus eIncompleteBlockDefinition = Gcad::eIncompleteBlockDefinition;
const Gcad::ErrorStatus eIncompleteComplexObject = Gcad::eIncompleteComplexObject;
const Gcad::ErrorStatus eBlockDefInEntitySection = Gcad::eBlockDefInEntitySection;
const Gcad::ErrorStatus eNoBlockBegin = Gcad::eNoBlockBegin;
const Gcad::ErrorStatus eDuplicateLayerName = Gcad::eDuplicateLayerName;
const Gcad::ErrorStatus eDuplicateBlockName = Gcad::eDuplicateBlockName;
const Gcad::ErrorStatus eBadPlotStyleName = Gcad::eBadPlotStyleName;
const Gcad::ErrorStatus eBadPlotStyleType = Gcad::eBadPlotStyleType;
const Gcad::ErrorStatus eBadPlotStyleNameHandle = Gcad::eBadPlotStyleNameHandle;
const Gcad::ErrorStatus eUndefineShapeName = Gcad::eUndefineShapeName;
const Gcad::ErrorStatus eDuplicateBlockDefinition = Gcad::eDuplicateBlockDefinition;
const Gcad::ErrorStatus eMissingBlockName = Gcad::eMissingBlockName;
const Gcad::ErrorStatus eBinaryDataSizeExceeded = Gcad::eBinaryDataSizeExceeded;
const Gcad::ErrorStatus eHatchTooDense = Gcad::eHatchTooDense;

const Gcad::ErrorStatus eUndoOperationNotAvailable = Gcad::eUndoOperationNotAvailable;
const Gcad::ErrorStatus eUndoNoGroupBegin = Gcad::eUndoNoGroupBegin;

const Gcad::ErrorStatus eObjectIsReferenced = Gcad::eObjectIsReferenced;
const Gcad::ErrorStatus eNoThumbnailBitmap = Gcad::eNoThumbnailBitmap;
const Gcad::ErrorStatus eGuidNoAddress = Gcad::eGuidNoAddress;
const Gcad::ErrorStatus eNoPlotStyleTranslationTable = Gcad::eNoPlotStyleTranslationTable;

const Gcad::ErrorStatus ePlotStyleInColorDependentMode = Gcad::ePlotStyleInColorDependentMode;
const Gcad::ErrorStatus eNoClassId = Gcad::eNoClassId;
const Gcad::ErrorStatus eMaxLayouts = Gcad::eMaxLayouts;

const Gcad::ErrorStatus eWrongCellType = Gcad::eWrongCellType;
const Gcad::ErrorStatus eCannotChangeColumnType = Gcad::eCannotChangeColumnType;
const Gcad::ErrorStatus eRowsMustMatchColumns = Gcad::eRowsMustMatchColumns;

const Gcad::ErrorStatus eNullNodeId = Gcad::eNullNodeId;
const Gcad::ErrorStatus eNoNodeActive = Gcad::eNoNodeActive;
const Gcad::ErrorStatus eGraphContainsProxies = Gcad::eGraphContainsProxies;

const Gcad::ErrorStatus eLoadFailed = Gcad::eLoadFailed;
const Gcad::ErrorStatus eDeviceNotFound = Gcad::eDeviceNotFound;
const Gcad::ErrorStatus eNoCurrentConfig = Gcad::eNoCurrentConfig;
const Gcad::ErrorStatus eNullPtr = Gcad::eNullPtr;
const Gcad::ErrorStatus eNoLayout = Gcad::eNoLayout;
const Gcad::ErrorStatus eIncompatiblePlotSettings = Gcad::eIncompatiblePlotSettings;
const Gcad::ErrorStatus eNonePlotDevice = Gcad::eNonePlotDevice;
const Gcad::ErrorStatus eNoMatchingMedia = Gcad::eNoMatchingMedia;
const Gcad::ErrorStatus eInvalidView = Gcad::eInvalidView;
const Gcad::ErrorStatus eInvalidWindowArea = Gcad::eInvalidWindowArea;
const Gcad::ErrorStatus eInvalidPlotArea = Gcad::eInvalidPlotArea;
const Gcad::ErrorStatus eCustomSizeNotPossible = Gcad::eCustomSizeNotPossible;

const Gcad::ErrorStatus ePageCancelled = Gcad::ePageCancelled;
const Gcad::ErrorStatus ePlotCancelled = Gcad::ePlotCancelled;
const Gcad::ErrorStatus eInvalidEngineState = Gcad::eInvalidEngineState;
const Gcad::ErrorStatus ePlotAlreadyStarted = Gcad::ePlotAlreadyStarted;
const Gcad::ErrorStatus eNoErrorHandler = Gcad::eNoErrorHandler;
const Gcad::ErrorStatus eInvalidPlotInfo = Gcad::eInvalidPlotInfo;
const Gcad::ErrorStatus eNumberOfCopiesNotSupported = Gcad::eNumberOfCopiesNotSupported;
const Gcad::ErrorStatus eLayoutNotCurrent = Gcad::eLayoutNotCurrent;
const Gcad::ErrorStatus eGraphicsNotGenerated = Gcad::eGraphicsNotGenerated;
const Gcad::ErrorStatus eCannotPlotToFile = Gcad::eCannotPlotToFile;
const Gcad::ErrorStatus eMustPlotToFile = Gcad::eMustPlotToFile;
const Gcad::ErrorStatus eBackgroundPlotInProgress = Gcad::eBackgroundPlotInProgress;

const Gcad::ErrorStatus eInvalidObjectId = Gcad::eInvalidObjectId;
const Gcad::ErrorStatus eInvalidXrefObjectId = Gcad::eInvalidXrefObjectId;
const Gcad::ErrorStatus eNoViewAssociation = Gcad::eNoViewAssociation;
const Gcad::ErrorStatus eNoLabelBlock = Gcad::eNoLabelBlock;
const Gcad::ErrorStatus eUnableToSetViewAssociation = Gcad::eUnableToSetViewAssociation;
const Gcad::ErrorStatus eUnableToGetViewAssociation = Gcad::eUnableToGetViewAssociation;
const Gcad::ErrorStatus eUnableToSetLabelBlock = Gcad::eUnableToSetLabelBlock;
const Gcad::ErrorStatus eUnableToGetLabelBlock = Gcad::eUnableToGetLabelBlock;
const Gcad::ErrorStatus eUnableToRemoveAssociation = Gcad::eUnableToRemoveAssociation;
const Gcad::ErrorStatus eUnableToSyncModelView = Gcad::eUnableToSyncModelView;

const Gcad::ErrorStatus eSubSelectionSetEmpty = Gcad::eSubSelectionSetEmpty;
const Gcad::ErrorStatus eGraphEdgeNotFound = Gcad::eGraphEdgeNotFound;
const Gcad::ErrorStatus eGraphNodeNotFound = Gcad::eGraphNodeNotFound;
const Gcad::ErrorStatus eGraphNodeAlreadyExists = Gcad::eGraphNodeAlreadyExists;
const Gcad::ErrorStatus eGraphEdgeAlreadyExists = Gcad::eGraphEdgeAlreadyExists;
const Gcad::ErrorStatus eGraphCyclesFound = Gcad::eGraphCyclesFound;

const Gcad::ErrorStatus eAlreadyHasRepresentation = 
                                        Gcad::eAlreadyHasRepresentation;
const Gcad::ErrorStatus eNoRepresentation = Gcad::eNoRepresentation;
const Gcad::ErrorStatus eNoIntersections = Gcad::eNoIntersections;
const Gcad::ErrorStatus eEmbeddedIntersections = Gcad::eEmbeddedIntersections;

const Gcad::ErrorStatus eFailedToSetEdgeChamfers = Gcad::eFailedToSetEdgeChamfers;
const Gcad::ErrorStatus eNoConnectedBlendSet = Gcad::eNoConnectedBlendSet;
const Gcad::ErrorStatus eFailedToBlend = Gcad::eFailedToBlend;
const Gcad::ErrorStatus eFailedToSetEdgeRounds = Gcad::eFailedToSetEdgeRounds;
const Gcad::ErrorStatus eFailedToSetVertexRounds = Gcad::eFailedToSetVertexRounds;

const Gcad::ErrorStatus eFailedToEvaluate = Gcad::eFailedToEvaluate;
const Gcad::ErrorStatus eFailedToEvaluateDependents = Gcad::eFailedToEvaluateDependents;
const Gcad::ErrorStatus eInvalidExpression = Gcad::eInvalidExpression;
const Gcad::ErrorStatus eCyclicDependency = Gcad::eCyclicDependency;
const Gcad::ErrorStatus eInconsistentConstraint = Gcad::eInconsistentConstraint;
const Gcad::ErrorStatus eOverDefinedConstraint = Gcad::eOverDefinedConstraint;
const Gcad::ErrorStatus eInvalidParameterName = Gcad::eInvalidParameterName;
const Gcad::ErrorStatus eReferencedInEquation = Gcad::eReferencedInEquation;

const Gcad::ErrorStatus eStringNotAllowedInExpression = Gcad::eStringNotAllowedInExpression;
const Gcad::ErrorStatus eTooManyActiveCommands = Gcad::eTooManyActiveCommands;

const Gcad::ErrorStatus eUnableToTrimLastPiece = Gcad::eUnableToTrimLastPiece;
const Gcad::ErrorStatus eUnableToTrimSurface = Gcad::eUnableToTrimSurface;

const Gcad::ErrorStatus eModifyingAssociativeEntity = Gcad::eModifyingAssociativeEntity;
const Gcad::ErrorStatus eModifyingDimensionWithExpression = Gcad::eModifyingDimensionWithExpression;

const Gcad::ErrorStatus eDependentOnObjectErased = Gcad::eDependentOnObjectErased;
const Gcad::ErrorStatus eSelfIntersecting = Gcad::eSelfIntersecting;
const Gcad::ErrorStatus eNotOnBoundary = Gcad::eNotOnBoundary;
const Gcad::ErrorStatus eNotConnected = Gcad::eNotConnected;
const Gcad::ErrorStatus eNoInputPath = Gcad::eNoInputPath;
const Gcad::ErrorStatus eNotAssociative = Gcad::eNotAssociative;
const Gcad::ErrorStatus eNotG1Continuous = Gcad::eNotG1Continuous;

const Gcad::ErrorStatus eChangedAgainstAssociativity = Gcad::eChangedAgainstAssociativity;