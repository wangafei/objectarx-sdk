/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GDUI_THEME_H_
#define _GDUI_THEME_H_
#include "gsoft.h"
#ifdef _GSOFT_WINDOWS_
#include <afxtempl.h>
#include "GdGChar.h"
#include "GcColorThemeEnum.h"

class CGcColorTheme;

#define PROPERTY_PALETTE_THEME  GCRX_T("PropertyPalette")
#define TOOL_PALETTE_THEME      GCRX_T("ToolPalette")
#define OWNDERDRAW_BUTTON_THEME GCRX_T("OwnerDrawButton")
#define DIALOG_WORKSHEET_THEME  GCRX_T("DialogWorksheet")
#define PALETTE_SET_THEME       GCRX_T("PaletteSet")
#define DESIGN_CENTER_THEME     GCRX_T("DesignCenter")   
#define TOOL_PANEL_THEME        GCRX_T("ToolPanel")
#define DOCKBAR_THEME           GCRX_T("DockBar")   
#define DOCKCONTROLBAR_THEME    GCRX_T("DockControlBar")   
#define ANCHORBAR_THEME         GCRX_T("AnchorBar")   
#define ACTIVE_THEME            GCRX_T("ACTIVETHEME")
#define DIALOG_THEME            GCRX_T("DIALOGTHEME")


typedef enum {
  kUnknownElements = -1,
  kPaletteFontCaption,
  kPaletteFontTab,
  kPaletteFontToolTip,
  kPaletteFont,
  kWorksheetFont,
  kWorksheetFontCaption,
  kInspectorItemFont,
  kInspectorRootFont,

  kPaletteBackground,
  kPaletteCaptionBackground,
  kPaletteCaptionInactive,
  kPaletteCaptionText,
  kPaletteCaptionInactiveText,
  kPaletteTabText,
  kPaletteTabBackground,
  kPaletteBorder,
  kPaletteTabShadow,
  kPaletteTabHighlight,
  kPaletteTabTextHilite,
  kPaletteTabSelectHilite,
  kPaletteToolTip,
  kPaletteToolTipText,
  kPaletteButtonText,
  kPaletteButtonTextDisabled,
  kPaletteButtonBorder,
  kPaletteItemText,
  kPaletteScrollBackground,
  kPaletteScrollThumb,
  kPaletteScrollArrow,

  kWorksheetBackground,
  kWorksheetCaptionBackground,
  kWorksheetCaptionText,
  kWorksheet3DBtnShadow,
  kWorksheetButtonText,
  kWorksheetButtonTextDisabled,
  kWorksheetScrollBackground,
  kWorksheetScrollThumb,
  kWorksheetBorder,
  kWorksheetGripHighlight,

  kInspector,
  kInspectorTop,
  kInspectorCat,
  kInspectorItem,
  kInspectorBorder,
  kInspectorBorderItem,
  kInspectorTextTop,
  kInspectorTextCat,
  kInspectorTextItem,
  kInspectorTextLabel,
  kInspectorFGHighlight,
  kInspectorBGHighlight,
  kInspector3dShadow,
  kInspectorControl,
  kInspectorCatChevron1,
  kInspectorCatChevron2,
  kInspectorSubChevron,
  kInspectorCellHighlight,

  kPanelBackground,
  kPanelSashBackground,
  kPanelBorder,

  kControlBorder,
  kControlBackground,
  kDisabledControlBorder,
  kControlSupport,
  kControlHighlight,
  kControlActiveOuterBorder,
  kControlErrorOuterBorder,
  kControlActiveText,
  kControlText,
  kControlInactiveText,

  kPaletteFrameInnerBorder,
  kPaletteFrameOuterBorder,
  kPaletteFrameBackground,
  kPaletteFrameShadow,
  kInspectorTopGradient1,
  kInspectorTopGradient2,
  kPaletteScrollBackgroundBorder,
  kPaletteScrollBackgroundGradient1,
  kPaletteScrollBackgroundGradient2,
  kPaletteScrollSliderInactive,
  kPaletteScrollSliderActiveOuterBorder,
  kPaletteScrollSliderActiveOuterGradient1,
  kPaletteScrollSliderActiveOuterGradient2,
  kPaletteScrollSliderActiveOuterGradient3,
  kPaletteScrollSliderActiveOuterGradient4,
  kPaletteScrollSliderActiveInnerGradient1,
  kPaletteScrollSliderActiveInnerGradient2,
  kInspectorClosedOuterBorder,
  kInspectorOpenOuterBorder,
  kInspectorInnerBorder,
  kPaletteColumnHeaderBackground,
  kPaletteHyperlinkText,
  kPaletteTreeOrListBackground,

  kAnchorBarOuterBorder,
  kAnchorBarEmbossRightBottom,
  kAnchorBarEmbossLeftTop,
  kAnchorBarInnerHighlight,
  kAnchorBarGradient1,
  kAnchorBarGradient2,
  kAnchorBarActiveTitleBackground,
  kAnchorBarCaptionText,

  kGrabBarDotDark,
  kGrabBarDotLight,
  kControlBarTitleBackground,

  kAppFrameBorder,
  kAppFrameOuterBorder,
  kAppFrameAFGradientTop,
  kAppFrameAFGradientBottom,
  kAppFrameCaptionActiveGradientTop,
  kAppFrameCaptionActiveGradientBottom,
  kAppFrameCaptionInActiveGradientTop,
  kAppFrameCaptionInActiveGradientBottom,
  kAppFrameCaptionOuterBorder,
  kAppFrameCaptionInnerBorder,
  kAppFrameQATGradientTop,
  kAppFrameQATGradientBottom,
  kAppFrameQATOuterBorder,
  kAppFrameQATInnerBorder,

  kAppFrameQATButtonsBorder,
  kAppFrameQATButtonsRolloverBorder,
  kAppFrameQATButtonsClickBorder,
  kAppFrameQATFlyoutButtonText,

  kAppFrameBigMBBGradientFillTop,
  kAppFrameBigMBBGradientFillMiddleUpper,
  kAppFrameBigMBBGradientFillMiddleLower,
  kAppFrameBigMBBGradientFillBottom,

  kAppFrameSmallMBBGradientFillTop,
  kAppFrameSmallMBBGradientFillMiddleUpper,
  kAppFrameSmallMBBGradientFillMiddleLower,
  kAppFrameSmallMBBGradientFillBottom,

  kAppFrameDocNameProductNameText,
  kAppFrameDocNameFileNameText,
  kAppFrameDocNameInactiveProductNameText,
  kAppFrameDocNameInactiveFileNameText,
  kAppFrameMenuBarMenuText,
  kAppFrameMenuBarMenuHighlightText,
  kAppFrameMenuBarMenuDeHighlightText,
  kAppFrameMenuBarRolloverBorder,
  kAppFrameMenuBarRolloverFill,
  kAppFrameMenuBarClickBorder,
  kAppFrameMenuBarClickFill,
  kAppFrameAppWindowControlButtonsRolloverGradientBorderTop,
  kAppFrameAppWindowControlButtonsRolloverGradientBorderMiddle,
  kAppFrameAppWindowControlButtonsRolloverGradientBorderBottom,
  kAppFrameAppWindowControlButtonsRolloverGradientFillTop,
  kAppFrameAppWindowControlButtonsRolloverGradientFillMiddleUpper,
  kAppFrameAppWindowControlButtonsRolloverGradientFillMiddleLower,
  kAppFrameAppWindowControlButtonsRolloverGradientFillBottom,
  kAppFrameAppWindowControlButtonsClickGradientBorderTop,
  kAppFrameAppWindowControlButtonsClickGradientBorderMiddle,
  kAppFrameAppWindowControlButtonsClickGradientBorderBottom,
  kAppFrameAppWindowControlButtonsClickGradientFillTop,
  kAppFrameAppWindowControlButtonsClickGradientFillMiddleUpper,
  kAppFrameAppWindowControlButtonsClickGradientFillMiddleLower,
  kAppFrameAppWindowControlButtonsClickGradientFillBottom,
  kAppFrameInfoCenterToggleButtonText,
  kAppFrameZeroDocBackgroundGradientTop,
  kAppFrameZeroDocBackgroundGradientBottom,

  kStatusBarPaneUnSelectedTopGradient,
  kStatusBarPaneUnSelectedBottomGradient,
  kStatusBarPaneRolloverGradient1,
  kStatusBarPaneRolloverGradient2,
  kStatusBarPaneRolloverGradient3,
  kStatusBarPaneRolloverGradient4,
  kStatusBarPaneSelectionGradient1,
  kStatusBarPaneSelectionGradient2,
  kStatusBarPaneSelectionGradient3,
  kStatusBarPaneSelectionGradient4,
  kStatusBarPaneBorder1,
  kStatusBarPaneBorder2,
  kStatusBarBkGrdBorder,
  kStatusBarBkGrdInnerLine,
  kStatusBarBkGrdTopGradient,
  kStatusBarBkGrdBottomGradient,

  kToolbarGripDarkDot,
  kToolbarGripLightDot,
  kToolbarGripBackground,
  kToolbarBorder,
  kToolbarBackground,
  kToolbarRolloverBorder,
  kToolbarCloseButton,

  kSquareButtonHoverBorder,
  kSquareButtonHoverHighlight,
  kSquareButtonHoverBackgroundTop,
  kSquareButtonHoverBackgroundBottom,
  kSquareButtonClickBorder,
  kSquareButtonClickHighlight,
  kSquareButtonClickBackgroundTop,
  kSquareButtonClickBackgroundBottom,

  kComboBoxBackgroundTop,
  kComboBoxBackgroundBottom,
  kComboBoxActiveBackgroundTop,
  kComboBoxActiveBackgroundBottom,
  kComboBoxArrow,
  kComboBoxArrowShadow,
  kComboBoxHoverText,
  kComboBoxSelectText,
  kComboBoxHoverBackgroundTop,
  kComboBoxHoverBackgroundBottom,
  kComboBoxSelectBackgroundTop,
  kComboBoxSelectBackgroundBottom,
  kComboBoxHoverSelectHighlight,

  kSpinControlHighlight,
  kSpinControlBorder,
  kSpinControlClickBackgroundTop,
  kSpinControlClickBackgroundBottom,
  kSpinControlBackgroundTop,
  kSpinControlBackgroundBottom,

  kTextInputInnerShadow,
  kTextInputActiveBackgroundTop,
  kTextInputActiveBackgroundBottom,
  kTextInputActiveHighlight,
  kTextInputActiveText,
  kTextInputActiveBorder,

  kCategoryExpander,
  kCategoryExpanderShadow,
  kGroupGrip,
  kGroupGripShadow,
  kCategoryBackground,
  kCategoryBorder,
  kCategoryActiveText,

  kListBoxHoverBackgroundTop,
  kListBoxHoverBackgroundBottom,
  kListBoxHoverBorder,
  kListBoxClickBackgroundTop,
  kListBoxClickBackgroundBottom,
  kListBoxClickBorder,
  kListBoxSelectBackgroundTop,
  kListBoxSelectBackgroundBottom,
  kListBoxSelectBorder,
  kListBoxSelectHoverBackgroundTop,
  kListBoxSelectHoverBackgroundBottom,
  kListBoxSelectHoverBorder,
  kListBoxInnerShadow,
  kListBoxSelectText,

  kTreeControlLine,

  kThemeElementReserved,

  kCommandLineHintBackgroundColor,
  kCommandLineHintBorderColor,
  kCommandLineHintTextColor,

  kCommandLineHintSelectBackgroundColor,
  kCommandLineHintSelectBorderColor,
  kCommandLineHintSelectTextColor,
  kCommandLineHintHeaderBackgroundColor,
  kCommandLineHintHeaderTextColor,

  kAnchorBarBackground,

  kAppFrameCaptionInactiveBorder,
  kAppFrameAppWindowControlButtonsRolloverBorder,
  kAppFrameAppWindowControlButtonsRolloverSymbol,
  kAppFrameAppWindowControlButtonsClickBorder,
  kAppFrameAppWindowControlButtonsClickSymbol,
  kAppFrameAppWindowControlButtonsSymbol,

  kControlDisabledText,

  kSquareButtonBorder,
  kSquareButtonBackground,
  kSquareButtonDisabledBorder,
  kSquareButtonDisabledBackground,
  kSquareButtonToggledBorder,
  kSquareButtonToggledBackground,
  kSquareButtonToggledHoverBorder,
  kSquareButtonToggledHoverBackground,
  kSquareButtonToggledDisabledBorder,
  kSquareButtonToggledDisabledBackground,

  kTreeControlBorder,
  kTreeControlSelectBackground,
  kTreeControlSelectActiveBackground,
  kTreeControlSelectInactiveBackground,
  kTreeControlText,
  kTreeControlDisabledText,
  kTreeControlInactiveText,
  kTreeControlSelectText,
  kTreeControlSelectInactiveText,

  kComboBoxText,
  kComboBoxDisabledText,
  kComboBoxBorder,
  kComboBoxHoverBorder,
  kComboBoxSeparator,

  kTextInputText,
  kTextInputDisabledText,
  kTextInputInactiveText,

  kSpinControlArrow,

  kListBoxBorder,
  kListBoxGrid,
  kListBoxSelectInactiveBackgroundTop,
  kListBoxSelectInactiveBackgroundBottom,
  kListBoxText,
  kListBoxDisabledText,
  kListBoxInactiveText,
  kListBoxSelectInactiveText,
  kListBoxColumnHeaderBackgroundTop,
  kListBoxColumnHeaderBackgroundBottom,
  kListBoxColumnHeaderBorder,
  kListBoxColumnHeaderText,
  kListBoxColumnHeaderArrow,
  kListBoxColumnHeaderSortCellBackgroundTop,
  kListBoxColumnHeaderSortCellBackgroundBottom,
  kListBoxGroupHeaderText,

  kTreeControlSelectDisabledText,

  kTextInputBackground,
  kTextInputBorder,

  kListBoxSelectDisabledText,

} GdUiThemeElement;

class CGdUiThemeModifiedReactor
{
public:
  virtual void ThemeModified(const CGdUiTheme * pTheme, GdUiThemeElement element) = 0;
};

class GCAD_PORT CGdUiTheme
{
  friend class CGdUiThemeManager;

public:
  COLORREF GetColor(GdUiThemeElement nDisplayElement) const;
  DWORD GetARGBColor(GdUiThemeElement nDisplayElement) const;
  BOOL SetColor(GdUiThemeElement nDisplayElement, COLORREF crColor);
  BOOL SetARGBColor(GdUiThemeElement nDisplayElement, DWORD dColor);

  BOOL SetFont(GdUiThemeElement nDisplayElement, LOGFONT *plf = NULL);
  BOOL GetFont(GdUiThemeElement nDisplayElement, LOGFONT *plf) const;
  BOOL GetFont(GdUiThemeElement nDisplayElement, CFont *& pFont) const;

  BOOL GetData(int nElement, DWORD& dwData) const;
  void SetData(int nElement, const DWORD& dwData);
  BOOL GetData(int nElement, CString& sData) const;
  void SetData(int nElement, const CString& sData);

  void* GetDataPtr(int nElement) const;
  void SetDataPtr(int nElement, void* pData);

  BOOL RegisterReactor(CGdUiThemeModifiedReactor * pReactor);
  BOOL UnregisterReactor(CGdUiThemeModifiedReactor * pReactor);

  void SuspendModifiedNotifications() { m_nModNotificationsSuspended++; }
  void ResumeModifiedNotifications();
  void SendModifiedNotification() const;

  bool UsesActiveThemeColors() const { return m_pColorTheme == NULL; }
  bool IsDark() const;
  void IncrementRefCount() { m_nRefCount++; }

  CGdUiTheme& operator=(const CGdUiTheme& Theme);

  static COLORREF GetRGBForeColor(DWORD fgColor, COLORREF bgColor);

private:
  CGdUiTheme();
  CGdUiTheme(const CGcColorTheme & colorTheme, GcColorThemeEnum themeType);
  virtual ~CGdUiTheme();
  void commonInitialize();
  void SetColorTheme(const CGcColorTheme& colorTheme, GcColorThemeEnum themeType);
  void InitializeFont(LOGFONT & sourceLF, LOGFONT & destLF, int fontType = 0);
  void InitializeFontsForDialog();

  void SendThemeModifiedNotifications(GdUiThemeElement nElement) const;

  void CheckXP();
  BOOL UsesXP() { return m_bUsesXPThemes; };

  void DecrementRefCount() { m_nRefCount--; }
  int RefCount() { return m_nRefCount; }

  int    m_nRefCount;
  CTypedPtrArray<CPtrArray, CGdUiThemeModifiedReactor*> m_arrayModReactors;
  int m_nModNotificationsSuspended;
  CMap<int, int, DWORD, DWORD> m_mapDwordValues;
  CMap<int, int, CString, CString> m_mapStringValues;
  CMap<int, int, void*, void*> m_mapPointerValues;

  LOGFONT             m_lfWorksheet;
  LOGFONT             m_lfWorksheetCaption;
  LOGFONT             m_lfPaletteCaption;
  LOGFONT             m_lfInspectorItem;
  LOGFONT             m_lfInspectorRoot;
  LOGFONT             m_lfPaletteTab;
  LOGFONT             m_lfPalette;
  LOGFONT             m_lfPaletteToolTip;

  CGcColorTheme*      m_pColorTheme;
  GcColorThemeEnum    m_themeType;

  BOOL                m_bUsesXPThemes;
};

#endif 
#endif 
