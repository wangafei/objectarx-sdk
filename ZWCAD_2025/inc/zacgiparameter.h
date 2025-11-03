
#pragma once

#include "zrxcopyonwriteobject.h"

#pragma pack(push, 8)

class ZcGiParameterImp;

class ZCDBCORE2D_PORT ZcGiParameter : public ZcRxCopyOnWriteObject
{
	friend class ZcGiParameterImp;

public:
	ZCRX_DECLARE_MEMBERS_READWRITE(ZcGiParameter, ZcGiParameterImp);

	ZcGiParameter(ZcGiParameterImp* pImp);
	ZcGiParameter(const ZcGiParameter& other);
	const ZcGiParameter& operator=(const ZcGiParameter& other);
};

#pragma pack(pop)
