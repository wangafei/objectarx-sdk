#pragma once
#include "zacgs.h"
#include "zdbNavSettings.h"

class ZcEdSteeringWheelReactor;
class ZcEdSteeringWheel;

ZcEdSteeringWheel* zcedCreateSteeringWheel ();
void zcedDestroySteeringWheel(ZcEdSteeringWheel* pWheel);

class ZcEdSteeringWheel
{
public:
    enum WheelType
    {
        kExterior = 0,		
        kInterior,			
        kFull,				
        k2D,
        kMini,		
        kMiniOther,	
        kMiniEight,	

        kTotalCount,		
        kWheelNone			
    };

    enum MenuType
    {

        kMenuNone = 0,
        kMenuInterior,
        kMenuExterior,
        kMenuFull,
        kMenu2D
    };

    virtual void    onKeyDown     (UINT nChar, UINT nRepCount, UINT nFlags) = 0;
    virtual void    onKeyUp       (UINT nChar, UINT nRepCount, UINT nFlags) = 0;
    virtual bool    onMouseWheel  (UINT nFlags, short zDelta, POINT pt) = 0;
    virtual void    onMouseMove   (UINT nFlags, POINT pt) = 0;
    virtual void    onLButtonUp   (UINT nFlags, POINT pt) = 0;
    virtual void    onLButtonDown (UINT nFlags, POINT pt) = 0;
    virtual void    onRButtonUp   (UINT nFlags, POINT pt) = 0;
    virtual void    onRButtonDown (UINT nFlags, POINT pt) = 0;
    virtual void    onMButtonDown (UINT nFlags, POINT pt) = 0;
    virtual void    onMButtonUp (UINT nFlags, POINT pt) = 0;

    virtual void    setHomeCamera (const ZcDbHomeView& home) = 0;
    virtual bool    setLargeWheelOpacity  (int nOpacity) = 0;
    virtual int     getLargeWheelOpacity  () = 0;
    virtual bool    setMiniWheelOpacity  (int nOpacity) = 0;
    virtual int     getMiniWheelOpacity  () = 0;
    virtual bool    setWalkSpeed(double speed) = 0;
    virtual double  getWalkSpeed() = 0;
    virtual bool    setActiveWheel(WheelType type) = 0;
    virtual WheelType   getActiveWheel() = 0;
    virtual void    enableWheel (bool enable) = 0;
    virtual bool    isWheelEnabled() = 0;

    virtual ZcGsModel * getModel() = 0;
    virtual ZcGsView *  getView()  = 0;
    virtual HWND        getDeviceHandle() = 0;

    virtual bool    attachView      (HWND hDevice, ZcGsView* pGsView) = 0;
    virtual void    detachView      () = 0;

    virtual void    addReactor  (ZcEdSteeringWheelReactor* pReactor) = 0;
    virtual void    removeReactor(ZcEdSteeringWheelReactor* pReactor) = 0;

};

class ZcEdSteeringWheelReactor
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
