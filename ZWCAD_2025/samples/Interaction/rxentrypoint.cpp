#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "Interaction.h"

#define cmd_group_name _T("INTERACTION_COMMANDS")

void initApp();
void unloadApp();

void initApp()
{
	// zcedGetXXX
	acedRegCmds->addCommand(cmd_group_name, _T("TestGetPoint"), _T("TestGetPoint"), ACRX_CMD_MODAL, getPoint);
	acedRegCmds->addCommand(cmd_group_name, _T("TestGetString"), _T("TestGetString"), ACRX_CMD_MODAL, getString);
	acedRegCmds->addCommand(cmd_group_name, _T("TestGetAngle"), _T("TestGetAngle"), ACRX_CMD_MODAL, getAngle);
	acedRegCmds->addCommand(cmd_group_name, _T("TestGetOrient"), _T("TestGetOrient"), ACRX_CMD_MODAL, getOrient);
	acedRegCmds->addCommand(cmd_group_name, _T("TestGetReal"), _T("TestGetReal"), ACRX_CMD_MODAL, getReal);
	acedRegCmds->addCommand(cmd_group_name, _T("TestGetInt"), _T("TestGetInt"), ACRX_CMD_MODAL, getInt);
	acedRegCmds->addCommand(cmd_group_name, _T("TestGetCorner"), _T("TestGetCorner"), ACRX_CMD_MODAL, getCorner);
	acedRegCmds->addCommand(cmd_group_name, _T("TestGetDist"), _T("TestGetDist"), ACRX_CMD_MODAL, getDist);
	acedRegCmds->addCommand(cmd_group_name, _T("TestGetKWord"), _T("TestGetKWord"), ACRX_CMD_MODAL, getKWord);
	acedRegCmds->addCommand(cmd_group_name, _T("TestGetInput"), _T("TestGetInput"), ACRX_CMD_MODAL, getInput);
	// zcedEntSel
	acedRegCmds->addCommand(cmd_group_name, _T("EntSelTest"), _T("EntSelTest"), ACRX_CMD_MODAL, entSelEx);
	// zcedSSGet--Selection
	acedRegCmds->addCommand(cmd_group_name, _T("SSGET_NoMode"), _T("SSGET_NoMode"), ACRX_CMD_MODAL, SSGet_Modeless);
	acedRegCmds->addCommand(cmd_group_name, _T("SSGET_Mode_I"), _T("SSGET_Mode_I"), ACRX_CMD_USEPICKSET | ACRX_CMD_REDRAW, SSGet_ModeI);
	acedRegCmds->addCommand(cmd_group_name, _T("SSGET_Mode_C"), _T("SSGET_Mode_C"), ACRX_CMD_MODAL, SSGet_ModeC);
	acedRegCmds->addCommand(cmd_group_name, _T("SSGET_Mode_W"), _T("SSGET_Mode_W"), ACRX_CMD_MODAL, SSGet_ModeW);
	acedRegCmds->addCommand(cmd_group_name, _T("SSGET_Mode_X"), _T("SSGET_Mode_X"), ACRX_CMD_MODAL, SSGet_ModeX);
	acedRegCmds->addCommand(cmd_group_name, _T("SSGET_Mode_:$"), _T("SSGET_Mode_:$"), ACRX_CMD_MODAL, SSGet_ModePrompts);
	acedRegCmds->addCommand(cmd_group_name, _T("SSGET_Mode_K"), _T("SSGET_Mode_:K"), ACRX_CMD_MODAL, SSGet_ModeK);
	acedRegCmds->addCommand(cmd_group_name, _T("SSGET_Mode_F"), _T("SSGET_Mode_F"), ACRX_CMD_MODAL, SSGet_ModeF);
	acedRegCmds->addCommand(cmd_group_name, _T("SSGET_Mode_B"), _T("SSGET_Mode_B"), ACRX_CMD_MODAL, SSGet_ModeB);
	acedRegCmds->addCommand(cmd_group_name, _T("SSGET_Mode_A"), _T("SSGET_Mode_A"), ACRX_CMD_MODAL, SSGet_ModeA);
	acedRegCmds->addCommand(cmd_group_name, _T("SSGET_Mode_:S"), _T("SSGET_Mode_:S"), ACRX_CMD_MODAL, SSGet_ModeS);
	acedRegCmds->addCommand(cmd_group_name, _T("SSGET_Mode_CP"), _T("SSGET_Mode_CP"), ACRX_CMD_MODAL, SSGet_ModeCP);
	// System var operation
	// You can press F1 to query various system variables and their preset values in the help file
	acedRegCmds->addCommand(cmd_group_name, _T("SetSysVarInt"), _T("SetSysVarInt"), ACRX_CMD_MODAL, setSysVarInt);
	acedRegCmds->addCommand(cmd_group_name, _T("GetSysVarInt"), _T("GetSysVarInt"), ACRX_CMD_MODAL, getSysVarInt);
	acedRegCmds->addCommand(cmd_group_name, _T("SetSysVarStr"), _T("SetSysVarStr"), ACRX_CMD_MODAL, setSysVarStr);
	acedRegCmds->addCommand(cmd_group_name, _T("GetSysVarStr"), _T("GetSysVarStr"), ACRX_CMD_MODAL, getSysVarStr);
	acedRegCmds->addCommand(cmd_group_name, _T("SetSysVarReal"), _T("SetSysVarReal"), ACRX_CMD_MODAL, setSysVarReal);
	acedRegCmds->addCommand(cmd_group_name, _T("GetSysVarReal"), _T("GetSysVarReal"), ACRX_CMD_MODAL, getSysVarReal);
	acedRegCmds->addCommand(cmd_group_name, _T("GetSysVarPoint"), _T("GetSysVarPoint"), ACRX_CMD_MODAL, getSysVarPoint);
	acedRegCmds->addCommand(cmd_group_name, _T("resetSysVar"), _T("resetSysVar"), ACRX_CMD_MODAL, resetSysVar);
}

void unloadApp()
{
	resetSysVar();
	acedRegCmds->removeGroup(cmd_group_name);
}

extern "C" AcRx::AppRetCode
zcrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
	switch (msg)
	{
	case AcRx::kInitAppMsg:
		acrxDynamicLinker->unlockApplication(pkt);
		acrxRegisterAppMDIAware(pkt);
		initApp();
		break;
	case AcRx::kUnloadAppMsg:
		unloadApp();
		break;
	default:
		break;
	}

	return AcRx::kRetOK;
}


