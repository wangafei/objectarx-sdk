
#ifndef AECMODELER_INC_SURFACE_H
#define AECMODELER_INC_SURFACE_H


#include "zentity.h"
#include "zcircle3d.h"
#include "ztransf3d.h"

AECMODELER_NAMESPACE_BEGIN


class DllImpExp ZwSurface : public ZwEntity
{
public:

    ZwSurface(ZwBody* pBody = NULL);
    
    enum Type { kUnspecified, kCylinder, kCone, kSphere, kTorus };

    virtual Type     type     () const = NULL;
    virtual ZwSurface* copy     () const = NULL;

    virtual bool     transform(const ZwTransf3d&,
                               ZwTransf3d::Type  /*transfType*/  = ZwTransf3d::kUnknown,
                               const ZwVector3d& /*stretchVect*/ = ZwVector3d::kNull) = NULL;

    virtual bool     isEqual  (const ZwSurface*) const = NULL;

    virtual bool containsPoint(const ZwPoint3d&) const = NULL;

    virtual ZwCircle3d circle   (const ZwPlane&, const ZwLine3d&) const = NULL;

    virtual ZwVector3d normal   (const ZwPoint3d&) const = NULL;

    virtual void     print    (FILE* = NULL) const   = NULL;
    virtual void     save     (ZwSaveRestoreCallback*) const;
    virtual void     restore  (ZwSaveRestoreCallback*) {}

    ZwSurface*         next     () const     { return mpNext; }
    void             setNext  (ZwSurface* s) { mpNext = s;    }

    ZwSurface* sptr;
    int      n;

private:

    ZwSurface* mpNext;

};



class DllImpExp ZwUnspecifiedSurface : public ZwSurface
{
public:

    ZwUnspecifiedSurface(ZwBody* b = NULL) : ZwSurface(b) {}
    
    virtual Type     type     () const { return kUnspecified; }
    virtual ZwSurface* copy     () const { return new ZwUnspecifiedSurface(*this); }
    virtual void     print    (FILE* = NULL) const;

    virtual bool     transform(const ZwTransf3d&,
                               ZwTransf3d::Type  /*transfType*/  = ZwTransf3d::kUnknown,
                               const ZwVector3d & /*stretchVect*/ = ZwVector3d::kNull)
    { return true; }

    virtual bool     isEqual  (const ZwSurface* s) const; // return this == s;

    virtual bool containsPoint(const ZwPoint3d&) const { return false; }

    virtual ZwCircle3d circle   (const ZwPlane&, const ZwLine3d&) const { return ZwCircle3d();      }
    virtual ZwVector3d normal   (const ZwPoint3d&)              const { return ZwVector3d(0,0,0); }

};



class DllImpExp ZwRevolutionSurface : public ZwSurface
{
public:

    ZwRevolutionSurface();
    ZwRevolutionSurface(const ZwLine3d& axis, const ZwVector3d& startDir, ZwBody* = NULL);
    ZwLine3d           axis     () const { return mAxis;     } 
    ZwVector3d         startDir () const { return mStartDir; }

    virtual bool     transform(const ZwTransf3d&,
                               ZwTransf3d::Type  transfType  = ZwTransf3d::kUnknown,
                               const ZwVector3d& stretchVect = ZwVector3d::kNull);

    virtual bool     isEqual  (const ZwSurface*) const;

    virtual void     save     (ZwSaveRestoreCallback*) const;
    virtual void     restore  (ZwSaveRestoreCallback*);

private:

    ZwLine3d   mAxis;
    ZwVector3d mStartDir;

};



class DllImpExp ZwSphereSurface : public ZwRevolutionSurface
{
public:

    ZwSphereSurface() {}
    ZwSphereSurface(const ZwPoint3d& origin, double radius, int approx, ZwBody*); 
    ZwPoint3d          center   () const { return axis().point; }
    double           radius   () const { return mRadius;      }
    int              approx   () const { return mApprox;      }

    virtual Type     type     () const { return kSphere; }
    virtual ZwSurface* copy     () const { return new ZwSphereSurface(*this); }

    virtual bool     transform(const ZwTransf3d&, 
                               ZwTransf3d::Type  transfType  = ZwTransf3d::kUnknown,
                               const ZwVector3d& stretchVect = ZwVector3d::kNull);

    virtual bool     isEqual  (const ZwSurface*) const;

    virtual bool containsPoint(const ZwPoint3d&) const; 

    virtual ZwCircle3d circle   (const ZwPlane&, const ZwLine3d&) const;
    virtual ZwVector3d normal   (const ZwPoint3d&)              const;

    virtual void     print    (FILE* = NULL)          const;
    virtual void     save     (ZwSaveRestoreCallback*)  const;
    virtual void     restore  (ZwSaveRestoreCallback*);

private:

    double  mRadius;
    int     mApprox;

};



class DllImpExp ZwCylinderSurface : public ZwRevolutionSurface
{
public:

    ZwCylinderSurface() {}
    ZwCylinderSurface(const ZwLine3d& axis, double radius, int approx, ZwBody*);
    ZwCylinderSurface(const ZwLine3d& axis, const ZwVector3d& startDir, double radius, int approx, ZwBody*);

    double           radius   () const { return mRadius;  }
    int              approx   () const { return mApprox;  }

    virtual Type     type     () const { return kCylinder; }
    virtual ZwSurface* copy     () const { return new ZwCylinderSurface(*this); }

    virtual bool     transform(const ZwTransf3d&, 
                               ZwTransf3d::Type  transfType  = ZwTransf3d::kUnknown,
                               const ZwVector3d& stretchVect = ZwVector3d::kNull);

    virtual bool     isEqual  (const ZwSurface*) const;

    virtual bool containsPoint(const ZwPoint3d&) const; 

    virtual ZwCircle3d circle   (const ZwPlane&, const ZwLine3d&) const;
    virtual ZwVector3d normal   (const ZwPoint3d&)              const;

    virtual void     print    (FILE* = NULL)          const;
    virtual void     save     (ZwSaveRestoreCallback*)  const;
    virtual void     restore  (ZwSaveRestoreCallback*);

private:

    double mRadius;
    int    mApprox;

};



class DllImpExp ZwConeSurface : public ZwRevolutionSurface
{
public:

    ZwConeSurface() {}
    ZwConeSurface(const ZwLine3d& axis, double radius1, double radius2, int approx, ZwBody*);

    double           radius   () const { return mRadius;   }
    double           tanAngle () const { return mTanAngle; }
    int              approx   () const { return mApprox;   }
    ZwPoint3d          apex     () const;

    virtual Type     type     () const { return kCone; }
    virtual ZwSurface* copy     () const { return new ZwConeSurface(*this); }

    virtual bool     transform(const ZwTransf3d&, 
                               ZwTransf3d::Type  transfType  = ZwTransf3d::kUnknown,
                               const ZwVector3d& stretchVect = ZwVector3d::kNull);

    virtual bool     isEqual  (const ZwSurface*) const;

    virtual bool containsPoint(const ZwPoint3d&) const; 

    virtual ZwCircle3d circle   (const ZwPlane&, const ZwLine3d&) const;
    virtual ZwVector3d normal   (const ZwPoint3d&)              const;

    virtual void     print    (FILE* = NULL)          const;
    virtual void     save     (ZwSaveRestoreCallback*)  const;
    virtual void     restore  (ZwSaveRestoreCallback*);

private:

    double mRadius;
    double mTanAngle;
    int    mApprox;

};



class DllImpExp ZwTorusSurface : public ZwRevolutionSurface
{
public:
    ZwTorusSurface() {}
    ZwTorusSurface(const ZwLine3d& axis, 
                 double        majRadius, 
                 double        minRadius, 
                 int           majApprox, 
                 int           minApprox, 
                 ZwBody*         b);

    ZwPoint3d          center     () const { return axis().point; }
    double           majorRadius() const { return mMajorRadius; }
    double           minorRadius() const { return mMinorRadius; }
    int              majorApprox() const { return mMajorApprox; }
    int              minorApprox() const { return mMinorApprox; }

    virtual Type     type       () const { return kTorus;   }
    virtual ZwSurface* copy       () const { return new ZwTorusSurface(*this); }

    virtual bool     transform  (const ZwTransf3d&, 
                                 ZwTransf3d::Type  transfType  = ZwTransf3d::kUnknown,
                                 const ZwVector3d& stretchVect = ZwVector3d::kNull);

    virtual bool     isEqual    (const ZwSurface*) const;

    virtual bool containsPoint(const ZwPoint3d&) const; 

    virtual ZwCircle3d circle     (const ZwPlane&, const ZwLine3d&) const;
    virtual ZwVector3d normal     (const ZwPoint3d&)              const;

    virtual void     print      (FILE* = NULL)          const;
    virtual void     save       (ZwSaveRestoreCallback*)  const;
    virtual void     restore    (ZwSaveRestoreCallback*);

private:

    double mMajorRadius;
    double mMinorRadius;
    int    mMajorApprox;
    int    mMinorApprox;

};


AECMODELER_NAMESPACE_END
#endif
