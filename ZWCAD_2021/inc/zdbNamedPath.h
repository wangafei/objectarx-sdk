

#pragma once

#include "zdbmain.h"

#pragma pack(push, 8)

#pragma warning( disable: 4275 4251 )

#ifdef SCENEDLLIMPEXP
#undef SCENEDLLIMPEXP
#endif
#ifdef SCENEOE
#define SCENEDLLIMPEXP __declspec( dllexport )
#else
#define SCENEDLLIMPEXP
#endif

const ZTCHAR ZCDB_NAMEDPATH_DICTIONARY[]  = ZCRX_T("ACAD_NAMEDPATH");

Zcad::ErrorStatus SCENEDLLIMPEXP zcdbGetNamedPathDictionary   (ZcDbDatabase* pDb, ZcDbDictionary*& pDict,
                                                            ZcDb::OpenMode mode, bool createIfNonExist);
Zcad::ErrorStatus SCENEDLLIMPEXP zcdbGetNamedPathDictionary   (ZcDbDatabase* pDb, ZcDbDictionary*& pDict,
                                                            ZcDb::OpenMode mode);

class ZcDbImpNamedPath;
class ZcGeCurve3d;

class SCENEDLLIMPEXP ZcDbNamedPath : public ZcDbObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbNamedPath);
    virtual ~ZcDbNamedPath();

    virtual Zcad::ErrorStatus   getGeometry(ZcGeCurve3d *& pCurveGeometry) const = 0;

protected:
    ZcDbNamedPath (ZcDbImpNamedPath* pImp);
    ZcDbImpNamedPath* imp() const;

private:
    friend class ZcDbImpNamedPath;
    ZcDbImpNamedPath* mpImp;
};

class SCENEDLLIMPEXP ZcDbCurvePath : public ZcDbNamedPath
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbCurvePath);
    ZcDbCurvePath();
    virtual ~ZcDbCurvePath();

    virtual Zcad::ErrorStatus   getGeometry(ZcGeCurve3d *& pCurveGeometry) const;

    Zcad::ErrorStatus   setGeometry(const ZcDbObjectId& id);
    ZcDbObjectId        entityId() const;
    virtual Zcad::ErrorStatus dwgInFields  (ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus dwgOutFields (ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus dxfInFields  (ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus dxfOutFields (ZcDbDxfFiler* pFiler) const;

protected: 
	virtual ZSoft::UInt32  subSetAttributes (ZcGiDrawableTraits* pTraits);	

private:
    friend class ZcDbImpCurvePath;
};

class SCENEDLLIMPEXP ZcDbPointPath : public ZcDbNamedPath
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbPointPath);
    ZcDbPointPath();
    virtual ~ZcDbPointPath();

    virtual Zcad::ErrorStatus   getGeometry(ZcGeCurve3d *& pCurveGeometry) const;

    Zcad::ErrorStatus   setGeometry(const ZcGePoint3d& pt);
    virtual Zcad::ErrorStatus dwgInFields  (ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus dwgOutFields (ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus dxfInFields  (ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus dxfOutFields (ZcDbDxfFiler* pFiler) const;

protected: 
	virtual ZSoft::UInt32  subSetAttributes (ZcGiDrawableTraits* pTraits);	

private:
#ifndef _ZSOFT_MAC_		
	friend class ZcDbPointPath;
#endif
};

#pragma pack(pop)

