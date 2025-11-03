/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRGBLABB_H
#define GC_BRGBLABB_H 1

#include "../../../inc/gcadstrc.h"
#include "brgbl.h"

typedef GcBr::ErrorStatus     GcBrErrorStatus;
typedef GcBr::Relation        GcBrRelation;
typedef GcBr::Element2dShape  GcBrElement2dShape;
typedef GcBr::LoopType        GcBrLoopType;
typedef GcBr::ValidationLevel GcBrValidationLevel;
typedef GcBr::ShellType       GcBrShellType;

const GcBrErrorStatus eOk                  = GcBr::eOk;
const GcBrErrorStatus eNotImplementedYet   = GcBr::eNotImplementedYet;
const GcBrErrorStatus eNotApplicable       = GcBr::eNotApplicable;
const GcBrErrorStatus eInvalidInput        = GcBr::eInvalidInput;
const GcBrErrorStatus eOutOfMemory         = GcBr::eOutOfMemory;
const GcBrErrorStatus eNullObjectPointer   = GcBr::eNullObjectPointer;
const GcBrErrorStatus eWrongObjectType     = GcBr::eWrongObjectType;
const GcBrErrorStatus eWrongSubentityType  = GcBr::eWrongSubentityType;
const GcBrErrorStatus eBrepChanged         = GcBr::eBrepChanged;
const GcBrErrorStatus eNullObjectId        = GcBr::eNullObjectId;
const GcBrErrorStatus eNullSubentityId     = GcBr::eNullSubentityId;
const GcBrErrorStatus eObjectIdMismatch    = GcBr::eObjectIdMismatch;
const GcBrErrorStatus eTopologyMismatch    = GcBr::eTopologyMismatch;
const GcBrErrorStatus eUnsuitableTopology  = GcBr::eUnsuitableTopology;
const GcBrErrorStatus eUnsuitableGeometry  = GcBr::eUnsuitableGeometry;
const GcBrErrorStatus eMissingGeometry     = GcBr::eMissingGeometry;
const GcBrErrorStatus eMissingSubentity    = GcBr::eMissingSubentity;
const GcBrErrorStatus eInvalidObject       = GcBr::eInvalidObject;
const GcBrErrorStatus eAmbiguousOutput     = GcBr::eAmbiguousOutput;
const GcBrErrorStatus eDegenerateTopology  = GcBr::eDegenerateTopology;
const GcBrErrorStatus eUninitialisedObject = GcBr::eUninitialisedObject;

#endif