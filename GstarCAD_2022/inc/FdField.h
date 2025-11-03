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


#ifndef _FdField_h_Included_
#define _FdField_h_Included_

#include "RxObject.h"
#include "RxDictionary.h"
#include "DbField.h"

class OdDbField;
class OdDbEvalVariant;
class OdFieldValue;
class OdFdFieldEngineImpl;
class OdFdFieldResult;
class OdDbDatabase;

#include "TD_PackPush.h"

/** Description:
  This class is an abstract base class that defines the field evaluator interface.
  Remarks: 
  Applications implement evaluators for fields by deriving from this class. 
  The evaluator object instantiated from this class is obtained from the field 
  evaluator loader using the evaluator ID stored in the field. An evaluator class 
  can be implemented for each type of field, or a single evaluator class can support 
  multiple types of fields.
  {group:Other_Classes}
*/
class TOOLKIT_EXPORT OdFdFieldEvaluator : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdFdFieldEvaluator);

  /** Description:
    Returns the evaluator IDs supported by this evaluator.
    Remarks:
    This function can return more than one evaluator ID if the evaluator 
    supports multiple IDs. If more than one ID is returned, the evaluator 
    IDs are separated by commas.
  */
  virtual const OdString evaluatorId() const = 0;
  /** Description:
    Returns the evaluator ID for the specified field code.
    Remarks:
    This version will be called to find an evaluator for a field code 
    that does not have an evaluator ID set. Implementations of this function 
    should examine the field code. If the field code is recognized by the evaluator 
    and can be handled by it, then this function should return the evaluator ID. 
    Arguments:
    pField (I) Input field for which to return an evaluator ID 
  */
  virtual const OdString evaluatorId(OdDbField* pField) const = 0;
  /** Description:
    This function is called by the
    field framework calls this method to initialize a new field.
    Remarks: 
    This method is called after setting a field code in the field and 
    before compile() is called. The evaluator can change the default 
    options that are set in the field when it is created. This method 
    will be called only once for a field. 
    Arguments:
    pField (I) Input field to initialize 
  */
  virtual OdResult initialize(OdDbField* pField) const = 0; 

//    The field framework calls this method to compile a field when the field code is changed.   
  
  /** Description:
    This function is called by the frame framework
    to compile a field when the field code is changed.
    Remarks:
    The evaluator can do any parsing of the field code here and store the parsed data in the 
    field. This method will be called only when the field code is changed, unlike evaluate(), 
    which is called whenever the field needs to be evaluated.
    Arguments:
    pField (I) Input field to compile 
    pDb (I) Input database pointer 
    pResult (I) Input field result object to set the compilation status 
  */
  virtual OdResult compile(OdDbField* pField, 
    OdDbDatabase* pDb,
    OdFdFieldResult* pResult) const = 0;

//  The field framework calls this method to evaluate a field whenever the field needs 
//    to be evaluated.

  /** Description:
    This function is called by the field framework when the field needs to be evaluated.
    Remarks:
    A field will be evaluated only when the evaluation option set in 
    the field matches the context in which the field evaluation is invoked. For example,
    if a field option is set to evaluate only manually, then it will be evaluated only 
    when the user updates the specific field or all fields in the drawing manually.

    The evaluator should evaluate the field and set the evaluated value using 
    OdFdFieldResult::setFieldValue() and the error status using OdFdFieldResult::setEvaluationStatus() 
    in the passed result object, which in turn will set them in the field object.

    The passed database pointer may be null if the field is not database resident and a 
    database could not be obtained in the current context. If the field evaluation requires 
    a database, then this method can set the evaluation error status in the field result object 
    and return an error. 

    If the evaluation fails for any reason, the previously cached result in the field object can 
    be left intact and used as the field value. Alternatively, the cached result can be deleted 
    and substituted with an error string (for example, "#ERR"), which will be displayed as field 
    value.

    Arguments:
    pField (I) Input field to evaluate 
    nContext (I) Input context in which the field is evaluated; this context flag is passed to the evaluator and can be one of the predefined OdDbField::EvalContext enum flags or a user-defined context flag 
    pDb (I) Input database pointer, which can be null if a database could not be obtained in the current context 
    pResult (I) Input field result object to set the evaluation result and status 
  */
  virtual OdResult evaluate(OdDbField* pField, 
    int nContext, 
    OdDbDatabase* pDb, 
    OdFdFieldResult* pResult) const = 0;

//      The field framework calls this method when a field is queried 
//      to get the evaluated field value as a string. The evaluator can 

  /** Description:
      This function is called by the field framework
      when a field is queried to get the evaluated field value as a string. 
      Remarks:
      The evaluator can 
      implement this method to support custom formatting of field values. 
      If the evaluator does not implement this method, the standard data types will 
      be formatted using default formats.

      Arguments:
      pField (I) Field whose value is to be formatted 
      pszValue (O) Pointer to the string that is the field value formatted as a string
  */
  virtual OdResult format(OdDbField* pField, OdString& pszValue) const = 0;
};

typedef OdSmartPtr<OdFdFieldEvaluator> OdFdFieldEvaluatorPtr;

/** Description:
  This class is used to load the evaluators required for evaluating fields. 
  Remarks:
  This class acts as the interface between the field framework and the applications 
  that implement evaluators. An application that implements evaluators should derive 
  from this class and register an object of this class with the field engine when 
  the application is loaded. The registered loader is used by the engine to obtain 
  the evaluator object. Only one loader object is required for an application and 
  it can support multiple evaluators. The loader objects are maintained globally and 
  are used by all open documents.
  {group:Other_Classes}
*/
class TOOLKIT_EXPORT OdFdFieldEvaluatorLoader : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdFdFieldEvaluatorLoader);

  /** Description:
    The field engine calls this method to get the evaluator using the evaluator ID 
    and uses the evaluator to evaluate the field. 
    Arguments:
    pszEvalId (I) Input evaluator ID for which the evaluator is required 
  */
  virtual OdFdFieldEvaluator* getEvaluator(
    const OdString& pszEvalId) = 0;

  /** Description:
    Finds an evaluator for a field that does not have an evaluator ID. 
    Arguments:
    pField (I) Input field for which to find an evaluator 
    pszEvalId (O) Output pointer to receive the evaluator ID 
  */
  virtual OdFdFieldEvaluator * findEvaluator(
    OdDbField* pField, 
    OdString& pszEvalId) = 0;
};

/** Description:
  This class is used to get notifications when fields in a database are evaluated.
  {group:Other_Classes}
*/
class TOOLKIT_EXPORT OdFdFieldReactor : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdFdFieldReactor);

  /** Description
    Notification function called before one or more fields in a database are evaluated.
    Arguments:
    nContext (I) Input evaluation context 
    pDb (I) Input pointer to database in which the fields are evaluated 
  */
  virtual OdResult beginEvaluateFields(
    int nContext, 
    OdDbDatabase* pDb);
  
  /** Description
    Notification function called after one or more fields in a database are evaluated.
    Arguments:
    nContext (I) Input evaluation context 
    pDb (I) Input pointer to database in which the fields are evaluated 
  */
  virtual OdResult endEvaluateFields(
    int nContext, 
    OdDbDatabase* pDb);
};

typedef OdArray<OdFdFieldReactor*> FieldReactors;

/** Description:
  This class manages the evaluation of fields. 
  Note:
  The field engine is a global one-per-session object. 

  The field evaluators should register their loader with 
  the engine during application startup
  {group:Other_Classes}
*/
class TOOLKIT_EXPORT OdFdFieldEngine : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdFdFieldEngine);
  virtual ~OdFdFieldEngine(){}
  /** Description:
    Registers the evaluator loader with the engine. 
    Remarks:The engine searches the registered
    evaluator loaders to find the appropriate evaluator for evaluating fields. Field 
    evaluators should register the evaluator loader with the field engine during application
    startup.
    Arguments:
    pLoader (I) Input evaluator loader to register 
  */
  virtual void registerEvaluatorLoader(OdFdFieldEvaluatorLoader* pLoader) = 0;

  /** Description:
    Unregisters the evaluator loader from the engine. 
    Remarks:
    Field evaluator modules 
    should unregister the evaluator loader when the module is unloaded, 
    before deleting the loader object.
    Arguments:
    pLoader (I) Input evaluator loader to unregister 
  */
  virtual void unregisterEvaluatorLoader(OdFdFieldEvaluatorLoader* pLoader) = 0;

  /** Description:
    Returns the number of registered field evaluator loaders.
  */
  virtual int evaluatorLoaderCount() const = 0;

  /** Description:
    Returns the field evaluator loader at the specified index.
    Remarks:
    This function can be used with evaluatorLoaderCount() to 
    enumerate the evaluator loaders.
    Arguments:
    inputIndex (I) Input index for which to get the field evaluator loader; the index is zero based and should be less than the number of registered evaluator loaders.
  */
  virtual OdFdFieldEvaluatorLoader * getEvaluatorLoader(int inputIndex) = 0;

  /** Description:
    Returns the field evaluator for the specified evaluator ID.
    Remarks: 
    Returns null if a field evaluator could not be found for the evaluator ID.
    Arguments:
    pszEvalId (I) Input evaluator ID for which to find the field evaluator 
  */
  virtual OdFdFieldEvaluator * getEvaluator (
    const OdString& pszEvalId) = 0;

  /** Description:
    Returns an an evaluator for the specified field from the set of registered evaluators
    if the field does not have an evaluator ID. 
    Arguments:
    pField (I) Input field for which to find an evaluator 
    pszEvalId (O) Output pointer to receive the evaluator ID 
    Remarks:
    Returns the field evaluator for the specified field, or 
    null if a field evaluator could not be found.

  */
  virtual OdFdFieldEvaluator * findEvaluator(
    OdDbField* pField,
    OdString& pszEvalId) = 0;

  /** Description:
    Adds the field reactor to the field framework.
    Arguments:
    pReactor (I) Input pointer to the reactor to be added 
  */
  virtual void addFieldReactor(OdFdFieldReactor* pReactor) = 0;
  
  /** Description:
    Removes the field reactor from the field framework.
    pReactor (I) Input pointer to field reactor to remove 
  */
  virtual void removeFieldReactor(OdFdFieldReactor* pReactor) = 0;
};

typedef OdSmartPtr<OdFdFieldEngine> OdFdFieldEnginePtr;
#define ODFD_FIELD_ENGINE             OD_T("FieldEngine")
/** Description:
  Returns the pointer to the field engine. There is only one field engine object per session.
*/
TOOLKIT_EXPORT OdFdFieldEnginePtr oddbGetFieldEngine();

/** Description:
  This class is used by the evaluators to set the evaluation status and 
  evaluation result in the field. 
  Remarks:
  This object is passed to the evaluators 
  during compilation and evaluation. This object cannot be instantiated.
  {group:Other_Classes}
*/
class TOOLKIT_EXPORT OdFdFieldResult : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdFdFieldResult);
  OdFdFieldResult();
  
  /** Description:
    Sets the evaluation result in the field.
    Arguments:
    pValue (I) Input evaluation to set in the field.
    Remarks:
    If pValue is null,the cached evaluation is deleted. 
  */
  virtual void setFieldValue(const OdFieldValue* pValue) = 0;
  
  /** Description:
    Sets the evaluation status in the field.
    Arguments:
    errorStatus (I) Error status
    errorCode (I) Extended error code or zero for success
    errorMessage (I) Error message
  */
  virtual void setEvaluationStatus(OdDbField::EvalStatus errorStatus, int errorCode = 0, const OdString& errorMessage = OdString()) = 0;
};

 /** Description:
    Evaluates fields in database.
    Arguments:
    pDb (I) Pointer to the *database* for which fields are to be evaluated
    nContext (I) Input context in which the field is evaluated, which can be a predefined *OdDbField::EvalContext* enum flag or a user-defined context flag; this context flag is passed to the evaluator
    objIds (I) Input array of object IDs of objects, whose fields are to be evaluated. If this is not null only, fields will be evaluated only for these objects.
    pFieldsToEvaluate (I) Input array of object IDs of fields to be evaluated. If this is not null only these fields in the specified objects will be evaluated. If this is null all the fields in the specified objects will be evaluated.
    pszEvaluatorId (I) Input evaluator ID. If this is not null only the fields matching this evaluator ID will be evaluated. If this is null all the fields in the specified objects will be evaluated. 
    nEvalFlag (I) Input one or more OdFd::EvalFields option flags
    pNumFound (O) Output pointer to store the number of fields found; can be null if this information is not required 
    pNumEvaluated (O) Output pointer to store the number of fields evaluated; can be null if this information is not required 
*/
TOOLKIT_EXPORT OdResult oddbEvaluateFields( 
  OdDbDatabase* pDb,
  int nContext,
  const OdDbObjectIdArray* objIds = 0, 
  const OdDbObjectIdArray* pFieldsToEvaluate = 0,
  const OdString& pszEvaluatorId = OdString(),
  OdFd::EvalFields nEvalFlag = OdFd::kEvalRecursive,
  int* pNumFound = 0,
  int* pNumEvaluated = 0);

#include "TD_PackPop.h"

#endif //_FdField_h_Included_
