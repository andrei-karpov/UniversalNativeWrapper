# Cmake script for project AddInCOM
# autor: 1C

CMAKE_MINIMUM_REQUIRED(VERSION 2.8.0 FATAL_ERROR)

PROJECT(AddInCOM)

SET(AddInIE_SRC 
    AddIn.cpp
    AddIn.rc
    AddIn.rgs
    AddInCOM.cpp
    AddInCOM.h
    AddInCOM.rgs
    dlldatax.c
    dlldatax.h
    dllmain.cpp
    dllmain.h
    resource.h
    stdafx.cpp
    stdafx.h
    targetver.h
    )
set_source_files_properties(AddInCOM.rgs AddIn.rgs PROPERTIES HEADER_FILE_ONLY TRUE)

set(MIDL_OUTPUT
    ${CMAKE_CURRENT_BINARY_DIR}/AddIn_i.h
    ${CMAKE_CURRENT_BINARY_DIR}/AddIn_i.c
    )
set(MIDL_FILE
    ${CMAKE_CURRENT_LIST_DIR}/AddIn.idl
    )
add_custom_command(
    OUTPUT ${MIDL_OUTPUT}
    COMMAND midl /h AddIn_i.h /iid AddIn_i.c /proxy AddIn_p.c /dlldata dlldata.c /amd64 ${MIDL_FILE}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS ${MIDL_FILE}
    VERBATIM
    )
add_custom_target(midl-com
    DEPENDS ${MIDL_OUTPUT}
    )

set_source_files_properties(${MIDL_OUTPUT} PROPERTIES  GENERATED TRUE )

IF (UNIX)
    MESSAGE(FATAL_ERROR "Must Windows only")
ELSE()
    ADD_DEFINITIONS(-DWIN32 -DUNICODE )
    SET(AddInIEDef_SRC AddIn.def)
    SET(CMAKE_LINK_DEF_FILE_FLAG AddIn.def)
ENDIF()

SET(CMAKE_LIBRARY_PATH ${CMAKE_SOURCE_DIR}/../lib)
LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/../lib)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/../include)

add_library(${PROJECT_NAME} SHARED ${AddInIE_SRC} ${MIDL_OUTPUT} ${AddInIEDef_SRC})
add_dependencies(${PROJECT_NAME}  midl-com)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} RpcRT4.lib oleaut32.lib)

SET_TARGET_PROPERTIES( ${PROJECT_NAME} PROPERTIES
    PREFIX ""
   CLEAN_DIRECT_OUTPUT 1
   OUTPUT_NAME ${PROJECT_NAME}${MySuffix2} 
   )
