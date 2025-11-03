/*****************************************************************************
***     文件名: GcPlot.h
*****************************************************************************/

#ifndef __GCAD__GS_PLOT__INTERFACE__H__
#define __GCAD__GS_PLOT__INTERFACE__H__

#include "../GcGraphicSystemService.h"
#include "GcPlotDataDumpper.h"


class GcGePoint2d;
class GcDbObject;
class GcDbObjectId;
class GcApDocument;

struct GcPlotParameters
{
  /* 打印空间
   0: 当前tilemode指定 Model_Space or Paper_Space
   1: 模型 Model_Space
   2: 图纸 Paper_Space
   3: 任意 Model_Space, Paper_Space, Paper_Space0, Paper_Space1, ...
  */
  int  pltSpace; // 默认值: 0(当前tilemode指定)
  GcDbObjectId blkSpaceId;  // 仅当 pltSpace=3 时有效

  /* 打印区域
   0: "显示"，当前视图的可见范围，视图可见范围外的不打印（可能裁剪）
   1: "布局"或"界限"，针对当前视图，模型空间为"界限"，图纸空间为"布局"
      "布局"，图纸空间下设定的打印图纸大小，图纸外的不打印（可能裁剪）
      "界限"，模型空间下设定的LIMMIN,LIMMAX系统指定，超过该范围的不打印（可能裁剪）
   2: "窗口"，当前视图指定的窗口范围，超过该范围的不打印（可能裁剪）
   3: "范围"，针对当前视图，当前空间里面所有实体的图形范围，无裁剪
   4: "视图"，指定视图的可见范围，需存在相应视图，视图可见范围外的不打印（可能裁剪）
  */
  int  pltArea;  // 默认值: 0("显示")
  GcGePoint2d lower_left, upper_right; // DCS，仅当 pltArea=2 时有效
  GcDbObjectId pltViewId; // 仅当 pltArea=4 时有效

  GcGePoint2d pltRealArea;	//打印区宽度（像素）

  /* 打印中心点
   plotCenter: 返回值，无需设置，供外部计算用，具体值的如下
     pltArea=0: 当前视图的中心点
     pltArea=1: 图形界限的中心点 或者 布局空间下打印图纸的中心点
     pltArea=2: 指定窗口的中心点
     pltArea=3: 图形范围的中心点
     pltArea=4: 当前视图(pltViewId)的中心点
     viewCenter!=NULL: viewCenter
   viewCenter: 不为NULL，表示自定义中心点
  */
  GcGePoint2d plotCenter;
  const GcGePoint2d* pltViewCenter; // 默认值: NULL

  /* 打印绘制模式
   0: 默认，使用打印视图的绘制模式
   1: 标准，线框 (Wireframe)
   2: 消隐, Hidden Lines Removed
   3: 着色, Shaded
   4: 视觉样式, Visual Style
  */
  int  pltViewMode; // 默认值: 0

  /* 打印顺序
   0: 默认，使用当前空间的绘制顺序
   1: 储存，使用实体的储存顺序
   2: 图纸最后, 以绘制顺序进行打印输出，但最后才生成图纸空间内的实体对象
  */
  bool pltOrder;  // 默认值: 0

  /* 打印实体（过滤器作用）
   0: 所有实体
   1: 指定 GcDbObjectId 数组
   2: 指定 GcDbObject 数组
   3: 指定选择集
   x: 将来扩展，比如限定打印某类实体，等等
  */
  int  pltEntities; // 默认值: 0(all entities)
  struct _PlotIds
  {
    OdInt32 num;
    const GcDbObjectId* ids;
  } plotIds;   // 仅当 pltEntities=1 时有效
  struct _PlotObjs
  {
    OdInt32 num;
    const GcDbObject** objs;
  } plotObjs;  // 仅当 pltEntities=2 时有效
  //GcEdSelectionSet* ss; //???

  /* 其他参数
  */
  GcDbObjectId vstyleId; // 视觉样式ID，仅pltViewMode==4有意义

  GcString     pltStyleFilePath;

  bool pltLineweights;
  bool pltPlotStyles;
  double pltScaleLineweights;

  GcPlotParameters()
  {
    pltSpace = 0;
    pltArea = 0;
    pltViewCenter = NULL;
    pltViewMode = 0;
    pltOrder = 0;
    pltEntities = 0;
    plotIds.num = 0;
    plotIds.ids = NULL;
    plotObjs.num = 0;
    plotObjs.objs = NULL;
    pltLineweights = true;
    pltPlotStyles = true;
    pltScaleLineweights = 1.0;
  }
};

class GcPlotInterface
{
public:
  virtual OdInt32 genPlotData(GcDbObjectId blockTableRecordId, // NULL => curDocument()
    GcPlotDataDumpper* pDumpper,
    GcPlotParameters* pParams,
    GcPlotProgressMeter* pProgress = NULL) = 0;
  virtual void clearPlotData() = 0;
};

inline GcPlotInterface* gcgsPlotInterface()
{
  GcadGraphicSystemService* pGsSrv = gcadGraphicSysService();
  return pGsSrv ? pGsSrv->plotInterface() : NULL;
}


#endif //__GCAD__GS_PLOT__INTERFACE__H__

