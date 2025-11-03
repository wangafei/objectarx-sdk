#pragma once
#include "gcadstd.h"
typedef struct fchnd
{
  struct fchnd *next;
  int fcode;
  int(*fhdl)();
} FunHandList;

class OdRxGenHand;

class RxGDSAppTableEntryType {
public:
  int    lflag;
  OdChar* appname;
  LONG_PTR  apphandle;
  int    ads_fcode;
  int    ads_invkcnt;
  struct resbuf* ads_argl;
  FunHandList* ads_fhdl;
  OdRxGenHand * modhandle;
  resbuf *ads_ret;
  int    ads_rettype;
};