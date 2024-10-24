#include <editor/shared/menu/menu-item.hpp>

namespace editor {
  namespace components {
    MenuItem::MenuItem(
      const std::string id,
      Callback callback,
      const std::string shortcut
    )
        : id(id), shortcut(shortcut), callback(callback) {}

    void MenuItem::render() {
      if (ImGui::MenuItem(id.c_str(), shortcut.c_str())) {
        callback();
      }
    }
  } // namespace components
} // namespace editor
