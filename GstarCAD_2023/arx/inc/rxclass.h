/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "../../inc/rxclass.h"
#include "acbasedefs.h"
#include "rxobject.h"
#include "AdAChar.h"
#include "acbasedefs.h" 

#define AcRxMemberCollectionConstructorPtr GcRxMemberCollectionConstructorPtr
#define AcRxClass GcRxClass
#define newAcRxClass newGcRxClass
#define acrxBuildClassHierarchy gcrxBuildClassHierarchy
#define deleteAcRxClass deleteGcRxClass
#define acrxQueueClassForInitialization gcrxQueueClassForInitialization

#define ACHAR	GCHAR
#define AcRxSet       GcRxSet
#define AcRxMemberCollection GcRxMemberCollection
#define AcRxAttributeCollection     GcRxAttributeCollection
#define ACBASE_PORT GCBASE_PORT