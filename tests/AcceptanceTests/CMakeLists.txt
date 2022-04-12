# Copyright (C) ei06125. All Rights Reserved.

add_executable(ProjectAcceptanceTests)
file(GLOB_RECURSE ProjectAcceptanceTests_SOURCES "*.cpp")
target_sources(ProjectAcceptanceTests PRIVATE ${ProjectAcceptanceTests_SOURCES})
target_link_libraries(
  ProjectAcceptanceTests PRIVATE ProjectLib doctest::doctest
)
target_include_directories(
  ProjectAcceptanceTests PRIVATE ${StandardLibraryPCH_INCLUDE_DIR}
                                 ${ProjectLib_INCLUDE_DIRS}
)
