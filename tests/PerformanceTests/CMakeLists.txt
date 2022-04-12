# Copyright (C) ei06125. All Rights Reserved.

add_executable(ProjectPerformanceTests)
file(GLOB_RECURSE ProjectPerformanceTests_SOURCES "*.cpp")
target_sources(
  ProjectPerformanceTests PRIVATE ${ProjectPerformanceTests_SOURCES}
)
target_link_libraries(
  ProjectPerformanceTests PRIVATE ProjectLib benchmark::benchmark
)
target_include_directories(
  ProjectPerformanceTests PRIVATE ${StandardLibraryPCH_INCLUDE_DIR}
                                 ${ProjectLib_INCLUDE_DIRS}
)
