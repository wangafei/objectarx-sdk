#ifndef _GCUICOMBOBOX_H
#define _GCUICOMBOBOX_H

#pragma pack (push, 8)
#pragma once

#pragma push_macro("_USE_ANSI_CPP")
#define _USE_ANSI_CPP
#include <map>
#pragma pop_macro("_USE_ANSI_CPP")
typedef std::map<int, GcCmColor*>   GcCmColorTable;

class GCUI_PORT CGcUiComboBox : public CGdUiComboBox
{
	DECLARE_DYNAMIC(CGcUiComboBox);

public:
	CGcUiComboBox();
	virtual ~CGcUiComboBox();

public:
	CGcUiEdit* GcUiEditBox();
	BOOL       Validate();
	GCUI_ERROR_CODE ValidateData(CString& x);
	void    Convert();
	BOOL    ConvertData(CString& x);
	void    SetRange(double vMin, double vMax);

	DECLARE_MESSAGE_MAP()
};

class GCUI_PORT CGcUiAngleComboBox : public CGcUiComboBox 
{
	DECLARE_DYNAMIC(CGcUiAngleComboBox);

public:
	CGcUiAngleComboBox();
	virtual ~CGcUiAngleComboBox();

	DECLARE_MESSAGE_MAP()
};

class GCUI_PORT CGcUiNumericComboBox : public CGcUiComboBox 
{
	DECLARE_DYNAMIC(CGcUiNumericComboBox);

public:
	CGcUiNumericComboBox();
	virtual ~CGcUiNumericComboBox();

	DECLARE_MESSAGE_MAP()
};

class GCUI_PORT CGcUiStringComboBox : public CGcUiComboBox 
{
	DECLARE_DYNAMIC(CGcUiStringComboBox);

public:
	CGcUiStringComboBox();
	virtual ~CGcUiStringComboBox();

	DECLARE_MESSAGE_MAP()
};

class GCUI_PORT CGcUiSymbolComboBox : public CGcUiComboBox 
{
	DECLARE_DYNAMIC(CGcUiSymbolComboBox);

public:
	CGcUiSymbolComboBox();
	virtual ~CGcUiSymbolComboBox();

	DECLARE_MESSAGE_MAP()
};

#define GCUI_MAX_COMBOBOX_MRU   6
#define GCUI_MAX_TRUECOLOR_COMBOBOX_MRU   16

class GCUI_PORT CGcUiMRUComboBox;
class GCUI_PORT CGcUiMRUListBox;

typedef enum 
{
	kAcUiMRUCargo_Last = -106,
	kGcUiMRUCargo_Option2 = -105,
	kGcUiMRUCargo_Option1 = -104,
	kGcUiMRUCargo_Other2 = -103,
	kGcUiMRUCargo_Other1 = -102,
	kGcUiMRUCargo_None = -101
} GCUI_MRU_CARGO;

class GCUI_PORT CGcUiMRUListBox : public CGcUiListBox 
{
public:
	CGcUiMRUListBox();
	virtual ~CGcUiMRUListBox();

	virtual void GetContentExtent(int item, LPCTSTR text, int& width, int& height);

protected:
	virtual BOOL OnGetTipRect(CRect& r);
	int ExtraWidth();
	CGcUiMRUComboBox* MRUComboBox();

	DECLARE_MESSAGE_MAP()
};

class GCUI_PORT CGcUiMRUComboBox : public CGcUiComboBox 
{
public:
	CGcUiMRUComboBox();
	virtual ~CGcUiMRUComboBox();

	virtual void GetContentExtent(LPCTSTR text, int& width, int& height);
	virtual BOOL GetItemColors(DRAWITEMSTRUCT& dis, COLORREF& fgColor, 
															COLORREF& bgColor, COLORREF& fillColor);

protected:
	virtual BOOL OnGetTipRect(CRect& r);

protected:
	bool    m_bIsDynamicCreation : 1;   // TRUE if Create() is used, else FALSE.
	bool    m_bUseOption1        : 1;
	bool    m_bUseOption2        : 1;
	bool    m_bUseOther1         : 1;
	bool    m_bUseOther2         : 1;
	bool    m_bOther1Selected    : 1;
	bool    m_bOther2Selected    : 1;
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

	int     m_separatorItem;

	virtual int     CalcItemHeight (); 

	virtual void    DrawItemImage (CDC& dc, CRect& r, INT_PTR cargo);
	void    DrawItemImageFromCargo(CDC* dc, CRect& r, int i);
	void    DrawTextAndFocusRect(LPDRAWITEMSTRUCT lpDrawItemStruct, 
																CDC* dc, 
																CRect& rItem, 
																int i,
																COLORREF& fgColor,
																COLORREF& bgColor);
	void    CreateAndSelectPalette (LPDRAWITEMSTRUCT lpDrawItemStruct, CDC* dc);
	void    SetupForImageDraw(LPDRAWITEMSTRUCT lpDrawItemStruct, 
														CDC* dc, 
														CRect& rItem,
														CRect& rImage,
														COLORREF& fgColor,
														COLORREF& bgColor);
	void    ResetAndRestorePalette(CDC* dc, int savedState);
	BOOL    FindCargoInMRU (int cargo);
	int     GenerateCargoFromMRU (int seed);
	virtual BOOL    GetOptionName (BOOL isOption2, CString& name);
	virtual BOOL    GetOtherName (BOOL isOther2, CString& name);
	virtual void    OnAddItems ();
	virtual void    OnComboBoxInit ();
	virtual BOOL    OnSelectOther (BOOL isOther2, int curSel, int& newSel);
	void    SelectOther (BOOL isOther2);

public:
	void    SetSeparatorItem(int item) { m_separatorItem = item; }
	int     AddItemToList (LPCTSTR name, INT_PTR cargo);
	int     AddItemToMRU (LPCTSTR name, int cargo); 
	void    AddItems ();
	virtual BOOL    Create (DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	virtual int    ExtraWidth ();
	int     FindItemByCargo (INT_PTR cargo);
	int     GetCargoOption1 ();
	int     GetCargoOption2 ();
	INT_PTR     GetCurrentItemCargo (); 
	INT_PTR     GetItemCargo (INT_PTR item);
	LOGPALETTE *GetLogPalette ();
	HPALETTE GetPalette ();
	BOOL    GetUseOption1 ();
	BOOL    GetUseOption2 ();
	BOOL    GetUseOther1 ();
	BOOL    GetUseOther2 ();
	virtual int     ImageWidth ();
	int     InsertItemInList (int index, LPCTSTR name, INT_PTR cargo);
	int     ItemHeight ();
	void    RecalcHeight ();
	void    RemoveItemFromMRU (int cargo);
	void    SetCargoOption1 (int cargo);
	void    SetCargoOption2 (int cargo);
	void    SetLastSelection (int sel);
	void    SetLogPalette (LOGPALETTE *logPalette);
	void    SetPalette (HPALETTE hPalette);
	void    SetUseOption1 (BOOL use);
	void    SetUseOption2 (BOOL use);
	void    SetUseOther1 (BOOL use);
	void    SetUseOther2 (BOOL use);

public:        
	BOOL    GetUseByBlock ();
	BOOL    GetUseByLayer ();
	BOOL    GetUseOther ();
	BOOL    GetUseWindows ();
	void    SetUseByBlock (BOOL use);
	void    SetUseByLayer (BOOL use);
	void    SetUseOther (BOOL use);
	void    SetUseWindows (BOOL use);

public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
    virtual void    OnDrawThemeComboBoxBk(LPDRAWITEMSTRUCT lpDrawItemStruct);
protected:
	virtual void PreSubclassWindow();
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

protected:
	afx_msg BOOL OnCloseUp();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnDropDown();
	afx_msg BOOL OnSelEndOk();

	DECLARE_MESSAGE_MAP()
};

class CGcUiLTypeRecord : public CObject
{
public:
	CString & ltypeName()				{ return m_strLTypeName; };
	void setLTypeName(CString sName)	{ m_strLTypeName = sName; };
	GcDbObjectId objectId()				{ return m_idObjectId; };
	void setObjectId(GcDbObjectId id)	{ m_idObjectId = id; };
	BOOL isDependent()					{ return m_bIsDependent; };
	void setIsDependent(BOOL bValue)	{ m_bIsDependent = bValue; };

private:
	CString			  m_strLTypeName;
	GcDbObjectId	m_idObjectId;
	BOOL			    m_bIsDependent;
};

class GCUI_PORT CGcUiLineTypeComboBox : public CGcUiMRUComboBox 
{
public:
	CGcUiLineTypeComboBox();
	virtual ~CGcUiLineTypeComboBox();

	virtual void    OnComboBoxInit ();

	void    AddItems ();

	GcDbObjectId getOIDSel(int sel);
	GcDbObjectId getOIDCurSel();
	void setCurSelByOID(const GcDbObjectId& oidCurSel);       
	bool isOtherSelected();
	void forceSelectOther (BOOL isOther2);
	int  getLastSelection();
	bool getDbReload();
	void setDbReload(bool bReload);
	void emptyLTypeLocalList();

  virtual void GetLBString(int nIndex, CString& rString);
protected:
	virtual void DrawItemImage (CDC& dc, CRect& r, INT_PTR cargo);
	virtual void OnAddItems ();
	virtual BOOL OnSelectOther (BOOL isOther2, int curSel, int& newSel);
  virtual bool GetCurrentLayerLineType(GcDbObjectId& id);  
  virtual BOOL GetCurrentLayerVpOverride();

  INT_PTR  GetItemCargo (INT_PTR item);  
	int  FindItemByCargo (GcDbObjectId cargo);
	void LoadContentsFromDatabase();
	void ShowLTypes(bool bForceReloadDB = false);
	int AddLTypeToControl(CGcUiLTypeRecord * pLTypeRecord);
	CGcUiLTypeRecord* CreateLTRecord(CString& cstrLTName, GcDbObjectId& oidLT);

	virtual int ImageWidth();
	GcDbDatabase* getLTLocalMapDB();
	void setLTLocalMapDB(GcDbDatabase* pDb);

	CObList m_LTypeLocalList;  
	GcDbDatabase* m_pLTLocalMapDB;
	CGcUiLTypeRecord* m_pByLayerRec;
  bool m_bDbReload;  
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

	DECLARE_MESSAGE_MAP()
};

inline bool CGcUiLineTypeComboBox::getDbReload()
{
	return m_bDbReload;
}

inline void CGcUiLineTypeComboBox::setDbReload(bool bReload)
{
	m_bDbReload = bReload;
}

inline void CGcUiLineTypeComboBox::forceSelectOther (BOOL isOther2)
{
	if (isOtherSelected())
	{
		ShowDropDown(FALSE);
	}
	else
	{
		SelectOther(isOther2);
	}
}

inline int CGcUiLineTypeComboBox::getLastSelection()
{
	return m_lastSelection;
}

inline bool CGcUiLineTypeComboBox::isOtherSelected()
{
	CString otherName;
	CString curSelName;
	GetOtherName (false, otherName);
	GetLBText(GetCurSel(), curSelName);
	return curSelName == otherName;
}

inline GcDbObjectId CGcUiLineTypeComboBox::getOIDSel(int sel)
{
	GcDbObjectId oidLT;

  INT_PTR nItemCargo = (INT_PTR)GetItemData(sel);
  if (nItemCargo == CB_ERR 
    || nItemCargo == kGcUiMRUCargo_Other1 
    || nItemCargo == kGcUiMRUCargo_Other2 
    || nItemCargo == kGcUiMRUCargo_None)
  {
    return oidLT;
  }

  CGcUiLTypeRecord* pLTRec = (CGcUiLTypeRecord*)nItemCargo;
	if (NULL != pLTRec)
		oidLT = pLTRec->objectId();
	return oidLT;
}

inline GcDbObjectId CGcUiLineTypeComboBox::getOIDCurSel()
{
	return getOIDSel(GetCurSel());
}

inline void CGcUiLineTypeComboBox::setCurSelByOID(const GcDbObjectId& oidCurSel)
{
	int i = FindItemByCargo(oidCurSel);
	SetCurSel(i >= 0 ? i : m_lastSelection);
	if (i >= 0)  m_lastSelection = i;
}

//////////////////////////////////////////////////////////////////////////////

class GCUI_PORT CGcUiColorComboBox : public CGcUiMRUComboBox 
{
public:
	CGcUiColorComboBox ();
	virtual         ~CGcUiColorComboBox ();

protected:
	virtual void    DrawItemImage (CDC& dc, CRect& r, INT_PTR cargo);
	virtual void    OnAddItems ();
	virtual BOOL    OnSelectOther (BOOL isOther2, int curSel, int& newSel);

protected:
	int     m_blockColorIndex;

	virtual BOOL    GetOtherColorIndex ( int defaultColorIndex, int layerColorIndex, BOOL enableMetaColors, int& colorIndex );
	virtual BOOL    GetWindowsColor (COLORREF& color);
	virtual BOOL    GetOtherName (BOOL isOther2, CString& name);

	void    RGBFill (CDC& dc, CRect& rFill);
public:
	int     AddColorToMRU (int colorIndex);        
	int     FindItemByColorIndex (int colorIndex); 
	int     GetBlockColorIndex ();
	virtual COLORREF GetColorFromIndex (int colorIndex);
	virtual int     GetColorIndex (COLORREF color); 
	int     GetCurrentItemColorIndex ();
	virtual int     GetCurrentLayerColorIndex ();
	int     GetItemColorIndex (int item); 
	virtual COLORREF LookupColor ( int colorIndex, LOGPALETTE *logPalette );
	void    SetBlockColorIndex (int colorIndex);

	DECLARE_MESSAGE_MAP()
};

//////////////////////////////////////////////////////////////////////////////

#define GCUI_TRUECOLOR_COMBOBOX_TABLE_SIZE  GCUI_MAX_TRUECOLOR_COMBOBOX_MRU + 9

class GCUI_PORT CGcUiTrueColorComboBox : public CGcUiMRUComboBox
{
public:

	enum ColorTableIndex
	{
		kCargoOption1           =  0,       // index of byLayer
		kCargoOption2           =  1,       // index of byBlock
		kCargoStockItem1        =  2,       // index of Red
		kCargoStockItem2        =  3,       // index of Yellow
		kCargoStockItem3        =  4,       // index of Green
		kCargoStockItem4        =  5,       // index of Cyan
		kCargoStockItem5        =  6,       // index of Blue
		kCargoStockItem6        =  7,       // index of Magenta
		kCargoStockItem7        =  8,       // index of White
		kIndexOfFirstMRUItem    =  9,       // default newt table index
		kCargoOther1            = -1,       // place holder for select color dialog
		kCargoOther2            = -2,       // place holder for windows dialog
		kLastIndex              = GCUI_TRUECOLOR_COMBOBOX_TABLE_SIZE-1      // last index in table
	};

	CGcUiTrueColorComboBox      ();
	virtual                 ~CGcUiTrueColorComboBox     ();

	void                    AddItems                    ();
	int                     AddItemToList               (LPCTSTR name, int index, INT_PTR cargo);
	int                     AddItemToMRU                (LPCTSTR name, int cargo);
	int                     AddColorToMRU               (const GcCmColor& color);

	int                     FindItemByColor             (const GcCmColor& color);
	void                    GetCurrentItemColor         (GcCmColor& color);
	DWORD                   getColorByCargo             (int cargo);

	const GcCmColor&        GetBlockColor               ();
	void                    SetBlockColor               (const GcCmColor& color);

	virtual COLORREF        GetColorFromIndex           (int colorIndex);
	DWORD                   getColorData                (GcCmColor color);
	int                     GetColorIndex               (COLORREF color);

  virtual void            GetLBString                 (int nIndex, CString& rString);
protected:

  virtual void            DrawItemImage               (CDC& dc, CRect& r, INT_PTR cargo);
	virtual void            OnAddItems                  ();
	virtual BOOL            OnSelectOther               (BOOL isOther2,int curSel,int& newSel);  
	virtual BOOL            GetOtherColor               (GcCmColor& defaultColor,
		const GcCmColor& layerColor,
		BOOL enableMetaColors);
	BOOL                    GetWindowsColor             (GcCmColor& color);
	virtual BOOL            GetOtherName                (BOOL isOther2, CString& name);
	void                    initGcCmColorTable          (void);
	void                    RGBFill                     (CDC& dc, CRect& rFill);
	virtual bool            GetCurrentLayerColor        (GcCmColor& color);
  virtual BOOL            GetCurrentLayerVpOverride();            

	virtual COLORREF        LookupColor                 (int colorIndex, LOGPALETTE *logPalette);
	afx_msg void            OnDrawItem                  (int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);

public:
  virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
protected:
	int                     m_cargoOther1;
	int                     m_cargoOther2;
	GcCmColor               m_blockColor;
	GcCmColor *             m_GcCmColorTable[GCUI_TRUECOLOR_COMBOBOX_TABLE_SIZE];
	int                     m_nextGcCmColorTableIndex;  
	DECLARE_MESSAGE_MAP()
};

//internal use
class GCUI_PORT CGcUiTrueColorComboBoxForPagesetup : public CGcUiTrueColorComboBox
{
public:
  CGcUiTrueColorComboBoxForPagesetup();

protected:
  virtual void OnAddItems();
  virtual COLORREF LookupColor(int colorIndex, LOGPALETTE *logPalette);
  virtual void DrawItemImage(CDC& dc, CRect& r, INT_PTR cargo);
  virtual BOOL GetOtherColor(GcCmColor& defaultColor,const GcCmColor& layerColor,BOOL enableMetaColors);
};

//internal use
class GCUI_PORT CGcUiWhiteBlackTrueColorComboBox : public CGcUiTrueColorComboBox
{
public:
  CGcUiWhiteBlackTrueColorComboBox();

protected:
  virtual void OnAddItems();
};

//////////////////////////////////////////////////////////////////////////////

class GCUI_PORT CGcUiLineWeightComboBox : public CGcUiMRUComboBox
{
public:
	CGcUiLineWeightComboBox();
	virtual ~CGcUiLineWeightComboBox();

public:
	int     FindItemByLineWeight(int lw);
	int     GetCurrentItemLineWeight();
	int     GetItemLineWeight(int item);
	double  GetLineWeightScale();
	void    SetLineWeightScale(double scale);
	void    SetUseDefault(BOOL b);
	virtual int ImageWidth();  

  virtual void GetLBString(int nIndex, CString& rString);
protected:
	virtual void DrawItemImage(CDC& dc, CRect& r, INT_PTR cargo);
	virtual void OnAddItems();
  virtual int  GetCurrentLayerLineWeight();
  virtual BOOL GetCurrentLayerVpOverride();

public:
  virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

protected:
	double  m_lineWeightScale;

private:
	BOOL    m_bUseDefault;
  
	DECLARE_MESSAGE_MAP()
};

//////////////////////////////////////////////////////////////////////////////

class GCUI_PORT CGcUiArrowHeadComboBox : public CGcUiMRUComboBox
{
public:
	CGcUiArrowHeadComboBox ();
	virtual         ~CGcUiArrowHeadComboBox ();

protected:
	virtual void    DrawItemImage (CDC& dc, CRect& r, INT_PTR cargo);
	virtual int     CalcItemHeight ();
	virtual BOOL    GetOtherName (BOOL isOther2, CString& name);
	virtual void    OnAddItems ();
	virtual void    OnComboBoxInit ();

public:        
	BOOL    GetUseOrigin2 ();
	void    SetUseOrigin2 (BOOL use);

private:
	CBitmap m_arrowBitmap;
	int     m_arrowCount;
	int     m_arrowSize;
	BOOL    m_bUseOrigin2;

public:
	int     AddArrowHeadToMRU (LPCTSTR name);

	DECLARE_MESSAGE_MAP()
};

//////////////////////////////////////////////////////////////////////////////

class GCUI_PORT CGcUiPlotStyleTablesComboBox : public CGcUiMRUComboBox
{
public:
	CGcUiPlotStyleTablesComboBox ();
	CGcUiPlotStyleTablesComboBox (BOOL bInitialize);        
	virtual         ~CGcUiPlotStyleTablesComboBox ();

	void    SetFileType(bool currentDrawing, bool named);
	int     AddMissingStyleTable(LPCTSTR fullFileName,bool bMissing = true);
	bool    IsMissing(int index);
	virtual int     ImageWidth ();
	void	GetLBText(int nIndex, CString& rString) const;
	int     AddItemToList (LPCTSTR name, INT_PTR cargo);        
protected:
	virtual void    DrawItemImage (CDC& dc, CRect& r, INT_PTR cargo);
	virtual int     CalcItemHeight ();
	virtual void    OnAddItems ();
	virtual void    OnComboBoxInit ();

private:
	CBitmap m_plotStyleTablesBitmap;
	int     m_plotStyleTableBitmapSize;
	BOOL    m_bImageDisplayed;
	bool    m_bCurrentDrawing;
	bool    m_bNamed;
	BOOL    m_bInitialize;
public:
	virtual BOOL OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*);
protected:
	afx_msg BOOL OnDropDown();

	DECLARE_MESSAGE_MAP()
};

//////////////////////////////////////////////////////////////////////////////

class GCUI_PORT CGcUiPlotStyleNamesComboBox : public CGcUiMRUComboBox
{
public:
	CGcUiPlotStyleNamesComboBox ();
	virtual         ~CGcUiPlotStyleNamesComboBox ();
	virtual int     ImageWidth ();
	void            OtherRunsSelectPlotStyle() {m_whatOtherDoes = 0; }
	void            OtherRunsCurrentPlotStyle() {m_whatOtherDoes = 1; }
	void            OtherRunsDefault() {m_whatOtherDoes = -1;}
	void            SetAllowByLayerByBlock(BOOL bAllow) {m_bAllowByLayerByBlock = bAllow;}
	void            SetColorDependentMode();
	void            SetNamedMode();

protected:
	virtual void    OnAddItems ();
	virtual BOOL    OnSelectOther (BOOL isOther2, int curSel, int& newSel);
	virtual void    OnComboBoxInit ();      

private:
	// -1 to leave up to control, 0 to run select plot style, 1 to run curent plot style.
	int m_whatOtherDoes;
	// TRUE if this control is in color depedent mode.
	BOOL m_bColorDependentMode;
	// If TRUE the following allows the selection of ByLayer/ByBlock in
	// the "Other..." dialog.
	BOOL m_bAllowByLayerByBlock;
	// Save the last set named mode settings for using ByBlock
	BOOL m_bLastByBlock;
	// Save the last set named mode settings for using ByLayer.
	BOOL m_bLastByLayer;
	// Other... when switched to color dependent mode.
	BOOL m_bLastUseOther;        

	DECLARE_MESSAGE_MAP()
};


class GCUI_PORT CGcUiPredefBlockComboBox : public CGcUiMRUComboBox {
public:
	CGcUiPredefBlockComboBox ();
	virtual         ~CGcUiPredefBlockComboBox ();

	// MRU control
protected:
	virtual void    DrawItemImage (CDC& dc, CRect& r, INT_PTR cargo);
	virtual int     CalcItemHeight ();
	virtual BOOL    GetOtherName (BOOL isOther2, CString& name);
	virtual void    OnAddItems ();
	virtual void    OnComboBoxInit ();

	// PredefBlock control
private:
	CBitmap m_blockBitmap;
	int     m_blockCount;           // Number of images in bitmap
	int     m_blockSize;            // Image height and width in pixels

public:
	int     AddPredefBlockToMRU (LPCTSTR name);   // Returns item index (or -1).

	// ClassWizard-controlled
public:
	//{{AFX_VIRTUAL(CGcUiPredefBlockComboBox)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CGcUiPredefBlockComboBox)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

// 字体组合框
class GCUI_PORT CGcUiFontComboBox : public CGcUiMRUComboBox
{
public:
  CGcUiFontComboBox();
  virtual ~CGcUiFontComboBox();

  void setBuddy(CComboBox* pStyleCombo, bool bExcludeLogicStyle);

  void setCurrentFont(const GCHAR* fn);
  void getCurrentFont(CString& str);

protected:
  virtual void DrawItemImage(CDC& dc, CRect& r, INT_PTR cargo);
  virtual int  CalcItemHeight();
  virtual void OnAddItems();

  afx_msg void OnDropDown();
  afx_msg void OnSelectChanged();

private:
  bool mbExcludeLogicStyle;
  CComboBox* mpStyleComboBox;

  HICON mIcons[2];

  DECLARE_MESSAGE_MAP()
};

// 字体列表控件
class GCUI_PORT CGcUiShxFontList : public CListBox
{
public:
  CGcUiShxFontList();
  virtual ~CGcUiShxFontList();

  void FillList(bool bBig);

protected:
  virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
  virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);

  HICON mIcon;

  DECLARE_MESSAGE_MAP()
};

#pragma pack (pop)

#endif//_GCUICOMBOBOX_H