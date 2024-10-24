#include <editor/shared/menu-item.hpp>

using Callback = std::function<void()>;

namespace editor {
namespace components {
MenuItem::MenuItem(const char* id, Callback callback)
    : id(id), callback(callback) {
}

void MenuItem::render() {
  if (ImGui::MenuItem(id)) {
    callback();
  }
}
} // namespace components
} // namespace editor
