#pragma once

#include "stdafx.h"
#include "dbmain.h"

class MyObject : public AcDbObject
{
public:
	ACRX_DECLARE_MEMBERS(MyObject);

	MyObject();
	MyObject(const double& val);
	~MyObject();

	Acad::ErrorStatus getData(double& val);
	Acad::ErrorStatus setData(double val);

	virtual Acad::ErrorStatus	dwgInFields(AcDbDwgFiler* filer);
	virtual Acad::ErrorStatus	dwgOutFields(AcDbDwgFiler* filer) const;

	virtual Acad::ErrorStatus	dxfInFields(AcDbDxfFiler* filer);
	virtual Acad::ErrorStatus	dxfOutFields(AcDbDxfFiler* filer) const;

private:
	double m_Testd;
};