//////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2016 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form.   
//
//////////////////////////////////////////////////////////////////////////////



/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0613 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for U:\develop\global\src\coreapps\opm\AcPp.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0613 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IAcPpAcadInput,0x07816A95,0x3C14,0x4236,0xB9,0xD3,0xAA,0x7F,0x4A,0x4A,0x1E,0xFB);


MIDL_DEFINE_GUID(IID, IID_IAcPpPalette,0xA20A927F,0x5508,0x4624,0x91,0x57,0xFD,0x5C,0xBE,0x5B,0x2D,0x64);


MIDL_DEFINE_GUID(IID, IID_IAcPpPaletteEvents,0xC1EA7682,0x303C,0x4173,0xBA,0x92,0x0E,0xEF,0x3D,0xD3,0x75,0x6E);


MIDL_DEFINE_GUID(IID, IID_IAcPpPaletteSet,0x0CC0CED7,0x7D69,0x490b,0xA8,0x4B,0xA7,0x50,0x06,0x74,0xA2,0x9C);


MIDL_DEFINE_GUID(IID, IID_IAcPpPaletteSet2,0xF5EEE553,0xBE37,0x4513,0x8D,0x10,0x4F,0x27,0x21,0xBA,0xE3,0x33);


MIDL_DEFINE_GUID(IID, IID_IAcPpPaletteSetEvents,0xC3F530AF,0xE211,0x49fa,0x9E,0x02,0x28,0x29,0x0E,0x41,0x41,0xF6);


MIDL_DEFINE_GUID(IID, IID_IAcPpNavTreeNode,0x11E68B1B,0x2A9F,0x4b1d,0xBB,0x58,0xCD,0x5A,0x43,0xFB,0x6F,0x30);


MIDL_DEFINE_GUID(IID, IID_IAcPpNavTreeNodeCollectionIter,0x82AE492A,0x56B9,0x45cb,0x81,0xDD,0x96,0x78,0xCA,0x98,0xE3,0xB4);


MIDL_DEFINE_GUID(IID, IID_IAcPpNavTreeNodeCollection,0x9A28A23F,0x9714,0x4c48,0x8B,0xE9,0xCB,0x8D,0x59,0x1F,0x1F,0x3C);


MIDL_DEFINE_GUID(IID, IID_IAcPpNavTreeCmdBtn,0x17F515C8,0x18E6,0x4731,0xA2,0x9A,0x12,0xA5,0xAB,0x72,0xF2,0xA9);


MIDL_DEFINE_GUID(IID, IID_IAcPpNavTreeCmdBtnCollectionIter,0x1B14B5F9,0xD967,0x4c62,0xAE,0x3B,0xFA,0xD4,0xCF,0x05,0x1F,0x63);


MIDL_DEFINE_GUID(IID, IID_IAcPpNavTreeCmdBtnCollection,0x5AD8767E,0x93C1,0x4256,0x80,0x31,0x29,0xD7,0x26,0xF4,0xD8,0xED);


MIDL_DEFINE_GUID(IID, IID_IAcPpNavTree,0x3412E0C1,0x20F7,0x43dd,0xB9,0xED,0x42,0x99,0xCC,0xD4,0x50,0x6C);


MIDL_DEFINE_GUID(IID, IID_IAcPpNavTreeEvents,0xE08AE839,0x864C,0x42a7,0x90,0xD2,0xF7,0x00,0x30,0x6C,0x81,0x1C);


MIDL_DEFINE_GUID(IID, IID_IAcPpPalette2,0x772460DD,0x82F1,0x4e99,0xB7,0xBF,0x5A,0xA4,0xB3,0x1E,0x3D,0xB1);


MIDL_DEFINE_GUID(IID, LIBID_AcPpLib,0x5CD1397D,0x084E,0x4020,0x80,0x22,0xB6,0x5B,0x93,0x63,0x6D,0xC9);


MIDL_DEFINE_GUID(CLSID, CLSID_AcPpAcadInput,0x9307A809,0x170D,0x4A75,0xB8,0xEC,0xD3,0xC4,0x62,0xD2,0xF4,0xDB);


MIDL_DEFINE_GUID(CLSID, CLSID_AcPpPaletteSet,0x2FAA8BEA,0xAB1B,0x479a,0x97,0xB2,0x6E,0x7A,0xAB,0x38,0x75,0x0E);


MIDL_DEFINE_GUID(CLSID, CLSID_AcPpPalette,0x83E53FB0,0xC3F9,0x44c8,0x89,0x17,0x1A,0x79,0xD8,0x9B,0x90,0xAA);


MIDL_DEFINE_GUID(CLSID, CLSID_AcPpPalette2,0xD43BEA50,0xAE29,0x4bd6,0x83,0xB6,0xDE,0x3E,0xD2,0x3F,0x51,0x7A);


MIDL_DEFINE_GUID(CLSID, CLSID_AcPpNavTree,0xF06460E2,0x3313,0x47b0,0xB4,0x64,0xDA,0xC6,0xB1,0xF4,0x5A,0x21);


MIDL_DEFINE_GUID(CLSID, CLSID_AcPpNavTreeNode,0x927E6A91,0xB46D,0x4149,0xB0,0xF9,0xEC,0x25,0x71,0x2F,0xF1,0xE0);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



