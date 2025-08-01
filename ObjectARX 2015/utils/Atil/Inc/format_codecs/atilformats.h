//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2014 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form.   
//
//////////////////////////////////////////////////////////////////////////////



#ifndef ATILDEFS_H
#include "AtilDefs.h"
#endif

#ifndef IMAGEFORMATCODEC_H
namespace Atil { class ImageFormatCodec; }
#endif
#ifndef FORMATCODECAPIVERSIONINTERFACE_H
namespace Atil { class FormatCodecApiVersionInterface; }
#endif
#ifndef PROPERTYSTRINGPROVIDERINTERFACE_H
namespace Atil { class PropertyStringProviderInterface; }
#endif


#ifndef ATILFORMATS_H
#define ATILFORMATS_H

/// <summary>
/// This structure serves the same purpose as a namespace for gathering the
/// exported utility functions of the library.
/// </summary>
///
struct AtilFormatCodecLibrary
{
    /// <summary> An enum listing the formats supported in this library. </summary>
    enum AvailableFormats { 
        /// <summary> JPEG </summary>
        kJfif, 
        /// <summary> PNG </summary>
        kPng, 
        /// <summary> TIFF </summary>
        kTiff, 
        /// <summary> Windows BMP/DIB </summary>
        kBmp, 
        /// <summary> CALS </summary>
        kCals, 
        /// <summary> GeoSpot </summary>
        kSpot,
        /// <summary> ImageSystems IG4 (deprecated) </summary>
        kIg4,
        /// <summary> Mac PICT </summary>
        kPict,
        /// <summary> ImageSystems RLC (deprecated) </summary>
        kRlc, 
        /// <summary> Targa </summary>
        kTarga,
        /// <summary> PCX </summary>
        kPcx,
        /// <summary> Autodesk Animator (deprecated) </summary>
        kFlic,
        /// <summary> GIF </summary>
        kGif,
        /// <summary> QuickBird Multispectral TIFF </summary>
        kQBTIFF,
        /// <summary> ESRI ASCII Grid </summary>
        kAAIGrid,
        /// <summary> ESRI Binary Grid </summary>
        kBAIGrid,
        /// <summary> Direct Show </summary>
        kDDS,
        /// <summary> Digital Elevation Model </summary>
        kDem,
        /// <summary> USGS Quad Sheets </summary>
        kDoq,
        /// <summary> US Armed forces Elevation data </summary>
        kDted,
        /// <summary> ERDAS ER Mapper </summary>
        kECW,
        /// <summary> ILM Open EXR Format </summary>
        kOpenEXR,
        /// <summary> USGS FAST Satellite Format </summary>
        kFAST,
        /// <summary> High Dynamic Range Format </summary>
        kHDR,
        /// <summary> JPEG 2000 </summary>
        kJp2,
        /// <summary> National Image Transfer Format </summary>
        kNITF,
        /// <summary> Adobe Photoshop Format </summary>
        kPsd,
        /// <summary> LizardTech SID format </summary>
        kSid,
    };

    /// <summary>
    /// Retrieve the number of codecs that are within the library.
    /// </summary>
    ///
    /// <returns>
    /// The number of codecs;
    /// </returns>
    ///
    static int numberOfCodecs ();

    /// <summary>
    /// Retrieve the version of the codec at the virtual array index;
    /// </summary>
    ///
    /// <param name='nCodec'> The index of the codec.
    /// </param>
    /// 
    /// <returns>
    /// The codec version class instance is return. 
    /// </returns>
    ///
    static const Atil::FormatCodecApiVersionInterface* getFormatCodecApiVersion (int nCodec);

    /// <summary>
    /// Load the cocec and return a pointer to it at the virtual array index;
    /// </summary>
    ///
    /// <param name='nCodec'> The index of the codec.
    /// </param>
    /// 
    /// <returns>
    /// The codec loaded. The pointer should NOT be deleted.
    /// </returns>
    ///
    static Atil::ImageFormatCodec* loadFormatCodec ( int nCodec );

    /// <summary>
    /// Unload the cocec and return a pointer to it at the virtual array index;
    /// </summary>
    ///
    /// <param name='nCodec'> The index of the codec.
    /// </param>
    /// 
    static void unloadFormatCodec ( int nCodec );

    /// <summary> 
    /// This allows easier access to a specific format. i.e. TIFF == kTiff
    /// The returned pointer should not be deleted. It is owned by the AtilFormatCodecLibrary;
    /// </summary>
    ///
    /// <param name='cdc'> A member of the <c>AvalailableFormats</c> enum indicating
    /// the codec that should be returned.
    /// </param>
    ///
    /// <returns>
    /// This method returns a pointer to an instance of the requested codec.
    /// This pointer can be used in reading or writing files. 
    /// The pointer should not be deleted. It is the pointer held by the class.
    /// </returns>
    ///
    static Atil::ImageFormatCodec* getFormatCodec (AvailableFormats cdc);

    /// <summary> 
    /// This allows easier access to a specific format. i.e. TIFF == kTiff
    /// </summary>
    ///
    /// <param name='cdc'> A member of the <c>AvalailableFormats</c> enum indicating
    /// the codec that should be returned.
    /// </param>
    ///
    /// <returns>
    /// This method returns a const pointer to the version information of a codec.
    /// </returns>
    ///
    static const Atil::FormatCodecApiVersionInterface* findFormatCodecApiVersion (AvailableFormats cdc);

    /// <summary>
    /// This will tell you the index of the passed in format in the array of
    /// available formats.
    /// </summary>
    ///
    /// <param name='cdc'> A member of the <c>AvalailableFormats</c> enum indicating
    /// the codec that should be returned.
    /// </param>
    ///
    /// <returns>
    /// This method the index in the virtual array.
    /// </returns>
    ///
    static int getFormatPosition ( AvailableFormats cdc );

    /// <summary>
    /// This allows the path of a dll (on Windows) that hold the resources
    /// from which the library should reference for it's strings.
    /// </summary>
    ///
    /// <param name='pResourceFile'> A const pointer to a string array that is the
    /// path to the file.
    /// </param>
    /// 
    static void setResourceFileName ( const Atil::char_t* pResourceFile );

    /// <summary>
    /// Some codecs have restrictions placed on their encoding schemes.
    /// Most famously this turned on an off LZW. That has since expired and
    /// now these default to ON.
    /// </summary>
    ///
    /// <param name='bTurnOnRead'> Enable reading of patented encoding schemes (LZW)
    /// </param>
    /// 
    /// <param name='bTurnOnWrite'> Enable writing of patented encoding schemes (LZW)
    /// </param>
    /// 
    static void setPatentedEncodingSupportEnabled ( bool bTurnOnRead, bool bTurnOnWrite );
    
    /// <summary> This is a way to map ATIL Property strings into client applications.
    /// See <c>PropertyStringProviderInterface.h</c></summary>
    ///
    /// <param name='pcProvider'> An instance of a class API providing strings based on Id</param>
    static void registerPropertyStringProvider(Atil::PropertyStringProviderInterface const* pcProvider );
};

#endif
