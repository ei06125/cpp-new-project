# Copyright (C) ei06125. All Rights Reserved.

set(ProjectLib_INCLUDE_DIRS
    ${CMAKE_CURRENT_LIST_DIR}
    PARENT_SCOPE
)

add_library(ProjectLib)
file(GLOB_RECURSE ProjectLib_SOURCES "*.cpp")
target_sources(ProjectLib PUBLIC ${ProjectLib_SOURCES})
target_link_libraries(ProjectLib PUBLIC GlobalSettings StandardLibraryPCH)
target_include_directories(ProjectLib PUBLIC ${StandardLibraryPCH_INCLUDE_DIR})
