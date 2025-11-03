#pragma once
#include <afxpriv.h>
#include "gduiTextTip.h"

class GdToolTip;
class GdWthToolTip;

class  CGdWthToolTipCtrl : public CGdToolTipCtrl
{
  DECLARE_DYNAMIC(CGdWthToolTipCtrl)
public:
  GdWthToolTip* GetWthToolTip();
};