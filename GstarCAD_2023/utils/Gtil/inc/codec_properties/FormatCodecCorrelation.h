/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef FORMATCODECPROPERTYINTERFACE_H
#include "FormatCodecPropertyInterface.h"
#endif
#ifndef FORMATCODECINCLUSIVEPROPERTYSETINTERFACE_H
#include "FormatCodecInclusivePropertySetInterface.h"
#endif
#ifndef POINT3D_H
#include "Point3d.h"
#endif
#ifndef VECTOR2D_H
#include "Vector2d.h"
#endif

#ifndef FORMATCODECCORRELATION_H
#define FORMATCODECCORRELATION_H

namespace Gtil
{
  class GTIL_EXPORT FormatCodecCorrelation : public FormatCodecPropertyInterface
  {
  public:
    enum Units
    {
      kNone,
      kUnknown,
      kMillimeter,
      kCentimeter,
      kMeter,
      kKilometer,
      kInch,
      kFoot,
      kUSSurveyFoot,
      kYard,
      kMile,
      kMicroinches,
      kMils,
      kAngstroms,
      kNanometers,
      kMicrons,
      kDecimeters,
      kDekameters,
      kHectometers,
      kGigameters,
      kAstronomical,
      kLightYears,
      kParsecs,
      kRadians,
      kArcSeconds,
      kDegrees
    };

  public:
    virtual ~FormatCodecCorrelation();

    virtual FormatCodecPropertyInterface* clone() const;

    virtual void getInsertionPoint(Point3d& ptInsertionPt) const;
    virtual void setInsertionPoint(const Point3d& ptInsertionPt);

    virtual void getScale(Vector2d& vecScale) const;
    virtual void setScale(const Vector2d& vecScale);

    virtual void getRotation(double& dfRotation) const;
    virtual void setRotation(const double& dfRotation);

    virtual void getResolution(Vector2d& vecResolution) const;
    virtual void setResolution(const Vector2d& vecResolution);

    virtual void getResolutionUnits(Units& resUnits) const;
    virtual void setResolutionUnits(Units resUnits);

    virtual bool hasCoordinateSystemDescription() const;
    virtual void getCoordinateSystemDescription(Gtil::StringBuffer& sbDescription) const;

    virtual bool isValid() const;

  protected:
    FormatCodecCorrelation();
    FormatCodecCorrelation(const FormatCodecCorrelation& from);

  protected:
    Point3d  mptInsertionPoint;
    Vector2d mvecScale;
    double   mdfRotation;
    Vector2d mvecResolution;
    Units    mResUnits;
    bool     mbValid;
  };
  class GTIL_EXPORT FormatCodecCorrelationSet : public FormatCodecInclusivePropertySetInterface
  {
  public:
    FormatCodecCorrelationSet();
    virtual ~FormatCodecCorrelationSet();

    virtual const FormatCodecCorrelation* getCorrelation(int nIndex) const;
  };
}

#endif
