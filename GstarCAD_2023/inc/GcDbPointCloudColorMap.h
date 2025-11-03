/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

class DBPOINTCLOUDOBJ_PORT GcPointCloudColorSchemeCollectionReactor
{
public:
  virtual void PointCloudColorSchemeCollectionChanged(class GcDbPointCloudColorMap* colorMap) = 0;

  virtual ~GcPointCloudColorSchemeCollectionReactor();
};

class PointCloudColorMapImp;

class DBPOINTCLOUDOBJ_PORT GcDbPointCloudColorRamp
{
public:

  GcDbPointCloudColorRamp();
  ~GcDbPointCloudColorRamp();

  Gsoft::Int32            numColors() const;
  Gcad::ErrorStatus       setNumColors(Gsoft::Int32 count);

  GcCmEntityColor         color(int c) const;
  void                    setColor(int c, GcCmEntityColor color);

  bool                    visibility(int c) const;
  void                    setVisibility(int c, bool visibility);

  void                    setFrom(const GcDbPointCloudColorRamp* source);

  const GcString          name() const;
  Gcad::ErrorStatus       setName(const GcString& name);

private:
  friend class PointCloudColorMapImp;
  Gcad::ErrorStatus       dwgOutFields(GcDbDwgFiler* pFiler) const;
  Gcad::ErrorStatus       dwgInFields(GcDbDwgFiler* pFiler);
  Gcad::ErrorStatus       dxfOutFields(GcDbDxfFiler* pFiler) const;
  Gcad::ErrorStatus       dxfInFields(GcDbDxfFiler* pFiler);

  class PointCloudColorRampImp* pImpl;
};

class DBPOINTCLOUDOBJ_PORT GcDbPointCloudClassificationColorRamp
{
public:

  GcDbPointCloudClassificationColorRamp();
  ~GcDbPointCloudClassificationColorRamp();

  Gsoft::Int32            numColors() const;

  GcCmEntityColor         color(int c) const;
  void                    setColor(int c, GcCmEntityColor color);

  bool                    visibility(int c) const;
  void                    setVisibility(int c, bool visibility);

  void                    setFrom(const GcDbPointCloudClassificationColorRamp* source);

  const GcString          name() const;
  Gcad::ErrorStatus       setName(const GcString& name);

private:
  friend class PointCloudColorMapImp;
  Gcad::ErrorStatus       dwgOutFields(GcDbDwgFiler* pFiler) const;
  Gcad::ErrorStatus       dwgInFields(GcDbDwgFiler* pFiler);
  Gcad::ErrorStatus       dxfOutFields(GcDbDxfFiler* pFiler) const;
  Gcad::ErrorStatus       dxfInFields(GcDbDxfFiler* pFiler);

  class PointCloudClassificationColorRampImp* pImpl;
};

class DBPOINTCLOUDOBJ_PORT GcDbPointCloudColorMap : public GcDbObject
{
  friend class PointCloudColorMapImp;
  friend class GcDbPointCloudMgr;

  static const Gsoft::UInt16  kCurrentObjectVersion;

public:
  GCRX_DECLARE_MEMBERS(GcDbPointCloudColorMap);

  static Gcad::ErrorStatus getColorMap(GcDbObjectId& id, GcDbDatabase* pDb, bool bCreateIfNone = true);

  ~GcDbPointCloudColorMap();

  void                            addColorSchemeCollectionReactor(GcPointCloudColorSchemeCollectionReactor* pReactor);
  void                            removeColorSchemeCollectionReactor(GcPointCloudColorSchemeCollectionReactor* pReactor);

  void                            notifyColorSchemeCollectionChanged() const;

  const GcString                  defaultIntensityColorScheme() const;
  bool                            setDefaultIntensityColorScheme(const GcString GUID);

  const GcString                  defaultElevationColorScheme() const;
  bool                            setDefaultElevationColorScheme(const GcString GUID);

  const GcString                  defaultClassificationColorScheme() const;
  bool                            setDefaultClassificationColorScheme(const GcString GUID);

  GcArray<GcString>               colorSchemeGUIDs() const;

  bool                            colorScheme(const wchar_t* GUID, GcDbPointCloudColorRamp& target) const;
  bool                            hasColorScheme(const wchar_t* GUID) const;
  bool                            setColorScheme(const wchar_t* GUID, const GcDbPointCloudColorRamp& source);
  bool                            deleteColorScheme(const wchar_t* GUID);

  GcArray<GcString>               classificationSchemeGUIDs() const;

  bool                            classificationScheme(const wchar_t* GUID, GcDbPointCloudClassificationColorRamp& target) const;
  bool                            hasClassificationScheme(const wchar_t* GUID) const;
  bool                            setClassificationScheme(const wchar_t* GUID, const GcDbPointCloudClassificationColorRamp& source);
  bool                            deleteClassificationScheme(const wchar_t* GUID);

  void                            getColorSchemeInUse(GcArray<GcString>& GUIDs) const;
  void                            getClassificationColorSchemeInUse(GcArray<GcString>& GUIDs) const;

  Gcad::ErrorStatus       dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus       dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus       dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus       dxfOutFields(GcDbDxfFiler* pFiler) const override;

  Gcad::ErrorStatus       subClose() override;

private:
  GcDbPointCloudColorMap();
  GcDbPointCloudColorMap(bool initializeDefaults);
  PointCloudColorMapImp *pImpl;
};