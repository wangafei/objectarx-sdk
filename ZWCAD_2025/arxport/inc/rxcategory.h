
#ifndef __RX_CATEGORY_H__
#define __RX_CATEGORY_H__

#include "acbasedefs.h"
#include "adesk.h"
#include "acadstrc.h"
#include "pimplapi.h"

#include "../../inc/zrxcategory.h"

#ifndef  AcRxMember
#define  AcRxMember  ZcRxMember
#endif  //ifndef AcRxMember

#ifndef  AcRxCategory
#define  AcRxCategory  ZcRxCategory
#endif  //ifndef AcRxCategory

#ifndef  ACRX_DECLARE_MEMBERS_EXPIMP
#define  ACRX_DECLARE_MEMBERS_EXPIMP  ZCRX_DECLARE_MEMBERS_EXPIMP
#endif  //ifndef ACRX_DECLARE_MEMBERS_EXPIMP

#ifndef  ACBASE_PORT
#define  ACBASE_PORT  ZCBASE_PORT
#endif  //ifndef ACBASE_PORT

#ifndef  ACHAR
#define  ACHAR  ZTCHAR
#endif  //ifndef ACHAR

#ifndef  Acad
#define  Acad  Zcad
#endif  //ifndef Acad

#ifndef  acdbGetLegacyCategoryId
#define  acdbGetLegacyCategoryId  zcdbGetLegacyCategoryId
#endif  //ifndef acdbGetLegacyCategoryId

#ifndef  acdbSetLegacyCategoryId
#define  acdbSetLegacyCategoryId  zcdbSetLegacyCategoryId
#endif  //ifndef acdbSetLegacyCategoryId

#endif // __RX_CATEGORY_H__
