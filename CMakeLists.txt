cmake_minimum_required(VERSION 3.22)

project(VoxelCraft
    VERSION 1.0
    LANGUAGES CXX C
)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(external)
add_subdirectory(voxel-engine)
add_subdirectory(voxel-craft)
