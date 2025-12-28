cmake_minimum_required(VERSION 3.16)
project(rawlite CXX)


if(${WIN32})
    #set(CMAKE_DEBUG_POSTFIX "d")
    add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR})
endif ()

list(APPEND library_source
        dcraw/dcraw.c
        #internal/aahd_demosaic.cpp
        #internal/dcb_demosaicing.c
        internal/dcraw_common.cpp
        internal/dcraw_fileio.cpp
        internal/defines.h
        internal/demosaic_packs.cpp
        #internal/dht_demosaic.cpp
        internal/libraw_internal_funcs.h
        #internal/libraw_x3f.cpp
        #internal/preprocess.pl
        internal/var_defines.h
        #internal/wf_filtering.cpp
        src/libraw_c_api.cpp
        src/libraw_cxx.cpp
        src/libraw_datastream.cpp

)


add_library(${PROJECT_NAME} SHARED ${library_source})

target_compile_options(${PROJECT_NAME} PRIVATE -Wno-c++11-narrowing)

target_compile_definitions(${PROJECT_NAME} PRIVATE NO_JASPER LIBRAW_NOTHREADS)

if(MSVC)
    target_compile_definitions(${PROJECT_NAME} PRIVATE LIBRAW_BUILDLIB)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE jpeg)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../webp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../jxr/common)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/FreeImage)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating_system/operating_system-${OPERATING_SYSTEM_LOWERED_NAME}/configuration/${PROJECT_NAME})



