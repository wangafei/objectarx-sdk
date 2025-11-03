
#pragma once
#pragma pack(push, 8)

class ZcDbImpHomeView;

class ZCDBCORE2D_PORT ZcDbHomeView
{
public:
    ZcDbHomeView();
    ZcDbHomeView(const ZcDbHomeView& rhvw);
    virtual ~ZcDbHomeView();

    
    const ZcGePoint3d&     eye()           const;
    const ZcGePoint3d&     center()        const;
    const ZcGeVector3d&    up()            const;
    const double           width()         const;
    const double           height()        const;
    const bool             isPerspective() const;

    void setEye         (const ZcGePoint3d& ptEye);
    void setCenter      (const ZcGePoint3d& ptCenter);
    void setUp          (const ZcGeVector3d& vUp);
    void setWidth       (double dWidth);
    void setHeight      (double dHeight);
    void setPerspective (bool bPerspective);

    
    Zcad::ErrorStatus setHomeView(ZcDbDatabase * pDb) const;
    Zcad::ErrorStatus getHomeView(ZcDbDatabase * pDb,
                                            bool           bCreateDefault = false);

    
    void toggleDefaultSettings();

    bool            operator == (const ZcDbHomeView& rhvw) const;
    bool            operator != (const ZcDbHomeView& rhvw) const;
    ZcDbHomeView&   operator  = (const ZcDbHomeView& rhvw);

    bool isDefaultHomeView() const;

private:
    ZcDbImpHomeView * mpImpObj;
};


ZCDBCORE2D_PORT 
Zcad::ErrorStatus zcdbSetHomeView(ZcDbDatabase *        pDb, 
                                  const ZcDbHomeView&   hmView);

ZCDBCORE2D_PORT 
Zcad::ErrorStatus zcdbGetHomeView(ZcDbDatabase *        pDb, 
                                  ZcDbHomeView&         hmView);


ZCDBCORE2D_PORT Zcad::ErrorStatus 
zcdbSetShowCompass(ZcDbDatabase *         pDb, 
                   bool                   bShow);

ZCDBCORE2D_PORT Zcad::ErrorStatus 
zcdbGetShowCompass(ZcDbDatabase *         pDb, 
                   bool &                 bShow);

#pragma pack(pop)