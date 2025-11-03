#ifndef __ACPOINTCLOUDITEM_H__
#define __ACPOINTCLOUDITEM_H__

#include "acarray.h"
#include "adsdef.h"
#include "acstring.h"

#include "../../inc/zAcPointCloudItem.h"

#ifndef ACDB_PORT
#define ACDB_PORT		ZCDB_PORT
#endif //#ifndef ACDB_PORT

#ifndef AcArray
#define AcArray	ZcArray
#endif //#ifndef AcArray

#ifndef AcString
#define AcString	ZcString
#endif //#ifndef AcString

#ifndef AcPointCloudItem
#define AcPointCloudItem	ZcPointCloudItem
#endif //#ifndef AcPointCloudItem   

#ifndef AcPointCloudItemArray
#define AcPointCloudItemArray		ZcPointCloudItemArray
#endif //#ifndef AcPointCloudItemArray

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef setAdsName
#define setAdsName		setZdsName
#endif //#ifndef setAdsName

#ifndef adsName
#define adsName		zdsName
#endif //#ifndef adsName

#ifndef AcPointCloudItemType 
#define AcPointCloudItemType 	ZcPointCloudItemType
#endif //#ifndef AcPointCloudItemType    

#ifndef ads_name
#define ads_name		zds_name
#endif //#ifndef ads_name

#ifndef m_adsName
#define m_adsName		m_zdsName
#endif //#ifndef m_adsName

#endif //#ifndef __ACPOINTCLOUDITEM_H__
