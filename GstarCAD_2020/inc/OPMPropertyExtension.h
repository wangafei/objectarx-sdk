#ifndef __OPMPROPERTYEXTENSION_H_
#define __OPMPROPERTYEXTENSION_H_

#include <atlbase.h>
#include "OdaCommon.h"
#include "OdPlatform.h"
#include "OdaDefs.h"
#include "RxObject.h"
#include "DbDatabase.h"

#ifdef _OPM_TOOLKIT_IN_DLL_
#define _IC_OPM_EXPORT_ _declspec(dllexport)
#else
#define _IC_OPM_EXPORT_ _declspec(dllimport)
#endif

interface IPropertyManager;
interface IDynamicProperty;

class _IC_OPM_EXPORT_ OPMPropertyExtension : public OdRxObject
{
protected:	
  CComPtr<IPropertyManager> m_pPropertyManager;
public:	
  OPMPropertyExtension(void);
  virtual ~OPMPropertyExtension(void);

  ODRX_DECLARE_MEMBERS(OPMPropertyExtension);

  virtual IPropertyManager* GetPropertyManager();

  virtual void SetPropertyManager(IPropertyManager* pPropManager);
};

class _IC_OPM_EXPORT_ OPMPropertyExtensionFactory :	public OdRxObject
{
public:	
  OPMPropertyExtensionFactory(void);
  virtual ~OPMPropertyExtensionFactory(void);

  ODRX_DECLARE_MEMBERS(OPMPropertyExtensionFactory);

  virtual OPMPropertyExtension* CreateOPMObjectProtocol(OdRxClass* pClass, LONG lReserved = NULL);

  virtual OPMPropertyExtension* CreateOPMCommandProtocol(const ACHAR * pGlobalCommand, LONG lReserved = NULL);

  virtual BOOL GetOPMManager(const ACHAR * pGlobalCommand, IPropertyManager** pManager);

  virtual BOOL GetPropertyCount(OdRxObject* pClass, LONG* pPropCount);

  virtual LONG GetPropertyClassArray(OdRxObject* pClass, IDynamicProperty**  pPropertyArray); 

  virtual BOOL GetPropertyCountEx(OdRxObject* pClass, LONG* pPropCount);

  virtual LONG GetPropertyClassArray(OdRxObject* pClass, IUnknown**  pPropertyArray);
};

typedef OdSmartPtr<OPMPropertyExtension> OPMPropertyExtensionPtr;
typedef OdSmartPtr<OPMPropertyExtensionFactory> OPMPropertyExtensionFactoryPtr;

#define GET_OPMEXTENSION_CREATE_PROTOCOL() \
  OPMPropertyExtensionFactory::cast(OdDbDatabase::desc()->getX(OPMPropertyExtensionFactory::desc()))

#define GET_OPMPROPERTY_MANAGER(pAcRxClass) \
  GET_OPMEXTENSION_CREATE_PROTOCOL()->CreateOPMObjectProtocol(pAcRxClass)->GetPropertyManager() 

#define GET_OPM_COMMAND_PROPERTY_MANAGER(pCommandName) \
  GET_OPMEXTENSION_CREATE_PROTOCOL()->CreateOPMCommandProtocol(pCommandName)->GetPropertyManager() 

#endif //#ifndef __OPMPROPERTYEXTENSION_H_