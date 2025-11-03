

#pragma once

#include "zdbmain.h"
#include "zacgimaterial.h"

#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbMaterial : public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbMaterial);

    ZcDbMaterial();
    virtual ~ZcDbMaterial();

    virtual Zcad::ErrorStatus   setName (const ZTCHAR * pName);
    virtual const ZTCHAR *       name    (void) const;

    virtual Zcad::ErrorStatus   setDescription(const ZTCHAR * pDescription);
    virtual const ZTCHAR *       description(void) const;

    virtual void setAmbient     (const ZcGiMaterialColor & color);
    virtual void ambient        (ZcGiMaterialColor & color) const;

    virtual void setDiffuse     (const ZcGiMaterialColor & color, 
                                 const ZcGiMaterialMap & map);
    virtual void diffuse        (ZcGiMaterialColor & color, 
                                 ZcGiMaterialMap & map) const;

    virtual void setSpecular    (const ZcGiMaterialColor & color, 
                                 const ZcGiMaterialMap & map,                                
                                 double dGloss);
    virtual void specular       (ZcGiMaterialColor & color, 
                                 ZcGiMaterialMap & map,                                
                                 double & dGloss) const;

    virtual void setReflection  (const ZcGiMaterialMap & map);
    virtual void reflection     (ZcGiMaterialMap & map) const;

    virtual void setOpacity     (double dPercentage, 
                                 const ZcGiMaterialMap & map);
    virtual void opacity        (double & dPercentage, 
                                 ZcGiMaterialMap & map) const;

    virtual void setBump        (const ZcGiMaterialMap & map);
    virtual void bump           (ZcGiMaterialMap & map) const;

    virtual void setRefraction  (double dIndex, 
                                 const ZcGiMaterialMap & map);
    virtual void refraction     (double & dIndex, 
                                 ZcGiMaterialMap & map) const;

    virtual double translucence() const;
    virtual Zcad::ErrorStatus setTranslucence(double value);

    virtual double selfIllumination() const;
    virtual Zcad::ErrorStatus setSelfIllumination(double value);

    virtual double reflectivity() const;
    virtual Zcad::ErrorStatus setReflectivity(double value);

    virtual ZcGiMaterialTraits::IlluminationModel illuminationModel() const;
    virtual Zcad::ErrorStatus setIlluminationModel(ZcGiMaterialTraits::IlluminationModel model);

    virtual ZcGiMaterialTraits::ChannelFlags channelFlags() const;
    virtual Zcad::ErrorStatus setChannelFlags(ZcGiMaterialTraits::ChannelFlags value);

    virtual ZcGiMaterialTraits::Mode mode() const;
    virtual Zcad::ErrorStatus setMode(ZcGiMaterialTraits::Mode value);
    virtual Zcad::ErrorStatus dwgInFields  (ZcDbDwgFiler* pFiler) override;
    virtual Zcad::ErrorStatus dwgOutFields (ZcDbDwgFiler* pFiler) const override;
    virtual Zcad::ErrorStatus dxfInFields  (ZcDbDxfFiler* pFiler) override;
    virtual Zcad::ErrorStatus dxfOutFields (ZcDbDxfFiler* pFiler) const override;
    virtual ZcGiDrawable*     drawable     (void) override;


    double              colorBleedScale         () const;
    Zcad::ErrorStatus   setColorBleedScale      (double value);

    double              indirectBumpScale       () const;
    Zcad::ErrorStatus   setIndirectBumpScale    (double value);

    double              reflectanceScale        () const;
    Zcad::ErrorStatus   setReflectanceScale     (double value);

    double              transmittanceScale      () const;
    Zcad::ErrorStatus   setTransmittanceScale   (double value);

    ZSoft::Boolean      twoSided                () const;
    Zcad::ErrorStatus   setTwoSided             (ZSoft::Boolean value);

    ZcGiMaterialTraits::LuminanceMode luminanceMode () const;
    Zcad::ErrorStatus   setLuminanceMode        (ZcGiMaterialTraits::LuminanceMode value);

    double              luminance               () const;
    Zcad::ErrorStatus   setLuminance            (double value);

    double              shininess               () const;
    Zcad::ErrorStatus   setShininess            (double value);

    Zcad::ErrorStatus   normalMap               (ZcGiMaterialMap & map,
                                                 ZcGiMaterialTraits::NormalMapMethod & method,
                                                 double & strength) const;
    Zcad::ErrorStatus   setNormalMap            (const ZcGiMaterialMap & map,
                                                 ZcGiMaterialTraits::NormalMapMethod method,
                                                 double strength);

    ZSoft::Boolean      isAnonymous             () const;
    Zcad::ErrorStatus   setAnonymous            (ZSoft::Boolean isAnonymous);

    ZcGiMaterialTraits::GlobalIlluminationMode globalIllumination() const;
    void                setGlobalIllumination   (ZcGiMaterialTraits::GlobalIlluminationMode mode);

    ZcGiMaterialTraits::FinalGatherMode        finalGather() const;
    void                setFinalGather          (ZcGiMaterialTraits::FinalGatherMode mode);
	
	bool                isRenamable             () const;

	void* getZwSoftMaterialData();

	Zcad::ErrorStatus setZwSoftMaterialData(const void* pMatObj, bool bCacheIt = false);

	void clearZwSoftMaterialCache();

	enum MaterialFlags {
		kNone               = 0,
		kIsLegacy           = 0x1,
		kIsModifiedIsValid  = 0x2,
		kIsModified         = 0x4,
		kIsModifiedAndValid = 0x6  
	};

	Zcad::ErrorStatus getZwSoftMaterialFlags(MaterialFlags& flags) const;
	Zcad::ErrorStatus setZwSoftMaterialFlags(MaterialFlags flags);
	

protected:
	virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;		
};

#pragma pack (pop)


