//ZwInputPointFilter.cpp
#include "stdafx.h"
#include "ZwInputPointFilter.h"
#include "aced.h"
#include "acgi.h"
#include "dbents.h"
#include "tchar.h"

Acad::ErrorStatus ZwInputPointFilter::processInputPoint(const AcEdInputPoint& input, AcEdInputPointFilterResult& output)
{
	if (input.pointComputed())
	{
		acutPrintf(_T("\nThis is processInputPoint function!\n"));

		// last point
		if (input.history() & Acad::eLastPt)
			acutPrintf(_T("Last valid point: (%g, %g, %g)\n"), input.lastPoint()[X], input.lastPoint()[Y], input.lastPoint()[Z]);

		// The point as tracked by the cursor position before subsequent filtering, or as entered via alternate means
		acutPrintf(_T("Raw point: (%g, %g, %g)\n"), input.rawPoint()[X], input.rawPoint()[Y], input.rawPoint()[Z]);

		// Calculated the cursor position
		acutPrintf(_T("Computed point: (%g, %g, %g)\n"), input.computedPoint()[X], input.computedPoint()[Y], input.computedPoint()[Z]);

		// Grip point
		if (input.history() & Acad::eGripped)
			acutPrintf(_T("Gripped point: (%g, %g, %g)\n"), input.grippedPoint()[X], input.grippedPoint()[Y], input.grippedPoint()[Z]);


		if (m_bPointChanged)
		{
			//newPoint: Offset the computedPoint according to AcGeVector3d (100, 100, 0.0)
			output.setNewPoint(input.computedPoint() + AcGeVector3d(100, 100, 0.0));
			input.drawContext()->subEntityTraits().setColor(1);
			input.drawContext()->geometry().circle(output.newPoint(), 200, AcGeVector3d::kZAxis);

			acutPrintf(_T("\nNew Point: (%g,%g,%g)"), output.newPoint()[X], output.newPoint()[Y], output.newPoint()[Z]);
		}

		Acad::ErrorStatus es;
		//apertured entities
		CString szToolTipStr;
		int aperEntLen = input.pickedEntities().length();
		if (aperEntLen > 0)
		{
			AcDbEntity* pCurEnt = NULL;
			es = acdbOpenAcDbEntity(pCurEnt, input.pickedEntities()[0], AcDb::kForRead);

			AcDbHandle handle;
			pCurEnt->getAcDbHandle(handle);
			TCHAR szHandle[256] = { 0 };
			handle.getIntoAsciiBuffer(szHandle);

			CString szTemp;
			szTemp.Format(_T(" handle: %s\n type: %s\n layer: %s\n color: %s\n linetype: %s\n"),
				szHandle, pCurEnt->isA()->name(), pCurEnt->layer(), pCurEnt->color().colorNameForDisplay(), pCurEnt->linetype());
			szToolTipStr += szTemp;

			szTemp.Empty();
			if (pCurEnt->isKindOf(AcDbCircle::desc()))
			{
				AcDbCircle* pCircle = AcDbCircle::cast(pCurEnt);
				szTemp.Format(_T(" center: (%g,%g,%g)\n radius: %g\n"),
					pCircle->center()[X], pCircle->center()[Y], pCircle->center()[Z], pCircle->radius());
				szToolTipStr += szTemp;
			}

			szTemp.Empty();
			if (pCurEnt->isKindOf(AcDbLine::desc()))
			{
				AcDbLine* pLine = AcDbLine::cast(pCurEnt);
				szTemp.Format(_T(" start point: (%g,%g,%g)\n end point: (%g,%g,%g)\n"),
					pLine->startPoint()[X], pLine->startPoint()[Y], pLine->startPoint()[Z],
					pLine->endPoint()[X], pLine->endPoint()[Y], pLine->endPoint()[Z]);
				szToolTipStr += szTemp;
			}

			output.setNewTooltipString(szToolTipStr);
			pCurEnt->close();
		}
		acedPostCommandPrompt();
	}
	return Acad::eOk;
}