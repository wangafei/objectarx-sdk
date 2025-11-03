/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRGBL_H
#define GC_BRGBL_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/gcadstrc.h"

#ifndef GCBR_PORT
#define GCBR_PORT
#endif

struct GcBr
{
  enum ErrorStatus
  {
    eOk                  = 0,
    eNotImplementedYet   = Gcad::eNotImplementedYet,
    eNotApplicable       = Gcad::eNotApplicable,
    eInvalidInput        = Gcad::eInvalidInput,
    eOutOfMemory         = Gcad::eOutOfMemory,
    eNullObjectPointer   = Gcad::eUnrecoverableErrors,
    eWrongObjectType     = Gcad::eWrongObjectType,
    eWrongSubentityType  = Gcad::eWrongSubentityType,
    eNullObjectId        = Gcad::eNullObjectId,
    eNullSubentityId     = Gcad::eInvalidIndex,
    eObjectIdMismatch    = Gcad::eWrongDatabase,
    eTopologyMismatch    = Gcad::eWrongDatabase,
    eUnsuitableGeometry  = Gcad::eAmbiguousOutput,
    eMissingGeometry     = Gcad::eDegenerateGeometry,
    eMissingSubentity    = Gcad::eNotInDatabase,
    eInvalidObject       = Gcad::eUnrecoverableErrors,
    eAmbiguousOutput     = Gcad::eAmbiguousOutput,
    eBrepChanged         = 3008,
    eUnsuitableTopology  = 3013,
    eDegenerateTopology  = 3020,
    eUninitialisedObject = 3021
  };

  enum Relation
  {
    kUnknown    = 0,
    kOutside    = 1,
    kInside     = 2,
    kBoundary   = 3,
    kCoincident = 4,
    kTangent    = 5,
    kIntersect  = 6
  };

  enum Element2dShape
  {
    kDefault           = 0,
    kAllPolygons       = 1,
    kAllQuadrilaterals = 2,
    kAllTriangles      = 3
  };

  enum LoopType
  {
    kUnclassified     = 0,
    kExterior         = 1,
    kInterior         = 2,
    kWinding          = 3,
    kLoopUnclassified = kUnclassified,
    kLoopExterior     = kExterior,
    kLoopInterior     = kInterior,
    kLoopWinding      = kWinding
  };

  enum ValidationLevel
  {
    kFullValidation = 0,
    kNoValidation   = 1
  };

  enum ShellType
  {
    kShellUnclassified = 0,
    kShellExterior     = 1,
    kShellInterior     = 2
  };
};

#endif
