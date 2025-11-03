/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gcuiEdit_h
#define _gcuiEdit_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif 


#define GC_ES_STRING                        0x01	
#define	GC_ES_SYMBOL                        0x02
#define GC_ES_NUMERIC                       0x04
#define GC_ES_ANGLE                         0x08

#define GC_ES_VAL_ONKILLFOCUS               0x10
#define GC_ES_CONV_ONKILLFOCUS              0x20
#define GC_ES_SHOW_ERRMSG                   0x40
#define GC_ES_ERRMSG_ALLOWIGNORE            0x80

#define GC_ES_NOZERO                        0x100
#define GC_ES_NOBLANK                       0x200	
#define GC_ES_NONEGATIVE                    0x400
#define	GC_ES_INRANGE                       0x800

typedef enum {
  kGcUiError_None,
  kGcUiError_Blank,
  kGcUiError_Symbol,
  kGcUiError_Numeric,
  kGcUiError_Angle,
  kGcUiError_Zero,
  kGcUiError_Negative,
  kGcUiError_Range
} GCUI_ERROR_CODE;

class GCAD_PORT CGcUiEdit : public CGdUiEdit {
  DECLARE_DYNAMIC(CGcUiEdit)
public:
  CGcUiEdit();
  ~CGcUiEdit();

private:
  BOOL    m_bWantsFocus;
  BOOL    m_bWasValid;

protected:
  GDUI_REPLY DoGdUiMessage(
    GDUI_NOTIFY notifyCode,
    UINT controlId,
    LPARAM lParam) override;

public:
  void    SetStyleMask(DWORD mask) override;

private:
  void    DisplayError(UINT);
public:
  BOOL    m_bChanged;
  double  m_dMinValue;
  double  m_dMaxValue;
  CString m_csMsg;
  BOOL    m_bTouch;

  void    Convert();
  BOOL    ConvertData(CString& x);
  BOOL    HasChanged();
  void    SetDirty();
  void    SetRange(double vMin, double vMax);
  BOOL    Validate();
  GCUI_ERROR_CODE ValidateData(CString& x);

protected:
  afx_msg BOOL OnChange();
  afx_msg void OnErrSpace();
  afx_msg void OnKillFocus(CWnd* pNewWnd);

  DECLARE_MESSAGE_MAP()
};

class GCAD_PORT CGcUiAngleEdit : public CGcUiEdit {
  DECLARE_DYNAMIC(CGcUiAngleEdit)
public:
  CGcUiAngleEdit();
  ~CGcUiAngleEdit();

public:
  void    SetStyleMask(DWORD mask) override;

protected:
  DECLARE_MESSAGE_MAP()
};

class GCAD_PORT CGcUiNumericEdit : public CGcUiEdit {
  DECLARE_DYNAMIC(CGcUiNumericEdit)
public:
  CGcUiNumericEdit();
  ~CGcUiNumericEdit();

public:
  void    SetStyleMask(DWORD mask) override;

protected:
  DECLARE_MESSAGE_MAP()
};

class GCAD_PORT CGcUiStringEdit : public CGcUiEdit {
  DECLARE_DYNAMIC(CGcUiStringEdit)
public:
  CGcUiStringEdit();
  ~CGcUiStringEdit();

public:
  void    SetStyleMask(DWORD mask) override;

protected:
  DECLARE_MESSAGE_MAP()
};

class GCAD_PORT CGcUiSymbolEdit : public CGcUiEdit {
  DECLARE_DYNAMIC(CGcUiSymbolEdit)
public:
  CGcUiSymbolEdit();
  ~CGcUiSymbolEdit();

public:
  void    SetStyleMask(DWORD mask) override;

protected:
  DECLARE_MESSAGE_MAP()
};

#pragma pack (pop)
#endif