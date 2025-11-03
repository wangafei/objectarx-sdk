
#pragma once

#include "zadui.h"
#include "zacfdui.h"

class ZcTcUiSystemInternals;
class CZcFdUiFieldDialog;
class CZcFdUiFieldDialogHook;
class CZcFdUiImpFieldDialog;
class ZcDbField;

class ZCFDUI_PORT CZcFdUiFieldOptionDialog : public CZdUiDialog
{
    friend CZcFdUiFieldDialog;
    friend CZcFdUiImpFieldDialog;

    DECLARE_DYNAMIC(CZcFdUiFieldOptionDialog)

public:
    CZcFdUiFieldOptionDialog(CZcFdUiFieldDialogHook* pDialogHook, CZcFdUiFieldDialog* pFieldDlg,
        UINT nIDTemplate, HINSTANCE hDialogResource = NULL);
    ~CZcFdUiFieldOptionDialog();

    CZcFdUiFieldDialogHook* GetFieldDialogHook(void) const;
    CZcFdUiFieldDialog* GetFieldDialog      (void) const;
    virtual BOOL    Create                  (CWnd* pParent);

public:

    virtual BOOL    Create                  (LPCTSTR lpszTemplateName,
                                             CWnd* pParent = NULL);
    virtual BOOL    Create                  (UINT nIDTemplate,
                                             CWnd* pParent = NULL);

protected:
    virtual BOOL    OnSetActive             (void);
    virtual BOOL    OnKillActive            (void);
    virtual BOOL    OnFieldSelected         (UINT uNewFieldId);

protected:

    void            OnOK                    () override;
    void            OnCancel                () override;

protected:
    void DoDataExchange(CDataExchange* pDX) override;
    afx_msg LRESULT OnFormatChanged         (WPARAM wParam,
                                             LPARAM lParam);
    afx_msg LRESULT OnBeginFormatExDialog   (WPARAM wParam,
                                             LPARAM lParam);
    afx_msg LRESULT OnEndFormatExDialog     (WPARAM wParam,
                                             LPARAM lParam);
    DECLARE_MESSAGE_MAP()

protected:
    void            *   mpImpObj;

private:
    friend class ZcFdUiSystemInternals;
};
