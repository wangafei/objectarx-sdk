///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2003-2011, Open Design Alliance (the "Alliance").
// All rights reserved.
//
// This software and its documentation and related materials are owned by
// the Alliance. The software may only be incorporated into application
// programs owned by members of the Alliance, subject to a signed
// Membership Agreement and Supplemental Software License Agreement with the
// Alliance. The structure and organization of this software are the valuable
// trade secrets of the Alliance and its suppliers. The software is also
// protected by copyright law and international treaty provisions. Application
// programs incorporating this software must include the following statement
// with their copyright notices:
//
//   This application incorporates Teigha(R) software pursuant to a license
//   agreement with Open Design Alliance.
//   Teigha(R) for .dwg files Copyright (C) 2003-2011 by Open Design Alliance.
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you
// acknowledge and accept the above terms.
//
//
// *DWG is the native and proprietary file format for AutoCAD(R) and a trademark
// of Autodesk, Inc.  Open Design Alliance is not associated with Autodesk.
///////////////////////////////////////////////////////////////////////////////



#ifndef TD_VERSION_DEFINED
#define TD_VERSION_DEFINED

#define TD_COMPANY_NAME_S   "Open Design Alliance"
#define TD_COMPANY_NAME_W  L"Open Design Alliance"

// The string below need to be defined in quotes else compiler complains in illegal characters
#define TD_COPYRIGHT_START_S          "Copyright\xA9 "
#define TD_COPYRIGHT_START_YEAR_S     "2003"
#define TD_COPYRIGHT_END_S            "-2011, Open Design Alliance"
#define TD_COPYRIGHT_START_W         L"Copyright \x00A9 "
#define TD_COPYRIGHT_START_YEAR_W    L"2003"
#define TD_COPYRIGHT_END_W           L"-2011, Open Design Alliance"
#define TDNET_COPYRIGHT_START_YEAR_W L"2009"

#define TD_COPYRIGHT_S       TD_COPYRIGHT_START_S TD_COPYRIGHT_START_YEAR_S TD_COPYRIGHT_END_S
#define TD_COPYRIGHT_W       TD_COPYRIGHT_START_W TD_COPYRIGHT_START_YEAR_W TD_COPYRIGHT_END_W

#define TD_PRODUCT_NAME_START_S        "Teigha\xAE"
#define TD_PRODUCT_NAME_ADDITION_S     ""
#define TDX_PRODUCT_NAME_ADDITION_S    "X"
#define TD_PRODUCT_NAME_END_S          " for .dwg files"
#define TD_PRODUCT_NAME_START_W       L"Teigha\x00AE"
#define TD_PRODUCT_NAME_ADDITION_W    L""
#define TDX_PRODUCT_NAME_ADDITION_W   L"X"
#define TDNET_PRODUCT_NAME_ADDITION_W L".NET"
#define TD_PRODUCT_NAME_END_W         L" for .dwg files"

#define TD_PRODUCT_NAME_S TD_PRODUCT_NAME_START_S TD_PRODUCT_NAME_END_S
#define TD_PRODUCT_NAME_W TD_PRODUCT_NAME_START_W TD_PRODUCT_NAME_END_W

#define DEFAULT_MODULE_EXTENSION_S         "tx"
#define DEFAULT_MODULE_EXTENSION_DOT_S    ".tx"
#define DEFAULT_MODULE_EXTENSION_W        L"tx"
#define DEFAULT_MODULE_EXTENSION_DOT_W    L".tx"
#define VECTORIZATION_MODULE_EXTENSION_S       "txv"
#define VECTORIZATION_MODULE_EXTENSION_DOT_S  ".txv"
#define VECTORIZATION_MODULE_EXTENSION_W      L"txv"
#define VECTORIZATION_MODULE_EXTENSION_DOT_W  L".txv"


// Full Product version is:
//   TD_MAJOR_VERSION.TD_MINOR_VERSION.TD_MAJOR_BUILD.TD_MINOR_BUILD
// Example: 1.11.00.00 (initial 1.11 release).
// OpenDesign maintenance updates to 1.11 will increase the major build number,
// for example, 1.11.01.00, 1.11.02.00, etc.  Minor build number is reserved for
// client builds.

/* When Incrementing these be sure to make the appropriate changes
 * to the Version string and build comments.
 */
#define TD_MAJOR_VERSION          3
#define TD_MINOR_VERSION         05
#define TD_MAJOR_BUILD            0
#define TD_MINOR_BUILD            0

// Numeric representation of the TD version to be used in preprocessor definitions
// like #if (TD_VERSION > 30500) ...
// (we never use minor build number, and it is not included in version.
// If you are building your custom version of Teigha, you may define an alternative TD_VERSION_
// or TD_VERSION_FULL, to distinguish between minor builds if necessary)
#define TD_VERSION  (TD_MAJOR_BUILD + TD_MINOR_VERSION*100 + TD_MAJOR_VERSION*10000)
#define TD_SHORT_STRING_VER_S   "3.05"
#define TD_SHORT_STRING_VER_W  L"3.05"

#define TD_PRODUCT_VER_STR_S   "3.05.0.0"
#define TD_PRODUCT_VER_STR_W  L"3.05.0.0"

//Changed in VersionInfo to TD_PRODUCT_NAME_S " " TD_PRODUCT_VER_STR_S
//That need for NET and ActiveX
#define TD_BUILD_COMMENTS_S    "Teigha\xAE for .dwg files 3.05.0.0"
#define TD_BUILD_COMMENTS_W   L"Teigha\x00AE for .dwg files 3.05.0.0"


#define TD_TYPELIB_VER(MAJ,MIN) version(##MAJ##.##MIN##)


#if defined(_TOOLKIT_IN_DLL_) && defined(_MSC_VER) // second condition for RC
#define TD_STRINGIZE2( s )      L##s
#define TD_STRINGIZE( s )       TD_STRINGIZE2( s )

#if _MSC_VER == 1200
#define TD_DLL_VERSION_SUFFIX_STR L"_"##TD_STRINGIZE(TD_MAJOR_VERSION.TD_MINOR_VERSION)##L"src_6"
#elif _MSC_VER == 1310
#define TD_DLL_VERSION_SUFFIX_STR L"_"##TD_STRINGIZE(TD_MAJOR_VERSION.TD_MINOR_VERSION)##L"src_7"
#elif _MSC_VER == 1400
#define TD_DLL_VERSION_SUFFIX_STR L"_"##TD_STRINGIZE(TD_MAJOR_VERSION.TD_MINOR_VERSION)##L"src_8"
#elif _MSC_VER == 1500
#define TD_DLL_VERSION_SUFFIX_STR L"_"##TD_STRINGIZE(TD_MAJOR_VERSION.TD_MINOR_VERSION)##L"src_9"
#elif _MSC_VER == 1600
#define TD_DLL_VERSION_SUFFIX_STR L"_"##TD_STRINGIZE(TD_MAJOR_VERSION.TD_MINOR_VERSION)##L"src_10"
#elif _MSC_VER == 1700
#define TD_DLL_VERSION_SUFFIX_STR L"_"##TD_STRINGIZE(TD_SHORT_STRING_VER_S)##L"src_11"
#elif _MSC_VER == 1800
#define TD_DLL_VERSION_SUFFIX_STR L"_"##TD_STRINGIZE(TD_SHORT_STRING_VER_S)##L"src_12"
#elif _MSC_VER == 1900
#define TD_DLL_VERSION_SUFFIX_STR L"_" TD_STRINGIZE(TD_SHORT_STRING_VER_S) L"src_14"
#elif _MSC_VER >= 1910
#define TD_DLL_VERSION_SUFFIX_STR L"_" TD_STRINGIZE(TD_SHORT_STRING_VER_S) L"src_15"

#else
#error "Unsupported compiler for suffixed version"
#endif
#endif


#if defined(_TOOLKIT_IN_DLL_) && defined(__BORLANDC__)
#define TD_STRINGIZE2( s )      L""#s
#define TD_STRINGIZE( s )       TD_STRINGIZE2( s )

#if __BORLANDC__ >= 0x0580 && __BORLANDC__ <= 0x0589
#define TD_DLL_VERSION_SUFFIX_STR L"_"##TD_STRINGIZE(TD_MAJOR_VERSION.TD_MINOR_VERSION)##L"src_b6"
#elif __BORLANDC__ >= 0x0610 && __BORLANDC__ <= 0x0619
#define TD_DLL_VERSION_SUFFIX_STR L"_"##TD_STRINGIZE(TD_MAJOR_VERSION.TD_MINOR_VERSION)##L"src_b9"
#elif __BORLANDC__ >= 0x0620 && __BORLANDC__ <= 0x0629
#define TD_DLL_VERSION_SUFFIX_STR L"_"##TD_STRINGIZE(TD_MAJOR_VERSION.TD_MINOR_VERSION)##L"src_b10"
#else
#error "Unsupported compiler for suffixed version"
#endif
#endif

#endif  // ODA_VERSION_DEFINED

