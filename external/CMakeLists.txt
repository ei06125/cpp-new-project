log_info("Including Google Test")
add_subdirectory(googletest EXCLUDE_FROM_ALL)

# if(ENABLE_PERFORMANCE_TESTS)
  log_info("Including Google Benchmark")
  add_subdirectory(benchmark EXCLUDE_FROM_ALL)
# endif()

log_info("Including doctest")
add_subdirectory(doctest EXCLUDE_FROM_ALL)
include(${CMAKE_CURRENT_LIST_DIR}/doctest/scripts/cmake/doctest.cmake)
