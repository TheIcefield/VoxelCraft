#pragma once

#include <string>
#include <cstdint>

struct GLFWwindow;

namespace voxel_engine
{

class Window
{
public:
    Window(std::size_t width = 800,
           std::size_t height = 600,
           std::string title = "Just Another Title");

    Window(Window const&) = delete;
    Window& operator=(Window const&) = delete;

    Window(Window &&other) noexcept;
    Window& operator=(Window &&other) noexcept;
    
    ~Window();
    
    void run();

private:
    bool is_ready_ {false};
    std::size_t width_ {800};
    std::size_t height_ {600};
    std::string title_ {"Just Another Title"};

    GLFWwindow *window_ {nullptr};
};

} // namespace voxel_engine
