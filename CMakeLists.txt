# Copyright (C) ei06125. All Rights Reserved.
cmake_minimum_required(VERSION 3.21)
project(
  CppTemplateProject
  VERSION 1.0.0
  LANGUAGES CXX
)

include(${PROJECT_SOURCE_DIR}/tools/cmake/Modules/BuildToolsMain.cmake)

find_package(Threads REQUIRED)
set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)
include(CTest)
include(GoogleTest)

# Surpress Target ZERO_CHECK
set(CMAKE_SUPPRESS_REGENERATION true)
set(CMAKE_CXX_STANDARD 23) # c++latest
set(CMAKE_CXX_EXTENSIONS OFF)

log_info("Generating Global Settings INTERFACE target")
add_library(GlobalSettings INTERFACE)
set_project_warnings(GlobalSettings)

add_subdirectory(external)
add_subdirectory(include)
add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(tests)

# set the startup project for the "play" button in MSVC
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT ProjectExec)

# Add other targets that you want installed here, be default we just package the one executable
# we know we want to ship
package_project(TARGETS ProjectLib)

# Experience shows that explicit package naming can help make it easier to sort
# out potential ABI related issues before they start, while helping you
# track a build to a specific GIT SHA
set(CPACK_PACKAGE_FILE_NAME
    "${CMAKE_PROJECT_NAME}-${CMAKE_PROJECT_VERSION}-${GIT_SHORT_SHA}-${CMAKE_SYSTEM_NAME}-${CMAKE_BUILD_TYPE}-${CMAKE_CXX_COMPILER_ID}-${CMAKE_CXX_COMPILER_VERSION}"
)

include(CPack)
