

#ifndef _ZDBMULTIMODESGRIP_H
#define _ZDBMULTIMODESGRIP_H

#include "zacdb.h"
#include "zdbmain.h"
#include "zAcstring.h"
#pragma pack (push, 8)


class ZCDBCORE2D_PORT ZSOFT_NO_VTABLE ZcDbMultiModesGripPE  :  public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbMultiModesGripPE);

    enum GripType 
    { 
        kPrimary,
        kSecondary 
    };

    enum GripModeIdentifier
    {
        kNone = 0,   
        kMove,
		
        kCustomStart = 100,
    };
    
    enum GripActionType
    {
      
        kDragOn = 0,
        kImmediate,
        kCommand,
    };

    enum GripCursorType
    {
        kcNone = 0,
        kcCrosshairPlus,         
        kcCrosshairMinus,
        kcCrosshairCurve,
        kcCrosshairLine,      
        kcCrosshairAngle,      
    };

    struct GripMode
    {
        GripMode();

        unsigned int    Mode;

        ZcString        DisplayString;

        ZcString        ToolTip;

        ZcString        CLIDisplayString;

        ZcString        CLIPromptString;

        ZcString        CLIKeywordList;

        GripCursorType  CursorType;

        GripActionType  ActionType;

        ZcString        CommandString;
    };


    virtual bool getGripModes(ZcDbEntity* pThis, 
                              ZcDbGripData* pGripData, 
                              ZcArray<GripMode>& modes, 
                              unsigned int& curMode) const = 0;

    virtual unsigned int mode(ZcDbEntity* pThis, ZcDbGripData* pGripData) const = 0;

    virtual GripMode modeEx(ZcDbEntity* pThis, ZcDbGripData* pGripData) const = 0;

    virtual bool setMode(ZcDbEntity* pThis, ZcDbGripData* pGripData, unsigned int newMode) = 0;

    virtual GripType gripType(ZcDbEntity* pThis, ZcDbGripData* pGripData) const = 0;


    virtual void reset(ZcDbEntity* pThis) = 0;
};

inline ZcDbMultiModesGripPE::GripMode::GripMode()
        : Mode(ZcDbMultiModesGripPE::kMove)
        , ActionType(kDragOn)
        , CursorType(kcNone)
{
}

#pragma pack (pop)

#endif  

