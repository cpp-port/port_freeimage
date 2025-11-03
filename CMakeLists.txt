cmake_minimum_required(VERSION 3.16)
project(port_freeimage CXX)


if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR})
endif ()



list(APPEND library_source
        Source/FreeImage/BitmapAccess.cpp
        Source/FreeImage/ColorLookup.cpp
        Source/FreeImage/ConversionRGBA16.cpp
        Source/FreeImage/ConversionRGBAF.cpp
        Source/FreeImage/FreeImage.cpp
        Source/FreeImage/FreeImageC.c
        Source/FreeImage/FreeImageIO.cpp
        Source/FreeImage/GetType.cpp
        Source/FreeImage/LFPQuantizer.cpp
        Source/FreeImage/MemoryIO.cpp
        Source/FreeImage/PixelAccess.cpp
        Source/FreeImage/J2KHelper.cpp
        Source/FreeImage/MNGHelper.cpp
        Source/FreeImage/Plugin.cpp
        Source/FreeImage/PluginBMP.cpp
        Source/FreeImage/PluginCUT.cpp
        Source/FreeImage/PluginDDS.cpp
        Source/FreeImage/PluginEXR.cpp
        Source/FreeImage/PluginG3.cpp
        Source/FreeImage/PluginGIF.cpp
        Source/FreeImage/PluginHDR.cpp
        Source/FreeImage/PluginICO.cpp
        Source/FreeImage/PluginIFF.cpp
        Source/FreeImage/PluginJ2K.cpp
        Source/FreeImage/PluginJNG.cpp
        Source/FreeImage/PluginJP2.cpp
        Source/FreeImage/PluginJPEG.cpp
        Source/FreeImage/PluginJXR.cpp
        Source/FreeImage/PluginKOALA.cpp
        Source/FreeImage/PluginMNG.cpp
        Source/FreeImage/PluginPCD.cpp
        Source/FreeImage/PluginPCX.cpp
        Source/FreeImage/PluginPFM.cpp
        Source/FreeImage/PluginPICT.cpp
        Source/FreeImage/PluginPNG.cpp
        Source/FreeImage/PluginPNM.cpp
        Source/FreeImage/PluginPSD.cpp
        Source/FreeImage/PluginRAS.cpp
        Source/FreeImage/PluginRAW.cpp
        Source/FreeImage/PluginSGI.cpp
        Source/FreeImage/PluginTARGA.cpp
        Source/FreeImage/PluginTIFF.cpp
        Source/FreeImage/PluginWBMP.cpp
        Source/FreeImage/PluginWebP.cpp
        Source/FreeImage/PluginXBM.cpp
        Source/FreeImage/PluginXPM.cpp
        Source/FreeImage/PSDParser.cpp
        Source/FreeImage/TIFFLogLuv.cpp
        Source/FreeImage/Conversion.cpp
        Source/FreeImage/Conversion16_555.cpp
        Source/FreeImage/Conversion16_565.cpp
        Source/FreeImage/Conversion24.cpp
        Source/FreeImage/Conversion32.cpp
        Source/FreeImage/Conversion4.cpp
        Source/FreeImage/Conversion8.cpp
        Source/FreeImage/ConversionFloat.cpp
        Source/FreeImage/ConversionRGB16.cpp
        Source/FreeImage/ConversionRGBF.cpp
        Source/FreeImage/ConversionType.cpp
        Source/FreeImage/ConversionUINT16.cpp
        Source/FreeImage/Halftoning.cpp
        Source/FreeImage/tmoColorConvert.cpp
        Source/FreeImage/tmoDrago03.cpp
        Source/FreeImage/tmoFattal02.cpp
        Source/FreeImage/tmoReinhard05.cpp
        Source/FreeImage/ToneMapping.cpp
        Source/FreeImage/NNQuantizer.cpp
        Source/FreeImage/WuQuantizer.cpp
        Source/DeprecationManager/Deprecated.cpp
        Source/DeprecationManager/DeprecationMgr.cpp
        Source/FreeImage/CacheFile.cpp
        Source/FreeImage/MultiPage.cpp
        Source/FreeImage/ZLibInterface.cpp
        Source/Metadata/Exif.cpp
        Source/Metadata/FIRational.cpp
        Source/Metadata/FreeImageTag.cpp
        Source/Metadata/IPTC.cpp
        Source/Metadata/TagConversion.cpp
        Source/Metadata/TagLib.cpp
        Source/Metadata/XTIFF.cpp
        Source/FreeImageToolkit/Background.cpp
        Source/FreeImageToolkit/BSplineRotate.cpp
        Source/FreeImageToolkit/Channels.cpp
        Source/FreeImageToolkit/ClassicRotate.cpp
        Source/FreeImageToolkit/Colors.cpp
        Source/FreeImageToolkit/CopyPaste.cpp
        Source/FreeImageToolkit/Display.cpp
        Source/FreeImageToolkit/Flip.cpp
        Source/FreeImageToolkit/JPEGTransform.cpp
        Source/FreeImageToolkit/MultigridPoissonSolver.cpp
        Source/FreeImageToolkit/Rescale.cpp
        Source/FreeImageToolkit/Resize.cpp
        Source/CacheFile.h
        Source/DeprecationManager/DeprecationMgr.h
        Source/MapIntrospector.h
        Source/Metadata/FIRational.h
        Source/FreeImage.h
        Source/FreeImageIO.h
        Source/Metadata/FreeImageTag.h
        Source/FreeImage/J2KHelper.h
        Source/Plugin.h
        Source/FreeImage/PSDParser.h
        Source/Quantizers.h
        Source/ToneMapping.h
        Source/Utilities.h
        Source/FreeImageToolkit/Resize.h

        Source/FreeImage/jxr_init_guid.c
)


if(${HAS_SYSTEM_JPEG})
    set(jpeg_library jpeg)
else()
    set(jpeg_library port_jpeg)
endif()


list(APPEND library_references
        ${jpeg_library}
        port_jxr
        port_openexr
        port_openjpeg
        port_png
        port_tiff4
        port_rawlite
        port_webp
)


if(${LINUX} OR ${OPENBSD})
    list(APPEND library_references z)
else()
    list(APPEND library_references zlib)
endif()


add_library(${PROJECT_NAME} SHARED ${library_source})


target_compile_definitions(${PROJECT_NAME} PRIVATE HAVE_CONFIG_H)

if(MSVC)
    target_compile_definitions(${PROJECT_NAME} PRIVATE OPENEXR_DLL)
    target_compile_definitions(${PROJECT_NAME} PRIVATE FREEIMAGE_EXPORTS)
    list(APPEND library_references Windowscodecs)
endif()

target_link_libraries(${PROJECT_NAME} ${library_references})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../webp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../jxr/common)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/FreeImage)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../port/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating_system/operating_system-${OPERATING_SYSTEM_LOWERED_NAME}/configuration)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating_system/operating_system-${OPERATING_SYSTEM_LOWERED_NAME}/configuration/jpeg)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating_system/operating_system-${OPERATING_SYSTEM_LOWERED_NAME}/configuration/${PROJECT_NAME})

#add_library(${PROJECT_NAME}_static STATIC ${ZLIB_SRCS} ${ZLIB_ASMS} ${ZLIB_PUBLIC_HDRS} ${ZLIB_PRIVATE_HDRS})
set_target_properties(${PROJECT_NAME} PROPERTIES DEFINE_SYMBOL FREEIMAGE_DLL)
#set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION 1)


