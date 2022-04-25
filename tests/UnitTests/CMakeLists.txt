# Copyright (C) ei06125. All Rights Reserved.

find_package(GTest CONFIG REQUIRED)
add_executable(ProjectUnitTests)
file(GLOB_RECURSE ProjectUnitTests_SOURCES "*.cpp")
target_sources(ProjectUnitTests PRIVATE ${ProjectUnitTests_SOURCES})
target_link_libraries(
  ProjectUnitTests PRIVATE ProjectLib GTest::gtest GTest::gmock
)
target_include_directories(
  ProjectUnitTests PRIVATE ${StandardLibraryPCH_INCLUDE_DIR}
                           ${ProjectLib_INCLUDE_DIRS}
)

add_test(NAME ProjectUnitTests COMMAND ProjectUnitTests)
