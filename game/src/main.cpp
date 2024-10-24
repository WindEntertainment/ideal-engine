#include "window/window.hpp"

int main(int argc, char **argv) {
  auto window = wind::Window::create([](wind::Window::Config *self) {
    self->title = "Hello, World!";
  });

  while (true) {
    window->update();
    window->show();
  }

  window->close();

  return 0;
}