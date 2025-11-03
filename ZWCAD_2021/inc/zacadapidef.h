#pragma once

#ifndef ZCADAPIDEF_H
#define ZCADAPIDEF_HH

#ifndef _ZSOFT_MAC_
#ifndef ZCAD_PORT
	#ifdef ZCAD_API
		#define ZCAD_PORT _declspec(dllexport)
	#else
		#define ZCAD_PORT _declspec(dllimport)
	#endif
#endif
#else

#define ZCAD_PORT
#endif

#endif
