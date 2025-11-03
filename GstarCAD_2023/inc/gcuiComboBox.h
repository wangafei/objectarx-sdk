/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gcuiComboBox_h
#define _gcuiComboBox_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif 

#pragma push_macro("_USE_ANSI_CPP")
#define _USE_ANSI_CPP
#include <map>
#pragma pop_macro("_USE_ANSI_CPP")
typedef std::map<int, GcCmColor*>   GcCmColorTable;

class CGdUiImage;

class GCAD_PORT CGcUiComboBox : public CGdUiComboBox {
  DECLARE_DYNAMIC(CGcUiComboBox);

public:
  CGcUiComboBox();
  ~CGcUiComboBox();

public:
  CGcUiEdit *GcUiEditBox();
  BOOL    Validate();
  GCUI_ERROR_CODE ValidateData(CString& x);
  void    Convert();
  BOOL    ConvertData(CString& x);
  void    SetRange(double vMin, double vMax);

protected:
  DECLARE_MESSAGE_MAP()
};

class GCAD_PORT CGcUiAngleComboBox : public CGcUiComboBox {
  DECLARE_DYNAMIC(CGcUiAngleComboBox);
public:
  CGcUiAngleComboBox();
  ~CGcUiAngleComboBox();

protected:
  DECLARE_MESSAGE_MAP()
};

class GCAD_PORT CGcUiNumericComboBox : public CGcUiComboBox {
  DECLARE_DYNAMIC(CGcUiNumericComboBox);
public:
  CGcUiNumericComboBox();
  ~CGcUiNumericComboBox();

protected:
  DECLARE_MESSAGE_MAP()
};

class GCAD_PORT CGcUiStringComboBox : public CGcUiComboBox {
  DECLARE_DYNAMIC(CGcUiStringComboBox);
public:
  CGcUiStringComboBox();
  ~CGcUiStringComboBox();

protected:
  DECLARE_MESSAGE_MAP()
};

class GCAD_PORT CGcUiSymbolComboBox : public CGcUiComboBox {
  DECLARE_DYNAMIC(CGcUiSymbolComboBox);
public:
  CGcUiSymbolComboBox();
  ~CGcUiSymbolComboBox();

protected:
  DECLARE_MESSAGE_MAP()
};

#define GCUI_MAX_COMBOBOX_MRU   6
#define GCUI_MAX_TRUECOLOR_COMBOBOX_MRU   16

class GCAD_PORT CGcUiMRUComboBox;
class GCAD_PORT CGcUiMRUListBox;

typedef enum {
  kGcUiMRUCargo_Last = -106,
  kGcUiMRUCargo_Option2 = -105,
  kGcUiMRUCargo_Option1 = -104,
  kGcUiMRUCargo_Other2 = -103,
  kGcUiMRUCargo_Other1 = -102,
  kGcUiMRUCargo_None = -101
} GCUI_MRU_CARGO;

class GCAD_PORT CGcUiMRUListBox : public CGcUiListBox {
public:
  CGcUiMRUListBox();
  ~CGcUiMRUListBox();

public:
  void    GetContentExtent(
    int item,
    LPCTSTR text,
    int& width,
    int& height) override;

protected:
  BOOL    OnGetTipRect(CRect& r) override;

protected:
  int     ExtraWidth();
  CGcUiMRUComboBox *MRUComboBox();

protected:
  DECLARE_MESSAGE_MAP()
};

class GCAD_PORT CGcUiMRUComboBox : public CGcUiComboBox {
public:
  CGcUiMRUComboBox();
  ~CGcUiMRUComboBox();

  void    GetContentExtent(LPCTSTR text, int& width, int& height) override;
  virtual BOOL    GetItemColors(DRAWITEMSTRUCT& dis, COLORREF& fgColor,
    COLORREF& bgColor, COLORREF& fillColor);

protected:
  BOOL    OnGetTipRect(CRect& r) override;

protected:
  bool    m_bIsDynamicCreation : 1;
  bool    m_bUseOption1 : 1;
  bool    m_bUseOption2 : 1;
  bool    m_bUseOther1 : 1;
  bool    m_bUseOther2 : 1;
  bool    m_bOther1Selected : 1;
  bool    m_bOther2Selected : 1;
  int     m_cargoOption1;
  int     m_cargoOption2;
  LOGPALETTE* m_logPalette;
  HPALETTE m_hPalette;
  CPalette* m_pOldPalette;
  int     m_itemHeight;
  int     m_lastSelection;
  int     m_mruCargo[GCUI_MAX_COMBOBOX_MRU];
  int     m_mruLen;
  CString m_mruName[GCUI_MAX_COMBOBOX_MRU];

  virtual int     CalcItemHeight();

  virtual void    DrawItemImage(CDC& dc, CRect& r, INT_PTR cargo);
  void    DrawItemImageFromCargo(CDC* dc, CRect& r, int i);
  void    DrawTextAndFocusRect(LPDRAWITEMSTRUCT lpDrawItemStruct,
    CDC* dc,
    CRect& rItem,
    int i,
    COLORREF& fgColor,
    COLORREF& bgColor);
  void    CreateAndSelectPalette(LPDRAWITEMSTRUCT lpDrawItemStruct,
    CDC* dc);
  void    SetupForImageDraw(LPDRAWITEMSTRUCT lpDrawItemStruct,
    CDC* dc,
    CRect& rItem,
    CRect& rImage,
    COLORREF& fgColor,
    COLORREF& bgColor);
  void    ResetAndRestorePalette(CDC* dc, int savedState);

  BOOL    FindCargoInMRU(int cargo);
  int     GenerateCargoFromMRU(int seed);
  virtual BOOL    GetOptionName(BOOL isOption2, CString& name);
  virtual BOOL    GetOtherName(BOOL isOther2, CString& name);
  virtual void    OnAddItems();
  virtual void    OnComboBoxInit();
  virtual BOOL    OnSelectOther(BOOL isOther2, int curSel, int& newSel);
  void    SelectOther(BOOL isOther2);

public:
  int     AddItemToList(LPCTSTR name, INT_PTR cargo);
  int     AddItemToMRU(LPCTSTR name, int cargo);
  void    AddItems();
  BOOL    Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID) override;
  virtual int     ExtraWidth();
  int     FindItemByCargo(INT_PTR cargo);
  int     GetCargoOption1();
  int     GetCargoOption2();
  INT_PTR     GetCurrentItemCargo();
  INT_PTR     GetItemCargo(int item);
  LOGPALETTE *GetLogPalette();
  HPALETTE GetPalette();
  BOOL    GetUseOption1();
  BOOL    GetUseOption2();
  BOOL    GetUseOther1();
  BOOL    GetUseOther2();
  virtual int     ImageWidth();
  int     InsertItemInList(int index, LPCTSTR name, INT_PTR cargo);
  int     ItemHeight();
  void    RecalcHeight();
  void    RemoveItemFromMRU(int cargo);
  void    SetCargoOption1(int cargo);
  void    SetCargoOption2(int cargo);
  void    SetLastSelection(int sel);
  void    SetLogPalette(LOGPALETTE *logPalette);
  void    SetPalette(HPALETTE hPalette);
  void    SetUseOption1(BOOL use);
  void    SetUseOption2(BOOL use);
  void    SetUseOther1(BOOL use);
  void    SetUseOther2(BOOL use);

public:
  BOOL    GetUseByBlock();
  BOOL    GetUseByLayer();
  BOOL    GetUseOther();
  BOOL    GetUseWindows();
  void    SetUseByBlock(BOOL use);
  void    SetUseByLayer(BOOL use);
  void    SetUseOther(BOOL use);
  void    SetUseWindows(BOOL use);

public:
  void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) override;
  void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) override;
protected:
  void PreSubclassWindow() override;
  LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam) override;

protected:
  afx_msg BOOL OnCloseUp();
  afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
  afx_msg BOOL OnDropDown();
  afx_msg BOOL OnSelEndOk();

  DECLARE_MESSAGE_MAP()
};
class CGcUiLTypeRecord : public CObject {
public:
  CString & ltypeName();
  void setLTypeName(CString sName);
  GcDbObjectId objectId();
  void setObjectId(GcDbObjectId id);
  BOOL isDependent();
  void setIsDependent(BOOL bValue);

private:
  CString m_strLTypeName;
  GcDbObjectId m_idObjectId;
  BOOL m_bIsDependent;
};

inline CString& CGcUiLTypeRecord::ltypeName()
{
  return m_strLTypeName;
}

inline void CGcUiLTypeRecord::setLTypeName(CString sName)
{
  m_strLTypeName = sName;
}

inline GcDbObjectId CGcUiLTypeRecord::objectId()
{
  return m_idObjectId;
}

inline void CGcUiLTypeRecord::setObjectId(GcDbObjectId id)
{
  m_idObjectId = id;
}

inline BOOL CGcUiLTypeRecord::isDependent()
{
  return m_bIsDependent;
}

inline void CGcUiLTypeRecord::setIsDependent(BOOL bValue)
{
  m_bIsDependent = bValue;
}

class GCAD_PORT CGcUiLineTypeComboBox : public CGcUiMRUComboBox
{
public:
  CGcUiLineTypeComboBox();
  ~CGcUiLineTypeComboBox();

  void    OnComboBoxInit() override;

  void    AddItems();

  GcDbObjectId getOIDSel(int sel);
  GcDbObjectId getOIDCurSel();
  void setCurSelByOID(const GcDbObjectId& oidCurSel);
  bool isOtherSelected();
  void forceSelectOther(BOOL isOther2);
  int  getLastSelection();
  bool getDbReload();
  void setDbReload(bool bReload);
  void emptyLTypeLocalList();
protected:
  void DrawItemImage(CDC& dc, CRect& r, INT_PTR cargo) override;
  void OnAddItems() override;
  BOOL OnSelectOther(BOOL isOther2, int curSel, int& newSel) override;
  INT_PTR  GetItemCargo(int item);
  int  FindItemByCargo(GcDbObjectId cargo);
  void LoadContentsFromDatabase();
  void ShowLTypes(bool bForceReloadDB = false);
  int AddLTypeToControl(CGcUiLTypeRecord * pLTypeRecord);
  CGcUiLTypeRecord* CreateLTRecord(CString& cstrLTName, GcDbObjectId& oidLT);

  int ImageWidth() override;
  GcDbDatabase* getLTLocalMapDB();
  void setLTLocalMapDB(GcDbDatabase* pDb);

  CObList m_LTypeLocalList;
  GcDbDatabase* m_pLTLocalMapDB;
  bool m_bDbReload;

public:
  void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) override;

protected:
  DECLARE_MESSAGE_MAP()
};

inline
bool
CGcUiLineTypeComboBox::getDbReload()
{
  return m_bDbReload;
}
inline
void
CGcUiLineTypeComboBox::setDbReload(bool bReload)
{
  m_bDbReload = bReload;
}

inline
void
CGcUiLineTypeComboBox::forceSelectOther(BOOL isOther2)
{
  SelectOther(isOther2);
}

inline
int
CGcUiLineTypeComboBox::getLastSelection()
{
  return m_lastSelection;
}

inline
bool
CGcUiLineTypeComboBox::isOtherSelected()
{
  CString otherName;
  CString curSelName;
  GetOtherName(false, otherName);
  GetLBText(GetCurSel(), curSelName);
  return curSelName == otherName;
}

inline
GcDbObjectId
CGcUiLineTypeComboBox::getOIDSel(int sel)
{
  GcDbObjectId oidLT;
  CGcUiLTypeRecord* pLTRec =
    (CGcUiLTypeRecord*)(GetItemDataPtr(sel));
  if (NULL != pLTRec)
    oidLT = pLTRec->objectId();
  return oidLT;
}

inline
GcDbObjectId
CGcUiLineTypeComboBox::getOIDCurSel()
{
  return getOIDSel(GetCurSel());
}

inline
void
CGcUiLineTypeComboBox::setCurSelByOID(const GcDbObjectId& oidCurSel)
{
  int i = FindItemByCargo(oidCurSel);
  SetCurSel(i >= 0 ? i : m_lastSelection);
  if (i >= 0)
    m_lastSelection = i;
}

class GCAD_PORT CGcUiColorComboBox : public CGcUiMRUComboBox {
public:
  CGcUiColorComboBox();
  ~CGcUiColorComboBox();

protected:
  void    DrawItemImage(CDC& dc, CRect& r, INT_PTR cargo) override;
  void    OnAddItems() override;
  BOOL    OnSelectOther(BOOL isOther2, int curSel, int& newSel) override;

protected:
  int     m_blockColorIndex;

  virtual BOOL    GetOtherColorIndex(
    int defaultColorIndex, int layerColorIndex, BOOL enableMetaColors,
    int& colorIndex
  );
  virtual BOOL    GetWindowsColor(COLORREF& color);
  BOOL    GetOtherName(BOOL isOther2, CString& name) override;

  void    RGBFill(CDC& dc, CRect& rFill);
public:
  int     AddColorToMRU(int colorIndex);
  int     FindItemByColorIndex(int colorIndex);
  int     GetBlockColorIndex();
  virtual COLORREF GetColorFromIndex(int colorIndex);
  virtual int     GetColorIndex(COLORREF color);
  int     GetCurrentItemColorIndex();
  virtual int     GetCurrentLayerColorIndex();
  int     GetItemColorIndex(int item);
  virtual COLORREF LookupColor(
    int colorIndex,
    LOGPALETTE *logPalette
  );
  void    SetBlockColorIndex(int colorIndex);

protected:
  DECLARE_MESSAGE_MAP()
};

#define GCUI_TRUECOLOR_COMBOBOX_TABLE_SIZE  GCUI_MAX_TRUECOLOR_COMBOBOX_MRU + 9

class GCAD_PORT CGcUiTrueColorComboBox : public CGcUiMRUComboBox {
public:

  enum ColorTableIndex {
    kCargoOption1 = 0,
    kCargoOption2 = 1,
    kCargoStockItem1 = 2,
    kCargoStockItem2 = 3,
    kCargoStockItem3 = 4,
    kCargoStockItem4 = 5,
    kCargoStockItem5 = 6,
    kCargoStockItem6 = 7,
    kCargoStockItem7 = 8,
    kIndexOfFirstMRUItem = 9,
    kCargoOther1 = -1,
    kCargoOther2 = -2,
    kLastIndex = GCUI_TRUECOLOR_COMBOBOX_TABLE_SIZE - 1
  };

  CGcUiTrueColorComboBox();
  ~CGcUiTrueColorComboBox();

  void                    AddItems();
  int                     AddItemToList(LPCTSTR name, int index, INT_PTR cargo);
  int                     AddItemToMRU(LPCTSTR name, int cargo);
  int                     AddColorToMRU(const GcCmColor& color);

  int                     FindItemByColor(const GcCmColor& color);
  void                    GetCurrentItemColor(GcCmColor& color);
  DWORD                   getColorByCargo(int cargo);

  const GcCmColor&        GetBlockColor();
  void                    SetBlockColor(const GcCmColor& color);

  virtual COLORREF        GetColorFromIndex(int colorIndex);
  DWORD                   getColorData(GcCmColor color);
  int                     GetColorIndex(COLORREF color);

  void                    SetSupportColorBook(BOOL newVal);
  BOOL                    GetSupportColorBook();

protected:
  int                     m_cargoOther1;
  int                     m_cargoOther2;
  GcCmColor               m_blockColor;

  void                    DrawItemImage(CDC& dc, CRect& r, INT_PTR cargo) override;
  void                    OnAddItems() override;


  BOOL                    OnSelectOther(BOOL isOther2, int curSel, int& newSel) override;
  BOOL                    GetOtherColor(GcCmColor& defaultColor,
    const GcCmColor& layerColor,
    BOOL enableMetaColors);
  BOOL                    GetWindowsColor(GcCmColor& color);
  BOOL                    GetOtherName(BOOL isOther2, CString& name) override;


  GcCmColor *             m_GcCmColorTable[GCUI_TRUECOLOR_COMBOBOX_TABLE_SIZE];
  int                     m_nextGcCmColorTableIndex;

  void                    initGcCmColorTable(void);

  void                    RGBFill(CDC& dc, CRect& rFill);

  bool                    GetCurrentLayerColor(GcCmColor& color);

  virtual COLORREF        LookupColor(int colorIndex, LOGPALETTE *logPalette);

  afx_msg void            OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);

protected:
  DECLARE_MESSAGE_MAP()
};

class GCAD_PORT CGcUiLineWeightComboBox : public CGcUiMRUComboBox {
public:
  CGcUiLineWeightComboBox();
  ~CGcUiLineWeightComboBox();

protected:
  void    DrawItemImage(CDC& dc, CRect& r, INT_PTR cargo) override;
  void    OnAddItems() override;

protected:
  double  m_lineWeightScale;

public:
  int     FindItemByLineWeight(int lw);
  int     GetCurrentItemLineWeight();
  int     GetCurrentLayerLineWeight();
  int     GetItemLineWeight(int item);
  double  GetLineWeightScale();
  void    SetLineWeightScale(double scale);
  void    SetUseDefault(BOOL b);
  int     ImageWidth() override;
private:
  BOOL    m_bUseDefault;

protected:
  DECLARE_MESSAGE_MAP()
};

class GCAD_PORT CGcUiArrowHeadComboBox : public CGcUiMRUComboBox {
public:
  CGcUiArrowHeadComboBox();
  ~CGcUiArrowHeadComboBox();

protected:
  void    DrawItemImage(CDC& dc, CRect& r, INT_PTR cargo) override;
  int     CalcItemHeight() override;
  BOOL    GetOtherName(BOOL isOther2, CString& name) override;
  void    OnAddItems() override;

  virtual bool    LoadImages();

public:
  BOOL    GetUseOrigin2();
  void    SetUseOrigin2(BOOL use);

private:
  CGdUiImage* m_pArrowImages;
  int     m_arrowCount;
  int     m_arrowSize;
  BOOL    m_bUseOrigin2;
  BOOL    m_bThemedArrowImagesLoaded;

public:
  int     AddArrowHeadToMRU(LPCTSTR name);
  void    DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) override;

protected:
  DECLARE_MESSAGE_MAP()
};

class GCAD_PORT CGcUiPlotStyleTablesComboBox : public CGcUiMRUComboBox {
public:
  CGcUiPlotStyleTablesComboBox();
  CGcUiPlotStyleTablesComboBox(BOOL bInitialize);
  ~CGcUiPlotStyleTablesComboBox();
  void    SetFileType(bool currentDrawing, bool named);
  int     AddMissingStyleTable(LPCTSTR fullFileName, bool bMissing = true);
  bool    IsMissing(int index);

  int     ImageWidth() override;

  void GetLBText(int nIndex, CString& rString) const;

  int     AddItemToList(LPCTSTR name, INT_PTR cargo);
protected:
  void    DrawItemImage(CDC& dc, CRect& r, INT_PTR cargo) override;
  int     CalcItemHeight() override;
  void    OnAddItems() override;
  void    OnComboBoxInit() override;

private:
  CBitmap m_plotStyleTablesBitmap;
  int     m_plotStyleTableBitmapSize;
  BOOL    m_bImageDisplayed;
  bool    m_bCurrentDrawing;
  bool    m_bNamed;
  BOOL    m_bInitialize;
public:
  BOOL OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*) override;

protected:
  afx_msg BOOL OnDropDown();
  DECLARE_MESSAGE_MAP()

private:
  BOOL AdjustDropDownListWidth(void);
};

class GCAD_PORT CGcUiPlotStyleNamesComboBox : public CGcUiMRUComboBox {
public:
  CGcUiPlotStyleNamesComboBox();
  ~CGcUiPlotStyleNamesComboBox();
  int     ImageWidth() override;
  void            OtherRunsSelectPlotStyle() { m_whatOtherDoes = 0; }
  void            OtherRunsCurrentPlotStyle() { m_whatOtherDoes = 1; }
  void            OtherRunsDefault() { m_whatOtherDoes = -1; }
  void            SetAllowByLayerByBlock(BOOL bAllow) { m_bAllowByLayerByBlock = bAllow; }
  void            SetColorDependentMode();
  void            SetNamedMode();

protected:
  void    OnAddItems() override;
  BOOL    OnSelectOther(BOOL isOther2, int curSel, int& newSel) override;
  void    OnComboBoxInit() override;

private:
  int m_whatOtherDoes;

  BOOL m_bColorDependentMode;
  BOOL m_bAllowByLayerByBlock;

  BOOL m_bLastByBlock;
  BOOL m_bLastByLayer;
  BOOL m_bLastUseOther;

protected:
  DECLARE_MESSAGE_MAP()
};

class GCAD_PORT CGcUiPredefBlockComboBox : public CGcUiMRUComboBox {
public:
  CGcUiPredefBlockComboBox();
  virtual ~CGcUiPredefBlockComboBox();

protected:
  void    DrawItemImage(CDC& dc, CRect& r, INT_PTR cargo) override;
  int     CalcItemHeight() override;
  BOOL    GetOtherName(BOOL isOther2, CString& name) override;
  void    OnAddItems() override;

  virtual bool    LoadImages();

private:
  CGdUiImage* m_pBlockImages;
  int     m_blockCount;
  int     m_blockSize;
  BOOL    m_bThemedBlockImagesLoaded;

public:
  int     AddPredefBlockToMRU(LPCTSTR name);

protected:
  DECLARE_MESSAGE_MAP()
};

#pragma pack (pop)
#endif