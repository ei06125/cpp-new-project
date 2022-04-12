# Copyright (C) ei06125. All Rights Reserved.

if(ENABLE_PERFORMANCE_TESTS)
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
  
  add_test(NAME ProjectPerformanceTests COMMAND ProjectPerformanceTests)
  set_tests_properties(ProjectPerformanceTests PROPERTIES TIMEOUT 2)

endif()
