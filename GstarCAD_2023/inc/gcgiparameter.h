/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "rxcopyonwriteobject.h"

#pragma pack(push, 8)

class GcGiParameterImp;

class GcGiParameter : public GcRxCopyOnWriteObject
{
  friend class GcGiParameterImp;

public:
  GCRX_DECLARE_MEMBERS_READWRITE_EXPIMP(GcGiParameter, GcGiParameterImp, GCBASE_PORT);

  GCBASE_PORT GcGiParameter(GcGiParameterImp* pImp);
  GCBASE_PORT GcGiParameter(const GcGiParameter& other);

  GCBASE_PORT const GcGiParameter& operator=(const GcGiParameter& other);
};

#pragma pack(pop)