
#pragma once
#include "zacui_port.h"
#include "zaduiDock.h"

#pragma pack (push, 8)

class ZCUI_PORT CZcUiDockFrame : public CZdUiDockFrame {
    DECLARE_DYNCREATE(CZcUiDockFrame);

public:
                CZcUiDockFrame ();
virtual         ~CZcUiDockFrame ();

public:

protected:

    afx_msg LRESULT OnZCADKeepFocus (WPARAM wParam, LPARAM lParam);

    DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiDockControlBar : public CZdUiDockControlBar {
    DECLARE_DYNCREATE(CZcUiDockControlBar);

public:
    CZcUiDockControlBar () {}

protected:
    virtual bool CanFrameworkTakeFocus () override;
};

#ifndef NEW_PALETTE

class ZCUI_PORT CZcUiPaletteSetDockFrame : public CZdUiPaletteSetDockFrame {
    DECLARE_DYNCREATE(CZcUiPaletteSetDockFrame);

public:
                CZcUiPaletteSetDockFrame ();
virtual         ~CZcUiPaletteSetDockFrame ();

public:

protected:

    afx_msg LRESULT OnZCADKeepFocus (WPARAM wParam, LPARAM lParam);
    afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);

    DECLARE_MESSAGE_MAP()
};
#endif

#pragma pack (pop)


