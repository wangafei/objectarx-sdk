
#include "zacdb.h"
#include "zdbmain.h"

#pragma once
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbDynamicUCSPE	: public ZcRxObject
{
public:
    enum Flags {
        kDefault     = 0x00,
    };

	ZCRX_DECLARE_MEMBERS(ZcDbDynamicUCSPE);
    virtual Zcad::ErrorStatus
        getCandidatePlanes(ZcArray<ZcGePlane>& results,
                            double &distToEdge,
                            double &objWidth,
                            double &objHeight,
                            ZcDbEntity* pEnt,
                            const ZcDbSubentId& subentId,
                            const ZcGePlane& viewplane,
                            ZcDbDynamicUCSPE::Flags flags = kDefault
                            ) const = 0;
};


class CPoint;
class ZcDbNonSubEntDynamicUCSPE : public ZcRxObject
{
public:
	ZCRX_DECLARE_MEMBERS_EXPIMP(ZcDbNonSubEntDynamicUCSPE, ZCDBCORE2D_PORT);

	virtual Zcad::ErrorStatus
		getCandidatePlane(
		ZcDbEntity* Ent,   
		const CPoint& pt,        
		ZcGePlane &result,       
		double &distToEdge,      
		double &objWidth,        
		double &objHeight,       
		void*& context           
		) = 0;

	virtual Zcad::ErrorStatus
		highlightPlane(
		ZcDbEntity* Ent,   
		void* context            
		) = 0;


	virtual Zcad::ErrorStatus
		dehighlightPlane(
		ZcDbEntity* Ent,   
		void* context            
		) = 0;
};


#pragma pack (pop)


