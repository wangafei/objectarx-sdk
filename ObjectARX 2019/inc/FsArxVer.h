#pragma once

//˵��: ���Ա�(�ֹ�����XML ������ User Macros ��)������ͬ���ĺ�����,��Щ���ƿ������ڿ������·��,
// �����ڴ�����(����VS2005)��ȡ����,����ٴζ���
//����ѩ���Ĺ۵�,Ӧ������Ŀ��Ԥ������Preprocessor�д���.����д=
#define FsAcadVer 2019
#define FsArxVer 23.0


//custom macro for use with command names that include special characters (e.g. hyphens)
//#define ACED_ARXCOMMAND_ENTRY_KEY_AUTO(classname, key, group, globCmd, locCmd, cmdFlags, UIContext) \
//	__declspec(selectany) _ARXCOMMAND_ENTRY __ArxCmdMap_##group##key = { _RXST(#group), _RXST(#globCmd), _RXST(#locCmd), cmdFlags, classname::##group ##key, UIContext } ; \
//	extern "C" __declspec(allocate("ARXCOMMAND$__m")) __declspec(selectany) _ARXCOMMAND_ENTRY* const __pArxCmdMap_##group##key = &__ArxCmdMap_##group##key ; \
//	ACED_ARXCOMMAND_ENTRY_PRAGMA(group, key)
