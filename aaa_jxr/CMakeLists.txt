cmake_minimum_required(VERSION 3.16)
project(port_jxr CXX)


if(${WIN32})
    #set(CMAKE_DEBUG_POSTFIX "d")
    add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR})
endif ()


list(APPEND library_source
        common/include/guiddef.h
        common/include/wmsal.h
        common/include/wmspecstring.h
        common/include/wmspecstrings_adt.h
        common/include/wmspecstrings_strict.h
        common/include/wmspecstrings_undef.h
        #common/guiddef.h
        common/wmsal.h
        common/wmspecstring.h
        common/wmspecstrings_adt.h
        common/wmspecstrings_strict.h
        common/wmspecstrings_undef.h
        image/x86/x86.h
        image/sys/adapthuff.c
        image/sys/ansi.h
        image/sys/strcodec.h
        image/sys/strTransform.c
        image/sys/xplatform_image.h
        image/sys/strPredQuant.c
        image/sys/strTransform.h
        image/sys/strcodec.c
        image/sys/perfTimerANSI.c
        image/sys/perfTimer.h
        image/sys/common.h
        image/sys/image.c
        image/sys/windowsmediaphoto.h
        image/encode/encode.c
        image/encode/strPredQuantEnc.c
        image/encode/strenc.c
        image/encode/segenc.c
        image/encode/strenc_x86.c
        image/encode/encode.h
        image/encode/strFwdTransform.c
        image/decode/decode.c
        image/decode/segdec.c
        image/decode/strdec_x86.c
        image/decode/decode.h
        image/decode/JXRTranscode.c
        image/decode/strdec.c
        image/decode/strPredQuantDec.c
        image/decode/postprocess.c
        image/decode/strInvTransform.c
        include/jxr/image/sys/windowsmediaphoto.h
        include/jxr/jxrgluelib/JXRGlue.h
        include/jxr/jxrgluelib/JXRMeta.h
        jxrgluelib/JXRGlue.c
        #jxrgluelib/JXRGlue.h
        jxrgluelib/JXRGlueJxr.c
        jxrgluelib/JXRGluePFC.c
        jxrgluelib/JXRMeta.c
        #jxrgluelib/JXRMeta.h
)


add_library(${PROJECT_NAME} SHARED ${library_source})

if(MSVC)
target_compile_definitions(${PROJECT_NAME} PRIVATE OPJ_EXPORTS)
else()
target_compile_definitions(${PROJECT_NAME} PRIVATE __ANSI__)

endif()


if(MSVC)

    set_target_properties(${PROJECT_NAME} PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON )
    target_compile_options(${PROJECT_NAME} PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(${PROJECT_NAME} PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(${PROJECT_NAME} PRIVATE "/IMPLIB:${LIBRARY_OUTPUT_PATH}/${PROJECT_NAME}.lib")
    #    target_link_options(${PROJECT_NAME} PRIVATE "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}.def")
elseif(${LINUX})
    target_compile_definitions(${PROJECT_NAME} PRIVATE LINUX)

endif()



target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../webp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../jxr/common)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../jxr/image/sys)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../port/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/FreeImage)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating_system/operating_system-${OPERATING_SYSTEM_LOWERED_NAME}/configuration/FreeImage)



