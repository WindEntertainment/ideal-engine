#pragma once
#include <editor/editor.hpp>
#include <utils/utils.hpp>

using Callback = std::function<void()>;

namespace editor {
namespace components {
class MenuItem {
public:
  MenuItem(const char* id, Callback callback);
  void render();

private:
  const char* id;
  Callback callback;
};
} // namespace components
} // namespace editor
