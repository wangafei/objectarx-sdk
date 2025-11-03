#ifndef _ASECLASS_H
#define _ASECLASS_H
#pragma once

#define getAcadDsPath  getGcadDsPath

#include "asiappl.h"
#include "aseconst.h"
#include "dbmain.h"

#define CASEAPPL(x)   ((CAseAppl*)x)
#define CASELINKPATH(x) ((CAseLinkPath*)x)
#define CASELINK(x)   ((CAseLink*)x)
#define CASELINKSEL(x)  ((CAseLinkSel*)x)

#define ASE_THROW(x)  {((CAseApiObj*)x)->appThrow() ;}
#define WORKINGDWG()  NULL

#pragma pack (push, 8)
#if defined(__cplusplus)

class CAseApiErr;
class CAseApiObj;
class CAseAppl;
class CAseLinkPath;
class CAseLinkSel;
class CAseReactor;

class CAseApiObj
{
public:
  CAseApiObj(CAseApiObj* pObj) ;
  CAseApiObj(CAseApiObj& Obj) ;
  CAseApiObj();
  virtual ~CAseApiObj() ;
  virtual EAsiBoolean init() ;
  virtual EAseApiClassId isA() const = 0 ;
  virtual CAseApiObj* clone() const = 0 ;
  virtual EAsiBoolean copyFrom(const CAseApiObj* pObj) ;
  virtual CAseApiObj& operator=(const CAseApiObj& Obj) ;
  virtual int operator==(const CAseApiObj* pObj) const = 0 ;
  virtual int operator==(const CAseApiObj& Obj) const = 0 ;
  virtual EAsiBoolean isInit() const ;
  const OdChar* version() const ;
  const CAsiException* errGet() const ;
  int errQty() const ;
  EAseErrDsc errDsc(int ErrNum) const ;
  int errCode(int ErrNum) const ;
  EAsiBoolean errMsg(int ErrNum,
    OdChar *pBuf,
    int BufLen) const;
  EAsiBoolean errClear() ;
  void appThrow() const ;
  const OdChar *errDiagParNameCode(int ParNum,
    int* pParCode,
    int* pIsStr) const ;
  EAsiBoolean errDiagPar(int ErrNum,
    int ParCode,
    int* pIntValue) const ;
  EAsiBoolean errDiagPar(int ErrNum,
    int ParCode,
    OdChar* pStrValue,
    int BufLen) const ;

  // Initialize the diagnostics area by ASI errors.
  EAsiBoolean errInitAsi(CAsiException* pErr) ;
  EAsiBoolean errInitAsi(CAsiSQLObject* pSQLObj) ;
  EAsiBoolean errInitAsi(CAsiSQLObject& sqlObj) ;

  friend class CAseApiErr ;
  friend class CAseAppl ;
protected:
  struct resbuf* getLast(const struct resbuf* bufptr) const ;
  struct resbuf* allocAttr(EAseLinkAttr attr, const OdChar* pStr=NULL) const ;
  struct resbuf* copyBuf(const struct resbuf* bufptr,
    const struct resbuf* pBorder=NULL) const ;
  struct resbuf* nextAttr(const struct resbuf* bufptr) const ;
  struct resbuf* getAttrType(const struct resbuf *bufptr,
    EAseLinkAttr lattr) const ;
  const struct resbuf *getAttrPtr(const struct resbuf *bufptr,
    EAseLinkAttr lattr) const ;
  EAsiBoolean setAttrPtr(struct resbuf *bufptr,
    EAseLinkAttr LinkAttr,
    struct resbuf *pAttrValue) const ;
  struct resbuf *delAttrPtr(struct resbuf *bufptr,
    struct resbuf *pAttr) const ;
  EAsiBoolean parseLisp(struct resbuf *bufptr) ;
  CAseAppl *getAppl() const ;
  void freeStr(struct resbuf *pBuf) const ;
  EAsiBoolean isDiffChar() const ;

  void* mpErr ;   // The error descriptor pointer
} ;

// This class is responsible for the interface
// with the ASE main module.
class CAseAppl : public CAseApiObj
{
public:
  CAseAppl(CAseApiObj* pObj =NULL ) ;
  CAseAppl(CAseApiObj& Obj) ;
  virtual ~CAseAppl() ;
  virtual EAsiBoolean init() ;
  virtual EAseApiClassId isA() const ;
  virtual CAseApiObj* clone() const ;
  virtual EAsiBoolean copyFrom(const CAseApiObj* pObj) ;
  virtual CAseApiObj& operator=(const CAseApiObj& Obj) ;
  virtual int operator==(const CAseApiObj* pObj) const ;
  virtual int operator==(const CAseApiObj& Obj) const ;
  virtual EAsiBoolean isInit() const ;
  void term() ;

  LPCTSTR getGcadDsPath();

  // Maps ASE global diagnostics area into the target CAseAppl object
  EAsiBoolean getAseErr() ;
  // Clears ASE global diagnostics area
  EAsiBoolean clearAseErr();

  // This function returns the ASI session
  // allocated in the current application
  CAsiSession* connectAse(CAsiAppl *pAppl,
    const TCHAR *pEnvName,
    const OdChar *pUserName=NULL,
    const OdChar *pPassWord=NULL,
    EAsiBoolean fPrompt = kAsiFalse) ;

  // Checks whether the ASE index exists and it is up to date for
  // the drawing database specified
  EAsiBoolean isIndexExist(OdDbDatabase *pDwg=NULL);
  EAsiBoolean isIndexUpToDate(OdDbDatabase *pDwg=WORKINGDWG());
  // Creates (writes) the ASE index in the drawing database specified
  EAsiBoolean createIndex(OdDbDatabase *pDwg=WORKINGDWG());
  // Erases the ASE index from the drawing database specified
  EAsiBoolean removeIndex(OdDbDatabase *pDwg=WORKINGDWG());

  int setIndexSaveMode (int mode);

  EAsiBoolean openDwg(OdDbDatabase *pDwg=WORKINGDWG()) ;
  EAsiBoolean openLazyDwg(OdDbDatabase *pDwg=WORKINGDWG()) ;
  EAsiBoolean isDwgOpened(OdDbDatabase *pDwg=WORKINGDWG()) ;
  EAsiBoolean isDwgLazyOpened(OdDbDatabase *pDwg=WORKINGDWG()) ;
  EAsiBoolean closeDwg(OdDbDatabase *pDwg=WORKINGDWG()) ;
  // Swaps the references to linked entities
  // Should be followed right after OdDbObject::swapIdWith() call
  EAsiBoolean swapEntIds(OdDbObjectId objectId,
    OdDbObjectId otherId,
    OdDbDatabase *pDwg=WORKINGDWG());
  // Swaps the references to BTR
  // Should be followed right after OdDbObject::swapIdWith() call
  // for BTR
  EAsiBoolean swapBTRIds(OdDbObjectId blockId,
    OdDbObjectId otherId,
    OdDbDatabase *pDwg=WORKINGDWG());
  // Makes ASE store unread ASE link information from the entity,
  // for lazy opened source drawing
  EAsiBoolean loadLinks(OdDbEntity *pObj);
  EAsiBoolean loadLinks(OdDbObjectId objId);
  EAsiBoolean translateDataSource(DatasourceTranslationCode xCode,
    unsigned int buflen,
    const OdChar * szFromEnv,
    const OdChar * szFromCat,
    const OdChar * szFromSchema,
    const OdChar * szFromTable,
    const OdChar * szFromLpn,
    OdChar * szToEnv,
    OdChar * szToCat,
    OdChar * szToSchema,
    OdChar * szToTable,
    OdChar * szToLpn);

  EAsiBoolean beginAseTransaction();
  EAsiBoolean commitAseTransaction();
  EAsiBoolean abortAseTransaction();
 
enum ETransactionMode
{
  kTransAutomatic = 0,
  kTransUserManaged
};

  void setAseTransactionMode(CAseAppl::ETransactionMode eMode );
  ETransactionMode getAseTransactionMode();

protected:

  // ASE call
  struct resbuf* aseiCallAse(int funCode,
    struct resbuf* pParms,
    void *pErr,
    void *pOdDbDatabase=NULL,
    EAsiBoolean needFullOpen=kAsiFalse) ;

  // RX-RX communication
  struct resbuf * ase_invoke(int funCode,
    struct resbuf* pParms,
    void *pErr,
    void *pAse) ;
  struct resbuf * ase_fromAse(struct resbuf *pBuf) ;
  EAsiBoolean ase_toAse(struct resbuf *pBuf) ;
  EAsiBoolean addObj(const CAseApiObj *pObj) ;
  EAsiBoolean remObj(const CAseApiObj *pObj) ;

  EAsiBoolean mapErrFromAse(void *pAse, void *pErr);

  friend class CAseApiObj ;
  friend class CAseLinkPath ;
  friend class CAseLink ;
  friend class CAseLinkSel ;
  friend class CAseApiErr ;
  TCHAR *mpVersion ;  // The ASE version
  void *mpRes ; // XMF file reference
  void *mpObjs ;   // Attached objects list
  EAsiBoolean mIsDiffChar ;  // ASE & ASE appl have the
  // different character sets (kAsiTrue)
  TCHAR *mpDefChar ;  // ASE default character set
  // (NULL if the same as ASE has)
  ETransactionMode meTransMode;  // Automatically committing ASE transactions
  // on Link/Label inserts, deletes, etc.

} ;


class CAseLinkPath : public CAseApiObj
{
public:
  CAseLinkPath(CAseApiObj *pObj) ;
  CAseLinkPath(CAseApiObj &Obj) ;
  virtual ~CAseLinkPath() ;
  virtual EAsiBoolean init() ;
  virtual EAseApiClassId isA() const ;
  virtual CAseApiObj *clone() const ;
  virtual EAsiBoolean copyFrom(const CAseApiObj *pObj) ;
  virtual CAseApiObj& operator=(const CAseApiObj &Obj) ;
  virtual int operator==(const CAseApiObj *pObj) const ;
  virtual int operator==(const CAseApiObj &Obj) const ;
  virtual EAsiBoolean isInit() const ;

  EAsiBoolean initPath(const OdChar *pPath) ;
  EAsiBoolean initName(const OdChar *pName) ;
  EAsiBoolean initCurrent() ;
  EAsiBoolean reInit();
  EAsiBoolean setName(const OdChar *pName,
    EAseDoNameCode NameCode=kAseLpnCode) ;
  EAsiBoolean getName(OdChar *pBuf, int BufLen,
    EAseDoNameCode NameCode=kAseLpnCode) const ;
  int getNameSize(EAseDoNameCode NameCode=kAseLpnCode) const;
  int cmpName(const OdChar *pName, 
    EAseDoNameCode NameCode=kAseLpnCode) const ;
  int cmpName(const CAseLinkPath *pLinkPath, 
    EAseDoNameCode NameCode=kAseLpnCode) const ;
  EAseDoNameCode getPathCode() const;
  int getStatus() const;
  EAsiBoolean isUpdatable() const ;
  EAsiBoolean getKeyDsc(CAsiRow **pKeyDsc) const;
  EAsiBoolean getKeyDsc(CAsiColumn **pKeyDsc[], int *pColQty) const;
  EAsiBoolean create(const CAsiRow *pKeyDsc) ;
  EAsiBoolean create(const CAsiRow &KeyDsc) ;
  EAsiBoolean create(const CAsiColumn *pKeyDsc[], int ColQty) ;
  EAsiBoolean erase() ;
  EAsiBoolean rename(const OdChar *pLinkPathName) ;
  EAsiBoolean setCurrent() const ;
  struct resbuf *getLinkNames() const ;
  struct resbuf *getPaths(int Status) const ;

  // Manages the ASE connection
  EAsiBoolean connectAse(const OdChar *pUsername=NULL,
    const OdChar *pPassword=NULL,
    EAsiBoolean fPrompt=kAsiFalse) ;

  EAsiBoolean connectAseIniString (const OdChar *pIniString);

  EAsiBoolean disconnectAse();

  // Check which ASI functionality is supported by the connected Env
  EAsiBoolean checkOp(ulong status) const;

  // Gets the description of the databas table
  EAsiBoolean getTableDsc(CAsiRow **pColumns) const;
  EAsiBoolean getTableDsc(CAsiColumn **pKeyDsc[],
    int *pColQty) const;
  // Creates the table
  EAsiBoolean createTable(const CAsiRow *pCols);
  EAsiBoolean createTable(const CAsiColumn *pCols[],
    int colNum);
  // Deletes the table from the database   
  EAsiBoolean dropTable();

  // Updates the values of the table row specified by the key values 
  EAsiBoolean updRow(const CAsiRow *pKey,
    const CAsiRow *pValue,
    long *pRowsQty=NULL) const;
  EAsiBoolean updRow(const CAsiColumn *pKey[],
    int numKeys,
    const CAsiColumn *pValue[],
    int numValues,
    long *pRowsQty=NULL) const;
  // Deletes the row specified by the key values
  EAsiBoolean delRow(const CAsiRow *pValue,
    long *pRowsQty=NULL) const;
  EAsiBoolean delRow(const CAsiColumn *pValue[],
    int numKeys,
    long *pRowsQty=NULL) const;
  // Adds the row to the table  
  EAsiBoolean addRow(const CAsiRow *pValue) const;
  EAsiBoolean addRow(const CAsiColumn *pValue[],
    int numValues) const;

  // Gets the values of the table row specified by the key
  // values into the specified buffer
  EAsiBoolean getRow(const CAsiRow *pKeyValue,
    CAsiRow *pRowBuffer) const;

  // This function has to be called to specify the drawing
  // database where the Link Paths are be processed in
  EAsiBoolean setDwg(const OdDbDatabase *pDwg=WORKINGDWG()) ;

  // Gets the drawing database which the processed
  // Link Paths are situated in
  const OdDbDatabase* getDwg() const ;


  EAsiBoolean allocCursor(const CAsiRow *pKeyDsc,
    const CAsiRow *pRow,
    long *pCursorNum) const;

  EAsiBoolean getCursorRow(long cursorNum,
    const CAsiRow *pKeyValue,
    CAsiRow *pRow) const;
  // Deallocates the cursor.   
  EAsiBoolean delCursor(long cursorNum) const;

protected:
  void *mpPath ;  // The internal data pointer
  void *mpDwg ;   // The drawing database pointer
} ;

//  This is the base class, defining the common
//  responsibility of the concrete links.
class CAseLink : public CAseApiObj
{
public:
  CAseLink(CAseApiObj *pObj) ;
  CAseLink(CAseApiObj &Obj) ;
  virtual ~CAseLink() ;
  virtual EAsiBoolean init() ;
  EAsiBoolean initType(EAseLinkType lType) ;
  EAsiBoolean initId(LinkID linkId) ;
  EAsiBoolean initEnt(const OdChar *pName,
    const CAsiRow *pKeyValue,
    tdx_name EntName) ;
  EAsiBoolean initEnt(const OdChar *pName,
    const CAsiRow &KeyValue,
    tdx_name EntName) ;
  EAsiBoolean initEnt(const OdChar *pName,
    const CAsiColumn *pKeyValue[],
    int ColQty,
    tdx_name EntName) ;
  EAsiBoolean initDA(const OdChar *pName,
    const CAsiRow *pKeyValue,
    const CAsiRow *pDACols,
    const struct resbuf *pDAParms) ;
  EAsiBoolean initDA(const OdChar *pName,
    const CAsiRow &KeyValue,
    const CAsiRow &DACols,
    const struct resbuf *pDAParms) ;
  EAsiBoolean initDA(const OdChar *pName,
    const CAsiColumn *pKeyValue[],
    int ColQty,
    const CAsiColumn *pDACols[],
    int DAColQty,
    const struct resbuf *pDAParms) ;
  virtual EAseApiClassId isA() const ;
  virtual CAseApiObj* clone() const ;
  virtual EAsiBoolean copyFrom(const CAseApiObj *pObj) ;
  virtual CAseApiObj& operator=(const CAseApiObj &Obj) ;
  virtual int operator==(const CAseApiObj *pObj) const ;
  virtual int operator==(const CAseApiObj &Obj) const ;
  virtual EAsiBoolean isInit() const ;

  LinkID getId () const ;
  EAseLinkType getType() const ;
  EAsiBoolean getName(OdChar *pBuf, int len) const;
  int getNameSize() const ;
  EAsiBoolean setName(const OdChar *pName) ;
  EAsiBoolean getEntity(tdx_name EntName) const ;
  EAsiBoolean setEntity(tdx_name EntName) ;
  EAsiBoolean getKey(CAsiRow *pKeyValue) const ;
  EAsiBoolean getKey(CAsiRow &KeyValue) const ;
  EAsiBoolean getKey(CAsiColumn *pKeyValue[], int ColQty) const ;
  EAsiBoolean setKey(const CAsiRow *pKeyValue) ;
  EAsiBoolean setKey(const CAsiRow &KeyValue) ;
  EAsiBoolean setKey(const CAsiColumn *pKeyValue[], int ColQty) ;
  EAsiBoolean setDACols (const CAsiRow *pCols) ;
  EAsiBoolean setDACols (const CAsiRow &Cols) ;
  EAsiBoolean setDACols(CAsiColumn *pCols[], int ColQty) ;
  EAsiBoolean getDACols (CAsiRow **pCols) const ;
  EAsiBoolean getDACols(CAsiColumn **pCols[], int *pColQty) const ;
  EAsiBoolean setDAParms(const struct resbuf *pParms) ;
  EAsiBoolean setDAValues(const CAsiRow *pDAValues) ;
  EAsiBoolean setDAValues(const CAsiRow &DAValues) ;
  EAsiBoolean setDAValues(CAsiColumn *pCols[], int ColQty) ;
  EAsiBoolean create () ;
  EAsiBoolean remove () ;
  EAsiBoolean update () ;
  EAsiBoolean getXName(OdChar *pBuf, int len) const ;
  EAsiBoolean isUpdatable() const ;

  // This function has to be called to specify the drawing
  // database where the Link Paths are be processed in
  EAsiBoolean setDwg(const OdDbDatabase *pDwg=WORKINGDWG()) ;
  
  // Gets the drawing database which the processed
  // Link Paths are situated in
  const OdDbDatabase* getDwg() const ;
  
  // Un-documented
  // Gets/sets the link attribute values in the internal representation
  struct resbuf* getAttr(EAseLinkAttr LinkAttr) const ;
  EAsiBoolean setAttr(EAseLinkAttr LinkAttr,
  const struct resbuf *pAttrValue) ;
private:
  struct resbuf *mpBuf ;  // The link result buffer representation
  void *mpDwg ;   // The drawing database pointer
} ;

//  This class describes the link selection.
class CAseLinkSel : public CAseApiObj 
{
public:
  CAseLinkSel(CAseApiObj *pObj) ;
  CAseLinkSel(CAseApiObj &Obj) ;
  virtual ~CAseLinkSel() ;
  virtual EAsiBoolean init() ;
  EAsiBoolean initType(EAseLinkType LinkType) ;
  EAsiBoolean initSel(tdx_name EntSelName,
    EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean initEnt(tdx_name EntName,
    EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean initXName(const OdChar *pXName,
    EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean initLp(const OdChar *pName,
    EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean initLp(const CAseLinkPath *pLinkPath,
    EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean initLp(const CAseLinkPath &LinkPath,
    EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean initLpEnt(const OdChar *pName,
    tdx_name EntName,
    EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean initLpEnt(const CAseLinkPath *pLinkPath,
    tdx_name EntName,
    EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean initLpEnt(const CAseLinkPath &LinkPath,
    tdx_name EntName,
    EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean initLpKey(const OdChar *pName,
    const CAsiRow *pKeyValue,
    EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean initLpKey(const OdChar *pName,
    const CAsiRow &KeyValue,
    EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean initLpKey(const CAseLinkPath *pLinkPath,
    const CAsiRow *pKeyValue,
    EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean initLpKey(const CAseLinkPath &LinkPath,
    const CAsiRow &KeyValue,
    EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean initLpKey(const OdChar *pName,
    const CAsiColumn *pKeyValue[],
    int ColQty,
    EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean initLpKey(const CAseLinkPath *pLinkPath,
    const CAsiColumn *pKeyValue[],
    int ColQty,
    EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean initLpCond(const OdChar *pName,
    const OdChar *pTextCondition,
    EAseLinkType LinkType) ;
  EAsiBoolean initLpCond(const CAseLinkPath *pLinkPath,
    const OdChar *pTextCondition,
    EAseLinkType LinkType) ;
  EAsiBoolean initLpCond(const CAseLinkPath &LinkPath,
    const OdChar *pTextCondition,
    EAseLinkType LinkType) ;
  EAsiBoolean initLpSel(const OdChar *pName,
    tdx_name EntSelName,
    EAseLinkType LinkType) ;
  EAsiBoolean initLpSel(const CAseLinkPath *pLinkPath,
    tdx_name EntSelName,
    EAseLinkType LinkType) ;
  EAsiBoolean initLpSel(const CAseLinkPath &LinkPath,
    tdx_name EntSelName,
    EAseLinkType LinkType) ;
  EAsiBoolean initPartialKey(const OdChar *pName,
    const CAsiRow *pKeyValue,
    EAseLinkType LinkType) ;
  EAsiBoolean initPartialKey(const CAseLinkPath *pLinkPath,
    const CAsiRow *pKeyValue,
    EAseLinkType LinkType) ;

  virtual EAseApiClassId isA() const ;
  virtual CAseApiObj *clone() const ;
  virtual EAsiBoolean copyFrom(const CAseApiObj *pObj) ;
  virtual CAseApiObj& operator=(const CAseApiObj &Obj) ;
  virtual int operator==(const CAseApiObj *pObj) const ;
  virtual int operator==(const CAseApiObj &Obj) const ;
  virtual EAsiBoolean  isInit() const ;
  EAsiBoolean isUpdatable() const ;

  long getQty() const ;
  LinkID getId(long ItemNum) const ;
  EAsiBoolean addId(LinkID linkId) ;
  EAsiBoolean delId(long ItemNum) ;
  long membId(LinkID linkId) const ;
  
  EAsiBoolean unite(const CAseLinkSel *pSel) ;
  EAsiBoolean unite(const CAseLinkSel &Sel) ;
  EAsiBoolean subtract(const CAseLinkSel *pSel) ;
  EAsiBoolean subtract(const CAseLinkSel &Sel) ;
  EAsiBoolean intersect(const CAseLinkSel *pSel) ;
  EAsiBoolean intersect(const CAseLinkSel &Sel) ;

  EAsiBoolean intersectType(EAseLinkType LinkType) ;
  EAsiBoolean intersectEnt(tdx_name EntName) ;
  EAsiBoolean intersectSel(tdx_name EntSelName) ;
  EAsiBoolean intersectXName(const OdChar *pXName) ;
  EAsiBoolean intersectLp(const OdChar *pName) ;
  EAsiBoolean intersectLp(const CAseLinkPath *pLinkPath) ;
  EAsiBoolean intersectLp(const CAseLinkPath &LinkPath) ;
  EAsiBoolean intersectLpKey(const OdChar *pName,
    const CAsiRow *pKeyValue) ;
  EAsiBoolean intersectLpKey(const OdChar *pName,
    const CAsiRow &KeyValue) ;
  EAsiBoolean intersectLpKey(const CAseLinkPath *pLinkPath,
    const CAsiRow *pKeyValue) ;
  EAsiBoolean intersectLpKey(const CAseLinkPath &LinkPath,
    const CAsiRow &KeyValue) ;
  EAsiBoolean intersectLpKey(const OdChar *pName,
    const CAsiColumn *pKeyValue[],
    int ColQty) ;
  EAsiBoolean intersectLpKey(const CAseLinkPath *pLinkPath,
    const CAsiColumn *pKeyValue[],
    int ColQty);
  EAsiBoolean intersectLpCond(const OdChar *pName,
    const OdChar *pTextCondition) ;
  EAsiBoolean intersectLpCond(const CAseLinkPath *pLinkPath,
    const OdChar *pTextCondition) ;
  EAsiBoolean intersectLpCond(const CAseLinkPath &LinkPath,
    const OdChar *pTextCondition) ;

  EAsiBoolean intersectPartialKey(const OdChar *pName,
    const CAsiRow *pKeyValue) ;
  EAsiBoolean intersectPartialKey(const CAseLinkPath *pLinkPath,
    const CAsiRow *pKeyValue) ;
   
  // Gets the LPN of the link which identifier are specified
  // by means of ItemNum position in the link selection
  EAsiBoolean getLinkName(long ItemNum,
    TCHAR *pNameBuf,
    int nameBufLen) const;
 
  // Get the key value of the link 
  // which identifier is specified by means of ItemNum position
  // in the link selection
  EAsiBoolean getLinkKey(long ItemNum, CAsiRow *pKeyValue);

  // Get the name of the entity having the link
  // which identifier is specified by means of ItemNum position
  // in the link selection
  EAsiBoolean getLinkEnt(long ItemNum, tdx_name ename);

  // Adds the identifiers of the drawing objects
  // having the links which identifiers are contained
  // in the link selection
  int getIdArray(OdDbObjectIdArray *pLinkedEntities) const;

  // Get the identifier of the entity having the link
  // which identifier is specified by means of ItemNum position
  // in the link selection
  EAsiBoolean getLinkEnt(long ItemNum, OdDbObjectId *pId); 
  // This function has to be called to specify the drawing
  // database where the links are processed in
  EAsiBoolean setDwg(const OdDbDatabase *pDwg=WORKINGDWG()) ;
  
  // Gets the drawing database which the processed
  // links are situated in
  const OdDbDatabase* getDwg() const ;

  struct resbuf* getXNames() const ;
  struct resbuf* getLinkNames() const ;
  EAsiBoolean getEntSel(tdx_name EntSelName) const ;
  EAsiBoolean erase() ;

  // Un-documented
  // Initializes the link selection by the 
  // internal link filter
  virtual EAsiBoolean initFilter(struct resbuf *pLinkFilter,
   EAsiBoolean needFullOpen=kAsiFalse) ;
  // Filters the link selection by the 
  // internal link filter
  virtual EAsiBoolean intersectFilter(const struct resbuf *pLinkFilter) ;

protected:
  void freeSel() ;
  struct resbuf* makeFilter(EAseLinkType LinkType,
    const OdChar* pXName,
    tdx_name EntName,
    tdx_name EntSelName,
    const OdChar *pName,
    const CAseLinkPath *pLinkPath,
    const CAsiRow *pKeyValue,
    const OdChar *pTextCondition,
    const CAsiRow *pParKeyValue = NULL) ;

  LinkSelID mSelId ;  // The link selection identifier
  void *mpDwg ;   // The drawing database pointer
} ;

#endif /* __cplusplus */
#pragma pack (pop)
#endif /*_ASECLASS_H*/
