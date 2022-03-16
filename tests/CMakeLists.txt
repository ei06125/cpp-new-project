# Copyright (C) ei06125. All Rights Reserved.

# =============================================================================
add_executable(behaviourTests)
target_sources(behaviourTests PRIVATE behaviourTests.cpp)
target_link_libraries(behaviourTests PRIVATE GlobalSettings gtest)

# =============================================================================
add_executable(benchmarkTests)
target_sources(benchmarkTests PRIVATE benchmarkTests.cpp)
target_link_libraries(benchmarkTests PRIVATE benchmark::benchmark)
