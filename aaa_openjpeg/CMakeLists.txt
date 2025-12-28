cmake_minimum_required(VERSION 3.16)
project(port_openjpeg CXX)

if(${WIN32})
    set(CMAKE_DEBUG_POSTFIX "d")
    add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR})
endif ()


list(APPEND library_source
        bio.c
        cidx_manager.c
        cio.c
        dwt.c
        event.c
        function_list.c
        image.c
        invert.c
        j2k.c
        jp2.c
        mct.c
        mqc.c
        openjpeg.c
        opj_clock.c
        phix_manager.c
        pi.c
        ppix_manager.c
        raw.c
        t1.c
        t1_generate_luts.c
        t2.c
        tcd.c
        tgt.c
        thix_manager.c
        tpix_manager.c
)


add_library(${PROJECT_NAME} SHARED ${library_source})


target_compile_definitions(${PROJECT_NAME} PRIVATE OPJ_EXPORTS)


target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../webp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../jxr/common)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/FreeImage)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating_system/operating_system-${OPERATING_SYSTEM_LOWERED_NAME}/configuration/FreeImage)



