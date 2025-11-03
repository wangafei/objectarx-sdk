#include "stdafx.h"
#include "Interaction.h"
#include "aced.h"
#include "adscodes.h"
#include "acestext.h"
#include "geassign.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// zcedGetXXX

void getPoint()
{
	ads_point adsPt;
	int nRet = acedGetPoint(NULL, _T("\nSelect a Point£º"), adsPt);
	if (nRet == RTNORM)
		acutPrintf(_T("\nThe point is (%g,%g,%g)"), adsPt[X], adsPt[Y], adsPt[Z]);
	else if (nRet == RTCAN)
		acutPrintf(_T("\nYou have cancelled!"));
	else
		acutPrintf(_T("Failed!"));
}

void getString()
{
	TCHAR szStr[1024] = { 0 };
	if (acedGetString(0, _T("\nInput a string:"), szStr) == RTNORM)   // If first parameter is not 0, you can input the Space
		acutPrintf(_T("\nThe string is %s"), szStr);
	else
		acutPrintf(_T("\nFailed!"));
}

void getAngle()
{
	ads_real dAngle = 0.0;
	if (acedGetAngle(NULL, _T("\nPick the first point"), &dAngle) == RTNORM)
		acutPrintf(_T("\nThe Angle is %g"), dAngle);
	else
		acutPrintf(_T("\nFailed!"));
}

void getOrient()
{
	ads_real dAngle = 0.0;
	if (acedGetOrient(NULL, _T("\nPick the first point"), &dAngle) == RTNORM)
		acutPrintf(_T("\nThe Angle is %g"), dAngle);
	else
		acutPrintf(_T("\nFailed!"));
}
void getInt()
{
	int nRet;
	if (acedGetInt(_T("\nInput a Integer:"), &nRet) == RTNORM)
		acutPrintf(_T("\nThe Integer is %d"), nRet);
	else
		acutPrintf(_T("\nFailed!"));
}

void getReal()
{
	ads_real dReal;
	if (acedGetReal(_T("\nInput a real number:"), &dReal) == RTNORM)
		acutPrintf(_T("\nThe real number is %g"), dReal);
	else
		acutPrintf(_T("\nFailed!"));
}

void getCorner()
{
	ads_point ptBase = { 0,0,0 };
	ads_point adsPt;
	if (acedGetCorner(ptBase, _T("\nPick the corner:"), adsPt) == RTNORM)
		acutPrintf(_T("\nThe Point is (%g, %g, %g)"), adsPt[X], adsPt[Y], adsPt[Z]);
	else
		acutPrintf(_T("\nFailed!"));
}

void getDist()
{
	ads_real dRet = 0.0;
	if (acedGetDist(NULL, _T("\nPick First point:"), &dRet) == RTNORM)
		acutPrintf(_T("\nThe distance is %g"), dRet);
	else
		acutPrintf(_T("\nFailed!"));
}

void getKWord()
{
	TCHAR keyWord[10] = { 0 };
	acedInitGet(0, _T("A B C D"));
	int retVal = acedGetKword(_T("Input KeyWord [Branch A(A)/Branch B(B)/Branch C(C)/Branch D(D)] <D>: "), keyWord);
	if (retVal == RTNORM)
	{
		if (_tcscmp(keyWord, _T("A")) == 0)
			acutPrintf(_T("\nThis is Branch A"));
		else if (_tcscmp(keyWord, _T("B")) == 0)
			acutPrintf(_T("\nThis is Branch B"));
		else if (_tcscmp(keyWord, _T("C")) == 0)
			acutPrintf(_T("\nThis is Branch C"));
		else if (_tcscmp(keyWord, _T("D")) == 0)
			acutPrintf(_T("\nThis is Branch D"));
	}
	else if (retVal == RTCAN)
		acutPrintf(_T("\nYou have cancelled!"));
	else if (retVal == RTNONE)
		acutPrintf(_T("\nYou Have not input, and the default is Branch D"));
}

void getInput()
{
	acedInitGet(0, _T("FisrtKWord SecondKWord ThirdKWord"));
	ads_point adsPt;
	int nRet = acedGetPoint(NULL, _T("\nSelect a Point£º"), adsPt);
	if (nRet == RTKWORD)
	{
		TCHAR kword[30] = { 0 };
		acedGetInput(kword);
		acutPrintf(_T("\nYoun have Entered the Keyword: %s"), kword);
	}
	else if (nRet == RTNORM)
	{
		acutPrintf(_T("\nYou don't enter any KWord. The Point is (%g, %g, %g)"), adsPt[X], adsPt[Y], adsPt[Z]);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// entsel

void entSelEx()
{
	ads_name entName;
	ads_point adsPt;
	int nRet = acedEntSel(_T("\nSelect a Entity:"), entName, adsPt);
	if (nRet == RTNORM)
	{
		AcDbObjectId objId;
		Acad::ErrorStatus es = Acad::eOk;
		if ((es = acdbGetObjectId(objId, entName)) != Acad::eOk)
		{
			acutPrintf(_T("\nErrorStatus = %s"), acadErrorStatusText(es));
			return;
		}

		AcDbEntity* pEnt = nullptr;
		if ((es = acdbOpenAcDbEntity(pEnt, objId, AcDb::kForRead)) != Acad::eOk)
		{
			acutPrintf(_T("\nErrorStatus = %s"), acadErrorStatusText(es));
			return;
		}

		acutPrintf(_T("\nThe Entity you select is %s"), pEnt->isA()->name());
		pEnt->close();
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// zcedSSGet - Selection set

// Single-point selection
void SSGet_Modeless()
{
	Adesk::Int32 len = 0;
	ads_name selSet;

	int nRet = acedSSGet(NULL, NULL, NULL, NULL, selSet);
	if (nRet != RTNORM)
		return;
	if (acedSSLength(selSet, &len) != RTNORM)
	{
		acedSSFree(selSet);
		return;
	}

	acutPrintf(_T("\nThe selection set has %d object"), len);
	acedSSFree(selSet);

	return;
}

// The PICKFIRST set
void SSGet_ModeI()
{
	// Ensure the system variable "PICKFIRST" is 1
	// Register command with ACRX_CMD_USEPICKSET | ACRX_CMD_REDRAW
	// You should select some entities in advance, otherwise -5001 returns

	Adesk::Int32 len = 0;
	ads_name selSet;

	acutPrintf(_T("\nFirst select some entites as pickfirst set."));
	acutPrintf(_T("\nThen press the Enter or the Space."));

	int nRet = acedSSGet(_T("I"), NULL, NULL, NULL, selSet);
	if (nRet != RTNORM)
	{
		acutPrintf(_T("\nError code: %d"), nRet);
		return;
	}
	if (acedSSLength(selSet, &len) != RTNORM)
	{
		acedSSFree(selSet);
		acutPrintf(_T("\nError code: %d"), nRet);
		return;
	}

	acutPrintf(_T("\nThe selection set has %d object"), len);
	acedSSFree(selSet);

	return;
}

// Crossing selection
void SSGet_ModeC()
{
	Adesk::Int32 len = 0;
	ads_name selSet;
	// Diagonal vertex of cross window
	ads_point adsPt1 = { 0, 0, 0 };
	ads_point adsPt2 = { 1000, 1000, 0 };

	int nRet = acedSSGet(_T("C"), adsPt1, adsPt2, NULL, selSet);
	if (nRet != RTNORM)
		return;
	if (acedSSLength(selSet, &len) != RTNORM)
	{
		acedSSFree(selSet);
		return;
	}

	acutPrintf(_T("\nThe selection set has %d object"), len);
	acedSSFree(selSet);

	return;
}

// Window selection, the window in the Window
void SSGet_ModeW()
{
	Adesk::Int32 len = 0;
	ads_name selSet;
	// Diagonal vertex of window
	ads_point adsPt1 = { 0, 0, 0 };
	ads_point adsPt2 = { 1000, 1000, 0 };

	int nRet = acedSSGet(_T("W"), adsPt1, adsPt2, NULL, selSet);
	if (nRet != RTNORM)
		return;
	if (acedSSLength(selSet, &len) != RTNORM)
	{
		acedSSFree(selSet);
		return;
	}

	acutPrintf(_T("\nThe selection set has %d object"), len);
	acedSSFree(selSet);

	return;
}

// Prompts
void SSGet_ModePrompts()
{
	Adesk::Int32 len = 0;
	ads_name selSet;
	TCHAR* prompt[2] = { _T("\nSelect some entities: "), _T("") };

	int nRet = acedSSGet(_T(":$"), prompt, NULL, NULL, selSet);
	if (nRet != RTNORM)
		return;
	if (acedSSLength(selSet, &len) != RTNORM)
	{
		acedSSFree(selSet);
		return;
	}

	acutPrintf(_T("\nThe selection set has %d object"), len);
	acedSSFree(selSet);

	return;
}

// Filter selection only, and in entire database
void SSGet_ModeX()
{
	Adesk::Int32 len = 0;
	ads_name selSet;
	TCHAR* prompt[2] = { _T("\nSelect some entities(red line or circle in layer1): "), _T("") };

	// Only Select red line or circle in layer1
	struct resbuf *rb;
	rb = acutBuildList(
		-4, _T("<OR"),
		-4, _T("<AND"), RTDXF0, _T("LINE"), 62, 1, -4, _T("AND>"),
		-4, _T("<AND"), 8, _T("Layer1"), RTDXF0, _T("CIRCLE"), -4, _T("AND>"),
		-4, _T("OR>"), RTNONE);
	// Other filter
	struct resbuf rb1, rb2;
	TCHAR buf[10] = { 0 };
	rb1.restype = 0;
	_tcscpy(buf, _T("LINE"));
	rb1.resval.rstring = buf;
	rb2.restype = 62;
	rb2.resval.rint = 1;
	rb2.rbnext = NULL;
	rb1.rbnext = &rb2;

	int nRet = acedSSGet(_T("X:$"), prompt, NULL, rb, selSet);
	//int nRet = acedSSGet(_T("X"), NULL, NULL, &rb1, selSet);
	//int nRet = acedSSGet(_T("X"), NULL, NULL, NULL, selSet);   //if the filter is NULL, find all entities in db

	if (nRet != RTNORM)
		return;
	if (acedSSLength(selSet, &len) != RTNORM)
	{
		acedSSFree(selSet);
		return;
	}

	acutPrintf(_T("\nThe selection set has %d object"), len);
	acedSSFree(selSet);
	acutRelRb(rb);

	return;
}

// Keyword callbacks 
resbuf* keywordCallback(const TCHAR* str)
{
	if (str)
	{
		acutPrintf(_T("\nYou has input the keyword: %s"), str);
	}
	return nullptr;
}

void SSGet_ModeK()
{
	Adesk::Int32 len = 0;
	ads_name selSet;
	TCHAR* prompt[2] = { _T("\nSelect some entities with mode \":K\": "), _T("") };
	TCHAR kwordlist[] = { _T("A B C _ A B C") };

	resbuf* (*oldKeyFunc) (const TCHAR*);
	acedSSGetKwordCallbackPtr(&oldKeyFunc);

	acedSSSetKwordCallbackPtr(keywordCallback);

	int nRet = acedSSGet(_T(":$:K"), prompt, kwordlist, NULL, selSet);
	if (nRet != RTNORM)
	{
		acedSSSetKwordCallbackPtr(oldKeyFunc);
		return;
	}
	if (acedSSLength(selSet, &len) != RTNORM)
	{
		acedSSSetKwordCallbackPtr(oldKeyFunc);
		acedSSFree(selSet);
		return;
	}

	acutPrintf(_T("\nThe selection set has %d object"), len);
	acedSSFree(selSet);

	acedSSSetKwordCallbackPtr(oldKeyFunc);

	return;
}

// Fence selection, find entities which intersects with the polygon 
void SSGet_ModeF()
{
	Adesk::Int32 len = 0;
	ads_name selSet;

	resbuf *rbPtSet = NULL, *rbPt = NULL;
	AcGePoint3dArray ptsArr;
	ptsArr.append(AcGePoint3d(0, 0, 0));
	ptsArr.append(AcGePoint3d(1000, 0, 0));
	ptsArr.append(AcGePoint3d(1000, 1500, 0));
	ptsArr.append(AcGePoint3d(0, 1000, 0));
	ptsArr.append(AcGePoint3d(0, 0, 0));

	for (int i = 0; i < ptsArr.length(); i++)
	{
		rbPt = ads_buildlist(RTPOINT, asDblArray(ptsArr[i]), 0);
		if (!rbPtSet)
			rbPtSet = rbPt;
		else
		{
			resbuf *t;
			for (t = rbPtSet; t->rbnext != NULL; t = t->rbnext);
			t->rbnext = rbPt;
		}
	}

	int nRet = acedSSGet(_T("F"), rbPtSet, NULL, NULL, selSet);
	if (nRet != RTNORM)
		return;
	if (acedSSLength(selSet, &len) != RTNORM)
	{
		acedSSFree(selSet);
		return;
	}

	acutPrintf(_T("\nThe selection set has %d object"), len);
	acedSSFree(selSet);

	return;
}

// Box, the box and in the Box
void SSGet_ModeB()
{
	Adesk::Int32 len = 0;
	ads_name selSet;
	ads_point adsPt1 = { 0, 0, 0 };
	ads_point adsPt2 = { 1000, 1000, 0 };

	int nRet = acedSSGet(_T("B"), adsPt1, adsPt2, NULL, selSet);
	if (nRet != RTNORM)
		return;
	if (acedSSLength(selSet, &len) != RTNORM)
	{
		acedSSFree(selSet);
		return;
	}

	acutPrintf(_T("\nThe selection set has %d object"), len);
	acedSSFree(selSet);

	return;
}

// All(Except for frozen layers), Model Space and the active Paper Space
void SSGet_ModeA()
{
	Adesk::Int32 len = 0;
	ads_name selSet;

	int nRet = acedSSGet(_T("A"), NULL, NULL, NULL, selSet);
	if (nRet != RTNORM)
		return;
	if (acedSSLength(selSet, &len) != RTNORM)
	{
		acedSSFree(selSet);
		return;
	}

	acutPrintf(_T("\nThe selection set has %d object"), len);
	acedSSFree(selSet);

	return;
}

// single object selection 
void SSGet_ModeS()
{
	Adesk::Int32 len = 0;
	ads_name selSet;

	int nRet = acedSSGet(_T(":S"), NULL, NULL, NULL, selSet);
	if (nRet != RTNORM)
		return;
	if (acedSSLength(selSet, &len) != RTNORM)
	{
		acedSSFree(selSet);
		return;
	}

	acutPrintf(_T("\nThe selection set has %d object"), len);
	acedSSFree(selSet);

	return;
}

// Crossing polygon selection
void SSGet_ModeCP()
{
	Adesk::Int32 len = 0;
	ads_name selSet;
	resbuf *rbPtSet = NULL, *rbPt = NULL;

	// Diagonal vertex of cross polygon
	AcGePoint3dArray ptsArr;
	ptsArr.append(AcGePoint3d(0, 0, 0));
	ptsArr.append(AcGePoint3d(1000, 0, 0));
	ptsArr.append(AcGePoint3d(1000, 1500, 0));
	ptsArr.append(AcGePoint3d(0, 1000, 0));
	ptsArr.append(AcGePoint3d(0, 0, 0));

	for (int i = 0; i < ptsArr.length(); i++)
	{
		rbPt = ads_buildlist(RTPOINT, asDblArray(ptsArr[i]), 0);
		if (!rbPtSet)
			rbPtSet = rbPt;
		else
		{
			resbuf *t;
			for (t = rbPtSet; t->rbnext != NULL; t = t->rbnext);
			t->rbnext = rbPt;
		}
	}

	int nRet = acedSSGet(_T("CP"), rbPtSet, NULL, NULL, selSet);
	if (nRet != RTNORM)
		return;
	if (acedSSLength(selSet, &len) != RTNORM)
	{
		acedSSFree(selSet);
		return;
	}

	acutPrintf(_T("\nThe selection set has %d object"), len);
	acedSSFree(selSet);

	return;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// System var operation

static std::map<TCHAR*, resbuf> g_oldSysVar;

void setSysVarInt()
{
	TCHAR *szName = _T("CURSORSIZE");
	int nInput = 0, nRet = 0;
	resbuf rbOld;
	nRet = acedGetVar(szName, &rbOld);
	g_oldSysVar.insert(std::pair<TCHAR*, resbuf>(szName, rbOld));

	acedInitGet(RSG_NONEG + RSG_NOZERO + RSG_NONULL, NULL);
	nRet = acedGetInt(_T("Set cursor size(Integer 1-100)£º"), &nInput);
	if (nRet == RTNORM)
	{
		resbuf rb;
		rb.restype = RTSHORT;
		rb.resval.rint = nInput;
		rb.rbnext = NULL;

		nRet = acedSetVar(szName, &rb);
		if (nRet == RTNORM)
			acutPrintf(_T("\nSuccessfully!"));
		else
			acutPrintf(_T("\nFailed! ErrorCode: %d"), nRet);
	}
}
void getSysVarInt()
{
	resbuf rb;
	int nRet = acedGetVar(_T("CURSORSIZE"), &rb);
	acutPrintf(_T("\nCURSORSIZE = %d"), rb.resval.rint);
}

void setSysVarStr()
{
	int nRet = 0;
	TCHAR *szName = _T("CECOLOR");
	TCHAR nInput[20] = { 0 };
	resbuf rbOld;

	nRet = acedGetVar(szName, &rbOld);
	g_oldSysVar.insert(std::pair<TCHAR*, resbuf>(szName, rbOld));

	acedInitGet(RSG_NONULL, NULL);
	nRet = acedGetString(0, _T("Set Color(BYLAYER/BYBLOCK/1-255)£º"), nInput);

	if (nRet == RTNORM)
	{
		resbuf rb;
		rb.restype = RTSTR;
		rb.resval.rstring = nInput;
		rb.rbnext = NULL;

		nRet = acedSetVar(szName, &rb);
		if (nRet == RTNORM)
			acutPrintf(_T("\nSuccessfully!"));
		else
			acutPrintf(_T("\nFailed! ErrorCode: %d"), nRet);
	}
}
void getSysVarStr()
{
	resbuf rb;
	int nRet = acedGetVar(_T("CECOLOR"), &rb);
	acutPrintf(_T("\nCECOLOR = %s"), rb.resval.rstring);
}

void setSysVarReal()
{
	int nRet = 0;
	TCHAR *szName = _T("CIRCLERAD");
	double dInput = 0;
	resbuf rbOld;
	nRet = acedGetVar(szName, &rbOld);
	g_oldSysVar.insert(std::pair<TCHAR*, resbuf>(szName, rbOld));

	acedInitGet(RSG_NONULL + RSG_NONEG, NULL);
	nRet = acedGetReal(_T("Set the default radius of circle(real number)£º"), &dInput);

	if (nRet == RTNORM)
	{
		resbuf rb;
		rb.restype = RTSTR;
		rb.resval.rreal = dInput;
		rb.rbnext = NULL;

		nRet = acedSetVar(szName, &rb);
		if (nRet == RTNORM)
			acutPrintf(_T("\nSuccessfully!"));
		else
			acutPrintf(_T("\nFailed! ErrorCode: %d"), nRet);
	}
}

void getSysVarReal()
{
	resbuf rb;
	int nRet = acedGetVar(_T("CIRCLERAD"), &rb);
	acutPrintf(_T("\nCIRCLERAD = %g"), rb.resval.rreal);
}

void getSysVarPoint()
{
	resbuf rb;
	int nRet = acedGetVar(_T("VIEWCTR"), &rb);
	acutPrintf(_T("\nVIEWCTR = (%g, %g, %g)"), nRet, rb.resval.rpoint[X], rb.resval.rpoint[Y], rb.resval.rpoint[Z]);
}

void resetSysVar()
{
	std::map<TCHAR*, resbuf>::iterator iter = g_oldSysVar.begin();
	while (iter != g_oldSysVar.end())
	{
		acedSetVar(iter->first, &(iter->second));
		iter++;
	}
}
