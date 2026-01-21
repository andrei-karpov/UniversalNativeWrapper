cmake_minimum_required(VERSION 3.18...3.31 FATAL_ERROR)

if (NOT WIN32)
    message(FATAL_ERROR "Поддерживается только Windows.")
endif()

project(UniversalNativeWrapper LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

set(MIDL_OUTPUT
    ${CMAKE_CURRENT_BINARY_DIR}/AddIn_i.h
    ${CMAKE_CURRENT_BINARY_DIR}/AddIn_i.c
    ${CMAKE_CURRENT_BINARY_DIR}/AddIn.tlb
)

set(TYPELIB_PATH "${CMAKE_CURRENT_BINARY_DIR}/AddIn.tlb")
configure_file(${SRC_DIR}/AddIn.rc.in ${CMAKE_CURRENT_BINARY_DIR}/AddIn.rc @ONLY)

add_custom_command(
    OUTPUT ${MIDL_OUTPUT}
    COMMAND midl /h ${CMAKE_CURRENT_BINARY_DIR}/AddIn_i.h
        /iid ${CMAKE_CURRENT_BINARY_DIR}/AddIn_i.c
        /tlb ${CMAKE_CURRENT_BINARY_DIR}/AddIn.tlb
        ${SRC_DIR}/AddIn.idl
    WORKING_DIRECTORY ${SRC_DIR}
    MAIN_DEPENDENCY ${SRC_DIR}/AddIn.idl
    BYPRODUCTS ${MIDL_OUTPUT}
    VERBATIM
)

add_library(${PROJECT_NAME} SHARED
    ${SRC_DIR}/AddInCOM.cpp
    ${SRC_DIR}/AddInCOM.h
    ${SRC_DIR}/AddIn.cpp
    ${SRC_DIR}/dllmain.cpp
    ${SRC_DIR}/dlldatax.c
    ${SRC_DIR}/stdafx.cpp
    ${SRC_DIR}/MyMemoryManager.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/AddIn.rc
    ${SRC_DIR}/AddIn.rgs
    ${SRC_DIR}/AddInCOM.rgs
    ${SRC_DIR}/AddIn.def
    ${MIDL_OUTPUT}
)

set_source_files_properties(${CMAKE_CURRENT_BINARY_DIR}/AddIn.rc
    PROPERTIES OBJECT_DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/AddIn.tlb")

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    WIN32
    UNICODE
    _UNICODE
    _USRDLL
    _CRT_SECURE_NO_WARNINGS
)

target_link_libraries(${PROJECT_NAME} PRIVATE rpcrt4 oleaut32)

if (MSVC)
    target_link_options(${PROJECT_NAME} PRIVATE "/DEF:${SRC_DIR}/AddIn.def")
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
    PREFIX ""
)
