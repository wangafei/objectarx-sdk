#pragma once
#include "acssgetfilter.h"

class InputContextRec : public AcEdInputContextReactor
{
public:
	InputContextRec();
	~InputContextRec();

	virtual void	beginGetPoint(const AcGePoint3d* pointIn,
		const ACHAR* promptString,
		int initGetFlags,
		const ACHAR* pKeywords);

	virtual void	endGetPoint(Acad::PromptStatus returnStatus,
		const AcGePoint3d& pointOut,
		const ACHAR*& pKeyword);

	virtual void	beginGetAngle(const AcGePoint3d* pointIn,
		const ACHAR* promptString,
		int initGetFlags,
		const ACHAR* pKeywords);

	virtual void	endGetAngle(Acad::PromptStatus returnStatus,
		double& angle,
		const ACHAR*& pKeyword);

	virtual void	beginGetDistance(const AcGePoint3d* pointIn,
		const ACHAR* promptString,
		int initGetFlags,
		const ACHAR* pKeywords);

	virtual void	endGetDistance(Acad::PromptStatus returnStatus,
		double& distance,
		const ACHAR*& pKeyword);

	virtual void	beginGetOrientation(const AcGePoint3d* pointIn,
		const ACHAR* promptString,
		int   initGetFlags,
		const ACHAR* pKeywords);

	virtual void	endGetOrientation(Acad::PromptStatus returnStatus,
		double& angle,
		const ACHAR*& pKeyword);

	virtual void	beginGetCorner(const AcGePoint3d* firstCorner,
		const ACHAR* promptString,
		int   initGetFlags,
		const ACHAR* pKeywords);

	virtual void	endGetCorner(Acad::PromptStatus returnStatus,
		AcGePoint3d& secondCorner,
		const ACHAR*& pKeyword);

	virtual void	beginGetScaleFactor(const AcGePoint3d* pointIn,
		const ACHAR* promptString,
		int initGetFlags,
		const ACHAR* pKeywords);

	virtual void	endGetScaleFactor(Acad::PromptStatus returnStatus,
		double& distance,
		const ACHAR*& pKeyword);

	virtual void	beginGetString(const ACHAR* promptString, int initGetFlags);

	virtual void	endGetString(Acad::PromptStatus returnStatus, ACHAR* pString);

	virtual void	beginGetKeyword(const ACHAR* promptString,
		int initGetFlags,
		const ACHAR* pKeywords);

	virtual void	endGetKeyword(Acad::PromptStatus returnStatus, const ACHAR*& pKeyword);

	virtual void	beginGetInteger(const int* dfault,
		const ACHAR* promptString,
		int initGetFlags,
		const ACHAR* pKeywords);

	virtual void	endGetInteger(Acad::PromptStatus returnStatus,
		int& retValue,
		const ACHAR*& pKeyword);

	virtual void	beginGetColor(const int* dfault,
		const ACHAR* promptString,
		int initGetFlags,
		const ACHAR* pKeywords);

	virtual void	endGetColor(Acad::PromptStatus returnStatus,
		int& retValue,
		const ACHAR*& pKeyword);

	virtual void	beginGetReal(const double* dfault,
		const ACHAR* promptString,
		int   initGetFlags,
		const ACHAR* pKeywords);

	virtual void	endGetReal(Acad::PromptStatus returnStatus,
		double& returnValue,
		const ACHAR*& pKeyword);

	virtual void	beginEntsel(const ACHAR* promptString,
		int initGetFlags,
		const ACHAR* pKeywords);

	virtual void	endEntsel(Acad::PromptStatus returnStatus,
		AcDbObjectId& entPicked,
		AcGePoint3d& pickPoint,
		const ACHAR* pKeyword);

	virtual void	beginNentsel(const ACHAR* promptString,
		Adesk::Boolean pickFlag,
		int initGetFlags,
		const ACHAR* pKeywords);

	virtual void	endNentsel(Acad::PromptStatus returnStatus,
		AcDbObjectId entPicked,
		const AcGePoint3d&  pickPoint,
		const AcGeMatrix3d& xform,
		const resbuf* referenceStack,
		const ACHAR* pKeyword);

	virtual void	beginSSGet(const ACHAR*  pPrompt,
		int  initGetFlags,
		const ACHAR* pKeywords,
		const ACHAR* pSSControls, // str in ADS
		const AcArray<AcGePoint3d>& points,
		const resbuf* entMask);

	virtual void	endSSGet(Acad::PromptStatus returnStatus,
		const AcArray<AcDbObjectId>& ss);

	virtual void	beginDragSequence(const ACHAR* promptString);

	virtual void	endDragSequence(Acad::PromptStatus returnStatus,
		AcGePoint3d& pickPoint, AcGeVector3d& vec);

	virtual void	beginQuiescentState();
	virtual void	endQuiescentState();
protected:
private:
};