#pragma once

#include "gcadstd.h"
#include "../Gs/Gs.h"
#include "../Gs/GsDefs.h"
#include "../Gs/GsBaseModel.h"
#include "../Gs/GsBaseVectorizer.h"
#include "../Gs/GsBitMap.h"
#include "../Gs/GsBMPDevice.h"
#include "../Gs/GsContainerNode.h"
#include "../Gs/GsDCPointArray.h"
#include "../Gs/GsEntityNode.h"
#include "../Gs/GsExport.h"
#include "../Gs/GsLayerNode.h"
#include "../Gs/GsLight.h"
#include "../Gs/GsLightNode.h"
#include "../Gs/GsModel.h"
#include "../Gs/GsNode.h"
#include "../Gs/GsSelectionReactor.h"
#include "../Gs/GsViewProps.h"
#include "../Gs/LineWtIndex.h"


//////////////////////////////////////////////////////////////////////////
// 
namespace GCGS
{
  typedef enum 
  {
    kSuccess = 0,
    kOutOfRange,
    kInvalidInput
  } ErrorStatus;

  typedef enum 
  {
    kScreenDevice = 0,
    kOffScreenDevice,
    kSelectionDevice
  } DeviceType;

  typedef enum  {
    kHighlightDashed            = 0, // 默认高亮线型
    kHighlightThicken           = 1, // 加厚(两侧)
    kHighlightDashedAndThicken  = 2, // 中间高亮两侧加厚 (以上两个是热点提示用到)
    kHighlightCustom            = 3, // 自定义 (图纸空间的中间虚线 动态输入中点线 等等)
    kHighlightDim               = 4, // 
    kHighlightThickDim          = 5, // (以上两个是2012 新特性 具体功能未知)
    kHighlightTransparency      = 99
  }HighlightStyle;

  // 参考 OdGsView::RenderMode

  typedef enum 
  {
    kWCS = 0,
    kOCS,     // Object, or Entity, or Model
    kECS,     // Eye (View)
    kDCS,     // Display (Projection)
    kUCS      // User
  } CoordnateSystem;

  typedef enum 
  {
    kNotCare = 0, // use last
    kDraw,
    kUndraw,
    kXOR,
    kHighlight,
    kXORHighlight,
    kXORFill,
  } DrawMode;

  typedef enum 
  {
    kModelSpace = 0,
    kPaperSpace
  } SpaceType;
};

typedef unsigned long GcGsDrawModeFlag;
#define GcGsMakeDMF(drawmode, highlightstyle) ((drawmode) | ((highlightstyle)<<8))
#define GcGsGetDrawMode(dmf)                  ((dmf) & 0xff)
#define GcGsGetDrawHLFlag(dmf)                (((dmf)>>8) & 0xff)

//////////////////////////////////////////////////////////////////////////
// 
typedef OdGiDrawable* (* GcGsGetInterfaceFunc)     (LONG_PTR objectId, bool bNeedsValidation);
typedef void          (* GcGsReleaseInterfaceFunc) (OdGiDrawable*);
class OdGiContextForDbDatabase;
typedef OdSmartPtr<OdGiContextForDbDatabase> OdGiContextForDbDatabasePtr;

class GcGsConfig;

class GcGsClassFactory
{
public:
  virtual ~GcGsClassFactory(void) { }

  //////////////////////////////////////////////////////////////////////////
  // 以下7个函数内部不调用，做为兼容ARX接口存在
  virtual OdGsModel *  createModel   (OdGsModel::RenderType) { return NULL; }
  virtual void         deleteModel   (OdGsModel * model)         = 0;

  virtual OdGsModel *  createModel   (OdGsModel::RenderType, 
    LONG_PTR databaseId, 
    GcGsGetInterfaceFunc, 
    GcGsReleaseInterfaceFunc ) = 0;

  virtual OdGsView *   createView    (const OdGsClientViewInfo * pInfo = NULL,
    bool bEnableLayerVisibilityPerView = false) = 0;
  virtual void         deleteView    (OdGsView * view)           = 0;

  virtual OdGsDevice * createDevice  (OdGsWindowingSystemID id,
    GCGS::DeviceType deviceType = GCGS::kScreenDevice) = 0;
  virtual OdGsDevice * createOffScreenDevice(void)               = 0;
  virtual void         deleteDevice  (OdGsDevice * device)       = 0;

public:
  virtual OdGiContextForDbDatabasePtr createContext() = 0;

public:
  virtual GcGsConfig * getConfig     (void)                      = 0;
  virtual void         releaseConfig (GcGsConfig * config)       = 0;

  virtual void         addReactor    (OdGsReactor * pReactor)    = 0;
  virtual void         removeReactor (OdGsReactor * pReactor)    = 0;
};
