#pragma once

//说明: 属性表(手工增加XML 或者在 User Macros 中)定义了同名的宏名称,这些名称可以用于控制输出路径,
// 但是在代码中(比如VS2005)获取不到,因此再次定义
//按照雪龙的观点,应该在项目的预处理器Preprocessor中处理.可以写=
#define FsAcadVer 2019
#define FsArxVer 23.0


//custom macro for use with command names that include special characters (e.g. hyphens)
//#define ACED_ARXCOMMAND_ENTRY_KEY_AUTO(classname, key, group, globCmd, locCmd, cmdFlags, UIContext) \
//	__declspec(selectany) _ARXCOMMAND_ENTRY __ArxCmdMap_##group##key = { _RXST(#group), _RXST(#globCmd), _RXST(#locCmd), cmdFlags, classname::##group ##key, UIContext } ; \
//	extern "C" __declspec(allocate("ARXCOMMAND$__m")) __declspec(selectany) _ARXCOMMAND_ENTRY* const __pArxCmdMap_##group##key = &__ArxCmdMap_##group##key ; \
//	ACED_ARXCOMMAND_ENTRY_PRAGMA(group, key)
