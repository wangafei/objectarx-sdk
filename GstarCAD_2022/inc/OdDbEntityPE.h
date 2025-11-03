#ifndef _ICDB_ENTITYPE_H_
#define _ICDB_ENTITYPE_H_

class OdDbEntity;

class TOOLKIT_EXPORT OdDbEntityPE : public OdRxObject
{
public:

	ODRX_DECLARE_MEMBERS(OdDbEntityPE);

	OdDbEntityPE() {}
	virtual ~OdDbEntityPE() {}

	virtual void list(const OdDbEntity* pEntity) const;
  virtual bool getAtt(const OdDbEntity* pEntity, int dxfCode, double& value) const;
  virtual bool getAtt(const OdDbEntity* pEntity, int dxfCode, int& value) const;
  virtual bool getAtt(const OdDbEntity* pEntity, int dxfCode, OdString& value) const;
  virtual bool getAtt(const OdDbEntity* pEntity, int dxfCode, tdx_point value) const;
};

typedef OdSmartPtr<OdDbEntityPE> OdDbEntityPEPtr;

#endif// _ICDB_ENTITYPE_H_