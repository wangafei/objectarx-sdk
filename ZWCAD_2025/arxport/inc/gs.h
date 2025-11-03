
#ifndef __GS_H__
#define __GS_H__

#include "acarray.h"
#include "AdAChar.h"
#include "gept3dar.h"
#include "dbid.h"
#include "AcString.h"
#include "acgi.h"

#include "../../inc/zgs.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef AcArray
#define AcArray		ZcArray
#endif //#ifndef AcArray

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcGeMatrix3d
#define AcGeMatrix3d		ZcGeMatrix3d
#endif //#ifndef AcGeMatrix3d

#ifndef AcGePoint2d
#define AcGePoint2d		ZcGePoint2d
#endif //#ifndef AcGePoint2d

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcGePoint3dArray
#define AcGePoint3dArray		ZcGePoint3dArray
#endif //#ifndef AcGePoint3dArray

#ifndef AcGeVector3d
#define AcGeVector3d		ZcGeVector3d
#endif //#ifndef AcGeVector3d

#ifndef AcGiContextualColors
#define AcGiContextualColors		ZcGiContextualColors
#endif //#ifndef AcGiContextualColors

#ifndef AcGiContextualAttributes
#define AcGiContextualAttributes		ZcGiContextualAttributes
#endif //#ifndef AcGiContextualAttributes

#ifndef AcGiGraphicsKernel
#define AcGiGraphicsKernel		ZcGiGraphicsKernel
#endif //#ifndef AcGiGraphicsKernel

#ifndef AcGsGraphicsKernel
#define AcGsGraphicsKernel		ZcGsGraphicsKernel
#endif //#ifndef AcGsGraphicsKernel

#ifndef AcGsRenderProgressMonitor
#define AcGsRenderProgressMonitor		ZcGsRenderProgressMonitor
#endif //#ifndef AcGsRenderProgressMonitor

#ifndef AcGiVisualStyle
#define AcGiVisualStyle		ZcGiVisualStyle
#endif //#ifndef AcGiVisualStyle

#ifndef AcGsClientViewInfo
#define AcGsClientViewInfo		ZcGsClientViewInfo
#endif //#ifndef AcGsClientViewInfo

#ifndef AcGsRenderInterrupter
#define AcGsRenderInterrupter		ZcGsRenderInterrupter
#endif //#ifndef AcGsRenderInterrupter

#ifndef AcGsColor
#define AcGsColor		ZcGsColor
#endif //#ifndef AcGsColor

#ifndef AcGsConfig
#define AcGsConfig		ZcGsConfig
#endif //#ifndef AcGsConfig

#ifndef AcGsDCPoint
#define AcGsDCPoint		ZcGsDCPoint
#endif //#ifndef AcGsDCPoint

#ifndef AcGsDCRect
#define AcGsDCRect		ZcGsDCRect
#endif //#ifndef AcGsDCRect

#ifndef AcGsDevice
#define AcGsDevice		ZcGsDevice
#endif //#ifndef AcGsDevice

#ifndef AcGsGetInterfaceFunc
#define AcGsGetInterfaceFunc		ZcGsGetInterfaceFunc
#endif //#ifndef AcGsGetInterfaceFunc

#ifndef AcGsModel
#define AcGsModel		ZcGsModel
#endif //#ifndef AcGsModel

#ifndef AcGsNode
#define AcGsNode		ZcGsNode
#endif //#ifndef AcGsNode

#ifndef AcGsReactor
#define AcGsReactor		ZcGsReactor
#endif //#ifndef AcGsReactor

#ifndef AcGsModelReactor
#define AcGsModelReactor	ZcGsModelReactor
#endif 

#ifndef AcGsConfigReactor
#define AcGsConfigReactor	ZcGsConfigReactor
#endif //#ifndef AcGsConfigReactor

#ifndef AcGsReleaseInterfaceFunc
#define AcGsReleaseInterfaceFunc		ZcGsReleaseInterfaceFunc
#endif //#ifndef AcGsReleaseInterfaceFunc

#ifndef AcGsView
#define AcGsView		ZcGsView
#endif //#ifndef AcGsView

#ifndef AcGsWindowingSystemID
#define AcGsWindowingSystemID		ZcGsWindowingSystemID
#endif //#ifndef AcGsWindowingSystemID

#ifndef AcGsWindowId
#define AcGsWindowId		ZcGsWindowId
#endif //#ifndef AcGsWindowId

#ifndef AcGiDrawable
#define AcGiDrawable		ZcGiDrawable
#endif //#ifndef AcGiDrawable

#ifndef acadWindowId
#define acadWindowId		zcadWindowId
#endif //#ifndef acadWindowId

#ifndef AcUniqueString
#define AcUniqueString		ZcUniqueString
#endif //#ifndef AcUniqueString

#ifndef AcGsDrawableLink
#define AcGsDrawableLink		ZcGsDrawableLink
#endif //#ifndef AcGsDrawableLink

#ifndef AcGsDrawablePath
#define AcGsDrawablePath		ZcGsDrawablePath
#endif //#ifndef AcGsDrawablePath

#ifndef AcGiKernelDescriptor
#define AcGiKernelDescriptor		ZcGiKernelDescriptor
#endif //#ifndef AcGiKernelDescriptor

#ifndef AcGsKernelDescriptor
#define AcGsKernelDescriptor		ZcGsKernelDescriptor
#endif //#ifndef AcGsKernelDescriptor

#ifndef AcGsRenderStatistics
#define AcGsRenderStatistics		ZcGsRenderStatistics
#endif //#ifndef AcGsRenderStatistics

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef AcString
#define AcString		ZcString
#endif //#ifndef AcString

#endif //#ifndef __GS_H__
