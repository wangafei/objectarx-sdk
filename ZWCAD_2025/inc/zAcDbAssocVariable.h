
#pragma once
#include "zAcDbAssocValueProviderPE.h"
#include "zAcDbAssocAction.h"
#pragma pack (push, 8)

ZCDBCORE2D_PORT ZcString& dummyString();

class ZCDBCORE2D_PORT ZcDbAssocVariable : public ZcDbAssocAction
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocVariable);

    explicit ZcDbAssocVariable(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    const ZcString& name() const;

    const ZcString& expression() const;

    const ZcString& expression(bool convertSymbolNamesFromCanonicalForm) const;

    const ZcDbEvalVariant& value() const;

    const ZcString& description() const;

    Zcad::ErrorStatus setName(const ZcString& newName, bool updateReferencingExpressions);

    bool isAnonymous() const;

    ZcDbObjectId findObjectByName(const ZcString&  objectName,
                                  const ZcRxClass* pObjectClass) const;

    Zcad::ErrorStatus validateNameAndExpression(const ZcString& nameToValidate,
                                                const ZcString& expressionToValidate,
                                                ZcString&       errorMessage) const;

    Zcad::ErrorStatus setExpression(const ZcString& newExpression,
                                    const ZcString& evaluatorId,
                                    bool checkForCyclicalDependencies,
                                    bool updateDependenciesOnReferencedSymbols,
                                    ZcString& errorMessage = dummyString(),
                                    bool silentMode = false);

    const ZcString& evaluatorId() const;

    Zcad::ErrorStatus setEvaluatorId(const ZcString& evalId);

    Zcad::ErrorStatus setValue(const ZcDbEvalVariant& newValue);

    Zcad::ErrorStatus setDescription(const ZcString& newDescription);

    bool     isMergeable          () const;
    bool     mustMerge            () const;
    ZcString mergeableVariableName() const;
    void setIsMergeable(bool isMerg, bool mustMerg = false, const ZcString& mergeableVariableName = ZcString());

    Zcad::ErrorStatus evaluateExpression(ZcDbEvalVariant& evaluatedExpressionValue,
                                         ZcString&        errorMessage = dummyString()) const;

    Zcad::ErrorStatus evaluateExpression(ZcDbObjectIdArray&        objectIds,
                                         ZcArray<ZcDbEvalVariant>& objectValues,
                                         ZcDbEvalVariant&          evaluatedExpressionValue,
                                         ZcString&                 errorMessage = dummyString()) const;

    static Zcad::ErrorStatus evaluateExpression(const ZcString&     expression,
                                                const ZcString&     evaluatorId,
                                                const ZcDbObjectId& networkId,
                                                ZcDbEvalVariant&    evaluatedExpressionValue,
                                                ZcString&           assignedToSymbolName,
                                                ZcString&           errorMessage = dummyString());

    static void addGlobalCallback(class ZcDbAssocVariableCallback* pCallback);

    static void removeGlobalCallback(class ZcDbAssocVariableCallback* pCallback);

    static class ZcDbAssocVariableCallback* globalCallback();

};

class ZCDBCORE2D_PORT ZcDbAssocVariableCallback
{
public:
    ZcDbAssocVariableCallback() {}
    virtual ~ZcDbAssocVariableCallback() {}

    virtual bool canBeErased(const ZcDbAssocVariable* pVariable) = 0;

    virtual Zcad::ErrorStatus validateNameAndExpression(const ZcDbAssocVariable* pVariable,
                                                        const ZcString&          nameToValidate,
                                                        const ZcString&          expressionToValidate,
                                                        ZcString&                errorMessage) = 0;
};

#pragma pack (pop)

ZCDBCORE2D_PORT void stringDefaultArgumentTest(ZcString& str = dummyString());
