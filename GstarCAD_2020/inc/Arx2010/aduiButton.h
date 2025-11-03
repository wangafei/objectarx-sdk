#pragma once
#include "AdUiTheme.h" 
#include "../grx/gduiButton.h"

#define  CAdUiODButtonThemeModReactor  CGdUiODButtonThemeModReactor
#define  CAdUiOwnerDrawButton		   CGdUiOwnerDrawButton
#define  CAdUiBitmapButton			   CGdUiBitmapButton
#define  CAdUiBitmapStatic			   CGdUiBitmapStatic
#define  CAdUiDropSite				   CGdUiDropSite
#define  CAdUiToolButton			   CGdUiToolButton
#define  CAdUiTrackButton			   CGdUiTrackButton
#define  CAdUiBitmapTextButton		   CGdUiBitmapTextButton

class  CGdUiBitmapTextButton : public CGdUiBitmapButton
{
	friend class CAdUiImpBitmapButton;
	DECLARE_DYNAMIC(CGdUiBitmapTextButton)

public:
	enum ButtonType
	{
		kBitmap = 0x1,
		kText = 0x2,
	};

	enum BitmapLocation
	{
		kLeft = 0x1,
		kTop = 0x2,
		kRight = 0x4,
		kBottom = 0x8,
	};

	enum ButtonStyle
	{
		kButtonStyleNone = 0,
		kButtonStyleFlat = 0x1,
		kButtonStyleCheck = 0x2,

		kButtonHCenter = 0x00000300,
		kButtonVCenter = 0x00000C00,
	};

public:
	CGdUiBitmapTextButton() {}
	virtual ~CGdUiBitmapTextButton() {}

protected:
	virtual void DrawButton(
		CDC& dc, int w, int h,
		BOOL isDefault,
		BOOL isDisabled,
		BOOL isSelected,
		BOOL isFocused
	);
	virtual BOOL OnAutoLoad();
	virtual BOOL OnReload(LPCTSTR strResId);
	virtual BOOL OnLoadBitmap(LPCTSTR strResId);

public:
	BOOL                GetAutoSizeToContent();
	void                SetAutoSizeToContent(BOOL autoSizeToContent);
	void                SizeToContent();
	void                SetContentOffsets(int nBorderOffset,
		int nFocusRectOffset);
	UINT                GetButtonType();
	UINT                GetBitmapLocation();
	UINT                SetButtonType(UINT btnType);
	UINT                SetBitmapLocation(UINT imgPos);

	ButtonStyle			GetBitmapTextButtonStyle() const;
	void				SetBitmapTextButtonStyle(ButtonStyle nBtnStyle);

	DECLARE_MESSAGE_MAP()
public:
	BOOL				GetAutoSizeToBitmap();
	void				SetAutoSizeToBitmap(BOOL autoSizeToBitmap);
	void				SizeToBitmap();
	void				SetBitmapOffsets(int nBorderOffset, int nFocusRectOffset);

	void				SetBkColor(COLORREF);
	void				SetBorderColor(COLORREF);

	void				SetCheck(int nCheck);
	int					GetCheck();

	HICON				SetIcon(HICON hIcon, BOOL bRedraw = TRUE);
	HICON				GetIcon() const;
	HBITMAP				SetBitmap(HBITMAP hBitmap, BOOL bRedraw = TRUE);
	HBITMAP				GetBitmap() const;
private:
	void*               mpImpObj;
};
