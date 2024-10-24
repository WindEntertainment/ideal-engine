#include "menu-item.hpp"
#pragma once
#include <editor/editor.hpp>
#include <utils/utils.hpp>

namespace editor {
namespace components {
class Menu {
public:
  Menu(const char* id, std::unordered_set<MenuItem> menuItems);
  void render();

private:
  const char* id;
  std::unordered_set<MenuItem> menuItems = {};
};
} // namespace components
} // namespace editor
