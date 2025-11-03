#pragma once

class ZCDB_PORT ZcPointCloudColorSchemeCollectionReactor
{
public:

    virtual void PointCloudColorSchemeCollectionChanged(class ZcDbPointCloudColorMap* colorMap) = 0;

    virtual ~ZcPointCloudColorSchemeCollectionReactor();
};

class PointCloudColorMapImp;

class ZCDB_PORT ZcDbPointCloudColorRamp
{
public:

    ZcDbPointCloudColorRamp();

    ~ZcDbPointCloudColorRamp();

    ZSoft::Int32            numColors() const;

    Zcad::ErrorStatus       setNumColors(ZSoft::Int32 count);

    ZcCmEntityColor         color(int c) const;

    void                    setColor(int c, ZcCmEntityColor color);

    bool                    visibility(int c) const;

    void                    setVisibility(int c, bool visibility);

    void                    setFrom(const ZcDbPointCloudColorRamp* source);

    const ZcString          name() const;

    Zcad::ErrorStatus       setName(const ZcString& name);

private:
friend class PointCloudColorMapImp;
    Zcad::ErrorStatus       dwgOutFields(ZcDbDwgFiler* pFiler) const;
    Zcad::ErrorStatus       dwgInFields(ZcDbDwgFiler* pFiler);
    Zcad::ErrorStatus       dxfOutFields(ZcDbDxfFiler* pFiler) const;
    Zcad::ErrorStatus       dxfInFields(ZcDbDxfFiler* pFiler);
	
    class PointCloudColorRampImp* pImpl;
};

class ZCDB_PORT ZcDbPointCloudClassificationColorRamp
{
public:

    ZcDbPointCloudClassificationColorRamp();

    ~ZcDbPointCloudClassificationColorRamp();

    ZSoft::Int32            numColors() const;

    ZcCmEntityColor         color(int c) const;

    void                    setColor(int c, ZcCmEntityColor color);

    bool                    visibility(int c) const;

    void                    setVisibility(int c, bool visibility);

    void                    setFrom(const ZcDbPointCloudClassificationColorRamp* source);

    const ZcString          name() const;

    Zcad::ErrorStatus       setName(const ZcString& name);

private:
friend class PointCloudColorMapImp;
    Zcad::ErrorStatus       dwgOutFields(ZcDbDwgFiler* pFiler) const;
    Zcad::ErrorStatus       dwgInFields(ZcDbDwgFiler* pFiler);
    Zcad::ErrorStatus       dxfOutFields(ZcDbDxfFiler* pFiler) const;
    Zcad::ErrorStatus       dxfInFields(ZcDbDxfFiler* pFiler);
	
    class PointCloudClassificationColorRampImp* pImpl;
};

class ZCDB_PORT ZcDbPointCloudColorMap : public ZcDbObject
{
friend class PointCloudColorMapImp;
friend class ZcDbPointCloudMgr;

    static const ZSoft::UInt16  kCurrentObjectVersion;

public:
    ZCRX_DECLARE_MEMBERS(ZcDbPointCloudColorMap);

    static Zcad::ErrorStatus getColorMap(ZcDbObjectId& id, ZcDbDatabase* pDb, bool bCreateIfNone = true);

    virtual ~ZcDbPointCloudColorMap();

    void                            addColorSchemeCollectionReactor(ZcPointCloudColorSchemeCollectionReactor* pReactor);

    void                            removeColorSchemeCollectionReactor(ZcPointCloudColorSchemeCollectionReactor* pReactor);

    void                            notifyColorSchemeCollectionChanged() const;

    const ZcString                  defaultIntensityColorScheme() const;

    bool                            setDefaultIntensityColorScheme(const ZcString GUID);

    const ZcString                  defaultElevationColorScheme() const;

    bool                            setDefaultElevationColorScheme(const ZcString GUID);

    const ZcString                  defaultClassificationColorScheme() const;

    bool                            setDefaultClassificationColorScheme(const ZcString GUID);

    ZcArray<ZcString>               colorSchemeGUIDs() const;

    bool                            colorScheme(const wchar_t* GUID, ZcDbPointCloudColorRamp& target) const;

    bool                            hasColorScheme(const wchar_t* GUID) const;

    bool                            setColorScheme(const wchar_t* GUID, const ZcDbPointCloudColorRamp& source);

    bool                            deleteColorScheme(const wchar_t* GUID);

    ZcArray<ZcString>               classificationSchemeGUIDs() const;

    bool                            classificationScheme(const wchar_t* GUID, ZcDbPointCloudClassificationColorRamp& target) const;

    bool                            hasClassificationScheme(const wchar_t* GUID) const;

    bool                            setClassificationScheme(const wchar_t* GUID, const ZcDbPointCloudClassificationColorRamp& source);

    bool                            deleteClassificationScheme(const wchar_t* GUID);

    void                            getColorSchemeInUse(ZcArray<ZcString>& GUIDs) const;

    void                            getClassificationColorSchemeInUse(ZcArray<ZcString>& GUIDs) const;

    virtual Zcad::ErrorStatus       dwgInFields(ZcDbDwgFiler* pFiler) override;

    virtual Zcad::ErrorStatus       dwgOutFields(ZcDbDwgFiler* pFiler) const override;

    virtual Zcad::ErrorStatus       dxfInFields(ZcDbDxfFiler* pFiler) override;

    virtual Zcad::ErrorStatus       dxfOutFields(ZcDbDxfFiler* pFiler) const override;

    virtual Zcad::ErrorStatus       subClose() override;

private:
    ZcDbPointCloudColorMap();
    ZcDbPointCloudColorMap(bool initializeDefaults);
    PointCloudColorMapImp *pImpl;
};
