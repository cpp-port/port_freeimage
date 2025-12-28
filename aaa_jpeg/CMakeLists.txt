cmake_minimum_required(VERSION 3.16)
project(jpeg CXX)

if(${WIN32})
    set(CMAKE_DEBUG_POSTFIX "d")
    add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR})
endif ()


list(APPEND library_source
        #ansi2knr.c
        cderror.h
        cdjpeg.c
        cdjpeg.h
        #cjpeg.c
        #ckconfig.c
        #djpeg.c
        #example.c
        jaricom.c
        jcapimin.c
        jcapistd.c
        jcarith.c
        jccoefct.c
        jccolor.c
        jcdctmgr.c
        jchuff.c
        jcinit.c
        jcmainct.c
        jcmarker.c
        jcmaster.c
        jcomapi.c
        jconfig.h
        jcparam.c
        jcprepct.c
        jcsample.c
        jctrans.c
        jdapimin.c
        jdapistd.c
        jdarith.c
        jdatadst.c
        jdatasrc.c
        jdcoefct.c
        jdcolor.c
        jdct.h
        jddctmgr.c
        jdhuff.c
        jdinput.c
        jdmainct.c
        jdmarker.c
        jdmaster.c
        jdmerge.c
        jdpostct.c
        jdsample.c
        jdtrans.c
        jerror.c
        include/jerror.h
        jfdctflt.c
        jfdctfst.c
        jfdctint.c
        jidctflt.c
        jidctfst.c
        jidctint.c
        #jinclude.h
        jmemmgr.c
        #jmemnobs.c
        jmemsys.h
        jmorecfg.h
        jpegint.h
        include/jpeglib.h
        jpegtran.c
        jquant1.c
        jquant2.c
        jutils.c
        jversion.h
        rdbmp.c
        rdcolmap.c
        rdgif.c
        #rdjpgcom.c
        rdppm.c
        rdrle.c
        rdswitch.c
        rdtarga.c
        resource.h
        transupp.c
        #transupp.h
        wrbmp.c
        wrgif.c
        #wrjpgcom.c
        wrppm.c
        wrrle.c
        wrtarga.c

)

if(${LINUX} OR ${ANDROID} OR ${WIN32})
    list(APPEND library_source
        jmemansi.c
    )
elseif(${MSDOS})
    list(APPEND library_source
        jmemdos.c)
elseif(${MACOS})
    list(APPEND library_source
            jmemmac.c)
else()
    list(APPEND library_source
        jmemname.c)
endif()

add_library(${PROJECT_NAME} SHARED ${library_source})


target_compile_definitions(${PROJECT_NAME} PRIVATE OPJ_EXPORTS)

if(MSVC)

    target_compile_definitions(${PROJECT_NAME} PRIVATE JPEG_EXPORTS)

endif()


target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../webp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../jxr/common)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/FreeImage)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating_system/operating_system-${OPERATING_SYSTEM_LOWERED_NAME}/configuration)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating_system/operating_system-${OPERATING_SYSTEM_LOWERED_NAME}/configuration/${PROJECT_NAME})



