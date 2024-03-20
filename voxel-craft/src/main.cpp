#include <voxel-engine/Logger.hpp>
#include <voxel-engine/Window.hpp>

int main() {

	LOG_INFO("Engine started");

	voxel_engine::Window window {1024, 800, "Voxelcraft"};

	window.run();

	return 0;
}