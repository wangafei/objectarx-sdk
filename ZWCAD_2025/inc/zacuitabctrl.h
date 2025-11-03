
#pragma once
#include "zacui_port.h"
#include "zaduiTabCtrl.h"

#pragma pack (push, 8)

class ZCUI_PORT CZcUiTab : public CZdUiTab {
    DECLARE_DYNAMIC(CZcUiTab);

public:
                CZcUiTab ();
virtual         ~CZcUiTab ();

public:

protected:

    DECLARE_MESSAGE_MAP()
};

#pragma pack (pop)

