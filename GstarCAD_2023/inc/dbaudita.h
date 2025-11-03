/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef DB_DBAUDITA_H
#define DB_DBAUDITA_H 1

#include "GdGChar.h"

#pragma pack(push, 8)

class GcDbDatabase;
class GcDbAuditInfo;
class GcDbImpAuditInfo;
class GcDbAuditImp;
class GcDbObject;

#define GCDB_AUDIT_RETURN(pAuditInfo, baseEs, localEs, boilDownLocalStatus)        \
    return (baseEs != eOk)                ?  \
               baseEs                     :  \
               (eOk == localEs)           ?  \
                   eOk                    :  \
                   boilDownLocalStatus    ?  \
                       (pAuditInfo->fixErrors()?  \
                           eFixedAllErrors     :  \
                           eLeftErrorsUnfixed) :  \
                       localEs;


class GCBASE_PORT GcDbAuditInfo
{
public:
  friend class GcDbImpAuditInfo;
  friend class GcDbAuditImp;
  enum AuditPass {
    PASS1 = 1,
    PASS2 = 2
  };

  GcDbAuditInfo();
  ~GcDbAuditInfo();

  bool fixErrors(void) const;
  int numErrors() const;
  int numFixes(void) const;
  void errorsFound(int count);
  void errorsFixed(int count);
  AuditPass auditPass(void) const;
  void printError(const GCHAR * name,
    const GCHAR * value,
    const GCHAR * validation,
    const GCHAR * defaultValue);
  void printError(const GcDbObject *pObj,
    const GCHAR * value,
    const GCHAR * validation,
    const GCHAR * defaultValue);

  void requestRegen();
  void resetNumEntities();
  void incNumEntities();
  int numEntities();
  void printNumEntities(const GCHAR* msg);

  Gcad::ErrorStatus fetchObject(GcDbObjectId    originalObjId,
    GcDbObjectId& newObjId,
    GcRxClass*    pObjClass,
    bool          uneraseIfPossible = false,
    bool          createIfNotFound = true,
    bool          externalDbOk = false);
  Gcad::ErrorStatus registerObject(GcDbHandle handle, bool objIsValid, GcRxClass* pObjClass);
  Gcad::ErrorStatus updateObject(GcDbHandle   handle,
    bool         setFileObjIsValid,
    bool         setNewObjIsValid,
    bool         setFileObjClass,
    bool         setNewObjClass,
    bool         setNewObjId,
    bool         fileObjIsValid,
    bool         newObjIsValid,
    GcRxClass*   pFileObjClass,
    GcRxClass*   pNewObjClass,
    GcDbObjectId newObjId);
private:
  GcDbImpAuditInfo * getImpAudit() const;
  GcDbImpAuditInfo * mpImpAudit;
};

class GcDbRecover {
public:
  virtual  int callBack(GcDbDatabase*) = 0;
};

class GcDbImpRecoverCallBack;

class GCDB_PORT GcDbRecoverCallBack {
public:
  GcDbRecoverCallBack();
  virtual ~GcDbRecoverCallBack();

  virtual  Gcad::ErrorStatus registerCallBack(GcDbRecover*);
  virtual  Gcad::ErrorStatus removeCallBack();
private:
  GcDbImpRecoverCallBack *mpImpRecoverCallBack;
};

#pragma pack(pop)

#endif