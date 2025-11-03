#pragma once

#include "aced.h"

class EdReactor : public AcEditorReactor
{
public:
	ACRX_DECLARE_MEMBERS(EdReactor);

	EdReactor();
	virtual ~EdReactor();

	virtual void commandWillStart(const ACHAR* cmdStr);
	virtual void commandEnded(const ACHAR* cmdStr);
	virtual void commandCancelled(const ACHAR* cmdStr);
	virtual void beginDwgOpen(const ACHAR* filename);
	virtual void endDwgOpen(const ACHAR* filename, AcDbDatabase* pDb);
	virtual void viewChanged();
	virtual void lispWillStart(const ACHAR* firstLine);
	virtual void lispEnded();
};
