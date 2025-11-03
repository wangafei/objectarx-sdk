//InputPointMonitor.cpp
#include "stdafx.h"
#include "ZwInputPointMonitor.h"
#include "acdbabb.h"
#include "adeskabb.h"
#include "aced.h"
#include "dbents.h"
#include "dbosnap.h"
#include "tchar.h"
#include "acestext.h"

#include "atlstr.h"
#include <set>

#define ZW_INPUTPOINT_SHOWMASK(val1, val2)  if (val1 & val2) acutPrintf(_T("%s "), _T(#val2))

Acad::ErrorStatus ZwInputPointMonitor::monitorInputPoint(const AcEdInputPoint& input, AcEdInputPointMonitorResult& output)
{
	if (input.pointComputed())
	{
		// History point action information
		acutPrintf(_T("\nAcEdInputPoint history: "));
		ZW_INPUTPOINT_SHOWMASK(input.history(), Acad::eLastPt);
		ZW_INPUTPOINT_SHOWMASK(input.history(), Acad::eGripped);
		ZW_INPUTPOINT_SHOWMASK(input.history(), Acad::eOsnapped);
		ZW_INPUTPOINT_SHOWMASK(input.history(),Acad::ePickMask);
		ZW_INPUTPOINT_SHOWMASK(input.history(), Acad::eUsedPickBox);
		acutPrintf(_T("\n"));

		// Last valid point, Mouse click or Text line input and so on
		if (input.history() & Acad::eLastPt)
			acutPrintf(_T("Last valid point: (%g, %g, %g)\n"), input.lastPoint()[X], input.lastPoint()[Y], input.lastPoint()[Z]);

		// The point as tracked by the cursor position before subsequent filtering, or as entered via alternate means
		acutPrintf(_T("Raw point: (%g, %g, %g)\n"), input.rawPoint()[X], input.rawPoint()[Y], input.rawPoint()[Z]);

		// Calculated the cursor position
		acutPrintf(_T("Computed point: (%g, %g, %g)\n"), input.computedPoint()[X], input.computedPoint()[Y], input.computedPoint()[Z]);

		// Grip point
		if (input.history() & Acad::eGripped)
			acutPrintf(_T("Gripped point: (%g, %g, %g)\n"), input.grippedPoint()[X], input.grippedPoint()[Y], input.grippedPoint()[Z]);

		// Osnap 
		if (input.history() & Acad::eOsnapped)
		{
			acutPrintf(_T("Osnapped point: (%g, %g, %g)\n"), input.osnappedPoint()[X], input.osnappedPoint()[Y], input.osnappedPoint()[Z]);
			acutPrintf(_T("Object snap type: "));

			// Show osnap type
			ZW_INPUTPOINT_SHOWMASK(input.osnapMask(), AcDb::kOsMaskEnd);
			ZW_INPUTPOINT_SHOWMASK(input.osnapMask(), AcDb::kOsMaskMid);
			ZW_INPUTPOINT_SHOWMASK(input.osnapMask(), AcDb::kOsMaskCen);
			// ...

			if (input.osnapMask() == 0)
			{
				for (int i = 0; i < input.customOsnapModes().length(); i++)
					acutPrintf(_T("%s input.osnapMask() = 0\n"), input.customOsnapModes()[i]->globalModeString());
			}

			acutPrintf(_T("\n"));
		}

		// Entities in the aperture
		acutPrintf(_T("%d apertured entities, "), input.pickedEntities().length());
		acutPrintf(_T("%d nested apertured entities\n"), input.nestedPickedEntities().length());

		// OSNAP Entities information
		acutPrintf(_T("%d keypoint entities, "), input.keyPointEntities().length());
		acutPrintf(_T("%d nested keypoint entities, "), input.nestedKeyPointEntities().length());
		acutPrintf(_T("%d alignment paths\n"), input.alignmentPaths().length());

		Acad::ErrorStatus es;
		extern std::set<AcDbObjectId> nstKeyPtEntIdSet;
		int nNstKeyPtEntLen = input.nestedKeyPointEntities().length();
		std::set<AcDbObjectId> curNstKeyPtEntIdSet;
		for (int i = 0; i < nNstKeyPtEntLen; i++)
		{
			AcDbEntity* pNstKeyPtEnt = NULL;

			for (int j = 0; j < input.nestedKeyPointEntities()[i].length(); j++)
			{
				es = acdbOpenAcDbEntity(pNstKeyPtEnt, input.nestedKeyPointEntities()[i][j], OpenMode::kForRead);
				if (es != Acad::eOk)
					continue;        // sometimes return eNullObjectId and crash

				es = pNstKeyPtEnt->highlight(); // highlight, such as osnap of one ent

				nstKeyPtEntIdSet.insert(input.nestedKeyPointEntities()[i][j]);
				curNstKeyPtEntIdSet.insert(input.nestedKeyPointEntities()[i][j]);

				pNstKeyPtEnt->close();
			}
		}

		if (nstKeyPtEntIdSet.size() > 0)
		{
			std::set<AcDbObjectId>::iterator it = nstKeyPtEntIdSet.begin();
			for (; it != nstKeyPtEntIdSet.end(); it++)
			{
				if (curNstKeyPtEntIdSet.find(*it) != curNstKeyPtEntIdSet.end())
					continue;
				AcDbEntity* pLastNstKeyPtEnt = NULL;
				es = acdbOpenAcDbEntity(pLastNstKeyPtEnt, *it, OpenMode::kForRead);
				acutPrintf(_T("\nes open =%s"), acadErrorStatusText(es));

				if (es != Acad::eOk)
					continue;

				pLastNstKeyPtEnt->unhighlight();
				pLastNstKeyPtEnt->close();
				nstKeyPtEntIdSet.erase(*it);
			}
		}

		// draw something
		if (input.drawContext() != NULL)
		{
			//input.drawContext()->subEntityTraits().setColor(1);
			//input.drawContext()->geometry().circle(input.computedPoint(), 200, AcGeVector3d::kZAxis);
		}

		// apertured entities
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

			output.setAdditionalTooltipString(szToolTipStr);
			pCurEnt->close();
		}

		acedPostCommandPrompt();
	}
	return Acad::eOk;

}

// Exclude some entities from the internal OSNAP calculation, such as not snapping certain entities or entities on a layer
bool ZwInputPointMonitor::excludeFromOsnapCalculation(const AcArray<AcDbObjectId>& nestedEntity, INT_PTR gsSelectionMark)
{
	acutPrintf(_T("\nThe function ExcludeFromOsnapCalculation was called on the monitor.\n"));
	acutPrintf(_T("%d nested entities under cursor.\n"), nestedEntity.length());

	for (int i = 0; i < nestedEntity.length(); i++)
	{
		AcDbEntity* pCurEnt = NULL;
		if (acdbOpenAcDbEntity(pCurEnt, nestedEntity[i], OpenMode::kForRead) == Acad::eOk)
		{
			if (pCurEnt->isKindOf(AcDbPolyline::desc()))
			{
				pCurEnt->close();
				return true;
			}
		}
	}

	return false;
}