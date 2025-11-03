#pragma once
#include "CmColorBase.h"

class OdCmDialogColor : public OdCmColorBase
{
public:

  OdCmDialogColor();
  OdCmDialogColor(const OdCmDialogColor& other);
  OdCmDialogColor(const OdCmColorBase& other);
  virtual ~OdCmDialogColor();

  OdCmDialogColor& operator =(const OdCmDialogColor& inputColor);
  OdCmDialogColor& operator =(const OdCmColorBase& inputColor);

  bool operator ==(const OdCmDialogColor& color) const;
  bool operator !=(const OdCmDialogColor& color) const;
  bool operator ==(const OdCmColorBase& color) const;
  bool operator !=(const OdCmColorBase& color) const;

  virtual OdCmEntityColor::ColorMethod colorMethod() const;
  virtual OdResult setColorMethod(OdCmEntityColor::ColorMethod eColorMethod);

  virtual bool isByColor() const;
  virtual bool isByLayer() const;
  virtual bool isByBlock() const;
  virtual bool isByACI() const;
  virtual bool isByPen() const;
  virtual bool isForeground() const;

  virtual OdUInt32 color() const;
  virtual OdResult setColor(OdUInt32 color);

  virtual OdResult setRGB(OdUInt8 red,
    OdUInt8 green,
    OdUInt8 blue);
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

  virtual OdResult setNames(const OdChar* colorName,
    const OdChar* bookName = NULL);
  virtual const OdChar* colorName(void) const;
  virtual const OdChar* bookName(void) const;
  virtual const OdChar* colorNameForDisplay(void);
  virtual bool hasColorName(void) const;
  virtual bool hasBookName(void) const;
};