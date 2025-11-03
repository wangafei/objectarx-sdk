/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#include "GdGChar.h"

#pragma once

#ifdef  _GCTC_BUILD
#  define   GCTC_PORT  __declspec(dllexport)
#else
#  define   GCTC_PORT  
#endif

class GcTcTool;
class GcTcStockTool;
class GcTcCatalog;
class GcTcCatalogItem;
class GcTcScheme;
class GcTcCatalogSet;
class GcTcSystemInternals;
class GcTcImpCatalogItem;
class GcTcCatalogItemReactor;

#define GCTC_IMAGE_NORMAL                   (0x1 << 0)
#define GCTC_IMAGE_SELECTED                 (0x1 << 1)
#define GCTC_IMAGE_HALO                     (0x1 << 2)
#define GCTC_IMAGE_SHADOW                   (0x1 << 3)

#define GCTC_MAX_CATALOG_ITEM_NAME          256
#define GCTC_MAX_CATALOG_ITEM_DESCRIPTION   2048
#define GCTC_MAX_CATALOG_ITEM_KEYWORDS      1024
#define GCTC_MAX_CATALOG_ITEM_TOOLTIP_TEXT  1024
#define GCTC_MAX_CATALOG_ITEM_LINK_NAME     256
#define GCTC_MAX_SCHEME_NAME                256
#define GCTC_MAX_TOOL_NAME                  GCTC_MAX_CATALOG_ITEM_NAME
#define GCTC_MAX_STOCKTOOL_NAME             GCTC_MAX_CATALOG_ITEM_NAME
#define GCTC_MAX_PALETTE_NAME               GCTC_MAX_CATALOG_ITEM_NAME
#define GCTC_MAX_PACKAGE_NAME               GCTC_MAX_CATALOG_ITEM_NAME
#define GCTC_MAX_CATEGORY_NAME              GCTC_MAX_CATALOG_ITEM_NAME
#define GCTC_MAX_CATALOG_NAME               GCTC_MAX_CATALOG_ITEM_NAME
#define GCTC_MAX_URL                        1024
#define GCTC_MAX_PATH                       MAX_PATH
#define GCTC_MAX_COMMAND_NAME               256
#define GCTC_MAX_COMMAND_ARGS               1024
#define GCTC_MAX_HELPINFO_FILE              GCTC_MAX_URL
#define GCTC_MAX_HELPINFO_COMMAND           256
#define GCTC_MAX_HELPINFO_DATA              GCTC_MAX_URL
#define GCTC_MAX_PARENT_DOCUMENT_NAME       256
#define GCTC_MAX_PUBLISHER_NAME             256
#define GCTC_MAX_PRODUCT_NAME               256
#define GCTC_MAX_LOCALE                     512


#define GCTC_POSTDOWNLOADCMD_EXECUTE        GCRX_T("Execute")

#define GCTC_DEFAULTDIR_IMAGE               GCRX_T("Images")
#define GCTC_DEFAULTFILE_IMAGE              GCRX_T("Image")

namespace GcTc
{
  enum AccessRight
  {
    kAccessRead = (0x1 << 0),
    kAccessReadWrite = (0x1 << 1),
    kAccessReadOnlyFile = (0x1 << 2),
    kAccessMultiple = (0x1 << 3),
    kAccessNewerVersion = (0x1 << 4),
  };

  enum CatalogItemType
  {
    kItemUnknown = 0,
    kItemTool = (0x1 << 0),
    kItemPackage = (0x1 << 1),
    kItemPalette = (0x1 << 2),
    kItemCategory = (0x1 << 3),
    kItemCatalog = (0x1 << 4),
    kItemStockTool = (0x1 << 5),
  };

  enum ReferencePath
  {
    kLoadRefPath = 1,
    kSaveRefPath = 2,
  };

  enum ImageType
  {
    kImageTypeUninitialized = -1,
    kImageTypeBitmap = 1,
    kImageTypeMetaFile = 2,
    kImageTypeIcon = 3,
    kImageTypeEnhMetaFile = 4,
    kImageTypeJpeg = 5,
    kImageTypePng = 6,
    kImageTypeGif = 7,
    kImageTypeTif = 8
  };

  enum ImageOption
  {
    kImageOptionNone = 0x0,
    kImageOptionRenderBitmapOpaque = (0x1 << 0),
    kImageOptionUserOverride = (0x1 << 1),
  };

  enum LoadOption
  {
    kLoadLinks = (0x1 << 0),
    kLoadImages = (0x1 << 1),
    kLoadOverlayImages = (0x1 << 2),
    kDoNotNotifyReactor = (0x1 << 3),
  };

  enum SaveOption
  {
    kSaveLinksAsLinks = (0x1 << 0),
    kSaveLinksAsEmbedded = (0x1 << 1),
    kSaveImages = (0x1 << 2),
    kSaveAs = (0x1 << 3),
    kSaveOverlayImages = (0x1 << 4),
    kSaveAnsi = (0x1 << 5),
  };

  enum DownloadOption
  {
    kDownloadItem = (0x1 << 0),
    kDownloadLinkedItem = (0x1 << 1),
    kDownloadImage = (0x1 << 2),
    kDownloadStockTool = (0x1 << 3),
    kDownloadChildren = (0x1 << 4),
    kDownloadAll = kDownloadItem | kDownloadLinkedItem |
    kDownloadImage | kDownloadStockTool |
    kDownloadChildren,
    kDownloadCleanDownloadDir = (0x1 << 5),
    kDownloadShowProgress = (0x1 << 6),
    kDownloadUseNewIds = (0x1 << 7),
    kDownloadNotifyTool = (0x1 << 12)
  };

  enum RefreshOption
  {
    kRefreshItem = kDownloadItem,
    kRefreshLinkedItem = kDownloadLinkedItem,
    kRefreshImage = kDownloadImage,
    kRefreshStockTool = kDownloadStockTool,
    kRefreshChildren = kDownloadChildren,
    kRefreshAll = kDownloadAll,
    kRefreshShowProgress = kDownloadShowProgress,
    kRefreshNotifyTool = (0x1 << 16)
  };

  enum CatalogType
  {
    kCatalog = (0x1 << 0),
    kStockToolCatalog = (0x1 << 1),
    kShapeCatalog = (0x1 << 2)
  };

  enum ToolType
  {
    kToolNormal = 1,
    kToolFlyout = 2,
    kToolText = 3,
    kToolSeparator = 4,
  };

  enum SortOption
  {
    kSortByName = (0x1 << 0),
    kSortByStockTool = (0x1 << 1),
    kSortByCustom = (0x1 << 2),
    kAscending = (0x1 << 3),
    kDescending = (0x1 << 4),
  };

  enum ItemOption
  {
    kItemOptionNone = 0x0,
    kItemOptionSupportsAutoImage = (0x1 << 0),
    kItemOptionSupportsUserImage = (0x1 << 1),
    kItemOptionMenuUpdateImage = (0x1 << 2),
    kItemOptionMenuSetImage = (0x1 << 3),
    kItemOptionMenuRemoveImage = (0x1 << 4),
  };
};

using namespace GcTc;

struct GCTC_IMAGE_INFO
{
  SIZE                mSize;
  GCHAR               mszResourceName[MAX_PATH];
  GCHAR               mszSourceFile[MAX_PATH];
};

struct GCTC_TARGET_PRODUCT_INFO
{
  GCHAR               mszProductName[GCTC_MAX_PRODUCT_NAME];
  GCHAR               mszLocaleIds[GCTC_MAX_LOCALE];
  DWORD               mdwMinVersion;
  DWORD               mdwMaxVersion;
};

class GCTC_PORT GcTcImage
{
public:
  GcTcImage();
  GcTcImage(const GcTcImage& srcImage);
  virtual ~GcTcImage();

  GcTcImage&          operator=           (const GcTcImage& gcTcImage);
  BOOL                Load(LPCTSTR pszFile);
  BOOL                Load(HBITMAP hBitmap);
  BOOL                Load(IStream* pStream);
  BOOL                Save(LPCTSTR pszFile);
  BOOL                Save(LPCTSTR sFileName,
    GcTc::ImageType nSaveAsType);
  BOOL                Save(IStream* pStream);
  BOOL                Render(HDC hDC,
    int xPos,
    int yPos,
    int nWidth,
    int nHeight,
    UINT nStyle = GCTC_IMAGE_NORMAL,
    BOOL bTransparentBitmap = TRUE);
  BOOL                GetSize(LPSIZE pSize) const;
  GcTc::ImageType     GetType(void) const;
  BOOL                IsImageLoaded(void) const;
  BOOL                GetHICON(HICON &hIcon);
  BOOL                GetHBITMAP(COLORREF cBackGroundColor,
    HBITMAP& hBitmap);
  GcTc::ImageType     GetSaveType(void) const;
  BOOL                SetSaveType(GcTc::ImageType nSaveType);
  BOOL                ConvertTo(GcTc::ImageType nToImageType,
    BOOL bTransparent);
  BOOL                IsForDarkTheme(void) const;
  void                SetIsForDarkTheme(BOOL bValue);

protected:
  void            *   mpImpObj;
private:
  friend class GcTcSystemInternals;
};

class GCTC_PORT GcTcImageList
{
  friend class GcTcImpCatalogItem;
public:
  virtual ~GcTcImageList();

  GcTcImageList&      operator=           (const GcTcImageList& gcTcImageList);
  INT_PTR             GetImageCount(void) const;
  BOOL                GetImageInfo(INT_PTR iIndex,
    GCTC_IMAGE_INFO* pImageInfo,
    BOOL bUseDarkTheme = FALSE) const;
  BOOL                GetEditImageInfo(INT_PTR iIndex,
    GCTC_IMAGE_INFO* pImageInfo,
    BOOL bUseDarkTheme = FALSE);
  BOOL                SetImageInfo(INT_PTR iIndex,
    const GCTC_IMAGE_INFO* pImageInfo,
    BOOL bUseDarkTheme = FALSE);
  GcTcImage*          GetImage(INT_PTR iIndex, BOOL bUseDarkTheme = FALSE);
  INT_PTR             SetImage(INT_PTR iIndex,
    const GcTcImage* pImage,
    BOOL bUseDarkTheme = FALSE);
  INT_PTR             Add(const GcTcImage* pImage, BOOL bUseDarkTheme = FALSE);
  INT_PTR             Add(const GCTC_IMAGE_INFO* pImageInfo);
  INT_PTR             UpdateImage(const GcTcImage* pImage, BOOL bUseDarkTheme = FALSE);
  BOOL                Delete(INT_PTR iIndex);
  BOOL                DeleteAllImages(void);
  BOOL                LoadImage(INT_PTR iIndex, BOOL bUseDarkTheme = FALSE);
  INT_PTR             GetImageIndex(const SIZE* pSize,
    BOOL bExactMatch = FALSE,
    BOOL bUseDarkTheme = FALSE);
  GcTc::ImageOption   GetOption(void) const;
  BOOL                SetOption(GcTc::ImageOption nOption);

protected:
  GcTcImageList(GcTcCatalogItem* pCatalogItem);
  void            *   mpImpObj;
private:
  friend class GcTcSystemInternals;
};

class GCTC_PORT GcTcManager
{
public:
  GcTcManager();
  virtual ~GcTcManager();

  INT_PTR             GetStockToolCatalogCount(void) const;
  GcTcCatalogItem *   GetStockToolCatalog(int nIndex) const;
  GcTcStockTool   *   FindStockTool(const GUID& id) const;

  INT_PTR             GetCatalogCount(void) const;
  GcTcCatalogItem *   GetCatalog(int nIndex) const;
  GcTcCatalogItem *   FindItem(const GUID& id) const;

  int                 GetCatalogPath(LPTSTR pszString,
    int cchSize) const;
  BOOL                SetCatalogPath(LPCTSTR pszPath);
  int                 GetStockToolCatalogPath(LPTSTR pszString,
    int cchSize) const;
  BOOL                SetStockToolCatalogPath(LPCTSTR pszPath);
  int                 GetShapeCatalogFile(LPTSTR pszString,
    int cchSize) const;
  BOOL                SetShapeCatalogFile(LPCTSTR pszFile);
  INT_PTR             AddStockToolCatalog(GcTcCatalogItem* pCatalogItem);
  INT_PTR             AddCatalog(GcTcCatalogItem* pCatalogItem);
  BOOL                LoadCatalogs(DWORD dwCatalogType = kCatalog | kStockToolCatalog,
    DWORD dwLoadOption = kLoadLinks);
  BOOL                UnloadCatalogs(DWORD dwCatalogType = kCatalog | kStockToolCatalog);
  BOOL                SaveCatalogs(DWORD dwCatalogType = kCatalog | kStockToolCatalog,
    DWORD dwSaveOption = kSaveLinksAsLinks);
  GcTcCatalogItem*    GetShapeCatalog(void);
  GcTcCatalogItem *   GetShapePackage(LPCTSTR lpszName = NULL) const;
  INT_PTR             InsertStockToolCatalog(INT_PTR nIndex,
    GcTcCatalogItem* pCatalog);
  GcTcCatalogItem*    RemoveStockToolCatalog(int nIndex);

  INT_PTR             GetSchemeCount(void) const;
  GcTcScheme      *   GetScheme(int nIndex) const;
  GcTcScheme      *   GetScheme(LPCTSTR pszSchemeName) const;
  INT_PTR             AddScheme(GcTcScheme* pScheme);
  BOOL                RemoveScheme(GcTcScheme* pScheme);

protected:
  void            *   mpImpObj;
private:
  friend class GcTcSystemInternals;
};

class GCTC_PORT GcTcScheme
{
public:
  GcTcScheme(LPCTSTR pszSchemeName);
  virtual ~GcTcScheme();

  int                 GetName(LPTSTR pszString,
    int cchSize) const;
  BOOL                SetName(LPCTSTR pszString);

  GcTcCatalogSet  *   GetCatalogSet(DWORD dwCatalogType) const;

  GcTcCatalogItem *   FindItem(const GUID& id) const;
  GcTcCatalogItem *   FindItem(const GUID& id,
    DWORD dwCatalogType) const;

  BOOL                LoadCatalogs(void);
  BOOL                LoadCatalogs(DWORD dwCatalogType,
    DWORD dwLoadOption);
  BOOL                UnloadCatalogs(void);
  BOOL                UnloadCatalogs(DWORD dwCatalogType);
  BOOL                SaveCatalogs(void);
  BOOL                SaveCatalogs(DWORD dwCatalogType,
    DWORD dwSaveOption);

protected:
  void            *   mpImpObj;
private:
  friend class GcTcSystemInternals;
};

class GCTC_PORT GcTcCatalogSet
{
public:
  virtual ~GcTcCatalogSet();

  GcTcScheme      *   GetScheme(void) const;

  INT_PTR             GetCatalogCount(void) const;
  GcTcCatalogItem *   GetCatalog(int nIndex) const;

  GcTcCatalogItem *   FindItem(const GUID& id) const;

  int                 GetCatalogPath(LPTSTR pszString,
    int cchSize) const;
  BOOL                SetCatalogPath(LPCTSTR pszPath);

  INT_PTR             AddCatalog(GcTcCatalogItem* pCatalog);
  INT_PTR             InsertCatalog(INT_PTR nIndex,
    GcTcCatalogItem* pCatalog);
  GcTcCatalogItem*    RemoveCatalog(int nIndex);

  BOOL                LoadCatalogs(void);
  BOOL                LoadCatalogs(DWORD dwLoadOption);
  BOOL                UnloadCatalogs(void);
  BOOL                SaveCatalogs(void);
  BOOL                SaveCatalogs(DWORD dwSaveOption);

protected:
  GcTcCatalogSet(DWORD dwCatalogType);
protected:
  void            *   mpImpObj;
private:
  friend class GcTcSystemInternals;
};

class GCTC_PORT GcTcCatalogItem
{
  friend class GcTcImpCatalogItem;

public:
  static GcTcCatalogItem * FromFile(LPCTSTR pszFile,
    BOOL bLoad = FALSE,
    DWORD dwLoadOption = kLoadLinks);
  static CatalogItemType   GetType(LPCTSTR pszFile);

public:
  virtual ~GcTcCatalogItem();

  BOOL                Load(LPCTSTR pszUrl,
    DWORD dwLoadOption = kLoadLinks);
  BOOL                LoadLink(void);
  BOOL                Save(LPCTSTR pszUrl,
    DWORD dwSaveOption = kSaveLinksAsLinks);
  INT_PTR             AddChild(GcTcCatalogItem* pNewItem);
  INT_PTR             InsertChild(INT_PTR iIndex,
    GcTcCatalogItem* pNewItem);
  BOOL                DeleteChild(GcTcCatalogItem* pItem);
  BOOL                DetachChild(GcTcCatalogItem* pItem);
  INT_PTR             GetChildCount(void) const;
  INT_PTR             GetChildCount(CatalogItemType nType) const;
  GcTcCatalogItem *   GetChild(INT_PTR iIndex) const;
  GcTcCatalogItem *   GetNextChild(int iIndex,
    CatalogItemType nType) const;
  BOOL                DeleteAllChildren(void);
  BOOL                HasChildren(void) const;

  BOOL                GetID(GUID* pId) const;
  BOOL                SetID(const GUID* pId);
  GcTc::AccessRight   GetAccessRight(void) const;
  BOOL                SetAccessRight(GcTc::AccessRight nAccessRight);
  BOOL                IsReadOnly(void) const;
  int                 GetName(LPTSTR pszString,
    int cchSize) const;
  BOOL                SetName(LPCTSTR pszString);
  int                 GetDescription(LPTSTR pszString,
    int cchSize) const;
  BOOL                SetDescription(LPCTSTR pszString);
  int                 GetToolTipText(LPTSTR pszString,
    int cchSize) const;
  BOOL                SetToolTipText(LPCTSTR pszString);
  INT_PTR             GetImageFilePath(INT_PTR iIndex,
    LPTSTR pszString,
    size_t cchSize) const;
  BOOL                GetHelpInfo(LPTSTR pszFile,
    LPTSTR pszCommand,
    LPTSTR pszData) const;
  BOOL                SetHelpInfo(LPCTSTR pszFile,
    LPCTSTR pszCommand,
    LPCTSTR pszData);
  int                 GetKeywords(LPTSTR pszString,
    int cchSize) const;
  BOOL                SetKeywords(LPCTSTR pszString);
  int                 GetLinkUrl(LPTSTR pszString,
    int cchSize) const;
  BOOL                SetLinkUrl(LPCTSTR pszString);
  int                 GetSourceUrl(LPTSTR pszString,
    int cchSize) const;
  BOOL                SetSourceUrl(LPCTSTR pszString);
  int                 GetParentDocumentName(LPTSTR pszString,
    int cchSize) const;
  BOOL                SetParentDocumentName(LPCTSTR pszString);
  int                 GetParentDocumentDescription(LPTSTR pszString,
    int cchSize) const;
  BOOL                SetParentDocumentDescription(LPCTSTR pszString);
  int                 GetParentDocumentUrl(LPTSTR pszString,
    int cchSize) const;
  BOOL                SetParentDocumentUrl(LPCTSTR pszString);
  int                 GetPublisherName(LPTSTR pszString,
    int cchSize) const;
  BOOL                SetPublisherName(LPCTSTR pszString);
  int                 GetPublisherDescription(LPTSTR pszString,
    int cchSize) const;
  BOOL                SetPublisherDescription(LPCTSTR pszString);
  int                 GetPublisherCountry(LPTSTR pszString,
    int cchSize) const;
  BOOL                SetPublisherCountry(LPCTSTR pszString);
  int                 GetPublisherEmail(LPTSTR pszString,
    int cchSize) const;
  BOOL                SetPublisherEmail(LPCTSTR pszString);
  int                 GetPublisherUrl(LPTSTR pszString,
    int cchSize) const;
  BOOL                SetPublisherUrl(LPCTSTR pszString);
  int                 GetUrl(LPTSTR pszString,
    int cchSize) const;
  int                 GetLocalFile(LPTSTR pszString,
    int cchSize) const;
  GcTcCatalogItem *   GetRoot(void) const;
  GcTcScheme      *   GetScheme(void) const;
  GcTcCatalogItem *   GetParent(void) const;
  BOOL                SetParent(GcTcCatalogItem* pParent);
  BOOL                IsRoot(void) const;
  BOOL                IsLink(void) const;
  BOOL                IsLinkLoaded(void) const;
  GcTcImageList   *   GetImageList(void) const;
  GcTcImage       *   GetImage(const SIZE* pSize, BOOL bUseDarkTheme = FALSE);
  int                 GetXml(LPTSTR pszString,
    int cchSize,
    DWORD dwSaveOption = kSaveLinksAsLinks);
  virtual GcTcCatalogItem* FindInChildren(const GUID& id,
    BOOL bRecursive = TRUE);
  GcTcCatalogItem *   FindInChildren(LPCTSTR pszName);
  GcTcCatalogItem *   FindInChildren(LPCTSTR pszName,
    BOOL bRecursive);
  BOOL                GetTime(time_t* pCreated,
    time_t* pLastModified,
    time_t* pLastRefreshed) const;
  BOOL                SetTime(const time_t* pCreated,
    const time_t* pLastModified,
    const time_t* pLastRefreshed);
  BOOL                CanRefresh(void) const;
  BOOL                SetRefresh(BOOL bRefresh);
  BOOL                GetRefresh(void) const;
  virtual BOOL        Refresh(DWORD dwRefreshFlag = kRefreshAll);
  virtual BOOL        Download(LPCTSTR pszUrl,
    DWORD dwDownloadFlag = kDownloadAll,
    LPCTSTR pszDownloadPath = NULL);
  BOOL                SetAutoRefresh(BOOL bAutoRefresh);
  BOOL                GetAutoRefresh(void) const;
  int                 GetReferencePath(LPTSTR pszString,
    int cchSize,
    int nFlag) const;
  BOOL                SetReferencePath(LPCTSTR pszString,
    int nFlag);
  BOOL                GetCustomData(IUnknown** ppCustomData);
  BOOL                SetNewID(BOOL bRecursive = FALSE);
  BOOL                DeleteImageFile(BOOL bRecursive = FALSE);
  int                 GetLinkFilePath(LPTSTR pszString,
    int cchSize) const;
  BOOL                DeleteLinkFile(BOOL bRecursive = FALSE);
  BOOL                GetSourceID(GUID* pId) const;
  BOOL                SetSourceID(const GUID* pId);
  GcTcImage       *   GetOverlayImage(BOOL bUseDarkTheme = FALSE) const;
  BOOL                SetOverlayImage(const GcTcImage* pImage, BOOL bUseDarkTheme = FALSE);
  BOOL                GetOverlayImageInfo(GCTC_IMAGE_INFO* pImageInfo, BOOL bUseDarkTheme = FALSE) const;
  BOOL                SetOverlayImageInfo(const GCTC_IMAGE_INFO* pImageInfo);
  INT_PTR             GetOverlayImageFilePath(LPTSTR pszString,
    size_t cchSize,
    BOOL bUseDarkTheme = FALSE) const;
  BOOL                DeleteOverlayImageFile(BOOL bRecursive = FALSE);
  INT_PTR             GetTargetProductCount(void) const;
  BOOL                GetTargetProduct(INT_PTR iIndex,
    GCTC_TARGET_PRODUCT_INFO* pProductInfo) const;
  INT_PTR             AddTargetProduct(const GCTC_TARGET_PRODUCT_INFO* pProductInfo);
  BOOL                DeleteTargetProduct(int iIndex);
  BOOL                IsValidForProduct(LPCTSTR pszProductName,
    int nMajorVersion,
    int nMinorVersion,
    DWORD dwLocaleId = 0);
  BOOL                AddReactor(GcTcCatalogItemReactor* pReactor);
  BOOL                RemoveReactor(GcTcCatalogItemReactor* pReactor);
  BOOL                Sort(int nSortOption,
    BOOL bRecursive);
  BOOL                SetItemOrder(GcTcCatalogItem** pItems,
    INT_PTR nNumItems);
  GcTc::ItemOption    GetOption(void) const;
  BOOL                SetOption(GcTc::ItemOption nOption);
  BOOL                GetFileRevision(long& lMajorVersion,
    long& lMinorVersion) const;
  BOOL                GetRevision(long& lMajorVersion,
    long& lMinorVersion,
    long& lUserVersion) const;
  BOOL                IsUserModified(void) const;

public:
  virtual GcTcCatalogItem&    operator=   (const GcTcCatalogItem& srcItem);
  virtual BOOL        Reset(void);

  virtual CatalogItemType GetType(void) const;
  virtual int         GetTypeString(LPTSTR pszString,
    int cchSize,
    BOOL bLocalized = FALSE,
    BOOL bPluralForm = FALSE) const;
  virtual int         GetTagName(LPTSTR pszString,
    int cchSize) const;

  virtual BOOL        Load(IUnknown* pUnknown,
    DWORD dwLoadOption = kLoadLinks);
  virtual BOOL        Load(IStream* pStream,
    DWORD dwLoadOption = kLoadLinks);
  virtual BOOL        Save(IUnknown* pUnknown,
    DWORD dwSaveOption = kSaveLinksAsLinks);
  virtual BOOL        Save(IStream* pStream,
    DWORD dwSaveOption = kSaveLinksAsLinks);
  virtual BOOL        Clone(BOOL bDeep,
    GcTcCatalogItem*& pClone,
    BOOL bCopyId = FALSE) const;
  virtual BOOL        CopyFrom(const GcTcCatalogItem* pSrcItem,
    BOOL bCopyId = FALSE);
  virtual BOOL        IsValidChild(const CatalogItemType nType) const;

protected:
  virtual GcTcCatalogItem * CreateObject(void) const;
protected:
  GcTcCatalogItem(GcTcSystemInternals*);

protected:
  void            *   mpImpObj;
private:
  friend class GcTcSystemInternals;
};

class GCTC_PORT GcTcCategory : public GcTcCatalogItem
{
public:
  GcTcCategory();
  GcTcCategory(const GcTcCategory& srcItem);
  ~GcTcCategory();

protected:
  GcTcCategory(GcTcSystemInternals*);
};

class GCTC_PORT GcTcCatalog : public GcTcCategory
{
public:
  GcTcCatalog();
  GcTcCatalog(const GcTcCatalog& srcItem);
  ~GcTcCatalog();

protected:
  GcTcCatalog(GcTcSystemInternals*);
};

class GCTC_PORT GcTcStockTool : public GcTcCatalogItem
{
public:
  GcTcStockTool();
  GcTcStockTool(const GcTcStockTool& srcItem);
  ~GcTcStockTool();

  GcTcTool        *   CreateTool(BOOL bSetDefaults = TRUE);
  BOOL                CreateGcadStockTool(IUnknown** ppStockTool);
  BOOL                CreateGcadTool(IUnknown** ppUnknown);
  BOOL                GetComClassID(CLSID& clsid) const;
  BOOL                SetComClassID(const  CLSID& clsid);
  int                 GetModuleFileName(LPTSTR pszString,
    int cchSize) const;
  BOOL                SetModuleFileName(LPCTSTR pszString);
  int                 GetModuleInstallUrl(LPTSTR pszString,
    int cchSize) const;
  BOOL                SetModuleInstallUrl(LPCTSTR pszString);
  int                 GetModuleInstallArguments(LPTSTR pszString,
    int cchSize) const;
  BOOL                SetModuleInstallArguments(LPCTSTR pszString);

protected:
  GcTcStockTool(GcTcSystemInternals*);
private:
  friend class GcTcSystemInternals;
};

class  GCTC_PORT GcTcTool : public GcTcCatalogItem
{
public:
  GcTcTool();
  GcTcTool(const GcTcTool& srcItem);
  ~GcTcTool();

  virtual BOOL        Execute(int nFlag,
    HWND hWnd,
    POINT point,
    DWORD dwKeyState);
  BOOL                GetToolData(IUnknown** ppUnknown);
  GcTcStockTool *     GetStockTool(void) const;
  BOOL                CreateGcadTool(IUnknown** ppTool,
    BOOL bLoadData = TRUE);
  BOOL                GetStockToolID(GUID* pId) const;
  BOOL                SetStockToolID(const GUID* pId);
  int                 GetStockToolFileUrl(LPTSTR pszString,
    int cchSize) const;
  BOOL                SetStockToolFileUrl(LPCTSTR pszString);
  ToolType            GetToolType(void) const;
  BOOL                SetToolType(ToolType nToolType);
  BOOL                IsFlyoutEnabled(void) const;
  BOOL                EnableFlyout(BOOL bUseFlyout);
  GcTcCatalogItem*    GetShapePackage(void) const;
  BOOL                SetShapePackage(GcTcCatalogItem* pPackage);
  GcTcTool*           GetCurrentShape(void) const;
  BOOL                SetCurrentShape(GcTcTool* pTool);
  BOOL                SetCurrentShape(const GUID& id);
  BOOL                GetActiveShapes(GcTcCatalogItem** pItems,
    INT_PTR & nNumItems);
  BOOL                SetActiveShapes(GcTcCatalogItem** pItems,
    int nNumItems);
protected:
  GcTcTool(GcTcSystemInternals*);
};

class GCTC_PORT GcTcPackage : public GcTcCatalogItem
{
public:
  GcTcPackage();
  GcTcPackage(const GcTcPackage& srcItem);
  ~GcTcPackage();

protected:
  GcTcPackage(GcTcSystemInternals*);
};

class GCTC_PORT GcTcPalette : public GcTcPackage
{
public:
  GcTcPalette();
  GcTcPalette(const GcTcPalette& srcItem);
  ~GcTcPalette();

protected:
  GcTcPalette(GcTcSystemInternals*);
};

class GCTC_PORT GcTcCatalogItemReactor
{
public:
  virtual ~GcTcCatalogItemReactor(void);

  BOOL                Enable(BOOL bEnable);
  BOOL                IsEnabled(void) const;

  virtual void        ChildAdded(GcTcCatalogItem* pChild);
  virtual void        ChildDeleted(GcTcCatalogItem* pChild);
  virtual void        ChildDetached(GcTcCatalogItem* pChild);

protected:
  void            *   mpImpObj;
protected:
  GcTcCatalogItemReactor();
private:
  friend class GcTcSystemInternals;
};

GCTC_PORT BOOL GcTcInitialize(void);
GCTC_PORT BOOL GcTcUninitialize(void);
GCTC_PORT GcTcManager* GcTcGetManager(void);
GCTC_PORT BOOL GcTcDownloadItem(LPCTSTR pszUrl,
  GcTcCatalogItem*& pNewItem,
  DWORD dwItemTypes = -1,
  DWORD dwDownloadFlag = kDownloadAll,
  LPCTSTR pszDownloadPath = NULL);
GCTC_PORT int GcTcDownloadItem(LPTSTR* pUrls,
  int nNumUrls,
  GcTcCatalogItem** pItems,
  DWORD dwItemTypes = -1,
  DWORD dwDownloadFlag = kDownloadAll,
  LPCTSTR pszDownloadPath = NULL);
GCTC_PORT BOOL GcTcRefreshItem(GcTcCatalogItem** pItems,
  int nNumItems,
  DWORD dwItemTypes = -1,
  DWORD dwRefreshFlag = kRefreshAll);
GCTC_PORT BOOL GcTcSort(GcTcCatalogItem** pItems,
  int nNumItems,
  int nSortOption);
GCTC_PORT BOOL GcTcSetHostInfo(long lCurrentMajorVersion,
  long lCurrentMinorVersion,
  bool bBldEnv);