#include <editor/shared/menu.hpp>

namespace editor {
namespace components {
Menu::Menu(const char* id, std::unordered_set<MenuItem> menuItems)
    : id(id), menuItems(menuItems) {
}

void Menu::render() {
  if (ImGui::BeginMenu(id)) {
    for (auto menuItem : menuItems) {
      menuItem.render();
    }
    ImGui::EndMenu();
  }
}
} // namespace components
} // namespace editor
