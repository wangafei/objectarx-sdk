
#ifndef _GCPLPLOTPROGRESS_H
#define _GCPLPLOTPROGRESS_H

#include "Gcpl.h"
class GcPlPlotProgress
{
public:

	enum SheetCancelStatus {
		kSheetContinue,
		kSheetCanceledByCancelButton,
		kSheetCanceledByCancelAllButton,
		kSheetCanceledByCaller,
		kSheetCancelStatusCount
	};

	enum PlotCancelStatus {
		kPlotContinue,
		kPlotCanceledByCaller,
		kPlotCanceledByCancelAllButton,
		kPlotCancelStatusCount
	};

	virtual bool isPlotCancelled() const = 0;
	virtual void setPlotCancelStatus(PlotCancelStatus Cancel) = 0;
	virtual PlotCancelStatus plotCancelStatus() const = 0;

	virtual void setPlotProgressRange(int nLower, int nUpper) = 0;
	virtual void getPlotProgressRange(int &nLower, int &nUpper) const = 0;

	virtual void setPlotProgressPos(int nPos) = 0;
	virtual int  plotProgressPos() const = 0;

	virtual bool isSheetCancelled() const = 0;
	virtual void setSheetCancelStatus(SheetCancelStatus Cancel) = 0;
	virtual SheetCancelStatus sheetCancelStatus() const = 0;

	virtual void setSheetProgressRange(int nLower, int nUpper) = 0;
	virtual void getSheetProgressRange(int &nLower, int &nUpper) const = 0;

	virtual void setSheetProgressPos(int nPos) = 0;
	virtual int  sheetProgressPos() const = 0;

	virtual bool setIsVisible(bool bVisible) = 0;
	virtual bool isVisible() const = 0;

	virtual bool setStatusMsgString(const GCHAR *pMsg) = 0;
	virtual bool getStatusMsgString(GCHAR *& pMsg) const = 0;

	virtual void heartbeat(void) = 0;
};
class GcPlPlotProgressDialog;
typedef void (*GCPLPLTPRGHELPPROC)(GcPlPlotProgressDialog *pGcPlPlotProgressDialog);

class GcPlPlotProgressDialog : public GcPlPlotProgress 
{
public:
	enum PlotMSGIndex {
		kDialogTitle,
		kSheetName,
		kSheetNameToolTip,
		kStatus,
		kSheetProgressCaption,
		kSheetSetProgressCaption,
		kMsgCancelling,
		kMsgCancellingCurrent,
		kCancelSheetBtnMsg,
		kCancelJobBtnMsg,
		kMsgCount
	};

	virtual bool onBeginPlot() = 0;
	virtual bool onEndPlot() = 0;

	virtual bool onBeginSheet() = 0;
	virtual bool onEndSheet() = 0;

	virtual bool setPlotMsgString(PlotMSGIndex index, const GCHAR *pMsg) = 0;
	virtual bool getPlotMsgString(PlotMSGIndex index, GCHAR *& pMsg) const = 0;

	virtual bool isSingleSheetPlot() const = 0;

	virtual void destroy() = 0;
};

GCPL_PORT GcPlPlotProgressDialog* __stdcall
	gcplCreatePlotProgressDialog( HWND hParent, 
	bool bPreview = false, 
	int nSheets = 1,
	GCPLPLTPRGHELPPROC hlpProc = NULL,
	bool bShowCancelSheetButton = true);

#endif //_GCPLPLOTPROGRESS_H