#include <voxel-engine/Window.hpp>
#include <voxel-engine/Logger.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace voxel_engine
{

Window::Window(std::size_t width,
               std::size_t height,
               std::string title)
    : width_{width}
    , height_{height}
    , title_{title}
{
    if (!glfwInit())
    {
        LOG_ERROR("Cannot initialize GLFW");
        return;
    }

    window_ = glfwCreateWindow(width_, height_, title_.c_str(), NULL, NULL);
    if (!window_)
    {
        glfwTerminate();
        LOG_ERROR("glfwCreateWindow() : failed");
        return;
    }

    glfwMakeContextCurrent(window_);

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        LOG_ERROR("Failed to initialize GLAD");
        return;
    }

    is_ready_ = true;
    LOG_INFO("Window successfully created");
}

Window::Window(Window &&other) noexcept
    : is_ready_{other.is_ready_}
    , width_{other.width_}
    , height_{other.height_}
    , title_{std::move(other.title_)}
    , window_{other.window_}
{
    other.window_ = nullptr;
    other.is_ready_ = false;
}

Window& Window::operator=(Window &&other) noexcept
{
    if (this != &other)
    {
        is_ready_ = other.is_ready_;
        width_ = other.width_;
        height_ = other.height_;
        title_ = std::move(other.title_);
        window_ = other.window_;
    }

    return *this;
}

Window::~Window()
{
    glfwTerminate();
}

void Window::run()
{
    if (!is_ready_)
    {
        LOG_ERROR("Cannot create window: it's initialized incorrect");
        return;
    }

    LOG_INFO("Window is running");

    glClearColor(1, 0, 0, 0);

    while (!glfwWindowShouldClose(window_))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window_);

        /* Poll for and process events */
        glfwPollEvents();
    }

    LOG_INFO("Window is stopped");
}

} // namespace voxel_engine
