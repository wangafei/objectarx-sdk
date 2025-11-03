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


#ifndef OD_DBFIELD_H
#define OD_DBFIELD_H

#include "TD_PackPush.h"

#include "DbObject.h"
#include "DbFieldValue.h"
#include "OdValue.h"

class OdDbField;
typedef OdSmartPtr<OdDbField> OdDbFieldPtr;

/** Description:
    This template class is a specialization of the OdArray class for OdDbField object pointers.
*/
typedef OdArray<OdDbField*> OdDbFieldArray;


/** Description:
  Library: TD_Db
  {group:Structs}
*/      
typedef struct OdFd
{
  enum EvalFields
  {
    kEvalRecursive = 1
  };
  
  // Options for function acdbConvertFieldsToText()
  enum ConvertFieldToText
  {
    kConvertFieldToTextNone         = 0,
    kEvaluateBeforeConversion       = (0x1 << 0),
    kExcludeEvaluatorsInList        = (0x1 << 1),
    kIgnoreEvaluatorVersion         = (0x1 << 2),
  };
} OdFd;

typedef struct OdHyperlink
{
    OdString                        msUrl;
    OdString                        msSubLocation;
    OdString                        msDescription;
    long                            mlFlag;
} OdHyperlink;

class OdDbField;

//Gcad(Add)
class OdDbHyperlink;
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbField object pointers.
*/
typedef OdSmartPtr<OdDbField> OdDbFieldPtr;

//*************************************************************************
// OdDbField
//*************************************************************************

/** Description:
    This class represents Field objects in an OdDbDatabase instance.
    
    Remarks:
    Field objects store both the Field expression and their evaluated values.
    
    Fields can be evaluated by an evaluator to any one of the following data types: Long,         
    Double, String, Date, Point, 3dPoint, ObjectId, Buffer, and Resbuf.       
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbField : public OdDbObject
{
public:
  enum State
  {
    kInitialized        = 0x01,       // Field was initialized by the evaluator.
    kCompiled           = 0x02,       // Field was compiled.
    kModified           = 0x04,       // Field was modified, but not evaluated.
    kEvaluated          = 0x08,       // Field was evaluated.
    kHasCache           = 0x10,       // Field has evaluated cache.
    kHasFormattedString = 0x20        // Internal use only. 
  };
  
  enum EvalOption
  {
    kDisable            = 0,          // Do not evaluate field.
    kOnOpen             = 0x01,       // Evaluate field when a drawing is opened.
    kOnSave             = 0x02,       // Evaluate field when a drawing is saved.
    kOnPlot             = 0x04,       // Evaluate field when a drawing is printed.
    kOnEtransmit        = 0x08,       // Evaluate field when a drawing is etransmitted.
    kOnRegen            = 0x10,       // Evaluate field when a drawing is regenerated.
    kOnDemand           = 0x20,       // Evaluate field when demanded.
    kAutomatic          = (kOnOpen | kOnSave | kOnPlot |  kOnEtransmit | kOnRegen | kOnDemand) // Evaluate automatically.
  };
  
  enum EvalContext
  {
    kOpen               = 0x01,       // Field is being evaluated when a drawing is opened.
    kSave               = 0x02,       // Field is being evaluated when a drawing is saved.
    kPlot               = 0x04,       // Field is being evaluated when a drawing is printed.
    kEtransmit          = 0x08,       // Field is being evaluated when a drawing is etransmitted.
    kRegen              = 0x10,       // Field is being evaluated when a drawing is regenerated.
    kDemand             = 0x20,       // Field is being evaluated when demanded.
    kPreview            = 0x40,       // Field is being evaluated when a drawing is previewed.
    kPlotPreview        = 0x80        // Field is being evaluated during plot preview
  };
  
  enum EvalStatus
  {
    kNotYetEvaluated    = 0x01,       // Evaluation not performed.
    kSuccess            = 0x02,       // Evaluation complete: Successful.
    kEvaluatorNotFound  = 0x04,       // Evaluator for the field not found.
    kSyntaxError        = 0x08,       // Evaluation complete: Syntax error in field code.
    kInvalidCode        = 0x10,       // Evaluation complete: Invalid field code.
    kInvalidContext     = 0x20,       // Evaluation complete: Invalid context to evaluate field.
    kOtherError         = 0x40        // Evaluation complete: Other evaluation error.
  };
  
  enum FieldCodeFlag
  {
    kRawCode            = 0x00,       // Returns the raw main field code. Ignored by setFieldCode().
    kFieldCode          = 0x01,       // Returns the raw field code. Ignored by setFieldCode().
    kEvaluatedText      = 0x02,       // Returns the evaluated text. Ignored by setFieldCode().
    kEvaluatedChildren  = 0x04,       // Returns the field code with evaluated text for child fields. Ignored by setFieldCode().
    kObjectReference    = 0x08,       // Returns embedded text as references to child fields. Ignored by setFieldCode().
    kAddMarkers         = 0x10,       // Returns embedded text as field codes enclosed in field markers. Ignored by setFieldCode().
    kEscapeBackslash    = 0x20,       // Converts single backslashes to double backslashes. Ignored by setFieldCode().
    kStripOptions       = 0x40,       // Strips the standard options from the field code. Ignored by setFieldCode().
    kPreserveFields     = 0x80,       // Internal use only. Ignored by getFieldCode().
    kTextField          = 0x100,      // Treats the field as text with embedded fields. Ignored by getFieldCode().
    kPreserveOptions    = 0x200,      // Ignored by getFieldCode(). For internal use.
    kDetachChildren     = 0x400,      // Ignored by getFieldCode(). For internal use.
    kChildObjectReference = 0x800,    // Get child fields as object references. For internal use. 
    kForExpression      = 0x1000      // Get the value in a format used in arithmatic expressions (e.g. vector child values are put in square brackets). For internal use. Ignored by setFieldCode().
  };
  
  enum FilingOption
  {
    kSkipFilingResult   = 0x01        // Don't file field value.
  };
  
public:
  ODDB_DECLARE_MEMBERS(OdDbField);
  
  OdDbField();

  //Gcad(Add)
  OdDbField(const OdChar* pszFieldCode, bool bTextField = false);

  //Gcad(Add)
  ~OdDbField(void);
  
  /** Description:
    Sets this Field object as a property of the specified object, and
    adds it to the database.
    
    Arguments:
    pOwner (I) Pointer to the Owner object.
    propertyName (I) Name of the property.
    
    Remarks:
    The specified object must be database resident.
  */
  OdResult setInObject(
    OdDbObject* pOwner, 
    const OdChar* pszPropName);
  
  /** Description:
    Adds this Field object and its Child objects to the specified database.
    
    Arguments:
    pDb (I) Pointer to the database in which to post.
  */
  OdResult postInDatabase(
    OdDbDatabase* pDb);
  
  /** Description:
    Returns the state of this Field object.
    
    Remarks:
    state() returns a combination of zero or more of the following: 
    
    @table
    Name                   Value    Description
    kInitialized           0x01     Field was initialized by the evaluator.
    kCompiled              0x02     Field was compiled.
    kModified              0x04     Field code was modified, but not evaluated.
    kEvaluated             0x08     Field was evaluated.
    kHasCache              0x10     Field has evaluated cache.
    kHasFormattedString    0x20     Internal use only. 
  */
  OdDbField::State state() const;
  
  /** Description:
    Returns the evaluation status of this Field object.
    
    Remarks:
    evaluationStatus() returns a combination of one or more of the following: 
    
    @table
    Name                   Value    Description
    kNotYetEvaluated       0x01     Evaluation not complete.
    kSuccess               0x02     Evaluation complete: Successful.
    kEvaluatorNotFound     0x04     Evaluator for the field not found.
    kSyntaxError           0x08     Evaluation complete: Field code syntax error.
    kInvalidCode           0x10     Evaluation complete: Invalid field code.
    kInvalidContext        0x20     Evaluation complete: Invalid context to evaluate field.
    kOtherError            0x40     Evaluation complete: Other evaluation error.
  */
  //Gcad(Modify)
  OdDbField::EvalStatus evaluationStatus(int* pnErrCode = NULL, OdChar** pszErrMsg = NULL) const; 
                                         // OdUInt32* errCode = 0, 
                                         // OdString* errMsg = 0) const;

  /** Description:
    Returns the evaluation option of this Field object.
    
    Remarks:
    evaluationOption() returns a combination of one or more of the following: 
    
    @table
    Name                   Value    Description
    kDisable               0x00     Do not evaluate field.
    kOnOpen                0x01     Evaluate field when a drawing is opened.
    kOnSave                0x02     Evaluate field when a drawing is saveed.
    kOnPlot                0x04     Evaluate field when a drawing is printed.
    kOnEtransmit           0x08     Evaluate field when a drawing is etransmitted.
    kOnRegen               0x10     Evaluate field when a drawing is regenerated.
    kOnDemand              0x20     Evaluate field when demanded.
    kAutomatic             0x3F     Evaluate field automatically.
  */
  OdDbField::EvalOption evaluationOption() const;
  
  /** Description:
    Sets the evaluation option for this Field object.
    
    Arguments:
    evaluationOption (I) Evaluation option.
    
    Remarks:
    evaluationStatus must be  a combination of one or more of the following: 
    
    @table
    Name                   Value    Description
    kDisable               0        Do not evaluate field.
    kOnOpen                0x01     Evaluate field when a drawing is opened.
    kOnSave                0x02     Evaluate field when a drawing is saved.
    kOnPlot                0x04     Evaluate field when a drawing is printed.
    kOnEtransmit           0x08     Evaluate field when a drawing is etransmitted.
    kOnRegen               0x10     Evaluate field when a drawing is regenerated.
    kOnDemand              0x20     Evaluate field when demanded.
    kAutomatic             0x3F     Evaluate field automatically.
  */
  OdResult setEvaluationOption(
    OdDbField::EvalOption evaluationOption);
    
  /** Description:
    Returns the filing option of this Field object.
    
    Remarks:
    filingOption() returns zero or more of the following: 
    
    @table
    Name                   Value    Description
    kSkipFilingResult      0x01     Do not file field value.
  */
  OdDbField::FilingOption filingOption() const;
  
  /** Description:
    Sets the filing option for this Field object.
    
    Remarks:
    filingOption must be zero or more of the following: 
    
    @table
    Name                   Value    Description
    kSkipFilingResult      0x01     Do not file field value.
  */
  OdResult setFilingOption(
    OdDbField::FilingOption filingOption);
  
  /** Description:
    Returns the ID of the evaluator for this Field object.
    
    Remarks:
    Returns an empty string if no evaluator has been set for this Field object, or if
    the evaluator cannot be found.
  */
  //Gcad(Modify)
  const OdChar* evaluatorId() const;

  /** Description:
    Sets the ID of the evaluator for this Field object.

    Arguments:
    evaluatorId (I) Evaluator ID.
  */
  OdResult setEvaluatorId(
    const OdChar* pszEvaluatorId);
  
  /** Description:
    Returns true if and only if this Field object is text with child fields.
  */
  bool isTextField() const;

  //Gcad(Add)
  OdResult convertToTextField (void);

  // OdString getFieldCode     (OdDbField::FieldCodeFlag nFlag, OdArray<OdDbField*>* pChildFields = 0, 
  //                           OdDb::OpenMode mode = OdDb::kForRead) const;
  
  /** Description:
    Returns the field code of this Field object in the specified form..
    
    Arguments:
    flags (I) Field code *flags*.
    
    Remarks:
    flags() returns a combination of one or more of the following:
    
    @table
    Name                   Value    Description
    kFieldCode             0x01     Returns the raw field code. 
    kEvaluatedText         0x02     Returns the evaluated text.
    kEvaluatedChildren     0x04     Returns the field code with evaluated text for child fields.
    kObjectReference       0x08     Returns the field code as an object reference.
    kAddMarkers            0x10     Includes markers around field codes.
    kEscapeBackslash       0x20     Converts single backslashes to double backslashes.
    kStripOptions          0x40     Strips the standard options from the field code.
    kPreserveFields        0x80     Internal use only. Ignored.
    kTextField             0x100    Treats the field as text with embedded fields. Ignored.
  */
  //Gcad(Modify)
  const OdChar* getFieldCode(
    OdDbField::FieldCodeFlag flags,
    OdArray<OdDbField*>* pChildFields = NULL,
    OdDb::OpenMode mode = OdDb::kForRead) const;
  
  /**Gcad(Add)
    pszFieldCode Output reference to receive the pointer to string that is the field code; 
    this pointer is a dynamically allocated copy and needs to be freed by the calling application 
  */
  OdResult getFieldCode(
    OdChar*& pszFieldCode, 
    OdDbField::FieldCodeFlag flags,
    OdArray<OdDbField*>* pChildFields = NULL,
    OdDb::OpenMode mode = OdDb::kForRead) const;

  /** Description:
    Sets the field code of this Field object in the specified form.
    
    Arguments:
    fieldCode (I) Field code.
    flags (I) Field code *flags*.
    pChildFields (I) Pointer to an array of child fields.
    
    Remarks:
    Child fields are the embedded fields of text fields, and 
    nested fields of non-text fields.
    
    flags must be a combination of one or more of the following:
    
    @table
    Name                   Value    Description
    kFieldCode             0x01     Returns the raw field code. Ignored.
    kEvaluatedText         0x02     Returns the evaluated text. Ignored. 
    kEvaluatedChildren     0x04     Returns the field code with evaluated text for child fields. Ignored.
    kObjectReference       0x08     Returns the field code as an object reference. Ignored.
    kAddMarkers            0x10     Includes markers around field codes. Ignored.
    kEscapeBackslash       0x20     Converts single backslashes to double backslashes. Ignored.
    kStripOptions          0x40     Strips the standard options from the field code. Ignored.
    kPreserveFields        0x80     Internal use only.
    kTextField             0x100    Treats the field as text with embedded fields.
  */
  OdResult setFieldCode(
    const OdChar* fieldCode,
    OdDbField::FieldCodeFlag flags = (OdDbField::FieldCodeFlag) 0,
    OdDbFieldArray* pChildFields = 0);
  
  /** Description:
    Returns the number of child fields in this Field object.
  */
  int  childCount() const;
  
  /** Description:
    Returns the specified child field in this Field object, and opens it in the specified mode.
    
    Arguments:
    childIndex (I) Child index.
    openMode (I)  Mode to apply to the child field.
  */
  OdDbFieldPtr getChild(
    int childIndex, 
    OdDb::OpenMode openMode);

  //GreatAdd
  OdResult getChild(int iIndex, 
    OdDbField*& pField, 
    OdDb::OpenMode mode);

  /** Description:
    Returns the output format for this Field object.
  */
  //Gcad(modify)
  const OdChar* getFormat() const;

  //Gcad(Add)
  OdResult getFormat (OdChar*& pszFormat) const;

  /** Description:
    Sets the output format for this Field object.
    
    Arguments:
    format (I) Output format.
    
    Note:
    Returns eOk if successful, or an appropriate error code if not.
  */
  OdResult setFormat(
    const OdChar* format);
          

  /** Description:
    Returns the evaluated Field object. 

    Remarks:
    After creating a field object and setting the field code, 
    call this method to evaluate the field.
    If pDb is null, the field's database will be used if the field is a database resident. 
    If it is null and the field is not a database resident, evaluation will fail if the 
    field requires a database.

    Arguments:
    nContext (I) Context in which the field is evaluated; the context flag can be one of the 
    predefined OdDbField::EvalContext enum flags or a user-defined context flag.
    pDb (I) Database to be used for the evaluation; can be null.
    pNumFound (O) Pointer to receive the number of fields evaluated; can be null if not required.  
    pNumEvaluated (O) Pointer to receive the number of fields evaluated; can be null if this information is not required. 
  */
  OdResult evaluate(
    int nContext, 
    OdDbDatabase* pDb = 0, 
    int* pNumFound = 0, 
    int* pNumEvaluated = 0);
  
  
  /** Description:
    Returns the data type of this Field object in the specified form.
    
    Remarks:
    Returns kUnknown if the field has yet to be evaluated.

    dataType() returns one of the following:
    
    @table
    Name                            Value
    OdFieldValue::kUnknown          0
    OdFieldValue::kLong             0x01
    OdFieldValue::kDouble           0x02
    OdFieldValue::kString           0x04
    OdFieldValue::kDate             0x08
    OdFieldValue::kPoint            0x10
    OdFieldValue::k3dPoint          0x20
    OdFieldValue::kObjectId         0x40
    OdFieldValue::kBuffer           0x80
    OdFieldValue::kResbuf           0x100
  */
  OdValue::DataType dataType() const;

  /** Description:
    Returns the field evaluation string using the output format for this Field object.
    
    Arguments:
    pValue (I) Receives a SmartPointer to the evaluation string.
    
    Remarks:
    If returning an OdString, returns an empty string if not successful.
    If returning an OdResult, returns eOk if successful, or returns an appropriate error code if unsuccessful.

    Note:
    The string pointed to by pValue must be freed by the caller.
  */      
  //Gcad(Modify)
  const OdChar* getValue() const;

  //Gcad(Add)
  OdResult getValue (OdChar*& pszValue) const;
  //Gcad(Add)
  OdResult getValue (OdValue& value) const;
  //Gcad(Add)
  OdResult getValue (OdFieldValue& value) const;

  bool  hasHyperlink() const;

  //Gcad(Modify)
  OdResult getHyperlink(OdString& psName,
                        OdString& psDescription, 
                        OdString& psSubLocation,
                        OdString& psDisplayString,
                        long* pFlag) const;

  //Gcad(Add)
  OdResult getHyperlink(OdDbHyperlink& hlink) const;
  //Gcad(Add)
  OdResult getHyperlink(OdChar** pszName,
                       OdChar** pszDescription, 
                       OdChar** pszSubLocation,
                       OdChar** pszDisplayString,
                       long* pFlag) const;

  
  OdResult setHyperlink(const OdChar* psName, 
                        const OdChar* psDescription,
                        const OdChar* psSubLocation = NULL);

  //Gcad(Add)
  OdResult setHyperlink(const OdDbHyperlink& hlink);

  //Gcad(Add):
  OdResult setHyperlink(const OdChar* psName,
                        const OdChar* psDescription,
                        const OdChar* psSubLocation,
                        long lFlag);

  OdResult removeHyperlink();
  
  /** Description:
    Returns the data for the specified key of this Field object.
    
    Arguments:
    key (I) Key.
  */
  OdFieldValue getData(
    const OdString& key) const;
  OdResult getData(
    const OdChar* pszKey, 
    OdValue* pData) const;
  
  /** Description:
    Sets the data for the specified key of this Field object.
    
    Arguments:
    key (I) Key.
    pData (I) Pointer to the object containing the data. 
  */
  OdResult setData(
    const OdString& key, 
    const OdFieldValue& pData);

  //Gcad(Add)
  OdResult setData(const OdChar* key,const OdValue* pData);
  OdResult setData(const OdChar* key,const OdValue* pData,bool bRecursive);

public:
  // Base class overrides

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;
  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;
  
  //Gcad(Modify):returns:void->OdResult
  virtual OdResult subClose();
};

#define TEXT_FIELD_NAME OD_T("TEXT")

#include "TD_PackPop.h"
#endif // OD_DBFIELD_H
