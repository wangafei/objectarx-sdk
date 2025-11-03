#pragma once

#include <map>

// zcedGetXXX
void getPoint();
void getString();
void getAngle();
void getOrient();
void getReal();
void getInt();
void getCorner();
void getDist();
void getKWord();
void getInput();

// entsel
void entSelEx();

// zcedSSGet--Selection
void SSGet_Modeless();
void SSGet_ModeI();
void SSGet_ModeC();
void SSGet_ModeW();
void SSGet_ModeX();
void SSGet_ModePrompts();
void SSGet_ModeK();
void SSGet_ModeF();
void SSGet_ModeB();
void SSGet_ModeA();
void SSGet_ModeS();
void SSGet_ModeCP();

// System var operation
void setSysVarInt();
void getSysVarInt();
void setSysVarStr();
void getSysVarStr();
void setSysVarReal();
void getSysVarReal();
void getSysVarPoint();
void resetSysVar();
