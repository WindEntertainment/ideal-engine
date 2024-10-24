#include "menu.hpp"
#pragma once
#include <editor/editor.hpp>
#include <utils/utils.hpp>

namespace editor {
namespace components {
class MenuBar {
public:
  MenuBar(std::unordered_set<Menu> menus);
  void render();

private:
  std::unordered_set<Menu> menus = {};
};
} // namespace components
} // namespace editor
