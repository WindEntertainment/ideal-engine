#include <editor/shared/menu-item.hpp>

namespace editor {
  namespace components {
    MenuItem::MenuItem(const std::string id, Callback callback)
        : id(id)
        , callback(callback) {}

    void MenuItem::render() {
      if (ImGui::MenuItem(id.c_str())) {
        callback();
      }
    }
  } // namespace components
} // namespace editor
