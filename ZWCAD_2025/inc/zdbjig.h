

#ifndef   _ZDBJIG_H_
#define   _ZDBJIG_H_ 1

#if defined(__cplusplus)
#include "zAcCoreDefs.h"

#include "zdbdimdata.h"  

#pragma pack (push, 8)

class	ZcEdImpJig;
class	ZcDbEntity;
class ZcEdImpDragStyle;
class ZcGePoint3d;
class ZcGiVisualStyle;
class ZcEdDragStyle;
class ZcEdJigInputHelper;


class ZCCORE_PORT ZcEdJig: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcEdJig);

    enum UserInputControls {
	kGovernedByOrthoMode	    = 0x000001,
	kNullResponseAccepted		= 0x000002,
	kDontEchoCancelForCtrlC		= 0x000004,
	kDontUpdateLastPoint		= 0x000008,
	kNoDwgLimitsChecking		= 0x000010,
	kNoZeroResponseAccepted		= 0x000020,
	kNoNegativeResponseAccepted	= 0x000040,
	kAccept3dCoordinates		= 0x000080,
	kAcceptMouseUpAsPoint		= 0x000100,
	kAnyBlankTerminatesInput	= 0x000200,
	kInitialBlankTerminatesInput	= 0x000400,
	kAcceptOtherInputString		= 0x000800,
    kGovernedByUCSDetect        = 0x001000,
    kNoZDirectionOrtho          = 0x002000,
	kImpliedFaceForUCSChange    = 0x004000,
	kUseBasePointElevation      = 0x008000,
	kDisableDirectDistanceInput     = 0x010000,
	};

    enum DragStatus {
        kModeless       = -17,
        kNoChange       = -6,
        kCancel         = -4,
        kOther          = -3,
        kNull           = -1,
        kNormal         = 0,
	kKW1,
	kKW2,
	kKW3,
	kKW4,
	kKW5,
	kKW6,
	kKW7,
	kKW8,
	kKW9
    };

    enum CursorType {
	kNoSpecialCursor = -1,           
	kCrosshair = 0,                  
	kRectCursor,                     
	kRubberBand,                     
	kNotRotated,                     
	kTargetBox,                      
	kRotatedCrosshair,               
	kCrosshairNoRotate,              
	kInvisible,                      
	kEntitySelect,                   
	kParallelogram,                  
	kEntitySelectNoPersp,            
	kPkfirstOrGrips,
    kCrosshairDashed
    };

    ZcEdJig();
    virtual ~ZcEdJig();

    DragStatus	drag();
	DragStatus drag ( const ZcEdDragStyle& style );	
    virtual DragStatus	sampler(); 
    virtual ZSoft::Boolean  update();
    ZcDbObjectId append();

    const ZTCHAR* keywordList();
    void        setKeywordList(const ZTCHAR*);

    const ZTCHAR* dispPrompt();
    void        setDispPrompt(const ZTCHAR*, ...);

    DragStatus acquireString(ZcString& s);

    DragStatus acquireString(ZTCHAR (&str)[2049]);	
    DragStatus acquireAngle(double &ang);
    DragStatus acquireAngle(double &ang, const ZcGePoint3d& basePnt);
    DragStatus acquireDist(double &dist);
    DragStatus acquireDist(double &dist, const ZcGePoint3d& basePnt);
    DragStatus acquirePoint(ZcGePoint3d&);
    DragStatus acquirePoint(ZcGePoint3d&, const ZcGePoint3d&basePnt);

    ZcEdJig::CursorType specialCursorType();
    void                setSpecialCursorType(CursorType);

    ZcEdJig::UserInputControls userInputControls();
    void                       setUserInputControls(ZcEdJig::UserInputControls);

    virtual ZcDbEntity* entity() const;
    virtual ZcDbDimDataPtrArray * dimData(const double dimScale);
    virtual Zcad::ErrorStatus setDimValue(const ZcDbDimData* dimData,
                                          const double dimValue); 

protected:
    ZcEdImpJig*  mpImpJig;
    friend class ZcEdJigInputHelper;
};

class ZCCORE_PORT ZcEdDragStyle
{
public:

	enum StyleType
	{
		kNone = 0, 
		kHide,
		kTransparent25,
		kTransparent75,
		kDeletedEffect,
		kHighlight,
		kNotSet,
        kOpacity
	};

	ZcEdDragStyle  ();
	ZcEdDragStyle  ( StyleType styleTypeForOriginal, StyleType styleTypeForDragged );
	ZcEdDragStyle  ( const ZcEdDragStyle& dragStyle );

	~ZcEdDragStyle ();

	StyleType             styleTypeForOriginal () const;

	StyleType             styleTypeForDragged () const;

	Zcad::ErrorStatus     setStyleTypeForOriginal ( StyleType styleType );

	Zcad::ErrorStatus     setStyleTypeForDragged ( StyleType styleType );

	ZcEdDragStyle&  operator = ( const ZcEdDragStyle& src );


	bool operator == ( const ZcEdDragStyle& other ) const;
	bool operator != ( const ZcEdDragStyle& other ) const;

private:
	ZcEdImpDragStyle  *mpOriginalDragStyle;
	ZcEdImpDragStyle  *mpDraggedDragStyle;

	friend class ZcEdImpDragStyle;
};


#pragma pack (pop)
#endif 
#endif
