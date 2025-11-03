
#ifndef ZMODELER_INC_CURVE_H
#define ZMODELER_INC_CURVE_H

#include "zentity.h"
#include "zcircle3d.h"
#include "ztransf3d.h"

AECMODELER_NAMESPACE_BEGIN


class DllImpExp ZwCurve : public ZwEntity
{
public:
    ZwCurve(ZwBody* pBody = NULL);

    enum Type { kUnspecified, kCircle };

    virtual Type       type     () const = NULL;
    virtual ZwCurve*   copy     () const = NULL;

    virtual bool       transform(const ZwTransf3d&, ZwTransf3d::Type  transfType  = ZwTransf3d::kUnknown, const ZwVector3d& stretchVect = ZwVector3d::kNull) = NULL;

    virtual void       print    (FILE* = NULL)         const = NULL;
    virtual void       save     (ZwSaveRestoreCallback*) const;
    virtual void       restore  (ZwSaveRestoreCallback*)       {}

    ZwCurve*           next     () const     { return mpNext; }
    void               setNext  (ZwCurve* c)   { mpNext = c;    }

    ZwCurve* cptr;
    int    n; 

private:

    ZwCurve* mpNext; 

}; 



class DllImpExp ZwUnspecifiedCurve : public ZwCurve
{
public:

    ZwUnspecifiedCurve(ZwBody* b = NULL) : ZwCurve(b) {}
    
    virtual Type     type     () const { return kUnspecified; }
    virtual ZwCurve*   copy     () const { return new ZwUnspecifiedCurve(*this); }
    virtual void     print    (FILE* = NULL) const;

    virtual bool     transform(const ZwTransf3d&,
                               ZwTransf3d::Type  /*transfType*/  = ZwTransf3d::kUnknown,
                               const ZwVector3d& /*stretchVect*/ = ZwVector3d::kNull)
    { return true; }

};



class DllImpExp ZwCircleCurve : public ZwCurve
{
public:

    ZwCircleCurve() {}
    ZwCircleCurve(const ZwCircle3d&, int approx, ZwBody*); 

    const ZwTransf3d&  transf   () const { return mTransf;          }
    ZwPoint3d          origin   () const { return mTransf.origin(); }
    ZwLine3d           axis     () const;
    double             radius   () const { return mRadius; }
    int                approx   () const { return mApprox; }
    ZwCircle3d         circle   () const { return ZwCircle3d(axis(), mRadius); }

    virtual Type     type     () const { return kCircle; }
    virtual ZwCurve*   copy     () const { return new ZwCircleCurve(*this); }

    virtual bool     transform(const ZwTransf3d&, ZwTransf3d::Type transfType = ZwTransf3d::kUnknown, const ZwVector3d& stretchVect = ZwVector3d::kNull);
    virtual void     print    (FILE* = NULL) const;
    virtual void     save     (ZwSaveRestoreCallback*) const;
    virtual void     restore  (ZwSaveRestoreCallback*);

private:

    ZwTransf3d mTransf;
    double   mRadius;
    int      mApprox;

}; 



AECMODELER_NAMESPACE_END
#endif
