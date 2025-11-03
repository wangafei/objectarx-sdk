#ifndef _OD_DB_SERVICES_
#define _OD_DB_SERVICES_

#include "TD_PackPush.h"

#include "rxsrvice.h"

class OdGiContext;

class ODRX_ABSTRACT OdDbServices : public OdRxService
{
public:
  ODRX_DECLARE_MEMBERS(OdDbServices);
};

TOOLKIT_EXPORT OdDbServices* oddbServices();

TOOLKIT_EXPORT bool oddbIsCustomObject(const OdDbObjectId& id);

TOOLKIT_EXPORT OdResult oddbValidateSetup(long lcid);

TOOLKIT_EXPORT OdResult oddbCleanUp();

TOOLKIT_EXPORT OdGiContext* oddbSetDefaultOdGiContext(OdGiContext *);

TOOLKIT_EXPORT OdResult oddbGetThumbnailBitmapFromDxfFile(const OdChar* filename, void*& pBitmap);

class OdDbXObject : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbXObject);

  virtual OdResult audit(OdDbAuditInfo* pAuditInfo);

  OdResult dwgIn(OdDbDwgFiler* pFiler);
  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);
  OdResult dwgOut(OdDbDwgFiler* pFiler) const;
  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;

  OdResult dxfIn(OdDbDxfFiler* pFiler);
  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);
  OdResult dxfOut(OdDbDxfFiler* pFiler) const;
  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;

protected:
  OdDbXObject();
};

class OdCmComplexColor : public  OdDbXObject
{
public:
  ODRX_DECLARE_MEMBERS(OdCmComplexColor);

  virtual OdCmComplexColor* incReference();
  virtual void              decReference();

  virtual OdResult getDescription(OdChar*& desc) const;
  virtual OdResult getExplanation(OdChar*& expl) const;

  virtual OdCmEntityColor::ColorMethod  colorMethod() const;
  virtual OdResult setColorMethod(OdCmEntityColor::ColorMethod eColorMethod);

  virtual bool isByColor() const;
  virtual bool isByLayer() const;
  virtual bool isByBlock() const;
  virtual bool isByACI() const;
  virtual bool isByPen() const;
  virtual bool isForeground() const;

  virtual OdUInt32 color() const;
  virtual OdResult setColor(OdUInt32 color);

  virtual OdResult setRGB(OdUInt8 red, OdUInt8 green, OdUInt8 blue);
  virtual OdResult setRed(OdUInt8 red);
  virtual OdResult setGreen(OdUInt8 green);
  virtual OdResult setBlue(OdUInt8 blue);
  virtual OdUInt8 red() const;
  virtual OdUInt8 green() const;
  virtual OdUInt8 blue() const;

  virtual OdUInt16 colorIndex() const;
  virtual OdResult setColorIndex(OdUInt16 colorIndex);
  virtual OdUInt16 penIndex() const;
  virtual OdResult setPenIndex(OdUInt16 penIndex);

  virtual OdResult copyFrom(const OdRxObject*);

  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;
  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;
  virtual OdResult audit(OdDbAuditInfo* pAuditInfo);

private:
  OdUInt16 refCount;
  OdCmEntityColor mColor;
};

#include "TD_PackPop.h"

#endif