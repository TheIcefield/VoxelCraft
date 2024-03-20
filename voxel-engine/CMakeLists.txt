set(target_name voxel-engine-lib)

add_library(${target_name} STATIC
    src/voxel-engine/Window.cpp
    include/voxel-engine/Window.hpp

    include/voxel-engine/Logger.hpp)

target_link_libraries(${target_name} PUBLIC glfw glad spdlog)

target_include_directories(${target_name} PUBLIC ./include)
