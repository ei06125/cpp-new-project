# Copyright (C) ei06125. All Rights Reserved.
cmake_minimum_required(VERSION 3.21)

project(
  CppTemplateProject
  VERSION 1.0.0
  LANGUAGES CXX
)

include(${PROJECT_SOURCE_DIR}/tools/cmake/Modules/BuildToolsMain.cmake)

# Surpress CTest Targets (Continuous, Experimental, Nightly)
set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)

find_package(Threads REQUIRED)
include(CTest)
include(GoogleTest)

# Surpress MSVC Target ZERO_CHECK
set(CMAKE_SUPPRESS_REGENERATION true)

set(CMAKE_CXX_STANDARD 23) # c++latest
set(CMAKE_CXX_EXTENSIONS OFF)

log_info("Generating Global Settings INTERFACE target")
add_library(GlobalSettings INTERFACE)
set_project_warnings(GlobalSettings)

# add_subdirectory(external)
add_subdirectory(include)
add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(tests)
