#ifndef _GcuiEdit_h
#define _GcuiEdit_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// data styles
#define GC_ES_STRING                        0x01	
#define	GC_ES_SYMBOL                        0x02
#define GC_ES_NUMERIC                       0x04
#define GC_ES_ANGLE                         0x08

// behavior styles
#define GC_ES_VAL_ONKILLFOCUS               0x10
#define GC_ES_CONV_ONKILLFOCUS              0x20
#define GC_ES_SHOW_ERRMSG                   0x40
#define GC_ES_ERRMSG_ALLOWIGNORE            0x80

// validation styles
#define GC_ES_NOZERO                        0x100
#define GC_ES_NOBLANK                       0x200	
#define GC_ES_NONEGATIVE                    0x400
#define	GC_ES_INRANGE                       0x800

typedef enum {
    kGcUiError_None,                    // No error; OK.
    kGcUiError_Blank,                   // Data is blank
    kGcUiError_Symbol,                  // Detected illegal symbol syntax
    kGcUiError_Numeric,                 // Detected non-numeric data
    kGcUiError_Angle,                   // Data does not represent an angle
    kGcUiError_Zero,                    // Data is zero
    kGcUiError_Negative,                // Data is negative
    kGcUiError_Range                    // Data is out of range
} GCUI_ERROR_CODE;

class GCUI_PORT CGcUiEdit : public CGdUiEdit {
  DECLARE_DYNAMIC(CGcUiEdit)

public:
  CGcUiEdit ();
  virtual ~CGcUiEdit ();
  virtual void SetStyleMask (DWORD mask);
  void    Convert ();             // data style conversion
  BOOL    ConvertData (CString& x);
  BOOL    HasChanged ();          // detect user changes
  void    SetDirty ();
  void    SetRange (double vMin, double vMax);
  BOOL    Validate ();			// data validation
  GCUI_ERROR_CODE ValidateData (CString& x);

protected:
  virtual GDUI_REPLY DoGdUiMessage (GDUI_NOTIFY notifyCode, UINT controlId, LPARAM lParam);

private:
  void    DisplayError (UINT); 

private:
  BOOL    m_bWantsFocus;
  BOOL    m_bWasValid;
public:
  BOOL    m_bChanged;
  double  m_dMinValue;
  double  m_dMaxValue;
  CString m_csMsg;
  BOOL    m_bTouch;
public:
  //{{AFX_VIRTUAL(CGcUiEdit)
  //}}AFX_VIRTUAL

protected:
  //{{AFX_MSG(CGcUiEdit)
  afx_msg BOOL OnChange();
  afx_msg void OnErrSpace();
  afx_msg void OnKillFocus(CWnd* pNewWnd);
  //}}AFX_MSG

  DECLARE_MESSAGE_MAP()
};

class GCUI_PORT CGcUiAngleEdit : public CGcUiEdit {
    DECLARE_DYNAMIC(CGcUiAngleEdit)

public:
                CGcUiAngleEdit ();
virtual         ~CGcUiAngleEdit ();

virtual void    SetStyleMask (DWORD mask);

public:
	//{{AFX_VIRTUAL(CGcUiAngleEdit)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CGcUiAngleEdit)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

class GCUI_PORT CGcUiNumericEdit : public CGcUiEdit {
    DECLARE_DYNAMIC(CGcUiNumericEdit)

public:
                CGcUiNumericEdit ();
virtual         ~CGcUiNumericEdit ();

virtual void    SetStyleMask (DWORD mask);

public:
	//{{AFX_VIRTUAL(CGcUiNumericEdit)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CGcUiNumericEdit)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

class GCUI_PORT CGcUiStringEdit : public CGcUiEdit {
    DECLARE_DYNAMIC(CGcUiStringEdit)

public:
	            CGcUiStringEdit ();
virtual         ~CGcUiStringEdit ();

virtual void    SetStyleMask (DWORD mask);

public:
	//{{AFX_VIRTUAL(CGcUiStringEdit)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CGcUiStringEdit)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

class GCUI_PORT CGcUiSymbolEdit : public CGcUiEdit {
    DECLARE_DYNAMIC(CGcUiSymbolEdit)

public:
                CGcUiSymbolEdit ();
virtual         ~CGcUiSymbolEdit ();

virtual void    SetStyleMask (DWORD mask);

public:
	//{{AFX_VIRTUAL(CGcUiSymbolEdit)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CGcUiSymbolEdit)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

#pragma pack (pop)
#endif