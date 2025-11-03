#include "stdafx.h"
#include "MyObject.h"
#include "rxboiler.h"
#include "dbproxy.h"

ACRX_DXF_DEFINE_MEMBERS(
	MyObject, AcDbObject,
	AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent,
	AcDbProxyEntity::kAllAllowedBits, MYOBJECT,
	"ZRXSAMPLES"
	"|Product:    ZRX Enabler for Object"
	"|Company:        ZWSOFT"
	"|Website:        www.zwcad.com"
)

MyObject::MyObject()
{
	m_Testd = 0.0;
}

MyObject::MyObject(const double & val)
{
	m_Testd = val;
}

MyObject::~MyObject()
{
}

Acad::ErrorStatus MyObject::getData(double & val)
{
	assertReadEnabled();
	val = m_Testd;
	return Acad::eOk;
}

Acad::ErrorStatus MyObject::setData(double val)
{
	assertWriteEnabled();
	m_Testd = val;
	return Acad::eOk;
}

Acad::ErrorStatus MyObject::dwgInFields(AcDbDwgFiler * filer)
{
	assertWriteEnabled();
	Acad::ErrorStatus es = AcDbObject::dwgInFields(filer);
	if (es != Acad::eOk)
		return (es);

	filer->readDouble(&m_Testd);

	return filer->filerStatus();
}

Acad::ErrorStatus MyObject::dwgOutFields(AcDbDwgFiler * filer) const
{
	assertReadEnabled();
	Acad::ErrorStatus es = AcDbObject::dwgOutFields(filer);
	if (es != Acad::eOk)
		return (es);

	filer->writeDouble(m_Testd);

	return filer->filerStatus();
}

Acad::ErrorStatus MyObject::dxfInFields(AcDbDxfFiler * filer)
{
	assertWriteEnabled();

	Acad::ErrorStatus es = AcDbObject::dxfInFields(filer);
	if (es != Acad::eOk)
		return (es);

	struct resbuf rb;
	if (!filer->atSubclassData(_T("MyObject")))
	{
		return Acad::eBadDxfSequence;
	}

	while (Acad::eOk == es)
	{
		if (Acad::eOk == (es = filer->readItem(&rb)))
		{
			switch (rb.restype)
			{
			case AcDb::kDxfReal:
				m_Testd = rb.resval.rreal;
				break;
			default:
				break;
			}
		}
	}

	return filer->filerStatus();
}

Acad::ErrorStatus MyObject::dxfOutFields(AcDbDxfFiler * filer) const
{
	assertReadEnabled();

	Acad::ErrorStatus es = AcDbObject::dxfOutFields(filer);
	if (es != Acad::eOk)
		return es;

	filer->writeItem(AcDb::kDxfSubclass, _T("MyObject"));

	filer->writeItem(AcDb::kDxfReal, m_Testd);

	return filer->filerStatus();
}
