#ifndef ZCADAPIDEF_H
#define ZCADAPIDEF_H

#ifndef _ZSOFT_MAC_
#ifndef ZCAD_PORT
	#ifdef ZCAD_API
		#define ZCAD_PORT _declspec(dllexport)
	#else
		#define ZCAD_PORT 
	#endif
#endif
#else

#define ZCAD_PORT
#endif

#endif
