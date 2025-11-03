#pragma once
#include "dbNavSettings.h"

class GcEdSteeringWheelReactor;
class GcEdSteeringWheel;

GCED_DLL_DECL GcEdSteeringWheel* gcedCreateSteeringWheel();

GCED_DLL_DECL void gcedDestroySteeringWheel(GcEdSteeringWheel* pWheel);

class GcEdSteeringWheel
{
public:
  enum WheelType
  {
    kExterior = 0,    ///< View Object Wheel.
    kInterior,        ///< Tour Buiding Wheel.
    kFull,            ///< Full Navigation Wheel.
    k2D,              ///< 2D Steering Wheel.
    kMini,            ///< Mini View Object Wheel.
    kMiniOther,       ///< Mini Tour Building Wheel.
    kMiniEight,       ///< Mini Full Navigation Wheel.

    kTotalCount,      ///< Total number of SteeringWheel types.
    kWheelNone        ///< Marks a disabled SteeringWheel.
  };

  enum MenuType
  {
    // Steering Wheel Menus
    kMenuNone = 0,
    kMenuInterior,
    kMenuExterior,
    kMenuFull,
    kMenu2D
  };

  // Message handlers
  virtual void    onKeyDown(UINT nChar, UINT nRepCount, UINT nFlags) = 0;
  virtual void    onKeyUp(UINT nChar, UINT nRepCount, UINT nFlags) = 0;
  virtual bool    onMouseWheel(UINT nFlags, short zDelta, POINT pt) = 0;
  virtual void    onMouseMove(UINT nFlags, POINT pt) = 0;
  virtual void    onLButtonUp(UINT nFlags, POINT pt) = 0;
  virtual void    onLButtonDown(UINT nFlags, POINT pt) = 0;
  virtual void    onRButtonUp(UINT nFlags, POINT pt) = 0;
  virtual void    onRButtonDown(UINT nFlags, POINT pt) = 0;
  virtual void    onMButtonDown(UINT nFlags, POINT pt) = 0;
  virtual void    onMButtonUp(UINT nFlags, POINT pt) = 0;

  virtual void    setHomeCamera(const GcDbHomeView& home) = 0;
  virtual bool    setLargeWheelOpacity(int nOpacity) = 0;
  virtual int     getLargeWheelOpacity() = 0;
  virtual bool    setMiniWheelOpacity(int nOpacity) = 0;
  virtual int     getMiniWheelOpacity() = 0;
  virtual bool    setWalkSpeed(double speed) = 0;
  virtual double  getWalkSpeed() = 0;
  virtual bool    setActiveWheel(WheelType type) = 0;
  virtual WheelType   getActiveWheel() = 0;
  virtual void    enableWheel(bool enable) = 0;
  virtual bool    isWheelEnabled() = 0;

  virtual GcGsModel * getModel() = 0;
  virtual GcGsModel *  getView() = 0;
  virtual HWND        getDeviceHandle() = 0;

  virtual bool    attachView(HWND hDevice, GcGsView* pGsView) = 0;
  virtual void    detachView() = 0;

  virtual void    addReactor(GcEdSteeringWheelReactor* pReactor) = 0;
  virtual void    removeReactor(GcEdSteeringWheelReactor* pReactor) = 0;

};

class GcEdSteeringWheelReactor
{
public:
  virtual void    modifyContextMenu(HMENU hMenu) = 0;
  virtual void    onSetCursor(HCURSOR hCursor) = 0;
  virtual void    onBeginOperation() = 0;
  virtual void    onEndOperation() = 0;
  virtual void    onBeginShot() = 0;
  virtual void    onEndShot() = 0;
  virtual void    onClose() = 0;
};
