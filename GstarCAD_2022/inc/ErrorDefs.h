/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2011, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) for .dwg files Copyright (C) 2003-2011 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
//
//
// *DWG is the native and proprietary file format for AutoCAD(R) and a trademark  
// of Autodesk, Inc.  Open Design Alliance is not associated with Autodesk.
///////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Error codes definition container


//                    Code                Message string                                  Code Value
OD_ERROR_CODEVAL_DEF( eOk,                OD_T("No error"),                                   0)

OD_ERROR_CODEVAL_DEF( eNotImplementedYet, OD_T("Not implemented yet"),                        1)
OD_ERROR_CODEVAL_DEF( eNotApplicable,     OD_T("Not applicable"),                             2)
OD_ERROR_CODEVAL_DEF( eInvalidInput,      OD_T("Invalid input"),                              3)
OD_ERROR_CODEVAL_DEF( eAmbiguousInput,    OD_T("Ambiguous input"),                            4)
OD_ERROR_CODEVAL_DEF( eAmbiguousOutput,   OD_T("Ambiguous output"),                           5)
OD_ERROR_CODEVAL_DEF( eOutOfMemory,       OD_T("Out of memory"),                              6)
OD_ERROR_CODEVAL_DEF( eBufferTooSmall,    OD_T("Buffer is too small"),                        7)
OD_ERROR_CODEVAL_DEF( eInvalidOpenState,  OD_T("Invalid open state"),                         8)
OD_ERROR_CODEVAL_DEF( eEntityInInactiveLayout, OD_T("Entity is in inactive Layout"),          9)

OD_ERROR_CODEVAL_DEF( eHandleExists, OD_T("Handle exists"),                                   10)
OD_ERROR_CODEVAL_DEF( eNullHandle,        OD_T("Null handle"),                                11)
OD_ERROR_CODEVAL_DEF( eBrokenHandle,      OD_T("Broken handle"),                              12)
OD_ERROR_CODEVAL_DEF( eUnknownHandle,     OD_T("Unknown handle"),                             13)
OD_ERROR_CODEVAL_DEF( eHandleInUse,       OD_T("Handle in use"),                              14)
OD_ERROR_CODEVAL_DEF( eNullObjectPointer, OD_T("Null object pointer"),                        15)
OD_ERROR_CODEVAL_DEF( eNullObjectId,      OD_T("Null object Id"),                             16)
OD_ERROR_CODEVAL_DEF( eNullBlockName,     OD_T("Null Block name"),                            17)
OD_ERROR_CODEVAL_DEF( eContainerNotEmpty, OD_T("Container is not empty"),                     18)

OD_ERROR_CODEVAL_DEF( eNullEntityPointer, OD_T("Null entity pointer"),                        20)
OD_ERROR_CODEVAL_DEF( eIllegalEntityType, OD_T("Illegal entity type"),                        21)
OD_ERROR_CODEVAL_DEF( eKeyNotFound,       OD_T("Key not found"),                              22)
OD_ERROR_CODEVAL_DEF( eDuplicateKey,      OD_T("Duplicate key"),                              23)
OD_ERROR_CODEVAL_DEF( eInvalidIndex,      OD_T("Invalid index"),                              24)
OD_ERROR_CODEVAL_DEF( eDuplicateIndex,    OD_T("Duplicate index"),                            25)
OD_ERROR_CODEVAL_DEF( eAlreadyInDb,       OD_T("Already in Database"),                        26)
OD_ERROR_CODEVAL_DEF( eOutOfDisk,         OD_T("Out of disk"),                                27)
OD_ERROR_CODEVAL_DEF( eDeletedEntry,      OD_T("Deleted entry"),                              28)
OD_ERROR_CODEVAL_DEF( eNegativeValueNotAllowed,   OD_T("Negative value not allowed"),         29)
OD_ERROR_CODEVAL_DEF( eInvalidExtents,    OD_T("Invalid extents"),                            30)
OD_ERROR_CODEVAL_DEF( eInvalidAdsName,    OD_T("Invalid ads name"),                           31)
OD_ERROR_CODEVAL_DEF( eInvalidSymbolTableName,OD_T("Invalid Symbol Table name"),              32)
OD_ERROR_CODEVAL_DEF( eInvalidKey,        OD_T("Invalid key"),                                33)
OD_ERROR_CODEVAL_DEF( eWrongObjectType,   OD_T("Wrong object type"),                          34)
OD_ERROR_CODEVAL_DEF( eWrongDatabase,     OD_T("Wrong Database"),                             35)
OD_ERROR_CODEVAL_DEF( eObjectToBeDeleted, OD_T("Object to be deleted"),                       36)
OD_ERROR_CODEVAL_DEF( eInvalidFileVersion, OD_T("Invalid file version"),                      37)
OD_ERROR_CODEVAL_DEF( eAnonymousEntry,    OD_T("Anonymous entry"),                            38)
OD_ERROR_CODEVAL_DEF( eIllegalReplacement, OD_T("Illegal replacement"),                       39)

OD_ERROR_CODEVAL_DEF( eEndOfObject,       OD_T("End of oject"),                               40)
OD_ERROR_CODEVAL_DEF( eEndOfFile,         OD_T("Unexpected end of file"),                     41)
OD_ERROR_CODEVAL_DEF( eIsReading,         OD_T("Is reading"),                                 42)
OD_ERROR_CODEVAL_DEF( eIsWriting,         OD_T("Is writing"),                                 43)
OD_ERROR_CODEVAL_DEF( eNotOpenForRead,    OD_T("Not opened for read"),                        44)
OD_ERROR_CODEVAL_DEF( eNotOpenForWrite,   OD_T("Not opened for write"),                       45)
OD_ERROR_CODEVAL_DEF( eNotThatKindOfClass, OD_T("Not that kind of class"),                    46)
OD_ERROR_CODEVAL_DEF( eInvalidBlockName,  OD_T("Invalid Block name"),                         47)
OD_ERROR_CODEVAL_DEF( eMissingDxfField,   OD_T("Missing dxf field"),                          48)
OD_ERROR_CODEVAL_DEF( eDuplicateDxfField, OD_T("Duplicate dxf field"),                        49)

OD_ERROR_CODEVAL_DEF( eInvalidGroupCode,  OD_T("Invalid group code"),                         50)
OD_ERROR_CODEVAL_DEF( eInvalidResBuf,     OD_T("Invalid ResBuf"),                             51)
OD_ERROR_CODEVAL_DEF( eBadDxfSequence,    OD_T("Bad Dxf sequence"),                           52)
OD_ERROR_CODEVAL_DEF( eFilerError,         OD_T("Filer error"),                               53)
OD_ERROR_CODEVAL_DEF( eVertexAfterFace,   OD_T("Polyface Mesh vertex after face"),            54)
OD_ERROR_CODEVAL_DEF( eInvalidFaceVertexIndex, OD_T("Invalid Face vertex index"),             55)
OD_ERROR_CODEVAL_DEF( eInvalidMeshVertexIndex, OD_T("Invalid Mesh vertex index"),             56)
OD_ERROR_CODEVAL_DEF( eOtherObjectsBusy,  OD_T("Other objects busy"),                         57)
OD_ERROR_CODEVAL_DEF( eMustFirstAddBlockToDb, OD_T("The invoked BlockTableRecord is not database-resident yet"), 58)
OD_ERROR_CODEVAL_DEF( eCannotNestBlockDefs, OD_T("Cannot nest Block definitions"),            59)

OD_ERROR_CODEVAL_DEF( eDwgRecoveredOK,    OD_T(".dwg file recovered OK"),                     60)
OD_ERROR_CODEVAL_DEF( eDwgNotRecoverable, OD_T(".dwg file is not recoverable"),               61)
OD_ERROR_CODEVAL_DEF( eDxfPartiallyRead,  OD_T(".dxf file partially read"),                   62)
OD_ERROR_CODEVAL_DEF( eDxfReadAborted,    OD_T(".dxf file read aborted"),                     63)
OD_ERROR_CODEVAL_DEF( eDxbPartiallyRead,  OD_T(".dxb file partially read"),                   64)
OD_ERROR_CODEVAL_DEF( eDwgCrcDoesNotMatch, OD_T("CRC does not match"),                        65)
OD_ERROR_CODEVAL_DEF( eDwgSentinelDoesNotMatch, OD_T("Sentinel does not match"),              66)
OD_ERROR_CODEVAL_DEF( eDwgObjectImproperlyRead, OD_T("Object improperly read"),               67)
OD_ERROR_CODEVAL_DEF( eNoInputFiler,      OD_T("No input filer"),                             68)
OD_ERROR_CODEVAL_DEF( eDwgNeedsAFullSave, OD_T("Drawing needs a full save"),                  69)

OD_ERROR_CODEVAL_DEF( eDxbReadAborted,    OD_T(".dxb file read aborted"),                     70)
OD_ERROR_CODEVAL_DEF( eFileLockedByACAD,  OD_T("File Locked By ACAD"),                        71)
OD_ERROR_CODEVAL_DEF( eFileAccessErr,     OD_T("File access error"),                          72)
OD_ERROR_CODEVAL_DEF( eFileSystemErr,     OD_T("File system error"),                          73)
OD_ERROR_CODEVAL_DEF( eFileInternalErr,   OD_T("File internal error"),                        74)
OD_ERROR_CODEVAL_DEF( eFileTooManyOpen,   OD_T("Too many open files"),                        75)
OD_ERROR_CODEVAL_DEF( eFileNotFound,      OD_T("File not found"),                             76)
OD_ERROR_CODEVAL_DEF( eDwkLockFileFound,  OD_T("Dwk lock file found"),                        77)

OD_ERROR_CODEVAL_DEF( eWasErased,         OD_T("Object was erased"),                          80)
OD_ERROR_CODEVAL_DEF( ePermanentlyErased, OD_T("Object was permanently erased"),              81)
OD_ERROR_CODEVAL_DEF( eWasOpenForRead,    OD_T("Was open for read"),                          82)
OD_ERROR_CODEVAL_DEF( eWasOpenForWrite,   OD_T("Was open for write"),                         83)
OD_ERROR_CODEVAL_DEF( eWasOpenForUndo,    OD_T("Was open for undo"),                          84)
OD_ERROR_CODEVAL_DEF( eWasNotifying,      OD_T("Was notifying"),                              85)
OD_ERROR_CODEVAL_DEF( eWasOpenForNotify,  OD_T("Was open for notify"),                        86)
OD_ERROR_CODEVAL_DEF( eOnLockedLayer,     OD_T("On locked Layer"),                            87)
OD_ERROR_CODEVAL_DEF( eMustOpenThruOwner, OD_T("Must open thru owner"),                       88)
OD_ERROR_CODEVAL_DEF( eSubentitiesStillOpen, OD_T("Subentities still open"),                  89)

OD_ERROR_CODEVAL_DEF( eAtMaxReaders,      OD_T("At max readers"),                             90)
OD_ERROR_CODEVAL_DEF( eIsWriteProtected,  OD_T("Is write protected"),                         91)
OD_ERROR_CODEVAL_DEF( eIsXRefObject,      OD_T("Is XRef object"),                             92)
OD_ERROR_CODEVAL_DEF( eNotAnEntity,       OD_T("An object in entitiesToMove is not an entity"), 93)
OD_ERROR_CODEVAL_DEF( eHadMultipleReaders, OD_T("Had multiple readers"),                      94)
OD_ERROR_CODEVAL_DEF( eDuplicateRecordName,   OD_T("Duplicate Record name"),                  95)
OD_ERROR_CODEVAL_DEF( eXRefDependent,         OD_T("Block depend on other XRefs"),            96)
OD_ERROR_CODEVAL_DEF( eSelfReference,         OD_T("Entity references itself"),               97)
OD_ERROR_CODEVAL_DEF( eMissingSymbolTable,    OD_T("Missing Symbol Table"),                   98)
OD_ERROR_CODEVAL_DEF( eMissingSymbolTableRec, OD_T("Missing Symbol Table record"),            99)

OD_ERROR_CODEVAL_DEF( eWasNotOpenForWrite,    OD_T("Was not open for write"),                 100)
OD_ERROR_CODEVAL_DEF( eCloseWasNotifying,     OD_T("Close was notifying"),                    101)
OD_ERROR_CODEVAL_DEF( eCloseModifyAborted,    OD_T("Close modify aborted"),                   102)
OD_ERROR_CODEVAL_DEF( eClosePartialFailure,   OD_T("Close partial failure"),                  103)
OD_ERROR_CODEVAL_DEF( eCloseFailObjectDamaged,OD_T("Close fail object damaged"),              104)
OD_ERROR_CODEVAL_DEF( eCannotBeErasedByCaller,OD_T("Object can't be erased"),                 105)
OD_ERROR_CODEVAL_DEF( eCannotBeResurrected,   OD_T("Cannot be resurrected"),                  106)
OD_ERROR_CODEVAL_DEF( eWasNotErased,          OD_T("Was not erased"),                         107)

OD_ERROR_CODEVAL_DEF( eInsertAfter,           OD_T("Insert after"),                           110)

OD_ERROR_CODEVAL_DEF( eFixedAllErrors,        OD_T("Fixed all errors"),                       120)
OD_ERROR_CODEVAL_DEF( eLeftErrorsUnfixed,     OD_T("Left errors unfixed"),                    122)
OD_ERROR_CODEVAL_DEF( eUnrecoverableErrors,   OD_T("Unrecoverable errors"),                   123)
OD_ERROR_CODEVAL_DEF( eNoDatabase,            OD_T("No Database"),                            124)
OD_ERROR_CODEVAL_DEF( eXdataSizeExceeded,     OD_T("XData size exceeded"),                    125)
OD_ERROR_CODEVAL_DEF( eRegappIdNotFound,      OD_T("Invalid RegApp"),                         126)
OD_ERROR_CODEVAL_DEF( eRepeatEntity,          OD_T("Repeat entity"),                          127)
OD_ERROR_CODEVAL_DEF( eRecordNotInTable,      OD_T("Record not in Table"),                    128)
OD_ERROR_CODEVAL_DEF( eIteratorDone,          OD_T("Iterator done"),                          129)
OD_ERROR_CODEVAL_DEF( eNullIterator,          OD_T("Null iterator"),                          130)
OD_ERROR_CODEVAL_DEF( eNotInBlock,            OD_T("Not in Block"),                           131)
OD_ERROR_CODEVAL_DEF( eOwnerNotInDatabase,    OD_T("Owner not in Database"),                  132)
OD_ERROR_CODEVAL_DEF( eOwnerNotOpenForRead,   OD_T("Owner not open for read"),                133)
OD_ERROR_CODEVAL_DEF( eOwnerNotOpenForWrite,  OD_T("Owner not open for write"),               134)
OD_ERROR_CODEVAL_DEF( eExplodeBeforeTransform, OD_T("Explode before transform"),              135)
OD_ERROR_CODEVAL_DEF( eCannotScaleNonUniformly, OD_T("Cannot transform by non-uniform scaling matrix"), 136)
OD_ERROR_CODEVAL_DEF( eNotInDatabase,         OD_T("Object not in Database"),                 137)
OD_ERROR_CODEVAL_DEF( eNotCurrentDatabase,    OD_T("Not current Database"),                   138)
OD_ERROR_CODEVAL_DEF( eIsAnEntity,            OD_T("Is an entity"),                           139)

OD_ERROR_CODEVAL_DEF( eCannotChangeActiveViewport, OD_T("Cannot change properties of active Viewport!"), 140)
OD_ERROR_CODEVAL_DEF( eNotInPaperspace,        OD_T("No active Viewport in Paper Space"),     141)
OD_ERROR_CODEVAL_DEF( eCommandWasInProgress,  OD_T("Command was in progress"),                142)

OD_ERROR_CODEVAL_DEF( eGeneralModelingFailure, OD_T("General modeling failure"),              150)
OD_ERROR_CODEVAL_DEF( eOutOfRange,            OD_T("Out of range"),                           151)
OD_ERROR_CODEVAL_DEF( eNonCoplanarGeometry,   OD_T("Non coplanar geometry"),                  152)
OD_ERROR_CODEVAL_DEF( eDegenerateGeometry,    OD_T("Degenerate geometry"),                    153)
OD_ERROR_CODEVAL_DEF( eInvalidAxis,           OD_T("Invalid axis"),                           154)
OD_ERROR_CODEVAL_DEF( ePointNotOnEntity,      OD_T("Point not on entity"),                    155)
OD_ERROR_CODEVAL_DEF( eSingularPoint,         OD_T("Singular point"),                         156)
OD_ERROR_CODEVAL_DEF( eInvalidOffset,         OD_T("Invalid offset"),                         157)
OD_ERROR_CODEVAL_DEF( eNonPlanarEntity,       OD_T("Non planar entity"),                      158)
OD_ERROR_CODEVAL_DEF( eCannotExplodeEntity,   OD_T("Can not explode entity"),                 159)

OD_ERROR_CODEVAL_DEF( eStringTooLong,         OD_T("String too long"),                        160)
OD_ERROR_CODEVAL_DEF( eInvalidSymTableFlag,   OD_T("Invalid Symbol Table flag"),              161)
OD_ERROR_CODEVAL_DEF( eUndefinedLineType,     OD_T("Undefined LineType"),                     162)
OD_ERROR_CODEVAL_DEF( eInvalidTextStyle,      OD_T("TextStyle is invalid"),                   163)
OD_ERROR_CODEVAL_DEF( eTooFewLineTypeElements, OD_T("Too few LineType elements"),             164)
OD_ERROR_CODEVAL_DEF( eTooManyLineTypeElements, OD_T("Too many LineType elements"),           165)
OD_ERROR_CODEVAL_DEF( eExcessiveItemCount,    OD_T("Excessive item count"),                   166)
OD_ERROR_CODEVAL_DEF( eIgnoredLinetypeRedef,  OD_T("Ignored LineType redefinition"),          167)
OD_ERROR_CODEVAL_DEF( eBadUCS,                OD_T("Bad UCS"),                                168)
OD_ERROR_CODEVAL_DEF( eBadPaperspaceView,     OD_T("Bad Paper Space View"),                   169)

OD_ERROR_CODEVAL_DEF( eSomeInputDataLeftUnread, OD_T("Some input data left unread"),          170)
OD_ERROR_CODEVAL_DEF( eNoInternalSpace,       OD_T("No internal space"),                      171)
OD_ERROR_CODEVAL_DEF( eInvalidDimStyle,       OD_T("Invalid DimensionStyle"),                 172)
OD_ERROR_CODEVAL_DEF( eInvalidLayer,          OD_T("Invalid Layer"),                          173)

OD_ERROR_CODEVAL_DEF( eUserBreak,             OD_T("User break"),                             180)
OD_ERROR_CODEVAL_DEF( eUserUnloaded,          OD_T("User Un loaded"),                         181)

OD_ERROR_CODEVAL_DEF( eDwgNeedsRecovery,      OD_T(".dwg file needs recovery"),               190)
OD_ERROR_CODEVAL_DEF( eDeleteEntity,          OD_T("Delete entity"),                          191)
OD_ERROR_CODEVAL_DEF( eInvalidFix,            OD_T("Invalid fix"),                            192)
OD_ERROR_CODEVAL_DEF( eFSMError,              OD_T("FSM Error"),                              193)

OD_ERROR_CODEVAL_DEF( eBadLayerName,          OD_T("Bad Layer name"),                         200)
OD_ERROR_CODEVAL_DEF( eLayerGroupCodeMissing, OD_T("Layer group code missing"),               201)
OD_ERROR_CODEVAL_DEF( eBadColorIndex,         OD_T("Bad color index"),                        202)
OD_ERROR_CODEVAL_DEF( eBadLinetypeName,       OD_T("Bad LineType name"),                      203)
OD_ERROR_CODEVAL_DEF( eBadLinetypeScale,      OD_T("Bad LineType scale"),                     204)
OD_ERROR_CODEVAL_DEF( eBadVisibilityValue,    OD_T("Bad visibility value"),                   205)
OD_ERROR_CODEVAL_DEF( eProperClassSeparatorExpected, OD_T("Proper class separator expected"), 206)
OD_ERROR_CODEVAL_DEF( eBadLineWeightValue,    OD_T("Bad lineweight value"),                   207)
OD_ERROR_CODEVAL_DEF( eBadColor,              OD_T("Bad color"),                              208)
OD_ERROR_CODEVAL_DEF( eBadMaterialName,       OD_T("Bad Material Name"),                      209)

OD_ERROR_CODEVAL_DEF( ePagerError,            OD_T("Pager error"),                            210)
OD_ERROR_CODEVAL_DEF( eOutOfPagerMemory,      OD_T("Out of pager memory"),                    211)
OD_ERROR_CODEVAL_DEF( ePagerWriteError,       OD_T("Pager write error"),                      212)
OD_ERROR_CODEVAL_DEF( eWasNotForwarding,      OD_T("Was not forwarding"),                     213)

OD_ERROR_CODEVAL_DEF( eInvalidIdMap,          OD_T("Invalid Id map"),                         220)
OD_ERROR_CODEVAL_DEF( eInvalidOwnerObject,    OD_T("Invalid owner Object"),                   221)
OD_ERROR_CODEVAL_DEF( eOwnerNotSet,           OD_T("Owner not set"),                          222)

OD_ERROR_CODEVAL_DEF( eWrongSubentityType,    OD_T("Wrong subentity type"),                   230)
OD_ERROR_CODEVAL_DEF( eTooManyVertices,       OD_T("Too many vertices"),                      231)
OD_ERROR_CODEVAL_DEF( eTooFewVertices,        OD_T("Too few vertices"),                       232)

OD_ERROR_CODEVAL_DEF( eNoActiveTransactions,  OD_T("No active transactions"),                 250)
OD_ERROR_CODEVAL_DEF( eNotTopTransaction,     OD_T("Not top transaction"),                    251)
OD_ERROR_CODEVAL_DEF( eTransactionOpenWhileCommandEnded, OD_T("Transaction open while command ended"), 252)
OD_ERROR_CODEVAL_DEF( eInProcessOfCommitting, OD_T("In process of committing"),               253)
OD_ERROR_CODEVAL_DEF( eNotNewlyCreated,       OD_T("Not newly created object"),               254)
OD_ERROR_CODEVAL_DEF( eLongTransReferenceError, OD_T("Entity is excluded from long transaction"), 255)
OD_ERROR_CODEVAL_DEF( eNoWorkSet,             OD_T("No work set"),                            256)

OD_ERROR_CODEVAL_DEF( eAlreadyInGroup,        OD_T("Entity already in group"),                260)
OD_ERROR_CODEVAL_DEF( eNotInGroup,            OD_T("There is no entity with this Id in group"), 261)
OD_ERROR_CODEVAL_DEF( eAlreadyInferred,       OD_T("Already Inferred"),                       262)

OD_ERROR_CODEVAL_DEF( eInvalidREFIID,         OD_T("Invalid REFIID"),                         290)
OD_ERROR_CODEVAL_DEF( eInvalidNormal,         OD_T("Invalid normal"),                         291)
OD_ERROR_CODEVAL_DEF( eInvalidStyle,          OD_T("Invalid Style"),                          292)

OD_ERROR_CODEVAL_DEF( eCannotRestoreFromAcisFile, OD_T("Cannot restore from Acis file"),      300)
OD_ERROR_CODEVAL_DEF( eMakeMeProxy,           OD_T("Make me proxy"),                          301)
OD_ERROR_CODEVAL_DEF( eNLSFileNotAvailable,   OD_T("NLS file not available"),                 302)
OD_ERROR_CODEVAL_DEF( eNotAllowedForThisProxy, OD_T("Not allowed for this proxy"),            303)
OD_ERROR_CODEVAL_DEF( eNotClonedPrimaryProxy, OD_T("Not Cloned PrimaryProxy"),                304)

OD_ERROR_CODEVAL_DEF( eNotSupportedInDwgApi,  OD_T("Not supported in API"),                   310)
OD_ERROR_CODEVAL_DEF( ePolyWidthLost,         OD_T("Poly width lost"),                        311)
OD_ERROR_CODEVAL_DEF( eNullExtents,           OD_T("Null extents"),                           312)
OD_ERROR_CODEVAL_DEF( eBadDwgHeader,          OD_T("Bad .dwg file header"),                   314)

OD_ERROR_CODEVAL_DEF( eLockViolation,         OD_T("Lock violation"),                         320)
OD_ERROR_CODEVAL_DEF( eLockConflict,          OD_T("Lock conflict"),                          321)
OD_ERROR_CODEVAL_DEF( eDatabaseObjectsOpen,   OD_T("Database objects open"),                  322)
OD_ERROR_CODEVAL_DEF( eLockChangeInProgress,  OD_T("Lock change in progress"),                323)

OD_ERROR_CODEVAL_DEF( eVetoed,                OD_T("Vetoed"),                                 325)

OD_ERROR_CODEVAL_DEF( eNoDocument,            OD_T("No document"),                            330)
OD_ERROR_CODEVAL_DEF( eNotFromThisDocument,   OD_T("Not from this document"),                 331)
OD_ERROR_CODEVAL_DEF( eLISPActive,            OD_T("LISP active"),                            332)
OD_ERROR_CODEVAL_DEF( eTargetDocNotQuiescent, OD_T("Target doc not quiescent"),               333)
OD_ERROR_CODEVAL_DEF( eDocumentSwitchDisabled, OD_T("Document switch disabled"),              334)
OD_ERROR_CODEVAL_DEF( eInvalidContext,        OD_T("Invalid context of execution"),           335)

OD_ERROR_CODEVAL_DEF( eCreateFailed,          OD_T("Create failed"),                          337)
OD_ERROR_CODEVAL_DEF( eCreateInvalidName,     OD_T("Create invalid name"),                    338)
OD_ERROR_CODEVAL_DEF( eSetFailed,             OD_T("Setting active Layout failed"),           340)
OD_ERROR_CODEVAL_DEF( eDelDoesNotExist,       OD_T("Does not exist"),                         342)
OD_ERROR_CODEVAL_DEF( eDelIsModelSpace,       OD_T("Model Space Layout can't be deleted"),    343)
OD_ERROR_CODEVAL_DEF( eDelLastLayout,         OD_T("Last Paper Space Layout can't be deleted"), 344)
OD_ERROR_CODEVAL_DEF( eDelUnableToSetCurrent, OD_T("Unable to delete current"),               345)
OD_ERROR_CODEVAL_DEF( eDelUnableToFind,       OD_T("Unable to find to delete"),               346)
OD_ERROR_CODEVAL_DEF( eRenameDoesNotExist,    OD_T("Cannot rename non-existing"),             348)
OD_ERROR_CODEVAL_DEF( eRenameIsModelSpace,    OD_T("Model Space Layout can't be renamed"),    349)
OD_ERROR_CODEVAL_DEF( eRenameInvalidLayoutName, OD_T("Invalid Layout name"),                  350)
OD_ERROR_CODEVAL_DEF( eRenameLayoutAlreadyExists, OD_T("Layout already exists"),              351)
OD_ERROR_CODEVAL_DEF( eRenameInvalidName,     OD_T("Cannot rename: the name is invalid"),     352)
OD_ERROR_CODEVAL_DEF( eCopyDoesNotExist,      OD_T("Copy failed: object does not exist"),     354)
OD_ERROR_CODEVAL_DEF( eCopyIsModelSpace,      OD_T("Cannot copy Model Space"),                355)
OD_ERROR_CODEVAL_DEF( eCopyFailed,            OD_T("Copy failed"),                            356)
OD_ERROR_CODEVAL_DEF( eCopyInvalidName,       OD_T("Copy failed: invalid name"),              357)
OD_ERROR_CODEVAL_DEF( eCopyNameExists,        OD_T("Copy failed: such name already exists"),  358)

OD_ERROR_CODEVAL_DEF( eProfileDoesNotExist,   OD_T("Profile does not exist"),                 359)
OD_ERROR_CODEVAL_DEF( eInvalidFileExtension,  OD_T("Invalid file extension"),                 360)
OD_ERROR_CODEVAL_DEF( eInvalidProfileName,    OD_T("Invalid profile name"),                   361)
OD_ERROR_CODEVAL_DEF( eFileExists,            OD_T("File exists"),                            362)
OD_ERROR_CODEVAL_DEF( eProfileIsInUse,        OD_T("Profile is in use"),                      363)
OD_ERROR_CODEVAL_DEF( eCantOpenFile,          OD_T("Can't open file"),                        364)
OD_ERROR_CODEVAL_DEF( eNoFileName,            OD_T("No filename"),                            365)
OD_ERROR_CODEVAL_DEF( eRegistryAccessError,   OD_T("Registry access error"),                  366)
OD_ERROR_CODEVAL_DEF( eRegistryCreateError,   OD_T("Registry create error"),                  367)

OD_ERROR_CODEVAL_DEF( eBadDxfFile,            OD_T("Bad Dxf file"),                           368)
OD_ERROR_CODEVAL_DEF( eUnknownDxfFileFormat,  OD_T("Unknown Dxf file format"),                369)
OD_ERROR_CODEVAL_DEF( eMissingDxfSection,     OD_T("Missing Dxf section"),                    370)
OD_ERROR_CODEVAL_DEF( eInvalidDxfSectionName, OD_T("Invalid Dxf section name"),               371)
OD_ERROR_CODEVAL_DEF( eNotDxfHeaderGroupCode, OD_T("Not Dxf header group code"),              372)
OD_ERROR_CODEVAL_DEF( eUndefinedDxfGroupCode, OD_T("Undefined Dxf group code"),               373)
OD_ERROR_CODEVAL_DEF( eNotInitializedYet,     OD_T("Not initialized yet"),                    374)
OD_ERROR_CODEVAL_DEF( eInvalidDxf2dPoint,     OD_T("Invalid Dxf 2d point"),                   375)
OD_ERROR_CODEVAL_DEF( eInvalidDxf3dPoint,     OD_T("Invalid Dxf 3d point"),                   376)
OD_ERROR_CODEVAL_DEF( eBadlyNestedAppData,    OD_T("Badly nested AppData"),                   378)
OD_ERROR_CODEVAL_DEF( eIncompleteBlockDefinition, OD_T("Incomplete Block definition"),        379)
OD_ERROR_CODEVAL_DEF( eIncompleteComplexObject, OD_T("Incomplete complex object"),            380)
OD_ERROR_CODEVAL_DEF( eBlockDefInEntitySection, OD_T("Block definition in entity section"),   381)
OD_ERROR_CODEVAL_DEF( eNoBlockBegin,          OD_T("No BlockBegin"),                          382)
OD_ERROR_CODEVAL_DEF( eDuplicateLayerName,    OD_T("Duplicate Layer name"),                   383)
OD_ERROR_CODEVAL_DEF( eBadPlotStyleName,      OD_T("Bad PlotStyle name"),                     384)
OD_ERROR_CODEVAL_DEF( eDuplicateBlockName,    OD_T("Duplicate Block name"),                   385)
OD_ERROR_CODEVAL_DEF( eBadPlotStyleType,      OD_T("Bad PlotStyle type"),                     386)
OD_ERROR_CODEVAL_DEF( eBadPlotStyleNameHandle, OD_T("Bad PlotStyle name handle"),             387)
OD_ERROR_CODEVAL_DEF( eUndefineShapeName,     OD_T("Undefined Shape name"),                   388)
OD_ERROR_CODEVAL_DEF( eDuplicateBlockDefinition, OD_T("Duplicate Block definition"),          389)
OD_ERROR_CODEVAL_DEF( eMissingBlockName,      OD_T("Missing Block name"),                     390)
OD_ERROR_CODEVAL_DEF( eBinaryDataSizeExceeded, OD_T("Binary data size exceeded"),             391)
OD_ERROR_CODEVAL_DEF( eObjectIsReferenced,    OD_T("Object is referenced"),                   392)
OD_ERROR_CODEVAL_DEF( eNoThumbnailBitmap,     OD_T("No thumbnail bitmap"),                    393)
OD_ERROR_CODEVAL_DEF( eGuidNoAddress,         OD_T("eGuidNoAddress"),                         394)

OD_ERROR_CODEVAL_DEF( eMustBe0to2,            OD_T("Must be 0 to 2"),                         395)
OD_ERROR_CODEVAL_DEF( eMustBe0to3,            OD_T("Must be 0 to 3"),                         396)
OD_ERROR_CODEVAL_DEF( eMustBe0to4,            OD_T("Must be 0 to 4"),                         397)
OD_ERROR_CODEVAL_DEF( eMustBe0to5,            OD_T("Must be 0 to 5"),                         398)
OD_ERROR_CODEVAL_DEF( eMustBe0to8,            OD_T("Must be 0 to 8"),                         399)
OD_ERROR_CODEVAL_DEF( eMustBe1to8,            OD_T("Must be 1 to 8"),                         400)
OD_ERROR_CODEVAL_DEF( eMustBe1to15,           OD_T("Must be 1 to 15"),                        401)
OD_ERROR_CODEVAL_DEF( eMustBePositive,        OD_T("Must be positive"),                       402)
OD_ERROR_CODEVAL_DEF( eMustBeNonNegative,     OD_T("Must be non negative"),                   403)
OD_ERROR_CODEVAL_DEF( eMustBeNonZero,         OD_T("Must be non zero"),                       404)
OD_ERROR_CODEVAL_DEF( eMustBe1to6,            OD_T("Must be 1 to 6"),                         405)

OD_ERROR_CODEVAL_DEF( eNoPlotStyleTranslationTable, OD_T("No PlotStyle translation table"),   406)
OD_ERROR_CODEVAL_DEF( ePlotStyleInColorDependentMode, OD_T("PlotStyle is in color dependent mode"), 407)
OD_ERROR_CODEVAL_DEF( eMaxLayouts,            OD_T("Max Layouts"),                            408)
OD_ERROR_CODEVAL_DEF( eNoClassId,             OD_T("No ClassId"),                             409)

OD_ERROR_CODEVAL_DEF( eUndoOperationNotAvailable, OD_T("Undo operation is not available"),    410)
OD_ERROR_CODEVAL_DEF( eUndoNoGroupBegin,      OD_T("No undo group begin"),                    411)

OD_ERROR_CODEVAL_DEF( eHatchTooDense,         OD_T("Hatch is too dense - ignoring"),          420)

OD_ERROR_CODEVAL_DEF( eOpenFileCancelled,     OD_T("File open cancelled"),                    430)
OD_ERROR_CODEVAL_DEF( eNotHandled,            OD_T("Not handled"),                            431)
OD_ERROR_CODEVAL_DEF( eMakeMeProxyAndResurrect, OD_T("Make me proxy and resurrect"),          432)
OD_ERROR_CODEVAL_DEF( eFileSharingViolation,  OD_T("File sharing violation"),                 433)
OD_ERROR_CODEVAL_DEF( eUnsupportedFileFormat, OD_T("Unsupported file format"),                434)
OD_ERROR_CODEVAL_DEF( eObsoleteFileFormat,    OD_T("Obsolete file format"),                   435)
OD_ERROR_CODEVAL_DEF( eFileMissingSections,   OD_T("Missing section"),                        436)
OD_ERROR_CODEVAL_DEF( eRepeatedDwgRead,       OD_T("Repeated .dwg file read"),                437)
OD_ERROR_CODEVAL_DEF( eSilentOpenFileCancelled, OD_T("Silent Open file cancelled"),           438)    // arx有 oda没有

OD_ERROR_CODEVAL_DEF( eWrongCellType,         OD_T("Wrong cell type"),                        440)
OD_ERROR_CODEVAL_DEF( eCannotChangeColumnType, OD_T("Cannot change column type"),             441)
OD_ERROR_CODEVAL_DEF( eRowsMustMatchColumns,  OD_T("Rows must match columns"),                442)

OD_ERROR_CODEVAL_DEF( eNullNodeId, OD_T("Null Node Id"),                                      450)
OD_ERROR_CODEVAL_DEF( eNoNodeActive, OD_T("No Node Active"),                                  451)
OD_ERROR_CODEVAL_DEF( eGraphContainsProxies,  OD_T("Graph Contains Proxies"),                 452)

OD_ERROR_CODEVAL_DEF( eDwgShareDemandLoad,    OD_T(".dwg file share demand load"),            500)
OD_ERROR_CODEVAL_DEF( eDwgShareReadAccess,    OD_T(".dwg file share read access"),            501)
OD_ERROR_CODEVAL_DEF( eDwgShareWriteAccess,   OD_T(".dwg file share write access"),           502)

// Plot
OD_ERROR_CODEVAL_DEF( eLoadFailed,            OD_T("Load failed"),                            503)
OD_ERROR_CODEVAL_DEF( eDeviceNotFound,        OD_T("Device not found"),                       504)
OD_ERROR_CODEVAL_DEF( eNoCurrentConfig,       OD_T("No current config"),                      505)
OD_ERROR_CODEVAL_DEF( eNullPtr,               OD_T("Null Ptr"),                               506)
OD_ERROR_CODEVAL_DEF( eNoLayout,              OD_T("No Layout"),                              507)
OD_ERROR_CODEVAL_DEF( eIncompatiblePlotSettings, OD_T("Incompatible PlotSettings"),           508)
OD_ERROR_CODEVAL_DEF( eNonePlotDevice,        OD_T("None plot device"),                       509)
OD_ERROR_CODEVAL_DEF( eNoMatchingMedia,       OD_T("No matching media"),                      510)
OD_ERROR_CODEVAL_DEF( eInvalidView,           OD_T("Invalid View"),                           511)
OD_ERROR_CODEVAL_DEF( eInvalidWindowArea,     OD_T("Invalid window area"),                    512)
OD_ERROR_CODEVAL_DEF( eInvalidPlotArea,       OD_T("Invalid plot area"),                      513)
OD_ERROR_CODEVAL_DEF( eCustomSizeNotPossible, OD_T("Custom size not possible"),               514)
OD_ERROR_CODEVAL_DEF( ePageCancelled,         OD_T("Page cancelled"),                         515)
OD_ERROR_CODEVAL_DEF( ePlotCancelled,         OD_T("Plot cancelled"),                         516)
OD_ERROR_CODEVAL_DEF( eInvalidEngineState,    OD_T("Invalid engine state"),                   517)
OD_ERROR_CODEVAL_DEF( ePlotAlreadyStarted,    OD_T("Plot already started"),                   518)
OD_ERROR_CODEVAL_DEF( eNoErrorHandler,        OD_T("No error handler"),                       519)
OD_ERROR_CODEVAL_DEF( eInvalidPlotInfo,       OD_T("Invalid plot info"),                      520)
OD_ERROR_CODEVAL_DEF( eNumberOfCopiesNotSupported, OD_T("Number of copies not supported"),    521)
OD_ERROR_CODEVAL_DEF( eLayoutNotCurrent,      OD_T("Layout not current"),                     522)
OD_ERROR_CODEVAL_DEF( eGraphicsNotGenerated,  OD_T("Graphics not generated"),                 523)
OD_ERROR_CODEVAL_DEF( eCannotPlotToFile,      OD_T("Cannot Plot To File"),                    524)
OD_ERROR_CODEVAL_DEF( eMustPlotToFile,        OD_T("Must plot to file"),                      525)
OD_ERROR_CODEVAL_DEF( eNotMultiPageCapable,   OD_T("Not multipage capable"),                  526)
OD_ERROR_CODEVAL_DEF( eBackgroundPlotInProgress, OD_T("Background Plot In Progress"),         527)
OD_ERROR_CODEVAL_DEF( eNotShownInPropertyPalette, OD_T("Not Shown In Property Palette"),      528)

// Sub Selection for Table Object
OD_ERROR_CODEVAL_DEF( eSubSelectionSetEmpty,  OD_T("SubSelectionSet empty"),                  550)

// Geometric Modeling 
OD_ERROR_CODEVAL_DEF( eNoIntersections,       OD_T("No Intersections"),                       551)
OD_ERROR_CODEVAL_DEF( eEmbeddedIntersections, OD_T("Embedded Intersections"),                 552)

// Layer property overrides
OD_ERROR_CODEVAL_DEF( eNoOverride,            OD_T("No Override"),                            570)
OD_ERROR_CODEVAL_DEF( eNoStoredOverrides,     OD_T("No Stored Overrides"),                    571)
OD_ERROR_CODEVAL_DEF( eUnableToRetrieveOverrides, OD_T("Unable To Retrieve Overrides"),       572)
OD_ERROR_CODEVAL_DEF( eUnableToStoreOverrides, OD_T("Unable To StoreOverrides"),              573)
OD_ERROR_CODEVAL_DEF( eUnableToRemoveOverrides, OD_T("Unable To Remove Overrides"),           574)

// View Association
OD_ERROR_CODEVAL_DEF( eInvalidObjectId,       OD_T("Invalid object Id"),                      600)
OD_ERROR_CODEVAL_DEF( eInvalidXrefObjectId,   OD_T("Invalid Xref object Id"),                 601)
OD_ERROR_CODEVAL_DEF( eNoViewAssociation,     OD_T("No View association"),                    602)
OD_ERROR_CODEVAL_DEF( eNoLabelBlock,          OD_T("No label Block"),                         603)
OD_ERROR_CODEVAL_DEF( eUnableToSetViewAssociation, OD_T("Unable to set View association"),    604)
OD_ERROR_CODEVAL_DEF( eUnableToGetViewAssociation, OD_T("Unable to get View association"),    605)
OD_ERROR_CODEVAL_DEF( eUnableToSetLabelBlock, OD_T("Unable to set label Block"),              606)
OD_ERROR_CODEVAL_DEF( eUnableToGetLabelBlock, OD_T("Unable to get label Block"),              607)
OD_ERROR_CODEVAL_DEF( eUnableToRemoveAssociation, OD_T("Unable to remove association"),       608)
OD_ERROR_CODEVAL_DEF( eUnableToSyncModelView, OD_T("Unable to sync Model View"),              609)

// Data links
OD_ERROR_CODEVAL_DEF( eDataLinkAdapterNotFound, OD_T("DataLink adapter not found"),           650)
OD_ERROR_CODEVAL_DEF( eDataLinkInvalidAdapterId, OD_T("DataLink invalid adapter id"),         651)
OD_ERROR_CODEVAL_DEF( eDataLinkNotFound,        OD_T("DataLink not found"),                   652)
OD_ERROR_CODEVAL_DEF( eDataLinkBadConnectionString, OD_T("DataLink bad connection string"),   653)
OD_ERROR_CODEVAL_DEF( eDataLinkNotUpdatedYet,   OD_T("DataLink not updated yet"),             654)
OD_ERROR_CODEVAL_DEF( eDataLinkSourceNotFound,  OD_T("DataLink source not found"),            655)
OD_ERROR_CODEVAL_DEF( eDataLinkConnectionFailed, OD_T("DataLink connection failed"),          656)
OD_ERROR_CODEVAL_DEF( eDataLinkSourceUpdateNotAllowed, OD_T("Data Link Source Update Not Allowed"), 657)
OD_ERROR_CODEVAL_DEF( eDataLinkSourceIsWriteProtected, OD_T("DataLink source is write protected"), 658)
OD_ERROR_CODEVAL_DEF( eDataLinkExcelNotFound,  OD_T("Data Link Excel Not Found"),             659)
OD_ERROR_CODEVAL_DEF( eDataLinkOtherError,     OD_T("DataLink other error"),                  660)

// Xref notification
OD_ERROR_CODEVAL_DEF( eXrefReloaded,           OD_T("Xref Reloaded"),                         700)
OD_ERROR_CODEVAL_DEF( eXrefReloadImpossibleAtThisTime, OD_T("Xref Reloaded impossiblt at this time"), 701)    // arx有 oda没有

// DWG Security
OD_ERROR_CODEVAL_DEF( eSecInitializationFailure, OD_T("Initialization failure"),              1001)
OD_ERROR_CODEVAL_DEF( eSecErrorReadingFile,   OD_T("Error reading file"),                     1002)
OD_ERROR_CODEVAL_DEF( eSecErrorWritingFile,   OD_T("Error writing file"),                     1003)

// Status codes specific to Digital Signatures
OD_ERROR_CODEVAL_DEF( eSecInvalidDigitalId,   OD_T("Invalid digital id"),                     1101)
OD_ERROR_CODEVAL_DEF( eSecErrorGeneratingTimestamp, OD_T("Error generating timestamp"),       1102)
OD_ERROR_CODEVAL_DEF( eSecErrorComputingSignature, OD_T("Error computing signature"),         1103)
OD_ERROR_CODEVAL_DEF( eSecErrorWritingSignature, OD_T("Error writing signature"),             1104)

// Status codes specific to password-based protection
OD_ERROR_CODEVAL_DEF( eSecErrorEncryptingData, OD_T("Error encrypting data"),                 1201)
OD_ERROR_CODEVAL_DEF( eSecErrorCipherNotSupported, OD_T("Error cipher not supported"),        1202)
OD_ERROR_CODEVAL_DEF( eSecErrorDecryptingData, OD_T("Error decrypting data"),                 1203)

OD_ERROR_CODEVAL_DEF( eNoAcDbHostApplication, OD_T("No AcDbHost Application"),                1300)
OD_ERROR_CODEVAL_DEF( eNoUnderlayHost,        OD_T("No Underlay Host"),                       1301)

// acad有 oda没有
// Status codes for Point Cloud indexing
OD_ERROR_CODEVAL_DEF( ePCUnknown,             OD_T("Point Cloud Unknown"),                    1400)
OD_ERROR_CODEVAL_DEF( ePCLargeData,           OD_T("Point Cloud Large Data"),                 1401)
OD_ERROR_CODEVAL_DEF( ePCUnknownFileType,     OD_T("Point Cloud Unknown File Type"),          1402)
OD_ERROR_CODEVAL_DEF( ePCFileNotFound,        OD_T("Point Cloud File Not Found"),             1403)
OD_ERROR_CODEVAL_DEF( ePCFileNotCreated,      OD_T("Point Cloud File Not Created"),           1404)
OD_ERROR_CODEVAL_DEF( ePCFileNotOpened,       OD_T("Point Cloud File Not Opened"),            1405)
OD_ERROR_CODEVAL_DEF( ePCFileNotClosed,       OD_T("Point Cloud File Not Closed"),            1406)
OD_ERROR_CODEVAL_DEF( ePCFileNotWritten,      OD_T("Point Cloud File Not Writted"),           1407)
OD_ERROR_CODEVAL_DEF( ePCFileWrongFormat,     OD_T("Point Cloud File Wrong Format"),          1408)
OD_ERROR_CODEVAL_DEF( ePCFileDataSelectorInvalid, OD_T("Point Cloud Data Selector Invalid"),  1409)
OD_ERROR_CODEVAL_DEF( ePCCoordSysReprojectFail, OD_T("Point Cloud Coord Sys Reproject Fail"), 1410)
OD_ERROR_CODEVAL_DEF( ePCDiskSpaceTooSmall,   OD_T("Point Cloud Disk Space Too Small"),       1411)
OD_ERROR_CODEVAL_DEF( ePCThreadTerminated,    OD_T("Point Cloud Thread Terminated"),          1412)
OD_ERROR_CODEVAL_DEF( ePCFileNotErased,       OD_T("Point Cloud File Not Erased"),            1413)
OD_ERROR_CODEVAL_DEF( ePCCoordSysAssignFail,  OD_T("Point Cloud Coord Sys Assign Fail"),      1414)
OD_ERROR_CODEVAL_DEF( ePCLastImporterUnfinished, OD_T("Point Cloud Last Importer Unfinished"), 1415)
OD_ERROR_CODEVAL_DEF( ePCNoEngineInfo,        OD_T("Point Cloud No Engine Info"),             1416)
OD_ERROR_CODEVAL_DEF( ePCInProgress,          OD_T("Point Cloud In Progress"),                1417)

// eveything went through just fine
OD_ERROR_CODEVAL_DEF( eInetBase,              OD_T("InetBase"),                               20000)
OD_ERROR_DEF( eInetInCache,           OD_T("Inet In Cache"))

// File access
OD_ERROR_DEF( eInetFileNotFound,      OD_T("Inet File Not Found"))
OD_ERROR_DEF( eInetBadPath,           OD_T("Inet Bad Path"))
OD_ERROR_DEF( eInetTooManyOpenFiles,  OD_T("Inet Too Many OpenFiles"))
OD_ERROR_DEF( eInetFileAccessDenied,  OD_T("Inet File Access Denied"))
OD_ERROR_DEF( eInetInvalidFileHandle, OD_T("Inet Invalid File Handle"))
OD_ERROR_DEF( eInetDirectoryFull,     OD_T("Inet Directory Full"))
OD_ERROR_DEF( eInetHardwareError,     OD_T("Inet Hardware Error"))
OD_ERROR_DEF( eInetSharingViolation,  OD_T("Inet Sharing Violation"))
OD_ERROR_DEF( eInetDiskFull,          OD_T("Inet Disk Full"))
OD_ERROR_DEF( eInetFileGenericError,  OD_T("Inet File Generic Error"))

// AcadInet-specific
OD_ERROR_DEF( eInetValidURL,          OD_T("Inet Valid URL"))
OD_ERROR_DEF( eInetNotAnURL,          OD_T("Inet Not An URL"))
OD_ERROR_DEF( eInetNoWinInet,         OD_T("Inet No Win Inet"))
OD_ERROR_DEF( eInetOldWinInet,        OD_T("Inet Old Win Inet"))
OD_ERROR_DEF( eInetNoAcadInet,        OD_T("Inet No Acad Inet"))      // arx有 oda没有
OD_ERROR_DEF( eInetNotImplemented,    OD_T("Inet Not Implemented"))
OD_ERROR_DEF( eInetProtocolNotSupported, OD_T("Inet Protocol Not Supported"))

OD_ERROR_DEF( eInetCreateInternetSessionFailed, OD_T("Inet Create Internet Session Failed"))
OD_ERROR_DEF( eInetInternetSessionConnectFailed, OD_T("Inet Internet Session Connect Failed"))
OD_ERROR_DEF( eInetInternetSessionOpenFailed, OD_T("Inet Internet Session Open Failed"))
                      
OD_ERROR_DEF( eInetInvalidAccessType, OD_T("Inet Invalid Access Type"))
OD_ERROR_DEF( eInetFileOpenFailed,    OD_T("Inet File Open Failed"))
OD_ERROR_DEF( eInetHttpOpenRequestFailed, OD_T("Inet Http Open Request Failed"))
OD_ERROR_DEF( eInetUserCancelledTransfer, OD_T("Inet User Cancelled Transfer"))

// WinInet-specific
OD_ERROR_DEF( eInetHttpBadRequest,    OD_T("Inet Http Bad Request"))
OD_ERROR_DEF( eInetHttpAccessDenied,  OD_T("Inet Http Access Denied"))
OD_ERROR_DEF( eInetHttpPaymentRequired, OD_T("Inet Http Payment Required"))
OD_ERROR_DEF( eInetHttpRequestForbidden, OD_T("Inet Http Request Forbidden"))
OD_ERROR_DEF( eInetHttpObjectNotFound, OD_T("Inet Http Object Not Found"))
OD_ERROR_DEF( eInetHttpBadMethod,     OD_T("Inet Http Bad Method"))
OD_ERROR_DEF( eInetHttpNoAcceptableResponse, OD_T("Inet Http No Acceptable Response，"))
OD_ERROR_DEF( eInetHttpProxyAuthorizationRequired, OD_T("Inet Http Proxy Authorization Required"))
OD_ERROR_DEF( eInetHttpTimedOut,      OD_T("Inet Http Timed Out"))
OD_ERROR_DEF( eInetHttpConflict,      OD_T("Inet Http Conflict"))
OD_ERROR_DEF( eInetHttpResourceGone,  OD_T("Inet Http Resource Gone"))
OD_ERROR_DEF( eInetHttpLengthRequired, OD_T("Inet Http Length Required"))
OD_ERROR_DEF( eInetHttpPreconditionFailure, OD_T("Inet Http Precondition Failure"))
OD_ERROR_DEF( eInetHttpRequestTooLarge, OD_T("Inet Http Request TooLarge"))
OD_ERROR_DEF( eInetHttpUriTooLong,    OD_T("Inet Http Uri TooLong"))
OD_ERROR_DEF( eInetHttpUnsupportedMedia, OD_T("Inet Http Unsupported Media"))
                      
OD_ERROR_DEF( eInetHttpServerError,   OD_T("Inet Http Server Error"))
OD_ERROR_DEF( eInetHttpNotSupported,  OD_T("Inet Http Not Supported"))
OD_ERROR_DEF( eInetHttpBadGateway,    OD_T("Inet Http Bad Gateway"))
OD_ERROR_DEF( eInetHttpServiceUnavailable, OD_T("Inet Http Service Unavailable"))
OD_ERROR_DEF( eInetHttpGatewayTimeout, OD_T("Inet Http Gateway Timeout"))
OD_ERROR_DEF( eInetHttpVersionNotSupported, OD_T("Inet Http Version Not Supported"))

OD_ERROR_DEF( eInetInternetError,     OD_T("Inet Internet Error"))

// corresponding to the MFC CException
OD_ERROR_DEF( eInetGenericException,  OD_T("Inet Generic Exception"))

// all others
OD_ERROR_DEF( eInetUnknownError,      OD_T("Inet Unknown Error"))

OD_ERROR_DEF( eAlreadyActive,         OD_T("Already active"))
OD_ERROR_DEF( eAlreadyInactive,       OD_T("Already inactive"))
                      
OD_ERROR_DEF( eGraphEdgeNotFound,     OD_T("Graph Edge Not Found"))
OD_ERROR_DEF( eGraphNodeNotFound,     OD_T("Graph Node Not Found"))
OD_ERROR_DEF( eGraphNodeAlreadyExists, OD_T("Graph Node Already Exists"))
OD_ERROR_DEF( eGraphEdgeAlreadyExists, OD_T("GraphEdge Already Exists"))
OD_ERROR_DEF( eGraphCyclesFound,      OD_T("Graph Cycles Found"))

OD_ERROR_DEF( eAlreadyHasRepresentation, OD_T("Already Has Representation"))
OD_ERROR_DEF( eNoRepresentation,      OD_T("No Representation"))

// solid chamfer/fillet
OD_ERROR_DEF( eFailedToSetEdgeChamfers, OD_T("e Failed To Set Edge Chamfers"))
OD_ERROR_DEF( eNoConnectedBlendSet,   OD_T("No Connected Blend Set"))
OD_ERROR_DEF( eFailedToBlend,         OD_T("Failed To Blend"))
OD_ERROR_DEF( eFailedToSetEdgeRounds, OD_T("Failed To Set Edge Rounds"))
OD_ERROR_DEF( eFailedToSetVertexRounds, OD_T("Failed To Set Vertex Rounds"))

// visual styles
OD_ERROR_DEF( eVSNotFound,            OD_T("VS Not Found"))
OD_ERROR_DEF( eVSTrue,                OD_T("eVSTrue"))
OD_ERROR_DEF( eVSFalse,               OD_T("VS False"))
OD_ERROR_DEF( eVSAlreadyExists,       OD_T("VS Already Exists"))
OD_ERROR_DEF( eVSOneOffCreated,       OD_T("VS One Off Created"))
OD_ERROR_DEF( eVSAPIOnlyValues,       OD_T("VS API Only Values"))
OD_ERROR_DEF( eVSIsInUse,             OD_T("VS Is In Use"))
OD_ERROR_DEF( eVSIsAcadDefault,       OD_T("VS Is Acad Default"))

// solid history evaluation
OD_ERROR_DEF( eEmptyOperand,          OD_T("Empty Operand"))
OD_ERROR_DEF( eNoEntitiesFromPersistentIds, OD_T("No Entities From Persistent Ids"))
OD_ERROR_DEF( eFailedCurveCheck, OD_T("Failed Curve Check"))    // arx有 oda没有
OD_ERROR_DEF( eMaxNodes, OD_T("Max Nodes"))

//Associative Network related errors.
OD_ERROR_DEF( eFailedToEvaluate,      OD_T("Failed To Evaluate"))
OD_ERROR_DEF( eFailedToEvaluateDependents, OD_T("Failed To Evaluate Dependents"))
OD_ERROR_DEF( eInvalidExpression,     OD_T("Invalid Expression"))
OD_ERROR_DEF( eCyclicDependency,      OD_T("Cyclic Dependency"))
OD_ERROR_DEF( eInconsistentConstraint, OD_T("Inconsistent Constraint"))
OD_ERROR_DEF( eOverDefinedConstraint, OD_T("Over Defined Constraint"))
OD_ERROR_DEF( eAllInSameRigidSet,     OD_T("All In Same Rigid Set"))
OD_ERROR_DEF( eInvalidParameterName,  OD_T("Invalid Parameter Name"))
OD_ERROR_DEF( eReferencedInEquation,  OD_T("Referenced In Equation"))
OD_ERROR_DEF( eEntityRestricedInDOF,  OD_T("Entity Restriced In DOF"))

// large object support
OD_ERROR_DEF( eDataTooLarge,          OD_T("Data Too Large"))
OD_ERROR_DEF( eNearSizeLimit,         OD_T("Near Size Limit"))

//////////////////////////////////////////////// arx有 oda没有 ///////////////////////////////////////////
// string user parameters
OD_ERROR_DEF( eStringNotAllowedInExpression, OD_T("String Not Allowed In Expression"))
OD_ERROR_DEF( eTooManyActiveCommands, OD_T("Too Many Active Commands"))

// parametric surface
OD_ERROR_DEF( eUnableToTrimLastPiece, OD_T("Unable To Trim Last Piece"))
OD_ERROR_DEF( eUnableToTrimSurface,   OD_T("Unable To Trim Surface"))

OD_ERROR_DEF( eModifyingAssociativeEntity, OD_T("Modifying Associative Entity"))
OD_ERROR_DEF( eModifyingDimensionWithExpression, OD_T("Modifying Dimension With Expression"))

OD_ERROR_DEF( eDependentOnObjectErased, OD_T("Dependent On Object Erased"))
OD_ERROR_DEF( eSelfIntersecting,      OD_T("Self Intersecting"))
OD_ERROR_DEF( eNotOnBoundary,         OD_T("Not On Boundary"))
OD_ERROR_DEF( eNotConnected,          OD_T("Not Connected"))
OD_ERROR_DEF( eNoInputPath,           OD_T("Modifying Associative Entity"))
OD_ERROR_DEF( eNotAssociative,        OD_T("Modifying Dimension With Expression"))

// ASM G1 discontinuity error 
OD_ERROR_DEF( eNotG1Continuous,       OD_T("Not G1 Continuous"))
OD_ERROR_DEF( eOwnerToBeTransformed,  OD_T("Owner To Be Transformed"))
OD_ERROR_DEF( eMustBeInteger,         OD_T("Must Be Integer"))
OD_ERROR_DEF( eMustBePositiveInteger, OD_T("Must Be Positive Integer"))

// Associative Array
OD_ERROR_DEF( eChangedAgainstAssociativity, OD_T("Change Against Associativity"))
OD_ERROR_DEF( eItemCountChanged,      OD_T("Item Count Changed"))

// AdIntImgServices error
OD_ERROR_DEF(eGetAdIntImgServicesFailed, OD_T("Get Ad Int Img Services Failed"))

// Atil::Image error
OD_ERROR_DEF( eReadImageBufferFailed, OD_T("Read Image Buffer Failed"))
OD_ERROR_DEF( eWriteImageBufferFailed, OD_T("Write Image Buffer Failed"))
OD_ERROR_DEF( eGetImageBytesFailed,   OD_T("Get Image Bytes Failed"))
OD_ERROR_DEF( eGetImageDIBFailed,     OD_T("Get Image DIB Failed"))
OD_ERROR_DEF( eConvertImageFormatFailed, OD_T("Convert Image Format Failed"))

// get preview image error
OD_ERROR_DEF( eGetPreviewImageFailed, OD_T("Invalid Drawing"))
OD_ERROR_DEF( eInvalidPreviewImage,   OD_T("Invalid Drawing"))

// Live Preview error
OD_ERROR_DEF( eDelayMore,             OD_T("Delay More"))
OD_ERROR_DEF( ePreviewFailed,         OD_T("Preview Failed"))
OD_ERROR_DEF( eAbortPreview,          OD_T("Abort Preview"))
OD_ERROR_DEF( eEndPreview,            OD_T("End Preview"))
OD_ERROR_DEF( eNoPreviewContext,      OD_T("No Preview Context"))

// Cloud error
OD_ERROR_DEF( eFileNotInCloud,        OD_T("File Not In Cloud"))

////////////////////////////////////////////////////////////////////////////////////////////////////


// oda 独有的，arx没有  
OD_ERROR_CODEVAL_DEF( eInvalidDrawing,        OD_T("Invalid Drawing"),                        3000)
OD_ERROR_DEF( eInvalidFiler,          OD_T("Invalid filer"))
OD_ERROR_DEF( eNoInterface,           OD_T("No interface"))
OD_ERROR_DEF( eUnsupportedMethod,     OD_T("Unsupported method"))
OD_ERROR_DEF( eDuplicateHandle,       OD_T("Handle already exists"))
OD_ERROR_DEF( eCharacterNotFound,     OD_T("Character not found"))
OD_ERROR_DEF( eFileCloseError,        OD_T("File close error"))
OD_ERROR_DEF( eFileWriteError,        OD_T("File write error"))
OD_ERROR_DEF( eInvalidVertexIndex,    OD_T("Invalid vertex index"))
OD_ERROR_DEF( eUnknownFileType,       OD_T("Unknown file type"))
OD_ERROR_DEF( eInvalidRoundTripR14Data, OD_T("Invalid RoundTripR14 data"))
OD_ERROR_DEF( eDwgCRCError,           OD_T("CRC does not match"))
OD_ERROR_DEF( eInvalidBlkRecordName,  OD_T("Invalid BlockTableRecord name"))
OD_ERROR_DEF( eNotXrefBlock,          OD_T("Block is not an external reference definition"))
OD_ERROR_DEF( eEmptyRecordName,       OD_T("Empty Record name"))
OD_ERROR_DEF( eCannotSaveHatchRoundtrip, OD_T("Cannot save Hatch roundtrip data due to format limitations (they are too large)"))
OD_ERROR_DEF( eHatchHasInconsistentPatParams, OD_T("Hatch is gradient, but either solid fill flag not set or pattern type is not pre-defined"))
OD_ERROR_DEF( eCannotScaleNonOrtho,   OD_T("Cannot transform by non-ortho matrix"))
OD_ERROR_DEF( eInvalidMlineStyle,     OD_T("MLineStyle is invalid"))
OD_ERROR_DEF( eRecoveryFailed,        OD_T("Recovery failed"))
OD_ERROR_DEF( eTransactionIsActive,   OD_T("Transaction is active"))
OD_ERROR_DEF( eBadDwgFile,            OD_T("Bad .dwg file"))
OD_ERROR_DEF( eEmptyAcisFile,         OD_T("Empty ACIS not allowed"))
OD_ERROR_DEF( eExplodeAgain,          OD_T("Explode again"))
OD_ERROR_DEF( eInvalidThumbnailBitmap, OD_T("Invalid thumbnail bitmap"))
OD_ERROR_DEF( eLibIntegrityBroken,    OD_T("Library integrity is broken"))
OD_ERROR_DEF( eCodepageNotFound,      OD_T("Codepage not found"))
OD_ERROR_DEF( eIncorrectInitFileVersion, OD_T("Incorrect init file version"))
OD_ERROR_DEF( eInternalFreetypeError, OD_T("Internal error in Freetype font library"))
OD_ERROR_DEF( eNoUCSPresent,          OD_T("No UCS present in object"))
OD_ERROR_DEF( eBadObjType,            OD_T("Object has wrong type"))
OD_ERROR_DEF( eBadProtocolExtension,  OD_T("Protocol extension object is bad"))
OD_ERROR_DEF( eHatchInvalidPatternName, OD_T("Bad name for Hatch pattern"))
OD_ERROR_DEF( eNotTransactionResident, OD_T("Object is not transaction resident"))
OD_ERROR_DEF( eDwgFileIsEncrypted,    OD_T(".dwg file is encrypted"))
OD_ERROR_DEF( eInvalidPassword,       OD_T("The password is incorrect"))
OD_ERROR_DEF( eDecryptionError,       OD_T("HostApp cannot decrypt data"))
OD_ERROR_DEF( eArithmeticOverflow,    OD_T("An arithmetic overflow"))
OD_ERROR_DEF( eSkipObjPaging,         OD_T("Paging skips the object"))
OD_ERROR_DEF( eStopPaging,            OD_T("Paging is stoped"))
OD_ERROR_DEF( eInvalidDimStyleResBufData,OD_T("Invalid ResBuf with DimensionStyle data"))
OD_ERROR_DEF( eExtendedError,         OD_T("Extended error"))
OD_ERROR_DEF( eGripOpFailure,         OD_T("The grip operation has failed"))
OD_ERROR_DEF( eGripOpNoRedrawGrip,    OD_T("NoRedrawGrip"))
OD_ERROR_DEF( eGripOpGripHotToWarm,   OD_T("GripHotToWarm"))
OD_ERROR_DEF( eGripOpGetNewGripPoints, OD_T("GetNewGripPoints"))
OD_ERROR_DEF( eUnsupportedEarlyDwgVersion, OD_T("Unsupported early .dwg file version"))

OD_ERROR_DEF( eFiniteStateMachineError, OD_T("Finite state machine error"))
OD_ERROR_DEF( eIgnoredLinetypeRedefinition, OD_T("Ignored LineType redefinition"))
OD_ERROR_DEF( eInternetBadPath, OD_T("Bad path"))
OD_ERROR_DEF( eInternetBase, OD_T("Base"))
OD_ERROR_DEF( eInternetCreateInternetSessionFailed, OD_T("CreateInternetSessionFailed"))
OD_ERROR_DEF( eInternetDirectoryFull              , OD_T("DirectoryFull              "))
OD_ERROR_DEF( eInternetDiskFull                   , OD_T("DiskFull                   "))
OD_ERROR_DEF( eInternetFileAccessDenied           , OD_T("FileAccessDenied           "))
OD_ERROR_DEF( eInternetFileGenericError           , OD_T("FileGenericError           "))
OD_ERROR_DEF( eInternetFileNotFound               , OD_T("FileNotFound               "))
OD_ERROR_DEF( eInternetFileOpenFailed             , OD_T("FileOpenFailed             "))
OD_ERROR_DEF( eInternetGenericException           , OD_T("GenericException           "))
OD_ERROR_DEF( eInternetHardwareError              , OD_T("HardwareError              "))
OD_ERROR_DEF( eInternetHttpAccessDenied           , OD_T("HttpAccessDenied           "))
OD_ERROR_DEF( eInternetHttpBadGateway             , OD_T("HttpBadGateway             "))
OD_ERROR_DEF( eInternetHttpBadMethod              , OD_T("HttpBadMethod              "))
OD_ERROR_DEF( eInternetHttpBadRequest             , OD_T("HttpBadRequest             "))
OD_ERROR_DEF( eInternetHttpConflict               , OD_T("HttpConflict               "))
OD_ERROR_DEF( eInternetHttpGatewayTimeout         , OD_T("HttpGatewayTimeout         "))
OD_ERROR_DEF( eInternetHttpLengthRequired         , OD_T("HttpLengthRequired         "))
OD_ERROR_DEF( eInternetHttpNoAcceptableResponse   , OD_T("HttpNoAcceptableResponse   "))
OD_ERROR_DEF( eInternetHttpNotSupported           , OD_T("HttpNotSupported           "))
OD_ERROR_DEF( eInternetHttpObjectNotFound         , OD_T("HttpObjectNotFound         "))
OD_ERROR_DEF( eInternetHttpOpenRequestFailed      , OD_T("HttpOpenRequestFailed      "))
OD_ERROR_DEF( eInternetHttpPaymentRequired        , OD_T("HttpPaymentRequired        "))
OD_ERROR_DEF( eInternetHttpPreconditionFailure    , OD_T("HttpPreconditionFailure    "))
OD_ERROR_DEF( eInternetHttpProxyAuthorizationRequired , OD_T("HttpProxyAuthorizationRequired "))
OD_ERROR_DEF( eInternetHttpRequestForbidden           , OD_T("HttpRequestForbidden           "))
OD_ERROR_DEF( eInternetHttpRequestTooLarge            , OD_T("HttpRequestTooLarge            "))
OD_ERROR_DEF( eInternetHttpResourceGone               , OD_T("HttpResourceGone               "))
OD_ERROR_DEF( eInternetHttpServerError                , OD_T("HttpServerError                "))
OD_ERROR_DEF( eInternetHttpServiceUnavailable         , OD_T("HttpServiceUnavailable         "))
OD_ERROR_DEF( eInternetHttpTimedOut                   , OD_T("HttpTimedOut                   "))
OD_ERROR_DEF( eInternetHttpUnsupportedMedia           , OD_T("HttpUnsupportedMedia           "))
OD_ERROR_DEF( eInternetHttpUriTooLong                 , OD_T("HttpUriTooLong                 "))
OD_ERROR_DEF( eInternetHttpVersionNotSupported        , OD_T("HttpVersionNotSupported        "))
OD_ERROR_DEF( eInternetInCache                        , OD_T("InCache                        "))
OD_ERROR_DEF( eInternetInternetError                  , OD_T("InternetError                  "))
OD_ERROR_DEF( eInternetInternetSessionConnectFailed   , OD_T("InternetSessionConnectFailed   "))
OD_ERROR_DEF( eInternetInternetSessionOpenFailed      , OD_T("InternetSessionOpenFailed      "))
OD_ERROR_DEF( eInternetInvalidAccessType              , OD_T("InvalidAccessType              "))
OD_ERROR_DEF( eInternetInvalidFileHandle              , OD_T("InvalidFileHandle              "))
OD_ERROR_DEF( eInternetNoInternetSupport              , OD_T("NoInternetSupport              "))
OD_ERROR_DEF( eInternetNotAnUrl                       , OD_T("NotAnUrl                       "))
OD_ERROR_DEF( eInternetNotImplemented                 , OD_T("NotImplemented                 "))
OD_ERROR_DEF( eInternetNoWinInternet                  , OD_T("NoWinInternet                  "))
OD_ERROR_DEF( eInternetOK                             , OD_T("OK                             "))
OD_ERROR_DEF( eInternetOldWinInternet                 , OD_T("OldWinInternet                 "))
OD_ERROR_DEF( eInternetProtocolNotSupported           , OD_T("ProtocolNotSupported           "))
OD_ERROR_DEF( eInternetSharingViolation               , OD_T("SharingViolation               "))
OD_ERROR_DEF( eInternetTooManyOpenFiles               , OD_T("TooManyOpenFiles               "))
OD_ERROR_DEF( eInternetUnknownError                   , OD_T("UnknownError                   "))
OD_ERROR_DEF( eInternetUserCancelledTransfer          , OD_T("UserCancelledTransfer          "))
OD_ERROR_DEF( eInternetValidUrl                       , OD_T("Valid URL"))
OD_ERROR_DEF( eTxError                                , OD_T("Tx application error"           ))
OD_ERROR_DEF( eHiddenLayerNotAllowed                  , OD_T("Hidden Layer not allowed"       ))
OD_ERROR_DEF( eCryptProviderUnavailable               , OD_T("The cryptography service provider \"%ls\" used to protect this drawing is not installed on this computer"))
OD_ERROR_DEF( eNoStoredReconcileStatus                , OD_T("No Stored Reconcile Status"     ))
OD_ERROR_DEF( eUnableToStoreReconcileStatus           , OD_T("Unable To Store ReconcileStatus"))

#define eNotImplemented eNotImplementedYet
#define eCannotBeErased eCannotBeErasedByCaller
#define eInvalidDwgVersion eInvalidFileVersion
#define eInvalidDxfCode eInvalidGroupCode
#define eInetOk eInetBase
#define eDwgCRCDoesNotMatch eDwgCRCError
#define eSecInvalidDigitalID eSecInvalidDigitalId
#define eLispActive eLISPActive
#define eNlsFileNotAvailable eNLSFileNotAvailable
