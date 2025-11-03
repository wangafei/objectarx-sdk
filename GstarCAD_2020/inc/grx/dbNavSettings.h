

#pragma once
#pragma pack(push, 8)

class GcDbImpHomeView;

///////////////////////////////////////////////////////////////////////////////
//
// class GcDbHomeView - navigation home view settings class
//
#define GCDB_PORT
class GcDbHomeView
{
public:
    GCDB_PORT GcDbHomeView();
    GCDB_PORT GcDbHomeView(const GcDbHomeView& rhvw);
    GCDB_PORT virtual ~GcDbHomeView();

    // Member variable routines
    GCDB_PORT const GcGePoint3d&     eye()           const;
    GCDB_PORT const GcGePoint3d&     center()        const;
    GCDB_PORT const GcGeVector3d&    up()            const;
    GCDB_PORT const double           width()         const;
    GCDB_PORT const double           height()        const;
    GCDB_PORT const bool             isPerspective() const;

    GCDB_PORT void setEye         (const GcGePoint3d& ptEye);
    GCDB_PORT void setCenter      (const GcGePoint3d& ptCenter);
    GCDB_PORT void setUp          (const GcGeVector3d& vUp);
    GCDB_PORT void setWidth       (double dWidth);
    GCDB_PORT void setHeight      (double dHeight);
    GCDB_PORT void setPerspective (bool bPerspective);

    // DB access utility
    GCDB_PORT OdResult  setHomeView(GcDbDatabase * pDb) const;
    GCDB_PORT OdResult  getHomeView(GcDbDatabase * pDb,
                                            bool           bCreateDefault = false);

    // Fill members with default values
    GCDB_PORT void toggleDefaultSettings();

    GCDB_PORT bool            operator == (const GcDbHomeView& rhvw) const;
    GCDB_PORT bool            operator != (const GcDbHomeView& rhvw) const;
    GCDB_PORT GcDbHomeView&   operator  = (const GcDbHomeView& rhvw);

private:
    GcDbImpHomeView * mpImpObj;
};

// Navigation home view routine
GCDB_PORT 
OdResult  gcdbSetHomeView(GcDbDatabase *        pDb, 
                                  const GcDbHomeView&   hmView);

GCDB_PORT 
OdResult  gcdbGetHomeView(GcDbDatabase *        pDb, 
                                  GcDbHomeView&         hmView);

// ViewCube compass show/hide
GCDB_PORT OdResult 
gcdbSetShowCompass(GcDbDatabase *         pDb, 
                   bool                   bShow);

GCDB_PORT OdResult 
gcdbGetShowCompass(GcDbDatabase *         pDb, 
                   bool &                 bShow);

#pragma pack(pop)