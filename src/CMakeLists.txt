# Copyright (C) ei06125. All Rights Reserved.

add_executable(ProjectExec)
target_sources(ProjectExec PRIVATE main.cpp)
target_link_libraries(ProjectExec PRIVATE ProjectLib)
target_include_directories(
  ProjectExec PRIVATE ${StandardLibraryPCH_INCLUDE_DIR}
)
