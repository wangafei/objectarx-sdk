#include "stdafx.h"
#include "InputContextRec.h"

InputContextRec::InputContextRec()
{
}

InputContextRec::~InputContextRec()
{
}

void InputContextRec::beginGetPoint(const AcGePoint3d * pointIn, const ACHAR * promptString, int initGetFlags, const ACHAR * pKeywords)
{
	acutPrintf(_T("\nbeginGetPoint"));
}

void InputContextRec::endGetPoint(Acad::PromptStatus returnStatus, const AcGePoint3d & pointOut, const ACHAR *& pKeyword)
{
	acutPrintf(_T("\nendGetPoint"));
}

void InputContextRec::beginGetAngle(const AcGePoint3d * pointIn, const ACHAR * promptString, int initGetFlags, const ACHAR * pKeywords)
{
	acutPrintf(_T("\nbeginGetAngle"));
}

void InputContextRec::endGetAngle(Acad::PromptStatus returnStatus, double & angle, const ACHAR *& pKeyword)
{
	acutPrintf(_T("\nendGetAngle"));
}

void InputContextRec::beginGetDistance(const AcGePoint3d * pointIn, const ACHAR * promptString, int initGetFlags, const ACHAR * pKeywords)
{
	acutPrintf(_T("\nbeginGetDistance"));
}

void InputContextRec::endGetDistance(Acad::PromptStatus returnStatus, double & distance, const ACHAR *& pKeyword)
{
	acutPrintf(_T("\nendGetDistance"));
}

void InputContextRec::beginGetOrientation(const AcGePoint3d * pointIn, const ACHAR * promptString, int initGetFlags, const ACHAR * pKeywords)
{
	acutPrintf(_T("\nbeginGetOrientation"));
}

void InputContextRec::endGetOrientation(Acad::PromptStatus returnStatus, double & angle, const ACHAR *& pKeyword)
{
	acutPrintf(_T("\nendGetOrientation"));
}

void InputContextRec::beginGetCorner(const AcGePoint3d * firstCorner, const ACHAR * promptString, int initGetFlags, const ACHAR * pKeywords)
{
	acutPrintf(_T("\nbeginGetCorner"));
}

void InputContextRec::endGetCorner(Acad::PromptStatus returnStatus, AcGePoint3d & secondCorner, const ACHAR *& pKeyword)
{
	acutPrintf(_T("\nendGetCorner"));
}

void InputContextRec::beginGetScaleFactor(const AcGePoint3d * pointIn, const ACHAR * promptString, int initGetFlags, const ACHAR * pKeywords)
{
	acutPrintf(_T("\nbeginGetScaleFactor"));
}

void InputContextRec::endGetScaleFactor(Acad::PromptStatus returnStatus, double & distance, const ACHAR *& pKeyword)
{
	acutPrintf(_T("\nendGetScaleFactor"));
}

void InputContextRec::beginGetString(const ACHAR * promptString, int initGetFlags)
{
	acutPrintf(_T("\nbeginGetString"));
}

void InputContextRec::endGetString(Acad::PromptStatus returnStatus, ACHAR * pString)
{
	acutPrintf(_T("\nendGetString"));
}

void InputContextRec::beginGetKeyword(const ACHAR * promptString, int initGetFlags, const ACHAR * pKeywords)
{
	acutPrintf(_T("\nbeginGetKeyword"));
}

void InputContextRec::endGetKeyword(Acad::PromptStatus returnStatus, const ACHAR *& pKeyword)
{
	acutPrintf(_T("\nendGetKeyword"));
}

void InputContextRec::beginGetInteger(const int * dfault, const ACHAR * promptString, int initGetFlags, const ACHAR * pKeywords)
{
	acutPrintf(_T("\nbeginGetInteger"));
}

void InputContextRec::endGetInteger(Acad::PromptStatus returnStatus, int & retValue, const ACHAR *& pKeyword)
{
	acutPrintf(_T("\nendGetInteger"));
}

void InputContextRec::beginGetColor(const int * dfault, const ACHAR * promptString, int initGetFlags, const ACHAR * pKeywords)
{
	acutPrintf(_T("\nbeginGetColor"));
}

void InputContextRec::endGetColor(Acad::PromptStatus returnStatus, int & retValue, const ACHAR *& pKeyword)
{
	acutPrintf(_T("\nendGetColor"));
}

void InputContextRec::beginGetReal(const double * dfault, const ACHAR * promptString, int initGetFlags, const ACHAR * pKeywords)
{
	acutPrintf(_T("\nbeginGetReal"));
}

void InputContextRec::endGetReal(Acad::PromptStatus returnStatus, double & returnValue, const ACHAR *& pKeyword)
{
	acutPrintf(_T("\nendGetReal"));
}

void InputContextRec::beginEntsel(const ACHAR * promptString, int initGetFlags, const ACHAR * pKeywords)
{
	acutPrintf(_T("\nbeginEntsel"));
}

void InputContextRec::endEntsel(Acad::PromptStatus returnStatus, AcDbObjectId & entPicked, AcGePoint3d & pickPoint, const ACHAR * pKeyword)
{
	acutPrintf(_T("\nendEntsel"));
}

void InputContextRec::beginNentsel(const ACHAR * promptString, Adesk::Boolean pickFlag, int initGetFlags, const ACHAR * pKeywords)
{
	acutPrintf(_T("\nbeginNentsel"));
}

void InputContextRec::endNentsel(Acad::PromptStatus returnStatus, AcDbObjectId entPicked, const AcGePoint3d & pickPoint, const AcGeMatrix3d & xform, const resbuf * referenceStack, const ACHAR * pKeyword)
{
	acutPrintf(_T("\nendNentsel"));
}

void InputContextRec::beginSSGet(const ACHAR * pPrompt, int initGetFlags, const ACHAR * pKeywords, const ACHAR * pSSControls, const AcArray<AcGePoint3d>& points, const resbuf * entMask)
{
	acutPrintf(_T("\nbeginSSGet"));
}

void InputContextRec::endSSGet(Acad::PromptStatus returnStatus, const AcArray<AcDbObjectId>& ss)
{
	acutPrintf(_T("\nendSSGet"));
}

void InputContextRec::beginDragSequence(const ACHAR * promptString)
{
	acutPrintf(_T("\nbeginDragSequence"));
}

void InputContextRec::endDragSequence(Acad::PromptStatus returnStatus, AcGePoint3d & pickPoint, AcGeVector3d & vec)
{
	acutPrintf(_T("\nendDragSequence"));
}

void InputContextRec::beginQuiescentState()
{
	acutPrintf(_T("\nbeginQuiescentState"));
}

void InputContextRec::endQuiescentState()
{
	acutPrintf(_T("\nendQuiescentState"));
}
