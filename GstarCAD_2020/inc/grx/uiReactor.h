#ifndef _UI_REACTOR_H_
#define _UI_REACTOR_H_

#include "..\OdMutex.h"
#include "..\RxEvent.h"
//#include <map>

//界面相关反应器基类  考虑性能，单独给界面适配了反应器机制

class CGcadUiReactor : public GcRxObject
{
public:
  /*
    样式切换时出发的反应器接口themeStyleChanged
    @nThemeIndex 样式索引
  */
  virtual ~CGcadUiReactor() {}
  virtual void themeStyleChanged(HcInt32 nThemeIndex) = 0;

};


typedef OdSmartPtr<CGcadUiReactor> GcRxGcadUiReactorPtr;

#define DEFINE_UIEVENT(method, params)\
virtual void fire##method params

/*
  UI 反应器管理类和触发类
  负责反应器的添加， 移除及触发
*/
enum em_UITYPE
{
  em_Gcad = 0,
  em_Cmd,
  em_Layman,
  em_sheetSet,
};

typedef std::map<em_UITYPE, HINSTANCE> MAPUI2ICONSRC;
typedef std::map<HcInt32, MAPUI2ICONSRC> MAPTHEME2UISRC;


class CGcadUiEvent : public GcRxObject
{
public:
  CGcadUiEvent() {}
  virtual ~CGcadUiEvent() {}
  /*
    getCurThemeIndex 获取当前主题的索引
    返回值: 主题的索引， 50000+
  */
  virtual HcInt32 getCurThemeIndex() = 0;
  /*
    getIconSrc 获取当前主题的资源句柄
    返回值: 资源句柄
  */
  virtual HINSTANCE getIconSrcInstance(const em_UITYPE& emType) = 0;

public:
  /*
    addReactor 添加反应器
    @pReactor 索要添加到列表的反应器
  */
  virtual void addReactor(CGcadUiReactor* pReactor) = 0;
  /*
    removeReactor 移除反应器
    @pReactor 索要从列表中移除的反应器
  */
  virtual void removeReactor(CGcadUiReactor* pReactor) = 0;

  /*
    ThemeStyleChanged 触发列表中的所有反应器
    @nThemeIndex 当前主题样式的索引
  */
  DEFINE_UIEVENT(ThemeStyleChanged, (HcInt32 nThemeIndex)) = 0;

};

class CGcadUiEvents : public CGcadUiEvent
{
private:
  CGcadUiEvents();
  virtual ~CGcadUiEvents();

public:
  /*
    getCurThemeIndex 获取当前主题的索引 
    返回值: 主题的索引， 50000+
  */
  HcInt32 getCurThemeIndex();
  /*
    getIconSrc 获取当前主题的资源句柄
    返回值: 资源句柄*/
  HINSTANCE getIconSrcInstance(const em_UITYPE& emType);

public:
  /*
    addReactor 添加反应器
    @pReactor 索要添加到列表的反应器
  */
  virtual void addReactor(CGcadUiReactor* pReactor);
  /*
    removeReactor 移除反应器
    @pReactor 索要从列表中移除的反应器
  */
  virtual void removeReactor(CGcadUiReactor* pReactor);

  /*
    ThemeStyleChanged 触发列表中的所有反应器
    @nThemeIndex 当前主题样式的索引
  */
  DEFINE_UIEVENT(ThemeStyleChanged, (HcInt32 nThemeIndex));

private:
  void initData();
  HINSTANCE loadSrcInstance(const em_UITYPE& emType);
  GcString getSrcName(const em_UITYPE& emType);

public:
  /*
    GcadUiEventInstance 获取主题UI反应器的唯一实例
    返回值: UI反应器的唯一实例
  */
  static CGcadUiEvent* GcadUiEventInstance();
  /*
    releaseUiEvent 释放主题UI反应器的唯一实例
  */
  static void releaseUiEvent();
protected:
  GcArray<GcRxGcadUiReactorPtr> m_arrUiReactor;   //反应器数组
  OdMutex                       m_Mutex;          //临界区对象
  HcInt32                       m_nCurThemeIndex; //当前主题的索引
  MAPTHEME2UISRC                m_mapThemeSrc;    //主题对应资源句柄

protected:
  static CGcadUiEvents* m_pGcadEvent;             //主题UI反应器唯一实例
};

GCUI_DLL_DECL CGcadUiEvent* gcrxUiEvent();       //获取主题UI反应器的实例

#define FIRE_UIEVENT(method)\
{  CGcadUiEvent* pEvt = gcrxUiEvent();\
  if (NULL != pEvt){pEvt->fire##method;}}

#endif//_UI_REACTOR_H_