/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocValueProviderPE.h"
#include "GcDbAssocAction.h"
#pragma pack (push, 8)

DBCONSTRAINTS_PORT GcString& dummyString();

class DBCONSTRAINTS_PORT GcDbAssocVariable : public GcDbAssocAction
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocVariable);

  explicit GcDbAssocVariable(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  const GcString& name() const;

  const GcString& expression() const;
  const GcString& expression(bool convertSymbolNamesFromCanonicalForm) const;

  const GcDbEvalVariant& value() const;
  const GcString& description() const;
  Gcad::ErrorStatus setName(const GcString& newName, bool updateReferencingExpressions);
  bool isAnonymous() const;
  GcDbObjectId findObjectByName(const GcString&  objectName,
    const GcRxClass* pObjectClass) const;
  Gcad::ErrorStatus validateNameAndExpression(const GcString& nameToValidate,
    const GcString& expressionToValidate,
    GcString&       errorMessage) const;
  Gcad::ErrorStatus setExpression(const GcString& newExpression,
    const GcString& evaluatorId,
    bool checkForCyclicalDependencies,
    bool updateDependenciesOnReferencedSymbols,
    GcString& errorMessage = dummyString(),
    bool silentMode = false);
  const GcString& evaluatorId() const;
  Gcad::ErrorStatus setEvaluatorId(const GcString& evalId);
  Gcad::ErrorStatus setValue(const GcDbEvalVariant& newValue);
  Gcad::ErrorStatus setDescription(const GcString& newDescription);
  bool     isMergeable() const;
  bool     mustMerge() const;
  GcString mergeableVariableName() const;
  void setIsMergeable(bool isMerg, bool mustMerg = false, const GcString& mergeableVariableName = GcString());

  Gcad::ErrorStatus evaluateExpression(GcDbEvalVariant& evaluatedExpressionValue,
    GcString&        errorMessage = dummyString()) const;
  Gcad::ErrorStatus evaluateExpression(GcDbObjectIdArray&        objectIds,
    GcArray<GcDbEvalVariant>& objectValues,
    GcDbEvalVariant&          evaluatedExpressionValue,
    GcString&                 errorMessage = dummyString()) const;
  static Gcad::ErrorStatus evaluateExpression(const GcString&     expression,
    const GcString&     evaluatorId,
    const GcDbObjectId& networkId,
    GcDbEvalVariant&    evaluatedExpressionValue,
    GcString&           assignedToSymbolName,
    GcString&           errorMessage = dummyString());

  static void addGlobalCallback(class GcDbAssocVariableCallback* pCallback);
  static void removeGlobalCallback(class GcDbAssocVariableCallback* pCallback);
  static class GcDbAssocVariableCallback* globalCallback();

};

class DBCONSTRAINTS_PORT GcDbAssocVariableCallback
{
public:
  GcDbAssocVariableCallback() {}
  virtual ~GcDbAssocVariableCallback() {}

  virtual bool canBeErased(const GcDbAssocVariable* pVariable) = 0;
  virtual Gcad::ErrorStatus validateNameAndExpression(const GcDbAssocVariable* pVariable,
    const GcString&          nameToValidate,
    const GcString&          expressionToValidate,
    GcString&                errorMessage) = 0;
};

#pragma pack (pop)

DBCONSTRAINTS_PORT void stringDefaultArgumentTest(GcString& str = dummyString());