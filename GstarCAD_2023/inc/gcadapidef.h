/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#ifndef GCADAPIDEF_H
#define GCADAPIDEF_H

#ifndef _GSOFT_MAC_
#ifndef GCAD_PORT
	#ifdef GCAD_API
		#include "gsoft.h"
		#define GCAD_PORT GSOFT_EXPORT
	#else
		#define GCAD_PORT
	#endif
#endif
#else
#define GCAD_PORT
#endif 

#endif 