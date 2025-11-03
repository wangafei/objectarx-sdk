#pragma once
#include "stdafx.h"
#include "acdocman.h"

class DocManReactor : public AcApDocManagerReactor
{
public:
	ACRX_DECLARE_MEMBERS(DocManReactor);

	DocManReactor();
	~DocManReactor();

	virtual void              documentCreateStarted(ZcApDocument* pDocCreating);

	virtual void              documentCreated(ZcApDocument* pDocCreating);

	virtual void              documentToBeDestroyed(ZcApDocument* pDocToDestroy);

	virtual void              documentDestroyed(const ZTCHAR* fileName);

	virtual void              documentCreateCanceled(ZcApDocument* pDocCreateCancelled);

	virtual void              documentLockModeWillChange(ZcApDocument*,
														ZcAp::DocLockMode myCurrentMode,
														ZcAp::DocLockMode myNewMode,
														ZcAp::DocLockMode currentMode,
														const ZTCHAR* pGlobalCmdName);
	virtual void              documentLockModeChangeVetoed(ZcApDocument*,
														const ZTCHAR* pGlobalCmdName);
	virtual void              documentLockModeChanged(ZcApDocument*,
														ZcAp::DocLockMode myPreviousMode,
														ZcAp::DocLockMode myCurrentMode,
														ZcAp::DocLockMode currentMode,
														const ZTCHAR* pGlobalCmdName);

	virtual void              documentBecameCurrent(ZcApDocument*);

	virtual void              documentToBeActivated(ZcApDocument* pActivatingDoc);

	virtual void              documentToBeDeactivated(ZcApDocument* pDeActivatedDoc);

	virtual void              documentActivationModified(bool bActivation);

	virtual void              documentActivated(ZcApDocument* pActivatedDoc);
protected:
private:
};