#pragma once

#include "../acadstrc.h"
#include "brgbl.h"

#define AcBrErrorStatus     OdBrErrorStatus
#define AcBrRelation        BrRelation
#define AcBrElement2dShape  Element2dShape
#define AcBrLoopType        BrLoopType
#define AcBrValidationLevel BrValidationLevel
#define AcBrShellType       BrShellType

const AcBrErrorStatus	eOk					= AcBr::eOk;
const AcBrErrorStatus	eNotImplementedYet	= AcBr::eNotImplementedYet;
const AcBrErrorStatus	eNotApplicable		= AcBr::eNotApplicable;
const AcBrErrorStatus	eInvalidInput		= AcBr::eInvalidInput;
const AcBrErrorStatus	eOutOfMemory		= AcBr::eOutOfMemory;
const AcBrErrorStatus	eNullObjectPointer	= AcBr::eNullObjectPointer;
const AcBrErrorStatus	eWrongObjectType	= AcBr::eWrongObjectType;
const AcBrErrorStatus	eWrongSubentityType	= AcBr::eWrongSubentityType;
const AcBrErrorStatus	eBrepChanged		= AcBr::eBrepChanged;
const AcBrErrorStatus	eNullObjectId		= AcBr::eNullObjectId;
const AcBrErrorStatus	eNullSubentityId	= AcBr::eNullSubentityId;
const AcBrErrorStatus	eObjectIdMismatch	= AcBr::eObjectIdMismatch;
const AcBrErrorStatus	eTopologyMismatch	= AcBr::eTopologyMismatch;
const AcBrErrorStatus	eUnsuitableTopology	= AcBr::eUnsuitableTopology;
const AcBrErrorStatus	eUnsuitableGeometry	= AcBr::eUnsuitableGeometry;
const AcBrErrorStatus	eMissingGeometry	= AcBr::eMissingGeometry;
const AcBrErrorStatus	eMissingSubentity	= AcBr::eMissingSubentity;
const AcBrErrorStatus	eInvalidObject		= AcBr::eInvalidObject;
const AcBrErrorStatus	eAmbiguousOutput	= AcBr::eAmbiguousOutput;
const AcBrErrorStatus	eDegenerateTopology	= AcBr::eDegenerateTopology;
const AcBrErrorStatus	eUninitialisedObject = AcBr::eUninitialisedObject;


