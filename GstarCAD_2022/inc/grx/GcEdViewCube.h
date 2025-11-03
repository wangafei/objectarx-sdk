#pragma once

class GcDbUcsPlane;
class GcDbHomeView;
class GcEdViewCubeReactor;

enum GcEdViewCubePart
{
  FACE_FRONT = 0,
  FACE_BACK,
  FACE_BOTTOM,
  FACE_TOP,
  FACE_LEFT,
  FACE_RIGHT,

  EDGE_FRONT_BOTTOM,
  EDGE_FRONT_TOP,
  EDGE_BACK_BOTTOM,
  EDGE_BACK_TOP,
  EDGE_LEFT_BOTTOM,
  EDGE_RIGHT_BOTTOM,
  EDGE_LEFT_TOP,
  EDGE_RIGHT_TOP,
  EDGE_FRONT_LEFT,
  EDGE_BACK_LEFT,
  EDGE_FRONT_RIGHT,
  EDGE_BACK_RIGHT,

  CORNER_FRONT_LEFT_BOTTOM,
  CORNER_FRONT_RIGHT_BOTTOM,
  CORNER_FRONT_LEFT_TOP,
  CORNER_FRONT_RIGHT_TOP,
  CORNER_BACK_LEFT_BOTTOM,
  CORNER_BACK_RIGHT_BOTTOM,
  CORNER_BACK_LEFT_TOP,
  CORNER_BACK_RIGHT_TOP,

  ARROW_FRONT,
  ARROW_BACK,
  ARROW_BOTTOM,
  ARROW_TOP,
  ARROW_LEFT,
  ARROW_RIGHT,

  BUTTON_ROTATE_CCW,
  BUTTON_ROTATE_CW,
  BUTTON_HOME,
  BUTTON_LOCK,
  BUTTON_MENU,

  COMPASS_EAST,
  COMPASS_WEST,
  COMPASS_SOUTH,
  COMPASS_NORTH,
  COMPASS_RING
};




class GcEdViewCube
{
public:
  virtual GcGiDrawable*       getDrawable() const = 0;
  virtual GcGsView*           getView() const = 0;
  virtual GcGsModel*          getModel() const = 0;

  virtual void                redraw() const = 0;
  virtual bool                isMouseInRegion() const = 0;

  virtual HWND                getDeviceHandle() const = 0;
  virtual bool                isVisible() const = 0;
  virtual bool                isEnable() const = 0;
  virtual bool                isOverride() const = 0;

  virtual int                 getLocation() const = 0;
  virtual int                 getSize() const = 0;
  virtual int                 getMinOpacity() const = 0;
  virtual int                 getTransitionDuration() const = 0;
  virtual bool                getOrientToUCS() const = 0;
  virtual bool                getDragSnap() const = 0;
  virtual bool                getZoomToFitScene() const = 0;
  virtual bool                getPreserveSceneUp() const = 0;
  virtual bool                getDrawCompass() const = 0;
  virtual bool                getDrawUCSMenu() const = 0;
  virtual bool                getPerspWithOrtho() const = 0;
  virtual const GcDbHomeView& getHomeCamera() const = 0;
  virtual const GcGeVector3d& getSceneUpDirection() const = 0;
  virtual const GcGeVector3d& getSceneFrontDirection() const = 0;
  virtual const GcDbUcsPlane& getUCSPlane() const = 0;

  virtual void                setDeviceHandle(HWND hDevice) = 0;
  virtual void                setVisible(bool bVisible) = 0;
  virtual void                setEnable(bool bEnable) = 0;
  virtual void                setOverride(bool bOverride) = 0;

  virtual void                setLocation(int nLocation) = 0;
  virtual void                setSize(int nSize) = 0;
  virtual void                setMinOpacity(int nMinOpacity) = 0;
  virtual void                setTransitionDuration(int nTransitionDuration) = 0;
  virtual void                setOrientToUCS(bool bOrientToUCS) = 0;
  virtual void                setDragSnap(bool bDragSnap) = 0;
  virtual void                setZoomToFitScene(bool bZoomToFitScene) = 0;
  virtual void                setPreserveSceneUp(bool bPreserveSceneUp) = 0;
  virtual void                setDrawCompass(bool bDrawCompass) = 0;
  virtual void                setDrawUCSMenu(bool bDrawUCSMenu) = 0;
  virtual void                setPerspWithOrtho(bool bPerspWithOrtho) = 0;
  virtual void                setHomeCamera(const GcDbHomeView& home) = 0;
  virtual void                setSceneUpDirection(const GcGeVector3d& up) = 0;
  virtual void                setSceneFrontDirection(const GcGeVector3d& front) = 0;
  virtual void                setUCSPlane(const GcDbUcsPlane& ucs) = 0;

  virtual void                onLButtonDown(UINT nFlags, POINT pt) = 0;
  virtual void                onLButtonUp(UINT nFlags, POINT pt) = 0;
  virtual void                onMouseMove(UINT nFlags, POINT pt) = 0;

  virtual bool                attachView(GcGsView* pGsView) = 0;
  virtual GcGsView*           detachView() = 0;

  virtual void                addReactor(GcEdViewCubeReactor* pReactor) = 0;
  virtual void                removeReactor(GcEdViewCubeReactor* pReactor) = 0;

  virtual void                goToHomeView() = 0;
  virtual GcEdViewCubePart    getActivePart() const = 0;
};


class GcEdViewCubeReactor
{
public:
  virtual void                onClicked(GcEdViewCube* pCube, GcEdViewCubePart part) = 0;
  virtual void                onDragBegin(GcEdViewCube* pCube, GcEdViewCubePart part) = 0;
  virtual void                onDragEnd(GcEdViewCube* pCube) = 0;
};


GCED_DLL_DECL GcEdViewCube* gcedCreateViewCube(GcGsView* pGsView);

GCED_DLL_DECL void gcedDestroyViewCube(GcEdViewCube* pCube);