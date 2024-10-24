#include "wind/window/window.hpp"

namespace wind {

namespace {

using timepoint = chrono::time_point<chrono::high_resolution_clock>;
static timepoint m_perSecond;

} // namespace

//===========================================//
// Lifecycle
bool Window::create(Config config) {
  m_window = SDL_CreateWindow(
    config.title.c_str(),
    config.position.x,
    config.position.y,
    config.size.x,
    config.size.y,
    SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

  if (!m_window) {
    spdlog::error("Failed create window: {}", SDL_GetError());
    return false;
  }

  m_alive = true;
  m_title = config.title.c_str();
  setVisibleCursor(config.visibleCursor);
}

Window::~Window() {
  close();
}

std::shared_ptr<Window> Window::create(void (*buildConfig)(Config*)) {
  Config config;
  buildConfig(&config);

  Window* window = new Window();
  if (window->create(config))
    return std::shared_ptr<Window>(window);

  return nullptr;
}

void Window::close() {
  if (!m_window)
    return;

  m_alive = false;
  SDL_DestroyWindow(m_window);
}

void Window::show() {
  static const auto oneSecond =
    std::chrono::duration_cast<std::chrono::high_resolution_clock::duration>(
      std::chrono::seconds(1));
  static int numFrames = 0;

  numFrames += 1;
  if (chrono::high_resolution_clock::now() > m_perSecond) {
    m_fps = numFrames;
    numFrames = 0;

    m_perSecond = chrono::high_resolution_clock::now() + oneSecond;
  }
}

bool Window::update() {
  return m_alive;
}

//===========================================//
// Setters

void Window::setTitle(const char* _title) {
  SDL_SetWindowTitle(m_window, _title);
  m_title = _title;
}

void Window::setSize(glm::ivec2 _size) {
  SDL_SetWindowSize(m_window, _size.x, _size.y);
}

void Window::setPosition(glm::ivec2 _position) {
  SDL_SetWindowPosition(m_window, _position.x, _position.y);
}

void Window::setResizable(bool _resizable) {
  SDL_SetWindowResizable(m_window, (SDL_bool)_resizable);
}

void Window::setVisibleCursor(bool _visible) {
  SDL_ShowCursor(_visible ? SDL_ENABLE : SDL_DISABLE);
}

//===========================================//
// Getters

const char* Window::title() {
  return m_title;
}

glm::ivec2 Window::size() {
  int w, h;
  SDL_GetWindowSize(m_window, &w, &h);
  return {w, h};
}

glm::ivec2 Window::position() {
  int x, y;
  SDL_GetWindowPosition(m_window, &x, &y);
  return {x, y};
}

bool Window::isFullScreen() {
  auto flag = SDL_GetWindowFlags(m_window);
  auto is_fullscreen = flag & SDL_WINDOW_FULLSCREEN;

  return is_fullscreen == SDL_WINDOW_FULLSCREEN;
}

bool Window::isResizable() {
  auto flag = SDL_GetWindowFlags(m_window);
  auto is_fullscreen = flag & SDL_WINDOW_RESIZABLE;

  return is_fullscreen == SDL_WINDOW_RESIZABLE;
}

bool Window::isVisibleCursor() {
  return SDL_ShowCursor(SDL_QUERY) == SDL_ENABLE;
}

int Window::getFPS() {
  return m_fps;
}

} // namespace wind
