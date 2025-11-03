#include "stdafx.h"
#include "EdReactor.h"
#include "rxboiler.h"

ACRX_NO_CONS_DEFINE_MEMBERS(EdReactor, AcEditorReactor);

EdReactor::EdReactor()
{
}

EdReactor::~EdReactor()
{
}

void EdReactor::commandWillStart(const ACHAR* cmdStr)
{
	acutPrintf(_T("\n%s will start!"), cmdStr);
}

void EdReactor::commandEnded(const ACHAR* cmdStr)
{
	acutPrintf(_T("\n%s ended!"), cmdStr);
}

void EdReactor::commandCancelled(const ACHAR* cmdStr)
{
	acutPrintf(_T("\n%s cancelled!"), cmdStr);
}

void EdReactor::beginDwgOpen(const ACHAR* filename)
{
	acutPrintf(_T("\n%s beginDwgOpen!"), filename);
}

void EdReactor::endDwgOpen(const ACHAR* filename, AcDbDatabase* pDb)
{
	acutPrintf(_T("\n%s endDwgOpen!"), filename);
}

void EdReactor::viewChanged()
{
	acutPrintf(_T("\nViewChanged"));
}

void EdReactor::lispWillStart(const ACHAR* firstLine)
{
	acutPrintf(_T("\nlispWillStart, %s"), firstLine);
}

void EdReactor::lispEnded()
{
	acutPrintf(_T("\nlispEnded"));
}