#ifndef _GDUI_THEME_H_
#define _GDUI_THEME_H_

#include <afxtempl.h>
//#include "gdui.h"

#define PROPERTY_PALETTE_THEME  /*MSG0*/"PropertyPalette"
#define TOOL_PALETTE_THEME      /*MSG0*/"ToolPalette"
#define OWNDERDRAW_BUTTON_THEME /*MSG0*/"OwnerDrawButton"
#define DIALOG_WORKSHEET_THEME  /*MSG0*/"DialogWorksheet"
#define PALETTE_SET_THEME       /*MSG0*/"PaletteSet"
#define DESIGN_CENTER_THEME     /*MSG0*/"DesignCenter"   // Constant theme for all apps, dom't override

typedef enum {
    
    kUnknownElements = -1,

    // Theme fonts
    kPaletteFontCaption,
    kPaletteFontTab,
    kPaletteFontToolTip,
    kPaletteFont,
    kWorksheetFont,
    kWorksheetFontCaption,
    kInspectorItemFont,
    kInspectorRootFont,

    // Theme colors

    // Palette Set Colors
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

    // Worksheets
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

    // Property Inspectors
    kInspector,
    kInspectorTop,
    kInspectorCat,
    kInspectorItem,
    kInspectorBorder,
    kInspectorBorderItem,
    kInspectorTextTop,
    kInspectorTextCat,
    kInspectorTextItem,
    kInspectorFGHighlight,
    kInspectorBGHighlight,
    kInspector3dShadow,
    kInspectorControl,
    kInspectorCatChevron1,
    kInspectorCatChevron2,
    kInspectorSubChevron,
	
	// Panel Colors
    kPanelBackground,
    kPanelSashBackground,
    kPanelBorder,
    kControlBorder,
    kControlBackground,  
    kDisabledControlBorder,
    kControlSupport,
	
	// Extra Palette Set Colors
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
	
	// Anchor Bar Colors
    kAnchorBarOuterBorder,
    kAnchorBarEmbossRightBottom,
    kAnchorBarEmbossLeftTop,
    kAnchorBarInnerHighlight,
    kAnchorBarGradient1,
    kAnchorBarGradient2,
    kAnchorBarActiveTitleBackground,
    kAnchorBarCaptionText,
	
	 // Other Colors
    kGrabBarDotDark,
    kGrabBarDotLight,
    kControlBarTitleBackground,
    
    // Application Frame Window Colors
    kAppFrameBorder,
    kAppFrameOuterBorder,

} GdUiThemeElement;


class CGdUiThemeModifiedReactor
{
public:
 //    virtual void ThemeModified(const CGdUiTheme * pTheme, GdUiThemeElement element) = 0;
};


class GDUI_PORT CGdUiTheme
{
    friend class CGdUiThemeManager;

public:
    // Returns the color of the specified display element. 
    COLORREF GetColor (GdUiThemeElement nDisplayElement) const;
    // Sets the color of the specified display element
    BOOL SetColor(GdUiThemeElement nDisplayElement, COLORREF crColor);

    BOOL SetFont(GdUiThemeElement nDisplayElement,LOGFONT *plf=NULL);
    BOOL GetFont(GdUiThemeElement nDisplayElement,LOGFONT *plf) const;
    BOOL GetFont(GdUiThemeElement nDisplayElement,CFont *& pFont) const;

    BOOL GetData(int nElement, DWORD& dwData) const;
    void SetData(int nElement, const DWORD& dwData);
    BOOL GetData(int nElement, CString& sData) const;
    void SetData(int nElement, const CString& sData);

    // Methods for registering a theme client with the theme for "Theme modified" notifications
    BOOL RegisterReactor(CGdUiThemeModifiedReactor * pReactor);
    BOOL UnregisterReactor(CGdUiThemeModifiedReactor * pReactor);

    void SuspendModifiedNotifications() { m_nModNotificationsSuspended++; }
    void ResumeModifiedNotifications();
    void SendModifiedNotification() const;

    void SetDataPtr(int nElement, void* pData);
    void* GetDataPtr(int nElement) const;
    bool UsesActiveThemeColors() { return false; }

    void IncrementRefCount() { m_nRefCount++; }

    // assignment operator
    CGdUiTheme& operator=(const CGdUiTheme *pTheme);
    
private:
    CGdUiTheme();
     virtual ~CGdUiTheme();

    void SendThemeModifiedNotifications(GdUiThemeElement nElement) const;

    void CheckXP();
    
    // Are XP themes supported (FUTURE USE!)
    BOOL UsesXP() { return m_bUsesXPThemes; };

    void DecrementRefCount() { m_nRefCount--; }
    int RefCount() { return m_nRefCount; }

    int    m_nRefCount;
    CTypedPtrArray<CPtrArray, CGdUiThemeModifiedReactor*> m_arrayModReactors;
    int m_nModNotificationsSuspended;
    CMap<int, int, DWORD, DWORD> m_mapDwordValues;
    CMap<int, int, CString, CString> m_mapStringValues;

    LOGFONT             m_lfWorksheet;
    LOGFONT             m_lfWorksheetCaption;
    LOGFONT             m_lfPaletteCaption;
    LOGFONT             m_lfInspectorItem;
    LOGFONT             m_lfInspectorRoot;
    LOGFONT             m_lfPaletteTab;
    LOGFONT             m_lfPalette;
    LOGFONT             m_lfPaletteToolTip;
    
    // Palettes
    COLORREF            m_crPaletteBkgnd;
    COLORREF            m_crPaletteCaptionBkgnd;
    COLORREF            m_crPaletteCaptionInactive;
    COLORREF            m_crPaletteCaptionText;
    COLORREF            m_crPaletteCaptionInactiveText;
    COLORREF            m_crPaletteItemText;
    COLORREF            m_crPaletteTabText;
    COLORREF            m_crPaletteTabBackground;
    COLORREF            m_crPaletteBorder;
    COLORREF            m_crPaletteTabShadow;
    COLORREF            m_crPaletteTabHighlight;
    COLORREF            m_crPaletteTabSelectHilite;
    COLORREF            m_crPaletteTabTextHilite;
    COLORREF            m_crPaletteScrollBackground;
    COLORREF            m_crPaletteScrollThumb;
    COLORREF            m_crPaletteScrollArrow;
    COLORREF            m_crPaletteButtonBorder;
    COLORREF            m_crPaletteButtonText;
    COLORREF            m_crPaletteButtonTextDisabled;
    COLORREF            m_crPaletteToolTip;
    COLORREF            m_crPaletteToolTipText;
  
    // Worksheets
    COLORREF            m_crWorksheetBkgnd;
    COLORREF            m_crWorksheetCaptionBkgnd;
    COLORREF            m_crWorksheetCaptionText;
    COLORREF            m_crWorksheetBtnShadow;
    COLORREF            m_crWorksheetBtnText;
    COLORREF            m_crWorksheetBtnTextDisabled;
    COLORREF            m_crWorksheetScroll;
    COLORREF            m_crWorksheetScrollThumb;
    COLORREF            m_crWorksheetBorder;
    COLORREF            m_crWorksheetGripHighlight;

    // Property inspectors
    COLORREF            m_crInspector;
    COLORREF            m_crInspectorTop;
    COLORREF            m_crInspectorCat;
    COLORREF            m_crInspectorItem;
    COLORREF            m_crInspectorBorder;
    COLORREF            m_crInspectorBorderItem;
    COLORREF            m_crInspectorTextTop;
    COLORREF            m_crInspectorTextCat;
    COLORREF            m_crInspectorTextItem;
    COLORREF            m_crInspectorFGHighlight;
    COLORREF            m_crInspectorBGHighlight;
    COLORREF            m_crInspector3dShadow;    
    COLORREF            m_crInspectorControl;
    COLORREF            m_crInspectorCatChevron1;
    COLORREF            m_crInspectorCatChevron2;
    COLORREF            m_crInspectorSubChevron;

    BOOL                m_bUsesXPThemes;    
    
};

#endif // ifndef _GDUI_THEME_H_

