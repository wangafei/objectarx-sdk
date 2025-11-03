#pragma once

class COleClientItem;
class OdDbDatabase;

class OdOleManageInterface
{
public:
  //获取指定Database（文档）中的Ole对象
	virtual bool getCntrItems(const OdDbDatabase* pDb,bool onlyLink,OdArray<COleClientItem*>& items) = 0;
  virtual void releaseItems() = 0;
};

TOOLKIT_EXPORT OdOleManageInterface* GetOleManage();
void TOOLKIT_EXPORT SetOleManage(OdOleManageInterface*pManageInterface);
