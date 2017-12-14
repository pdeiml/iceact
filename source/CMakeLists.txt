cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(iceact)

# Find Geant4 package, activating all available UI and Vis drivers by default
option(WITH_GEANT4_UIVIS "Build with all Geant4 UIs and all visualization drivers" ON)
option(WITH_GEANT4_OPENGL "Build with Geant4 shell UI and OpenGl visualization" OFF)
option(WITH_GEANT4_QT "Build with Geant4 Qt UI" OFF)

if(WITH_GEANT4_OPENGL)
    find_package(Geant4 REQUIRED vis_opengl_x11 ui_tcsh)
elseif(WITH_GEANT4_QT)
    find_package(Geant4 REQUIRED qt)
elseif(WITH_GEANT4_UIVIS)
    find_package(Geant4 REQUIRED ui_all vis_all)
else()
    find_package(Geant4 REQUIRED)
endif()

add_definitions(${Geant4_DEFINITIONS})
include(${Geant4_USE_FILE})
set(LIBS ${LIBS} ${Geant4_LIBRARIES})

# Switch for static / shared library building.
if(Geant4_shared_FOUND)
    set(LIBRARY_MODE "SHARED")
else()
    set(LIBRARY_MODE "STATIC")
endif()

# Add Root
execute_process(COMMAND root-config --libs OUTPUT_VARIABLE root_libs OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND root-config --cflags OUTPUT_VARIABLE root_cflags OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND root-config --incdir OUTPUT_VARIABLE root_includes OUTPUT_STRIP_TRAILING_WHITESPACE)
add_definitions(${root_cflags})
include_directories(${root_includes})
set(LIBS ${LIBS} ${root_libs})

# Here the actual source code is included

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SOURCES)

add_library(fresnel SHARED ${SOURCES})

set(EXE_NAMES fresnelSimu)

foreach(EXE_NAME ${EXE_NAMES})
    add_executable(${EXE_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src_exe/${EXE_NAME}.cpp)
    target_link_libraries(${EXE_NAMES} ${LIBS} fresnel)
endforeach()
