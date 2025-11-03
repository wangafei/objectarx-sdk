#ifndef _ODDBSIGNATUREINFO_INCLUDED_
#define _ODDBSIGNATUREINFO_INCLUDED_

#include "TD_PackPush.h"

class OdDbDate;

struct SignatureInfo
{
  unsigned long   cbSize;

  unsigned long   ulFlags;
  wchar_t*        wszCertSubject;
  wchar_t*        wszCertIssuer;
  wchar_t*        wszSubjectEMail;
  wchar_t*        wszCertSerialNum;
  wchar_t*        wszX500;
  OdDbDate*       pTimeCertNotBefore;
  OdDbDate*       pTimeCertNotAfter;
  wchar_t*        wszComment;
  wchar_t*        wszTimeServer;
  OdDbDate*       pTimestamp;
};

#include "TD_PackPop.h"

#endif