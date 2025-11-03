/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef   _GDSRXDEF_H_
#define   _GDSRXDEF_H_ 1

#pragma pack (push, 8)
typedef struct fchnd {
  struct fchnd *next;
  int fcode;
  int(*fhdl)();
} FunHandList;

class GcRxGenHand;

class RxGDSAppTableEntryType {
public:
  int    lflag;
  GCHAR* appname;
  Gsoft::LongPtr  apphandle;
  int    gds_fcode;
  int    gds_invkcnt;
  struct resbuf* gds_argl;
  FunHandList* gds_fhdl;
  GcRxGenHand * modhandle;
  resbuf *gds_ret;
  int    gds_rettype;
};

#pragma pack (pop)
#endif