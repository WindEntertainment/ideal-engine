#include <editor/shared/menu-bar.hpp>

namespace editor {
namespace components {
MenuBar::MenuBar(std::unordered_set<Menu> menus)
    : menus(menus) {
}

void MenuBar::render() {
  if (ImGui::BeginMenuBar()) {
    for (auto menuItem : menus) {
      menuItem.render();
    }
    ImGui::EndMenuBar();
  }
}
} // namespace components
} // namespace editor
