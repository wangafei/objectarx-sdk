
#ifndef __RXATTRIB_H_
#define __RXATTRIB_H_

#pragma once
#include "acbasedefs.h"
#include "adesk.h"
#include "acadstrc.h"
#include "pimplapi.h"
#include "rxvalue.h"
#include "dbid.h"

#include "../../inc/zrxattrib.h"

#ifndef AcRxAttributeImp
#define AcRxAttributeImp	ZcRxAttributeImp
#endif  //ifndef AcRxAttributeImp

#ifndef AcRxAttributeCollectionImp
#define AcRxAttributeCollectionImp	ZcRxAttributeCollectionImp
#endif  //ifndef AcRxAttributeCollectionImp

#ifndef AcRxMember
#define AcRxMember	ZcRxMember
#endif  //ifndef AcRxMember

#ifndef AcRxPropertyBase
#define AcRxPropertyBase	ZcRxPropertyBase
#endif  //ifndef AcRxPropertyBase

#ifndef ADESK_NO_VTABLE
#define ADESK_NO_VTABLE		ZSOFT_NO_VTABLE
#endif  //ifndef ADESK_NO_VTABLE

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif  //ifndef AcRxObject

#ifndef AcRxAttribute
#define AcRxAttribute		ZcRxAttribute
#endif  //ifndef AcRxAttribute

#ifndef ACRX_DECLARE_MEMBERS_EXPIMP
#define ACRX_DECLARE_MEMBERS_EXPIMP		ZCRX_DECLARE_MEMBERS_EXPIMP
#endif  //ifndef ACRX_DECLARE_MEMBERS_EXPIMP

#ifndef ACBASE_PORT
#define ACBASE_PORT		ZCBASE_PORT
#endif  //ifndef ACBASE_PORT

#ifndef AcRxAttributeCollectionImp
#define AcRxAttributeCollectionImp		ZcRxAttributeCollectionImp
#endif  //ifndef AcRxAttributeCollectionImp

#ifndef AcRxAttributeCollection
#define AcRxAttributeCollection		ZcRxAttributeCollection
#endif  //ifndef AcRxAttributeCollection

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif  //ifndef AcRxObject

#ifndef AcRxClass
#define AcRxClass		ZcRxClass
#endif  //ifndef AcRxClass

#ifndef Acad
#define Acad		Zcad
#endif  //ifndef Acad

#ifndef AcRxResourceLoader
#define AcRxResourceLoader		ZcRxResourceLoader
#endif  //ifndef AcRxResourceLoader

#ifndef AcString
#define AcString	ZcString
#endif  //ifndef AcString

#ifndef AcRxLocalizedNameAttribute
#define AcRxLocalizedNameAttribute		ZcRxLocalizedNameAttribute
#endif  //ifndef AcRxLocalizedNameAttribute

#ifndef AcRxAlternateLocalizedNameAttribute
#define AcRxAlternateLocalizedNameAttribute		ZcRxAlternateLocalizedNameAttribute
#endif  //ifndef AcRxAlternateLocalizedNameAttribute

#ifndef AcRxUiPlacementAttribute
#define AcRxUiPlacementAttribute		ZcRxUiPlacementAttribute
#endif  //ifndef AcRxUiPlacementAttribute

#ifndef ACHAR
#define ACHAR	ZTCHAR
#endif  //ifndef ACHAR

#ifndef AcRxLMVAttribute
#define AcRxLMVAttribute		ZcRxLMVAttribute
#endif  //ifndef AcRxLMVAttribute

#ifndef AcRxDescriptionAttribute
#define AcRxDescriptionAttribute		ZcRxDescriptionAttribute
#endif  //ifndef AcRxDescriptionAttribute

#ifndef AcRxRefersToAttribute
#define AcRxRefersToAttribute		ZcRxRefersToAttribute
#endif  //ifndef AcRxRefersToAttribute

#ifndef AcRxDisplayAsAttribute
#define AcRxDisplayAsAttribute		ZcRxDisplayAsAttribute
#endif  //ifndef AcRxDisplayAsAttribute

#ifndef AcDbObjectId
#define AcDbObjectId	ZcDbObjectId
#endif  //ifndef AcDbObjectId

#ifndef AcRxCOMAttribute
#define AcRxCOMAttribute	ZcRxCOMAttribute
#endif  //ifndef AcRxCOMAttribute

#ifndef AcRxFilePathAttribute
#define AcRxFilePathAttribute	ZcRxFilePathAttribute
#endif  //ifndef AcRxFilePathAttribute

#ifndef AcRxFlagsAttribute
#define AcRxFlagsAttribute	ZcRxFlagsAttribute
#endif  //ifndef AcRxFlagsAttribute

#ifndef AcRxUnitTypeAttribute
#define AcRxUnitTypeAttribute	ZcRxUnitTypeAttribute
#endif  //ifndef AcRxUnitTypeAttribute

#ifndef AcRxGenerateDynamicPropertiesAttribute
#define AcRxGenerateDynamicPropertiesAttribute	ZcRxGenerateDynamicPropertiesAttribute
#endif  //ifndef AcRxGenerateDynamicPropertiesAttribute

#ifndef AcRxUseDialogForReferredCollectionAttribute
#define AcRxUseDialogForReferredCollectionAttribute	ZcRxUseDialogForReferredCollectionAttribute
#endif  //ifndef AcRxUseDialogForReferredCollectionAttribute

#ifndef AcRxUiCascadingContextMenuAttribute
#define AcRxUiCascadingContextMenuAttribute	ZcRxUiCascadingContextMenuAttribute
#endif  //ifndef AcRxUiCascadingContextMenuAttribute

#ifndef AcRxCumulativeAttribute
#define AcRxCumulativeAttribute	ZcRxCumulativeAttribute
#endif  //ifndef AcRxCumulativeAttribute

#ifndef AcRxAffinityAttribute
#define AcRxAffinityAttribute	ZcRxAffinityAttribute
#endif  //ifndef AcRxAffinityAttribute

#ifndef AcRxTypePromotionAttribute
#define AcRxTypePromotionAttribute	ZcRxTypePromotionAttribute
#endif  //ifndef AcRxTypePromotionAttribute

#ifndef AcRxDefaultValueAttribute
#define AcRxDefaultValueAttribute	ZcRxDefaultValueAttribute
#endif  //ifndef AcRxDefaultValueAttribute

#ifndef AcRxValue
#define AcRxValue	ZcRxValue
#endif  //ifndef AcRxValue

#ifndef ACDB_PORT
#define ACDB_PORT	ZCDB_PORT
#endif  //ifndef ACDB_PORT

#endif  //__RXATTRIB_H_
