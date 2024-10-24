#include <editor/shared/menu.hpp>

namespace editor {
  namespace components {
    Menu::Menu(const std::string id, MenuItems menuItems)
        : id(id), menuItems(menuItems) {}

    void Menu::render() {
      if (ImGui::BeginMenu(id.c_str())) {
        for (auto menuItem : menuItems) {
          menuItem.render();
        }
        ImGui::EndMenu();
      }
    }
  } // namespace components
} // namespace editor
