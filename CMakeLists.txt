# Cmake script for project AddIn
# autor: 1C
cmake_minimum_required (VERSION 2.8.12)

if (MSVC)
    set(CMAKE_VS_PLATFORM_TOOLSET "v120_xp" GLOBAL)
endif(MSVC)

project (AddIn)
#-----------------------------------------------------------------------------
# Minimum compiler version check: Microsoft C/C++ >= 18.0 (aka VS 2013 aka VS 12.0)
if (MSVC AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 18.0)
  message(FATAL_ERROR "Microsoft Visual Studio 2013 or later is required.")
endif ()
if (MSVC)
    set(CMAKE_VS_PLATFORM_TOOLSET "v120_xp" CACHE "STRING" "Compilator toolset" FORCE)
    foreach(flag
        CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
        CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO
        CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
        if(${flag} MATCHES "/MD")
            string(REGEX REPLACE "/MD" "/MT" ${flag} "${${flag}}")
            set(${flag} ${${flag}} CACHE "STRING" "Compilation flags" FORCE)
        endif()
    endforeach()
endif()
OPTION(TARGET_PLATFORM_32 "Build target for i386" ON)
MARK_AS_ADVANCED(TARGET_PLATFORM_32)
#-----------------------------------------------------------------------------
# Minimum compiler version check: GCC >= 4.8
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND
    CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.8)
  message(FATAL_ERROR "GCC 4.8 or later is required.")
endif ()

message(STATUS "System: " ${CMAKE_SYSTEM_NAME} " " ${CMAKE_SYSTEM_VERSION})
message(STATUS "Processor: " ${CMAKE_HOST_SYSTEM_PROCESSOR})

if (NOT UNIX)
    IF(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
       SET(CMAKE_BUILD_TYPE Release CACHE "STRING" "Compilator type" FORCE)
    ENDIF(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)   
endif(NOT UNIX)

if (UNIX)
    set(MySuffix1 "Lin")
    if (APPLE)
        set(MySuffix1 "Mac")
    endif(APPLE)
else(UNIX)
    set(MySuffix1 "Win")
endif(UNIX)

set(BUILD_DIR "build")
set(CMAKE_SKIP_RPATH ON CACHE "BOOL" "" FORCE)

if (TARGET_PLATFORM_32)
    set(MySuffix2 "32")
    if (UNIX)
        set (CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -m32" CACHE "STRING" "Linker flags" FORCE)
        set (CMAKE_MODULE_LINKER_FLAGS  "${CMAKE_MODULE_LINKER_FLAGS} -m32" CACHE "STRING" "Linker flags" FORCE)
        set (CMAKE_SHARED_LINKER_FLAGS  "${CMAKE_SHARED_LINKER_FLAGS} -m32" CACHE "STRING" "Linker flags" FORCE)
        set (CMAKE_STATIC_LINKER_FLAGS  "${CMAKE_STATIC_LINKER_FLAGS} -m32" CACHE "STRING" "Linker flags" FORCE)
        set (CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -m32" CACHE "STRING" "Linker flags" FORCE)
        set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -m32" CACHE "STRING" "Linker flags" FORCE)
    endif()
    if (NOT UNIX)
        #set(CMAKE_EXE_LINKER_FLAGS "/machine:x86")
    endif()
else()
    set(MySuffix2 "64")
    if (UNIX)
        set (CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -m64" CACHE "STRING" "Linker flags" FORCE)
        set (CMAKE_MODULE_LINKER_FLAGS  "${CMAKE_MODULE_LINKER_FLAGS} -m64" CACHE "STRING" "Linker flags" FORCE)
        set (CMAKE_SHARED_LINKER_FLAGS  "${CMAKE_SHARED_LINKER_FLAGS} -m64" CACHE "STRING" "Linker flags" FORCE)
        set (CMAKE_STATIC_LINKER_FLAGS  "${CMAKE_STATIC_LINKER_FLAGS} -m64" CACHE "STRING" "Linker flags" FORCE)
        set (CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -m64" CACHE "STRING" "Linker flags" FORCE)
        set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -m64" CACHE "STRING" "Linker flags" FORCE)
    endif()
    if (NOT UNIX)
        #set(CMAKE_EXE_LINKER_FLAGS "/machine:x64")
    endif()
endif()

set (LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set (EXECUTABLE_OUTPUT_PATH ${LIBRARY_OUTPUT_PATH})

include_directories(BEFORE  . ${CMAKE_SOURCE_DIR}../include)

if (WIN32)
    add_subdirectory(COM)
endif (WIN32)
