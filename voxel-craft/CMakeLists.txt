set(target_name voxel-craft) 

add_executable(${target_name}
    src/main.cpp
)

target_link_libraries(${target_name} PUBLIC voxel-engine-lib)
