/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2002-2015, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) Copyright (C) 2002-2015 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////

#ifndef __FMBUILDSETTINGS_H__
#define __FMBUILDSETTINGS_H__

#include "../OdaCommon.h"

  #if defined(ODA_WINDOWS)
    #pragma warning( disable: 4275 4251 )
  #endif

//#ifdef ADT_STATIC_BUILD

//    #define FMGEOMETRY_API
//    #define FMGEOMETRY_API_STATIC

//#elif defined(ADT_DYNAMIC_BUILD)

    #ifdef FACETMODELER_EXPORTS
        #define FMGEOMETRY_API        OD_DLL_EXPORT
        #define FMGEOMETRY_API_STATIC
    #else
        #define FMGEOMETRY_API        OD_DLL_IMPORT
        #define FMGEOMETRY_API_STATIC 
    #endif 

//#else

//    #error "You must choose STATIC or DYNAMIC build setting! Use ADT_STATIC_BUILD or ADT_DYNAMIC_BUILD defines."

//#endif

#endif  //__FMBUILDSETTINGS_H__
