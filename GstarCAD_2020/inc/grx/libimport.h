/*****************************************************************************
***     DDConfig.cpp
***
***     Description: 
***
*****************************************************************************/

#ifndef _DRXLIB_IMPORT__H_
#define _DRXLIB_IMPORT__H_

//#pragma comment( lib, "" )

//#pragma message( "Compiling " __FILE__ ) 
//#pragma message( "Last modified on " __TIMESTAMP__ )

 
/////////////////////////////////////////////////////////////////////////////////////
// Entry Point
#pragma comment( lib, "grxport.lib" )


/////////////////////////////////////////////////////////////////////////////////////
// Memory Allocation "icmem.lib"
//#ifdef _USE_DD_ALLOC_
//#pragma message( "USE TD_Alloc_dll.lib")
//#pragma comment( lib, "TD_Alloc_dll.lib" )
//#endif

/////////////////////////////////////////////////////////////////////////////////////
// ========== Core Components ========== 

// DD_Root - Core DWGdirect functionality. 
#pragma comment( lib, "TD_Root_dll.lib" )

// DD_Ge - Geometry classes (OdGe*). 
#pragma comment( lib, "TD_Ge_dll.lib" )

// DD_Gi - Entity vectorization classes (DD_Gi*). 
#pragma comment( lib, "TD_Gi_dll.lib" )

// DD_Db - Database classes (OdDb*). 
#pragma comment( lib, "TD_Db_dll.lib" )


/////////////////////////////////////////////////////////////////////////////////////
// ========== other Components ========== 

// DD_Gs - Graphical system classes (OdGs*). 
//#pragma comment( lib, "TD_Gs_dll.lib" )


#endif  //_DRXLIB_IMPORT__H_
