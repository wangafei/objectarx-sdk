/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GcDbHostApplicationServices_INC
#define GcDbHostApplicationServices_INC

#include "gsoft.h"
#include "gcdb.h"
#include "gcarray.h"
#include "GcString.h"
#include "PAL/api/codepgid.h"
#include "gcdlflagbits.h"

#include "inetstrc.h"
#include "rxdlinkr.h"
#include "PAL/api/product_flavors.h"
#include "PAL/api/GcLocale.h"
#pragma pack (push, 8)

class GcadInternalServices;
class GcadInternalServices2;
class GcDbAppSystemVariables;
class GcDbAuditInfo;
class GcDbDatabase;
class GcDbGlobals;
class GcDbObjectId;
class GcDbTransactionManager;
class GcDbUndoController;
class CArchive;
class COleClientItem;
struct flagmat;

class GcDbAbstractClipBoundaryDefinition;
class ClipBoundaryArray;

class GcDbPlotSettingsValidator;
class GcDbLayoutManager;
class GcPwdCache;

enum  GcSDIValues {
  kMDIEnabled = 0,
  kSDIUserEnforced,
  kSDIAppEnforced,
  kSDIUserAndAppEnforced
};

class GCBASE_PORT GcDbHostApplicationProgressMeter {
public:
  GcDbHostApplicationProgressMeter();
  virtual ~GcDbHostApplicationProgressMeter();

  virtual void start(const GCHAR * displayString = NULL);
  virtual void stop();
  virtual void meterProgress();
  virtual void setLimit(int max);
};

typedef Gcad::ErrorStatus(*SELECTFILEPROC)(short *userCancel,
  GCHAR *& chosenPath,
  void* h,
  const int nFlags,
  const GCHAR * prompt,
  const GCHAR * dir,
  const GCHAR * name,
  const GCHAR * type,
  int* pnChoice,
  bool* pbReadOnly,
  const GCHAR * pszWSTags,
  GcStringArray* pReserved);

typedef Gcad::ErrorStatus(*REMAPPROC) (GCHAR *& newName,
  const GCHAR * filename,
  int context,
  void* pReserved);

typedef void(*MAPFILENOTIFYPROC) (const GCHAR * filename,
  const GCHAR * newName,
  int context,
  void* pReserved);

class GcString;

class GSOFT_NO_VTABLE GCDB_PORT GcDbHostApplicationServices : public GcRxObject
{
  friend class GcadInternalServices;
public:
  GCRX_DECLARE_MEMBERS(GcDbHostApplicationServices);
  GcDbHostApplicationServices(int createGlobals = 1);
  ~GcDbHostApplicationServices();

  enum FindFileHint
  {
    kDefault = 0,
    kFontFile,
    kCompiledShapeFile,
    kTrueTypeFontFile,
    kEmbeddedImageFile,
    kXRefDrawing,
    kPatternFile,
    kGRXApplication,
    kFontMapFile,
    kUnderlayFile,
    kDataLinkFile,
    kPhotometricWebFile,
    kMaterialMapFile,
    kCloudOrProjectFile,
  };

  enum RemapFileContext
  {
    kDrawingOpen,
    kXrefResolution,
    kRasterResolution,
    kAfterXrefResolution
  };

private:
  virtual Gcad::ErrorStatus findFile(GCHAR * pcFullPathOut,
    int   nBufferLength,
    const GCHAR * pcFilename,
    GcDbDatabase * pDb = NULL,
    GcDbHostApplicationServices::FindFileHint hint = kDefault) = 0;
public:
  Gcad::ErrorStatus findFile(GcString& fileOut,
    const GCHAR * pcFilename,
    GcDbDatabase * pDb = nullptr,
    GcDbHostApplicationServices::FindFileHint hint = GcDbHostApplicationServices::kDefault);
  virtual Gcad::ErrorStatus getRoamableRootFolder(const GCHAR *& folder);
  virtual Gcad::ErrorStatus getLocalRootFolder(const GCHAR *& folder);
  virtual Gcad::ErrorStatus getAllUsersRootFolder(const GCHAR*& folder);
  virtual Gcad::ErrorStatus getGraphicsCacheFolder(const GCHAR *& folder);
  virtual Gcad::ErrorStatus selectFile(short *userCancel,
    GCHAR *& chosenPath,
    void* h,
    const int nFlags,
    const GCHAR * prompt,
    const GCHAR * dir,
    const GCHAR * name,
    const GCHAR * type,
    int* pnChoice,
    bool* pbReadOnly,
    const GCHAR * pszWSTags,
    GcStringArray* pReserved);
  virtual Gcad::ErrorStatus registerSelectFileCallback(const GCHAR * appName,
    SELECTFILEPROC proc,
    bool unRegister = false,
    bool asPrimary = false);
  virtual const GCHAR *     primaryClientForSelectFileCallback();
  virtual Gcad::ErrorStatus getRegisteredSelectFileClients(GcArray<const GCHAR *>& clients);
  virtual Gcad::ErrorStatus mapFile(GCHAR *& newName,
    const GCHAR * filename,
    int context,
    void* pReserved);
  virtual Gcad::ErrorStatus   registerMapFileCallback(const GCHAR * appName,
    REMAPPROC  proc,
    bool unRegister = false,
    bool asPrimary = false);
  virtual const GCHAR *       primaryClientForMapFileCallback();
  virtual bool                setMapFlag(bool setIt);
  virtual Gcad::ErrorStatus   getRegisteredFileMapClients(GcArray<const GCHAR *>& clients);
  virtual Gcad::ErrorStatus   registerMapFileNotification(const GCHAR * appName, MAPFILENOTIFYPROC, bool unRegister = false);
  virtual void fatalError(const GCHAR *format, ...);
  virtual void reportUnhandledGrxException(const GCHAR* pExceptionDescription, const GCHAR *pAppName);
  virtual Gsoft::Boolean userBreak(bool updCtrlsWhenEnteringIdle = true) const;
  virtual void displayChar(GCHAR c) const;
  virtual void displayString(const GCHAR* string, int count) const;
  virtual Gsoft::Boolean readyToDisplayMessages();
  virtual void enableMessageDisplay(Gsoft::Boolean);
  virtual Gsoft::Boolean doFullCRCCheck();
  virtual unsigned int getTempPath(Gsoft::UInt32 lBufferSize,	GCHAR* pcBuffer);
  GcString getTempPath();
  virtual const GCHAR* getEnv(const GCHAR * var);
  virtual GcDbHostApplicationProgressMeter* newProgressMeter();
  void setWorkingProgressMeter(GcDbHostApplicationProgressMeter* pNewMeter);
  virtual GcDbAbstractClipBoundaryDefinition* newClipBoundaryRectangular();
  virtual GcDbAbstractClipBoundaryDefinition* newClipBoundaryPolygonal();
  virtual ClipBoundaryArray* newClipBoundaryArray();
  GcDbDatabase* workingDatabase() const;
  void setWorkingDatabase(GcDbDatabase* pDatabase);
  virtual GcDbUndoController* defaultUndoController();
  void setDefaultUndoController(GcDbUndoController* pUndoCtrl);
  virtual GcDbTransactionManager* workingTransactionManager();
  void setWorkingTransactionManager(GcDbTransactionManager* pTM);
  virtual GcDbGlobals * createWorkingGlobals();
  GcDbGlobals * workingGlobals() const;
  void setWorkingGlobals(GcDbGlobals* pGlobals);
  GcDbAppSystemVariables * workingAppSysvars() const;
  void setWorkingAppSysvars(GcDbAppSystemVariables* pSysvars);
  virtual const GCHAR * program();
  virtual const GCHAR * product();
  virtual const GCHAR * companyName();
  virtual const ProdIdCode prodcode();
  virtual const GCHAR * releaseMajorMinorString();
  virtual int   releaseMajorVersion();
  virtual int   releaseMinorVersion();
  virtual const GCHAR * versionString();
  virtual const GCHAR * getMachineRegistryProductRootKey();
  virtual const GCHAR * getUserRegistryProductRootKey();
  virtual const GCHAR* releaseMarketVersion();
  virtual GcLocale  getProductLocale();
  virtual bool  supportsMultiRedo() const;
  enum ModelerFlavor { kModelerFull = 0, kModelerRegionsOnly = 1, kModelerObjectsOnly = 2 };
   virtual ModelerFlavor  getModelerFlavor() const;
  code_page_id getSystemCodePage() const;
  virtual GcadInternalServices* gcadInternalServices();
  void * gcadInternalGetvar(const GCHAR *name);
  virtual bool isURL(const GCHAR * pszURL) const;
  virtual bool isRemoteFile(const GCHAR * pszLocalFile, GCHAR * pszURL, size_t nUrlLen) const;

  template<size_t N> bool isRemoteFile(const GCHAR * pszLocalFile,
    GCHAR(&pszURL)[N]) const
  {
    return isRemoteFile(pszLocalFile, pszURL, N);
  }

  bool isRemoteFile(const GCHAR * pszLocalFile, GcString& strUrl);
  virtual Gcad::ErrorStatus getRemoteFile(const GCHAR * pszURL, GCHAR * pszLocalFile,
                                            size_t nLocalFileLen,
                                            bool bIgnoreCache) const;

  Gcad::ErrorStatus getRemoteFile(const GCHAR * pszURL, GcString& strLocalFile,
                                  bool bIgnoreCache) const;

  Gcad::ErrorStatus getRemoteFile(const GCHAR * pszURL, GcString& strLocalFile)
  {
    return this->getRemoteFile(pszURL, strLocalFile, false);
  }
  template<size_t N> Gcad::ErrorStatus getRemoteFile(const GCHAR * pszURL,
    GCHAR(&pszLocalFile)[N]) const
  {
    return this->getRemoteFile(pszURL, pszLocalFile, N, false);
  }
  virtual Gcad::ErrorStatus putRemoteFile(const GCHAR * pszURL, const GCHAR * pszLocalFile) const;
  virtual Gsoft::Boolean launchBrowserDialog(
    GCHAR *          pszSelectedURL,
    size_t           selectedUrlLen,
    const GCHAR *    pszDialogTitle,
    const GCHAR *    pszOpenButtonCaption,
    const GCHAR *    pszStartURL,
    const GCHAR *    pszRegistryRootKey = 0,
    Gsoft::Boolean bOpenButtonAlwaysEnabled = Gsoft::kFalse) const;

  template<size_t N> Gsoft::Boolean launchBrowserDialog(
    GCHAR(&pszSelectedURL)[N],
    const GCHAR *    pszDialogTitle,
    const GCHAR *    pszOpenButtonCaption,
    const GCHAR *    pszStartURL,
    const GCHAR *    pszRegistryRootKey = 0,
    Gsoft::Boolean bOpenButtonAlwaysEnabled = Gsoft::kFalse) const
  {
    return launchBrowserDialog(pszSelectedURL, N, pszDialogTitle,
      pszOpenButtonCaption, pszStartURL,
      pszRegistryRootKey, bOpenButtonAlwaysEnabled);
  }
  virtual void drawOleOwnerDrawItem(COleClientItem* pItem,
    Gsoft::LongPtr hdc,
    Gsoft::Int32 left, Gsoft::Int32 top, Gsoft::Int32 right, Gsoft::Int32 bottom);
  virtual Gcad::ErrorStatus getNewOleClientItem(COleClientItem*& pItem);
  virtual Gcad::ErrorStatus serializeOleItem(COleClientItem* pItem, CArchive*);
  virtual Gsoft::Boolean _entToWorldTransform(double normal[3], flagmat *tran);
   virtual void terminateScript();
   virtual Gsoft::Boolean getSubstituteFont(GCHAR **pFileName, const GCHAR *prompt, int type, int fontAlt);

  virtual Gsoft::Boolean getSubstituteFont(GCHAR **pFileName, GCHAR *prompt, int type, int fontAlt) final
  {
    const GCHAR *pConstPrompt = prompt;
    return this->getSubstituteFont(pFileName, pConstPrompt, type, fontAlt);
  }

  virtual void alert(const GCHAR * string) const;
  virtual void auditPrintReport(GcDbAuditInfo * pAuditInfo, const GCHAR * line, int both) const;
  virtual const GCHAR * getAlternateFontName() const;
  virtual const GCHAR * getFontMapFileName() const;
  virtual bool cacheSymbolIndices() const;
  virtual GcDbPlotSettingsValidator* plotSettingsValidator() const;
  virtual GcDbLayoutManager* layoutManager() const;
  virtual bool loadApp(const GCHAR * appName,
    GcadApp::LoadReasons why,
    bool printit,
    bool asCmd);
  virtual bool getDefaultPlotCfgInfo(GCHAR * plotDeviceName, size_t nDevNameLen,
    GCHAR * plotStyleName, size_t nStyleNameLen);

  template<size_t nDevLen, size_t nStyleLen> bool getDefaultPlotCfgInfo(
    GCHAR(&devName)[nDevLen], GCHAR(&styleName)[nStyleLen])
  {
    return getDefaultPlotCfgInfo(devName, nDevLen, styleName, nStyleLen);
  }

  void getDefaultPlotCfgInfo(GcString& devName, GcString& styleName);

  virtual Gcad::ErrorStatus signingComplete(Gcad::ErrorStatus es,
    const GCHAR * msg,
    bool* result);

  enum PasswordOptions { kPasswordOptionDefault = 0, kPasswordOptionUpperCase = 1, kPasswordOptionIsExternalReference = 2 };

  virtual bool getPassword(const GCHAR * dwgName,
    PasswordOptions options,
    wchar_t *password,
    const size_t bufSize);
  bool getPassword(const GCHAR * dwgName,
    GcDbHostApplicationServices::PasswordOptions options,
    GcString& password);
  virtual void usedPasswordFromCacheMsg(const GCHAR *dwgName);
  virtual void missingCryptoProviderMsg();
  virtual const GCHAR * getColorBookLocation() const;
  GcPwdCache * getPasswordCache() const;
  virtual short getKeyState(int nVirtKey) const;

  enum RequiredVersionFlags {
    kNoOpen = 0,
    kReadOnly = 1,
    kWriteAllowed = 2
  };

  virtual bool requiredVersionNotAvailable(GcDbHostApplicationServices::RequiredVersionFlags flags,GcDbDatabase* pDb) const;
  virtual bool notifyCorruptDrawingFoundOnOpen(GcDbObjectId id, Gcad::ErrorStatus es);
  virtual GcadInternalServices2* gcadInternalServices2();
protected:
  Gcad::ErrorStatus mapInetStatusToGcadStatus(const GcadInet::Status status) const;
protected:
  void * mp_sessionVars = nullptr;
  void gcadInternalSetvar(const GCHAR *name, void * var);
private:
  GcDbDatabase* mpWorkingDatabase = nullptr;
  GcDbUndoController* mpDefaultUndoController = nullptr;
  GcDbTransactionManager* mpWorkingTransactionManager = nullptr;
  GcDbGlobals * mpWorkingGlobals = nullptr;
  GcDbAppSystemVariables * mpWorkingAppSysvars = nullptr;
  code_page_id m_eSystemCodePage = code_page_id::CODE_PAGE_UNDEFINED;
  bool mbDisplayMessages = true;
  GcPwdCache * mpPasswordCache = nullptr;
};

GCCORE_PORT Gcad::ErrorStatus gcdbSetHostApplicationServices(GcDbHostApplicationServices * pServices);
GCDB_PORT GcDbHostApplicationServices * gcdbHostApplicationServices();
GCDB_PORT Gcad::ErrorStatus gcdbSendInitialDwgFileOpenComplete(GcDbDatabase* pDb);
GCDB_PORT GcDbGlobals* getDefaultGlobals();

inline GcDbGlobals *
GcDbHostApplicationServices::workingGlobals() const
{
  return mpWorkingGlobals ? mpWorkingGlobals : getDefaultGlobals();
}

inline code_page_id
GcDbHostApplicationServices::getSystemCodePage() const
{
  return this->m_eSystemCodePage;
}

inline GcDbTransactionManager *
GcDbHostApplicationServices::workingTransactionManager()
{
  return mpWorkingTransactionManager;
}

inline GcDbDatabase *
GcDbHostApplicationServices::workingDatabase() const
{
  return mpWorkingDatabase;
}

inline GcDbAppSystemVariables *
GcDbHostApplicationServices::workingAppSysvars() const
{
  return mpWorkingAppSysvars;
}

inline void
GcDbHostApplicationServices::setWorkingAppSysvars(GcDbAppSystemVariables* pSysvars)
{
  mpWorkingAppSysvars = pSysvars;
}

inline GcPwdCache *
GcDbHostApplicationServices::getPasswordCache() const
{
  return mpPasswordCache;
}

GCDB_PORT void gcdbTriggerGcadOctTreeReclassification();
GCDB_PORT Gcad::ErrorStatus gcdbSetBreak3dQueueForRegen(bool);

class GSOFT_NO_VTABLE GcDbPasswordedFile
{
protected:
  virtual Gcad::ErrorStatus tryPassword(const wchar_t* wzPassword) = 0;
  virtual const GCHAR* getFullPath() = 0;
public:
  Gcad::ErrorStatus open(const wchar_t* wszPassword, GcDbHostApplicationServices::PasswordOptions options);
};

#pragma pack (pop)

#endif