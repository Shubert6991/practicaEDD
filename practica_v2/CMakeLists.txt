cmake_minimum_required(VERSION 2.6)

project (practica_v2 CXX)

set(PRACTICA_V2_HEADERS practica_v2.h NodoUsuario.h NodoServicio.h NodoRecurso.h)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(PRACTICA_V2_CODEGEN_DIR "${PROJECT_BINARY_DIR}/codegen")

PREPEND(PRACTICA_V2_HEADERS_PATHS ${PROJECT_SOURCE_DIR} ${PRACTICA_V2_HEADERS})

CODEGEN_FILES(PRACTICA_V2_CODEGEN_SOURCES ${PRACTICA_V2_CODEGEN_DIR} ${PRACTICA_V2_HEADERS})

add_custom_command(OUTPUT ${PRACTICA_V2_CODEGEN_SOURCES}
    COMMAND ${NGREST_BIN_PATH}ngrestcg -i "${PROJECT_SOURCE_DIR}" -o ${PRACTICA_V2_CODEGEN_DIR} -t service ${PRACTICA_V2_HEADERS}
    DEPENDS ${PRACTICA_V2_HEADERS_PATHS}
)

file(GLOB PRACTICA_V2_SOURCES ${PROJECT_SOURCE_DIR}/*.cpp)

list(APPEND PRACTICA_V2_SOURCES ${PRACTICA_V2_CODEGEN_SOURCES})

include_directories(${PROJECT_SOURCE_DIR} $ENV{NGREST_EXT_INCLUDES})

add_library(practica_v2 MODULE ${PRACTICA_V2_SOURCES})

set_target_properties(practica_v2 PROPERTIES PREFIX "")
set_target_properties(practica_v2 PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SERVICES_DIR}"
)

target_link_libraries(practica_v2 ngrestutils ngrestcommon ngrestjson ngrestengine $ENV{NGREST_EXT_LIBS})
