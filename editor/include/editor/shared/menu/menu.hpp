#pragma once
#include <editor/editor.hpp>
#include <utils/utils.hpp>
#include "menu-item.hpp"

namespace editor {
  namespace components {
    class Menu {
    public:
      const std::string id;

      Menu(const std::string id, MenuItems menuItems);
      void render();

      bool operator==(const Menu &menu) const { return id == menu.id; }

    private:
      MenuItems menuItems = {};
    };

    struct MenuHash {
      std::size_t operator()(const Menu &menu) const {
        return std::hash<std::string>()(menu.id);
      }
    };
    using Menus = std::unordered_set<Menu, MenuHash>;
  } // namespace components
} // namespace editor
