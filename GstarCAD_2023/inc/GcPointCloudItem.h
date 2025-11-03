/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gcarray.h"
#include "gdsdef.h"
#include "GcString.h"

class GcPointCloudItem;
typedef GcPointCloudItem* PPointCloudItem;
typedef GcArray<GcPointCloudItem*> GcPointCloudItemArray;

class DBPOINTCLOUDOBJ_PORT GcPointCloudItem
{
public:
  enum GcPointCloudItemType
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

  GcPointCloudItem();
  ~GcPointCloudItem() {}
  GcPointCloudItem(const GcString& name, const GcString& projectname, int objectid, GcPointCloudItemType categoryid, bool visibility = true, bool highlight = false, GcString guid = L"");
  GcPointCloudItem(const GcPointCloudItem& item);

  GcPointCloudItem& operator =  (const GcPointCloudItem& other);

  static GcPointCloudItem* CreateFromCmdString(const GCHAR* cmd);

public:
  void        setName(const GcString& val);
  GcString    name() const;

  void        setProjectName(const GcString& val);
  GcString    projectName() const;

  void        setGuid(const GcString& val);
  const GcString&    guid() const;

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

  void                    setGdsName(const gds_name& val);
  const gds_name&         gdsName() const;

  void                    setItemType(GcPointCloudItemType val);
  GcPointCloudItemType    itemType() const;

private:
  void        copyItem(const GcPointCloudItem& other);

private:
  GcString    m_name;
  GcString    m_projectName;
  GcString    m_guid;
  int         m_id;
  bool        m_visibility;
  bool        m_highlight;
  gds_name    m_gdsName;
  float       m_red;
  float       m_green;
  float       m_blue;
  GcPointCloudItemType    m_itemType;
};
