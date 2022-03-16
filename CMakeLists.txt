# Copyright (C) ei06125. All Rights Reserved.
cmake_minimum_required(VERSION 3.21)
project(
  CppTemplateProject
  VERSION 1.0.0
  LANGUAGES CXX
)

include(${PROJECT_SOURCE_DIR}/tools/cmake/Modules/BuildToolsMain.cmake)

log_info("Generating Global Settings INTERFACE target")
add_library(GlobalSettings INTERFACE)
target_compile_features(GlobalSettings INTERFACE cxx_std_20)
set_project_warnings(GlobalSettings)

add_subdirectory(external)
add_subdirectory(src)
add_subdirectory(tests)
