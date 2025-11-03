

#ifndef ZGEOMENT_DBBODY_H
#define ZGEOMENT_DBBODY_H

#include "zdbmain.h"
#include "zdbsubeid.h"

#pragma pack (push, 8)

class ZCDB_PORT ZcDbBody: public  ZcDbEntity
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbBody);
	     ZcDbBody();
    virtual ~ZcDbBody();

    virtual ZSoft::Boolean    isNull       () const;

	virtual void	  dragStatus(const ZcDb::DragStat) override;
	virtual void*             ZSMBodyCopy(bool bDeepCopy = false) const; 
	virtual void const *      getLockedZSMBody();                        
	virtual void              unlockZSMBody();                           
	virtual void*             getLockedWritableZSMBody();                
	virtual void              commitWritableZSMBody();                   
	virtual Zcad::ErrorStatus setZSMBody      (const void* modelerBody); 


    virtual ZcDbSubentId    internalSubentId (void*) const;                   
    virtual void*           internalSubentPtr(const ZcDbSubentId& id) const;  

    static  Zcad::ErrorStatus acisOut      (const ZTCHAR* fileName,
					    const ZcDbVoidPtrArray&);
    static  Zcad::ErrorStatus acisIn       (const ZTCHAR* fileName,
					    ZcDbVoidPtrArray&);

    virtual ZSoft::UInt32 numChanges() const;
	virtual bool usesGraphicsCache();

    void invalidateCachedBodySubentIds();
};

#pragma pack (pop)

#endif
