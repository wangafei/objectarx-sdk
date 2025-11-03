
#pragma once

class ZcDbSectionablePE : public ZcRxObject
{
public:
    
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcDbSectionablePE, ZCDBCORE2D_PORT);

    virtual bool supportSection(const ZcDbObject& pObject) = 0;
};