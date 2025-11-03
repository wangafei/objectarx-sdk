/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#pragma pack(push, 8)

class GcDbImpHomeView;

class GcDbHomeView
{
public:
  GCCORE_PORT GcDbHomeView();
  GCCORE_PORT GcDbHomeView(const GcDbHomeView& rhvw);
  GCCORE_PORT virtual ~GcDbHomeView();

  GCCORE_PORT const GcGePoint3d&     eye()           const;
  GCCORE_PORT const GcGePoint3d&     center()        const;
  GCCORE_PORT const GcGeVector3d&    up()            const;
  GCCORE_PORT const double           width()         const;
  GCCORE_PORT const double           height()        const;
  GCCORE_PORT const bool             isPerspective() const;

  GCCORE_PORT void setEye(const GcGePoint3d& ptEye);
  GCCORE_PORT void setCenter(const GcGePoint3d& ptCenter);
  GCCORE_PORT void setUp(const GcGeVector3d& vUp);
  GCCORE_PORT void setWidth(double dWidth);
  GCCORE_PORT void setHeight(double dHeight);
  GCCORE_PORT void setPerspective(bool bPerspective);

  GCCORE_PORT Gcad::ErrorStatus setHomeView(GcDbDatabase * pDb) const;
  GCCORE_PORT Gcad::ErrorStatus getHomeView(GcDbDatabase * pDb, bool bCreateDefault = false);

  GCCORE_PORT void toggleDefaultSettings();

  GCCORE_PORT bool            operator == (const GcDbHomeView& rhvw) const;
  GCCORE_PORT bool            operator != (const GcDbHomeView& rhvw) const;
  GCCORE_PORT GcDbHomeView&   operator  = (const GcDbHomeView& rhvw);

  GCCORE_PORT bool isDefaultHomeView() const;

private:
  GcDbImpHomeView * mpImpObj;
};

GCCORE_PORT Gcad::ErrorStatus gcdbSetHomeView(GcDbDatabase* pDb, const GcDbHomeView& hmView);
GCCORE_PORT Gcad::ErrorStatus gcdbGetHomeView(GcDbDatabase* pDb, GcDbHomeView& hmView);
GCCORE_PORT Gcad::ErrorStatus gcdbSetShowCompass(GcDbDatabase* pDb, bool bShow);
GCCORE_PORT Gcad::ErrorStatus gcdbGetShowCompass(GcDbDatabase* pDb, bool& bShow);

#pragma pack(pop)