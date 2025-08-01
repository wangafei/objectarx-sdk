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
/* Compiler settings for idlsource\acad.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0613 
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

MIDL_DEFINE_GUID(IID, LIBID_AutoCAD,0x51B6A117,0xCF84,0x4FEC,0x97,0x99,0xF6,0x17,0xFB,0xCD,0x25,0xF5);


MIDL_DEFINE_GUID(IID, IID_IAcadObject,0x364866EA,0x81ED,0x4087,0x9E,0x00,0xC8,0x7A,0x7C,0x58,0xC4,0xD9);


MIDL_DEFINE_GUID(IID, IID_IAcadDictionary,0x67BF6059,0x2C65,0x4F39,0x82,0x38,0x51,0xCD,0x00,0x4F,0x15,0xD1);


MIDL_DEFINE_GUID(IID, IID_IAcadEntity,0x009E12CB,0x87A5,0x4CE6,0xA3,0xE3,0x61,0xF5,0xB4,0x04,0xF5,0x53);


MIDL_DEFINE_GUID(IID, IID_IAcadBlock,0x356F1F9B,0x21D3,0x498C,0x90,0x69,0xBB,0xFE,0x4D,0x1A,0xE4,0xE4);


MIDL_DEFINE_GUID(IID, IID_IAcadDatabase,0xE4381A8A,0x279E,0x452A,0xA7,0x0A,0x72,0x75,0x64,0x9A,0x95,0xD4);


MIDL_DEFINE_GUID(IID, IID_IAcadSectionTypeSettings,0x432BADC7,0x67BA,0x43B2,0xB7,0xE9,0x8C,0x93,0xB5,0xAF,0x6E,0xC4);


MIDL_DEFINE_GUID(IID, IID_IAcadSectionTypeSettings2,0xBFEDE378,0x87A1,0x4EEE,0x8D,0x2B,0x5E,0xC3,0x89,0x49,0xA8,0xDD);


MIDL_DEFINE_GUID(IID, IID_IAcadHyperlink,0x126A9873,0xFCBA,0x4AAA,0x92,0xAA,0xDD,0x50,0x86,0xDD,0xD8,0x5E);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadHyperlink,0x82547C8C,0x44A8,0x42D7,0xAD,0x98,0x07,0x81,0x66,0xC5,0x73,0xA5);


MIDL_DEFINE_GUID(IID, IID_IAcadDynamicBlockReferenceProperty,0xD10B2C8F,0x4DE9,0x48E5,0x95,0xEB,0x5D,0x0B,0xA5,0xEE,0x9D,0xD4);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDynamicBlockReferenceProperty,0xFB58C0F7,0x5A5C,0x453B,0x86,0x02,0x53,0xE7,0x85,0xEF,0x0F,0x14);


MIDL_DEFINE_GUID(IID, IID_IAcadAcCmColor,0xFBD98E25,0x5DD2,0x4DFB,0xBA,0x4A,0x94,0x51,0x55,0x48,0xA9,0xDC);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadAcCmColor,0x8489ED0D,0x5A6D,0x4C59,0xB1,0x73,0x2F,0x98,0x55,0xDE,0x49,0x6C);


MIDL_DEFINE_GUID(IID, IID_IAcadObjectEvents,0x947459D9,0x469B,0x4B3A,0x89,0x2F,0xD4,0x62,0x96,0xBC,0xCF,0x89);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadObject,0xCC65C4AF,0x6B21,0x4F18,0x9E,0x97,0x11,0xFD,0xE9,0x63,0xC5,0x5E);


MIDL_DEFINE_GUID(IID, IID_IAcadXRecord,0xFA9E035D,0x8E13,0x4BBE,0x97,0x95,0x2A,0x96,0xAA,0x37,0x78,0x15);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadXRecord,0xABBB188C,0x0FAD,0x40C3,0x87,0xFC,0x1E,0x2F,0xBF,0x9D,0x44,0x5C);


MIDL_DEFINE_GUID(IID, IID_IAcadSortentsTable,0x38BA360C,0x37E3,0x4587,0xB7,0x5A,0xA1,0xC3,0xD7,0x40,0xE0,0x19);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSortentsTable,0x2A16F892,0x4AD1,0x4F21,0x99,0x17,0x62,0x4A,0x8D,0x06,0xA6,0x51);


MIDL_DEFINE_GUID(IID, IID_IAcadDimStyle,0x6839858A,0xBE2A,0x4976,0xA7,0xDF,0xFD,0x33,0x9E,0x5A,0xE5,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimStyle,0x19757890,0xE59D,0x4DC4,0x99,0x19,0x6D,0xE6,0x1F,0x98,0xD2,0x74);


MIDL_DEFINE_GUID(IID, IID_IAcadLayer,0x7B344FF1,0x4D80,0x41CB,0x9A,0x8A,0x91,0x29,0x7C,0xAE,0xEF,0x6A);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLayer,0x063B89E8,0x3728,0x4C7A,0xA6,0xB5,0xC2,0x15,0x0C,0xA6,0xAE,0xB8);


MIDL_DEFINE_GUID(IID, IID_IAcadLineType,0x72B732FC,0x1438,0x41B8,0x8A,0xF5,0x58,0xCB,0xFA,0x1B,0x0B,0x84);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLineType,0xD0282B8F,0x2FF8,0x41E9,0xB9,0x19,0xE4,0x93,0xD9,0x60,0xDE,0x4C);


MIDL_DEFINE_GUID(IID, IID_IAcadMaterial,0x808DC5F8,0xF6FE,0x471E,0x87,0xC8,0x02,0xCC,0x36,0xF1,0x07,0xF5);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMaterial,0xE8088DA8,0xB0EF,0x437E,0xBF,0xCF,0xE3,0x8A,0x73,0xE3,0xFC,0x04);


MIDL_DEFINE_GUID(IID, IID_IAcadRegisteredApplication,0xE62A6236,0xC6D0,0x441A,0xA0,0x09,0x46,0x8B,0x38,0xF6,0xB5,0xBC);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadRegisteredApplication,0xB911B0D4,0x5599,0x4498,0xA6,0xC3,0x65,0x4A,0x36,0x1D,0x98,0x4E);


MIDL_DEFINE_GUID(IID, IID_IAcadTextStyle,0x759C9106,0x92A0,0x4F4B,0x8B,0x4E,0x6C,0xF1,0xC8,0x14,0x23,0xAD);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadTextStyle,0x5E5580AD,0x5750,0x4DB1,0x85,0xAA,0xD1,0x5B,0xC2,0xA4,0xF6,0xE8);


MIDL_DEFINE_GUID(IID, IID_IAcadUCS,0xA4558C0D,0xE59F,0x463F,0x95,0x94,0x66,0x0E,0x50,0xE7,0x6A,0xC2);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadUCS,0x37C0E6FF,0xF35A,0x4498,0xB5,0x3A,0xF6,0xEF,0x19,0x03,0x64,0xCF);


MIDL_DEFINE_GUID(IID, IID_IAcadView,0xB9B10EC3,0xA668,0x419E,0xA0,0x06,0x79,0xD5,0x02,0xCA,0x98,0x6E);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadView,0x3AA0D898,0xAF91,0x4BFD,0x87,0x1B,0x68,0x84,0xF7,0x41,0xF7,0x4A);


MIDL_DEFINE_GUID(IID, IID_IAcadViewport,0xDB436B59,0xFBFC,0x4550,0x87,0x29,0xF2,0x57,0x78,0xBB,0xBE,0x46);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadViewport,0x4360A8E5,0xFE2C,0x470C,0x86,0xAC,0x69,0xDF,0x9E,0x78,0xD9,0xCD);


MIDL_DEFINE_GUID(IID, IID_IAcadGroup,0xD81C0DAE,0x2481,0x4A63,0x90,0x36,0x0C,0x33,0x27,0x52,0x43,0xD7);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadGroup,0x3A028ECB,0xFD98,0x466D,0x9D,0xD1,0x7B,0xE3,0xAB,0xFD,0x21,0x9B);


MIDL_DEFINE_GUID(IID, IID_IAcadPlotConfiguration,0x0AEE854F,0x9DA1,0x4410,0xBD,0x18,0xAC,0xD1,0x2A,0xB9,0xE5,0x8D);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPlotConfiguration,0xE8D2BE0B,0xFC02,0x44E6,0xA9,0xCE,0x6C,0x8F,0x3F,0x9A,0xC2,0x8E);


MIDL_DEFINE_GUID(IID, IID_IAcadLayout,0x5AABEAF3,0x786D,0x45EF,0x87,0xAD,0x09,0x30,0x25,0x15,0x43,0x4B);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLayout,0xD9E05C36,0xB6DF,0x497E,0x8B,0x17,0xA7,0xE4,0x64,0xD5,0xAE,0x38);


MIDL_DEFINE_GUID(IID, IID_IAcadIdPair,0xE778C0C5,0xD512,0x487C,0x89,0x54,0x03,0xE9,0x19,0xDD,0x15,0xA4);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadIdPair,0xCCD8F5AC,0x6BE4,0x4339,0x8F,0xA4,0x96,0x92,0x5A,0x91,0x17,0x53);


MIDL_DEFINE_GUID(IID, IID_IAcadTableStyle,0xA05D4208,0x9F61,0x4C93,0x9F,0x40,0x0C,0xE9,0xA9,0x84,0x2C,0x10);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadTableStyle,0x52714180,0x45EE,0x43AC,0x80,0xB0,0xD6,0x9B,0x79,0x40,0xC5,0x0D);


MIDL_DEFINE_GUID(IID, IID_IAcadSectionSettings,0xCDEAA78F,0x8112,0x4368,0xA4,0xB9,0x41,0x33,0x09,0x59,0x3F,0xC5);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSectionSettings,0x6951AFB4,0x324F,0x4218,0x82,0xEB,0xA6,0x47,0x6E,0x15,0x4B,0x02);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSectionTypeSettings,0xBA697283,0x3CDA,0x4918,0x9A,0xEB,0xE0,0xE1,0x5F,0xC3,0x42,0x77);


MIDL_DEFINE_GUID(IID, IID_IAcadMLeaderStyle,0x35B096E1,0x93CB,0x4E34,0xA3,0xDA,0xF5,0x7E,0xC0,0x8C,0x74,0x39);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMLeaderStyle,0xE1F219D1,0x1558,0x4EAB,0xB6,0xEF,0x5B,0x9A,0x2A,0x57,0xFC,0xA7);


MIDL_DEFINE_GUID(IID, IID_IAcadHyperlinks,0xA5C5BE7A,0x5814,0x4D85,0x9D,0x39,0x8F,0xA4,0xEF,0x57,0x26,0xD7);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadHyperlinks,0x45C632D0,0xF5DD,0x4C7C,0x91,0x82,0x0B,0xDE,0x8A,0x77,0x11,0x9B);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDictionary,0xC5F3036D,0xACD5,0x40A6,0xB8,0x22,0x5B,0xED,0xA2,0xC8,0x06,0x83);


MIDL_DEFINE_GUID(IID, IID_IAcadLayers,0xD591AF6D,0x0CD8,0x4A33,0x8D,0x44,0xEC,0xF6,0x6C,0x75,0xE8,0x02);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLayers,0x273D815C,0x6C08,0x4AFA,0x90,0x4D,0xA1,0x24,0xC6,0x5D,0x85,0x83);


MIDL_DEFINE_GUID(IID, IID_IAcadDimStyles,0xC5C188BF,0xA9E7,0x45E6,0x96,0x6C,0xDB,0x77,0x7C,0xBE,0xDF,0xF7);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimStyles,0xC89600D1,0x9CAB,0x4333,0x96,0x98,0x55,0x86,0x0F,0x7E,0xB4,0xFB);


MIDL_DEFINE_GUID(IID, IID_IAcadDictionaries,0x4E2EDA54,0xA67D,0x47D2,0x82,0xB0,0xA9,0x6A,0xA4,0x93,0x3D,0xE3);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDictionaries,0xAF26D17C,0xC40A,0x4DBE,0xB7,0x42,0xF0,0x29,0xDC,0xC4,0xF3,0xC0);


MIDL_DEFINE_GUID(IID, IID_IAcadLineTypes,0xDAF7067D,0xEC56,0x4AC1,0x88,0xD6,0x4E,0x34,0xC4,0x0C,0xF0,0x79);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLineTypes,0x875F8998,0xEC9A,0x4D25,0xAD,0xC2,0x5D,0x31,0x78,0xD8,0xEA,0x3C);


MIDL_DEFINE_GUID(IID, IID_IAcadMaterials,0x997A401C,0x5024,0x4213,0x8B,0x6C,0xC0,0xFE,0xCA,0x89,0xE9,0xF3);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMaterials,0x8F96AC9F,0x4CCC,0x4A0A,0x8B,0xEA,0x70,0x41,0x2E,0x23,0x16,0x0C);


MIDL_DEFINE_GUID(IID, IID_IAcadTextStyles,0xB81E9282,0x3131,0x42FE,0xA9,0x13,0xBD,0x12,0x7B,0x03,0x38,0x07);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadTextStyles,0x33958D6A,0x4322,0x4590,0x92,0x27,0xC0,0x32,0x3C,0x43,0x9B,0x86);


MIDL_DEFINE_GUID(IID, IID_IAcadUCSs,0xFE63C815,0x1246,0x4E88,0x96,0x08,0x14,0xEF,0x27,0xC4,0xB4,0xE8);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadUCSs,0x0D11ACB2,0x2120,0x4B39,0xAA,0xA4,0xBC,0x7A,0x9B,0x2D,0xA4,0x29);


MIDL_DEFINE_GUID(IID, IID_IAcadRegisteredApplications,0xA28C77DE,0x41CB,0x4C50,0xBA,0x8E,0x04,0xA5,0x77,0x83,0xF0,0x58);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadRegisteredApplications,0x0796C07B,0x889A,0x4D0C,0xBC,0x16,0x93,0x9A,0xD0,0xB6,0x89,0xF4);


MIDL_DEFINE_GUID(IID, IID_IAcadViews,0xD6F07277,0x087C,0x4A49,0x80,0x92,0x80,0x46,0xD5,0xB4,0xCD,0xA3);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadViews,0xB32A697C,0x2268,0x4828,0xB7,0x57,0x50,0x7C,0x78,0x3C,0xFC,0x70);


MIDL_DEFINE_GUID(IID, IID_IAcadViewports,0x74684C14,0xF782,0x4287,0x93,0xE4,0x44,0x05,0x60,0x59,0x23,0x01);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadViewports,0x0FC62543,0xA5F1,0x4C19,0x96,0x82,0xDE,0x84,0x08,0xA4,0xB2,0x12);


MIDL_DEFINE_GUID(IID, IID_IAcadGroups,0x9B12741A,0xCB8E,0x4484,0xBC,0xEA,0x80,0x7A,0x30,0x43,0x59,0xC1);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadGroups,0xA3808A1E,0x1CAC,0x4C14,0xA4,0x43,0x99,0x8F,0x26,0x66,0x9F,0xF1);


MIDL_DEFINE_GUID(IID, IID_IAcadBlocks,0xAF0355A4,0x33B9,0x4D2F,0x92,0x2E,0xB5,0xD0,0x27,0x79,0xEE,0xDA);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadBlocks,0x8A8FD330,0xD31D,0x4639,0xBD,0x3B,0x56,0x91,0x63,0xB2,0xEB,0xE9);


MIDL_DEFINE_GUID(IID, IID_IAcadLayouts,0x7F9BC070,0xB9B4,0x48EF,0x9B,0x31,0x1A,0x42,0xE5,0xDA,0xD7,0x40);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLayouts,0xD8842A05,0xF84A,0x404B,0x9A,0xDF,0xC9,0xD3,0x80,0xF0,0x26,0x2D);


MIDL_DEFINE_GUID(IID, IID_IAcadPlotConfigurations,0x6A44E2D4,0x25D2,0x4AAD,0xBF,0xBF,0xC6,0xEE,0x53,0x1B,0x40,0x68);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPlotConfigurations,0x3DB4B2BF,0xF58A,0x407D,0x86,0x26,0x4C,0xBD,0xE8,0x6C,0x1F,0xB0);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadEntity,0x9B768196,0x44AA,0x4728,0x94,0x8E,0x22,0x06,0x1D,0x60,0x50,0x16);


MIDL_DEFINE_GUID(IID, IID_IAcadShadowDisplay,0xA5DF8294,0x6C8C,0x4427,0x98,0xD7,0x46,0xFC,0x75,0x4D,0xDC,0x7B);


MIDL_DEFINE_GUID(IID, IID_IAcadRasterImage,0x6515313D,0x84A3,0x4B21,0x88,0x40,0x31,0x8A,0x36,0x65,0xC8,0x9E);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadRasterImage,0xC8AC1000,0xD574,0x4A8B,0xAB,0x3C,0xF3,0x45,0xBA,0xEF,0x36,0x83);


MIDL_DEFINE_GUID(IID, IID_IAcad3DFace,0x80E24531,0x60B5,0x47A2,0xB2,0x4D,0x9F,0xA6,0x58,0x04,0xE2,0x34);


MIDL_DEFINE_GUID(CLSID, CLSID_Acad3DFace,0x463D5542,0xC77E,0x4F8C,0x85,0xFF,0xD7,0x49,0x3A,0x43,0xBD,0x3F);


MIDL_DEFINE_GUID(IID, IID_IAcad3DPolyline,0x4151ED8B,0x9A32,0x4BE6,0xA8,0xD2,0x15,0x90,0x67,0x71,0xC4,0xA6);


MIDL_DEFINE_GUID(CLSID, CLSID_Acad3DPolyline,0x3040CCB9,0xE25B,0x4087,0xB3,0x6D,0xD2,0xF4,0x09,0xB7,0x33,0x8F);


MIDL_DEFINE_GUID(IID, IID_IAcadRegion,0x67AD8688,0xC080,0x4EEF,0xBC,0x98,0xA3,0xAD,0x66,0x26,0x66,0x5D);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadRegion,0x806B9CA4,0x9DB9,0x445A,0x83,0xD2,0x87,0xF7,0xBB,0x1D,0x00,0x72);


MIDL_DEFINE_GUID(IID, IID_IAcad3DSolid,0x81C6B11D,0xAFBF,0x4EB8,0x94,0xCC,0xBA,0xDB,0x1E,0xB8,0xC7,0xCB);


MIDL_DEFINE_GUID(CLSID, CLSID_Acad3DSolid,0x07621A84,0x9457,0x415D,0xBF,0xD7,0xE9,0x3C,0x90,0x96,0x6F,0x97);


MIDL_DEFINE_GUID(IID, IID_IAcadArc,0x36ABD135,0x1B59,0x4787,0x97,0x7B,0x38,0x6C,0x0F,0x19,0xF8,0x85);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadArc,0x585BFF19,0x0001,0x43E6,0xA7,0x37,0x43,0x15,0xDC,0x7D,0x38,0xDC);


MIDL_DEFINE_GUID(IID, IID_IAcadAttribute,0x7A50A11C,0xA924,0x4A7A,0xB3,0x6E,0x70,0x5C,0xF5,0xC1,0x95,0xCA);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadAttribute,0xA3238286,0x3FBE,0x47D3,0x99,0xAB,0x6B,0xEF,0xF7,0x1F,0xB6,0xDD);


MIDL_DEFINE_GUID(IID, IID_IAcadAttributeReference,0xC367B1E6,0x1D6D,0x4B4D,0x9C,0xBC,0x54,0xA9,0x6D,0xC4,0x0B,0x66);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadAttributeReference,0x8D352F9D,0x9032,0x4D35,0xAE,0x8B,0x1A,0x2D,0xC4,0xA8,0xBF,0xDA);


MIDL_DEFINE_GUID(IID, IID_IAcadBlockReference,0xC4C47A3D,0x09CB,0x4309,0xBC,0xC9,0xD3,0x06,0x07,0x5D,0x79,0xF4);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadBlockReference,0x90B39404,0xB229,0x4FC9,0xA4,0xB1,0x8E,0xE6,0xBD,0x0C,0x47,0x29);


MIDL_DEFINE_GUID(IID, IID_IAcadCircle,0x07018367,0x5BD5,0x4585,0x94,0x49,0x6D,0x3B,0x08,0xFF,0xE5,0x74);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadCircle,0x92025176,0x077A,0x4E9D,0xA2,0x26,0xD4,0x7E,0x3C,0x7B,0xE3,0xEC);


MIDL_DEFINE_GUID(IID, IID_IAcadEllipse,0x6001DC14,0xCFF5,0x49E9,0x83,0x3B,0xF9,0xC7,0x19,0x2F,0x4F,0x92);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadEllipse,0xA5BF4DA8,0x0AE4,0x47FB,0x86,0xFD,0xD2,0x12,0xC7,0xBE,0x23,0x89);


MIDL_DEFINE_GUID(IID, IID_IAcadHatch,0x9B1D1AF7,0xE35B,0x4845,0xBE,0x08,0xCD,0xCD,0xBB,0x8E,0x29,0x69);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadHatch,0x74C21669,0x1C61,0x45E7,0x90,0x1B,0x3B,0xB4,0xA0,0xB0,0x93,0x70);


MIDL_DEFINE_GUID(IID, IID_IAcadLeader,0x20E59E60,0xDD27,0x4668,0x80,0x8F,0xE1,0xDA,0x09,0x81,0x6F,0xFA);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLeader,0xDBB18BED,0x79B7,0x4430,0xAC,0x0B,0x1E,0x83,0x0F,0x36,0x57,0x63);


MIDL_DEFINE_GUID(IID, IID_IAcadSubEntity,0xFBFA7060,0x7AFD,0x4B19,0x85,0xE2,0x4C,0x13,0xCF,0x68,0xF0,0xFC);


MIDL_DEFINE_GUID(IID, IID_IAcadMLeaderLeader,0xC1BCB9BD,0x555B,0x43BC,0xBE,0xBB,0xB0,0x29,0x24,0x4E,0xC8,0x5E);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMLeaderLeader,0x53A02CFF,0x6900,0x4D72,0x9F,0xF5,0xB9,0xD6,0xBF,0x66,0xAA,0xCC);


MIDL_DEFINE_GUID(IID, IID_IAcadMLeader,0x797E2112,0x4FCD,0x4BC8,0xBA,0x74,0xA0,0xE7,0x6D,0x73,0xC8,0x2C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMLeader,0xBB1F3896,0xD460,0x401A,0x80,0x74,0x07,0x48,0xBE,0xA7,0x42,0x75);


MIDL_DEFINE_GUID(IID, IID_IAcadLWPolyline,0x37B9BD1F,0xD194,0x470E,0x90,0xC2,0x7D,0x28,0xDE,0x88,0xEC,0xE6);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLWPolyline,0x3E475628,0xC0C3,0x4BA5,0x94,0x69,0x64,0xB3,0x80,0x21,0x21,0xB0);


MIDL_DEFINE_GUID(IID, IID_IAcadLine,0x1EDF1191,0x8CB7,0x4822,0x85,0xA0,0x9E,0x69,0x68,0xF4,0x36,0xDE);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLine,0x19024DF1,0x65F2,0x41D2,0x9F,0xC2,0xC6,0xD1,0x6B,0x51,0xFC,0xB6);


MIDL_DEFINE_GUID(IID, IID_IAcadMText,0xE2CDCBAB,0xAA43,0x405D,0x86,0x77,0x0F,0x95,0x07,0x75,0xCB,0x52);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMText,0x62633E55,0x0DCC,0x48D7,0x84,0x38,0x3F,0xA1,0x31,0xCA,0xDF,0x6C);


MIDL_DEFINE_GUID(IID, IID_IAcadPoint,0x21FBF38C,0x35D0,0x46C9,0x95,0x7B,0xE5,0xE9,0x1A,0x2F,0xFD,0x60);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPoint,0xEEF55288,0xC754,0x491C,0xB4,0xE1,0xD5,0x33,0x93,0xBF,0x88,0xAD);


MIDL_DEFINE_GUID(IID, IID_IAcadPolyline,0xDBCB2E09,0x996C,0x4980,0x8C,0x74,0xE9,0x38,0xDD,0x69,0x63,0xE4);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPolyline,0x46AEE2CC,0xA92F,0x4BA9,0xB6,0xB3,0x13,0x40,0x3D,0x79,0xD6,0xD3);


MIDL_DEFINE_GUID(IID, IID_IAcadPolygonMesh,0x9FD474CE,0xDE30,0x4366,0xA8,0xF1,0xF8,0x0E,0x7A,0x7E,0x4C,0xD1);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPolygonMesh,0x73ED65E4,0xEF95,0x488E,0x9F,0x14,0xC0,0x1D,0x69,0x12,0x5A,0x48);


MIDL_DEFINE_GUID(IID, IID_IAcadRay,0x514D33A0,0xA41B,0x4F17,0xB3,0x87,0x97,0xD7,0xAB,0xB4,0xEE,0xEC);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadRay,0x1E8D9695,0xE3C1,0x4047,0x88,0x47,0x0D,0x01,0xB0,0xA4,0x35,0x64);


MIDL_DEFINE_GUID(IID, IID_IAcadShape,0xE9DD5EED,0x9285,0x4370,0x80,0x2E,0x84,0x01,0x46,0x81,0x87,0x82);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadShape,0xB8C7D559,0x9516,0x4157,0xB0,0x63,0x61,0x3B,0xFA,0xF8,0x3B,0xB8);


MIDL_DEFINE_GUID(IID, IID_IAcadSolid,0x6F53FD11,0x0EB8,0x4A8A,0x8E,0x5D,0x1E,0x17,0xF6,0xB7,0x95,0x1F);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSolid,0x8CDF4C9E,0xF1C5,0x4264,0xB3,0xE7,0x6A,0xA4,0x4B,0x5B,0xB8,0x9F);


MIDL_DEFINE_GUID(IID, IID_IAcadSpline,0x9789094A,0x6C7E,0x459B,0x99,0x10,0x30,0x91,0x89,0x24,0xE1,0x74);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSpline,0x409885E6,0xF896,0x4EFD,0xBC,0xC4,0x16,0x09,0x31,0x32,0x5E,0x5C);


MIDL_DEFINE_GUID(IID, IID_IAcadText,0xA70415F6,0x0956,0x48DC,0x81,0x4F,0xE7,0xBA,0x43,0x7A,0xB9,0x9C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadText,0xAFD81966,0x5CBF,0x4756,0x90,0x61,0xEB,0x50,0x69,0xC5,0x4D,0xBC);


MIDL_DEFINE_GUID(IID, IID_IAcadTolerance,0xDC52646B,0xEF0E,0x433D,0xB2,0xC5,0x38,0x9C,0x02,0x2B,0x78,0x48);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadTolerance,0xFBE13464,0x124F,0x4A81,0x8B,0x5C,0x04,0xDE,0x69,0xEA,0xC0,0x6F);


MIDL_DEFINE_GUID(IID, IID_IAcadTrace,0x21C946D9,0x7D80,0x4BCC,0x9B,0x58,0x3F,0x69,0x69,0x46,0xB8,0x7A);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadTrace,0x2111BF4D,0xB691,0x4E68,0xA0,0x21,0x4B,0x17,0xCF,0x32,0xAB,0x8F);


MIDL_DEFINE_GUID(IID, IID_IAcadXline,0x8D4E0CAF,0x24C8,0x4198,0xB2,0x8C,0xEA,0x50,0x54,0xFF,0x8E,0xAD);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadXline,0x1A368D01,0x0A8E,0x496D,0x92,0x92,0xE3,0x02,0xD4,0xB5,0x30,0x63);


MIDL_DEFINE_GUID(IID, IID_IAcadPViewport,0x1FB65978,0xD52E,0x464D,0x87,0x5E,0x20,0x2B,0x04,0x2F,0x76,0x3A);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPViewport,0x894A26C0,0x7E80,0x4336,0x87,0xD4,0xFE,0x2C,0x75,0x8A,0xD8,0x88);


MIDL_DEFINE_GUID(IID, IID_IAcadMInsertBlock,0x9A2666BC,0x1652,0x42BA,0x9C,0x9F,0x17,0x0A,0x32,0x19,0xE3,0x82);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMInsertBlock,0x0DA9547B,0x9E13,0x4549,0x8B,0x01,0x78,0xC3,0x14,0xAC,0xCE,0x69);


MIDL_DEFINE_GUID(IID, IID_IAcadPolyfaceMesh,0x98334CA8,0x7F09,0x4E17,0xA0,0x42,0x69,0x69,0xAA,0x9B,0xDC,0x58);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPolyfaceMesh,0x9BB89379,0xE21C,0x49C4,0x99,0x7C,0x70,0x93,0xC0,0xFD,0x6C,0x28);


MIDL_DEFINE_GUID(IID, IID_IAcadMLine,0xB5D4757D,0xB6E5,0x4FC4,0x90,0xFA,0x39,0xBB,0x0D,0x0B,0x9F,0xE8);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMLine,0x208EA3A0,0xEA41,0x4378,0xA4,0x34,0x29,0xCE,0x36,0x73,0x2B,0xC1);


MIDL_DEFINE_GUID(IID, IID_IAcadExternalReference,0x04ABD24D,0xEB15,0x4D7A,0xB5,0x47,0x9E,0xE5,0xB5,0x42,0x0D,0xF4);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadExternalReference,0xBFBFAA19,0x212A,0x47EF,0xBC,0x01,0xE7,0x30,0xA6,0xE0,0x5B,0xB8);


MIDL_DEFINE_GUID(IID, IID_IAcadTable,0x7FC60C21,0x0F2A,0x489D,0x89,0x60,0x3F,0x87,0x01,0x99,0x56,0x03);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadTable,0x5D0F5C31,0xDF55,0x446B,0xAA,0xA2,0x2A,0x56,0x32,0x35,0xBA,0x44);


MIDL_DEFINE_GUID(IID, IID_IAcadOle,0xD74D0794,0x5447,0x488D,0x9B,0xBA,0x56,0x16,0x23,0x94,0x9E,0xA5);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadOle,0xC6C73F45,0x8A5A,0x4A1F,0x9F,0xFE,0x31,0xDE,0xD6,0xA8,0x51,0x23);


MIDL_DEFINE_GUID(IID, IID_IAcadHelix,0xA9BBFDE2,0x7BD4,0x4AEC,0xA5,0x1E,0x8A,0xC3,0xBD,0x7D,0x7F,0x84);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadHelix,0xDA09C4EE,0x95DE,0x4382,0x95,0xCC,0x70,0x68,0xEA,0x23,0x31,0x82);


MIDL_DEFINE_GUID(IID, IID_IAcadSurface,0xE69B51CC,0xE661,0x4A3F,0x90,0x66,0xDB,0x33,0xBD,0xE0,0x6C,0xAA);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSurface,0x1E24C48F,0x197D,0x42F6,0xA8,0x65,0x3D,0x95,0xF0,0xAB,0x2D,0x27);


MIDL_DEFINE_GUID(IID, IID_IAcadPlaneSurface,0x9A466777,0xC40C,0x4625,0x8C,0x61,0x26,0xEA,0x00,0x8A,0x7F,0x28);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPlaneSurface,0xEEC9E51D,0xA609,0x4D31,0x80,0xA1,0x51,0x9D,0xD3,0x63,0x94,0xFA);


MIDL_DEFINE_GUID(IID, IID_IAcadExtrudedSurface,0x06840887,0xF52F,0x442E,0xA3,0x54,0x08,0xE4,0x1C,0x0A,0xF2,0x4C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadExtrudedSurface,0xD7350B82,0x3736,0x44AE,0x92,0xA4,0x85,0xCC,0x17,0x74,0x9E,0xD5);


MIDL_DEFINE_GUID(IID, IID_IAcadRevolvedSurface,0x61E812C0,0x6F60,0x4475,0xAF,0xE4,0xA8,0x99,0x0E,0xF2,0x04,0xB4);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadRevolvedSurface,0x9DE83266,0xE5E0,0x4BA1,0xAF,0x80,0xB2,0xA6,0x3B,0xF6,0x30,0xCF);


MIDL_DEFINE_GUID(IID, IID_IAcadSweptSurface,0x3203AA82,0xAABA,0x49E1,0xA5,0x04,0x07,0x25,0xF6,0x2F,0x95,0xEA);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSweptSurface,0x190FB7CC,0x91C6,0x4948,0xB8,0x5C,0xC9,0x46,0x88,0xD7,0x53,0x24);


MIDL_DEFINE_GUID(IID, IID_IAcadLoftedSurface,0x4B87B28C,0xF248,0x4B4D,0xBE,0x12,0xA3,0x52,0x51,0xE3,0x32,0x1C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLoftedSurface,0x73714CBA,0x4CB6,0x4EC8,0xB6,0xEB,0x45,0x03,0x2A,0xD1,0xFF,0x0F);


MIDL_DEFINE_GUID(IID, IID_IAcadSection,0xAB7DBB7A,0x6E20,0x4577,0xB0,0x0D,0x36,0x45,0x4D,0xB3,0xBF,0xD6);


MIDL_DEFINE_GUID(IID, IID_IAcadSection2,0x3D8156FF,0x9498,0x4E25,0x9F,0x72,0x14,0x81,0x6F,0x83,0x1E,0xF9);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSection,0x90E47ECE,0x9277,0x4524,0x96,0xFC,0x8D,0xCD,0xBC,0xB5,0xED,0xEB);


MIDL_DEFINE_GUID(IID, IID_IAcadSectionManager,0xB96E0629,0x5268,0x4D38,0x99,0x9E,0x04,0x43,0xAB,0x22,0x3A,0xEB);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSectionManager,0x0E200E45,0x5A20,0x450A,0xB8,0x7A,0xE0,0xE9,0xE0,0xCB,0x4E,0xF2);


MIDL_DEFINE_GUID(IID, IID_IAcadUnderlay,0xDE565E84,0xB508,0x4310,0xA6,0x2C,0xBE,0x44,0x1B,0xD3,0x0E,0xE6);


MIDL_DEFINE_GUID(IID, IID_IAcadDwfUnderlay,0x55317527,0x0757,0x4CFE,0x9F,0xF3,0xE1,0x5D,0x3F,0x0B,0xC1,0x4C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDwfUnderlay,0x9C5DE14C,0xC805,0x4582,0xBE,0x0F,0x20,0x94,0x1D,0xCB,0x91,0x9E);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDgnUnderlay,0xD14ABE17,0x087D,0x4565,0xA2,0x34,0x5F,0x25,0xA5,0xDD,0xC1,0x00);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPdfUnderlay,0x20AEBC62,0xE2C7,0x4CE3,0x86,0x30,0x33,0xDA,0xDE,0x23,0x14,0xB1);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubEntity,0x1C8F5F76,0xA4DF,0x4F74,0x80,0x9E,0xB4,0x8E,0xD0,0x8D,0x4D,0x0A);


MIDL_DEFINE_GUID(IID, IID_IAcadSubEntSolidFace,0xDA286C17,0x9689,0x4CE3,0xB1,0xD8,0xB2,0x19,0x83,0xC8,0x01,0x40);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubEntSolidFace,0x4ED71541,0xC46C,0x4A7E,0x8C,0xE3,0xF9,0xBE,0x5F,0xD6,0xD7,0x19);


MIDL_DEFINE_GUID(IID, IID_IAcadSubEntSolidEdge,0x4955E58C,0x98D2,0x44AE,0x9D,0x6E,0xBA,0x49,0xBB,0xC8,0xF2,0x35);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubEntSolidEdge,0xA8B9AC22,0x8299,0x4E0E,0x9C,0x0F,0xDB,0xA5,0x7C,0x83,0x47,0x75);


MIDL_DEFINE_GUID(IID, IID_IAcadSubEntSolidVertex,0x82446452,0xB967,0x4890,0x9D,0xF0,0x05,0x7B,0x4F,0x1C,0x7B,0xD9);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubEntSolidVertex,0xF494B42C,0x0D99,0x4CAD,0x82,0x9B,0xBF,0x56,0x1F,0xDF,0x7A,0xB2);


MIDL_DEFINE_GUID(IID, IID_IAcadSubEntSolidNode,0x2781B666,0x1819,0x452D,0x93,0x80,0x32,0x52,0xA9,0x27,0xB7,0x02);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubEntSolidNode,0xAA04A465,0x8507,0x4023,0x99,0x44,0x55,0xE3,0x1D,0x24,0x33,0xDA);


MIDL_DEFINE_GUID(IID, IID_IAcadWipeout,0x47BF9952,0x6986,0x401C,0xB1,0x5C,0x65,0x1A,0x25,0x0F,0xE1,0x06);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadWipeout,0x44E1E732,0x8052,0x4880,0x9A,0x59,0xF7,0xEE,0xED,0x24,0x6D,0x12);


MIDL_DEFINE_GUID(IID, IID_IAcadSubDMesh,0x7DC85C47,0xC61F,0x49A1,0xB5,0xE9,0x0F,0xA2,0x82,0x4C,0xC7,0x90);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubDMesh,0xF4EAB5FF,0x5C4A,0x43BC,0xBA,0x19,0x9C,0x95,0xC5,0x19,0xD8,0xAC);


MIDL_DEFINE_GUID(IID, IID_IAcadSubDMeshFace,0xDE454A9E,0x0AEC,0x4502,0xA0,0x75,0xBF,0xF6,0xEE,0xDE,0xAD,0x18);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubDMeshFace,0xE91DFDA0,0x8267,0x4145,0x82,0x04,0x57,0xEA,0x28,0x74,0x54,0x30);


MIDL_DEFINE_GUID(IID, IID_IAcadSubDMeshEdge,0x2C4B087E,0x5C25,0x4AC8,0x89,0x3F,0x58,0xC8,0x30,0x1D,0xF0,0x7A);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubDMeshEdge,0x4FB06098,0xDB4B,0x49EF,0x9A,0x6E,0x3A,0x58,0xD3,0x8E,0x84,0x19);


MIDL_DEFINE_GUID(IID, IID_IAcadSubDMeshVertex,0x8E0A3D42,0x2F09,0x47EE,0x90,0x40,0x0C,0x6A,0x82,0x22,0xAA,0xEC);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubDMeshVertex,0x1CF6419C,0xEB08,0x446A,0xB2,0x1A,0x86,0x48,0xA9,0xB4,0x45,0x65);


MIDL_DEFINE_GUID(IID, IID_IAcadNurbSurface,0x3CB19743,0xD5E0,0x4D2B,0xBB,0x43,0xAC,0x8B,0x68,0x40,0x1D,0x00);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadNurbSurface,0x4882BEB7,0x3E9F,0x4ED2,0x8E,0x69,0x64,0xE9,0x55,0xDA,0xFF,0x26);


MIDL_DEFINE_GUID(IID, IID_IAcadGeoPositionMarker,0x354DE2DF,0xC7F8,0x46F1,0xB9,0x11,0x9D,0x8D,0x6B,0x7F,0xA9,0x00);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadGeoPositionMarker,0x7093F7CB,0x516B,0x4D7A,0x99,0xD7,0x77,0xD7,0xA5,0x78,0x2C,0x4E);


MIDL_DEFINE_GUID(IID, IID_IAcadGeomapImage,0x0792A9E8,0xF0E2,0x4A68,0xA4,0xC0,0xF1,0x97,0xDB,0x99,0xBC,0x60);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadGeomapImage,0x9C0E5023,0x7125,0x4669,0xBE,0x1A,0x4A,0xED,0x4C,0xC5,0x64,0x15);


MIDL_DEFINE_GUID(IID, IID_IAcadDimension,0x44378BFB,0x7870,0x495B,0x94,0xFF,0x58,0x2F,0x5F,0x1E,0x24,0x0B);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimension,0x69397113,0x68A3,0x4B89,0xBD,0xEE,0x52,0xEE,0x68,0x19,0x61,0x9F);


MIDL_DEFINE_GUID(IID, IID_IAcadDimAligned,0x672043DE,0xC8D0,0x4554,0xA6,0x8C,0x4D,0x63,0xF6,0xD8,0xB0,0x71);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimAligned,0x6B6E4A11,0x1124,0x479D,0xA7,0xF6,0xE2,0x62,0xE9,0x92,0x05,0x09);


MIDL_DEFINE_GUID(IID, IID_IAcadDimAngular,0xD28D161F,0x1E0E,0x4C03,0x90,0xE7,0x7C,0x95,0xCE,0xF8,0x39,0xE0);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimAngular,0x82B477F1,0xE82B,0x4359,0xA2,0x2A,0x4A,0x7A,0x61,0xBE,0x9B,0x13);


MIDL_DEFINE_GUID(IID, IID_IAcadDimDiametric,0xDF90AE5E,0x1DEA,0x475E,0xA3,0x65,0xEF,0xAB,0x7D,0xC7,0xFC,0xEC);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimDiametric,0x3DDD61F5,0xBC51,0x4D70,0x89,0x67,0x45,0xD3,0x0E,0x36,0x1D,0xCB);


MIDL_DEFINE_GUID(IID, IID_IAcadDimOrdinate,0x32C8AC26,0x2376,0x4E3E,0xB4,0x4C,0xBE,0x2A,0x53,0x01,0x37,0x1F);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimOrdinate,0x394031EA,0x6D74,0x45F5,0xAB,0xF1,0x81,0x90,0x5B,0x6D,0x94,0xA8);


MIDL_DEFINE_GUID(IID, IID_IAcadDimRadial,0xDA87BB1A,0xA91B,0x46D8,0x92,0xD5,0xE3,0x55,0x92,0x7E,0xC3,0xF9);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimRadial,0x40118472,0xDA0A,0x4927,0x90,0x3A,0xF4,0xBC,0xBA,0xD4,0x54,0xA0);


MIDL_DEFINE_GUID(IID, IID_IAcadDimRotated,0xC53F4809,0x5E22,0x4FFC,0x81,0x48,0x06,0xFB,0xA7,0x33,0x9B,0x6E);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimRotated,0x3DC84993,0xE894,0x4272,0xB3,0x77,0x52,0xA0,0x1E,0xEB,0x7F,0xC5);


MIDL_DEFINE_GUID(IID, IID_IAcadDim3PointAngular,0x7560FB7B,0x9292,0x42EA,0xBF,0x88,0x73,0xC1,0xAD,0xD1,0x86,0x9C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDim3PointAngular,0xD8374A04,0x9DD9,0x4912,0x84,0x3D,0xD5,0xC2,0xE2,0x3B,0xC4,0x77);


MIDL_DEFINE_GUID(IID, IID_IAcadDimArcLength,0x0BD36716,0xD2FB,0x4824,0xAF,0x50,0x91,0x70,0x4E,0xAB,0x28,0x7B);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimArcLength,0x89939DBF,0x8C75,0x4CDF,0xB0,0x0D,0x3F,0xFC,0x27,0xDC,0x79,0x11);


MIDL_DEFINE_GUID(IID, IID_IAcadDimRadialLarge,0xE063E055,0x5E23,0x4A83,0xA8,0x2E,0xAF,0xE9,0x82,0x5A,0x79,0xBD);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimRadialLarge,0x254A0B97,0x1A90,0x4C56,0xB0,0x95,0xCC,0x9B,0x7C,0x24,0xB8,0xB8);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadBlock,0x95CC3A4D,0x8E7B,0x4F13,0xA8,0x99,0xFA,0x1F,0xB2,0xF6,0xA0,0xE1);


MIDL_DEFINE_GUID(IID, IID_IAcadModelSpace,0x1161AB96,0x3D6A,0x4CBC,0x84,0x53,0x6E,0xA9,0xEF,0xC2,0xDC,0x09);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadModelSpace,0xFE616360,0x1748,0x440F,0xB1,0x43,0x98,0xD7,0xE2,0xE9,0x28,0xF6);


MIDL_DEFINE_GUID(IID, IID_IAcadPaperSpace,0xE8BFC720,0x213A,0x4C72,0x95,0xA8,0x94,0x4A,0x92,0x54,0x70,0xD1);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPaperSpace,0x08D5B2B1,0xBBC3,0x45BE,0x80,0xED,0x52,0x8B,0x9B,0x98,0x23,0x8F);


MIDL_DEFINE_GUID(IID, IID_IAcadPointCloud,0x1AFCB42D,0xACEC,0x41EF,0x95,0x89,0xA2,0x90,0x28,0xAD,0x14,0x4A);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPointCloud,0x1B166B76,0x11E2,0x421E,0x9C,0xB7,0x9F,0x8F,0x10,0x52,0xDA,0x80);


MIDL_DEFINE_GUID(IID, IID_IAcadPointCloudEx,0xC6B0FD8C,0x9AB7,0x48DD,0xA4,0xD9,0xB3,0xC9,0x38,0x74,0x20,0x88);


MIDL_DEFINE_GUID(IID, IID_IAcadPointCloudEx2,0x96E43D6D,0x48E0,0x47FF,0x8E,0x09,0x3F,0xD8,0x32,0x3A,0x9F,0xB5);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPointCloudEx,0xF751B1AC,0x976C,0x4F40,0x96,0x40,0x5B,0xDD,0xA7,0xF3,0x05,0x8C);


MIDL_DEFINE_GUID(IID, IID_IAcadFileDependency,0x4E2075F0,0x8109,0x485B,0x97,0xA5,0x21,0x9F,0x88,0xC5,0x70,0xBD);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadFileDependency,0xEE2AB753,0x9CD9,0x489D,0xAC,0xFF,0xBC,0xC6,0x29,0x3A,0x0E,0xDD);


MIDL_DEFINE_GUID(IID, IID_IAcadFileDependencies,0x2C6A147C,0xE33C,0x45B7,0x8B,0xD1,0x24,0x79,0xFF,0x40,0xBA,0x91);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadFileDependencies,0x994B535A,0x3851,0x449F,0x86,0xE4,0x2F,0x7A,0x64,0xDB,0xEE,0xFF);


MIDL_DEFINE_GUID(IID, IID_IAcadSummaryInfo,0xCAFC2EAC,0xDB39,0x4DC5,0xBD,0x80,0xE8,0x85,0xE4,0xF3,0x1D,0xA9);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSummaryInfo,0xFDD1E36E,0xBA8A,0x4BB5,0xBC,0x8A,0x0F,0xA6,0xB0,0x4B,0x82,0xAF);


MIDL_DEFINE_GUID(IID, IID_IAcadDatabasePreferences,0x81412468,0xA8E3,0x4C1D,0x9F,0x64,0x53,0xFF,0xCB,0x6C,0xF3,0xBF);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDatabasePreferences,0x21484BD2,0xEDEE,0x4131,0x92,0xBE,0xEB,0x49,0x7B,0x28,0x6B,0x06);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDatabase,0x3FC88B89,0x3C97,0x492F,0x83,0xF8,0xA5,0x3B,0x5F,0x63,0xCE,0xEE);


MIDL_DEFINE_GUID(IID, IID_IAcadSecurityParams,0xFBCA8396,0x2861,0x4B0F,0x85,0x47,0x81,0x48,0x69,0x88,0x83,0x99);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSecurityParams,0x26DA3C63,0xBEB3,0x4B9B,0x8B,0xB5,0x00,0x8C,0x7D,0x96,0x16,0x31);


MIDL_DEFINE_GUID(IID, IID_IAcadLayerStateManager,0x3F781433,0x9326,0x4765,0xA4,0x6B,0x19,0x02,0x7E,0x07,0x96,0x1C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLayerStateManager,0x3D17F248,0x35E7,0x4DFD,0x9C,0x65,0x90,0xEE,0x72,0x59,0x38,0xE7);


MIDL_DEFINE_GUID(IID, DIID__DAcadApplicationEvents,0xF77EC6C7,0x34C1,0x477D,0xBD,0x9B,0xB4,0xA7,0x25,0x4F,0x85,0x1C);


MIDL_DEFINE_GUID(IID, IID_IAcadDocument,0x27956032,0x8A1B,0x4BB1,0x85,0x7A,0xC9,0xEA,0x2E,0x64,0x3F,0xBC);


MIDL_DEFINE_GUID(IID, IID_IAcadDocuments,0xCA08F9EF,0xEC9F,0x4A3B,0x89,0x42,0x52,0x34,0x1A,0x99,0x2E,0xEC);


MIDL_DEFINE_GUID(IID, IID_IAcadPreferences,0x26F462EE,0x7F92,0x4BC1,0x9A,0x96,0x04,0xB8,0xBB,0x55,0x14,0x0F);


MIDL_DEFINE_GUID(IID, IID_IAcadMenuGroups,0x410EBAA3,0x9457,0x416B,0xB6,0x14,0xEF,0x71,0xF3,0xA0,0x00,0xC0);


MIDL_DEFINE_GUID(IID, IID_IAcadMenuBar,0x0B4AAD1A,0x9818,0x4F58,0xAB,0x85,0x8C,0xE2,0x17,0x83,0x9E,0x41);


MIDL_DEFINE_GUID(IID, IID_IAcadApplication,0x0008ACBA,0x2CDA,0x445A,0xAB,0x43,0x41,0x78,0x6C,0xCC,0x10,0xD8);


MIDL_DEFINE_GUID(IID, IID_IAcadState,0xEEF7EB4A,0x3AA3,0x4F7A,0x81,0x4A,0x31,0xC0,0x1F,0x35,0x09,0x3B);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadState,0x5BFE14C9,0x296D,0x4D89,0xB2,0x88,0x73,0xBF,0x4A,0x38,0xF6,0x2D);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadApplication,0x0D327DA6,0xB4DF,0x4842,0xB8,0x33,0x2C,0xFF,0x84,0xF0,0x94,0x8F);


MIDL_DEFINE_GUID(IID, IID_IAcadSelectionSet,0x2004F89D,0x403A,0x4AEF,0x89,0x8C,0xE7,0xFE,0xBB,0xAF,0x33,0x13);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSelectionSet,0x270E24A7,0x8932,0x4B28,0xAD,0x38,0x86,0x55,0x68,0x02,0x76,0xF9);


MIDL_DEFINE_GUID(IID, IID_IAcadSelectionSets,0x9BE70954,0xE799,0x4E6C,0xB6,0x9D,0xCB,0xBE,0x82,0x2D,0xED,0x74);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSelectionSets,0x1128E12D,0xDE62,0x482C,0x87,0xDB,0xB0,0xBA,0xBC,0x33,0x9B,0x26);


MIDL_DEFINE_GUID(IID, IID_IAcadPlot,0xF794D02F,0x8E1D,0x429F,0x93,0x14,0x3C,0x0C,0x33,0xEC,0x62,0xDE);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPlot,0x05FEBF18,0x8AFD,0x428A,0x82,0x6F,0xC4,0xE8,0x22,0x40,0x02,0x25);


MIDL_DEFINE_GUID(IID, IID_IAcadPreferencesFiles,0x70FEE117,0xDA4E,0x41CD,0x87,0x6C,0x18,0x61,0x3F,0x33,0xD5,0x05);


MIDL_DEFINE_GUID(IID, IID_IAcadPreferencesDisplay,0x98A8E72E,0x3CD9,0x49A8,0x83,0x24,0x43,0xC0,0x2B,0xAF,0x8C,0x21);


MIDL_DEFINE_GUID(IID, IID_IAcadPreferencesOpenSave,0x68DC6386,0x1B4D,0x4CCC,0x80,0xC7,0xCA,0xF5,0xF1,0x4A,0xBA,0x53);


MIDL_DEFINE_GUID(IID, IID_IAcadPreferencesUser,0x2F1FE189,0x52BB,0x4E4A,0x8A,0x7C,0x67,0x0D,0xDC,0x42,0x82,0xFE);


MIDL_DEFINE_GUID(IID, IID_IAcadPreferencesProfiles,0xC1596A9D,0xFDE1,0x472D,0xA9,0x2C,0x9D,0xB9,0xCD,0xF4,0xF2,0x5E);


MIDL_DEFINE_GUID(IID, IID_IAcadPreferencesDrafting,0xBDB843F6,0xD6C6,0x490C,0xBE,0x2A,0x1D,0x55,0x45,0x2F,0x85,0x25);


MIDL_DEFINE_GUID(IID, IID_IAcadPreferencesOutput,0x91093392,0x5541,0x47BC,0xAB,0xA6,0x8C,0xC2,0x6C,0xE1,0x31,0x8E);


MIDL_DEFINE_GUID(IID, IID_IAcadPreferencesSelection,0xA2C16287,0xC9FA,0x4FF0,0x98,0xD1,0xD0,0xD9,0xBE,0x53,0x97,0x3D);


MIDL_DEFINE_GUID(IID, IID_IAcadPreferencesSystem,0x813E1752,0x5BD2,0x4319,0xB0,0x90,0xD2,0xAE,0x92,0xBC,0x0C,0x2D);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPreferences,0xF99055F3,0x20C1,0x4F2A,0x9F,0xB9,0xB4,0xF0,0xA0,0xC2,0x8C,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPreferencesDrafting,0x6997257A,0x0A52,0x4801,0xB7,0xAD,0x13,0x3E,0xB4,0x4E,0xEE,0xAB);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPreferencesDisplay,0x47C4B163,0xBB1F,0x4060,0xA9,0xE4,0x52,0xC6,0x9E,0x5F,0x49,0x6E);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPreferencesFiles,0x43B84872,0x9D9C,0x48C9,0xAF,0x02,0x65,0x53,0x46,0x6E,0x50,0x36);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPreferencesOpenSave,0x7BC98F0B,0x76D8,0x480D,0x84,0xE8,0x85,0x8E,0x2B,0xDC,0xCB,0x28);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPreferencesOutput,0xCDBB29DE,0x7DD3,0x4008,0xAE,0x0C,0xA1,0x07,0x8E,0xCA,0xA6,0x8C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPreferencesProfiles,0x454F2B83,0x82C4,0x49C5,0xA6,0x33,0xB9,0x67,0x35,0xBC,0x97,0xB4);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPreferencesSelection,0x36466982,0x3BDE,0x4243,0x96,0x1F,0xCA,0xCC,0x33,0x2E,0x5F,0x95);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPreferencesSystem,0x02DF4D76,0xDB78,0x4BF5,0xA0,0xC9,0xFA,0x19,0x18,0x56,0x6E,0x50);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPreferencesUser,0x4C7D8B0E,0x2B24,0x41C8,0x8A,0xDF,0x6D,0x78,0xB5,0xBD,0xDA,0x35);


MIDL_DEFINE_GUID(IID, IID_IAcadMenuGroup,0x6D9A79DD,0xAB1F,0x4DA6,0xA0,0x3F,0x06,0x52,0x10,0x39,0x8F,0xC5);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMenuGroups,0x0FD5DD80,0x6C6B,0x4693,0xA5,0xFA,0x3E,0x8B,0x8F,0x1F,0xD2,0x62);


MIDL_DEFINE_GUID(IID, IID_IAcadPopupMenus,0x83AE8DC2,0x7B94,0x47A2,0x93,0x66,0x44,0x4C,0xE9,0x32,0x7D,0xA8);


MIDL_DEFINE_GUID(IID, IID_IAcadToolbars,0xEFA9D7A5,0x920F,0x4139,0x87,0x6A,0x45,0x5E,0x29,0x4E,0xF4,0x21);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMenuGroup,0x91990DF3,0xEBF5,0x4A19,0xA6,0x19,0x38,0x63,0x29,0x0D,0x9E,0x33);


MIDL_DEFINE_GUID(IID, IID_IAcadPopupMenu,0x12E2FC02,0x22BE,0x4CFD,0x85,0x45,0xC7,0x93,0x1C,0xB0,0xBF,0x81);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMenuBar,0x686343D8,0xEC00,0x4AB7,0xAA,0x2E,0x38,0xCC,0x2C,0x18,0xDF,0xB0);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPopupMenus,0x84347500,0x3B71,0x4BEA,0xA0,0x00,0xDA,0x0B,0x37,0x3C,0x75,0xBE);


MIDL_DEFINE_GUID(IID, IID_IAcadPopupMenuItem,0x0B08A9A1,0xB1C5,0x4F81,0xB2,0x26,0xE3,0xA6,0x68,0x0B,0x80,0xEF);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPopupMenu,0x089CB5FD,0x692E,0x48E4,0xBA,0xF4,0x71,0xCF,0x75,0xCB,0x4F,0x58);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPopupMenuItem,0x5B6122A4,0xE83A,0x4E39,0x8E,0x0B,0x74,0x3C,0xF6,0x92,0x92,0xF4);


MIDL_DEFINE_GUID(IID, IID_IAcadUtility,0xDF80A867,0xFF5A,0x46F7,0x9B,0x2F,0xD9,0x3C,0x49,0x74,0xB1,0x22);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadUtility,0x5222EDD7,0x4C51,0x4417,0xA3,0x40,0xAC,0xED,0xAB,0x69,0xEA,0x77);


MIDL_DEFINE_GUID(IID, DIID__DAcadDocumentEvents,0x6DD95E15,0x2448,0x48B0,0x87,0x1F,0xA4,0xAF,0xDC,0xEF,0x43,0x9C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDocument,0x720DB9AF,0xD62C,0x4ED0,0xA3,0x77,0x42,0x9C,0x22,0x31,0x28,0x52);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDocuments,0x46F2D47E,0xB78B,0x490C,0xAF,0x25,0xB8,0xDC,0x8D,0x70,0x81,0xDB);


MIDL_DEFINE_GUID(IID, IID_IAcadToolbar,0xA6D59EE7,0x3BA3,0x404A,0xB1,0x2D,0x13,0x3F,0xC7,0x83,0x40,0xAF);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadToolbars,0xAA169F21,0x8C69,0x4393,0xB9,0xBD,0xD4,0x47,0xB7,0x96,0xD8,0x8D);


MIDL_DEFINE_GUID(IID, IID_IAcadToolbarItem,0x0332F464,0x8C34,0x4CA4,0x93,0xC3,0x5F,0xED,0xFD,0x29,0xE3,0xF9);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadToolbar,0xC642D5E6,0x3F92,0x410A,0xA2,0x4E,0xD4,0xA6,0x19,0xA3,0x29,0xF9);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadToolbarItem,0x3B4318A1,0x112D,0x4849,0x91,0x96,0x5F,0x3A,0x6F,0x98,0xEF,0x54);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



