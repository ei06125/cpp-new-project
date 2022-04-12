# Copyright (C) ei06125. All Rights Reserved.

add_executable(ProjectUnitTests)
file(GLOB_RECURSE ProjectUnitTests_SOURCES "*.cpp")
target_sources(ProjectUnitTests PRIVATE ${ProjectUnitTests_SOURCES})
target_link_libraries(ProjectUnitTests PRIVATE ProjectLib gtest gmock)
target_include_directories(
  ProjectUnitTests PRIVATE ${StandardLibraryPCH_INCLUDE_DIR}
                           ${ProjectLib_INCLUDE_DIRS}
)
