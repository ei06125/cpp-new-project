# Copyright (C) ei06125. All Rights Reserved.
cmake_minimum_required(VERSION 3.21)
project(
  CppTemplateProject
  VERSION 1.0.0
  LANGUAGES CXX
)

include(${PROJECT_SOURCE_DIR}/tools/cmake/Modules/BuildToolsMain.cmake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

log_info("Generating Global Settings INTERFACE target")
add_library(GlobalSettings INTERFACE)
set_project_warnings(GlobalSettings)

add_subdirectory(external EXCLUDE_FROM_ALL)
add_subdirectory(include)
add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(tests)
