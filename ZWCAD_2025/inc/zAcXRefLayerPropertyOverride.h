

#pragma once

class ZCDBCORE2D_PORT ZcXRefLayerPropertyOverride
{
public:

    enum XRefLayerPropertyOverrideType
    {
        On           = 0,    
        Freeze       = 1,    
        Lock         = 2,    
        Plot         = 3,    
        Color        = 4,    
        Linetype     = 5,    
        Lineweight   = 6,    
        Transparency = 7,    
        PlotStyle    = 8,    
        NewVPFreeze  = 9,    
        Description  = 10    
    };

    static bool hasXRefLayerOverride(const ZcDbObjectId& hostLayerId, XRefLayerPropertyOverrideType property);

    static bool hasAnyXRefLayerOverrides(const ZcDbObjectId& hostLayerId);

    static bool hasAnyXRefLayerOverrides(ZcDbDatabase* pHostDb);

    static bool hasXRefLayerOverride(ZcDbBlockReference* pRef);

    static Zcad::ErrorStatus addXRefLayerOverride(const ZcDbObjectId& hostLayerId, XRefLayerPropertyOverrideType property);

    static Zcad::ErrorStatus removeXRefLayerOverride(const ZcDbObjectId& hostLayerId, XRefLayerPropertyOverrideType property);
	static Zcad::ErrorStatus removeXRefLayerOverride(ZcDbDatabase* pHostDb, XRefLayerPropertyOverrideType property);
    static Zcad::ErrorStatus removeXRefLayerOverrides(const ZcDbObjectId& hostLayerId);
    static Zcad::ErrorStatus removeXRefLayerOverrides(ZcDbDatabase* pHostDb);

    static void enableXRefLayerPropertyOverrideRecording();

    static void disableXRefLayerPropertyOverrideRecording();

    static bool isXRefLayerPropertyOverrideRecordingEnabled();

};

