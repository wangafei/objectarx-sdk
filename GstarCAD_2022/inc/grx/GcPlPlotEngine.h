#pragma once
#include "GcPlObject.h"
#include "GcPlPlotInfo.h"
#include "GcPlPlotPageInfo.h"
#include "GcPlPlotProgress.h"
class GcPlPlotEngine
{
public:
	GcPlPlotEngine(void);
	virtual ~GcPlPlotEngine(void);

public:
	virtual Gcad::ErrorStatus beginPlot(GcPlPlotProgress* pPlotProgress, void* pParams = NULL);
	virtual Gcad::ErrorStatus endPlot(void* pParams = NULL);

	// This plotInfo must not be deleted until endDocument().
	virtual Gcad::ErrorStatus beginDocument(GcPlPlotInfo& plotInfo, 
		const GCHAR * pDocname,
		void *pParams = NULL,
		long nCopies = 1, 
		bool bPlotToFile = false, 
		const GCHAR * pFileName = NULL);
	virtual Gcad::ErrorStatus endDocument(void* pParams = NULL);

	// This plotInfo may be the same as for beginDocument().
	virtual Gcad::ErrorStatus beginPage(GcPlPlotPageInfo& pageInfo, 
		GcPlPlotInfo& plotInfo, 
		bool bLastPage, 
		void* pParams = NULL);
	virtual Gcad::ErrorStatus endPage(void* pParams = NULL);

	virtual Gcad::ErrorStatus beginGenerateGraphics(void* pParams = NULL);
	virtual Gcad::ErrorStatus beginGenerateGraphics(GcGiViewport*& pViewport, void* pParams = NULL);
	virtual Gcad::ErrorStatus endGenerateGraphics(void* pParams = NULL);

	virtual void destroy();
	virtual bool isBackgroundPackaging() const;
};

enum PreviewStatus {
  kNormal = 0,
  kPlot,
  kCancel,
  kNext,
  kPrevious
};

struct GCPL_PREVIEWENDPLOT {
  PreviewStatus nStatus;
};


