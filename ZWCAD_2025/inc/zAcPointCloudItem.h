#pragma once

#include "zacarray.h"
#include "zadsdef.h"
#include "zacstring.h"

class ZcPointCloudItem;
typedef ZcPointCloudItem* PPointCloudItem;
typedef ZcArray<ZcPointCloudItem*> ZcPointCloudItemArray;

class ZCDB_PORT ZcPointCloudItem
{
public:
    enum ZcPointCloudItemType
    {
        kLegacyPointCloud = 0,

        kPointCloudProject,

        kIndividualScan,

        kScan,

        kRegion,

        kScanRootGroup,

        kRegionRootGroup,

        kUnassignedPoint
    };

    ZcPointCloudItem();
    ~ZcPointCloudItem() {}

    ZcPointCloudItem(const ZcString& name, const ZcString& projectname, int objectid, ZcPointCloudItemType categoryid, bool visibility = true, bool highlight = false, ZcString guid = L"");
    ZcPointCloudItem(const ZcPointCloudItem& item);
    ZcPointCloudItem& operator =  (const ZcPointCloudItem& other);

    static ZcPointCloudItem* CreateFromCmdString(const ZTCHAR* cmd);

public:
    void        setName(const ZcString& val);
    ZcString    name() const;

    void        setProjectName(const ZcString& val);
    ZcString    projectName() const;

    void        setGuid(const ZcString& val);
    const ZcString&    guid() const;

    void        setId(int val);
    int         id() const;

    void        setVisibility(bool val);
    bool        visibility() const;

    void        setHighlight(bool val);
    bool        highlight() const;

    void        setColor(float red, float green, float blue);
    float       red() const;
    float       green() const;
    float       blue() const;

    void                    setZdsName(const zds_name& val);
    const zds_name&         zdsName() const;

    void                    setItemType(ZcPointCloudItemType val);
    ZcPointCloudItemType    itemType() const;

private:
    void        copyItem(const ZcPointCloudItem& other);

private:
    ZcString    m_name;
    ZcString    m_projectName;
    ZcString    m_guid;
    int         m_id;
    bool        m_visibility;
    bool        m_highlight;
    zds_name    m_zdsName;
    float       m_red;
    float       m_green;
    float       m_blue;
    ZcPointCloudItemType    m_itemType;

};
