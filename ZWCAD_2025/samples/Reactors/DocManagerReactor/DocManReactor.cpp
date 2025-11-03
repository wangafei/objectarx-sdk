#include "stdafx.h"
#include "DocManReactor.h"
#include "acutads.h"

ACRX_NO_CONS_DEFINE_MEMBERS(DocManReactor, AcApDocManagerReactor);

DocManReactor::DocManReactor()
{
}

DocManReactor::~DocManReactor()
{
}

void DocManReactor::documentCreateStarted(ZcApDocument * pDocCreating)
{
	acutPrintf(_T("\ndocumentCreateStarted"));
}

void DocManReactor::documentCreated(ZcApDocument * pDocCreating)
{
	acutPrintf(_T("\ndocumentCreated"));
}

void DocManReactor::documentToBeDestroyed(ZcApDocument * pDocToDestroy)
{
	acutPrintf(_T("\ndocumentToBeDestroyed"));
}

void DocManReactor::documentDestroyed(const ZTCHAR * fileName)
{
	acutPrintf(_T("\ndocumentDestroyed"));
}

void DocManReactor::documentCreateCanceled(ZcApDocument * pDocCreateCancelled)
{
	acutPrintf(_T("\ndocumentCreateCanceled"));
}

void DocManReactor::documentLockModeWillChange(ZcApDocument *, ZcAp::DocLockMode myCurrentMode, ZcAp::DocLockMode myNewMode, ZcAp::DocLockMode currentMode, const ZTCHAR * pGlobalCmdName)
{
	acutPrintf(_T("\ndocumentLockModeWillChange"));
}

void DocManReactor::documentLockModeChangeVetoed(ZcApDocument *, const ZTCHAR * pGlobalCmdName)
{
	acutPrintf(_T("\ndocumentLockModeChangeVetoed"));
}

void DocManReactor::documentLockModeChanged(ZcApDocument *, ZcAp::DocLockMode myPreviousMode, ZcAp::DocLockMode myCurrentMode, ZcAp::DocLockMode currentMode, const ZTCHAR * pGlobalCmdName)
{
	acutPrintf(_T("\ndocumentLockModeChanged"));
}

void DocManReactor::documentBecameCurrent(ZcApDocument *)
{
	acutPrintf(_T("\ndocumentBecameCurrent"));
}

void DocManReactor::documentToBeActivated(ZcApDocument * pActivatingDoc)
{
	acutPrintf(_T("\ndocumentToBeActivated"));
}

void DocManReactor::documentToBeDeactivated(ZcApDocument * pDeActivatedDoc)
{
	acutPrintf(_T("\ndocumentToBeDeactivated"));
}

void DocManReactor::documentActivationModified(bool bActivation)
{
	acutPrintf(_T("\ndocumentActivationModified"));
}

void DocManReactor::documentActivated(ZcApDocument * pActivatedDoc)
{
	acutPrintf(_T("\ndocumentActivated"));
}
