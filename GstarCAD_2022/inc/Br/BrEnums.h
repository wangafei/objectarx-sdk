/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2002-2021, Open Design Alliance (the "Alliance"). 
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
//   This application incorporates Open Design Alliance software pursuant to a license 
//   agreement with Open Design Alliance.
//   Open Design Alliance Copyright (C) 2002-2021 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////



// OdBrEnums.h -- declaration of enumerated types used in the
//                OdBr B-Rep and traverser classes.

#pragma warning ( disable : 4482 )  

#ifndef ODBRENUMS_H
#define ODBRENUMS_H
#include "../OdError.h"
#include "../Br/BrExport.h"
#include "../Gi/Gi.h"

#if 1
struct OdBr
{
  enum ErrorStatus
  {
    eOk                   = 0,
    eNotImplementedYet    = Oda::eNotImplementedYet,
    eNotApplicable        = Oda::eNotApplicable,
    eInvalidInput         = Oda::eInvalidInput,
    eOutOfMemory          = Oda::eOutOfMemory,
    eNullObjectPointer    = Oda::eUnrecoverableErrors,
    eWrongObjectType      = Oda::eWrongObjectType,
    eWrongSubentityType   = Oda::eWrongSubentityType,
    eNullObjectId         = Oda::eNullObjectId,
    eNullSubentityId      = Oda::eInvalidIndex,
    eObjectIdMismatch     = Oda::eWrongDatabase,
    eTopologyMismatch     = Oda::eWrongDatabase,
    eUnsuitableGeometry   = Oda::eAmbiguousOutput,
    eMissingGeometry      = Oda::eDegenerateGeometry,
    eMissingSubentity     = Oda::eNotInDatabase,
    eInvalidObject        = Oda::eUnrecoverableErrors,
    eAmbiguousOutput      = Oda::eAmbiguousOutput,

    eBrepChanged          = 3008,
    eUnsuitableTopology   = 3013,
    eDegenerateTopology   = 3020,
    eUninitialisedObject  = 3021
  };

  enum Relation
  {
    kUnknown              = 0,
    kOutside              = 1,
    kInside               = 2,
    kBoundary             = 3,
    kCoincident           = 4,
    kTangent              = 5,
    kIntersect            = 6
  };

  enum Element2dShape
  {
    kDefault              = 0,
    kAllPolygons          = 1,
    kAllQuadrilaterals    = 2,
    kAllTriangles         = 3
  };

  enum LoopType
  {
    kUnclassified         = 0,
    kExterior             = 1,
    kInterior             = 2,
    kWinding              = 3,
    kLoopUnclassified     = kUnclassified,
    kLoopExterior         = kExterior,
    kLoopInterior         = kInterior,
    kLoopWinding          = kWinding
  };

  enum ValidationLevel
  {
    kFullValidation  = 0,
    kNoValidation    = 1
  };

  enum ShellType
  {
    kShellUnclassified    = 0,
    kShellExterior        = 1,
    kShellInterior        = 2
  };
};

typedef OdBr::ErrorStatus     OdBrErrorStatus;
typedef OdBr::Relation        BrRelation;
typedef OdBr::Element2dShape  Element2dShape;
typedef OdBr::LoopType        BrLoopType;
typedef OdBr::ValidationLevel BrValidationLevel;
typedef OdBr::ShellType       BrShellType;


const OdBrErrorStatus odbrOK                        = OdBr::eOk;
const OdBrErrorStatus odbrNotImplementedYet         = OdBr::eNotImplementedYet;
const OdBrErrorStatus odbrUninitialisedObject       = OdBr::eUninitialisedObject;
const OdBrErrorStatus odbrUnrecoverableErrors       = OdBr::eInvalidObject;
const OdBrErrorStatus odbrUnsuitableTopology        = OdBr::eUnsuitableTopology;
const OdBrErrorStatus odbrDegenerateGeometry        = OdBr::eMissingGeometry;
const OdBrErrorStatus odbrInvalidInput              = OdBr::eInvalidInput;
const OdBrErrorStatus odbrWrongObjectType           = OdBr::eWrongObjectType;
const OdBrErrorStatus odbrDegenerateTopology        = OdBr::eDegenerateTopology;
const OdBrErrorStatus odbrMissingTopology           = OdBr::eDegenerateTopology;
const OdBrErrorStatus odbrMissingGeometry           = OdBr::eMissingGeometry;
const OdBrErrorStatus odbrWrongSubentityType        = OdBr::eWrongSubentityType;
const OdBrErrorStatus odbrInvalidObject             = OdBr::eNullObjectPointer;
const OdBrErrorStatus odbrBrepChanged               = OdBr::eBrepChanged;
const OdBrErrorStatus odbrOutOfMemory               = OdBr::eOutOfMemory;
const OdBrErrorStatus odbrNotApplicable             = OdBr::eNotApplicable;
const OdBrErrorStatus odbrUnsuitableGeometry        = OdBr::eAmbiguousOutput;


const BrLoopType odbrLoopUnclassified = OdBr::kUnclassified;
const BrLoopType odbrLoopExterior     = OdBr::kExterior;
const BrLoopType odbrLoopInterior     = OdBr::kInterior;
const BrLoopType odbrLoopWinding      = OdBr::kWinding;

const BrShellType odbrShellUnclassified       = OdBr::kShellUnclassified;
const BrShellType odbrShellExterior           = OdBr::kShellExterior;
const BrShellType odbrShellInterior           = OdBr::kShellInterior;

const BrValidationLevel odbrFullValidation         = OdBr::kFullValidation;
const BrValidationLevel odbrNoValidation           = OdBr::kNoValidation;

/** \details
  Represents the B-rep error status.
*/
#else
enum OdBrErrorStatus
{ 
  /** The operation is finished successfully. */
  odbrOK                     = ::eOk,
  /** The type of returned object is not supported as a B-rep. */
  odbrWrongObjectType        = eWrongObjectType,
  /** The OdBr* object is not initialized or is invalid. */
  odbrInvalidObject          = eUnrecoverableErrors,
  odbrUnsuitableTopology     = 0XBC5,                 
  /** Represents the partially or fully missing geometry. */
  odbrMissingGeometry        = eDegenerateGeometry,
  /** The input arguments point to an invalid object. */
  odbrInvalidInput           = eInvalidInput,
  /** The subentity does not map to the topology. */
  odbrDegenerateTopology     = 0XBCC,
  /** The OdBr* object is not initialized. */
  odbrUninitialisedObject    = 0xBCD,
  /** The memory for the object could not be allocated. */
  odbrOutOfMemory            = eOutOfMemory,
  /** The object has been modified since this OdBr* object was last set. */
  odbrBrepChanged            = 0xBC0,
  /** Returned if the function is not implemented yet. */
  odbrNotImplementedYet      = ::eNotImplementedYet,
  /** Returned when the subentity path does not point to an object. */
  odbrNullObjectId           = eNullObjectId,
  /** Represents the situation when the inherited function is not applicable to this subclass. */
  odbrNotApplicable          = eNotApplicable,
  /** The subentity type does not match the subclass. */
  odbrWrongSubentityType     = eWrongSubentityType,
  /** Returned when the subentity path does not point to a subentity. */
  odbrNullSubentityId        = eInvalidIndex,
  /** Returned when the function implementation is missing. */
  odbrNullObjectPointer      = eUnrecoverableErrors,
  /** The traverser list owner and list position do not point to the same object. */
  odbrObjectIdMismatch       = eWrongDatabase,
  /** Returned when the traverser list position cannot be set because the subentity is not connected to the list owner. */
  odbrTopologyMismatch       = eWrongDatabase,
  /** The geometry of OdGe object is unsuitable for this function. */
  odbrUnsuitableGeometry     = eAmbiguousOutput,
  /** The topology does not map to a subentity. */
  odbrMissingSubentity       = eNotInDatabase,
  /** The result is ambiguous. */
  odbrAmbiguousOutput        = eAmbiguousOutput,

  odbrUnrecoverableErrors    = eUnrecoverableErrors,
  odbrMissingTopology        = odbrDegenerateTopology,
  odbrWrongDatabase          = eWrongDatabase,
  odbrNotInDatabase          = eNotInDatabase,
  odbrDegenerateGeometry     = eDegenerateGeometry
};

/** \details
  Represents the type of a loop.
*/
enum BrLoopType{
  /** The loop type is ambiguous or cannot be determined at this time. */
  odbrLoopUnclassified = 0,
  /** The loop is on a peripheral boundary. */
  odbrLoopExterior     = 1,
  /** The loop represents a hole in the interior of a face. */
  odbrLoopInterior     = 2,
  /** The loop is winding on a conical surface. */
  odbrLoopWinding      = 3
};

/** \details
  Represents the shell type.
*/
enum BrShellType{ 
  /** The shell type cannot be determined at this time. */
  odbrShellUnclassified = 0,
  /** The shell is on a peripheral boundary of region or B-rep. */
  odbrShellExterior     = 1,
  /** The shell is empty in the interior of a region or B-rep. */
  odbrShellInterior     = 2
};

/** \details
  Represents the validation level.
*/
enum BrValidationLevel { 
  /** Full validation. */
  odbrFullValidation    = 0,
  /** No validation. */
  odbrNoValidation      = 1
};

/** \details
  Represents the element shape criteria.
*/
enum Element2dShape { 
  /** Default. */
  kDefault          = 0,
  /** All polygons. */
  kAllPolygons       = 1,
  /** All quadrilaterals. */
  kAllQuadrilaterals = 2,
  /** All triangles. */
  kAllTriangles      = 3
};
#endif
/** \details
  Represents bit flags for BrEntity.
*/
enum BrEntityFlags {
  /** No flags. */
  kNoFlags         = 0,
  /** If it is DoubleSide then not SingleSide and vice versa. */
  kDoubleSide      = 0x001,
  /** Visible should be set by default. kNoFlags is default/drawings version. */
  kVisible         = 0x002,
  /** Invisible. */
  kInvisible       = 0x004, 
  /** Highlight. */
  kHighlight       = 0x008,  
  /** It cannot be selected. */
  kSelectionIgnore = 0x010,
  /** Internal use only. */
  kBimRvEdgeSwapFaces = 0x01000000,
};

/** \details
  This class is a specialization of the OdError class for OdBr errors.  
  Corresponding C++ library: TD_Br
  <group OdBr_Classes>
*/
class ODBR_TOOLKIT_EXPORT OdBrException : public OdError
{
public:
  /** \details
    Constructor.
  
    \param errorStatus [in]  Error status.
  */
  OdBrException(OdBrErrorStatus errorStatus);
  
  /** \details
    Returns the error status associated with this Exception object.
  */
  OdBrErrorStatus getErrorStatus() const;
};

#define BR_THROW(n) throw OdBrException(n)

#define BR_ERR_RESULT  od_br_error_result
#define BR_TRY_I(def)  OdBrErrorStatus OD_ERR_RESULT = def; try {
#define BR_CATCH_I()   } catch(OdBrException& brerr){OD_ERR_RESULT = brerr.getErrorStatus();} catch(OdError& ) { OD_ERR_RESULT = odbrMissingGeometry; ODA_FAIL();} 

#define BR_TRY()       BR_TRY_I(odbrOK)
#define BR_CATCH()     BR_CATCH_I() return OD_ERR_RESULT;

#endif // ODBRENUMS_H
