#pragma once
#include "stdafx.h"
#include "Pipe.h"
#include "DBUtils.h"
#include "dbapserv.h"
#include "dbents.h"
#include "dbobjptr.h"
#include "dbproxy.h"
#include "acdb.h"


class CMyAppData
{
public:
	CMyAppData(int nId);

	CMyAppData(int nId, const AcGeVector3d& dir);

	~CMyAppData();

	int Index() const;

	void SetIndex(int nId);

	AcGeVector3d Direction() const;

	void SetDirection(const AcGeVector3d& dir);

	const AcDbDimDataPtrArray& DimData() const;

	void AppendDimData(AcDbDimData* pData);

	void ResetDimData();

private:
	int m_nId;
	AcGeVector3d m_dir;
	AcDbDimDataPtrArray m_dimDataArr;
};

CMyAppData::CMyAppData(int nId)
{
	m_nId = nId;
}

CMyAppData::CMyAppData(int nId, const AcGeVector3d& dir)
{
	m_nId = nId;
	m_dir = dir;
}

CMyAppData::~CMyAppData()
{

}

int CMyAppData::Index() const
{
	return m_nId;
}

void CMyAppData::SetIndex(int nId)
{
	m_nId = nId;
}

AcGeVector3d CMyAppData::Direction() const
{
	return m_dir;
}

void CMyAppData::SetDirection(const AcGeVector3d& dir)
{
	m_dir = dir;
}

const AcDbDimDataPtrArray& CMyAppData::DimData() const
{
	return m_dimDataArr;
}

void CMyAppData::AppendDimData(AcDbDimData *pData)
{
	int dummyIndex;
	if (!m_dimDataArr.find(pData, dummyIndex))
		m_dimDataArr.append(pData);
}

void CMyAppData::ResetDimData()
{
	m_dimDataArr.setLogicalLength(0);
}


Adesk::UInt32 Pipe::kCurrentVersionNumber = 1;

ACRX_DXF_DEFINE_MEMBERS(
	Pipe, AcDbCurve,
	AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent,
	AcDbProxyEntity::kAllAllowedBits, PIPE,
	"MYPIPESAMPLE"
	"|Product:    ZRX Enabler for Curve"
	"|Company:        ZWSOFT"
	"|Website:        www.zwcad.com"
)

Pipe::Pipe()
{
	m_nStuffId = 1;
	m_pBaseCurve = new AcDbPolyline(2);
	m_pBaseCurve->addVertexAt(0, AcGePoint3d::kOrigin.convert2d(AcGePlane::kXYPlane));
	m_pBaseCurve->addVertexAt(1, AcGePoint3d::kOrigin.convert2d(AcGePlane::kXYPlane));
}

Pipe::~Pipe()
{
	delete m_pBaseCurve;
}

Acad::ErrorStatus Pipe::applyPartialUndo(AcDbDwgFiler* pFiler, AcRxClass* classObj)
{
	if (classObj != Pipe::desc())
		return AcDbCurve::applyPartialUndo(pFiler, classObj);

	Adesk::Int16 opCode;
	pFiler->readItem(&opCode);

	double diameter;
	Adesk::Int16 nStuffId;

	switch ((PartialUndoOpCode)opCode)
	{
	case kSetDiameter:
		pFiler->readDouble(&diameter);
		SetDiameter(diameter);
		break;
	case kSetStuffId:
		pFiler->readInt16(&nStuffId);
		SetStuffId(nStuffId);
		break;
	default:
		ASSERT(0);
		break;
	}

	return Acad::eOk;
}

Acad::ErrorStatus Pipe::dwgOutFields(AcDbDwgFiler* pFiler) const
{
	assertReadEnabled();
	// First save the parent class information
	Acad::ErrorStatus es = AcDbCurve::dwgOutFields(pFiler);
	if (es != Acad::eOk)
		return (es);
	// Save the object version
	if ((es = pFiler->writeUInt32(Pipe::kCurrentVersionNumber)) != Acad::eOk)
		return (es);
	// Output other parameters
	pFiler->writePoint3d(m_startPnt);
	pFiler->writePoint3d(m_endPnt);
	pFiler->writeDouble(m_diameter);
	pFiler->writeInt16(m_nStuffId);
	pFiler->writeVector3d(m_diaDimOffset);

	return (pFiler->filerStatus());
}

Acad::ErrorStatus Pipe::dwgInFields(AcDbDwgFiler* pFiler)
{
	assertWriteEnabled();
	// Read the parent class information first
	Acad::ErrorStatus es = AcDbCurve::dwgInFields(pFiler);
	if (es != Acad::eOk)
		return (es);
	// Read the object version
	Adesk::UInt32 version = 0;
	if ((es = pFiler->readUInt32(&version)) != Acad::eOk)
		return (es);
	if (version > Pipe::kCurrentVersionNumber)
		return (Acad::eMakeMeProxy);
	// Read other parameters
	pFiler->readPoint3d(&m_startPnt);
	pFiler->readPoint3d(&m_endPnt);
	pFiler->readDouble(&m_diameter);
	pFiler->readInt16(&m_nStuffId);
	pFiler->readVector3d(&m_diaDimOffset);

	AcGePoint2d pt1 = m_startPnt.convert2d(AcGePlane::kXYPlane);
	AcGePoint2d pt2 = m_endPnt.convert2d(AcGePlane::kXYPlane);
	m_pBaseCurve->setPointAt(0, pt1);
	m_pBaseCurve->setPointAt(1, pt2);
	m_pBaseCurve->setThickness(m_diameter);

	return (pFiler->filerStatus());
}

Acad::ErrorStatus Pipe::dxfOutFields(AcDbDxfFiler* pFiler) const
{
	assertReadEnabled();
	// First save the parent class information
	Acad::ErrorStatus es = AcDbCurve::dxfOutFields(pFiler);
	if (es != Acad::eOk)
		return es;

	pFiler->writeItem(AcDb::kDxfSubclass, _T("Pipe"));
	// Save the object version
	if ((es = pFiler->writeUInt32(AcDb::kDxfInt32, Pipe::kCurrentVersionNumber)) != Acad::eOk)
		return es;

	pFiler->writeItem(AcDb::kDxfXCoord, m_startPnt);
	pFiler->writeItem(AcDb::kDxfXCoord + 1, m_endPnt);
	pFiler->writeItem(AcDb::kDxfReal, m_diameter);
	pFiler->writeUInt32(AcDb::kDxfInt16, m_nStuffId);
	pFiler->writeItem(AcDb::kDxfNormalX, m_diaDimOffset);

	return pFiler->filerStatus();
}

Acad::ErrorStatus Pipe::dxfInFields(AcDbDxfFiler * pFiler)
{
	assertWriteEnabled();
	// Read the parent class information first
	Acad::ErrorStatus es = AcDbCurve::dxfInFields(pFiler);
	if (es != Acad::eOk)
		return (es);

	struct resbuf rb;
	if (!pFiler->atSubclassData(_T("Pipe")))
	{
		return Acad::eBadDxfSequence;
	}

	// Check the object version
	if (Acad::eOk != (es = pFiler->readItem(&rb)))
	{
		return es;
	}
	if (AcDb::kDxfInt32 != rb.restype)
	{
		return Acad::eMakeMeProxy;
	}
	if (rb.resval.rreal > 1)
	{
		return Acad::eMakeMeProxy;
	}

	while (Acad::eOk == es)
	{
		if (Acad::eOk == (es = pFiler->readItem(&rb)))
		{
			switch (rb.restype)
			{
			case AcDb::kDxfXCoord:
				m_startPnt.set(rb.resval.rpoint[X], rb.resval.rpoint[Y], rb.resval.rpoint[Z]);
				break;
			case AcDb::kDxfXCoord + 1:
				m_endPnt.set(rb.resval.rpoint[X], rb.resval.rpoint[Y], rb.resval.rpoint[Z]);
				break;
			case AcDb::kDxfReal:
				m_diameter = rb.resval.rreal;
				break;
			case AcDb::kDxfInt16:
				m_nStuffId = rb.resval.rint;
				break;
			case AcDb::kDxfNormalX:
				m_diaDimOffset.set(rb.resval.rpoint[X], rb.resval.rpoint[Y], rb.resval.rpoint[Z]);
				break;
			default:
				break;
			}
		}
	}

	return pFiler->filerStatus();
}

Adesk::Boolean Pipe::subWorldDraw(AcGiWorldDraw* mode)
{
	assertReadEnabled();

	AcGePoint3d points[2];
	AcGeVector3d vec = (m_endPnt - m_startPnt).perpVector().normal();

	// Draw the centerline
	mode->subEntityTraits().setSelectionMarker(eSubentTypeCenterLine);
	mode->subEntityTraits().setColor(AcadColor::kRed);

	points[0] = m_startPnt;
	points[1] = m_endPnt;
	m_pBaseCurve->setConstantWidth(10);
	mode->geometry().pline(*m_pBaseCurve);

	// Draw the edges
	mode->subEntityTraits().setSelectionMarker(eSubentTypeBorderLine);
	mode->subEntityTraits().setColor(232);

	points[0] = m_startPnt + vec * m_diameter / 2;
	points[1] = m_endPnt + vec * m_diameter / 2;
	mode->geometry().polyline(2, points);

	points[0] = m_startPnt - vec * m_diameter / 2;
	points[1] = m_endPnt - vec * m_diameter / 2;
	mode->geometry().polyline(2, points);

	mode->subEntityTraits().setSelectionMarker(eSubentTypeCloseLine);

	points[0] = m_startPnt + vec * m_diameter / 2;
	points[1] = m_startPnt - vec * m_diameter / 2;
	mode->geometry().polyline(2, points);

	points[0] = m_endPnt + vec * m_diameter / 2;
	points[1] = m_endPnt - vec * m_diameter / 2;
	mode->geometry().polyline(2, points);

	mode->subEntityTraits().setSelectionMarker(eSubentTypeDiaLabel);
	mode->subEntityTraits().setColor(AcadColor::kGreen);

	AcDbText text;
	CString strDia;
	AcGePoint3d position = (m_startPnt + m_endPnt.asVector()) / 2 + m_diaDimOffset;
	AcDbDatabase* pDb = database();

	if (pDb == NULL)
		pDb = acdbHostApplicationServices()->workingDatabase();

	strDia.Format(_T("%.3f"), m_diameter);
	text.setDatabaseDefaults(pDb);
	text.setRotation((m_endPnt - m_startPnt).angleOnPlane(AcGePlane::kXYPlane));
	text.setTextString(strDia);
	text.setPosition(position);
	text.setHorizontalMode(AcDb::kTextCenter);
	text.setVerticalMode(AcDb::kTextVertMid);
	text.setAlignmentPoint(position);
	text.setHeight(m_diameter / 3);
	text.adjustAlignment(pDb);
	text.worldDraw(mode);

	return Adesk::kTrue;
}

void Pipe::subViewportDraw(AcGiViewportDraw* mode)
{
	assertReadEnabled();

	AcGePoint3d points[2];
	AcGeVector3d vec = (m_endPnt - m_startPnt).perpVector().normal();

	// Draw the centerline
	mode->subEntityTraits().setSelectionMarker(eSubentTypeCenterLine);
	mode->subEntityTraits().setColor(AcadColor::kRed);

	points[0] = m_startPnt;
	points[1] = m_endPnt;
	m_pBaseCurve->setConstantWidth(10);
	mode->geometry().pline(*m_pBaseCurve);

	// Draw the edges
	mode->subEntityTraits().setSelectionMarker(eSubentTypeBorderLine);
	mode->subEntityTraits().setColor(232);

	points[0] = m_startPnt + vec * m_diameter / 2;
	points[1] = m_endPnt + vec * m_diameter / 2;
	mode->geometry().polyline(2, points);

	points[0] = m_startPnt - vec * m_diameter / 2;
	points[1] = m_endPnt - vec * m_diameter / 2;
	mode->geometry().polyline(2, points);

	mode->subEntityTraits().setSelectionMarker(eSubentTypeCloseLine);

	points[0] = m_startPnt + vec * m_diameter / 2;
	points[1] = m_startPnt - vec * m_diameter / 2;
	mode->geometry().polyline(2, points);

	points[0] = m_endPnt + vec * m_diameter / 2;
	points[1] = m_endPnt - vec * m_diameter / 2;
	mode->geometry().polyline(2, points);

	mode->subEntityTraits().setSelectionMarker(eSubentTypeDiaLabel);
	mode->subEntityTraits().setColor(AcadColor::kGreen);

	AcDbText text;
	CString strDia;
	AcGePoint3d position = (m_startPnt + m_endPnt.asVector()) / 2 + m_diaDimOffset;
	AcDbDatabase* pDb = database();

	if (pDb == NULL)
		pDb = acdbHostApplicationServices()->workingDatabase();

	strDia.Format(_T("%.3f"), m_diameter);
	text.setDatabaseDefaults(pDb);
	text.setRotation((m_endPnt - m_startPnt).angleOnPlane(AcGePlane::kXYPlane));
	text.setTextString(strDia);
	text.setPosition(position);
	text.setHorizontalMode(AcDb::kTextCenter);
	text.setVerticalMode(AcDb::kTextVertMid);
	text.setAlignmentPoint(position);
	text.setHeight(m_diameter / 3);
	text.adjustAlignment(pDb);
	text.viewportDraw(mode);
}

Acad::ErrorStatus Pipe::subGetGeomExtents(AcDbExtents& extents) const
{
	assertReadEnabled();

	AcGePoint3d points[4];
	AcGeVector3d vec = (m_endPnt - m_startPnt).perpVector().normal();

	points[0] = m_startPnt + vec * m_diameter / 2;
	points[1] = m_endPnt + vec * m_diameter / 2;
	points[2] = m_startPnt - vec * m_diameter / 2;
	points[3] = m_endPnt - vec * m_diameter / 2;

	extents.addPoint(m_startPnt);
	extents.addPoint(m_endPnt);
	for (int i = 0; i < 4; i++)
		extents.addPoint(points[i]);

	return Acad::eOk;
}

Acad::ErrorStatus Pipe::subExplode(AcDbVoidPtrArray& entitySet) const
{
	assertReadEnabled();

	AcDbLine* pLine = NULL;
	AcGePoint3d points[2];
	AcGeVector3d vec = (m_endPnt - m_startPnt).perpVector().normal();

	// Draw the centerline
	pLine = new AcDbLine(m_startPnt, m_endPnt);
	pLine->setColorIndex(1);
	entitySet.append(pLine);

	// Draw the edges
	pLine = new AcDbLine(m_startPnt + vec * m_diameter / 2, m_endPnt + vec * m_diameter / 2);
	pLine->setColorIndex(232);
	entitySet.append(pLine);

	pLine = new AcDbLine(m_startPnt - vec * m_diameter / 2, m_endPnt - vec * m_diameter / 2);
	pLine->setColorIndex(232);
	entitySet.append(pLine);

	pLine = new AcDbLine(m_startPnt + vec * m_diameter / 2, m_startPnt - vec * m_diameter / 2);
	pLine->setColorIndex(232);
	entitySet.append(pLine);

	pLine = new AcDbLine(m_endPnt + vec * m_diameter / 2, m_endPnt - vec * m_diameter / 2);
	pLine->setColorIndex(232);
	entitySet.append(pLine);

	AcDbText* pText = new AcDbText;
	CString strDia;
	AcGePoint3d position = (m_startPnt + m_endPnt.asVector()) / 2 + m_diaDimOffset;
	AcDbDatabase* pDb = database();

	if (pDb == NULL)
		pDb = acdbHostApplicationServices()->workingDatabase();

	strDia.Format(_T("%.3f"), m_diameter);
	pText->setDatabaseDefaults(pDb);
	pText->setRotation((m_endPnt - m_startPnt).angleOnPlane(AcGePlane::kXYPlane));
	pText->setTextString(strDia);
	pText->setPosition(position);
	pText->setHorizontalMode(AcDb::kTextCenter);
	pText->setVerticalMode(AcDb::kTextVertMid);
	pText->setAlignmentPoint(position);
	pText->setHeight(m_diameter / 3);
	pText->adjustAlignment(pDb);
	pText->setColorIndex(AcadColor::kGreen);
	entitySet.append(pText);

	return Acad::eOk;
}

void Pipe::subList() const
{
	assertReadEnabled();

	// First, list the parent class information
	AcDbCurve::subList();

	Adesk::UInt16 lunit = database()->lunits();
	Adesk::UInt16 lprec = database()->luprec();
	ZcString strX, strY, strZ, strDia;

	acdbRToS(m_startPnt.x, strX, lunit, lprec);
	acdbRToS(m_startPnt.y, strY, lunit, lprec);
	acdbRToS(m_startPnt.z, strZ, lunit, lprec);
	acutPrintf(_T("                 Start point X=%9s  Y=%9s  Z=%9s\n"), strX, strY, strZ);

	acdbRToS(m_endPnt.x, strX, lunit, lprec);
	acdbRToS(m_endPnt.y, strY, lunit, lprec);
	acdbRToS(m_endPnt.z, strZ, lunit, lprec);
	acutPrintf(_T("                 End point X=%9s  Y=%9s  Z=%9s\n"), strX, strY, strZ);

	acdbRToS(m_diameter, strDia, lunit, lprec);
	acutPrintf(_T("                 Pipe diameter %9s\n"), strDia);
}

Acad::ErrorStatus Pipe::subGetClassID(CLSID* pClsid) const
{
	static CLSID clsid;
	CLSIDFromString(L"{701C2B6D-DDD2-4E45-963B-736DD44B2D2B}", &clsid);
	*pClsid = clsid;

	return Acad::eOk;
}

Acad::ErrorStatus Pipe::subGetSubentPathsAtGsMarker(AcDb::SubentType type, int gsMark, const AcGePoint3d& pickPoint, const AcGeMatrix3d& viewXform, int& numPaths, AcDbFullSubentPath*& subentPaths, int numInserts, AcDbObjectId* entAndInsertStack) const
{
	assertReadEnabled();

	AcDbFullSubentPath* pPaths = new AcDbFullSubentPath[1];
	pPaths->subentId().setIndex(gsMark);
	pPaths->subentId().setType(gsMark);
	pPaths->objectIds().append(objectId());

	subentPaths = pPaths;
	numPaths = 1;

	return Acad::eOk;
}

Acad::ErrorStatus Pipe::subGetGsMarkersAtSubentPath(const AcDbFullSubentPath& subPath, AcDbIntArray& gsMarkers) const
{
	assertReadEnabled();

	gsMarkers.append(subPath.subentId().index());

	return Acad::eOk;
}

AcDbEntity* Pipe::subSubentPtr(const AcDbFullSubentPath& id) const
{
	if (id.subentId().type() == eSubentTypeCenterLine)
	{
		return new AcDbLine(m_startPnt, m_endPnt);
	}

	return NULL;
}

Acad::ErrorStatus Pipe::subGetGripPointsAtSubentPath(const AcDbFullSubentPath& path, AcDbGripDataPtrArray& grips, const double curViewUnitSize, const int gripSize, const AcGeVector3d& curViewDir, const int bitflags) const
{
	assertReadEnabled();

	if (path.subentId().type() == eSubentTypeDiaLabel)
	{
		AcDbGripData* pGripData = NULL;
		CMyAppData* pAppData = NULL;

		pGripData = new AcDbGripData;
		pGripData->setGripPoint((m_startPnt + m_endPnt.asVector()) / 2 + m_diaDimOffset);
		pAppData = new CMyAppData(0);
		m_appDataArr.append(pAppData);
		pGripData->setAppData(pAppData);
		grips.append(pGripData);
	}

	return Acad::eOk;
}


Acad::ErrorStatus Pipe::subMoveGripPointsAtSubentPaths(const AcDbFullSubentPathArray& paths, const AcDbVoidPtrArray& gripAppData, const AcGeVector3d& offset, const int bitflags)
{
	assertWriteEnabled();

	CMyAppData* pAppData = (CMyAppData*)gripAppData[0];

	switch (pAppData->Index())
	{
	case 0:
		m_diaDimOffset += offset;
		break;
	}

	return Acad::eOk;
}


Acad::ErrorStatus Pipe::subTransformSubentPathsBy(const AcDbFullSubentPathArray& paths, const AcGeMatrix3d& xform)
{
	assertWriteEnabled();

	AcGePoint3d position;
	AcGePoint3d newPoint;

	switch (paths[0].subentId().type())
	{
	case eSubentTypeDiaLabel:
		position = (m_startPnt + m_endPnt.asVector()) / 2;
		newPoint = position + m_diaDimOffset;
		newPoint.transformBy(xform);
		m_diaDimOffset = newPoint - position;
		break;
	}

	return Acad::eOk;
}

Acad::ErrorStatus Pipe::subGetOsnapPoints(AcDb::OsnapMode osnapMode, int gsSelectionMark, const AcGePoint3d& pickPoint, const AcGePoint3d& lastPoint, const AcGeMatrix3d& viewXform, AcGePoint3dArray& snapPoints, AcDbIntArray& geomIds) const
{
	assertReadEnabled();

	AcGePoint3d points[4];
	AcGeVector3d vec = (m_endPnt - m_startPnt).perpVector().normal();

	points[0] = m_startPnt + vec * m_diameter / 2;
	points[1] = m_endPnt + vec * m_diameter / 2;
	points[2] = m_startPnt - vec * m_diameter / 2;
	points[3] = m_endPnt - vec * m_diameter / 2;

	if (osnapMode == AcDb::kOsModeEnd)
	{
		if (gsSelectionMark == eSubentTypeCenterLine)
		{
			snapPoints.append(m_startPnt);
			snapPoints.append(m_endPnt);
		}
		else if (gsSelectionMark == eSubentTypeBorderLine)
		{
			for (int i = 0; i < 4; i++)
				snapPoints.append(points[i]);
		}
		else if (gsSelectionMark == eSubentTypeCloseLine)
		{
			for (int i = 0; i < 4; i++)
				snapPoints.append(points[i]);
		}
	}
	else if (osnapMode == AcDb::kOsModeMid)
	{
		if (gsSelectionMark == eSubentTypeCenterLine)
		{
			snapPoints.append((m_startPnt + m_endPnt.asVector()) / 2);
		}
	}
	else if (osnapMode == AcDb::kOsModeNear)
	{
		if (gsSelectionMark == eSubentTypeCenterLine)
		{
			AcDbLine line;
			AcGePoint3d tmpPoint;

			line.setStartPoint(m_startPnt);
			line.setEndPoint(m_endPnt);
			if (line.getClosestPointTo(pickPoint, AcGeVector3d::kZAxis, tmpPoint) == Acad::eOk)
				snapPoints.append(tmpPoint);
		}
	}

	return Acad::eOk;
}

Acad::ErrorStatus Pipe::subIntersectWith(const AcDbEntity* pEnt, AcDb::Intersect intType, AcGePoint3dArray& points, int thisGsMarker/* = 0*/, int otherGsMarker/* = 0*/) const
{
	assertReadEnabled();

	AcGePoint3d tmpPoints[4];
	AcGeVector3d vec = (m_endPnt - m_startPnt).perpVector().normal();

	tmpPoints[0] = m_startPnt + vec * m_diameter / 2;
	tmpPoints[1] = m_endPnt + vec * m_diameter / 2;
	tmpPoints[2] = m_startPnt - vec * m_diameter / 2;
	tmpPoints[3] = m_endPnt - vec * m_diameter / 2;

	if (thisGsMarker == eSubentTypeCenterLine)
	{
		AcDbLine line;

		line.setStartPoint(m_startPnt);
		line.setEndPoint(m_endPnt);
		pEnt->intersectWith(&line, intType, points, otherGsMarker, 0);
	}
	else if (thisGsMarker == eSubentTypeBorderLine)
	{
		for (int i = 0; i < 2; i++)
		{
			AcDbLine line;

			line.setStartPoint(tmpPoints[i * 2]);
			line.setEndPoint(tmpPoints[i * 2 + 1]);
			pEnt->intersectWith(&line, intType, points, otherGsMarker, 0);
		}
	}
	else if (thisGsMarker == eSubentTypeCloseLine)
	{
		for (int i = 0; i < 2; i++)
		{
			AcDbLine line;

			line.setStartPoint(tmpPoints[i]);
			line.setEndPoint(tmpPoints[i + 2]);
			pEnt->intersectWith(&line, intType, points, otherGsMarker, 0);
		}
	}

	return Acad::eOk;
}

Acad::ErrorStatus Pipe::subIntersectWith(const AcDbEntity* pEnt, AcDb::Intersect intType, const AcGePlane& projPlane, AcGePoint3dArray& points, int thisGsMarker/* = 0*/, int otherGsMarker/* = 0*/) const
{
	assertReadEnabled();

	return m_pBaseCurve->intersectWith(pEnt, intType, projPlane, points, thisGsMarker, otherGsMarker);
}

void Pipe::GripViewportDraw(AcDbGripData* pThis, AcGiViewportDraw* pWd, const AcDbObjectId& entId, AcDbGripOperations::DrawType type, AcGePoint3d* imageGripPoint, int gripSize)
{
	int nGripColor;		// the grip color not selected
	int nGripHot;		// the grip color selected 
	int nGripHover;		// the grip color when hover 
	int nGripContour;	// the grip contour

	GetSysVar(_T("GRIPCOLOR"), nGripColor);
	GetSysVar(_T("GRIPHOT"), nGripHot);
	GetSysVar(_T("GRIPHOVER"), nGripHover);
	GetSysVar(_T("GRIPCONTOUR"), nGripContour);

	CMyAppData* pAppData = (CMyAppData*)pThis->appData();
	AcGePoint3d points[4];
	AcGePoint3d basePoint;
	AcGePoint2d glyphSize;
	double glyphHeight;		// Grip size

	pWd->viewport().getNumPixelsInUnitSquare(pThis->gripPoint(), glyphSize);
	glyphHeight = gripSize / glyphSize[Y];

	CString str;
	str.Format(_T("HY::Vec:%.3f,%.3f,%.3f"), pAppData->Direction().x, pAppData->Direction().y, pAppData->Direction().z);
	OutputDebugString(str);

	AcGeVector3d leftVec(pAppData->Direction());
	AcGeVector3d rightVec(pAppData->Direction());

	leftVec.rotateBy(kRad90, AcGeVector3d::kZAxis);
	rightVec.rotateBy(kRad90, AcGeVector3d::kZAxis);
	leftVec.normalize();
	rightVec.normalize();

	basePoint = pThis->gripPoint() - pAppData->Direction() * glyphHeight * 1;
	points[0] = basePoint + leftVec * glyphHeight;
	points[1] = basePoint + rightVec * glyphHeight;
	points[2] = basePoint + pAppData->Direction() * glyphHeight * 4;
	points[3] = basePoint + leftVec * glyphHeight;

	for (int i = 0; i < 4; i++)
	{
		str.Format(_T("HY::Pnt(%d):%.3f,%.3f,%.3f"), i, points[i].x, points[i].y, points[i].z);
		OutputDebugString(str);
	}
	if (type == AcDbGripOperations::kWarmGrip)
		pWd->subEntityTraits().setColor(nGripContour);
	else if (type == AcDbGripOperations::kHoverGrip)
		pWd->subEntityTraits().setColor(nGripHover);
	else if (type == AcDbGripOperations::kHotGrip)
		pWd->subEntityTraits().setColor(nGripHot);
	pWd->geometry().polyline(4, points, &AcGeVector3d::kZAxis);

	glyphHeight = (gripSize - 1) / glyphSize[Y];
	basePoint += pAppData->Direction() * (1 / glyphSize[Y]);// Move Up One Pixel
	points[0] = basePoint + leftVec * glyphHeight;
	points[1] = basePoint + rightVec * glyphHeight;
	points[2] = basePoint + pAppData->Direction() * glyphHeight * 4;
	points[3] = basePoint + leftVec * glyphHeight;
	if (type == AcDbGripOperations::kWarmGrip)
		pWd->subEntityTraits().setColor(nGripColor);
	else if (type == AcDbGripOperations::kHoverGrip)
		pWd->subEntityTraits().setColor(nGripHover);
	else if (type == AcDbGripOperations::kHotGrip)
		pWd->subEntityTraits().setColor(nGripHot);
	pWd->subEntityTraits().setFillType(kAcGiFillAlways);
	pWd->geometry().polygon(4, points);
}

void Pipe::GripDimension(AcDbGripData* pGrip, const AcDbObjectId& objId, double dimScale, AcDbDimDataPtrArray& dimDataArr, bool isHover)
{
	if (pGrip == NULL)
		return;

	AcDbObjectPointer<Pipe> pPipe(objId, AcDb::kForRead);
	if (pPipe.openStatus() != Acad::eOk)
		return;

	CMyAppData* pAppData = (CMyAppData*)pGrip->appData();
	int gripId = pAppData ? pAppData->Index() : -1;
	if (gripId < 3)
		return;

	AcGePoint3d startPoint = pGrip->gripPoint();
	AcGePoint3d endPoint = pGrip->gripPoint() - pAppData->Direction() * pPipe->Diameter();
	CString strDiameter;

	strDiameter.Format(_T("%.3f"), pPipe->Diameter());

	AcDbAlignedDimension* pDim = new AcDbAlignedDimension;
	pDim->setDatabaseDefaults(pPipe->database());
	pDim->setXLine1Point(startPoint);
	pDim->setXLine2Point(endPoint);
	pDim->setDimLinePoint(AcGePoint3d((startPoint.x + endPoint.x) / 2, max(startPoint.y, endPoint.y) + 5, 0));
	pDim->setDimensionText(strDiameter);

	AcDbDimData* pDimData = new AcDbDimData(pDim);
	pDimData->setOwnerId(objId);
	pDimData->setDimFocal(true);
	pDimData->setDimEditable(true);
	pDimData->setDimHideIfValueIsZero(true);
	pDimData->setDimValueFunc(SetDimValueFunc);

	dimDataArr.append(pDimData);

	pAppData->ResetDimData();
	pAppData->AppendDimData(pDimData);
}

void Pipe::HoverDimension(AcDbGripData* pGrip, const AcDbObjectId& objId, double dimScale, AcDbDimDataPtrArray& dimDataArr)
{
	GripDimension(pGrip, objId, dimScale, dimDataArr, true);
}

void Pipe::HotGripDimension(AcDbGripData* pGrip, const AcDbObjectId& objId, double dimScale, AcDbDimDataPtrArray& dimDataArr)
{
	GripDimension(pGrip, objId, dimScale, dimDataArr, false);
}

AcGeVector3d Pipe::SetDimValueFunc(AcDbDimData* pThis, AcDbEntity* pEnt, double value, const AcGeVector3d& offset)
{
	if ((pThis == NULL) || (pEnt == NULL))
		return offset;

	CMyAppData* pDimAppData = (CMyAppData*)pThis->appData();
	Pipe* pPipe = Pipe::cast(pEnt);

	pPipe->SetDiameter(value);

	return offset;
}

Acad::ErrorStatus Pipe::subGetGripPoints(AcGePoint3dArray& gripPoints, AcDbIntArray& osnapModes, AcDbIntArray& geomIds) const
{
	assertReadEnabled();

	gripPoints.append((m_startPnt + m_endPnt.asVector()) / 2);
	gripPoints.append(m_startPnt);
	gripPoints.append(m_endPnt);

	return Acad::eOk;
}

Acad::ErrorStatus Pipe::subMoveGripPointsAt(const AcDbIntArray& indices, const AcGeVector3d& offset)
{
	assertWriteEnabled();

	for (int i = 0; i < indices.length(); i++)
	{
		int idx = indices[i];

		switch (idx)
		{
		case 0:
			SetStartPoint(m_startPnt + offset);
			SetEndPoint(m_endPnt + offset);
			break;
		case 1:
			SetStartPoint(m_startPnt + offset);
			break;
		case 2:
			SetEndPoint(m_endPnt + offset);
			break;
		default:
			break;
		}
	}

	return Acad::eOk;
}

Acad::ErrorStatus Pipe::subGetGripPoints(AcDbGripDataPtrArray& grips, const double curViewUnitSize, const int gripSize, const AcGeVector3d& curViewDir, const int bitflags) const
{
	assertReadEnabled();

	AcDbGripData* pGripData = NULL;
	CMyAppData* pAppData = NULL;

	pGripData = new AcDbGripData;
	pGripData->setGripPoint((m_startPnt + m_endPnt.asVector()) / 2);
	pAppData = new CMyAppData(0);
	m_appDataArr.append(pAppData);
	pGripData->setAppData(pAppData);
	grips.append(pGripData);

	pGripData = new AcDbGripData;
	pGripData->setGripPoint(m_startPnt);
	pAppData = new CMyAppData(1);
	m_appDataArr.append(pAppData);
	pGripData->setAppData(pAppData);
	grips.append(pGripData);

	pGripData = new AcDbGripData;
	pGripData->setGripPoint(m_endPnt);
	pAppData = new CMyAppData(2);
	m_appDataArr.append(pAppData);
	pGripData->setAppData(pAppData);
	grips.append(pGripData);

	AcGeVector3d vec = (m_endPnt - m_startPnt).perpVector().normal();
	AcGePoint3d gripPoint = m_endPnt + vec * m_diameter / 2;

	pGripData = new AcDbGripData;
	pGripData->setGripPoint(gripPoint);
	pAppData = new CMyAppData(3, vec);
	m_appDataArr.append(pAppData);
	pGripData->setAppData(pAppData);
	pGripData->setHoverDimensionFunc(HoverDimension);
	pGripData->setHotGripDimensionFunc(HotGripDimension);
	pGripData->setViewportDraw(GripViewportDraw);
	grips.append(pGripData);

	return Acad::eOk;
}

Acad::ErrorStatus Pipe::subMoveGripPointsAt(const AcDbVoidPtrArray& gripAppData, const AcGeVector3d& offset, const int bitflags)
{
	assertWriteEnabled();

	if (!gripAppData.length())
		return Acad::eInvalidInput;

	CMyAppData* pAppData = (CMyAppData*)gripAppData[0];

	switch (pAppData->Index())
	{
	case 0:
		SetStartPoint(m_startPnt + offset);
		SetEndPoint(m_endPnt + offset);
		break;
	case 1:
		SetStartPoint(m_startPnt + offset);
		break;
	case 2:
		SetEndPoint(m_endPnt + offset);
		break;
	case 3:
	{
		OutputDebugString(_T("HY::move 1"));
		AcGeVector3d vec = (m_endPnt - m_startPnt).perpVector().normal();
		AcGePoint3d oldPoint = m_endPnt + vec * m_diameter / 2.0;
		AcGePoint3d newPoint = oldPoint + offset;
		AcGePointOnCurve3d closestPoint;
		AcGeLine3d line(m_endPnt, oldPoint);
		OutputDebugString(_T("HY::move 2"));

		line.getClosestPointTo(newPoint, closestPoint);
		newPoint = closestPoint;
		OutputDebugString(_T("HY::move 3"));

		m_diameter = newPoint.distanceTo(m_endPnt) * 2.0;
	}
	break;
	}

	return Acad::eOk;
}

void Pipe::subGripStatus(const AcDb::GripStat status)
{
	int i;
	switch (status)
	{
	case AcDb::kGripsToBeDeleted:
		for (i = 0; i < m_appDataArr.length(); i++)
			delete m_appDataArr[i];
		m_appDataArr.setLogicalLength(0);
		break;
	case AcDb::kDimDataToBeDeleted:
		for (i = 0; i < m_appDataArr.length(); i++)
		{
			const AcDbDimDataPtrArray& dimDataArr = m_appDataArr[i]->DimData();
			m_appDataArr[i]->ResetDimData();
		}
		break;
	}
}

Acad::ErrorStatus Pipe::subTransformBy(const AcGeMatrix3d& xform)
{
	assertWriteEnabled();

	m_startPnt.transformBy(xform);
	m_endPnt.transformBy(xform);

	return Acad::eOk;
}

Adesk::Boolean Pipe::isClosed() const
{
	assertReadEnabled();

	return m_pBaseCurve->isClosed();
}

Adesk::Boolean Pipe::isPlanar() const
{
	assertReadEnabled();

	return m_pBaseCurve->isPlanar();
}

Acad::ErrorStatus Pipe::getPlane(AcGePlane& plane, AcDb::Planarity& type) const
{
	assertReadEnabled();

	return m_pBaseCurve->getPlane(plane, type);
}

Acad::ErrorStatus Pipe::getStartParam(double& param) const
{
	assertReadEnabled();

	return m_pBaseCurve->getStartParam(param);
}

Acad::ErrorStatus Pipe::getEndParam(double& param) const
{
	assertReadEnabled();

	return m_pBaseCurve->getEndParam(param);
}

Acad::ErrorStatus Pipe::getStartPoint(AcGePoint3d& point) const
{
	assertReadEnabled();

	return m_pBaseCurve->getStartPoint(point);
}

Acad::ErrorStatus Pipe::getEndPoint(AcGePoint3d& point) const
{
	assertReadEnabled();

	return m_pBaseCurve->getEndPoint(point);
}

Acad::ErrorStatus Pipe::getPointAtParam(double param, AcGePoint3d& point) const
{
	assertReadEnabled();

	return m_pBaseCurve->getPointAtParam(param, point);
}

Acad::ErrorStatus Pipe::getParamAtPoint(const AcGePoint3d& point, double& param) const
{
	assertReadEnabled();

	return m_pBaseCurve->getParamAtPoint(point, param);
}

Acad::ErrorStatus Pipe::getDistAtPoint(const AcGePoint3d& point, double& dist) const
{
	return m_pBaseCurve->getDistAtPoint(point, dist);
}

Acad::ErrorStatus Pipe::getPointAtDist(double dist, AcGePoint3d& point) const
{
	return m_pBaseCurve->getPointAtDist(dist, point);
}

Acad::ErrorStatus Pipe::getFirstDeriv(double param, AcGeVector3d& firstDeriv) const
{
	assertReadEnabled();

	return m_pBaseCurve->getFirstDeriv(param, firstDeriv);
}

Acad::ErrorStatus Pipe::getFirstDeriv(const AcGePoint3d& point, AcGeVector3d& firstDeriv) const
{
	assertReadEnabled();

	return m_pBaseCurve->getFirstDeriv(point, firstDeriv);
}

Acad::ErrorStatus Pipe::getClosestPointTo(const AcGePoint3d& givenPnt, AcGePoint3d& pointOnCurve, Adesk::Boolean extend /*=Adesk::kFalse*/) const
{
	assertReadEnabled();

	return m_pBaseCurve->getClosestPointTo(givenPnt, pointOnCurve, extend);
}

Acad::ErrorStatus Pipe::getClosestPointTo(const AcGePoint3d& givenPnt, const AcGeVector3d& direction, AcGePoint3d& pointOnCurve, Adesk::Boolean extend /*=Adesk::kFalse*/) const
{
	assertReadEnabled();

	return m_pBaseCurve->getClosestPointTo(givenPnt, direction, pointOnCurve, extend);
}

Acad::ErrorStatus Pipe::getOffsetCurvesGivenPlaneNormal(const AcGeVector3d& normal, double offsetDist, AcDbVoidPtrArray& offsetCurves) const
{
	assertReadEnabled();

	AcDbVoidPtrArray tempOffsetCurves;
	m_pBaseCurve->getOffsetCurvesGivenPlaneNormal(normal, offsetDist, tempOffsetCurves);

	for (int i = 0; i < tempOffsetCurves.length(); i++)
	{
		AcDbCurve* pCurve = (AcDbCurve*)tempOffsetCurves[i];
		Pipe* pEnt = Pipe::cast(clone());

		if (pEnt->ConvertFrom(pCurve) == Acad::eOk)
		{
			offsetCurves.append(pEnt);
			delete pCurve;
		}
		else
		{
			offsetCurves.append(pCurve);
			delete pEnt;
		}
	}

	return Acad::eOk;
}

Acad::ErrorStatus Pipe::getSplitCurves(const AcGeDoubleArray& params, AcDbVoidPtrArray& curveSegments) const
{
	assertReadEnabled();

	AcDbVoidPtrArray tempCurveSegments;
	EOK_RETURN(m_pBaseCurve->getSplitCurves(params, tempCurveSegments));

	for (int i = 0; i < tempCurveSegments.length(); i++)
	{
		AcDbCurve* pCurve = (AcDbCurve*)tempCurveSegments[i];
		Pipe* pEnt = Pipe::cast(clone());

		if (pEnt->ConvertFrom(pCurve) == Acad::eOk)
		{
			curveSegments.append(pEnt);
			delete pCurve;
		}
		else
		{
			curveSegments.append(pCurve);
			delete pEnt;
		}
	}

	return Acad::eOk;
}

Acad::ErrorStatus Pipe::getSplitCurves(const AcGePoint3dArray& points, AcDbVoidPtrArray& curveSegments) const
{
	assertReadEnabled();

	AcDbVoidPtrArray tempCurveSegments;
	EOK_RETURN(m_pBaseCurve->getSplitCurves(points, tempCurveSegments));

	for (int i = 0; i < tempCurveSegments.length(); i++)
	{
		AcDbCurve* pCurve = (AcDbCurve*)tempCurveSegments[i];
		Pipe* pEnt = Pipe::cast(clone());

		if (pEnt->ConvertFrom(pCurve) == Acad::eOk)
		{
			curveSegments.append(pEnt);
			delete pCurve;
		}
		else
		{
			curveSegments.append(pCurve);
			delete pEnt;
		}
	}

	return Acad::eOk;
}

Acad::ErrorStatus Pipe::extend(double newParam)
{
	assertWriteEnabled();

	std::auto_ptr<AcDbCurve> pCurve(AcDbCurve::cast(m_pBaseCurve->clone()));
	EOK_RETURN(pCurve->extend(newParam));

	return ConvertFrom(pCurve.get());
}

Acad::ErrorStatus Pipe::extend(Adesk::Boolean extendStart, const AcGePoint3d& toPoint)
{
	assertWriteEnabled();

	std::auto_ptr<AcDbCurve> pCurve(AcDbCurve::cast(m_pBaseCurve->clone()));
	EOK_RETURN(pCurve->extend(extendStart, toPoint));

	return ConvertFrom(pCurve.get());
}

Acad::ErrorStatus Pipe::ConvertFrom(AcDbEntity* pEnt)
{
	assertWriteEnabled();

	if (!pEnt->isKindOf(AcDbLine::desc()))
		return Acad::eNotApplicable;

	AcDbLine* pLine = AcDbLine::cast(pEnt);

	SetStartPoint(pLine->startPoint());
	SetEndPoint(pLine->endPoint());
	SetDiameter(pLine->thickness());

	return Acad::eOk;
}

AcGePoint3d Pipe::StartPoint() const
{
	assertReadEnabled();

	return m_startPnt;
}

void Pipe::SetStartPoint(const AcGePoint3d& pnt)
{
	assertWriteEnabled();

	m_startPnt = pnt;
	m_pBaseCurve->setPointAt(0, pnt.convert2d(AcGePlane::kXYPlane));
}

AcGePoint3d Pipe::EndPoint() const
{
	assertReadEnabled();

	return m_endPnt;
}

void Pipe::SetEndPoint(const AcGePoint3d& pnt)
{
	assertWriteEnabled();

	m_endPnt = pnt;

	m_pBaseCurve->setPointAt(1, pnt.convert2d(AcGePlane::kXYPlane));
}

double Pipe::Diameter() const
{
	assertReadEnabled();

	return m_diameter;
}

void Pipe::SetDiameter(double diameter)
{
	assertWriteEnabled(Adesk::kFalse);

	if (m_diameter == diameter)
		return;

	AcDbDwgFiler* pFiler = NULL;
	if ((pFiler = undoFiler()) != NULL)
	{
		pFiler->writeAddress(Pipe::desc());
		pFiler->writeItem((Adesk::Int16)kSetDiameter);
		pFiler->writeDouble(m_diameter);
	}

	m_diameter = diameter;
	m_pBaseCurve->setThickness(m_diameter);
}

Adesk::Int16 Pipe::StuffId() const
{
	assertReadEnabled();

	return m_nStuffId;
}

void Pipe::SetStuffId(Adesk::Int16 nStuffId)
{
	assertWriteEnabled(Adesk::kFalse);

	if (m_nStuffId == nStuffId)
		return;

	AcDbDwgFiler* pFiler = NULL;
	if ((pFiler = undoFiler()) != NULL)
	{
		pFiler->writeAddress(Pipe::desc());
		pFiler->writeItem((Adesk::Int16)kSetDiameter);
		pFiler->writeInt16(m_nStuffId);
	}

	m_nStuffId = nStuffId;
}