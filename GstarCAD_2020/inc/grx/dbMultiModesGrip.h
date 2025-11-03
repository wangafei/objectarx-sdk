#ifndef _DBMULTIMODESGRIP_H
#define _DBMULTIMODESGRIP_H

#include "gcdb.h"
#include "dbmain.h"

#pragma pack (push, 8)

class GCDB_DLL_DECL GcDbMultiModesGripPE  :  public GcRxObject
{
public:
    GCRX_DECLARE_MEMBERS(GcDbMultiModesGripPE);

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
        GcString        DisplayString;
        GcString        ToolTip;
        GcString        CLIDisplayString;
        GcString        CLIPromptString;
        GcString        CLIKeywordList;
        GripCursorType  CursorType;
        GripActionType  ActionType;
        GcString        CommandString;
    };

    virtual bool getGripModes(GcDbEntity* pThis, 
                              GcDbGripData* pGripData, 
                              GcArray<GripMode>& modes, 
                              unsigned int& curMode) const = 0;
   
    virtual unsigned int mode(GcDbEntity* pThis, GcDbGripData* pGripData) const = 0;

    virtual GripMode modeEx(GcDbEntity* pThis, GcDbGripData* pGripData) const = 0;

    virtual bool setMode(GcDbEntity* pThis, GcDbGripData* pGripData, unsigned int newMode) = 0;

    virtual GripType gripType(GcDbEntity* pThis, GcDbGripData* pGripData) const = 0;

    virtual void reset(GcDbEntity* pThis) = 0;
};

inline GcDbMultiModesGripPE::GripMode::GripMode()
        : Mode(GcDbMultiModesGripPE::kMove)
        , ActionType(kDragOn)
{
}

#pragma pack (pop)

#endif  // _DBMULTIMODESGRIP_H

