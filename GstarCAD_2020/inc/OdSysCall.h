///////////////////////////////////////////////////////////////////////////////
// TODO
// 
// 本文件被包含在 "OdaCommon.h" 里面
// 
///////////////////////////////////////////////////////////////////////////////


#ifndef _OD_SYSTEM_INTERNAL_CALL_H_INCLUDED_
#define _OD_SYSTEM_INTERNAL_CALL_H_INCLUDED_

// 定义是否使用内部调用
#define USE_SYSTEM_INTERNAL_CALL


#ifdef  USE_SYSTEM_INTERNAL_CALL

// 注意：对于内部函数，不允许使用 OdSystemInteral
class OdSystemInternal;
#define ODGETSYSCALLER  (*(OdSystemInternal*)0)

#define ODMAKEPARAM0()  ODGETSYSCALLER
#define ODMAKEPARAM(p)  ODGETSYSCALLER,(p)

#else

#define ODMAKEPARAM0()  
#define ODMAKEPARAM(p)  (p)

#endif //USE_SYSTEM_INTERNAL_CALL


#define ODSYSDEF     const OdSystemInternal&
#define ODSYSNAME    si
#define ODSYSDEFNAME ODSYSDEF ODSYSNAME

#define ODARXDEF

#define ODSYSCALL0(FN)                  FN(ODMAKEPARAM0())
#define ODSYSCALL1(FN, p1)              FN(ODMAKEPARAM(p1))
#define ODSYSCALL2(FN, p1, p2)          FN(ODMAKEPARAM(p1), (p2))
#define ODSYSCALL3(FN, p1, p2, p3)      FN(ODMAKEPARAM(p1), (p2), (p3))
#define ODSYSCALL4(FN, p1, p2, p3, p4)  FN(ODMAKEPARAM(p1), (p2), (p3), (p4))

#define ODSYSCALL5(FN, p1, p2, p3, p4, p5) \
        FN(ODMAKEPARAM(p1), (p2), (p3), (p4), (p5))

#define ODSYSCALL6(FN, p1, p2, p3, p4, p5, p6) \
        FN(ODMAKEPARAM(p1), (p2), (p3), (p4), (p5), (p6))

#define ODSYSCALL7(FN, p1, p2, p3, p4, p5, p6, p7) \
        FN(ODMAKEPARAM(p1), (p2), (p3), (p4), (p5), (p6), (p7))

#define ODSYSCALL8(FN, p1, p2, p3, p4, p5, p6, p7, p8) \
        FN(ODMAKEPARAM(p1), (p2), (p3), (p4), (p5), (p6), (p7), (p8))

#define ODSYSCALL9(FN, p1, p2, p3, p4, p5, p6, p7, p8, p9) \
        FN(ODMAKEPARAM(p1), (p2), (p3), (p4), (p5), (p6), (p7), (p8), (p9))

// 不提供可变参数宏 ODSYSCALL (参考TRACE, TRACE0, ...)


// 使用范例(注意: ODSYSCALLx 要根据参数个数选择)
// fo()         ->  ODSYSCALL0(fo)            -> fo ( == ODSYSCALL0(fo
// foa(p)       ->  ODSYSCALL1(foa, p)        -> foa( == ODSYSCALL1(foa, 
// fob(p, t, x) ->  ODSYSCALL3(fob, p, t, x)  -> fob( == ODSYSCALL3(fob, 


/************************ Gcad(Code) - 异常转错误值**********************************/

#ifndef OD_ERR_RESULT

  #define OD_ERR_RESULT  od_internal_error_result

  // 异常转错误值-起始(I=init, 指需要指定错误初始值)
  #define OD_TRY_I(def)  OdResult OD_ERR_RESULT = def; try {

  // 异常转错误值-结束(I=set to Init, 指设置错误值到初始化变量)
  #define OD_CATCH_I()   } catch(OdError& oderr) { OD_ERR_RESULT = oderr.code(); }


  // 异常转错误值-起始(0=空处理, 可以用于在同一语法范围内捕获下一个异常)
  #define OD_TRY_0()     try {

  // 异常转错误值-结束(0=空处理, 异常捕获后不处理)
  #define OD_CATCH_0()   } catch(OdError&) { }


  // 异常转错误值-起始(设置初始值为 eOk, 默认)
  #define OD_TRY()       OD_TRY_I(Oda::eOk)

  // 异常转错误值-结束(返回 OD_ERR_RESULT, 默认)
  #define OD_CATCH()     OD_CATCH_I() return OD_ERR_RESULT;


  // 异常转错误值(N=No return, 指没有返回)
  #ifdef _DEBUG

    #define OD_TRY_N()   OD_TRY_I(Oda::eOk)
    #define OD_CATCH_N() OD_CATCH_I()

  #else

    #define OD_TRY_N()   OD_TRY_0()
    #define OD_CATCH_N() OD_CATCH_0()

  #endif

#endif //OD_ERR_RESULT

/************************ Gcad(Code) - 异常转错误值**********************************/


#endif // _OD_SYSTEM_INTERNAL_CALL_H_INCLUDED_

