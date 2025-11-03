

#ifndef ZcDbHostApplicationServices_INC
#define ZcDbHostApplicationServices_INC

#include "zadesk.h"
#include "zacdb.h"
#include "zacarray.h"
#include "zAcString.h"
#include "PAL/api/zcodepgid.h"
#include "zacdlflagbits.h"	

#include "zinetstrc.h"
#include "zrxdlinkr.h"
#include "PAL/api/zproduct_flavors.h"	
#include "PAL/api/zaclocale.h"	
#include <wtypes.h>
#pragma pack (push, 8)

class ZcadInternalServices;
class ZcDbAppSystemVariables;

class ZcDbAuditInfo;
class ZcDbDatabase;
class ZcDbGlobals;
class ZcDbObjectId;
class ZcDbTransactionManager;
class ZcDbUndoController;
class CArchive;
class COleClientItem;
struct flagmat;

class ZcDbAbstractClipBoundaryDefinition;
class ClipBoundaryArray;

class ZcDbPlotSettingsValidator;
class ZcDbLayoutManager;
class ZcPwdCache;

enum  ZcSDIValues {
    kMDIEnabled = 0,
    kSDIUserEnforced,
    kSDIAppEnforced,
    kSDIUserAndAppEnforced
};

int zcdbHostAppMinorVersion();

class ZCDBCORE2D_PORT ZcDbHostApplicationProgressMeter{
public:
    ZcDbHostApplicationProgressMeter();
    virtual ~ZcDbHostApplicationProgressMeter();

    virtual void start(const ZTCHAR * displayString = NULL);
    virtual void stop();
    
    virtual void meterProgress();

    virtual void setLimit(int max);

	virtual int setStatusBarProgressMeterPos(int nPos){ return -1; }	
};

typedef Zcad::ErrorStatus (*SELECTFILEPROC )( short *userCancel, 
                                              ZTCHAR *& chosenPath,
                                             void* h, 
                                             const int nFlags,
                                             const ZTCHAR * prompt,
                                             const ZTCHAR * dir,
                                             const ZTCHAR * name,
                                             const ZTCHAR * type,
                                             int* pnChoice,
                                             bool* pbReadOnly,
                                             const ZTCHAR * pszWSTags,
                                             ZcStringArray* pReserved);		

typedef Zcad::ErrorStatus (* REMAPPROC) ( ZTCHAR *& newName,
                                         const ZTCHAR * filename,
                                         int context,
                                         void* pReserved);

typedef void (* MAPFILENOTIFYPROC) (const ZTCHAR * filename,
                                    const ZTCHAR * newName,
                                    int context,
                                    void* pReserved);

class ZCDBCORE2D_PORT ZSOFT_NO_VTABLE ZcDbHostApplicationServices : public ZcRxObject
{
    friend class ZcadInternalServices;
public:    
    ZCRX_DECLARE_MEMBERS(ZcDbHostApplicationServices);
    ZcDbHostApplicationServices( int createGlobals = 1 );
    virtual ~ZcDbHostApplicationServices();
    enum FindFileHint
    {
        kDefault = 0,
        kFontFile,              
        kCompiledShapeFile,     
        kTrueTypeFontFile,      
        kEmbeddedImageFile,
        kXRefDrawing,
        kPatternFile,
        kZRXApplication,
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

    virtual Zcad::ErrorStatus findFile(ZTCHAR * pcFullPathOut,
                 int   nBufferLength,
                 const ZTCHAR * pcFilename,
                 ZcDbDatabase * pDb = NULL, 
                                            
                 ZcDbHostApplicationServices::FindFileHint hint = kDefault) = 0;
public:
	Zcad::ErrorStatus findFile(ZcString & fileOut,
		const ZTCHAR * pcFilename,
		ZcDbDatabase * pDb = nullptr, 
		ZcDbHostApplicationServices::FindFileHint hint =ZcDbHostApplicationServices::kDefault );	

    virtual Zcad::ErrorStatus getRoamableRootFolder(const ZTCHAR *& folder);
	virtual Zcad::ErrorStatus getLocalRootFolder(const ZTCHAR *& folder);
	virtual Zcad::ErrorStatus getAllUsersRootFolder(const ZTCHAR*& folder);
	virtual Zcad::ErrorStatus getGraphicsCacheFolder(const ZTCHAR *& folder);

    virtual Zcad::ErrorStatus   selectFile(short *userCancel, 
                                           ZTCHAR *& chosenPath,
                                           void* h, 
                                           const int nFlags,
                                           const ZTCHAR * prompt,
                                           const ZTCHAR * dir,
                                           const ZTCHAR * name,
                                           const ZTCHAR * type,
                                           int* pnChoice,
                                           bool* pbReadOnly,
                                           const ZTCHAR * pszWSTags,
                                           ZcStringArray* pReserved) ;	
    virtual Zcad::ErrorStatus   registerSelectFileCallback(const ZTCHAR * appName,
                                                   SELECTFILEPROC proc, 
                                                   bool unRegister = false, 
                                                   bool asPrimary  = false);
    virtual const ZTCHAR *       primaryClientForSelectFileCallback();
    virtual Zcad::ErrorStatus   getRegisteredSelectFileClients(
                                            ZcArray<const ZTCHAR *>& clients);

    virtual Zcad::ErrorStatus   mapFile( ZTCHAR *& newName,
                                        const ZTCHAR * filename,
                                        int context,
                                        void* pReserved);
    virtual Zcad::ErrorStatus   registerMapFileCallback(const ZTCHAR * appName,
                                                REMAPPROC  proc,
                                                bool unRegister = false, 
                                                bool asPrimary  = false);
    virtual const ZTCHAR *       primaryClientForMapFileCallback();
    virtual bool                setMapFlag(bool setIt);
    virtual Zcad::ErrorStatus   getRegisteredFileMapClients(
                                            ZcArray<const ZTCHAR *>& clients);
    virtual Zcad::ErrorStatus   registerMapFileNotification(const ZTCHAR * appName,
                                                MAPFILENOTIFYPROC,
                                                bool unRegister = false);

    virtual void fatalError(const ZTCHAR *format, ...);

    virtual void reportUnhandledZrxException(const ZTCHAR *pExceptionDescription,
                                             const ZTCHAR *pAppName);

    virtual ZSoft::Boolean userBreak(bool updCtrlsWhenEnteringIdle = true) const;

    virtual void displayChar(ZTCHAR c) const;
    virtual void displayString(const ZTCHAR* string, int count) const;

    virtual ZSoft::Boolean readyToDisplayMessages();

    virtual void enableMessageDisplay(ZSoft::Boolean);

    virtual ZSoft::Boolean doFullCRCCheck();

    virtual unsigned int getTempPath(ZSoft::UInt32 lBufferSize, 
                                     ZTCHAR* pcBuffer);
    ZcString getTempPath();	

    virtual const ZTCHAR* getEnv(const ZTCHAR * var);

    virtual ZcDbHostApplicationProgressMeter* newProgressMeter();

    void setWorkingProgressMeter(ZcDbHostApplicationProgressMeter* pNewMeter);

    virtual ZcDbAbstractClipBoundaryDefinition* newClipBoundaryRectangular();
    virtual ZcDbAbstractClipBoundaryDefinition* newClipBoundaryPolygonal();
    virtual ClipBoundaryArray* newClipBoundaryArray();
	

    ZcDbDatabase* workingDatabase() const;
    void setWorkingDatabase(ZcDbDatabase* pDatabase);

    virtual ZcDbUndoController* defaultUndoController();
    void setDefaultUndoController(ZcDbUndoController* pUndoCtrl);

    virtual ZcDbTransactionManager* workingTransactionManager();
    void setWorkingTransactionManager(ZcDbTransactionManager* pTM);

    virtual ZcDbGlobals * createWorkingGlobals();
    ZcDbGlobals * workingGlobals() const;
    void setWorkingGlobals(ZcDbGlobals* pGlobals);
    
    ZcDbAppSystemVariables * workingAppSysvars() const;
    void setWorkingAppSysvars(ZcDbAppSystemVariables* pSysvars);

	virtual const ZTCHAR * program ();
	virtual const ZTCHAR * product ();
	virtual const ZTCHAR * companyName();
	virtual const ProdIdCode prodcode();
	virtual const ZTCHAR * releaseMajorMinorString();
	virtual int   releaseMajorVersion();
	virtual int   releaseMinorVersion();
	virtual const ZTCHAR * versionString();
	virtual const ZTCHAR* getMachineRegistryProductRootKey();
	virtual const ZTCHAR* getUserRegistryProductRootKey();
	virtual const ZTCHAR* releaseMarketVersion();
	virtual ZcLocale  getProductLocale() ;	
	virtual LCID  getRegistryProductLCID();
    virtual bool  supportsMultiRedo() const;
    enum ModelerFlavor {kModelerFull=0, kModelerRegionsOnly=1, kModelerObjectsOnly=2};
    virtual ModelerFlavor  getModelerFlavor() const;

    code_page_id getSystemCodePage() const;

    virtual ZcadInternalServices* zcadInternalServices();
    ZcadInternalServices* zcadInternalServices2()
    {
        return this->zcadInternalServices();
    }

    void * zcadInternalGetvar (const ZTCHAR *name);

    virtual bool isURL(const ZTCHAR * pszURL) const;	

	virtual bool isRemoteFile(const ZTCHAR * pszLocalFile,
                                          ZTCHAR * pszURL, size_t urlLen) const;
	template<size_t N> bool isRemoteFile(const ZTCHAR * pszLocalFile,
		ZTCHAR (&pszURL)[N]) const
	{
		return isRemoteFile(pszLocalFile, pszURL, N);
	}
	bool isRemoteFile(const ZTCHAR * pszLocalFile, ZcString& strUrl);	
	

	virtual Zcad::ErrorStatus getRemoteFile(const ZTCHAR * pszURL, 
		ZTCHAR * pszLocalFile, size_t localFileLen, bool bIgnoreCache) const;

	Zcad::ErrorStatus getRemoteFile(const ZTCHAR * pszURL, ZcString& strLocalFile,
								bool bIgnoreCache = false) const;		
	
	template<size_t N>
	Zcad::ErrorStatus getRemoteFile(const ZTCHAR * pszURL, ZTCHAR(&pszLocalFile)[N]) const
	{
		return this->getRemoteFile(pszURL, pszLocalFile, N, false);
	}

    virtual Zcad::ErrorStatus putRemoteFile(const ZTCHAR * pszURL,
        const ZTCHAR * pszLocalFile) const;

    virtual ZSoft::Boolean launchBrowserDialog(
                 ZTCHAR *          pszSelectedURL,
				 size_t            selectedUrlLen,
                 const ZTCHAR *    pszDialogTitle,
                 const ZTCHAR *    pszOpenButtonCaption,
                 const ZTCHAR *    pszStartURL,
                 const ZTCHAR *    pszRegistryRootKey = 0,
                 ZSoft::Boolean bOpenButtonAlwaysEnabled = ZSoft::kFalse) const;
	template<size_t N> ZSoft::Boolean launchBrowserDialog(
		ZTCHAR          (&pszSelectedURL)[N],
		const ZTCHAR*    pszDialogTitle,
		const ZTCHAR*    pszOpenButtonCaption,
		const ZTCHAR*    pszStartURL, 
		const ZTCHAR*    pszRegistryRootKey = 0,
		ZSoft::Boolean bOpenButtonAlwaysEnabled = ZSoft::kFalse) const
	{
		return launchBrowserDialog(pszSelectedURL,N,pszDialogTitle,
			pszOpenButtonCaption,pszStartURL,
			pszRegistryRootKey,bOpenButtonAlwaysEnabled);
	}
    virtual void drawOleOwnerDrawItem(COleClientItem* pItem,
                                      ZSoft::LongPtr hdc,
        ZSoft::Int32 left,  ZSoft::Int32 top,  ZSoft::Int32 right,  ZSoft::Int32 bottom);

    virtual Zcad::ErrorStatus getNewOleClientItem(COleClientItem*& pItem);

    virtual Zcad::ErrorStatus serializeOleItem(COleClientItem* pItem,
        CArchive*);

    virtual ZSoft::Boolean _entToWorldTransform(double normal[3], 
                                                flagmat *tran);

    virtual void terminateScript();
    virtual ZSoft::Boolean getSubstituteFont(ZTCHAR **pFileName,
                                             const ZTCHAR *prompt,
                                             int type, int fontAlt); 
	virtual ZSoft::Boolean getSubstituteFont(ZTCHAR **pFileName,
											ZTCHAR *prompt,
											int type, int fontAlt) final
	{
		const ZTCHAR* pConstPrompt = prompt;
		return this->getSubstituteFont(pFileName, pConstPrompt, type, fontAlt);
	}
    virtual void alert(const ZTCHAR * string) const;

    virtual void auditPrintReport(ZcDbAuditInfo * pAuditInfo,
                                             const ZTCHAR *    line,
                                             int             both) const;

    virtual const ZTCHAR * getAlternateFontName() const;

    virtual const ZTCHAR * getFontMapFileName() const;

    virtual bool cacheSymbolIndices() const;

    virtual ZcDbPlotSettingsValidator* plotSettingsValidator() const; 
    virtual ZcDbLayoutManager* layoutManager() const;
    virtual bool loadApp(const ZTCHAR * appName,
                         ZcadApp::LoadReasons why, 
                         bool printit, 
                         bool asCmd);
	
	void getDefaultPlotCfgInfo(ZcString& devName, ZcString& styleName);	

    virtual Zcad::ErrorStatus signingComplete(Zcad::ErrorStatus es,
                                              const ZTCHAR * msg,
                                              bool* result);

	enum PasswordOptions {kPasswordOptionDefault = 0, kPasswordOptionUpperCase =1, kPasswordOptionIsExternalReference = 2};
	virtual bool getPassword(const ZTCHAR* dwgName,
                             PasswordOptions options,
                             wchar_t *password, 
                             const size_t bufSize);

	bool getPassword(const ZTCHAR * dwgName,
		ZcDbHostApplicationServices::PasswordOptions options,
		ZcString& password);	

    virtual void usedPasswordFromCacheMsg(const ZTCHAR *dwgName);
    virtual void missingCryptoProviderMsg();

    virtual const ZTCHAR * getColorBookLocation() const;

    ZcPwdCache * getPasswordCache() const;
	virtual short getKeyState(int nVirtKey) const;

	enum RequiredVersionFlags 
	{
		kNoOpen       = 0,
		kReadOnly     = 1,
		kWriteAllowed = 2
	};
	virtual bool requiredVersionNotAvailable(ZcDbHostApplicationServices::RequiredVersionFlags flags,
		ZcDbDatabase* pDb)const;

	virtual bool notifyCorruptDrawingFoundOnOpen(ZcDbObjectId id, Zcad::ErrorStatus es);/* { return false; }*/  

protected:

    Zcad::ErrorStatus mapInetStatusToZcadStatus(
        const ZcadInet::Status status) const;

protected:

    void * mp_sessionVars = nullptr;

    void zcadInternalSetvar (const ZTCHAR *name, void * var);

private:

    ZcDbDatabase* mpWorkingDatabase = nullptr;
    ZcDbUndoController* mpDefaultUndoController = nullptr;
    ZcDbTransactionManager* mpWorkingTransactionManager = nullptr;
    ZcDbGlobals * mpWorkingGlobals = nullptr;
    ZcDbAppSystemVariables * mpWorkingAppSysvars = nullptr;

    code_page_id m_eSystemCodePage = code_page_id::CODE_PAGE_UNDEFINED;

    bool mbDisplayMessages = true;

    ZcPwdCache * mpPasswordCache = nullptr;
};

ZCDBCORE2D_PORT Zcad::ErrorStatus zcdbSetHostApplicationServices(ZcDbHostApplicationServices * pServices);

ZCDBCORE2D_PORT ZcDbHostApplicationServices* zcdbHostApplicationServices();

ZCDBCORE2D_PORT Zcad::ErrorStatus zcdbSendInitialDwgFileOpenComplete(ZcDbDatabase* pDb);
ZCDBCORE2D_PORT ZcDbGlobals* getDefaultGlobals();

inline ZcDbGlobals *
ZcDbHostApplicationServices::workingGlobals() const
{
    return mpWorkingGlobals ? mpWorkingGlobals : getDefaultGlobals();
}

inline code_page_id
ZcDbHostApplicationServices::getSystemCodePage() const
{
    return this->m_eSystemCodePage;
}

inline ZcDbTransactionManager *
ZcDbHostApplicationServices::workingTransactionManager()
{
    return mpWorkingTransactionManager;
}

inline ZcDbDatabase *
ZcDbHostApplicationServices::workingDatabase() const
{
    return mpWorkingDatabase;
}

inline ZcDbAppSystemVariables * 
ZcDbHostApplicationServices::workingAppSysvars() const
{
    return mpWorkingAppSysvars;
}

inline void 
ZcDbHostApplicationServices::setWorkingAppSysvars(ZcDbAppSystemVariables* pSysvars)
{
    mpWorkingAppSysvars = pSysvars;
}

inline ZcPwdCache * 
ZcDbHostApplicationServices::getPasswordCache() const
{
    return mpPasswordCache;
}

void zcdbTriggerZcadOctTreeReclassification();

Zcad::ErrorStatus zcdbSetBreak3dQueueForRegen(bool);

class ZCDBCORE2D_PORT ZSOFT_NO_VTABLE ZcDbPasswordedFile
{
protected:
    virtual Zcad::ErrorStatus tryPassword(const wchar_t* wzPassword) = 0;
    virtual const ZTCHAR* getFullPath() = 0;
public:
    Zcad::ErrorStatus open(const wchar_t* wszPassword, ZcDbHostApplicationServices::PasswordOptions options);
};

#pragma pack (pop)

#endif


