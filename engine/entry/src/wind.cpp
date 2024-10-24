#include "wind/wind.hpp"

namespace wind {

std::shared_ptr<Window> Engine::_mainWindow = nullptr;

int Engine::run() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    spdlog::error("Failed initialization SDL: {}", SDL_GetError());
    return EXIT_FAILURE;
  }

  _mainWindow = Window::create([](Window::Config* self) {
    self->title = "Hello, World!";
  });

  SDL_Event event;

  while (true) {

    while (SDL_PollEvent(&event)) {
    }

    _mainWindow->update();
    _mainWindow->show();
  }

  _mainWindow->close();
  SDL_Quit();

  return EXIT_SUCCESS;
}

} // namespace wind